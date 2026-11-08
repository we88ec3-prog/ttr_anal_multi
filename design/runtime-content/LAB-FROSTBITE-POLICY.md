# Crmd frostbite component — v71 preparation

Normal room-based village entry remains first for manual acceptance. This extends
only the admitted role7/Practice255/Active3034 comparison with a partial gameplay
component. It does not recover native active-to-motion dispatch or complete the
ice-spike skill. Live Host remains v68 pending a later combined batch.

## Source versus Server choices

KR/TC Active3034 explicitly describes frostbite: `동상` / `凍傷`. It matches
BuffExplain28, not Hold12, ordinary stun13 or weak stun39. The exact Buff28 rows:

| Buff level | Raw time | Declared attack-speed reduction |
|---|---:|---:|
|1|5|20%|
|2|5|22%|
|3|6|24%|
|4|6|26%|
|5|7|28%|

Movement speed is described as reduced, without a numeric percentage in these
rows. `_BuffList` declares `S_Dbuff_BasisFrostbite01.eff`; this alone does not
establish an enemy Buff/FX packet emission contract. No effect is sent from that
filename alone.

Evidence `crmd-frostbite-source-boundary-v1.json` SHA256:
`f038be108b98590665413433a86de73408f817919de5ac20f858a9f172c29f37`.
The audit rechecks four exact Table members in original/working KR and TC; it
preserves all five texts, raw times and visual declaration. No archive-wide scan,
new native method audit, geometry search, target execution or MEF investigation.

The following are explicit provisional Server lab choices: equal Active/Buff
level, raw time interpreted as seconds, guaranteed application after a positive
hit to a survivor,20% movement reduction, and reciprocal timing for an attack
rate reduction. Native grant, chance, level conversion, clock, immunity, stacking,
dispel and damage-release rules remain unverified. Other ice skills are not
automatically granted this effect by name or attribute.

## Per-enemy behavior

Each surviving hit enemy keeps its own deadline and movement/attack reductions.
Retain the current prototype forward arc/range65, hit at0.2seconds and X damage35;
there is no new ice-spike area or multi-hit simulation. Do not apply the effect to
an enemy behind the prototype forward arc or to an unhit nearby enemy.

During the effect, multiply Server movement distance by0.8 and publish the existing
movement-speed parameter6 multiplied by0.8, rounded to nearest positive integer.
Integer native speed versus continuous Server position remains a rendering
limitation; no new interpretation of native speed units is claimed. The existing
collision and authoritative-position path is retained.

New melee admissions snapshot attack rate `r=1-reduction/100`. Schedule windup,
recovery and that enemy's next-attack interval divided by r, and use r in the
existing000D animation SPEED field. Preserve the global group-attack gap, so an
unaffected enemy is not slowed by another enemy's debuff. This is not a blanket
attack prohibition, AI replacement or native status-state implementation.

An already admitted melee keeps its existing impact/recovery/cooldown deadlines;
application/expiry does not retroactively cancel or accelerate it. On expiry,
restore movement parameter6 and use rate1 for future attacks. A previously admitted
slow attack finishes under its snapshot. Root/stun deadlines remain independent;
expiry is processed even while those effects prevent movement. Death clears the
frostbite deadline. Overlap/reapplication and adversarial timing remain deferred,
not newly accepted by this normal-path implementation.

The page displays duration, source attack reduction and provisional movement20%/
guaranteed application separately, with unfinished status visuals, official proc/
movement ratio and ice-spike targeting/multi-hit still listed. No enemy0077 Buff
packet, new native FSM state, guessed EFF request, Client edit or native MEF data.
Prepared candidate counts stay181/883,62 unavailable; complete skills and actual
Client/model/animation/control acceptance remain unfinished.

## Validation

197 HappyPath passed,0failed/skipped. Four added cases cover levels1/5, targeted
movement reduction/restoration, an unaffected rear enemy, source attack rates in
000D, slower windup/cooldown, unchanged other-enemy action rate and post-expiry
future attacks. Host Release passed0warnings/errors. Source audit reproduced
byte-identically. JavaScript syntax and `check_frostbite_page_flow.cjs` passed
source/calibration/pending-effect labels alongside existing catalogue-fetch,
picker, per-key level and target POST behavior. The DOM harness is a synthetic
presentation fixture, not an actual game skill/resource or native UI test.
See `v71-validation.json`; Client acceptance remains pending.
