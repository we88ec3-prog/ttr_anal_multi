# E07 — Event SceneList native XML parser ↔ tutorial scene table cross-check

2026-10-29, `extra/roy1`; read-only original KR `Tartaros.bin`, `Event.stp`, E06-derived `SceneList.xml`. No Client execution, patch, or Git main mutation.

## Provenance and byte-level verification
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`.
- Event.stp SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`.
- E06 decoded `Event/SceneList.xml`: 158269 bytes, SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`, `SCENESET` root, 1687 `SCENE` children. XML declares `euc-kr`; CP949 decode succeeds, while Python ElementTree direct parse from bytes fails due to lack of supported multibyte XML codec, so parse decoded Unicode string instead.
- Direct native evidence: GNU objdump raw `Tartaros.bin` with `--adjust-vma=0x400C00`; this offset applies only to PE .text.

## 1. Native XML loader/parser proof

The `0x5607D0` function is not an inert filename xref, it accesses the XML root, enumerates scene entries, reads attributes and produces an indexed local data structure.

Selected verified instructions:

```asm
560815: mov ecx,0xC10668    ; "Event/SceneList.xml"
56081A: call 0x72EE30
560845: call 0x72F110
56084A: test al,al
56084C: je 0x560A26         ; failed load exit
56087D: push 0xC1067C      ; "SCENESET"
56088A: call 0x72E2E0
56088F: cmp eax,ebx
560891: je 0x560A26        ; missing root exit
560897: push 0xC0338C     ; inspect value from RDATA before naming
56089C: call 0x72E2E0
5608B5: mov eax,[esi]
5608B7: mov edx,[eax+0x14]
5608BC: call edx           ; XML node child/data
5608D9: push 0xC10688     ; "questIdx"
5608E6: call 0x7300A0
560911: push 0xC03394     ; inspect value from RDATA before naming
560916: call 0x7300A0
56093D: push 0xC10694     ; "funcName"
560942: call 0x7300A0
56099D: call 0x403040
5609B3: call 0x568950
5609C4: call 0x568680
560A17: mov esi,[esi+0x40] ; next XML node candidate
560A20: jne 0x5608B1
```

We **do not** assert that `0x568950` and `0x568680` are server calls; they are reached after XML attribute access and appear to maintain client-side scene lookup records. Naming and indexing policy need their own full disassembly.

## 2. E06 original scene row expansion

The actual Unicode XML rows for `questIdx=1000` include scene 1 `talkevent1_1`, 3 `talkevent2_1`, 4 `talkevent3_1`, 6 `talkevent4_1`, 7 `talkevent5_1`, 8 `talkevent6_1`, 9 `tutorial5_1`, 10 `talkevent7_1`, 12–14 `talkevent8_1`–`talkevent10_1`, and scene 15–18 `Synopsis_Tartaros` through `Synopsis_Tartaros4`.
- `questIdx=1001, sceneIdx=1, funcName=tutorial_start, endBehavior=0`.
- `questIdx=15`: `sceneIdx=1 Square_Tutorial01`, `sceneIdx=2 scenario_tuto1_1`, `sceneIdx=4 scenario_tuto2_1`. All these specific rows have `endBehavior=0`.
- This is a table of static event script function names; it **does not** establish the start condition, C→S opcode, server selection or native Tutorial controller.

## 3. Direct BIN negative evidence: distinct Lua and XML identity

Plain ASCII `tutorial_start` has **zero** occurrences in original `Tartaros.bin`; `Tutorial_EntryPoint` has one at BIN raw `0x804EA8`; `questIdx` one at `0x80EC88`, `funcName` one at `0x80EC94`, `SCENESET` one at `0x80EC7C`.

Therefore the XML script `tutorial_start` is not a native hard-coded plaintext C++ function name in this BIN. This says **nothing** about indirect Lua registration, compiled Lua bytecode, or dynamically built names. It is wrong to equate `tutorial_start` with `Tutorial_EntryPoint` on name similarity alone.

T16-46 (main blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`) documents `TutorialMain.lua` proto9 `Tutorial_EntryPoint` at Lua lines 274–276, proto8 `TutorialMain` coroutine, proto5 Part1 and proto6 Part2, including `GetTutorialState`, `RequestStartScenario`, `IsScenarioEnded`, and `g_TutoEmployCharQuery` wait/reset. These are **confirmed Lua structures**, but the relationship `questIdx=1001/sceneIdx=1→tutorial_start→Tutorial_EntryPoint` remains unproved.

## 4. End-to-end state/packet gaps (do not substitute fixture values)

- Confirmed: original Event.stp decodes to scene table and original Client BIN loads `Event/SceneList.xml` and reads `SCENESET` + row attributes.
- Unknown: mapping from XML `funcName=tutorial_start` to original event Lua function implementation; caller which selects scene `1001/1`; selected-character response handler and first-login decision; server authority and `005F`/scene-state wire.
- T07 existing restriction remains: `005F type6` is original `CDuelField`, unlike historically modified fixture Tutorial. Do not upgrade fixture behavior.
- The `Table/SceneList.xml` path belongs to a separate resource table, as confirmed E04/E05, and must not be mixed into the Event SCENESET.

## 5. Native reproduction

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5607d0 --stop-address=0x560a30 Tartaros.bin
```
```python
from pathlib import Path
from hashlib import sha256
from xml.etree import ElementTree as ET
b=Path("SceneList.xml").read_bytes()
assert sha256(b).hexdigest()=="8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25"
root=ET.fromstring(b.decode("cp949"))
assert root.tag=="SCENESET" and len(root)==1687
for r in root:
 if (r.get("questIdx"),r.get("sceneIdx")) in {("1001","1"),("1000","9"),("15","1"),("15","2"),("15","4")}:
  print(r.attrib)
```

## 6. Next E08 and integration rule

1. Disassemble `0x568950` and `0x568680` to determine the keys/values actually inserted by parser.
2. Identify corresponding original Event.stp Lua script defining `tutorial_start` (must not assume this function exists in TutorialMain.lua) and trace registration through client Lua runtime.
3. Follow xrefs to the scene lookup reader, then connect it to T03 `0x42` response and T07 scene entry; classify every unproven link.
4. Keep `kr-extra-roy/` until T01 explicitly integrates source-backed evidence; only then remove integration temp files. No main changes here.
