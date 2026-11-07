# GAME_RUNTIME_OBSERVATION: resource recovery restarts cooldown sweep

## User report — 2026-11-07

During v28 skill-icon testing, insufficient resources greyed the skill while a
cooldown was in progress. When resources recovered midway, the icon brightened
but the radial cooldown sweep restarted. User expects the resource availability
brightness to change while the original cooldown progress continues.
Client last reported v5; this specific report does not independently identify
which skill/remaining duration or executable image was used. Do not invent them.

## Confirmed current Server behavior

LocalTutorialCombat.RecoverResources publishes normalized resource updates plus
typed ResourceSnapshot, then calls AvailabilitySnapshot when SP or MP changes.
AvailabilitySnapshot emits EnterCombat (012A, reset DWORD1) followed by a full
CombatAvailability map (012A, reset0) containing current remaining milliseconds.
The Server _cooldowns dictionary stores absolute deadlines; resource recovery
does not assign new deadlines. Therefore remaining duration and radial starting
ratio are distinct issues.

Existing bounded native analysis in anal/CONTROL-AND-SKILL-SOURCE.md describes
4B1A00 ->545E20: reset!=0 clears the actor timer map; reset0 converts values with
signed /33 and writes both total and remaining counters. This directly supports
the concern that full refresh recreates the timer basis. It does not newly prove
the complete icon rendering chain or official wall-clock units. The user's
observation supplies the actual modified-copy UI symptom.

Other current full refresh triggers include rejected actions, another skill
launch and timer expiry. Fixing only resource recovery must not be represented as
closing all unrelated timer restarts; each needs bounded review.

## Server-only correction requirement

On resource-only change publish resource values, preserving existing timer
entries, total duration, remaining countdown and original Server deadline.
Do not reset the full cooldown map or republish unchanged active cooldowns merely
to change resource greying. Brightness reflects resource eligibility; a bright
icon may still be cooling down and must not bypass Server admission.
At battle setup a full context snapshot may remain necessary. Skill start and
expiry need appropriately scoped updates without restarting other active timers.
No Client/resource/font patch is required for this Server-side correction plan.

## Acceptance scope

A normal positive regression should cast near a scheduled resource-recovery tick,
observe resource values increase during an active cooldown without a cooldown-map
reset/reinitialization, and preserve the original deadline. Then human-check
brightness plus continuous radial progress on the same skill. Separately verify
casting another skill does not reset its existing neighbors' sweeps.

Status: REPORTED / SOURCE_CONFIRMED_REFRESH_TRIGGER / FIX_NOT_YET_APPLIED.
Live Server remains v28; no new deployment or human pass is claimed in this report.
