# Enemy Hold component — v65 prepared, not deployed

Current live Host remains v63. Normal room-based village entry stays first for
manual acceptance; the user deferred testing. This work adds a partial gameplay
component to an already admitted Grnt skill, not another motion mapping.

## Source and boundaries

Grnt6 /Practice93 /Active483 describes an attack field around the caster and a
high chance of Hold. KR explicitly names `홀드`; TC names `拘束`. Both describe
movement prevention. BuffExplain12 has raw times10/11/12/13/14 at levels1..5.
Practice93's five SkillLevel modifiers explicitly target483. These exact original/
work KR and TC members are recorded in `grnt-hold-source-boundary-v1.json`, SHA256
`0a8e80674d2cfef12071b7b872738df3ff66553741f041682294356d598dc72b`.

Hold is not stun. Neither description says to forbid attacks/skills, clear an
already launched attack, break on incoming damage or drain resources. Do not
borrow those effects from similarly translated binding/suppression statuses.
T10/T11's existing native targeting/timing/formula gaps are not closed by this
Table review; their task owners, source reports and acceptance states are unchanged.

The following remain explicit **Server lab choices**: same Active/Buff level,
raw time interpreted as seconds, radius65, impact at the existing0.2s prototype
point, and guaranteed application for observation. “High probability” does not
establish an official100% chance. The page labels guaranteed application. Normal
tutorial/mainline combat without an explicit lab profile is unchanged.

## Prepared behavior

Capture the accepted advanced effect plan before V consumption restores the base
configuration. At its impact, evaluate living enemy recipients inside a circle
around the current caster position, including behind the caster. The source says
surrounding field, so this skill does not use the generic forward half-plane.
Radius/timing/center sampling remain provisional. Current prototype X damage35
is retained; it is not the recovered per-skill attack formula.

A surviving recipient gets an independent movement deadline. If already walking,
publish its existing movement-stop packet and, when not attacking, idle state.
Do not send a stun state or cancel its ongoing attack. During the deadline the
Server enemy agent cannot chase or emit new walking positions; attacks against
an in-range player remain eligible. When the deadline expires, normal chase can
resume. It does not extend the player's cast/charge/input lock. Newly entering
enemies are not automatically rooted: this is a recipient set sampled at impact,
not a continuously applying trap. Death removes the movement deadline.

Enemy state is per combat instance and is not saved as quest/account progress.
Recast replacement uses a new deadline as an explicit lab policy; recast, death,
overlap, observation-gap and adversarial cases remain deferred rather than newly
scheduled tests. There is no shared/multiplayer authority or native MEF change.

No new Buff0077 IDs or enemy Buff packets are introduced. The existing owner
defence allowlist remains unchanged. Enemy Buff icon/EFF publication and exact
native grant/level semantics need separate verification. The page displays the
partial Hold calibration, with state visuals marked pending. This is not a full
483 skill, native probability or native timing acceptance.

## Validation

Positive cases exercise levels1/5: stop already moving enemies, affect a surviving
enemy behind the caster, leave the outside recipient walking, preserve the latched
advanced plan after base restoration, resume chase after10/14seconds, retain a
nearby enemy's attack and restore caster movement independently. Source audit and
build/test receipts are in the all-skills evidence package. Candidate counts stay
179/881 prepared,64 unavailable; live v63 remains178/880 and human-pending.

175 HappyPath passed,0failed/0skipped,62seconds; Host Release build passed with
0warnings/errors and extracted page JavaScript syntax passed without execution.
The source audit reproduced byte-identically. No original Client, native provider,
Client modification or deferred behavior suite ran. No new motion or Buff opcode
was invented by this component.
