# T16-9 — KR FE18DC global index: second consumer and non-quest counterevidence

- Analysis timestamp (Asia/Taipei): `20261028-014919`
- KR source: `Tartaros.bin`, `12472320` bytes, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` (directly recalculated)
- PE `.text`: VA `0x00401000` ↔ raw `0x400`, `.rdata`: `0x00BD2000` ↔ `0x007D0600`; image base `0x00400000`.
- Baseline GitHub main: `c5f888ff4f1a2b55215bfebbe4901f71f3c6408e` (verified at start); T16-1..T16-8 are earlier baselines, not redefined here.
- Method: read-only BIN + GNU objdump, bounded x86 code ranges, constant xrefs; native semantics only where instruction flow supports. No client execution, DLL injection, patch, or server emulation.
- TC baseline: manifest SHA `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`, actual TC binary unavailable.

## Purpose and substantive findings

Earlier T16-6/8 associated `0x00FE18DC` with an ordered index written during a XML-like parsing path at `0x0053FE03..0x0053FE1C`. A fresh full `.text` scan for little-endian `DC 18 FE 00` yields **four direct references**, not just the parser. Importantly a separate `0x004AE888` consumer looks up an entry using a WORD read from `[ebx]` and uses the returned node's `+0x10` payload. This is strong counterevidence against automatically labeling the global tree as an authoritative quest progress registry.

## Direct xref and bounded consumer trace

`0x00FE18DC`: 0x004AE889, 0x0053FADF, 0x0053FAEF, 0x0053FE04. Calls/uses include: `0x004AE888` passes address as `ecx` to `0x008438C0`; `0x004AE891` calls lookup; `0x004AE896..0x004AE8A0` compares candidate with sentinel `[0x00FE18E0]`; only on non-sentinel `0x004AE8A9` loads `[ecx+0x10]` and `0x004AE8C7` calls `0x0053EBA0`. Key originates from `movzx esi, WORD PTR [ebx]` at `0x004AE87C`; compare to the parser's key preparation rather than assuming common quest ID namespace.

```asm
004ae875 <.text+0xad875>:
  4ae875:	89 b4 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],esi
  4ae87c:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  4ae87f:	8d 54 24 14          	lea    edx,[esp+0x14]
  4ae883:	52                   	push   edx
  4ae884:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae888:	b9 dc 18 fe 00       	mov    ecx,0xfe18dc
  4ae88d:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4ae891:	e8 2a 50 39 00       	call   0x8438c0
  4ae896:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  4ae89a:	3b 0d e0 18 fe 00    	cmp    ecx,DWORD PTR ds:0xfe18e0
  4ae8a0:	74 2e                	je     0x4ae8d0
  4ae8a2:	8a 43 fd             	mov    al,BYTE PTR [ebx-0x3]
  4ae8a5:	88 44 24 44          	mov    BYTE PTR [esp+0x44],al
  4ae8a9:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  4ae8ac:	8b 0d ec 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe18ec
  4ae8b2:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  4ae8b6:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae8ba:	bf cc 18 fe 00       	mov    edi,0xfe18cc
  4ae8bf:	89 74 24 48          	mov    DWORD PTR [esp+0x48],esi
  4ae8c3:	89 4c 24 50          	mov    DWORD PTR [esp+0x50],ecx
  4ae8c7:	e8 d4 02 09 00       	call   0x53eba0
  4ae8cc:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4ae8d0:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4ae8d4:	eb 41                	jmp    0x4ae917
```

## Mechanism and provenance caution

- `[ebx]` is read as a WORD, zero-extended into `esi`; the surrounding buffer at `[ebx-3]` is also read as a byte. This is evidence of a structured record lookup, **not evidence of a particular player task ID**.
- `0x008438C0` likely implements an ordered lookup contract here, but exact return record/layout must be cross checked with its own disassembly and caller ABI. Sentinel compare at `0x004AE89A` is direct proof of an absent-entry branch.
- On found path, `node+0x10` is forwarded to `0x0053EBA0` with other fields. This proves a runtime consumer outside parser construction.
- Remaining direct references `0x0053FADF`, `0x0053FAEF`, `0x0053FE04` include disposal and insertion paths; **same address** rather than guessed similarity.

## Counterevidence and updated conclusion

Prior plausible hypothesis: FE18DC is a quest index. Updated: FE18DC is an ordered global index accessed from at least two distinct code pathways, including a runtime record-creation/lookup path; owner, ID domain, object payload, and quest relationship remain unknown. Do not place this address in a server quest-state writer column. To resolve: locate full `0x004AE800` parent and its dispatch; inspect `0x008438C0` and `0x0053EBA0`; identify keys and data provenance.

## Supplemental assembly `0x53fade..0x53fb29`
```asm
0053fade <.text+0x13eade>:
  53fade:	f0 dc 18             	lock fcomp QWORD PTR [eax]
  53fae1:	fe 00                	inc    BYTE PTR [eax]
  53fae3:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  53fae7:	8b 01                	mov    eax,DWORD PTR [ecx]
  53fae9:	51                   	push   ecx
  53faea:	50                   	push   eax
  53faeb:	8d 75 ec             	lea    esi,[ebp-0x14]
  53faee:	b8 dc 18 fe 00       	mov    eax,0xfe18dc
  53faf3:	e8 c8 45 01 00       	call   0x5540c0
  53faf8:	a1 e0 18 fe 00       	mov    eax,ds:0xfe18e0
  53fafd:	50                   	push   eax
  53fafe:	e8 09 17 35 00       	call   0x89120c
  53fb03:	a1 cc 18 fe 00       	mov    eax,ds:0xfe18cc
  53fb08:	83 c4 04             	add    esp,0x4
  53fb0b:	3b c3                	cmp    eax,ebx
  53fb0d:	74 09                	je     0x53fb18
  53fb0f:	50                   	push   eax
  53fb10:	e8 f7 16 35 00       	call   0x89120c
  53fb15:	83 c4 04             	add    esp,0x4
  53fb18:	89 1d cc 18 fe 00    	mov    DWORD PTR ds:0xfe18cc,ebx
  53fb1e:	89 1d d0 18 fe 00    	mov    DWORD PTR ds:0xfe18d0,ebx
  53fb24:	89 1d d4 18 fe     	mov    DWORD PTR ds:0xfe18d4,ebx
```

## Result limitations and GitHub status at authoring

- Native-confirmed means exact reads/branches/calls in the supplied KR BIN; inferred domain names remain provisional. No actual original XML/Lua content available.
- No read-only evidence here proves server authoritative rules, NPC dialogue flow, tutorial step list, first mainline quest ID, or TC correspondence.
- GitHub publication follows user approval only after T16-12; recorded commit references should be confirmed from remote separately.