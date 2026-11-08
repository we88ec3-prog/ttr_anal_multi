# Additional skill Buff components — v61 prepared only

Live Host remains v58/source d2b85b791ce02b250818ddce19b30b77ed398580.
Normal room-based village entry retains first manual-test priority; the user
deferred testing. This batch adds partial skill mechanics without another Host swap.
No new motion mapping is admitted:178 lab candidates /880 slots,65 actives still
unavailable. Reused numeric-family metadata did not justify borrowing another key
or admitting an ambiguous power-punch component as a native skill mapping.

## Source review and decisions

|Role / Active / Practice|Source text candidate|Accepted lab portion / limit|
|---|---|---|
|Soma1 /2492/157|Same-name Buff107, plus full Active text explicitly names ordinary Defence.|Compose reviewed107 finite all-hit shield and existing Buff1 reduction on self, alongside the existing provisional enemy attack. Same-level simultaneous grant is a Server choice, not a native grant proof.|
|Epds9 /1409/136|Same-name Buff86; KR explicitly self and nearby allies.|Apply self percentage reduction and publish identity. Store all-defence stat increase as declared/not applied; other allies/stat formula remain open.|
|Aelt5 /42/69|Same-name Buff8; KR explicitly self HP recovery on being hit.|Restore HP after positive applied damage, consuming a finite recovery-hit count. Do not restore SP/MP based on conflicting TC Active prose.|
|Grnt6 /1297/94|Same-name Buff97, physical reduction for allies in a circle.|Not granted to the caster: neither reviewed version explicitly includes self. Summoned pixie, ally targeting, binding and physical-only filtering remain separate work.|

All four full KR/TC Active descriptions, Practice modifiers/levels, per-level
Buff explanations and _BuffList entries were checked. Numeric/raw-time version
differences are0, but wording differences remain. Equal names do not establish
native Active→Buff dispatch or level conversion. Raw time interpreted as seconds
remains a Server lab choice. The four referenced EFF members exist and match
original/work bytes; complete geometry/loading/rendering is unverified.

## Explicit composition and values

Soma2492 grants two separate lab entries at the selected Active level: Buff107
and Buff1. Buff107 level1 blocks3 hits for raw time10; level5 blocks12 for raw
time18. Buff1 retains its reviewed reduction25..33% and raw time20..24. Consuming
the finite shield removes only107 and leaves1 active until its own expiry. Do not
describe107 alone as the entire skill or erase the reduction on shield exhaustion.
Exact grant level/order is not recovered from the full Active description.

Epds1409 levels1/5 describe all-defence stat+20/+140 and reduction12%/20%, raw
time20. The stat is not20/140 flat damage subtraction. Source levels1..5 omit a
maximum-reduction percentage; the v2 projection preserves this asnull, using the
selected reduction itself in the lab's strongest-reduction calculation. It does
not invent a50% source cap for these rows. Buff86 text also has levels6..10 with
other bonuses, but Practice136 only grants1..5, so those are not new learned levels.

Aelt42/Buff8 levels1..5 describe received-damage recovery70/90/110/130/150%,
5/6/7/8/9 hits, raw time12. Percentages over100 are retained. Server lab ordering:

1. Resolve existing shield/reduction, then clamp damage to current HP.
2. Subtract that applied damage. If still alive, recover `ceil(appliedDamage *
   percentage /100)` HP, capped at existing maximum500, and consume one recovery hit.
3. Publish the actual damage result plus final HP parameter/absolute totals once.
   No SP/MP restoration, extra cost, cooldown restart or invented heal flag.
4. Remove Buff8 when its recovery-hit count or lifetime expires; preserve other Buffs.

Blocked/zero damage does not trigger recovery in this lab; lethal damage does not
resurrect. Pre/post-mitigation basis, lethal ordering, blocked-hit consumption,
rounding and simultaneous effects are **Server choices**, not native proof. Their
adversarial/cross-source cases remain deferred. Practice69 has a learned6→Active6
row but Buff8 has no level6 explanation: no silent level5 fallback is provided.

## Data, publication and scope

The independent schema is`LOCAL_SKILL_LAB_DEFENCE_V2_NOT_NATIVE_MEF` with40 rows:
the old20, two components for Soma2492 at five levels, five Epds1409 rows and five
Aelt42 rows. It pins both source reviews. Multiple components are grouped by exact
role/Active/ActiveLevel; each Buff identity is distinct. UI shows all components,
and reports declared physical/all-defence stat fields as not yet applied.

The bounded0077 emitter extends its allowlist from1..4 to1/2/3/4/8/86/107, all
reviewed IDs below the native indexed-array bound128. Levels remain1..5. The
complete current owner list is emitted on apply, expiry and exhausted counts,
so one component's removal does not clear another. Opaque byte remains0 as a lab
candidate, not remaining time/count. Buff97 is not admitted into the own-caster
emitter. Original Client icon/visual acceptance and official timing remain pending.

## Evidence and validation

Source package:`governance/client-variants/20261107-all-skills-unlock`.

|Artifact|SHA256|
|---|---|
|four-additional-buff-text-candidates-v1.json|11c961dddcd26ad1ff4f919e25cf4c1a3d8f8b056884401258d0c6cde310baac|
|additional-buff-effect-members.json|bbf871c92bd0e4c9ea6ce401ec784ef54dfa074f57b8e9fd8fc20a05b2ce9780|
|v2 lab projection|458fdb26c93c03c80ddff017a63e35403977fde7bd507215a4f1c86be01304f7|

Source audits are bounded read-only and reproducible; no new original members
were exported.160 HappyPath passed,0failed/0skipped,61seconds; Host Release build
0warnings/errors; extracted JavaScript syntax passed without execution. Six new
level1/5 cases validate compound shield/reduction persistence, percentage vs
declared stat, received-hit HP recovery/count exhaustion and complete Buff lists.
These are partial Server gameplay checks, not Client acceptance or full skills.
No game operation, Client modification, provider retry, native MEF search or
deferred replay/concurrency/fault/security/load/multiplayer testing occurred.
