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

## 2026-10-31 原生後續修正：T08-134～152（本分支）

前一次索引只記錄129～133。後續已完成7份涵蓋134～151的真正PE BIN-first交叉研究，證據與原Git blob及跨篇未解在[134～151技術稿交付索引](../20261031-023700-chatgpt-web-roy-T08-T01-legacy-134-151-BIN-correction-delivery-index.md)（blob c65530704ffde0106a47a98f4f585dc8da6cebb4）。

本輪新增**獨立原生 T08-152 完整有界勘誤來源**：[T08-152 native PE／MSVC RTTI 原生證據](../20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md)（Git blob **14813f82c72673a0ffe271dcdc23ad6abcb106f3**；舊T08-152原稿仍保留FAILED）。本輪重新按真PE對指令入口、完整BIN DWORD/E8、RTTI COL、TypeDescriptor和vtable各表界核對，確認：

- C4F67C 主vptr **MSVC RTTI CDoll offset=0**，+0x08保存真 **7A63C0**（有guard的B producer）；主/次vtable不是靠相同+0x08 offset推測同一動態類別，而是來自RTTI型別與constructor四份vfptr的交叉證據。
- **C4F6C0為CDoll offset+0xC子物件vtable，只有+00/+04/+08三個method**；分別為7AAA90(ECX−C thunk)、7A8310（execute）、7A8E10（三維距離平方score）。**C4F6CC = C7F9F4是下一個Ref_count<ModelReleaseSpec>表的COL，不能當成C4F6C0的+0x0C方法。**
- 另一控制表 C0760C由 C07608 COL 指示實際型別 **std::tr1::_Ref_count<CDoll>**；其+0=4CA660、+4=7A3920都有原生有效入口。先前「指向半指令」負面推論從真PE反證撤回。
- 全BIN搜尋真7A63C0有一筆原始DWORD at raw 84DC84；無direct E8只是表示vtable間接分派，不是producer不可達證據。**仍需找到具體slot+8間接caller及動態owner/析構時序；B→22桶及原版wire/Server觸發不因此成立**。

上述是進一步原生勘誤，但**不是T01對24份原稿的全文FULL-PASS，也不授權把整項LEGACY-MAPPING-001改RESOLVED**。舊來源／原審核歷史均維持。其後優先查Host→virtual slot+8實際caller與T08-202未完別名writer。

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

- **仍需T01逐篇全文複驗**：134–151已另有7份交叉勘誤稿、152有獨立BIN-first完整有界修訂來源；這些是新的技術證據，不是對每篇來源每項肯定主張的T01 FULL-PASS；129–133亦仍待T01複驗。
- **無T01逐列code表的另外六篇**：131/132有獨立限定R2，148–151已有上述跨篇原生勘誤；仍須重新核對所有受影響source的完整CFG、生命週期與未知的間接caller，不能機械平移或擅自結案。
- 所有版本需要嚴格區分code RVA、PE `.rdata`絕對vtable、常數與欄位地址。跨函式的ABI和所有權若只憑舊文字，仍屬未驗。
- **正式狀態**：`T01-RETURN-T08-LEGACY-MAPPING-001`仍`NEEDS_FIX`；T01審核`RESOLVED`、共用FULL-PASS、RR接受與Server可玩分開。T08-202整體目標未完，也沒有因此開203。

## 相關來源

`shared/integrations/T01-20261029-semantic-review/t08-early/{mapping-findings.json,mapping-reviews.json}`；`kr/tasks/T08/README.md`；`shared/verified-knowledge/README.md`。
