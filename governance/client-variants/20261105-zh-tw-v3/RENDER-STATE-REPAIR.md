# zh-tw-v3 render-state dependency repair — 2026-11-07

## User observation and authorization

The user operated the separately requested translated Client and reported obvious
3D texture/rendering defects at login and additional defects in game. Two supplied
screenshots show flat blue water and opaque foliage rectangles in one view versus
water effects and transparent foliage in the other. Image attribution is based on
the user's comparison; no process-to-image capture correlation is asserted.

This is recorded as GAME_RUNTIME_OBSERVATION of a modified working copy, not
native Client compatibility or a Server protocol failure. The prior user request
explicitly authorized a separate build skipping the opening age image and applying
Taiwanese NPC/skill text and fonts. Repairing that build's missing dependencies is
within that scope. No additional gameplay patch is authorized or applied.

## Findings and repair

The variant omitted baseline `pack.gms` (6900 bytes), SHA256
529e06a159f905a2b5d12dd1e473fd50f60c3992f6ac58371ec1f98b601e8a8c.
Its strings include _gbDefaultStateBlock, alphablend, alphatest and lightmap
render-state names. Existing saved original-Client strings reference pack.gms at
string offset 0x84dcf4. This is consistent with the water/foliage symptom; a new
full native loading-chain audit has not been performed, so visual repair remains
pending human confirmation.

Copied the exact baseline pack.gms into the private variant; extended both local
and published profile builders to include .gms and require baseline equality.
All 15 baseline root DLL/config/registry/render-state files checked match the
variant, including Tartaros.cfg and TartarosKR.ini. The EXE is unchanged:
f1a23ee3c410e4261aef5eddcb9b4bacbe185cfff50d83155d2c3842bf088cee.
The original v2 EXE and original resource files remain unchanged. Logs before
repair are preserved locally. Raw resources/screenshots/logs remain local.

## Why the launch packaging changed

Earlier changes were executable patches used from the existing game root.
This variant also has external text and font resources. To preserve the original
and working v2, its builder placed a separate profile under CLIENT/build/zh-tw-v3.
The .cmd only sets that profile's working directory and starts the actual EXE;
it does not implement translation or rendering, and it is not intrinsically
required by EXE modification. This packaging decision introduced dependency
omissions (previous fcs.flu and now pack.gms), which are builder defects.
A local .lnk points to the same EXE and working directory as an optional convenience;
the user's question concerned the reason for the packaging change, not a request
to replace .cmd with a shortcut. No binary-only standalone delivery is claimed.

## Status

Login screen reached in the user's report; rendering FAILED before this repair.
Repair is STATIC_VERIFIED / PENDING_USER_RETEST. Translation/font completeness,
in-game rendering and all-skill combat acceptance are not promoted.
