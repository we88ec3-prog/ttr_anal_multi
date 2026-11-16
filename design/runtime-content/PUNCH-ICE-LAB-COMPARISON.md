# Punch and ice semantic comparisons — v70 preparation

Status: two explicit SERVER_DESIGN_CHOICE comparison candidates, not recovered
native active-to-motion mappings or completed skills. Live Host remains v68.
Normal room-based village entry remains first for manual acceptance.

## Finite source review

The existing numeric-effect projection identified a fist component for Pipa and
ice components for Crmd. Recheck only eight selected ABF/ASD rows and their direct
EFF references, the two exact Practice/Active/matrix records, full KR/TC skill
descriptions and the two roles' already indexed named-motion EFF references.
There is no294-family rescan or family-number/skill-order assignment.

`punch-ice-component-review-v1.json` SHA256:
`6a93bd097a95556d132ce8775f988ff2fd68b1761dbd3d26442941392f542873`.
The companion `audit_punch_ice_comparisons.py` checks original/working member
identity, prior declared-file projections and exact IDs. It requires separately
supplied local resources and previous motion/numeric indexes. Raw game members
and complete source XML are not redistributed.

| Role / Practice / Active | Exact KR slot | Comparison clips | Finite semantic relation |
|---|---|---|---|
| Pipa2 /216 /2995 奮力之拳 | matrix3,tier2,C(mask4) |196,197,198,199| Each EFF declares `C_Pipa_Powerpunchi.gb3`; full text describes a forward fist and pull on return. |
| Crmd7 /255 /3034 冰凍暴風 | matrix6,tier0,X(mask2) |188,189| EFF declares IceStone02/04 components; full text describes forward falling ice spikes and possible frostbite. |

Pipa component counts are2/2/2/4, and Crmd's selected counts are5/18. These are
rendering declarations, not gameplay hit/projectile counts. The component is not
proven globally unique. The bounded Pipa named-role EFF scope found no reuse;
Crmd's existing SuperThornyIce motion197 reuses IceStone01. That reuse remains in
the evidence rather than being hidden as a unique-ID bridge.

Crmd motions186/187 were reviewed but contain none of the selected literal
IceStone token. Do not admit them merely because they share the numeric family.
All eight reviewed ASD trees differ only in EFF/Sound reference paths after
excluding header ID/NAME. This supports bounded comparison, not automatic
variant equivalence in appearance or a native selector. No geometry or rendered
trajectory is established by this review.

## Explicit lab implementation

Allow only these two existing exact slots to cycle the selected whole clips,
one clip per accepted cast. Cursor advances only on admission, wraps after the
last clip and is independent of learned level. Retain all945 slots, existing
Practice IDs, Active IDs, learned-level costs, matrix and tier.

Pipa's default level1 consumes150MP and remains tier2/emission-related; successful
cast restores base under the existing lab charge policy. Crmd default level1
consumes60MP. Existing cooldown and0126 publication are unchanged. V/Tab keep
the current independent skill-level configuration; there is no new charge bypass.

`project_punch_ice_candidates.py` pins the source report, requires exact token
counts and non-repeating clips, selects only those six clips and modifies only
Motions/Durations/Status on the two bindings. Unrelated rows must remain identical.
The duration sum uses the existing unverified estimate `(EndFrame+Delay)/FPS`;
negative delays remain visible. This is not a native animation clock, skill lock,
cancel window, projectile impact or multi-phase playback schedule.

The generic prototype attack remains a provisional observation aid. The page
explicitly lists unimplemented fist flight/return hit/pull, and ice-spike targeting,
multi-hit/frostbite chance/movement and attack-speed reductions. No fake frostbite
Buff, guessed displacement, added packet or native MEF data is sent.

Prepared coverage becomes181 comparison actives/883slots, leaving62 unavailable
actives out of243. These are animation-test candidates; all181 still have separately
unfinished mechanics, official dispatch and Client acceptance. Do not report them
as181 complete skills or close the full all-role skill requirement.

## Validation

193 HappyPath cases passed,0failed/skipped, including two new positive comparison
cycles. They verify exact slot/Active ID, one action and payment per admission,
full selected cycles and wrap, base restoration, normal short-V return to Pipa's
source tier, no automatic extra phases, and explicit pending-effects metadata.
The matrix catalogue check confirms883 enabled slots while preserving945 total
slots/243 unique actives. Host Release passed0warnings/errors. Source audit and
bindings projection both reproduced byte-identically; only two bindings changed.
See `v70-validation.json` for source/bindings/TRX digests and acceptance limits.
No game operation, Client change, Host replacement or deferred suite was run.
