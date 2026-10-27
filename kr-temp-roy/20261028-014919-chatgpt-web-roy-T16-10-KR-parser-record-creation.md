# T16-10 — KR parser record creation: object allocation, branch and global index insertion

- Analysis timestamp (Asia/Taipei): `20261028-014919`
- KR source: `Tartaros.bin`, `12472320` bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` (directly recalculated)
- PE `.text`: VA `0x00401000` ↔ raw `0x400`, `.rdata`: `0x00BD2000` ↔ `0x007D0600`; image base `0x00400000`.
- Baseline GitHub main: `c5f888ff4f1a2b55215bfebbe4901f71f3c6408e` (verified at start); T16-1..T16-8 are earlier baselines, not redefined here.
- Method: read-only BIN + GNU objdump, bounded x86 code ranges, constant xrefs; native semantics only where instruction flow supports. No client execution, DLL injection, patch, or server emulation.
- TC baseline: manifest SHA `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`, actual TC binary unavailable.

## Purpose

Trace how the candidate XML/event parser transfers extracted attributes to a record and a tree, separating local XML content from persistent game state. The path at `0x0053FCF5..0x0053FE23` is newly inspected, including the vtable call, allocation size, and container assignment.

## Key source -> allocated object -> vector fields -> ordered insert

1. At `0x0053FCEA`, `[esi+0x18]` selects a linked item, and at `0x0053FCF5..0x0053FCFC`, a vtable `+0x14` callback returns a value or node. This is a polymorphic parser callback; vtable owner is **unknown**.
2. `0x0053FD08` uses key string pointer `0x00BED1D0` in a lookup via `0x007300A0`. Successful value is converted through `0x008917B4`, otherwise local scalar `0`. This is a data extraction, not a network response.
3. `0x0053FD3B: push 0x40`, `call 0x00891268`: **0x40 bytes allocated**, with explicit zero-initialized fields `+0x00,+0x04,+0x08,+0x10,+0x14,+0x18,+0x20,+0x24,+0x28,+0x30,+0x34,+0x38`. Any claim that structure equals persisted quest step requires separate support.
4. `0x0053FD76..0x0053FDF2` accesses FOUR strings (`0x00C0F4E4` plus HasQuest / HasCompletableQuest / HasScenario); helper `0x0053FEB0` populates record base and `+0x10/+0x20/+0x30` respectively. Previous notes emphasized three, now explicitly retain the fourth *unlabeled in this analysis*.
5. `0x0053FE03..0x0053FE17`: tree node allocation `0x0057EF20` and insertion via `0x0057E850`; the global structure is `0x00FE18DC` (confirmed address). But operation's key and later runtime consumer have not been tied to a canonical quest ID.

## Direct disassembly: record creation and fields

```asm
0053fcea <.text+0x13ecea>:
  53fcea:	8b 5e 18             	mov    ebx,DWORD PTR [esi+0x18]
  53fced:	85 db                	test   ebx,ebx
  53fcef:	0f 84 34 01 00 00    	je     0x53fe29
  53fcf5:	8b 13                	mov    edx,DWORD PTR [ebx]
  53fcf7:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  53fcfa:	8b cb                	mov    ecx,ebx
  53fcfc:	ff d0                	call   eax
  53fcfe:	33 f6                	xor    esi,esi
  53fd00:	3b c6                	cmp    eax,esi
  53fd02:	0f 84 16 01 00 00    	je     0x53fe1e
  53fd08:	68 d0 d1 be 00       	push   0xbed1d0
  53fd0d:	8d 78 44             	lea    edi,[eax+0x44]
  53fd10:	e8 8b 03 1f 00       	call   0x7300a0
  53fd15:	3b c6                	cmp    eax,esi
  53fd17:	74 1e                	je     0x53fd37
  53fd19:	83 c0 30             	add    eax,0x30
  53fd1c:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53fd20:	72 02                	jb     0x53fd24
  53fd22:	8b 00                	mov    eax,DWORD PTR [eax]
  53fd24:	3b c6                	cmp    eax,esi
  53fd26:	74 0f                	je     0x53fd37
  53fd28:	50                   	push   eax
  53fd29:	e8 86 1a 35 00       	call   0x8917b4
  53fd2e:	83 c4 04             	add    esp,0x4
  53fd31:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  53fd35:	eb 04                	jmp    0x53fd3b
  53fd37:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  53fd3b:	6a 40                	push   0x40
  53fd3d:	e8 26 15 35 00       	call   0x891268
  53fd42:	83 c4 04             	add    esp,0x4
  53fd45:	3b c6                	cmp    eax,esi
  53fd47:	74 29                	je     0x53fd72
  53fd49:	89 30                	mov    DWORD PTR [eax],esi
  53fd4b:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  53fd4e:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  53fd51:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  53fd54:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  53fd57:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  53fd5a:	89 70 20             	mov    DWORD PTR [eax+0x20],esi
  53fd5d:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
  53fd60:	89 70 28             	mov    DWORD PTR [eax+0x28],esi
  53fd63:	89 70 30             	mov    DWORD PTR [eax+0x30],esi
  53fd66:	89 70 34             	mov    DWORD PTR [eax+0x34],esi
  53fd69:	89 70 38             	mov    DWORD PTR [eax+0x38],esi
  53fd6c:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  53fd70:	eb 04                	jmp    0x53fd76
  53fd72:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  53fd76:	68 e4 f4 c0 00       	push   0xc0f4e4
  53fd7b:	8b c3                	mov    eax,ebx
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd82:	8b f8                	mov    edi,eax
  53fd84:	68 ec f4 c0 00       	push   0xc0f4ec
  53fd89:	8b c3                	mov    eax,ebx
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd90:	8b f0                	mov    esi,eax
  53fd92:	68 f8 f4 c0 00       	push   0xc0f4f8
  53fd97:	8b c3                	mov    eax,ebx
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fd9e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  53fda2:	68 0c f5 c0 00       	push   0xc0f50c
  53fda7:	8b c3                	mov    eax,ebx
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdae:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe ff ff    	jne    0x53fcf5
  53fe29:	bb           	mov    ebx,0x10
```

## Evidence boundaries

This path is an **original KR client data parser**, not proven authoritative task-state persistence. A 0x40 allocation is confirmed, not a 0x40 server packet. `+0x10/+0x20/+0x30` belong to a local output record, not necessarily a T15 persistent field. `0xFE18DC` is also read from a different runtime path (T16-9). Data type names remain placeholders pending symbol evidence.


## Result limitations and GitHub status at authoring

- Native-confirmed means exact reads/branches/calls in the supplied KR BIN; inferred domain names remain provisional. No actual original XML/Lua content available.
- No read-only evidence here proves server authoritative rules, NPC dialogue flow, tutorial step list, first mainline quest ID, or TC correspondence.
- GitHub publication follows user approval only after T16-12; recorded commit references should be confirmed from remote separately.