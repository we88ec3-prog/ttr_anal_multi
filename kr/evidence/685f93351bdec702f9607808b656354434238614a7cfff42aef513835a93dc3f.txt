# T16-11 — KR QuestInfo vs QuestTalk parser entry and independent error states

- Analysis timestamp (Asia/Taipei): `20261028-014919`
- KR source: `Tartaros.bin`, `12472320` bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` (directly recalculated)
- PE `.text`: VA `0x00401000` ↔ raw `0x400`, `.rdata`: `0x00BD2000` ↔ `0x007D0600`; image base `0x00400000`.
- Baseline GitHub main: `c5f888ff4f1a2b55215bfebbe4901f71f3c6408e` (verified at start); T16-1..T16-8 are earlier baselines, not redefined here.
- Method: read-only BIN + GNU objdump, bounded x86 code ranges, constant xrefs; native semantics only where instruction flow supports. No client execution, DLL injection, patch, or server emulation.
- TC baseline: manifest SHA `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`, actual TC binary unavailable.

## Goal

Compare the two native XML loader beginnings without treating two parser names as proof of mainline state semantics. Both files are **referenced** by the client; actual XML bytes remain unprovided.

## Two concrete entrypoints and error branches

- QuestInfo loader `0x00504740`: `0x0050478B` places `0x00C0DB48` (`Table/QuestInfo.xml`) in `ecx`, calls `0x0072EE30`; `0x005047C6` calls `0x0072F110`; a nonzero local byte branches into a cleanup and `xor eax,eax` -> `0x005054D8`. On success at `0x00504831`, pushes `0x00C0DB70` to `0x0072E2E0` for a root lookup.
- QuestTalk loader `0x00505570`: `0x005055B8` places `0x00C0DB5C` (`Table/QuestTalk.xml`) in `ecx`, calls `0x0072EE30`; `0x005055E7` calls `0x0072F110`; a nonzero local byte triggers cleanup and return-zero path to `0x0050582D`. On success at `0x00505641`, pushes `0x00C0DC44` to `0x0072E2E0`.
- Both are independent native callsites, but they share generic helper routines. Their **root string identifiers differ**, and the program doesn't establish equivalence of schema or Quest ID domain merely from names.

## First code range: QuestInfo
```asm
00504780 <.text+0x103780>:
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
```

## Second code range: QuestTalk
```asm
005055b0 <.text+0x1045b0>:
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  505631:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  505635:	e8 06 8a 22 00       	call   0x72e040
  50563a:	33 c0                	xor    eax,eax
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  505641:	68 44 dc c0 00       	push   0xc0dc44
  505646:	8d 44 24 28          	lea    eax,[esp+0x28]
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50          	push   0xc0dc50
```

## Functional boundaries / known unknowns

Resource path `Table/...` is not XML content. We have not decoded quest IDs, NPC IDs, dialogue branch keys, stage IDs, reward tables, or server validation. A loader's failure return is not evidence that failing a quest should reset tutorial progress. T16 should record only business mappings discovered in actual content; lower-level file access remains shared resource owner. TC native module remains absent.


## Result limitations and GitHub status at authoring

- Native-confirmed means exact reads/branches/calls in the supplied KR BIN; inferred domain names remain provisional. No actual original XML/Lua content available.
- No read-only evidence here proves server authoritative rules, NPC dialogue flow, tutorial step list, first mainline quest ID, or TC correspondence.
- GitHub publication follows user approval only after T16-12; recorded commit references should be confirmed from remote separately.