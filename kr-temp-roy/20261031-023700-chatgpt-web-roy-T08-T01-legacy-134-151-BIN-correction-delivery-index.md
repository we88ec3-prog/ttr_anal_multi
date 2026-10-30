# T08-134～151／T01 LEGACY-MAPPING 勘誤交付索引（2026-10-31）

研究者 chatgpt-web roy。KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE `.text` code raw=VA−0x400C00，`.rdata` 依自身section raw mapping。原始FAILED原稿全部保留，以下7份為**新勘誤證據稿**，各具原生bytes／function VA／E8目標、局部CFG、邊界與下游工作項。**仍非T01全文FULL-PASS，LEGACY-MAPPING-001尚未RESOLVED。**

## 新原生技術稿

|涵蓋段號|文件|Git blob SHA|主要研究新成果|
|---|---|---|---|
| 134 | [20261031-023000-chatgpt-web-roy-T08-134-name-key-tree-PE-CFG-corrected-source.md](20261031-023000-chatgpt-web-roy-T08-134-name-key-tree-PE-CFG-corrected-source.md) | `20f421eb8cc8db7464793bcc07a1b9e269a2e8d4` | 名稱key樹真正函式及比較helper |
| 135 | [20261031-023100-chatgpt-web-roy-T08-135-generic-vector-append-three-owner-PE-corrected-source.md](20261031-023100-chatgpt-web-roy-T08-135-generic-vector-append-three-owner-PE-corrected-source.md) | `d414943c08f68a20ffb417b3e5df7937042e4338` | 泛用vector append與三種owner辨識 |
| 136/137/140 | [20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md](20261031-023200-chatgpt-web-roy-T08-136-137-140-B-queue-lifecycle-PE-true-CFG-and-negative-evidence.md) | `8a0457a7b8f1cb6e7fbda759b23d603d4d2f71cd` | B consumer logical-clear與析構區別 |
| 138/139 | [20261031-023300-chatgpt-web-roy-T08-138-139-manager-vtable-entry-score-ABI-PE-correction.md](20261031-023300-chatgpt-web-roy-T08-138-139-manager-vtable-entry-score-ABI-PE-correction.md) | `788ee4733821770c72c932b5b8f21873485c6653` | manager 8個vtable指標真入口、B score比較器 |
| 141–144 | [20261031-023400-chatgpt-web-roy-T08-141-144-PE-B-producer-Host-entry-and-two-growth-arms.md](20261031-023400-chatgpt-web-roy-T08-141-144-PE-B-producer-Host-entry-and-two-growth-arms.md) | `ccf38073ad9a366bc00a3ceeedc52d1f01f171b5` | B producer真正0x7A63C0與Host+0C寫入 |
| 145–147 | [20261031-023500-chatgpt-web-roy-T08-145-147-Host-embedded-vtable-squared-distance-and-record-registry-link.md](20261031-023500-chatgpt-web-roy-T08-145-147-Host-embedded-vtable-squared-distance-and-record-registry-link.md) | `d9b8eb5390840d68c6c9f41eb5ab5d88eb322d15` | Host vptr C4F6C0、3D squared-distance、fn4記錄登記與析構 |
| 148–151 | [20261031-023600-chatgpt-web-roy-T08-148-151-Host-allocation-control-pair-native-PE-revision.md](20261031-023600-chatgpt-web-roy-T08-148-151-Host-allocation-control-pair-native-PE-revision.md) | `ddb27a169a7d05c4981fdb567b4b69d1f2555a79` | Host 0x170三分配、control 0x10、引用計數兩階段釋放 |

## 橫向交叉連結（已查實 vs 未證）

### 已查實（指定vptr正常、有效指標及條件分支前提）

- `0x7A4C50` Host constructor寫入`Host+0x0C` vptr `0xC4F6C0`，`0x7A63C0` 具體producer對全域manager B-vector `[+B4/+B8/+BC]` append `Host+0x0C`，必要時 `0x797930`grow。
- `0x7BB240` B consumer對top-N做`0x7BB3B0` selection，entry vtable+8後可實體解析為 `0x7A8E10` 並計算相對12-byte context的3D平方距離分數；fn4可實體解析為`0x7A8310`。
- `0x7A8310` 有條件地使用`Host/entry+0x150` record，必要時`0x7BAA80`建構，再於`0x7A8618` E8呼叫真正registry`0x7E8240`，可下接 keyed-record find `0x7E86E0→0x7E8A00` 及record+0x20 append `0x7BB350`。
- `0x7A5651` Host destructor phase還原subobject vptr為`0xC4F66C`；真正`0x4CA460`建0x10 control block、`0x4E0F60`轉移pair且按strong→weak二階段條件釋放。

### 仍未證，禁止直接轉成原版Server規格

- 所有producer的上游caller、B entry的完整實際多型集合、B每次消費是否必然非空、fn4必然登記record與全部控制分支。
- `0x799F20`前置B consumer與後續22桶callback有局部順序，但B fn4的具體有向條目是否在同幀引入22桶、entry count增長、wire格式與Server生成決策**未核實**。
- Host借用subobject指標被owner/control析構的完整順序、是否可能UAF、跨執行緒引用安全性。靜態未能證明漏洞存在或不存在。
- 舊146/149/151對vtable函式位址『指令中段』的懷疑，在正確PE source mapping下需重審；已驗 `0x7A8310/0x7A8E10/0x4CA660/0x7A3920` 皆為真有效PE入口，但不能自行推廣到所有vtable欄位。

## 對T01與後續工作者的交付

- 原稿不覆寫；T01舊原稿FAILED歷史保持；此新批7稿只在T08分支，不代T01宣布`READY_FOR_REVIEW`/`RESOLVED`。
- `LEGACY-MAPPING-001`整體仍`NEEDS_FIX`：152及其他早期原稿仍待完整根入口CFG與派生語義全文驗證；18篇既有逐列row工作表可參 `kr-temp-roy/T01-legacy-pe-crosswalk/README.md`，不能拿座標表直接取代原稿修正版。
- 原版Client/API、Server待開發、跨T02/T06/T07串接、遊玩驗證應依S00獨立收件/驗收。T08-202未完成，不跳203。
