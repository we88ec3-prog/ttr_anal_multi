# Town2 scene cue metadata for Server planning

2026-11-07. Publish scene-cue-public-projection.json and this note; full calls/source/args, cameras, object positions, animation/wait scripts and raw members remain local. No Client or Lua execution was performed.

35 sequence metadata rows coverQuest133..144.38 original/working resource member hashes match. Each row contains function/member/SHA, temporary model, typed dialogue table/entry IDs, prologue numbers andRestoreMap flag. Source membership and known baseline/handoff SHA pins are included. Source identities also pin existing T16-133 qbase interpretation; no new opcode is defined. public-validation.json checks metadata exclusion, not runtime acceptance.

questPlans separates resource cues from S00 Server reconstruction. Q133/135/137 are story-only candidates despite field values; Q139 is story-only despite using temporary dungeon models. Q134/136 use Blank1 before formation and Clear2 as return. Q142 node3 preserves scenes4 then5 as an explicit Server order. Q144node3 scene3 usesiceman02D while gameplay map306 isiceman15D: the override must restore/rebuild combatmap. Q144scene5 presents town003N andProlog3 thenRestoreMap; persistentTown3 remains a Server reconstruction.

Gaps: Chart nodes contain no scene trigger IDs; scene names/order/model equality do not prove dispatch. All endBehavior0 values are raw data. ReturnScene is not settlement. The35 sequences contain no explicit BeginScenario/MoveToTown/character-recruit calls; cinematic object presence does not prove an unlock. Boss/wave spawning, portal/event binding, reward and permanent progression need their separate verified inputs. Existing47/3F adapters stay separate from these metadata cues.

The previous20261103 quest-scenes.csv covers only133/1 in this range. Its missing rows are a scope gap, not evidence the scenes are absent.
