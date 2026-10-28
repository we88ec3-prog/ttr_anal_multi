# T03-LOGIN-01 — KR F42EF 事件來源、獨立 UI 消費者與選角記錄門檻

> 日期：2026-10-28 Asia/Taipei。本檔為本對話新研究的完整可保留原稿（已取得證據的範圍），未提交 GitHub。`LOGIN-01` 是新研究序列暫定標記；GitHub 原有 T03 無已證實連續 `T03-NNN` 序列，待整合者核對命名。不可將此檔視作完整角色選擇網路閉環。

## 0. 源及分支基準

- 原件 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`（當次本機直接 `sha256sum`）。
- PE32 .text RVA 0x1000 VA 0x401000 raw 0x400，故 .text raw = VA-0x400C00；.rdata RVA 0x7D2000 raw 0x7D0600；.data RVA 0x961000 raw 0x95E800（均由當次 PE section header 直接讀得）。
- 來源為 `objdump -D -Mintel` 實際 BIN 位元組及 `.text` immediate scan，非執行目標；沒有原始 Server 封包或動態執行證據。
- GitHub 已核對 `main` 6f621c95740276c2f950f7998bfb7283ff21e65a，T03 舊 head 459d49c02745e3a1f17f35c8e6f9ad4871c992b2；生成並推送雙父合併 commit `2d1def1be4c1becba79df1438f0a2e2e6c3c45a4` 至 `t03/roy/chatgpt-web`，遠端 compare `behind_by=0`、`ahead_by=2`。這是使用者明確授權的同步，**本研究無 Commit／Push**。
- 先前 `kr/tasks/T03/README.md` 與 `task.json`：已建立 command2 65+53*n roster、`4D4150`→record+5C、`672F00` UI gate 及 `5A67D0` F4246/F4278/F4247 局部處理；尚缺 F42EF 消費者和 producer 等。本段不將歷史成果當新增驗證，僅做新入口對照。

## 1. 第一輪（LOGIN-01）：原始 BIN F42EF 常數交叉掃描

對 `.text` raw 範圍直接搜尋 little-endian dword `0x000F42EF`，得到三個 literal 位址 `0x5A69EB`、`0x6602F3`、`0x673E16`；前者是**另一獨立函式的 CMP 立即數**，後二者為事件物件 `+0x10` writer。先前已分析 `5A67D0` switch 並未列出 F42EF；但同一 `.text` 區塊後方另有 `5A69E0` 函式，故不能因 switch 排除全域 consumer。

### 1.1 F42EF consumer — 0x5A69E0

```asm
5a69e0: 55                    push ebp
5a69e1: 8b ec                 mov ebp,esp
5a69e5: 8b 75 08              mov esi,[ebp+0x8]
5a69e8: 81 7e 10 ef 42 0f 00  cmp DWORD PTR [esi+0x10],0xf42ef
5a69f1: 75 4b                 jne 0x5a6a3e
5a69f3: 8b 06                 mov eax,[esi]
5a69f5: 8b 50 04              mov edx,[eax+0x4]
5a69f8: 8b ce                 mov ecx,esi
5a69fa: ff d2                 call edx
5a69fc: 3d b9 05 01 00        cmp eax,0x105b9
5a6a01: 75 04                 jne 0x5a6a07
5a6a1d: 8b 40 14              mov eax,[eax+0x14]
5a6a21: 8b bb 3c 01 00 00     mov edi,[ebx+0x13c]
5a6a27: 50                    push eax
5a6a28: e8 23 e7 0b 00        call 0x665150
5a6a2d: 8b 8b 3c 01 00 00     mov ecx,[ebx+0x13c]
5a6a33: 8b 11                 mov edx,[ecx]
5a6a35: 8b 82 d0 00 00 00     mov eax,[edx+0xd0]
5a6a3b: ff d0                 call eax
```

`0x5A6A07` 在虛擬方法回傳值非 `0x105B9` 時經由 `ds:[0xBD2580]` 呼叫診斷路徑，接著 EAX 設零；立即在 `0x5A6A1D` 解參考 `EAX+0x14`。**沒有動態證據**判斷診斷函式是否必定不返回，故不得把此當成可正常恢復的錯誤路徑。成功時事件 `+0x14` 傳給 `0x665150`，隨後 `receiver+0x13C` dialog 的 virtual `+0xD0` 被呼叫。這構成具體 F42EF UI 消費入口，但不等於證明 dialog 已訂閱此事件或原始 wire opcode。

### 1.2 生產者 A — 0x660260 的事件條件分支

```asm
660285: 8b 4d 08              mov ecx,[ebp+0x8]
660288: 8b 41 10              mov eax,[ecx+0x10]
66028b: 3d 78 05 00 00        cmp eax,0x578
660290: 74 23                 je 0x6602b5
660292: 3d 41 06 00 00        cmp eax,0x641
660297: 0f 85 bd 00 00 00     jne 0x66035a
6602b5: 8b 86 64 01 00 00     mov eax,[esi+0x164]
6602bb: 8b 40 20              mov eax,[eax+0x20]
6602be: 39 41 08              cmp [ecx+0x8],eax
6602c1: 0f 85 93 00 00 00     jne 0x66035a
6602c7: 6a 18                 push 0x18
6602c9: e8 9a 0f 23 00        call 0x891268
6602d5: 8b 8e a8 01 00 00     mov ecx,[esi+0x1a8]
6602f0: c7 40 10 ef 42 0f 00  mov [eax+0x10],0xf42ef
6602f7: c7 00 ac 67 c4 00     mov [eax],0xc467ac
6602fd: 89 48 14              mov [eax+0x14],ecx
660336: 8b 0d d4 5b f9 00     mov ecx,ds:[0xf95bd4]
660340: 8b 11                 mov edx,[ecx]
660342: 8b 82 5c 01 00 00     mov eax,[edx+0x15c]
660348: 56                    push esi
660349: ff d0                 call eax
```

已確認事件型別 writer：僅 `event+0x10=F42EF`；事件 payload `event+0x14` 來自 `producer_receiver+0x1A8`。條件有本地類型 `0x578`、比較 `incoming+0x8` 與 `receiver+0x164->+0x20`，`0x641` 走另一條本地方法 `0x660370`。`0x578/0x641` 是傳入物件欄位，**不可叫 wire opcode**。配發失敗時傳送參數為零的情形仍有條件分支，函式尾有 event release 虛擬呼叫。

### 1.3 生產者 B — 0x673DA0 另一事件路徑

```asm
673dc6: 8b 45 08              mov eax,[ebp+0x8]
673dc9: 8b 48 10              mov ecx,[eax+0x10]
673dcc: 81 f9 78 05 00 00     cmp ecx,0x578
673dd2: 0f 85 ea 00 00 00     jne 0x673ec2
673dde: 8b 49 20              mov ecx,[[esi+0xc0]+0x20]
673de1: 8b 40 08              mov eax,[eax+0x8]
673de4: 3b c1                 cmp eax,ecx
673de6: 0f 85 a1 00 00 00     jne 0x673e8d
673dec: 6a 18                 push 0x18
673dee: e8 75 d4 21 00        call 0x891268
673dfd: 8b b6 d8 00 00 00     mov esi,[esi+0xd8]
673e03: 89 70 14              mov [eax+0x14],esi
673e13: c7 40 10 ef 42 0f 00  mov [eax+0x10],0xf42ef
673e1a: c7 00 ac 67 c4 00     mov [eax],0xc467ac
673e52: 8b 0d d4 5b f9 00     mov ecx,ds:[0xf95bd4]
673e5c: 8b 11                 mov edx,[ecx]
673e5e: 8b 82 5c 01 00 00     mov eax,[edx+0x15c]
673e64: 56                    push esi
673e65: ff d0                 call eax
673e8d: 8b 8e dc 00 00 00     mov ecx,[esi+0xdc]
673e93: 3b 41 20              cmp eax,[ecx+0x20]
673e9c: e8 df 07 da ff        call 0x414680
673ea9: 52                    push edx
673eaa: e8 d1 fc e2 ff        call 0x4a3b80
```

同為 `0x578` 本地事件輸入，但 B 從 `receiver+0xC0->+0x20` 比較，並把 `receiver+0xD8` 寫入 F42EF payload，而非 A 的 `+0x1A8`。另一比對支線則往 `0x4A3B80`，不能合併成同一 UI 狀態機結論。B 的 `0x387` 輸入另建 `F4247`（已見既有局部研究），故這是同一 producer 的多分支關係。

### 1.4 F42EF 下游 — 0x665150 角色記錄 gate

```asm
665186: 8b 15 f4 1d fe 00     mov edx,ds:[0xfe1df4]
66518c: 8b 42 0c              mov eax,[edx+0xc]
66518f: 2b 42 08              sub eax,[edx+0x8]
665194: c1 f8 03              sar eax,0x3
66519b: 8b 5a 08              mov ebx,[edx+0x8]
6651a0: 0f b6 32              movzx esi,BYTE PTR [edx]
6651a3: 3b 75 08              cmp esi,[ebp+0x8]
6651a9: 83 c2 08              add edx,0x8
6651e4: 8b 55 08              mov edx,[ebp+0x8]
6651e7: 83 fa 09              cmp edx,0x9
6651ec: 8b 0d 04 43 f9 00     mov ecx,ds:[0xf94304]
6651f4: 69 c0 10 02 00 00     imul eax,eax,0x210
6651fc: 8b 41 5c              mov eax,[ecx+0x5c]
66520e: 85 db                 test ebx,ebx
665210: 0f 84 9e 01 00 00     je 0x6653b4
665216: 85 c0                 test eax,eax
665218: 0f 84 96 01 00 00     je 0x6653b4
66521e: 89 97 10 01 00 00     mov [edi+0x110],edx
66522b: e8 70 f9 d9 ff        call 0x404ba0
```

此段是重大新進展：F42EF 不只存在 producer/consumer，還將 `event+0x14` 值傳入 `0x665150`，與先前由 command2 清單寫入的 `F94304+ID*0x210`／`record+0x5C` **可用條件**接合。`0x665150` 另外要求 `FE1DF4` 的 8-byte stride 結構能找到相同低位元組 ID，及後續 `+5C` 有效，兩者皆滿足時寫 `dialog+0x110` 並進入更深操作。這是原生 Client UI 狀態選擇 gate 的重要證據，**不是**官方 Server 已批准角色登入的證據。尚未核對 `0x665150` 整函式結尾的全部發包與 vtable，也未證實 full UI lifecycle。

## 2. 研究輪次及停止理由

- `LOGIN-01` 第一輪：完成原始 BIN literal 搜索，確認 **兩條獨立 F42EF writer → 全域虛擬投遞介面；另發現與先前 `5A67D0` 不同的 `5A69E0` F42EF consumer → `665150` → roster+5C gate**。第一輪已達 02 共用規範的「重大新發現／有界功能鏈」門檻，故結束本段。
- `LOGIN-01-2`、`LOGIN-01-3`：**未啟動**，原因為第一輪已找到新的 producer、consumer、關鍵 record gate 及原生組合關係；不是把困難當成跳段理由。
- 所有 E8 rel32 靜態掃描都可能有資料誤陽性；直接呼叫 `0x665150` 的候選 `0x5A6A28` 和 `0x59A520`，此處僅在 `0x5A6A28` 指令反組譯確認。其他 receiver handler 使用虛擬分派，不能拿直呼未命中當缺少 caller。

## 3. 本輪玩家情境矩陣

| 玩家或事件情境 | 本地條件 | C→S | S→C | Client 效果 | Server 責任 | 未解 |
|---|---|---|---|---|---|---|
| 收到原生角色清單後選角 UI 有可用記錄 | 舊已證 command2 record→+5C | 本段未重新驗證 | 舊已證 command2 roster 消費 | `record+5C=1` 可供選角 gate 使用 | 名單內容須有實際權威 | 真實名單／UI 資源及事件投遞時序 |
| 本地 0x578 事件符合身分比較，產生 F42EF | producer A `+0x164->+0x20` 或 B `+0xC0->+0x20` | 未證明 | **0x578 不認定 wire opcode** | F42EF 事件及 `+0x14` payload 生成，經 virtual+15C 投遞 | 未知 | upstream 原始輸入／接收契約 |
| F42EF 到達 `5A69E0` | 事件方法回 `0x105B9` | 未證明 | F42EF 是本地事件 ID | `665150(payload)`；對照本地 8-byte 表與 roster+5C gate，再更新 dialog 欄位 | 不能推斷批准／拒絕政策 | 真正 UI 訂閱與後續 send/transition |
| 玩家點選後收到允許/拒絕 | 未定位操作→packet builder | 未定位 wire opcode/len/fields | 未定位配對 response | 未驗收 | 待相容設計 | UI callback→C→S→S→C→T05 完整鏈 |

## 4. 下一段定向入口

1. `0x665150` 自 `0x66521E` 後追到所有後繼，特別是 `dialog+0x110`、`0x404BA0` 及任何 packet builder/send；核對角色 UI 各成功／失敗／無名單分支。
2. 查 `0x5A69E0` 被何種 UI listener/vtable registration 認領；比較 `0x5A67D0` 的 switch 與獨立方法之間關係，避免只看 switch 就否認 F42EF。
3. A/B (`0x660260`、`0x673DA0`) 的上游註冊或間接 callback，`0x578/0x641/0x387` 型別與 `+8` 身分由來；保留可能是本地 GUI 事件而非封包。
4. 沿歷史 `42` 的 4-byte 選角請求回查確切 UI callchain → T02 send queue；S→C response 不猜 `43/69`。
5. T04 驗 roster 權威；T05 驗轉場；T06 驗 dialog 訂閱與資源存在；不修改其他 Task 內容。

## 5. 反證與界線

- 既有報告「F42EF 不在 `0x5A67D0` switch」仍正確，但不等於沒有 consumer。本輪新增 `0x5A69E0` 獨立函式，因此解除更廣泛的缺口。
- `.text` 搜索值三次命中是 literal 交叉引用，不證明全部動態分派；名稱、物件正式 C++ 型別、wire opcode 與網路事件來源仍待查。
- 只觀察 Client 靜態碼：無原版 Server、runtime、封包擷取，不能聲稱已進入世界或選角玩法已驗收。
- GitHub 本研究未 Commit／Push；同步 Merge 的 SHA 與研究原稿是兩件不同的交付。