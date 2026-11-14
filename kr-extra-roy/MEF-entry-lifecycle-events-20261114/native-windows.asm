
# RESEARCH GROUP: entry

# frontend_table_default_and_stride 0x00493170 raw=0x00092570 size=46 sha256=f1143e1ceb1b36150c0b4737e74104b958aad1ee47ff015040a4eaa5312e66c6

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00493170 <.text+0x92170>:
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190

# frontend_0040_0045_0046_0047_Quest_bridge 0x0049368F raw=0x00092A8F size=92 sha256=46800558c19b7272cbd62e56a56c6b67c174d0f194e6da71d6ae5093151ca38d

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049368f <.text+0x9268f>:
  49368f:	ba 40 44 49 00       	mov    edx,0x494440
  493694:	89 90 08 06 00 00    	mov    DWORD PTR [eax+0x608],edx
  49369a:	89 b0 0c 06 00 00    	mov    DWORD PTR [eax+0x60c],esi
  4936a0:	89 88 10 06 00 00    	mov    DWORD PTR [eax+0x610],ecx
  4936a6:	ba 40 44 49 00       	mov    edx,0x494440
  4936ab:	89 90 58 06 00 00    	mov    DWORD PTR [eax+0x658],edx
  4936b1:	89 b0 5c 06 00 00    	mov    DWORD PTR [eax+0x65c],esi
  4936b7:	89 88 60 06 00 00    	mov    DWORD PTR [eax+0x660],ecx
  4936bd:	ba 40 44 49 00       	mov    edx,0x494440
  4936c2:	89 90 68 06 00 00    	mov    DWORD PTR [eax+0x668],edx
  4936c8:	89 b0 6c 06 00 00    	mov    DWORD PTR [eax+0x66c],esi
  4936ce:	89 88 70 06 00 00    	mov    DWORD PTR [eax+0x670],ecx
  4936d4:	ba 40 44 49 00       	mov    edx,0x494440
  4936d9:	89 90 78 06 00 00    	mov    DWORD PTR [eax+0x678],edx
  4936df:	89 b0 7c 06 00 00    	mov    DWORD PTR [eax+0x67c],esi
  4936e5:	89 88 80 06 00 00    	mov    DWORD PTR [eax+0x680],ecx

# frontend_dispatch_table_call 0x0048AAD0 raw=0x00089ED0 size=160 sha256=9febfa225890d6855926b631c3e4c32e920bad450abb14422c45a03cb884bd95

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048aad0 <.text+0x89ad0>:
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
  48ab68:	cc                   	int3
  48ab69:	cc                   	int3
  48ab6a:	cc                   	int3
  48ab6b:	cc                   	int3
  48ab6c:	cc                   	int3
  48ab6d:	cc                   	int3
  48ab6e:	cc                   	int3
  48ab6f:	cc                   	int3

# Quest_bridge_no_current_scene_lookup 0x00494440 raw=0x00093840 size=130 sha256=d4a12bc9ab8dc2b740314edab430c4c17866971bbb6ecaea3a30d7eb65dea3f3

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00494440 <.text+0x93440>:
  494440:	55                   	push   ebp
  494441:	8b ec                	mov    ebp,esp
  494443:	6a ff                	push   0xffffffff
  494445:	68 fe 7d 94 00       	push   0x947dfe
  49444a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  494450:	50                   	push   eax
  494451:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  494456:	51                   	push   ecx
  494457:	33 c5                	xor    eax,ebp
  494459:	50                   	push   eax
  49445a:	8d 45 f4             	lea    eax,[ebp-0xc]
  49445d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  494463:	b8 01 00 00 00       	mov    eax,0x1
  494468:	84 05 9c b2 fa 00    	test   BYTE PTR ds:0xfab29c,al
  49446e:	75 26                	jne    0x494496
  494470:	09 05 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,eax
  494476:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  49447d:	e8 de b9 06 00       	call   0x4ffe60
  494482:	68 00 cf bc 00       	push   0xbccf00
  494487:	e8 8e de 3f 00       	call   0x89231a
  49448c:	83 c4 04             	add    esp,0x4
  49448f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  494496:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  494499:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  49449c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  49449f:	50                   	push   eax
  4944a0:	a1 a0 b2 fa 00       	mov    eax,ds:0xfab2a0
  4944a5:	51                   	push   ecx
  4944a6:	52                   	push   edx
  4944a7:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4944aa:	b9 a0 b2 fa 00       	mov    ecx,0xfab2a0
  4944af:	ff d2                	call   edx
  4944b1:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4944b4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4944bb:	59                   	pop    ecx
  4944bc:	8b e5                	mov    esp,ebp
  4944be:	5d                   	pop    ebp
  4944bf:	c2 0c 00             	ret    0xc

# Quest_ctor_vtable_assignment 0x004FFE87 raw=0x000FF287 size=29 sha256=1ce26db031e43ba7d87c46a5530fdad7b0571ebec45652318bba8cbfa6fda06c

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ffe87 <.text+0xfee87>:
  4ffe87:	c7 45 ec a0 b2 fa 00 	mov    DWORD PTR [ebp-0x14],0xfab2a0
  4ffe8e:	33 f6                	xor    esi,esi
  4ffe90:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4ffe93:	6a 10                	push   0x10
  4ffe95:	c7 05 a0 b2 fa 00 08 	mov    DWORD PTR ds:0xfab2a0,0xc0db08
  4ffe9c:	db c0 00 
  4ffe9f:	e8 c4 13 39 00       	call   0x891268

# Quest_table_register_0047 0x005020B0 raw=0x001014B0 size=107 sha256=909c9e2fc8e32812674c09d297b83e0d69de1582e9145fac075cace37819dc87

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005020b0 <.text+0x1010b0>:
  5020b0:	b8 a8 b2 fa 00       	mov    eax,0xfab2a8
  5020b5:	ba 40 7d 4b 00       	mov    edx,0x4b7d40
  5020ba:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  5020bf:	90                   	nop
  5020c0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  5020c3:	89 08                	mov    DWORD PTR [eax],ecx
  5020c5:	83 c0 08             	add    eax,0x8
  5020c8:	3d 50 11 fb 00       	cmp    eax,0xfb1150
  5020cd:	7c f1                	jl     0x5020c0
  5020cf:	c7 05 a4 b4 fa 00 70 	mov    DWORD PTR ds:0xfab4a4,0x502270
  5020d6:	22 50 00 
  5020d9:	89 0d a8 b4 fa 00    	mov    DWORD PTR ds:0xfab4a8,ecx
  5020df:	89 15 9c b4 fa 00    	mov    DWORD PTR ds:0xfab49c,edx
  5020e5:	89 0d a0 b4 fa 00    	mov    DWORD PTR ds:0xfab4a0,ecx
  5020eb:	c7 05 cc b4 fa 00 d0 	mov    DWORD PTR ds:0xfab4cc,0x5027d0
  5020f2:	27 50 00 
  5020f5:	89 0d d0 b4 fa 00    	mov    DWORD PTR ds:0xfab4d0,ecx
  5020fb:	c7 05 d4 b4 fa 00 40 	mov    DWORD PTR ds:0xfab4d4,0x502b40
  502102:	2b 50 00 
  502105:	89 0d d8 b4 fa 00    	mov    DWORD PTR ds:0xfab4d8,ecx
  50210b:	c7 05 dc b4 fa 00 40 	mov    DWORD PTR ds:0xfab4dc,0x503040
  502112:	30 50 00 
  502115:	89 0d e0 b4 fa 00    	mov    DWORD PTR ds:0xfab4e0,ecx

# Quest_vtable_four_slots 0x00C0DB08 raw=0x0080C108 size=16 sha256=90f6b36668318d84a2d39b919c86c011bcc7075ce98e88b9f437e7fd28789d19
80ff4f0030da4f0010284200f0274200

# manager_table_dispatch 0x004FDA30 raw=0x000FCE30 size=131 sha256=f972c684f3955a1d49c1e56eef445bb5f60fd3e4e16da15c654a51ef21054f88

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004fda30 <.text+0xfca30>:
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

# S2C_0047_signed_keys_and_scene_manager 0x00503040 raw=0x00102440 size=128 sha256=142d0323b1f076ba219871090580d380c799a152d4367177598342f586aaa23f

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00503040 <.text+0x102040>:
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
  5030bf:	cc                   	int3

# scene_start_gate_lookup_path_prepass_wait_formal_load 0x00561760 raw=0x00160B60 size=1616 sha256=b1384aa92a8e9b8debc3f2628d2942d6f93185d5b485daae6ddbeb49df62f9d2

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561760 <.text+0x160760>:
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
  561da0:	8b e5                	mov    esp,ebp
  561da2:	5d                   	pop    ebp
  561da3:	c2 08 00             	ret    0x8
  561da6:	cc                   	int3
  561da7:	cc                   	int3
  561da8:	cc                   	int3
  561da9:	cc                   	int3
  561daa:	cc                   	int3
  561dab:	cc                   	int3
  561dac:	cc                   	int3
  561dad:	cc                   	int3
  561dae:	cc                   	int3
  561daf:	cc                   	int3

# SceneList_constructor_only_direct_call 0x00560327 raw=0x0015F727 size=39 sha256=d36c10d4208fc48e0d1d413da94b4509188fceb213dcefa7323f113d5a9b6a9a

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00560327 <.text+0x15f327>:
  560327:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  56032b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  560332:	00 
  560333:	f3 0f 11 05 44 74 fb 	movss  DWORD PTR ds:0xfb7444,xmm0
  56033a:	00 
  56033b:	66 c7 05 48 74 fb 00 	mov    WORD PTR ds:0xfb7448,0x1
  560342:	01 00 
  560344:	e8 87 04 00 00       	call   0x5607d0
  560349:	e8 f2 20 00 00       	call   0x562440

# SceneList_fixed_path_XML_keys_and_insert 0x00560810 raw=0x0015FC10 size=441 sha256=b4c8620359e69665d85304d21ac3235a90bcf1acc5c265c4a73900977fb7bd48

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00560810 <.text+0x15f810>:
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

# scene_path_and_error_string_literals 0x00C10668 raw=0x0080EC68 size=129 sha256=23087bf550f47737d0500c304956458843ae0eb137b61ee25d3f42f6344e13f3
4576656e742f5363656e654c6973742e786d6c005343454e455345540000000071756573744964780000000066756e634e616d6500000000665f646f436f5461736b0000c0ccb9cc20c4c6bec0c0cc20bdc7c7e020c1dfc0d4b4cfb4d92e202825642c20256429004576656e742f53657175656e6365732f000000002e73657100

# bootstrap_constructor_and_framework_init 0x004A3041 raw=0x000A2441 size=42 sha256=09ace2796e5687dac6a382dc29b7cbfc9a25ffe2756e51f725a0e9719f3f5533

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a3041 <.text+0xa2041>:
  4a3041:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  4a3045:	51                   	push   ecx
  4a3046:	e8 25 7b fe ff       	call   0x48ab70
  4a304b:	8d 74 24 34          	lea    esi,[esp+0x34]
  4a304f:	c7 84 24 c0 c0 00 00 	mov    DWORD PTR [esp+0xc0c0],0x1
  4a3056:	01 00 00 00 
  4a305a:	e8 e1 ba 23 00       	call   0x6deb40
  4a305f:	e8 dc bb 23 00       	call   0x6dec40
  4a3064:	8b fe                	mov    edi,esi
  4a3066:	e8 25 bc 23 00       	call   0x6dec90

# Client_subobjects_and_vtable_install 0x0048AC79 raw=0x0008A079 size=61 sha256=b0d55c346395ca774e7db0dc74d2c6cf98a99c85ff17543cd8efad97371983f3

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048ac79 <.text+0x89c79>:
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

# Client_constructor_fixed_core_scripts 0x0048B0E3 raw=0x0008A4E3 size=113 sha256=821782575d5ad7b6cc9d80e72504d9bcaaa3b7a530860824e09b2d3a5cf75d92

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048b0e3 <.text+0x8a0e3>:
  48b0e3:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  48b0ea:	89 87 5c bf 00 00    	mov    DWORD PTR [edi+0xbf5c],eax
  48b0f0:	75 21                	jne    0x48b113
  48b0f2:	83 0d d4 f3 fd 00 01 	or     DWORD PTR ds:0xfdf3d4,0x1
  48b0f9:	c6 45 fc 18          	mov    BYTE PTR [ebp-0x4],0x18
  48b0fd:	e8 7e 92 26 00       	call   0x6f4380
  48b102:	68 d0 e6 bc 00       	push   0xbce6d0
  48b107:	e8 0e 72 40 00       	call   0x89231a
  48b10c:	83 c4 04             	add    esp,0x4
  48b10f:	c6 45 fc 0b          	mov    BYTE PTR [ebp-0x4],0xb
  48b113:	68 b0 55 c0 00       	push   0xc055b0
  48b118:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48b11d:	e8 2e 99 26 00       	call   0x6f4a50
  48b122:	68 bc 55 c0 00       	push   0xc055bc
  48b127:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48b12c:	e8 1f 99 26 00       	call   0x6f4a50
  48b131:	68 c8 55 c0 00       	push   0xc055c8
  48b136:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48b13b:	e8 10 99 26 00       	call   0x6f4a50
  48b140:	8b c7                	mov    eax,edi
  48b142:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  48b145:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  48b14c:	59                   	pop    ecx
  48b14d:	5f                   	pop    edi
  48b14e:	5e                   	pop    esi
  48b14f:	5b                   	pop    ebx
  48b150:	8b e5                	mov    esp,ebp
  48b152:	5d                   	pop    ebp
  48b153:	c2               	ret    0x4

# framework_init_virtual_28 0x006DEBF4 raw=0x002DDFF4 size=75 sha256=65189fe666a76827379f7cef61dc610bc3663b08350c6e184738cc0d882ebcb7

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006debf4 <.text+0x2ddbf4>:
  6debf4:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6debf7:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  6debfa:	8b 56 28             	mov    edx,DWORD PTR [esi+0x28]
  6debfd:	8b 7e 24             	mov    edi,DWORD PTR [esi+0x24]
  6dec00:	50                   	push   eax
  6dec01:	51                   	push   ecx
  6dec02:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  6dec05:	52                   	push   edx
  6dec06:	33 d2                	xor    edx,edx
  6dec08:	e8 c3 38 00 00       	call   0x6e24d0
  6dec0d:	83 c4 0c             	add    esp,0xc
  6dec10:	e8 4b 11 00 00       	call   0x6dfd60
  6dec15:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  6dec18:	8b 06                	mov    eax,DWORD PTR [esi]
  6dec1a:	8b 48 28             	mov    ecx,DWORD PTR [eax+0x28]
  6dec1d:	56                   	push   esi
  6dec1e:	ff d1                	call   ecx
  6dec20:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6dec23:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  6dec26:	56                   	push   esi
  6dec27:	68 50 ae 6e 00       	push   0x6eae50
  6dec2c:	68 10 ae 6e 00       	push   0x6eae10
  6dec31:	50                   	push   eax
  6dec32:	51                   	push   ecx
  6dec33:	e8 18 3c 00 00       	call   0x6e2850
  6dec38:	83 c4 14             	add    esp,0x14
  6dec3b:	33 c0                	xor    eax,eax
  6dec3d:	5f                   	pop    edi
  6dec3e:	c3                   	ret

# Client_framework_vtable 0x00C05AA4 raw=0x008040A4 size=56 sha256=415973de7afd135981ffc6f4db15a8d5526e7c83779796af1f5fdb9e217c9178
e0ad490070ee4800f0ff48005005490010f948002008490090b7730040ed6d0050be480070c14800e0c6480030e64800e00f490040204900

# Client_init_fixed_UI_and_table_scripts 0x0048C9DA raw=0x0008BDDA size=120 sha256=7734e41f560125e74fea7a977813c248122e8063188cd550954c8aec1b070702

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0048c9da <.text+0x8b9da>:
  48c9da:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  48c9e1:	75 24                	jne    0x48ca07
  48c9e3:	09 3d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,edi
  48c9e9:	c7 44 24 70 07 00 00 	mov    DWORD PTR [esp+0x70],0x7
  48c9f0:	00 
  48c9f1:	e8 8a 79 26 00       	call   0x6f4380
  48c9f6:	68 d0 e6 bc 00       	push   0xbce6d0
  48c9fb:	e8 1a 59 40 00       	call   0x89231a
  48ca00:	83 c4 04             	add    esp,0x4
  48ca03:	89 5c 24 70          	mov    DWORD PTR [esp+0x70],ebx
  48ca07:	68 4c 57 c0 00       	push   0xc0574c
  48ca0c:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48ca11:	e8 3a 80 26 00       	call   0x6f4a50
  48ca16:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  48ca1d:	75 24                	jne    0x48ca43
  48ca1f:	09 3d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,edi
  48ca25:	c7 44 24 70 08 00 00 	mov    DWORD PTR [esp+0x70],0x8
  48ca2c:	00 
  48ca2d:	e8 4e 79 26 00       	call   0x6f4380
  48ca32:	68 d0 e6 bc 00       	push   0xbce6d0
  48ca37:	e8 de 58 40 00       	call   0x89231a
  48ca3c:	83 c4 04             	add    esp,0x4
  48ca3f:	89 5c 24 70          	mov    DWORD PTR [esp+0x70],ebx
  48ca43:	68 60 57 c0 00       	push   0xc05760
  48ca48:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48ca4d:	e8 fe 7f 26 00       	call   0x6f4a50

# Client_init_shared_wrapper_scene_and_Tutorial 0x0048D73E raw=0x0008CB3E size=165 sha256=5e77b168796541d49a33767f8788da5abac70327a6930ee4ac54465774f9ddce

project_sources/02-Tartaros.bin:     file format pei-i386


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

# scene_manager_wrapper_binding 0x00560600 raw=0x0015FA00 size=33 sha256=c479cbd8787fd94562f89f20d10b79a5ab01ee0a3033b22dce0c11bcbffcd2f3

project_sources/02-Tartaros.bin:     file format pei-i386


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

# scene_manager_four_fixed_script_paths 0x0056078F raw=0x0015FB8F size=52 sha256=d90e79c732acea97beb9f1823dfd173822a3fea554fc0abaa4bc9501e30af0a0

project_sources/02-Tartaros.bin:     file format pei-i386


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

# core_script_literals 0x00C055B0 raw=0x00803BB0 size=38 sha256=ed3b98240b020c4fa78b0e99cfa3f50eaa4e96a4264880ba009a3aad97db94bf
426f6f742e6c7561000000004c6f6769632e6c7561000000436f726f7574696e652e6c756100

# UI_table_script_literals 0x00C0574C raw=0x00803D4C size=42 sha256=20dfa9ef3a40eca9d76a841d43d88734cc062d418e30d578acb764e018c5176b
55492f4c55412f4c75615574696c2e6c756100005461626c652f4c55412f5461626c65732e6c75610000

# qbase_script_literal 0x00C10658 raw=0x0080EC58 size=16 sha256=9adac42f4232c3a29bf31c289341409365f74fd6016443d3813a4345343749e2
4576656e742f71626173652e6c756100

# S2C_005F_scene_factory 0x004B99C0 raw=0x000B8DC0 size=404 sha256=8ca53748d98a147ec71498ec0daddb0932b25b56c7f198d40bb0f4e01827a5bc

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b99c0 <.text+0xb89c0>:
  4b99c0:	55                   	push   ebp
  4b99c1:	8b ec                	mov    ebp,esp
  4b99c3:	83 e4 f8             	and    esp,0xfffffff8
  4b99c6:	6a ff                	push   0xffffffff
  4b99c8:	68 3e 71 94 00       	push   0x94713e
  4b99cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b99d3:	50                   	push   eax
  4b99d4:	83 ec 08             	sub    esp,0x8
  4b99d7:	53                   	push   ebx
  4b99d8:	56                   	push   esi
  4b99d9:	57                   	push   edi
  4b99da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b99df:	33 c4                	xor    eax,esp
  4b99e1:	50                   	push   eax
  4b99e2:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b99e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b99ec:	8b d9                	mov    ebx,ecx
  4b99ee:	b8 01 00 00 00       	mov    eax,0x1
  4b99f3:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4b99f9:	75 28                	jne    0x4b9a23
  4b99fb:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4b9a01:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b9a08:	00 
  4b9a09:	e8 82 7b 02 00       	call   0x4e1590
  4b9a0e:	68 80 cc bc 00       	push   0xbccc80
  4b9a13:	e8 02 89 3d 00       	call   0x89231a
  4b9a18:	83 c4 04             	add    esp,0x4
  4b9a1b:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b9a22:	ff 
  4b9a23:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b9a26:	0f b6 41 02          	movzx  eax,BYTE PTR [ecx+0x2]
  4b9a2a:	39 05 2c 39 f9 00    	cmp    DWORD PTR ds:0xf9392c,eax
  4b9a30:	74 05                	je     0x4b9a37
  4b9a32:	a3 2c 39 f9 00       	mov    ds:0xf9392c,eax
  4b9a37:	0f b6 41 02          	movzx  eax,BYTE PTR [ecx+0x2]
  4b9a3b:	83 c0 fe             	add    eax,0xfffffffe
  4b9a3e:	83 f8 1a             	cmp    eax,0x1a
  4b9a41:	0f 87 f4 00 00 00    	ja     0x4b9b3b
  4b9a47:	0f b6 80 74 9b 4b 00 	movzx  eax,BYTE PTR [eax+0x4b9b74]
  4b9a4e:	ff 24 85 54 9b 4b 00 	jmp    DWORD PTR [eax*4+0x4b9b54]
  4b9a55:	68 54 bd 00 00       	push   0xbd54
  4b9a5a:	e8 09 78 3d 00       	call   0x891268
  4b9a5f:	83 c4 04             	add    esp,0x4
  4b9a62:	85 c0                	test   eax,eax
  4b9a64:	0f 84 c6 00 00 00    	je     0x4b9b30
  4b9a6a:	8b f0                	mov    esi,eax
  4b9a6c:	e8 7f ac 00 00       	call   0x4c46f0
  4b9a71:	e9 bc 00 00 00       	jmp    0x4b9b32
  4b9a76:	68 5c bd 00 00       	push   0xbd5c
  4b9a7b:	e8 e8 77 3d 00       	call   0x891268
  4b9a80:	83 c4 04             	add    esp,0x4
  4b9a83:	85 c0                	test   eax,eax
  4b9a85:	0f 84 a5 00 00 00    	je     0x4b9b30
  4b9a8b:	e8 10 2c 00 00       	call   0x4bc6a0
  4b9a90:	e9 9d 00 00 00       	jmp    0x4b9b32
  4b9a95:	68 54 bd 00 00       	push   0xbd54
  4b9a9a:	e8 c9 77 3d 00       	call   0x891268
  4b9a9f:	8b f0                	mov    esi,eax
  4b9aa1:	83 c4 04             	add    esp,0x4
  4b9aa4:	85 f6                	test   esi,esi
  4b9aa6:	74 1e                	je     0x4b9ac6
  4b9aa8:	e8 a3 42 ff ff       	call   0x4add50
  4b9aad:	c7 06 0c 71 c0 00    	mov    DWORD PTR [esi],0xc0710c
  4b9ab3:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x44554546
  4b9aba:	45 55 44 
  4b9abd:	e8 de 40 00 00       	call   0x4bdba0
  4b9ac2:	8b fe                	mov    edi,esi
  4b9ac4:	eb 6e                	jmp    0x4b9b34
  4b9ac6:	33 f6                	xor    esi,esi
  4b9ac8:	8b fe                	mov    edi,esi
  4b9aca:	eb 68                	jmp    0x4b9b34
  4b9acc:	68 5c bd 00 00       	push   0xbd5c
  4b9ad1:	e8 92 77 3d 00       	call   0x891268
  4b9ad6:	83 c4 04             	add    esp,0x4
  4b9ad9:	85 c0                	test   eax,eax
  4b9adb:	74 53                	je     0x4b9b30
  4b9add:	e8 fe b9 00 00       	call   0x4c54e0
  4b9ae2:	eb 4e                	jmp    0x4b9b32
  4b9ae4:	68 54 bd 00 00       	push   0xbd54
  4b9ae9:	e8 7a 77 3d 00       	call   0x891268
  4b9aee:	83 c4 04             	add    esp,0x4
  4b9af1:	85 c0                	test   eax,eax
  4b9af3:	74 3b                	je     0x4b9b30
  4b9af5:	8b f0                	mov    esi,eax
  4b9af7:	e8 f4 c9 f9 ff       	call   0x4564f0
  4b9afc:	eb 34                	jmp    0x4b9b32
  4b9afe:	68 54 bd 00 00       	push   0xbd54
  4b9b03:	e8 60 77 3d 00       	call   0x891268
  4b9b08:	83 c4 04             	add    esp,0x4
  4b9b0b:	85 c0                	test   eax,eax
  4b9b0d:	74 21                	je     0x4b9b30
  4b9b0f:	8b f0                	mov    esi,eax
  4b9b11:	e8 ba ce f7 ff       	call   0x4369d0
  4b9b16:	eb 1a                	jmp    0x4b9b32
  4b9b18:	68 5c bd 00 00       	push   0xbd5c
  4b9b1d:	e8 46 77 3d 00       	call   0x891268
  4b9b22:	83 c4 04             	add    esp,0x4
  4b9b25:	85 c0                	test   eax,eax
  4b9b27:	74 07                	je     0x4b9b30
  4b9b29:	e8 82 94 f6 ff       	call   0x422fb0
  4b9b2e:	eb 02                	jmp    0x4b9b32
  4b9b30:	33 c0                	xor    eax,eax
  4b9b32:	8b f8                	mov    edi,eax
  4b9b34:	8b f3                	mov    esi,ebx
  4b9b36:	e8 15 e2 ff ff       	call   0x4b7d50
  4b9b3b:	33 c0                	xor    eax,eax
  4b9b3d:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4b9b41:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b9b48:	59                   	pop    ecx
  4b9b49:	5f                   	pop    edi
  4b9b4a:	5e                   	pop    esi
  4b9b4b:	5b                   	pop    ebx
  4b9b4c:	8b e5                	mov    esp,ebp
  4b9b4e:	5d                   	pop    ebp
  4b9b4f:	c2 0c 00             	ret    0xc
  4b9b52:	8b ff                	mov    edi,edi

# S2C_005F_switch_tables 0x004B9B54 raw=0x000B8F54 size=59 sha256=6e2725f10e3a806042032d1a1c1a67ad55b837544f3020dc2fe9d78da3a197cb
559a4b00769a4b00959a4b00cc9a4b00e49a4b00fe9a4b00189b4b003b9b4b00000701070207070307070707070707070707070707070704050706

# GameInfo_base_return_for_scene_mode_identity 0x00404BA0 raw=0x00003FA0 size=105 sha256=364c631a3e7417084f88552adf6f2b01d939e0dde1969c29bb43843da2085c84

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00404ba0 <.text+0x3ba0>:
  404ba0:	55                   	push   ebp
  404ba1:	8b ec                	mov    ebp,esp
  404ba3:	83 e4 f8             	and    esp,0xfffffff8
  404ba6:	6a ff                	push   0xffffffff
  404ba8:	68 0e f8 93 00       	push   0x93f80e
  404bad:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  404bb3:	50                   	push   eax
  404bb4:	51                   	push   ecx
  404bb5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  404bba:	33 c4                	xor    eax,esp
  404bbc:	50                   	push   eax
  404bbd:	8d 44 24 08          	lea    eax,[esp+0x8]
  404bc1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  404bc7:	b8 01 00 00 00       	mov    eax,0x1
  404bcc:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  404bd2:	75 20                	jne    0x404bf4
  404bd4:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  404bda:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  404be1:	00 
  404be2:	e8 a9 c9 0d 00       	call   0x4e1590
  404be7:	68 80 cc bc 00       	push   0xbccc80
  404bec:	e8 29 d7 48 00       	call   0x89231a
  404bf1:	83 c4 04             	add    esp,0x4
  404bf4:	b8 e0 d9 f8 00       	mov    eax,0xf8d9e0
  404bf9:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  404bfd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  404c04:	59                   	pop    ecx
  404c05:	8b e5                	mov    esp,ebp
  404c07:	5d                   	pop    ebp
  404c08:	c3                   	ret

# CScenarioField_constructor 0x004C46F0 raw=0x000C3AF0 size=96 sha256=8f998f48e982fbbe6256e2ee301e1f679f76032d55620b5f3b1c8c739840533b

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c46f0 <.text+0xc36f0>:
  4c46f0:	8b c6                	mov    eax,esi
  4c46f2:	e8 59 96 fe ff       	call   0x4add50
  4c46f7:	68 a8 5e 00 00       	push   0x5ea8
  4c46fc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4702:	6a 00                	push   0x0
  4c4704:	50                   	push   eax
  4c4705:	c7 06 b4 73 c0 00    	mov    DWORD PTR [esi],0xc073b4
  4c470b:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x53434546
  4c4712:	45 43 53 
  4c4715:	e8 46 a1 3d 00       	call   0x89e860
  4c471a:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c471f:	89 86 50 5f 00 00    	mov    DWORD PTR [esi+0x5f50],eax
  4c4725:	89 86 20 5f 00 00    	mov    DWORD PTR [esi+0x5f20],eax
  4c472b:	83 c4 0c             	add    esp,0xc
  4c472e:	c7 86 4c 5f 00 00 30 	mov    DWORD PTR [esi+0x5f4c],0x4c5930
  4c4735:	59 4c 00 
  4c4738:	c7 86 1c 5f 00 00 40 	mov    DWORD PTR [esi+0x5f1c],0x436c40
  4c473f:	6c 43 00 
  4c4742:	8b c6                	mov    eax,esi
  4c4744:	c3                   	ret
  4c4745:	cc                   	int3
  4c4746:	cc                   	int3
  4c4747:	cc                   	int3
  4c4748:	cc                   	int3
  4c4749:	cc                   	int3
  4c474a:	cc                   	int3
  4c474b:	cc                   	int3
  4c474c:	cc                   	int3
  4c474d:	cc                   	int3
  4c474e:	cc                   	int3
  4c474f:	cc                   	int3

# CMissionField_constructor 0x004BC6A0 raw=0x000BBAA0 size=64 sha256=477b633a4c765c92a89c06ad791f295dafa7003e4a0a206cea7b142d888dd74b

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bc6a0 <.text+0xbb6a0>:
  4bc6a0:	56                   	push   esi
  4bc6a1:	8b f0                	mov    esi,eax
  4bc6a3:	e8 a8 16 ff ff       	call   0x4add50
  4bc6a8:	f3 0f 10 05 c0 56 c5 	movss  xmm0,DWORD PTR ds:0xc556c0
  4bc6af:	00 
  4bc6b0:	c7 06 5c 70 c0 00    	mov    DWORD PTR [esi],0xc0705c
  4bc6b6:	c7 86 54 bd 00 00 00 	mov    DWORD PTR [esi+0xbd54],0x0
  4bc6bd:	00 00 00 
  4bc6c0:	f3 0f 11 86 58 bd 00 	movss  DWORD PTR [esi+0xbd58],xmm0
  4bc6c7:	00 
  4bc6c8:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x4d495346
  4bc6cf:	53 49 4d 
  4bc6d2:	e8 09 00 00 00       	call   0x4bc6e0
  4bc6d7:	8b c6                	mov    eax,esi
  4bc6d9:	5e                   	pop    esi
  4bc6da:	c3                   	ret
  4bc6db:	cc                   	int3
  4bc6dc:	cc                   	int3
  4bc6dd:	cc                   	int3
  4bc6de:	cc                   	int3
  4bc6df:	cc                   	int3

# CScenarioField_init 0x004C4750 raw=0x000C3B50 size=320 sha256=feb5add2623bf47b3e24b35fb8181d8e86746396149fd211843ef232d79a8be0

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4750 <.text+0xc3750>:
  4c4750:	55                   	push   ebp
  4c4751:	8b ec                	mov    ebp,esp
  4c4753:	83 e4 f8             	and    esp,0xfffffff8
  4c4756:	6a ff                	push   0xffffffff
  4c4758:	68 67 6b 93 00       	push   0x936b67
  4c475d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4763:	50                   	push   eax
  4c4764:	83 ec 08             	sub    esp,0x8
  4c4767:	57                   	push   edi
  4c4768:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c476d:	33 c4                	xor    eax,esp
  4c476f:	50                   	push   eax
  4c4770:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c4774:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c477a:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4c4781:	75 29                	jne    0x4c47ac
  4c4783:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4c478a:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4c4791:	00 
  4c4792:	e8 f9 a4 01 00       	call   0x4dec90
  4c4797:	68 30 ce bc 00       	push   0xbcce30
  4c479c:	e8 79 db 3c 00       	call   0x89231a
  4c47a1:	83 c4 04             	add    esp,0x4
  4c47a4:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4c47ab:	ff 
  4c47ac:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c47b2:	85 c9                	test   ecx,ecx
  4c47b4:	74 2b                	je     0x4c47e1
  4c47b6:	83 3d ac a7 fb 00 03 	cmp    DWORD PTR ds:0xfba7ac,0x3
  4c47bd:	75 09                	jne    0x4c47c8
  4c47bf:	8b f9                	mov    edi,ecx
  4c47c1:	e8 8a 07 08 00       	call   0x544f50
  4c47c6:	eb 56                	jmp    0x4c481e
  4c47c8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c47ca:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  4c47cd:	ff d2                	call   edx
  4c47cf:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c47d5:	85 c9                	test   ecx,ecx
  4c47d7:	74 08                	je     0x4c47e1
  4c47d9:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c47db:	8b 10                	mov    edx,DWORD PTR [eax]
  4c47dd:	6a 01                	push   0x1
  4c47df:	ff d2                	call   edx
  4c47e1:	68 c8 00 00 00       	push   0xc8
  4c47e6:	e8 7d ca 3c 00       	call   0x891268
  4c47eb:	83 c4 04             	add    esp,0x4
  4c47ee:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  4c47f2:	c7 44 24 18 03 00 00 	mov    DWORD PTR [esp+0x18],0x3
  4c47f9:	00 
  4c47fa:	85 c0                	test   eax,eax
  4c47fc:	74 08                	je     0x4c4806
  4c47fe:	50                   	push   eax
  4c47ff:	e8 8c 2b 08 00       	call   0x547390
  4c4804:	eb 02                	jmp    0x4c4808
  4c4806:	33 c0                	xor    eax,eax
  4c4808:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4c480f:	ff 
  4c4810:	8b 10                	mov    edx,DWORD PTR [eax]
  4c4812:	a3 a4 a7 fb 00       	mov    ds:0xfba7a4,eax
  4c4817:	8b c8                	mov    ecx,eax
  4c4819:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  4c481c:	ff d0                	call   eax
  4c481e:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4c4825:	75 29                	jne    0x4c4850
  4c4827:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4c482e:	c7 44 24 18 08 00 00 	mov    DWORD PTR [esp+0x18],0x8
  4c4835:	00 
  4c4836:	e8 45 2c 0c 00       	call   0x587480
  4c483b:	68 c0 cc bc 00       	push   0xbcccc0
  4c4840:	e8 d5 da 3c 00       	call   0x89231a
  4c4845:	83 c4 04             	add    esp,0x4
  4c4848:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4c484f:	ff 
  4c4850:	b8 07 00 00 00       	mov    eax,0x7
  4c4855:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4c485b:	74 18                	je     0x4c4875
  4c485d:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4c4862:	33 c0                	xor    eax,eax
  4c4864:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4c4868:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c486f:	59                   	pop    ecx
  4c4870:	5f                   	pop    edi
  4c4871:	8b e5                	mov    esp,ebp
  4c4873:	5d                   	pop    ebp
  4c4874:	c3                   	ret
  4c4875:	e8 26 61 0c 00       	call   0x58a9a0
  4c487a:	33 c0                	xor    eax,eax
  4c487c:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4c4880:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4887:	59                   	pop    ecx
  4c4888:	5f                   	pop    edi
  4c4889:	8b e5                	mov    esp,ebp
  4c488b:	5d                   	pop    ebp
  4c488c:	c3                   	ret
  4c488d:	cc                   	int3
  4c488e:	cc                   	int3
  4c488f:	cc                   	int3

# CMissionField_init 0x004BC750 raw=0x000BBB50 size=480 sha256=b97142a1235dd9b8a33e7bd5db3379af24859da74848e5e3ffa5f06190b2cf1d

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bc750 <.text+0xbb750>:
  4bc750:	55                   	push   ebp
  4bc751:	8b ec                	mov    ebp,esp
  4bc753:	83 e4 f8             	and    esp,0xfffffff8
  4bc756:	6a ff                	push   0xffffffff
  4bc758:	68 b1 48 94 00       	push   0x9448b1
  4bc75d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4bc763:	50                   	push   eax
  4bc764:	83 ec 0c             	sub    esp,0xc
  4bc767:	53                   	push   ebx
  4bc768:	57                   	push   edi
  4bc769:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4bc76e:	33 c4                	xor    eax,esp
  4bc770:	50                   	push   eax
  4bc771:	8d 44 24 18          	lea    eax,[esp+0x18]
  4bc775:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4bc77b:	83 cb ff             	or     ebx,0xffffffff
  4bc77e:	f6 05 78 13 fb 00 01 	test   BYTE PTR ds:0xfb1378,0x1
  4bc785:	8d 7b 02             	lea    edi,[ebx+0x2]
  4bc788:	75 24                	jne    0x4bc7ae
  4bc78a:	09 3d 78 13 fb 00    	or     DWORD PTR ds:0xfb1378,edi
  4bc790:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4bc797:	00 
  4bc798:	e8 83 d4 07 00       	call   0x539c20
  4bc79d:	68 b0 cf bc 00       	push   0xbccfb0
  4bc7a2:	e8 73 5b 3d 00       	call   0x89231a
  4bc7a7:	83 c4 04             	add    esp,0x4
  4bc7aa:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc7ae:	68 80 13 fb 00       	push   0xfb1380
  4bc7b3:	e8 28 f0 07 00       	call   0x53b7e0
  4bc7b8:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4bc7bf:	75 20                	jne    0x4bc7e1
  4bc7c1:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4bc7c7:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  4bc7cb:	e8 c0 24 02 00       	call   0x4dec90
  4bc7d0:	68 30 ce bc 00       	push   0xbcce30
  4bc7d5:	e8 40 5b 3d 00       	call   0x89231a
  4bc7da:	83 c4 04             	add    esp,0x4
  4bc7dd:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc7e1:	f6 05 00 b1 fa 00 01 	test   BYTE PTR ds:0xfab100,0x1
  4bc7e8:	75 24                	jne    0x4bc80e
  4bc7ea:	09 3d 00 b1 fa 00    	or     DWORD PTR ds:0xfab100,edi
  4bc7f0:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4bc7f7:	00 
  4bc7f8:	e8 a3 0e fe ff       	call   0x49d6a0
  4bc7fd:	68 20 ce bc 00       	push   0xbcce20
  4bc802:	e8 13 5b 3d 00       	call   0x89231a
  4bc807:	83 c4 04             	add    esp,0x4
  4bc80a:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc80e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4bc814:	85 c9                	test   ecx,ecx
  4bc816:	74 2f                	je     0x4bc847
  4bc818:	83 3d ac a7 fb 00 02 	cmp    DWORD PTR ds:0xfba7ac,0x2
  4bc81f:	75 0e                	jne    0x4bc82f
  4bc821:	8b f9                	mov    edi,ecx
  4bc823:	e8 28 87 08 00       	call   0x544f50
  4bc828:	bf 01 00 00 00       	mov    edi,0x1
  4bc82d:	eb 51                	jmp    0x4bc880
  4bc82f:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bc831:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  4bc834:	ff d2                	call   edx
  4bc836:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4bc83c:	85 c9                	test   ecx,ecx
  4bc83e:	74 07                	je     0x4bc847
  4bc840:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bc842:	8b 10                	mov    edx,DWORD PTR [eax]
  4bc844:	57                   	push   edi
  4bc845:	ff d2                	call   edx
  4bc847:	68 c0 00 00 00       	push   0xc0
  4bc84c:	e8 17 4a 3d 00       	call   0x891268
  4bc851:	83 c4 04             	add    esp,0x4
  4bc854:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4bc858:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  4bc85f:	00 
  4bc860:	85 c0                	test   eax,eax
  4bc862:	74 08                	je     0x4bc86c
  4bc864:	50                   	push   eax
  4bc865:	e8 d6 bc 08 00       	call   0x548540
  4bc86a:	eb 02                	jmp    0x4bc86e
  4bc86c:	33 c0                	xor    eax,eax
  4bc86e:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc872:	8b 10                	mov    edx,DWORD PTR [eax]
  4bc874:	a3 a4 a7 fb 00       	mov    ds:0xfba7a4,eax
  4bc879:	8b c8                	mov    ecx,eax
  4bc87b:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  4bc87e:	ff d0                	call   eax
  4bc880:	f6 05 a4 72 fb 00 01 	test   BYTE PTR ds:0xfb72a4,0x1
  4bc887:	75 24                	jne    0x4bc8ad
  4bc889:	09 3d a4 72 fb 00    	or     DWORD PTR ds:0xfb72a4,edi
  4bc88f:	c7 44 24 20 0a 00 00 	mov    DWORD PTR [esp+0x20],0xa
  4bc896:	00 
  4bc897:	e8 b4 2f fe ff       	call   0x49f850
  4bc89c:	68 e0 cf bc 00       	push   0xbccfe0
  4bc8a1:	e8 74 5a 3d 00       	call   0x89231a
  4bc8a6:	83 c4 04             	add    esp,0x4
  4bc8a9:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc8ad:	68 b8 72 fb 00       	push   0xfb72b8
  4bc8b2:	e8 09 47 02 00       	call   0x4e0fc0
  4bc8b7:	83 c4 04             	add    esp,0x4
  4bc8ba:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4bc8c1:	75 24                	jne    0x4bc8e7
  4bc8c3:	09 3d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,edi
  4bc8c9:	c7 44 24 20 0b 00 00 	mov    DWORD PTR [esp+0x20],0xb
  4bc8d0:	00 
  4bc8d1:	e8 aa ab 0c 00       	call   0x587480
  4bc8d6:	68 c0 cc bc 00       	push   0xbcccc0
  4bc8db:	e8 3a 5a 3d 00       	call   0x89231a
  4bc8e0:	83 c4 04             	add    esp,0x4
  4bc8e3:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc8e7:	b8 05 00 00 00       	mov    eax,0x5
  4bc8ec:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4bc8f2:	74 19                	je     0x4bc90d
  4bc8f4:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4bc8f9:	33 c0                	xor    eax,eax
  4bc8fb:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4bc8ff:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4bc906:	59                   	pop    ecx
  4bc907:	5f                   	pop    edi
  4bc908:	5b                   	pop    ebx
  4bc909:	8b e5                	mov    esp,ebp
  4bc90b:	5d                   	pop    ebp
  4bc90c:	c3                   	ret
  4bc90d:	e8 8e e0 0c 00       	call   0x58a9a0
  4bc912:	33 c0                	xor    eax,eax
  4bc914:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4bc918:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4bc91f:	59                   	pop    ecx
  4bc920:	5f                   	pop    edi
  4bc921:	5b                   	pop    ebx
  4bc922:	8b e5                	mov    esp,ebp
  4bc924:	5d                   	pop    ebp
  4bc925:	c3                   	ret
  4bc926:	cc                   	int3
  4bc927:	cc                   	int3
  4bc928:	cc                   	int3
  4bc929:	cc                   	int3
  4bc92a:	cc                   	int3
  4bc92b:	cc                   	int3
  4bc92c:	cc                   	int3
  4bc92d:	cc                   	int3
  4bc92e:	cc                   	int3
  4bc92f:	cc                   	int3

# CScenarioField_vtable 0x00C073B4 raw=0x008059B4 size=48 sha256=781cdb6e92bd261a62cfa1ef9aca462e818011726ce8eaf1629c1d1bf816a4ae
40594c0070464c0010284200f027420050474c00f0c28d0010db4a0090db4a0020dc4a0090484c0020494c0010494c00

# CMissionField_vtable 0x00C0705C raw=0x0080565C size=48 sha256=c474e836cd4b767bd9483587fc1fae6650bfa865005d34169ad6889bc73d5e7d
40594c0070464c0010284200f027420050c74b0010bf4b006030420090db4a0020dc4a0090484c0040064b00f0304200

# S2C_0012_map_selector_reset 0x004B24F0 raw=0x000B18F0 size=128 sha256=a342655520816c2a7eb6d432a9bb3132855c78c06ac31317e721bea728887045

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b24f0 <.text+0xb14f0>:
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
  4b2566:	cc                   	int3
  4b2567:	cc                   	int3
  4b2568:	cc                   	int3
  4b2569:	cc                   	int3
  4b256a:	cc                   	int3
  4b256b:	cc                   	int3
  4b256c:	cc                   	int3
  4b256d:	cc                   	int3
  4b256e:	cc                   	int3
  4b256f:	cc                   	int3

# MapList_TRIGGER_lookup_then_other_field 0x004DF538 raw=0x000DE938 size=188 sha256=fe6921b5767dd0d1aef54dadd4d08c7fa122e8ecd93be61bfa428305d7e2b58f

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004df538 <.text+0xde538>:
  4df538:	8b 75 0c             	mov    esi,DWORD PTR [ebp+0xc]
  4df53b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4df53e:	39 70 48             	cmp    DWORD PTR [eax+0x48],esi
  4df541:	0f 84 cc 04 00 00    	je     0x4dfa13
  4df547:	f6 05 b0 75 fb 00 01 	test   BYTE PTR ds:0xfb75b0,0x1
  4df54e:	89 70 48             	mov    DWORD PTR [eax+0x48],esi
  4df551:	bf 01 00 00 00       	mov    edi,0x1
  4df556:	75 27                	jne    0x4df57f
  4df558:	09 3d b0 75 fb 00    	or     DWORD PTR ds:0xfb75b0,edi
  4df55e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4df565:	e8 16 48 01 00       	call   0x4f3d80
  4df56a:	68 e0 d1 bc 00       	push   0xbcd1e0
  4df56f:	e8 a6 2d 3b 00       	call   0x89231a
  4df574:	83 c4 04             	add    esp,0x4
  4df577:	83 cb ff             	or     ebx,0xffffffff
  4df57a:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4df57d:	eb 03                	jmp    0x4df582
  4df57f:	83 cb ff             	or     ebx,0xffffffff
  4df582:	8d 55 f0             	lea    edx,[ebp-0x10]
  4df585:	b9 c0 74 fb 00       	mov    ecx,0xfb74c0
  4df58a:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4df58d:	e8 5e 88 01 00       	call   0x4f7df0
  4df592:	f6 05 b0 75 fb 00 01 	test   BYTE PTR ds:0xfb75b0,0x1
  4df599:	75 1e                	jne    0x4df5b9
  4df59b:	09 3d b0 75 fb 00    	or     DWORD PTR ds:0xfb75b0,edi
  4df5a1:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4df5a4:	e8 d7 47 01 00       	call   0x4f3d80
  4df5a9:	68 e0 d1 bc 00       	push   0xbcd1e0
  4df5ae:	e8 67 2d 3b 00       	call   0x89231a
  4df5b3:	83 c4 04             	add    esp,0x4
  4df5b6:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4df5b9:	8d 45 f0             	lea    eax,[ebp-0x10]
  4df5bc:	50                   	push   eax
  4df5bd:	8d 45 ec             	lea    eax,[ebp-0x14]
  4df5c0:	b9 e0 74 fb 00       	mov    ecx,0xfb74e0
  4df5c5:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4df5c8:	e8 23 08 fa ff       	call   0x47fdf0
  4df5cd:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  4df5d0:	3b 05 e4 74 fb 00    	cmp    eax,DWORD PTR ds:0xfb74e4
  4df5d6:	74 1c                	je     0x4df5f4
  4df5d8:	83 c0 10             	add    eax,0x10
  4df5db:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  4df5df:	72 02                	jb     0x4df5e3
  4df5e1:	8b 00                	mov    eax,DWORD PTR [eax]
  4df5e3:	8b c8                	mov    ecx,eax
  4df5e5:	bf 70 74 fb 00       	mov    edi,0xfb7470
  4df5ea:	e8 91 78 01 00       	call   0x4f6e80
  4df5ef:	bf 01 00 00 00       	mov    edi,0x1

# alternate_scene_start_full_bounded_function 0x00565720 raw=0x00164B20 size=880 sha256=8c557826d2d92cd54a0b9c61120c63a6dbbe328b49160280ad2ad816736bb94b

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00565720 <.text+0x164720>:
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

# review_UI_event_routing 0x0047C5D0 raw=0x0007B9D0 size=272 sha256=6d08c392743e04a0e77efa871905fb6110880c1c79a516471e33b6ca280804e5

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047c5d0 <.text+0x7b5d0>:
  47c5d0:	55                   	push   ebp
  47c5d1:	8b ec                	mov    ebp,esp
  47c5d3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47c5d6:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  47c5d9:	2d 78 05 00 00       	sub    eax,0x578
  47c5de:	0f 84 90 00 00 00    	je     0x47c674
  47c5e4:	2d 92 01 00 00       	sub    eax,0x192
  47c5e9:	74 4e                	je     0x47c639
  47c5eb:	48                   	dec    eax
  47c5ec:	0f 85 e6 00 00 00    	jne    0x47c6d8
  47c5f2:	81 7a 08 a0 0f 00 00 	cmp    DWORD PTR [edx+0x8],0xfa0
  47c5f9:	0f 83 d9 00 00 00    	jae    0x47c6d8
  47c5ff:	8b 81 f8 00 00 00    	mov    eax,DWORD PTR [ecx+0xf8]
  47c605:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c60b:	85 c0                	test   eax,eax
  47c60d:	74 17                	je     0x47c626
  47c60f:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  47c615:	8b 80 48 02 00 00    	mov    eax,DWORD PTR [eax+0x248]
  47c61b:	50                   	push   eax
  47c61c:	51                   	push   ecx
  47c61d:	e8 de 04 00 00       	call   0x47cb00
  47c622:	5d                   	pop    ebp
  47c623:	c2 04 00             	ret    0x4
  47c626:	33 c0                	xor    eax,eax
  47c628:	8b 80 48 02 00 00    	mov    eax,DWORD PTR [eax+0x248]
  47c62e:	50                   	push   eax
  47c62f:	51                   	push   ecx
  47c630:	e8 cb 04 00 00       	call   0x47cb00
  47c635:	5d                   	pop    ebp
  47c636:	c2 04 00             	ret    0x4
  47c639:	81 7a 08 88 13 00 00 	cmp    DWORD PTR [edx+0x8],0x1388
  47c640:	0f 82 92 00 00 00    	jb     0x47c6d8
  47c646:	8b 81 fc 00 00 00    	mov    eax,DWORD PTR [ecx+0xfc]
  47c64c:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c652:	85 c0                	test   eax,eax
  47c654:	74 11                	je     0x47c667
  47c656:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  47c65c:	50                   	push   eax
  47c65d:	51                   	push   ecx
  47c65e:	e8 ad 11 00 00       	call   0x47d810
  47c663:	5d                   	pop    ebp
  47c664:	c2 04 00             	ret    0x4
  47c667:	33 c0                	xor    eax,eax
  47c669:	50                   	push   eax
  47c66a:	51                   	push   ecx
  47c66b:	e8 a0 11 00 00       	call   0x47d810
  47c670:	5d                   	pop    ebp
  47c671:	c2 04 00             	ret    0x4
  47c674:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  47c677:	8b 91 08 01 00 00    	mov    edx,DWORD PTR [ecx+0x108]
  47c67d:	39 42 20             	cmp    DWORD PTR [edx+0x20],eax
  47c680:	75 0e                	jne    0x47c690
  47c682:	8b 01                	mov    eax,DWORD PTR [ecx]
  47c684:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  47c68a:	ff d2                	call   edx
  47c68c:	5d                   	pop    ebp
  47c68d:	c2 04 00             	ret    0x4
  47c690:	8b 91 04 01 00 00    	mov    edx,DWORD PTR [ecx+0x104]
  47c696:	39 42 20             	cmp    DWORD PTR [edx+0x20],eax
  47c699:	75 29                	jne    0x47c6c4
  47c69b:	8b 81 fc 00 00 00    	mov    eax,DWORD PTR [ecx+0xfc]
  47c6a1:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c6a7:	85 c0                	test   eax,eax
  47c6a9:	74 08                	je     0x47c6b3
  47c6ab:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  47c6b1:	eb 02                	jmp    0x47c6b5
  47c6b3:	33 c0                	xor    eax,eax
  47c6b5:	85 c0                	test   eax,eax
  47c6b7:	74 1f                	je     0x47c6d8
  47c6b9:	50                   	push   eax
  47c6ba:	51                   	push   ecx
  47c6bb:	e8 50 11 00 00       	call   0x47d810
  47c6c0:	5d                   	pop    ebp
  47c6c1:	c2 04 00             	ret    0x4
  47c6c4:	8b 91 00 01 00 00    	mov    edx,DWORD PTR [ecx+0x100]
  47c6ca:	39 42 20             	cmp    DWORD PTR [edx+0x20],eax
  47c6cd:	75 09                	jne    0x47c6d8
  47c6cf:	56                   	push   esi
  47c6d0:	8b f1                	mov    esi,ecx
  47c6d2:	e8 b9 0d 00 00       	call   0x47d490
  47c6d7:	5e                   	pop    esi
  47c6d8:	5d                   	pop    ebp
  47c6d9:	c2 04 00             	ret    0x4
  47c6dc:	cc                   	int3
  47c6dd:	cc                   	int3
  47c6de:	cc                   	int3
  47c6df:	cc                   	int3

# review_party_gate 0x0047D86A raw=0x0007CC6A size=31 sha256=8cdd2b2360177dec10e2f569ed4649763c25cea30b4e0b361cbfd6d13c41122d

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047d86a <.text+0x7c86a>:
  47d86a:	a1 58 72 fb 00       	mov    eax,ds:0xfb7258
  47d86f:	3b c3                	cmp    eax,ebx
  47d871:	0f 84 5d 01 00 00    	je     0x47d9d4
  47d877:	8b 48 2c             	mov    ecx,DWORD PTR [eax+0x2c]
  47d87a:	2b 48 28             	sub    ecx,DWORD PTR [eax+0x28]
  47d87d:	83 e1 fc             	and    ecx,0xfffffffc
  47d880:	83 f9 04             	cmp    ecx,0x4
  47d883:	0f 84 45 01 00 00    	je     0x47d9ce

# review_party_gate_accept_tail 0x0047D9CE raw=0x0007CDCE size=50 sha256=8744dc6e81857cba1512e5323908e531aa11b4a60dbc3a9fa2d4ec013a0ca4e6

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047d9ce <.text+0x7c9ce>:
  47d9ce:	50                   	push   eax
  47d9cf:	e8 1c c1 0b 00       	call   0x539af0
  47d9d4:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  47d9d7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47d9da:	e8 51 fb ff ff       	call   0x47d530
  47d9df:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d9e2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d9e9:	59                   	pop    ecx
  47d9ea:	5f                   	pop    edi
  47d9eb:	5e                   	pop    esi
  47d9ec:	5b                   	pop    ebx
  47d9ed:	8b e5                	mov    esp,ebp
  47d9ef:	5d                   	pop    ebp
  47d9f0:	c2 08 00             	ret    0x8
  47d9f3:	cc                   	int3
  47d9f4:	cc                   	int3
  47d9f5:	cc                   	int3
  47d9f6:	cc                   	int3
  47d9f7:	cc                   	int3
  47d9f8:	cc                   	int3
  47d9f9:	cc                   	int3
  47d9fa:	cc                   	int3
  47d9fb:	cc                   	int3
  47d9fc:	cc                   	int3
  47d9fd:	cc                   	int3
  47d9fe:	cc                   	int3
  47d9ff:	cc                   	int3

# review_selected_record_to_scene_key 0x0047D530 raw=0x0007C930 size=140 sha256=1afab9bddcd1096e2b55fbbeefb5ac7b54cbb9ef3f48309378610a8186961c5e

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047d530 <.text+0x7c530>:
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0

# review_first_scene_key_lookup 0x0047E890 raw=0x0007DC90 size=272 sha256=abc70333086fca2010e319d197042b9d1471cd104e72c73e9121c68503351805

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047e890 <.text+0x7d890>:
  47e890:	55                   	push   ebp
  47e891:	8b ec                	mov    ebp,esp
  47e893:	6a ff                	push   0xffffffff
  47e895:	68 b8 8a 90 00       	push   0x908ab8
  47e89a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e8a0:	50                   	push   eax
  47e8a1:	83 ec 14             	sub    esp,0x14
  47e8a4:	53                   	push   ebx
  47e8a5:	56                   	push   esi
  47e8a6:	57                   	push   edi
  47e8a7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e8ac:	33 c5                	xor    eax,ebp
  47e8ae:	50                   	push   eax
  47e8af:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e8b2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e8b8:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8bb:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  47e8be:	8b 33                	mov    esi,DWORD PTR [ebx]
  47e8c0:	3b f3                	cmp    esi,ebx
  47e8c2:	74 67                	je     0x47e92b
  47e8c4:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  47e8c7:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e8ca:	51                   	push   ecx
  47e8cb:	8d 4f 34             	lea    ecx,[edi+0x34]
  47e8ce:	8d 45 08             	lea    eax,[ebp+0x8]
  47e8d1:	e8 fa e5 0a 00       	call   0x52ced0
  47e8d6:	8b 7f 38             	mov    edi,DWORD PTR [edi+0x38]
  47e8d9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8dc:	3b c7                	cmp    eax,edi
  47e8de:	75 61                	jne    0x47e941
  47e8e0:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  47e8e4:	75 41                	jne    0x47e927
  47e8e6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  47e8e9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e8ed:	75 1d                	jne    0x47e90c
  47e8ef:	8b f0                	mov    esi,eax
  47e8f1:	8b 06                	mov    eax,DWORD PTR [esi]
  47e8f3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e8f7:	75 2e                	jne    0x47e927
  47e8f9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47e900:	8b f0                	mov    esi,eax
  47e902:	8b 06                	mov    eax,DWORD PTR [esi]
  47e904:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e908:	74 f6                	je     0x47e900
  47e90a:	eb 1b                	jmp    0x47e927
  47e90c:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  47e90f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e913:	75 10                	jne    0x47e925
  47e915:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  47e918:	75 0b                	jne    0x47e925
  47e91a:	8b f0                	mov    esi,eax
  47e91c:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  47e91f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e923:	74 f0                	je     0x47e915
  47e925:	8b f0                	mov    esi,eax
  47e927:	3b f3                	cmp    esi,ebx
  47e929:	75 99                	jne    0x47e8c4
  47e92b:	33 c0                	xor    eax,eax
  47e92d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e930:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e937:	59                   	pop    ecx
  47e938:	5f                   	pop    edi
  47e939:	5e                   	pop    esi
  47e93a:	5b                   	pop    ebx
  47e93b:	8b e5                	mov    esp,ebp
  47e93d:	5d                   	pop    ebp
  47e93e:	c2 08 00             	ret    0x8
  47e941:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  47e944:	83 c0 14             	add    eax,0x14
  47e947:	50                   	push   eax
  47e948:	8d 45 e4             	lea    eax,[ebp-0x1c]
  47e94b:	50                   	push   eax
  47e94c:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  47e94f:	e8 3c a1 36 00       	call   0x7e8a90
  47e954:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e95b:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47e95e:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  47e961:	2b c8                	sub    ecx,eax
  47e963:	c1 f9 02             	sar    ecx,0x2
  47e966:	85 c9                	test   ecx,ecx
  47e968:	75 0a                	jne    0x47e974
  47e96a:	68 08 34 bf 00       	push   0xbf3408
  47e96f:	e8 09 f2 3f 00       	call   0x87db7d
  47e974:	8b 30                	mov    esi,DWORD PTR [eax]
  47e976:	50                   	push   eax
  47e977:	e8 90 28 41 00       	call   0x89120c
  47e97c:	83 c4 04             	add    esp,0x4
  47e97f:	8b c6                	mov    eax,esi
  47e981:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e984:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e98b:	59                   	pop    ecx
  47e98c:	5f                   	pop    edi
  47e98d:	5e                   	pop    esi
  47e98e:	5b                   	pop    ebx
  47e98f:	8b e5                	mov    esp,ebp
  47e991:	5d                   	pop    ebp
  47e992:	c2 08 00             	ret    0x8
  47e995:	cc                   	int3
  47e996:	cc                   	int3
  47e997:	cc                   	int3
  47e998:	cc                   	int3
  47e999:	cc                   	int3
  47e99a:	cc                   	int3
  47e99b:	cc                   	int3
  47e99c:	cc                   	int3
  47e99d:	cc                   	int3
  47e99e:	cc                   	int3
  47e99f:	cc                   	int3

# review_60001_special_case_and_normal_keys 0x0047B5E9 raw=0x0007A9E9 size=102 sha256=8112a8db4c6bb95a6334ac59fff695e14e5db82dc741dd855d6d180986049367

project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047b5e9 <.text+0x7a5e9>:
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720

# review_vtable_and_RTTI_pointer 0x00C03128 raw=0x00801728 size=356 sha256=7012bb9649c3ec3fe96a409dc54db06bff9958f49e0f570d9523029bae5c250b
948bc600e0824800907240009072400080724000e03d4000005f7500405f7500e0c44700f071400040714000807040002064580030557400f0567400800b7600205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f00e06f7400d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b740080707500703d4000d05a7400205b7400b0ca470000db4400f0a07400503d4000b03d4000403d40005004550000da4700e0674000d0877400f08774006071750060717500105d5f00105d5f00105d5f00a0c54700e0c64700b06a7400d06a7400f06a7400106b7400800c7600105d5f00105d5f0050045500d06f400020a1740050d5650030644700805f7500e0674000e06740003064470030644700d0c54700

# review_RTTI_complete_object_locator 0x00C68B94 raw=0x00867194 size=20 sha256=9cae13210d440a8a7d8ce7deec21be32a1d3c27cfab5b6795dff3a922768f0ac
000000000000000000000000e4d8f700a88bc600

# review_RTTI_type_descriptor 0x00F7D8E4 raw=0x00B7B0E4 size=36 sha256=ea39e69dd733921d6b63ad1cf1a49faf96dfbe9f42db5eabcd56c2e223472901
f435bd00000000002e3f4156435363656e6172696f526576696577576e64404655494040

# RESEARCH GROUP: lifecycle

## client-update-owner-argument: [0x490fe0, 0x491029)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00490fe0 <.text+0x8ffe0>:
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

## client-update-current-field-slot18: [0x491ca7, 0x491d03)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00491ca7 <.text+0x90ca7>:
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

## client-update-global-scene-pump: [0x491e71, 0x491edc)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00491e71 <.text+0x90e71>:
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

## current-scene-manager-getter: [0x489cb0, 0x489cef)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00489cb0 <.text+0x88cb0>:
  489cb0:	b8 01 00 00 00       	mov    eax,0x1
  489cb5:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  489cbb:	75 2c                	jne    0x489ce9
  489cbd:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  489cc3:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  489cca:	6e c0 00 
  489ccd:	c7 05 a4 8b fd 00 00 	mov    DWORD PTR ds:0xfd8ba4,0x0
  489cd4:	00 00 00 
  489cd7:	e8 e4 e0 02 00       	call   0x4b7dc0
  489cdc:	68 f0 dc bc 00       	push   0xbcdcf0
  489ce1:	e8 34 86 40 00       	call   0x89231a
  489ce6:	83 c4 04             	add    esp,0x4
  489ce9:	b8 f8 2c fd 00       	mov    eax,0xfd2cf8
  489cee:	c3                   	ret

## q-manager-singleton-getter: [0x422f40, 0x422fa2)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00422f40 <.text+0x21f40>:
  422f40:	55                   	push   ebp
  422f41:	8b ec                	mov    ebp,esp
  422f43:	6a ff                	push   0xffffffff
  422f45:	68 ae b2 93 00       	push   0x93b2ae
  422f4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  422f50:	50                   	push   eax
  422f51:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  422f56:	33 c5                	xor    eax,ebp
  422f58:	50                   	push   eax
  422f59:	8d 45 f4             	lea    eax,[ebp-0xc]
  422f5c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  422f62:	b8 01 00 00 00       	mov    eax,0x1
  422f67:	84 05 b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,al
  422f6d:	75 1f                	jne    0x422f8e
  422f6f:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  422f75:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  422f7c:	e8 ef d1 13 00       	call   0x560170
  422f81:	68 10 d1 bc 00       	push   0xbcd110
  422f86:	e8 8f f3 46 00       	call   0x89231a
  422f8b:	83 c4 04             	add    esp,0x4
  422f8e:	b8 c0 73 fb 00       	mov    eax,0xfb73c0
  422f93:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  422f96:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  422f9d:	59                   	pop    ecx
  422f9e:	8b e5                	mov    esp,ebp
  422fa0:	5d                   	pop    ebp
  422fa1:	c3                   	ret

## q-manager-constructor-state: [0x560170, 0x5602db)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00560170 <.text+0x15f170>:
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

## q-formal-wrapper-install: [0x560600, 0x56061c)

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

## q-formal-root-script-loads: [0x56078f, 0x5607c3)

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

## q-update-gates-and-object-tick: [0x561520, 0x561678)

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

## q-end-scene-both-modes: [0x561db0, 0x5620aa)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561db0 <.text+0x160db0>:
  561db0:	55                   	push   ebp
  561db1:	8b ec                	mov    ebp,esp
  561db3:	83 e4 f8             	and    esp,0xfffffff8
  561db6:	6a ff                	push   0xffffffff
  561db8:	68 64 fc 93 00       	push   0x93fc64
  561dbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561dc3:	50                   	push   eax
  561dc4:	83 ec 10             	sub    esp,0x10
  561dc7:	53                   	push   ebx
  561dc8:	56                   	push   esi
  561dc9:	57                   	push   edi
  561dca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  561dcf:	33 c4                	xor    eax,esp
  561dd1:	50                   	push   eax
  561dd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  561dd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561ddc:	8b f9                	mov    edi,ecx
  561dde:	33 f6                	xor    esi,esi
  561de0:	80 bf 89 00 00 00 00 	cmp    BYTE PTR [edi+0x89],0x0
  561de7:	0f 84 73 01 00 00    	je     0x561f60
  561ded:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561df0:	0f 84 aa 00 00 00    	je     0x561ea0
  561df6:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561df9:	e8 52 24 ed ff       	call   0x434250
  561dfe:	bb 01 00 00 00       	mov    ebx,0x1
  561e03:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561e06:	84 1d d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,bl
  561e0c:	75 25                	jne    0x561e33
  561e0e:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  561e14:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e18:	e8 63 25 19 00       	call   0x6f4380
  561e1d:	68 d0 e6 bc 00       	push   0xbce6d0
  561e22:	e8 f3 04 33 00       	call   0x89231a
  561e27:	83 c4 04             	add    esp,0x4
  561e2a:	83 ce ff             	or     esi,0xffffffff
  561e2d:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e31:	eb 03                	jmp    0x561e36
  561e33:	83 ce ff             	or     esi,0xffffffff
  561e36:	68 ec 06 c1 00       	push   0xc106ec
  561e3b:	6a 00                	push   0x0
  561e3d:	68 c8 f3 fd 00       	push   0xfdf3c8
  561e42:	e8 59 b2 f4 ff       	call   0x4ad0a0
  561e47:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  561e4e:	75 20                	jne    0x561e70
  561e50:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  561e56:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  561e5a:	e8 21 56 02 00       	call   0x587480
  561e5f:	68 c0 cc bc 00       	push   0xbcccc0
  561e64:	e8 b1 04 33 00       	call   0x89231a
  561e69:	83 c4 04             	add    esp,0x4
  561e6c:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e70:	d9 87 84 00 00 00    	fld    DWORD PTR [edi+0x84]
  561e76:	83 ec 08             	sub    esp,0x8
  561e79:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  561e7d:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  561e81:	d9 54 24 04          	fst    DWORD PTR [esp+0x4]
  561e85:	d9 1c 24             	fstp   DWORD PTR [esp]
  561e88:	e8 93 7b 02 00       	call   0x589a20
  561e8d:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  561e93:	e8 08 2d ea ff       	call   0x404ba0
  561e98:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  561e9e:	eb 03                	jmp    0x561ea3
  561ea0:	83 ce ff             	or     esi,0xffffffff
  561ea3:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  561eaa:	75 25                	jne    0x561ed1
  561eac:	83 0d 64 0f fc 00 01 	or     DWORD PTR ds:0xfc0f64,0x1
  561eb3:	c7 44 24 28 02 00 00 	mov    DWORD PTR [esp+0x28],0x2
  561eba:	00 
  561ebb:	e8 20 be f1 ff       	call   0x47dce0
  561ec0:	68 f0 da bc 00       	push   0xbcdaf0
  561ec5:	e8 50 04 33 00       	call   0x89231a
  561eca:	83 c4 04             	add    esp,0x4
  561ecd:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561ed1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  561ed4:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561ed7:	50                   	push   eax
  561ed8:	51                   	push   ecx
  561ed9:	68 68 0f fc 00       	push   0xfc0f68
  561ede:	e8 5d c7 f1 ff       	call   0x47e640
  561ee3:	33 db                	xor    ebx,ebx
  561ee5:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  561ee8:	3b c3                	cmp    eax,ebx
  561eea:	74 1f                	je     0x561f0b
  561eec:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561eef:	50                   	push   eax
  561ef0:	52                   	push   edx
  561ef1:	8b f7                	mov    esi,edi
  561ef3:	e8 28 38 00 00       	call   0x565720
  561ef8:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561efc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f03:	59                   	pop    ecx
  561f04:	5f                   	pop    edi
  561f05:	5e                   	pop    esi
  561f06:	5b                   	pop    ebx
  561f07:	8b e5                	mov    esp,ebp
  561f09:	5d                   	pop    ebp
  561f0a:	c3                   	ret
  561f0b:	f6 05 c0 0f fc 00 01 	test   BYTE PTR ds:0xfc0fc0,0x1
  561f12:	75 25                	jne    0x561f39
  561f14:	83 0d c0 0f fc 00 01 	or     DWORD PTR ds:0xfc0fc0,0x1
  561f1b:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  561f22:	00 
  561f23:	e8 28 6f 17 00       	call   0x6d8e50
  561f28:	68 b0 db bc 00       	push   0xbcdbb0
  561f2d:	e8 e8 03 33 00       	call   0x89231a
  561f32:	83 c4 04             	add    esp,0x4
  561f35:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561f39:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  561f3c:	50                   	push   eax
  561f3d:	b9 c8 0f fc 00       	mov    ecx,0xfc0fc8
  561f42:	e8 e9 74 17 00       	call   0x6d9430
  561f47:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  561f4a:	89 5f 3c             	mov    DWORD PTR [edi+0x3c],ebx
  561f4d:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561f51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f58:	59                   	pop    ecx
  561f59:	5f                   	pop    edi
  561f5a:	5e                   	pop    esi
  561f5b:	5b                   	pop    ebx
  561f5c:	8b e5                	mov    esp,ebp
  561f5e:	5d                   	pop    ebp
  561f5f:	c3                   	ret
  561f60:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561f63:	0f 84 28 01 00 00    	je     0x562091
  561f69:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561f6c:	e8 df 22 ed ff       	call   0x434250
  561f71:	bb 01 00 00 00       	mov    ebx,0x1
  561f76:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561f79:	39 77 38             	cmp    DWORD PTR [edi+0x38],esi
  561f7c:	74 39                	je     0x561fb7
  561f7e:	68 44 03 c1 00       	push   0xc10344
  561f83:	53                   	push   ebx
  561f84:	e8 a7 92 f3 ff       	call   0x49b230
  561f89:	50                   	push   eax
  561f8a:	e8 11 b1 f4 ff       	call   0x4ad0a0
  561f8f:	6a ff                	push   0xffffffff
  561f91:	51                   	push   ecx
  561f92:	e8 99 92 f3 ff       	call   0x49b230
  561f97:	83 c4 04             	add    esp,0x4
  561f9a:	e8 b1 0b f4 ff       	call   0x4a2b50
  561f9f:	3b c3                	cmp    eax,ebx
  561fa1:	75 4e                	jne    0x561ff1
  561fa3:	e8 d8 26 eb ff       	call   0x414680
  561fa8:	8b 4f 3c             	mov    ecx,DWORD PTR [edi+0x3c]
  561fab:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561fae:	51                   	push   ecx
  561faf:	52                   	push   edx
  561fb0:	e8 eb 19 f4 ff       	call   0x4a39a0
  561fb5:	eb 3a                	jmp    0x561ff1
  561fb7:	8d 5f 3c             	lea    ebx,[edi+0x3c]
  561fba:	8d 77 74             	lea    esi,[edi+0x74]
  561fbd:	53                   	push   ebx
  561fbe:	e8 7d be 15 00       	call   0x6bde40
  561fc3:	50                   	push   eax
  561fc4:	56                   	push   esi
  561fc5:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  561fc9:	e8 c2 48 ed ff       	call   0x436890
  561fce:	57                   	push   edi
  561fcf:	e8 cc 03 00 00       	call   0x5623a0
  561fd4:	e8 a7 26 eb ff       	call   0x414680
  561fd9:	8b 03                	mov    eax,DWORD PTR [ebx]
  561fdb:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561fde:	50                   	push   eax
  561fdf:	51                   	push   ecx
  561fe0:	e8 bb 19 f4 ff       	call   0x4a39a0
  561fe5:	e8 c6 00 00 00       	call   0x5620b0
  561fea:	bb 01 00 00 00       	mov    ebx,0x1
  561fef:	33 f6                	xor    esi,esi
  561ff1:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  561ff8:	75 28                	jne    0x562022
  561ffa:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  562000:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  562007:	00 
  562008:	e8 73 23 19 00       	call   0x6f4380
  56200d:	68 d0 e6 bc 00       	push   0xbce6d0
  562012:	e8 03 03 33 00       	call   0x89231a
  562017:	83 c4 04             	add    esp,0x4
  56201a:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  562021:	ff 
  562022:	68 ec 06 c1 00       	push   0xc106ec
  562027:	56                   	push   esi
  562028:	68 c8 f3 fd 00       	push   0xfdf3c8
  56202d:	e8 6e b0 f4 ff       	call   0x4ad0a0
  562032:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  562039:	75 28                	jne    0x562063
  56203b:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  562041:	c7 44 24 28 05 00 00 	mov    DWORD PTR [esp+0x28],0x5
  562048:	00 
  562049:	e8 32 54 02 00       	call   0x587480
  56204e:	68 c0 cc bc 00       	push   0xbcccc0
  562053:	e8 c2 02 33 00       	call   0x89231a
  562058:	83 c4 04             	add    esp,0x4
  56205b:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  562062:	ff 
  562063:	d9 87 84 00 00 00    	fld    DWORD PTR [edi+0x84]
  562069:	83 ec 08             	sub    esp,0x8
  56206c:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  562070:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  562074:	d9 54 24 04          	fst    DWORD PTR [esp+0x4]
  562078:	d9 1c 24             	fstp   DWORD PTR [esp]
  56207b:	e8 a0 79 02 00       	call   0x589a20
  562080:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  562086:	e8 15 2b ea ff       	call   0x404ba0
  56208b:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  562091:	89 77 38             	mov    DWORD PTR [edi+0x38],esi
  562094:	89 77 3c             	mov    DWORD PTR [edi+0x3c],esi
  562097:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  56209b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5620a2:	59                   	pop    ecx
  5620a3:	5f                   	pop    edi
  5620a4:	5e                   	pop    esi
  5620a5:	5b                   	pop    ebx
  5620a6:	8b e5                	mov    esp,ebp
  5620a8:	5d                   	pop    ebp
  5620a9:	c3                   	ret

## q-stop-gate: [0x5624b0, 0x562527)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005624b0 <.text+0x1614b0>:
  5624b0:	55                   	push   ebp
  5624b1:	8b ec                	mov    ebp,esp
  5624b3:	83 e4 f8             	and    esp,0xfffffff8
  5624b6:	6a ff                	push   0xffffffff
  5624b8:	68 60 3d 94 00       	push   0x943d60
  5624bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5624c3:	50                   	push   eax
  5624c4:	83 ec 28             	sub    esp,0x28
  5624c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5624cc:	33 c4                	xor    eax,esp
  5624ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  5624d2:	53                   	push   ebx
  5624d3:	56                   	push   esi
  5624d4:	57                   	push   edi
  5624d5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5624da:	33 c4                	xor    eax,esp
  5624dc:	50                   	push   eax
  5624dd:	8d 44 24 38          	lea    eax,[esp+0x38]
  5624e1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5624e7:	33 f6                	xor    esi,esi
  5624e9:	8b f9                	mov    edi,ecx
  5624eb:	89 7c 24 10          	mov    DWORD PTR [esp+0x10],edi
  5624ef:	39 75 08             	cmp    DWORD PTR [ebp+0x8],esi
  5624f2:	74 2a                	je     0x56251e
  5624f4:	81 7f 38 e8 03 00 00 	cmp    DWORD PTR [edi+0x38],0x3e8
  5624fb:	75 21                	jne    0x56251e
  5624fd:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  562500:	83 f8 0f             	cmp    eax,0xf
  562503:	74 0f                	je     0x562514
  562505:	83 f8 10             	cmp    eax,0x10
  562508:	74 0a                	je     0x562514
  56250a:	83 f8 11             	cmp    eax,0x11
  56250d:	74 05                	je     0x562514
  56250f:	83 f8 12             	cmp    eax,0x12
  562512:	75 0a                	jne    0x56251e
  562514:	c7 05 a0 a7 fb 00 01 	mov    DWORD PTR ds:0xfba7a0,0x1
  56251b:	00 00 00 
  56251e:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  562521:	0f 84 6a 03 00 00    	je     0x562891

## q-stop-owned-state-callees: [0x5625fb, 0x5626a2)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005625fb <.text+0x1615fb>:
  5625fb:	8b 47 54             	mov    eax,DWORD PTR [edi+0x54]
  5625fe:	bf 04 00 00 00       	mov    edi,0x4
  562603:	3b c6                	cmp    eax,esi
  562605:	0f 85 7c 00 00 00    	jne    0x562687
  56260b:	f6 05 e8 1e fe 00 01 	test   BYTE PTR ds:0xfe1ee8,0x1
  562612:	75 25                	jne    0x562639
  562614:	83 0d e8 1e fe 00 01 	or     DWORD PTR ds:0xfe1ee8,0x1
  56261b:	c7 44 24 40 03 00 00 	mov    DWORD PTR [esp+0x40],0x3
  562622:	00 
  562623:	e8 e8 9f ff ff       	call   0x55c610
  562628:	68 90 f2 bc 00       	push   0xbcf290
  56262d:	e8 e8 fc 32 00       	call   0x89231a
  562632:	83 c4 04             	add    esp,0x4
  562635:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  562639:	68 ec 1e fe 00       	push   0xfe1eec
  56263e:	8d 74 24 18          	lea    esi,[esp+0x18]
  562642:	e8 79 d9 ff ff       	call   0x55ffc0
  562647:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56264b:	50                   	push   eax
  56264c:	83 c1 44             	add    ecx,0x44
  56264f:	89 7c 24 44          	mov    DWORD PTR [esp+0x44],edi
  562653:	e8 58 05 ea ff       	call   0x402bb0
  562658:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  56265c:	83 7c 24 28 10       	cmp    DWORD PTR [esp+0x28],0x10
  562661:	72 0d                	jb     0x562670
  562663:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  562667:	50                   	push   eax
  562668:	e8 9f eb 32 00       	call   0x89120c
  56266d:	83 c4 04             	add    esp,0x4
  562670:	c7 44 24 28 0f 00 00 	mov    DWORD PTR [esp+0x28],0xf
  562677:	00 
  562678:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  56267f:	00 
  562680:	c6 44 24 14 00       	mov    BYTE PTR [esp+0x14],0x0
  562685:	33 f6                	xor    esi,esi
  562687:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56268b:	e8 10 19 00 00       	call   0x563fa0
  562690:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  562694:	e8 d7 13 00 00       	call   0x563a70
  562699:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56269d:	e8 5e 04 00 00       	call   0x562b00

## q-stop-calls-end-scene: [0x56284a, 0x5628b1)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0056284a <.text+0x16184a>:
  56284a:	83 25 30 88 fb 00 fd 	and    DWORD PTR ds:0xfb8830,0xfffffffd
  562851:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  562858:	75 24                	jne    0x56287e
  56285a:	09 3d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,edi
  562860:	c7 44 24 40 0c 00 00 	mov    DWORD PTR [esp+0x40],0xc
  562867:	00 
  562868:	e8 63 0b ff ff       	call   0x5533d0
  56286d:	68 00 d1 bc 00       	push   0xbcd100
  562872:	e8 a3 fa 32 00       	call   0x89231a
  562877:	83 c4 04             	add    esp,0x4
  56287a:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  56287e:	b8 58 73 fb 00       	mov    eax,0xfb7358
  562883:	e8 b8 0e ff ff       	call   0x553740
  562888:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56288c:	e8 1f f5 ff ff       	call   0x561db0
  562891:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  562895:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  56289c:	59                   	pop    ecx
  56289d:	5f                   	pop    edi
  56289e:	5e                   	pop    esi
  56289f:	5b                   	pop    ebx
  5628a0:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5628a4:	33 cc                	xor    ecx,esp
  5628a6:	e8 56 e7 32 00       	call   0x891001
  5628ab:	8b e5                	mov    esp,ebp
  5628ad:	5d                   	pop    ebp
  5628ae:	c2 04 00             	ret    0x4

## tutorial-formal-wrapper-and-api-registration: [0x4a88e0, 0x4a89bf)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a88e0 <.text+0xa78e0>:
  4a88e0:	55                   	push   ebp
  4a88e1:	8b ec                	mov    ebp,esp
  4a88e3:	83 ec 08             	sub    esp,0x8
  4a88e6:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4a88e9:	56                   	push   esi
  4a88ea:	51                   	push   ecx
  4a88eb:	89 30                	mov    DWORD PTR [eax],esi
  4a88ed:	e8 ae 1c 00 00       	call   0x4aa5a0
  4a88f2:	83 c4 08             	add    esp,0x8
  4a88f5:	50                   	push   eax
  4a88f6:	e8 85 1d 00 00       	call   0x4aa680
  4a88fb:	50                   	push   eax
  4a88fc:	e8 1f 1e 00 00       	call   0x4aa720
  4a8901:	50                   	push   eax
  4a8902:	e8 b9 1e 00 00       	call   0x4aa7c0
  4a8907:	50                   	push   eax
  4a8908:	e8 53 1f 00 00       	call   0x4aa860
  4a890d:	50                   	push   eax
  4a890e:	e8 ed 1f 00 00       	call   0x4aa900
  4a8913:	50                   	push   eax
  4a8914:	e8 87 20 00 00       	call   0x4aa9a0
  4a8919:	50                   	push   eax
  4a891a:	e8 21 21 00 00       	call   0x4aaa40
  4a891f:	50                   	push   eax
  4a8920:	e8 bb 21 00 00       	call   0x4aaae0
  4a8925:	50                   	push   eax
  4a8926:	e8 55 22 00 00       	call   0x4aab80
  4a892b:	50                   	push   eax
  4a892c:	e8 ef 22 00 00       	call   0x4aac20
  4a8931:	50                   	push   eax
  4a8932:	e8 89 23 00 00       	call   0x4aacc0
  4a8937:	50                   	push   eax
  4a8938:	e8 23 24 00 00       	call   0x4aad60
  4a893d:	50                   	push   eax
  4a893e:	e8 bd 24 00 00       	call   0x4aae00
  4a8943:	50                   	push   eax
  4a8944:	e8 57 25 00 00       	call   0x4aaea0
  4a8949:	50                   	push   eax
  4a894a:	e8 f1 25 00 00       	call   0x4aaf40
  4a894f:	50                   	push   eax
  4a8950:	e8 8b 26 00 00       	call   0x4aafe0
  4a8955:	50                   	push   eax
  4a8956:	e8 25 27 00 00       	call   0x4ab080
  4a895b:	50                   	push   eax
  4a895c:	e8 bf 27 00 00       	call   0x4ab120
  4a8961:	50                   	push   eax
  4a8962:	e8 59 28 00 00       	call   0x4ab1c0
  4a8967:	50                   	push   eax
  4a8968:	e8 f3 28 00 00       	call   0x4ab260
  4a896d:	50                   	push   eax
  4a896e:	e8 8d 29 00 00       	call   0x4ab300
  4a8973:	50                   	push   eax
  4a8974:	e8 27 2a 00 00       	call   0x4ab3a0
  4a8979:	50                   	push   eax
  4a897a:	e8 c1 2a 00 00       	call   0x4ab440
  4a897f:	50                   	push   eax
  4a8980:	e8 5b 2b 00 00       	call   0x4ab4e0
  4a8985:	50                   	push   eax
  4a8986:	e8 f5 2b 00 00       	call   0x4ab580
  4a898b:	50                   	push   eax
  4a898c:	e8 8f 2c 00 00       	call   0x4ab620
  4a8991:	50                   	push   eax
  4a8992:	e8 29 2d 00 00       	call   0x4ab6c0
  4a8997:	50                   	push   eax
  4a8998:	e8 c3 2d 00 00       	call   0x4ab760
  4a899d:	50                   	push   eax
  4a899e:	e8 5d 2e 00 00       	call   0x4ab800
  4a89a3:	50                   	push   eax
  4a89a4:	e8 f7 2e 00 00       	call   0x4ab8a0
  4a89a9:	50                   	push   eax
  4a89aa:	e8 91 2f 00 00       	call   0x4ab940
  4a89af:	68 64 68 c0 00       	push   0xc06864
  4a89b4:	8b ce                	mov    ecx,esi
  4a89b6:	e8 95 c0 24 00       	call   0x6f4a50
  4a89bb:	8b e5                	mov    esp,ebp
  4a89bd:	5d                   	pop    ebp
  4a89be:	c3                   	ret

## tutorial-synopsis-entry: [0x4a89c0, 0x4a8a5f)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a89c0 <.text+0xa79c0>:
  4a89c0:	55                   	push   ebp
  4a89c1:	8b ec                	mov    ebp,esp
  4a89c3:	6a ff                	push   0xffffffff
  4a89c5:	68 7e a4 93 00       	push   0x93a47e
  4a89ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a89d0:	50                   	push   eax
  4a89d1:	57                   	push   edi
  4a89d2:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a89d7:	33 c5                	xor    eax,ebp
  4a89d9:	50                   	push   eax
  4a89da:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a89dd:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a89e3:	8d 7e 14             	lea    edi,[esi+0x14]
  4a89e6:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a89ed:	00 00 00 
  4a89f0:	e8 2b 8a 3a 00       	call   0x851420
  4a89f5:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  4a89fc:	75 27                	jne    0x4a8a25
  4a89fe:	83 0d 54 73 fb 00 01 	or     DWORD PTR ds:0xfb7354,0x1
  4a8a05:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8a0c:	e8 bf a9 0a 00       	call   0x5533d0
  4a8a11:	68 00 d1 bc 00       	push   0xbcd100
  4a8a16:	e8 ff 98 3e 00       	call   0x89231a
  4a8a1b:	83 c4 04             	add    esp,0x4
  4a8a1e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a8a25:	c7 05 b4 73 fb 00 01 	mov    DWORD PTR ds:0xfb73b4,0x1
  4a8a2c:	00 00 00 
  4a8a2f:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8a31:	68 7c 68 c0 00       	push   0xc0687c
  4a8a36:	e8 15 c0 24 00       	call   0x6f4a50
  4a8a3b:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8a3d:	6a 00                	push   0x0
  4a8a3f:	6a 00                	push   0x0
  4a8a41:	68 94 68 c0 00       	push   0xc06894
  4a8a46:	e8 85 c3 24 00       	call   0x6f4dd0
  4a8a4b:	83 c4 0c             	add    esp,0xc
  4a8a4e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8a51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a8a58:	59                   	pop    ecx
  4a8a59:	5f                   	pop    edi
  4a8a5a:	8b e5                	mov    esp,ebp
  4a8a5c:	5d                   	pop    ebp
  4a8a5d:	c3                   	ret
  4a8a5e:	cc                   	int3

## tutorial-main-entry: [0x4a8a60, 0x4a8b8e)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a8a60 <.text+0xa7a60>:
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
  4a8a65:	68 4c a4 93 00       	push   0x93a44c
  4a8a6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8a70:	50                   	push   eax
  4a8a71:	83 ec 08             	sub    esp,0x8
  4a8a74:	53                   	push   ebx
  4a8a75:	57                   	push   edi
  4a8a76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8a7b:	33 c5                	xor    eax,ebp
  4a8a7d:	50                   	push   eax
  4a8a7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a8a81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a8a87:	8d 7e 04             	lea    edi,[esi+0x4]
  4a8a8a:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a8a91:	00 00 00 
  4a8a94:	e8 b7 ad 37 00       	call   0x823850
  4a8a99:	8d 7e 14             	lea    edi,[esi+0x14]
  4a8a9c:	e8 7f 89 3a 00       	call   0x851420
  4a8aa1:	bb 01 00 00 00       	mov    ebx,0x1
  4a8aa6:	83 cf ff             	or     edi,0xffffffff
  4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a8aaf:	75 22                	jne    0x4a8ad3
  4a8ab1:	09 1d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,ebx
  4a8ab7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
  4a8ac3:	68 00 d1 bc 00       	push   0xbcd100
  4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
  4a8acd:	83 c4 04             	add    esp,0x4
  4a8ad0:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8ad3:	89 1d b4 73 fb 00    	mov    DWORD PTR ds:0xfb73b4,ebx
  4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4a8adf:	75 1e                	jne    0x4a8aff
  4a8ae1:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4a8ae7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a8aea:	e8 91 e9 0d 00       	call   0x587480
  4a8aef:	68 c0 cc bc 00       	push   0xbcccc0
  4a8af4:	e8 21 98 3e 00       	call   0x89231a
  4a8af9:	83 c4 04             	add    esp,0x4
  4a8afc:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8aff:	b8 0f 00 00 00       	mov    eax,0xf
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b20:	09 1d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,ebx
  4a8b26:	68 10 cf bc 00       	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b30:	83 c4 04             	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00       	mov    eax,0xc
  4a8b3f:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee             	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                	push   0x6
  4a8b55:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8b58:	50                   	push   eax
  4a8b59:	6a 00                	push   0x0
  4a8b5b:	ff d2                	call   edx
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4a8b79:	83 c4 0c             	add    esp,0xc
  4a8b7c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8b7f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a8b86:	59                   	pop    ecx
  4a8b87:	5f                   	pop    edi
  4a8b88:	5b                   	pop    ebx
  4a8b89:	8b e5                	mov    esp,ebp
  4a8b8b:	5d                   	pop    ebp
  4a8b8c:	c3                   	ret
  4a8b8d:	cc                   	int3

## tutorial-task-pump-numeric-return: [0x4a8b90, 0x4a8c1b)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a8b90 <.text+0xa7b90>:
  4a8b90:	55                   	push   ebp
  4a8b91:	8b ec                	mov    ebp,esp
  4a8b93:	83 ec 18             	sub    esp,0x18
  4a8b96:	53                   	push   ebx
  4a8b97:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a8b9a:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a8b9c:	56                   	push   esi
  4a8b9d:	57                   	push   edi
  4a8b9e:	68 d4 68 c0 00       	push   0xc068d4
  4a8ba3:	6a 01                	push   0x1
  4a8ba5:	50                   	push   eax
  4a8ba6:	e8 f5 44 00 00       	call   0x4ad0a0
  4a8bab:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a8bad:	8b 09                	mov    ecx,DWORD PTR [ecx]
  4a8baf:	83 c8 ff             	or     eax,0xffffffff
  4a8bb2:	e8 39 c5 24 00       	call   0x6f50f0
  4a8bb7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a8bba:	83 f9 03             	cmp    ecx,0x3
  4a8bbd:	74 26                	je     0x4a8be5
  4a8bbf:	83 f9 04             	cmp    ecx,0x4
  4a8bc2:	75 42                	jne    0x4a8c06
  4a8bc4:	8b 30                	mov    esi,DWORD PTR [eax]
  4a8bc6:	83 c6 10             	add    esi,0x10
  4a8bc9:	8d 7d f4             	lea    edi,[ebp-0xc]
  4a8bcc:	e8 8f eb 24 00       	call   0x6f7760
  4a8bd1:	85 c0                	test   eax,eax
  4a8bd3:	74 31                	je     0x4a8c06
  4a8bd5:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4a8bd8:	c7 45 f4 03 00 00 00 	mov    DWORD PTR [ebp-0xc],0x3
  4a8bdf:	dd 5d ec             	fstp   QWORD PTR [ebp-0x14]
  4a8be2:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8be5:	dd 00                	fld    QWORD PTR [eax]
  4a8be7:	dd 5d f4             	fstp   QWORD PTR [ebp-0xc]
  4a8bea:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4a8bed:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4a8bf0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a8bf3:	33 d2                	xor    edx,edx
  4a8bf5:	85 c0                	test   eax,eax
  4a8bf7:	0f 95 c2             	setne  dl
  4a8bfa:	89 53 34             	mov    DWORD PTR [ebx+0x34],edx
  4a8bfd:	5f                   	pop    edi
  4a8bfe:	5e                   	pop    esi
  4a8bff:	5b                   	pop    ebx
  4a8c00:	8b e5                	mov    esp,ebp
  4a8c02:	5d                   	pop    ebp
  4a8c03:	c2 04 00             	ret    0x4
  4a8c06:	33 d2                	xor    edx,edx
  4a8c08:	33 c0                	xor    eax,eax
  4a8c0a:	85 c0                	test   eax,eax
  4a8c0c:	0f 95 c2             	setne  dl
  4a8c0f:	5f                   	pop    edi
  4a8c10:	5e                   	pop    esi
  4a8c11:	89 53 34             	mov    DWORD PTR [ebx+0x34],edx
  4a8c14:	5b                   	pop    ebx
  4a8c15:	8b e5                	mov    esp,ebp
  4a8c17:	5d                   	pop    ebp
  4a8c18:	c2 04 00             	ret    0x4

## tutorial-get-scene-active: [0x4a97b0, 0x4a9812)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a97b0 <.text+0xa87b0>:
  4a97b0:	55                   	push   ebp
  4a97b1:	8b ec                	mov    ebp,esp
  4a97b3:	6a ff                	push   0xffffffff
  4a97b5:	68 ae b2 93 00       	push   0x93b2ae
  4a97ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a97c0:	50                   	push   eax
  4a97c1:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a97c6:	33 c5                	xor    eax,ebp
  4a97c8:	50                   	push   eax
  4a97c9:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a97cc:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a97d2:	b8 01 00 00 00       	mov    eax,0x1
  4a97d7:	84 05 b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,al
  4a97dd:	75 1f                	jne    0x4a97fe
  4a97df:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  4a97e5:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a97ec:	e8 7f 69 0b 00       	call   0x560170
  4a97f1:	68 10 d1 bc 00       	push   0xbcd110
  4a97f6:	e8 1f 8b 3e 00       	call   0x89231a
  4a97fb:	83 c4 04             	add    esp,0x4
  4a97fe:	a1 e8 73 fb 00       	mov    eax,ds:0xfb73e8
  4a9803:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a9806:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a980d:	59                   	pop    ecx
  4a980e:	8b e5                	mov    esp,ebp
  4a9810:	5d                   	pop    ebp
  4a9811:	c3                   	ret

## tutorial-stop-scene: [0x4a9820, 0x4a98c2)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a9820 <.text+0xa8820>:
  4a9820:	55                   	push   ebp
  4a9821:	8b ec                	mov    ebp,esp
  4a9823:	6a ff                	push   0xffffffff
  4a9825:	68 8c 4e 94 00       	push   0x944e8c
  4a982a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a9830:	50                   	push   eax
  4a9831:	51                   	push   ecx
  4a9832:	53                   	push   ebx
  4a9833:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a9838:	33 c5                	xor    eax,ebp
  4a983a:	50                   	push   eax
  4a983b:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a983e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a9844:	bb 01 00 00 00       	mov    ebx,0x1
  4a9849:	84 1d b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,bl
  4a984f:	75 26                	jne    0x4a9877
  4a9851:	09 1d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,ebx
  4a9857:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a985e:	e8 0d 69 0b 00       	call   0x560170
  4a9863:	68 10 d1 bc 00       	push   0xbcd110
  4a9868:	e8 ad 8a 3e 00       	call   0x89231a
  4a986d:	83 c4 04             	add    esp,0x4
  4a9870:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a9877:	6a 00                	push   0x0
  4a9879:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4a987e:	e8 2d 8c 0b 00       	call   0x5624b0
  4a9883:	84 1d b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,bl
  4a9889:	75 22                	jne    0x4a98ad
  4a988b:	09 1d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,ebx
  4a9891:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a9894:	e8 d7 68 0b 00       	call   0x560170
  4a9899:	68 10 d1 bc 00       	push   0xbcd110
  4a989e:	e8 77 8a 3e 00       	call   0x89231a
  4a98a3:	83 c4 04             	add    esp,0x4
  4a98a6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a98ad:	e8 9e 89 0b 00       	call   0x562250
  4a98b2:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a98b5:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a98bc:	59                   	pop    ecx
  4a98bd:	5b                   	pop    ebx
  4a98be:	8b e5                	mov    esp,ebp
  4a98c0:	5d                   	pop    ebp
  4a98c1:	c3                   	ret

## tutorial-get-scene-active-binding: [0x4aacc0, 0x4aad59)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004aacc0 <.text+0xa9cc0>:
  4aacc0:	55                   	push   ebp
  4aacc1:	8b ec                	mov    ebp,esp
  4aacc3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aacc6:	53                   	push   ebx
  4aacc7:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4aaccd:	56                   	push   esi
  4aacce:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aacd0:	57                   	push   edi
  4aacd1:	8b 38                	mov    edi,DWORD PTR [eax]
  4aacd3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4aacd8:	c7 05 30 18 fe 00 b0 	mov    DWORD PTR ds:0xfe1830,0x4a97b0
  4aacdf:	97 4a 00 
  4aace2:	e8 99 a9 24 00       	call   0x6f5680
  4aace7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4aace9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aacec:	83 e8 10             	sub    eax,0x10
  4aacef:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4aacf4:	74 06                	je     0x4aacfc
  4aacf6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4aacfa:	74 14                	je     0x4aad10
  4aacfc:	57                   	push   edi
  4aacfd:	68 c4 26 c4 00       	push   0xc426c4
  4aad02:	e8 b6 83 3e 00       	call   0x8930bd
  4aad07:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4aad09:	83 c4 08             	add    esp,0x8
  4aad0c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4aad10:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4aad16:	8b 37                	mov    esi,DWORD PTR [edi]
  4aad18:	68 00 ac d6 00       	push   0xd6ac00
  4aad1d:	e8 ee a7 24 00       	call   0x6f5510
  4aad22:	8b 37                	mov    esi,DWORD PTR [edi]
  4aad24:	83 c4 04             	add    esp,0x4
  4aad27:	6a 00                	push   0x0
  4aad29:	68 70 c2 4a 00       	push   0x4ac270
  4aad2e:	e8 7d a8 24 00       	call   0x6f55b0
  4aad33:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4aad35:	51                   	push   ecx
  4aad36:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4aad3b:	e8 b0 aa 24 00       	call   0x6f57f0
  4aad40:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4aad46:	8b 02                	mov    eax,DWORD PTR [edx]
  4aad48:	83 c4 0c             	add    esp,0xc
  4aad4b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4aad4f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aad52:	5f                   	pop    edi
  4aad53:	5e                   	pop    esi
  4aad54:	5b                   	pop    ebx
  4aad55:	5d                   	pop    ebp
  4aad56:	c2 04 00             	ret    0x4

## tutorial-stop-scene-binding: [0x4aad60, 0x4aadf9)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004aad60 <.text+0xa9d60>:
  4aad60:	55                   	push   ebp
  4aad61:	8b ec                	mov    ebp,esp
  4aad63:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aad66:	53                   	push   ebx
  4aad67:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4aad6d:	56                   	push   esi
  4aad6e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aad70:	57                   	push   edi
  4aad71:	8b 38                	mov    edi,DWORD PTR [eax]
  4aad73:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4aad78:	c7 05 34 18 fe 00 20 	mov    DWORD PTR ds:0xfe1834,0x4a9820
  4aad7f:	98 4a 00 
  4aad82:	e8 f9 a8 24 00       	call   0x6f5680
  4aad87:	8b 03                	mov    eax,DWORD PTR [ebx]
  4aad89:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aad8c:	83 e8 10             	sub    eax,0x10
  4aad8f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4aad94:	74 06                	je     0x4aad9c
  4aad96:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4aad9a:	74 14                	je     0x4aadb0
  4aad9c:	57                   	push   edi
  4aad9d:	68 c4 26 c4 00       	push   0xc426c4
  4aada2:	e8 16 83 3e 00       	call   0x8930bd
  4aada7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4aada9:	83 c4 08             	add    esp,0x8
  4aadac:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4aadb0:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4aadb6:	8b 37                	mov    esi,DWORD PTR [edi]
  4aadb8:	68 14 ac d6 00       	push   0xd6ac14
  4aadbd:	e8 4e a7 24 00       	call   0x6f5510
  4aadc2:	8b 37                	mov    esi,DWORD PTR [edi]
  4aadc4:	83 c4 04             	add    esp,0x4
  4aadc7:	6a 00                	push   0x0
  4aadc9:	68 e0 c2 4a 00       	push   0x4ac2e0
  4aadce:	e8 dd a7 24 00       	call   0x6f55b0
  4aadd3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4aadd5:	51                   	push   ecx
  4aadd6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4aaddb:	e8 10 aa 24 00       	call   0x6f57f0
  4aade0:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4aade6:	8b 02                	mov    eax,DWORD PTR [edx]
  4aade8:	83 c4 0c             	add    esp,0xc
  4aadeb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4aadef:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aadf2:	5f                   	pop    edi
  4aadf3:	5e                   	pop    esi
  4aadf4:	5b                   	pop    ebx
  4aadf5:	5d                   	pop    ebp
  4aadf6:	c2 04 00             	ret    0x4

## tutorial-get-scene-active-wrapper: [0x4ac270, 0x4ac2de)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ac270 <.text+0xab270>:
  4ac270:	55                   	push   ebp
  4ac271:	8b ec                	mov    ebp,esp
  4ac273:	6a ff                	push   0xffffffff
  4ac275:	68 d8 87 93 00       	push   0x9387d8
  4ac27a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac280:	50                   	push   eax
  4ac281:	83 ec 0c             	sub    esp,0xc
  4ac284:	56                   	push   esi
  4ac285:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac28a:	33 c5                	xor    eax,ebp
  4ac28c:	50                   	push   eax
  4ac28d:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac290:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ac296:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4ac299:	33 c0                	xor    eax,eax
  4ac29b:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  4ac29e:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4ac2a1:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ac2a4:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4ac2a7:	8b 0d 04 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1804
  4ac2ad:	ff 15 30 18 fe 00    	call   DWORD PTR ds:0xfe1830
  4ac2b3:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4ac2b6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4ac2b9:	db 45 08             	fild   DWORD PTR [ebp+0x8]
  4ac2bc:	c7 40 08 03 00 00 00 	mov    DWORD PTR [eax+0x8],0x3
  4ac2c3:	dd 18                	fstp   QWORD PTR [eax]
  4ac2c5:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  4ac2c9:	b8 01 00 00 00       	mov    eax,0x1
  4ac2ce:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ac2d1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ac2d8:	59                   	pop    ecx
  4ac2d9:	5e                   	pop    esi
  4ac2da:	8b e5                	mov    esp,ebp
  4ac2dc:	5d                   	pop    ebp
  4ac2dd:	c3                   	ret

## tutorial-stop-scene-wrapper: [0x4ac2e0, 0x4ac336)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ac2e0 <.text+0xab2e0>:
  4ac2e0:	55                   	push   ebp
  4ac2e1:	8b ec                	mov    ebp,esp
  4ac2e3:	6a ff                	push   0xffffffff
  4ac2e5:	68 c8 83 93 00       	push   0x9383c8
  4ac2ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac2f0:	50                   	push   eax
  4ac2f1:	83 ec 0c             	sub    esp,0xc
  4ac2f4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac2f9:	33 c5                	xor    eax,ebp
  4ac2fb:	50                   	push   eax
  4ac2fc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac2ff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ac305:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ac308:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4ac30b:	33 c0                	xor    eax,eax
  4ac30d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4ac310:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ac313:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4ac316:	8b 0d 04 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1804
  4ac31c:	ff 15 34 18 fe 00    	call   DWORD PTR ds:0xfe1834
  4ac322:	b8 01 00 00 00       	mov    eax,0x1
  4ac327:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ac32a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ac331:	59                   	pop    ecx
  4ac332:	8b e5                	mov    esp,ebp
  4ac334:	5d                   	pop    ebp
  4ac335:	c3                   	ret

## tutorial-scene-constructor: [0x4c4ac0, 0x4c4b04)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4ac0 <.text+0xc3ac0>:
  4c4ac0:	8b c6                	mov    eax,esi
  4c4ac2:	e8 89 92 fe ff       	call   0x4add50
  4c4ac7:	68 a8 5e 00 00       	push   0x5ea8
  4c4acc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4ad2:	6a 00                	push   0x0
  4c4ad4:	50                   	push   eax
  4c4ad5:	c7 06 e8 73 c0 00    	mov    DWORD PTR [esi],0xc073e8
  4c4adb:	c7 05 74 a6 d6 00 4f 	mov    DWORD PTR ds:0xd6a674,0x5455544f
  4c4ae2:	54 55 54 
  4c4ae5:	e8 76 9d 3d 00       	call   0x89e860
  4c4aea:	83 c4 0c             	add    esp,0xc
  4c4aed:	c7 86 0c 61 00 00 20 	mov    DWORD PTR [esi+0x610c],0x4c4f20
  4c4af4:	4f 4c 00 
  4c4af7:	c7 86 10 61 00 00 75 	mov    DWORD PTR [esi+0x6110],0xbf2375
  4c4afe:	23 bf 00 
  4c4b01:	8b c6                	mov    eax,esi
  4c4b03:	c3                   	ret

## tutorial-scene-init: [0x4c4b10, 0x4c4d59)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4b10 <.text+0xc3b10>:
  4c4b10:	55                   	push   ebp
  4c4b11:	8b ec                	mov    ebp,esp
  4c4b13:	83 e4 f8             	and    esp,0xfffffff8
  4c4b16:	6a ff                	push   0xffffffff
  4c4b18:	68 51 a5 93 00       	push   0x93a551
  4c4b1d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4b23:	50                   	push   eax
  4c4b24:	83 ec 08             	sub    esp,0x8
  4c4b27:	53                   	push   ebx
  4c4b28:	56                   	push   esi
  4c4b29:	57                   	push   edi
  4c4b2a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4b2f:	33 c4                	xor    eax,esp
  4c4b31:	50                   	push   eax
  4c4b32:	8d 44 24 18          	lea    eax,[esp+0x18]
  4c4b36:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4b3c:	f6 05 f0 2c fd 00 01 	test   BYTE PTR ds:0xfd2cf0,0x1
  4c4b43:	bf 01 00 00 00       	mov    edi,0x1
  4c4b48:	75 18                	jne    0x4c4b62
  4c4b4a:	09 3d f0 2c fd 00    	or     DWORD PTR ds:0xfd2cf0,edi
  4c4b50:	e8 3b 35 27 00       	call   0x738090
  4c4b55:	68 80 e6 bc 00       	push   0xbce680
  4c4b5a:	e8 bb d7 3c 00       	call   0x89231a
  4c4b5f:	83 c4 04             	add    esp,0x4
  4c4b62:	33 f6                	xor    esi,esi
  4c4b64:	39 35 b8 2b fd 00    	cmp    DWORD PTR ds:0xfd2bb8,esi
  4c4b6a:	74 39                	je     0x4c4ba5
  4c4b6c:	8b 0d d0 2c fd 00    	mov    ecx,DWORD PTR ds:0xfd2cd0
  4c4b72:	89 3d c4 2b fd 00    	mov    DWORD PTR ds:0xfd2bc4,edi
  4c4b78:	c7 05 c8 2b fd 00 c8 	mov    DWORD PTR ds:0xfd2bc8,0xc8
  4c4b7f:	00 00 00 
  4c4b82:	3b ce                	cmp    ecx,esi
  4c4b84:	74 0d                	je     0x4c4b93
  4c4b86:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c4b88:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c4b8b:	ff d2                	call   edx
  4c4b8d:	89 35 d0 2c fd 00    	mov    DWORD PTR ds:0xfd2cd0,esi
  4c4b93:	89 35 d4 2c fd 00    	mov    DWORD PTR ds:0xfd2cd4,esi
  4c4b99:	89 3d cc 2b fd 00    	mov    DWORD PTR ds:0xfd2bcc,edi
  4c4b9f:	89 3d e8 2c fd 00    	mov    DWORD PTR ds:0xfd2ce8,edi
  4c4ba5:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c4bab:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c4bad:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4c4bb0:	ff d2                	call   edx
  4c4bb2:	83 cb ff             	or     ebx,0xffffffff
  4c4bb5:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4c4bbc:	75 20                	jne    0x4c4bde
  4c4bbe:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4c4bc4:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4c4bc8:	e8 c3 a0 01 00       	call   0x4dec90
  4c4bcd:	68 30 ce bc 00       	push   0xbcce30
  4c4bd2:	e8 43 d7 3c 00       	call   0x89231a
  4c4bd7:	83 c4 04             	add    esp,0x4
  4c4bda:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4bde:	68 30 b1 fa 00       	push   0xfab130
  4c4be3:	e8 a8 b2 01 00       	call   0x4dfe90
  4c4be8:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4c4bef:	75 20                	jne    0x4c4c11
  4c4bf1:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4c4bf7:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  4c4bfb:	e8 90 a0 01 00       	call   0x4dec90
  4c4c00:	68 30 ce bc 00       	push   0xbcce30
  4c4c05:	e8 10 d7 3c 00       	call   0x89231a
  4c4c0a:	83 c4 04             	add    esp,0x4
  4c4c0d:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4c11:	68 48 b1 fa 00       	push   0xfab148
  4c4c16:	89 35 28 b2 fa 00    	mov    DWORD PTR ds:0xfab228,esi
  4c4c1c:	e8 4f c4 01 00       	call   0x4e1070
  4c4c21:	83 c4 04             	add    esp,0x4
  4c4c24:	f6 05 c8 18 fe 00 01 	test   BYTE PTR ds:0xfe18c8,0x1
  4c4c2b:	75 24                	jne    0x4c4c51
  4c4c2d:	09 3d c8 18 fe 00    	or     DWORD PTR ds:0xfe18c8,edi
  4c4c33:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4c4c3a:	00 
  4c4c3b:	e8 30 ad 07 00       	call   0x53f970
  4c4c40:	68 10 e8 bc 00       	push   0xbce810
  4c4c45:	e8 d0 d6 3c 00       	call   0x89231a
  4c4c4a:	83 c4 04             	add    esp,0x4
  4c4c4d:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4c51:	a1 cc 18 fe 00       	mov    eax,ds:0xfe18cc
  4c4c56:	3b 05 d0 18 fe 00    	cmp    eax,DWORD PTR ds:0xfe18d0
  4c4c5c:	74 05                	je     0x4c4c63
  4c4c5e:	a3 d0 18 fe 00       	mov    ds:0xfe18d0,eax
  4c4c63:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4c6a:	75 24                	jne    0x4c4c90
  4c4c6c:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c4c72:	c7 44 24 20 03 00 00 	mov    DWORD PTR [esp+0x20],0x3
  4c4c79:	00 
  4c4c7a:	e8 31 62 fb ff       	call   0x47aeb0
  4c4c7f:	68 70 db bc 00       	push   0xbcdb70
  4c4c84:	e8 91 d6 3c 00       	call   0x89231a
  4c4c89:	83 c4 04             	add    esp,0x4
  4c4c8c:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4c90:	b9 84 0f fc 00       	mov    ecx,0xfc0f84
  4c4c95:	e8 86 3f fe ff       	call   0x4a8c20
  4c4c9a:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c4ca0:	3b ce                	cmp    ecx,esi
  4c4ca2:	74 2f                	je     0x4c4cd3
  4c4ca4:	83 3d ac a7 fb 00 04 	cmp    DWORD PTR ds:0xfba7ac,0x4
  4c4cab:	75 0e                	jne    0x4c4cbb
  4c4cad:	8b f9                	mov    edi,ecx
  4c4caf:	e8 9c 02 08 00       	call   0x544f50
  4c4cb4:	bf 01 00 00 00       	mov    edi,0x1
  4c4cb9:	eb 52                	jmp    0x4c4d0d
  4c4cbb:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c4cbd:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  4c4cc0:	ff d2                	call   edx
  4c4cc2:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c4cc8:	3b ce                	cmp    ecx,esi
  4c4cca:	74 07                	je     0x4c4cd3
  4c4ccc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c4cce:	8b 10                	mov    edx,DWORD PTR [eax]
  4c4cd0:	57                   	push   edi
  4c4cd1:	ff d2                	call   edx
  4c4cd3:	68 38 01 00 00       	push   0x138
  4c4cd8:	e8 8b c5 3c 00       	call   0x891268
  4c4cdd:	83 c4 04             	add    esp,0x4
  4c4ce0:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c4ce4:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  4c4ceb:	00 
  4c4cec:	3b c6                	cmp    eax,esi
  4c4cee:	74 09                	je     0x4c4cf9
  4c4cf0:	8b f0                	mov    esi,eax
  4c4cf2:	e8 99 3e 08 00       	call   0x548b90
  4c4cf7:	eb 02                	jmp    0x4c4cfb
  4c4cf9:	33 c0                	xor    eax,eax
  4c4cfb:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4cff:	8b 10                	mov    edx,DWORD PTR [eax]
  4c4d01:	a3 a4 a7 fb 00       	mov    ds:0xfba7a4,eax
  4c4d06:	8b c8                	mov    ecx,eax
  4c4d08:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  4c4d0b:	ff d0                	call   eax
  4c4d0d:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4d14:	75 24                	jne    0x4c4d3a
  4c4d16:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c4d1c:	c7 44 24 20 0b 00 00 	mov    DWORD PTR [esp+0x20],0xb
  4c4d23:	00 
  4c4d24:	e8 87 61 fb ff       	call   0x47aeb0
  4c4d29:	68 70 db bc 00       	push   0xbcdb70
  4c4d2e:	e8 e7 d5 3c 00       	call   0x89231a
  4c4d33:	83 c4 04             	add    esp,0x4
  4c4d36:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4d3a:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d44:	33 c0                	xor    eax,eax
  4c4d46:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4c4d4a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4d51:	59                   	pop    ecx
  4c4d52:	5f                   	pop    edi
  4c4d53:	5e                   	pop    esi
  4c4d54:	5b                   	pop    ebx
  4c4d55:	8b e5                	mov    esp,ebp
  4c4d57:	5d                   	pop    ebp
  4c4d58:	c3                   	ret

## tutorial-scene-leave-cancel: [0x4c4d60, 0x4c4de2)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4d60 <.text+0xc3d60>:
  4c4d60:	55                   	push   ebp
  4c4d61:	8b ec                	mov    ebp,esp
  4c4d63:	6a ff                	push   0xffffffff
  4c4d65:	68 ce 3e 93 00       	push   0x933ece
  4c4d6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4d70:	50                   	push   eax
  4c4d71:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4d76:	33 c5                	xor    eax,ebp
  4c4d78:	50                   	push   eax
  4c4d79:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4d7c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4d82:	b8 01 00 00 00       	mov    eax,0x1
  4c4d87:	84 05 80 0f fc 00    	test   BYTE PTR ds:0xfc0f80,al
  4c4d8d:	75 26                	jne    0x4c4db5
  4c4d8f:	09 05 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,eax
  4c4d95:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4d9c:	e8 0f 61 fb ff       	call   0x47aeb0
  4c4da1:	68 70 db bc 00       	push   0xbcdb70
  4c4da6:	e8 6f d5 3c 00       	call   0x89231a
  4c4dab:	83 c4 04             	add    esp,0x4
  4c4dae:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4db5:	a1 84 0f fc 00       	mov    eax,ds:0xfc0f84
  4c4dba:	68 bc 68 c0 00       	push   0xc068bc
  4c4dbf:	6a 00                	push   0x0
  4c4dc1:	50                   	push   eax
  4c4dc2:	e8 d9 82 fe ff       	call   0x4ad0a0
  4c4dc7:	b9 84 0f fc 00       	mov    ecx,0xfc0f84
  4c4dcc:	e8 df 4f fe ff       	call   0x4a9db0
  4c4dd1:	33 c0                	xor    eax,eax
  4c4dd3:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c4dd6:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4ddd:	59                   	pop    ecx
  4c4dde:	8b e5                	mov    esp,ebp
  4c4de0:	5d                   	pop    ebp
  4c4de1:	c3                   	ret

## tutorial-scene-update: [0x4c4df0, 0x4c4ea2)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4df0 <.text+0xc3df0>:
  4c4df0:	55                   	push   ebp
  4c4df1:	8b ec                	mov    ebp,esp
  4c4df3:	6a ff                	push   0xffffffff
  4c4df5:	68 dc 79 94 00       	push   0x9479dc
  4c4dfa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4e00:	50                   	push   eax
  4c4e01:	56                   	push   esi
  4c4e02:	57                   	push   edi
  4c4e03:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4e08:	33 c5                	xor    eax,ebp
  4c4e0a:	50                   	push   eax
  4c4e0b:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4e0e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4e14:	e8 f7 8c fe ff       	call   0x4adb10
  4c4e19:	f6 05 c8 18 fe 00 01 	test   BYTE PTR ds:0xfe18c8,0x1
  4c4e20:	8b f0                	mov    esi,eax
  4c4e22:	75 27                	jne    0x4c4e4b
  4c4e24:	83 0d c8 18 fe 00 01 	or     DWORD PTR ds:0xfe18c8,0x1
  4c4e2b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4e32:	e8 39 ab 07 00       	call   0x53f970
  4c4e37:	68 10 e8 bc 00       	push   0xbce810
  4c4e3c:	e8 d9 d4 3c 00       	call   0x89231a
  4c4e41:	83 c4 04             	add    esp,0x4
  4c4e44:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4e4b:	bf cc 18 fe 00       	mov    edi,0xfe18cc
  4c4e50:	e8 fb b0 07 00       	call   0x53ff50
  4c4e55:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4e5c:	75 27                	jne    0x4c4e85
  4c4e5e:	b8 01 00 00 00       	mov    eax,0x1
  4c4e63:	09 05 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,eax
  4c4e69:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c4e6c:	e8 3f 60 fb ff       	call   0x47aeb0
  4c4e71:	68 70 db bc 00       	push   0xbcdb70
  4c4e76:	e8 9f d4 3c 00       	call   0x89231a
  4c4e7b:	83 c4 04             	add    esp,0x4
  4c4e7e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4e85:	68 84 0f fc 00       	push   0xfc0f84
  4c4e8a:	e8 01 3d fe ff       	call   0x4a8b90
  4c4e8f:	8b c6                	mov    eax,esi
  4c4e91:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c4e94:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4e9b:	59                   	pop    ecx
  4c4e9c:	5f                   	pop    edi
  4c4e9d:	5e                   	pop    esi
  4c4e9e:	8b e5                	mov    esp,ebp
  4c4ea0:	5d                   	pop    ebp
  4c4ea1:	c3                   	ret

## tutorial-native-owned-table-cleanup: [0x4a9db0, 0x4a9efa)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a9db0 <.text+0xa8db0>:
  4a9db0:	55                   	push   ebp
  4a9db1:	8b ec                	mov    ebp,esp
  4a9db3:	6a ff                	push   0xffffffff
  4a9db5:	68 ee ce 90 00       	push   0x90ceee
  4a9dba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a9dc0:	50                   	push   eax
  4a9dc1:	53                   	push   ebx
  4a9dc2:	56                   	push   esi
  4a9dc3:	57                   	push   edi
  4a9dc4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a9dc9:	33 c5                	xor    eax,ebp
  4a9dcb:	50                   	push   eax
  4a9dcc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a9dcf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a9dd5:	8b 51 18             	mov    edx,DWORD PTR [ecx+0x18]
  4a9dd8:	8d 59 14             	lea    ebx,[ecx+0x14]
  4a9ddb:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4a9ddd:	3b ca                	cmp    ecx,edx
  4a9ddf:	74 55                	je     0x4a9e36
  4a9de1:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4a9de4:	c7 40 14 00 00 00 00 	mov    DWORD PTR [eax+0x14],0x0
  4a9deb:	80 79 11 00          	cmp    BYTE PTR [ecx+0x11],0x0
  4a9def:	75 41                	jne    0x4a9e32
  4a9df1:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  4a9df4:	80 78 11 00          	cmp    BYTE PTR [eax+0x11],0x0
  4a9df8:	75 16                	jne    0x4a9e10
  4a9dfa:	8b c8                	mov    ecx,eax
  4a9dfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a9dfe:	80 78 11 00          	cmp    BYTE PTR [eax+0x11],0x0
  4a9e02:	75 2e                	jne    0x4a9e32
  4a9e04:	8b c8                	mov    ecx,eax
  4a9e06:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a9e08:	80 78 11 00          	cmp    BYTE PTR [eax+0x11],0x0
  4a9e0c:	74 f6                	je     0x4a9e04
  4a9e0e:	eb 22                	jmp    0x4a9e32
  4a9e10:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4a9e13:	80 78 11 00          	cmp    BYTE PTR [eax+0x11],0x0
  4a9e17:	75 17                	jne    0x4a9e30
  4a9e19:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4a9e20:	3b 48 08             	cmp    ecx,DWORD PTR [eax+0x8]
  4a9e23:	75 0b                	jne    0x4a9e30
  4a9e25:	8b c8                	mov    ecx,eax
  4a9e27:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4a9e2a:	80 78 11 00          	cmp    BYTE PTR [eax+0x11],0x0
  4a9e2e:	74 f0                	je     0x4a9e20
  4a9e30:	8b c8                	mov    ecx,eax
  4a9e32:	3b ca                	cmp    ecx,edx
  4a9e34:	75 ab                	jne    0x4a9de1
  4a9e36:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4a9e39:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  4a9e3c:	80 7f 11 00          	cmp    BYTE PTR [edi+0x11],0x0
  4a9e40:	8b f7                	mov    esi,edi
  4a9e42:	75 1e                	jne    0x4a9e62
  4a9e44:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  4a9e47:	51                   	push   ecx
  4a9e48:	8b cb                	mov    ecx,ebx
  4a9e4a:	e8 d1 81 3a 00       	call   0x852020
  4a9e4f:	8b 36                	mov    esi,DWORD PTR [esi]
  4a9e51:	57                   	push   edi
  4a9e52:	e8 b5 73 3e 00       	call   0x89120c
  4a9e57:	83 c4 04             	add    esp,0x4
  4a9e5a:	80 7e 11 00          	cmp    BYTE PTR [esi+0x11],0x0
  4a9e5e:	8b fe                	mov    edi,esi
  4a9e60:	74 e2                	je     0x4a9e44
  4a9e62:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4a9e65:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4a9e68:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4a9e6b:	89 00                	mov    DWORD PTR [eax],eax
  4a9e6d:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4a9e70:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4a9e73:	33 c0                	xor    eax,eax
  4a9e75:	89 43 08             	mov    DWORD PTR [ebx+0x8],eax
  4a9e78:	bb 01 00 00 00       	mov    ebx,0x1
  4a9e7d:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a9e83:	75 59                	jne    0x4a9ede
  4a9e85:	09 1d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,ebx
  4a9e8b:	68 20 30 84 00       	push   0x843020
  4a9e90:	68 50 40 55 00       	push   0x554050
  4a9e95:	6a 04                	push   0x4
  4a9e97:	6a 10                	push   0x10
  4a9e99:	68 58 73 fb 00       	push   0xfb7358
  4a9e9e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a9ea1:	e8 5d 81 3e 00       	call   0x892003
  4a9ea6:	68 00 d1 bc 00       	push   0xbcd100
  4a9eab:	c7 05 98 73 fb 00 00 	mov    DWORD PTR ds:0xfb7398,0x0
  4a9eb2:	00 00 00 
  4a9eb5:	c7 05 ac 73 fb 00 00 	mov    DWORD PTR ds:0xfb73ac,0x400
  4a9ebc:	04 00 00 
  4a9ebf:	c7 05 b0 73 fb 00 00 	mov    DWORD PTR ds:0xfb73b0,0x300
  4a9ec6:	03 00 00 
  4a9ec9:	89 1d b4 73 fb 00    	mov    DWORD PTR ds:0xfb73b4,ebx
  4a9ecf:	e8 46 84 3e 00       	call   0x89231a
  4a9ed4:	83 c4 04             	add    esp,0x4
  4a9ed7:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a9ede:	b8 58 73 fb 00       	mov    eax,0xfb7358
  4a9ee3:	e8 58 98 0a 00       	call   0x553740
  4a9ee8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a9eeb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a9ef2:	59                   	pop    ecx
  4a9ef3:	5f                   	pop    edi
  4a9ef4:	5e                   	pop    esi
  4a9ef5:	5b                   	pop    ebx
  4a9ef6:	8b e5                	mov    esp,ebp
  4a9ef8:	5d                   	pop    ebp
  4a9ef9:	c3                   	ret

## scene-switch-old-exit-new-init: [0x4b7d50, 0x4b7dc0)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b7d50 <.text+0xb6d50>:
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

## expedition-constructor-vptr: [0x4c13e0, 0x4c142f)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c13e0 <.text+0xc03e0>:
  4c13e0:	55                   	push   ebp
  4c13e1:	8b ec                	mov    ebp,esp
  4c13e3:	6a ff                	push   0xffffffff
  4c13e5:	68 28 90 94 00       	push   0x949028
  4c13ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c13f0:	50                   	push   eax
  4c13f1:	83 ec 10             	sub    esp,0x10
  4c13f4:	56                   	push   esi
  4c13f5:	57                   	push   edi
  4c13f6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c13fb:	33 c5                	xor    eax,ebp
  4c13fd:	50                   	push   eax
  4c13fe:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c1401:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c1407:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c140a:	8b c6                	mov    eax,esi
  4c140c:	c7 05 74 a6 d6 00 4c 	mov    DWORD PTR ds:0xd6a674,0x4e554c4c
  4c1413:	4c 55 4e 
  4c1416:	e8 35 c9 fe ff       	call   0x4add50
  4c141b:	33 ff                	xor    edi,edi
  4c141d:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4c1420:	0f 57 c0             	xorps  xmm0,xmm0
  4c1423:	c7 06 80 72 c0 00    	mov    DWORD PTR [esi],0xc07280
  4c1429:	89 be 54 bd 00 00    	mov    DWORD PTR [esi+0xbd54],edi

## expedition-synopsis-enable-and-entry: [0x4c1e10, 0x4c2001)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c1e10 <.text+0xc0e10>:
  4c1e10:	55                   	push   ebp
  4c1e11:	8b ec                	mov    ebp,esp
  4c1e13:	83 e4 f8             	and    esp,0xfffffff8
  4c1e16:	6a ff                	push   0xffffffff
  4c1e18:	68 9c a5 93 00       	push   0x93a59c
  4c1e1d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c1e23:	50                   	push   eax
  4c1e24:	83 ec 10             	sub    esp,0x10
  4c1e27:	53                   	push   ebx
  4c1e28:	56                   	push   esi
  4c1e29:	57                   	push   edi
  4c1e2a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c1e2f:	33 c4                	xor    eax,esp
  4c1e31:	50                   	push   eax
  4c1e32:	8d 44 24 20          	lea    eax,[esp+0x20]
  4c1e36:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c1e3c:	6a 1c                	push   0x1c
  4c1e3e:	e8 25 f4 3c 00       	call   0x891268
  4c1e43:	33 db                	xor    ebx,ebx
  4c1e45:	83 c4 04             	add    esp,0x4
  4c1e48:	3b c3                	cmp    eax,ebx
  4c1e4a:	74 11                	je     0x4c1e5d
  4c1e4c:	89 18                	mov    DWORD PTR [eax],ebx
  4c1e4e:	c6 40 08 01          	mov    BYTE PTR [eax+0x8],0x1
  4c1e52:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  4c1e55:	89 58 10             	mov    DWORD PTR [eax+0x10],ebx
  4c1e58:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  4c1e5b:	eb 02                	jmp    0x4c1e5f
  4c1e5d:	33 c0                	xor    eax,eax
  4c1e5f:	50                   	push   eax
  4c1e60:	8d 44 24 18          	lea    eax,[esp+0x18]
  4c1e64:	50                   	push   eax
  4c1e65:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  4c1e69:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c1e6d:	e8 5e a2 fb ff       	call   0x47c0d0
  4c1e72:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4c1e76:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4c1e7a:	c6 46 08 01          	mov    BYTE PTR [esi+0x8],0x1
  4c1e7e:	8d 7e 0c             	lea    edi,[esi+0xc]
  4c1e81:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1e85:	c7 46 04 03 00 00 00 	mov    DWORD PTR [esi+0x4],0x3
  4c1e8c:	c7 44 24 10 f8 03 00 	mov    DWORD PTR [esp+0x10],0x3f8
  4c1e93:	00 
  4c1e94:	e8 e7 67 fe ff       	call   0x4a8680
  4c1e99:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1e9d:	c7 44 24 10 f9 03 00 	mov    DWORD PTR [esp+0x10],0x3f9
  4c1ea4:	00 
  4c1ea5:	e8 d6 67 fe ff       	call   0x4a8680
  4c1eaa:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1eae:	c7 44 24 10 14 27 00 	mov    DWORD PTR [esp+0x10],0x2714
  4c1eb5:	00 
  4c1eb6:	e8 c5 67 fe ff       	call   0x4a8680
  4c1ebb:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1ebf:	c7 44 24 10 15 27 00 	mov    DWORD PTR [esp+0x10],0x2715
  4c1ec6:	00 
  4c1ec7:	e8 b4 67 fe ff       	call   0x4a8680
  4c1ecc:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1ed0:	c7 44 24 10 16 27 00 	mov    DWORD PTR [esp+0x10],0x2716
  4c1ed7:	00 
  4c1ed8:	e8 a3 67 fe ff       	call   0x4a8680
  4c1edd:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1ee1:	c7 44 24 10 17 27 00 	mov    DWORD PTR [esp+0x10],0x2717
  4c1ee8:	00 
  4c1ee9:	e8 92 67 fe ff       	call   0x4a8680
  4c1eee:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1ef2:	c7 44 24 10 38 27 00 	mov    DWORD PTR [esp+0x10],0x2738
  4c1ef9:	00 
  4c1efa:	e8 81 67 fe ff       	call   0x4a8680
  4c1eff:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1f03:	c7 44 24 10 44 27 00 	mov    DWORD PTR [esp+0x10],0x2744
  4c1f0a:	00 
  4c1f0b:	e8 70 67 fe ff       	call   0x4a8680
  4c1f10:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1f14:	c7 44 24 10 45 27 00 	mov    DWORD PTR [esp+0x10],0x2745
  4c1f1b:	00 
  4c1f1c:	e8 5f 67 fe ff       	call   0x4a8680
  4c1f21:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1f25:	c7 44 24 10 2b 4e 00 	mov    DWORD PTR [esp+0x10],0x4e2b
  4c1f2c:	00 
  4c1f2d:	e8 4e 67 fe ff       	call   0x4a8680
  4c1f32:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c1f36:	c7 44 24 10 31 4e 00 	mov    DWORD PTR [esp+0x10],0x4e31
  4c1f3d:	00 
  4c1f3e:	e8 3d 67 fe ff       	call   0x4a8680
  4c1f43:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  4c1f47:	83 ec 08             	sub    esp,0x8
  4c1f4a:	8b fc                	mov    edi,esp
  4c1f4c:	89 64 24 18          	mov    DWORD PTR [esp+0x18],esp
  4c1f50:	89 1f                	mov    DWORD PTR [edi],ebx
  4c1f52:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  4c1f55:	3b d3                	cmp    edx,ebx
  4c1f57:	74 16                	je     0x4c1f6f
  4c1f59:	e8 f2 a2 fb ff       	call   0x47c250
  4c1f5e:	84 c0                	test   al,al
  4c1f60:	74 0d                	je     0x4c1f6f
  4c1f62:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4c1f66:	51                   	push   ecx
  4c1f67:	56                   	push   esi
  4c1f68:	8b f7                	mov    esi,edi
  4c1f6a:	e8 51 12 2e 00       	call   0x7a31c0
  4c1f6f:	c6 44 24 30 01       	mov    BYTE PTR [esp+0x30],0x1
  4c1f74:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  4c1f7b:	bf 01 00 00 00       	mov    edi,0x1
  4c1f80:	75 22                	jne    0x4c1fa4
  4c1f82:	09 3d 60 0f fc 00    	or     DWORD PTR ds:0xfc0f60,edi
  4c1f88:	c6 44 24 30 02       	mov    BYTE PTR [esp+0x30],0x2
  4c1f8d:	e8 ae af 2d 00       	call   0x79cf40
  4c1f92:	68 80 db bc 00       	push   0xbcdb80
  4c1f97:	e8 7e 03 3d 00       	call   0x89231a
  4c1f9c:	83 c4 04             	add    esp,0x4
  4c1f9f:	c6 44 24 30 01       	mov    BYTE PTR [esp+0x30],0x1
  4c1fa4:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  4c1fa9:	88 5c 24 30          	mov    BYTE PTR [esp+0x30],bl
  4c1fad:	e8 2e bd 2d 00       	call   0x79dce0
  4c1fb2:	8b f0                	mov    esi,eax
  4c1fb4:	6a ff                	push   0xffffffff
  4c1fb6:	56                   	push   esi
  4c1fb7:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  4c1fbd:	56                   	push   esi
  4c1fbe:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  4c1fc4:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c1fcb:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c1fce:	89 ba 78 bd 00 00    	mov    DWORD PTR [edx+0xbd78],edi
  4c1fd4:	75 21                	jne    0x4c1ff7
  4c1fd6:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c1fdc:	c6 44 24 28 03       	mov    BYTE PTR [esp+0x28],0x3
  4c1fe1:	e8 ca 8e fb ff       	call   0x47aeb0
  4c1fe6:	68 70 db bc 00       	push   0xbcdb70
  4c1feb:	e8 2a 03 3d 00       	call   0x89231a
  4c1ff0:	83 c4 04             	add    esp,0x4
  4c1ff3:	88 5c 24 28          	mov    BYTE PTR [esp+0x28],bl
  4c1ff7:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c1ffc:	e8 bf 69 fe ff       	call   0x4a89c0

## expedition-synopsis-update-and-completion: [0x4c1930, 0x4c1a39)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c1930 <.text+0xc0930>:
  4c1930:	55                   	push   ebp
  4c1931:	8b ec                	mov    ebp,esp
  4c1933:	83 e4 f8             	and    esp,0xfffffff8
  4c1936:	6a ff                	push   0xffffffff
  4c1938:	68 d2 07 94 00       	push   0x9407d2
  4c193d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c1943:	50                   	push   eax
  4c1944:	83 ec 28             	sub    esp,0x28
  4c1947:	53                   	push   ebx
  4c1948:	56                   	push   esi
  4c1949:	57                   	push   edi
  4c194a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c194f:	33 c4                	xor    eax,esp
  4c1951:	50                   	push   eax
  4c1952:	8d 44 24 38          	lea    eax,[esp+0x38]
  4c1956:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c195c:	8b f1                	mov    esi,ecx
  4c195e:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  4c1962:	83 be 78 bd 00 00 00 	cmp    DWORD PTR [esi+0xbd78],0x0
  4c1969:	bf 01 00 00 00       	mov    edi,0x1
  4c196e:	0f 84 c2 00 00 00    	je     0x4c1a36
  4c1974:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c197b:	75 29                	jne    0x4c19a6
  4c197d:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c1983:	c7 44 24 40 00 00 00 	mov    DWORD PTR [esp+0x40],0x0
  4c198a:	00 
  4c198b:	e8 20 95 fb ff       	call   0x47aeb0
  4c1990:	68 70 db bc 00       	push   0xbcdb70
  4c1995:	e8 80 09 3d 00       	call   0x89231a
  4c199a:	83 c4 04             	add    esp,0x4
  4c199d:	83 cb ff             	or     ebx,0xffffffff
  4c19a0:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  4c19a4:	eb 03                	jmp    0x4c19a9
  4c19a6:	83 cb ff             	or     ebx,0xffffffff
  4c19a9:	68 84 0f fc 00       	push   0xfc0f84
  4c19ae:	e8 dd 71 fe ff       	call   0x4a8b90
  4c19b3:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c19ba:	75 20                	jne    0x4c19dc
  4c19bc:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c19c2:	89 7c 24 40          	mov    DWORD PTR [esp+0x40],edi
  4c19c6:	e8 e5 94 fb ff       	call   0x47aeb0
  4c19cb:	68 70 db bc 00       	push   0xbcdb70
  4c19d0:	e8 45 09 3d 00       	call   0x89231a
  4c19d5:	83 c4 04             	add    esp,0x4
  4c19d8:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  4c19dc:	83 3d b8 0f fc 00 00 	cmp    DWORD PTR ds:0xfc0fb8,0x0
  4c19e3:	75 54                	jne    0x4c1a39
  4c19e5:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c19ec:	75 24                	jne    0x4c1a12
  4c19ee:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c19f4:	c7 44 24 40 02 00 00 	mov    DWORD PTR [esp+0x40],0x2
  4c19fb:	00 
  4c19fc:	e8 af 94 fb ff       	call   0x47aeb0
  4c1a01:	68 70 db bc 00       	push   0xbcdb70
  4c1a06:	e8 0f 09 3d 00       	call   0x89231a
  4c1a0b:	83 c4 04             	add    esp,0x4
  4c1a0e:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  4c1a12:	a1 84 0f fc 00       	mov    eax,ds:0xfc0f84
  4c1a17:	68 bc 68 c0 00       	push   0xc068bc
  4c1a1c:	6a 00                	push   0x0
  4c1a1e:	50                   	push   eax
  4c1a1f:	e8 7c b6 fe ff       	call   0x4ad0a0
  4c1a24:	b9 84 0f fc 00       	mov    ecx,0xfc0f84
  4c1a29:	e8 82 83 fe ff       	call   0x4a9db0
  4c1a2e:	56                   	push   esi
  4c1a2f:	e8 1c 06 00 00       	call   0x4c2050
  4c1a34:	eb 03                	jmp    0x4c1a39
  4c1a36:	83 cb ff             	or     ebx,0xffffffff

## expedition-synopsis-cancel-and-disable: [0x4c2050, 0x4c20d0)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c2050 <.text+0xc1050>:
  4c2050:	55                   	push   ebp
  4c2051:	8b ec                	mov    ebp,esp
  4c2053:	6a ff                	push   0xffffffff
  4c2055:	68 cc 96 93 00       	push   0x9396cc
  4c205a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c2060:	50                   	push   eax
  4c2061:	83 ec 10             	sub    esp,0x10
  4c2064:	53                   	push   ebx
  4c2065:	56                   	push   esi
  4c2066:	57                   	push   edi
  4c2067:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c206c:	33 c5                	xor    eax,ebp
  4c206e:	50                   	push   eax
  4c206f:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c2072:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c2078:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c207f:	75 27                	jne    0x4c20a8
  4c2081:	83 0d 80 0f fc 00 01 	or     DWORD PTR ds:0xfc0f80,0x1
  4c2088:	33 ff                	xor    edi,edi
  4c208a:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4c208d:	e8 1e 8e fb ff       	call   0x47aeb0
  4c2092:	68 70 db bc 00       	push   0xbcdb70
  4c2097:	e8 7e 02 3d 00       	call   0x89231a
  4c209c:	83 c4 04             	add    esp,0x4
  4c209f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c20a6:	eb 02                	jmp    0x4c20aa
  4c20a8:	33 ff                	xor    edi,edi
  4c20aa:	a1 84 0f fc 00       	mov    eax,ds:0xfc0f84
  4c20af:	68 bc 68 c0 00       	push   0xc068bc
  4c20b4:	57                   	push   edi
  4c20b5:	50                   	push   eax
  4c20b6:	e8 e5 af fe ff       	call   0x4ad0a0
  4c20bb:	b9 84 0f fc 00       	mov    ecx,0xfc0f84
  4c20c0:	e8 eb 7c fe ff       	call   0x4a9db0
  4c20c5:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c20c8:	6a 1c                	push   0x1c
  4c20ca:	89 b9 78 bd 00 00    	mov    DWORD PTR [ecx+0xbd78],edi

## ui-review-third-tutorial-pump: [0x47c980, 0x47caac)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0047c980 <.text+0x7b980>:
  47c980:	55                   	push   ebp
  47c981:	8b ec                	mov    ebp,esp
  47c983:	6a ff                	push   0xffffffff
  47c985:	68 7c 98 93 00       	push   0x93987c
  47c98a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47c990:	50                   	push   eax
  47c991:	53                   	push   ebx
  47c992:	56                   	push   esi
  47c993:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47c998:	33 c5                	xor    eax,ebp
  47c99a:	50                   	push   eax
  47c99b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47c99e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47c9a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47c9a7:	8b 80 fc 00 00 00    	mov    eax,DWORD PTR [eax+0xfc]
  47c9ad:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c9b3:	85 c0                	test   eax,eax
  47c9b5:	0f 84 dd 00 00 00    	je     0x47ca98
  47c9bb:	8b b0 dc 00 00 00    	mov    esi,DWORD PTR [eax+0xdc]
  47c9c1:	85 f6                	test   esi,esi
  47c9c3:	0f 84 cf 00 00 00    	je     0x47ca98
  47c9c9:	8b 16                	mov    edx,DWORD PTR [esi]
  47c9cb:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  47c9ce:	8b ce                	mov    ecx,esi
  47c9d0:	ff d0                	call   eax
  47c9d2:	3d 2d 01 00 00       	cmp    eax,0x12d
  47c9d7:	74 27                	je     0x47ca00
  47c9d9:	6a 00                	push   0x0
  47c9db:	68 c0 1f bf 00       	push   0xbf1fc0
  47c9e0:	68 18 21 bf 00       	push   0xbf2118
  47c9e5:	6a 00                	push   0x0
  47c9e7:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  47c9ed:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47c9f0:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47c9f7:	59                   	pop    ecx
  47c9f8:	5e                   	pop    esi
  47c9f9:	5b                   	pop    ebx
  47c9fa:	8b e5                	mov    esp,ebp
  47c9fc:	5d                   	pop    ebp
  47c9fd:	c2 04 00             	ret    0x4
  47ca00:	80 be 6c 02 00 00 00 	cmp    BYTE PTR [esi+0x26c],0x0
  47ca07:	0f 84 8b 00 00 00    	je     0x47ca98
  47ca0d:	bb 01 00 00 00       	mov    ebx,0x1
  47ca12:	84 1d 80 0f fc 00    	test   BYTE PTR ds:0xfc0f80,bl
  47ca18:	75 26                	jne    0x47ca40
  47ca1a:	09 1d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,ebx
  47ca20:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47ca27:	e8 84 e4 ff ff       	call   0x47aeb0
  47ca2c:	68 70 db bc 00       	push   0xbcdb70
  47ca31:	e8 e4 58 41 00       	call   0x89231a
  47ca36:	83 c4 04             	add    esp,0x4
  47ca39:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47ca40:	68 84 0f fc 00       	push   0xfc0f84
  47ca45:	e8 46 c1 02 00       	call   0x4a8b90
  47ca4a:	84 1d 80 0f fc 00    	test   BYTE PTR ds:0xfc0f80,bl
  47ca50:	75 22                	jne    0x47ca74
  47ca52:	09 1d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,ebx
  47ca58:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47ca5b:	e8 50 e4 ff ff       	call   0x47aeb0
  47ca60:	68 70 db bc 00       	push   0xbcdb70
  47ca65:	e8 b0 58 41 00       	call   0x89231a
  47ca6a:	83 c4 04             	add    esp,0x4
  47ca6d:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47ca74:	83 3d b8 0f fc 00 00 	cmp    DWORD PTR ds:0xfc0fb8,0x0
  47ca7b:	75 1b                	jne    0x47ca98
  47ca7d:	56                   	push   esi
  47ca7e:	e8 2d ec ff ff       	call   0x47b6b0
  47ca83:	e8 d8 25 f9 ff       	call   0x40f060
  47ca88:	8b 40 48             	mov    eax,DWORD PTR [eax+0x48]
  47ca8b:	50                   	push   eax
  47ca8c:	e8 6f f8 ff ff       	call   0x47c300
  47ca91:	8b c8                	mov    ecx,eax
  47ca93:	e8 98 c9 25 00       	call   0x6d9430
  47ca98:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47ca9b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47caa2:	59                   	pop    ecx
  47caa3:	5e                   	pop    esi
  47caa4:	5b                   	pop    ebx
  47caa5:	8b e5                	mov    esp,ebp
  47caa7:	5d                   	pop    ebp
  47caa8:	c2 04 00             	ret    0x4
  47caab:	cc                   	int3

## mission-field-update: [0x423060, 0x4230eb)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00423060 <.text+0x22060>:
  423060:	55                   	push   ebp
  423061:	8b ec                	mov    ebp,esp
  423063:	51                   	push   ecx
  423064:	56                   	push   esi
  423065:	8b f1                	mov    esi,ecx
  423067:	e8 a4 aa 08 00       	call   0x4adb10
  42306c:	83 be 54 bd 00 00 00 	cmp    DWORD PTR [esi+0xbd54],0x0
  423073:	74 6f                	je     0x4230e4
  423075:	d9 86 58 bd 00 00    	fld    DWORD PTR [esi+0xbd58]
  42307b:	dc 25 70 5a c5 00    	fsub   QWORD PTR ds:0xc55a70
  423081:	d9 5d fc             	fstp   DWORD PTR [ebp-0x4]
  423084:	d9 45 fc             	fld    DWORD PTR [ebp-0x4]
  423087:	d9 96 58 bd 00 00    	fst    DWORD PTR [esi+0xbd58]
  42308d:	d9 ee                	fldz
  42308f:	df f1                	fcomip st,st(1)
  423091:	dd d8                	fstp   st(0)
  423093:	76 4f                	jbe    0x4230e4
  423095:	b8 01 00 00 00       	mov    eax,0x1
  42309a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  4230a0:	75 13                	jne    0x4230b5
  4230a2:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  4230a8:	68 10 cf bc 00       	push   0xbccf10
  4230ad:	e8 68 f2 46 00       	call   0x89231a
  4230b2:	83 c4 04             	add    esp,0x4
  4230b5:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4230bc:	c7 45 fc 31 00 00 00 	mov    DWORD PTR [ebp-0x4],0x31
  4230c3:	75 15                	jne    0x4230da
  4230c5:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4230cb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4230cd:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4230d0:	6a 04                	push   0x4
  4230d2:	8d 45 fc             	lea    eax,[ebp-0x4]
  4230d5:	50                   	push   eax
  4230d6:	6a 00                	push   0x0
  4230d8:	ff d2                	call   edx
  4230da:	c7 86 54 bd 00 00 00 	mov    DWORD PTR [esi+0xbd54],0x0
  4230e1:	00 00 00 
  4230e4:	33 c0                	xor    eax,eax
  4230e6:	5e                   	pop    esi
  4230e7:	8b e5                	mov    esp,ebp
  4230e9:	5d                   	pop    ebp
  4230ea:	c3                   	ret

## base-field-update-virtuals: [0x4adb10, 0x4adb85)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004adb10 <.text+0xacb10>:
  4adb10:	56                   	push   esi
  4adb11:	57                   	push   edi
  4adb12:	8b f9                	mov    edi,ecx
  4adb14:	b9 01 00 00 00       	mov    ecx,0x1
  4adb19:	84 0d ec 79 fb 00    	test   BYTE PTR ds:0xfb79ec,cl
  4adb1f:	75 34                	jne    0x4adb55
  4adb21:	09 0d ec 79 fb 00    	or     DWORD PTR ds:0xfb79ec,ecx
  4adb27:	33 c0                	xor    eax,eax
  4adb29:	68 70 d2 bc 00       	push   0xbcd270
  4adb2e:	c7 05 f0 79 fb 00 68 	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  4adb35:	f8 c0 00 
  4adb38:	a3 f4 79 fb 00       	mov    ds:0xfb79f4,eax
  4adb3d:	a3 f8 79 fb 00       	mov    ds:0xfb79f8,eax
  4adb42:	a3 fc 79 fb 00       	mov    ds:0xfb79fc,eax
  4adb47:	89 0d 04 7a fb 00    	mov    DWORD PTR ds:0xfb7a04,ecx
  4adb4d:	e8 c8 47 3e 00       	call   0x89231a
  4adb52:	83 c4 04             	add    esp,0x4
  4adb55:	8b 35 f4 79 fb 00    	mov    esi,DWORD PTR ds:0xfb79f4
  4adb5b:	3b 35 f8 79 fb 00    	cmp    esi,DWORD PTR ds:0xfb79f8
  4adb61:	74 14                	je     0x4adb77
  4adb63:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4adb65:	8b 01                	mov    eax,DWORD PTR [ecx]
  4adb67:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4adb6a:	ff d2                	call   edx
  4adb6c:	83 c6 04             	add    esi,0x4
  4adb6f:	3b 35 f8 79 fb 00    	cmp    esi,DWORD PTR ds:0xfb79f8
  4adb75:	75 ec                	jne    0x4adb63
  4adb77:	8b 07                	mov    eax,DWORD PTR [edi]
  4adb79:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  4adb7c:	8b cf                	mov    ecx,edi
  4adb7e:	ff d2                	call   edx
  4adb80:	5f                   	pop    edi
  4adb81:	33 c0                	xor    eax,eax
  4adb83:	5e                   	pop    esi
  4adb84:	c3                   	ret

## mission-field-exit-hook: [0x4bbf10, 0x4bbf80)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bbf10 <.text+0xbaf10>:
  4bbf10:	55                   	push   ebp
  4bbf11:	8b ec                	mov    ebp,esp
  4bbf13:	6a ff                	push   0xffffffff
  4bbf15:	68 0e db 90 00       	push   0x90db0e
  4bbf1a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4bbf20:	50                   	push   eax
  4bbf21:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4bbf26:	33 c5                	xor    eax,ebp
  4bbf28:	50                   	push   eax
  4bbf29:	8d 45 f4             	lea    eax,[ebp-0xc]
  4bbf2c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4bbf32:	b8 01 00 00 00       	mov    eax,0x1
  4bbf37:	84 05 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,al
  4bbf3d:	75 26                	jne    0x4bbf65
  4bbf3f:	09 05 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,eax
  4bbf45:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4bbf4c:	e8 7f 74 09 00       	call   0x5533d0
  4bbf51:	68 00 d1 bc 00       	push   0xbcd100
  4bbf56:	e8 bf 63 3d 00       	call   0x89231a
  4bbf5b:	83 c4 04             	add    esp,0x4
  4bbf5e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4bbf65:	b8 58 73 fb 00       	mov    eax,0xfb7358
  4bbf6a:	e8 d1 77 09 00       	call   0x553740
  4bbf6f:	33 c0                	xor    eax,eax
  4bbf71:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4bbf74:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4bbf7b:	59                   	pop    ecx
  4bbf7c:	8b e5                	mov    esp,ebp
  4bbf7e:	5d                   	pop    ebp
  4bbf7f:	c3                   	ret

## mission-s2c0031-cancel-helper: [0x4bca90, 0x4bcb3d)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bca90 <.text+0xbba90>:
  4bca90:	55                   	push   ebp
  4bca91:	8b ec                	mov    ebp,esp
  4bca93:	6a ff                	push   0xffffffff
  4bca95:	68 3c 48 94 00       	push   0x94483c
  4bca9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4bcaa0:	50                   	push   eax
  4bcaa1:	53                   	push   ebx
  4bcaa2:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4bcaa7:	33 c5                	xor    eax,ebp
  4bcaa9:	50                   	push   eax
  4bcaaa:	8d 45 f4             	lea    eax,[ebp-0xc]
  4bcaad:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4bcab3:	bb 01 00 00 00       	mov    ebx,0x1
  4bcab8:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4bcabe:	75 26                	jne    0x4bcae6
  4bcac0:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4bcac6:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4bcacd:	e8 ae a9 0c 00       	call   0x587480
  4bcad2:	68 c0 cc bc 00       	push   0xbcccc0
  4bcad7:	e8 3e 58 3d 00       	call   0x89231a
  4bcadc:	83 c4 04             	add    esp,0x4
  4bcadf:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4bcae6:	68 67 42 0f 00       	push   0xf4267
  4bcaeb:	e8 e0 df 0c 00       	call   0x58aad0
  4bcaf0:	83 c4 04             	add    esp,0x4
  4bcaf3:	84 1d b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,bl
  4bcaf9:	75 22                	jne    0x4bcb1d
  4bcafb:	09 1d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,ebx
  4bcb01:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4bcb04:	e8 67 36 0a 00       	call   0x560170
  4bcb09:	68 10 d1 bc 00       	push   0xbcd110
  4bcb0e:	e8 07 58 3d 00       	call   0x89231a
  4bcb13:	83 c4 04             	add    esp,0x4
  4bcb16:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4bcb1d:	6a 00                	push   0x0
  4bcb1f:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4bcb24:	e8 87 59 0a 00       	call   0x5624b0
  4bcb29:	33 c0                	xor    eax,eax
  4bcb2b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4bcb2e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4bcb35:	59                   	pop    ecx
  4bcb36:	5b                   	pop    ebx
  4bcb37:	8b e5                	mov    esp,ebp
  4bcb39:	5d                   	pop    ebp
  4bcb3a:	c2 0c 00             	ret    0xc

## q-end-binding-target: [0x565fc0, 0x566059)

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00565fc0 <.text+0x164fc0>:
  565fc0:	55                   	push   ebp
  565fc1:	8b ec                	mov    ebp,esp
  565fc3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  565fc6:	53                   	push   ebx
  565fc7:	8b 1d 74 27 fe 00    	mov    ebx,DWORD PTR ds:0xfe2774
  565fcd:	56                   	push   esi
  565fce:	8b 33                	mov    esi,DWORD PTR [ebx]
  565fd0:	57                   	push   edi
  565fd1:	8b 38                	mov    edi,DWORD PTR [eax]
  565fd3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  565fd8:	c7 05 80 27 fe 00 b0 	mov    DWORD PTR ds:0xfe2780,0x561db0
  565fdf:	1d 56 00 
  565fe2:	e8 99 f6 18 00       	call   0x6f5680
  565fe7:	8b 03                	mov    eax,DWORD PTR [ebx]
  565fe9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  565fec:	83 e8 10             	sub    eax,0x10
  565fef:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  565ff4:	74 06                	je     0x565ffc
  565ff6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  565ffa:	74 14                	je     0x566010
  565ffc:	57                   	push   edi
  565ffd:	68 c4 26 c4 00       	push   0xc426c4
  566002:	e8 b6 d0 32 00       	call   0x8930bd
  566007:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  566009:	83 c4 08             	add    esp,0x8
  56600c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  566010:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  566016:	8b 37                	mov    esi,DWORD PTR [edi]
  566018:	68 60 a2 d6 00       	push   0xd6a260
  56601d:	e8 ee f4 18 00       	call   0x6f5510
  566022:	8b 37                	mov    esi,DWORD PTR [edi]
  566024:	83 c4 04             	add    esp,0x4
  566027:	6a 00                	push   0x0
  566029:	68 90 8a 56 00       	push   0x568a90
  56602e:	e8 7d f5 18 00       	call   0x6f55b0
  566033:	8b 0f                	mov    ecx,DWORD PTR [edi]
  566035:	51                   	push   ecx
  566036:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  56603b:	e8 b0 f7 18 00       	call   0x6f57f0
  566040:	8b 15 74 27 fe 00    	mov    edx,DWORD PTR ds:0xfe2774
  566046:	8b 02                	mov    eax,DWORD PTR [edx]
  566048:	83 c4 0c             	add    esp,0xc
  56604b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  56604f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  566052:	5f                   	pop    edi
  566053:	5e                   	pop    esi
  566054:	5b                   	pop    ebx
  566055:	5d                   	pop    ebp
  566056:	c2 04 00             	ret    0x4

## client-update-vtable: [0xc05aa0, 0xc05ae8), raw 0x8040a0
0c94c600e0ad490070ee4800f0ff48005005490010f948002008490090b7730040ed6d0050be480070c14800e0c6480030e64800e00f490040204900002949003064470030644700

## client-update-col: [0xc6940c, 0xc69420), raw 0x867a0c
0000000008000000000000001cddf7003494c600

## client-update-type: [0xf7dd1c, 0xf7dd32), raw 0xb7b51c
f435bd00000000002e3f415643436c69656e74404000

## tutorial-scene-vtable: [0xc073e4, 0xc07418), raw 0x8059e4
049ec60040594c0070464c0010284200f0274200104b4c00604d4c00f04d4c00f045420020dc4a009066450040064b0070254b00

## tutorial-scene-col: [0xc69e04, 0xc69e18), raw 0x868404
000000000000000000000000e0e1f700189ec600

## tutorial-scene-type: [0xf7e1e0, 0xf7e200), raw 0xb7b9e0
f435bd00000000002e3f4156435475746f7269616c405363656e654040000000

## expedition-scene-vtable: [0xc0727c, 0xc072b0), raw 0x80587c
709cc60030154c0070464c0010284200f0274200c0154c00f0c28d0030194c00801c4c00f0c28d009066450040064b0070254b00

## expedition-scene-col: [0xc69c70, 0xc69c84), raw 0x868270
00000000000000000000000038e1f700849cc600

## expedition-scene-type: [0xf7e138, 0xf7e158), raw 0xb7b938
f435bd00000000002e3f41564345787065646974696f6e405363656e65404000

## mission-field-vtable: [0xc07058, 0xc0708c), raw 0x805658
889ac60040594c0070464c0010284200f027420050c74b0010bf4b006030420090db4a0020dc4a0090484c0040064b00f0304200

## mission-field-col: [0xc69a88, 0xc69a9c), raw 0x868088
00000000000000000000000060e0f7009c9ac600

## mission-field-type: [0xf7e060, 0xf7e084), raw 0xb7b860
f435bd00000000002e3f4156434d697373696f6e4669656c64405363656e654040000000

## scenario-field-vtable: [0xc073b0, 0xc073e4), raw 0x8059b0
b49dc60040594c0070464c0010284200f027420050474c00f0c28d0010db4a0090db4a0020dc4a0090484c0020494c0010494c00

## scenario-field-col: [0xc69db4, 0xc69dc8), raw 0x8683b4
000000000000000000000000bce1f700c89dc600

## scenario-field-type: [0xf7e1bc, 0xf7e1e0), raw 0xb7b9bc
f435bd00000000002e3f4156435363656e6172696f4669656c64405363656e6540400000

## tutorial-script-and-entry-names: [0xc06864, 0xc068df), raw 0x804e64
4576656e742f5475746f7269616c426173652e6c756100004576656e742f5475746f7269616c4d61696e2e6c7561000053796e6f707369735f456e747279506f696e74005475746f7269616c5f456e747279506f696e7400745f72656d6f7665416c6c436f726f7574696e6573000000745f646f436f5461736b00

## tutorial-scene-query-stop-names: [0xd6ac00, 0xd6ac21), raw 0x968400
49734375745363656e6552756e6e696e6700000053746f704375745363656e6500

## q-pump-name: [0xc106a0, 0xc106ab), raw 0x80eca0
665f646f436f5461736b00

## q-remove-all-name: [0xc106ec, 0xc10702), raw 0x80ecec
665f72656d6f7665416c6c436f726f7574696e657300

## q-end-api-name: [0xd6a260, 0xd6a26c), raw 0x967a60
456e644375745363656e6500

## root-script-names: [0xc055b0, 0xc055d6), raw 0x803bb0
426f6f742e6c7561000000004c6f6769632e6c7561000000436f726f7574696e652e6c756100

## qbase-resource-name: [0xc10658, 0xc10668), raw 0x80ec58
4576656e742f71626173652e6c756100

# RESEARCH GROUP: events

### N01: Existing common S2C 000C handler registration
# VA 0x4addc6..0x4addd0 exclusive; raw 0x000ad1c6; SHA256 ee3ead9043611fe42f1175437c261b74184e34aee98fe169bd2199053c9e769e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004addc6 <.text+0xacdc6>:
  4addc6:	c7 40 64 30 01 4b 00 	mov    DWORD PTR [eax+0x64],0x4b0130
  4addcd:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx

### N02: 000C handler view: 3-byte EntityId/state rows to actor FSM
# VA 0x4b0130..0x4b01bf exclusive; raw 0x000af530; SHA256 8c455f0159324b40abd9ea1ca240572e9ef169f270961ce32d4e0e5c21d6147b

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b0130 <.text+0xaf130>:
  4b0130:	55                   	push   ebp
  4b0131:	8b ec                	mov    ebp,esp
  4b0133:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b0136:	83 f8 02             	cmp    eax,0x2
  4b0139:	73 04                	jae    0x4b013f
  4b013b:	33 d2                	xor    edx,edx
  4b013d:	eb 0c                	jmp    0x4b014b
  4b013f:	8d 48 fe             	lea    ecx,[eax-0x2]
  4b0142:	b8 ab aa aa aa       	mov    eax,0xaaaaaaab
  4b0147:	f7 e1                	mul    ecx
  4b0149:	d1 ea                	shr    edx,1
  4b014b:	85 d2                	test   edx,edx
  4b014d:	74 6a                	je     0x4b01b9
  4b014f:	53                   	push   ebx
  4b0150:	56                   	push   esi
  4b0151:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b0154:	57                   	push   edi
  4b0155:	83 c6 02             	add    esi,0x2
  4b0158:	8b da                	mov    ebx,edx
  4b015a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4b0160:	0f b7 16             	movzx  edx,WORD PTR [esi]
  4b0163:	89 55 0c             	mov    DWORD PTR [ebp+0xc],edx
  4b0166:	e8 f5 ee f5 ff       	call   0x40f060
  4b016b:	8b f8                	mov    edi,eax
  4b016d:	8d 45 0c             	lea    eax,[ebp+0xc]
  4b0170:	50                   	push   eax
  4b0171:	8d 4f 08             	lea    ecx,[edi+0x8]
  4b0174:	8d 45 08             	lea    eax,[ebp+0x8]
  4b0177:	e8 84 ed 37 00       	call   0x82ef00
  4b017c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b017f:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  4b0182:	74 07                	je     0x4b018b
  4b0184:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b0187:	85 c0                	test   eax,eax
  4b0189:	75 0f                	jne    0x4b019a
  4b018b:	68 fc 6a c0 00       	push   0xc06afc
  4b0190:	e8 cb d9 23 00       	call   0x6edb60
  4b0195:	83 c4 04             	add    esp,0x4
  4b0198:	eb 16                	jmp    0x4b01b0
  4b019a:	8b 90 f0 00 00 00    	mov    edx,DWORD PTR [eax+0xf0]
  4b01a0:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  4b01a3:	8d 88 f0 00 00 00    	lea    ecx,[eax+0xf0]
  4b01a9:	0f be 46 02          	movsx  eax,BYTE PTR [esi+0x2]
  4b01ad:	50                   	push   eax
  4b01ae:	ff d2                	call   edx
  4b01b0:	83 c6 03             	add    esi,0x3
  4b01b3:	4b                   	dec    ebx
  4b01b4:	75 aa                	jne    0x4b0160
  4b01b6:	5f                   	pop    edi
  4b01b7:	5e                   	pop    esi
  4b01b8:	5b                   	pop    ebx
  4b01b9:	33 c0                	xor    eax,eax
  4b01bb:	5d                   	pop    ebp
  4b01bc:	c2 0c 00             	ret    0xc

### N03: CMonster installs primary/secondary tables and state 3
# VA 0x4d1736..0x4d17c8 exclusive; raw 0x000d0b36; SHA256 50734d70e124ee4207385a7f8873b8713bb7200264a2ff244fa0adf27df66c29

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1736 <.text+0xd0736>:
  4d1736:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4d1739:	57                   	push   edi
  4d173a:	e8 31 59 ff ff       	call   0x4c7070
  4d173f:	33 db                	xor    ebx,ebx
  4d1741:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4d1744:	0f 57 c0             	xorps  xmm0,xmm0
  4d1747:	6a 3c                	push   0x3c
  4d1749:	c7 07 dc c9 c0 00    	mov    DWORD PTR [edi],0xc0c9dc
  4d174f:	c7 87 f0 00 00 00 64 	mov    DWORD PTR [edi+0xf0],0xc0ca64
  4d1756:	ca c0 00 
  4d1759:	89 9f 20 04 00 00    	mov    DWORD PTR [edi+0x420],ebx
  4d175f:	89 9f 28 04 00 00    	mov    DWORD PTR [edi+0x428],ebx
  4d1765:	f3 0f 11 87 2c 04 00 	movss  DWORD PTR [edi+0x42c],xmm0
  4d176c:	00 
  4d176d:	89 9f 30 04 00 00    	mov    DWORD PTR [edi+0x430],ebx
  4d1773:	e8 f0 fa 3b 00       	call   0x891268
  4d1778:	8b f0                	mov    esi,eax
  4d177a:	83 c4 04             	add    esp,0x4
  4d177d:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4d1780:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4d1784:	3b f3                	cmp    esi,ebx
  4d1786:	74 19                	je     0x4d17a1
  4d1788:	8b c7                	mov    eax,edi
  4d178a:	8d 4b 03             	lea    ecx,[ebx+0x3]
  4d178d:	e8 9e 9a ff ff       	call   0x4cb230
  4d1792:	c7 06 cc 77 c0 00    	mov    DWORD PTR [esi],0xc077cc
  4d1798:	c7 46 34 01 00 00 00 	mov    DWORD PTR [esi+0x34],0x1
  4d179f:	eb 02                	jmp    0x4d17a3
  4d17a1:	33 f6                	xor    esi,esi
  4d17a3:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4d17a7:	8b 5e 08             	mov    ebx,DWORD PTR [esi+0x8]
  4d17aa:	83 bc 9f f4 00 00 00 	cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
  4d17b1:	00 
  4d17b2:	74 0d                	je     0x4d17c1
  4d17b4:	68 3c 75 c0 00       	push   0xc0753c
  4d17b9:	e8 a2 c3 21 00       	call   0x6edb60
  4d17be:	83 c4 04             	add    esp,0x4
  4d17c1:	89 b4 9f f4 00 00 00 	mov    DWORD PTR [edi+ebx*4+0xf4],esi

### N04: Actor state constructor owner +04 and state ID +08
# VA 0x4cb230..0x4cb245 exclusive; raw 0x000ca630; SHA256 a7097d207402f11016c2610887111fa007d16ec9e1ab11220b98bff3eec23f77

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cb230 <.text+0xca230>:
  4cb230:	55                   	push   ebp
  4cb231:	8b ec                	mov    ebp,esp
  4cb233:	83 ec 10             	sub    esp,0x10
  4cb236:	57                   	push   edi
  4cb237:	33 ff                	xor    edi,edi
  4cb239:	c7 06 84 77 c0 00    	mov    DWORD PTR [esi],0xc07784
  4cb23f:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  4cb242:	89 4e 08             	mov    DWORD PTR [esi+0x8],ecx

### N05: FSM transition exits old and enters selected registered state
# VA 0x4ca060..0x4ca0ab exclusive; raw 0x000c9460; SHA256 2bef145cdcd604a8197d7838922ae2e06e3fe2822a9e8d2b4c682aeabe729231

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ca060 <.text+0xc9060>:
  4ca060:	55                   	push   ebp
  4ca061:	8b ec                	mov    ebp,esp
  4ca063:	56                   	push   esi
  4ca064:	57                   	push   edi
  4ca065:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4ca068:	8b f1                	mov    esi,ecx
  4ca06a:	83 ff 1a             	cmp    edi,0x1a
  4ca06d:	74 34                	je     0x4ca0a3
  4ca06f:	83 7c be 04 00       	cmp    DWORD PTR [esi+edi*4+0x4],0x0
  4ca074:	74 2d                	je     0x4ca0a3
  4ca076:	8b 4e 68             	mov    ecx,DWORD PTR [esi+0x68]
  4ca079:	8b 01                	mov    eax,DWORD PTR [ecx]
  4ca07b:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  4ca07e:	ff d2                	call   edx
  4ca080:	8b 46 68             	mov    eax,DWORD PTR [esi+0x68]
  4ca083:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4ca086:	8b 4c be 04          	mov    ecx,DWORD PTR [esi+edi*4+0x4]
  4ca08a:	89 51 0c             	mov    DWORD PTR [ecx+0xc],edx
  4ca08d:	8b 4c be 04          	mov    ecx,DWORD PTR [esi+edi*4+0x4]
  4ca091:	89 4e 68             	mov    DWORD PTR [esi+0x68],ecx
  4ca094:	8b 01                	mov    eax,DWORD PTR [ecx]
  4ca096:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4ca099:	ff d2                	call   edx
  4ca09b:	5f                   	pop    edi
  4ca09c:	b0 01                	mov    al,0x1
  4ca09e:	5e                   	pop    esi
  4ca09f:	5d                   	pop    ebp
  4ca0a0:	c2 04 00             	ret    0x4
  4ca0a3:	5f                   	pop    edi
  4ca0a4:	32 c0                	xor    al,al
  4ca0a6:	5e                   	pop    esi
  4ca0a7:	5d                   	pop    ebp
  4ca0a8:	c2 04 00             	ret    0x4

### N06: CDeadState enter
# VA 0x4cb590..0x4cb70d exclusive; raw 0x000ca990; SHA256 82be10e0cad9fc7304566d0ef4d21158c38394a4f2ab90a8e0a0cff56eee0131

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cb590 <.text+0xca590>:
  4cb590:	55                   	push   ebp
  4cb591:	8b ec                	mov    ebp,esp
  4cb593:	6a ff                	push   0xffffffff
  4cb595:	68 ac 9e 93 00       	push   0x939eac
  4cb59a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4cb5a0:	50                   	push   eax
  4cb5a1:	83 ec 14             	sub    esp,0x14
  4cb5a4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4cb5a9:	33 c5                	xor    eax,ebp
  4cb5ab:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4cb5ae:	53                   	push   ebx
  4cb5af:	56                   	push   esi
  4cb5b0:	57                   	push   edi
  4cb5b1:	50                   	push   eax
  4cb5b2:	8d 45 f4             	lea    eax,[ebp-0xc]
  4cb5b5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4cb5bb:	f6 05 00 b1 fa 00 01 	test   BYTE PTR ds:0xfab100,0x1
  4cb5c2:	8b d9                	mov    ebx,ecx
  4cb5c4:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  4cb5c7:	75 27                	jne    0x4cb5f0
  4cb5c9:	83 0d 00 b1 fa 00 01 	or     DWORD PTR ds:0xfab100,0x1
  4cb5d0:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4cb5d7:	e8 c4 20 fd ff       	call   0x49d6a0
  4cb5dc:	68 20 ce bc 00       	push   0xbcce20
  4cb5e1:	e8 34 6d 3c 00       	call   0x89231a
  4cb5e6:	83 c4 04             	add    esp,0x4
  4cb5e9:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4cb5f0:	f6 05 04 b1 fa 00 04 	test   BYTE PTR ds:0xfab104,0x4
  4cb5f7:	8b b6 88 00 00 00    	mov    esi,DWORD PTR [esi+0x88]
  4cb5fd:	74 07                	je     0x4cb606
  4cb5ff:	8b fe                	mov    edi,esi
  4cb601:	e8 da 22 fd ff       	call   0x49d8e0
  4cb606:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  4cb609:	d9 e8                	fld1
  4cb60b:	8b 01                	mov    eax,DWORD PTR [ecx]
  4cb60d:	8b 50 68             	mov    edx,DWORD PTR [eax+0x68]
  4cb610:	51                   	push   ecx
  4cb611:	d9 1c 24             	fstp   DWORD PTR [esp]
  4cb614:	6a 07                	push   0x7
  4cb616:	ff d2                	call   edx
  4cb618:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4cb61b:	50                   	push   eax
  4cb61c:	e8 ef d9 ff ff       	call   0x4c9010
  4cb621:	0f 57 c0             	xorps  xmm0,xmm0
  4cb624:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  4cb627:	f3 0f 11 43 38       	movss  DWORD PTR [ebx+0x38],xmm0
  4cb62c:	8b 11                	mov    edx,DWORD PTR [ecx]
  4cb62e:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  4cb631:	ff d0                	call   eax
  4cb633:	8b 08                	mov    ecx,DWORD PTR [eax]
  4cb635:	89 4d e4             	mov    DWORD PTR [ebp-0x1c],ecx
  4cb638:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4cb63b:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  4cb63e:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4cb641:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4cb644:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  4cb647:	8b b0 5c 01 00 00    	mov    esi,DWORD PTR [eax+0x15c]
  4cb64d:	85 f6                	test   esi,esi
  4cb64f:	74 13                	je     0x4cb664
  4cb651:	83 b8 70 03 00 00 00 	cmp    DWORD PTR [eax+0x370],0x0
  4cb658:	74 0a                	je     0x4cb664
  4cb65a:	e8 a1 ba 2d 00       	call   0x7a7100
  4cb65f:	d9 5d e0             	fstp   DWORD PTR [ebp-0x20]
  4cb662:	eb 08                	jmp    0x4cb66c
  4cb664:	0f 57 c0             	xorps  xmm0,xmm0
  4cb667:	f3 0f 11 45 e0       	movss  DWORD PTR [ebp-0x20],xmm0
  4cb66c:	f6 05 dc f6 fd 00 01 	test   BYTE PTR ds:0xfdf6dc,0x1
  4cb673:	d9 45 e0             	fld    DWORD PTR [ebp-0x20]
  4cb676:	dc 0d b0 56 c5 00    	fmul   QWORD PTR ds:0xc556b0
  4cb67c:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  4cb67f:	d8 45 ec             	fadd   DWORD PTR [ebp-0x14]
  4cb682:	d9 5d ec             	fstp   DWORD PTR [ebp-0x14]
  4cb685:	f3 0f 10 81 b4 00 00 	movss  xmm0,DWORD PTR [ecx+0xb4]
  4cb68c:	00 
  4cb68d:	f3 0f 11 45 e0       	movss  DWORD PTR [ebp-0x20],xmm0
  4cb692:	75 27                	jne    0x4cb6bb
  4cb694:	b8 01 00 00 00       	mov    eax,0x1
  4cb699:	09 05 dc f6 fd 00    	or     DWORD PTR ds:0xfdf6dc,eax
  4cb69f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4cb6a2:	e8 79 51 08 00       	call   0x550820
  4cb6a7:	68 b0 e6 bc 00       	push   0xbce6b0
  4cb6ac:	e8 69 6c 3c 00       	call   0x89231a
  4cb6b1:	83 c4 04             	add    esp,0x4
  4cb6b4:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4cb6bb:	6a ff                	push   0xffffffff
  4cb6bd:	6a ff                	push   0xffffffff
  4cb6bf:	b9 78 77 c0 00       	mov    ecx,0xc07778
  4cb6c4:	ba 80 f6 fd 00       	mov    edx,0xfdf680
  4cb6c9:	e8 b2 64 08 00       	call   0x551b80
  4cb6ce:	d9 45 e0             	fld    DWORD PTR [ebp-0x20]
  4cb6d1:	6a 01                	push   0x1
  4cb6d3:	83 ec 08             	sub    esp,0x8
  4cb6d6:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4cb6da:	8d 55 e4             	lea    edx,[ebp-0x1c]
  4cb6dd:	d9 ee                	fldz
  4cb6df:	8b c8                	mov    ecx,eax
  4cb6e1:	d9 1c 24             	fstp   DWORD PTR [esp]
  4cb6e4:	52                   	push   edx
  4cb6e5:	6a 00                	push   0x0
  4cb6e7:	68 80 f6 fd 00       	push   0xfdf680
  4cb6ec:	e8 df 66 08 00       	call   0x551dd0
  4cb6f1:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4cb6f4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4cb6fb:	59                   	pop    ecx
  4cb6fc:	5f                   	pop    edi
  4cb6fd:	5e                   	pop    esi
  4cb6fe:	5b                   	pop    ebx
  4cb6ff:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4cb702:	33 cd                	xor    ecx,ebp
  4cb704:	e8 f8 58 3c 00       	call   0x891001
  4cb709:	8b e5                	mov    esp,ebp
  4cb70b:	5d                   	pop    ebp
  4cb70c:	c3                   	ret

### N07: CDeadState update
# VA 0x4cb710..0x4cb7c9 exclusive; raw 0x000cab10; SHA256 dbf7893b0159a2d424a9faafde4406fc2b437c498fde0b7548782e8b5f76b7cd

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cb710 <.text+0xca710>:
  4cb710:	55                   	push   ebp
  4cb711:	8b ec                	mov    ebp,esp
  4cb713:	83 e4 f8             	and    esp,0xfffffff8
  4cb716:	83 ec 18             	sub    esp,0x18
  4cb719:	56                   	push   esi
  4cb71a:	57                   	push   edi
  4cb71b:	8b f9                	mov    edi,ecx
  4cb71d:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  4cb720:	e8 8b e3 ff ff       	call   0x4c9ab0
  4cb725:	dd 05 20 58 c5 00    	fld    QWORD PTR ds:0xc55820
  4cb72b:	d9 c9                	fxch   st(1)
  4cb72d:	df f1                	fcomip st,st(1)
  4cb72f:	dd d8                	fstp   st(0)
  4cb731:	0f 86 8a 00 00 00    	jbe    0x4cb7c1
  4cb737:	d9 47 38             	fld    DWORD PTR [edi+0x38]
  4cb73a:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4cb741:	00 
  4cb742:	d8 45 08             	fadd   DWORD PTR [ebp+0x8]
  4cb745:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  4cb749:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  4cb74d:	d9 57 38             	fst    DWORD PTR [edi+0x38]
  4cb750:	d9 e8                	fld1
  4cb752:	d9 c9                	fxch   st(1)
  4cb754:	df f1                	fcomip st,st(1)
  4cb756:	dd d8                	fstp   st(0)
  4cb758:	76 05                	jbe    0x4cb75f
  4cb75a:	f3 0f 11 47 38       	movss  DWORD PTR [edi+0x38],xmm0
  4cb75f:	f3 0f 10 4f 38       	movss  xmm1,DWORD PTR [edi+0x38]
  4cb764:	0f 2f 0d 0c 7d c0 00 	comiss xmm1,DWORD PTR ds:0xc07d0c
  4cb76b:	f3 0f 11 4c 24 0c    	movss  DWORD PTR [esp+0xc],xmm1
  4cb771:	76 4e                	jbe    0x4cb7c1
  4cb773:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  4cb777:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  4cb77a:	dc 25 b0 56 c5 00    	fsub   QWORD PTR ds:0xc556b0
  4cb780:	83 ec 10             	sub    esp,0x10
  4cb783:	8b c4                	mov    eax,esp
  4cb785:	f3 0f 11 44 24 20    	movss  DWORD PTR [esp+0x20],xmm0
  4cb78b:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4cb78f:	dc c0                	fadd   st(0),st
  4cb791:	d9 e8                	fld1
  4cb793:	89 08                	mov    DWORD PTR [eax],ecx
  4cb795:	f3 0f 11 44 24 24    	movss  DWORD PTR [esp+0x24],xmm0
  4cb79b:	de e1                	fsubrp st(1),st
  4cb79d:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  4cb7a1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4cb7a4:	f3 0f 11 44 24 28    	movss  DWORD PTR [esp+0x28],xmm0
  4cb7aa:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4cb7ae:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  4cb7b2:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4cb7b6:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4cb7b9:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4cb7bc:	e8 9f e2 ff ff       	call   0x4c9a60
  4cb7c1:	5f                   	pop    edi
  4cb7c2:	5e                   	pop    esi
  4cb7c3:	8b e5                	mov    esp,ebp
  4cb7c5:	5d                   	pop    ebp
  4cb7c6:	c2 04 00             	ret    0x4

### N08: CDeadState exit
# VA 0x4cb7d0..0x4cb843 exclusive; raw 0x000cabd0; SHA256 5f22c66659b8b74a0d78bea72140ed399a816ebfa1741ef8fba670f7883e2ecd

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cb7d0 <.text+0xca7d0>:
  4cb7d0:	55                   	push   ebp
  4cb7d1:	8b ec                	mov    ebp,esp
  4cb7d3:	83 e4 f8             	and    esp,0xfffffff8
  4cb7d6:	83 ec 14             	sub    esp,0x14
  4cb7d9:	0f 57 c0             	xorps  xmm0,xmm0
  4cb7dc:	56                   	push   esi
  4cb7dd:	8b 71 04             	mov    esi,DWORD PTR [ecx+0x4]
  4cb7e0:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4cb7e6:	f3 0f 11 44 24 08    	movss  DWORD PTR [esp+0x8],xmm0
  4cb7ec:	f3 0f 11 44 24 0c    	movss  DWORD PTR [esp+0xc],xmm0
  4cb7f2:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4cb7f8:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4cb7fe:	85 c0                	test   eax,eax
  4cb800:	74 3c                	je     0x4cb83e
  4cb802:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4cb809:	74 33                	je     0x4cb83e
  4cb80b:	6a 00                	push   0x0
  4cb80d:	50                   	push   eax
  4cb80e:	e8 ad c4 2d 00       	call   0x7a7cc0
  4cb813:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4cb817:	8b 54 24 0c          	mov    edx,DWORD PTR [esp+0xc]
  4cb81b:	83 ec 10             	sub    esp,0x10
  4cb81e:	8b c4                	mov    eax,esp
  4cb820:	89 08                	mov    DWORD PTR [eax],ecx
  4cb822:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4cb826:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4cb829:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  4cb82d:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4cb830:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4cb833:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4cb839:	e8 b2 c3 2d 00       	call   0x7a7bf0
  4cb83e:	5e                   	pop    esi
  4cb83f:	8b e5                	mov    esp,ebp
  4cb841:	5d                   	pop    ebp
  4cb842:	c3                   	ret

### N09: CMonster frame accumulation and actor update call
# VA 0x4d1af0..0x4d1b89 exclusive; raw 0x000d0ef0; SHA256 b0e4cb1c5bb003584142ed55b6b5d00c76168fc6220c8d7a74d04fa3915d7593

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1af0 <.text+0xd0af0>:
  4d1af0:	55                   	push   ebp
  4d1af1:	8b ec                	mov    ebp,esp
  4d1af3:	51                   	push   ecx
  4d1af4:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  4d1af7:	56                   	push   esi
  4d1af8:	d9 c0                	fld    st(0)
  4d1afa:	8b f1                	mov    esi,ecx
  4d1afc:	d8 86 2c 04 00 00    	fadd   DWORD PTR [esi+0x42c]
  4d1b02:	57                   	push   edi
  4d1b03:	d9 5d fc             	fstp   DWORD PTR [ebp-0x4]
  4d1b06:	d9 45 fc             	fld    DWORD PTR [ebp-0x4]
  4d1b09:	d9 96 2c 04 00 00    	fst    DWORD PTR [esi+0x42c]
  4d1b0f:	dd 05 e8 5d c5 00    	fld    QWORD PTR ds:0xc55de8
  4d1b15:	d9 ca                	fxch   st(2)
  4d1b17:	df f2                	fcomip st,st(2)
  4d1b19:	dd d9                	fstp   st(1)
  4d1b1b:	76 25                	jbe    0x4d1b42
  4d1b1d:	f3 0f 10 05 e0 5d c5 	movss  xmm0,DWORD PTR ds:0xc55de0
  4d1b24:	00 
  4d1b25:	0f 2f 45 fc          	comiss xmm0,DWORD PTR [ebp-0x4]
  4d1b29:	76 2f                	jbe    0x4d1b5a
  4d1b2b:	8b be 5c 01 00 00    	mov    edi,DWORD PTR [esi+0x15c]
  4d1b31:	dd d8                	fstp   st(0)
  4d1b33:	e8 78 40 2d 00       	call   0x7a5bb0
  4d1b38:	5f                   	pop    edi
  4d1b39:	33 c0                	xor    eax,eax
  4d1b3b:	5e                   	pop    esi
  4d1b3c:	8b e5                	mov    esp,ebp
  4d1b3e:	5d                   	pop    ebp
  4d1b3f:	c2 04 00             	ret    0x4
  4d1b42:	f3 0f 10 45 08       	movss  xmm0,DWORD PTR [ebp+0x8]
  4d1b47:	0f 2f 05 28 5a c5 00 	comiss xmm0,DWORD PTR ds:0xc55a28
  4d1b4e:	76 0a                	jbe    0x4d1b5a
  4d1b50:	f3 0f 10 05 c8 5d c5 	movss  xmm0,DWORD PTR ds:0xc55dc8
  4d1b57:	00 
  4d1b58:	eb cb                	jmp    0x4d1b25
  4d1b5a:	0f 57 c0             	xorps  xmm0,xmm0
  4d1b5d:	d9 5d 08             	fstp   DWORD PTR [ebp+0x8]
  4d1b60:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  4d1b63:	51                   	push   ecx
  4d1b64:	d9 1c 24             	fstp   DWORD PTR [esp]
  4d1b67:	f3 0f 11 86 2c 04 00 	movss  DWORD PTR [esi+0x42c],xmm0
  4d1b6e:	00 
  4d1b6f:	e8 5c 6c ff ff       	call   0x4c87d0
  4d1b74:	8b f8                	mov    edi,eax
  4d1b76:	8b 06                	mov    eax,DWORD PTR [esi]
  4d1b78:	8b 50 64             	mov    edx,DWORD PTR [eax+0x64]
  4d1b7b:	8b ce                	mov    ecx,esi
  4d1b7d:	ff d2                	call   edx
  4d1b7f:	8b c7                	mov    eax,edi
  4d1b81:	5f                   	pop    edi
  4d1b82:	5e                   	pop    esi
  4d1b83:	8b e5                	mov    esp,ebp
  4d1b85:	5d                   	pop    ebp
  4d1b86:	c2 04 00             	ret    0x4

### N10: Current actor state update virtual call
# VA 0x4c88ce..0x4c88eb exclusive; raw 0x000c7cce; SHA256 0e202aeaf2c4d292c02b3e2348a3eae6cdd52779098330bbb14247bfafd75bc0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c88ce <.text+0xc78ce>:
  4c88ce:	8b 8e 58 01 00 00    	mov    ecx,DWORD PTR [esi+0x158]
  4c88d4:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  4c88d7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c88d9:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c88dc:	51                   	push   ecx
  4c88dd:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c88e0:	ff d2                	call   edx
  4c88e2:	33 c0                	xor    eax,eax
  4c88e4:	5e                   	pop    esi
  4c88e5:	8b e5                	mov    esp,ebp
  4c88e7:	5d                   	pop    ebp
  4c88e8:	c2 04 00             	ret    0x4

### N11: Actor motion ID setter and model animation call
# VA 0x4c8da0..0x4c8dd2 exclusive; raw 0x000c81a0; SHA256 eaf93b25e791a009ef64fd75bfafbf3ca10ced38ab103a6a68d204523b6d48a2

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8da0 <.text+0xc7da0>:
  4c8da0:	55                   	push   ebp
  4c8da1:	8b ec                	mov    ebp,esp
  4c8da3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c8da6:	57                   	push   edi
  4c8da7:	8b b9 5c 01 00 00    	mov    edi,DWORD PTR [ecx+0x15c]
  4c8dad:	89 81 8c 03 00 00    	mov    DWORD PTR [ecx+0x38c],eax
  4c8db3:	85 ff                	test   edi,edi
  4c8db5:	74 16                	je     0x4c8dcd
  4c8db7:	83 b9 70 03 00 00 00 	cmp    DWORD PTR [ecx+0x370],0x0
  4c8dbe:	74 0d                	je     0x4c8dcd
  4c8dc0:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  4c8dc3:	51                   	push   ecx
  4c8dc4:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c8dc7:	50                   	push   eax
  4c8dc8:	e8 a3 db 2d 00       	call   0x7a6970
  4c8dcd:	5f                   	pop    edi
  4c8dce:	5d                   	pop    ebp
  4c8dcf:	c2 08 00             	ret    0x8

### N12: Diagnostic flags are initialized to zero
# VA 0x49d6a0..0x49d6e7 exclusive; raw 0x0009caa0; SHA256 f820f7e1df1f092360fd830a8d904ccc9afe697d392893a1d5f6931a6e7d8a43

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049d6a0 <.text+0x9c6a0>:
  49d6a0:	55                   	push   ebp
  49d6a1:	8b ec                	mov    ebp,esp
  49d6a3:	6a ff                	push   0xffffffff
  49d6a5:	68 9b db 90 00       	push   0x90db9b
  49d6aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  49d6b0:	50                   	push   eax
  49d6b1:	83 ec 14             	sub    esp,0x14
  49d6b4:	56                   	push   esi
  49d6b5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49d6ba:	33 c5                	xor    eax,ebp
  49d6bc:	50                   	push   eax
  49d6bd:	8d 45 f4             	lea    eax,[ebp-0xc]
  49d6c0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49d6c6:	33 f6                	xor    esi,esi
  49d6c8:	c7 45 ec 04 b1 fa 00 	mov    DWORD PTR [ebp-0x14],0xfab104
  49d6cf:	89 35 04 b1 fa 00    	mov    DWORD PTR ds:0xfab104,esi
  49d6d5:	89 35 08 b1 fa 00    	mov    DWORD PTR ds:0xfab108,esi
  49d6db:	89 35 0c b1 fa 00    	mov    DWORD PTR ds:0xfab10c,esi
  49d6e1:	89 35 10 b1 fa 00    	mov    DWORD PTR ds:0xfab110,esi

### N13: Optional death diagnostic formats model identity
# VA 0x49d8e0..0x49d9b9 exclusive; raw 0x0009cce0; SHA256 273a8c32f9a66d88d1e1a57c0e9b5936fef0ba26c4346ba78320c1fc032a865e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049d8e0 <.text+0x9c8e0>:
  49d8e0:	55                   	push   ebp
  49d8e1:	8b ec                	mov    ebp,esp
  49d8e3:	6a ff                	push   0xffffffff
  49d8e5:	68 4c 0e 93 00       	push   0x930e4c
  49d8ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  49d8f0:	50                   	push   eax
  49d8f1:	51                   	push   ecx
  49d8f2:	56                   	push   esi
  49d8f3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49d8f8:	33 c5                	xor    eax,ebp
  49d8fa:	50                   	push   eax
  49d8fb:	8d 45 f4             	lea    eax,[ebp-0xc]
  49d8fe:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49d904:	f6 05 b0 75 fb 00 01 	test   BYTE PTR ds:0xfb75b0,0x1
  49d90b:	75 27                	jne    0x49d934
  49d90d:	83 0d b0 75 fb 00 01 	or     DWORD PTR ds:0xfb75b0,0x1
  49d914:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  49d91b:	e8 60 64 05 00       	call   0x4f3d80
  49d920:	68 e0 d1 bc 00       	push   0xbcd1e0
  49d925:	e8 f0 49 3f 00       	call   0x89231a
  49d92a:	83 c4 04             	add    esp,0x4
  49d92d:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  49d934:	8d 55 f0             	lea    edx,[ebp-0x10]
  49d937:	b9 70 74 fb 00       	mov    ecx,0xfb7470
  49d93c:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  49d93f:	e8 2c a1 05 00       	call   0x4f7a70
  49d944:	83 78 30 08          	cmp    DWORD PTR [eax+0x30],0x8
  49d948:	72 05                	jb     0x49d94f
  49d94a:	8b 70 1c             	mov    esi,DWORD PTR [eax+0x1c]
  49d94d:	eb 03                	jmp    0x49d952
  49d94f:	8d 70 1c             	lea    esi,[eax+0x1c]
  49d952:	f6 05 e0 11 fb 00 01 	test   BYTE PTR ds:0xfb11e0,0x1
  49d959:	75 27                	jne    0x49d982
  49d95b:	b8 01 00 00 00       	mov    eax,0x1
  49d960:	09 05 e0 11 fb 00    	or     DWORD PTR ds:0xfb11e0,eax
  49d966:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  49d969:	e8 a2 73 03 00       	call   0x4d4d10
  49d96e:	68 f0 ce bc 00       	push   0xbccef0
  49d973:	e8 a2 49 3f 00       	call   0x89231a
  49d978:	83 c4 04             	add    esp,0x4
  49d97b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  49d982:	8b c7                	mov    eax,edi
  49d984:	c1 e8 10             	shr    eax,0x10
  49d987:	fe c0                	inc    al
  49d989:	0f b6 c8             	movzx  ecx,al
  49d98c:	51                   	push   ecx
  49d98d:	0f b7 d7             	movzx  edx,di
  49d990:	52                   	push   edx
  49d991:	56                   	push   esi
  49d992:	68 6c 5d c0 00       	push   0xc05d6c
  49d997:	b9 e8 11 fb 00       	mov    ecx,0xfb11e8
  49d99c:	e8 cf 92 03 00       	call   0x4d6c70
  49d9a1:	83 c4 10             	add    esp,0x10
  49d9a4:	b8 01 00 00 00       	mov    eax,0x1
  49d9a9:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  49d9ac:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  49d9b3:	59                   	pop    ecx
  49d9b4:	5e                   	pop    esi
  49d9b5:	8b e5                	mov    esp,ebp
  49d9b7:	5d                   	pop    ebp
  49d9b8:	c3                   	ret

### N14: Varargs diagnostic wrapper
# VA 0x4d6c70..0x4d6c84 exclusive; raw 0x000d6070; SHA256 ade98a7ade4007718bfe73566af8f0f0938f89bdec54e64436ea1ad71ba4b4ab

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d6c70 <.text+0xd5c70>:
  4d6c70:	55                   	push   ebp
  4d6c71:	8b ec                	mov    ebp,esp
  4d6c73:	51                   	push   ecx
  4d6c74:	8d 45 0c             	lea    eax,[ebp+0xc]
  4d6c77:	50                   	push   eax
  4d6c78:	51                   	push   ecx
  4d6c79:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4d6c7c:	e8 1f ff ff ff       	call   0x4d6ba0
  4d6c81:	59                   	pop    ecx
  4d6c82:	5d                   	pop    ebp
  4d6c83:	c3                   	ret

### N15: Allocate text record; UTF16 formatting; queue and UI refresh
# VA 0x4d6ba0..0x4d6c67 exclusive; raw 0x000d5fa0; SHA256 88d5f1aa6c270e5d97354d751fd8a5b13ff5697ee0d81dc718d97de9c156e0c2

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d6ba0 <.text+0xd5ba0>:
  4d6ba0:	55                   	push   ebp
  4d6ba1:	8b ec                	mov    ebp,esp
  4d6ba3:	81 ec 0c 02 00 00    	sub    esp,0x20c
  4d6ba9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4d6bae:	33 c5                	xor    eax,ebp
  4d6bb0:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4d6bb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4d6bb6:	53                   	push   ebx
  4d6bb7:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4d6bba:	56                   	push   esi
  4d6bbb:	57                   	push   edi
  4d6bbc:	6a 24                	push   0x24
  4d6bbe:	89 85 f4 fd ff ff    	mov    DWORD PTR [ebp-0x20c],eax
  4d6bc4:	8b f9                	mov    edi,ecx
  4d6bc6:	e8 9d a6 3b 00       	call   0x891268
  4d6bcb:	83 c4 04             	add    esp,0x4
  4d6bce:	85 c0                	test   eax,eax
  4d6bd0:	74 18                	je     0x4d6bea
  4d6bd2:	33 c9                	xor    ecx,ecx
  4d6bd4:	c7 40 1c 07 00 00 00 	mov    DWORD PTR [eax+0x1c],0x7
  4d6bdb:	c7 40 18 00 00 00 00 	mov    DWORD PTR [eax+0x18],0x0
  4d6be2:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  4d6be6:	8b f0                	mov    esi,eax
  4d6be8:	eb 02                	jmp    0x4d6bec
  4d6bea:	33 f6                	xor    esi,esi
  4d6bec:	53                   	push   ebx
  4d6bed:	6a 00                	push   0x0
  4d6bef:	57                   	push   edi
  4d6bf0:	8d 95 f8 fd ff ff    	lea    edx,[ebp-0x208]
  4d6bf6:	68 00 01 00 00       	push   0x100
  4d6bfb:	52                   	push   edx
  4d6bfc:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  4d6c02:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  4d6c06:	e8 73 ba 3b 00       	call   0x89267e
  4d6c0b:	8d 85 f8 fd ff ff    	lea    eax,[ebp-0x208]
  4d6c11:	83 c4 14             	add    esp,0x14
  4d6c14:	8d 50 02             	lea    edx,[eax+0x2]
  4d6c17:	66 8b 08             	mov    cx,WORD PTR [eax]
  4d6c1a:	83 c0 02             	add    eax,0x2
  4d6c1d:	66 85 c9             	test   cx,cx
  4d6c20:	75 f5                	jne    0x4d6c17
  4d6c22:	2b c2                	sub    eax,edx
  4d6c24:	d1 f8                	sar    eax,1
  4d6c26:	50                   	push   eax
  4d6c27:	8d 85 f8 fd ff ff    	lea    eax,[ebp-0x208]
  4d6c2d:	50                   	push   eax
  4d6c2e:	8d 4e 08             	lea    ecx,[esi+0x8]
  4d6c31:	e8 2a b5 f2 ff       	call   0x402160
  4d6c36:	8b bd f4 fd ff ff    	mov    edi,DWORD PTR [ebp-0x20c]
  4d6c3c:	57                   	push   edi
  4d6c3d:	8b ce                	mov    ecx,esi
  4d6c3f:	e8 bc 0e 00 00       	call   0x4d7b00
  4d6c44:	83 bf 20 01 00 00 00 	cmp    DWORD PTR [edi+0x120],0x0
  4d6c4b:	75 07                	jne    0x4d6c54
  4d6c4d:	8b cf                	mov    ecx,edi
  4d6c4f:	e8 3c 00 00 00       	call   0x4d6c90
  4d6c54:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4d6c57:	5f                   	pop    edi
  4d6c58:	5e                   	pop    esi
  4d6c59:	33 cd                	xor    ecx,ebp
  4d6c5b:	5b                   	pop    ebx
  4d6c5c:	e8 a0 a3 3b 00       	call   0x891001
  4d6c61:	8b e5                	mov    esp,ebp
  4d6c63:	5d                   	pop    ebp
  4d6c64:	c2 08 00             	ret    0x8

### N16: Diagnostic record type 1 selects bucket 5
# VA 0x4d7b2b..0x4d7b7f exclusive; raw 0x000d6f2b; SHA256 03b7d0323f1df861bb09a3ce7110551fc8492b7b7fb5697e20c9f5fafd5d90e3

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d7b2b <.text+0xd6b2b>:
  4d7b2b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4d7b2e:	8b f1                	mov    esi,ecx
  4d7b30:	8a 4e 04             	mov    cl,BYTE PTR [esi+0x4]
  4d7b33:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  4d7b36:	0f be c1             	movsx  eax,cl
  4d7b39:	40                   	inc    eax
  4d7b3a:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  4d7b3d:	bf 01 00 00 00       	mov    edi,0x1
  4d7b42:	83 f8 0d             	cmp    eax,0xd
  4d7b45:	77 33                	ja     0x4d7b7a
  4d7b47:	ff 24 85 38 7c 4d 00 	jmp    DWORD PTR [eax*4+0x4d7c38]
  4d7b4e:	bf 05 00 00 00       	mov    edi,0x5
  4d7b53:	eb 25                	jmp    0x4d7b7a
  4d7b55:	33 ff                	xor    edi,edi
  4d7b57:	eb 21                	jmp    0x4d7b7a
  4d7b59:	bf 02 00 00 00       	mov    edi,0x2
  4d7b5e:	eb 1a                	jmp    0x4d7b7a
  4d7b60:	bf 04 00 00 00       	mov    edi,0x4
  4d7b65:	eb 13                	jmp    0x4d7b7a
  4d7b67:	bf 03 00 00 00       	mov    edi,0x3
  4d7b6c:	eb 0c                	jmp    0x4d7b7a
  4d7b6e:	bf 06 00 00 00       	mov    edi,0x6
  4d7b73:	eb 05                	jmp    0x4d7b7a
  4d7b75:	bf 07 00 00 00       	mov    edi,0x7
  4d7b7a:	80 f9 01             	cmp    cl,0x1
  4d7b7d:	74 5a                	je     0x4d7bd9

### N17: Queue record/index and call maintenance helper when count exceeds 50
# VA 0x4d7bd9..0x4d7c35 exclusive; raw 0x000d6fd9; SHA256 01eeaec8192357bdac7bd40ebb590e2761db9c2fa3a42d0af3f33c68a9497ece

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d7bd9 <.text+0xd6bd9>:
  4d7bd9:	8b 55 cc             	mov    edx,DWORD PTR [ebp-0x34]
  4d7bdc:	8d 0c 7f             	lea    ecx,[edi+edi*2]
  4d7bdf:	8d 1c ca             	lea    ebx,[edx+ecx*8]
  4d7be2:	8d 45 c8             	lea    eax,[ebp-0x38]
  4d7be5:	50                   	push   eax
  4d7be6:	8d 73 2c             	lea    esi,[ebx+0x2c]
  4d7be9:	e8 72 c6 32 00       	call   0x804260
  4d7bee:	8b 4d c8             	mov    ecx,DWORD PTR [ebp-0x38]
  4d7bf1:	8b 75 cc             	mov    esi,DWORD PTR [ebp-0x34]
  4d7bf4:	8d 55 c0             	lea    edx,[ebp-0x40]
  4d7bf7:	52                   	push   edx
  4d7bf8:	83 c6 14             	add    esi,0x14
  4d7bfb:	89 7d c0             	mov    DWORD PTR [ebp-0x40],edi
  4d7bfe:	89 4d c4             	mov    DWORD PTR [ebp-0x3c],ecx
  4d7c01:	e8 7a f2 2d 00       	call   0x7b6e80
  4d7c06:	83 7b 3c 32          	cmp    DWORD PTR [ebx+0x3c],0x32
  4d7c0a:	76 0b                	jbe    0x4d7c17
  4d7c0c:	8b 45 cc             	mov    eax,DWORD PTR [ebp-0x34]
  4d7c0f:	50                   	push   eax
  4d7c10:	8b c7                	mov    eax,edi
  4d7c12:	e8 59 00 00 00       	call   0x4d7c70
  4d7c17:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4d7c1a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4d7c21:	59                   	pop    ecx
  4d7c22:	5f                   	pop    edi
  4d7c23:	5e                   	pop    esi
  4d7c24:	5b                   	pop    ebx
  4d7c25:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4d7c28:	33 cd                	xor    ecx,ebp
  4d7c2a:	e8 d2 93 3b 00       	call   0x891001
  4d7c2f:	8b e5                	mov    esp,ebp
  4d7c31:	5d                   	pop    ebp
  4d7c32:	c2 04 00             	ret    0x4

### N18: FXUI event 0xF4366 contains no actor/group fields
# VA 0x4d6c90..0x4d6cd5 exclusive; raw 0x000d6090; SHA256 780913b5ef9393e9b210ad15eb1227525d5996be30a48e9e0389645ac52616f9

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d6c90 <.text+0xd5c90>:
  4d6c90:	56                   	push   esi
  4d6c91:	e8 0a e3 ff ff       	call   0x4d4fa0
  4d6c96:	6a 14                	push   0x14
  4d6c98:	e8 cb a5 3b 00       	call   0x891268
  4d6c9d:	83 c4 04             	add    esp,0x4
  4d6ca0:	85 c0                	test   eax,eax
  4d6ca2:	74 26                	je     0x4d6cca
  4d6ca4:	83 c9 ff             	or     ecx,0xffffffff
  4d6ca7:	8b f0                	mov    esi,eax
  4d6ca9:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  4d6caf:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  4d6cb2:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4d6cb5:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  4d6cbc:	c7 40 10 66 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4366
  4d6cc3:	e8 d8 05 f3 ff       	call   0x4072a0
  4d6cc8:	5e                   	pop    esi
  4d6cc9:	c3                   	ret
  4d6cca:	33 c0                	xor    eax,eax
  4d6ccc:	8b f0                	mov    esi,eax
  4d6cce:	e8 cd 05 f3 ff       	call   0x4072a0
  4d6cd3:	5e                   	pop    esi
  4d6cd4:	c3                   	ret

### N19: Actor removal: controller slot reads then destructor and tree erase
# VA 0x4dfbc0..0x4dfc2c exclusive; raw 0x000defc0; SHA256 21ae8dd896a0efbf2fc1719b9b2af83daf1fc550fdb8d3c10097a2a4c642baf8

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4

### N20: Controller v+1C is a pure 0..2 slot getter
# VA 0x545290..0x5452ac exclusive; raw 0x00144690; SHA256 3655bd98c5647734210172057589ff991795bf2a451d8707908727dd660b9f4b

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545290 <.text+0x144290>:
  545290:	55                   	push   ebp
  545291:	8b ec                	mov    ebp,esp
  545293:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  545296:	83 f8 02             	cmp    eax,0x2
  545299:	77 0b                	ja     0x5452a6
  54529b:	8d 44 40 03          	lea    eax,[eax+eax*2+0x3]
  54529f:	8b 04 81             	mov    eax,DWORD PTR [ecx+eax*4]
  5452a2:	5d                   	pop    ebp
  5452a3:	c2 04 00             	ret    0x4
  5452a6:	33 c0                	xor    eax,eax
  5452a8:	5d                   	pop    ebp
  5452a9:	c2 04 00             	ret    0x4

### N21: Single/Tutorial v+14 clears control slots/vector
# VA 0x545210..0x54525b exclusive; raw 0x00144610; SHA256 e67566d1fbaaeed7c9f2a92d91d2887b09c9854fce3713f8341dfba04fc5f72d

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545210 <.text+0x144210>:
  545210:	33 c0                	xor    eax,eax
  545212:	89 41 0c             	mov    DWORD PTR [ecx+0xc],eax
  545215:	89 41 18             	mov    DWORD PTR [ecx+0x18],eax
  545218:	89 41 10             	mov    DWORD PTR [ecx+0x10],eax
  54521b:	b2 01                	mov    dl,0x1
  54521d:	88 51 14             	mov    BYTE PTR [ecx+0x14],dl
  545220:	89 41 1c             	mov    DWORD PTR [ecx+0x1c],eax
  545223:	88 51 20             	mov    BYTE PTR [ecx+0x20],dl
  545226:	89 41 24             	mov    DWORD PTR [ecx+0x24],eax
  545229:	89 41 28             	mov    DWORD PTR [ecx+0x28],eax
  54522c:	88 51 2c             	mov    BYTE PTR [ecx+0x2c],dl
  54522f:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  545232:	56                   	push   esi
  545233:	8b 71 34             	mov    esi,DWORD PTR [ecx+0x34]
  545236:	3b d6                	cmp    edx,esi
  545238:	74 1f                	je     0x545259
  54523a:	8b c6                	mov    eax,esi
  54523c:	3b f6                	cmp    esi,esi
  54523e:	74 16                	je     0x545256
  545240:	57                   	push   edi
  545241:	8b 38                	mov    edi,DWORD PTR [eax]
  545243:	89 3a                	mov    DWORD PTR [edx],edi
  545245:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  545248:	89 7a 04             	mov    DWORD PTR [edx+0x4],edi
  54524b:	83 c0 08             	add    eax,0x8
  54524e:	83 c2 08             	add    edx,0x8
  545251:	3b c6                	cmp    eax,esi
  545253:	75 ec                	jne    0x545241
  545255:	5f                   	pop    edi
  545256:	89 51 34             	mov    DWORD PTR [ecx+0x34],edx
  545259:	5e                   	pop    esi
  54525a:	c3                   	ret

### N22: Formation v+14 clears control slots and SubAI globals
# VA 0x547750..0x54780a exclusive; raw 0x00146b50; SHA256 d7092631f921d0c23b6fd84b7aedd6a2c97797926c3bbdc350508086357c8cb1

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00547750 <.text+0x146750>:
  547750:	55                   	push   ebp
  547751:	8b ec                	mov    ebp,esp
  547753:	6a ff                	push   0xffffffff
  547755:	68 7e 83 90 00       	push   0x90837e
  54775a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  547760:	50                   	push   eax
  547761:	53                   	push   ebx
  547762:	56                   	push   esi
  547763:	57                   	push   edi
  547764:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  547769:	33 c5                	xor    eax,ebp
  54776b:	50                   	push   eax
  54776c:	8d 45 f4             	lea    eax,[ebp-0xc]
  54776f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  547775:	33 ff                	xor    edi,edi
  547777:	89 79 0c             	mov    DWORD PTR [ecx+0xc],edi
  54777a:	89 79 18             	mov    DWORD PTR [ecx+0x18],edi
  54777d:	89 79 10             	mov    DWORD PTR [ecx+0x10],edi
  547780:	bb 01 00 00 00       	mov    ebx,0x1
  547785:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  547788:	89 79 1c             	mov    DWORD PTR [ecx+0x1c],edi
  54778b:	88 59 20             	mov    BYTE PTR [ecx+0x20],bl
  54778e:	89 79 24             	mov    DWORD PTR [ecx+0x24],edi
  547791:	89 79 28             	mov    DWORD PTR [ecx+0x28],edi
  547794:	88 59 2c             	mov    BYTE PTR [ecx+0x2c],bl
  547797:	8b 71 34             	mov    esi,DWORD PTR [ecx+0x34]
  54779a:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  54779d:	3b d6                	cmp    edx,esi
  54779f:	74 22                	je     0x5477c3
  5477a1:	8b c6                	mov    eax,esi
  5477a3:	3b f6                	cmp    esi,esi
  5477a5:	74 19                	je     0x5477c0
  5477a7:	8b 18                	mov    ebx,DWORD PTR [eax]
  5477a9:	89 1a                	mov    DWORD PTR [edx],ebx
  5477ab:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  5477ae:	89 5a 04             	mov    DWORD PTR [edx+0x4],ebx
  5477b1:	83 c0 08             	add    eax,0x8
  5477b4:	83 c2 08             	add    edx,0x8
  5477b7:	3b c6                	cmp    eax,esi
  5477b9:	75 ec                	jne    0x5477a7
  5477bb:	bb 01 00 00 00       	mov    ebx,0x1
  5477c0:	89 51 34             	mov    DWORD PTR [ecx+0x34],edx
  5477c3:	84 1d 20 7a fb 00    	test   BYTE PTR ds:0xfb7a20,bl
  5477c9:	75 1b                	jne    0x5477e6
  5477cb:	09 1d 20 7a fb 00    	or     DWORD PTR ds:0xfb7a20,ebx
  5477d1:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5477d4:	e8 c7 15 00 00       	call   0x548da0
  5477d9:	68 70 d3 bc 00       	push   0xbcd370
  5477de:	e8 37 ab 34 00       	call   0x89231a
  5477e3:	83 c4 04             	add    esp,0x4
  5477e6:	89 3d d0 7a fb 00    	mov    DWORD PTR ds:0xfb7ad0,edi
  5477ec:	89 3d e0 7a fb 00    	mov    DWORD PTR ds:0xfb7ae0,edi
  5477f2:	89 3d f0 7a fb 00    	mov    DWORD PTR ds:0xfb7af0,edi
  5477f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5477fb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547802:	59                   	pop    ecx
  547803:	5f                   	pop    edi
  547804:	5e                   	pop    esi
  547805:	5b                   	pop    ebx
  547806:	8b e5                	mov    esp,ebp
  547808:	5d                   	pop    ebp
  547809:	c3                   	ret

### N23: Tutorial controller initializes 32 flags and mode 4
# VA 0x548b90..0x548c73 exclusive; raw 0x00147f90; SHA256 56829ff4c89883b2c8182059d8d3d2411902bfc9f31d2878cba8b3bcca6c6685

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548b90 <.text+0x147b90>:
  548b90:	51                   	push   ecx
  548b91:	56                   	push   esi
  548b92:	e8 a9 c0 ff ff       	call   0x544c40
  548b97:	33 c0                	xor    eax,eax
  548b99:	89 86 34 01 00 00    	mov    DWORD PTR [esi+0x134],eax
  548b9f:	c7 06 1c fb c0 00    	mov    DWORD PTR [esi],0xc0fb1c
  548ba5:	89 86 b4 00 00 00    	mov    DWORD PTR [esi+0xb4],eax
  548bab:	89 86 b8 00 00 00    	mov    DWORD PTR [esi+0xb8],eax
  548bb1:	89 86 bc 00 00 00    	mov    DWORD PTR [esi+0xbc],eax
  548bb7:	89 86 c0 00 00 00    	mov    DWORD PTR [esi+0xc0],eax
  548bbd:	89 86 c4 00 00 00    	mov    DWORD PTR [esi+0xc4],eax
  548bc3:	89 86 c8 00 00 00    	mov    DWORD PTR [esi+0xc8],eax
  548bc9:	89 86 cc 00 00 00    	mov    DWORD PTR [esi+0xcc],eax
  548bcf:	89 86 d0 00 00 00    	mov    DWORD PTR [esi+0xd0],eax
  548bd5:	89 86 d4 00 00 00    	mov    DWORD PTR [esi+0xd4],eax
  548bdb:	89 86 d8 00 00 00    	mov    DWORD PTR [esi+0xd8],eax
  548be1:	89 86 dc 00 00 00    	mov    DWORD PTR [esi+0xdc],eax
  548be7:	89 86 e0 00 00 00    	mov    DWORD PTR [esi+0xe0],eax
  548bed:	89 86 e4 00 00 00    	mov    DWORD PTR [esi+0xe4],eax
  548bf3:	89 86 e8 00 00 00    	mov    DWORD PTR [esi+0xe8],eax
  548bf9:	89 86 ec 00 00 00    	mov    DWORD PTR [esi+0xec],eax
  548bff:	89 86 f0 00 00 00    	mov    DWORD PTR [esi+0xf0],eax
  548c05:	89 86 f4 00 00 00    	mov    DWORD PTR [esi+0xf4],eax
  548c0b:	89 86 f8 00 00 00    	mov    DWORD PTR [esi+0xf8],eax
  548c11:	89 86 fc 00 00 00    	mov    DWORD PTR [esi+0xfc],eax
  548c17:	89 86 00 01 00 00    	mov    DWORD PTR [esi+0x100],eax
  548c1d:	89 86 04 01 00 00    	mov    DWORD PTR [esi+0x104],eax
  548c23:	89 86 08 01 00 00    	mov    DWORD PTR [esi+0x108],eax
  548c29:	89 86 0c 01 00 00    	mov    DWORD PTR [esi+0x10c],eax
  548c2f:	89 86 10 01 00 00    	mov    DWORD PTR [esi+0x110],eax
  548c35:	89 86 14 01 00 00    	mov    DWORD PTR [esi+0x114],eax
  548c3b:	89 86 18 01 00 00    	mov    DWORD PTR [esi+0x118],eax
  548c41:	89 86 1c 01 00 00    	mov    DWORD PTR [esi+0x11c],eax
  548c47:	89 86 20 01 00 00    	mov    DWORD PTR [esi+0x120],eax
  548c4d:	89 86 24 01 00 00    	mov    DWORD PTR [esi+0x124],eax
  548c53:	89 86 28 01 00 00    	mov    DWORD PTR [esi+0x128],eax
  548c59:	89 86 2c 01 00 00    	mov    DWORD PTR [esi+0x12c],eax
  548c5f:	89 86 30 01 00 00    	mov    DWORD PTR [esi+0x130],eax
  548c65:	c7 05 ac a7 fb 00 04 	mov    DWORD PTR ds:0xfba7ac,0x4
  548c6c:	00 00 00 
  548c6f:	8b c6                	mov    eax,esi
  548c71:	59                   	pop    ecx
  548c72:	c3                   	ret

### N24: Mission path allocates 0xC0 SingleController and installs it
# VA 0x4bc847..0x4bc880 exclusive; raw 0x000bbc47; SHA256 7daa5da30270bd8c92237230d879d5f4d8389e8f176d5817dd006896320c35d8

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bc847 <.text+0xbb847>:
  4bc847:	68 c0 00 00 00       	push   0xc0
  4bc84c:	e8 17 4a 3d 00       	call   0x891268
  4bc851:	83 c4 04             	add    esp,0x4
  4bc854:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4bc858:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  4bc85f:	00 
  4bc860:	85 c0                	test   eax,eax
  4bc862:	74 08                	je     0x4bc86c
  4bc864:	50                   	push   eax
  4bc865:	e8 d6 bc 08 00       	call   0x548540
  4bc86a:	eb 02                	jmp    0x4bc86e
  4bc86c:	33 c0                	xor    eax,eax
  4bc86e:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4bc872:	8b 10                	mov    edx,DWORD PTR [eax]
  4bc874:	a3 a4 a7 fb 00       	mov    ds:0xfba7a4,eax
  4bc879:	8b c8                	mov    ecx,eax
  4bc87b:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  4bc87e:	ff d0                	call   eax

### N25: SingleController +B4/+B8 are heap objects; mode 2
# VA 0x548540..0x5485f5 exclusive; raw 0x00147940; SHA256 2c4ca5aff26a5011de9ee825341792cccd0d34d4b5bdc9c336286549a48464be

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548540 <.text+0x147540>:
  548540:	55                   	push   ebp
  548541:	8b ec                	mov    ebp,esp
  548543:	6a ff                	push   0xffffffff
  548545:	68 8e 3a 93 00       	push   0x933a8e
  54854a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  548550:	50                   	push   eax
  548551:	51                   	push   ecx
  548552:	56                   	push   esi
  548553:	57                   	push   edi
  548554:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  548559:	33 c5                	xor    eax,ebp
  54855b:	50                   	push   eax
  54855c:	8d 45 f4             	lea    eax,[ebp-0xc]
  54855f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  548565:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  548568:	56                   	push   esi
  548569:	e8 d2 c6 ff ff       	call   0x544c40
  54856e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  548575:	6a 18                	push   0x18
  548577:	c7 06 c4 fa c0 00    	mov    DWORD PTR [esi],0xc0fac4
  54857d:	e8 e6 8c 34 00       	call   0x891268
  548582:	83 c4 04             	add    esp,0x4
  548585:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  548588:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  54858c:	85 c0                	test   eax,eax
  54858e:	74 09                	je     0x548599
  548590:	8b f8                	mov    edi,eax
  548592:	e8 19 40 25 00       	call   0x79c5b0
  548597:	eb 02                	jmp    0x54859b
  548599:	33 c0                	xor    eax,eax
  54859b:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  54859f:	6a 40                	push   0x40
  5485a1:	89 86 b4 00 00 00    	mov    DWORD PTR [esi+0xb4],eax
  5485a7:	e8 bc 8c 34 00       	call   0x891268
  5485ac:	83 c4 04             	add    esp,0x4
  5485af:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  5485b2:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  5485b6:	85 c0                	test   eax,eax
  5485b8:	74 0a                	je     0x5485c4
  5485ba:	6a 00                	push   0x0
  5485bc:	50                   	push   eax
  5485bd:	e8 ee 44 25 00       	call   0x79cab0
  5485c2:	eb 02                	jmp    0x5485c6
  5485c4:	33 c0                	xor    eax,eax
  5485c6:	89 86 b8 00 00 00    	mov    DWORD PTR [esi+0xb8],eax
  5485cc:	c7 86 bc 00 00 00 00 	mov    DWORD PTR [esi+0xbc],0x0
  5485d3:	00 00 00 
  5485d6:	c7 05 ac a7 fb 00 02 	mov    DWORD PTR ds:0xfba7ac,0x2
  5485dd:	00 00 00 
  5485e0:	8b c6                	mov    eax,esi
  5485e2:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5485e5:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5485ec:	59                   	pop    ecx
  5485ed:	5f                   	pop    edi
  5485ee:	5e                   	pop    esi
  5485ef:	8b e5                	mov    esp,ebp
  5485f1:	5d                   	pop    ebp
  5485f2:	c2 04 00             	ret    0x4

### N26: Checkpoint dispatcher reads category; category 3 special case
# VA 0x54409c..0x5440af exclusive; raw 0x0014349c; SHA256 507eb898a7c44d484780fab4309758cedad086fb4cc1434e64fa5a743f004a25

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054409c <.text+0x14309c>:
  54409c:	8b f1                	mov    esi,ecx
  54409e:	0f b7 86 f4 00 00 00 	movzx  eax,WORD PTR [esi+0xf4]
  5440a5:	66 83 f8 03          	cmp    ax,0x3
  5440a9:	0f 85 11 03 00 00    	jne    0x5443c0

### N27: Category 4 writer requires mode 4 and writes controller flag
# VA 0x5443c0..0x544401 exclusive; raw 0x001437c0; SHA256 0b0e95efd7cf279f0f24e4c22a8bed11b5dd689414030dd37dd73908a701441a

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005443c0 <.text+0x1433c0>:
  5443c0:	bb 04 00 00 00       	mov    ebx,0x4
  5443c5:	66 3b c3             	cmp    ax,bx
  5443c8:	75 37                	jne    0x544401
  5443ca:	39 1d ac a7 fb 00    	cmp    DWORD PTR ds:0xfba7ac,ebx
  5443d0:	0f 85 3d 03 00 00    	jne    0x544713
  5443d6:	0f bf 86 f6 00 00 00 	movsx  eax,WORD PTR [esi+0xf6]
  5443dd:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  5443e3:	c7 84 81 b4 00 00 00 	mov    DWORD PTR [ecx+eax*4+0xb4],0x1
  5443ea:	01 00 00 00 
  5443ee:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5443f2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5443f9:	59                   	pop    ecx
  5443fa:	5f                   	pop    edi
  5443fb:	5e                   	pop    esi
  5443fc:	5b                   	pop    ebx
  5443fd:	8b e5                	mov    esp,ebp
  5443ff:	5d                   	pop    ebp
  544400:	c3                   	ret

### N28: Noncategory2 checkpoint continues to general exit path
# VA 0x544478..0x544482 exclusive; raw 0x00143878; SHA256 47c3bb200c5df8324ed588d51d50b9def49a413732daa0510a9b15ffa1e6fb2f

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00544478 <.text+0x143478>:
  544478:	66 83 f8 02          	cmp    ax,0x2
  54447c:	0f 85 a7 00 00 00    	jne    0x544529

### N29: General checkpoint mode-specific UI routing gate
# VA 0x544529..0x544540 exclusive; raw 0x00143929; SHA256 8c51099affb11ca5e6c5c1fe1422ecce7740bea11fb199f8607016f0fe354397

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00544529 <.text+0x143529>:
  544529:	e8 72 06 ec ff       	call   0x404ba0
  54452e:	8b 80 4c 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f4c]
  544534:	83 c0 e9             	add    eax,0xffffffe9
  544537:	83 f8 01             	cmp    eax,0x1
  54453a:	0f 87 cc 01 00 00    	ja     0x54470c

### N30: General checkpoint falls through to C2S 001C sender
# VA 0x54470c..0x544726 exclusive; raw 0x00143b0c; SHA256 80daab044ecbbb32e243749459c623a903a13e9a7423f7a23ec29dff208c9100

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0054470c <.text+0x14370c>:
  54470c:	8b c6                	mov    eax,esi
  54470e:	e8 0d f9 ff ff       	call   0x544020
  544713:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  544717:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  54471e:	59                   	pop    ecx
  54471f:	5f                   	pop    edi
  544720:	5e                   	pop    esi
  544721:	5b                   	pop    ebx
  544722:	8b e5                	mov    esp,ebp
  544724:	5d                   	pop    ebp
  544725:	c3                   	ret

### N31: C2S 001C: category/key intent, send enabled when FBA798 is zero
# VA 0x544020..0x544067 exclusive; raw 0x00143420; SHA256 a54a9b5055bf662d296e38c36cc67f59d6e6989961e6002c05f7b5350df50ad4

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00544020 <.text+0x143020>:
  544020:	55                   	push   ebp
  544021:	8b ec                	mov    ebp,esp
  544023:	83 ec 08             	sub    esp,0x8
  544026:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  54402d:	66 8b 90 f4 00 00 00 	mov    dx,WORD PTR [eax+0xf4]
  544034:	66 8b 80 f6 00 00 00 	mov    ax,WORD PTR [eax+0xf6]
  54403b:	b9 1c 00 00 00       	mov    ecx,0x1c
  544040:	66 89 4d f8          	mov    WORD PTR [ebp-0x8],cx
  544044:	66 89 55 fa          	mov    WORD PTR [ebp-0x6],dx
  544048:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  54404c:	75 15                	jne    0x544063
  54404e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  544054:	8b 11                	mov    edx,DWORD PTR [ecx]
  544056:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  544059:	6a 06                	push   0x6
  54405b:	8d 45 f8             	lea    eax,[ebp-0x8]
  54405e:	50                   	push   eax
  54405f:	6a 00                	push   0x0
  544061:	ff d2                	call   edx
  544063:	8b e5                	mov    esp,ebp
  544065:	5d                   	pop    ebp
  544066:	c3                   	ret

### N32: Checkpoint enabled/radius/input-or-auto transition test
# VA 0x544730..0x5447ef exclusive; raw 0x00143b30; SHA256 0f66fd6985d6d4a57f9a1f1dac947de658f4e90a78188cc253335289e8d44223

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00544730 <.text+0x143730>:
  544730:	55                   	push   ebp
  544731:	8b ec                	mov    ebp,esp
  544733:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  544736:	83 ec 08             	sub    esp,0x8
  544739:	80 b9 05 01 00 00 00 	cmp    BYTE PTR [ecx+0x105],0x0
  544740:	75 0e                	jne    0x544750
  544742:	c7 02 00 00 00 00    	mov    DWORD PTR [edx],0x0
  544748:	33 c0                	xor    eax,eax
  54474a:	8b e5                	mov    esp,ebp
  54474c:	5d                   	pop    ebp
  54474d:	c2 0c 00             	ret    0xc
  544750:	d9 00                	fld    DWORD PTR [eax]
  544752:	c7 02 01 00 00 00    	mov    DWORD PTR [edx],0x1
  544758:	d8 a1 a0 00 00 00    	fsub   DWORD PTR [ecx+0xa0]
  54475e:	d9 5d f8             	fstp   DWORD PTR [ebp-0x8]
  544761:	d9 40 04             	fld    DWORD PTR [eax+0x4]
  544764:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  544767:	d8 a1 a4 00 00 00    	fsub   DWORD PTR [ecx+0xa4]
  54476d:	d9 5d fc             	fstp   DWORD PTR [ebp-0x4]
  544770:	d9 45 f8             	fld    DWORD PTR [ebp-0x8]
  544773:	d9 45 fc             	fld    DWORD PTR [ebp-0x4]
  544776:	dc c8                	fmul   st(0),st
  544778:	d9 c1                	fld    st(1)
  54477a:	de ca                	fmulp  st(2),st
  54477c:	de c1                	faddp  st(1),st
  54477e:	d9 5d 08             	fstp   DWORD PTR [ebp+0x8]
  544781:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  544784:	d9 10                	fst    DWORD PTR [eax]
  544786:	d9 81 fc 00 00 00    	fld    DWORD PTR [ecx+0xfc]
  54478c:	dc c8                	fmul   st(0),st
  54478e:	df f1                	fcomip st,st(1)
  544790:	dd d8                	fstp   st(0)
  544792:	76 04                	jbe    0x544798
  544794:	b0 01                	mov    al,0x1
  544796:	eb 02                	jmp    0x54479a
  544798:	32 c0                	xor    al,al
  54479a:	83 b9 00 01 00 00 00 	cmp    DWORD PTR [ecx+0x100],0x0
  5447a1:	75 2b                	jne    0x5447ce
  5447a3:	83 7d 10 00          	cmp    DWORD PTR [ebp+0x10],0x0
  5447a7:	74 37                	je     0x5447e0
  5447a9:	84 c0                	test   al,al
  5447ab:	74 33                	je     0x5447e0
  5447ad:	80 b9 04 01 00 00 00 	cmp    BYTE PTR [ecx+0x104],0x0
  5447b4:	74 06                	je     0x5447bc
  5447b6:	c7 02 00 00 00 00    	mov    DWORD PTR [edx],0x0
  5447bc:	c6 81 04 01 00 00 01 	mov    BYTE PTR [ecx+0x104],0x1
  5447c3:	b8 01 00 00 00       	mov    eax,0x1
  5447c8:	8b e5                	mov    esp,ebp
  5447ca:	5d                   	pop    ebp
  5447cb:	c2 0c 00             	ret    0xc
  5447ce:	84 c0                	test   al,al
  5447d0:	75 db                	jne    0x5447ad
  5447d2:	38 81 04 01 00 00    	cmp    BYTE PTR [ecx+0x104],al
  5447d8:	75 06                	jne    0x5447e0
  5447da:	c7 02 00 00 00 00    	mov    DWORD PTR [edx],0x0
  5447e0:	c6 81 04 01 00 00 00 	mov    BYTE PTR [ecx+0x104],0x0
  5447e7:	33 c0                	xor    eax,eax
  5447e9:	8b e5                	mov    esp,ebp
  5447eb:	5d                   	pop    ebp
  5447ec:	c2 0c 00             	ret    0xc

### N33: GetControlStatus reads current controller +B4+4*key
# VA 0x4a9fb0..0x4a9fc7 exclusive; raw 0x000a93b0; SHA256 1ef8a39b88129ba48810dda32d2bd9e0ec095399e13a749bcd1131a9d31f1b03

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a9fb0 <.text+0xa8fb0>:
  4a9fb0:	55                   	push   ebp
  4a9fb1:	8b ec                	mov    ebp,esp
  4a9fb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a9fb6:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4a9fbc:	8b 84 81 b4 00 00 00 	mov    eax,DWORD PTR [ecx+eax*4+0xb4]
  4a9fc3:	5d                   	pop    ebp
  4a9fc4:	c2 04 00             	ret    0x4

### N34: SetControlStatus writes same controller array
# VA 0x4a9f90..0x4a9faa exclusive; raw 0x000a9390; SHA256 87c6dcc8d7a073507fd5beb2223af45dd67d16ec5823de6b3264669d98145130

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a9f90 <.text+0xa8f90>:
  4a9f90:	55                   	push   ebp
  4a9f91:	8b ec                	mov    ebp,esp
  4a9f93:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4a9f96:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4a9f99:	8b 15 a4 a7 fb 00    	mov    edx,DWORD PTR ds:0xfba7a4
  4a9f9f:	89 84 8a b4 00 00 00 	mov    DWORD PTR [edx+ecx*4+0xb4],eax
  4a9fa6:	5d                   	pop    ebp
  4a9fa7:	c2 08 00             	ret    0x8

### N35: GetControlStatus native target -> FE185C
# VA 0x4ab3b8..0x4ab3c2 exclusive; raw 0x000aa7b8; SHA256 7c750829aaeecea54e5ee70f54429d33f9b34eb417a4a405b2ef6058ef945919

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ab3b8 <.text+0xaa3b8>:
  4ab3b8:	c7 05 5c 18 fe 00 b0 	mov    DWORD PTR ds:0xfe185c,0x4a9fb0
  4ab3bf:	9f 4a 00 

### N36: Register GetControlStatus name and Lua closure
# VA 0x4ab3f0..0x4ab40e exclusive; raw 0x000aa7f0; SHA256 06f92a4197794183fcd9be11ee82c5c8ebbd4dd4b1cbd41a79a5a054ccaef8ea

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ab3f0 <.text+0xaa3f0>:
  4ab3f0:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab3f6:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab3f8:	68 dc ac d6 00       	push   0xd6acdc
  4ab3fd:	e8 0e a1 24 00       	call   0x6f5510
  4ab402:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab404:	83 c4 04             	add    esp,0x4
  4ab407:	6a 00                	push   0x0
  4ab409:	68 a0 c6 4a 00       	push   0x4ac6a0

### N37: GetControlStatus Lua closure delegates conversion and result push
# VA 0x4ac6a0..0x4ac6fd exclusive; raw 0x000abaa0; SHA256 f5286f9517c8d3f61bfa219c675133d38a45e4b3640dbe1f3bdde0c2019ce45b

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ac6a0 <.text+0xab6a0>:
  4ac6a0:	55                   	push   ebp
  4ac6a1:	8b ec                	mov    ebp,esp
  4ac6a3:	6a ff                	push   0xffffffff
  4ac6a5:	68 c8 83 93 00       	push   0x9383c8
  4ac6aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac6b0:	50                   	push   eax
  4ac6b1:	83 ec 0c             	sub    esp,0xc
  4ac6b4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac6b9:	33 c5                	xor    eax,ebp
  4ac6bb:	50                   	push   eax
  4ac6bc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac6bf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ac6c5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ac6c8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4ac6cb:	33 c0                	xor    eax,eax
  4ac6cd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4ac6d0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ac6d3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4ac6d6:	8b 0d 5c 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe185c
  4ac6dc:	51                   	push   ecx
  4ac6dd:	8d 55 e8             	lea    edx,[ebp-0x18]
  4ac6e0:	52                   	push   edx
  4ac6e1:	e8 aa 08 00 00       	call   0x4acf90
  4ac6e6:	83 c4 08             	add    esp,0x8
  4ac6e9:	b8 01 00 00 00       	mov    eax,0x1
  4ac6ee:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ac6f1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ac6f8:	59                   	pop    ecx
  4ac6f9:	8b e5                	mov    esp,ebp
  4ac6fb:	5d                   	pop    ebp
  4ac6fc:	c3                   	ret

### N38: Number-argument conversion; native result is pushed as Lua number
# VA 0x4acf90..0x4ad019 exclusive; raw 0x000ac390; SHA256 6e8aec76b980d9ca1d74821b76457717fabf17e284fd3e182430bbb18e263674

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004acf90 <.text+0xabf90>:
  4acf90:	55                   	push   ebp
  4acf91:	8b ec                	mov    ebp,esp
  4acf93:	83 ec 14             	sub    esp,0x14
  4acf96:	a1 04 18 fe 00       	mov    eax,ds:0xfe1804
  4acf9b:	53                   	push   ebx
  4acf9c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4acf9f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4acfa1:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4acfa4:	83 c8 ff             	or     eax,0xffffffff
  4acfa7:	e8 44 81 24 00       	call   0x6f50f0
  4acfac:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acfaf:	83 f9 03             	cmp    ecx,0x3
  4acfb2:	74 2a                	je     0x4acfde
  4acfb4:	83 f9 04             	cmp    ecx,0x4
  4acfb7:	75 5c                	jne    0x4ad015
  4acfb9:	56                   	push   esi
  4acfba:	8b 30                	mov    esi,DWORD PTR [eax]
  4acfbc:	57                   	push   edi
  4acfbd:	83 c6 10             	add    esi,0x10
  4acfc0:	8d 7d f4             	lea    edi,[ebp-0xc]
  4acfc3:	e8 98 a7 24 00       	call   0x6f7760
  4acfc8:	5f                   	pop    edi
  4acfc9:	5e                   	pop    esi
  4acfca:	85 c0                	test   eax,eax
  4acfcc:	74 47                	je     0x4ad015
  4acfce:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4acfd1:	c7 45 f4 03 00 00 00 	mov    DWORD PTR [ebp-0xc],0x3
  4acfd8:	dd 5d ec             	fstp   QWORD PTR [ebp-0x14]
  4acfdb:	8d 45 ec             	lea    eax,[ebp-0x14]
  4acfde:	dd 00                	fld    QWORD PTR [eax]
  4acfe0:	dd 5d f4             	fstp   QWORD PTR [ebp-0xc]
  4acfe3:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4acfe6:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4acfe9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4acfec:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4acfef:	50                   	push   eax
  4acff0:	ff 55 0c             	call   DWORD PTR [ebp+0xc]
  4acff3:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  4acff6:	8b 03                	mov    eax,DWORD PTR [ebx]
  4acff8:	db 45 0c             	fild   DWORD PTR [ebp+0xc]
  4acffb:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acffe:	c7 41 08 03 00 00 00 	mov    DWORD PTR [ecx+0x8],0x3
  4ad005:	dd 19                	fstp   QWORD PTR [ecx]
  4ad007:	83 40 08 10          	add    DWORD PTR [eax+0x8],0x10
  4ad00b:	b8 01 00 00 00       	mov    eax,0x1
  4ad010:	5b                   	pop    ebx
  4ad011:	8b e5                	mov    esp,ebp
  4ad013:	5d                   	pop    ebp
  4ad014:	c3                   	ret
  4ad015:	33 c0                	xor    eax,eax
  4ad017:	eb d3                	jmp    0x4acfec

### N39: Inherited IsScenarioEnded getter uses owner+4 map
# VA 0x4aa510..0x4aa524 exclusive; raw 0x000a9910; SHA256 56570b9ffbec6f763df4e278d34c59620e6726cb5fbbe2c42da7151cfa41e8db

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004aa510 <.text+0xa9510>:
  4aa510:	55                   	push   ebp
  4aa511:	8b ec                	mov    ebp,esp
  4aa513:	8d 41 04             	lea    eax,[ecx+0x4]
  4aa516:	8d 55 08             	lea    edx,[ebp+0x8]
  4aa519:	e8 62 83 01 00       	call   0x4c2880
  4aa51e:	8b 00                	mov    eax,DWORD PTR [eax]
  4aa520:	5d                   	pop    ebp
  4aa521:	c2 04 00             	ret    0x4

### N40: Tutorial field builds second receive table and registers 004C only there
# VA 0x4c4ac0..0x4c4b04 exclusive; raw 0x000c3ec0; SHA256 e1a0928c0da336ceabf02254b2e983b676a8c62e96d459a5b61624df9ea62935

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4ac0 <.text+0xc3ac0>:
  4c4ac0:	8b c6                	mov    eax,esi
  4c4ac2:	e8 89 92 fe ff       	call   0x4add50
  4c4ac7:	68 a8 5e 00 00       	push   0x5ea8
  4c4acc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4ad2:	6a 00                	push   0x0
  4c4ad4:	50                   	push   eax
  4c4ad5:	c7 06 e8 73 c0 00    	mov    DWORD PTR [esi],0xc073e8
  4c4adb:	c7 05 74 a6 d6 00 4f 	mov    DWORD PTR ds:0xd6a674,0x5455544f
  4c4ae2:	54 55 54 
  4c4ae5:	e8 76 9d 3d 00       	call   0x89e860
  4c4aea:	83 c4 0c             	add    esp,0xc
  4c4aed:	c7 86 0c 61 00 00 20 	mov    DWORD PTR [esi+0x610c],0x4c4f20
  4c4af4:	4f 4c 00 
  4c4af7:	c7 86 10 61 00 00 75 	mov    DWORD PTR [esi+0x6110],0xbf2375
  4c4afe:	23 bf 00 
  4c4b01:	8b c6                	mov    eax,esi
  4c4b03:	c3                   	ret

### N41: Inherited 004C writes scenarioKey flag in FC0F88 map
# VA 0x4c4f20..0x4c4fa2 exclusive; raw 0x000c4320; SHA256 931f7d521dee63a85e3ee39ba19b1ca63feebd738cb4c05f916e3a9eba220c20

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c4f20 <.text+0xc3f20>:
  4c4f20:	55                   	push   ebp
  4c4f21:	8b ec                	mov    ebp,esp
  4c4f23:	6a ff                	push   0xffffffff
  4c4f25:	68 9e 76 92 00       	push   0x92769e
  4c4f2a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4f30:	50                   	push   eax
  4c4f31:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4f36:	33 c5                	xor    eax,ebp
  4c4f38:	50                   	push   eax
  4c4f39:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4f3c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4f42:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4f49:	75 27                	jne    0x4c4f72
  4c4f4b:	83 0d 80 0f fc 00 01 	or     DWORD PTR ds:0xfc0f80,0x1
  4c4f52:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4f59:	e8 52 5f fb ff       	call   0x47aeb0
  4c4f5e:	68 70 db bc 00       	push   0xbcdb70
  4c4f63:	e8 b2 d3 3c 00       	call   0x89231a
  4c4f68:	83 c4 04             	add    esp,0x4
  4c4f6b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4f72:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c4f75:	0f b7 48 02          	movzx  ecx,WORD PTR [eax+0x2]
  4c4f79:	8d 55 08             	lea    edx,[ebp+0x8]
  4c4f7c:	b8 88 0f fc 00       	mov    eax,0xfc0f88
  4c4f81:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4c4f84:	e8 f7 d8 ff ff       	call   0x4c2880
  4c4f89:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  4c4f8f:	33 c0                	xor    eax,eax
  4c4f91:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c4f94:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4f9b:	59                   	pop    ecx
  4c4f9c:	8b e5                	mov    esp,ebp
  4c4f9e:	5d                   	pop    ebp
  4c4f9f:	c2 0c 00             	ret    0xc

### N42: IsScenarioEnded native target -> FE1880
# VA 0x4ab958..0x4ab962 exclusive; raw 0x000aad58; SHA256 e52051c3b78fe4d9ed463b0684038074fdff3de6827705bd39ca666baa2bd7a8

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ab958 <.text+0xaa958>:
  4ab958:	c7 05 80 18 fe 00 10 	mov    DWORD PTR ds:0xfe1880,0x4aa510
  4ab95f:	a5 4a 00 

### N43: IsScenarioEnded name and closure
# VA 0x4ab998..0x4ab9ae exclusive; raw 0x000aad98; SHA256 2c8657b944187b004cf1546170c50866e2e8ce84e5811d60e62d30777ff6d545

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004ab998 <.text+0xaa998>:
  4ab998:	68 80 ad d6 00       	push   0xd6ad80
  4ab99d:	e8 6e 9b 24 00       	call   0x6f5510
  4ab9a2:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab9a4:	83 c4 04             	add    esp,0x4
  4ab9a7:	6a 00                	push   0x0
  4ab9a9:	68 40 ca 4a 00       	push   0x4aca40

### N44: Actor +88/+8C model identity setter, not world EntityId
# VA 0x4c6fb0..0x4c6fd0 exclusive; raw 0x000c63b0; SHA256 74bf7e0c3d5ff41cf31cb0089009d79c4ec72191745060987bdd0b0efa1a1053

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c6fb0 <.text+0xc5fb0>:
  4c6fb0:	55                   	push   ebp
  4c6fb1:	8b ec                	mov    ebp,esp
  4c6fb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c6fb6:	89 81 88 00 00 00    	mov    DWORD PTR [ecx+0x88],eax
  4c6fbc:	89 81 8c 00 00 00    	mov    DWORD PTR [ecx+0x8c],eax
  4c6fc2:	5d                   	pop    ebp
  4c6fc3:	c2 04 00             	ret    0x4
  4c6fc6:	cc                   	int3
  4c6fc7:	cc                   	int3
  4c6fc8:	cc                   	int3
  4c6fc9:	cc                   	int3
  4c6fca:	cc                   	int3
  4c6fcb:	cc                   	int3
  4c6fcc:	cc                   	int3
  4c6fcd:	cc                   	int3
  4c6fce:	cc                   	int3
  4c6fcf:	cc                   	int3

### N45: CMonster detach forwards to actor render/effect cleanup
# VA 0x4d1f80..0x4d1f8a exclusive; raw 0x000d1380; SHA256 50559243bc3cd82af415e353b9660f287edc454d39738de10a9fd2bf59d358c9

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004d1f80 <.text+0xd0f80>:
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
  4d1f88:	cc                   	int3
  4d1f89:	cc                   	int3

### N46: Color/fade helper acts on model
# VA 0x4c9a60..0x4c9ab0 exclusive; raw 0x000c8e60; SHA256 1e5bd7a5d7f87fe5fc91e6de90ea86db73f66dceef200ab4765de713acbce35c

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c9a60 <.text+0xc8a60>:
  4c9a60:	55                   	push   ebp
  4c9a61:	8b ec                	mov    ebp,esp
  4c9a63:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4c9a69:	85 c0                	test   eax,eax
  4c9a6b:	74 38                	je     0x4c9aa5
  4c9a6d:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c9a74:	74 2f                	je     0x4c9aa5
  4c9a76:	6a 00                	push   0x0
  4c9a78:	50                   	push   eax
  4c9a79:	e8 42 e2 2d 00       	call   0x7a7cc0
  4c9a7e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c9a81:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  4c9a84:	83 ec 10             	sub    esp,0x10
  4c9a87:	8b c4                	mov    eax,esp
  4c9a89:	89 08                	mov    DWORD PTR [eax],ecx
  4c9a8b:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4c9a8e:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4c9a91:	8b 55 14             	mov    edx,DWORD PTR [ebp+0x14]
  4c9a94:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4c9a97:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4c9a9a:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4c9aa0:	e8 4b e1 2d 00       	call   0x7a7bf0
  4c9aa5:	5d                   	pop    ebp
  4c9aa6:	c2 10 00             	ret    0x10
  4c9aa9:	cc                   	int3
  4c9aaa:	cc                   	int3
  4c9aab:	cc                   	int3
  4c9aac:	cc                   	int3
  4c9aad:	cc                   	int3
  4c9aae:	cc                   	int3
  4c9aaf:	cc                   	int3

### N47: Known no-op virtual target is a direct return
# VA 0x5f5d10..0x5f5d11 exclusive; raw 0x001f5110; SHA256 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005f5d10 <.text+0x1f4d10>:
  5f5d10:	c3                   	ret

# RESEARCH GROUP: identity

## lb_initializer

02-Tartaros.bin:     file format pei-i386


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

## create_object_defaults

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0b40 <.text+0x9fb40>:
  4a0b40:	55                   	push   ebp
  4a0b41:	8b ec                	mov    ebp,esp
  4a0b43:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  4a0b46:	d9 45 10             	fld    DWORD PTR [ebp+0x10]
  4a0b49:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4a0b4c:	50                   	push   eax
  4a0b4d:	6a 00                	push   0x0
  4a0b4f:	6a 0c                	push   0xc
  4a0b51:	83 ec 08             	sub    esp,0x8
  4a0b54:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4a0b58:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  4a0b5b:	d9 1c 24             	fstp   DWORD PTR [esp]
  4a0b5e:	52                   	push   edx
  4a0b5f:	e8 0c 04 00 00       	call   0x4a0f70
  4a0b64:	5d                   	pop    ebp
  4a0b65:	c2 10 00             	ret    0x10

## set_actor_avatar

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0b80 <.text+0x9fb80>:
  4a0b80:	55                   	push   ebp
  4a0b81:	8b ec                	mov    ebp,esp
  4a0b83:	83 e4 f8             	and    esp,0xfffffff8
  4a0b86:	6a ff                	push   0xffffffff
  4a0b88:	68 fe 6e 93 00       	push   0x936efe
  4a0b8d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a0b93:	50                   	push   eax
  4a0b94:	83 ec 0c             	sub    esp,0xc
  4a0b97:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a0b9c:	33 c4                	xor    eax,esp
  4a0b9e:	50                   	push   eax
  4a0b9f:	8d 44 24 10          	lea    eax,[esp+0x10]
  4a0ba3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a0ba9:	b8 01 00 00 00       	mov    eax,0x1
  4a0bae:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4a0bb4:	75 28                	jne    0x4a0bde
  4a0bb6:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4a0bbc:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4a0bc3:	00 
  4a0bc4:	e8 c7 e0 03 00       	call   0x4dec90
  4a0bc9:	68 30 ce bc 00       	push   0xbcce30
  4a0bce:	e8 47 17 3f 00       	call   0x89231a
  4a0bd3:	83 c4 04             	add    esp,0x4
  4a0bd6:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4a0bdd:	ff 
  4a0bde:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a0be1:	8d 4c 24 04          	lea    ecx,[esp+0x4]
  4a0be5:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4a0be9:	51                   	push   ecx
  4a0bea:	8d 44 24 0c          	lea    eax,[esp+0xc]
  4a0bee:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4a0bf3:	e8 08 e3 38 00       	call   0x82ef00
  4a0bf8:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  4a0bfc:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4a0c02:	74 2f                	je     0x4a0c33
  4a0c04:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a0c07:	85 c0                	test   eax,eax
  4a0c09:	74 28                	je     0x4a0c33
  4a0c0b:	8b 88 5c 01 00 00    	mov    ecx,DWORD PTR [eax+0x15c]
  4a0c11:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4a0c14:	66 89 90 88 03 00 00 	mov    WORD PTR [eax+0x388],dx
  4a0c1b:	85 c9                	test   ecx,ecx
  4a0c1d:	74 14                	je     0x4a0c33
  4a0c1f:	83 b8 70 03 00 00 00 	cmp    DWORD PTR [eax+0x370],0x0
  4a0c26:	74 0b                	je     0x4a0c33
  4a0c28:	52                   	push   edx
  4a0c29:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  4a0c2c:	52                   	push   edx
  4a0c2d:	51                   	push   ecx
  4a0c2e:	e8 6d 62 30 00       	call   0x7a6ea0
  4a0c33:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4a0c37:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a0c3e:	59                   	pop    ecx
  4a0c3f:	8b e5                	mov    esp,ebp
  4a0c41:	5d                   	pop    ebp
  4a0c42:	c2 0c 00             	ret    0xc

## attach_actor_item

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0c50 <.text+0x9fc50>:
  4a0c50:	55                   	push   ebp
  4a0c51:	8b ec                	mov    ebp,esp
  4a0c53:	83 e4 f8             	and    esp,0xfffffff8
  4a0c56:	6a ff                	push   0xffffffff
  4a0c58:	68 fe 6e 93 00       	push   0x936efe
  4a0c5d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a0c63:	50                   	push   eax
  4a0c64:	83 ec 0c             	sub    esp,0xc
  4a0c67:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a0c6c:	33 c4                	xor    eax,esp
  4a0c6e:	50                   	push   eax
  4a0c6f:	8d 44 24 10          	lea    eax,[esp+0x10]
  4a0c73:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a0c79:	b8 01 00 00 00       	mov    eax,0x1
  4a0c7e:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4a0c84:	75 28                	jne    0x4a0cae
  4a0c86:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4a0c8c:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4a0c93:	00 
  4a0c94:	e8 f7 df 03 00       	call   0x4dec90
  4a0c99:	68 30 ce bc 00       	push   0xbcce30
  4a0c9e:	e8 77 16 3f 00       	call   0x89231a
  4a0ca3:	83 c4 04             	add    esp,0x4
  4a0ca6:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4a0cad:	ff 
  4a0cae:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a0cb1:	8d 4c 24 04          	lea    ecx,[esp+0x4]
  4a0cb5:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4a0cb9:	51                   	push   ecx
  4a0cba:	8d 44 24 0c          	lea    eax,[esp+0xc]
  4a0cbe:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4a0cc3:	e8 38 e2 38 00       	call   0x82ef00
  4a0cc8:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  4a0ccc:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4a0cd2:	74 29                	je     0x4a0cfd
  4a0cd4:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a0cd7:	85 c0                	test   eax,eax
  4a0cd9:	74 22                	je     0x4a0cfd
  4a0cdb:	8b 88 5c 01 00 00    	mov    ecx,DWORD PTR [eax+0x15c]
  4a0ce1:	85 c9                	test   ecx,ecx
  4a0ce3:	74 18                	je     0x4a0cfd
  4a0ce5:	83 b8 70 03 00 00 00 	cmp    DWORD PTR [eax+0x370],0x0
  4a0cec:	74 0f                	je     0x4a0cfd
  4a0cee:	0f b7 55 0c          	movzx  edx,WORD PTR [ebp+0xc]
  4a0cf2:	6a 00                	push   0x0
  4a0cf4:	6a 00                	push   0x0
  4a0cf6:	52                   	push   edx
  4a0cf7:	51                   	push   ecx
  4a0cf8:	e8 43 65 30 00       	call   0x7a7240
  4a0cfd:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4a0d01:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a0d08:	59                   	pop    ecx
  4a0d09:	8b e5                	mov    esp,ebp
  4a0d0b:	5d                   	pop    ebp
  4a0d0c:	c2 08 00             	ret    0x8

## detach_actor_item

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0d10 <.text+0x9fd10>:
  4a0d10:	55                   	push   ebp
  4a0d11:	8b ec                	mov    ebp,esp
  4a0d13:	83 e4 f8             	and    esp,0xfffffff8
  4a0d16:	6a ff                	push   0xffffffff
  4a0d18:	68 fe 6e 93 00       	push   0x936efe
  4a0d1d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a0d23:	50                   	push   eax
  4a0d24:	83 ec 0c             	sub    esp,0xc
  4a0d27:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a0d2c:	33 c4                	xor    eax,esp
  4a0d2e:	50                   	push   eax
  4a0d2f:	8d 44 24 10          	lea    eax,[esp+0x10]
  4a0d33:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a0d39:	b8 01 00 00 00       	mov    eax,0x1
  4a0d3e:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4a0d44:	75 28                	jne    0x4a0d6e
  4a0d46:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4a0d4c:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4a0d53:	00 
  4a0d54:	e8 37 df 03 00       	call   0x4dec90
  4a0d59:	68 30 ce bc 00       	push   0xbcce30
  4a0d5e:	e8 b7 15 3f 00       	call   0x89231a
  4a0d63:	83 c4 04             	add    esp,0x4
  4a0d66:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4a0d6d:	ff 
  4a0d6e:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a0d71:	8d 4c 24 04          	lea    ecx,[esp+0x4]
  4a0d75:	89 44 24 04          	mov    DWORD PTR [esp+0x4],eax
  4a0d79:	51                   	push   ecx
  4a0d7a:	8d 44 24 0c          	lea    eax,[esp+0xc]
  4a0d7e:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4a0d83:	e8 78 e1 38 00       	call   0x82ef00
  4a0d88:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  4a0d8c:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4a0d92:	74 24                	je     0x4a0db8
  4a0d94:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a0d97:	85 c0                	test   eax,eax
  4a0d99:	74 1d                	je     0x4a0db8
  4a0d9b:	8b 88 5c 01 00 00    	mov    ecx,DWORD PTR [eax+0x15c]
  4a0da1:	85 c9                	test   ecx,ecx
  4a0da3:	74 13                	je     0x4a0db8
  4a0da5:	83 b8 70 03 00 00 00 	cmp    DWORD PTR [eax+0x370],0x0
  4a0dac:	74 0a                	je     0x4a0db8
  4a0dae:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  4a0db1:	52                   	push   edx
  4a0db2:	51                   	push   ecx
  4a0db3:	e8 68 68 30 00       	call   0x7a7620
  4a0db8:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4a0dbc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a0dc3:	59                   	pop    ecx
  4a0dc4:	8b e5                	mov    esp,ebp
  4a0dc6:	5d                   	pop    ebp
  4a0dc7:	c2 08 00             	ret    0x8

## create_object_ex_native

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a0f70 <.text+0x9ff70>:
  4a0f70:	55                   	push   ebp
  4a0f71:	8b ec                	mov    ebp,esp
  4a0f73:	83 e4 f8             	and    esp,0xfffffff8
  4a0f76:	6a ff                	push   0xffffffff
  4a0f78:	68 6b 9f 93 00       	push   0x939f6b
  4a0f7d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a0f83:	50                   	push   eax
  4a0f84:	83 ec 18             	sub    esp,0x18
  4a0f87:	53                   	push   ebx
  4a0f88:	56                   	push   esi
  4a0f89:	57                   	push   edi
  4a0f8a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a0f8f:	33 c4                	xor    eax,esp
  4a0f91:	50                   	push   eax
  4a0f92:	8d 44 24 28          	lea    eax,[esp+0x28]
  4a0f96:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a0f9c:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4a0f9f:	33 f6                	xor    esi,esi
  4a0fa1:	33 db                	xor    ebx,ebx
  4a0fa3:	83 ff 0a             	cmp    edi,0xa
  4a0fa6:	7c 10                	jl     0x4a0fb8
  4a0fa8:	81 ff 10 27 00 00    	cmp    edi,0x2710
  4a0fae:	0f 9e c3             	setle  bl
  4a0fb1:	4b                   	dec    ebx
  4a0fb2:	83 e3 05             	and    ebx,0x5
  4a0fb5:	43                   	inc    ebx
  4a0fb6:	75 27                	jne    0x4a0fdf
  4a0fb8:	68 44 04 00 00       	push   0x444
  4a0fbd:	e8 a6 02 3f 00       	call   0x891268
  4a0fc2:	83 c4 04             	add    esp,0x4
  4a0fc5:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4a0fc9:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4a0fd0:	00 
  4a0fd1:	85 c0                	test   eax,eax
  4a0fd3:	74 6e                	je     0x4a1043
  4a0fd5:	6a 00                	push   0x0
  4a0fd7:	50                   	push   eax
  4a0fd8:	e8 13 c7 02 00       	call   0x4cd6f0
  4a0fdd:	eb 66                	jmp    0x4a1045
  4a0fdf:	83 fb 01             	cmp    ebx,0x1
  4a0fe2:	75 35                	jne    0x4a1019
  4a0fe4:	68 34 04 00 00       	push   0x434
  4a0fe9:	e8 7a 02 3f 00       	call   0x891268
  4a0fee:	83 c4 04             	add    esp,0x4
  4a0ff1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4a0ff5:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  4a0ff9:	85 c0                	test   eax,eax
  4a0ffb:	74 08                	je     0x4a1005
  4a0ffd:	50                   	push   eax
  4a0ffe:	e8 0d 07 03 00       	call   0x4d1710
  4a1003:	eb 02                	jmp    0x4a1007
  4a1005:	33 c0                	xor    eax,eax
  4a1007:	57                   	push   edi
  4a1008:	c7 44 24 34 ff ff ff 	mov    DWORD PTR [esp+0x34],0xffffffff
  4a100f:	ff 
  4a1010:	8b f0                	mov    esi,eax
  4a1012:	e8 b9 fd ff ff       	call   0x4a0dd0
  4a1017:	eb 36                	jmp    0x4a104f
  4a1019:	83 fb 06             	cmp    ebx,0x6
  4a101c:	75 31                	jne    0x4a104f
  4a101e:	68 2c 04 00 00       	push   0x42c
  4a1023:	e8 40 02 3f 00       	call   0x891268
  4a1028:	83 c4 04             	add    esp,0x4
  4a102b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4a102f:	c7 44 24 30 02 00 00 	mov    DWORD PTR [esp+0x30],0x2
  4a1036:	00 
  4a1037:	85 c0                	test   eax,eax
  4a1039:	74 08                	je     0x4a1043
  4a103b:	50                   	push   eax
  4a103c:	e8 df 10 03 00       	call   0x4d2120
  4a1041:	eb 02                	jmp    0x4a1045
  4a1043:	33 c0                	xor    eax,eax
  4a1045:	8b f0                	mov    esi,eax
  4a1047:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4a104e:	ff 
  4a104f:	66 a1 04 de f7 00    	mov    ax,ds:0xf7de04
  4a1055:	f3 0f 10 45 0c       	movss  xmm0,DWORD PTR [ebp+0xc]
  4a105a:	8b 16                	mov    edx,DWORD PTR [esi]
  4a105c:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4a105f:	66 89 46 04          	mov    WORD PTR [esi+0x4],ax
  4a1063:	6a 01                	push   0x1
  4a1065:	8d 44 24 18          	lea    eax,[esp+0x18]
  4a1069:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4a106f:	f3 0f 10 45 10       	movss  xmm0,DWORD PTR [ebp+0x10]
  4a1074:	50                   	push   eax
  4a1075:	8b ce                	mov    ecx,esi
  4a1077:	f3 0f 11 44 24 20    	movss  DWORD PTR [esp+0x20],xmm0
  4a107d:	ff d2                	call   edx
  4a107f:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  4a1082:	8b 06                	mov    eax,DWORD PTR [esi]
  4a1084:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4a1087:	51                   	push   ecx
  4a1088:	8b ce                	mov    ecx,esi
  4a108a:	ff d2                	call   edx
  4a108c:	8b 06                	mov    eax,DWORD PTR [esi]
  4a108e:	8b 40 3c             	mov    eax,DWORD PTR [eax+0x3c]
  4a1091:	0f b6 cb             	movzx  ecx,bl
  4a1094:	0f b7 d7             	movzx  edx,di
  4a1097:	c1 e1 18             	shl    ecx,0x18
  4a109a:	0b ca                	or     ecx,edx
  4a109c:	51                   	push   ecx
  4a109d:	8b ce                	mov    ecx,esi
  4a109f:	ff d0                	call   eax
  4a10a1:	83 ff 0a             	cmp    edi,0xa
  4a10a4:	bf 01 00 00 00       	mov    edi,0x1
  4a10a9:	7d 24                	jge    0x4a10cf
  4a10ab:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4a10b1:	8b cf                	mov    ecx,edi
  4a10b3:	66 89 8e 88 03 00 00 	mov    WORD PTR [esi+0x388],cx
  4a10ba:	85 c0                	test   eax,eax
  4a10bc:	74 11                	je     0x4a10cf
  4a10be:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4a10c5:	74 08                	je     0x4a10cf
  4a10c7:	57                   	push   edi
  4a10c8:	57                   	push   edi
  4a10c9:	50                   	push   eax
  4a10ca:	e8 d1 5d 30 00       	call   0x7a6ea0
  4a10cf:	8b 16                	mov    edx,DWORD PTR [esi]
  4a10d1:	8b 42 30             	mov    eax,DWORD PTR [edx+0x30]
  4a10d4:	8b ce                	mov    ecx,esi
  4a10d6:	ff d0                	call   eax
  4a10d8:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  4a10df:	75 28                	jne    0x4a1109
  4a10e1:	09 3d 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,edi
  4a10e7:	c7 44 24 30 03 00 00 	mov    DWORD PTR [esp+0x30],0x3
  4a10ee:	00 
  4a10ef:	e8 5c e7 0a 00       	call   0x54f850
  4a10f4:	68 80 d5 bc 00       	push   0xbcd580
  4a10f9:	e8 1c 12 3f 00       	call   0x89231a
  4a10fe:	83 c4 04             	add    esp,0x4
  4a1101:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4a1108:	ff 
  4a1109:	db 45 14             	fild   DWORD PTR [ebp+0x14]
  4a110c:	8b 16                	mov    edx,DWORD PTR [esi]
  4a110e:	8b 42 5c             	mov    eax,DWORD PTR [edx+0x5c]
  4a1111:	51                   	push   ecx
  4a1112:	d8 0d bc 90 fb 00    	fmul   DWORD PTR ds:0xfb90bc
  4a1118:	8b ce                	mov    ecx,esi
  4a111a:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  4a111e:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  4a1122:	d9 1c 24             	fstp   DWORD PTR [esp]
  4a1125:	ff d0                	call   eax
  4a1127:	f3 0f 10 45 0c       	movss  xmm0,DWORD PTR [ebp+0xc]
  4a112c:	8b 16                	mov    edx,DWORD PTR [esi]
  4a112e:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4a1131:	57                   	push   edi
  4a1132:	8d 44 24 20          	lea    eax,[esp+0x20]
  4a1136:	f3 0f 11 44 24 20    	movss  DWORD PTR [esp+0x20],xmm0
  4a113c:	f3 0f 10 45 10       	movss  xmm0,DWORD PTR [ebp+0x10]
  4a1141:	50                   	push   eax
  4a1142:	8b ce                	mov    ecx,esi
  4a1144:	f3 0f 11 44 24 28    	movss  DWORD PTR [esp+0x28],xmm0
  4a114a:	ff d2                	call   edx
  4a114c:	8b 86 f0 00 00 00    	mov    eax,DWORD PTR [esi+0xf0]
  4a1152:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4a1155:	8d 8e f0 00 00 00    	lea    ecx,[esi+0xf0]
  4a115b:	57                   	push   edi
  4a115c:	ff d2                	call   edx
  4a115e:	d9 e8                	fld1
  4a1160:	8b 06                	mov    eax,DWORD PTR [esi]
  4a1162:	8b 50 68             	mov    edx,DWORD PTR [eax+0x68]
  4a1165:	51                   	push   ecx
  4a1166:	d9 1c 24             	fstp   DWORD PTR [esp]
  4a1169:	57                   	push   edi
  4a116a:	8b ce                	mov    ecx,esi
  4a116c:	ff d2                	call   edx
  4a116e:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4a1175:	f3 0f 10 05 b4 5a c5 	movss  xmm0,DWORD PTR ds:0xc55ab4
  4a117c:	00 
  4a117d:	f3 0f 11 86 cc 00 00 	movss  DWORD PTR [esi+0xcc],xmm0
  4a1184:	00 
  4a1185:	75 28                	jne    0x4a11af
  4a1187:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4a118d:	c7 44 24 30 04 00 00 	mov    DWORD PTR [esp+0x30],0x4
  4a1194:	00 
  4a1195:	e8 f6 da 03 00       	call   0x4dec90
  4a119a:	68 30 ce bc 00       	push   0xbcce30
  4a119f:	e8 76 11 3f 00       	call   0x89231a
  4a11a4:	83 c4 04             	add    esp,0x4
  4a11a7:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4a11ae:	ff 
  4a11af:	68 30 b1 fa 00       	push   0xfab130
  4a11b4:	8b c6                	mov    eax,esi
  4a11b6:	e8 75 ed 03 00       	call   0x4dff30
  4a11bb:	01 3d 04 de f7 00    	add    DWORD PTR ds:0xf7de04,edi
  4a11c1:	83 7d 1c 00          	cmp    DWORD PTR [ebp+0x1c],0x0
  4a11c5:	74 51                	je     0x4a1218
  4a11c7:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4a11cd:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a11cf:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4a11d2:	56                   	push   esi
  4a11d3:	89 79 04             	mov    DWORD PTR [ecx+0x4],edi
  4a11d6:	ff d2                	call   edx
  4a11d8:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4a11de:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a11e0:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4a11e3:	ff d2                	call   edx
  4a11e5:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  4a11ec:	75 20                	jne    0x4a120e
  4a11ee:	09 3d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,edi
  4a11f4:	c7 44 24 30 05 00 00 	mov    DWORD PTR [esp+0x30],0x5
  4a11fb:	00 
  4a11fc:	e8 4f f5 22 00       	call   0x6d0750
  4a1201:	68 30 d5 bc 00       	push   0xbcd530
  4a1206:	e8 0f 11 3f 00       	call   0x89231a
  4a120b:	83 c4 04             	add    esp,0x4
  4a120e:	c7 05 30 88 fb 00 00 	mov    DWORD PTR ds:0xfb8830,0x0
  4a1215:	00 00 00 
  4a1218:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4a121c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a1223:	59                   	pop    ecx
  4a1224:	5f                   	pop    edi
  4a1225:	5e                   	pop    esi
  4a1226:	5b                   	pop    ebx
  4a1227:	8b e5                	mov    esp,ebp
  4a1229:	5d                   	pop    ebp
  4a122a:	c2 18 00             	ret    0x18

## create_object_wrapper

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1fb0 <.text+0xa0fb0>:
  4a1fb0:	55                   	push   ebp
  4a1fb1:	8b ec                	mov    ebp,esp
  4a1fb3:	6a ff                	push   0xffffffff
  4a1fb5:	68 c8 83 93 00       	push   0x9383c8
  4a1fba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a1fc0:	50                   	push   eax
  4a1fc1:	83 ec 0c             	sub    esp,0xc
  4a1fc4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a1fc9:	33 c5                	xor    eax,ebp
  4a1fcb:	50                   	push   eax
  4a1fcc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a1fcf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a1fd5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1fd8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a1fdb:	33 c0                	xor    eax,eax
  4a1fdd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a1fe0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a1fe3:	8d 4d e8             	lea    ecx,[ebp-0x18]
  4a1fe6:	51                   	push   ecx
  4a1fe7:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a1fea:	e8 71 04 00 00       	call   0x4a2460
  4a1fef:	83 c4 04             	add    esp,0x4
  4a1ff2:	b8 01 00 00 00       	mov    eax,0x1
  4a1ff7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a1ffa:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a2001:	59                   	pop    ecx
  4a2002:	8b e5                	mov    esp,ebp
  4a2004:	5d                   	pop    ebp
  4a2005:	c3                   	ret

## create_object_ex_wrapper

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2010 <.text+0xa1010>:
  4a2010:	55                   	push   ebp
  4a2011:	8b ec                	mov    ebp,esp
  4a2013:	6a ff                	push   0xffffffff
  4a2015:	68 c8 83 93 00       	push   0x9383c8
  4a201a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a2020:	50                   	push   eax
  4a2021:	83 ec 0c             	sub    esp,0xc
  4a2024:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a2029:	33 c5                	xor    eax,ebp
  4a202b:	50                   	push   eax
  4a202c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a202f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a2035:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a2038:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a203b:	33 c0                	xor    eax,eax
  4a203d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a2040:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a2043:	8d 4d e8             	lea    ecx,[ebp-0x18]
  4a2046:	51                   	push   ecx
  4a2047:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a204a:	e8 a1 05 00 00       	call   0x4a25f0
  4a204f:	83 c4 04             	add    esp,0x4
  4a2052:	b8 01 00 00 00       	mov    eax,0x1
  4a2057:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a205a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a2061:	59                   	pop    ecx
  4a2062:	8b e5                	mov    esp,ebp
  4a2064:	5d                   	pop    ebp
  4a2065:	c3                   	ret

## create_object_marshaller

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2460 <.text+0xa1460>:
  4a2460:	55                   	push   ebp
  4a2461:	8b ec                	mov    ebp,esp
  4a2463:	83 ec 34             	sub    esp,0x34
  4a2466:	a1 88 17 fe 00       	mov    eax,ds:0xfe1788
  4a246b:	8b 0d 78 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1778
  4a2471:	53                   	push   ebx
  4a2472:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a2475:	56                   	push   esi
  4a2476:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a2479:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  4a247c:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a247e:	57                   	push   edi
  4a247f:	83 c8 ff             	or     eax,0xffffffff
  4a2482:	e8 69 2c 25 00       	call   0x6f50f0
  4a2487:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a248a:	83 f9 03             	cmp    ecx,0x3
  4a248d:	74 2e                	je     0x4a24bd
  4a248f:	83 f9 04             	cmp    ecx,0x4
  4a2492:	0f 85 34 01 00 00    	jne    0x4a25cc
  4a2498:	8b 30                	mov    esi,DWORD PTR [eax]
  4a249a:	83 c6 10             	add    esi,0x10
  4a249d:	8d 7d dc             	lea    edi,[ebp-0x24]
  4a24a0:	e8 bb 52 25 00       	call   0x6f7760
  4a24a5:	85 c0                	test   eax,eax
  4a24a7:	0f 84 1f 01 00 00    	je     0x4a25cc
  4a24ad:	dd 45 dc             	fld    QWORD PTR [ebp-0x24]
  4a24b0:	c7 45 d4 03 00 00 00 	mov    DWORD PTR [ebp-0x2c],0x3
  4a24b7:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a24ba:	8d 45 cc             	lea    eax,[ebp-0x34]
  4a24bd:	dd 00                	fld    QWORD PTR [eax]
  4a24bf:	dd 5d dc             	fstp   QWORD PTR [ebp-0x24]
  4a24c2:	dd 45 dc             	fld    QWORD PTR [ebp-0x24]
  4a24c5:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4a24c8:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4a24cb:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  4a24ce:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a24d0:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a24d3:	8b 48 e8             	mov    ecx,DWORD PTR [eax-0x18]
  4a24d6:	83 e8 20             	sub    eax,0x20
  4a24d9:	83 f9 03             	cmp    ecx,0x3
  4a24dc:	74 2e                	je     0x4a250c
  4a24de:	83 f9 04             	cmp    ecx,0x4
  4a24e1:	0f 85 f1 00 00 00    	jne    0x4a25d8
  4a24e7:	8b 30                	mov    esi,DWORD PTR [eax]
  4a24e9:	83 c6 10             	add    esi,0x10
  4a24ec:	8d 7d dc             	lea    edi,[ebp-0x24]
  4a24ef:	e8 6c 52 25 00       	call   0x6f7760
  4a24f4:	85 c0                	test   eax,eax
  4a24f6:	0f 84 dc 00 00 00    	je     0x4a25d8
  4a24fc:	dd 45 dc             	fld    QWORD PTR [ebp-0x24]
  4a24ff:	c7 45 d4 03 00 00 00 	mov    DWORD PTR [ebp-0x2c],0x3
  4a2506:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a2509:	8d 45 cc             	lea    eax,[ebp-0x34]
  4a250c:	dd 00                	fld    QWORD PTR [eax]
  4a250e:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a2510:	dd 5d e4             	fstp   QWORD PTR [ebp-0x1c]
  4a2513:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a2516:	8b 48 d8             	mov    ecx,DWORD PTR [eax-0x28]
  4a2519:	83 e8 30             	sub    eax,0x30
  4a251c:	83 f9 03             	cmp    ecx,0x3
  4a251f:	74 2e                	je     0x4a254f
  4a2521:	83 f9 04             	cmp    ecx,0x4
  4a2524:	0f 85 b5 00 00 00    	jne    0x4a25df
  4a252a:	8b 30                	mov    esi,DWORD PTR [eax]
  4a252c:	83 c6 10             	add    esi,0x10
  4a252f:	8d 7d dc             	lea    edi,[ebp-0x24]
  4a2532:	e8 29 52 25 00       	call   0x6f7760
  4a2537:	85 c0                	test   eax,eax
  4a2539:	0f 84 a0 00 00 00    	je     0x4a25df
  4a253f:	dd 45 dc             	fld    QWORD PTR [ebp-0x24]
  4a2542:	c7 45 d4 03 00 00 00 	mov    DWORD PTR [ebp-0x2c],0x3
  4a2549:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a254c:	8d 45 cc             	lea    eax,[ebp-0x34]
  4a254f:	dd 00                	fld    QWORD PTR [eax]
  4a2551:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a2553:	dd 5d dc             	fstp   QWORD PTR [ebp-0x24]
  4a2556:	b8 fc ff ff ff       	mov    eax,0xfffffffc
  4a255b:	e8 90 2b 25 00       	call   0x6f50f0
  4a2560:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a2563:	83 f9 03             	cmp    ecx,0x3
  4a2566:	74 26                	je     0x4a258e
  4a2568:	83 f9 04             	cmp    ecx,0x4
  4a256b:	75 79                	jne    0x4a25e6
  4a256d:	8b 30                	mov    esi,DWORD PTR [eax]
  4a256f:	83 c6 10             	add    esi,0x10
  4a2572:	8d 7d f8             	lea    edi,[ebp-0x8]
  4a2575:	e8 e6 51 25 00       	call   0x6f7760
  4a257a:	85 c0                	test   eax,eax
  4a257c:	74 68                	je     0x4a25e6
  4a257e:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4a2581:	c7 45 d4 03 00 00 00 	mov    DWORD PTR [ebp-0x2c],0x3
  4a2588:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a258b:	8d 45 cc             	lea    eax,[ebp-0x34]
  4a258e:	dd 00                	fld    QWORD PTR [eax]
  4a2590:	dd 5d d4             	fstp   QWORD PTR [ebp-0x2c]
  4a2593:	dd 45 d4             	fld    QWORD PTR [ebp-0x2c]
  4a2596:	db 5d fc             	fistp  DWORD PTR [ebp-0x4]
  4a2599:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4a259c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a259f:	dd 45 e4             	fld    QWORD PTR [ebp-0x1c]
  4a25a2:	d9 5d f4             	fstp   DWORD PTR [ebp-0xc]
  4a25a5:	51                   	push   ecx
  4a25a6:	d9 45 f4             	fld    DWORD PTR [ebp-0xc]
  4a25a9:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4a25ac:	83 ec 08             	sub    esp,0x8
  4a25af:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4a25b3:	dd 45 dc             	fld    QWORD PTR [ebp-0x24]
  4a25b6:	d9 5d f4             	fstp   DWORD PTR [ebp-0xc]
  4a25b9:	d9 45 f4             	fld    DWORD PTR [ebp-0xc]
  4a25bc:	d9 1c 24             	fstp   DWORD PTR [esp]
  4a25bf:	50                   	push   eax
  4a25c0:	ff 55 ec             	call   DWORD PTR [ebp-0x14]
  4a25c3:	5f                   	pop    edi
  4a25c4:	5e                   	pop    esi
  4a25c5:	33 c0                	xor    eax,eax
  4a25c7:	5b                   	pop    ebx
  4a25c8:	8b e5                	mov    esp,ebp
  4a25ca:	5d                   	pop    ebp
  4a25cb:	c3                   	ret
  4a25cc:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  4a25d3:	e9 f6 fe ff ff       	jmp    0x4a24ce
  4a25d8:	d9 ee                	fldz
  4a25da:	e9 2f ff ff ff       	jmp    0x4a250e
  4a25df:	d9 ee                	fldz
  4a25e1:	e9 6b ff ff ff       	jmp    0x4a2551
  4a25e6:	33 c0                	xor    eax,eax
  4a25e8:	eb b2                	jmp    0x4a259c

## create_object_ex_marshaller

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a25f0 <.text+0xa15f0>:
  4a25f0:	55                   	push   ebp
  4a25f1:	8b ec                	mov    ebp,esp
  4a25f3:	83 ec 44             	sub    esp,0x44
  4a25f6:	a1 8c 17 fe 00       	mov    eax,ds:0xfe178c
  4a25fb:	8b 0d 78 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1778
  4a2601:	53                   	push   ebx
  4a2602:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a2605:	56                   	push   esi
  4a2606:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  4a2609:	89 4d e0             	mov    DWORD PTR [ebp-0x20],ecx
  4a260c:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a260e:	57                   	push   edi
  4a260f:	83 c8 ff             	or     eax,0xffffffff
  4a2612:	e8 d9 2a 25 00       	call   0x6f50f0
  4a2617:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a261a:	83 f9 03             	cmp    ecx,0x3
  4a261d:	74 2e                	je     0x4a264d
  4a261f:	83 f9 04             	cmp    ecx,0x4
  4a2622:	0f 85 ea 01 00 00    	jne    0x4a2812
  4a2628:	8b 30                	mov    esi,DWORD PTR [eax]
  4a262a:	83 c6 10             	add    esi,0x10
  4a262d:	8d 7d cc             	lea    edi,[ebp-0x34]
  4a2630:	e8 2b 51 25 00       	call   0x6f7760
  4a2635:	85 c0                	test   eax,eax
  4a2637:	0f 84 d5 01 00 00    	je     0x4a2812
  4a263d:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a2640:	c7 45 c4 03 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x3
  4a2647:	dd 5d bc             	fstp   QWORD PTR [ebp-0x44]
  4a264a:	8d 45 bc             	lea    eax,[ebp-0x44]
  4a264d:	dd 00                	fld    QWORD PTR [eax]
  4a264f:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a2652:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a2655:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4a2658:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4a265b:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  4a265e:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a2660:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  4a2665:	e8 86 2a 25 00       	call   0x6f50f0
  4a266a:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a266d:	83 f9 03             	cmp    ecx,0x3
  4a2670:	74 2e                	je     0x4a26a0
  4a2672:	83 f9 04             	cmp    ecx,0x4
  4a2675:	0f 85 a3 01 00 00    	jne    0x4a281e
  4a267b:	8b 30                	mov    esi,DWORD PTR [eax]
  4a267d:	83 c6 10             	add    esi,0x10
  4a2680:	8d 7d cc             	lea    edi,[ebp-0x34]
  4a2683:	e8 d8 50 25 00       	call   0x6f7760
  4a2688:	85 c0                	test   eax,eax
  4a268a:	0f 84 8e 01 00 00    	je     0x4a281e
  4a2690:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a2693:	c7 45 c4 03 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x3
  4a269a:	dd 5d bc             	fstp   QWORD PTR [ebp-0x44]
  4a269d:	8d 45 bc             	lea    eax,[ebp-0x44]
  4a26a0:	dd 00                	fld    QWORD PTR [eax]
  4a26a2:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a26a5:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a26a8:	db 5d fc             	fistp  DWORD PTR [ebp-0x4]
  4a26ab:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4a26ae:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a26b1:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a26b3:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a26b8:	e8 33 2a 25 00       	call   0x6f50f0
  4a26bd:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a26c0:	83 f9 03             	cmp    ecx,0x3
  4a26c3:	74 2e                	je     0x4a26f3
  4a26c5:	83 f9 04             	cmp    ecx,0x4
  4a26c8:	0f 85 5c 01 00 00    	jne    0x4a282a
  4a26ce:	8b 30                	mov    esi,DWORD PTR [eax]
  4a26d0:	83 c6 10             	add    esi,0x10
  4a26d3:	8d 7d cc             	lea    edi,[ebp-0x34]
  4a26d6:	e8 85 50 25 00       	call   0x6f7760
  4a26db:	85 c0                	test   eax,eax
  4a26dd:	0f 84 47 01 00 00    	je     0x4a282a
  4a26e3:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a26e6:	c7 45 c4 03 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x3
  4a26ed:	dd 5d bc             	fstp   QWORD PTR [ebp-0x44]
  4a26f0:	8d 45 bc             	lea    eax,[ebp-0x44]
  4a26f3:	dd 00                	fld    QWORD PTR [eax]
  4a26f5:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a26f8:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a26fb:	db 5d f8             	fistp  DWORD PTR [ebp-0x8]
  4a26fe:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  4a2701:	89 4d e4             	mov    DWORD PTR [ebp-0x1c],ecx
  4a2704:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a2706:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a2709:	8b 48 c8             	mov    ecx,DWORD PTR [eax-0x38]
  4a270c:	83 e8 40             	sub    eax,0x40
  4a270f:	83 f9 03             	cmp    ecx,0x3
  4a2712:	74 2e                	je     0x4a2742
  4a2714:	83 f9 04             	cmp    ecx,0x4
  4a2717:	0f 85 19 01 00 00    	jne    0x4a2836
  4a271d:	8b 30                	mov    esi,DWORD PTR [eax]
  4a271f:	83 c6 10             	add    esi,0x10
  4a2722:	8d 7d cc             	lea    edi,[ebp-0x34]
  4a2725:	e8 36 50 25 00       	call   0x6f7760
  4a272a:	85 c0                	test   eax,eax
  4a272c:	0f 84 04 01 00 00    	je     0x4a2836
  4a2732:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a2735:	c7 45 c4 03 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x3
  4a273c:	dd 5d bc             	fstp   QWORD PTR [ebp-0x44]
  4a273f:	8d 45 bc             	lea    eax,[ebp-0x44]
  4a2742:	dd 00                	fld    QWORD PTR [eax]
  4a2744:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a2746:	dd 5d d4             	fstp   QWORD PTR [ebp-0x2c]
  4a2749:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a274c:	8b 48 b8             	mov    ecx,DWORD PTR [eax-0x48]
  4a274f:	83 e8 50             	sub    eax,0x50
  4a2752:	83 f9 03             	cmp    ecx,0x3
  4a2755:	74 2e                	je     0x4a2785
  4a2757:	83 f9 04             	cmp    ecx,0x4
  4a275a:	0f 85 dd 00 00 00    	jne    0x4a283d
  4a2760:	8b 30                	mov    esi,DWORD PTR [eax]
  4a2762:	83 c6 10             	add    esi,0x10
  4a2765:	8d 7d cc             	lea    edi,[ebp-0x34]
  4a2768:	e8 f3 4f 25 00       	call   0x6f7760
  4a276d:	85 c0                	test   eax,eax
  4a276f:	0f 84 c8 00 00 00    	je     0x4a283d
  4a2775:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a2778:	c7 45 c4 03 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x3
  4a277f:	dd 5d bc             	fstp   QWORD PTR [ebp-0x44]
  4a2782:	8d 45 bc             	lea    eax,[ebp-0x44]
  4a2785:	dd 00                	fld    QWORD PTR [eax]
  4a2787:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a2789:	dd 5d cc             	fstp   QWORD PTR [ebp-0x34]
  4a278c:	b8 fa ff ff ff       	mov    eax,0xfffffffa
  4a2791:	e8 5a 29 25 00       	call   0x6f50f0
  4a2796:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a2799:	83 f9 03             	cmp    ecx,0x3
  4a279c:	74 2e                	je     0x4a27cc
  4a279e:	83 f9 04             	cmp    ecx,0x4
  4a27a1:	0f 85 9d 00 00 00    	jne    0x4a2844
  4a27a7:	8b 30                	mov    esi,DWORD PTR [eax]
  4a27a9:	83 c6 10             	add    esi,0x10
  4a27ac:	8d 7d f0             	lea    edi,[ebp-0x10]
  4a27af:	e8 ac 4f 25 00       	call   0x6f7760
  4a27b4:	85 c0                	test   eax,eax
  4a27b6:	0f 84 88 00 00 00    	je     0x4a2844
  4a27bc:	dd 45 f0             	fld    QWORD PTR [ebp-0x10]
  4a27bf:	c7 45 c4 03 00 00 00 	mov    DWORD PTR [ebp-0x3c],0x3
  4a27c6:	dd 5d bc             	fstp   QWORD PTR [ebp-0x44]
  4a27c9:	8d 45 bc             	lea    eax,[ebp-0x44]
  4a27cc:	dd 00                	fld    QWORD PTR [eax]
  4a27ce:	dd 5d c4             	fstp   QWORD PTR [ebp-0x3c]
  4a27d1:	dd 45 c4             	fld    QWORD PTR [ebp-0x3c]
  4a27d4:	db 5d f4             	fistp  DWORD PTR [ebp-0xc]
  4a27d7:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  4a27da:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  4a27dd:	dd 45 d4             	fld    QWORD PTR [ebp-0x2c]
  4a27e0:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  4a27e3:	52                   	push   edx
  4a27e4:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  4a27e7:	d9 5d e4             	fstp   DWORD PTR [ebp-0x1c]
  4a27ea:	d9 45 e4             	fld    DWORD PTR [ebp-0x1c]
  4a27ed:	51                   	push   ecx
  4a27ee:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  4a27f1:	52                   	push   edx
  4a27f2:	83 ec 08             	sub    esp,0x8
  4a27f5:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4a27f9:	dd 45 cc             	fld    QWORD PTR [ebp-0x34]
  4a27fc:	d9 5d e4             	fstp   DWORD PTR [ebp-0x1c]
  4a27ff:	d9 45 e4             	fld    DWORD PTR [ebp-0x1c]
  4a2802:	d9 1c 24             	fstp   DWORD PTR [esp]
  4a2805:	50                   	push   eax
  4a2806:	ff 55 dc             	call   DWORD PTR [ebp-0x24]
  4a2809:	5f                   	pop    edi
  4a280a:	5e                   	pop    esi
  4a280b:	33 c0                	xor    eax,eax
  4a280d:	5b                   	pop    ebx
  4a280e:	8b e5                	mov    esp,ebp
  4a2810:	5d                   	pop    ebp
  4a2811:	c3                   	ret
  4a2812:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  4a2819:	e9 40 fe ff ff       	jmp    0x4a265e
  4a281e:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  4a2825:	e9 87 fe ff ff       	jmp    0x4a26b1
  4a282a:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  4a2831:	e9 ce fe ff ff       	jmp    0x4a2704
  4a2836:	d9 ee                	fldz
  4a2838:	e9 07 ff ff ff       	jmp    0x4a2744
  4a283d:	d9 ee                	fldz
  4a283f:	e9 43 ff ff ff       	jmp    0x4a2787
  4a2844:	33 c0                	xor    eax,eax
  4a2846:	eb 92                	jmp    0x4a27da

## world_id_lookup

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0082ef00 <.text+0x42df00>:
  82ef00:	55                   	push   ebp
  82ef01:	8b ec                	mov    ebp,esp
  82ef03:	51                   	push   ecx
  82ef04:	53                   	push   ebx
  82ef05:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  82ef08:	56                   	push   esi
  82ef09:	8b f1                	mov    esi,ecx
  82ef0b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  82ef0e:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  82ef11:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  82ef15:	75 1e                	jne    0x82ef35
  82ef17:	57                   	push   edi
  82ef18:	8b 3b                	mov    edi,DWORD PTR [ebx]
  82ef1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  82ef20:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  82ef23:	73 05                	jae    0x82ef2a
  82ef25:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  82ef28:	eb 04                	jmp    0x82ef2e
  82ef2a:	8b d1                	mov    edx,ecx
  82ef2c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  82ef2e:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  82ef32:	74 ec                	je     0x82ef20
  82ef34:	5f                   	pop    edi
  82ef35:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  82ef38:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  82ef3b:	3b d1                	cmp    edx,ecx
  82ef3d:	74 16                	je     0x82ef55
  82ef3f:	8b 33                	mov    esi,DWORD PTR [ebx]
  82ef41:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  82ef44:	72 0f                	jb     0x82ef55
  82ef46:	8d 4d 08             	lea    ecx,[ebp+0x8]
  82ef49:	8b 09                	mov    ecx,DWORD PTR [ecx]
  82ef4b:	5e                   	pop    esi
  82ef4c:	89 08                	mov    DWORD PTR [eax],ecx
  82ef4e:	5b                   	pop    ebx
  82ef4f:	8b e5                	mov    esp,ebp
  82ef51:	5d                   	pop    ebp
  82ef52:	c2 04 00             	ret    0x4
  82ef55:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  82ef58:	8d 4d fc             	lea    ecx,[ebp-0x4]
  82ef5b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  82ef5d:	5e                   	pop    esi
  82ef5e:	89 08                	mov    DWORD PTR [eax],ecx
  82ef60:	5b                   	pop    ebx
  82ef61:	8b e5                	mov    esp,ebp
  82ef63:	5d                   	pop    ebp
  82ef64:	c2 04 00             	ret    0x4

## lua_c_result_count_reused

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

006fe351 <.text+0x2fd351>:
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

## lb_bind_SetDebugLevel

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a15b0 <.text+0xa05b0>:
  4a15b0:	55                   	push   ebp
  4a15b1:	8b ec                	mov    ebp,esp
  4a15b3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a15b6:	53                   	push   ebx
  4a15b7:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a15bd:	56                   	push   esi
  4a15be:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a15c0:	57                   	push   edi
  4a15c1:	8b 38                	mov    edi,DWORD PTR [eax]
  4a15c3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a15c8:	c7 05 7c 17 fe 00 a0 	mov    DWORD PTR ds:0xfe177c,0x4a0aa0
  4a15cf:	0a 4a 00 
  4a15d2:	e8 a9 40 25 00       	call   0x6f5680
  4a15d7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a15d9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a15dc:	83 e8 10             	sub    eax,0x10
  4a15df:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a15e4:	74 06                	je     0x4a15ec
  4a15e6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a15ea:	74 14                	je     0x4a1600
  4a15ec:	57                   	push   edi
  4a15ed:	68 c4 26 c4 00       	push   0xc426c4
  4a15f2:	e8 c6 1a 3f 00       	call   0x8930bd
  4a15f7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a15f9:	83 c4 08             	add    esp,0x8
  4a15fc:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1600:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1606:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1608:	68 90 ad d6 00       	push   0xd6ad90
  4a160d:	e8 fe 3e 25 00       	call   0x6f5510
  4a1612:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1614:	83 c4 04             	add    esp,0x4
  4a1617:	6a 00                	push   0x0
  4a1619:	68 90 1e 4a 00       	push   0x4a1e90
  4a161e:	e8 8d 3f 25 00       	call   0x6f55b0
  4a1623:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1625:	51                   	push   ecx
  4a1626:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a162b:	e8 c0 41 25 00       	call   0x6f57f0
  4a1630:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1636:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1638:	83 c4 0c             	add    esp,0xc
  4a163b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a163f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1642:	5f                   	pop    edi
  4a1643:	5e                   	pop    esi
  4a1644:	5b                   	pop    ebx
  4a1645:	5d                   	pop    ebp
  4a1646:	c2 04 00             	ret    0x4

## lb_bind_GetObjectCount

02-Tartaros.bin:     file format pei-i386


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

## lb_bind_ChangeMap

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a16f0 <.text+0xa06f0>:
  4a16f0:	55                   	push   ebp
  4a16f1:	8b ec                	mov    ebp,esp
  4a16f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a16f6:	53                   	push   ebx
  4a16f7:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a16fd:	56                   	push   esi
  4a16fe:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1700:	57                   	push   edi
  4a1701:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1703:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1708:	c7 05 84 17 fe 00 c0 	mov    DWORD PTR ds:0xfe1784,0x4a0ac0
  4a170f:	0a 4a 00 
  4a1712:	e8 69 3f 25 00       	call   0x6f5680
  4a1717:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1719:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a171c:	83 e8 10             	sub    eax,0x10
  4a171f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1724:	74 06                	je     0x4a172c
  4a1726:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a172a:	74 14                	je     0x4a1740
  4a172c:	57                   	push   edi
  4a172d:	68 c4 26 c4 00       	push   0xc426c4
  4a1732:	e8 86 19 3f 00       	call   0x8930bd
  4a1737:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1739:	83 c4 08             	add    esp,0x8
  4a173c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1740:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1746:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1748:	68 b0 ad d6 00       	push   0xd6adb0
  4a174d:	e8 be 3d 25 00       	call   0x6f5510
  4a1752:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1754:	83 c4 04             	add    esp,0x4
  4a1757:	6a 00                	push   0x0
  4a1759:	68 50 1f 4a 00       	push   0x4a1f50
  4a175e:	e8 4d 3e 25 00       	call   0x6f55b0
  4a1763:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1765:	51                   	push   ecx
  4a1766:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a176b:	e8 80 40 25 00       	call   0x6f57f0
  4a1770:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1776:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1778:	83 c4 0c             	add    esp,0xc
  4a177b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a177f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1782:	5f                   	pop    edi
  4a1783:	5e                   	pop    esi
  4a1784:	5b                   	pop    ebx
  4a1785:	5d                   	pop    ebp
  4a1786:	c2 04 00             	ret    0x4

## lb_bind_CreateObject

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1790 <.text+0xa0790>:
  4a1790:	55                   	push   ebp
  4a1791:	8b ec                	mov    ebp,esp
  4a1793:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1796:	53                   	push   ebx
  4a1797:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a179d:	56                   	push   esi
  4a179e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a17a0:	57                   	push   edi
  4a17a1:	8b 38                	mov    edi,DWORD PTR [eax]
  4a17a3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a17a8:	c7 05 88 17 fe 00 40 	mov    DWORD PTR ds:0xfe1788,0x4a0b40
  4a17af:	0b 4a 00 
  4a17b2:	e8 c9 3e 25 00       	call   0x6f5680
  4a17b7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a17b9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a17bc:	83 e8 10             	sub    eax,0x10
  4a17bf:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a17c4:	74 06                	je     0x4a17cc
  4a17c6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a17ca:	74 14                	je     0x4a17e0
  4a17cc:	57                   	push   edi
  4a17cd:	68 c4 26 c4 00       	push   0xc426c4
  4a17d2:	e8 e6 18 3f 00       	call   0x8930bd
  4a17d7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a17d9:	83 c4 08             	add    esp,0x8
  4a17dc:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a17e0:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a17e6:	8b 37                	mov    esi,DWORD PTR [edi]
  4a17e8:	68 bc ad d6 00       	push   0xd6adbc
  4a17ed:	e8 1e 3d 25 00       	call   0x6f5510
  4a17f2:	8b 37                	mov    esi,DWORD PTR [edi]
  4a17f4:	83 c4 04             	add    esp,0x4
  4a17f7:	6a 00                	push   0x0
  4a17f9:	68 b0 1f 4a 00       	push   0x4a1fb0
  4a17fe:	e8 ad 3d 25 00       	call   0x6f55b0
  4a1803:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1805:	51                   	push   ecx
  4a1806:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a180b:	e8 e0 3f 25 00       	call   0x6f57f0
  4a1810:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1816:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1818:	83 c4 0c             	add    esp,0xc
  4a181b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a181f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1822:	5f                   	pop    edi
  4a1823:	5e                   	pop    esi
  4a1824:	5b                   	pop    ebx
  4a1825:	5d                   	pop    ebp
  4a1826:	c2 04 00             	ret    0x4

## lb_bind_CreateObjectEx

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1830 <.text+0xa0830>:
  4a1830:	55                   	push   ebp
  4a1831:	8b ec                	mov    ebp,esp
  4a1833:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1836:	53                   	push   ebx
  4a1837:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a183d:	56                   	push   esi
  4a183e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1840:	57                   	push   edi
  4a1841:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1843:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1848:	c7 05 8c 17 fe 00 70 	mov    DWORD PTR ds:0xfe178c,0x4a0f70
  4a184f:	0f 4a 00 
  4a1852:	e8 29 3e 25 00       	call   0x6f5680
  4a1857:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1859:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a185c:	83 e8 10             	sub    eax,0x10
  4a185f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1864:	74 06                	je     0x4a186c
  4a1866:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a186a:	74 14                	je     0x4a1880
  4a186c:	57                   	push   edi
  4a186d:	68 c4 26 c4 00       	push   0xc426c4
  4a1872:	e8 46 18 3f 00       	call   0x8930bd
  4a1877:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1879:	83 c4 08             	add    esp,0x8
  4a187c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1880:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1886:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1888:	68 cc ad d6 00       	push   0xd6adcc
  4a188d:	e8 7e 3c 25 00       	call   0x6f5510
  4a1892:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1894:	83 c4 04             	add    esp,0x4
  4a1897:	6a 00                	push   0x0
  4a1899:	68 10 20 4a 00       	push   0x4a2010
  4a189e:	e8 0d 3d 25 00       	call   0x6f55b0
  4a18a3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a18a5:	51                   	push   ecx
  4a18a6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a18ab:	e8 40 3f 25 00       	call   0x6f57f0
  4a18b0:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a18b6:	8b 02                	mov    eax,DWORD PTR [edx]
  4a18b8:	83 c4 0c             	add    esp,0xc
  4a18bb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a18bf:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a18c2:	5f                   	pop    edi
  4a18c3:	5e                   	pop    esi
  4a18c4:	5b                   	pop    ebx
  4a18c5:	5d                   	pop    ebp
  4a18c6:	c2 04 00             	ret    0x4

## lb_bind_SetActorAvatar

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a18d0 <.text+0xa08d0>:
  4a18d0:	55                   	push   ebp
  4a18d1:	8b ec                	mov    ebp,esp
  4a18d3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a18d6:	53                   	push   ebx
  4a18d7:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a18dd:	56                   	push   esi
  4a18de:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a18e0:	57                   	push   edi
  4a18e1:	8b 38                	mov    edi,DWORD PTR [eax]
  4a18e3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a18e8:	c7 05 90 17 fe 00 80 	mov    DWORD PTR ds:0xfe1790,0x4a0b80
  4a18ef:	0b 4a 00 
  4a18f2:	e8 89 3d 25 00       	call   0x6f5680
  4a18f7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a18f9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a18fc:	83 e8 10             	sub    eax,0x10
  4a18ff:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1904:	74 06                	je     0x4a190c
  4a1906:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a190a:	74 14                	je     0x4a1920
  4a190c:	57                   	push   edi
  4a190d:	68 c4 26 c4 00       	push   0xc426c4
  4a1912:	e8 a6 17 3f 00       	call   0x8930bd
  4a1917:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1919:	83 c4 08             	add    esp,0x8
  4a191c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1920:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1926:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1928:	68 dc ad d6 00       	push   0xd6addc
  4a192d:	e8 de 3b 25 00       	call   0x6f5510
  4a1932:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1934:	83 c4 04             	add    esp,0x4
  4a1937:	6a 00                	push   0x0
  4a1939:	68 70 20 4a 00       	push   0x4a2070
  4a193e:	e8 6d 3c 25 00       	call   0x6f55b0
  4a1943:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1945:	51                   	push   ecx
  4a1946:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a194b:	e8 a0 3e 25 00       	call   0x6f57f0
  4a1950:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1956:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1958:	83 c4 0c             	add    esp,0xc
  4a195b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a195f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1962:	5f                   	pop    edi
  4a1963:	5e                   	pop    esi
  4a1964:	5b                   	pop    ebx
  4a1965:	5d                   	pop    ebp
  4a1966:	c2 04 00             	ret    0x4

## lb_bind_AttachActorItem

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1970 <.text+0xa0970>:
  4a1970:	55                   	push   ebp
  4a1971:	8b ec                	mov    ebp,esp
  4a1973:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1976:	53                   	push   ebx
  4a1977:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a197d:	56                   	push   esi
  4a197e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1980:	57                   	push   edi
  4a1981:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1983:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1988:	c7 05 94 17 fe 00 50 	mov    DWORD PTR ds:0xfe1794,0x4a0c50
  4a198f:	0c 4a 00 
  4a1992:	e8 e9 3c 25 00       	call   0x6f5680
  4a1997:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1999:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a199c:	83 e8 10             	sub    eax,0x10
  4a199f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a19a4:	74 06                	je     0x4a19ac
  4a19a6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a19aa:	74 14                	je     0x4a19c0
  4a19ac:	57                   	push   edi
  4a19ad:	68 c4 26 c4 00       	push   0xc426c4
  4a19b2:	e8 06 17 3f 00       	call   0x8930bd
  4a19b7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a19b9:	83 c4 08             	add    esp,0x8
  4a19bc:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a19c0:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a19c6:	8b 37                	mov    esi,DWORD PTR [edi]
  4a19c8:	68 ec ad d6 00       	push   0xd6adec
  4a19cd:	e8 3e 3b 25 00       	call   0x6f5510
  4a19d2:	8b 37                	mov    esi,DWORD PTR [edi]
  4a19d4:	83 c4 04             	add    esp,0x4
  4a19d7:	6a 00                	push   0x0
  4a19d9:	68 d0 20 4a 00       	push   0x4a20d0
  4a19de:	e8 cd 3b 25 00       	call   0x6f55b0
  4a19e3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a19e5:	51                   	push   ecx
  4a19e6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a19eb:	e8 00 3e 25 00       	call   0x6f57f0
  4a19f0:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a19f6:	8b 02                	mov    eax,DWORD PTR [edx]
  4a19f8:	83 c4 0c             	add    esp,0xc
  4a19fb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a19ff:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1a02:	5f                   	pop    edi
  4a1a03:	5e                   	pop    esi
  4a1a04:	5b                   	pop    ebx
  4a1a05:	5d                   	pop    ebp
  4a1a06:	c2 04 00             	ret    0x4

## lb_bind_DetachActorItem

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1a10 <.text+0xa0a10>:
  4a1a10:	55                   	push   ebp
  4a1a11:	8b ec                	mov    ebp,esp
  4a1a13:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1a16:	53                   	push   ebx
  4a1a17:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1a1d:	56                   	push   esi
  4a1a1e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1a20:	57                   	push   edi
  4a1a21:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1a23:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1a28:	c7 05 98 17 fe 00 10 	mov    DWORD PTR ds:0xfe1798,0x4a0d10
  4a1a2f:	0d 4a 00 
  4a1a32:	e8 49 3c 25 00       	call   0x6f5680
  4a1a37:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1a39:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1a3c:	83 e8 10             	sub    eax,0x10
  4a1a3f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1a44:	74 06                	je     0x4a1a4c
  4a1a46:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1a4a:	74 14                	je     0x4a1a60
  4a1a4c:	57                   	push   edi
  4a1a4d:	68 c4 26 c4 00       	push   0xc426c4
  4a1a52:	e8 66 16 3f 00       	call   0x8930bd
  4a1a57:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1a59:	83 c4 08             	add    esp,0x8
  4a1a5c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1a60:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1a66:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1a68:	68 fc ad d6 00       	push   0xd6adfc
  4a1a6d:	e8 9e 3a 25 00       	call   0x6f5510
  4a1a72:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1a74:	83 c4 04             	add    esp,0x4
  4a1a77:	6a 00                	push   0x0
  4a1a79:	68 30 21 4a 00       	push   0x4a2130
  4a1a7e:	e8 2d 3b 25 00       	call   0x6f55b0
  4a1a83:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1a85:	51                   	push   ecx
  4a1a86:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1a8b:	e8 60 3d 25 00       	call   0x6f57f0
  4a1a90:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1a96:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1a98:	83 c4 0c             	add    esp,0xc
  4a1a9b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1a9f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1aa2:	5f                   	pop    edi
  4a1aa3:	5e                   	pop    esi
  4a1aa4:	5b                   	pop    ebx
  4a1aa5:	5d                   	pop    ebp
  4a1aa6:	c2 04 00             	ret    0x4

## lb_bind_GetTime

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1ab0 <.text+0xa0ab0>:
  4a1ab0:	55                   	push   ebp
  4a1ab1:	8b ec                	mov    ebp,esp
  4a1ab3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1ab6:	53                   	push   ebx
  4a1ab7:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1abd:	56                   	push   esi
  4a1abe:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1ac0:	57                   	push   edi
  4a1ac1:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1ac3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1ac8:	c7 05 9c 17 fe 00 70 	mov    DWORD PTR ds:0xfe179c,0x4a0b70
  4a1acf:	0b 4a 00 
  4a1ad2:	e8 a9 3b 25 00       	call   0x6f5680
  4a1ad7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1ad9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1adc:	83 e8 10             	sub    eax,0x10
  4a1adf:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1ae4:	74 06                	je     0x4a1aec
  4a1ae6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1aea:	74 14                	je     0x4a1b00
  4a1aec:	57                   	push   edi
  4a1aed:	68 c4 26 c4 00       	push   0xc426c4
  4a1af2:	e8 c6 15 3f 00       	call   0x8930bd
  4a1af7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1af9:	83 c4 08             	add    esp,0x8
  4a1afc:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1b00:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1b06:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1b08:	68 0c ae d6 00       	push   0xd6ae0c
  4a1b0d:	e8 fe 39 25 00       	call   0x6f5510
  4a1b12:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1b14:	83 c4 04             	add    esp,0x4
  4a1b17:	6a 00                	push   0x0
  4a1b19:	68 90 21 4a 00       	push   0x4a2190
  4a1b1e:	e8 8d 3a 25 00       	call   0x6f55b0
  4a1b23:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1b25:	51                   	push   ecx
  4a1b26:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1b2b:	e8 c0 3c 25 00       	call   0x6f57f0
  4a1b30:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1b36:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1b38:	83 c4 0c             	add    esp,0xc
  4a1b3b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1b3f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1b42:	5f                   	pop    edi
  4a1b43:	5e                   	pop    esi
  4a1b44:	5b                   	pop    ebx
  4a1b45:	5d                   	pop    ebp
  4a1b46:	c2 04 00             	ret    0x4

## lb_bind_DoFile

02-Tartaros.bin:     file format pei-i386


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
  4a1be6:	c2 04 00             	ret    0x4

## lb_bind_PrintCurrSceneID

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1bf0 <.text+0xa0bf0>:
  4a1bf0:	55                   	push   ebp
  4a1bf1:	8b ec                	mov    ebp,esp
  4a1bf3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1bf6:	53                   	push   ebx
  4a1bf7:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1bfd:	56                   	push   esi
  4a1bfe:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1c00:	57                   	push   edi
  4a1c01:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1c03:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1c08:	c7 05 a4 17 fe 00 10 	mov    DWORD PTR ds:0xfe17a4,0x5f5d10
  4a1c0f:	5d 5f 00 
  4a1c12:	e8 69 3a 25 00       	call   0x6f5680
  4a1c17:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1c19:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1c1c:	83 e8 10             	sub    eax,0x10
  4a1c1f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1c24:	74 06                	je     0x4a1c2c
  4a1c26:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1c2a:	74 14                	je     0x4a1c40
  4a1c2c:	57                   	push   edi
  4a1c2d:	68 c4 26 c4 00       	push   0xc426c4
  4a1c32:	e8 86 14 3f 00       	call   0x8930bd
  4a1c37:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1c39:	83 c4 08             	add    esp,0x8
  4a1c3c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1c40:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1c46:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1c48:	68 1c ae d6 00       	push   0xd6ae1c
  4a1c4d:	e8 be 38 25 00       	call   0x6f5510
  4a1c52:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1c54:	83 c4 04             	add    esp,0x4
  4a1c57:	6a 00                	push   0x0
  4a1c59:	68 60 22 4a 00       	push   0x4a2260
  4a1c5e:	e8 4d 39 25 00       	call   0x6f55b0
  4a1c63:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1c65:	51                   	push   ecx
  4a1c66:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1c6b:	e8 80 3b 25 00       	call   0x6f57f0
  4a1c70:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1c76:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1c78:	83 c4 0c             	add    esp,0xc
  4a1c7b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1c7f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1c82:	5f                   	pop    edi
  4a1c83:	5e                   	pop    esi
  4a1c84:	5b                   	pop    ebx
  4a1c85:	5d                   	pop    ebp
  4a1c86:	c2 04 00             	ret    0x4

## lb_bind_ChangeResolution

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1c90 <.text+0xa0c90>:
  4a1c90:	55                   	push   ebp
  4a1c91:	8b ec                	mov    ebp,esp
  4a1c93:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1c96:	53                   	push   ebx
  4a1c97:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1c9d:	56                   	push   esi
  4a1c9e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1ca0:	57                   	push   edi
  4a1ca1:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1ca3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1ca8:	c7 05 a8 17 fe 00 30 	mov    DWORD PTR ds:0xfe17a8,0x4a1330
  4a1caf:	13 4a 00 
  4a1cb2:	e8 c9 39 25 00       	call   0x6f5680
  4a1cb7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1cb9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1cbc:	83 e8 10             	sub    eax,0x10
  4a1cbf:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1cc4:	74 06                	je     0x4a1ccc
  4a1cc6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1cca:	74 14                	je     0x4a1ce0
  4a1ccc:	57                   	push   edi
  4a1ccd:	68 c4 26 c4 00       	push   0xc426c4
  4a1cd2:	e8 e6 13 3f 00       	call   0x8930bd
  4a1cd7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1cd9:	83 c4 08             	add    esp,0x8
  4a1cdc:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1ce0:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1ce6:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1ce8:	68 30 ae d6 00       	push   0xd6ae30
  4a1ced:	e8 1e 38 25 00       	call   0x6f5510
  4a1cf2:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1cf4:	83 c4 04             	add    esp,0x4
  4a1cf7:	6a 00                	push   0x0
  4a1cf9:	68 c0 22 4a 00       	push   0x4a22c0
  4a1cfe:	e8 ad 38 25 00       	call   0x6f55b0
  4a1d03:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1d05:	51                   	push   ecx
  4a1d06:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1d0b:	e8 e0 3a 25 00       	call   0x6f57f0
  4a1d10:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1d16:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1d18:	83 c4 0c             	add    esp,0xc
  4a1d1b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1d1f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1d22:	5f                   	pop    edi
  4a1d23:	5e                   	pop    esi
  4a1d24:	5b                   	pop    ebx
  4a1d25:	5d                   	pop    ebp
  4a1d26:	c2 04 00             	ret    0x4

## lb_bind_LoadMinimap

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1d30 <.text+0xa0d30>:
  4a1d30:	55                   	push   ebp
  4a1d31:	8b ec                	mov    ebp,esp
  4a1d33:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1d36:	53                   	push   ebx
  4a1d37:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1d3d:	56                   	push   esi
  4a1d3e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1d40:	57                   	push   edi
  4a1d41:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1d43:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1d48:	c7 05 ac 17 fe 00 00 	mov    DWORD PTR ds:0xfe17ac,0x4a1400
  4a1d4f:	14 4a 00 
  4a1d52:	e8 29 39 25 00       	call   0x6f5680
  4a1d57:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1d59:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1d5c:	83 e8 10             	sub    eax,0x10
  4a1d5f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1d64:	74 06                	je     0x4a1d6c
  4a1d66:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1d6a:	74 14                	je     0x4a1d80
  4a1d6c:	57                   	push   edi
  4a1d6d:	68 c4 26 c4 00       	push   0xc426c4
  4a1d72:	e8 46 13 3f 00       	call   0x8930bd
  4a1d77:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1d79:	83 c4 08             	add    esp,0x8
  4a1d7c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1d80:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1d86:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1d88:	68 44 ae d6 00       	push   0xd6ae44
  4a1d8d:	e8 7e 37 25 00       	call   0x6f5510
  4a1d92:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1d94:	83 c4 04             	add    esp,0x4
  4a1d97:	6a 00                	push   0x0
  4a1d99:	68 20 23 4a 00       	push   0x4a2320
  4a1d9e:	e8 0d 38 25 00       	call   0x6f55b0
  4a1da3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1da5:	51                   	push   ecx
  4a1da6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1dab:	e8 40 3a 25 00       	call   0x6f57f0
  4a1db0:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1db6:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1db8:	83 c4 0c             	add    esp,0xc
  4a1dbb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1dbf:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1dc2:	5f                   	pop    edi
  4a1dc3:	5e                   	pop    esi
  4a1dc4:	5b                   	pop    ebx
  4a1dc5:	5d                   	pop    ebp
  4a1dc6:	c2 04 00             	ret    0x4

## lb_bind_ChangeKeymapType

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a1dd0 <.text+0xa0dd0>:
  4a1dd0:	55                   	push   ebp
  4a1dd1:	8b ec                	mov    ebp,esp
  4a1dd3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1dd6:	53                   	push   ebx
  4a1dd7:	8b 1d 74 17 fe 00    	mov    ebx,DWORD PTR ds:0xfe1774
  4a1ddd:	56                   	push   esi
  4a1dde:	8b 33                	mov    esi,DWORD PTR [ebx]
  4a1de0:	57                   	push   edi
  4a1de1:	8b 38                	mov    edi,DWORD PTR [eax]
  4a1de3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4a1de8:	c7 05 b0 17 fe 00 40 	mov    DWORD PTR ds:0xfe17b0,0x4a1440
  4a1def:	14 4a 00 
  4a1df2:	e8 89 38 25 00       	call   0x6f5680
  4a1df7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4a1df9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4a1dfc:	83 e8 10             	sub    eax,0x10
  4a1dff:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4a1e04:	74 06                	je     0x4a1e0c
  4a1e06:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4a1e0a:	74 14                	je     0x4a1e20
  4a1e0c:	57                   	push   edi
  4a1e0d:	68 c4 26 c4 00       	push   0xc426c4
  4a1e12:	e8 a6 12 3f 00       	call   0x8930bd
  4a1e17:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4a1e19:	83 c4 08             	add    esp,0x8
  4a1e1c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4a1e20:	8b 3d 74 17 fe 00    	mov    edi,DWORD PTR ds:0xfe1774
  4a1e26:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1e28:	68 50 ae d6 00       	push   0xd6ae50
  4a1e2d:	e8 de 36 25 00       	call   0x6f5510
  4a1e32:	8b 37                	mov    esi,DWORD PTR [edi]
  4a1e34:	83 c4 04             	add    esp,0x4
  4a1e37:	6a 00                	push   0x0
  4a1e39:	68 80 23 4a 00       	push   0x4a2380
  4a1e3e:	e8 6d 37 25 00       	call   0x6f55b0
  4a1e43:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a1e45:	51                   	push   ecx
  4a1e46:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a1e4b:	e8 a0 39 25 00       	call   0x6f57f0
  4a1e50:	8b 15 74 17 fe 00    	mov    edx,DWORD PTR ds:0xfe1774
  4a1e56:	8b 02                	mov    eax,DWORD PTR [edx]
  4a1e58:	83 c4 0c             	add    esp,0xc
  4a1e5b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4a1e5f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a1e62:	5f                   	pop    edi
  4a1e63:	5e                   	pop    esi
  4a1e64:	5b                   	pop    ebx
  4a1e65:	5d                   	pop    ebp
  4a1e66:	c2 04 00             	ret    0x4

## set_actor_avatar_wrapper

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2070 <.text+0xa1070>:
  4a2070:	55                   	push   ebp
  4a2071:	8b ec                	mov    ebp,esp
  4a2073:	6a ff                	push   0xffffffff
  4a2075:	68 c8 83 93 00       	push   0x9383c8
  4a207a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a2080:	50                   	push   eax
  4a2081:	83 ec 0c             	sub    esp,0xc
  4a2084:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a2089:	33 c5                	xor    eax,ebp
  4a208b:	50                   	push   eax
  4a208c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a208f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a2095:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a2098:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a209b:	33 c0                	xor    eax,eax
  4a209d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a20a0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a20a3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a20a6:	8b 0d 90 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1790
  4a20ac:	51                   	push   ecx
  4a20ad:	8d 55 e8             	lea    edx,[ebp-0x18]
  4a20b0:	52                   	push   edx
  4a20b1:	e8 9a 07 00 00       	call   0x4a2850
  4a20b6:	83 c4 08             	add    esp,0x8
  4a20b9:	b8 01 00 00 00       	mov    eax,0x1
  4a20be:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a20c1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a20c8:	59                   	pop    ecx
  4a20c9:	8b e5                	mov    esp,ebp
  4a20cb:	5d                   	pop    ebp
  4a20cc:	c3                   	ret

## attach_actor_item_wrapper

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a20d0 <.text+0xa10d0>:
  4a20d0:	55                   	push   ebp
  4a20d1:	8b ec                	mov    ebp,esp
  4a20d3:	6a ff                	push   0xffffffff
  4a20d5:	68 c8 83 93 00       	push   0x9383c8
  4a20da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a20e0:	50                   	push   eax
  4a20e1:	83 ec 0c             	sub    esp,0xc
  4a20e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a20e9:	33 c5                	xor    eax,ebp
  4a20eb:	50                   	push   eax
  4a20ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a20ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a20f5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a20f8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a20fb:	33 c0                	xor    eax,eax
  4a20fd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a2100:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a2103:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a2106:	8b 0d 94 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1794
  4a210c:	51                   	push   ecx
  4a210d:	8d 55 e8             	lea    edx,[ebp-0x18]
  4a2110:	52                   	push   edx
  4a2111:	e8 7a 08 00 00       	call   0x4a2990
  4a2116:	83 c4 08             	add    esp,0x8
  4a2119:	b8 01 00 00 00       	mov    eax,0x1
  4a211e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a2121:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a2128:	59                   	pop    ecx
  4a2129:	8b e5                	mov    esp,ebp
  4a212b:	5d                   	pop    ebp
  4a212c:	c3                   	ret

## detach_actor_item_wrapper

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2130 <.text+0xa1130>:
  4a2130:	55                   	push   ebp
  4a2131:	8b ec                	mov    ebp,esp
  4a2133:	6a ff                	push   0xffffffff
  4a2135:	68 c8 83 93 00       	push   0x9383c8
  4a213a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a2140:	50                   	push   eax
  4a2141:	83 ec 0c             	sub    esp,0xc
  4a2144:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a2149:	33 c5                	xor    eax,ebp
  4a214b:	50                   	push   eax
  4a214c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a214f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a2155:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a2158:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4a215b:	33 c0                	xor    eax,eax
  4a215d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a2160:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a2163:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a2166:	8b 0d 98 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe1798
  4a216c:	51                   	push   ecx
  4a216d:	8d 55 e8             	lea    edx,[ebp-0x18]
  4a2170:	52                   	push   edx
  4a2171:	e8 1a 08 00 00       	call   0x4a2990
  4a2176:	83 c4 08             	add    esp,0x8
  4a2179:	b8 01 00 00 00       	mov    eax,0x1
  4a217e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a2181:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a2188:	59                   	pop    ecx
  4a2189:	8b e5                	mov    esp,ebp
  4a218b:	5d                   	pop    ebp
  4a218c:	c3                   	ret

## three_int_marshaller

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2850 <.text+0xa1850>:
  4a2850:	55                   	push   ebp
  4a2851:	8b ec                	mov    ebp,esp
  4a2853:	83 ec 2c             	sub    esp,0x2c
  4a2856:	a1 78 17 fe 00       	mov    eax,ds:0xfe1778
  4a285b:	53                   	push   ebx
  4a285c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a285f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a2861:	56                   	push   esi
  4a2862:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  4a2865:	57                   	push   edi
  4a2866:	83 c8 ff             	or     eax,0xffffffff
  4a2869:	e8 82 28 25 00       	call   0x6f50f0
  4a286e:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a2871:	83 f9 03             	cmp    ecx,0x3
  4a2874:	74 2e                	je     0x4a28a4
  4a2876:	83 f9 04             	cmp    ecx,0x4
  4a2879:	0f 85 e9 00 00 00    	jne    0x4a2968
  4a287f:	8b 30                	mov    esi,DWORD PTR [eax]
  4a2881:	83 c6 10             	add    esi,0x10
  4a2884:	8d 7d e8             	lea    edi,[ebp-0x18]
  4a2887:	e8 d4 4e 25 00       	call   0x6f7760
  4a288c:	85 c0                	test   eax,eax
  4a288e:	0f 84 d4 00 00 00    	je     0x4a2968
  4a2894:	dd 45 e8             	fld    QWORD PTR [ebp-0x18]
  4a2897:	c7 45 dc 03 00 00 00 	mov    DWORD PTR [ebp-0x24],0x3
  4a289e:	dd 5d d4             	fstp   QWORD PTR [ebp-0x2c]
  4a28a1:	8d 45 d4             	lea    eax,[ebp-0x2c]
  4a28a4:	dd 00                	fld    QWORD PTR [eax]
  4a28a6:	dd 5d e8             	fstp   QWORD PTR [ebp-0x18]
  4a28a9:	dd 45 e8             	fld    QWORD PTR [ebp-0x18]
  4a28ac:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4a28af:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4a28b2:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  4a28b5:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a28b7:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  4a28bc:	e8 2f 28 25 00       	call   0x6f50f0
  4a28c1:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a28c4:	83 f9 03             	cmp    ecx,0x3
  4a28c7:	74 2e                	je     0x4a28f7
  4a28c9:	83 f9 04             	cmp    ecx,0x4
  4a28cc:	0f 85 a2 00 00 00    	jne    0x4a2974
  4a28d2:	8b 30                	mov    esi,DWORD PTR [eax]
  4a28d4:	83 c6 10             	add    esi,0x10
  4a28d7:	8d 7d e8             	lea    edi,[ebp-0x18]
  4a28da:	e8 81 4e 25 00       	call   0x6f7760
  4a28df:	85 c0                	test   eax,eax
  4a28e1:	0f 84 8d 00 00 00    	je     0x4a2974
  4a28e7:	dd 45 e8             	fld    QWORD PTR [ebp-0x18]
  4a28ea:	c7 45 dc 03 00 00 00 	mov    DWORD PTR [ebp-0x24],0x3
  4a28f1:	dd 5d d4             	fstp   QWORD PTR [ebp-0x2c]
  4a28f4:	8d 45 d4             	lea    eax,[ebp-0x2c]
  4a28f7:	dd 00                	fld    QWORD PTR [eax]
  4a28f9:	dd 5d e8             	fstp   QWORD PTR [ebp-0x18]
  4a28fc:	dd 45 e8             	fld    QWORD PTR [ebp-0x18]
  4a28ff:	db 5d fc             	fistp  DWORD PTR [ebp-0x4]
  4a2902:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4a2905:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  4a2908:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a290a:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4a290f:	e8 dc 27 25 00       	call   0x6f50f0
  4a2914:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a2917:	83 f9 03             	cmp    ecx,0x3
  4a291a:	74 26                	je     0x4a2942
  4a291c:	83 f9 04             	cmp    ecx,0x4
  4a291f:	75 5c                	jne    0x4a297d
  4a2921:	8b 30                	mov    esi,DWORD PTR [eax]
  4a2923:	83 c6 10             	add    esi,0x10
  4a2926:	8d 7d f4             	lea    edi,[ebp-0xc]
  4a2929:	e8 32 4e 25 00       	call   0x6f7760
  4a292e:	85 c0                	test   eax,eax
  4a2930:	74 4b                	je     0x4a297d
  4a2932:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4a2935:	c7 45 dc 03 00 00 00 	mov    DWORD PTR [ebp-0x24],0x3
  4a293c:	dd 5d d4             	fstp   QWORD PTR [ebp-0x2c]
  4a293f:	8d 45 d4             	lea    eax,[ebp-0x2c]
  4a2942:	dd 00                	fld    QWORD PTR [eax]
  4a2944:	dd 5d dc             	fstp   QWORD PTR [ebp-0x24]
  4a2947:	dd 45 dc             	fld    QWORD PTR [ebp-0x24]
  4a294a:	db 5d f8             	fistp  DWORD PTR [ebp-0x8]
  4a294d:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4a2950:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4a2953:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  4a2956:	51                   	push   ecx
  4a2957:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  4a295a:	52                   	push   edx
  4a295b:	50                   	push   eax
  4a295c:	ff 55 0c             	call   DWORD PTR [ebp+0xc]
  4a295f:	5f                   	pop    edi
  4a2960:	5e                   	pop    esi
  4a2961:	33 c0                	xor    eax,eax
  4a2963:	5b                   	pop    ebx
  4a2964:	8b e5                	mov    esp,ebp
  4a2966:	5d                   	pop    ebp
  4a2967:	c3                   	ret
  4a2968:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  4a296f:	e9 41 ff ff ff       	jmp    0x4a28b5
  4a2974:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  4a297b:	eb 8b                	jmp    0x4a2908
  4a297d:	33 c0                	xor    eax,eax
  4a297f:	eb cf                	jmp    0x4a2950

## two_int_marshaller

02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004a2990 <.text+0xa1990>:
  4a2990:	55                   	push   ebp
  4a2991:	8b ec                	mov    ebp,esp
  4a2993:	83 ec 24             	sub    esp,0x24
  4a2996:	a1 78 17 fe 00       	mov    eax,ds:0xfe1778
  4a299b:	53                   	push   ebx
  4a299c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4a299f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a29a1:	56                   	push   esi
  4a29a2:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4a29a5:	57                   	push   edi
  4a29a6:	83 c8 ff             	or     eax,0xffffffff
  4a29a9:	e8 42 27 25 00       	call   0x6f50f0
  4a29ae:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a29b1:	83 f9 03             	cmp    ecx,0x3
  4a29b4:	74 2a                	je     0x4a29e0
  4a29b6:	83 f9 04             	cmp    ecx,0x4
  4a29b9:	0f 85 8e 00 00 00    	jne    0x4a2a4d
  4a29bf:	8b 30                	mov    esi,DWORD PTR [eax]
  4a29c1:	83 c6 10             	add    esi,0x10
  4a29c4:	8d 7d f0             	lea    edi,[ebp-0x10]
  4a29c7:	e8 94 4d 25 00       	call   0x6f7760
  4a29cc:	85 c0                	test   eax,eax
  4a29ce:	74 7d                	je     0x4a2a4d
  4a29d0:	dd 45 f0             	fld    QWORD PTR [ebp-0x10]
  4a29d3:	c7 45 e4 03 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x3
  4a29da:	dd 5d dc             	fstp   QWORD PTR [ebp-0x24]
  4a29dd:	8d 45 dc             	lea    eax,[ebp-0x24]
  4a29e0:	dd 00                	fld    QWORD PTR [eax]
  4a29e2:	dd 5d f0             	fstp   QWORD PTR [ebp-0x10]
  4a29e5:	dd 45 f0             	fld    QWORD PTR [ebp-0x10]
  4a29e8:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4a29eb:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4a29ee:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  4a29f1:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4a29f3:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  4a29f8:	e8 f3 26 25 00       	call   0x6f50f0
  4a29fd:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4a2a00:	83 f9 03             	cmp    ecx,0x3
  4a2a03:	74 26                	je     0x4a2a2b
  4a2a05:	83 f9 04             	cmp    ecx,0x4
  4a2a08:	75 4c                	jne    0x4a2a56
  4a2a0a:	8b 30                	mov    esi,DWORD PTR [eax]
  4a2a0c:	83 c6 10             	add    esi,0x10
  4a2a0f:	8d 7d f8             	lea    edi,[ebp-0x8]
  4a2a12:	e8 49 4d 25 00       	call   0x6f7760
  4a2a17:	85 c0                	test   eax,eax
  4a2a19:	74 3b                	je     0x4a2a56
  4a2a1b:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4a2a1e:	c7 45 e4 03 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x3
  4a2a25:	dd 5d dc             	fstp   QWORD PTR [ebp-0x24]
  4a2a28:	8d 45 dc             	lea    eax,[ebp-0x24]
  4a2a2b:	dd 00                	fld    QWORD PTR [eax]
  4a2a2d:	dd 5d e4             	fstp   QWORD PTR [ebp-0x1c]
  4a2a30:	dd 45 e4             	fld    QWORD PTR [ebp-0x1c]
  4a2a33:	db 5d fc             	fistp  DWORD PTR [ebp-0x4]
  4a2a36:	8b 55 f4             	mov    edx,DWORD PTR [ebp-0xc]
  4a2a39:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4a2a3c:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4a2a3f:	52                   	push   edx
  4a2a40:	50                   	push   eax
  4a2a41:	ff 55 0c             	call   DWORD PTR [ebp+0xc]
  4a2a44:	5f                   	pop    edi
  4a2a45:	5e                   	pop    esi
  4a2a46:	33 c0                	xor    eax,eax
  4a2a48:	5b                   	pop    ebx
  4a2a49:	8b e5                	mov    esp,ebp
  4a2a4b:	5d                   	pop    ebp
  4a2a4c:	c3                   	ret
  4a2a4d:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  4a2a54:	eb 9b                	jmp    0x4a29f1
  4a2a56:	8b 55 f4             	mov    edx,DWORD PTR [ebp-0xc]
  4a2a59:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4a2a5c:	33 c0                	xor    eax,eax
  4a2a5e:	52                   	push   edx
  4a2a5f:	50                   	push   eax
  4a2a60:	ff 55 0c             	call   DWORD PTR [ebp+0xc]
  4a2a63:	5f                   	pop    edi
  4a2a64:	5e                   	pop    esi
  4a2a65:	33 c0                	xor    eax,eax
  4a2a67:	5b                   	pop    ebx
  4a2a68:	8b e5                	mov    esp,ebp
  4a2a6a:	5d                   	pop    ebp
  4a2a6b:	c3                   	ret

# RESEARCH GROUP: controller-input

### P01: Q active writes DWORD controller+58=1 before Q pump pause check
# raw 0x160987; SHA256 d37094ab5b484cae38ed655f4d226cdc0104f74f3870b5b4c0c97b3904f811b9

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00561587 <.text+0x160587>:
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

### P02: Base controller constructor initializes DWORD +58=0
# raw 0x144068; SHA256 da446d0b4914926d1c682c5397507092713984e3dfa718dc5a4907ad9f8a2f3e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00544c68 <.text+0x143c68>:
  544c68:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  544c6b:	c7 07 44 f9 c0 00    	mov    DWORD PTR [edi],0xc0f944
  544c71:	33 db                	xor    ebx,ebx
  544c73:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  544c76:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  544c79:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  544c7c:	c6 47 14 01          	mov    BYTE PTR [edi+0x14],0x1
  544c80:	89 5f 18             	mov    DWORD PTR [edi+0x18],ebx
  544c83:	89 5f 1c             	mov    DWORD PTR [edi+0x1c],ebx
  544c86:	c6 47 20 01          	mov    BYTE PTR [edi+0x20],0x1
  544c8a:	89 5f 24             	mov    DWORD PTR [edi+0x24],ebx
  544c8d:	89 5f 28             	mov    DWORD PTR [edi+0x28],ebx
  544c90:	c6 47 2c 01          	mov    BYTE PTR [edi+0x2c],0x1
  544c94:	89 5f 30             	mov    DWORD PTR [edi+0x30],ebx
  544c97:	89 5f 34             	mov    DWORD PTR [edi+0x34],ebx
  544c9a:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  544c9d:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  544ca0:	89 5f 40             	mov    DWORD PTR [edi+0x40],ebx
  544ca3:	89 5f 44             	mov    DWORD PTR [edi+0x44],ebx
  544ca6:	6a 18                	push   0x18
  544ca8:	89 5f 50             	mov    DWORD PTR [edi+0x50],ebx
  544cab:	e8 b8 c5 34 00       	call   0x891268
  544cb0:	83 c4 04             	add    esp,0x4
  544cb3:	3b c3                	cmp    eax,ebx
  544cb5:	0f 84 61 01 00 00    	je     0x544e1c
  544cbb:	89 47 4c             	mov    DWORD PTR [edi+0x4c],eax
  544cbe:	89 00                	mov    DWORD PTR [eax],eax
  544cc0:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  544cc3:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  544cc6:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  544cc9:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  544ccc:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  544ccf:	c6 40 14 01          	mov    BYTE PTR [eax+0x14],0x1
  544cd3:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  544cd6:	c6 41 15 01          	mov    BYTE PTR [ecx+0x15],0x1
  544cda:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  544cde:	33 d2                	xor    edx,edx
  544ce0:	89 5f 58             	mov    DWORD PTR [edi+0x58],ebx
  544ce3:	89 57 5c             	mov    DWORD PTR [edi+0x5c],edx
  544ce6:	89 5f 60             	mov    DWORD PTR [edi+0x60],ebx

### P03: Single v+2C enabled gate and common5452C0 call
# raw 0x147e90; SHA256 ef1838e2468506fb9f61ce2ee95392e9e91e14af1170bf0b04d6aa19bdaf7471

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548a90 <.text+0x147a90>:
  548a90:	55                   	push   ebp
  548a91:	8b ec                	mov    ebp,esp
  548a93:	6a ff                	push   0xffffffff
  548a95:	68 2e 53 94 00       	push   0x94532e
  548a9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  548aa0:	50                   	push   eax
  548aa1:	51                   	push   ecx
  548aa2:	53                   	push   ebx
  548aa3:	56                   	push   esi
  548aa4:	57                   	push   edi
  548aa5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  548aaa:	33 c5                	xor    eax,ebp
  548aac:	50                   	push   eax
  548aad:	8d 45 f4             	lea    eax,[ebp-0xc]
  548ab0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  548ab6:	8b f9                	mov    edi,ecx
  548ab8:	83 7f 04 00          	cmp    DWORD PTR [edi+0x4],0x0
  548abc:	75 14                	jne    0x548ad2
  548abe:	33 c0                	xor    eax,eax
  548ac0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  548ac3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  548aca:	59                   	pop    ecx
  548acb:	5f                   	pop    edi
  548acc:	5e                   	pop    esi
  548acd:	5b                   	pop    ebx
  548ace:	8b e5                	mov    esp,ebp
  548ad0:	5d                   	pop    ebp
  548ad1:	c3                   	ret
  548ad2:	e8 e9 c7 ff ff       	call   0x5452c0

### P04: Formation v+2C enabled gate and common5452C0 call
# raw 0x147390; SHA256 328774a5976312657fc7503f0ffa992c444291e72333a50d3d50da4d32da4e9e

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00547f90 <.text+0x146f90>:
  547f90:	55                   	push   ebp
  547f91:	8b ec                	mov    ebp,esp
  547f93:	6a ff                	push   0xffffffff
  547f95:	68 9e 77 94 00       	push   0x94779e
  547f9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  547fa0:	50                   	push   eax
  547fa1:	56                   	push   esi
  547fa2:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  547fa7:	33 c5                	xor    eax,ebp
  547fa9:	50                   	push   eax
  547faa:	8d 45 f4             	lea    eax,[ebp-0xc]
  547fad:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  547fb3:	83 79 04 00          	cmp    DWORD PTR [ecx+0x4],0x0
  547fb7:	75 12                	jne    0x547fcb
  547fb9:	33 c0                	xor    eax,eax
  547fbb:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  547fbe:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547fc5:	59                   	pop    ecx
  547fc6:	5e                   	pop    esi
  547fc7:	8b e5                	mov    esp,ebp
  547fc9:	5d                   	pop    ebp
  547fca:	c3                   	ret
  547fcb:	e8 f0 d2 ff ff       	call   0x5452c0

### P05: Tutorial v+2C requires +04 and +DC then calls common5452C0
# raw 0x1480b0; SHA256 83c438daa7d6bfa549a5b4edc6564646b3f610ebcbfbe84bc5472d92529dabfd

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548cb0 <.text+0x147cb0>:
  548cb0:	56                   	push   esi
  548cb1:	8b f1                	mov    esi,ecx
  548cb3:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  548cb7:	75 04                	jne    0x548cbd
  548cb9:	33 c0                	xor    eax,eax
  548cbb:	5e                   	pop    esi
  548cbc:	c3                   	ret
  548cbd:	83 be dc 00 00 00 00 	cmp    DWORD PTR [esi+0xdc],0x0
  548cc4:	74 f3                	je     0x548cb9
  548cc6:	57                   	push   edi
  548cc7:	e8 f4 c5 ff ff       	call   0x5452c0

### P06: 000A send buffer starts at 6 bytes; actor rows later append 5 bytes
# raw 0x144c22; SHA256 5b4655e7d5c038f79961c980d6de94cda07428d81cf0e01b719635158de3abd3

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545822 <.text+0x144822>:
  545822:	33 c0                	xor    eax,eax
  545824:	b8 06 00 00 00       	mov    eax,0x6
  545829:	ba 0a 00 00 00       	mov    edx,0xa
  54582e:	66 89 54 24 2c       	mov    WORD PTR [esp+0x2c],dx
  545833:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  545837:	66 8b 54 24 30       	mov    dx,WORD PTR [esp+0x30]
  54583c:	a3 d0 48 fe 00       	mov    ds:0xfe48d0,eax
  545841:	33 c0                	xor    eax,eax
  545843:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  54584a:	89 0d d0 38 fe 00    	mov    DWORD PTR ds:0xfe38d0,ecx
  545850:	66 89 15 d4 38 fe 00 	mov    WORD PTR ds:0xfe38d4,dx
  545857:	66 89 44 24 34       	mov    WORD PTR [esp+0x34],ax

### P07: Three controlled-slot rows: +58 clears WORD control and preserves original direction
# raw 0x144c95; SHA256 a3f08348645e84199bb9f0cd6ab031c93fe34a3b0d33a9e0e0775d92a6692a39

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545895 <.text+0x144895>:
  545895:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  545899:	8d 14 7f             	lea    edx,[edi+edi*2]
  54589c:	8b 74 90 0c          	mov    esi,DWORD PTR [eax+edx*4+0xc]
  5458a0:	8d 04 90             	lea    eax,[eax+edx*4]
  5458a3:	85 f6                	test   esi,esi
  5458a5:	0f 84 e5 00 00 00    	je     0x545990
  5458ab:	80 78 14 00          	cmp    BYTE PTR [eax+0x14],0x0
  5458af:	0f 84 db 00 00 00    	je     0x545990
  5458b5:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  5458b9:	8b 11                	mov    edx,DWORD PTR [ecx]
  5458bb:	8a 9e b0 00 00 00    	mov    bl,BYTE PTR [esi+0xb0]
  5458c1:	8b 52 48             	mov    edx,DWORD PTR [edx+0x48]
  5458c4:	8d 44 24 34          	lea    eax,[esp+0x34]
  5458c8:	50                   	push   eax
  5458c9:	57                   	push   edi
  5458ca:	88 5c 24 20          	mov    BYTE PTR [esp+0x20],bl
  5458ce:	ff d2                	call   edx
  5458d0:	84 c0                	test   al,al
  5458d2:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5458d6:	74 66                	je     0x54593e
  5458d8:	83 78 58 00          	cmp    DWORD PTR [eax+0x58],0x0
  5458dc:	74 1d                	je     0x5458fb
  5458de:	33 c0                	xor    eax,eax
  5458e0:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  5458e5:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5458e9:	88 5c 24 38          	mov    BYTE PTR [esp+0x38],bl
  5458ed:	8b 16                	mov    edx,DWORD PTR [esi]
  5458ef:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  5458f2:	50                   	push   eax
  5458f3:	8b ce                	mov    ecx,esi
  5458f5:	ff d2                	call   edx
  5458f7:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5458fb:	8a 4c 24 38          	mov    cl,BYTE PTR [esp+0x38]
  5458ff:	85 ff                	test   edi,edi
  545901:	75 0a                	jne    0x54590d
  545903:	8b 54 24 34          	mov    edx,DWORD PTR [esp+0x34]
  545907:	89 50 68             	mov    DWORD PTR [eax+0x68],edx
  54590a:	88 48 6c             	mov    BYTE PTR [eax+0x6c],cl
  54590d:	66 8b 46 04          	mov    ax,WORD PTR [esi+0x4]
  545911:	66 89 44 24 34       	mov    WORD PTR [esp+0x34],ax
  545916:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  54591b:	8d 50 05             	lea    edx,[eax+0x5]
  54591e:	81 fa 00 10 00 00    	cmp    edx,0x1000
  545924:	77 6a                	ja     0x545990
  545926:	8b 54 24 34          	mov    edx,DWORD PTR [esp+0x34]
  54592a:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  545930:	89 10                	mov    DWORD PTR [eax],edx
  545932:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  545935:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5
  54593c:	eb 52                	jmp    0x545990
  54593e:	83 78 58 00          	cmp    DWORD PTR [eax+0x58],0x0
  545942:	74 4c                	je     0x545990
  545944:	b9 00 80 00 00       	mov    ecx,0x8000
  545949:	66 85 48 6a          	test   WORD PTR [eax+0x6a],cx
  54594d:	74 41                	je     0x545990
  54594f:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  545953:	33 d2                	xor    edx,edx
  545955:	66 89 54 24 36       	mov    WORD PTR [esp+0x36],dx
  54595a:	88 5c 24 38          	mov    BYTE PTR [esp+0x38],bl
  54595e:	8b 06                	mov    eax,DWORD PTR [esi]
  545960:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  545963:	51                   	push   ecx
  545964:	8b ce                	mov    ecx,esi
  545966:	ff d2                	call   edx
  545968:	85 ff                	test   edi,edi
  54596a:	75 12                	jne    0x54597e
  54596c:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  545970:	8b 4c 24 34          	mov    ecx,DWORD PTR [esp+0x34]
  545974:	8a 54 24 38          	mov    dl,BYTE PTR [esp+0x38]
  545978:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx
  54597b:	88 50 6c             	mov    BYTE PTR [eax+0x6c],dl
  54597e:	66 8b 46 04          	mov    ax,WORD PTR [esi+0x4]
  545982:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  545986:	66 89 44 24 34       	mov    WORD PTR [esp+0x34],ax
  54598b:	e8 20 18 00 00       	call   0x5471b0
  545990:	47                   	inc    edi
  545991:	83 ff 03             	cmp    edi,0x3
  545994:	0f 8c fb fe ff ff    	jl     0x545895

### P08: Additional actor rows: same control-word suppression
# raw 0x144e99; SHA256 8b5e14a28389fbdb75e641e3c57880b1a1543fd76a6d690a62e2a4ec611656f2

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545a99 <.text+0x144a99>:
  545a99:	85 c0                	test   eax,eax
  545a9b:	74 0f                	je     0x545aac
  545a9d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  545aa1:	74 33                	je     0x545ad6
  545aa3:	33 c0                	xor    eax,eax
  545aa5:	66 89 44 24 2e       	mov    WORD PTR [esp+0x2e],ax
  545aaa:	eb 18                	jmp    0x545ac4
  545aac:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  545ab0:	74 68                	je     0x545b1a
  545ab2:	b8 00 80 00 00       	mov    eax,0x8000
  545ab7:	66 85 47 6a          	test   WORD PTR [edi+0x6a],ax
  545abb:	74 5d                	je     0x545b1a
  545abd:	33 c9                	xor    ecx,ecx
  545abf:	66 89 4c 24 2e       	mov    WORD PTR [esp+0x2e],cx
  545ac4:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  545ac8:	88 5c 24 30          	mov    BYTE PTR [esp+0x30],bl
  545acc:	8b 16                	mov    edx,DWORD PTR [esi]
  545ace:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  545ad1:	50                   	push   eax
  545ad2:	8b ce                	mov    ecx,esi
  545ad4:	ff d2                	call   edx
  545ad6:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  545adb:	8a 4c 24 30          	mov    cl,BYTE PTR [esp+0x30]
  545adf:	75 0a                	jne    0x545aeb
  545ae1:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  545ae5:	89 47 68             	mov    DWORD PTR [edi+0x68],eax
  545ae8:	88 4f 6c             	mov    BYTE PTR [edi+0x6c],cl
  545aeb:	66 8b 56 04          	mov    dx,WORD PTR [esi+0x4]
  545aef:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  545af4:	66 89 54 24 2c       	mov    WORD PTR [esp+0x2c],dx
  545af9:	8d 50 05             	lea    edx,[eax+0x5]
  545afc:	81 fa 00 10 00 00    	cmp    edx,0x1000
  545b02:	77 16                	ja     0x545b1a
  545b04:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  545b08:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  545b0e:	89 10                	mov    DWORD PTR [eax],edx
  545b10:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  545b13:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5

### P09: Nonempty 000A buffer may still send; reset DWORD +58 at normal exit
# raw 0x144f38; SHA256 7359c8db0ff0131ed9f939d6f966521fe87a3a131a643913740e3d3270abbcf7

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545b38 <.text+0x144b38>:
  545b38:	83 3d d0 48 fe 00 06 	cmp    DWORD PTR ds:0xfe48d0,0x6
  545b3f:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  545b43:	76 2e                	jbe    0x545b73
  545b45:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  545b49:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  545b4f:	ff 0d b0 a7 fb 00    	dec    DWORD PTR ds:0xfba7b0
  545b55:	c7 46 74 00 00 00 00 	mov    DWORD PTR [esi+0x74],0x0
  545b5c:	89 46 64             	mov    DWORD PTR [esi+0x64],eax
  545b5f:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  545b64:	8b 11                	mov    edx,DWORD PTR [ecx]
  545b66:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  545b69:	50                   	push   eax
  545b6a:	68 d0 38 fe 00       	push   0xfe38d0
  545b6f:	6a 00                	push   0x0
  545b71:	ff d2                	call   edx
  545b73:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  545b77:	33 c0                	xor    eax,eax
  545b79:	66 89 46 5c          	mov    WORD PTR [esi+0x5c],ax
  545b7d:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  545b81:	74 07                	je     0x545b8a
  545b83:	c7 43 58 00 00 00 00 	mov    DWORD PTR [ebx+0x58],0x0
  545b8a:	33 c0                	xor    eax,eax
  545b8c:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  545b90:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  545b97:	59                   	pop    ecx
  545b98:	5f                   	pop    edi
  545b99:	5e                   	pop    esi
  545b9a:	5b                   	pop    ebx
  545b9b:	8b e5                	mov    esp,ebp
  545b9d:	5d                   	pop    ebp
  545b9e:	c3                   	ret

### P10: Common mapper obtains input action value and merges low15 bits
# raw 0x145654; SHA256 6cb31fd539a758ae3a0b326e8f68d0a7b396d1716d6a24d7930dd56a7c4c3fd5

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00546254 <.text+0x145254>:
  546254:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  546258:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  54625c:	51                   	push   ecx
  54625d:	8d 54 24 20          	lea    edx,[esp+0x20]
  546261:	52                   	push   edx
  546262:	57                   	push   edi
  546263:	e8 18 05 00 00       	call   0x546780
  546268:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  54626c:	e8 ef e6 ef ff       	call   0x444960
  546271:	80 b8 ef 07 00 00 01 	cmp    BYTE PTR [eax+0x7ef],0x1
  546278:	75 0c                	jne    0x546286
  54627a:	b8 00 01 00 00       	mov    eax,0x100
  54627f:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  546284:	eb 09                	jmp    0x54628f
  546286:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  54628a:	66 85 c0             	test   ax,ax
  54628d:	74 13                	je     0x5462a2
  54628f:	66 8b 4b 02          	mov    cx,WORD PTR [ebx+0x2]
  546293:	66 33 c8             	xor    cx,ax
  546296:	ba ff 7f 00 00       	mov    edx,0x7fff
  54629b:	66 23 ca             	and    cx,dx
  54629e:	66 31 4b 02          	xor    WORD PTR [ebx+0x2],cx

### P11: Movement step uses actor position/speed and sets or clears 0x8000
# raw 0x145774; SHA256 e1fc0076c865138fe53b7916e6bcdbb5faaf1d07857f753bd3a5f3f2f4733036

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00546374 <.text+0x145374>:
  546374:	8a 4c 24 1c          	mov    cl,BYTE PTR [esp+0x1c]
  546378:	88 4b 04             	mov    BYTE PTR [ebx+0x4],cl
  54637b:	39 44 24 28          	cmp    DWORD PTR [esp+0x28],eax
  54637f:	0f 84 ea 00 00 00    	je     0x54646f
  546385:	ba ff 7f 00 00       	mov    edx,0x7fff
  54638a:	66 85 53 02          	test   WORD PTR [ebx+0x2],dx
  54638e:	0f 85 db 00 00 00    	jne    0x54646f
  546394:	8b 07                	mov    eax,DWORD PTR [edi]
  546396:	8b 50 60             	mov    edx,DWORD PTR [eax+0x60]
  546399:	8b cf                	mov    ecx,edi
  54639b:	8d b7 a0 00 00 00    	lea    esi,[edi+0xa0]
  5463a1:	ff d2                	call   edx
  5463a3:	dc 0d 70 5a c5 00    	fmul   QWORD PTR ds:0xc55a70
  5463a9:	0f b6 43 04          	movzx  eax,BYTE PTR [ebx+0x4]
  5463ad:	51                   	push   ecx
  5463ae:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  5463b2:	8b ce                	mov    ecx,esi
  5463b4:	d9 44 24 2c          	fld    DWORD PTR [esp+0x2c]
  5463b8:	d9 1c 24             	fstp   DWORD PTR [esp]
  5463bb:	50                   	push   eax
  5463bc:	e8 6f fb ff ff       	call   0x545f30
  5463c1:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5463c5:	33 d2                	xor    edx,edx
  5463c7:	89 51 70             	mov    DWORD PTR [ecx+0x70],edx
  5463ca:	3b c2                	cmp    eax,edx
  5463cc:	75 43                	jne    0x546411
  5463ce:	39 51 74             	cmp    DWORD PTR [ecx+0x74],edx
  5463d1:	75 3e                	jne    0x546411
  5463d3:	39 97 a8 03 00 00    	cmp    DWORD PTR [edi+0x3a8],edx
  5463d9:	74 06                	je     0x5463e1
  5463db:	89 97 a8 03 00 00    	mov    DWORD PTR [edi+0x3a8],edx
  5463e1:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  5463e7:	3b c2                	cmp    eax,edx
  5463e9:	74 1b                	je     0x546406
  5463eb:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  5463ee:	74 16                	je     0x546406
  5463f0:	0f b7 43 02          	movzx  eax,WORD PTR [ebx+0x2]
  5463f4:	a9 ff 7f 00 00       	test   eax,0x7fff
  5463f9:	75 0b                	jne    0x546406
  5463fb:	0d 00 80 00 00       	or     eax,0x8000
  546400:	66 89 43 02          	mov    WORD PTR [ebx+0x2],ax
  546404:	eb 4d                	jmp    0x546453
  546406:	b8 ff 7f 00 00       	mov    eax,0x7fff
  54640b:	66 21 43 02          	and    WORD PTR [ebx+0x2],ax
  54640f:	eb 42                	jmp    0x546453

### P12: Alternate movement step and 0x8000 flag path
# raw 0x145811; SHA256 88be6b1db738031ebee5a5f36c27b05f6c528c8bda9a136794e913f08759797b

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00546411 <.text+0x145411>:
  546411:	8b 17                	mov    edx,DWORD PTR [edi]
  546413:	8d 43 04             	lea    eax,[ebx+0x4]
  546416:	50                   	push   eax
  546417:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  54641b:	50                   	push   eax
  54641c:	8b 42 60             	mov    eax,DWORD PTR [edx+0x60]
  54641f:	8b cf                	mov    ecx,edi
  546421:	ff d0                	call   eax
  546423:	51                   	push   ecx
  546424:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  546428:	d9 1c 24             	fstp   DWORD PTR [esp]
  54642b:	8b 51 74             	mov    edx,DWORD PTR [ecx+0x74]
  54642e:	52                   	push   edx
  54642f:	e8 8c 00 00 00       	call   0x5464c0
  546434:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  546438:	89 41 70             	mov    DWORD PTR [ecx+0x70],eax
  54643b:	b8 00 80 00 00       	mov    eax,0x8000
  546440:	66 09 43 02          	or     WORD PTR [ebx+0x2],ax
  546444:	83 79 70 00          	cmp    DWORD PTR [ecx+0x70],0x0
  546448:	74 09                	je     0x546453
  54644a:	6a 01                	push   0x1
  54644c:	8b f7                	mov    esi,edi
  54644e:	e8 6d 2c f8 ff       	call   0x4c90c0
  546453:	0f b6 43 04          	movzx  eax,BYTE PTR [ebx+0x4]
  546457:	8b 17                	mov    edx,DWORD PTR [edi]
  546459:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  54645c:	50                   	push   eax
  54645d:	8b cf                	mov    ecx,edi
  54645f:	ff d2                	call   edx
  546461:	8a 44 24 30          	mov    al,BYTE PTR [esp+0x30]
  546465:	38 43 04             	cmp    BYTE PTR [ebx+0x4],al
  546468:	74 05                	je     0x54646f
  54646a:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  54646f:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  546473:	c7 41 74 00 00 00 00 	mov    DWORD PTR [ecx+0x74],0x0
  54647a:	eb 09                	jmp    0x546485
  54647c:	ba ff 7f 00 00       	mov    edx,0x7fff
  546481:	66 21 53 02          	and    WORD PTR [ebx+0x2],dx

### P13: Input producer combines controller+5C and short/long press result
# raw 0x145b80; SHA256 158f9179195b408100737c12ea54643a378138bcd05e58add69db974eca179bc

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00546780 <.text+0x145780>:
  546780:	55                   	push   ebp
  546781:	8b ec                	mov    ebp,esp
  546783:	83 e4 f8             	and    esp,0xfffffff8
  546786:	51                   	push   ecx
  546787:	53                   	push   ebx
  546788:	56                   	push   esi
  546789:	57                   	push   edi
  54678a:	8b f8                	mov    edi,eax
  54678c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  54678f:	8a 00                	mov    al,BYTE PTR [eax]
  546791:	0f b7 5f 5c          	movzx  ebx,WORD PTR [edi+0x5c]
  546795:	8d 77 40             	lea    esi,[edi+0x40]
  546798:	88 44 24 0d          	mov    BYTE PTR [esp+0xd],al
  54679c:	88 44 24 0e          	mov    BYTE PTR [esp+0xe],al
  5467a0:	88 44 24 0f          	mov    BYTE PTR [esp+0xf],al
  5467a4:	e8 97 0a 00 00       	call   0x547240
  5467a9:	85 c0                	test   eax,eax
  5467ab:	74 1b                	je     0x5467c8
  5467ad:	83 e8 02             	sub    eax,0x2
  5467b0:	74 13                	je     0x5467c5
  5467b2:	48                   	dec    eax
  5467b3:	74 08                	je     0x5467bd
  5467b5:	48                   	dec    eax
  5467b6:	75 10                	jne    0x5467c8
  5467b8:	83 cb 40             	or     ebx,0x40
  5467bb:	eb 0b                	jmp    0x5467c8
  5467bd:	81 cb 80 00 00 00    	or     ebx,0x80
  5467c3:	eb 03                	jmp    0x5467c8
  5467c5:	83 cb 08             	or     ebx,0x8
  5467c8:	8d 4c 24 0d          	lea    ecx,[esp+0xd]
  5467cc:	51                   	push   ecx
  5467cd:	e8 7e 00 00 00       	call   0x546850
  5467d2:	8b f0                	mov    esi,eax
  5467d4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5467d7:	56                   	push   esi
  5467d8:	8d 54 24 12          	lea    edx,[esp+0x12]
  5467dc:	52                   	push   edx
  5467dd:	50                   	push   eax
  5467de:	8b c7                	mov    eax,edi
  5467e0:	e8 6b 03 00 00       	call   0x546b50
  5467e5:	8d 4c 24 0f          	lea    ecx,[esp+0xf]
  5467e9:	51                   	push   ecx
  5467ea:	8b f8                	mov    edi,eax
  5467ec:	e8 5f 05 00 00       	call   0x546d50
  5467f1:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  5467f4:	66 89 1a             	mov    WORD PTR [edx],bx
  5467f7:	85 f6                	test   esi,esi
  5467f9:	74 16                	je     0x546811
  5467fb:	8a 4c 24 0d          	mov    cl,BYTE PTR [esp+0xd]
  5467ff:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  546802:	0b c7                	or     eax,edi
  546804:	88 0a                	mov    BYTE PTR [edx],cl
  546806:	0b c6                	or     eax,esi
  546808:	5f                   	pop    edi
  546809:	5e                   	pop    esi
  54680a:	5b                   	pop    ebx
  54680b:	8b e5                	mov    esp,ebp
  54680d:	5d                   	pop    ebp
  54680e:	c2 0c 00             	ret    0xc
  546811:	85 ff                	test   edi,edi
  546813:	74 16                	je     0x54682b
  546815:	8a 4c 24 0e          	mov    cl,BYTE PTR [esp+0xe]
  546819:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  54681c:	0b c7                	or     eax,edi
  54681e:	88 0a                	mov    BYTE PTR [edx],cl
  546820:	0b c6                	or     eax,esi
  546822:	5f                   	pop    edi
  546823:	5e                   	pop    esi
  546824:	5b                   	pop    ebx
  546825:	8b e5                	mov    esp,ebp
  546827:	5d                   	pop    ebp
  546828:	c2 0c 00             	ret    0xc
  54682b:	85 c0                	test   eax,eax
  54682d:	74 09                	je     0x546838
  54682f:	8a 4c 24 0f          	mov    cl,BYTE PTR [esp+0xf]
  546833:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  546836:	88 0a                	mov    BYTE PTR [edx],cl
  546838:	0b c7                	or     eax,edi
  54683a:	5f                   	pop    edi
  54683b:	0b c6                	or     eax,esi
  54683d:	5e                   	pop    esi
  54683e:	5b                   	pop    ebx
  54683f:	8b e5                	mov    esp,ebp
  546841:	5d                   	pop    ebp
  546842:	c2 0c 00             	ret    0xc
  546845:	cc                   	int3
  546846:	cc                   	int3
  546847:	cc                   	int3
  546848:	cc                   	int3
  546849:	cc                   	int3
  54684a:	cc                   	int3
  54684b:	cc                   	int3
  54684c:	cc                   	int3
  54684d:	cc                   	int3
  54684e:	cc                   	int3
  54684f:	cc                   	int3

### P14: Single v+48 delegates to common mapper under actor/mode conditions
# raw 0x147e20; SHA256 e31c2e536ebdf8f14b340529a6c9ea228e36b8ffe8a80880aabed7c7b2f83550

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548a20 <.text+0x147a20>:
  548a20:	55                   	push   ebp
  548a21:	8b ec                	mov    ebp,esp
  548a23:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  548a26:	85 c0                	test   eax,eax
  548a28:	74 58                	je     0x548a82
  548a2a:	83 b8 8c 03 00 00 10 	cmp    DWORD PTR [eax+0x38c],0x10
  548a31:	74 19                	je     0x548a4c
  548a33:	83 b9 a4 00 00 00 00 	cmp    DWORD PTR [ecx+0xa4],0x0
  548a3a:	75 10                	jne    0x548a4c
  548a3c:	c7 81 bc 00 00 00 00 	mov    DWORD PTR [ecx+0xbc],0x0
  548a43:	00 00 00 
  548a46:	5d                   	pop    ebp
  548a47:	e9 b4 d6 ff ff       	jmp    0x546100

### P15: Formation v+48 leader to common mapper; followers to5480E0
# raw 0x1474a0; SHA256 8ea4d4eba38849e7c3822946a1d418edef6ce2a273a72354191003a02fbdf7d0

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005480a0 <.text+0x1470a0>:
  5480a0:	55                   	push   ebp
  5480a1:	8b ec                	mov    ebp,esp
  5480a3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5480a6:	8d 54 40 03          	lea    edx,[eax+eax*2+0x3]
  5480aa:	83 3c 91 00          	cmp    DWORD PTR [ecx+edx*4],0x0
  5480ae:	75 06                	jne    0x5480b6
  5480b0:	32 c0                	xor    al,al
  5480b2:	5d                   	pop    ebp
  5480b3:	c2 08 00             	ret    0x8
  5480b6:	85 c0                	test   eax,eax
  5480b8:	74 10                	je     0x5480ca
  5480ba:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5480bd:	52                   	push   edx
  5480be:	51                   	push   ecx
  5480bf:	8b c8                	mov    ecx,eax
  5480c1:	e8 1a 00 00 00       	call   0x5480e0
  5480c6:	5d                   	pop    ebp
  5480c7:	c2 08 00             	ret    0x8
  5480ca:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5480cd:	50                   	push   eax
  5480ce:	6a 00                	push   0x0
  5480d0:	e8 2b e0 ff ff       	call   0x546100
  5480d5:	5d                   	pop    ebp
  5480d6:	c2 08 00             	ret    0x8

### P16: Tutorial v+48 tailcalls common546100
# raw 0x148110; SHA256 2db047dff8f757caecea963505262bb1d2d534755da3780d6378646963d2fdfc

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548d10 <.text+0x147d10>:
  548d10:	55                   	push   ebp
  548d11:	8b ec                	mov    ebp,esp
  548d13:	5d                   	pop    ebp
  548d14:	e9 e7 d3 ff ff       	jmp    0x546100

### P17: Append a 5-byte row including a neutral stop row
# raw 0x1465b0; SHA256 0eb69596412170513d36ac12fb2ac8db69644574baea61cb10f50c81479d46f7

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005471b0 <.text+0x1461b0>:
  5471b0:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  5471b5:	8d 50 05             	lea    edx,[eax+0x5]
  5471b8:	81 fa 00 10 00 00    	cmp    edx,0x1000
  5471be:	77 17                	ja     0x5471d7
  5471c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  5471c2:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  5471c8:	89 10                	mov    DWORD PTR [eax],edx
  5471ca:	8a 49 04             	mov    cl,BYTE PTR [ecx+0x4]
  5471cd:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  5471d0:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5
  5471d7:	c3                   	ret

### P18: Common method disabled fast return bypasses normal reset
# raw 0x1446ec; SHA256 9ecb711c5ad26980c6360379399b69f4042f099241a8051a681331f492251695

/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005452ec <.text+0x1442ec>:
  5452ec:	8b f1                	mov    esi,ecx
  5452ee:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5452f2:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  5452f6:	0f 84 8e 08 00 00    	je     0x545b8a
