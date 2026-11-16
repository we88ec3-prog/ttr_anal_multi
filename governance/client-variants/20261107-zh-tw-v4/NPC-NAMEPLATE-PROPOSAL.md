# v4 user result and NPC overhead-name proposal — 2026-11-07

The user reports normal display and normal NPC dialogue names, but overhead NPC
names remain Korean. Record only that bounded result; age-image skipping, all
skills, full translation and original Client compatibility were not separately
confirmed by this answer.

Current v4 Table has translated category6 _ActorList NAME, while npctable NAME
and GUILD remain Korean. Example10338: Actor NAME is 特蒂絲; npctable NAME remains
테티스 and GUILD remains 시나리오 담당관. TC npctable for the same ID/TYPE and actor
FILE has 特蒂絲 / 主線劇情負責官. For10002 the analogous pair is 拉傑德 / 라제드.
The current Server SquareNpc fixture packet includes entity/model/position/state,
not a literal display name. This bounds the resource mismatch; the full native
nameplate-reader chain was not newly audited, so the candidate still needs human
retest after any approved repair.

The first text builder translated category6 actor NAME but omitted npctable;
this is an incomplete translation build, not proof of a Server defect.

## Concrete proposal, not applied

Create Tartaros.ip-zh-tw-v5.exe and TC_UI/Table.story-zh-tw-v5.stp, preserving
all v4/original files. Reuse v4 fonts unchanged. Only redirect the table path
v4->v5; keep existing age/font patches. Within npctable, replace only NAME/GUILD
with nonempty TC text when NPC ID and TYPE and corresponding category6 actor FILE
match uniquely. Leave all other attributes, children and archive members intact.
Preflight:528 unique NPC IDs,330 eligible;327 NAME and11 GUILD differences.
Ambiguous IDs10518/10519/10520 and all unproven joins stay unchanged. The first
preflight rejected duplicate IDs; the revised proposal explicitly excludes them
rather than treating ID alone as unique. This is not a promise of complete NPC
translation across the whole game.

The user requested prior explanation/confirmation for companion-resource changes.
Therefore this remains PENDING_USER_APPROVAL; no v5 EXE/resource has been written.
Raw game resources remain local; the proposal JSON contains metadata only.
