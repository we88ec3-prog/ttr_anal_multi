# Buff map snapshot0077 — v60 prepared, not deployed

Live Host stays v58. Normal room-based village entry remains the first manual
test; the user deferred testing. This is a bounded KR receiver contract plus
explicit lab publication policy, not official Server sequencing or full T11 acceptance.
Original target SHA256:
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`.

## Evidence chain

Native493170 registers494750 at fullClient+978. The normal processor's function
slot base is fullClient+208 with16byte stride, giving `(978h-208h)/10h=77h`.
This is register-value/operand evidence, not an opcode guessed from class names.

Callback4930E0 accepts application lane2. Callbackthis is Client+148; its+B8
processor is fullClient+200, whose VT slot points to48AAD0. The known primary
socket0/8416 also uses lane2. **Lane2 is not socket slot2.** The explicit0077
callback494750 forwards the payload to4D2E40 without routing through the scene.

4D2E40 finds actors using a WORD key in FAB138, clears only each included actor's
embedded map at+3F0 and rebuilds it from supplied records. A missing actor skips
its records; included actor/count0 clears that actor. It does not clear all actors.
The wrapper does not forward payload length and the native consumer has no proved
packet-bounds checks; the independent Server emits only bounded known shapes.

4C9840 uses ESI=actor/CX=ID and two byte stack arguments.4CA0B0 searches/inserts
the WORD-keyed map and returns node+10.4C997E/4C9992/4C99A6 store ID WORD,
first argument BYTE and second argument BYTE. The same function also creates
indexed visual attachments at actor+164+ID*4. The old attachment audit covered
that visual path only; it was not evidence of no Buff-map mutation.

The independent UI chain68B260→68B1E0→4D2DA0/4D2CC0 reads actor+3F0. Packed value
low16 feeds BuffSlot+248 ID; bits16..23 feed+24C level and BuffExplain lookup.
The high byte remains opaque.6BE950 reads static level descriptions; it does not
establish remaining time. Cleanup helper4C83C0 can remove absent indexed effects
when actor+36C==0, but complete scheduling/visual result remains unverified.

## Inner payload

|Offset|Type|Meaning|
|---|---|---|
|0|WORD LE|0077|
|2|BYTE|Actor count; lab uses1.|
|3|WORD LE|Existing owner actor entity ID.|
|5|BYTE|Number of records for this actor.|
|6+4i|WORD LE|Buff ID.|
|8+4i|BYTE|Buff level consumed by the reviewed UI chain.|
|9+4i|BYTE|Opaque value, lab emits0; not claimed seconds or remaining charges.|

General receiver shape repeats actor header3bytes then4bytes per Buff. The lab
builder intentionally supports only one owner, reviewed IDs1..4, levels1..5 and
at most4 distinct entries. These IDs avoid arbitrary native indexed attachment
access. Empty owner snapshot is6bytes; it removes this owner's list. Normal frame
transport remains the existing working-copy primary transport.

## Lab publication policy

- Only explicit skill-lab combat uses this emitter. Normal tutorial/mainline
  characters are not given guessed Buff snapshots.
- Initial/rebuilt owner state sends its complete current implemented defence list
  **after** actor creation and owner/controller binding. It does not send against
  an absent actor or use account alias as an actor ID.
- Snapshot all implemented live defence Buffs together after apply/recast. This
  receiver is replacement, so sending only a newly added Buff would delete others.
- On lifetime expiry, charge exhaustion or player-death cleanup, send the remaining
  complete list, including empty when none remain. Expiry is polled even without
  an incoming hit. No repeated unchanged snapshots on ordinary damage or partial
  charge consumption; no invented remaining-count field.
- Do not rebuild cooldown lists, charge resource costs again or alter the prior
  v59 defence formula. Skills/HP/cooldowns and Buff identity lists are distinct.
- Opaque0 and publication points are Server choices awaiting Client acceptance.
  Other native/script statuses are not implemented; this owner-authoritative list
  is confined to the isolated lab, not a universal status reconciliation scheme.

No native remaining-duration protocol, separate incremental add/remove opcode,
original grant/expiration order, gameplay mapping or countdown icon is newly
established. It is partial source-backed integration; manual icon/visual and
charge/matrix regression remain pending. No Client bytes or resources were changed.
Native MEF remains unsupported; all custom gameplay policy staysNOT_NATIVE_MEF.

## Source artifacts

In `governance/client-variants/20261107-all-skills-unlock`:

|Artifact|SHA256|
|---|---|
|buff-ui-actor-map-boundary-v1.json|d9db25deab8d90bac9a4aa8c906286816bd9d6e8104a1b0e0c5207745c007ede|
|buff-snapshot-command-dispatch-v1.json|882b3c11fa8237ce7efaa77936a85d5c25792fa90c96e7c37fa44e488ab4465c|
|buff-snapshot-writer-root-review.json|2e3d7cce77acbcfb31b99db6ac17428a952f048e830f13c948db40b9f63cce06|
|buff-snapshot-effect-members.json|5bfd5e57122c24f99652b12eb8319431c587624a2acb39bd288ea072cbbbc13d|

Four audit tools reproduce these artifacts using original bytes/saved bulk and
known resources only. UI artifact null wire fields describe its earlier scope;
the later dispatch and writer reviews close the specifically listed new chain.
The four named Buff EFF members exist and equal original/work bytes. Their complete
geometry dependencies, actual loading and rendering are not thereby validated.

Validation:154 HappyPath passed,0failed/0skipped,71seconds. Extended owner-order
assertions additionally passed their targeted case covering27 role/tier entries.
Checks include exact multi-record shape, sparse complete grant/expiry/exhaustion
updates and actor-before-snapshot ordering. No Client/game operation or deferred
replay/concurrency/fault/security/load/multiplayer suites ran. These are not an
original Client pass, formal Task full-pass or entire native protocol acceptance.
