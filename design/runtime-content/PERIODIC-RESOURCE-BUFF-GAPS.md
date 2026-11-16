# Eight periodic resource Buffs — source boundary and implementation plan

2026-11-08. Normal room-based village entry remains the first manual acceptance
item. Live Host stays v58; this work does not replace it or change Client files.

The bounded audit uses original/work KR and TC Table members plus the existing
Practice-level effect projection. The public evidence is
`governance/client-variants/20261107-all-skills-unlock/periodic-resource-buff-text-boundary-v1.json`,
SHA256 `8ab70a5cb209f4c9d13638fd06cec90317789b4499964a18414b77ff9f2b7630`.
It covers eight selected skills, not all regeneration mechanics.

|Role / Active / Practice|Buff candidate|Reviewed portion|Unresolved part|
|---|---|---|---|
|Aelt5 /41 /73|9, 平靜|Self HP/SP/MP recovery; raw time8.|Amount, interval, cleanse and attack timing.|
|Grnt6 /52 /84|11, 治癒之手|Self and allies receive HP recovery and cleansing; raw time10.|Buff recipients, amount/interval, cleanse categories.|
|Grnt6 /54 /87|10, 艾格里特之魂|Self HP recovery and resistance+30; raw time8.|Recovery amount/interval, resistance formula, cleanse; weak stun requires trait.|
|Crom7 /335 /99|35, 解除魔法|Self and circle allies receive MP recovery and cleanse; raw time10.|Amount/interval, recipients and cleanse. Practice has8 levels but BuffExplain only7: no level8 fallback.|
|Ruko8 /965 /123|77, 精力充沛|Self SP/MP recovery; raw time10; charge prerequisite retained.|Recovery amount/interval and knockback behavior.|
|Epds9 /1404 /132|85, 神之庇佑|Self and allies receive SP recovery; raw time10.|Amount/interval and recipients. KR describes an enemy attack; TC full description omits that sentence.|
|Isla4 /475 /59|53|Physical attack+110..270 and SP recovery stat+40..120; raw time60.|Recovery-stat formula/clock, physical attack formula. TC Active/Buff spelling differs.|
|Grnt6 /482 /92|58, 萊比歐斯之保佑|Self/allies: mental attack and SP/MP recovery stat increase; raw time60.|Stat formulas, recipients and displacement.|

Same names are candidate identities, not recovered Active→Buff dispatch. TC475
has no exact-name match: the audit explicitly compares KR candidate numeric ID53
and retains the different Active and Buff names. It does not repair the source
or describe a numeric-ID comparison as an exact-name join.

All reviewed learned-level joins for these eight skills have ATTACK declarations
and no HEAL coefficient. This does not negate the recovery Buff described in
their full text. Conversely, attack ratio/revision must not be reused as a heal
amount. Most reviewed descriptions provide no numeric recovery amount. The two
recovery-stat increases are not independently proven flat amounts per tick.
Raw time is recorded without establishing native timer units or grant level.
Practice482 has five learned levels despite ten BuffExplain levels; additional
Buff levels must not automatically become learned levels.

## Shared implementation work still required

1. Separate base actor regeneration attributes from accepted skill modifiers;
   preserve HP/SP/MP identity, ownership, lifetime and source skill/level.
2. Resolve the original recovery-stat formula and update clock, or explicitly
   label a separately chosen lab calibration. Do not reuse the user's temporary
   MP/SP50% per10s and HP20% per60s as recovered skill mechanics.
3. Add per-owner periodic effects independently of cast/animation deadlines,
   with per-resource caps and costs/cooldowns charged once. Keep field occupancy,
   self Buffs and ally target selection as distinct recipient rules.
4. Publish existing absolute resource totals/parameters after actual changes;
   do not rebuild skill cooldowns on a recovery tick. Native Buff publication
   needs its own ID/level/EFF review; this audit does not expand0077 allowlists.
5. Keep attack, cleansing, resistance, knockback and trait components separate.
   A recovery component alone cannot establish a complete skill.

## Current development and validation

The prepared Server impact metadata/test page now identifies these eight pending
recovery components, including attacks that previously only showed the generic
attack status. It does not apply invented recovery amounts or grant new Buffs.
These labels are not an exhaustive per-skill completion inventory.

Source audit reproduced its output SHA after reviewing all KR/TC full descriptions
and Buff levels. Host Release build passed with0warnings/errors; extracted page
JavaScript syntax passed without execution. Initial default parallel build exited1
with no compiler diagnostic; serial build completed successfully after a compiler
server pipe-access fallback. No gameplay behavior changed, no new behavioral
suite or original Client ran, and the prior160 HappyPath result is historical
v61 evidence rather than a fresh v62 test claim. No native MEF claim is made.
