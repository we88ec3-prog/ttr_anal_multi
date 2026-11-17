# P0 內容真實依賴：完整 Q119/3 與 Q2440/5 的選檔鏈

日期：2026-11-17。分支：`extra/roy1`。研究基準：`ac7e668ef19b91f86f05074d660aba10612c9a5f`；main 讀集基準 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。目標 BIN SHA-256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 1. 結論與可驗證終點

本輪已把上一輪 Q119/3 的部分依賴查核，以及 Q2440/5 的單張 DDS 樣本，擴成**兩個真實原始 Scene 函式的全部靜態呼叫與所能到達的資源依賴**。Q119/3 有 46 個 body calls；Q2440/5 有 62 個；各另有一個 top-level `Register`。兩者均是單一、無分支、無迴圈、無賦值的 literal 直接呼叫函式。產生器消耗全部 token，遇到新增構型直接失敗，不會把只找到若干檔名字串當作全 Scene 分析。[D1]

本次新增原生證據把幾個容易誤接的層次分開：**Master.stp 建立虛擬目錄與載體關係；檔案索引的同 basename 保留首筆；Actor.ID→FILE 暫存表的同 ID 則後列覆寫；正式 Q.Create 還會請求 action 1、4 與模型衍生預設 item；Prolog19 的圖片欄確有獨立載入及繪製 consumer。** 這些規則使 Server 可以建立可審查的內容依賴檢查，而不必猜 `Character/Mon/`、Q PRE 或「一張圖就是整個場景」。[N1–N7]

**完整實際資源閉合仍受阻。** 15 個不同模型只有 2 份實際描述檔可讀；其餘 13 份描述檔、Items.ipk、Master.stp、fcs.flu／同版本 scan 結果、FLD、頭像與各種 payload 不在本輪可用材料中。缺描述檔便不能列出其未知後代。本包保留每個到達的 frontier，`full_transitive_payload_enumeration_complete=false`，沒有把「已完整分析現有輸入」改寫成「所有需要的資源已列盡／實際選檔已證」。[D1–D3]

| 完成層次 | 本次結果 | 不能據此宣稱 |
|---|---|---|
| 全部原始呼叫覆蓋 | 兩函式 108 body calls；0 未消耗 token | Lua／Client 已執行 |
| selector、模型鍵、action、直接內容與已到達的子依賴 | 原始資料與 native 路徑公式已對照，132 個依賴節點 | 缺失描述檔的後代已知 |
| 同版本實際選檔 | `BLOCKED_MISSING_ORIGINAL_SOURCE` | Base member 就是 runtime selected entry |
| payload 與語意接受 | 多項明確缺件；無 native open/parse/render 成功資料 | 模型、動畫、音效或圖片可呈現 |
| Server／玩家流程 | 提供 REQ-0019／0021 增量需求 | 任務結算、獎勵、進度遷移或遊玩驗收通過 |

## 2. 來源、方法與原文邊界

原件讀集是 `02-Tartaros.bin`、`06-Event.stp`、`07-Table.stp`、`10-BoundMap.stp`、補充 `Base.stp` 及 `Tartaros-Web-AI-W1-W2-W3-input.zip`。六份來源皆逐次核對完整 SHA-256 與 bytes。既有 STP 只讀 reader 與 Lua lexer 由 Git commit／blob／SHA 固定；所有使用的舊報告、native windows、原 Boot chunk 與反編譯導航亦在 [source-manifest.json](source-manifest.json) 逐項保存。[S1]

四份 STP index 分別含 7,382、1,026、1,296、830 個 members；ZIP 有 131 entries，其中 19 個 local-resource 成員。**830 是 Base index 數，不是 830 份描述都已解析。** 本題實際解析 Base 的 `Mon/02_Stoncken.abf` 與 `Mon/00_Alphonso.abf` 兩份。26 個 active TalkTableSet 成員共 50,222 列，僅輸出所選 talk keys 的位置、屬性、字數及文字 SHA，不輸出故事文字。[D1、D2]

Lua 只用 lexer 與受限 parser 讀取，從未執行。全部 calls 保存 line、name、arity、call SHA 與依賴分類；位置／角度／等待時間等非資源參數不整批複製到 Git。原 BIN／STP／ZIP、完整 SEQ、完整解出 XML 只留原有本機材料。新 native 摘錄按實際函式起點反組譯，截取完整指令，另核 PE mapping、原 bytes 與相同反組譯結果；反編譯 C 只是導航，沒有代替原 BIN。[D2、N0]

每個依賴節點分開保存 `source`、typed `selector`、`proven_path_rule`、exact/case/basename candidates、`missing`、`parents` 與 readiness。ASCII casefold／basename 查找只是盤點比較，**不冒充 native filename→member ID 演算法、執行期 locale 或選檔順位**。所有節點的 `native_selected_path`／native 成功欄位目前仍為 null。[D1]

## 3. 三種覆寫／保留規則不能混用

### 3.1 Master 是載體與虛擬目錄的必要原件

原始啟動 `48BD30` 建立 package manager `FE48E0`，將它接到 `FBA814`，於 `48BE13` 呼 `713740`。後者使用字串 `Master`，經 `715620` 附加 `.stp` 並交 `714770` 開啟；其內部 package name 必須對上 `Master0z`。`EncSetting` 若存在，本路檢查為 4 bytes；缺省使用 1。這些是本 build 的啟動輸入，沒有據此推導整體加密格式或繞過規則。[N1 `package_manager_install`、`master_open_and_name`、`master_encsetting_and_walk`、`package_suffix_open`]

`7135B0` 遞迴走 Master 子目錄節點：用 directory name 呼 `714D50` 登記虛擬目錄，再找 `AttachedPackage`，讀出實際 carrier basename，經 `715620` 開啟成功後寫入目錄物件的 provider `+0x100`，之後繼續遞迴。`714D50` 比對目錄名不分大小寫；既有目錄會回同一物件，否則追加新目錄。因此**重複指向同一虛擬目錄的成功 AttachedPackage 設定，可以改寫該 provider**。這與下面的 basename 索引保留首筆是不同層。[N1 `mount_recursive_assignment`、`mount_directory_registration`]

目前只有 Base 的 member `Mon/02_Stoncken.abf`，沒有 Master 的實際 AttachedPackage 樹。故 `Character/` 是否掛某個 package，`Mon/` 是載體內相對路徑還是 selected scan directory 的一部分，不能只用字串拼接解決。需要同一安裝版本的 Master 原件及其指向的 carriers，而不是任選一個看起來合理的前綴。[D3、N1]

### 3.2 路徑查找、member ID 與 loose-file 次序

`714C50` 將 path 按斜線／反斜線切段，掃描大小寫不敏感的目錄節點；有 provider 就先向 `7155B0` 問剩餘 path，未取到才向同一目錄的下層遞迴。`7155B0` 確認 file node 型別，將 node `+0x11C` 的 member ID 與 provider entry `+0x44` 相等比較，尚未 materialize 的 entry 走 `7186A0`。本題證實的是 lookup 接口與 ID 比較，**沒有把 STP reader 的 ASCII index 查找當成完整 native member-ID grammar**。[N1 `mount_path_lookup`、`package_member_id_and_cache`]

沿用已固定的 `714770` 路徑：mounted package hit 優先於後續 loose-file fallback；fallback 仍有既有 restriction／prefix／integrity 條件。缺原 Master、實際 cwd、index、cache 及 carrier 版本，不能選定最終 bytes。此規則不表示任何同名 loose file 都一定能覆寫載體，也不表示所有「外部檔案」都一律可讀。[S1 `published_package_reader_native`]

### 3.3 模型表後列覆寫，檔名索引首筆保留

| 層次 | 鍵與處理 | 本輪可證結果 |
|---|---|---|
| `540B10` Actor 暫存 map | category 3 排除；key 為 Actor.ID；PRE 轉數字後丟棄 | 後一個 accepted ID row 對同 key 指派 FILE；Q 的 model catalog 不選 PRE |
| `7198F0` cache entry 建立 | filename 經 `7198B0` 正規化，再查同一 group 的索引 | key 已存在就刪除新 entry；首筆 accepted entry 保留 |
| `718FB0` default scan | 同樣 normalized basename key | duplicate 走 Conflict 記錄與新 entry 釋放；只有 miss 插入 |
| `714D50`／`7135B0` mount tree | 同名虛擬目錄回既有節點；成功讀 AttachedPackage | 寫 provider `+0x100`，可由後一次成功綁定改寫 |

cache duplicate 的關鍵分支在 `719A0E` 比較 iterator、`719A3D..719A52` 已存在時釋放新 entry；default scan 的 duplicate 路在 `7194DE` 後分流，至 `7196D4` 釋放新 entry。這給出「同 key 保留首筆」的原件反例，不能用 Actor.ID 的後列覆寫規則代換。實際第一筆仍取決於 fcs 中記錄順序／真實 scan 遍歷順序；本包沒有那些原件，故沒有猜贏家。[N2 `cached_basename_first_entry`、`scanned_basename_first_entry`；舊 selection windows]

## 4. Q119/3：完整 46-call 依賴

`Event/SceneList.xml` 的 `(questIdx=119, sceneIdx=3)` 唯一列指向 `Phindous_YuriandRazed_Boss`，原 member 為 `Event/Sequences/Phindous_YuriandRazed_Boss.seq`；1,571 bytes，decoded SHA `05abe5f9773c3b0b40d5a849f7d984b4f06f57d2e5a5fe8c931e83ec2d7b857a`。內容涉及三個 Q slots，皆 model 1086。[D1、D2]

| Q slot | Create 行 | 預掃描最終 action 集合 | 正式額外請求 |
|---|---:|---|---|
| 0 | 13 | 1、4、8、11、101 | 1、4；本例已在集合中 |
| 1 | 14 | 1、4 | 1、4 |
| 2 | 15 | 1、4、8、11、103 | 1、4；本例已在集合中 |

collector 的 Create／Ani／Walk 規則按原 native replay：低 WORD slot/model；首筆 Create 決定 model；新 record 的原始 action **恰為 0**才先改 1，再截 WORD；Walk gate 0 不收集、負 action 才用 4。這裡是 `55D6A0` 重新綁定的預掃描 callback `55CED0`：`55D17D` 查 gate，`55D188..55D18C` 以 signed test／jns 將負整數改為4。**正式 qbase P26 helper 只在 action 等於 number −1 時改4，與此預掃描規則分開。** 本例行 40、41 的 Walk gate=0，manifest 記 `collected=false`；action 11 仍由後續 AniObject 明確納入。這是資源依賴 replay，沒有跑場景或把行走座標當 Server 出生點。[D1；S1 bridge report／native；父包 abi-adoption]

1086 的 admitted ActorList 三列 PRE 為 1、2、5，但 FILE 全為 `02_Stoncken`。model numeric key 只有 1086；不能任選 PRE1 或 PRE5 作 Q 模型鍵。Base 唯一 basename candidate 為 `Mon/02_Stoncken.abf`，真實 CharacterList 可解析，但其選中 runtime path 仍未知。[D1、N2]

六個需要的 motion 都有實際宣告：`Stoncken_WAIT01.gb3`、`Stoncken_MOVE01.gb3`、`Stoncken_STUN.gb3`、`Stoncken_KNOCKED.gb3`、`Stoncken_SKILL01.gb3`、`Stoncken_SKILL03.gb3`；另有 BaseFile `Stoncken_BASE.gb3`、Texture `Stoncken.dds`。101／103 的子列增加兩個 `Effect/Monster/M_Stoncken-AttacK01.eff`／`M_Stoncken-AttacK03.eff` 與對應 Stoncken SKILL01／SKILL03 WAV。實際 payload 在本讀集都缺；EFF 的子依賴也不能在缺 EFF 原件時自行補出。[D1]

其餘直接依賴如下：

| 類別 | 已綁資料 | 邊界 |
|---|---|---|
| Camera | `Event/CameraWorks/Phin_YuriandRazed_Boss_01.cam` exact member，framepos 0／140 | 只證原檔與結構；未執行相機 |
| FLD | `mushroom12D.fld` → MAP_FLD selected entry | FLD 原件及實際 entry 缺失 |
| world BND | 7 個 `_MapList` rows 同 MAP stem，BOUND 都為 `mushroom12`；`BoundMap/mushroom12.bnd` 原件在 | 不據 filename 選定 Server MapId；Q.LoadMap 本身未因此證明讀 BND |
| Talk | `OpenTalkScene(12,11)` → 5 列：display keys 3、2、1、3、2；talk keys 1287–1291 | 五個文字 key 可綁 active table；display extension／portrait／voice 未齊 |
| Music | `Sound/BGM024.ogg` | 表名存在不代表音檔存在 |
| SFX | Stoncken_SKILL01.wav、SKILL03.wav、DEAD.wav 的原 literal／Sound declarations | 兩個 skill 音亦出現在 ABF 子列，來源保留而不當成五個不同音檔 |
| 預設外觀 | model1086 嘗試 default item32086 | 查表嘗試；不是 inventory item grant，也不保證有對應 descriptor |

`SetFinalMusic("")` 是空字串 append0 的保留語意，不是一個缺失音檔，也不是清空。Start 的 assign0 清空與 Restore／End 的後續處理參見 sibling lifecycle，不在本題把它改寫成 cleanup。[D1；父包 execution-lifecycle]

## 5. Q2440/5：從單張 DDS 擴成完整 62-call 場景

selector 唯一指向 `Aisen_01_After`，原 member `Event/Sequences/Aisen_01_After.seq`；2,353 bytes，decoded SHA `22131443cd236fd9498847353da3e7b8f8862f05cfab3258932e8158c9be3258`。14 個 Create 的原始 action 都是 0，因此預掃描收 1；正式物件在 `M+70` 及 materialized model 存在的條件下另要求 1、4。slot10 的 Walk 再加入 action51。只看原 script 的非零 action 或先前的單張 FlyingObject，會遺漏大部分內容。[D1；bridge `formal_resource_consumer`]

| Slot | Model | ActorList FILE | 所需 action | 顯式 item | 衍生 default item 嘗試 |
|---:|---:|---|---|---:|---:|
| 0 | 1478 | N01_Soma | 1、4 | 1 | 32478 |
| 1 | 1479 | N02_Pipa | 1、4 | 10 | 32479 |
| 2 | 1480 | N03_Sblm | 1、4 | 19 | 32480 |
| 3 | 1481 | N04_Isla | 1、4 | 28 | 32481 |
| 4 | 1482 | N05_Aelt | 1、4 | 37 | 32482 |
| 5 | 1483 | N06_Grnt | 1、4 | 46 | 32483 |
| 6 | 1484 | N07_Crmd | 1、4 | 254 | 32484 |
| 7 | 1485 | N08_Ruko | 1、4 | 5601 | 32485 |
| 8 | 1486 | N09_Epds | 1、4 | 7072 | 32486 |
| 9 | 102 | 00_Alphonso | 1、4 | 0 | 31102 |
| 10 | 10320 | 14_Alster | 1、4、51 | 0 | 41320 |
| 11 | 10323 | 14_Tommy | 1、4 | 0 | 41323 |
| 12 | 2064 | 11_SupplyCabH | 1、4 | 0 | 33064 |
| 19 | 10107 | 07_Mimi | 1、4 | 0 | 41107 |

ActorList 另有 category3 的 ID102 `Stone_Option_StoneWander`；本 catalog producer 明確排除 category3，不能把它當成與 `00_Alphonso` 同等的未解候選。這 14 個模型中，Base 僅有 `Mon/00_Alphonso.abf`；所需 WAIT01／MOVE01 皆宣告存在，BaseFile／texture 亦已記錄；另外 13 個模型的 `.abf` bytes 缺失，無法完成後代列舉。[D1]

其餘場景內容完整納入：七個 `Aisen_01_After_01.cam` 至 `_07.cam` 都在 `Event/CameraWorks/`；三次 Talk selectors 為 `(168,29)`、`(168,30)`、`(168,31)`，合計 7 talk rows，keys27000–27006；兩首音樂為 BGM148／BGM147；直接圖片為 `Image/Prologue/Aisen00_1.dds`。[D1]

FLD 請求是 `town014S.fld`。原 `_MapList` 無相同 stem；`_SysMapList` 有 ID50412/MAP `town014`，BoundMap 有 `town014.bnd`，但這是**不同 literal 的鄰近候選**，沒有原件規則授權刪掉 S 後綴或把它選為 Q 場景 BND。manifest 保存 nearby evidence 與 `edge_to_town014S_proven=false`，實際 FLD／BND／world context 待同版本原件解除。[D1、D2]

### 5.1 15 個預設 item 與 9 個顯式 item 的正確含義

QCreate 將模型鍵交 actor virtual `+3C=4C6FB0`，寫 actor `+88/+8C`；`4C7E2D..58` 優先取 `+8C`、轉 low WORD，經 `7A4C50` 寫 Doll `+18`。`4D101A` 讀這個 model，再於 `4D1021` 加 `0x7918`（31000），由 `4D1029` 交 `7A7240` 的 ushort item 參數。因此 default lookup key 是 `(modelLowWord+31000)&0xffff`；不是另外猜一張 item stat 表的值。[N4]

`7A7240` 用 item、variant/type 與 model 查 `FE1B60` appearance catalog，model-specific miss 再試 common model0；兩者都 miss 回 0。**這只證每個模型會嘗試查表，不能把每個 lookup absence 一律當 Scene 必失敗。** 選定全外觀呈現目標時，哪些 default／顯式附件必須存在應由內容 profile 明定；native 的 silent miss 與 Server 的發布驗收政策需分開。此處兩 scene 共 15 種 model default 嘗試；Q2440/5 另有表中 9 次顯式非零 item 嘗試。[D1、N4]

實際資料入口也已找到：啟動 `48CF01` 傳 `Character/Cha/Items.ipk` 給 `7AC7E0`，讀 `IPK` root、`Include`、`ItemList`／`EffectList`，再到 `7ACA80` 建 typed catalog；`Include File` 會遞迴，選取的 descriptor File 經 `7ADD40` 組目錄／檔名與 `714770` 讀取。此 IPK 與其 Include／File 原件在可用材料中缺失，所以目前不能從 item1、32086 等整數推得一個真實附件 mesh 路徑。附件髒標記、apply 與 release 所有權由 sibling lifecycle 接續。[N4]

### 5.2 Prolog19 有七種圖片，不是一個抽象文字呼叫

原 `Table/Prolog.xml` 的 idx19 有 10 個 Dialog、36 個 Line；圖序列為 `Aisen01_1`、`_2`、`_3`、`_3`、`_4`、`_4`、`_5`、`_6`、`_7`、`_7`，皆 `Image/Prologue/*.dds`。因此 7 種 Prolog 圖加上前面的 Aisen00_1，共 **8 個不同 DDS**。保存的是行數／文字 SHA 與圖名，沒有整段序章文字。[D1]

前輪 `Q.Dialogue` consumer 不使用 PicturePath，不能套用到這次 `DoProlog`。本輪直接核 `55F370`：讀 owner `+24` 的目前 row，從 row `+1C` 取 PicturePath，轉寬字後呼 `736B00` texture cache，結果存 owner `+8`；`55FC50` active 時對非空 owner `+8` 呼 texture virtual `+24` 繪製。`55F960` 換段以及 `55F9D0` fade transition 都有真實 caller 到 `55F370`。這將原 XML 圖名接到實際 texture consumer，沒有只停在欄位名稱。[N5]

同一 row 的 zero-based ordinal `+38` 經 `55F470→4A03F0` 形成 `Scenario/Prologue/P%02d_%02d.ogg`，再由音訊 helper 處理 Sound 前綴。因此 idx19 有 P19_00 至 P19_09 十個 voice candidates。沒有 voice bytes 或 native 選中結果，`.ogg`／`.wav` fallback 的 probe 存在也不等於串流播放成功。[D1、N6]

## 6. 模型子資源與 FLD：公式閉合，未知前綴保留

model catalog 先按 numeric ID 取得 record；`79D570` 把 record `+38` 的 directory 及 `+1C` 的 filename 傳 `7AC4C0`。reader 串接兩者，開 XML/EX 資源並進 CharacterList。這一段沿用上一輪已釘選的原件結果。[S1 selection／bridge]

本輪延伸兩份實有 CharacterList 的 `RelativePath` 路徑：`7AEE60` 將 incoming directory 存 resource `+4`、RelativePath 存 `+20`、BaseFile 存 `+3C`；new resource constructor `7C3220` 設 `+F4=0`。`7C5670` 在此旗標為 0 時組成 `directory + "Avatar/" + RelativePath`；旗標非 0 時路徑不同，不能把前者當所有資源的無條件 grammar。[N3]

| 類別 | 兩份 selected descriptor 的有條件請求公式 | consumer／限制 |
|---|---|---|
| Base mesh | base prefix + BaseFile | `7C5BE0→7C4310→7D0920`；沒有 payload 語意成功證據 |
| Motion | base prefix + `Ani/` + Animation.File | `7C5710`、non-ASD 分支及 motion 建構；ASD 用另一 prefix helper |
| Texture | base prefix + `Texture/` + Texture.File | TextureList 存 resource `+74` vector；`7C5600`／`7C4310` 將 key/path 提交 `FE1AE0` |
| Effect／Sound 子列 | 所選 action 的 Folder+File 宣告 | 真實 EFF／音訊原件缺失，不能越過 frontier 猜後代 |

`scene-dependencies.json` 保存含 `<selected CHA_ABF[...].directory>` placeholder 的 symbolic request，明示它不是實際 path。譬如 Stoncken 的 motion 尾段可具體寫成 `Avatar/02_Stoncken/Ani/Stoncken_WAIT01.gb3`，但前面的選中 directory 仍為 null。沒有把 Base index 的 `Mon/` 偷填進去。[D1、N3]

檔名宣告 `.gb3`／`.dds` 與引擎其它 packed format 的存在亦分層：本輪不將另一路驗檔函式的 `.emf/.etf` probe 視為這些 render loaders 已證的 fallback grammar。缺真實 payload 仍不能宣布 base mesh、motion、texture 的 parse 或語意可用。[D3]

FLD 路徑已接到另一個確定 group：`Q.LoadMap(563C40)→7C1E00` 使用 basename 加 `.fld` 查 `MAP_FLD`；建立 parser `7E9FF0` 的 vtable `C50908`，其 `+4` 明確為 `7ED180`。該函式重查 MAP_FLD，經 `79C590→543500` 組 `entry.directory + entry.filename`，TiXml `72F110` 再進同一 `714770` package／loose-file opener。缺 fcs 或實際 scan entry 與 FLD bytes，實際 field、geometry、objects、environment 的後代仍不能列出。BND 與 Server 地圖選擇是額外 world 資料契約，不由此字串推導。[N7]

## 7. 對話文字、頭像、語音與共用 UI

兩個 Scene 共 12 個 Talk rows／12 個不同 talk keys，均可從 active TalkTableSet 唯一找到文字；文字與 face attribute 的 metadata 全數保存。每個 `talk_text` 節點綁到實際文字表的 exact member，12 個已解出的文字節點不列為缺件；132 個依賴節點中的 108 個保留明確缺件前緣。同版本原生 mount／目前文字表選取則仍受全域來源 gate 約束，不能用這個靜態表列匹配代替 runtime 選檔證據。Q119 的 `char` 列與 Q2440 的 `npc` 列在 native record 有 kind0／1，但已驗 `6BD050` display consumer 取 key 與 talk key，沒有按這個 kind 分支尋找世界 EntityId。manifest 保留原始 kind，沒有把相同數字的 display actor、model、Q slot 或 Server entity 合併。[D1–D3；S1 dialogue report]

Q119 display keys1／2／3 在 supplied NPCTable 無列；Q2440 的10320、1201有原 NPCTable 名稱列，2／7沒有。這不能直接等同「角色不存在」，因為 native 依序還讀 `Image/TalkNPC.xml`，延伸名字、face group 與表情對應；頭像 consumer 又查 `NPC_Talk` image group。缺這份 extension 及其 image resources 時，不能只用 text 存在便宣稱頭像對白完整。[D1、D3]

talk voice 選擇也有具體原件規則：`49FED0` 從 version32 降到0，先問 `Sound/Scenario/%02d/Locale`；存在、成功開啟且長度2、內容為 `JP` 的候選會被跳過。其餘版本嘗試 `Scenario/%02d/V%05d.ogg`，由 `49FD10` 組字串並使用 `80D230` 的 Sound 前綴及 ogg/wav probe，再取 resource，第一個得到 resource 的版本即離開搜尋。這是最多33版的候選順序，不是預設選00或32；12 keys 的候選以 template 表達，不展開成數百條猜測選中路徑。缺 Locale 與聲音載體時 `selected_voice_path` 仍未知。[N6、D1]

一般 ScenarioTalkBox、PrologBookPanel、字型 cache、fade／文字 renderer 等共用 owner/context 必須由既有 Client 初始化提供。此題核的是完整 Scene 根與其已到達依賴，並未取得全部 UI image/font 配置或全程式動態 globals；故另列 inherited UI/context frontier，不能因七張 Prolog 圖都已命名就聲稱 UI 資源閉合。`FALSE` 則已有實際 Boot 原件：baseline number0，經 qbase Create helper 轉 `isVisible=number1`，再用 **native integer32** 取1；不是 boolean false，也不是這個參數走 lua_toboolean。載入順序與後續 writer 條件見 sibling ABI 採用。[D1；父包 abi-adoption]

## 8. Q119 world 資料與現行 Server candidate 的差異

補充 ZIP 的同 bytes 原資料可連 `Quest119.field26 → Case107.STAGE26 → CHART_scenario_chicken_01 node1/Map635`；cluster 資料中另有 `Cluster19 / model1086 / PRE1 / COUNT1`。它能提供合法的內容上下文，但不能證明演出 slot0／1／2 對應 cluster19 的某個 runtime instance，也不能拿 chart editor x/y 當出生座標。[D1 world_data_context；S1 supplemental-audit]

父包已比對 main 基準的 Server candidate：相應 node4／sourceNode1／Map635 採 `selectedCluster4`、encounter models `[1001,1001,1001,1022]`、enterScene3／clearScene4，returnScene5。這是 Server 候選政策與其來源摘要，**不是** Q119/3 的三個 model1086 演出物件或 cluster19 的原生同一實體。外部 story-q119-clear-scene scenario 亦不能因有戰鬥 node／portal 就被當成已綁 scene。精確來源與採用方式由 [SERVER-ADOPTION.md](../SERVER-ADOPTION.md)／integration pins 保存，本包不覆寫它。[父包 integration/server-context.json]

## 9. 精確缺件與解除條件

| 缺口 | 現有證據能做到哪裡 | 解除所需材料 |
|---|---|---|
| 虛擬根與載體 | 原生 Master／AttachedPackage walker、覆寫及查找規則 | 同版本 `Master.stp`，其引用的 carriers、安裝 roots／overlay 清單及 SHA |
| CHA_ABF／MAP_FLD 實際 entry | fcs record／default scan／basename first-wins／entry 拼路徑規則 | 同版本 `fcs.flu`，或真實 scan 來源目錄與完整順序／結果；不能只給另一版 cache |
| 13 份 Q2440 模型描述 | 原 ActorList 的精確 FILE stem、required actions | 表中13個 `.abf` 原件及其 carrier/version；之後才展開其所有子依賴 |
| 外觀附件 | 15 default +9 explicit lookup attempts、typed fallback及IPK入口 | `Character/Cha/Items.ipk`、recursive Include、匹配 descriptor/File及payload；依profile決定缺項是否阻擋 |
| 已有兩模型的子資源 | 10個所選 base/motion GB3宣告、2 texture、2 EFF、相應WAV | 真實 meshes／motions／textures／effects／sounds與可驗版本；EFF再展開後代 |
| FLD與world地圖 | `mushroom12D.fld`／`town014S.fld` MAP_FLD請求；Q119有BND資料；Q2440只有未連的town014候選 | 真實FLD及其child assets、明確world／Server地圖選擇；不能用BND替代FLD |
| 12段頭像對話 | 場景列、文字、face metadata、native display／voice selector | `Image/TalkNPC.xml`、`NPC_Talk`／face圖片、版本Locale及聲音載體 |
| 8種DDS、3首BGM、3種直接SFX、10段Prolog voice | 全部直接／資料衍生候選已列 | 相應Image／Sound載體、選中檔與parse/render/play證據 |
| inherited UI／runtime context | 已知owner、binding、loader與caller邊界 | 同版本UI/font配置與資源；其初始化、載入及實際呈現測試獨立驗收 |

root 本輪針對 Image.stp／Sound.stp／TalkNPC.xml／Master.stp 做精確 title 與一次簡化查詢，並完整列出實際 ttr 資料夾17檔；沒有可新增材料。另在 source-map-v2 的3187個 original_path 作定向比對，所需 Master／fcs／IPK／ABF／FLD等未命中。fcs／Character／Field 沿用前輪陰性而未重掃。這是**可用來源範圍的有界陰性紀錄**，不是「安裝版本沒有這些檔案」。詳細機器紀錄在父包 [source-availability.json](../source-availability.json)。本包不保存私人檔案識別碼。[父包來源紀錄；S1]

## 10. Server 開發需求與採用建議

沿用既有 **REQ-0019／REQ-0021**；不另建平行台帳、不自稱已 ACCEPTED。建議將本 graph 接到父包 Server-owned scenario/version 管線，保留 `NOT_NATIVE_MEF` 邊界，先支援下列可實作契約：[S1 prior dependency contract；父包 Server adoption]

1. **Typed 身分與來源版本。** QuestScene、Qslot、QModel、world actor/PRE、display actor、talk key、appearance item、MapId／BOUND 各自儲存。每個內容版本綁原 carrier SHA、selector、實際 index/mount entry；world PRE 不能灌回 Q catalog key。
2. **預驗完整 profile。** 記錄整個 Scene 的直接 calls、formal action1/4、default／explicit附件、ABF的所選actions、effect/sound children、Talk／Prolog圖文與音訊。缺描述檔時拒稱「後代已全列」，回報確切 frontier。required／optional 由可審查的 feature profile決定，保留原生缺件可能silent skip的事實。
3. **三層成功狀態。** 分開 `audit_complete`、`selected_payload_resolved`、`native/runtime_accepted`。模型event被signaled、Scene query變idle、GetFile取到候選或文字key存在，都不能自動代替對方或視為遊戲成功。
4. **版本發派與進度遷移。** Server須自行提供相容內容版本選擇、相依性檢查、已完成任務ID保留、checkpoint／returnScene／結算及獎勵政策。換content hash不應靠重置帳號解決；也不能宣稱Client必有未知MEF傳檔opcode。
5. **可玩驗收仍獨立。** 完整材料與可審查實作備妥後，按使用者既有正常流程優先政策安排有限遊玩驗收。此研究沒有啟動Client／Server、沒有封包發送或新增全套Server行為測試。

四層剩餘工作：**Client待逆向**是尚未逐項閉合的完整child格式／UI資源及動態writer等具體邊界；**原件受阻**是本表精確缺件；**Server待開發**是版本、預驗、進度與結算等政策；**跨功能待整合／待遊玩驗證**是ABI、lifecycle、world選圖與真實呈現。這些不互相冒充，也沒有改動任何Task owner、catalog、native_complete或歷史FULL-PASS。[D3；父包採用文件]

## 11. 重跑、結果與證據導航

重跑命令見 [README.md](README.md)。驗證器預設只讀，逐一核 source Git blob＋SHA／bytes、六份原件、native windows與strings／vtable、舊窗口原bytes，再從原STP／ZIP重新生成三份資料並逐項相等比較。lexer/parser 的合成控制包含註解內假call、escaped字串、qualified Q call及五種拒絕構型，均只是分析器測試，不是 native／Server測試向量。實際結果保存 [verification-result.json](verification-result.json)。`--require-ready`維持exit2，不能藉研究驗證PASS消掉缺原件。[V1]

| 記號 | 本報告使用的第一手／固定證據 |
|---|---|
| S1 | [source-manifest.json](source-manifest.json)：原件及published commit／blob／SHA固定讀集 |
| D1 | [scene-dependencies.json](scene-dependencies.json)：兩selected functions、typed graph、原資料meta與world join |
| D2 | [member-evidence.json](member-evidence.json)：member block／offset／stored/decodedSHA，含未連town014候選 |
| D3 | [dependency-frontier.json](dependency-frontier.json)：精確frontier與材料要求 |
| N0 | [native-evidence.json](native-evidence.json)：所有完整指令、raw offsets、SHA與重用窗口 |
| N1 | `package_manager_install`、`master_*`、`package_suffix_open`、`mount_*`、`package_member_id_and_cache` |
| N2 | `cached_basename_first_entry`、`scanned_basename_first_entry`及prior selection windows |
| N3 | `model_resource_directory`、`model_relative_path_branch`、`model_default_path_flag`、`model_*_prefix`、`texture_*`、`model_mesh_path_consumer`、`model_reload_base_consumer` |
| N4 | `qcreate_model_key`、`qactor_*`、`doll_model_store`、`default_item_attempt`、`appearance_item_lookup`、`items_ipk_startup`、`ipk_*`、`item_*` |
| N5 | `prolog_texture_load`、`prolog_texture_draw`、`prolog_next_picture_caller`、`prolog_transition_picture_caller`及prior prolog table/pop windows |
| N6 | `talk_voice_version_selection`、`voice_resource_probe`、`sound_prefix_and_format_probe`、`prolog_voice_format` |
| N7 | `fld_*`、`entry_directory_filename_concat`、`two_string_concat`、`xml_uses_package_open`與`fld_parser_vtable` |
| V1 | [verify_evidence.py](verify_evidence.py) 與 [verification-result.json](verification-result.json)；只證研究可再生，不授予正式驗收狀態 |
