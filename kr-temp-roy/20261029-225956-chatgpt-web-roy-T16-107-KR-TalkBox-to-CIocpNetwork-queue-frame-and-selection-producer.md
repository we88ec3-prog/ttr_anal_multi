# T16-107 — KR TalkBox 選取紀錄 → CIocpNetwork queue → framing／WSASend：三輪 BIN-first 有界閉合

- 作者：`chatgpt-web roy`；原稿完成時間（Asia/Taipei）：`2026-10-29T22:59:56.179071+08:00`；KR Client 靜態研究，**沒有遊戲程式執行／附加／patch／實測封包**。
- 來源：本次直接讀取 `Tartaros.bin` 12,472,320 bytes / SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 2,594,816 bytes / SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。核對與 T16 固定版本相同。
- GitHub 起點：本對話首次開工已以 `main=43c51f579cada3aa6257eb8467f65af281c3585b`、`t16/roy/chatgpt-web=6723fd0b0da2b870812450ee424574e96c10555b` 比較 `main...branch`，**ahead 22、behind 0**；無需新 merge。符合 AGENTS 同對話後段沿用開工 snapshot 的規則。**此狀態是本對話開工快照，未重查最新遠端瞬時狀態**。
- T01：本對話首次核對之 main Task README 有 **43 READY_FOR_REVIEW / 0 新 NEEDS_FIX / 0 RESOLVED**；T01 尚待獨立複驗；T16 inbox 沒有新 RR。不得把本次研究或作者勘誤當成 FULL-PASS。
- 前一原稿：`20261029-225143-chatgpt-web-roy-T16-106-KR-scene-table-talk-dialog-UI-message-producer.md`（本地 585 行）；已完成至 T16-106。遠端既有正式原稿最高 T16-105；新原稿留本機，不冒稱已上傳。
- 證據方法：PE header section 可重算 raw/VA，32-bit little-endian pointers／RTTI、`objdump` i386 Intel 有界解碼與 native bytes SHA256。單純函式名（缺符號時）、玩家操作語意與『原版 Server』一律限定推論；不以 linear decode 穿過跳表為真正 CFG。
- PE 位置：`.text` RVA `0x1000` / raw `0x400`, VA `0x401000..0xBD1200`（有效程式 VA），因此 `.text raw=VA-0x400C00`；`.rdata` VA `0xBD2000` / raw `0x7D0600`；`.data` VA `0xD61000` / raw `0x95E800`。該映射依 KR 原件 section header，不能跨段通用一個 offset。

## 1. 主要結論與證據分級

### 1.1 新的有界原生結果

**新發現 A（網路類別實作身分）**：`0x8046ED` 經 `0x803D60` 建立物件；`0x8046F7` 將 vptr 設為 `0x00C51748`，`0x80470F` 把該物件指標寫到全域 `[0xFBA854]`。`0xC51748-4` 的 MSVC COL / TypeDescriptor 還原原件名稱 `.?AVCIocpNetwork@@`。vtable `+0x10`（slot 4）在原始 `.rdata` 指向 **`0x8069A0`**，而 `+0xC`（slot 3）是 **`0x8068B0`**。`0x8045EE` 和 `0x803F76` 在生命週期末端清零此全域欄位。此結論是**原生確認此 constructor 寫入的網路物件及其函式表**；不保證動態執行時永遠非 null/從不變更型別。

**新發現 B（對話 UI → 原生 queue）**：T16-106 的 `CTalkBoxDialog 0x636DE0 → 0x636E10` 在事件 `0xF4402`、virtual event type `0x105BD`、action `0x6A7`、`[dialog+0x88] != 0`、`[FBA798]==0` 下，建立 `WORD 0x0036 + WORD [selected_record+0]`，傳 `(channel_or_key=0, pointer, length=4)` 給 `[FBA854].vtable+0x10`。`0x8069A0` 使用 `0x8438C0` 依**signed integer key**在 `CIocpNetwork+0x18` 相關樹查找 node，從 `node+0x10` 取到有效 connection pointer；length=4 時 `call 0x8060D0`。`0x8060D0` 在 `connection+A0A4 <= 300`，且小 payload `len <= 0x1000` 下，透過 `0x807470` 配置 packet-like 物件，以 `0x89DBD0` 複製 **4 byte payload** 至 node+8，並寫 node+4=4；`0x806060` 在連線鎖保護下將 node 插入 `connection+A074` 的 pending list，增加 **`connection+A078`** 計數，設 **`connection+A024`=1**。**此處已證 enqueue，尚不表示任何網路傳輸成功。**

**新發現 C（flush 到 socket 邊界）**：`0x491FDD` 在 controller flag `[ebx+0x90]==0` 的分支呼叫 `0x804A40`；`0x804A40` 遍歷 connection，在 `connection+A0AC != 0` 時經 `0x8061A0` 排出等待節點。`0x8061A0` 以 `connection+A02C` 切換 encoding/framing：mode=0 走 `0x807A70`；mode!=0 先試 `0x807830`，只有該處回 0 才 fallback `0x807A70`。`0x807A70` 成功分支把 payload len=4 包成 **8-byte buffer：`04 00 68 1A 36 00 xx xx`**（little-endian 2-byte payload length, marker `0x1A68`, 4-byte payload）；`0x807830` 成功分支使用 **6-byte transformed header**（`len16=4`, marker `0x0BBB`, checksum16）與變換後 payload（此處不可假定變換 bytes 固定）。兩條路徑均是**有條件排送**。`0x804B3C..0x804B5A` 從 `connection+A028` / `connection+5020` 按 vtable+0xC 呼叫 `CIocpNetwork` `0x8068B0`，該函式以 `0xBD25B8` 對應的 socket send API（前段 T02/T16-71 的 WSASend 調用）發起非同步寫入。**成功返回／pending 不等於已送達 Server，未抓包。**

**新發現 D（`dialog+0x88` 寫入者）**：`0x636520` 以 `EDI=EDX` 接受 dialog-like object，`+0x90` mode case0 將 `+0x88` 保持 null；case1/2/3 在 `0x63666B/0x63669E/0x6366D1` 呼叫 `0x500F90`，把返回的 record 指標寫 `EDI+0x88`。`0x500F90` 從 active scene-like owner `ECX+0x5EAC` 取 keyed tree，交 `0x503D20` 查找；找到後 `node+0x10`，否則 null。`0x5B6BB2` / `0x5B6CE4` 等 5 個真實 call sites 在 `EDX=[controller+0x224]` 時呼叫 `0x636520`。因此選取紀錄不是單純未設來源的任意 UI 參數；**但 record 首 WORD 尚未證明是 Quest ID，更不能證明 `0x36` 就是接任務 opcode**。

### 1.2 不得跨越的界線

- 確認 `CIocpNetwork` 的 vtable、connection tree、pending node、frame/WSASend 的條件靜態鏈，**仍無實際 wire capture**，亦無 `0x36` 對應的 S→C response handler、Quest16→Quest15 業務對應、NPC refresh 完整閉環。
- `0x6A7` 是 UI virtual event 內檢查的 action/value；`0x105BD` 是 event runtime type 判定；這兩者**都不是已證 wire opcode**。
- `[dialog+0x88]` 依不同 mode 指向 `0x500F90` 回傳的 record；`0x500F90` 第 0 WORD 的正式 namespace 未由 QuestInfo 真實資源或 S→C 封包證明。
- `0x8069A0` 可因 channel/key 不存在、connection null、len=0 而不排入 pending；`0x8060D0` 有 `A0A4 > 300` 的拒絕分支。`0x807A70` 有容量、無資料及 buffer overlap 的失敗條件；mode!=0 的 `0x807830` 亦有額外驗證。不能說每次按鈕都產生網路封包。
- `[FBA798] != 0` 只證明**跳過這個直接 sender call**，不能證明沒有其他網路路徑；`0x6A8` 另走 UI 內部分支。
- 在 `0x804A40` 中的 `connection+A0A4` 是 drain 狀態計數相關欄位（`±5`/reset），**不是佇列長度**；佇列筆數在 `connection+A078`。此點遵守 T16-69 的勘誤。
- 同一個數值 `0x36` 出現在本地 payload 首 WORD，還不能不加版本／socket framing 條件就提升成整個封包的唯一 wire opcode，尤其不同 connection/encoder mode 可能形成不同 frame header。

## 2. 三輪深入記錄

### 第一輪 T16-107 — 原件 RTTI、vtable writer、連線查找（重大新發現）

1. 在 `.text` 搜尋 `0xFBA854` 的 little-endian dword literal，有 **374** 個候選 4-byte imm/address windows；依 opcode 上下文分類出 **371 次 `mov ecx, [0xFBA854]`** 與 **3 次明確寫入**（`0x803F76/0x8045EE` 的清零、`0x80470F` 的網路實例指標註冊）。只有在指令邊界確證者才算 writer；不同資料區碰撞不納入。
2. 於 `0x8046F1..0x804715`：allocation 0x5C bytes；`0x803D60` base 初始化；`mov [esi], 0xC51748`，原件 RTTI `.?AVCIocpNetwork@@`；`mov [FBA854],ecx` 然後調 `vtable+0x8`。此事實將 T16-106 的 dynamic call `+0x10` 綁定成此 constructor 實例的 `0x8069A0`。
3. `0x8069A0` 查 `[this+0x18]` 樹；`0x8438C0` signed compare `[node+0xC]` 對 key（本次傳入 0），`0x8069BF` 驗證非 sentinel、`node+0x10` 非空；length field `[ebp+0x10]`=4 才呼叫 `0x8060D0`。找不到走 return 0；length=0 走 return 1 且不送資料。**本地例外不能誤寫成 Server 拒絕**。
4. 由這些 bytes 可得到 4-byte 內容進入真實網路類別，但此輪未聲稱 WSASend 已發生；以第二輪檢查 queue/flush 與 failure。

### 第二輪 T16-107-2 — queue、frame 與 Socket 非同步發送（重大新發現）

1. `0x8060D0` 的 `connection+A0A4>0x12C` 拒絕返回 0；其餘會以 `0x807470` 分配節點。length=4 經 memcpy（`0x89DBD0`）放入 node+8、node+4 填4，`0x806060` 加入 pending。超過 `0x1000` 的 payload 走另一條不複製分支，不適用本次 4-byte payload。
2. `0x806060` 取得 connection 自己的同步鎖 `A0D4`，以 `0x74D700` 對 `A074` 列表插入；`A078` 加一，`A024` byte 設一，再解鎖。過去 A0A4 queue count 說法在本段予以否定。
3. `0x491FDD` 只在 `[controller+0x90]==0` 分支，才 call `0x804A40`；`0x804A40` 以 `[FBA858]` 的連線容器迭代，非所有時刻都無條件 flush。這建立與原先 queue 間的可能調度，不證明每一包立即 flush。
4. `0x8061A0` 以 `A02C` 決定封裝；mode 0 可走 `0x807A70`。`0x807A8F` marker `0x1A68` 放 `[ebp-2]`，`0x807A93` payload length `edx` 放 `[ebp-4]`；`0x807AE2` 讀 DWORD `[ebp-4]`，因此最終 4-byte header 序為 **`[payload_length16, 0x1A68]`**（不是倒置！）。當 len=4 時，確認固定 frame header `04 00 68 1A`，payload `36 00 xx xx` 從 `0x807AEE..0x807AF2` 拷貝。因沒有動態執行證據，這是 mode 0 + 寫入成功 的條件性封裝。
5. mode !=0 先進 `0x807830`：`0x807870/0x80787A` 生成含 payload length 及 marker `0x0BBB` 的 header，另 `0x8079F8` 寫 16-bit checksum，`0x807A0E` 追加 transformed payload，長度增加 `len+6`。其內容不可以簡化成 plaintext。只有這個 writer return0 時才 fallback `0x807A70`（`0x80622A..0x806234`）。
6. `0x804B3C..0x804B5A` 在 `A028>0`、`A0B8<=0` 等條件下，用 `connection+0x5020` 作 buffer ptr，`A028` 作 length，呼叫 `[FBA854].vtable+0xC`。vtable 指向 `0x8068B0`，其在非空參數/非停止連線下，會準備 `WSABUF` 與 `OVERLAPPED` 並 call native import `[0xBD25B8]`（既有 T16-71 已指出 WSASend），區分同步成功／WSA_IO_PENDING／錯誤。**這是原始 Client 中的 socket 發送呼叫邊界，不是已抓到 0x36 封包。**

### 第三輪 T16-107-3 — 選取紀錄來源、模式差異、反證與後續（重大新發現）

1. `0x636520` 由 `0x5B6BB2/0x5B6CE4/0x5B6E24/0x5B6F64/0x5B72D3` 五處相對 call 存在，root 解碼證實不是資料碰撞。`0x5B6BA4` 將 `[controller+0x224]` 放 EDX、設定 stack mode=0，再呼叫 `0x636520`，證明被寫入者指標實際由對話相關 controller 保存，不是憑欄位相似猜 alias。
2. `0x636520` `EDI=EDX`；清 `EDI+0x88`，再按 `[EDI+0x90]` 模式分支。case0 `0x63664A` 呼叫 `0x635CA0` 更新 record-derived flags；case1/2/3 分別 `0x63666B / 0x63669E / 0x6366D1` 呼叫 `0x500F90`，非空時保留 record 到 `+0x88`，並以 `record+0x30/0x34/0x38` 選擇下游 `0x635F10`。這是**不同欄位語意且分支互斥**的證據，非重複列單純 3 次 call。
3. `0x500F90` 對 scene-like object `+0x5EAC` 找 keyed tree，返回 node+0x10 payload 指標；`0x636E82` 取其首 WORD，故第二 WORD 本地來源是**被查得的 record 首欄**。對不同 quest / scenario / NPC namespace 的含義保持 unknown。
4. 對 `0x636E10` `0x6A7` 與 `0x6A8`、sender gate 非 0、selected=null、connection key 0 查找失敗及容量失敗做反證路徑分離；沒有讀到 Quest16/Quest15 真實資源就不給任務 ID 或接取回覆 opcode。
5. 三輪達到新的可回溯完整有界進展：**UI→record→network object→queue→conditional framing→WSASend static boundary**；本段停止，下一段應專注實際 S→C handler/Quest ID 業務關係，而非繼續重驗 T02 既有通用 socket 工具。

## 3. 靜態資料流／條件性 frame

```text
FUI::CTalkBoxDialog (vptr C2E3DC)
  slot87 636DE0 -- event F4402 and event-derived 105BD --> 636E10
      action=6A7, [dialog+88]!=null, [FBA798]==0
      build local [WORD 0036][WORD *(dialog+88)]  (len=4)
          vcall [FBA854] +0x10
          object constructed 8046F1→803D60, vptr C51748 (CIocpNetwork RTTI)
          8069A0(channel/key=0, data pointer, len=4)
              8438C0: find connection node in this+18 tree
              absent/null => return 0, len0 => return 1 without enqueue
              8060D0(conn, data,4)
                  if conn+A0A4>300: reject; else allocate 807470
                  packet_node+4=4; packet_node+8...+B = [36 00 xx xx]
                  806060: synchronized queue insertion, conn+A078++, A024=1
                      [NOT AN IMMEDIATE SOCKET SEND]
              [scheduled branch] 491FDD→804A40→8061A0
                  if conn+A02C == 0: 807A70
                      conditioned raw 04 00 68 1A 36 00 xx xx (8 bytes)
                  else: 807830; only on failure fallback 807A70
                      conditioned transformed [04 00 BB 0B checksum16] + opaque transformed payload
                  804B3C..5A→vtable+0xC→8068B0→WSASend-like import BD25B8
                      success/pending/error are DIFFERENT; no actual packet capture
```

### header 與失敗路徑矩陣

| 來源／條件 | Data/Length | 本機結果 | socket/Server 是否證實 | 級別 |
|---|---|---|---|---|
| UI action `0x6A7`, selected 非空，`FBA798=0`, network object/connection 有效，`A0A4<=300` | `[36 00 xx xx]`, 4 | 符合條件會透過 CIocpNetwork 插入 queue | 是否成功 flush / 實際發出依 mode, state; 不等於 Server 收到 | native enqueue path |
| network channel 0 查找失敗／connection null | 相同 UI local buffer | `0x8069A0` return 0 | 未 enqueue | native failure path |
| network submit len0 | 任意 pointer, len0 | `0x8069A0` return 1 | 未 enqueue；此例不是 UI len4 | native control branch |
| `A0A4 > 0x12C` | len4 | `0x8060D0` return 0，不走成功 queue 路徑 | 未證送出 | native gate |
| queue 待 flush、conn+A02C=0、frame buffer 容量足夠 | `36 00 xx xx` | `807A70` 可生成 `04 00 68 1A 36 00 xx xx` | 仍受實際 flush/WSASend 成功與否約束 | conditional plaintext frame |
| mode!=0、`807830` 成功 | same source payload | 6 bytes header `04 00 BB 0B chk chk` + 4 bytes transformed | 不得把原 payload 直接稱 encrypted wire bytes | native transformed frame boundary |
| mode!=0、`807830` return0 | same source payload | fallback 到 `807A70`，若自身成功才有 plaintext buffer | no guaranteed socket | native fallback |
| selected=null、event 6A8、`FBA798!=0` | 無本分支有效 4-byte send | UI 不呼叫此 +0x10 method；可能走 +0xD4 內部流程 | 不能推成其他所有 sender 都不存在 | native bounded negative |
| Quest16 完成→Quest15 解鎖→玩家接取 | **unknown** | 尚未與此 network payload 形成任務語意證據 | **S→C callback/reply/acceptance unknown** | Client 待逆向 |

## 4. 核對為何 `0x6A7` / record 首欄≠Quest ID

`0x636E42..0x636E4A` 對 UI event object 的 `[eax+0x14]` 比對常數 `0x6A7`，`0x636EB9` 另比 `0x6A8`，說明此常數參與 UI action dispatch；是否映射任務操作需 KR 對話資源、事件描述及原生收發回覆交叉驗證。`0x500F90` 只證明從 `owner+0x5EAC` 的 keyed tree 查回一個 record payload，沒有確認 record 首 WORD 的 namespace。不能把 UI 控件/action、scene index、QuestInfo questNum、Server wire opcode 混在一個數字域。尤其 `0x36` 是**payload** 第一 WORD，而非 frame marker：在條件 plaintext frame，真正 frame marker 是 `0x1A68`；在 transformed 模式是 `0x0BBB`。

## 5. Client/Server/跨功能/遊玩四類未解事項

**Client 待逆向 P0**：找到 `0x36` 對應的 S→C 真實命令、長度/欄位/dispatcher/結果、是否回覆同一連線；證實 `0x6A7` 對應哪個玩家操作及 scene/quest 操作、`[dialog+88]` record 首 WORD 是什麼 ID；定位 Quest16/Quest15 的 native XML/Lua／NPC 清單和 UI 狀態 writer；scene callback 66 的網路分派指標來源；網路模式 `A02C` 的 runtime 選擇/首封包時序由 T02 定向補證。

**Server 待開發**：待 Client 接收契約證實後，實作相容 Quest accept/finish/turn-in/progression 的狀態檢查與回覆及玩家資料保存；原版 Server 內部前置判斷、DB 規則**不可由本地靜態分析猜稱原版**。目前不應把 `0x36` 或 `0x6A7` 寫成正式 Server contract。

**跨 Task 待整合**：T02 network mode/packet headers、T06 TalkBox widget/resource IDs、T07 NPC/scene、T14 mission result、T15 snapshot/persistence；本段只引用其 boundary，不修改 owner/catalog 或別人的原稿。

**待遊玩驗證**：遊戲真實對話輸入、連線 mode、送出/Server 收到/收到結果/S2C 更新、Quest16→Quest15、失敗/拒絕/重登各階段需本地依法取得資料並核對；本段無執行時觀測。

## 6. 可交 T02 / T06 / S00 的精確阻塞

- T02：用原生合法流量/離線可重播 trace 複證 `[FBA854]+0x10` 的 key=0 下實際 connection、`A02C` runtime mode 與 frame 0x1A68 / 0x0BBB 的選擇，提供 send/receive 同一連線 ID 及 S2C 命令域對照；已知 queue/WSASend 靜態入口不需重做。
- T06／T07：查實際 `0x6A7` 控件所代表的 TalkBox 行為及 `[dialog+88]` record 首 WORD 定義；檢查 QuestInfo 15/16 對話資料如何注入 `0x5EAC` key tree，並以已存原始資源 SHA 對照。
- T16 下一段：從 `0x4930E0` 的已證 receive domain 定向追 S2C Quest state/result handler + UI consumer；查 `0x36` local payload 是否於任何 handler 存在對應 response，**不要把相同數字的 callback index 或命令編號直接映射**。
- 此處只是工作建議；S00 `research/requests/index.json` 未有 T16 RR，不自動建立、認領、提交。

## 7. 原始 BIN 位元組及 rooted 有界反組譯片段（重現材料）

下列每個區間列原始 VA、raw offset、SHA256，並由同一個 KR BIN bytes 經 i386 指令解碼。**如果擷取終點截斷完整指令，最後 objdump `.byte`/不完整 decode 一概不作結論；區間非宣稱完整 CFG，所有重要分支必回到已證根入口。** 報告作者未執行原 Client。

### network constructor registering CIocpNetwork global — VA 0X8046CC..0X804737 (end-exclusive)

- raw `0x00403ACC..0x00403B37`, bytes `107`, SHA256 `bfa61c0256ebca1bfa2eb9bfd878473783b45afdc72d4c93840988e65afaaf14`.

```asm
  8046cc:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  8046d1:	50                   	push   eax
  8046d2:	e8 49 10 00 00       	call   0x805720
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
  804724:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
  804727:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80472a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804731:	59                   	pop    ecx
  804732:	5e                   	pop    esi
  804733:	8b e5                	mov    esp,ebp
  804735:	5d                   	pop    ebp
  804736:	c3                   	ret
```

### network vptr slot 4: keyed lookup, connection gate, queue call — VA 0X8069A0..0X8069F4 (end-exclusive)

- raw `0x00405DA0..0x00405DF4`, bytes `84`, SHA256 `2eabc71734af1539f5a206bc30304d23178412fba8a43f67966705a004675c8a`.

```asm
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2                   	.byte 0xc2
```

### signed-key map lower-bound lookup — VA 0X8438C0..0X843925 (end-exclusive)

- raw `0x00442CC0..0x00442D25`, bytes `101`, SHA256 `171ae66fbd8bbc564d6525ded5b43ef6853b18308df0e8b9933e2afc3d9126d3`.

```asm
  8438c0:	55                   	push   ebp
  8438c1:	8b ec                	mov    ebp,esp
  8438c3:	51                   	push   ecx
  8438c4:	53                   	push   ebx
  8438c5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  8438c8:	56                   	push   esi
  8438c9:	8b f1                	mov    esi,ecx
  8438cb:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  8438ce:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  8438d1:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438d5:	75 1e                	jne    0x8438f5
  8438d7:	57                   	push   edi
  8438d8:	8b 3b                	mov    edi,DWORD PTR [ebx]
  8438da:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  8438e0:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  8438e3:	7d 05                	jge    0x8438ea
  8438e5:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  8438e8:	eb 04                	jmp    0x8438ee
  8438ea:	8b d1                	mov    edx,ecx
  8438ec:	8b 09                	mov    ecx,DWORD PTR [ecx]
  8438ee:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438f2:	74 ec                	je     0x8438e0
  8438f4:	5f                   	pop    edi
  8438f5:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  8438f8:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  8438fb:	3b d1                	cmp    edx,ecx
  8438fd:	74 16                	je     0x843915
  8438ff:	8b 33                	mov    esi,DWORD PTR [ebx]
  843901:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  843904:	7c 0f                	jl     0x843915
  843906:	8d 4d 08             	lea    ecx,[ebp+0x8]
  843909:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84390b:	5e                   	pop    esi
  84390c:	89 08                	mov    DWORD PTR [eax],ecx
  84390e:	5b                   	pop    ebx
  84390f:	8b e5                	mov    esp,ebp
  843911:	5d                   	pop    ebp
  843912:	c2 04 00             	ret    0x4
  843915:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  843918:	8d 4d fc             	lea    ecx,[ebp-0x4]
  84391b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84391d:	5e                   	pop    esi
  84391e:	89 08                	mov    DWORD PTR [eax],ecx
  843920:	5b                   	pop    ebx
  843921:	8b e5                	mov    esp,ebp
  843923:	5d                   	pop    ebp
  843924:	c2                   	.byte 0xc2
```

### connection A0A4 gate, copy 4 bytes into pending node — VA 0X8060D0..0X806190 (end-exclusive)

- raw `0x004054D0..0x00405590`, bytes `192`, SHA256 `5fd088cc6ffcac879999c30db513f2459995a81e125abd99054c35b7765941bc`.

```asm
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
  80618e:	c2                   	.byte 0xc2
  80618f:	08                   	.byte 0x8
```

### connection synchronized queue insertion/count+flag — VA 0X806060..0X8060CC (end-exclusive)

- raw `0x00405460..0x004054CC`, bytes `108`, SHA256 `00daec472f276163c3b79ec9d9d3d79d707775b6749aa7f9099d116048e7aca0`.

```asm
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806071:	8b be 74 a0 00 00    	mov    edi,DWORD PTR [esi+0xa074]
  806077:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  80607a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  80607d:	51                   	push   ecx
  80607e:	52                   	push   edx
  80607f:	57                   	push   edi
  806080:	e8 7b 76 f4 ff       	call   0x74d700
  806085:	8b 8e 78 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa078]
  80608b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  806090:	2b d1                	sub    edx,ecx
  806092:	83 fa 01             	cmp    edx,0x1
  806095:	73 0a                	jae    0x8060a1
  806097:	68 34 20 bf 00       	push   0xbf2034
  80609c:	e8 8f 7a 07 00       	call   0x87db30
  8060a1:	41                   	inc    ecx
  8060a2:	89 8e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ecx
  8060a8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  8060ab:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8060ae:	89 01                	mov    DWORD PTR [ecx],eax
  8060b0:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8060b6:	52                   	push   edx
  8060b7:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8060bd:	c6 86 24 a0 00 00 01 	mov    BYTE PTR [esi+0xa024],0x1
  8060c4:	b8 01 00 00 00       	mov    eax,0x1
  8060c9:	5f                   	pop    edi
  8060ca:	5d                   	pop    ebp
  8060cb:	c2                   	.byte 0xc2
```

### frame drain mode A02C and fallback roots — VA 0X8061E6..0X80624F (end-exclusive)

- raw `0x004055E6..0x0040564F`, bytes `105`, SHA256 `35e2eaf34e1362bcc09488d142ae458c04457dd19d4a326ff7c63b74c623f135`.

```asm
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
```

### buffer plaintext frame writer header, length+marker — VA 0X807A70..0X807B18 (end-exclusive)

- raw `0x00406E70..0x00406F18`, bytes `168`, SHA256 `38410986e45957da9d8ca3c4d598e973ceb2a5b0c57cc8f4c4132fc2f02eb90f`.

```asm
  807a70:	55                   	push   ebp
  807a71:	8b ec                	mov    ebp,esp
  807a73:	83 ec 08             	sub    esp,0x8
  807a76:	53                   	push   ebx
  807a77:	56                   	push   esi
  807a78:	8b 37                	mov    esi,DWORD PTR [edi]
  807a7a:	56                   	push   esi
  807a7b:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  807a7e:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2                   	.byte 0xc2
  807b17:	08                   	.byte 0x8
```

### transformed frame header generation & capacity gate — VA 0X807861..0X8078EF (end-exclusive)

- raw `0x00406C61..0x00406CEF`, bytes `142`, SHA256 `f839ed7d27cefe26266c9ea037e71594f2e82fa0ef8b9f6e7a7f03310f95b8a6`.

```asm
  807861:	89 85 f0 ef ff ff    	mov    DWORD PTR [ebp-0x1010],eax
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
```

### transformed frame header write, checksum and payload copy — VA 0X8079D7..0X807A4C (end-exclusive)

- raw `0x00406DD7..0x00406E4C`, bytes `117`, SHA256 `72800de90f75266699642042522132770c4c7b953fb5349c72b86965f4a4b6bb`.

```asm
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01 86 0c 50 00 00    	add    DWORD PTR [esi+0x500c],eax
  807a25:	01 86 04 50 00 00    	add    DWORD PTR [esi+0x5004],eax
  807a2b:	83 c4 0c             	add    esp,0xc
  807a2e:	52                   	push   edx
  807a2f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a35:	5f                   	pop    edi
  807a36:	5e                   	pop    esi
  807a37:	b8 01 00 00 00       	mov    eax,0x1
  807a3c:	5b                   	pop    ebx
  807a3d:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a40:	33 cd                	xor    ecx,ebp
  807a42:	e8 ba 95 08 00       	call   0x891001
  807a47:	8b e5                	mov    esp,ebp
  807a49:	5d                   	pop    ebp
  807a4a:	c2                   	.byte 0xc2
  807a4b:	08                   	.byte 0x8
```

### connection loop and send vtable +0xC — VA 0X804A40..0X804B5C (end-exclusive)

- raw `0x00403E40..0x00403F5C`, bytes `284`, SHA256 `0e3645f8c167777b33dae69da00d9badf16449aad6738d2f2352a2c022ab7bab`.

```asm
  804a40:	55                   	push   ebp
  804a41:	8b ec                	mov    ebp,esp
  804a43:	83 ec 18             	sub    esp,0x18
  804a46:	53                   	push   ebx
  804a47:	8b 1d a0 25 bd 00    	mov    ebx,DWORD PTR ds:0xbd25a0
  804a4d:	56                   	push   esi
  804a4e:	57                   	push   edi
  804a4f:	ff d3                	call   ebx
  804a51:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  804a58:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  804a5b:	89 47 48             	mov    DWORD PTR [edi+0x48],eax
  804a5e:	75 15                	jne    0x804a75
  804a60:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  804a67:	74 07                	je     0x804a70
  804a69:	e8 f2 64 c9 ff       	call   0x49af60
  804a6e:	eb 05                	jmp    0x804a75
  804a70:	e8 8b 65 c9 ff       	call   0x49b000
  804a75:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  804a7b:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  804a7e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804a85:	ff d3                	call   ebx
  804a87:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  804a8d:	2b c8                	sub    ecx,eax
  804a8f:	bb 01 00 00 00       	mov    ebx,0x1
  804a94:	83 f9 21             	cmp    ecx,0x21
  804a97:	76 09                	jbe    0x804aa2
  804a99:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  804a9f:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  804aa2:	8b 7e 04             	mov    edi,DWORD PTR [esi+0x4]
  804aa5:	2b 3e                	sub    edi,DWORD PTR [esi]
  804aa7:	33 c0                	xor    eax,eax
  804aa9:	c1 ff 02             	sar    edi,0x2
  804aac:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  804aaf:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  804ab2:	85 ff                	test   edi,edi
  804ab4:	0f 84 a1 01 00 00    	je     0x804c5b
  804aba:	eb 07                	jmp    0x804ac3
  804abc:	8d 64 24 00          	lea    esp,[esp+0x0]
  804ac0:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  804b1a:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  804b21:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  804b28:	0f 84 1d 01 00 00    	je     0x804c4b
  804b2e:	8b 86 b8 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0b8]
  804b34:	85 c0                	test   eax,eax
  804b36:	0f 8f 0f 01 00 00    	jg     0x804c4b
  804b3c:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  804b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b48:	8b 11                	mov    edx,DWORD PTR [ecx]
  804b4a:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  804b4d:	8d 7d ec             	lea    edi,[ebp-0x14]
  804b50:	57                   	push   edi
  804b51:	50                   	push   eax
  804b52:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  804b58:	50                   	push   eax
  804b59:	56                   	push   esi
  804b5a:	ff d2                	call   edx
```

### WSASend dispatch with WSABUF/overlapped & outcome — VA 0X8068B0..0X80699B (end-exclusive)

- raw `0x00405CB0..0x00405D9B`, bytes `235`, SHA256 `abae75dd0e81616099da807611b697f5aade87d4e1bd9319210245a07fe84582`.

```asm
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2                   	.byte 0xc2
```

### call site conditional flush in controller — VA 0X491FC7..0X491FF1 (end-exclusive)

- raw `0x000913C7..0x000913F1`, bytes `42`, SHA256 `793d2e456807cb5bf154741e34569ceaf4e94005253d65d3dbee42fde954879b`.

```asm
  491fc7:	e8 64 33 f9 ff       	call   0x425330
  491fcc:	8b f0                	mov    esi,eax
  491fce:	e8 ad 4b 06 00       	call   0x4f6b80
  491fd3:	80 bb 90 00 00 00 00 	cmp    BYTE PTR [ebx+0x90],0x0
  491fda:	75 08                	jne    0x491fe4
  491fdc:	53                   	push   ebx
  491fdd:	e8 5e 2a 37 00       	call   0x804a40
  491fe2:	eb 07                	jmp    0x491feb
  491fe4:	8b f3                	mov    esi,ebx
  491fe6:	e8 85 2c 37 00       	call   0x804c70
  491feb:	53                   	push   ebx
  491fec:	e8 cf 2f 37 00       	call   0x804fc0
```

### CTalkBoxDialog input event gate — VA 0X636DE0..0X636E0C (end-exclusive)

- raw `0x002361E0..0x0023620C`, bytes `44`, SHA256 `03e1c88531b048287a744098a903893e36141054427acb318eb25c45e6acc61c`.

```asm
  636de0:	55                   	push   ebp
  636de1:	8b ec                	mov    ebp,esp
  636de3:	56                   	push   esi
  636de4:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  636de7:	57                   	push   edi
  636de8:	8b f9                	mov    edi,ecx
  636dea:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636df0:	8b 01                	mov    eax,DWORD PTR [ecx]
  636df2:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  636df5:	56                   	push   esi
  636df6:	ff d2                	call   edx
  636df8:	81 7e 10 02 44 0f 00 	cmp    DWORD PTR [esi+0x10],0xf4402
  636dff:	75 05                	jne    0x636e06
  636e01:	e8 0a 00 00 00       	call   0x636e10
  636e06:	5f                   	pop    edi
  636e07:	5e                   	pop    esi
  636e08:	5d                   	pop    ebp
  636e09:	c2 04 00             	ret    0x4
```

### CTalkBoxDialog 4-byte producer and bypass — VA 0X636E10..0X636ECC (end-exclusive)

- raw `0x00236210..0x002362CC`, bytes `188`, SHA256 `0cc4d7212173ddd7c989e126e2d4340c145f34b2166490de4fcd4c02f5bf16ec`.

```asm
  636e10:	55                   	push   ebp
  636e11:	8b ec                	mov    ebp,esp
  636e13:	51                   	push   ecx
  636e14:	85 f6                	test   esi,esi
  636e16:	74 28                	je     0x636e40
  636e18:	8b 06                	mov    eax,DWORD PTR [esi]
  636e1a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  636e1d:	8b ce                	mov    ecx,esi
  636e1f:	ff d2                	call   edx
  636e21:	3d bd 05 01 00       	cmp    eax,0x105bd
  636e26:	75 04                	jne    0x636e2c
  636e28:	8b c6                	mov    eax,esi
  636e2a:	eb 16                	jmp    0x636e42
  636e2c:	6a 00                	push   0x0
  636e2e:	68 c0 1f bf 00       	push   0xbf1fc0
  636e33:	68 18 21 bf 00       	push   0xbf2118
  636e38:	6a 00                	push   0x0
  636e3a:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  636e40:	33 c0                	xor    eax,eax
  636e42:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636e45:	3d a7 06 00 00       	cmp    eax,0x6a7
  636e4a:	75 6d                	jne    0x636eb9
  636e4c:	83 bf 88 00 00 00 00 	cmp    DWORD PTR [edi+0x88],0x0
  636e53:	74 77                	je     0x636ecc
  636e55:	b8 01 00 00 00       	mov    eax,0x1
  636e5a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  636e60:	75 13                	jne    0x636e75
  636e62:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  636e68:	68 10 cf bc 00       	push   0xbccf10
  636e6d:	e8 a8 b4 25 00       	call   0x89231a
  636e72:	83 c4 04             	add    esp,0x4
  636e75:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  636e7c:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  636e82:	66 8b 11             	mov    dx,WORD PTR [ecx]
  636e85:	b8 36 00 00 00       	mov    eax,0x36
  636e8a:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  636e8e:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  636e92:	75 2c                	jne    0x636ec0
  636e94:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  636e9a:	8b 01                	mov    eax,DWORD PTR [ecx]
  636e9c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  636e9f:	6a 04                	push   0x4
  636ea1:	8d 55 fc             	lea    edx,[ebp-0x4]
  636ea4:	52                   	push   edx
  636ea5:	6a 00                	push   0x0
  636ea7:	ff d0                	call   eax
  636ea9:	8b 17                	mov    edx,DWORD PTR [edi]
  636eab:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636eb1:	8b cf                	mov    ecx,edi
  636eb3:	ff d0                	call   eax
  636eb5:	8b e5                	mov    esp,ebp
  636eb7:	5d                   	pop    ebp
  636eb8:	c3                   	ret
  636eb9:	3d a8 06 00 00       	cmp    eax,0x6a8
  636ebe:	75 0c                	jne    0x636ecc
  636ec0:	8b 17                	mov    edx,DWORD PTR [edi]
  636ec2:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636ec8:	8b cf                	mov    ecx,edi
  636eca:	ff d0                	call   eax
```

### TalkBox mode setter and selected record init — VA 0X636520..0X6365B0 (end-exclusive)

- raw `0x00235920..0x002359B0`, bytes `144`, SHA256 `2d7cae95d74559fee174b16f7b4cd7b24cc5637b233721f1e954a9af1f2035d9`.

```asm
  636520:	55                   	push   ebp
  636521:	8b ec                	mov    ebp,esp
  636523:	83 e4 f8             	and    esp,0xfffffff8
  636526:	6a ff                	push   0xffffffff
  636528:	68 32 92 94 00       	push   0x949232
  63652d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636533:	50                   	push   eax
  636534:	83 ec 28             	sub    esp,0x28
  636537:	53                   	push   ebx
  636538:	56                   	push   esi
  636539:	57                   	push   edi
  63653a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  63653f:	33 c4                	xor    eax,esp
  636541:	50                   	push   eax
  636542:	8d 44 24 38          	lea    eax,[esp+0x38]
  636546:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  63654c:	8b f1                	mov    esi,ecx
  63654e:	8b fa                	mov    edi,edx
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
  6365ab:	e8 30 24 00 00       	call   0x6389e0
```

### TalkBox case 0 record-filter flag writer — VA 0X636620..0X636654 (end-exclusive)

- raw `0x00235A20..0x00235A54`, bytes `52`, SHA256 `7b0479355b75e0ec9617509052bbbf76be061737184c5bf0ea4426e583696c9c`.

```asm
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
```

### TalkBox modes 1,2,3 selected writer & downstream property — VA 0X636654..0X6366ED (end-exclusive)

- raw `0x00235A54..0x00235AED`, bytes `153`, SHA256 `8ae20166fc7c3fabb9cc6d8428cb527ea85b6eda173f82f6323502569fbc2108`.

```asm
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb 3f                	jmp    0x6366f9
  6366ba:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  6366c2:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6366c5:	ff d0                	call   eax
  6366c7:	e8 64 92 dd ff       	call   0x40f930
  6366cc:	8b c8                	mov    ecx,eax
  6366ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  6366d1:	e8 ba a8 ec ff       	call   0x500f90
  6366d6:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366dc:	3b c3                	cmp    eax,ebx
  6366de:	74 0d                	je     0x6366ed
  6366e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  6366e3:	51                   	push   ecx
  6366e4:	8b c7                	mov    eax,edi
  6366e6:	e8 25 f8 ff ff       	call   0x635f10
  6366eb:	eb 0c                	jmp    0x6366f9
```

### record pointer lookup through owner+5EAC — VA 0X500F90..0X500FC4 (end-exclusive)

- raw `0x00100390..0x001003C4`, bytes `52`, SHA256 `3bb8758a306096de8b08d5d71a42d00b11f193ecaa37d2d84d04581d9b040fb3`.

```asm
  500f90:	55                   	push   ebp
  500f91:	8b ec                	mov    ebp,esp
  500f93:	83 ec 08             	sub    esp,0x8
  500f96:	56                   	push   esi
  500f97:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  500f9d:	8d 55 fc             	lea    edx,[ebp-0x4]
  500fa0:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500fa3:	52                   	push   edx
  500fa4:	8d 45 f8             	lea    eax,[ebp-0x8]
  500fa7:	8b ce                	mov    ecx,esi
  500fa9:	e8 72 2d 00 00       	call   0x503d20
  500fae:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500fb1:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500fb4:	5e                   	pop    esi
  500fb5:	74 07                	je     0x500fbe
  500fb7:	83 c0 10             	add    eax,0x10
  500fba:	8b e5                	mov    esp,ebp
  500fbc:	5d                   	pop    ebp
  500fbd:	c3                   	ret
  500fbe:	33 c0                	xor    eax,eax
  500fc0:	8b e5                	mov    esp,ebp
  500fc2:	5d                   	pop    ebp
  500fc3:	c3                   	ret
```

### controller mode0 caller passes +224 dialog pointer — VA 0X5B6B70..0X5B6BD2 (end-exclusive)

- raw `0x001B5F70..0x001B5FD2`, bytes `98`, SHA256 `4557a28b516bbe1fddb579dceb18988bed0e59d2f47b4f667919b235529d4185`.

```asm
  5b6b70:	57                   	push   edi
  5b6b71:	8b f8                	mov    edi,eax
  5b6b73:	85 f6                	test   esi,esi
  5b6b75:	74 28                	je     0x5b6b9f
  5b6b77:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6b79:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6b7c:	8b ce                	mov    ecx,esi
  5b6b7e:	ff d2                	call   edx
  5b6b80:	3d be 05 01 00       	cmp    eax,0x105be
  5b6b85:	75 04                	jne    0x5b6b8b
  5b6b87:	8b c6                	mov    eax,esi
  5b6b89:	eb 16                	jmp    0x5b6ba1
  5b6b8b:	6a 00                	push   0x0
  5b6b8d:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6b92:	68 18 21 bf 00       	push   0xbf2118
  5b6b97:	6a 00                	push   0x0
  5b6b99:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6b9f:	33 c0                	xor    eax,eax
  5b6ba1:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b6ba4:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6baa:	6a 00                	push   0x0
  5b6bac:	6a 00                	push   0x0
  5b6bae:	51                   	push   ecx
  5b6baf:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  5b6bb2:	e8 69 f9 07 00       	call   0x636520
  5b6bb7:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6bbd:	52                   	push   edx
  5b6bbe:	e8 4d 34 19 00       	call   0x74a010
  5b6bc3:	8b 87 24 02 00 00    	mov    eax,DWORD PTR [edi+0x224]
  5b6bc9:	50                   	push   eax
  5b6bca:	57                   	push   edi
  5b6bcb:	e8 30 02 fe ff       	call   0x596e00
  5b6bd0:	5f                   	pop    edi
  5b6bd1:	c3                   	ret
```

### controller mode1 caller passes +224 dialog pointer — VA 0X5B6CCF..0X5B6D15 (end-exclusive)

- raw `0x001B60CF..0x001B6115`, bytes `70`, SHA256 `d6503471ea84557194e1048a89902be6db70bfabd0da7da5cc544185d103b503`.

```asm
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
```

### network manager shutdown clears global pointer — VA 0X8045DC..0X8045F4 (end-exclusive)

- raw `0x004039DC..0x004039F4`, bytes `24`, SHA256 `de30544e3a2d3d63a1a940adc73324b91653ac51dc6c21e36d31e6fe17641b08`.

```asm
  8045dc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8045e2:	3b cb                	cmp    ecx,ebx
  8045e4:	74 0e                	je     0x8045f4
  8045e6:	8b 11                	mov    edx,DWORD PTR [ecx]
  8045e8:	8b 02                	mov    eax,DWORD PTR [edx]
  8045ea:	6a 01                	push   0x1
  8045ec:	ff d0                	call   eax
  8045ee:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
```

### network base destructor clears global pointer — VA 0X803F59..0X803F7C (end-exclusive)

- raw `0x00403359..0x0040337C`, bytes `35`, SHA256 `03ec72cf78b0d0339e0b5087e6356245f2c2a362065a0c1d515a6715e4c36798`.

```asm
  803f59:	8b 57 50             	mov    edx,DWORD PTR [edi+0x50]
  803f5c:	6a ff                	push   0xffffffff
  803f5e:	52                   	push   edx
  803f5f:	c7 47 4c 01 00 00 00 	mov    DWORD PTR [edi+0x4c],0x1
  803f66:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  803f6c:	8b 47 50             	mov    eax,DWORD PTR [edi+0x50]
  803f6f:	50                   	push   eax
  803f70:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  803f76:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
```

## 8. 可重放的小型唯讀驗證操作

```python
from pathlib import Path
import hashlib,struct
p=Path('Tartaros.bin').read_bytes()
assert len(p)==12472320
assert hashlib.sha256(p).hexdigest()=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def raw_text(va): return va-0x400C00
def raw_va(va):
    for start,end,offset in [(0xBD2000,0xD60200,0x7D0600),
                             (0xD61000,0xFE7400,0x95E800)]:
        if start <= va < end: return va-start+offset
    if 0x401000 <= va < 0xBD1200: return va-0x400C00
    raise ValueError(hex(va))
def d32r(va): return struct.unpack_from('<I',p,raw_va(va))[0]
assert d32r(0xC51748+0x10)==0x8069A0
assert d32r(0xC51748+0x0C)==0x8068B0
assert d32r(0xC51748+0x04)==0x806CF0
# MSVC RTTI: vtable[-1] -> COL, COL+0xC -> TypeDescriptor
col=d32r(0xC51748-4)
ty=d32r(col+0xC)
assert p[raw_va(ty+8):raw_va(ty+8)+22].split(b'\0')[0]==b'.?AVCIocpNetwork@@'
```

本報告原生地址、frame、選取紀錄與分支細節均基於此版本。跨 KR/TC／其他變體不自動成立。研究已滿足三輪實質有界進展；未獲使用者提交授權，不建立 Commit／Push，不修改 T01 或 S00 狀態。
