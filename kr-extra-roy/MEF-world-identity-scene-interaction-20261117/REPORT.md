# 世界身分與事件／場景與互動：整合分析與開發邊界

研究日期：2026-11-17（Asia/Taipei）。目標倉庫 `we88ec3-prog/ttr_anal_multi`，沿用 **extra/roy1**。本輪核對分支仍為 `0d76b827dfda0deb263e2692281ec304747652f8`、main為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。原件、舊稿和規則的精確來源見 [source-manifest.json](source-manifest.json)。

**本輪完成的是兩條選定 native 功能鏈的整合、缺邊補證和 Server 開發交接，不是全部 MEF 功能、普通世界事件到 Lua 或實機遊玩已完成。** 官方 MEF 入口／格式仍未證，新增內容設計均為 `NOT_NATIVE_MEF`。不以全部戰鬥轉交腳本為門檻。

## 1. 使用者問題的結論

### 世界身分與事件

可以確定不同建立來源、world lookup、控制關聯、死亡呈現與實際移除各自使用何種身分及欄位。新增一條有實際world erase consumer的受限Lua刪除，並證明它與001A的控制器前置不同。然而本地生成物件的可靠ID回報、普通死亡／群清到Lua的最後連接仍未取得，不能用畫面死亡或樹節點移除冒充。

### 場景與互動

已將005F field、0012普通map、lb.ChangeMap、Q視覺map備份、BOUND／minimap、points、S2C000A控制重綁、loading及ready分開。這使Server可以據以設計正確發布偏序，而不是把換到相同畫面或送過某個ready當成完整轉場。

| 研究目標 | 本輪交付狀態 |
|---|---|
| typed world ID與Q／point／relation domains | 有界native契約與既有證據接合完成 |
| 網路／本地建立、更新、控制重綁、死亡與移除 | 選定正常consumer閉合；型別前置與資料來源另列 |
| 受限Lua世界刪除的真實參數與引用邊界 | 新增正向鏈，非任意怪物刪除 |
| 普通world死亡／群清結果→Lua | **未閉合**；precise missing edge保留，不作全程式不存在宣告 |
| field/map/point/controller/loading/ready的同流程關係 | 有界原件契約與必要偏序完成 |
| 特定實際關卡的portal／spawn／formation最終資料綁定 | **待整合**；Map/Case/BND身分已核，W2圖表關係復用，不猜值 |
| Server通關、服務、發布、權威狀態與保存 | **Server待開發**，不是要求Client補回官方Server內部演算法 |
| Client／Lua／Server／遊玩驗收 | **未執行** |
| Git遠端發布 | 本環境沒有寫入操作；已製作累積patch，**未推送** |

## 2. 本輪新增的五個實質結果

**一，Tutorial.DeleteObject不只硬編碼固定角色，但也不接受任意EntityId。** 它使用 `(arg & 255) << 8`，進入共用world erase。參數240可選到0xF000；直接傳0xF000反而投影成0。只有來源已知且布局／引用條件成立的lowbyte0目標才可規劃使用；沒有新成功ACK。詳見 [世界 §5](WORLD-IDENTITY-EVENTS.md)。

**二，網路移除和Lua刪除的控制器處理不等效。** 001A命中任一受控槽時會呼controller清整槽；共用erase裡的三次v+1C只是getter。Lua直接erase沒有取得001A相同的preclear契約。這影響剩餘角色重綁，不可只看world tree有沒有ID。

**三，0012會先清points及控制槽，同MapID也照做。** loader在同ID直接走音樂尾段，不重載graphics／BOUND／minimap。lb.ChangeMap則沒有前面的清理。故不能把重送同MapID當完整reset，也不能把兩個入口當整體等效。詳見 [場景 §3–4](SCENE-INTERACTION.md)。

**四，loading、ready與Q解除是三個狀態域。** 前端0023／0024寫Client loading欄；0014設controller+4，且僅Q inactive時清mask1。它不清mask2、不清controller+58，也不回報所有資源／角色已成功。00EB仍是另一條Q等待解除。

**五，Q.LoadMap/RestoreMap只保存一份演出backup。** Load記camera及mapKey後走視覺loader；Restore不回寫world currentMapKey，且會更新backup key。它不是actors／points／bounds／minimap及Server節點的整體交易回滾。詳見 [場景 §5–6](SCENE-INTERACTION.md)。

## 3. 功能如何分工

可以優先採取「Server持有可靠worldID、合法地圖／points及權威結果；相容內容只編排已證本地操作」。例如既有互動點切換、已知world actor的外觀，以及有限演出後恢復。

不能將以下步驟省略：
- CreateObjectEx無ID回傳，0007 hit不是採用；需另有可靠配對。
- 000C的state3可以重入，不能每次enter都算新死亡；001A可移除未死物件。
- S2C000A先查relation record及world actor；缺失不暫存，晚到建立不補播。
- 0027是完整snapshot；0048及Lua setter只修改第一個匹配既有點。
- mapKey已寫入、loading清零、handler回0x100、003F抵達都不是一般「操作成功」ACK。
- 005F和普通UI事件不保證舊qco已取消；內容與Server須定明生命週期。

詳細需求與正常路徑驗收在 [SERVER-HANDOFF.md](SERVER-HANDOFF.md)，不是正式Server程式或新RR台帳。

## 4. 第一手證據與復用範圍

本輪唯讀KR BIN、Table.stp、Event.stp索引與BoundMap.stp的選定成員。既有身份／死亡／Q actor／005F分析以固定Git commit/path/blob引用；只對新的連接與必要接點追加原件檢查。

本輪實際保存：
- **48個連續native區間、20,388 bytes、5,113條解碼指令**；窗口包含必要舊接點，數量不是新功能數或全程式覆蓋率。
- **25組精確byte錨點、8組資料區間**；RTTI描述符與名稱地址分開核對，vtable只保存選定真實前綴，鄰接metadata不冒充方法。
- **10條指定call、11個vtable關係**；另有4個target的E8候選與counter literal候選範圍。
- **4個原件resource member**：MapList、CaseList及兩份scenario BND，只發布少量屬性、前綴與hash。
- **30項明示為推導的離線模型檢查**，非執行原Client或Server。

可讀組譯：[native-evidence.asm](native-evidence.asm)；機讀資料：[native-evidence.json](native-evidence.json)、[resource-evidence.json](resource-evidence.json)。已查範圍、復用項目及下一條證據入口見 [read-set.json](read-set.json)。

### 精確資源例子不是合法spawn配置

原表Case103確實引用Field/Stage19的chart／cluster；Map191、192確實分別引用對應MAP、BOUND、TRIGGER字串。既有W2已保存nodes1/2對應。本輪只核成員身分，不重做全部BND幾何，也沒有給任意出生座標、portal key或formation token。附加Table/Event索引中未找到兩個exact graph檔名，不等於其他資源或舊W2證據不存在。

## 5. 驗證與可重現性

[verify_evidence.py](verify_evidence.py) 先核原BIN SHA與PE節區，按區間hash與實際機器碼解碼；反組譯讀到區間end之後再檢查最後完整指令，避免把截斷指令當通過。再核byte錨點、RTTI、vtable、call與bounded候選，最後核選定資源及純資料模型。

```sh
python -S -B verify_evidence.py \
  --bin /path/to/Tartaros.bin \
  --table-stp /path/to/Table.stp \
  --event-stp /path/to/Event.stp \
  --boundmap-stp /path/to/BoundMap.stp
```

`-S`可略過外部site自動載入；本工具只用標準函式庫和GNU objdump。不允許`-O`繞過原件parser assertions。STPD reader從既有已審閱data-only parser抽出並固定hash，從未執行Lua chunk。工具只印結果，不改原始資源、不發包、不抓Git。

實際成功stdout保存在 [verification-result.json](verification-result.json)。PASS只表示限定證據一致與模型自洽，不是語意形式證明、T01 FULL-PASS、所有間接call閉包或可玩驗收。

## 6. 下一步及發布

優先把「指定普通轉場的真實資料綁定＋發布偏序」接到Server規格，再交一個已知worldID的本地操作切片。world事件到Lua另追一條真正producer→typed state/callback→getter鏈，不重掃已排除的教學／Q／圖片觀察器。完整次序見 [NEXT-ANALYSIS.md](NEXT-ANALYSIS.md)。

前兩輪31個待發布檔案保持原樣，本輪另新增此自有目錄；累積patch與ZIP保留所有內容，不覆寫歷史。GitHub目前只讀，沒有產生新遠端commit；發布狀態、套用檢查與限制見 [PUBLICATION.md](PUBLICATION.md)。
