# Returning fist delivery — v72 preparation

This is a shared Server-only returning-projectile mechanism, first admitted only
for Pipa2/Practice216/Active2995 奮力之拳 in its existing matrix3/tier2/C(mask4)
lab slot. It is not native projectile dispatch, a full skill implementation or
native MEF. Live Host remains v71 pending a later combined batch. Normal room-based
village entry remains the first actual Client acceptance item.

## Bounded original evidence

KR text explicitly describes a fist attacking forward and pulling enemies as it
returns. TC confirms the forward attack/pull and emission-state requirement, but
does not independently specify the return leg. Neither text specifies another
damage event on return, gameplay projectile count, range, speed, hit radius,
pull distance or immunity/forced-move rules.

The four previously reviewed EFFs declare2/2/2/4 fist elements. First EFF includes
positionsX±33/Y−30/Z30 and raw delay11. These are rendering declarations, not proof
of world projectile count, gameplay coordinates, travel curves or a native clock.
No geometry, new native opcode or EFF-derived trajectory is invented from them.

`pipa-returning-fist-source-boundary-v1.json` SHA256:
`d6ff7fd7da8d8c7016a194418f402896bd7285ba39c815c29df58ecad9b666ea`.
The companion audit pins original/working Table and four exact EFF members and
the earlier component reviewSHA6a93bd097a95556d132ce8775f988ff2fd68b1761dbd3d26442941392f542873.
Raw original resources remain separately supplied and read-only. No source archive
inventory rescan, Client execution/edit or native MEF transfer claim.

## Explicit reconstruction plan

Export schema `LOCAL_RETURNING_PROJECTILE_V1_NOT_NATIVE_MEF`, authority
`SERVER_RECONSTRUCTION_NOT_NATIVE_MEF`; use JSON/C# definitions, never a `.mef`
payload or a claim that the Client reads this plan. The schema describes the lab
catalogue's plan object, not a new Server file-loader or native protocol.

| Field | Provisional value | Meaning |
|---|---:|---|
|LabRange|65|outbound centre travel in Server reconstruction world units|
|LabSpeed|80|travel units per Server second|
|LabHitRadius|16|swept-volume radius, additional to centre travel|
|LabOutboundDamage|60|existing C-key prototype damage, once per recipient|
|LabReturnDamage|0|no invented second damage event|
|LabReturnPullDistance|20|max pull per return recipient|
|LabPullStopDistance|8|minimum intended distance from current owner pose|
|LabMaximumLifetimeSeconds|4|max Server observation lifetime|

One aggregate logical volume is an explicit test approximation, not a conclusion
that native rendering's two/four elements are one projectile. All four admitted
whole-clip variants share this provisional plan; learned level changes its exact
source costs/coefficients but does not infer native trajectory variants or scale
the60 prototype damage by a recovered formula.

## Engine and combat integration

1. Pay source cost once on admitted cast and retain existing motion/cooldown/V
   consumption. At the existing0.2-second impact observation, launch from the
   current owner pose using captured cast direction. Suppress the old immediate
   generic forward hit for this plan; do not apply both damage paths.
2. Advance a swept segment with elapsed Server time capped at0.25seconds per
   observation. Use current target positions only; no historical target backfill.
   Each target can be contacted once per leg. Outbound damage excludes targets
   behind the launch direction. Return may contact a target missed outbound.
3. At max range or a blocked outbound segment, turn toward the current owner pose.
   Use remaining travel budget on the return leg. Stop at owner, lifetime expiry
   or a blocked return path. Owner death/encounter cleanup discards flights.
4. Sample existing static BND walkability every0.25 travel units for flight and
   line-to-target occlusion. This is a conservative lab collision policy, not
   recovered native projectile-height/wall logic. Do not hit across a blocked
   line merely because the target is inside the capsule radius.
5. Apply outbound damage through the shared existing damage/death/status path.
   Return contact applies no damage or extra cost; move a surviving enemy toward
   the current owner by at most20, stopping outside8 and before blocked ground.
   Publish existing authoritative position16, not a guessed forced-move/stun
   packet. Existing melee deadlines/armor behavior are not newly cancelled.

Projectiles are internal combat objects keyed by source Active ID, not spawned
network actors. No new projectile/return/displacement/MEF opcode or Buff identity.
No native pull animation, boss immunity, party target ownership, simultaneous
recasts or stacking acceptance. Existing35-second source cooldown prevents a
normal same-skill recast during this4-second lab lifetime; broader overlap rules
remain deferred. The shared helper is reusable, but no other skill is automatically
granted returning behavior by name or attribute.

The page exposes provisional range/speed/damage/pull alongside remaining native
count/trajectory/hit/pull values and forced-move animation gaps. Existing input
recovery, basic buffering, charge costs, NPC/progress/persistence and normal village
entry are not redesigned by this change. Coverage remains181 comparison actives/
883slots with62 unavailable; full skills and Client compatibility remain pending.

## Validation

201 HappyPath cases passed,0failed/skipped. Four added positive cases cover exact
level1/5 MP150/230, no immediate old generic damage, one outbound damage per
recipient, zero extra return damage/payment, clamped pull, rear-enemy exclusion,
normal recovery, wall turn/occlusion and return toward the current owner pose,
including a target missed outbound. Existing shared damage/death/hold/stun/frostbite
and normal journeys remain covered by their retained positive checks.

Host Release passed0warnings/errors. Source audit reproduced byte-identically;
JS syntax and the DOM fixture passed new calibration/pending labels and existing
level/target POST behavior. A compiled probe of the author's own Server assembly
exported level1/5 plans and exact MP costs; no game or listener was started. The
two exported plans match the independent JSON schema's required fields, constants
and numeric constraints. This was a bounded property check, not a full external
JSON Schema validator run. Examples and digests are in the companion evidence
package and `v72-validation.json`. Actual native trajectories, forced-move visuals,
official formulas and Client acceptance remain pending; deferred suites unrun.

After the201-case run, the implementation stayed unchanged. The two level1/5
combat fixtures were strengthened to place a rear target within8 units, covering
forward-only outbound damage and the minimum pull distance. Both refined positive
cases passed in a targeted rerun; both TRX identities are retained in the receipt.
