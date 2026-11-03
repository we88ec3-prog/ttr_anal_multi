# 證據、來源版本與有界驗證索引

本索引供四份指定交付與CSV共同引用。`S-*`是已讀既有來源；`N-*`是本輪有界BIN-first原件證據；`K-*`是CSV／方向子稿的同義來源碼；`B-S* / B-N*`保留buffer子稿的精確索引。source-only、byte/window通過、bounded語意補證與T01 FULL-PASS不是同一級別。

**原件**：KR `02-Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes，PE32 x86，ImageBase400000。`.text raw=VA−400C00`，`.rdata raw=VA−401A00`；data依PE section映射，沒有把rdata公式套到data。原件不隨交付重新打包。

**版本**：首次核對main `83959c0e7e65ab01348b285f03c285f487077610`；原T10分支 `0419c66009a958597e95c9a88740d6f7f0d6772c`；本機同步merge `72771cd6f6b3b001f5aaf341d861edf3a719a72a`。本輪研究尚未Commit／Push，表列來源Git blob都是既有檔案的固定版本，不把新檔本地hash稱為已發布remote blob。

## 1. 既有來源（精確Git版本）

同一列的aliases引用同一份檔案。每個連結固定commit；完整repo相對路徑、SHA256、Git blob保存在[source-catalog.json](evidence/source-catalog.json)。引用不代表採用該來源所有歷史推論；本輪勘誤優先範圍見§3。

| 來源碼 | 固定來源 | Git blob | 使用範圍／限制 |
|---|---|---|---|
| `S-W01` / `K-W01` | [20261031-154059-chatgpt-web-roy-T10-W01-input-source-to-action-gates.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W01-20261031/20261031-154059-chatgpt-web-roy-T10-W01-input-source-to-action-gates.md) | `a5d6c4ca0104e8ffba51e151169f6072f09035d4` | physical→held/phase→UI→logical/latch |
| `S-W03C` / `K-W03` | [20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W03-20261031/20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md) | `0d17362eb300ab8ea002c3d6380d5a41039665bc` | OR bits／和弦matrix predicate；546100完整CFG本輪另補 |
| `S-DIR` / `K-DIR` | [20261027-chatgpt-web-roy-T10-10-direction-byte-synthesis.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/20261027-chatgpt-web-roy-T10-10-direction-byte-synthesis.md) | `e6f414aa1601f0078df0e6cd88b57752a36f867c` | logical四方向與八向合成；新BIN校正截斷量化 |
| `S-T09INPUT` / `K-T09` | [20261026-001843-claude-web-roy-T09-hero-input-record-546100-546780.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261026-001843-claude-web-roy-T09-hero-input-record-546100-546780.md) | `6002bce2ee0c18ecccf0093ffa115334bead659f` | 既有collector起點；舊mouse及held語意推測不沿用 |
| `S-E66` / `K-E66` | [20261030-chatgpt-web-roy-E66-RR0002-square-handshake-43-68-6A-and-dual-state-RTTI.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-extra-roy/20261030-chatgpt-web-roy-E66-RR0002-square-handshake-43-68-6A-and-dual-state-RTTI.md) | `a802e8482af20145476015c17ee3dda029558f6c` | Square entry、scene RTTI；本輪接Single ctor |
| `S-KMAP` / `K-MAP` | [6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt) | `cb8a9da734567b10e37cc966a981300cb3e7b8bc` | 實際KR Type0/Type1 mapping；不證runtime bank |
| `S-ANGLE` / `K-ANGLE` | [20261025-231655-claude-web-roy-T09-collision-users-probe-545F30-and-direction-table.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261025-231655-claude-web-roy-T09-collision-users-probe-545F30-and-direction-table.md) | `1c34936296b1bcf63bd905aad80d4270bbf48cab` | 256方向表／角度byte／collision probe |
| `S-CONTEXT` / `K-SCENES` | [8762287177ecd19a4bf1b4a21c8e311a58733e962b1bacc28c6c1461e02b7bb3.txt](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/8762287177ecd19a4bf1b4a21c8e311a58733e962b1bacc28c6c1461e02b7bb3.txt) | `59254f10bcdc4acbcf51d68846e6e6b01454afb9` | MissionField/Room、Scenario、Tutorial controller種類 |
| `S-FORM` / `K-FORM` | [1db3c9b6a84258433cee91db91c0346ddfffea5045bfedb274073b6ce633d0d9.txt](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/1db3c9b6a84258433cee91db91c0346ddfffea5045bfedb274073b6ce633d0d9.txt) | `e5c942a9cbf9f3af01f8a1217c5ab103976efd17` | Formation導航；新增原件補閉合 |
| `S-SUBAI` / `K-SUBAI` | [20261027-211146-chatgpt-web-roy-T10-30-subai-actor-state-counter-and-branches.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/20261027-211146-chatgpt-web-roy-T10-30-subai-actor-state-counter-and-branches.md) | `dc6fdc940d9b35f2656e417c88d198cbd92adae8` | 548FF0候選與publish，不是physical keys |
| `S-SIDE` / `K-SIDE` | [91830956fb04388f5eabd1c876f283c6e78e9f001e953e978345472ff3572866.txt](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/91830956fb04388f5eabd1c876f283c6e78e9f001e953e978345472ff3572866.txt) | `686a9def33b3484031cc62b4a6d8d4a3a6549add` | Single sidepath、A4/38C例外 |
| `S-INTERACT` / `K-INTERACT` | [c04a004606b26865dd9e351e6cac35af96b885056d6223264455a4680207da5a.txt](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/c04a004606b26865dd9e351e6cac35af96b885056d6223264455a4680207da5a.txt) | `1b16f81ac4689d18f7f66e8dc498f9f194490dfc` | 544A00/544730手動參數與NPC互動candidate；不把舊Server驗證升成本輪結果 |
| `S-SUBAI31` | [20261027-211146-chatgpt-web-roy-T10-31-skill-candidate-fallback-and-matrix-stage.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/20261027-211146-chatgpt-web-roy-T10-31-skill-candidate-fallback-and-matrix-stage.md) | `6e53a50978a0802cb7fc09f9769b9c4399db0028` | 549C60 candidate／target方向writer |
| `S-SUBAI26` | [20261027-205931-chatgpt-web-roy-T10-26-subai-cast-state-machine.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/20261027-205931-chatgpt-web-roy-T10-26-subai-cast-state-machine.md) | `c82bc8c3c53f304faecab0911f214b89440d1784` | 549E10 seed與heading writer |
| `B-S1` / `S-W05` | [20261031-182635-chatgpt-web-roy-T10-W05-skillmatrix-resource-timing-T11-handoff.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W05-20261031/20261031-182635-chatgpt-web-roy-T10-W05-skillmatrix-resource-timing-T11-handoff.md) | `b3c0f31db311cce06f3a87fcbbf4f938171ce972` | SkillMatrix／timer／SubAI resource predicate |
| `B-S2` / `S-W04` | [20261031-172536-chatgpt-web-roy-T10-W04-S2C-receive-actor-motion-native.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-S2C-receive-actor-motion-native.md) | `8e915daab064177490d5de0b3f193810a5de2f41` | 0B/0C/0D/0000 actors及跨時間feedback |
| `B-S3` / `S-W06` | [20261031-184010-chatgpt-web-roy-T10-W06-hit-result-death-T12-boundary.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W06-20261031/20261031-184010-chatgpt-web-roy-T10-W06-hit-result-death-T12-boundary.md) | `69189fda3fee408c373738a1c1113f9470b9d640` | 000E 13-byte結果與效果；不等於必扣HP／自動hurt |
| `B-S4` | [20261031-191217-chatgpt-web-roy-T10-W07-S00-combat-feasibility-handoff.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W07-20261031/20261031-191217-chatgpt-web-roy-T10-W07-S00-combat-feasibility-handoff.md) | `1bd44222725303783c0e216d7dbe88b829b1aba7` |  |
| `B-S5` / `S-012A` | [20261101-T11-KR-SKILL-012A-GATES-BOUNDARY.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/0419c66009a958597e95c9a88740d6f7f0d6772c/research/handoffs/s00-web-skill-gap-20261101/20261101-T11-KR-SKILL-012A-GATES-BOUNDARY.md) | `3691a72a7177c5fb91767cc01a4caf030375f304` | 既有012A交接；本輪接源與state/current分層 |
| `B-S6` / `S-P0B` | [20261101-T10-T11-P0B-KR-000E-VTABLE-VS-000D-MOTION.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/0419c66009a958597e95c9a88740d6f7f0d6772c/research/handoffs/s00-web-skill-gap-20261101/20261101-T10-T11-P0B-KR-000E-VTABLE-VS-000D-MOTION.md) | `02d09ab834d5f5b878a419a3391da76b9b077dc4` | 保留有效0D部分；000E receiver類別判斷撤回，見新反證 |
| `B-S7` | [20261026-190148-chatgpt-web-roy-T08-CMonster-inherited-components.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261026-190148-chatgpt-web-roy-T08-CMonster-inherited-components.md) | `77b8dcf98f0c94bd74ad8f52081bd10fea0eb08f` |  |
| `B-S8` | [20261026-211852-chatgpt-web-roy-T08-dispatch-composite-id.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261026-211852-chatgpt-web-roy-T08-dispatch-composite-id.md) | `96061996117565ac35209a4dcd027155703395d6` |  |
| `B-S9` / `S-T106` | [20261028-1942-chatgpt-web-roy-T10-106-queue-header-key-and-dispatch-bases.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261028-1942-chatgpt-web-roy-T10-106-queue-header-key-and-dispatch-bases.md) | `b9873d454eca75147c3251b85aed7f54929ecb5f` | 16-byte outer dispatcher bases與callback this |
| `B-S10` | [20261027-141326-claude-web-roy-T09-bulk-tick-rate-hero-driven-by-server-echo-and-actor-id-type.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261027-141326-claude-web-roy-T09-bulk-tick-rate-hero-driven-by-server-echo-and-actor-id-type.md) | `a7dc14d4dcf9458a0a9a1fdb681012a76071f149` |  |
| `B-S11` | [622c03c8f35e217e0799ca787b550ebad648b9767cbb2bc8f2c74da71d75a65d.txt](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/622c03c8f35e217e0799ca787b550ebad648b9767cbb2bc8f2c74da71d75a65d.txt) | `b6c49209c9047ed4afec118eafa2a34eb038fcec` |  |
| `B-S12` / `S-T01REVIEW` | [README.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/research/handoffs/t01-20261031-t10-w00-w05-native-review/README.md) | `d978ee1e8f090e28bb996d2600b58b020ed81347` | 有限R2，不升整函式FULL-PASS；七退回狀態未改 |
| `B-S13` | [20261029-234329-chatgpt-web-roy-T16-109-KR-quest14-16-15-five-studies-native-receiver-to-Phindous.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261029-234329-chatgpt-web-roy-T16-109-KR-quest14-16-15-five-studies-native-receiver-to-Phindous.md) | `d256fd6a32e34eff00ef5d80e57ef088759d338f` |  |
| `S-T09CLOCK` | [20261027-084935-claude-web-roy-T09-send-throttle-header-and-server-authoritative-movement.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261027-084935-claude-web-roy-T09-send-throttle-header-and-server-authoritative-movement.md) | `5a86e1a7261e3ad08d7151ffb302793433944daf` | timeGetTime／send credits起點；DA index及fallback敘述本輪勘誤 |
| `S-T09TICK` | [20261027-142007-claude-web-roy-T09-per-tick-frame-order-490FE0-4E0060-actor-update-loop.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261027-142007-claude-web-roy-T09-per-tick-frame-order-490FE0-4E0060-actor-update-loop.md) | `631002d75c005cd27794636588c084850a025ec6` | frame/controller order；不保證runtime恆定FPS |
| `S-AUX-30` | [20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md) | `2ca02f3870d79d3217abf39b8651c43226eb77d6` |  |
| `S-E84` | [20261101-chatgpt-web-roy-E84-RR0007-outer-router-alternate-paths-native-review.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-extra-roy/20261101-chatgpt-web-roy-E84-RR0007-outer-router-alternate-paths-native-review.md) | `a993238122a167222392a8c15c0c69061fe8e68a` | 最新outer router分流 |
| `S-W03T` | [20261031-165757-chatgpt-web-roy-T10-W03-action-transport-native.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W03-20261031/20261031-165757-chatgpt-web-roy-T10-W03-action-transport-native.md) | `62d31e8b3d8a450e644362092fd04e7ae696c729` | 0A header/Row A/Row B及其他C2S producers |
| `S-AUX-33` | [20261029-222122-chatgpt-web-roy-E38-RR0005-dispatch-slot2-key2-BB9-and-BD2-response.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-extra-roy/20261029-222122-chatgpt-web-roy-E38-RR0005-dispatch-slot2-key2-BB9-and-BD2-response.md) | `2e2d028db09f9262a38f9b9e36906e57a84b0931` |  |
| `S-W00-116` | [20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md) | `bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804` | T01-116第五byte與stack勘誤；原README退回狀態未解除 |
| `S-T115` | [20261028-213024-chatgpt-web-roy-T10-115-KR-C2S000A-builder-to-pending-transport-closure.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261028-213024-chatgpt-web-roy-T10-115-KR-C2S000A-builder-to-pending-transport-closure.md) | `e5de0249c0fdc0b97685e68b76921510e57aea78` | builder→queue/framing/WSASend，與動作buffer分開 |
| `S-P0A` | [20261101-T10-P0A-V7-Z-INPUT-ROW-CLOCK-BOUNDARY.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/0419c66009a958597e95c9a88740d6f7f0d6772c/research/handoffs/s00-web-skill-gap-20261101/20261101-T10-P0A-V7-Z-INPUT-ROW-CLOCK-BOUNDARY.md) | `d5de9db6fb6db5fccb837abd5be7e50ca5156d12` | 先前S00交接；clock未知已由舊來源＋原件補證 |

## 2. 本輪有界原件證據

各JSON保存VA、raw offset、原件bytes／window SHA、RTTI／vtable、來源與scope。窗口end一律exclusive。核心與新增補證均是唯讀，不執行或附加遊戲；不是重做全量反編譯。

| 引用碼 | 本輪檔案與原件範圍 | 限定主張 |
|---|---|---|
| N-5452 | [5452c0.asm](evidence/5452c0.asm)，5452C0..545BA0；[core-native-audit.json](evidence/core-native-audit.json) | action OR latch、eligibility、clock/credit、Row A/B順序、owner override、N=0仍清+5C |
| N-5461 | [546100.asm](evidence/546100.asm)，546100..5464C0；同core audit | 初始化→collection→availability→movement完整分支→emit；action skip兩個8000 writer；舊E2/E4比較 |
| N-COLLECTOR | [546780.asm](evidence/546780.asm)；546780..546850 | +5C／special bits、三路收集、heading優先與5467F4 WORD store |
| N-ROWB | [546ef0.asm](evidence/546ef0.asm)，546EF0..5471B0 | actor-target幾何、10/70距離、lowbit2、highbit gates與state回授 |
| N-FALLBACK | [5471b0.asm](evidence/5471b0.asm)；5471B0..547220 | 容量檢查後確實append五bytes；不是無輸出helper |
| N-CLOCK | [490fe0-clock-prefix.asm](evidence/490fe0-clock-prefix.asm)、[4e1590-clock-init-prefix.asm](evidence/4e1590-clock-init-prefix.asm)，core audit import及constants | WINMM timeGetTime IAT BD25A0→F9423C；100/120/180/300資料值；不是action期限 |
| N-KEY | [keys-direction-analysis.md](evidence/keys-direction-analysis.md)、[keys-direction-evidence.json](evidence/keys-direction-evidence.json) | logical方向、八向、向零量化、Joypad axes／Mouse區別、UI與A4來源 |
| N-SQUARE | 同keys audit；4BBB70/4BBC10/548540、548A20/548A90；另[548a20.asm](evidence/548a20.asm)、[548a90.asm](evidence/548a90.asm) | CSquare→Single；正常546100與A4/38C例外；互動true/false參數在builder後 |
| N-CONTROLLERS | keys audit `controller_vtables`、RTTI、5480A0/5480E0/548CB0等 | 七個具名controller tick及row callback；主／副actor不混用 |
| N-FORMATION | [formation-secondary-row-detail.md](evidence/formation-secondary-row-detail.md)，keys audit新增windows | 副角色output無B0/E4固定seed；548FF0 publish AI+72/+74；early-return界線；heading比較早於高位重寫 |
| N-STATE = B-N2/B-N3/B-N6 | [buffer-s2c-analysis.md](evidence/buffer-s2c-analysis.md)、[buffer-s2c-native-audit.json](evidence/buffer-s2c-native-audit.json) | actor+158 current FSM、具體state flags、0C5與0D9不等價、000D不直接清E2 movement |
| N-TIMER = B-N1 | 同buffer audit，4ADD50/4B1A00/545E20/597B70及controller+40 | 012A來源、actor-key map、signed/33、overwrite/clear／active q=0限制 |
| N-RESOURCE = B-N5 | 同buffer audit，4B3090/4ADD50 | 0034 typed絕對resource updates，非施放扣費事件 |
| N-RESULT = B-N4 | 同buffer audit，4C4670/4FDA30/436C40及scene RTTI/+28 | 000E receiver是scene；保留W06的結果consumer，撤回P0B錯類別解讀 |
| N-DA / E-WIRE | [wire-complements-da.md](evidence/wire-complements-da.md)、[wire-complements-provenance.json](evidence/wire-complements-provenance.json) | 493170+FA8→4959F0的key為DA；完整handler +5、不讀packet args；其他已證wire不能補physical-held |

CSV的`BINxxxxx`是「對應原件VA／vtable slot」簡寫，不是新函式名：5468xx/546Axx/4BB4xx對N-KEY，5461xx/5463xx/5464xx對N-5461，5467xx對N-COLLECTOR，5452xx對N-5452，548xxx依N-CONTROLLERS/N-SQUARE/N-FORMATION，49Cxxx對N-KEY的A4 writer；4914B1/491530/491CB6的frame order復用S-W01。BIN_C0FA6C+48是已核controller vtable pointer。K-W03專指combo closure，**不是**transport稿S-W03T。

## 3. 勘誤與證據優先序

| 歷史問題 | 本輪採用的精確更正 | 不擅改的狀態 |
|---|---|---|
| T01-116第五byte被一律叫B0、RowA stack slot誤認 | 採W00-116；Row A看callback，Row B初始E4但callback／owner可改；Formation副角色另有AI seed | 舊原稿與README退回保留；不自行RESOLVED |
| T01-007 store位址 | 5467F1是pointer load，5467F4才WORD store | 不升整函式FULL-PASS |
| 546100低15與8000 | 由初始化和完整CFG確認retained action skip；不把單AND/OR或此callback外推所有controller | 不改W03原稿／舊候選規則 |
| 廣場controller誤套MissionRoom | 正常CSquare→Single；548350是MissionRoom | runtime scene/controller仍以實際資料為準 |
| Single互動只在pressed呼叫的語病 | phase1傳true，其餘傳false；兩者都call互動。A4有Space writer，不能歸因每次Z | 不宣稱所有v+64 UI callback已窮盡 |
| 546D50舊cursor推測 | 已證軸provider可來自Joypad；Mouse該slot回null | 不推測使用者當時的裝置 |
| 11/1 P0B的000E controller解讀 | receiver是scene，+28→4B0640/4C4920；W06 13B結果路徑保留 | P0B有效0D部分仍可引用；不按日期全面覆蓋 |
| 10/27 T09把+FA8算成key78、+F28算成70 | 用outer16-byte表基址R+208：分別是DA、D2；本輪只給DA業務語義 | 不改舊稿，不把D2未查內容補成結論 |
| 發送clock被重新列未知 | 舊T09＋原件import/write支持F9423C=timeGetTime(ms) | 不把ms推廣到012A正式單位、combo／cancel／0.4s |
| RowB第二次metric被相同ESP offset誤讀 | 54706C在cdecl stack回收前、54707A在回收後，仍讀dx與dy | 不將審查過程的誤讀留作反證 |

## 4. 前置、審核與完成層級

[governance-sources.md](evidence/governance-sources.md)保存AGENTS、Task、RR、T01與先前S00交接的來源索引。[bulk-review-seven.json](evidence/bulk-review-seven.json)保存使用者指定七個候選的凍結逐函式review；七者均`full_function_semantic_review=not-recorded`，只有5452C0有T10登記，登記不等於語意review。後續W00–W05有限R2有效，但不是全稿／全函式FULL-PASS。

T10原有116/062/063/007/026為NEEDS_FIX、055/056為NEEDS_QUALIFICATION；T11沒有對應退回專節。未改Task owner、task.json、RR、T01退回或共享verified-knowledge。開工RR index十項沒有owner_task=T10/T11；本輪依使用者直接工作包，不虛稱已正式認領RR。

已完成的是四份指定交付與有界Client模型／反例；尚未閉合的Client欄位與callee、Server政策、跨功能整合、真人驗收各自列示。沒有以缺原版Server演算法為由把已知Client介面寫成未知，也沒有以本地byte檢查替代可玩驗收。

## 5. 重現與文件完整性

執行[verify-evidence.py](evidence/verify-evidence.py)只讀提供的原件BIN與本包JSON，核對SHA、PE映射、windows、anchors、pointers及RTTI；可選`--repo`核對既有來源blob。它不載入或呼叫Client API，也不執行原件。所需Python套件為pefile與capstone。

```bash
python evidence/verify-evidence.py --bin /absolute/path/02-Tartaros.bin
# 如需同時核對固定來源內容：
python evidence/verify-evidence.py --bin /absolute/path/02-Tartaros.bin --repo /absolute/path/ttr_anal_multi
```

實際結果見[verification-result.json](evidence/verification-result.json)。這是證據包一致性驗證，不是全部肯定主張的T01全文驗證。CSV欄位與每context必需組合、相對連結、Markdown fences、所有檔案hash另列於[artifact-validation.json](evidence/artifact-validation.json)與[manifest.sha256](manifest.sha256)。

所有數值例子與相同wire反例均為static/symbolic，沒有偽造新增實測；舊152筆無row log未被重建。包內子工作稿保留完整證據推進過程，主交付以本索引所列勘誤與限定範圍為準。
