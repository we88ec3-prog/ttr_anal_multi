# T01 R2 第五批：同 key Conn+0x14 與 Pool 轉移，及 RR-0005 E56 初次限定審查

2026-10-30（Asia/Taipei）；原件 KR Tartaros.bin，12,472,320 bytes、SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。原檔唯讀，沒有啟動、修改、附加 Client 或產生原版 Server 封包擷取。這是 T01 R2 有界原生資料流審核，不等於整篇 E56 FULL-PASS，也不是 S00 對 RR-0005 的接受決議。

## 0. 交付基準與來源版本

前批完整 T01 Batch4 位於 research/handoffs/t01-20261030-extra-t16-r2/batch4/，其中 0x7B6890 rooted CFG 檢查 223 句 reachable native instructions、45 branches、10 direct calls。前批 51 份來源已正式登錄 SRC-0400～0450，都是 REGISTERED；與正式 R1/R2/R3 審查分開。

本次新增的 **RR-0005 E56** 是 T02 作者正式提交的限定靜態研究來源：
kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md
原始 Git blob: 843889349bb58209c02221e720800f0e9e3ff9d8。
唯一 RR 台帳已收到 SUBMITTED 及 E56 report_path/blob；T01 不擅自覆寫 RR 狀態、代 S00 ACCEPTED 或把「靜態研究已交付」視為所有 Client wire/ownership 實際 runtime 證明。

T02 extra/roy1 來源 E53 Git blob 659e26be843cb29e6fdfc1f14246fb8357c1aca9、E55 blob a9594a1933472f1f42e2618b07682e26b98435cd 已用於交叉對照；它們的版本位於研究分支，T01 不擅自合併其它 Task 工作分支。

PE sections：.text VA 0x401000/raw 0x400，故 text raw=VA-0x400C00；.rdata VA 0xBD2000/raw 0x7D0600，故 rdata raw=VA-0x401A00。所用未命名 class/Pool/Conn/Client 均為用途暫名。

## 1. 新 native 核對：Client+0x30 虛擬更新路徑是第三條 Pool+48 producer

.rdata 原件 VA 0xC05AD4（raw 0x8040D4）LE32 = 0x490FE0，為 vtable 0xC05AA4 + 0x30。這是有正向指標的間接方法，不得用「沒有 direct E8 xref」當作從未被呼叫證據。

~~~asm
490fe0  55 8b ec               ; 進入函式
491045  8b 0d 58 a8 fb 00     mov ecx,[FBA858]      ; Pool*
49104b  8b 41 34              mov eax,[ecx+0x34]   ; Pool mutex
49104f  ff 15 4c 22 bd 00     call [BD224C]        ; EnterCriticalSection
491077  8b 4a 28              mov ecx,[edx+0x28]   ; Pool+0x28 tracking sentinel
49108c  8b 58 08              mov ebx,[eax+0x8]    ; tracked Conn*
49108f  39 b3 ac a0 00 00     cmp [ebx+0xA0AC],esi; 必要 lease gate
4910c5  39 98 58 bf 00 00     cmp [eax+0xBF58],ebx; Client alias conditional branch
49117c  ff 48 44              dec dword [eax+0x44] ; Pool active count
49117f  8b 78 48              mov edi,[eax+0x48]  ; Pool+0x48
491193  e8 68 c5 2b 00        call 0x74D700       ; list-node insertion helper
4911b7  c7 43 14 00 00 00 00 mov dword [ebx+0x14],0
491203  e8 38 49 37 00        call 0x805B40       ; recycler
~~~

具體限制：Pool+28 必須非空、Conn+A0AC !=0；Pool+48 配置與容量／例外路徑不能逕視為一定成功。Client+BF58 的條件命中會有 0x6D6300 衍生 callback，**目前不能無證據把 BF58 與 BF60/BF64/BF68 的 key-slot 畫等號**。

已知 Pool+48 正向來源至少三類：0x805AF0 (connect failure)、0x8066A0 (Manager teardown)、0x490FE0 (Client update tracked Conn)。不是說「same key replace 時舊 Conn 一定被以上任一路徑接納」。本段與 E53 在此 bounded chain 互相支持，而非作者來源提升為 FULL-PASS。

## 2. 重要精確反證：Conn+0x14 == 0 並非 Pool+48 入列的唯一來源

~~~asm
805b30  c7 42 14 00 00 00 00  mov dword [edx+0x14],0 ; connect failure producer
806778  c7 40 14 00 00 00 00  mov dword [eax+0x14],0 ; manager teardown producer
4911b7  c7 43 14 00 00 00 00  mov dword [ebx+0x14],0 ; Client update producer
805f50  c7 06 ff ff ff ff     mov dword [esi],-1
805f59  33 db                 xor ebx,ebx
805f6d  89 5e 14              mov dword [esi+0x14],ebx ; reset also clears to zero!
805fda  e8 01 04 00 00        call 0x8063E0           ; clear local TX queue
805b58  83 79 14 00           cmp dword [ecx+0x14],0 ; Pool+28 prune gate
805ba6  8b 8e b8 a0 00 00     mov ecx,[esi+0xA0B8]   ; Pool+48 recycle gate
805bb7  e8 94 03 00 00        call 0x805F50
~~~

reset 0x805F50 在 Conn 重用路徑 (0x805950) 也可能被呼叫。因而只看到 +14==0 **不能倒推出其歷史必定是 Pool+48 enqueue**。這是對 CLM-NET-0015 應追加的負面範圍。Pool+28 tracking gate 與 Pool+48 A0B8==0 reset gate 也是兩個條件，不能當單一原子 close。

## 3. same-key owner 與 0x7B6890 的已驗證／未驗證界線

Batch4 的 native rooted 0x7B6890 graph 經 0x89120C→0x8920FC→HeapFree 釋放的是 tree node；未見該 bounded call chain 取 node+0x10 Conn* 執行 close/Conn destructor。key map replacement 不能直接等同 socket close。Client 0x490FE0 新補了一條正常 Pool+28→+48 清理途徑，**但沒有證據保證同 key oldConn 一定在其追蹤列表**。同時 IOCP completion 使用原先 Conn* completion key，而非重新查現行 Manager[key]；其 pending／cancel／ABA race 關係仍未形成全稱保證。故 oldConn leak 或 race-freedom 均不可當已證結論。

## 4. E56 的 T01 先期驗收分級（不是 S00 review 判決）

| E56 限定主張 | 本批獨立來源檢核 | 此時 T01 等級 |
| --- | --- | --- |
| 0x7B6890 erase tree node ≠ Conn close | 本地 Batch4 rooted CFG 223/45/10 + HeapFree；本批沿用 | PARTIAL：該函式鏈有界成立；全域持有者 U |
| 正常 Client update 0x490FE0 → Pool+48 | 本次原始 .rdata vtable + native 0x49117C/4911B7/491203 | PARTIAL：條件式成立；上游實際觸發頻率 U |
| Conn+0x14 是 recycler gate | 本次 4 個清零 site、0x805B58、0x805BA6 | PARTIAL：反例 reset 0x805F50 使 0 值不具專屬來源 |
| 0x495610 的 6 caller 與 0x38/0x68/0x2CE 首送候選 | E56/E55 作者主張；本次未獨立逐個重跑其 CFG | SOURCE-ONLY（待 T01 定向 R2） |
| 0x0013/0x007A → selection records/UI → 4957C0 | 已存在 E44/E45/T03 的限定來源；本批未重做最小合法 payload 長度/alias 全閉合 | PARTIAL/source-scoped；不可宣稱 real session |
| key0 的 0x39 bytes local queue、送 pump 進 WSASend | E56/E54/T16/T02 的有限原生鏈；本次主要核 Pool/Conn | SOURCE-ONLY for E56 的整段 assertion，需核 send-by-key return/failure/wire |
| 連線失敗後可 clean shutdown，oldConn 全回收 | 0x805F50 reset 和 0x8063E0 不等於 closesocket；另有 0x806FC0 close | **UNKNOWN 全域**：不得用本批靜態證據宣稱保證 |
| 實際 first Server reply/wire ordering、官方端點 | Client 靜態無合法同 session runtime 記錄 | UNKNOWN；S00 決策不得偽裝成 Client 事實 |

E56 已正式 SUBMITTED，T01 本批尚**未**完成其全部 affirmative claims 的獨立根據審查，故不代 S00 接受，也未替原作者建立 NEEDS_FIX（部分證據待查，不等於已證原稿錯誤）。下次 T01 對 E56 的優先 R2：0x495610 六種 entry 的不同 local send payload/len、0x4957C0 兩 Conn success/fail 和 Connect error 的 socket release、0x4C37A0/0x4C3C10 handler-local length 下界、Client+BF58 真實 writer 或 alias。

## 5. 與 T16 的跨 Task 邊界

現有 Batch4 獨立證據：0x5009D8 是 QuestRecord type1 篩選，0x500A58 為 type2，0x5008F3 呼叫 0x500A00；因此 T16-116 type1 UI reader 不直接保證 Quest16 type2 表示。T16-117 已修正該局部推論，不表示 0x74 key14 或 0x36 Quest16 C2S 的所有限定鏈被撤銷。後續 T16 原稿仍屬 T16 分支，不由 T01 擅改 source。

## 6. 可重現性／缺口與 S00 handoff

本地原始 BIN 自行重跑 22 native bytes、7 E8/E9 rel32 targets、1 .rdata vtable pointer 全部 PASS。下列 JSON 列出本次定點；這不構成全體 Conn+14 writers 查盡、所有相關 callback 的 rooted CFG、實際 OS 競態安全或 FULL-PASS。

- Client 待逆向：old Conn owner、其能否進 Pool+28 / Client update 路徑、IOCP completed/cancel balance、BF58 所有來源、E56 其餘輸入/錯誤 path。
- Server 待開發：對登入/選服/重連斷線及 Quest 進度規劃相容回覆；Client Pool 是內部結構，不能變成 Server 規格強制複製的演算法。
- 跨功能待整合：T02 transport / T03 UI selection / T16 quest event；以精確來源 SHA 跨任務參照。
- 待遊玩驗證：合法 session wire 順序、重連、NPC/Quest UI refresh。
- 本批沒有 NATIVE_VERIFIED/FULL-PASS、RR ACCEPTED、S00 SPEC STABLE。研究仍有具體未閉合路徑，不把此次交件視為 RR 靜態整體目標已由 T01 獨立通過。

