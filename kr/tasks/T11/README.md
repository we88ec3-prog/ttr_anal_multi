# T11 技能施放

狀態：bounded-review-handoff；負責人未認領。

## 範圍

技能計時與消費、消耗和施放裁決；共用攻擊輸入引用 T10

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：讀取技能矩陣不等於決策；官方冷卻與消耗裁決不完整
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。讀取技能矩陣不等於決策；官方冷卻與消耗裁決不完整
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：T02, T04, T10。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/skill-timing-fixture-audit.json](../../../unclassified/evidence/0332932e6198f90638fdd2779f9d8960b2471bbe862a5143c5293f6618857cbc.txt)
- [native-index/matrix-index-lookup.txt](../../../unclassified/evidence/0881a061cfb58b7c4e97482147c99e85d0305ebd72310b14b7e0ee98428909a1.txt)
- [native-index/skill-list-hero-gate.txt](../../../unclassified/evidence/0bc50b85c7ecbbaac4561b347d45fcec529643b43d213581fe3bdfa62f8052c9.txt)
- [native-index/skill-condition-hero-gate.txt](../../../unclassified/evidence/0f7204eda6a341f1a3c065f6364664d95b3cdfd99c79ef393bece190e5b1ed18.txt)
- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [native-index/general-monster-comparison.json](../../../unclassified/evidence/2d8d0f50e7dba1c7a712acb6e8cd4f36d41e8519bdf42e36207ebd6c49b1dbc2.txt)
- [native-index/skill-flags-availability.txt](../../../unclassified/evidence/304161491b17c8db220ff7ec0920d5f662781931782e700ab9e9cc1de000b21e.txt)
- [GENERAL-MONSTER-AI-COMPARISON.md](../../../kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt)
- [audit_native_skill_timing.py](../../../unclassified/evidence/49782e44e5da6f0f86cf0ead1fecee49e0432cb4b20226024734366b6772b5e4.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/skill-matrix-shared-lookup.txt](../../../unclassified/evidence/5d41410f1836a5529a3e1c4a3ed3ef7440d1b5e911f56d5802c48b798136a381.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [native-index/skill-condition-subai-adapter.txt](../../../unclassified/evidence/61a41818afee6303d4493b7bd43f20eb6b9ab6c47166857c1f76d09322ea9fad.txt)
- [native-index/matrix-file-loader.txt](../../../unclassified/evidence/673c92234834b527f9b30cb9fff1e647b3e06fe8f273d09d5c091ef6e5e5fb49.txt)
- [native-index/non-matrix-tree-lookup.txt](../../../unclassified/evidence/6827e715dfcd28bcedb39a4f872622c4832f3ec46037daeba779fc7f64992ec1.txt)
- [native-index/matrix-0081a8e0.txt](../../../unclassified/evidence/69f69c6748f3651ee5a0c11f82eb472f0ccf1ff0d936fc34958c6f4116722c46.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [native-index/general-monster-skill-id-hits.json](../../../unclassified/evidence/6d70c3b97d5429908131980e6928cacf59d80273108b524aba5cd95e421e8e1a.txt)
- [audit_skill_matrix_consumers.py](../../../kr/evidence/76c6266ea4969307f261c2757611062af506f2a43cba151b6680b33de87530c1.txt)
- [CONTROL-AND-SKILL-SOURCE.md](../../../unclassified/evidence/7bafd3143273877097a98dd0c42dc0f1c7e30719d0e86821318db4612473f89f.txt)
- [native-index/skill-matrix-shared-key.txt](../../../unclassified/evidence/9669363ac83b8e3a2949d8802955d649c082580ab9c51c7aaff407095b8faea6.txt)
- [native-index/skill-matrix-consumer-audit.json](../../../kr/evidence/a26a83997b086fba1532b174451358cbf197825ea9f9d7800fd51529e53ec646.txt)
- [native-index/matrix-list-loader.txt](../../../unclassified/evidence/addff13491ca8b3eb68dab1810b5b7e9b48b5f77f9b7014add070b18b3dfee12.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [SKILL-MATRIX-CONSUMERS.md](../../../kr/evidence/d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/matrix-0040f7f0.txt](../../../unclassified/evidence/f98244749162cdb1657aab85832eb28db2c987d8449700e4d9a8c141568c51da.txt)
- [audit_general_monsters.py](../../../unclassified/evidence/fb5dabe6d0d600496e532de1cc710f5e165293b2aacff98fd92c604c099a7dc3.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。
