# Resource action preview and video matching — v74

> V76 reference-data correction: `action-preview-catalogue-v2.json` preserves all
>294 action entries and carries109 video links, adding two whitespace-repaired
>title joins and retaining one unjoined title with null Active. SHA256
>`15cdfa769491075e5a5fb78b5885602248b2b8480b62296fd1a5ed79475b4593`.
>See `PIPA-GRENADE-VIDEO-COMPARISON.md`. V1 counts/hashes below remain historical.

Purpose: close the missing visual comparison layer, rather than equating numeric
animation names/order or partial effect implementations with confirmed skills.
Video references can identify the intended pose/effect/movement; they do not
directly expose the Client's internal motion ID. The missing work belongs to the
local action-to-rendered-appearance comparison, not presumed inadequate user input.

## Finite source whitelist

Reuse the prior294 numeric ASD targets. Recheck the nine roles' exact ABF entries,
ASD header IDs/splits/non-repeat values, direct EFF member hashes and unchanged
original/working carriers. No new archive inventory search. All294 are non-repeat,
covering9 roles and71 numeric families.72 new skills do not imply72 families or
an ordinal assignment. No Active ID is assigned to an action entry.

Source catalogue `action-preview-catalogue-v1.json`, SHA256
`514f9d38c4bf1b451280f3a3bf9d4bb18cb3311c0043405627438f6a46819431`,
has independent schema `LOCAL_ACTION_PREVIEW_CATALOGUE_V1_NOT_NATIVE_MEF`.
The builder requires the previously supplied local indexes and original resources.
Raw ASD/EFF/animation data is not redistributed. Runtime uses the same compiled
JSON whitelist, not a native MEF file or user-supplied motion list.

The catalogue includes106 user-reference video links: exact title/name joins for
roles1/2/3/7 plus the supplied role4 level-change reference. It does not claim all
videos were visually reviewed, complete reference coverage for all nine roles,
or an action-to-skill match. Reference links and action entries stay separate.

The bounded seven-member Soma follow-up (`soma-numeric-animation-name-scope-v1.json`)
found numeric declared GB3 names and same-stem gzip EMF candidates; an embedded
Soma_012 token even differs from Soma_011's filename. These are not semantic
skill IDs, a recovered native alias, a full binary parser or MEF AI scripts.
Do not infer a global absence of links from this name/token scope.

## Isolated Server mode

On the existing loopback test page, choose a role and raw motion, enter the empty
lab and press Z once. Selection uses the existing serialized connection-loop
override; no game launch or Client resource/executable modification is required
by the Server feature. Only a role-matching whitelist motion is admitted.

Preview fixes matrix0/tier0/learned1,energy1000,empty targets and no per-Practice
overrides. These settings initialize ordinary role presentation only. Z emits
existing000D/motion/SPEED1, without assigning an Active ID, paying skill resources,
damage, buffs, healing fields, projectiles, V/Tab changes or queued auto-replay.
The existing HUD skill icons are not the selected action's skill identity; page
text explains the distinction. Ordinary skill mode remains a separate entry.

A conservative10..30-second recovery watchdog is not the native animation clock
or skill hard lock. Native split-clock/cancel timing remains unresolved. Same-role
selection (including selecting the current action again) stops the prior preview
and resets its watchdog without reloading the map, preserving current position.
After the visual finishes, use that reset to continue promptly rather than timing
the animation by the Server watchdog. Role changes use the existing world rebuild.

Loopback `/local-test/actions/catalog` lazily serves cached actions/videos; normal
2-second status polling does not resend it. Status and the existing audit journal
retain last applied preview role/motion; the outbound trace records actual000D.
No SQL role/item/quest grants or formal progression acceptance follow from preview.

Resource checks cover identity, non-repeat and direct EFF existence, not all
geometry/texture/loader dependencies or actual rendering safety. Native motion,
camera/effect cleanup, visual completion and working-copy behavior remain pending
until actual Client observations. A preview success is not native skill dispatch.

## Comparison/adoption procedure

1. Choose an unresolved skill video; note URL/time span and visible pose, effect,
   displacement and phases. Use existing resource hints to narrow candidates.
2. Preview candidate actions for that role. Record exact role/motion, catalogue
   SHA, Client variant SHA and applied/outbound trace correlation. Compare camera
   orientation and variants; do not infer a full family from one similar frame.
3. Record distinguishable agreement and disagreement. A title match or numeric
   position is not a visual result. Keep unreviewed and rejected comparisons.
4. Once visually supported, adopt an explicit Server binding separately, then
   validate resource consumption, targeting, damage/effects and normal gameplay.
   `WORKING_COPY_VISUAL_MATCH` / `SERVER_BINDING_ADOPTED` do not imply official
   Server dispatch or T01 whole-function FULL-PASS.

No visual matches are claimed in this batch. Existing181 comparison actives/
883slots and62 missing motion assignments remain unchanged. Normal room-based
village human acceptance stays first; user deferred testing, no repeated request.

## Validation

231 HappyPath passed,0failed/skipped.11 added cases synthetically exercise all294
whitelist actions across nine roles, exact000D IDs, single play/recovery/no replay,
unchanged full resources/no damage/cooldown, no Active field on action rows,
user-reference links and nine-role same-map retarget/return to ordinary lab.
After adjusting the watchdog to conservative10..30seconds, all11 affected preview
cases passed again. A zero-test filter attempt is retained locally and excluded
from pass counts. Host Release0warnings/errors, source reproduction and embedded
catalogue byte identity passed. JS syntax and a DOM fixture cover cached preview
fetch, role filtering, reference URL, exact POST and existing skill-lab flow.
These are Server/DOM checks, not actual rendered visual matches. See
`v74-validation.json`; no Client execution or deferred suites occurred.
