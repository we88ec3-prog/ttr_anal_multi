# Alsmeer mainline: exact resources and declared local reconstruction

Town2 was previously only an arrival destination. The original QuestInfo explicitly identifies12 type2 quests in Town2, connected by their actual single-Demand edges:

132(incoming) →133→134→135→136→137→138→139→140→141→142→143→144 →65(Town3 successor).

Q65, not Q145, depends on144. This route is not constructed by consecutive-number assumptions. Optional non-type2 quests and Chapter/phase membership do not become mandatory mainline entries.

| Quest | Giver / finisher | Field raw | Case candidate | Local kind |
|---|---|---|---|---|
|133|10053 /10005|21|105|Story only|
|134|10053 /10005|21|105|Solo scenario|
|135|10053 /10005|29|110|Story only|
|136|10053 /10005|29|110|Solo scenario|
|137|10005 /10005|30|111|Story only|
|138|10005 /10005|30|111|Solo scenario|
|139|10053 /10005|absent|—|Story only|
|140|10053 /10005|31|112|Solo scenario|
|141|10005 /10005|absent|—|Story only|
|142|10005 /10005|20|104|Solo scenario|
|143|10012 /10012|absent|—|Story only|
|144|10012 /10012|22|106|Solo scenario|

Field presence alone does not admit combat:133/135/137 remain story-only by the explicitly declared scene template. Source Case joins are unique Field=STAGE joins, not native completion or acceptance proof.

## Resource baseline

prepare_resources.py creates resource-baseline.json.32 original/working members match: four Table definitions,12 Chart/Cluster members and16 BND members representing19 maps. All six Charts contain one100%-choice NodeLink path. Node IDs must follow the actual links; Donjuan is1→2→4→3→5, not ID sorting. Complete cluster sets, PRE/count and preload IDs are retained. Chart x/y are editor coordinates, not player positions. No Chart SceneID/GoalTown/trigger-event field exists in the bounded data.

BND copies remain local under runtime-observations/20261107-alsmeer-mainline/assets; never publish their raw bytes. The prior complete32-descriptor, both-layer offset/count/zlib EOF/full-payload validation is preserved. Derived placements select a largest clearance-qualified connected grid component, a central legal spawn, and a farthest connected portal candidate. These are legal-space reconstruction, not official MEF exits/waves. Town3 map199 needs clearance request36 reduced to18(world-grid actual20); nine NPC candidates lie in that same component, at least20 from spawn,12 from portal and12 from one another. Existing Town2 placement is preserved separately in final content, regardless of newly derived candidates.

Existing T16 CSV has only133/1 among Town2, so it cannot define the full route. The sibling public scene metadata supplies35 scene entries with source hashes and explicitly declared assignment overrides. Q144 Scene3 uses temporary iceman02D while combat node3 is iceman15D; the candidate retains the scene and rebuilds actual combat after restoration. Q142 scenes4/5 share map196; both remain in explicit candidate order. Return scenes do not prove settlement. Q144 LoadMap town003N +DoProlog3 followed byRestoreMap supports visual village context, not persistent GoalTown; Town3 persistence remains S00 reconstruction.

## Reproducible content and compatibility

build_content_candidate.py emits alsmeer-full-mainline-content-candidate.json and an identical new runtime-observations/20261107-alsmeer-mainline/story-content-v34.json. It refuses a differing existing runtime output. The old v20 content is pinned to59a0e6221e76171ef9618b787dbf25c6ba0db61180866458317025916ef35678. All first10 quest objects compare byte-for-byte against their original raw JSON object fragments. Old Town2 map183 and all GoalNpcs are unchanged. New content has22 quests, Town1/Town2/Town3 contexts, giver plus finisher metadata and previous-version lineage. This is not a formal quest settlement/reward implementation or human acceptance result.

explicit-boss-choices.json records root S00's finite policy: Q138 terminal group44(model1029); Q142 terminal combined groups13/14(models1029/1043), simultaneous candidate rather than recovered transformation/waves. Q144 keeps first-group policy because scene actor models have no actual CLUSTER OBJECT match. PRELOAD and presentation actors never automatically become battle monsters. boss-cluster-audit.json preserves exact group intersections and all source groups.

scenario-source-catalog-v2.json preserves all five old cases, schema, runtimePolicy, sourceCommit and sourceW1Sha256; it appends six exact resource cases with NodeOrder,100% map choices and all set/group/model/PRE/count data. Added baseline metadata distinguishes this extension from the original commit lineage.

Run prepare_resources.py; project_scene_created_models.py; build_content_candidate.py. The model-ID projection is numeric metadata only; full sequence/call text is not copied into public artifacts. Final builder reads public scene metadata and derived model IDs. Existing original executables/resources, Server source and Git were not edited; no target launch, attachment or MEF rescan occurred.
