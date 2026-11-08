# 群羊暴走 whole-clip comparison — v64 prepared only

Normal room-based village entry remains the first manual acceptance item. Live
Host stays v63/source94e60d735bfe90921e6c17e4d16c6996731a4234; no tiny Host swap.

## Source boundary and adopted hypothesis

Grnt role6 /Practice277 /Active3056 occurs at KR matrix5, tier1, column2/X mask2.
KR describes sheep coming from behind and running in three branching directions;
TC describes three rows. Both descriptions retain the charge prerequisite and a
chance of weak stun. Exact Practice→Active modifiers and Matrix slot were checked
against original/work KR Tables, with full KR/TC descriptions preserved.

Five explicit ABF/ASD clips191/192/193/194/210 reference the same sheep-component
filename. Their EFF declarations distribute sheep elements across three raw
Rotation.Z values0/+0.401426/-0.401426, respectively8/11/16/21/21 per value.
These are render declarations, not proof of three world-space rows, damage hits,
projectile count or duration. No coordinate system/unit or geometry was recovered.

The token is **not unique**. A bounded countercheck of76 EFF references belonging
to existing named Grnt motions found two reuses: BasisScud/motion113 (10 elements)
and AverageScud/motion128 (14 elements). Both declare onlyRotation.Z0. Their reuse
is retained as counterevidence against identifying a skill from the filename alone.
The additional direction pattern and full skill description justify a bounded lab
comparison hypothesis, not a recovered native Active→motion mapping.

All five ASDs are non-repeat; canonical comparison excluding only Header ID/NAME
found differences solely under Effect/Sound references. They share FileID304 and
the same split declaration0..50 atFPS40. Original/work ASD/EFF/ABF bytes agree.
The same-stem `Object/U3_OE_ShapeSheep_FrontStayA_X01.emf` exists in
`Effect/Object.stp` and its bytes agree; this is not native proof that the loader
aliases the EFF's `.gb3` reference to that `.emf` member. Rendering remains pending.

## Server comparison policy

Admit all five complete clips for this exact role/Practice/Active/slot. Rotate one
whole clip per accepted cast in order191,192,193,194,210 and then wrap. This is a
Server-owned comparison order, not a sequence automatically scheduled within a
cast, random selector or learned-level/trait-to-animation mapping. Do not choose
the minimum numeric ID as an alleged official default.

Each cast pays the selected source cost and starts its existing Active cooldown
once. Level1 SP200/MP200 and rawcooltime550 remain unchanged. Existing charge
consumption restores base icons while the admitted action remains latched. The
current unverified resource estimate1.25seconds is retained for all five clips;
it is not a recovered playback clock/cancel window. Projectile paths, damage,
weak-stun probability/duration, interruption and learned-level variants remain
unfinished. Prototype attack behavior is not promoted to a full3056 implementation.

Prepared totals become179 distinct lab motion candidates /881 of945 matrix
slots,64 active IDs still unavailable. These are not fully implemented skills.
Official/native mapping counts receive no completion credit. No Client files,
original resources, native MEF schema or game operation changed.

## Reproduction and validation

Source package:`governance/client-variants/20261107-all-skills-unlock`.
`audit_grnt_sheep_component.py` reads the bounded original/work members and exact
reference countercheck. It does not rescan the294 numeric ASDs. Its initial UTF8
reader was corrected to respect declared EUC-KR in an older named EFF. The first
matrix traversal was corrected to traverse SkillMatrix through the XML wrapper;
the final audit asserts the one exact slot. Earlier exploratory outputs are not
the published source pin. A loose-name workspace query returned no file and was
not used as absence proof; only explicit package references support this report.

Published source review SHA256:
`b65d29be680c251a8f0332f573442010b54039043c4f3e98f65c0fdaf70da1f6`.
`project_grnt_sheep_candidate.py` pins this review, enforces the exact slot, checks
the reuse/direction/canonical boundaries and produces a separate binding output.
Projection reproduced byte-identically to the prepared Server binding metadata.
Positive-test results are recorded in the v64 receipt; no original Client pass
or deferred behavior testing is claimed.

172 HappyPath passed,0failed/0skipped,61seconds; Host Release build passed with
0warnings/errors. The added positive case verifies all five clips plus wrap,
one action/payment per admitted cast, unchanged exact slot/tier and restoration
to base after charge consumption, recharge and no scheduled extra action.
The all-role matrix check retains945 slots and now counts881 ready slots.
