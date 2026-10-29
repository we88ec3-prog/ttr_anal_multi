# T03-LOGIN-02 — F42EF 後續 0x665150 完整 UI 選角資料填入與返回值差異

日期 2026-10-28 Asia/Taipei；研究者 chatgpt-web roy。範圍：KR 原始 BIN 唯讀、後續 UI 與發包邊界。此為本段完整取得證據之原稿，不宣稱選角封包閉環。

## 0. 來源與前段去重

- `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE32 i386，.text VA `0x401000` raw `0x400`，故 `.text` 中 `raw=VA−0x400c00`。使用 `objdump -D -Mintel --start-address=... --stop-address=...` 直接反組譯原始 BIN；未執行 Client。
- 前段 T03-LOGIN-01（`20261028-203031-chatgpt-web-roy-T03-LOGIN-01-F42EF-native-event-chain.md`）已證 F42EF writer 0x660260 / 0x673DA0、consumer 0x5A69E0、其對 0x665150 的呼叫及 `FE1DF4` list、`F94304+ID*0x210` record+5C gate；本段不將該部分重複列為新發現。
- GitHub T03 README、task.json 既有角色清單 command2 → 53-byte records →+5C、`672F00` 舊 UI gate 為已審核的有限成果；本段為靜態 BIN-first 深入，不把任何 event ID 認成 wire opcode。

## 1. 第 1 輪：665150 成功與失敗 CFG（原始 x86）

函式體 `0x665150..0x6653D9`，返 `ret 4`，參數 `[ebp+8]` 為候選 ID；`EDI` 在呼叫前由 caller 設為 UI dialog 物件。直接 caller `0x5A6A28` / `0x59A520` 均已獨立反組譯核對。

```asm
665186  mov edx, [0xfe1df4]
66518c  mov eax, [edx+0xc]
66518f  sub eax, [edx+0x8]
665194  sar eax, 3
66519b  mov ebx, [edx+0x8]
6651a0  movzx esi, byte ptr [edx]
6651a3  cmp esi, [ebp+8]
6651a6  je 665207
6651a9  add edx, 8
6651b2  test byte ptr [0xf94390],1
6651bb  or dword ptr [0xf94390],1
6651ca  call 0x4e1590
6651e4  mov edx,[ebp+8]
6651e7  cmp edx,9
6651ea  ja 66520c
6651ec  mov ecx,[0xf94304]
6651f4  imul eax,eax,0x210
6651fa  add ecx,eax
6651fc  mov eax,[ecx+0x5c]
6651ff  neg eax
665201  sbb eax,eax
665203  and eax,ecx
66520e  test ebx,ebx
665210  je 6653b4
665216  test eax,eax
665218  je 6653b4
66521e  mov [edi+0x110],edx
```

**確認**：需候選 ID 在 `FE1DF4` 的 8-byte stride 表中匹配，且 `ID<=9` 並能從 `F94304+ID*0x210` 找到 `+0x5C!=0`；否則跳過 UI 資料填入，走 `0x6653B4`。特別注意 `0x6651B2` 的 lazy initialization (`F94390` bit0、call 4E1590) 使「空表」與「未初始化」不可直接混同。若找到列表 ID，但 record 尚未可用，函式末端仍回 1；返回值代表 list 命中，而非完整 UI 資料填入成功。

### 1.1 通過 gate 之後：UI 多欄位填入

```asm
66521e  mov [edi+0x110],edx
665224  mov edx,[ebx+4]
665227  mov [esp+0x10],edx
66522b  call 0x404ba0
665230  mov edx,[edi+0xf4]
665236  mov eax,[eax+0x6864]
66523c  movzx ecx,byte ptr [ebx+1]
66524c  call 0x7597b0
665251  mov cl,byte ptr [ebx+1]
665258  call 0x662800
665265  mov esi,[edi+0xf8]
665272  call 0x757800
665293  mov cx,word ptr [ebx+2]
66529b  call 0x665560
6652a8  mov esi,[edi+0xfc]
6652b5  call 0x757800
6652d6  mov ecx,[esp+0x10]
6652de  call 0x412df0
6652f7  mov esi,[edi+0x100]
665303  call 0x757710
665324  mov ecx,[esp+0x14]
66532c  call 0x412df0
665345  mov esi,[edi+0x104]
665351  call 0x757710
665372  mov ecx,[edi+0x108]
66537a  mov eax,[eax+0x90]
66538b  cmp [esp+0x10],edx
665397  setle dl
66539d  push edx
6653a6  call eax
6653a8  mov edx,[edi]
6653aa  mov eax,[edx+0xc8]
6653b2  call eax
6653b4  xor eax,eax
6653b6  test ebx,ebx
6653b8  setne al
6653d7  ret 4
```

**新增有界結論**：`0x665150` 是選角 detail dialog 的**本地多控件資料填入函式**，不是已驗證的選角 C→S producer。來自 `FE1DF4` 表項的 `+1 byte`、`+2 word`、`+4 dword` 分別進 UI 資料顯示轉換；`dialog+0xF4`、`+0xF8`、`+0xFC`、`+0x100`、`+0x104`、`+0x108` 是控件/相關物件指標的使用位置，不得未查 T06 資源便直接命名具體 UI 控件。最後 `dialog virtual+0xC8` 被呼叫。`0x665372..0x6653A6` 使用 `[esp+0x10] <= [esp+0x14]` 形成布林值傳給 `dialog+0x108` 指向物件的 `virtual+0x90`；該比較的業務含義未知。

### 1.2 直接 caller 的重要差異

```asm
59a515 mov eax,[eax+0x14]
59a519 mov edi,[ebx+0x1d4]
59a520 call 665150
59a526 test eax,eax
59a528 je 59a53a
59a52a mov ecx,[ebx+0x1d4]
59a532 mov eax,[edx+0xd0]
59a538 call eax

5a6a1d mov eax,[eax+0x14]
5a6a21 mov edi,[ebx+0x13c]
5a6a28 call 665150
5a6a2d mov ecx,[ebx+0x13c]
5a6a35 mov eax,[edx+0xd0]
5a6a3b call eax
```

**新差異**：`0x59A520` 的 caller **以 665150 非零 return gate** 控制後續 UI virtual +D0；`0x5A6A28` 的 caller **無條件**呼叫 dialog virtual +D0（在 F42EF type check 通過後）。因此即使未找到角色 ID，兩條 GUI 更新路徑在通知觸發條件上不同。該差異不等於 Server 拒絕或成功；需要 GUI listener 與 T06 的控件資料補證。

### 1.3 `0x665560` 不是網路建包

```asm
665570 push 0xa
665572 push 0x7
665577 movzx ecx,cx
66557c mov dword ptr [ebp-0x18],0
665583 call 0x89243a
66558d mov dword ptr [esi+0x14],7
665594 mov dword ptr [esi+0x10],0
66559e mov word ptr [esi],dx
6655aa test cx,cx
6655b3 push eax
6655ba call 0x402160
6655ce ret
```

此 helper 將 `CX` 的無符號整數經 formatting helper `0x89243A` 轉成文字並寫入 `ESI` 所指 string-like 物件；它在 `0x665293` 取 `word [ebx+2]` 後被呼叫，因此只是 UI 字串格式化證據。不能把 `0x7/0xA` 當作 packet opcode 或資料長度。

## 2. 三輪深入評定

- `LOGIN-02` 第 1 輪：由第一手 x86 完成 `0x665150` 從兩層 gate、5 組資料 UI setter、format helper、虛擬通知到返回值分支的有界功能鏈；並辨明兩個 caller 對返回值的**實質不同**處理，已達重大新增功能鏈門檻。
- `LOGIN-02-2`：未啟動，第一輪已有完整有界 UI 填入鏈及已證 caller 差異。
- `LOGIN-02-3`：未啟動，同上。此處不聲稱選角網路鏈完成，下一段應轉向真正按鈕回調與 42 request 封包。

## 3. 玩家情境與缺口矩陣

| 情境 | Client 條件 | C→S | S→C | Client 結果 | Server 未知/待開發 | 尚未確認 |
|---|---|---|---|---|---|---|
| UI 收到 F42EF | 本地事件類型、payload ID | 未證明有發送 | F42EF 不是已證 wire opcode | `5A69E0→665150→dialog virtual+D0` | 名單資料權威仍未知 | F42EF listener 投遞時序 |
| 候選 ID 在本地表且 record +5C 可用 | `ID<=9`、8-byte 表命中、record+5C 非零 | 未證明有發送 | 無新增證據 | dialog+110 保存 ID，控件 F4..108 更新、virtual+C8 | 角色選擇批准規則未知 | 真實 UI 控件資源與文義 |
| ID 在本地表但 record +5C 不可用 | 8-byte 表命中、record gate 為零 | 未證明有發送 | 無新增證據 | 不填入欄位；`665150` 仍可能返回 1 | 未知 | `0x59A4xx` 的後續 UI 通知條件 |
| ID 不在本地表 | `EBX=0` | 未證明有發送 | 無新增證據 | `665150` 返回 0；`59A520` 不呼叫 +D0；`5A6A28` 仍呼叫 +D0 | 未知 | 各事件源的真正 GUI 身份 |
| 玩家確認角色 | 未追至按鈕 callback | 未定位 wire opcode/len/fields | 未定位 response handler | 轉場未知 | 相容 Server 必須依後續證據設計 | T02/T05 界線 |

## 4. 排除、限制、下一入口

1. `0x665150` 全程所見是 `dialog/UI` setter、string processing 和 virtual+0xC8；**在此函式內沒有直接證明發送 packet**，這不排除 UI click callback 在別處發包。
2. `0x59A520` 與 `0x5A6A28` 都由 `event+0x14` 取 ID，但 dialog owner 位置不同（`+0x1D4` vs `+0x13C`），不可合併成單一控制器類型。
3. `+0xF4..+0x108` 真正控件名稱與生命週期歸 T06；`+0x4` 表項 payload 與真正業務名需更多 xref；`0x665372` 比較的業務含義仍未知。
4. 下一入口：追角色選中確認按鈕 virtual callback → 既有 command `42` 四位元組請求 → T02 封包送出；再從 dispatcher 查 S→C 回覆與 T05 轉場；不能將本地 fixture `42→43/69` 視為原版規格。
5. 不執行原始程式、無動態封包、無官方 Server；僅靜態 KR Client 的有界結論。GitHub 提交應為兩段完整原稿，而非僅摘要；本檔應保持完整不削減。