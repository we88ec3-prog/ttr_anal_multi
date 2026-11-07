# Active cache consumer follow-up — bounded result

Target: original KR `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`.
Status: **bounded cost-ABI closure; scriptLevel-to-motion bridge still unresolved**. This is not T01 FULL-PASS, an official Server mapping or a skill-unlock result.

## Positive result: cache+4 cost ABI

The earlier skill-level report retained this def-use as PARTIAL because saved pseudocode omitted register arguments. Selected original instructions now close the following exact path:

- `549AE3` calls `825F70`, whose ESI input is the hero skill-cache map and whose return EAX is the8-byte active record.
- `549AF2`, `549B05`, `549B1C` load **word+4**. The value goes to EAX and active ID goes to ECX before calls `530530`, `5305C0`, `530650` (HP/SP/MP getters).
- The second conditional query at `549B5E` uses the same +4 level-to-getter ABI at `549B69/B80/B97` and `549B77/B8E/BA7`.
- `549980` performs affordability/availability checks and returns0/1, wrapped by `54AE70`. This bounded path supplies no cache+6 value to an outgoing packet or animation/script selector.

See `cache-cost-abi-windows.txt`. This does not establish a complete official resource or charge-consumption policy; it only resolves the actual register/data source for these cost calls.

## Exact +6 read: bookkeeping, not presentation

`825FA0` initializes record DWORD+4 to `0x10000`, giving level+4=0 and scriptLevel+6=1. The exact +6 read at `826114` and write at `826123` implement unsigned MAX(existing scriptLevel, modifier+8). This is a cache-construction read/write, not a consumer selecting Basis/Average/Exper or a motion ID.

See `cache-scriptlevel-max-windows.txt`. Ordinary learned level and Talent scriptLevel remain different fields.

## Caller and reader boundary

Completed saved-text queries, independently checked against direct opcode candidates and function-entry disassembly:

|Callee|Actual direct callers in this scope|
|---|---|
|825F70|549980 at549AE3 and549B5E|
|825FA0|4E46D0 at4E4870;4E48A0 at4E4A82|
|549980|54AE70 wrapper|

All four exact call instructions to825F70/825FA0 were verified at instruction boundaries. No direct tail-jump candidate to either target was found in the pinned executable sections searched. This is not complete indirect-call closure.

The generic map helper826280 is shared by unrelated maps; its entire caller list cannot be labeled a skill-cache graph. We separately inspected these identified hero+1D4 cache readers:

- 4704C0: cache+4 becomes a byte level in skill UI cells.
- 5CD520: cache+4 drives cost getters and skill UI updates.
- 617B70: cache+4 nonzero sets an editor-availability flag.
- 61B0B0: iterates the map and forwards cache+4 to learned-skill UI.
- 61E4A0: forwards active ID plus low byte+4 to skill-slot UI.

No cache+6-to-action/script/motion consumer was identified in these specific readers. This does **not** prove the field has no consumer elsewhere; indirect, inlined or differently addressed readers remain outside the closed path.

## Consequence for all-role skills

This pass supplies **no new active-to-motion bridge** for the remaining new-configuration or spelling-mismatch skills. It does not justify aliasing names, choosing arbitrary motion IDs, treating multiple Basis resources as a sequence, or inventing learned-level animation thresholds. Numeric learned-level costs can continue using the verified mapping; presentation variants remain a separate unresolved contract.

## Provenance and reproduction

`source-identities.json` pins18 existing bulk C files to the matching index pseudocode hashes/raw-batch references, plus6 bounded instruction-range identities. Bulk outputs remain saved-unreviewed except for the exact bounded facts described here. Existing original resources, pinned reports, Client and Server files were not modified; no game execution, attachment, provider retry, new decompilation or Git commit occurred.

Run from the authorized local workspace with existing `rg`, local `anal` PE/Capstone helpers and the pinned original file:

`python -B audit_cache_consumers.py --workspace-root E:/Tartaros/workspace`

The script repeats only named saved-text searches and selected-function byte checks. An earlier sequential full-folder Python filter was canceled; its partial scan is not treated as a completed search or used to establish absence.

Publish only the filenames listed in `public-artifacts.json`. Full local selected-function dumps and the preliminary raw opcode-candidate file are working evidence, not required publication payload. No entire bulk tree, EXE, archive or decoded game resource is copied into this evidence package.
