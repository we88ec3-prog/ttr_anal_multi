# W2：Base.stp 三怪 body 原件完整盤點

日期：2026-11-04（Asia/Taipei；實際產生時間見 JSON）。使用者指定分支：`extra/roy2`。

**已從新提供的 `Character/Mon/Base.stp` 直接取得並完整讀取三個 body。** `Mon/00_HokyPoky.abf`、`Mon/01_Moose.abf`、`Mon/01_Nepenths.abf` 的 bytes 與既有 SHA 宣告一致。三份 XML 合計 94 個節點、419 次屬性、47 個 Animation 宣告。這次補齊的是 body 及其動作／資源引用；body 內沒有 matrix skill WORD 對應欄位、技能傷害／冷卻／距離、完整影格數或命中時間。來源為 [base-stp-audit.json](base-stp-audit.json) 的 `targets`、`totals` 與逐節點 inventory。

狀態：`BOUNDED_DIRECT_RESOURCE_AUDIT_NOT_T01_FULL_PASS`。本次三個 body 的有界資料盤點已完成；沒有提升 T01 FULL-PASS、RR 接受、S00 規格狀態或宣稱 Server 已實作／可玩。原有 ZIP-only W2 成果應保留其歷史來源範圍；新提供的原件另以本補件結果追溯。

## 1. 原件、格式與可重跑核對

本段只開啟使用者提供的 `Base.stp`，沒有開啟其他 STP、BIN、MEF，沒有執行歷史腳本、遊戲或 loader。新核對器 [audit_base_stp.py](audit_base_stp.py) 依已讀的格式來源重新實作；舊程式僅作文字參考。格式來源的精確 Git blob 在 JSON 的 `format_sources`。

| 項目 | 本次直接核對結果 |
|---|---|
| 邏輯來源 | `Character/Mon/Base.stp`；使用者提供檔名為 `Base.stp` |
| 原件 bytes | 946,961 |
| 原件 SHA256 | `1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957` |
| Block table offset | 860,176 |
| STPI directory index offset | 886,740 |
| Directory nodes | 1,450；包括空目錄，不等於檔案數 |
| File members / block records | 830 / 830；全部 file member 的 suffix 為 `.abf` |
| Stored MD5 | 830 / 830 相符 |
| 索引完整性 | 精確讀到 EOF；member ID 唯一，與 block ID 集合相等，無 orphan block |
| 資料配置 | block allocations 無重疊；每筆 stored extent 均在資料區內 |
| 解碼及全文 XML 盤點 | 僅本次三個指定 body；其餘 827 份沒有 EX 解碼或 XML 語意盤點 |

來源：JSON `archive_sha256`、`archive_bytes`、`archive_index`、`read_scope`。

格式核對分為三層。STPD container 的資料先做全檔 XOR `0xff`，由 header 指向 STPI tree 與固定 32-byte block records；每個 body 位於 `16 + first_block × 1024`，取 record 宣告的 stored size。**Stored MD5 是 XOR 還原後、EX 解碼前的 member bytes 雜湊**，與 XOR 還原的 record digest 比較；它不是直接對硬碟上那一段加擾 bytes 算的 MD5。三個 body 均為 EX mode 1，payload offset 為 16，經 XOR1024 key 與 zlib 解碼；核對宣告長度、zlib EOF、無未使用尾端及無未消耗 payload，再核對 decoded SHA256。這些欄位逐筆保留在 JSON target 的 `stored_*`、`archive_raw_member_span_sha256`、`ex_wrapper` 與 `decoded_sha256`。

| 證據鍵 | 精確 member | Actor 上下文 | Member ID | Stored bytes | Raw body offset | Block record offset | Decoded bytes / 行數 |
|---|---|---:|---:|---:|---:|---:|---:|
| B1 | `Mon/00_HokyPoky.abf` | 1001 | 16 | 569 | 16,400 | 860,692 | 3,744 / 39 |
| B2 | `Mon/01_Moose.abf` | 1009 | 43 | 581 | 45,072 | 861,556 | 3,931 / 41 |
| B3 | `Mon/01_Nepenths.abf` | 1004 | 46 | 552 | 48,144 | 861,652 | 4,018 / 41 |

| 證據鍵 | Decoded SHA256，直接對原始解碼 bytes 計算 |
|---|---|
| B1 | `3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633` |
| B2 | `d0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b` |
| B3 | `6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71` |

後文 `B1:30` 表示上述精確 bytes 的第 30 行，**不是 XML 重新排版後的行號**。三份 XML 宣告 `encoding="euc-kr"`、使用 CRLF，解碼與重新編碼 bytes 完全往返。所有節點的 tag、attributes、selector、起迄行、子節點關係均在 `targets[].xml.nodes`；另外用獨立 ElementTree parse 核對整份 tag／attribute 序列覆蓋一致。沒有非空白文字節點、comment 或額外 processing instruction。

在 W2 目錄可重跑：

```bash
python -B audit_base_stp.py --archive /path/to/Base.stp --report base-stp-audit.json --extract-dir /path/to/local-analysis/base-decoded
```

`--extract-dir` 可省略。指定時必須位於 Git repository 外，既有同名 bytes 不同即拒絕覆寫。核對器只把結構化資訊寫入 JSON，不將整份 ABF XML 文字／bytes、archive 或其 ZIP 寫進 Git。當次原始解碼檔供本機分析使用。

## 2. 全部 XML 結構與欄位

| Element | B1 數量 | B2 數量 | B3 數量 | 全部出現的 attribute names |
|---|---:|---:|---:|---|
| `CharacterList` | 1 | 1 | 1 | 無 |
| `Character` | 1 | 1 | 1 | `RelativePath`, `BaseFile` |
| `MeshList` | 1 | 1 | 1 | 無；空節點 |
| `TextureList` | 1 | 1 | 1 | 無 |
| `Texture` | 1 | 1 | 1 | `File` |
| `TextureReplaceList` | 1 | 1 | 1 | 無；空節點 |
| `AnimationList` | 1 | 1 | 1 | 無 |
| `Animation` | 15 | 16 | 16 | `ID`, `File`, `CameraAttach`, `FrameSpeed`, `FaceIndex`, `Repeat`, `RepeatStartFrame`, `LagtimeType` |
| `Effect` | 2 | 3 | 3 | `File`, `Folder` |
| `Sound` | 3 | 3 | 3 | `File`, `Folder` |
| `FaceList` | 1 | 1 | 1 | 無；空節點 |
| `AvatarList` | 1 | 1 | 1 | 無；空節點 |
| `ParticleList` | 1 | 1 | 1 | 無；空節點 |
| **合計節點 / 屬性次數** | **30 / 133** | **32 / 143** | **32 / 143** | **94 / 419** |

來源：各 target 的 `xml.element_counts`、`xml.attribute_inventory`、`xml.nodes`。空 `ParticleList` 與存在 `Animation/Effect` 可同時成立，不能把前者改寫成「沒有任何效果」。

### Character、Texture 與空容器

`Character` selector 固定為 `/CharacterList/Character[1]`，出現在三份檔案第 3 行；`Texture` 為 `/CharacterList/Character[1]/TextureList[1]/Texture[1]`，出現在第 6 行。

| 證據 | `RelativePath` 原值 | `BaseFile` 原值 | `Texture/@File` 原值 |
|---|---|---|---|
| B1:3,6 | `00_HokyPoky/` | `HokyPoky_BASE.gb3` | `HokyPoky.dds` |
| B2:3,6 | `01_Moose/` | `Moose_BASE.gb3` | `Moose.dds` |
| B3:3,6 | `01_Nepenths/` | `Nepenths_BASE.gb3` | `Nepenths.dds` |

`MeshList`、`TextureReplaceList` 分別在三份第 4、8 行；`FaceList`／`AvatarList`／`ParticleList` 在 B1:35/36/37、B2:37/38/39、B3:37/38/39。這些空容器沒有 hidden attribute 或子節點。`MeshList` 空也不否定 `Character/@BaseFile` 的模型引用。

Actor 1001／1009／1004 是依既有 Table inventory 的 `FILE` stem 與本次精確 member 名稱、`RelativePath` 對應而給的分析上下文；**ABF 本身沒有 Actor ID 或 PRE 欄位**。本次沒有確認 loader 如何組合路徑，也不把這份共同 stem body 宣稱為每個 PRE 的完整 runtime 外觀設定。Actor/PRE 對照仍以原 W2 Table 來源為準。

## 3. 全部 47 個 Animation slot

下表完整列出三份 body 的每一個 Animation。每個 selector 為：

```text
/CharacterList/Character[1]/AnimationList[1]/Animation[@ID='<表中的 ID>']
```

三份所有 47 筆都具有相同的五個原始屬性：`CameraAttach="false"`、`FrameSpeed="40.000000"`、`FaceIndex="0"`、`RepeatStartFrame="0.000000"`、`LagtimeType="LightMelee"`。表中補足其餘 `ID`、`File`、`Repeat`，因此涵蓋每筆全部八個 attributes。括號為 XML 原始行號。來源為各 target `animations` 和對應 `xml.nodes`。

| ID | `Repeat` 原值 | B1：`File`（行） | B2：`File`（行） | B3：`File`（行） |
|---:|---:|---|---|---|
| 1 | `1` | `HokyPoky_WAIT01.gb3`（10） | `Moose_WAIT01.gb3`（10） | `Nepenths_WAIT01.gb3`（10） |
| 3 | `1` | `HokyPoky_WAIT01.gb3`（11） | `Moose_WAIT01.gb3`（11） | `Nepenths_WAIT01.gb3`（11） |
| 4 | `1` | `HokyPoky_MOVE01.gb3`（12） | `Moose_MOVE01.gb3`（12） | `Nepenths_WAIT01.gb3`（12） |
| 6 | `1` | `HokyPoky_MOVE01.gb3`（13） | `Moose_MOVE01.gb3`（13） | `Nepenths_WAIT01.gb3`（13） |
| 7 | `0` | `HokyPoky_DEAD.gb3`（14） | `Moose_DEAD.gb3`（14） | `Nepenths_DEAD.gb3`（14） |
| 8 | `1` | `HokyPoky_WAIT01.gb3`（17） | `Moose_STUN.gb3`（17） | `Nepenths_STUN.gb3`（17） |
| 9 | `0` | `HokyPoky_ATTACKED.gb3`（18） | `Moose_ATTACKED.gb3`（18） | `Nepenths_ATTACKED.gb3`（18） |
| 10 | `0` | `HokyPoky_LIE.gb3`（21） | `Moose_LIE.gb3`（19） | `Nepenths_ATTACKED.gb3`（19） |
| 11 | `0` | `HokyPoky_KNOCKED.gb3`（22） | `Moose_KNOCKED.gb3`（20） | `Nepenths_ATTACKED.gb3`（20） |
| 12 | `0` | `HokyPoky_AERIAL.gb3`（23） | `Moose_AERIAL.gb3`（21） | `Nepenths_ATTACKED.gb3`（21） |
| 13 | `0` | `HokyPoky_A01_RISE.gb3`（24） | `Moose_B01_RISE.gb3`（22） | `Nepenths_WAIT01.gb3`（22） |
| 14 | `0` | `HokyPoky_PULLED.gb3`（25） | `Moose_PULLED.gb3`（23） | `Nepenths_ATTACKED.gb3`（23） |
| 27 | `0` | `HokyPoky_A02_RISE.gb3`（26） | `Moose_B02_RISE.gb3`（24） | `Nepenths_WAIT01.gb3`（24） |
| 35 | `0` | `HokyPoky_WAIT01.gb3`（27） | `Moose_WAIT01.gb3`（25） | `Nepenths_WAIT01.gb3`（25） |
| 101 | `0` | `HokyPoky_SKILL01.gb3`（30） | `Moose_SKILL01.gb3`（28） | `Nepenths_SKILL01.gb3`（28） |
| 102 | `0` | 此 body 無此宣告 | `Moose_SKILL02.gb3`（32） | `Nepenths_SKILL02.gb3`（32） |

去重後，B1／B2／B3 分別引用 11／13／6 個 clip filename，合計 30 個。不同 Animation ID 共用同一個 filename 是原始資料事實，不能反推相同狀態或 AI 規則。具體例子包括 Nepenths 的 4、6 使用 `WAIT01`，以及 9、10、11、12、14 共用 `ATTACKED`；這沒有提供「不能移動」「禁止某種受擊狀態」等 Server 判定。[B3:12–13,18–24]

### 單位、FPS、影格與 duration 的界線

| 欄位／問題 | 可確認的資料 | 此來源不能確立的語意 |
|---|---|---|
| `FrameSpeed` | 47 筆都是字串 `40.000000` | 缺 consumer／clip 時基證據；不填「40 FPS」或換算 duration |
| `RepeatStartFrame` | 47 筆都是 `0.000000` | 沒有總影格數、結束影格或時間基準；不視為命中影格 |
| `Repeat` | 1、3、4、6、8 為 `1`，其他已宣告 slot 為 `0` | 保留原旗標；不據此計算動作次數、技能冷卻或 Server tick |
| `LagtimeType` | 47 筆都是 `LightMelee` | 沒有 lag 秒數／毫秒數；也不能把三隻所有技能都分類成近戰 AI |
| FPS、總 frames、duration、hit frame | 這三份完整 XML 沒有明確對應欄位 | JSON 中保持 `null`；不得以 filename、FrameSpeed 或音效長度補猜 |
| collision、range、projectile、cooldown、aggro、chase/leash | 這三份 XML 的完整 element／attribute inventory 均無這些定義 | 不以 BaseFile、clip 或 effect 名稱作為判定半徑或 AI 數值 |

來源：完整欄位集合及 `timing_boundary`。這是對三份 body 的否定結果，不代表別的表、clip、effect 或 Client consumer 沒有相關資料。

## 4. 全部 Effect／Sound 子節點；沒有時間事件

下表覆蓋 8 個 `Effect` 與 9 個 `Sound`，合計 17 個子節點。selector 在對應 Animation selector 後加 `/Effect[1]` 或 `/Sound[1]`。每個子節點**只有 `File` 與 `Folder`**；下表的路徑是這兩個原字串相接，沒有做 case normalization 或推測 archive 位置。

| 來源 | Animation ID | 類型 | `Folder` + `File` 原字串相接 |
|---|---:|---|---|
| B1:15 | 7 | Sound | `Sound/Monster/HokyPoky/HokyPoky_DEAD.wav` |
| B1:19 | 9 | Sound | `Sound/Monster/HokyPoky/HokyPoky_SKILL01.wav` |
| B1:28 | 35 | Effect | `Effect/Assist/State/S_State-BasisDisband01.eff` |
| B1:31 | 101 | Effect | `Effect/Monster/M_HokyPoky-AttacK01.eff` |
| B1:32 | 101 | Sound | `Sound/Monster/HokyPoky/HokyPoky_SKILL01.wav` |
| B2:15 | 7 | Sound | `Sound/Monster/Moose/Moose_DEAD.wav` |
| B2:26 | 35 | Effect | `Effect/Assist/State/S_State-BasisDisband01.eff` |
| B2:29 | 101 | Effect | `Effect/Monster/M_Moose-AttacK01.eff` |
| B2:30 | 101 | Sound | `Sound/Monster/Moose/Moose_SKILL01.wav` |
| B2:33 | 102 | Effect | `Effect/Monster/M_Moose-AttacK02.eff` |
| B2:34 | 102 | Sound | `Sound/Monster/Moose/Moose_SKILL02.wav` |
| B3:15 | 7 | Sound | `Sound/Monster/Nepenths/Nepenths_DEAD.wav` |
| B3:26 | 35 | Effect | `Effect/Assist/State/S_State-BasisDisband01.eff` |
| B3:29 | 101 | Effect | `Effect/Monster/M_Nepenths-AttacK01.eff` |
| B3:30 | 101 | Sound | `Sound/Monster/Nepenths/Nepenths_SKILL01.wav` |
| B3:33 | 102 | Effect | `Effect/Monster/M_Nepenths-AttacK02.eff` |
| B3:34 | 102 | Sound | `Sound/Monster/Nepenths/Nepenths_SKILL02.wav` |

`HokyPoky_SKILL01.wav` 同時出現在 slot 9 與 101，正好說明 filename 含 `SKILL01` 不足以建立某個數值技能的 foreign key。[B1:19,32] `Effect` 子節點存在也不等於有可用的傷害／命中事件：沒有 frame、start、offset、duration、damage 或 skill identifier。完整 XML 沒有 Event／Trigger／Notify element；外部 `.eff` 是否另有時間資訊，本次未讀而保持未知。

## 5. 可用的橋接與仍未成立的 join

本次有直接原件支撐的串接是：指定 Actor 的既有 `FILE` stem → 同名 Base member → `Character/@RelativePath` → body 中的 `Animation/@ID`、`@File` 及附屬 Effect／Sound 字串。前半段是來源名稱對照，沒有驗證 loader；後半段是 XML 的直接父子關係。這足以讓後續設計引用「slot 101 對應哪個 clip/effect 名稱」並保留來源。

| Actor 上下文 | 本 body 內檔名含 `SKILL` 的 Animation 宣告 | 此 body 內的數值技能橋接 |
|---:|---|---|
| 1001 | `101` → `HokyPoky_SKILL01.gb3`；B1:30–32 | 沒有 matrix skill WORD／SkillID 欄位 |
| 1009 | `101` → `Moose_SKILL01.gb3`、`102` → `Moose_SKILL02.gb3`；B2:28–34 | 同上 |
| 1004 | `101` → `Nepenths_SKILL01.gb3`、`102` → `Nepenths_SKILL02.gb3`；B3:28–34 | 同上 |

Table 原件補件的 matrix facts 仍以 [table-stp-presence-audit.json](table-stp-presence-audit.json) 為來源；**Animation ID 與 matrix skill WORD、matrix ID／tier／key、Actor PRE 是不同欄位域**。這三份 body 沒有把數值技能連到 Animation ID 的欄位。不得用 slot 數量、`SKILL01/02` 後綴或相同整數建立這條 join，也不能從效果名稱推導技能距離、傷害、冷卻或施放順序。較早報告的 consumer 主張須另按其來源與審核狀態引用；本次原件讀取不替它們提供新的 native certification。

## 6. 下游引用的精確名稱與缺件範圍

完整 830-member Base index 的 file members 全是 ABF。三份 body 的 70 次引用去重後有 **50 項：30 個動畫 clip、3 個 BaseFile、3 個 texture、6 個 effect、8 個 sound**。逐項 exact literal path 與 basename 在此 Base 的比對都為 0。JSON `referenced_resources` 完整保留這 50 項的精確名稱、引用 member／SHA／selector／line 與負向結果；本文第 2–4 節也已涵蓋全部名稱。

索引包含 `Mon/Avatar/00_HokyPoky/`、`Mon/Avatar/01_Moose/`、`Mon/Avatar/01_Nepenths/` 下的 `Ani`、`Mesh`、`Texture` 空目錄。空目錄不表示具備 GB3／DDS 內容；也不允許推論內容位於哪個未開啟 carrier。對 `BaseFile`、Texture、Animation，JSON 中 `literal_path_from_attributes` 只把 `RelativePath` 與 filename 相接；它不是確認過的 archive member path。Effect／Sound 則保留其自身的 `Folder + File`。

若下一個明確目標是核對五個 `SKILL` clip 的長度或內部時間資訊，可由目前已知的**精確引用**提出下列最小候選輸入。這些是資料名稱，尚未證實它們的其他 carrier／完整載入路徑，不能把表內路徑當作已存在的檔案。

| 角色 | 精確 filename | body 的 literal 相對參考 | 原始行 |
|---|---|---|---|
| 1001 clip | `HokyPoky_SKILL01.gb3` | `00_HokyPoky/HokyPoky_SKILL01.gb3` | B1:30 |
| 1009 clip 1 | `Moose_SKILL01.gb3` | `01_Moose/Moose_SKILL01.gb3` | B2:28 |
| 1009 clip 2 | `Moose_SKILL02.gb3` | `01_Moose/Moose_SKILL02.gb3` | B2:32 |
| 1004 clip 1 | `Nepenths_SKILL01.gb3` | `01_Nepenths/Nepenths_SKILL01.gb3` | B3:28 |
| 1004 clip 2 | `Nepenths_SKILL02.gb3` | `01_Nepenths/Nepenths_SKILL02.gb3` | B3:32 |

與上述 slot 直接相連的精確 effect 引用為 `Effect/Monster/M_HokyPoky-AttacK01.eff`、`Effect/Monster/M_Moose-AttacK01.eff`、`Effect/Monster/M_Moose-AttacK02.eff`、`Effect/Monster/M_Nepenths-AttacK01.eff`、`Effect/Monster/M_Nepenths-AttacK02.eff`，來源分別是 B1:31、B2:29/33、B3:29/33。這些可能供有界的呈現／事件研究使用；沒有先假定檔案內一定存在命中、傷害或技能 WORD 定義。

其餘 WAIT／MOVE／受擊等 clip、BASE、texture、sound 與共用 state effect 已在完整引用清單，屬各自後續目標所需的資源，**不是本次三 body 盤點的 50 個必備檔案要求**。sound 本段只登記原字串，不啟動音效研究。完整資源名單也不能替代尚未定位的 Monster metadata provider 或 skill WORD definition provider；後兩者的精確 member 名稱仍未知，不能擅造 `Monster.xml` 等檔名。

## 7. 後續工作責任與完成界線

| 類別 | 本補件已交付 | 保留的後續事項 |
|---|---|---|
| 原始資源證據 | 完整 Base index／所有 stored MD5；三 body bytes SHA、全 XML 欄位、動作與引用 | 其他 827 body 僅做索引／雜湊，沒有把它們稱為語意已驗完 |
| Client 待補證 | 三 body 的 slot／檔名／父子引用事實 | matrix WORD → 技能定義 → 動作選擇的確切 join；FrameSpeed／timing 消費語意；若有明確需要，再定位對應 clip/effect 原件。沒有以本段授權重新研究 BIN／MEF／loader |
| Server 待開發 | 可追溯的三怪呈現 metadata，unknown timing／數值保持空值 | 目標選取、仇恨、追擊／回歸、攻擊距離、施放排程、冷卻、傷害與同步規則仍須相容 Server 設計；不是要求還原官方 Server 內部演算法 |
| 跨功能待整合 | 可接回 Actor/PRE、已提供的 matrix 與新 body evidence | 依證據等級接入 profiles／skill links／unknowns；不把 body slot 當作 matrix WORD，也不刪掉原 ZIP-only 範圍歷史 |
| 待遊玩驗證 | 本段沒有執行遊戲 | 呈現、動作時序、命中回饋與端到端流程另行安排；靜態 PASS 不代表可玩 |

此段解除了「三個 body 尚未取得」的缺口。缺少原版 Server 政策不能再包裝成 body 缺件，也不能由動畫檔名填入官方 AI 參數；相容 Server 的具體規則需依既有 S00 流程設計與整合。原有 T16 `DRAFT_BLOCKED`、T10/T11 審核狀態及其適用限制未由此資源盤點改寫。
