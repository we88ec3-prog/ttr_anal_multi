# Skill impact routing and self-heal calibration — v57 prepared

Priority remains normal room-based village entry, all-role skills, native MEF,
then other features. Live Host stays v53; normal village Client acceptance is
pending. This policy fixes a lab defect without claiming recovered combat rules.

## Problem and source scope

The existing prototype applied the same enemy damage loop to every admitted
skill, including healing and defensive buffs. ActiveTable projection plus full
KR/TC descriptions do not support turning those casts into direct enemy attacks.
T11's official targeting, formula and timing gaps remain open. This is a bounded
S00 Server-owned lab policy; it does not resolve T10/T11 native contracts.

The1,448 Practice-level effect rows were rechecked against the pinned original
KR Active XML. Within243 matrix actives (columns1..6, excluding V/Tab), there are
11 pure HEAL,3 mixed ATTACK+HEAL and5 with neither tag. Every learned-level row
has the same tag set for its active. Classification is source metadata, not proof
of target selection or HP/SP meaning.

| Branch | Lab action |
|---|---|
|ATTACK present|Retain existing provisional enemy damage; source ratio/revision are not yet used as a damage formula.|
|Pure HEAL|Do not run generic enemy damage. Only the five explicitly accepted self components below receive a one-point healing calibration.|
|Neither tag, five reviewed buffs|Do not run generic direct damage. Keep the declared buff mechanics visibly pending.|
|Mixed ATTACK+HEAL|Retain provisional attack only; no automatic HP healing from the HEAL tag.|

Absence of a tag alone never proves absence of gameplay or script-side damage.
The five empty-tag skills have affirmative descriptions: Soma4 reduces damage;
Pipa13 reduces damage and increases later physical attack; Pipa15 blocks a finite
number of ordinary bullets/normal attacks for self/allies; Sblm25 blocks a finite
number of all attacks on self; Isla34 increases evasion. No magnitude, duration,
hit count, reflection, counterattack or HP absorption pool is newly invented.

## Explicit self-heal calibration

|Role / Active|Accepted portion|Still unfinished|
|---|---|---|
|Aelt5 /43|Caster HP portion of group heal|Other allies/radius/native timing|
|Aelt5 /46|Caster HP portion of purification|Circle allies, cleansing, resistance buff|
|Grnt6 /50|Caster HP portion of battle heal|Other allies/radius/native timing|
|Grnt6 /51|Caster HP recovery|Equipment-derived magic power/native formula|
|Grnt6 /53|Caster HP portion of group heal|Other allies/radius/native timing|

Calibration magic attack is explicitly100, not the actor's actual stat or an
original default. For each admitted HEAL coefficient, the **Server-owned lab
choice** is `ceil(100 * ratio / 100 + revision)`, floored at0. Sum these amounts
and cap actual recovery at the existing player maximum500. Source ratio/revision
values vary with exact learned level, but their interpretation here is provisional.
This arithmetic is not reverse-engineering evidence of the official formula.
The test page labels both calibration magic power and expected self-heal amount.

Use the existing prototype impact point0.2seconds after admission. Capture the
impact plan before successful charge consumption restores the base skill group;
do not resolve the same key against the restored group at impact. One request
charges resources/cooldown once; healing only changes existing HP parameter and
absolute resource totals. It does not reconstruct cooldowns, restart timer sweeps,
invent a heal-result flag, create green floating numbers or alter resource regen.
Dead players are not resurrected by this policy.

## Explicit exclusions

- Aelt478/3024 are gradual fields;3024 also has guided outside-ally healing.
- Grnt481 requires lowest-HP ally selection/projectile arrival and cleansing.
- Aelt2511 is an ally chain and does not justify unconditional self-targeting.
- Grnt2518 includes self but uses recovery orbs; its arrival is not a cast-instant
  self-heal proof, so it is not in the five-skill calibration.
- Epds1407 is a support field; TC adds HP sacrifice/attack increase absent from
  KR prose, while level1 source ACTIVEINFO HP cost is0. Do not invent HP cost.
- Mixed Epds3043 describes persistent **SP** recovery despite a HEAL tag. It must
  not automatically use the caster-HP path. Mixed3021/3052 also need distinct
  attack/healing recipients and timing.

These excluded effects remain presentation-only or provisional-attack as labelled,
not gameplay-complete. No new motions are opened: prepared counts stay178 lab
candidates /880 matrix slots,65 unavailable actives. Normal tutorial/mainline
combat without an explicit skill-lab profile retains its previous prototype path.

## Reproducible evidence

Under `governance/client-variants/20261107-all-skills-unlock`:

|Evidence|SHA256|
|---|---|
|heal-targeting-source-boundary-v1.json|b23e937b9a4f9a5f1e5d62328900cfc5a823c0fc7ff8a289f665b48cf092cf1b|
|empty-effect-five-description-boundary-v1.json|f99d05477e1026f12607fbf78b6a66f8e146b1256f9bd77935c4a710b4a154cf|

The helper's six self-included description candidates include2518; this policy
deliberately accepts only five non-projectile/non-persistent self components.
Both accompanying audit scripts reproduced their pinned hashes. Original members
remain local/read-only; no game operation, native-provider retry or MEF rescan ran.

The lab UI selects a common learned level supported by every key in a matrix/tier.
The reviewed Aelt/Grnt groups support levels1..5 together, even when an individual
healing Practice has a higher level. Per-key independent levels remain future work.

Validation:148 HappyPath cases passed,0failed/0skipped,61seconds; Host Release
build passed with0warnings/errors; extracted page JavaScript passed `node --check`
without executing the script. Ten new healing cases cover injured self recovery
at supported learned levels1/5, cap, source costs, HP bar/totals, charge-reset
snapshot and unchanged cooldown timers. Ten additional normal support casts
preserve pending buff/field/chain/orb semantics without generic enemy damage.
The initial fixture used unsupported group level6 and failed five null-profile
cases; correction uses supported level5 without relaxing product validation.
Its failed TRX is preserved alongside the successful rerun, with hashes in
`v57-validation.json`. No deferred behavior suite or original Client test ran.
