# T01 R0/R2 Batch4 Git integration receipt — 2026-10-30

Source: original full batch4 report and native disassembly preserved at the file paths in this folder. This **new receipt supersedes only the original report's historical statement 'not yet pushed'**, not the technical analysis.

- Main before this commit: `2f7569560aff1de9b992653904f9ab36e9e3dc6c`.
- Intake: 51 sources, extra/roy1 33 and T16 18; proposed `SRC-0400..SRC-0450`; all source identities tied to original pre-existing Git blob SHA and UTF-8 content SHA256 as independently recomputed in the preceding T01 batch4 analysis. Exact digest/size pairs retained in `source-r0-51-manifest.json`.
- Main canonical total after applying the patch: `450` SRC, original 399 preserved; **all 51 are REGISTERED only**.
- Independently re-ran the original `verify_r2_batch4.py` on the original KR `Tartaros.bin` in this turn; original SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`. Rooted `0x7B6890` CFG 223 reachable instructions/45 branches/10 calls; selected type1 vs type2 readers also verified.
- Evidence scope: `0x7B6890→0x89120C→0x8920FC→HeapFree` frees a tree node in the inspected native chain; **not evidence of old Conn destruction, absence of other owners, leak, or race freedom**.
- T16 type2: `0x500950` is type1 and `0x500A00` is type2 in guarded candidate readers; T16-117 corrects the limited T16-116 UI overreach, without invalidating all of its Quest key-handling observations.
- RR-0005 status must be read from the latest `research/requests/index.json`: it moved to `IN_PROGRESS` under T02 and is deliberately unchanged here.
- No new R3/FULL-PASS/NATIVE_VERIFIED, SPEC_CONSUMABLE, RR ACCEPTED, or S00 STABLE. T16 and extra own branches not merged by T01.
- Proof-of-replay scripts are in the user's original local ZIP `T01-20261030-R2-BATCH4.zip`; Git here publishes the original complete report, disassembly and exact source manifest. The code JSON/source audit can be reproduced from that ZIP; do not claim every ZIP member is in Git.
