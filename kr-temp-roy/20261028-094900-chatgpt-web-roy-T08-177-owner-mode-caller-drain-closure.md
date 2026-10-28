# T08-177 — owner+0x44 模式寫入來源、全直接 caller 與 deferred drain 靜態閉合

- 研究者：`chatgpt-web roy`；實際記錄時間：`2026-10-28T09:49:01+08:00`（Asia/Taipei）。
- 本地完整交付相對路徑：`kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md`；**尚未 Commit／Push**。
- 原始來源：`/mnt/data/Tartaros.bin`，SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（原始檔直接計算，匹配交接）。
- GitHub 當輪最新查得提交：`33a43543b050c58349b272bf04fc6cc7facdb469`（T10-081，非 T08 原稿）；前次 T08-176 交接：`775ff786efcd710c28fd63dbd8c0ec06f6213fac`。GitHub 記錄只讀，不改他人原稿。
- 基線參考：`kr-temp-roy/T08-KNOWLEDGE-BASE.md`、`kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-176-ownership-lifecycle-audit.md`；`shared/source-review-status.json` 曾讀取，未將其審計級別自動升級成 runtime 證明。BIN 的實際 byte 及 objdump 為本段主證據。
- 位址映射：原始 PE `.text` VA `0x00401000`、raw `0x400`、size `0x007D01F0`，由本地 `objdump -h` 核對。下述 raw offset 僅對此 `.text` 有效，公式 `raw = VA - 0x00401000 + 0x400`。
- 方法：全 `.text` byte 掃描 `E8 + signed rel32` 並計算 `target = call_va+5+rel32`；它只是一階**候選**呼叫枚舉（可能誤中指令內資料），關鍵呼叫點逐一使用 objdump 上下文驗證。間接 `FF /2`、vtable、跨模組/異常路徑不在此枚舉覆蓋範圍。

## 1. 新確認成果與對舊筆記的精確更正

1. **`0x007B7FD0` 才是完整函式入口**：前段提及 `0x007B7FA0` 是前一函式的尾段，中途可能落在 `mov ecx,0x10` 的立即數內；真正以 `push ebp / mov ebp,esp` 開始的模式啟用函式是 `0x007B7FD0`，結束於 `0x007B8025: ret 4`。今後 caller 檢索須以 `0x7B7FD0` 定錨。此為新段 BIN-first 更正，不否定前段在 `0x7B8006` 寫入的 byte 事實。
2. **`owner+0x44` 寫入來源是常數 1，已排除該條路徑外部 ECX 未知說法**：`0x7B7FFE: mov ecx,1`，`0x7B8003: mov edx,[eax+0x24]`，`0x7B8006: mov [edx+0x44],ecx`。在同一迴圈 `ecx` 未被改寫；上游 caller 不能在這條路徑決定存入數值。這只證明這一個寫入者，不保證全域只有這一個非零寫入者。
3. `0x7B7FD0` 從傳入的 `[ebp+8]` 取得容器 base `ebx`；先走 `[ebx]` 對應集合的 payload 虛擬呼叫 `vtable+0x04`，再遍歷 `[ebx+0x08]` 指向之另一組節點，將每筆 `node+0x24` payload 的 `+0x44` 設成 1；最後 `[ebx+0x30]=1`。此處兩個容器不可只因都有 `node+0x24` 就混為同一類型。
4. `0x7B8030` 對相同參數容器的 `[ebx+8]` 節點：先以 `esi=[node+0x24]` 執行 `0x7DD1F0`，**然後** `[esi+0x44]=0`；最後對 `[ebx]` 集合的 payload 呼叫另一虛擬函式 `vtable+0x08`，並寫 `[ebx+0x30]=0`。與啟用順序非鏡像：前者先通知另一集合再設模式；後者先 drain/清模式再通知另一集合。
5. 兩個直接 caller 各僅見一處 `E8`，且都 `push 0x00FE173C` 傳入**位址**：`0x007AAF1F → 0x007B7FD0`、`0x007AB155 → 0x007B8030`。故不能把 `0x00FE173C` 誤判成已經解參照的 owner 本體。
6. `0x007DD1F0` **只查得兩個 E8 靜態直接呼叫點**：`0x007B8045`（停用模式時每個 payload drain）與 `0x007DD132`（管理器的 `+0x5C` 計數減到 0 時 drain）。這是全 `.text` E8 byte 掃描及反組譯下的範圍結論；不排除間接/尾呼叫或 DLL 外部調用。
7. `0x007DD100` 以 `ecx` 作管理器基底寫入 `esi`，`0x007DD12A add [esi+0x5C], -1`，只有結果為零才在 `0x007DD132` 呼叫 drain、`0x007DD140` 清 `+0x44`，再逐項呼叫 `0x007DC510`。因此可觀察**條件式最終解除引用時清空佇列**，不是每次引用減少都 drain。
8. `0x007DD1A0` 在 `cmp [ebx+0x44],1; jl immediate` 下，有條件在 `+0x64` 臨界區用 `0x007BB350` 向 `+0x7C/+0x80` 陣列插入指標，否則走 `0x007BD850` 與 `0x0089120C` 的立即釋放；僅能稱**模式閘門**，不能定義為 reference count。
9. `0x007DD1F0` 使用**ESI 寄存器**作 owner 基底，與 C++ 標準 `ecx this` 不同；兩個 caller 都能在呼叫前追到 `esi` 是相應 owner。持 `+0x64` 鎖、對槽位呼叫 `0x007BE0F0`、必要時清理並釋放，最後 `+0x80` 指向 `+0x7C` 相同的 begin。**尤其 `0x7DD26A～0x7DD285` 實際 `mov eax,ecx; sub eax,ecx` => 永遠零，`0x8912F0` 的長度參數為零**，該 `memmove` 不應被筆記錯誤描述為搬移整段記憶體；實際效果以 `end = begin` 及處理槽位為主。

## 2. 直接 call rel32 搜尋核對表

掃描來源：SHA256 匹配的本地 BIN `.text` 全區間，命中目標位址；`E8` 證據含原始 5 bytes，詳細上下文見下文逐函式 disassembly。下列只有已識別的直接候選，**不是完整 xref/CFG**。

| 目標函式 VA | E8 命中數 | 候選 caller VA（原始 bytes） |
|---|---:|---|
| `0x007B7FD0` | 1 | `007AAF1F` (`e8acd00000`) |
| `0x007B8030` | 1 | `007AB155` (`e8d6ce0000`) |
| `0x007DD100` | 1 | `007B8129` (`e8d24f0200`) |
| `0x007DD1A0` | 2 | `007A8741` (`e85a4a0300`); `007BE60F` (`e88ceb0100`) |
| `0x007DD1F0` | 2 | `007B8045` (`e8a6510200`); `007DD132` (`e8b9000000`) |
| `0x007BE5F0` | 42 | `004C7C8F` (`e85c692f00`); `004C7DB4` (`e837682f00`); `004C838C` (`e85f622f00`); `004C83AF` (`e83c622f00`); `004C8411` (`e8da612f00`); `004C902C` (`e8bf552f00`); `004C9066` (`e885552f00`); `004C9074` (`e877552f00`); `004CAFF4` (`e8f7352f00`); `004CC867` (`e8841d2f00`); `004CC89A` (`e8511d2f00`); `004CDDF1` (`e8fa072f00`); `004CE927` (`e8c4fc2e00`); `004CEC2C` (`e8bff92e00`); `004CECA7` (`e844f92e00`)；其餘 27 筆見附錄 |
| `0x004DFF30` | 5 | `004A11B6` (`e875ed0300`); `004AA222` (`e8095d0300`); `004AEC03` (`e828130300`); `004AF4F7` (`e8340a0300`); `004B2F83` (`e8a8cf0200`) |
| `0x004DFBC0` | 2 | `004AA057` (`e8645b0300`); `004B2AC2` (`e8f9d00200`) |
| `0x004DFE90` | 11 | `00424448` (`e843ba0b00`); `004BA9C9` (`e8c2540200`); `004BB62A` (`e861480200`); `004BBCF0` (`e89b410200`); `004BC423` (`e8683a0200`); `004BCCDA` (`e8b1310200`); `004BE5AF` (`e8dc180200`); `004C1706` (`e885e70100`); `004C33E6` (`e8a5ca0100`); `004C4BE3` (`e8a8b20100`); `004C5AA8` (`e8e3a30100`) |

### E8 位移原始算式抽驗

- `0x007AAF1F` bytes `E8 AC D0 00 00`：`0x007AAF24 + 0xD0AC = 0x007B7FD0`。
- `0x007AB155` bytes `E8 D6 CE 00 00`：`0x007AB15A + 0xCED6 = 0x007B8030`。
- `0x007B8045` bytes `E8 A6 51 02 00`：`0x007B804A + 0x251A6 = 0x007DD1F0`。
- `0x007DD132` bytes `E8 B9 00 00 00`：`0x007DD137 + 0xB9 = 0x007DD1F0`。
- `0x007B8129` bytes `E8 D2 4F 02 00`：`0x007B812E + 0x24FD2 = 0x007DD100`。
- `0x007A8741` bytes `E8 5A 4A 03 00`：`0x007A8746 + 0x34A5A = 0x007DD1A0`。
- `0x007BE60F` bytes `E8 8C EB 01 00`：`0x007BE614 + 0x1EB8C = 0x007DD1A0`。

## 3. 資料流與 ABI / 計數協定

### 3.1 模式啟閉

```text
初始化上游：0x7AAF1A push &global(0xFE173C)
              0x7AAF1F call 0x7B7FD0(container*)
              先遍歷 container->collection0，呼叫 payload->vfunc(+4)
              後遍歷 container->collection8，payload->field44 = 1
              container->field30 = 1

終止上游：  0x7AB150 push &global(0xFE173C)
              0x7AB155 call 0x7B8030(container*)
              先遍歷 collection8，ESI=payload; drain(ESI); field44=0
              後遍歷 collection0，呼叫 payload->vfunc(+8)
              container->field30 = 0
```

`[ebx]` 的解參照級數為 `edi=[ebx] ; eax=[edi+4]; esi=[eax]`；`[ebx+8]` 是另一組來源。因 entry node 與 owner 具型別差異，不能把容器 `+0x30`、owner `+0x44` 及 scene actor `+0x44` 宣稱為同一個欄位。

### 3.2 生產和兩個消費時機

```text
resource update (0x7A8741) ─┐
                              ├─> 0x7DD1A0(owner,resource)
release (0x7BE60F) ──────────┘        if owner+44 >= 1: lock(owner+64), append owner+7C..80, unlock
                                       else: resource cleanup/free

shutdown-mode (0x7B8045) ────┐
                              ├─> 0x7DD1F0(ESI=owner): lock, process slots, end=begin, unlock
last-manager-ref (0x7DD132) ─┘
```

`0x7BE5F0` 是 slot 指向之 resource 的 release helper，與場景 actor 登記方法不是同一原語；在 `0x7BE60F` push 的資源及 owner 使用 `ecx`/`esi` 上游資料流各自辨識。`0x7A8741` call 前由 `[edi]` 取 owner 並 push 指標，`0x7BE60F` 前從 `[eax]` 取得 owner。`0x7DD1A0` 函式 `ret 8`，是兩個 stack arguments、callee 清 stack。

### 3.3 `0x7DD100` 解除引用及回傳狀態

`0x7B8124` 取 `edi=[eax+24]`，`mov ecx,edi; call 0x7DD100`；`0x7DD100` 把 `ecx` 存到 `esi`。若 `--[esi+0x5C] != 0`，跳至尾聲返回當前計數；若等於零，則執行 `drain(esi)`、`[esi+0x44]=0`、循環 `owner+0x4C/+0x50` 並調 `0x7DC510`。其上游 `0x7B812E` 使用返回值判斷是否能釋放 `edi`，但「`0x5C` 是否是唯一所有權計數」仍需建構者與全部 `+0x5C` 寫入者驗證。

### 3.4 `0x7DD1F0` 鎖與佇列細節

- 入口 `lea eax,[esi+0x64] ; push eax ; call [0xBD224C]`；退出對相同鎖指標呼叫 `[0xBD2248]`。IAT 具體符號可以另以 import table 核對，不藉指令形態判定平台臨界區 API 名稱。
- begin=`[esi+0x7C]`, end=`[esi+0x80]`，`(end-begin)>>2` 為初始數量；每輪可能重新讀取 end，所以不是對固定快照大小的一次遍歷。
- `push slot ; call 0x7BE0F0` 後檢查原 slot 是否非零；如非零則呼叫 `0x7BD850`、`0x89120C`，將 slot 設零。若 slot 已經為零，直接跳過釋放/清零。`0x7BE0F0` 對傳入值的內部處理需依此前 T08-170 補證，不可推定所有 entry 都保證 non-null。
- `0x7DD26A: mov eax,ecx ; 0x7DD26C: sub eax,ecx`，因此 `eax=0`，計算出的 `ebx=0`；`0x7DD27B` 呼叫 `0x8912F0` 時長度是 0，`0x7DD285: mov [esi+0x80], ebx` 的 `ebx` 在 `0x7DD283 add ebx,edi` 後等於 begin。先前只總結為「複製剩餘資料」的說法在這條具體 BIN 路徑**沒有證據**。
- 本函式沒有直接的時間/帧號讀取；模式停用及最後引用退出都能 drain，不應推定每 frame drain，亦不能推定永不跨 frame。

## 4. 正式 T08 0007 主責與資源 subsystem 的交界

- 已知 scene 登記 `0x004DFF30` 共有五個 E8 候選 caller；scene 個別移除 `0x004DFBC0` 兩個；整表清理 `0x004DFE90` 十一個，見下表。三者和 `0x007DD1F0` **沒有證明直接 caller 邊**。
- 觀察到 `0x007BE5F0` 在資源槽解除引用等地方共有 42 個 E8 byte 候選，包含 `0x004C7DB4`、`0x004C838C` 等；這只提供「場景/元件持有 resource 到 resource manager」的局部 bridge，而**不代表 actor tree remove 等於 deferred queue drain**。
- 正式 0007 的 client-side 建立、登記、移除資料介面是 T08；服務端生成時間、波次、出生規則不從本段推導。T02/T06/T07/T16 的責任界面不修改。

## 5. 證據分級

| 結論 | 等級 | 證據與邊界 |
|---|---|---|
| `0x7B7FD0` 真正入口，`0x7B7FA0` 不是入口 | 已確認 | PE 反組譯與函式界線；本輪更正 |
| `+0x44=1` 由常數立即數設定 | 已確認 | `0x7B7FFE` / `0x7B8006` |
| mode wrapper caller 使用 `&0xFE173C` | 已確認 | `0x7AAF1A` / `0x7AB150` |
| `0x7DD100` 計數歸零時 drain | 已確認 | `0x7DD12A..0x7DD140` |
| `0x7DD1F0` 直接 E8 caller 僅兩個 | 限定確認 | 全 `.text` E8 掃描，不含 indirect |
| `0x7DD1F0` tail memmove 長度為 0 | 已確認 | `0x7DD26A..0x7DD285`，精確資料流 |
| `owner+44` 代表延遲回收模式 | 合理推測 | 模式值為 1 配合 producer gate；全部 writer/types 尚未閉合 |
| 無其他方式呼叫 drain / 故障回滾 | 尚待驗證 | vtable/間接/callback、例外分支未全面核查 |
| 等同每 frame 清空／跨 frame 語意 | 尚待驗證 | 無 runtime tracing / 外層事件時間源 |
| scene 登記/移除與 deferred 佇列同一生命週期 | 尚待驗證 | 暫無同一 owner/物件身分的直接證據 |

## 6. 尚未解決與 T08-178 入口

1. 以 owner 類型與所有配置/建構函式核對 `+0x44` **其他可能寫入者**（含間接/初始化），`+0x5C` 增量寫入者及 mode 啟動/終止是否還有間接 wrapper。
2. 詳析 `0x7B7FD0` `[ebx]` 及 `[ebx+8]` 容器元素 payload 的各自 vptr，並以 `0xFE173C` 實際初始化/解構建立對象身分；避免兩棵名稱容器混同。
3. 驗證 `0x7DD1F0` 中 `0x7BE0F0` 是否可修改 slot、產生重入；索引動態上限、持鎖 callback 的副作用及例外安全仍未知。
4. 檢查 `0x7DD1F0` 函式尾 `0x8912F0` 是否標準 memcpy/memmove stub；零長度可靜態確立，不能因此宣稱編譯器錯誤或 runtime bug。
5. 把正式 `0x004DFF30 / 0x004DFBC0 / 0x004DFE90` 的 owner 取得與 `0x007BE5F0` 的 resource slot 接點逐項比對；沒有型別/指標身分交點就保持隔離。
6. 遠端 `shared/integrations/T01-20261028-06/` 的 PE/flat 限制繼續適用：只以同一 PE raw windows 互證，不使用普遍 `-0x400` 轉位址。

## 附錄 A：本次原始 BIN 小範圍反組譯

以下 output 由本輪 `objdump -D -M intel` 直接取得，**不是 GitHub 偽碼摘錄**。截取上游 caller 區段可能從前一函式中間開始，僅用於確認指定 caller 周邊，請勿將區段首位當函式入口。

### 模式啟用函式（真實入口） — `007B7FD0..007B8026`

```asm
007b7fd0 <.text+0x3b6fd0>:
  7b7fd0:	55                   	push   ebp
  7b7fd1:	8b ec                	mov    ebp,esp
  7b7fd3:	53                   	push   ebx
  7b7fd4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b7fd7:	56                   	push   esi
  7b7fd8:	57                   	push   edi
  7b7fd9:	8b 3b                	mov    edi,DWORD PTR [ebx]
  7b7fdb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7b7fde:	8b 30                	mov    esi,DWORD PTR [eax]
  7b7fe0:	3b f0                	cmp    esi,eax
  7b7fe2:	74 11                	je     0x7b7ff5
  7b7fe4:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7b7fe7:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b7fe9:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7b7fec:	ff d2                	call   edx
  7b7fee:	8b 36                	mov    esi,DWORD PTR [esi]
  7b7ff0:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7b7ff3:	75 ef                	jne    0x7b7fe4
  7b7ff5:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b7ff8:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b7ffa:	3b c1                	cmp    eax,ecx
  7b7ffc:	74 1c                	je     0x7b801a
  7b7ffe:	b9 01 00 00 00       	mov    ecx,0x1
  7b8003:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  7b8006:	89 4a 44             	mov    DWORD PTR [edx+0x44],ecx
  7b8009:	8b 00                	mov    eax,DWORD PTR [eax]
  7b800b:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b800e:	75 f3                	jne    0x7b8003
  7b8010:	5f                   	pop    edi
  7b8011:	5e                   	pop    esi
  7b8012:	89 4b 30             	mov    DWORD PTR [ebx+0x30],ecx
  7b8015:	5b                   	pop    ebx
  7b8016:	5d                   	pop    ebp
  7b8017:	c2 04 00             	ret    0x4
  7b801a:	5f                   	pop    edi
  7b801b:	5e                   	pop    esi
  7b801c:	c7 43 30 01 00 00 00 	mov    DWORD PTR [ebx+0x30],0x1
  7b8023:	5b                   	pop    ebx
  7b8024:	5d                   	pop    ebp
  7b8025:	c2               	ret    0x4
```

### 模式停用函式 — `007B8030..007B8080`

```asm
007b8030 <.text+0x3b7030>:
  7b8030:	55                   	push   ebp
  7b8031:	8b ec                	mov    ebp,esp
  7b8033:	53                   	push   ebx
  7b8034:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b8037:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b803a:	56                   	push   esi
  7b803b:	57                   	push   edi
  7b803c:	8b 38                	mov    edi,DWORD PTR [eax]
  7b803e:	3b f8                	cmp    edi,eax
  7b8040:	74 16                	je     0x7b8058
  7b8042:	8b 77 24             	mov    esi,DWORD PTR [edi+0x24]
  7b8045:	e8 a6 51 02 00       	call   0x7dd1f0
  7b804a:	c7 46 44 00 00 00 00 	mov    DWORD PTR [esi+0x44],0x0
  7b8051:	8b 3f                	mov    edi,DWORD PTR [edi]
  7b8053:	3b 7b 08             	cmp    edi,DWORD PTR [ebx+0x8]
  7b8056:	75 ea                	jne    0x7b8042
  7b8058:	8b 3b                	mov    edi,DWORD PTR [ebx]
  7b805a:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7b805d:	8b 30                	mov    esi,DWORD PTR [eax]
  7b805f:	3b f0                	cmp    esi,eax
  7b8061:	74 11                	je     0x7b8074
  7b8063:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7b8066:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b8068:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7b806b:	ff d2                	call   edx
  7b806d:	8b 36                	mov    esi,DWORD PTR [esi]
  7b806f:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7b8072:	75 ef                	jne    0x7b8063
  7b8074:	5f                   	pop    edi
  7b8075:	5e                   	pop    esi
  7b8076:	c7 43 30 00 00 00 00 	mov    DWORD PTR [ebx+0x30],0x0
  7b807d:	5b                   	pop    ebx
  7b807e:	5d                   	pop    ebp
  7b807f:	c2               	ret    0x4
```

### 模式啟用直接 caller — `007AAF0A..007AAF50`

```asm
007aaf0a <.text+0x3a9f0a>:
  7aaf0a:	68 90 e7 bc 00       	push   0xbce790
  7aaf0f:	e8 06 74 0e 00       	call   0x89231a
  7aaf14:	83 c4 04             	add    esp,0x4
  7aaf17:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7aaf1a:	68 3c 17 fe 00       	push   0xfe173c
  7aaf1f:	e8 ac d0 00 00       	call   0x7b7fd0
  7aaf24:	f6 05 1c 1e fe 00 01 	test   BYTE PTR ds:0xfe1e1c,0x1
  7aaf2b:	75 22                	jne    0x7aaf4f
  7aaf2d:	09 3d 1c 1e fe 00    	or     DWORD PTR ds:0xfe1e1c,edi
  7aaf33:	c7 45 fc 08 00 00 00 	mov    DWORD PTR [ebp-0x4],0x8
  7aaf3a:	e8 81 81 01 00       	call   0x7c30c0
  7aaf3f:	68 b0 f1 bc 00       	push   0xbcf1b0
  7aaf44:	e8 d1 73 0e 00       	call   0x89231a
  7aaf49:	83 c4 04             	add    esp,0x4
  7aaf4c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7aaf4f:	b9           	mov    ecx,0xfe1e0c
```

### 模式停用直接 caller — `007AB13B..007AB175`

```asm
007ab13b <.text+0x3aa13b>:
  7ab13b:	e8 60 cc 00 00       	call   0x7b7da0
  7ab140:	68 90 e7 bc 00       	push   0xbce790
  7ab145:	e8 d0 71 0e 00       	call   0x89231a
  7ab14a:	83 c4 04             	add    esp,0x4
  7ab14d:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  7ab150:	68 3c 17 fe 00       	push   0xfe173c
  7ab155:	e8 d6 ce 00 00       	call   0x7b8030
  7ab15a:	84 1d f0 93 fd 00    	test   BYTE PTR ds:0xfd93f0,bl
  7ab160:	75 22                	jne    0x7ab184
  7ab162:	09 1d f0 93 fd 00    	or     DWORD PTR ds:0xfd93f0,ebx
  7ab168:	c7 45 fc 05 00 00 00 	mov    DWORD PTR [ebp-0x4],0x5
  7ab16f:	e8 6c 03 00 00       	call   0x7ab4e0
  7ab174:	68           	push   0xbce6a0
```

### 管理器計數解除引用 — `007DD100..007DD19C`

```asm
007dd100 <.text+0x3dc100>:
  7dd100:	55                   	push   ebp
  7dd101:	8b ec                	mov    ebp,esp
  7dd103:	6a ff                	push   0xffffffff
  7dd105:	68 2e 88 91 00       	push   0x91882e
  7dd10a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dd110:	50                   	push   eax
  7dd111:	53                   	push   ebx
  7dd112:	56                   	push   esi
  7dd113:	57                   	push   edi
  7dd114:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dd119:	33 c5                	xor    eax,ebp
  7dd11b:	50                   	push   eax
  7dd11c:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dd11f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dd125:	8b f1                	mov    esi,ecx
  7dd127:	83 cf ff             	or     edi,0xffffffff
  7dd12a:	01 7e 5c             	add    DWORD PTR [esi+0x5c],edi
  7dd12d:	8b 46 5c             	mov    eax,DWORD PTR [esi+0x5c]
  7dd130:	75 58                	jne    0x7dd18a
  7dd132:	e8 b9 00 00 00       	call   0x7dd1f0
  7dd137:	33 db                	xor    ebx,ebx
  7dd139:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7dd140:	89 5e 44             	mov    DWORD PTR [esi+0x44],ebx
  7dd143:	75 1f                	jne    0x7dd164
  7dd145:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7dd14c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7dd14f:	e8 4c ac fd ff       	call   0x7b7da0
  7dd154:	68 90 e7 bc 00       	push   0xbce790
  7dd159:	e8 bc 51 0b 00       	call   0x89231a
  7dd15e:	83 c4 04             	add    esp,0x4
  7dd161:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  7dd164:	8b 7e 50             	mov    edi,DWORD PTR [esi+0x50]
  7dd167:	2b 7e 4c             	sub    edi,DWORD PTR [esi+0x4c]
  7dd16a:	c1 ff 02             	sar    edi,0x2
  7dd16d:	3b fb                	cmp    edi,ebx
  7dd16f:	76 16                	jbe    0x7dd187
  7dd171:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  7dd174:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7dd177:	8b 0d 3c 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe173c
  7dd17d:	e8 8e f3 ff ff       	call   0x7dc510
  7dd182:	43                   	inc    ebx
  7dd183:	3b df                	cmp    ebx,edi
  7dd185:	72 ea                	jb     0x7dd171
  7dd187:	8b 46 5c             	mov    eax,DWORD PTR [esi+0x5c]
  7dd18a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dd18d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dd194:	59                   	pop    ecx
  7dd195:	5f                   	pop    edi
  7dd196:	5e                   	pop    esi
  7dd197:	5b                   	pop    ebx
  7dd198:	8b e5                	mov    esp,ebp
  7dd19a:	5d                   	pop    ebp
  7dd19b:	c3                   	ret
```

### 佇列生產/立即釋放 — `007DD1A0..007DD1EB`

```asm
007dd1a0 <.text+0x3dc1a0>:
  7dd1a0:	55                   	push   ebp
  7dd1a1:	8b ec                	mov    ebp,esp
  7dd1a3:	53                   	push   ebx
  7dd1a4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dd1a7:	83 7b 44 01          	cmp    DWORD PTR [ebx+0x44],0x1
  7dd1ab:	57                   	push   edi
  7dd1ac:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  7dd1af:	7c 24                	jl     0x7dd1d5
  7dd1b1:	56                   	push   esi
  7dd1b2:	8d 73 64             	lea    esi,[ebx+0x64]
  7dd1b5:	56                   	push   esi
  7dd1b6:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dd1bc:	8d 7b 7c             	lea    edi,[ebx+0x7c]
  7dd1bf:	8d 45 0c             	lea    eax,[ebp+0xc]
  7dd1c2:	e8 89 e1 fd ff       	call   0x7bb350
  7dd1c7:	56                   	push   esi
  7dd1c8:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd1ce:	5e                   	pop    esi
  7dd1cf:	5f                   	pop    edi
  7dd1d0:	5b                   	pop    ebx
  7dd1d1:	5d                   	pop    ebp
  7dd1d2:	c2 08 00             	ret    0x8
  7dd1d5:	85 ff                	test   edi,edi
  7dd1d7:	74 0e                	je     0x7dd1e7
  7dd1d9:	e8 72 06 fe ff       	call   0x7bd850
  7dd1de:	57                   	push   edi
  7dd1df:	e8 28 40 0b 00       	call   0x89120c
  7dd1e4:	83 c4 04             	add    esp,0x4
  7dd1e7:	5f                   	pop    edi
  7dd1e8:	5b                   	pop    ebx
  7dd1e9:	5d                   	pop    ebp
  7dd1ea:	c2               	ret    0x8
```

### 佇列消費 — `007DD1F0..007DD29B`

```asm
007dd1f0 <.text+0x3dc1f0>:
  7dd1f0:	55                   	push   ebp
  7dd1f1:	8b ec                	mov    ebp,esp
  7dd1f3:	51                   	push   ecx
  7dd1f4:	53                   	push   ebx
  7dd1f5:	8d 46 64             	lea    eax,[esi+0x64]
  7dd1f8:	57                   	push   edi
  7dd1f9:	50                   	push   eax
  7dd1fa:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7dd1fd:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dd203:	8b 46 7c             	mov    eax,DWORD PTR [esi+0x7c]
  7dd206:	8b 8e 80 00 00 00    	mov    ecx,DWORD PTR [esi+0x80]
  7dd20c:	2b c8                	sub    ecx,eax
  7dd20e:	c1 f9 02             	sar    ecx,0x2
  7dd211:	33 db                	xor    ebx,ebx
  7dd213:	85 c9                	test   ecx,ecx
  7dd215:	74 46                	je     0x7dd25d
  7dd217:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7dd21a:	52                   	push   edx
  7dd21b:	e8 d0 0e fe ff       	call   0x7be0f0
  7dd220:	8b 46 7c             	mov    eax,DWORD PTR [esi+0x7c]
  7dd223:	83 3c 98 00          	cmp    DWORD PTR [eax+ebx*4],0x0
  7dd227:	8d 04 98             	lea    eax,[eax+ebx*4]
  7dd22a:	74 1e                	je     0x7dd24a
  7dd22c:	8b 38                	mov    edi,DWORD PTR [eax]
  7dd22e:	85 ff                	test   edi,edi
  7dd230:	74 0e                	je     0x7dd240
  7dd232:	e8 19 06 fe ff       	call   0x7bd850
  7dd237:	57                   	push   edi
  7dd238:	e8 cf 3f 0b 00       	call   0x89120c
  7dd23d:	83 c4 04             	add    esp,0x4
  7dd240:	8b 4e 7c             	mov    ecx,DWORD PTR [esi+0x7c]
  7dd243:	c7 04 99 00 00 00 00 	mov    DWORD PTR [ecx+ebx*4],0x0
  7dd24a:	8b 46 7c             	mov    eax,DWORD PTR [esi+0x7c]
  7dd24d:	8b 96 80 00 00 00    	mov    edx,DWORD PTR [esi+0x80]
  7dd253:	2b d0                	sub    edx,eax
  7dd255:	43                   	inc    ebx
  7dd256:	c1 fa 02             	sar    edx,0x2
  7dd259:	3b da                	cmp    ebx,edx
  7dd25b:	72 ba                	jb     0x7dd217
  7dd25d:	8b 8e 80 00 00 00    	mov    ecx,DWORD PTR [esi+0x80]
  7dd263:	8b 7e 7c             	mov    edi,DWORD PTR [esi+0x7c]
  7dd266:	3b f9                	cmp    edi,ecx
  7dd268:	74 21                	je     0x7dd28b
  7dd26a:	8b c1                	mov    eax,ecx
  7dd26c:	2b c1                	sub    eax,ecx
  7dd26e:	c1 f8 02             	sar    eax,0x2
  7dd271:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7dd278:	53                   	push   ebx
  7dd279:	51                   	push   ecx
  7dd27a:	57                   	push   edi
  7dd27b:	e8 70 40 0b 00       	call   0x8912f0
  7dd280:	83 c4 0c             	add    esp,0xc
  7dd283:	03 df                	add    ebx,edi
  7dd285:	89 9e 80 00 00 00    	mov    DWORD PTR [esi+0x80],ebx
  7dd28b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7dd28e:	50                   	push   eax
  7dd28f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd295:	5f                   	pop    edi
  7dd296:	5b                   	pop    ebx
  7dd297:	8b e5                	mov    esp,ebp
  7dd299:	5d                   	pop    ebp
  7dd29a:	c3                   	ret
```

### 計數解除引用直接 caller — `007B8118..007B8157`

```asm
007b8118 <.text+0x3b7118>:
  7b8118:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7b811b:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7b811e:	75 04                	jne    0x7b8124
  7b8120:	33 c0                	xor    eax,eax
  7b8122:	eb 32                	jmp    0x7b8156
  7b8124:	8b 78 24             	mov    edi,DWORD PTR [eax+0x24]
  7b8127:	8b cf                	mov    ecx,edi
  7b8129:	e8 d2 4f 02 00       	call   0x7dd100
  7b812e:	85 c0                	test   eax,eax
  7b8130:	75 1f                	jne    0x7b8151
  7b8132:	85 ff                	test   edi,edi
  7b8134:	74 0e                	je     0x7b8144
  7b8136:	e8 05 4e 02 00       	call   0x7dcf40
  7b813b:	57                   	push   edi
  7b813c:	e8 cb 90 0d 00       	call   0x89120c
  7b8141:	83 c4 04             	add    esp,0x4
  7b8144:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7b8147:	50                   	push   eax
  7b8148:	8d 4d d0             	lea    ecx,[ebp-0x30]
  7b814b:	51                   	push   ecx
  7b814c:	e8 2f 05 00 00       	call   0x7b8680
  7b8151:	b8 01 00 00 00       	mov    eax,0x1
  7b8156:	8b               	mov    ecx,DWORD PTR [ebp-0xc]
```

### 資源更新到生產 — `007A872B..007A8763`

```asm
007a872b <.text+0x3a772b>:
  7a872b:	8b 07                	mov    eax,DWORD PTR [edi]
  7a872d:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7a8730:	8b 47 74             	mov    eax,DWORD PTR [edi+0x74]
  7a8733:	85 c0                	test   eax,eax
  7a8735:	74 11                	je     0x7a8748
  7a8737:	83 7f 78 00          	cmp    DWORD PTR [edi+0x78],0x0
  7a873b:	74 0b                	je     0x7a8748
  7a873d:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7a873f:	57                   	push   edi
  7a8740:	51                   	push   ecx
  7a8741:	e8 5a 4a 03 00       	call   0x7dd1a0
  7a8746:	eb 19                	jmp    0x7a8761
  7a8748:	83 f8 01             	cmp    eax,0x1
  7a874b:	7c 06                	jl     0x7a8753
  7a874d:	57                   	push   edi
  7a874e:	e8 9d 59 01 00       	call   0x7be0f0
  7a8753:	e8 f8 50 01 00       	call   0x7bd850
  7a8758:	57                   	push   edi
  7a8759:	e8 ae 8a 0e 00       	call   0x89120c
  7a875e:	83 c4 04             	add    esp,0x4
  7a8761:	8b 7e              	mov    edi,DWORD PTR [esi+0xc]
```

### 資源解除引用到生產 — `007BE5F0..007BE647`

```asm
007be5f0 <.text+0x3bd5f0>:
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
```

## 附錄 B：較大量 caller（`0x007BE5F0`）完整 E8 候選

- `0x004C7C8F`: `e85c692f00` => `0x007BE5F0`
- `0x004C7DB4`: `e837682f00` => `0x007BE5F0`
- `0x004C838C`: `e85f622f00` => `0x007BE5F0`
- `0x004C83AF`: `e83c622f00` => `0x007BE5F0`
- `0x004C8411`: `e8da612f00` => `0x007BE5F0`
- `0x004C902C`: `e8bf552f00` => `0x007BE5F0`
- `0x004C9066`: `e885552f00` => `0x007BE5F0`
- `0x004C9074`: `e877552f00` => `0x007BE5F0`
- `0x004CAFF4`: `e8f7352f00` => `0x007BE5F0`
- `0x004CC867`: `e8841d2f00` => `0x007BE5F0`
- `0x004CC89A`: `e8511d2f00` => `0x007BE5F0`
- `0x004CDDF1`: `e8fa072f00` => `0x007BE5F0`
- `0x004CE927`: `e8c4fc2e00` => `0x007BE5F0`
- `0x004CEC2C`: `e8bff92e00` => `0x007BE5F0`
- `0x004CECA7`: `e844f92e00` => `0x007BE5F0`
- `0x004D0330`: `e8bbe22e00` => `0x007BE5F0`
- `0x004D1333`: `e8b8d22e00` => `0x007BE5F0`
- `0x004D16B8`: `e833cf2e00` => `0x007BE5F0`
- `0x004D2449`: `e8a2c12e00` => `0x007BE5F0`
- `0x004D2497`: `e854c12e00` => `0x007BE5F0`
- `0x004D2522`: `e8c9c02e00` => `0x007BE5F0`
- `0x004D25A6`: `e845c02e00` => `0x007BE5F0`
- `0x004D2632`: `e8b9bf2e00` => `0x007BE5F0`
- `0x004D26BE`: `e82dbf2e00` => `0x007BE5F0`
- `0x004D2772`: `e879be2e00` => `0x007BE5F0`
- `0x004D287D`: `e86ebd2e00` => `0x007BE5F0`
- `0x00543B98`: `e853aa2700` => `0x007BE5F0`
- `0x00543FDF`: `e80ca62700` => `0x007BE5F0`
- `0x0054480B`: `e8e09d2700` => `0x007BE5F0`
- `0x00550B7D`: `e86eda2600` => `0x007BE5F0`
- `0x00550DAE`: `e83dd82600` => `0x007BE5F0`
- `0x00550EF9`: `e8f2d62600` => `0x007BE5F0`
- `0x00550EFE`: `e8edd62600` => `0x007BE5F0`
- `0x00550FB5`: `e836d62600` => `0x007BE5F0`
- `0x00552380`: `e86bc22600` => `0x007BE5F0`
- `0x007A5361`: `e88a920100` => `0x007BE5F0`
- `0x007A69A9`: `e8427c0100` => `0x007BE5F0`
- `0x007A78AA`: `e8416d0100` => `0x007BE5F0`
- `0x007A7A79`: `e8726b0100` => `0x007BE5F0`
- `0x007A7ACE`: `e81d6b0100` => `0x007BE5F0`
- `0x007A8DAC`: `e83f580100` => `0x007BE5F0`
- `0x007FF79A`: `e851eefbff` => `0x007BE5F0`
