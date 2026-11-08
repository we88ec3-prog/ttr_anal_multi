# 群羊暴走 weak-stun component — v67 prepared only

Live Host remains v63. Normal room-based village entry remains first for manual
acceptance. This extends the already admitted Grnt3056 comparison candidate with
a partial enemy gameplay effect; it does not establish its native motion mapping.

## Reviewed source

Active3056/Practice277 explicitly names weak stun: KR `약한 기절`, TC `輕微暈眩`.
It matches BuffExplain39, not ordinary stun13 or movement-only Hold12. Buff39
describes inability to act and release on damage, with raw time4/5/6/7/8 at
levels1..5. KR Active prose says damage has a high chance of releasing it, whereas
the Buff explanation and TC text state release on damage. Do not silently turn
that difference into a recovered numeric probability.

Evidence `grnt-weak-stun-source-boundary-v1.json`, SHA256
`8f5841ee0ebffae0bf83212816d35ff1674081960665d1d4672d1526c9fd1cc5`,
pins original/work KR and TC Table members and the existing Practice/matrix/full
description reviewSHA `b65d29be680c251a8f0332f573442010b54039043c4f3e98f65c0fdaf70da1f6`.
No new archive-wide animation search or native method/MEF/provider run occurred.

## Explicit Server lab choices

- Apply only for role6/Active3056 at exact source Active levels1..5, after the
  existing prototype hit against a surviving enemy. No other skill or trait is
  granted weak stun just because its description mentions the phrase.
- Use equal Active/Buff level and raw time interpreted as seconds:4..8. Neither
  native level conversion nor timer units are established.
- Guarantee application and release on later positive damage for observation.
  Both100% rates are labelled lab choices; official numeric rates remain unknown.
- Retain current prototype forward targeting/range65 and X damage35. This is not
  a simulation of three sheep trajectories, projectile counts or official damage.
- Latch the admitted plan before successful V consumption restores base skills.

## State behavior

Each enemy keeps a separate weak-stun deadline. At application, cancel pending
Server-owned melee windup/action deadlines, stop walking and publish the existing
idle state. During this deadline the agent cannot move or begin another attack;
exclude it from group attacker selection so other enemies may act normally.
Cancelling a pending prototype melee hit is a lab policy, not proof of what the
original game does to an independently launched projectile (not implemented here).

On expiry, the enemy resumes normal movement/attack eligibility with its existing
cooldown/group pacing deadlines. On a later positive player hit, remove the old
weak stun before any new effect from that hit is applied. No periodic damage or
ally-source damage handling is claimed; those systems remain unfinished. Death
clears its root/stun deadlines. The caster's animation/input recovery is independent.

Movement-only Hold retains its separate deadline: it does not disable nearby
attacks. Clearing weak stun must not clear unrelated root state. Overlap/recast,
adversarial timing, interruption categories and stress cases remain deferred;
this batch does not schedule those suites or claim stacking acceptance.

No new Buff0077 identity, enemy Buff icon/EFF packet, guessed native stun FSM state,
Client edit, persistence or native MEF format is introduced. The existing idle
publication is not a rendered stun-pose implementation. The page displays duration,
guaranteed lab application/removal and pending state visuals. Full skill mechanics
and Client acceptance remain incomplete.

## Validation

180 HappyPath passed,0failed/0skipped,63seconds. Three new cases cover levels1/5,
stopping a moving recipient, preserving another enemy's actions, independent
expiry/chase, retained source costs and base restoration, cancellation of a pending
prototype melee hit and a later damaging hit restoring attack before expiry.
JavaScript syntax and the existing page-flow simulation passed. Host Release
build and source reproduction are recorded in the v67 validation receipt.
Prepared counts remain179/881,64 unavailable; live v63 stays178/880 and human-pending.
