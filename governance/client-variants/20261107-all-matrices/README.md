# All-matrix isolated skill lab candidates

Reproduce with `python build_all_matrix_candidates.py`, then `python project_runtime_matrix_rows.py` from the workspace. Scripts read original and working archives, compare bytes and pinned member hashes, and write only this evidence directory.

`runtime-matrix-rows.json` has schema `tartaros-role-skill-lab-runtime-matrix-rows-v1`. Its 945 rows cover nine roles × matrices0..6 × actual 15 six-key tier slots. Each row includes role, matrix, tier, mask, practice, active, hp/sp/mp consumption, rawCooldown, motions, durationSeq, status, blocked and isBasicChain. Level remains the explicitly declared level1 Basis lab candidate. Learned-level cost selection must use the separate exact cost projection, not tier or matrix number.

778 slot rows are resource preview candidates (743 single Basis,35 basic-Z sequences);167 stay blocked (143 no exact resource join,24 ambiguous multiple Basis phases). Across the243 distinct role/active pairs,154 are preview candidates and89 blocked. `summary.json` lists each role's27 distinct actives with all matrix/tier/mask occurrences and exact status. `blocked-rows.json` is the complete blocked slot list.

Distinct candidate/blocked actives by role1..9:14/13,14/13,18/9,19/8,17/10,17/10,18/9,18/9,19/8. Matrix0 has119 candidate slots and16 blocked, identical to the prior135 runtime rows after removing the new matrix field.

Candidate rules are unchanged: unique ActiveSkill Practice; exact resource-stem join; refine only by unambiguous Effect Basis tags. A basic Z resource sequence additionally requires consecutive _SKILL01_01..N names. No nearest spelling, reused fixed motion IDs, automatic multiphase selection, or default-tier animation borrowing. Multiple Basis phase arrays are retained for evidence but remain blocked.

610 archive members were byte-reverified and checked against existing pinned catalogs. `source-members.json` records their original and working hashes. Full details are in `role-skill-lab-candidates.json`.

These are source-backed isolated preview candidates, not a completed native active-to-motion dispatcher or authoritative cancellation, hit, multihit and damage timing. A proven matrix setter is separate. Special columns7..10, all animation variants and the existing unresolved joins remain outside this projection. Server and Client were not modified; no game launch, attachment, MEF search or Git commit occurred.
