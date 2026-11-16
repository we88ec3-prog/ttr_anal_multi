# Fixed healing field — v58 prepared only

Normal room-based village entry remains first priority and its Client acceptance
is pending. User-deferred tests are not repeatedly requested. Live Host stays v53.
This extends v57 impact routing only for Aelt role5 /Active478 /Practice75.
Prepared counts stay178 lab candidates /880 matrix slots;65 actives unavailable.

## Source and accepted portion

The pinned full KR description explicitly says the caster and allies inside the
field gradually recover HP. TC describes gradual recovery for team members inside
the field. This supports a fixed area/periodic healing concept, not a single
immediate self-heal. Exact radius, lifetime, period, amount interpretation, native
field entity/visual lifetime and targeting are not recovered from those sentences.

Reuse `heal-targeting-source-boundary-v1.json`, SHA256
`b23e937b9a4f9a5f1e5d62328900cfc5a823c0fc7ff8a289f665b48cf092cf1b`.
The exact source coefficients at learned levels1/5 are respectively HEAL90+15
and130+35. Those are raw ratio/revision values, not proven per-tick units.
No new original-resource search or native-provider run is needed for this extension.

## Server-owned lab policy

|Setting|Explicit provisional choice|
|---|---|
|Recipients currently connected|Living caster only; other allies remain unfinished.|
|Center|Fixed authoritative position sampled when the existing0.2s prototype impact is processed. It does not follow the caster afterward.|
|Radius|45 world units; no native radius claim.|
|Period|2seconds after field activation.|
|Lifetime|6seconds, regular ticks at+2,+4,+6; no immediate tick.|
|Amount per tick|v57 calibration: `ceil(100*ratio/100+revision)`, magic attack100, floor0 and HP cap500. This is not the official formula.|
|Cost/cooldown|Original selected learned-level costs charged once at admission; ticks do not charge or restart cooldowns.|
|Leaving/re-entering|Tick only while inside the fixed circle. Outside ticks are consumed; re-entry receives only remaining future ticks.|
|Observation gaps|No historical position is invented. Skip missed deadlines, evaluate at most one current tick per field per poll; expired fields do not backfill healing.|
|Ownership/lifecycle|Per combat object, one field per source Active; accepted recast replaces that field. No DB/progression persistence or shared-world authority.|

Field creation captures the accepted Active and impact plan before charge reset
changes the base skill group. Its timer is independent of the animation/input
deadline, so field lifetime does not extend movement locking. Death suppresses
recovery and clears fields on the next effect poll; a new combat object owns a new
empty scheduler. Recast/death/observation-gap stress cases remain untested/deferred.

Apply HP changes through existing normalized actor HP and absolute resource totals.
No timer rebuild, heal-result opcode/flag, field-spawn packet, artificial animation
chain or Client resource modification is introduced. The current action122/EFF
remains the presentation candidate; persistent visual alignment/lifetime requires
manual confirmation and is not proven by the Server scheduler.

This mechanism is independent Server code, **NOT_NATIVE_MEF**. No native MEF
format, file transfer or AI authority is established by its completion.

## Remaining gameplay

Other allies, native numeric balance, source healing stat, periodic visual entity,
native timing and radius remain open.3024 has additional outside-ally guided
healing and still lacks an admitted motion; it is not unlocked by borrowing122.
Grnt481/2518, Aelt2511 and Epds1407 retain their own projectile/chain/aura gaps.
Five v57 instantaneous self components retain their prior calibration unchanged.

The test page explicitly displays the field's provisional radius, interval,
per-tick amount and lifetime. This is partial gameplay development, not full
skill acceptance, multiplayer testing or an original Client pass.

Validation:149 HappyPath cases passed,0failed/0skipped,60seconds. The two field
cases use supported learned levels1/5 and check delayed ticks, source cost once,
charge reset, a fixed center, walking outside and back, remaining lifetime,
enemy HP unchanged, HP totals and unchanged cooldown sweep. Host Release build
passed with0warnings/errors; extracted page JavaScript syntax passed without
execution. No original Client or deferred behavior suite ran.
