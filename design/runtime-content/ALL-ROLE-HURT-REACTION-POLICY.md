# Nine-role hurt reaction — v69 preparation

Normal room-based village entry remains the first manual acceptance item. This
change fixes a role4-only restriction in the private Server prototype; it does
not complete the remaining skills. Live Host remains v68 until a later batch.

## Bounded source

`governance/client-variants/20261107-all-skills-unlock/audit_all_role_hurt.py`
rechecks nine exact original/working ABF members and their ATTACKED ASD members.
Each role has ABF9 -> ASD header9, non-repeating FileID9, frames0..20 at FPS40,
delay0. Member identity is checked against the earlier all-role motion index.
The index and original resources must be supplied locally; they are not bundled
game resources or a public redistribution of the raw XML.

The pinned KR executable SHA is
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`.
Rooted Capstone windows show the common character constructor4CD6F0 passing
state5 to4CB230, setting motion+38=9, input flag+2C=1 and vtableC0799C.
Base constructor stores the state argument at+8. The vtable's Enter4CB870
requests that motion through actor virtual+68 at speed1. Actor+418 receives raw300;
its units and downstream meaning are not established here.

Evidence: `all-role-hurt-source-boundary-v1.json`, SHA256
`352e90896abc360c0eea23eee32b9cedecbf485fe33cdc9b86ceccba2e84bfe5`.
These limited instructions and nine member joins do not establish a whole-function
FULL-PASS, per-role runtime acceptance, native armor or official emission timing.
Nominal20/40 clip duration is not the native input lock or cancel window.

## Server behavior

Extend the existing state5 path from role4 to supported roles1..9 when positive
enemy damage leaves the player alive, no admitted action is running, and the
reaction trigger cooldown has expired. Stop movement and send existing000C state5;
do not request motion9 through000D/SkillState13.

Retain provisional Server values: reaction0.15seconds, trigger cooldown0.9seconds.
Damage continues during trigger cooldown. An active admitted skill continues
without a hurt-state overwrite; this is an explicit responsiveness policy pending
native armor/cancel evidence. A valid later action can supersede the short reaction.
After the reaction, restore only the latest fresh movement intent (existing750ms
freshness rule). No stale movement extrapolation, new key mask, packet or Client
modification is introduced. Existing death handling remains independent.

The synthetic checks cover each role's moving hit, stop/recovery, positive damage
without retrigger during cooldown and a later retrigger; an additional nine-role
loop checks that admitted X actions remain active while taking damage. These prove
Server packet/state behavior only. Actual motion, control feel, balance and all
remaining skill functionality still require separate validation.

No native MEF format, Client AI control, full monster behavior, new active-to-motion
mapping or complete skill implementation is claimed. Candidate counts remain
179 actives/881 slots;64 actives remain unavailable.

## Validation

191 HappyPath cases passed,0failed/0skipped, including10 new cases. The existing
weak-stun positive test now checks the Grnt player's brief hurt/recovery after
the enemy resumes its attack instead of assuming role6 never flinches. Host
Release build passed with0warnings/errors. Source audit passed for all nine
roles and bounded registration/entry bytes. See `v69-validation.json` for the
TRX digest and scope. No deferred suites, Client execution/modification or
Host replacement occurred. Actual Client acceptance remains pending.
