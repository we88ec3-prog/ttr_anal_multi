# E68 — RR-0008：選角 0x42 入站消費者、ScenarioReview +0x248 writer、雙鍵 SceneList 與 EndCutScene 反例

> 2026-10-30（Asia/Taipei）｜研究者 chatgpt-web roy｜唯一研究分支 `extra/roy1`。
> **有界 Client 靜態研究交付，不是原版 Server 封包擷取、T01 FULL-PASS、S00 ACCEPTED、遊玩驗收或官方首登規則。**
> KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；KR `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`，11,241,597 bytes。本輪三件原檔均重新計算 SHA。未執行／修改 Client。

## 1. RR-0008 的完整問題與逐項答覆

RR-0008 指定：以 E06/E08/E13/E14/E15/E16 及 T03/T07 為基礎，確認實際 `S→C 0x42` 接收者、有無寫 `0x47B5C0` 的 object+0x248 或選定 `0x565720` `(questIdx, sceneIdx)`、EndCutScene 重入、首次 tutorial 條件；對 GAP-FLOW-0001 提供方向明確的 Client 消息/狀態偏序，保留失敗與 UNKNOWN。

| 子題 | 本次有界結果 | 來源 |
|---|---|---|
| S2C app 0x42 | base scene table `0x4ADD50` 在 `0x4ADF3D` 寫入 slot `+0x214 = 0x4B2190`；T02 lane2+active scene 才可能落到該處 | 原始 10 bytes `c7 80 14 02 00 00 90 21 4b 00` |
| 接收資料與狀態 | `0x4B21FD` 讀 `signed WORD payload+2`；`0x500110` 對 `0xFAB2A0+0x5ED0` 最多 20 個 WORD 搜尋/插入；某些子項走 `0x53D840` 24-byte record | 原始 `0x4B2190..0x4B22DA` 與 callee |
| 是否將結果寫入 ScenarioReviewSceneItem+0x248 | 已追到的 **正向 writer 不是 S2C42**：Ctor `0x47B4C9` 設 -1；`0x47B2EF` 將來源 `[EDI]` 寫 `EBX+0x248`，隨後 UI/scene reader 走另一條 caller | 原始 RTTI+writer+direct call chain；不否定未知間接 alias |
| 是否選擇 `0x565720` 場景雙鍵 | 本輪找到的直接 E8 兩處：`0x47B64A`（ScenarioReview item）及 `0x561EF3`（EndCutScene），沒有 `0x4B2190` 直接呼叫它 | `.text` E8-rel32 全區候選掃描＋各指令邊界 |
| 1001/1 首教學 | E06 SceneList 的 `(1001,1)→tutorial_start` 是資源查表；本輪重驗 Event.stp 中 Lua source 522-byte SHA，未找到該數值是選角 response wire 欄位 | STP/XOR source、E06/E08 |
| 原版 Server 選角批准/拒絕 | 仍無正向的 C2S42→原版 S2C status/opcode/slot 順序證據，不能以 0x42 相同號或 0x69 subtype7 猜測 | RR-0002 繼續 BLOCKED；非本 RR 偽造解答 |

## 2. 原始 PE、RTTI、caller 的獨立驗證

`.text` VMA `0x401000` raw `0x400`、VA→raw `VA−0x400C00`；`.rdata` VMA `0xBD2000` raw `0x7D0600`；`.data` VMA `0xD61000` raw `0x95E800`。不可用 `.text` 差額轉換 RTTI。

| vptr | vptr[-1] COL | TypeDescriptor | 由原件讀得名稱 |
|---|---|---|---|
| `0xC02F3C` | `0xC68ACC` | `0xF7D864` | `.?AVCScenarioReviewSceneItem@FUI@@` |
| `0xC02D9C` | `0xC68B30` | `0xF7D890` | `.?AVCScenarioReviewChapterItem@FUI@@` |

完整 `.text` 逐 byte 尋找 `E8 rel32` 並驗算 destination 的候選結果如下；本輪已針對列出的 caller 做局部反組譯、確認是指令邊界。此掃描 **不包括虛擬函式、指標回呼、重疊機器碼與其他間接轉入**：

| Target | 直接 E8 指令位址 |
|---|---|
| `0x47B2B0` (Review item record→ID writer) | `0x47D36D` |
| `0x47B5C0` (Review item→scene reader) | `0x47D5B7` |
| `0x47D530` (Review UI state relay) | `0x47D9DA` |
| `0x565720` (雙鍵 scene loader) | `0x47B64A`、`0x561EF3` |
| `0x4B2190` (S2C42 base handler) | 0（以 table pointer `0x4ADF3D` 分派，**不能解釋成不可達**） |

## 3. S2C 0x42 的完整局部資料流與反例

1. 解析後 payload 從 T02 lane2 到 Client delegate。第一層未命中覆寫時，需有效 active scene 才能進場景次表；LOGIN scene 次表沒有直接覆寫 `0x42`，但基底表 `0x4ADF3D` 有 `0x42→0x4B2190`。不能從 LOGIN 沒直接覆寫推定沒有 handler。
2. `0x4B21FD`：`0f bf 76 02` = `movsx esi,word [esi+2]`。`0x4B2201` 將 EDI 設 `0xFAB2A0`，`0x4B2206 call 0x500110`，後者對 20 個 WORD 檢索既有/空槽，非角色授權或地圖進入 flag。
3. `0x4B2210` 比較資料長度與常數 4；當 `len>4`，`0x4B221C` 使用 `[payload+5]` 做 subtype（從 `payload+4` 再加 1）。所以 `len=5` **會越過所宣告 payload 邏輯長度讀一個 byte**。此為靜態風險，沒有 runtime crash 證據；有效子項最短應有 6 bytes，還須符合各分支額外欄位。
4. 子項有 11 種 switch 分支和 cursor 調整；`0x4B2266` 可能記錄 cursor 超長診斷但未必阻斷；部分路徑在 `0x4B22BC` 進 `0x53D840`，更新另外一組 stride 0x18 的記錄。
5. ScenarioReview UI 讀取：`0x47D610` 裡 `0x47D693 push 0xFAB2A0`→`0x503440`，是**同一 S2C42 集合的 UI consumer**。但 `0xFAB2A0` ≠ Review SceneItem+0x248，不能將前者的 record mutation 偷換成後者的 key writer。
6. 對 `0x4B2190..0x4B22DA` 的直接控制流，本輪未找到 `0x47B2B0/0x47B5C0/0x565720` 或 `0x4B7D50` 直接 call，也沒有被確認的同一 object+0x248 直接寫入。此結果是**特定 handler 的有界陰性**，不宣稱全 Client 間接路徑皆不存在。

## 4. 誰實際寫入 object+0x248？

- `0x47B143` 把 `+0x248=-1` 寫到 **CScenarioReviewChapterItem**；`0x47B4C9` 也在 **CScenarioReviewSceneItem** ctor 設 `+0x248=-1`。兩者同位移但不是同一 class/owner。
- `0x47B2B0` 以來源 `[EDI]` 資料建置 Review Item；`0x47B2EF mov [EBX+0x248],EAX` 是 **CScenarioReviewSceneItem** 有界非初始化 writer，還會拷貝來源文字到 `+0x24C`。該 helper 的直接 E8 caller `0x47D36D`；這是 UI 記錄流，不是 S2C network payload 直接 memcpy。
- `0x47D530` 將 `source+0x248/+0x24C` 傳到 `dest+0x120/+0x11C`；`0x47D5AF` 經 `0x47E890` 取出第二 key，`0x47D5B7` 傳 `source`（ECX）呼叫 `0x47B5C0`；它本身的直接 caller `0x47D9DA`。形成有 source provenance 的 **Review UI → SceneList** 路徑。
- `0x47B5C0` 在 `0x47B5EB cmp [edi+0x248],0xEA61` 有特別分支，還檢查 `+0x26C`；該分支可走 `0x47B850` 而非 `0x565720`。其餘路徑 `0x47B63D` 把 Review Item+0x248 與外部 key push 後於 `0x47B64A` 呼叫雙鍵 loader。
- `0xEA61` 是 object field 比較常數，未證為 S2C opcode、首登 quest ID 或 scene key。Review UI 的 writer 命中並不等於 Server 已批准選角。

## 5. EndCutScene 與雙鍵 loader 的真正不同來源

`0x565720` 入口 `0x565756 cmp dword [ESI+0x28],0` 並先設 `ESI+0x89=1`；若先前 `+0x28` 非零，會走診斷／跳轉，不是每次呼叫都重新載入。正常新啟動才把兩個 arg 記在 `ESI+0x38`/`+0x3C`，對 SceneList 作有界雙鍵查找、組 `.seq` path，再依 E14/E15 的修正可達 Lua `0x6F4A50` 資源讀取／解析／protected-call 候選，資源或 VM 失敗另論。

與 Review Item 無關的另一 E8 caller：

```asm
561DE0 cmp byte ptr [edi+0x89],0
561DE7 je 0x561F60                ; gate: 狀態未就緒
561DED cmp dword ptr [edi+0x28],esi
561DF6 mov [edi+0x28],esi        ; reset loader-active state
561ED1 mov eax,[edi+0x3C]       ; caller 自身之 state
561ED4 mov ecx,[edi+0x38]
561ED7 push eax
561ED8 push ecx
561EDE call 0x47E640            ; 取得後續鍵
561EE5 mov [edi+0x3C],eax
561EE8 cmp eax,0
561EEA je 0x561F0B             ; zero 不重入
561EEC mov edx,[edi+0x38]
561EEF push eax
561EF0 push edx
561EF1 mov esi,edi
561EF3 call 0x565720
```

因此同一 `0x565720` 同時被 Review scene UI 和 **EndCutScene 恢復路徑** 使用，且前者的來源是 `SceneItem+0x248`，後者來源是 `this+0x38/+0x3C` 與 `0x47E640`，**不可視為同一 net-to-first-tutorial writer**。

## 6. Event.stp 資源與禁止幻想 `1001/1` wire

E06 對 `Event/SceneList.xml` 已解得 SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`：row `(questIdx=1001,sceneIdx=1)→tutorial_start`。E08 追 SceneList 兩個整數欄位的 parser/index writer；E13 查兩套 `(questIdx,sceneIdx)` reader；E14 的 Lua loader 有實際讀檔、BOM、protected path；E15 更正 E14：第一條 reader 也經共用 setup 的內部 `0x55D7C2` 抵達 `0x6F4A50`，第二條有額外 `0x5659D9`，不等於反覆必然成功執行。

本輪獨立讀 `Event.stp` 原件：前四 bytes 是 `STPD`，按 XOR `0xFF` 解視角，raw `0xA1C010..0xA1C219` 為 522 bytes，SHA256 `1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc`；可見 `Quest #1001 / Scene #1 - Function tutorial_start`、`function tutorial_start()`、`Register(tutorial_start)`，同一 XOR view 含 `tutorial_start.seq` 字串。

這是**靜態資源鍵及 Lua function 的正向證據**，不是 `S2C0x42` body 哪個 offset 要填 1001/1、也不是新帳號必定第一時間啟動的官方規則。沒有此 wire→key 正向關係就不能升為 Server MUST。

## 7. GAP-FLOW-0001：有方向、可驗證的**局部偏序**，不是單一官方完整封包序列

| 階段 | Client 已證的本地資料/控制條件 | 未證的跨 socket / Server 行為 |
|---|---|---|
| AUTH 入口 | mode52→`C2S 0xE8` 112B；mode54/default→`C2S 0x0F` 214B，經 T02 發送 gate | 原版帳密認證政策和本次 Conn wire 時序 |
| AUTH 結果 | 有效 LOGIN scene 才能讓 `S2C 0x13`→`0x4C37A0`，status0 且非空名稱資料走成功；status5/其它有拒絕/清理路徑 | 不推定 Server 第一包必為某特定 frame |
| 選服/連線 | RR-0005 的 `0x495610/0x4957C0` 各 key 的 UI→Connect 邊界 | 異步跨 Conn 真實先後、Server endpoint policy |
| roster | `S2C 0x02` first-layer `0x4B7F00`，有效資源下 65B header＋53B*N record→`0x4D4150` 置 record+0x5C | 所有初始化 S2C 完成順序與真正角色授權規則 |
| 玩家選角 | UI→`0x4A3B80`→`C2S 42 00 XX YY`，4B，需 `FBA798==0` 及各 UI caller guard | 原版 Server 真正成功／拒絕 opcode/body/order，RR-0002 尚 BLOCKED |
| 若收到 S2C42 | 在相符 active scene 分派到 `0x4B2190`，更新 `FAB2A0`，Review UI 可讀 | 沒有證明它就是 C2S42 request 的 ACK |
| 若收到 S2C69/7 | global `0x4B9090` 可建立 CSquare，`0x4B7D50` 安裝/啟動 `0x4BBC10`，後者有條件本地 enqueue `C2S 0x43` len4（E66） | 不能證明原版 Server 將 69/7 當選角成功回覆 |
| tutorial/seq | Review UI 或 EndCutScene 都可能走 `0x565720`，索引可找到 1001/1 | 選角結果至首次教學選擇之 writer/到達順序 UNKNOWN |

上表的**行排序僅為研究／解說排列**。可證偏序只在單一 handler 內部，例如解包/分派先於資料寫入、`S2C69/7` 在條件成立時先於 CSquare::entry 與本地 `C2S43` enqueue；沒有原版 Server trace，不得將表格逐行解釋成原版 wire 時間軸。

## 8. 反例、錯誤邊界、合成測試與交付

1. `C2S42` 與 `S2C42` 共用數值，但前者只有四 bytes、後者操作 20-WORD list；**不能直接配對**。
2. `S2C43` 處理 type6 物件清理，而 CSquare 的 `C2S43` 是另外一個方向的 handshake；不能以 +1 推定回覆。
3. `S2C42` `len=5` 走到 payload+5 讀取，應以 `len>=6` 加子項界限作安全測試；這是靜態短包風險，不是已執行 Client 觀察崩潰。
4. `0x47B5C0` 對 `0xEA61` 有不進雙鍵 loader 的特別分支；`0x565720` 的 `+0x28` 非零還有重入抑制／診斷路徑。
5. EndCutScene 可從不同物件鍵值重用 `0x565720`，不能把 Lua loader 可達＝第一次登入。
6. 合成 `S2C69/7`→CSquare→`C2S43` 的測試若執行只能證相容性；無可靠原版 Server capture 時不稱它為原版选角應答。

### 原始 BIN self-audit：23 項 assertions 皆通過

原始 ELF/PE 跨段 VA→raw、S2C42 table 10 bytes、`0x4B21FD`/`0x4B2210`/`0x4B221C`、20-word loop、Review UI global、兩個 `+0x248` writer、兩個 RTTI、四組 direct-callers、EndCutScene dataflow、`0x565720` reentrant、C2S42 builder、S2C69 global handler、STP Lua SHA 與內容均逐項由原始 bytes 比對。輸出 `passed=true; exact_assertions=23`，全部為靜態 assert；`client_runtime_tested=false`、`server_wire_tested=false`。

可重現測試源應獨立附檔；此 Git 筆記提供完整 fixture：`0x4ADF3D=c7801402000090214b00`、`0x4B21FD=0fbf7602`、`0x47B2EF=898348020000`、`0x47B4C9=898648020000`；E8 callers `0x565720=[0x47B64A,0x561EF3]`，`0x47B5C0=[0x47D5B7]`，`0x47B2B0=[0x47D36D]`，`0x47D530=[0x47D9DA]`；STP decoded Lua SHA 如 §6。

## 9. Client／Server／跨 Task／測試責任與 RR-0008 完成界線

**Client 已證**：RR-0008 指定的 `S2C42` 真正 consumer、表狀態、Review UI consumer、`SceneItem+0x248` 正向 writer+RTTI owner、review 场景双鍵 caller、EndCutScene 另一路、原始 tutorial 資源已形成有界、可追溯的靜態答覆。

**Client 待逆向**：其它間接 alias/callback 是否能從另一種接收命令寫入首次遊玩角色場景；此項不能用現有 Review 路徑的負向論證作全域不存在結論。
**Server 待開發**：由 S00 決定相容選角回覆、角色授權及首次教學策略，但不得宣稱舊 Server 內部政策已還原；未知 `S2C` wire 必須保留 GAP。
**跨 Task 待整合**：RR-0002 仍 `BLOCKED`（原版 C2S42↔真正 S2C reply 未證）；T05/T07/T16 場景／任務／教學真實觸發可由其 owner 繼續。T03 既有 T01 `NEEDS_FIX` 是另一獨立問題，未隨本 RR 解決。
**待遊玩驗證**：需可信 KR 原版成功／失敗封包 capture（Conn key/時間/完整 body）或明確標為合成的自製 Server↔原版 Client 測試。後者不能證明官方 Server 使用同一順序。

**形式化交付**：可向 T01/S00 提交有界 static Client contract，請 T01 逐項審核並由 S00 判定 `ACCEPTED/NEEDS_REVISION`。研究者不自行改 SPEC STABLE、GAP RESOLVED、FULL-PASS。

## 10. 來源及勘誤

在 `extra/roy1/kr-extra-roy/` 的 E06（XML EXv1）、E08（Event.stp Lua/SceneList）、E13（兩個讀者）、E14（Lua loader）、E15（更正第一路也到 loader）、E16（兩個 scene caller 和 EndCutScene）；E61～E67（選角原始 caller、role record、S2C42/43 negative evidence、ScenarioReview RTTI、CSquare scene 和 C2S43）均原樣保留。**E16 對 0x47B5C0 owner 的未知，此篇以 E63 RTTI 和原始機器碼正向補強，不能回頭默認其為 first-login**。T02 E60 lane2/scene dispatcher 與 T03 RR-0003 auth 依主責復用，不再將其它 Task 的網路 core 改寫為 T03。

## 附錄：已存 E63 的原始機器碼精確節選（本輪重驗關鍵 bytes 與 callers）

這些附錄沿用 `extra/roy1` E63 現有原生反組譯文本，避免重新創作機器碼；此 E68 自行重核 SHA、RTTI、表位移和直接 E8 calls。附錄的截取不等於整個函式／Client 的 FULL-PASS。

### Scene review ChapterItem ctor/vptr

`Tartaros.bin` .text VA `0x0047b0f0..0x0047b185`，原生反組譯（終點不含）：

```asm
  47b0f0:	55                   	push   ebp
  47b0f1:	8b ec                	mov    ebp,esp
  47b0f3:	6a ff                	push   0xffffffff
  47b0f5:	68 68 9c 91 00       	push   0x919c68
  47b0fa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b100:	50                   	push   eax
  47b101:	51                   	push   ecx
  47b102:	56                   	push   esi
  47b103:	57                   	push   edi
  47b104:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b109:	33 c5                	xor    eax,ebp
  47b10b:	50                   	push   eax
  47b10c:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b10f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b115:	8b f1                	mov    esi,ecx
  47b117:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b11a:	e8 61 97 2d 00       	call   0x754880
  47b11f:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  47b125:	33 ff                	xor    edi,edi
  47b127:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  47b12a:	50                   	push   eax
  47b12b:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  47b131:	e8 ea 03 30 00       	call   0x77b520
  47b136:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  47b13d:	c7 06 9c 2d c0 00    	mov    DWORD PTR [esi],0xc02d9c
  47b143:	c7 86 48 02 00 00 ff 	mov    DWORD PTR [esi+0x248],0xffffffff
  47b14a:	ff ff ff 
  47b14d:	c7 86 60 02 00 00 07 	mov    DWORD PTR [esi+0x260],0x7
  47b154:	00 00 00 
  47b157:	89 be 5c 02 00 00    	mov    DWORD PTR [esi+0x25c],edi
  47b15d:	33 c9                	xor    ecx,ecx
  47b15f:	66 89 8e 4c 02 00 00 	mov    WORD PTR [esi+0x24c],cx
  47b166:	89 be 68 02 00 00    	mov    DWORD PTR [esi+0x268],edi
  47b16c:	89 be 6c 02 00 00    	mov    DWORD PTR [esi+0x26c],edi
  47b172:	8b c6                	mov    eax,esi
  47b174:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47b177:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b17e:	59                   	pop    ecx
  47b17f:	5f                   	pop    edi
  47b180:	5e                   	pop    esi
  47b181:	8b e5                	mov    esp,ebp
  47b183:	5d                   	pop    ebp
  47b184:	c3                   	ret
```


---

### Scene review SceneItem ctor/vptr

`Tartaros.bin` .text VA `0x0047b490..0x0047b515`，原生反組譯（終點不含）：

```asm
  47b490:	50                   	push   eax
  47b491:	51                   	push   ecx
  47b492:	53                   	push   ebx
  47b493:	56                   	push   esi
  47b494:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b499:	33 c5                	xor    eax,ebp
  47b49b:	50                   	push   eax
  47b49c:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b49f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b4a5:	8b f1                	mov    esi,ecx
  47b4a7:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b4aa:	e8 d1 93 2d 00       	call   0x754880
  47b4af:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  47b4b5:	33 db                	xor    ebx,ebx
  47b4b7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47b4ba:	50                   	push   eax
  47b4bb:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  47b4c1:	e8 5a 00 30 00       	call   0x77b520
  47b4c6:	83 c8 ff             	or     eax,0xffffffff
  47b4c9:	89 86 48 02 00 00    	mov    DWORD PTR [esi+0x248],eax
  47b4cf:	89 86 4c 02 00 00    	mov    DWORD PTR [esi+0x24c],eax
  47b4d5:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  47b4dc:	c7 06 3c 2f c0 00    	mov    DWORD PTR [esi],0xc02f3c
  47b4e2:	c7 86 64 02 00 00 07 	mov    DWORD PTR [esi+0x264],0x7
  47b4e9:	00 00 00 
  47b4ec:	89 9e 60 02 00 00    	mov    DWORD PTR [esi+0x260],ebx
  47b4f2:	33 c9                	xor    ecx,ecx
  47b4f4:	66 89 8e 50 02 00 00 	mov    WORD PTR [esi+0x250],cx
  47b4fb:	88 9e 6c 02 00 00    	mov    BYTE PTR [esi+0x26c],bl
  47b501:	89 9e 70 02 00 00    	mov    DWORD PTR [esi+0x270],ebx
  47b507:	8b c6                	mov    eax,esi
  47b509:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47b50c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b513:	59                   	pop    ecx
  47b514:	5e                   	pop    esi
```


---

### Scene item ID writer from ChapterItem

`Tartaros.bin` .text VA `0x0047b2d8..0x0047b310`，原生反組譯（終點不含）：

```asm
  47b2d8:	8b f9                	mov    edi,ecx
  47b2da:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  47b2dd:	8b 07                	mov    eax,DWORD PTR [edi]
  47b2df:	6a ff                	push   0xffffffff
  47b2e1:	6a 00                	push   0x0
  47b2e3:	8d 4f 08             	lea    ecx,[edi+0x8]
  47b2e6:	8d b3 4c 02 00 00    	lea    esi,[ebx+0x24c]
  47b2ec:	51                   	push   ecx
  47b2ed:	8b ce                	mov    ecx,esi
  47b2ef:	89 83 48 02 00 00    	mov    DWORD PTR [ebx+0x248],eax
  47b2f5:	e8 e6 73 f8 ff       	call   0x4026e0
  47b2fa:	56                   	push   esi
  47b2fb:	8d b3 e8 00 00 00    	lea    esi,[ebx+0xe8]
  47b301:	e8 fa c4 2d 00       	call   0x757800
  47b306:	83 7f 04 16          	cmp    DWORD PTR [edi+0x4],0x16
  47b30a:	b8 01 00 00 00       	mov    eax,0x1
  47b30f:	0f         	jle    0x47b39b
```


---

### Scene object runtime handoff to scene reader

`Tartaros.bin` .text VA `0x0047d530..0x0047d608`，原生反組譯（終點不含）：

```asm
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0
  47d5bc:	57                   	push   edi
  47d5bd:	e8 2e f8 ff ff       	call   0x47cdf0
  47d5c2:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5c8:	8b 31                	mov    esi,DWORD PTR [ecx]
  47d5ca:	e8 41 00 00 00       	call   0x47d610
  47d5cf:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5d5:	0f b6 d0             	movzx  edx,al
  47d5d8:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  47d5de:	52                   	push   edx
  47d5df:	ff d0                	call   eax
  47d5e1:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5e7:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d5e9:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  47d5ef:	ff d0                	call   eax
  47d5f1:	8b cf                	mov    ecx,edi
  47d5f3:	e8 b8 fa ff ff       	call   0x47d0b0
  47d5f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d5fb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d602:	59                   	pop    ecx
  47d603:	5f                   	pop    edi
  47d604:	5e                   	pop    esi
  47d605:	8b e5                	mov    esp,ebp
  47d607:	5d                   	pop    ebp
```


---

### Scenario Review global FAB2A0 UI consumer

`Tartaros.bin` .text VA `0x0047d610..0x0047d6d0`，原生反組譯（終點不含）：

```asm
  47d610:	55                   	push   ebp
  47d611:	8b ec                	mov    ebp,esp
  47d613:	83 e4 f8             	and    esp,0xfffffff8
  47d616:	6a ff                	push   0xffffffff
  47d618:	68 4c 7e 94 00       	push   0x947e4c
  47d61d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d623:	50                   	push   eax
  47d624:	83 ec 2c             	sub    esp,0x2c
  47d627:	53                   	push   ebx
  47d628:	56                   	push   esi
  47d629:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d62e:	33 c4                	xor    eax,esp
  47d630:	50                   	push   eax
  47d631:	8d 44 24 38          	lea    eax,[esp+0x38]
  47d635:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d63b:	8d 87 1c 01 00 00    	lea    eax,[edi+0x11c]
  47d641:	50                   	push   eax
  47d642:	8d 8f 0c 01 00 00    	lea    ecx,[edi+0x10c]
  47d648:	8d 44 24 10          	lea    eax,[esp+0x10]
  47d64c:	e8 6f 62 3c 00       	call   0x8438c0
  47d651:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  47d658:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  47d65c:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47d65f:	75 29                	jne    0x47d68a
  47d661:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  47d668:	c7 44 24 40 00 00 00 	mov    DWORD PTR [esp+0x40],0x0
  47d66f:	00 
  47d670:	e8 eb 27 08 00       	call   0x4ffe60
  47d675:	68 00 cf bc 00       	push   0xbccf00
  47d67a:	e8 9b 4c 41 00       	call   0x89231a
  47d67f:	83 c4 04             	add    esp,0x4
  47d682:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  47d689:	ff 
  47d68a:	83 c6 24             	add    esi,0x24
  47d68d:	56                   	push   esi
  47d68e:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  47d692:	51                   	push   ecx
  47d693:	68 a0 b2 fa 00       	push   0xfab2a0
  47d698:	e8 a3 5d 08 00       	call   0x503440
  47d69d:	c7 44 24 40 01 00 00 	mov    DWORD PTR [esp+0x40],0x1
  47d6a4:	00 
  47d6a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  47d6a9:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  47d6ad:	2b ce                	sub    ecx,esi
  47d6af:	c1 f9 02             	sar    ecx,0x2
  47d6b2:	33 c0                	xor    eax,eax
  47d6b4:	49                   	dec    ecx
  47d6b5:	74 19                	je     0x47d6d0
  47d6b7:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [edi+0x120]
  47d6bd:	8d 49 00             	lea    ecx,[ecx+0x0]
  47d6c0:	8b 1c 86             	mov    ebx,DWORD PTR [esi+eax*4]
  47d6c3:	40                   	inc    eax
  47d6c4:	3b 13                	cmp    edx,DWORD PTR [ebx]
  47d6c6:	0f 84 bc 00 00 00    	je     0x47d788
  47d6cc:	3b c1                	cmp    eax,ecx
  47d6ce:	72 f0                	jb     0x47d6c0
```


---

### S2C42 current handler writes FAB2A0

`Tartaros.bin` .text VA `0x004b21bc..0x004b2230`，原生反組譯（終點不含）：

```asm
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00     	ja     0x4b22c6
```


---

**E68 結論**：S2C42 的 Client 消費確定為局部列表/Review 相關狀態；現在可追到 `0x47B5C0` 的 +0x248 正向寫入者屬 ScenarioReview，另一個 scene loader 呼叫屬 EndCutScene；沒有 `0x42` 回覆→首登 tutorial 的肯定鏈。此限定目標已可提交 T01/S00 審查；原版 Server 的真正選角批准/拒絕仍需 RR-0002 解除阻塞與可信封包證據。
