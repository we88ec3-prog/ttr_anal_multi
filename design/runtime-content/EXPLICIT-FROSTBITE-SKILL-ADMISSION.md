# Explicit frostbite skill components — v73 preparation

Live Host remains v71. This extends the partial Buff28 lab component to eight
additional already admitted skills, without increasing the181 motion-comparison
candidate count or claiming complete skill mechanics. Normal room-based village
entry remains first for actual Client acceptance; the user deferred testing.

## Source review and admission boundary

Read full KR/TC descriptions and exact Practice→Active identities for the13
specified skills below. Do not infer frostbite from an ice attribute or name.
Evidence `frostbite-skill-admission-source-boundary-v1.json`, SHA256:
`78b6bb1eb11256f97831a29a536ae2adcdbb02478ffa63fef875e194ee7b7c84`.
It references the separately reviewed Buff28 rows, SHA256
`f038be108b98590665413433a86de73408f817919de5ac20f858a9f172c29f37`.
The exact original/working Table members and finite Practice files are rechecked;
no animation archive inventory scan, new native dispatch or game execution.

|Role / Practice / Active|Partial lab admission|Still separate|
|---|---|---|
|Crmd7 /98 /333 冰凍弓箭|No frostbite without trait wiring|Full text explicitly requires trait enhancement|
|Crmd7 /105 /340 冰窗|Frostbite on existing prototype hit|Branching projectiles and target marker|
|Crmd7 /106 /737 冰凍結晶|Frostbite on existing prototype hit|Protective crystals/count/lifetime/contact timing|
|Crmd7 /110 /1299 暴風雪|Frostbite on existing prototype hit|Persistent field, falling ice and repeated hits|
|Epds9 /129 /1403 砍擊|No frostbite without trait wiring|Full text explicitly requires trait enhancement|
|Epds9 /139 /1412 冰凍召喚|Self-circle pulse, frostbite, collision-clamped pull|Original curtain/lifetime/range/forced-move visuals|
|Crmd7 /181 /2527 憤怒冰雪刺|Self-circle pulse and frostbite|Multiple spikes and final roll|
|Epds9 /186 /2534 緊急支援|Caster self-circle pulse and frostbite|Up to3 allies' auras and taunt/target changes|
|Epds9 /187 /2536 憤怒之浪|Frostbite on existing prototype hit|Fan wave/multi-hit timing and shape|
|Crmd7 /254 /3033 冰凍旋風|Deferred: no motion candidate|No automatic action borrowing|
|Crmd7 /255 /3034 冰凍暴風|Retain v71 admission|Original ice-spike area/multi-hit/proc|
|Epds9 /264 /3043 冰凍保護|Deferred: no motion candidate|No automatic action borrowing/buff grants|
|Epds9 /266 /3045 冰之盾|Frostbite on existing prototype hit|Shield lifetime, knockback resistance and low native chance|

The descriptions give different qualitative proc rates. Lab proc remains100% for
observation, not a recovered shared official chance. Use only exact Active levels
1..5 → equal Buff28 levels1..5. Raw times5/5/6/6/7 interpreted as seconds and
movement20% remain provisional. Attack-rate reductions20/22/24/26/28% come from
Buff text; their application/timing formula remains the v71 Server policy.

Active340 has a legitimate sixth level, but no admitted Buff28level6 source row.
Keep that skill playable with its exact MP175 and existing animation candidate;
do not invent a level conversion/cap. Explicitly report frostbite mapping pending.
Trait-gated333/1403 likewise keep normal attacks and report missing trait wiring.

## Area and pull reuse

For1412/2527/2534 only, explicit surrounding/self wording selects a circular
prototype pulse of radius65 at the existing0.2-second observation, including
targets behind the caster. This is one current-pose pulse, not the native area,
persistent damage, projectile wave or all-ally aura. Other admitted skills retain
the existing prototype forward arc/range65; no new trajectory is guessed.

After1412's surviving hit, pull each recipient toward the current caster by at
most20, stopping outside8 and before static blocked ground. Reuse the same
quarter-unit trace as the v72 returning fist. Both callers share `PullEnemy`;
the trace is now a separate component rather than an implementation hidden in
the returning-projectile helper. Retain original damage/status order and publish
only existing authoritative position16. Do not add guessed forced-move/stun
packets, immunity rules or cancel already admitted melee deadlines.

Circle/forward target tests retain the existing prototype area-hit collision
limitations; this change does not establish native line-of-sight for AoE. Pull
movement itself cannot cross static blocked ground. Dynamic MEF barriers, vertical
projectile collision and original forced-move visuals remain unknown.

Area and hit-pull catalogue objects have independent schemas
`LOCAL_SKILL_AREA_V1_NOT_NATIVE_MEF` and `LOCAL_SKILL_HIT_PULL_V1_NOT_NATIVE_MEF`.
They are exported JSON/C# Server definitions, not native MEF payloads or a newly
implemented external file loader. Skill IDs, learned-level costs, matrix, V/Tab
semantics and original motion candidates remain unchanged. Page text labels
radius/pull values provisional and retains each unfinished field/trait/aura detail.

No enemy0077/FX, taunt, target mark, armor, multiplayer aura, trait activation,
native proc/grant/clock or new skill animation is claimed. Coverage stays181/883,
62 unavailable motion candidates. All-role skill completion and actual Client
compatibility remain pending; deferred suites are not scheduled by this document.

## Validation

220 HappyPath passed,0failed/skipped.19 new cases cover eight skills at levels1/5,
exact cost/charge retention, captured post-V effects, front/circle/far recipients,
5/7-second restoration,1412 pull stopping at8, two legitimate unenhanced trait-gated
attacks and playable340level6 with its frostbite gap visible. Existing returning
fist, damage/death, other effects and normal journeys retain their positive checks.

Host Release passed0warnings/errors; source audit reproduced byte-identically.
JS syntax and a synthetic DOM fixture passed area/pull/pending labels and existing
picker/level/target POST. A compiled probe of the author's own Server assembly
exported19 examples without starting a game/listener:16 frostbite plans,6 area
objects and2 pull objects, with traits/level6 kept unapplied. Area/pull required
fields/constants/enum/numeric constraints match the independent schemas; this
was a bounded check rather than a full JSON Schema validator. Digests/examples
are in `v73-validation.json` and the companion evidence package. No actual Client
or deferred-suite acceptance is inferred from these results.
