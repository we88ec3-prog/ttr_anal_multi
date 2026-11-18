# 固定來源索引

所有 Git 來源均固定於 `60c1c1a5dc7a73902d9dbb50361d5148e8b30058`；文件中的已實作／離線收據是既有記錄，本輪沒有重新執行 Server。舊文件中早期缺口依 `source_precedence` 與較新 consumer／實作段落修正。

| ID | 固定檔案 | 本題用途 |
|---|---|---|
| S01 | [kr-extra-roy/MEF-capabilities-20261116/world-npc/report.md](../../MEF-capabilities-20261116/world-npc/report.md) | NPC/world/shop native capability |
| S02 | [design/scenario-content/TOWN-MARKETS.md](../../../design/scenario-content/TOWN-MARKETS.md) | Current configurable NPC/shop placement and trade reuse |
| S03 | [design/runtime-content/SKILL-PRACTICE-PROTOCOL.md](../../../design/runtime-content/SKILL-PRACTICE-PROTOCOL.md) | Later type3 SkillExp native chain and current settlement persistence |
| S04 | [kr-extra-roy/MEF-P0-P1-master-continuation-20261117/journey-families/REPORT.md](../../MEF-P0-P1-master-continuation-20261117/journey-families/REPORT.md) | Q119 and real family selectors |
| S05 | [governance/client-variants/20261109-mef-town-services/shop-services.md](../../../governance/client-variants/20261109-mef-town-services/shop-services.md) | Legacy shop UI/request routing |
| S06 | [kr-extra-roy/20261116-MEF-checkpoint-lifecycle.md](../../20261116-MEF-checkpoint-lifecycle.md) | Point snapshot, delta, Lua setter and fallback intent |
| S07 | [kr-extra-roy/MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md) | Field/map/point/reset boundaries |
| S08 | [governance/client-variants/20261108-mainline-progression/experience-publication.md](../../../governance/client-variants/20261108-mainline-progression/experience-publication.md) | Existing growth, ScenarioCompletion, transaction and wallet adaptation |
| S09 | [design/scenario-content/ORDINARY-QUEST-READY-RESTORE.md](../../../design/scenario-content/ORDINARY-QUEST-READY-RESTORE.md) | Ready restore original consumer and older status superseded by S10 |
| S10 | [design/scenario-content/ORDINARY-QUEST-OBJECTIVE-JOURNAL.md](../../../design/scenario-content/ORDINARY-QUEST-OBJECTIVE-JOURNAL.md) | Later Accepted/Ready/objective snapshots and documented offline coverage |
| S11 | [design/scenario-content/PHINDOS-NPC-DIALOGUE-QUEST.md](../../../design/scenario-content/PHINDOS-NPC-DIALOGUE-QUEST.md) | Concrete ordinary dialogue quest Q2842 and existing transaction |
| S12 | [design/scenario-content/story-q119-clear-scene.scenario.json](../../../design/scenario-content/story-q119-clear-scene.scenario.json) | Existing candidate Q119 portal policy |
| S13 | [design/scenario-content/local-scenario-definition.schema.json](../../../design/scenario-content/local-scenario-definition.schema.json) | Existing finite event engine schema, not to extend silently |
| S14 | [kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/ABI-CATALOG.md](../../MEF-comprehensive-contracts-20261117/abi/ABI-CATALOG.md) | 121 normal registered bindings and output discipline |
| S15 | [governance/s00-iterations/evidence/t07-phindos-intake-20261103/post-t01/SCENARIO-RESULT-AND-RETURN-INTERFACE.md](../../../governance/s00-iterations/evidence/t07-phindos-intake-20261103/post-t01/SCENARIO-RESULT-AND-RETURN-INTERFACE.md) | General scenario result/return interface; partial old reward fields refined by S03 |
| S16 | [governance/s00-iterations/S00-20261102-QUEST-REWARD-CHANNELS.md](../../../governance/s00-iterations/S00-20261102-QUEST-REWARD-CHANNELS.md) | PartyExp and LeeLoo original mapping; type3 refined by S03 |
| S17 | [design/scenario-content/ALSMEER-SINGLE-PLAYER-ACCEPTANCE.md](../../../design/scenario-content/ALSMEER-SINGLE-PLAYER-ACCEPTANCE.md) | Current documented normal persistence/publication and limited verification scope |
| S18 | [kr-extra-roy/MEF-capabilities-20261116/world-npc/native-windows.json](../../MEF-capabilities-20261116/world-npc/native-windows.json) | Fixed reused native spans |
| S19 | [kr-extra-roy/MEF-world-identity-scene-interaction-20261117/native-evidence.json](../../MEF-world-identity-scene-interaction-20261117/native-evidence.json) | Fixed full point setter and delta spans |
| S20 | [kr-extra-roy/MEF-capabilities-20261116/dialogue-ui/native-windows.json](../../MEF-capabilities-20261116/dialogue-ui/native-windows.json) | Fixed dialogue native spans |
| S21 | [kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/abi-contracts.json](../../MEF-comprehensive-contracts-20261117/abi/abi-contracts.json) | Machine-readable ABI |
| S22 | [kr-extra-roy/MEF-P0-P1-master-continuation-20261117/journey-families/data-evidence.json](../../MEF-P0-P1-master-continuation-20261117/journey-families/data-evidence.json) | Reference real Q119/service data, original data re-read here |
| S23 | [governance/s00-iterations/evidence/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.json](../../../governance/s00-iterations/evidence/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.json) | 006F full snapshot native spans |
| S24 | [governance/s00-iterations/evidence/S00-20261102-QUEST-REWARD-CHANNELS.json](../../../governance/s00-iterations/evidence/S00-20261102-QUEST-REWARD-CHANNELS.json) | Reward mapping native spans |
| S25 | [kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py](../../MEF-world-identity-scene-interaction-20261117/stp_reader.py) | Read-only STPD/EX reader reused from immutable Git blob |
| S26 | [governance/s00-iterations/S00-20261103-PHINDOS-NPC-INTENT.md](../../../governance/s00-iterations/S00-20261103-PHINDOS-NPC-INTENT.md) | NPC local intro precedes selected 001C sender |
| S27 | [governance/MEF-FUNCTIONAL-COMPLETION.md](../../../governance/MEF-FUNCTIONAL-COMPLETION.md) | Existing MEF product goal and implementation limits |
| S28 | [design/scenario-content/local-town-placement-v3.schema.json](../../../design/scenario-content/local-town-placement-v3.schema.json) | Existing shop/NPC unlock schema |
| S29 | [design/scenario-content/phindos-shop-unlock.town-placement.json](../../../design/scenario-content/phindos-shop-unlock.town-placement.json) | Q117 shop2/NPC unlock example |
| S30 | [design/scenario-content/phindos-q119.story-wallet.json](../../../design/scenario-content/phindos-q119.story-wallet.json) | Existing Q119 LeeLoo900 rule and experience-policy pin |
| S31 | [governance/s00-iterations/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md](../../../governance/s00-iterations/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md) | 006F semantics only; old implementation absence superseded |
| S32 | [kr-extra-roy/MEF-capabilities-20261116/dialogue-ui/report.md](../../MEF-capabilities-20261116/dialogue-ui/report.md) | Local dialogue advancement and callback is not business completion |
| S33 | [governance/client-variants/20261109-mef-town-services/shop-asset-sync.md](../../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md) | Legacy trade asset publication |
| S34 | [design/scenario-content/BLACKSMITH-EQUIPMENT-ENHANCEMENT.md](../../../design/scenario-content/BLACKSMITH-EQUIPMENT-ENHANCEMENT.md) | Existing Server enhancement implementation and its supported scope |
| S35 | [design/scenario-content/PHINDOS-GROCER-TRADE.md](../../../design/scenario-content/PHINDOS-GROCER-TRADE.md) | Existing transactional trade/wallet/persistence reuse |
| S36 | [design/runtime-content/STORY-EVENT-ENGINE-CANDIDATE.md](../../../design/runtime-content/STORY-EVENT-ENGINE-CANDIDATE.md) | Existing LocalScenarioDefinition compiler/event engine |
| S37 | [AGENTS.md](../../../AGENTS.md) | Repository work boundary |
| S38 | [design/requirements/index.json](../../../design/requirements/index.json) | Existing requirement references, unchanged formal status |
