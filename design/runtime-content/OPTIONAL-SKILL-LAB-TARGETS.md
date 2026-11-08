# Optional skill lab targets — v66 prepared, not deployed

Live Host remains v63. Normal room-based village entry is still the first manual
acceptance item. These targets enable later skill-effect observation; they do not
replace that village test or establish a full skill implementation.

## Motivation and selection

Previously all SkillLab profiles forced an empty encounter. Animations and resource
costs could be inspected, but there was no recipient for hits, healing reactions
or the new enemy Hold component. Add an explicit optional target mode while keeping
the existing empty scene as the default. This is test infrastructure for gameplay
development, not official dungeon spawn content or native MEF.

The existing local-test SkillLab request accepts `targets: "None"` (default) or
`targets: "Melee"`. The page exposes the choice alongside role/matrix/tier/levels/
energy. Each accepted profile retains this mode through V/Tab selection changes.
Choosing it changes only that isolated lab encounter. Existing IsiliaSkills,
IsiliaSkills500, normal mainline content and scenario/monster files are unchanged.

## Explicit Server-owned training policy

|Setting|Provisional lab value|
|---|---|
|Count/model|Three existing model1036 agents; no new Client asset.|
|HP/damage|1000 maximum HP each,5 damage per attack.|
|Movement|8 world units/sec, matching native movement parameter8; existing collision-aware prototype.|
|Start delay|5seconds before approaching/attacking.|
|Pacing|3second per-agent attack cooldown,2second group gap; existing windup/recovery retained.|
|Entry clearance|At least80 world units from the selected entry pose.|
|Separation|At least16 units between selected spawn points.|
|Lifetime|One finite group per lab entry; re-enter to rebuild.|

The clearance requirement implements the user's request to avoid spawning enemies
beside the player;80/16 are lab choices, not original dungeon data. Never substitute
the mainline node's much nearer spawn positions for this mode.

Placement examines a bounded set of straight rays: radius80,100,120, and32 direction
samples starting at64 with step8 on the existing256-direction representation.
Accept a point only if the entire approach passes the existing CanStand check at
quarter-unit samples and separation holds. Stop at three; do not silently fall
back near the player or on blocked terrain if three cannot be placed. This does
not add general pathfinding or prove dynamic collision/barriers.

Each entry creates the selected player/skills before the usual monster packets and
activation. Agents use the existing Server-owned movement/damage machinery, so
the Hold component can stop their movement independently of in-range attacks.
They are not client-autonomous/native-MEF agents. Stats and pacing are not official
balance. Skill damage, targeting, statuses and visuals retain their own pending
limits; merely supplying targets does not finish those components.

## Progress isolation

Clearing this group must not open a mainline exit, emit result/return flow, grant
EXP/items or commit normal quest victories. Existing six-key test isolation and
local progress override rules remain in force. No database/schema or account skill
grant is added. Empty mode creates no training actors and retains prior behavior.
No automatic respawn loop is introduced. Real Client/model/AI display remains pending.

## Evidence and verification

177 HappyPath passed,0failed/0skipped,63seconds. New cases cover all nine roles'
three-target entries/default empty restoration, entry clearance and separation,
actor creation before health initialization, retained mode across a configuration
change, delayed approach and clearing all3000 training HP without story return.
Host Release build passed0warnings/errors. Extracted JavaScript syntax and the
page-flow simulation passed, including target mode in the submitted request.

A separate local .NET probe invoked the **compiled Server placement implementation**
against actual Road191 static BND SHA256
`adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58`.
For entry418/385 it selected498/385,387.3853/458.91037 and361.43146/441.56854;
all were at least80 units away with clear sampled approaches. The probe result is
recorded in the validation receipt. It is a static Server placement check, not
an original Client gameplay, model-loading or dynamic-pathfinding acceptance.

Prepared counts remain179 candidates/881 slots,64 unavailable. No new motion,
opcode, Buff ID, Client file, original resource or native MEF format was introduced.
Normal room-based village and target-mode human acceptance remain pending.
