# 2026-11-07 Server development and acceptance snapshot

This snapshot supersedes ambiguous current-status wording in older iteration
entries, preserving those entries as version-specific history.

| Area | Implemented/deployed scope | Human acceptance / remaining work |
| --- | --- | --- |
| Local runtime | v28, private main e3cd883e66c29fa71d0ebe9c211897384f75b87c | Confirmed running PID34824; loopback auth8415 and HTTP5082 healthy |
| Fresh-account tutorial | Login, expedition naming, movement/camera/Tab, first battle, recruitment and house scenes to square | Fresh-account journey to square passed on r1102f; later v12 reached Phindos. These are historical bounded working-copy passes, not full product acceptance |
| Existing login and controls | Display page then explicit enter-square, saved narrative progress, NPC interaction range3x; v23 nonbattle controls/NPC fixes | v23 human: controls normal and village NPC scene appears. This is not an all-input/all-NPC verdict |
| Entry to Phindos | Square mainline, single-player formation, two-map instance, result/arrival | v12 human reached Phindos with NPCs and movement; loading screen separately passed. Later portal/combat/input corrections retain per-version limits |
| Phindos to Alsmeer | Candidate shared route:10 quest steps (117/118/119/120/121/122/123/124/131/132),16 maps and destination initialization | Synthetic journey covered; full real-Client route to Alsmeer remains NOT_PASSED. v23 only proved first village NPC scene |
| Battle | Basic combo/recovery, hurt/enemy prototype, Isilia six-key test lab, v28 resource/type/level correction | v26 combos/ZC/walking passed; v27 skill feel and MP/SP recovery passed, HP untested. v28 six keys, corrected motion/costs and resource-shortage greying pending human |
| Full skills | Local9-role/846Practice/469active L1 catalogue and bounded motion projections | Not all roles/skills enabled. Only Isilia default six-key lab; multi-hit/range/displacement/damage and advanced skills remain prototype/unresolved |
| Quest product rules | Shared narrative/instance route and narrative checkpoint persistence | Formal quest objectives, turn-in/rewards/EXP/new-role grants remain incomplete; story progression is not complete quest settlement |
| MEF | Design/defer record | Actual format/load integration not implemented; user postpones original MEF investigation until Server development at least60%; no new completion percentage invented |
| Client v4/v5 | v4 rendering/dialogue text human normal; v5 candidate nameplate fix | v5 human pending, not a Server source change |

Latest deployed v28 positive synthetic batch:57 HappyPath tests passed (59s),
recorded in S00-20261105-V28-RESOURCE-SEMANTICS-AND-SIX-KEYS.md. No Server
source changed in this Client-only work, and no deferred Server suite was rerun.
Negative/replay/concurrency/fault/security/load tests stay deferred under user policy.

Next practical sequence:verify v5 NPC nameplate -> finish v28 six-key/cost/greying
human checks -> correct combat blockers -> continue full Phindos-to-Alsmeer route
human test and formal quest-settlement development. Do not claim complete villages
or all combat based on synthetic counts alone. Both repositories work on main.
