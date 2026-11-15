# 收尾封包契約：00EB 的完整接收鏈與 003F 的使用界線

## 1. 本輪結論

**在這份 KR 原始 BIN、正常初始化且 callback 未被另行改寫、經有效lane2 business connection、current field 是本稿核對的 Mission／Scenario 的條件下，S2C application bytes `EB 00` 已足以到達現有的等待解除 helper。** 本輪從入站 frame parser、application queue、Client 前端整張表初始化、SceneManager、current field，一路接到 `4B6190 → 562250`，補上前輪刻意保留的「只見 handler 不讀 body，尚未證完整封裝」缺口。〔[native-windows.json](native-windows.json)、[contracts.json](contracts.json)〕

可供相容 Server serializer 採用的兩個**靜態合成範例（SYN）**如下。它們由原件 receiver 的規則推導，沒有發送至 Client，也不是官服 pcap：

| 層次／形式 | 完整 bytes | 長度 |
|---|---|---:|
| Application payload | `EB 00` | 2 bytes |
| `1A68` raw frame | `02 00 68 1A EB 00` | 6 bytes |
| `0BBB` differential XOR frame | `02 00 BB 0B EB 00 5D EB` | 8 bytes |

**00EB 解除等待，不負責載入 `.mef`、停止 Q、清除 qco 或確認本次內容已成功執行。** `003F` 也不能單獨提供這些保證：除了正常 End，Q 的「已看過而略過」支線同樣能送出它；這一支會跳過本次正常 sequence 選取／載入，卻仍進入等待鎖。Server 必須依自己追蹤的 instance／內容鍵／執行階段決定是否送 00EB。這是 **Server 開發需求**，沒有宣稱官方固定 `003F → 00EB` 一對一配對。〔`c2s_003f_builder`、`q_start_and_skip`、`reused_q_end_target`；前輪 [input-lifecycle](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)〕

## 2. 固定原件、方法與本輪增量

| 項目 | 身分／範圍 |
|---|---|
| 工作分支／parent | `extra/roy1`／`acc5b1e6d856bd31456fe2806044c3a09d5bbb43` |
| 最新 main 參考 | `060ed5163a67308f15aa32a91f3a6661e6e5b106`，未 merge |
| 原始 Client | `02-Tartaros.bin`，12,472,320 bytes |
| SHA-256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| PE | i386 PE32，ImageBase `0x400000`；每個 VA 依實際 section raw 範圍轉址 |
| 原件證據 | 35 records，其中 28 code windows、4,168 decoded instructions；合計 18,212 bytes，含前輪重核視窗 |
| 來源 | 13 個 commit／path／Git blob／SHA-256 pins；見 [source-manifest.json](source-manifest.json) |
| 驗證 | 原件逐窗 bytes／完整指令邊界、46 anchors、197 frontend overrides、3 個 003F direct-call candidates、合成 framing 算術；見 [verification-result.json](verification-result.json) |

既有 E54／E59／E60／E84 已提供底層 transport 與 routing 研究；本輪不把這些舊發現全數重列為新成果。**新增閉合是把 00EB 的特定命令、完整 frontend 初始化、最小 payload／frame、三個 003F producer 與收尾排程放在同一份可重驗契約。** 原件是結論依據；以前的大型報告只重讀相關段落者，已在 manifest 明列，沒有宣稱整份重讀。

所有檢查均為靜態讀取，不執行 Client／Lua，不附加 process、不改原資源，也沒有為此建立新 branch。

## 3. 從 wire 到 application：長度與 lane 不能混在一起

### 3.1 直接以 inbound parser 證明

`806CF0` 的 receive completion 分支先核 OVERLAPPED／有效 Conn，再在 `806E08` 呼 `807B40`。後者以 `EDX=Conn+18` 的 receive buffer 及累積 cursor 解析多個 frame；不是把每次 receive 視為完整 application。〔`receive_iocp_prefix`、`receive_frame_parser`〕

本稿採用兩種已核形式：

| 欄位／條件 | Raw `1A68` | `0BBB` |
|---|---|---|
| `frame+0` | u16 LE `n` | u16 LE `n` |
| `frame+2` | u16 LE `0x1A68` | u16 LE `0x0BBB` |
| Header 長度 | 4 | 6 |
| `frame+4` | payload 開始 | u16 LE plaintext bytes sum mod 65536 |
| 內容開始 | `frame+4` | `frame+6` |
| 解碼 | raw copy | 首 byte XOR `B6`；後續 XOR 前一個已解碼 byte |
| 合法 n 範圍 | 1…`0x1000` | 1…`0x1000` |

`807C34..807C3E` 必須已有 `header+n` bytes 才繼續。`807D35` 的 seed、`807D53` 的前一 plaintext byte、`807D5F` 的 WORD 累加及 `807D66` 的 header checksum 比較，共同支持上列 BBB 規則。當 plaintext 是 `EB 00`，sum 為 `00EB`、cipher 為 `5D EB`；header 的 n=2 **不包含 header 自己**。〔同一完整 parser 視窗；[contracts.json](contracts.json) 的 frames〕

parser 另有 2633 解壓與 22D7／default raw 分支；本輪沒有以其存在擴張成「Server 可任選未知 marker」。也沒有把 Client **出站** writer 的 total-buffer 上限錯套成 inbound n 上限。這兩點沿用 E59／E85 的方向區分，本稿兩個最小向量直接按 inbound 重新核對。

### 3.2 decoded node 與 lane 的真正來源

`807E50` 將解碼內容複製到 `node+8`，把 payload 長度放 `node+4`。成功正長度節點經 `807DA6 → 489920` 取得 `FC10D0` queue owner，再經 `807DAD → 8040A0` 排隊。**lane 來自 `Conn+A080`，不是 wire 多出的一個欄位。** 本稿的 business callback 條件是 lane=2。〔`node_payload_copy`、`queue_owner`、`queue_enqueue`〕

main update 的 `49198A → 804740` 取出 node，以 `(Conn*, node+8, node+4, lane)` 呼 callback holder slot0。正常 CClient 的 holder `H=C+148`，其 vtable `C05AEC` slot0 是 `4930E0`。這一層先讀 application WORD，之後才測非零長度，再只對 lane2 轉交。**因此最小完整 opcode 是 2 bytes；不能因 transport 容許 n=1 就宣稱 1-byte application 對這個 consumer 安全。**〔`queue_consume`、`client_packet_callback`、`client_constructor_prefix`、`client_packet_vtable`〕

## 4. 本輪完整閉合的 frontend table

### 4.1 三個 base 必須分開

| 符號 | 所指物件 | 有關 offset |
|---|---|---|
| `C` | 完整 CClient | callback holder `C+148`，frontend `C+200` |
| `H` | `C+148` | `H+B8 == C+200` |
| `F` | `C+200` frontend subobject | handler `F+0x08+16*op`，this-adjust `F+0x0C+16*op` |

constructor 的 `48ACAC` 將 `C05B04` 寫到 `[C+200]`；該 vtable `+4` 原 DWORD 為 `48AAD0`。因此 `493135` 對 `H+B8` 的 virtual call 可以精確落到 frontend dispatcher。`48AAD0` 把 command WORD sign-extend、乘16讀 handler 與 adjust，再在 `48AB34` 以 `adjust+F−200` 形成實際 receiver；預設 adjust=0 時就是完整 C。〔`client_constructor_prefix`、`client_frontend_vtable`、`frontend_dispatch`〕

`48BE50` 使用 framework 子物件參數；其 `48C027` 取 `EBX−8`，`48C02A` 呼 `493170` 建表。對正常 `C+8` framework 初始化，建表 base 是同一個 C；`C05AA4+20` 指向該 init，`+30` 指向 main update `490FE0`。本稿採正常初始化成功、有效接收 owner 的前提，不宣稱初始化錯誤路徑也已 ready。〔`client_initialize`、`client_tick_vtable`；framework 基址沿用前輪 entry 證據〕

### 4.2 完整 initializer 支持的精確陰性

原件 `493170..494355` 除開頭 **3029 次、stride16** 的預設 loop 外，其餘為固定 offset stores、常數裝入及返回，沒有後續 call／另一個條件分支／未解寫入形式。

- loop 將 handler 設 `494360`、this-adjust 設0、metadata 設 `BF2375`。
- loop 後完整解出 **591 個固定 stores = 197 個唯一 handler 項目及各自 adjust／metadata**。
- `004C`、`004E`、`00EB` 三筆 record 均未被這些 stores 覆寫。

| Application | Handler record 相對完整 C | 初始化後路由 |
|---|---:|---|
| `004C` | `+6C8` | default `494360` |
| `004E` | `+6E8` | default `494360` |
| `00EB` | `+10B8` | default `494360` |

這比 E84「195 個特定相鄰編碼樣式命中」的範圍更完整，但**只擴張到這一個已逐指令分類的 initializer**；仍不排除日後 runtime table alias／patch。197 不用來宣稱整個程式只有197種業務命令。完整 stores、handler 值與查詢結果在 [frontend-table.json](frontend-table.json)。`004C`／`004E` 後續語意由同輪 [events 分題](../events/report.md) 接續，不與 00EB 混用。

## 5. 到 ordinary field 的 00EB

本輪以原件重新核對前輪 field 鏈：

| 階段 | 具體 native 關係 | 前提／結果 |
|---|---|---|
| Frontend default | `48AB3B → 494360` | 當前初始化表的 00EB 無 override |
| SceneManager | `49439C` receiver=`FD2CF8`；v+4=`4FDA30` | 00EB 採 `4B7DC0` 初始化的 default `4B7EC0` |
| Current field | `4B7EC0` 讀 `SceneManager+5EAC`，非NULL才 tail-call field v+4 | 無 current field 時不保存成「稍後自動重播」 |
| Mission／Scenario | v+4=`4C4670`；secondary slot `field+6604` 在兩個初始化範圍被清零，無 00EB override | secondary miss 回 `4FDA30` primary dispatch |
| Common primary | `4AE1FD` 寫 `[field+75C]=4B6190` | `(75C−4)/8 == EB` |
| Handler | `4B61E5 → 562250`，`4B61EA` 清 EAX 返回0 | 全函式不取 message bytes／length 內欄位 |
| Unlock | `5622DB → 753440` 依 F4322 tag 移除等待 dialog，`562307` 清 `FB8830 & 2` | 找不到該 dialog 也仍到清 mask 路徑 |

證據分別是 `reused_scene_manager_*`、`primary_index_dispatch`、`reused_ordinary_*`、`reused_common_field_callback_registration`、`reused_unlock_packet_00eb`、`reused_input_wait_unlock`。00EB 經這條完整路由沒有比 opcode 更長的 payload 欄位需求，故**2-byte app 是本版本這條路由的足夠最小候選**，並非宣稱官方每次必定只送2 bytes。

handler 返回0，`4930E0` 不會為它走「handler return0x100 且 loading flag 非零才暫停 lane」的分支；但 queue、時間、loading 與當前場景的其它條件仍存在。解除成功也不證其它 input mask／capture 已清。前輪已證 Q active 會另設 controller `+58`，本 helper 不處理該欄、Q active、qco 或 VM。〔同一 native windows；[前輪兩層 input owner](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)〕

## 6. 003F：可實作的 builder，不能當「新 MEF 跑過」證據

### 6.1 原始 8-byte application schema

`4A39A0` 先組八個 bytes，僅當 `[FBA798]==0` 才經 NetworkManager v+10、key0、length8 排送。vtable `C51748+10=8069A0` 是 queue method；這裡不是已觀測 wire transmission。〔`c2s_003f_builder`、`network_manager_vtable`〕

| Offset | 型別 | 值／producer |
|---:|---|---|
| +0 | u16 LE | `003F` |
| +2 | u16 LE | `arg1` 低16位；End caller 從 manager `+38` 取 |
| +4 | u16 LE | `arg2` 低16位；End caller 從 manager `+3C` 取 |
| +6 | u16 LE | 常數1 |

前輪已將 manager `+38/+3C` 接回 SceneList 的 quest／scene 雙鍵；本稿的 raw contract 刻意保留低16位與 caller，而不把最後 WORD 擅命名為「MEF成功」或「全部清理完成」。〔`reused_q_end_target`、`q_start_and_skip`；[原 entry 雙鍵選取](../../MEF-entry-lifecycle-events-20261114/entry.md)〕

### 6.2 三個直接 caller 的分歧

原 `.text` 對 `4A39A0` 的 E8-rel32 有三個候選，全部回到已知函式起點確認指令邊界。這是 bounded direct-call 清冊，不排除其他間接呼叫。

| Callsite | 能走到的條件 | 請求／結束含義 | 後續等待鎖 |
|---|---|---|---|
| `5618C8`，位於 `561760` | 初始 Q 非active；`FB92F1!=0`、第一key=0、GameInfo模式為9／4／25，第二key已在 manager `+74` 集合 | 送 `(0, requestedKey, 1)`，跳函式尾；本次正常 sequence 選取／載入與後面的 active 設置被略過 | `5618CD → 5620B0` |
| `561FB0`，位於 normal End | active、非review、`M+38!=0`，`CheckConfirmMessage` 回值恰1 | 送目前兩鍵；後續仍有 Lua／UI 收尾 | 此分支不經 `561FE5` |
| `561FE0`，位於 normal End | active、非review、`M+38==0` | 先清 active，送目前兩鍵；不是所有收尾已完成 | `561FE5 → 5620B0` |

第一列的原件控制流從 `561823` 條件進 `561864` 查已看集合，命中後到 `5618C8`，再在 `5618D2` 跳 `561D86`。一般接納要到 `5618E9/EC` 寫雙鍵、`5618EF` 設 active，之後才查表與載入。這是**不能把收到003F當本次新檔案曾執行**的具體反例，不是泛泛的未知可能性。〔完整 `q_start_and_skip`〕

normal End 的送報位置又早於 `56202D → f_removeAllCoroutines`。因此即使不是略過分支，003F 也不是怪死亡事件、清組完成、原生物件同步完成或獎勵可入帳的充分證據。相關業務判定與重送／去重都要由 Server 規則實作。

## 7. 實際可安排的送出時機

此處的「能傳」分三個層次：transport 能排入 frame、既有 application handler 可達、遊戲狀態允許產生該副作用。本輪補齊 00EB 前兩層的有界原件證據；第三層是 **Server 的合法狀態與收尾協調需求**。

| Client／Server 狀態 | 00EB 的可用性 | Server 開發要求 |
|---|---|---|
| 完整 lane2、ordinary current field 已初始化；對應 run 已停止／進入等待解除階段 | 本稿支持的相容使用候選 | 為既有00EB實作 serializer，與自己的 current run／instance 狀態關聯 |
| Q 還 active，只想讓玩家持續戰鬥 | 清一層mask，不停止Q；controller限制仍可持續 | 選能滿足 ordinary 背景工作需求的 runner，不把00EB當取消API |
| 在 End 重新置鎖之前處理了00EB | 之後 End 可再次 OR mask2 | 排程必須滿足 End／置鎖之後才解除，不能只採固定毫秒delay |
| 收到003F但內容已被略過 | 仍可能有 wait dialog／mask，然而本次腳本未走正常載入 | 區分略過、正常End、取消；不得以003F證明新MEF已接手工作 |
| SceneManager current field為空，或該場景未保留本稿callback | 本稿不能保證到解除helper | 驗證目前field／transition，不預送期待Client自動保留重播 |
| 遲到、重複、跨下一run的00EB | payload沒有instance、generation、key | Server在自己的佇列／狀態機抑制過期解除；不能新增Client未讀的欄位來假裝有token |

frame 中沒有 run ID，handler 也不回一個00EB專屬ACK。本版 main update 先做 `49198A` receive pump，後做 `491ED7` Q pump，`491FDD` 才是後段send drain；這支持按狀態／事件順序設計，**不提供網路延遲的固定時間保證**。其它上游 early-return／loading gate 的影響沿用前輪 input 報告，不將任意瞬間都稱為可執行時機。〔`reused_client_update_order`；[前輪收尾條件](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)〕

新 Server 可以設計「核對目前合法內容鍵的003F，再安排適用的00EB」作為相容策略；該策略與原版官方的因果配對要分開記錄。選擇策略後還需在獲准的整合驗收中觀察 runner、dialog、mask、controller 與scene，不能用本稿靜態PASS取代遊玩驗證。

## 8. 驗證與交付

最小交付為本報告、native JSON／asm、frontend table、contracts、source manifest、唯讀 verifier、verification result。所有 hex 範例都是文件中的合成資料，沒有製作可執行遊戲資源。

```sh
python -B kr-extra-roy/MEF-world-integration-20261115/wire/verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --repo /path/to/ttr_anal_multi
```

verifier 先驗 helper SHA 與原件 SHA，再核每窗 bytes／disassembly／指令終點、原始 vtable、完整591 stores、固定來源的 commit/path/blob。另以純Python重現兩個指定 frame 的解碼算術、未完整prefix保留、多frame與checksum失敗不投遞；**這一部分只證明文件算術與模型自洽，沒有執行 native parser。**

本題已收斂的範圍是00EB這個既有收尾consumer與其可重驗封裝。新 `.mef` 的首次caller、常駐戰鬥runner、實體ID與typed事件仍依同輪各分題及主報告處理；官方MEF原檔、官方003F回覆政策沒有被列成停止Server開發的先決條件。
