# Skill growth axes and ScriptLevel source closure

S00 planning supplement,2026-11-08. Source metadata is not a newly recovered
animation dispatch or native MEF format. No formal T01 FULL-PASS is asserted.

|Axis|Bounded source / meaning|Server integration boundary|
|---|---|---|
|Active Practice learned level|SkillLevel modifier selects exact Active LEVEL; old grenade19 has1..6, strengthened2996 has1..5|Existing learned-level cost/coefficient joins; do not use as a motion ordinal|
|Talent learned level|Separate Talent Practice ID and declared LevelData/requirements|Do not grant by learning the Active or selecting a matrix|
|SkillScriptLevel|Talent modifier targets a specific Active ID and supplies Level|Separate per-Active field; not ordinary skill level or V tier|
|Matrix / V tier|Selects which Active occupies a key slot|Same key does not make old19 and2996 interchangeable|
|Animation family / variant|ABF/ASD motion resources and EFF declarations|Resource availability does not prove a ScriptLevel mapping|

## Two exact grenade pairs

`pipa-scriptlevel-trait-boundary-v1.json` SHA256
`956f807240f8e8a01c29d15167dd12013b6e9cbc17b3b89516f013d396e71164`:

- Talent1227,`Table/Skill/Talent/pipa_27.xml`: learned1/2 supply ScriptLevel2/3
  to Active19 ONLY. Requirements include CharLevel10,Skillpoint1,UsedSkillpoint30.
- Talent1251,`Table/Skill/Talent/pipa_51.xml`: learned1/2/3 supply ScriptLevel2/3/4
  to Active2996 ONLY. Requirements include CharLevel50,Skillpoint1,UsedSkillpoint55.
- Ordinary Active Practice26 grants SkillLevel1..6 to19; Practice217 grants1..5
  to2996. Both KR/working and TC projections agree. These are separate dimensions.

Raw requirement attributes are source declarations; payment/enforcement and
actual learned-Talent state are not proved by reading them. Neither pair declares
a motion ID. The four grenade visual variants must not be assigned to ScriptLevel
1..4 just because their counts/order happen to agree.

## Nine-role projection

`skill-scriptlevel-traits-v1.json` SHA256
`5d6a8263a768e1759b744ae57f85c49fceccadf4e7ec98f96f3f20e1297c1a62`.
Starting from the existing pinned catalogue, only228 known Talent member paths
were read, all their608 declared levels projected, covering228 unique role/Active
targets across nine roles. All72 known new-matrix Actives have a projected Talent.
This includes the currently unresolved motion cohort, without unlocking it.
Original/work bytes match for every selected member; KR/TC ScriptLevel modifier
projections agree. No archive inventory, MEF or whole-program search was repeated.
This does not cover other Talent members with no first-level ScriptLevel marker.
The repeated equal level trees are stored once per Talent, with per-version
projection hashes/equality flags and original member identities retained.

The selected sources also contain interrupt declarations on102 levels (195
declarations: Buffcast69,Consume46,AttackFactor39,BuffEnhance29,Skillcast6,
SkillCooltimeReset6). Their exact declaration trees are retained separately from
the ScriptLevel modifiers. Raw ScriptLevel values span1..5. In this selected scope
KR/TC interrupt trees and projected Require attributes also agree. None of these
matches establishes chance units, BuffSide enums, condition-combination semantics,
native execution order or full requirement enforcement. Do not implement a Talent
by keeping its ScriptLevel while silently dropping its interrupt behavior.

Existing bounded `cache-consumer` audit establishes default ScriptLevel1 and an
unsigned MAX(existing,modifier) write to cache word+6 at826114..826123. Cost readers
use ordinary level word+4 instead. This is a specific cache-building path, not a
proof of all global stacking/removal rules or a presentation selector. Preserve
that audit's unknown indirect/inlined consumer scope and source hashes.

## Implementation requirements before actual trait support

1. Keep learned Active and Talent states distinct. Resolve a modifier by exact
   role,TargetSkillID and declared Talent level; never by current key alone.
2. Preserve requirement/level metadata and source versions. A lab override must
   remain separate from permanent player grants and normal progression.
3. Cache ScriptLevel separately from cost ActiveLevel. Do not change resource
   payment just because presentation/ScriptLevel changes.
4. Adopt any motion/phase rule through an explicit per-Active evidence-backed
   mapping. Keep working-copy visual observations, Server design choices and
   native dispatch claims separate. No numeric-family or ordinal fallback.
5. Validate style, effect phases/targets, costs and transition behavior separately.
   Existing raw-action tool can compare visuals after authorized Client testing;
   current runtime restrictions are not lifted by this document.

No Server behavior or Client changes in this projection batch; normal village,
all-role skill behavior and native MEF completion remain unverified/incomplete.
