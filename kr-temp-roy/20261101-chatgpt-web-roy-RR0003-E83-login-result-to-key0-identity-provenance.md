# E83 — RR-0003：S2C 0x0013 登入結果→key0 C2S 0x0001 身分欄位原生閉合、錯誤分支與 E82 勘誤

> 2026-11-01 Asia/Taipei｜KR／T03，chatgpt-web roy。工作分支：**既有** `t03/roy/chatgpt-web`（未新增 branch）。使用者指定完成 RR-0003 後上 GitHub；`main=b1fa730c99dbe2ff29f0ffed8b7a0448d6f4c460`；按 T03 既有規範先經 PR #83 **main → t03/roy/chatgpt-web** 真正 merge（`a82d5c6c3070413bd8a7e9efa8ad8e9780f6c502`），保留雙方全部歷史。本檔是原有已 `IN_REVIEW` RR-0003 的新增 Client-first 研究，不覆寫 E69／原稿，也不由研究者把台帳改成 `ACCEPTED`。T03 既有 T01-RETURN-T03-006-LAYOUT-001 退回按本次指定 RR3 延後（其它 T03-A 勘誤保留待 T01 審核）。

## 1. 來源／研究終點／結果等級

- 第一手 KR `Tartaros.bin` 12,472,320 bytes，SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。全部唯讀；**沒有執行／修補／附加 Client，沒有連原版 Server／封包抓取**。
- PE32 i386，ImageBase `0x400000`；`.text` VA `0x401000`、raw `0x400`，virtual size `0x7D01F0`、raw size `0x7D0200`；`.rdata` VA `0xBD2000`、raw `0x7D0600`；`.data` VA `0xD61000`、raw `0x95E800`（virtual size `0x2873D8`, raw size `0x22B800`）。**只在 .text 使用 file offset = VA−0x400C00**。
- 正式 RR-0003 題目：有界 E8/000F opaque fields 與 codepage、實際 0x13 status response、group/channel cursor/bounds 和下游 handoff；保留官方後端未知。`GAP-AUTH-0001` 要求 opaque E8 tail、codepage、0x13 fields/array bounds、result→connection 接續，以及原版與自訂 Server 決策界線。
- 既有權威：T03 RR3 1,463 行主稿 `kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`（Git blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`）；T03-B W05–W08（blob `e5463936b7b48421219c0e0c83d5d4bf9b07b09f`）；T03-C W09–W12；E69；T02 RR5；S00 `SPEC-AUTH-0001`／`SPEC-FLOW-0001`；以及已於 main 的 **RR-0001 E82 key0 57B 報告（本輪發現其一項重要錯誤，詳 §4）**。T01 對原 RR3 已做 R0 與局部 R2 而非 FULL-PASS。
- **本輪原始 BIN 驗證器** `kr-temp-roy/20261101-chatgpt-web-roy-RR0003-E83-verify.py`：原件 hash、PE、raw 指令、直接 call、表槽、原生 vtable 空實作、group parser 邊界、跨事件欄位 writer→reader、合成安全向量 **97 個明確斷言 PASS（其中 86 項非 synthetic 的原生／PE 主張）**。這不是完整函式 CFG 的 T01 語意認證，不是原版 TCP/GUI 實機互通證據。

## 2. 新的正向跨步驟資料流：S2C 0x0013 成功→Client shared owner→key0 C2S 0x0001

這是本輪最有價值的 **Client native dependence**，並非猜測「原版 Server 必然以 0x0013 回覆 E8/0F」。在**有效 LOGIN scene S2C0x0013 已抵達，且 status=0、名稱非空、copy/資料資源正常**的情況，`0x4C37A0` 寫入的身分相關本地欄位，在其後**另由 UI 選服觸發、且 key0/key2 Conn 都成功**的 `0x4957C0` 中，會成為 key0 local C2S0x0001 的應用資料。

| S2C0x0013 原始 payload offset → handler/writer | Client owner shared field | key0 C2S0x0001 讀取 → output offset | 證據及限制 |
| --- | --- | --- | --- |
| `+0x18` DWORD，`4C3979→4C3981` | `returned_0x404BA0_object+0x67E0` | `4958B8→4958BE`，`C2S1 +2..5` DWORD | 已證同一 getter (`0x404BA0`) 基底與成員位移；Server 業務身份意味 UNKNOWN |
| `+2` UTF-16 name，`4C3990/399B` | 同一物件 `+0x67E4`，capacity11/最多10 WCHAR 複製 | `4958C8/4958D4` → `C2S1 +6..25` capacity10/最多10 WCHAR | 第二次 copy 的**目的容量比前一次更小**；保守合成 Server 可限 **≤9 非 NUL WCHAR**（自訂安全決策，非官方上限） |
| `+0x86` BYTE，`4C39C3→4C39F2` | `+0x6898` | `4958FA→495900` → `C2S1 +27` BYTE | 不等於角色／群組 ID 的正式名稱 |
| `+0x87` narrow string，`4C39E2→4C39F8` | `+0x6899`，容量5B | `495908→495914` → `C2S1 +28..32` 容量5B | **不能**直接稱 credential/token；留意 NUL/轉碼/拷貝失敗 |
| `+0x8C` DWORD，`4C39C9→4C39FD` | `+0x68A0` | `495921→495927` → `C2S1 +33..36` DWORD | 不應把它當 Server 可信 authentication authority |

以上列的是**兩段原生函式確實透過同一 singleton getter／欄位相接**，不能將其升格為「某一次實際 0x13→C2S1 TCP 時序必然發生」：仍需 scene、資源、選服 UI/control、Conn 成功、send queue、外層 framing、WSASend 的各自 gate。被拒絕的 status5 或其它狀態不走這些成功 writer；後續 key0 builder 可能讀到過期或預設 Client 欄位，Server 不應因 payload 字段存在就把請求視為授權。

### 原件指令（精確 VA/記憶體角色）

```asm
4C3979 mov ebx,[esi+18h]              ; S2C13 payload+18 identity-like DWORD
4C397C call 404BA0                    ; shared Client owner
4C3981 mov [eax+67E0h],ebx
4C3990 push 0Ah                       ; name max source units 10
4C3993 add eax,67E4h                 ; destination owner+67E4
4C3998 push 0Bh                       ; destination capacity 11 WCHAR
4C399B call 893FFE                   ; bounded WCHAR copy
4C39C3 mov dl,[esi+86h]
4C39C9 mov ebx,[esi+8Ch]
4C39E2 lea ecx,[esi+87h]
4C39E9 lea edx,[edi+6899h]           ; narrow dest capacity5
4C39F2 mov [edi+6898h],al
4C39F8 call 893B59
4C39FD mov [edi+68A0h],ebx
4C3A03 mov eax,[esi+1Ch]              ; group count
4C3A0A lea ecx,[esi+92h]              ; group cursor
4C3A10 call 4C3080                   ; parse group, local F4243
4C3A15 cmp byte [esi+90h],0
4C3A24 call 4C3170                   ; ONLY when 0; local F4241, not Connect

4958B3 call 404BA0
4958B8 mov edx,[eax+67E0h]
4958BE mov [ebp-3Eh],edx              ; C2S1+2
4958C1 call 404BA0
4958C8 add eax,67E4h                  ; source of first 10 WCHAR
4958D4 call 893FFE                   ; C2S1+6
4958F5 call 404BA0
4958FA mov dl,[eax+6898h]
495908 add eax,6899h                  ; C2S1+28, narrow5
495914 call 893B59
495921 mov ecx,[eax+68A0h]
495927 mov [ebp-1Fh],ecx              ; C2S1+33
495935 push 39h                       ; application payload length57
49593B push 0                         ; manager queue slot0
49593D call edx                       ; queue, NOT wire receipt
```

新 Server **可以做**：以已證欄位產生合成 S2C13 success，再監測原版 Client 在有效選服操作後是否把同樣 opaque bytes 帶入 key0 C2S1；將 raw session/correlation/permission 的真正權威放在新 Server，不能信任 Client 把 S2C bytes 原樣回顯就是身份證明。只把這條鏈當作**候選相容 handshake/反射**，非官方帳號／token 規則。

## 3. 新確認的 S2C 0x13 失敗行為：兩個拒絕分支都要求額外登入/連線狀態處理，並無自動重送證據

有界 UI 狀態矩陣：

| 收到 S2C app0x0013 | Client 直接結果 | Native branches | 新 Server 設計界線 |
| --- | --- | --- | --- |
| `+0x16==5` | 專用結果 UI；global login object（若存在）virtual `+0x14(0)`；manager virtual `+0x20(1,1)`；最後本地 BF60=0，返回 `0x80004005` | `4C3821..4C3944`, `4C3B59..3B64` | 可作失敗相容測試，**不能把 5 命名成官方 bad-password/ban 重試** |
| `+0x16!=0,5` | generic error UI，同樣的 virtual+0x14/manager+0x20/BF60 clear/error HRESULT | `4C3949→4C3A30..4C3B64` | 未證所有錯誤代碼業務 enum；Client 不會在此 handler 自動重送 auth |
| `+0x16==0` 但 `+2` UTF16 name 空 | 跳 generic failure | `4C3951..4C3973→4C3A30` | 單一 status0 **不夠**構成成功；需有 NUL/name/其他資源前提 |
| status0 非空 | 寫 shared owner、解析群組，送 local F4243；`+0x90==0` 才 local F4241 | `4C3979..4C3A29` | 沒有當場 key0/key2 Connect；UI selection 後續另有 guard |

**新增 vtable 反證（先前容易誤會為自動 retry）：** `0x4C38ED/4C3B02` 的 lazy singleton 初始化會呼叫 `0x6D6300`；該函式正常配置、在 `0x6D6321` 把 vptr 寫為 `0xBFB01C`；此已證型別的 vtable `+0x14` 在 `.rdata 0xBFB030` 是指向 **`0x476430`** 的函式指標，`0x476430` 只有 `C2 04 00`（`ret 4`）。因此對**未被重新替換 vptr 的這個新建型別**而言，失敗分支呼叫 virtual+0x14(0) 為空實作，不會因為它自動產生新 C2S auth packet；而 manager+0x20 是另一個虛擬方法，不能以這個 no-op 取代其連線管理副作用。若 singleton 先前被其他合法類別／owner 替換，應重新查 vptr，不能宣稱全程只有這個 target。

```asm
6D6321 mov dword [eax],0xBFB01C   ; new local login-mode object
6D6340 mov dword [eax+8],0x52
.rdata BFB030: dd 00476430h       ; BFB01C + 14h
476430 C2 04 00                   ; ret 4 (no state write or enqueue)
4C3925 mov edx,[ecx]
4C3927 mov eax,[edx+14h]; push 0; call eax
4C3935 mov eax,[edx+20h]; push 1; push 1; call eax
4C3B3A mov eax,[ecx]
4C3B3C mov edx,[eax+14h]; push 0; call edx
4C3B4A mov edx,[eax+20h]; push 1; push 1; call edx
4C3B59 mov eax,80004005h
4C3B5E mov [esi+BF60h],edi         ; EDI is local zero in the common failure path
```

失敗前若 `payload+0x20` optional UTF16 notice 首 WCHAR 非零，handler `4C37E2` 在**status 分支之前**以 `[FBA808]` codepage 呼叫 `WideCharToMultiByte`、輸出到本地字串通知；即使失敗不保證無副作用。不能以 status5/一般失敗說「未顯示任何服務端文字」。缺最短外層 payload 逐欄位 guard／真實失敗 UI screenshot；對新 Server 測試器應採保守長度、NUL 和權限限制。若 `payload+0x20` 沒有 NUL、失敗可能發生於 CRT/Win32/上層框架，不能從單一 handler 保證安全退回。

## 4. **E82/RR-0001 原稿必須勘誤：key0 `+37..56` 並非最終固定 0**

`main` 的 E82 報告把 `C2S app0x0001 +37..56` 稱為「初始化為零」，並在 Server 介面上暗示固定零。這只看到了區域堆疊初始化 `4958A4..4958B0`；**在 queue `0x49593D` 之前還有實際資料寫入！**

```asm
4958A4 mov [ebp-1Bh],eax           ; initial zero at +37
4958A7 mov [ebp-17h],eax
4958AA mov [ebp-13h],eax
4958AD mov [ebp-0Fh],eax
4958B0 mov [ebp-0Bh],eax
4958D9 call 404BA0                   ; get same Client owner
4958DE push 0Ah                      ; count 10 WCHAR
4958E0 add eax,67FAh                ; SECOND string source owner+67FA
4958E5 push eax
4958E6 lea ecx,[ebp-1Bh]            ; C2S1 +37
4958E9 push 0Ah                      ; dest capacity 10 WCHAR
4958EB push ecx
4958EC call 893FFE                   ; native bounded UTF16 copy
...
495935 push 39h                      ; sends original 57B application payload
49593D call edx
```

**更正：** key0 `C2S0x0001 +37..56` 是**第二個 10-WCHAR copy 目的緩衝**，來源為 **`Client owner+0x67FA`**，不是最終固定零。`0x67FA` 的 4-byte direct displacement 在 `.text` 只有 `0x4958E1` 一處；這只是有界 literal-xref 陰性，無法排除 computed address/建構子/相鄰記憶體 copy 將來源設值，**不能臆測該第二字串一定為零**。原報告 E82 的原生初始化 bytes 仍是真的，但被後續 writer 覆寫，原有 verifier 未涵蓋後續 copy，並非其 74 項測試可驗出完整末態。修訂以獨立 [E82 勘誤文件](./20261101-chatgpt-web-roy-RR0003-E83-E82-key0-second-utf16-correction.md) 保留原稿不可覆蓋。請 S00 更新 C04-E1 首包 parser，T01 定向處理早前報告中的「固定 0」assertion，若未經 T01 複驗，**不得稱原 E82 完整語意 FULL-PASS**。

這也是 RR3 原生結果交接的重要未知：在已查的 `0x4C37A0` 成功 writer 中找到 `+67E0/+67E4/+6898/+6899/+68A0` 五個來源，但**未找到「同一 handler 顯式初始化 +67FA」**；key0 會繼續讀那個欄位。應按 Client 全域 writer provenance 另外研究第二字串的來源，不要因為 Server 政策可自訂而憑空補零。

## 5. 0x0013/0x007A layout、bounds 及新 Server 的可執行防禦性合成向量

這一節引用並重新核對既有 E69、RR3、T03-B/C，而不是聲稱第一次發現：

- **LOGIN scene** `0x4C3220` 第二層 table base `+0x5EAC`：`+0x5F44` 是 app0x13→`0x4C37A0`；`+0x627C` 是 app0x7A→`0x4C3C10`（兩者與 wire frame marker、C2S builder mode 不同）。上游 T02 lane2/scene gate 必須正確。
- app0x13 success local fixed prefix 使用最遠 `group cursor=payload+0x92`；固定資料含 `name+2`、status `+0x16`、groupCount DWORD `+0x1C`、optional notice `+0x20`、`+0x86..+0x90` 其他 owner bytes。**對合成 Server 的安全發送器**建議至少填滿 `0x92` bytes，groupCount=0 時也保留整段 prefix。這是 S00 可選的生成器底線，不是原版 Client 會安全拒絕任何較短 payload 的證明。
- `0x4C3080` group header **3B** (u16 ID + u8 child count)，每個 child **10B**；row+4..7 的四 octet 格式化成 IPv4 文字，row+8 非0才進 Client list，row+9 傳給 child append helper；groupCount=0 仍發**本地** F4243。**原生函式不逐 group/child 檢查剩餘封包長度**，新 Server 應在生成前自行驗長及上限。
- app0x7A 是獨立的 `DWORD +2` groupCount、`cursor +6`，不複製 0x13 的 `+0x1C/+0x92`。選服 UI event→record lookup→`0x4957C0` key0/key2 還有 listener、resource、Conn 指標等條件；status0、群組列表和 F4241 不等於直接 Connect。
- 合成測試器（非 Client runtime）：一組 app0x13 len0x92/groupCount0/name「A」/status0，另一組 status5、status0 empty-name 反例；一組 group1 row1 (len0x92+3+10)、無/短 header、過大 groupCount、缺最後 child byte 反例。原件 checker內以**明標 synthetic**的 safe parser 規範驗證，不能拿它證明 Client 自帶 guard。

### Server 建議契約（區分研究與政策）

```text
[server-chosen authentication policy/ADR]
  --frame/profile--> C2S0xE8 112B (narrow CP_ACP after builder) OR C2S0xF 214B (wide UTF16)
  --server validates native fields, treats E8+104..109 as opaque/unstable-->
  --chooses bounded, compatible S2C0x13 response (not proven official pairing)-->
      status0 + nonempty UTF16 username + valid groupCount/cursor
  --Client local state: +67E0/+67E4/+6898/+6899/+68A0; F4243 and optional F4241-->
      [player UI selection and dual Conn gate, not immediate]
  --Client key0 C2S0x0001 57B: fields reflected from above + second 10WCHAR +67FA-->
  --server correlates internally with its own connection/session authority-->
      further roster/scene stages (T02/T03/T04/T05; not claimed completed here)
```

**身份安全**：Client 回傳自己從 S2C 讀過的值可作測試用相關值或 hint，但**不能被當作 proof-of-identity**。Client 可偽造、封包可能重送／交錯；Server 應使用本身可信的帳密認證 Session 綁定 key0/key1/key2 及過期／重放防護（均屬自訂 ADR，不冒稱官方協定實作）。`CP_ACP` 依 Windows locale 改變，E8 tail 6B 沒有經已核 builder 明確填值，Server 應接受 opaque/保留原始 bytes 供有界診斷（不得記錄密碼），**不要**以固定零做認證前提。

## 6. 完成矩陣／剩餘項目與正式流程

| RR3 子問題 | 本輪處置 | 權限與後續 |
| --- | --- | --- |
| E8/000F C2S builder、slot、payload/opaque 6B | 原稿與 E83 再驗，**局部限定已證** | E8+104..109 的每次 memory bytes 仍未知；不能憑空指定官方值 |
| Codepage default/前置和輸出差異 | PE virtual-zero FBA808, direct xref7、E8 WCTMB CP_ACP；已有 B 證據 | 主機 ACP / runtime alias 未完全封閉 |
| S2C0x13 result 0/5/other、UI、group cursor | 有界 Client 分支已證；E83 增 virtual+14 **no-op** (新建型別) 與 manager close path | status5 官方錯誤名稱未知；未執行原版 UI |
| 登入結果→後續連線 handoff | **本輪新正向 bridge：5個 shared field writer→key0 C2S1 reader**；F4243/1 和 GUI/Conn gate 另在 T03-C | C2S1 第二 WCHAR 來源 +67FA provenance 還有 Client 待追，已做 E82 勘誤 |
| 完整原版 Server request/reply 及真正 TCP 時序 | Client 靜態無法指定對端先後 | Server 可自訂 policy 和合成相容驗證；不可當原版唯一規則 |
| 交付完整研究原稿、bounded verifier、S00/T01 更正 | **E83 本稿＋E82 勘誤＋97-check verifier** | 正式 RR3 `IN_REVIEW`，由 S00 決定 `ACCEPTED`/`NEEDS_REVISION`，T01 全文 FULL-PASS 另行判定 |

**Client 待逆向**：`owner+0x67FA` 的完整 writer/constructor/indirect alias；E8 six-byte stack slot 全部 pointer provenance；S2C 0x13 前的 scene/conn實際 runtime source；Client status 失敗訊息與自動 reauth/retry 的其它 callback；登入成功到玩家 UI 的 listener 及互通。

**Server 待開發**：安全解析 login E8/F 與 CP_ACP，server-owned auth/Session/跨 Conn 綁定；選擇 bounded S2C0x13 status/errors/groups、重複登入、失敗重試、反重播及 session fencing；不把 Client opaque bytes 當自有權威。

**跨功能待整合**：S00 C04-E1/E2/E3/F0、`SPEC-AUTH-0001`、`SPEC-FLOW-0001`、`GAP-AUTH-0001`、`TEST-AUTH`，T02 RR1/4/5/7、T03 T03-C、T01 原始驗證與 E82 勘誤。既有 RR3 在 main 已是 IN_REVIEW；不得逆向轉回 SUBMITTED、也不得由 T03 研究者編 ACCEPTED。

**待遊玩驗證**：獲使用者授權後，在隔離自製 Server＋對應 SHA 的原版 Client，分別測 0x13 success/status5/空名、N0/N1 group、斷線重試與第二 WCHAR 欄位；記錄 Client 實際 queue/wire/畫面。**自製 Server 通過≠還原官方 Server 歷史內部決策**。

### 讀取／測試

```powershell
python -B kr-temp-roy/20261101-chatgpt-web-roy-RR0003-E83-verify.py Tartaros.bin
# 預期：PASS，97項有界斷言；不是 Client runtime test 或 T01 FULL-PASS
```

此稿只提交完整新增限定研究，保留 E69/E82/B/C 已發布檔案。GitHub Commit 與 blob SHA 以實際提交後遠端讀回為準。
