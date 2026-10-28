# T01-20261028-25 — Sixth ten-source FULL-PASS review (document-scoped bounded affirmative claims)

**Review disposition:** 10 unique GitHub **file paths and Git blob SHAs** independently reviewed, none of which were among the forty + ten unique paths in T01-20..24. IMPORTANT: Four entries named T16-41..44 are the **20261028-095118 versions**; earlier T16-41..43 versions reviewed in T01-24 are distinct documents. **Do not infer 60 distinct sequence numbers: the count is sixty unique original *files***.

**Definition:** FULL-PASS is limited to the positive bounded factual claims actually made in a given note, with negative/unknown/next-steps accurately preserved. A plan, prospective acceptance test, audit matrix or missing-resource report can pass *accuracy as a document* without the researched gameplay or server feature being fully validated. Nothing here changes task-level `native_complete=false`.

## Verification provenance

- Original KR `Tartaros.bin` size 12,472,320 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`; EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`. Both independently hashed from current local mounted files. Binary not executed, injected, or patched.
- PE .text RVA 0x1000/VA 0x401000/raw 0x400. Mapping **only within .text**: raw=VA-0x400C00; rdata VA 0xBD2000/raw 0x7D0600.
- Independent native byte assertions in `/mnt/data/t01_batch6_checks.py`: **46/46 passing**, grouped 4 per each of the first eight source notes and 7 per T08-177/T08-179; this verifies sampled native evidence, while remaining functional semantics are judged against the source's bounded wording, not auto-certified by the sample count.
- Separate full .text raw `E8 rel32` target re-scan: `0x7B7FD0→[0x7AAF1F]`; `0x7B8030→[0x7AB155]`; `0x7DD100→[0x7B8129]`; `0x7DD1A0→[0x7A8741,0x7BE60F]`; `0x7DD1F0→[0x7B8045,0x7DD132]`; `0x7DC510→[0x7DD17D]`; `0x7DCF40→[0x7B7F49,0x7B8136]`. Raw byte scan does NOT assert instruction-boundary CFG validation or completeness of indirect calls.
- GitHub `main` original source files fetched anew **10/10 blob SHA matched**. Original Lua and QuestTalk evidence were fetched separately, not inferred solely from prior research summaries.
- GitHub Lua evidence: `kr/evidence/662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809.txt` (blob `3131bf2248949a6d06b5634eec68f818bf57cc2f`), `kr/evidence/d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3.txt` (blob `834e1fe2211e257bd6f72f01fed4ef6b3cf5ee30`). Fetched base64 and decoded original bytes. Independently parsed Lua 5.1 32-bit little-endian string/proto/code/constants/child prototypes/debug tables, consuming entire bytes without overread: TutorialMain 5480/5480, 11 proto, 558 instruction words; qbase 11836/11836, 76 proto, 906 words. **Do not claim both payloads' SHA256 was independently recomputed in this turn**; filenames/audit provenance and blob SHA are recorded, not a new original SHA256 assertion.
- GitHub QuestTalk source `kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt` blob `232b936d73dfd3f260d52208b959a3a682ecb054` read original XML first 16 lines; `QuestInfo.xml` entire content NOT accessed. T01-06 metadata is classed A/audit evidence, and cannot be called first-hand XML child-row validation.

## Full claim disposition table

| # | Original file + immutable Git blob SHA | Bounded affirmative evidence claim independently checked | Retained unknown / non-claim | Result |
|---|---|---|---|---|
| 1 | [T16-41 (09:51)](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-41-KR-tutorial-Lua-provenance-and-entry.md) `46d93721bb6a343d83a00fa5cfe2283b33e16337` | KR TutorialMain/TutorialBase source provenance and Lua client entry, not completed tutorial. Independently parsed TutorialMain chunk: 5480 bytes/11 protos/558 instructions; native 0x4A8A60 loader initialization, 0x4A8A94→0x823850. | Lua original TutorialBase source bytes not independently opened, Lua side effects and server persistence unknown. | **FULL-PASS (document-scope)** |
| 2 | [T16-42 (09:51)](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-42-KR-quest-XML-versioned-source.md) `77b960803fe95ba9fc5dd7a7f086dcc79c05b6e4` | Versioned XML provenance; QuestInfo reader 0x504740 and QuestTalk reader 0x505570 use distinct strings 0xC0DB48 and 0xC0DB5C; QuestTalk original first 16 lines read and actual id13→id17 ordering reproduced. | QuestInfo id15/16 source rows inaccessible, not asserted. XML child counts are T01 manifest records, not independently decoded here. | **FULL-PASS (document-scope)** |
| 3 | [T16-43 (09:51)](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-43-KR-tutorial-to-quest16-quest15-evidence.md) `22c02f093ab0e8804e42ec5b071c9fb316e9bebc` | Native script loader calls 0x4A8A36→0x6F4A50 and 0x4A8A46→0x6F4DD0 verified; source T01-06 NEXT-QUERIES explicitly labels tutorial→scenario14→Quest16/15 as unresolved research sequence. | Never promotes scenario14 completion, Quest16 server completion or Quest15 availability; no server writer/ack. | **FULL-PASS (document-scope)** |
| 4 | [T16-44 (09:51)](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-44-KR-quest-state-authority-acceptance.md) `8262d45d0f8cf5672ff4617d2c0ac741d764c205` | Original source is a five-stage acceptance contract (request, validate, write, notify, restore) with sampled client Lua bootstrap, NOT an already completed quest feature; 0x4A8A60 and 0x5043E9 native anchors verified and T01-06 pending backend gaps corroborate contract. | The five stages were NOT all tested; this passes only accuracy and provenance of document's actual diagnostic/negative conclusions. | **FULL-PASS (document-scope)** |
| 5 | [T16-45](../../../kr-temp-roy/20261028-101028-chatgpt-web-roy-T16-45-KR-Lua-XML-source-and-BIN-validation.md) `8067059908d888141c8d7b4a12b80eb6b427e49c` | Actual `kr/evidence/662f8416...txt` fetched with base64; decoded 5480-byte Lua5.1 header 1B 4C 75 61 51 00 01 04 04 04 08 00 00 00. qbase fetched 11836 bytes; T01-45 positive statement of readable original chunks and native Lua loader confirmed. GitHub evidence blob Sha Lua `3131bf2248949a6d06b5634eec68f818bf57cc2f`. | QuestInfo.xml row 15/16 was NOT retrieved, and original source itself identifies missing; native script load is not quest server state. | **FULL-PASS (document-scope)** |
| 6 | [T16-46](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md) `dea68e6db1af124ecdaca7943a877a7dbddd2377` | Independently wrote/re-ran Lua5.1 32-bit little-endian byte decoder on unmodified GitHub evidence: TutorialMain 5480/5480 byte consumption, 11 protos, 558 words (proto5 197; proto6 158; proto8 78), qbase 11836/11836, 76 protos, 906 words. Jumps: proto5 pc23 sBx+3, pc26 -9, proto6 pc26 +3, pc29 -10 confirmed. Proto6 constants include RequestStartScenario and IsScenarioEnded. | Lua control-flow structural claim passed; no runtime execution or scenario ID/server result confirmed. | **FULL-PASS (document-scope)** |
| 7 | [T16-47](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-47-KR-quest16-quest15-source-schema.md) `fef1cae164a07377ce29b8586453e385bd05520c` | Fetched original QuestTalk evidence first 16 lines; root QuestTalk; id11/12/13/17 entries and id13 giver/giverto/finisher 387/389/390, id17 2216/2219/2220 corroborated. BIN 0x50478B push path constant 0xC0DB48, 0x5055B8 0xC0DB5C; HasQuest strings at 0x53FD84/92. | Original explicitly says XML closing tag in excerpt is illustrative; not an observed line. Can't derive Quest15/16 missing from XML or require predecessor. | **FULL-PASS (document-scope)** |
| 8 | [T16-48](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-48-KR-quest-authority-validation-matrix.md) `e4633cecbb8531a950a4d15f24d7db5ae4fd6529` | Acceptance matrix correctly keeps scenario14 legitimate result, Quest16 state writer, Quest15 prerequisite and relogin as unknown. Native x86 entry 0x4A89C0/0x4A8A60 and literal 0x53FDA2; Lua proto5/6/8 source-level control skeleton independently parsed. | This file's proposed test cases are UNEXECUTED test specifications. Document-scope review does not imply full quest authority acceptance. | **FULL-PASS (document-scope)** |
| 9 | [T08-177](../../../kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md) `fdc8a64aa0f33866defe5a2484fa432f4bbaf66c` | Corrected enable entry 0x7B7FD0 (not 0x7B7FA0), 0x7B7FFE mov ecx,1 → 0x7B8006 [owner+44]=1; 0x7AAF1F and 0x7AB155 direct enable/disable callers; drain 0x7DD1F0 raw direct callers 0x7B8045/0x7DD132; mode vs delayed queue counters separated. Seven E8 target-sets independently rescanned. | Raw E8 occurrences do not prove indirect xrefs, all possible object dynamic types, exception path or runtime concurrency. Disable vtable target unresolved. | **FULL-PASS (document-scope)** |
| 10 | [T08-179](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-179-last-reference-registry-release.md) `76e410b206bde1e85444134303da17b0242794f0` | 0x7DD125 mov esi,ecx; 0x7DD12A add [esi+0x5C],-1; zero → 0x7DD132 call 0x7DD1F0; 0x7DD140 clear owner+44; 0x7DD174 read [eax+ebx*4]; 0x7DD177 load ecx=[0xFE173C]; 0x7DD17D call 0x7DC510. Direct E8 target sets cross-verified. | Owner+5C counter differs from owner+60; no assertion of atomic/threadsafe reference count, constructor initial value or complete aliases. | **FULL-PASS (document-scope)** |

## Native byte-level checkpoints

The reproducible assertion script currently exists at `/mnt/data/t01_batch6_checks.py`; the essential direct bytes/targets are repeated here for a reviewer without access to the local runtime.

| VA | Original bytes | Observation |
|---|---|---|
| `0x4A8A31` | `68 7C 68 C0 00` | Push Lua filename constant for loader path |
| `0x4A8A36` | `E8 15 C0 24 00` | Direct call `0x6F4A50` |
| `0x4A8A46` | `E8 85 C3 24 00` | Direct call `0x6F4DD0` |
| `0x50478B` | `B9 48 DB C0 00` | First reader path string pointer |
| `0x5055B8` | `B9 5C DB C0 00` | Second reader path string pointer |
| `0x53FD84` | `68 EC F4 C0 00` | Named condition string |
| `0x53FD92` | `68 F8 F4 C0 00` | Another named condition string |
| `0x7B7FFE` | `B9 01 00 00 00` | Mode value literal 1 |
| `0x7B8006` | `89 4A 44` | Store mode to owner+44 |
| `0x7AAF1F` | `E8 AC D0 00 00` | Mode-enable direct call |
| `0x7AB155` | `E8 D6 CE 00 00` | Mode-disable direct call |
| `0x7DD12A` | `01 7E 5C` | Decrement owner+5C using EDI=-1 |
| `0x7DD132` | `E8 B9 00 00 00` | Zero-count branch drain direct call |
| `0x7DD177` | `8B 0D 3C 17 FE 00` | Load manager pointer from global slot (contrast literal-address push on mode caller) |
| `0x7DD17D` | `E8 8E F3 FF FF` | Direct call `0x7DC510` |

## Lua independent decode and CFG boundary

- Lua5.1 constant parsing validates proper types: nil(0), boolean(1), double(3), string(4); 32-bit little-endian Lua instruction array. JMP opcode is low six bits = 22, signed offset `sBx=(instruction>>>14)-131071`, target next PC + sBx.
- TutorialMain root proto0 25 words, proto1 17, proto2 13, proto3 22, proto4 12, proto5 197, proto6 158, proto7 28, proto8 78, proto9 4, proto10 4: **558**. Proto5 PC23 JMP +3 / PC26 -9; proto6 PC26 +3 / PC29 -10. Lua source code not executed and client native bridge does not certify script network semantics.
- qbase root 173 words and 75 descendants totalling 733 → 906. Both buffers exactly exhausted. Lua source/version counts are locally decoded facts while XML root counts and other source-carrier SHA are audit-record facts.
- QuestTalk original XML entries: line 15 `<Quest id="13" givertalk="387" givertotalk="389" finishertalk="390"/>`, line 16 `<Quest id="17" givertalk="2216" givertotalk="2219" finishertalk="2220"/>`. **Do not treat the illustrative closing `</QuestTalk>` from T16-47 snippet as source line 17**, and do not infer absence of Quest15/16 in QuestInfo.

## Revalidation command and next handoff

```sh
python /mnt/data/t01_batch6_checks.py
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -d -Mintel --start-address=0x7b7fd0 --stop-address=0x7b8082 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7dd100 --stop-address=0x7dd19c /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4a89c0 --stop-address=0x4a8b90 /mnt/data/Tartaros.bin
```

**Batch disposition:** 10 distinct files passed review of their actually asserted, bounded document-level positive claims. No unverified hypotheses promoted. Prior 50 + this 10 means 60 *distinct path/SHA documents*, **not 60 distinct logical sequence identifiers**, and not 60 native-complete gameplay functions. All remaining T08-173..192 broad ownership/cross-resource files and T08-196/200 (prior contradiction flags) remain candidates requiring detailed negative/positive review. We did NOT overwrite their source, modify other Tasks, or change `source-review-status.json`, owner fields, or game binaries. A future contradictions audit may demote any reviewed document; document-scope FULL-PASS never certifies a feature-level end-to-end acceptance.
