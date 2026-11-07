# Defensive skill mechanics — v59 prepared only

Live Host remains v58/source d2b85b791ce02b250818ddce19b30b77ed398580.
Normal room-based village entry still has first priority and its Client acceptance
is pending. This source batch does not replace that Host or request another test.

## New source and limits

`Table/BuffExplainTable.xml` supplies per-level description values missing from
ActiveTable's ATTACK/HEAL tags. Original/work members agree. Exact Active names
match unique BuffExplain names for these candidates; BuffExplain.no and _BuffList.ID
then give an exact shared-identifier join to the effect filename. **Active→Buff
dispatch and Active-level→Buff-level conversion are not recovered native facts.**
S00 explicitly adopts the four name hypotheses below for the opt-in lab only.

|Role / Active / Practice|Same-name Buff candidate|Source text at levels1..5|
|---|---|---|
|Soma1 /4/4|1|Reduction25,27,29,31,33%; raw time20..24; stated maximum reduction50%.|
|Pipa2 /13/21|2|Reduction17,19,21,23,25%; raw time20..24; maximum50%; physical attack+120,155,190,225,260.|
|Pipa2 /15/22|3|Block6,8,10,12,14 ordinary bullets/normal attacks; raw time15.|
|Sblm3 /25/38|4|Block5,6,7,8,9 attacks of any category; raw time12.|

KR/TC numeric and raw-time rows agree for all five reviewed name candidates.
Their text does not prove stacking, rounding, packet flags or duration units.
The five exact Practice files contain SkillLevel modifiers to the Active only,
not an explicit Buff modifier, so they do not close the missing native bridge.

Isla34→Buff6 is retained as source evidence only. Its42% etc is an evasion
**increase**, not an established absolute hit/miss probability. Levels6..10 also
mention attack speed; level11 literally says200% and is preserved without clamping
or converting it to guaranteed evasion. No evasion roll is implemented here.
No exact same-name BuffExplain entry was found for478 in the two known members;
that bounded absence does not supply or change v58's provisional field timing.

## Explicit lab choices

- Match the selected **Active level**, not blindly the learned Practice level,
  to the same numbered Buff level. Only the four explicit identities/levels1..5
  are projected. No nearest-level fallback or automatic new skill unlock.
- Interpret raw time as seconds for this Server lab. Apply the own-caster portion
  at the existing0.2s prototype impact; capture the plan before charge reset.
- Replace the same-source Buff on accepted recast; keep it per combat object,
  without DB persistence. Clear it when this combat's player dies. Lifetime is
  checked against the monotonic clock at incoming-hit resolution.
- For reduction, choose the strongest live reduction, capped by its description,
  and use `ceil(incomingDamage*(100-reduction)/100)`. Stacking/order/rounding are
  Server choices, not a proven official formula.
- For a shield, consume one charge for one eligible in-range positive-damage hit.
  Blocked hits cause no HP loss, damage-result packet or hurt reaction. Do not
  invent an unverified block/miss flag. Normal-only shields cannot block a skill
  category; all-attack shields accept it. Current prototype agents supply ordinary
  close-range category only; skill/projectile integration remains unfinished.
- If both shield kinds later coexist, the current explicit arbitration prefers
  all-attack shield before normal-only shield and consumes just one charge.
  Cross-source arbitration is not native-verified or tested in this batch.
- Pipa13's physical-attack increase is exposed as **declared but not applied**.
  It is a stat modifier, not permission to add120 directly to generic hit damage.
  The source physical-stat/damage formula and equipment pipeline remain open.

Costs/cooldowns stay exact selected-level joins, paid once on admission. The
defence cast itself does not damage monsters. Enemy action/recovery continues
when blocked, and Buff lifetime does not extend player input locking. A shield
expires after its count or lifetime; it is not full-time invulnerability.

No native Buff icon/effect/status packet is added; visual/timer alignment remains
pending. Pipa15 affects only the caster here; nearby allies require shared actor
targeting. Non-lab tutorial/mainline combat retains its prior behavior. All these
structures are independent Server definitions, **NOT_NATIVE_MEF**.

## Evidence and projection

Under `governance/client-variants/20261107-all-skills-unlock`:

|Artifact|SHA256|
|---|---|
|named-defensive-buff-text-candidates-v1.json|e1a10b5ea0fab9eaf52dfaaea46c264f6ce5f3d05aa640db2cb827a22439f419|
|defensive-practice-bridge-boundary.json|6dd4e976211df8921cbbf3829d88726354b54f1f32aecbdb557dd9b3dd331826|
|20-row independent lab projection|19461d041ce97e6039307ad4dc167bc188e1c29a83960b4c42a0fe158fa624e4|

`audit_named_defensive_buff_text.py` and the five-Practice boundary audit are
bounded read-only tools; original game members remain local. The projection tool
pins the reviewed evidence and four explicit hypotheses. No game operation,
provider setup, all-motion rescan or native MEF search was performed.

Prepared lab counts remain178 candidates /880 slots,65 unavailable Active IDs;
these partial defensive mechanics are not full-skill or native compatibility passes.

Validation:153 HappyPath passed,0failed/0skipped,61seconds; Host Release build
0warnings/errors; page JavaScript syntax passed without execution. Eight new
normal cases exercise selected levels1/5, reduction expiry, finite charges,
exhaustion followed by damage, exact cost and plan retention across charge reset.
The initial eight cases failed because the synthetic fixture inherited a2second
startup while scheduling earlier hits, and the expiry fixture moved the enemy
outside attack range. Only the fixture was corrected; the failed TRX is preserved
beside the passing rerun with hashes in `v59-validation.json`. Existing149 minus
four formerly-pending-only cases plus eight new mechanics cases gives153.
No cross-source, skill/projectile admission, replay/concurrency/fault/security/load,
death/recast stress or original Client testing was run.
