# Independent Practice levels in the skill lab — prepared v63

The previous selector used one learned level for every key in a role/matrix/tier.
It exposed only the intersection of those Practices' supported levels. For example,
an unrelated five-level skill prevented testing an X skill's source level11.
This change permits independent levels without inventing new source levels,
motions, strengthened variants, trait ownership or complete skill mechanics.

## Public source contract

The existing exact Practice LevelData→SkillLevel modifier→Active LEVEL join
remains authoritative for numeric values. Cost projection SHA256:
`75095ecd0c61abadd931eb9dc36114d2898d04997c6b41790a19a0771f55a779`.
Effect coefficients remain the separately pinned1,448-row projection in the
all-skills evidence package. No new original Client/resource scan is needed.

`LocalSkillLabSelection` accepts optional `practiceLevels`, an object keyed by
numeric Practice ID. The existing `learnedLevel` remains the common default.
An absent entry uses that default; an explicit entry must have an exact source
row for the selected role and the same Active identity. It may not clamp to a
nearby level, borrow another key, or enable a previously unavailable motion.
Server snapshots copy the map so later caller mutations cannot alter a profile.

Example local-test request body:

```json
{
  "checkpoint": "SkillLab",
  "role": 4,
  "matrix": 0,
  "tier": 0,
  "energy": 1000,
  "learnedLevel": 5,
  "practiceLevels": { "50": 11 }
}
```

This selects Isla Practice50/Active30 at learned11 (SP55/MP50); the other five
Practices remain5. This does not mean all six keys support11. The endpoint's
existing loopback/header/connected-test-session requirements remain unchanged.

## State and publication

Each binding carries its actual learned level alongside ActiveLevel, exact costs
and raw effect coefficients.0126 SkillSet records use each binding's learned
level rather than the group's default. Special V/Tab Practices retain their prior
level1 policy. Costs and effect plans use the same binding as the cache record.

V short charge, held-V emission, successful advanced cast returning to base,
release and Tab matrix changes retain the Practice-ID overrides. If X becomes
a different Practice, its level comes from its own entry/default; X's previous
level must not leak to it. A subsequent return restores the original Practice's
level. Cooldown identity, deadlines and resources are not reset by this feature.
The group's existing default support requirement is retained; it is not silently
lowered when switching to another tier or matrix.

The status catalogue adds `keyLevels` per key, containing only exact supported
levels and their cost/effect/impact metadata. Existing whole-group `levels` and
baseline `keys` remain compatible. The page provides an individual selector with
an explicit default option; preview and submitted map use the same choice.
Unchanged status refreshes preserve the picker DOM. Choosing another role/matrix/
tier in the page clears its local overrides; in-game V/Tab does not.

This is isolated local-test state only. It does not persist test grants to normal
accounts, implement the formal skill tree, or turn all admitted animations into
complete skills. Missing Buff level explanations still have no automatic fallback.
Native MEF and gameplay formulas are unchanged; current live Host remains v58.

## Validation scope

Positive tests cover all nine base-role X skills at exact source level11 while
other keys remain5: cache packets, ActiveLevel, numeric costs and admitted motion
identity. Additional journeys exercise short-V cast/reset, held-V release and
Tab replacement/return with mixed Practice levels. The page-flow simulation
checks selection, cost preview, POST data, default restoration and preservation
of an unchanged open picker. These are not original Client acceptance tests.

Results and build status are recorded separately in the v63 validation receipt;
normal room-based village Client acceptance remains the first manual test.

171 HappyPath tests passed,0failed/0skipped,62seconds. Host Release build passed
with0warnings/errors; JavaScript syntax and the page-flow simulation passed.
The first test runner could not connect to its testhost and executed0 cases;
its TRX was preserved. PID41152 was confirmed absent before the successful rerun.
No deferred behavioral suite, game execution, Client modification or Host swap ran.
