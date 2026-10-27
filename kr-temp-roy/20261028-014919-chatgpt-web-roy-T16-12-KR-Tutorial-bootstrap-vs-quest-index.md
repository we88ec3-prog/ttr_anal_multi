# T16-12 — KR Tutorial bootstrap vs quest index: cross-task proof matrix

- Analysis timestamp (Asia/Taipei): `20261028-014919`
- KR source: `Tartaros.bin`, `12472320` bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` (directly recalculated)
- PE `.text`: VA `0x00401000` ↔ raw `0x400`, `.rdata`: `0x00BD2000` ↔ `0x007D0600`; image base `0x00400000`.
- Baseline GitHub main: `c5f888ff4f1a2b55215bfebbe4901f71f3c6408e` (verified at start); T16-1..T16-8 are earlier baselines, not redefined here.
- Method: read-only BIN + GNU objdump, bounded x86 code ranges, constant xrefs; native semantics only where instruction flow supports. No client execution, DLL injection, patch, or server emulation.
- TC baseline: manifest SHA `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`, actual TC binary unavailable.

## Goal and findings

Integrate newly observed index consumers and record-parser controls with existing `Tutorial_EntryPoint` native call chain. The decisive finding is **negative but actionable**: no direct native transition has yet been shown from Tutorial function return to persisted quest state or from the global FE18DC index to the first mainline task ID.

## Tutorial call is not conditional on the FE-related flag

`0x004A8B33` tests `[0x00FBA798]` against zero. The zero branch calls an object virtual method `vtable+0x10` with a local temporary record. Both paths reach `0x004A8B5D` and invoke `Event/TutorialMain.lua` (`0x006F4A50`) and `Tutorial_EntryPoint` (`0x006F4DD0`). Thus **that branch alone cannot be equated to a tutorial complete/skip decision**. The Lua script may contain conditions not visible until source content is obtained.

```asm
004a8b33 <.text+0xa7b33>:
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
```

## Current proof chain

```text
T03/T04 existing actor [identity available through other Task, exact tutorial input unknown]
  -> (caller to 0x004A8A60, T16-3)
  -> 0x004A8B33 global branch [native confirmed, semantic unknown]
  -> 0x006F4A50('Event/TutorialMain.lua') [native confirmed]
  -> 0x006F4DD0('Tutorial_EntryPoint',0,0) [native confirmed]
  -> tutorial Lua event logic [resource not present; missing]
  -X-> task-state writer / packet ack [not established]
  -X-> tutorial complete / next mainline quest / NPC [not established]

XML candidate field parser [native confirmed; ID domain unknown]
  -> 0x40 byte record + local vectors (T16-10)
  -> 0x00FE18DC ordered global index (T16-6 and 10)
  -> separate runtime consumer 0x004AE888 (T16-9)
  -X-> tutorial or mainline progression [not demonstrated]
```

## Node / acceptance / evidence matrix

| hypothesis or phase | KR direct proof | authority | TC | next evidence |
|---|---|---|---|---|
| initial/tutorial selection | specific caller identified, gate semantics unknown | unknown | unknown | trace input from T03/T04, Lua content |
| Tutorial_EntryPoint dispatch | loader + callable entry confirmed | script execution only | unknown | actual Lua and return/exception path |
| tutorial objective update | missing | unknown | missing | relevant event listener and T02 packet payload |
| tutorial complete flag | missing | unknown | missing | state writer and cross-login T15 interface |
| quest candidate XML records | parser+0x40 allocation observed | client-local parser | missing | source XML and schema |
| FE18DC runtime consumer | confirmed bounded native trace | client memory only | missing | inspect actor record key and use after 0x53EBA0 |
| first mainline quest | missing | unknown | missing | quest resources IDs and authority mapping |
| playable test | not performed | unknown | not performed | no client execution authorization |

## Cross-task handoffs

- T03/T04: ask for existing actor/tutorial input **proven** fields only; no new character initialization in T16.
- T02: request confirmed task-notification dispatch and payload semantics; no framed protocol redefinition.
- T07/T14: verify which stage outcome triggers task update, not stage conclusion itself.
- T15: seek task field persistence and post-relogin restore semantics, not storage implementation.
- T06/resource: acquire version-matched `Event/TutorialMain.lua`, `Table/QuestInfo.xml`, `Table/QuestTalk.xml` and any relevant packs. Reference from T16, do not claim resource parsing ownership.

## Next batch recommendation

T16-13 should inspect `0x008438C0` key comparison + `0x0053EBA0` payload routing from `0x004AE888`, and locate quest notification commands in original T02 dispatcher. Prefer resources and confirmed business events over tracing another generic STL allocator. Keep TC comparison strictly unknown pending matching original. No automatic client modifications or commit permissions beyond user's explicit one-time request for T16-9..12.


## Result limitations and GitHub status at authoring

- Native-confirmed means exact reads/branches/calls in the supplied KR BIN; inferred domain names remain provisional. No actual original XML/Lua content available.
- No read-only evidence here proves server authoritative rules, NPC dialogue flow, tutorial step list, first mainline quest ID, or TC correspondence.
- GitHub publication follows user approval only after T16-12; recorded commit references should be confirmed from remote separately.