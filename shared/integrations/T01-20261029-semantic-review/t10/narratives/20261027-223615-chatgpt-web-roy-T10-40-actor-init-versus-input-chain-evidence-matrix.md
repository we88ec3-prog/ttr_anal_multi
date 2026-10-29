# T10-40 — actor 初始化與控制器輸入的雙鏈界線、後續可驗證橋接點（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 新核對：同名/同偏移不能自動合併
1. 【確認】factory `0x4AE5E4` 分配 `0x444`，`0x4AE609` 呼叫 `0x4CD6F0`，`0x4AEB34..0x4AEB7D` 對同一個 `esi` 連續執行 vfunc `+0x3C/+0x44/+0x58/+0x5C/+0x30`。這建立 constructor → instance field init → 虛擬方法的一條具體鏈，但**尚未找到這個 instance 寫入玩家 controller 所讀取的 actor slot 的中間指令**。
2. 【確認】setter `0x4CE90A` 透過 selector 5 把帶號 WORD 擴展為 DWORD `+0x3E8`，先清理 `[+0x364]` 舊從屬狀態；只有當新值為 1 才呼叫 vfunc `+0x4C`、`0x49B140`、`0x551F90`，並把新返回物件存回 `+0x364`。這是具體資料生命週期，不能直接稱作 V 蓄氣動畫。
3. 【確認】`0x5462ED` controller 在 `0x54F270` predicate 失敗後，如果 actor `+0x3E8!=0`，仍會把局部 byte `[esp+0x17]` 設 1。若兩者都不允許，`0x5462FD` 執行 `and WORD [ebx+2],0x8000`。**這是 selector/actor state 影響 controller gate 的強直接證據**，但真正玩家事件如何設定 selector 未知。
4. 【確認】`0x546338` 的 index5==0 判斷只出現在後續的空間/方向輔助分支，不能直接和 `0x5462ED` gate 混成同一個 V 按鍵。
5. 【確認】`0x4C90C0` 管理 `+0x3A8` 旗標；`0x5464C0` 搜尋方向；兩者均可出現在玩家控制器流程中，但不是 `+0x3E8` 的寫入者。
## 可測試狀態轉移（靜態條件）
| 靜態條件 | 可觀察程式分支 | 原生來源 | 玩家語義 |
|---|---|---|---|
| `54F270` true | local flag=1 | 0x5462DD..2E6 | 未知技能類型 |
| predicate false 且 `actor+3E8!=0` | local flag=1 | 0x5462ED..2F6 | 未知 charge/state |
| predicate false 且 `actor+3E8==0` | `word[ebx+2] &= 0x8000` | 0x5462FD..302 | 未知 bit-group |
| `[FB9009]==0` 且 158 chain/4C9ED0 pass | 空間/方向分支 | 0x546338..374 | 未證明攻擊 |
| `4C90C0(actor,1)` 且 `actor+3A8==0` | `actor+3A8=1` | 0x4C90CC..113 | 非 +3E8 |
## 後續工作清單（精確阻塞點）
- 找到確切 `vptr+0x2C` call，其 receiver 必須有從 `0x4CD6F0` 建構實例連續傳遞的資料流；從此回查 selector 參數是否 `5`，而不是盲搜所有 `+0x2C`。
- 確定 actor 指標來自哪個 registry/slot：追 `0x4AEC00` 的 `0x4DFF30` 及 `0x546137` 的取值鏈，中途每個樹節點與索引保留型別。
- 針對 `[0xFB9004+index]` 的**非零 writer**，先辨別 index 5 是何 action row，獨立證實鍵重映射的 Z/X/C/V 對應；勿直接以 VK_Z 猜。
- `0x546100` 下游要另尋動作開始→動畫事件→queue→完成/cancel 的有證據 callback；T11 已有的 skill matrix 只作跨任務引用。
## 批次總結／交付界線
四段分別得到：型別 factory 至 instance 初始化鏈、輸入 index5 的閘門極性和控制器局部 state、方向掃描 helper 的 256 候選上限、setter 與 controller gate 的嚴格證據矩陣。研究深度以函式/狀態流證據為準；未解結構連線明示，不聲稱已還原 V 或 Z 普攻。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x4ae5dd–0x4ae614
[code block separately checked in preflight]

### VA 0x4aeb0a–0x4aeb80
[code block separately checked in preflight]

### VA 0x4ce90a–0x4ce9a3
[code block separately checked in preflight]

### VA 0x5462dd–0x546374
[code block separately checked in preflight]

### VA 0x4c90c0–0x4c913a
[code block separately checked in preflight]