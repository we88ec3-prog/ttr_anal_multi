# T08 LEGACY-MAPPING-001 工作索引（2026-10-31，仍NEEDS_FIX）

作者 chatgpt-web roy。KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本索引僅保存本輪來源修訂與證據交叉對照，保留24篇原稿和T01先前FAILED；不改T01審核結案標準。

## 本輪已上傳的新來源修訂（5篇；未全文T01複驗）

| T08 | 獨立修訂 Markdown | 有界研究核心 | 狀態 |
|---|---|---|---|
| 129 | `kr-temp-roy/20261031-020700-chatgpt-web-roy-T08-129-LEGACY-MAPPING-PE-callback-revision.md` | dispatcher真正PE與callback vtable | source修訂候選，T01未核 |
| 130 | `kr-temp-roy/20261031-020700-chatgpt-web-roy-T08-130-LEGACY-MAPPING-PE-dispatcher-vector-revision.md` | dispatcher調度/queue/helper和bucket producer | source修訂候選，T01未核 |
| 131 | `kr-temp-roy/20261031-020700-chatgpt-web-roy-T08-131-LEGACY-MAPPING-PE-queue-constructor-revision.md` | FBA838建構和B-vector欄位 | source修訂候選，T01未核 |
| 132 | `kr-temp-roy/20261031-020700-chatgpt-web-roy-T08-132-LEGACY-MAPPING-PE-second-caller-A-B-boundary-revision.md` | 第二caller和A/B容器分界 | source修訂候選，T01未核 |
| 133 | `kr-temp-roy/20261031-020700-chatgpt-web-roy-T08-133-LEGACY-MAPPING-PE-registry-revision.md` | registry真函式/ABI/vector append | source修訂候選，T01未核 |

本輪129/130特別確認**兩種原本混在舊稿的地址**：被錯誤raw0→VA映射的指令列應按真PE修正（如舊79A320→真799F20），而從PE `.rdata`直接讀到的 vtable DWORD `C4FF8C+0C=7D1310`、原生 `79985C` vptr writer 等**原本就正確，不可減0x400**。131/132修復另一條constructor及queue caller，133修復registry入口與append target。

## 18篇／1263條 T01 已核 code-row 對照表

以下每一表**只是復用T01原始`mapping-findings.json`已核的行對照，非本輪獨立逐條二次驗證，更不是已修復整份來源**。逐條表提供舊VA、真PE VA、原始bytes、實際不同bytes以及E8真目的地候選。

| T08 | code-row 對照表 |
|---|---|
| 129 | [T08-129-verified-row-repair-map.md](T08-129-verified-row-repair-map.md) |
| 130 | [T08-130-verified-row-repair-map.md](T08-130-verified-row-repair-map.md) |
| 133 | [T08-133-verified-row-repair-map.md](T08-133-verified-row-repair-map.md) |
| 134 | [T08-134-verified-row-repair-map.md](T08-134-verified-row-repair-map.md) |
| 135 | [T08-135-verified-row-repair-map.md](T08-135-verified-row-repair-map.md) |
| 136 | [T08-136-verified-row-repair-map.md](T08-136-verified-row-repair-map.md) |
| 137 | [T08-137-verified-row-repair-map.md](T08-137-verified-row-repair-map.md) |
| 138 | [T08-138-verified-row-repair-map.md](T08-138-verified-row-repair-map.md) |
| 139 | [T08-139-verified-row-repair-map.md](T08-139-verified-row-repair-map.md) |
| 140 | [T08-140-verified-row-repair-map.md](T08-140-verified-row-repair-map.md) |
| 141 | [T08-141-verified-row-repair-map.md](T08-141-verified-row-repair-map.md) |
| 142 | [T08-142-verified-row-repair-map.md](T08-142-verified-row-repair-map.md) |
| 143 | [T08-143-verified-row-repair-map.md](T08-143-verified-row-repair-map.md) |
| 144 | [T08-144-verified-row-repair-map.md](T08-144-verified-row-repair-map.md) |
| 145 | [T08-145-verified-row-repair-map.md](T08-145-verified-row-repair-map.md) |
| 146 | [T08-146-verified-row-repair-map.md](T08-146-verified-row-repair-map.md) |
| 147 | [T08-147-verified-row-repair-map.md](T08-147-verified-row-repair-map.md) |
| 152 | [T08-152-verified-row-repair-map.md](T08-152-verified-row-repair-map.md) |

前9篇（129,130,133–139）工作表分支提交`da2973e34199fd273b7a8b98754544d249cc0327`；後9篇（140–147,152）提交`d23808c924e89e5896104684bff97be75c0a8d63`。

## 剩餘待研究與可驗收邊界

- **仍需逐篇完整語義重建**：134–147與152的上述座標表尚未成為完整修訂原稿；129–133也需T01對全部肯定主張複驗，不能因有source修訂就標FULL-PASS。
- **無T01逐列code表的另外六篇**：131/132已有上述限定R2修訂，148、149、150、151仍要回原始BIN重解真正CFG及vtable，不能自動推測所有程式碼座標統一平移。
- 所有版本需要嚴格區分code RVA、PE `.rdata`絕對vtable、常數與欄位地址。跨函式的ABI和所有權若只憑舊文字，仍屬未驗。
- **正式狀態**：`T01-RETURN-T08-LEGACY-MAPPING-001`仍`NEEDS_FIX`；T01審核`RESOLVED`、共用FULL-PASS、RR接受與Server可玩分開。T08-202整體目標未完，也沒有因此開203。

## 相關來源

`shared/integrations/T01-20261029-semantic-review/t08-early/{mapping-findings.json,mapping-reviews.json}`；`kr/tasks/T08/README.md`；`shared/verified-knowledge/README.md`。
