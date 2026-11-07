# Town2 NPC main-quest marker: bounded native gates

2026-11-07. OriginalKR target SHA2569741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91. Saved bulk and previousW5/T16/T08 source only; no target execution/attachment, provider request, Server/Client edit or Git operation. This is not T01/nativeFULLPASS or gameplay acceptance. Exact source hashes and original byte windows are retained.

## Precise level threshold, without assuming a single cause

500240 clears/rebuilds candidate WORD IDs atQuestOwner+5EC0/+5EC4. At5002E7..500315 it checks valid role slots1..9, stride210, role+5C present flag. It takes signedMAX(role+8), initially0. This is not just the currently controlled hero. At500491..500498 it rejects a quest whenQuestRecord+0C is greater than that maximum.

504740 parses the literalQuestInfo attribute level into this QuestRecord field. OriginalQ133 has type2,town2,level10,giver10053,finisher10005,subtype1,Demand132. Thus max-valid-role field+8 below10 is a sufficient reason forQ133 to be absent. Isilia displaying2 alone cannot prove the maximum of every other valid role, so it is not a complete runtime diagnosis. The operational business interpretation is the role eligibility level compared to the sourceQuestInfo.level; this report does not claim to have independently traced its specific UI label/control.

Other necessary gates in500240: correctTown selector, no currentQuestID in20 exclusion slots at+5ED0, no currentQuestID already present in prerequisite keys at+5EB0, and allDemand IDs present. An earlierFB9398 condition/exclusion check is kept as a separate partially named gate.6F is a prerequisite snapshot and candidate-refresh trigger, not an override for level/town.

## Why this controls the overhead marker

CNPC4D2120 installs its own vtable. KnownCNPC update4D2890 calls4D2360. That method uses signed actor model WORD at+88 and calls500A80(QuestOwner,NpcModel). For eligible global modes1/3/7/23/24,500A80 consults500A00, which reads the candidate list and requiresQuestRecord.type2 andgiver==NPC selector. Presence of such a mainline candidate contributes status5.

4D2360 status0 removes the attached marker atactor+420 and resets marker-kind+424 to-1. Status5 rechecks those modes, builds the attached marker through49B140/551F90, stores it at+420 and records marker-kind2. actor+36C!=0 skips the entire update. Other status values cover other quest/UI states and must not be flattened into a single unlocked flag. Exact marker glyph/resource ABI and this runtime instance'sglobalmode/subtype remain unknown.

Consequently a candidate failure can suppress the mainline marker. A correct level field does not prove all the remaining display gates pass.

## Server-side repair interface

W5-02 and4D41A0 prove005C payload+2 chooses an already-present role andpayload+3 BYTE becomesDWORD roleRecord+8.005C then calls500240 using the currentTown. The53B role row+2A DWORD from4D4150 writes the same field.005C cannot create an absent role, awardEXP or independently add prerequisites.

CurrentServer Rebuild publishes005C twice with role2=1,role4=2,all others=5. A level update sent only beforeRebuild is overwritten before the following6F. A legitimate repair is to use one consistent Server-owned role-level DTO in all relevant initial/delta/Rebuild publications, then refresh candidates afterTown andstats. For a progress-override test, any level floor must remain a declared test provision, not fabricated official progression/rewards. KeepQuestInfo.rawlevel unchanged and do not patchClient gates or force an arbitrary marker packet.

Next positive-flow observation: inspect the actual emitted role field values andTown/prerequisite snapshot forStory133; when the source-defined threshold andother gates are satisfied, observe bothQ133 candidate/NPC interaction andhead marker. Preserve unknown marker/resource issues if the candidate appears butthe icon does not. No negative/replay/concurrency testing was run.
