# E72 — RR-0010 KR 建角交易補證：次級分派表、另一條 53B record writer 與 0x33 非專用 ACK 界線

> chatgpt-web roy｜2026-10-31 Asia/Taipei｜repo `we88ec3-prog/ttr_anal_multi`｜工作分支 `extra/roy1`。本件延續 [E71](20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md)，不覆蓋 E71。KR `Tartaros.bin` **12,472,320B**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。均從本次可用原件唯讀核對。`.text` VA `00401000` raw `00000400`；`.rdata` VA `00BD2000` raw `007D0600`，以實際 PE header 驗證。**未執行 Client、未取得原版 Server 原始封包。**

## 0. 應回答的 RR-0010 與本次結果

本 RR 目標是「非選角 0x42」的建角 C→S 來源、S→C 接受或拒絕、名稱/初值/slot、連線/字元編碼、後續 roster 與失敗重試。E71 只查得 `CEmployNewCharacter` event → 可發固定 **`33 00` 2-byte application payload**；此 payload **沒有姓名、屬性或外觀欄位**，不能作為可配置新玩家角色的正向證據。E72 新增以下 **原始 BIN 可重現界線**：

1. **另一張 Client 本地命令表**在 `004E1DA0..004E23D0` 初始化：共 `0xBD5` 個 8B 槽位、預設 handler `004B7D40`，97 個直接覆寫；本表 index `0x33` 的 handler 位置 `base+0x19C` **未在此 initializer 被直接覆寫**，但 index `0x2B` 被設定至 `004E2730`。此處的 **index 不等於已確認的 wire opcode**。預設 `004B7D40` 尾跳到物件 vtable `+0xC`，因此不能叫「無 handler」，也不能叫「0x33 ACK」。
2. `004E2730` 是一條**與 S→C command2 roster 不同的 53-byte record consumer**：長度至少2，按 `(len−2)/53` 計數，row 起點`buffer+2`，每 row 檢查 byte `+0x2E <=9`，目的為 `[client+0x6924] + slot*0x210`，以 `004D4150` 複製，再 `004E5FB0` 後處理。它與 command2 `(len−65)/53`、row at `buffer+65`、目的全域 `[F94304]` **不是同一個封包/物件來源**。共同 writer 不能替代建角成功回覆的時序證明。
3. 兩條 record consumer 使用的 `004D4150` 在 `004D4160..004D416E` 以 16-bit NUL 判斷逐 `WORD` 複製，**迴圈中沒有依 53B row 長度或目的緩衝大小限界**；後續讀 row `+0x2A,+0x2E,+0x2F,+0x30,+0x31`。相容 Server/測試至少要提供位於 `row[0..0x29]` 內、偶數位移的 UTF-16LE NUL；這是 **Client 輸入安全前置**，不是官方名字政策、字碼頁或正式建角 C→S 規格。

**結果**：新增 33 項原始 BIN byte/表槽位/函式資料流檢查全部 PASS；仍未有真實 `create C→S → matching S→C accept/reject → roster/UI` 正向閉合。正式 RR-0010 在最新 `main` 已是 `BLOCKED`，本補證**不得改成 SUBMITTED / ACCEPTED / FULL-PASS**。S00 可使用這些有限 Client 契約與反例修訂 DRAFT，但不得宣稱建立角色成功已恢復。

## 1. 分派表 A：全域 app 入口與 active-scene fallback（承接 E71）

- `004B7DC0`: 由 `FD2D00` 起填預設 `004B7EC0`，相鄰欄位寫 `BF2375`。其中 `S→C app2` 直接覆寫地址 `FD2D0C` → `004B7F00`；app`0x33` 的 handler 槽位是 `FD2CFC + 0x33*8 = FD2E94`。
- `004B7DC0..004B7EBF` 中沒有寫 `FD2E94` 的 **直接絕對位址 registration**；不排除後續動態覆寫及其他 domain。
- `004B7EC3` 查 `[ecx+0x5EAC]` active scene；非 NULL 時 `004B7ED2..D8` 經 scene vtable `+4` **tail jump**，NULL 走診斷/返回。這是一條 fallback 委派鏈，而不是 0x33 已正向確認的成功回覆。

```asm
4B7DC0 mov eax,0xFD2D00
4B7DC5 mov edx,0x004B7EC0
4B7DD0 mov [eax-4],edx
4B7DD5 add eax,8
4B7DDF mov dword [0xFD2D0C],0x004B7F00
4B7EC3 cmp dword [ecx+0x5EAC],0
4B7ECC mov ecx,[ecx+0x5EAC]
4B7ED4 mov eax,[eax+4]
4B7ED8 jmp eax
```

## 2. 分派表 B：另一個 `0xBD5 × 8` 的 owner/場景物件表（E72 新證）

`004E1DA0` 使用 `EDX=EAX+8`，從 `EDX-4` 開始填 handler；所以 index `i` 的 **handler 偏移為 `4+8*i`**，第二欄在 `8+8*i`。由原始指令解出：

```asm
4E1DA0 push esi
4E1DA1 lea edx,[eax+8]
4E1DA4 mov esi,0xBD5
4E1DA9 mov ecx,0x00BF2375
4E1DB0 mov dword [edx-4],0x004B7D40
4E1DB7 mov [edx],ecx
4E1DB9 add edx,8
4E1DBC dec esi
4E1DBD jne 0x004E1DB0
4E1E2F mov dword [eax+0x33C],0x004E2710 ; index 0x67
4E1E3F mov dword [eax+0x15C],0x004E2730 ; index 0x2B
...
4E23D0 ret
4B7D40 mov eax,[ecx]
4B7D42 jmp dword [eax+0xC]
```

依 `C7 80 disp32 imm32` 且 handler 指向 `.text` 的指令邊界解析，本 initializer **97 個直接覆寫**；沒有 `disp32=0x19C` 的項目。對 index `0x33` 的受限結論：**本 initializer 仍為預設 vtable fallback**；但其他 handler 登錄、物件型別、到達來源與 wire opcode 尚須串接。**不要將 index `0x2B` 說成建角 request/result**，它只錨定下節另一條 copy routine。

## 3. 第二個角色記錄 writer（E72 新證）

`004E2730` 使用 `len` (`[ebp+0xC]`) 和 `buffer` (`[ebp+0x8]`)：若 `len <2`，N=0；否則採編譯器 reciprocal multiplication 求 `floor((len-2)/53)`；row 為 `buffer+2+k*53`。只有 `row[0x2E] <=9` 且目的 pointer 非空才呼叫 `004D4150`。不論零筆或多筆，在 `004E2794` 呼叫 `004E5FB0`。

```asm
4E273D cmp eax,2
4E2746 lea ecx,[eax-2]
4E2749 mov eax,0x3521CFB3
4E2756 shr ecx,5
4E2759 test ecx,ecx
4E275B je 0x004E2792
4E275F mov edi,[ebp+8]
4E2762 add edi,2
4E2767 movzx eax,byte [edi+0x2E]
4E276B cmp eax,9
4E2770 imul eax,eax,0x210
4E2776 add eax,[esi+0x6924]
4E277E mov edx,edi
4E2782 call 0x004D4150
4E278A add edi,0x35
4E2794 call 0x004E5FB0
```

獨立對照 `004B8920..004B8A9C`：`len >=65` / `(len−65)/53`；`EDI=buffer+0x6F`，傳 `EDX=EDI-0x2E=buffer+0x41`；用 `[0x00F94304]+slot*0x210` 而非 `[client+0x6924]`；`N=0` 跳共同 post，寫 `[F94240]` 後 `call 004E5FB0`。**兩種 53B layout 有不同 header/base/destination**。其中一條是既有 app2 清單，另一條為 local dispatch slot`0x2B`，但不能在未追完 Client ingress 時命名為建立角色回覆。

## 4. Shared writer 的 UTF-16 NUL 長度前置與反例

```asm
4D4151 lea edi,[esi+0x0C]
4D4154 mov dword [esi+0x5C],1
4D415B mov eax,edx
4D4160 movzx ecx,word [eax]
4D4163 mov word [edi+eax],cx     ; EDI 已減 EDX
4D4167 add eax,2
4D416A test cx,cx
4D416D jne 0x004D4160
4D416F movzx eax,byte [edx+0x2E]
4D4176 movzx ecx,byte [edx+0x2F]
4D4180 movzx eax,byte [edx+0x30]
4D418A mov ecx,[edx+0x31]
4D4190 mov edx,[edx+0x2A]
```

因 `0x2A` 起已有其他欄位，**安全的 53B 測試向量**應讓 name terminator 在 row offset `0x00,0x02,...,0x28` 其中之一（至多20個非 NUL UTF-16 code units）。否則迴圈可能繼續讀入其他欄位/下一筆而不做本地 bound check。這是「所檢視 in-loop 無界限」的原生證據，不是已觀察崩潰或官方名稱長度限制。角色名來源已是 UTF-16LE `WORD`，**不能據此推導建角 outbound 也一定是 UTF-16LE**。

## 5. 客戶端建角候選的分支加深（E71 補強）

`006BF2A0` 是 RTTI `CEmployNewCharacter` 的 UI event callback：`event+0x10==0x578`、`event+8==([this+0xD0]+0x20)` 才進分支；`Client+0x5F4C==1` 時 `0049B230` 取得 `FDF3C8` lazy object，`006BFAE0` 使用其内部 writer 保存 `double 1.0`、tag `3` 並呼叫 `006FEC70`/`006FB9A0`，接著其他本地 UI 呼叫；**不能將這段自動命名為 socket send**。`Client+0x5F4C!=1` 則 `00414680` 取得另一 global object，接著 `004A38D0` 只打包 `33 00` 2B app payload，無 name/appearance/slot。`0x33` **不是已證 Create Character opcode**。`CEmploy...` 也可能是遊戲內角色招募，僅 RTTI 字面不能決定遊戲帳號建角。

## 6. RR 驗收逐項／負面測試與外部解阻

| 驗收要求 | 本輪實證 | 狀態 |
|---|---|---|
| 真正建立角色 C→S producer + 姓名/外觀/slot/encoding | E71 候選 33/21/27 各有 native builder，但無 GUI `name` positive link；E72 mode1 分支是本地 object writer | **Client 待逆向** |
| 真正 S→C 建角接受/拒絕 | first-layer app0x33 → scene fallback；第二表 index0x33 仍 default vtable+0xC；無專用 ACK | **Client 待逆向** |
| 結果導致 roster/initialization | 已證兩個 53B data parser，來源與目的不同；沒有 request→result→哪一條 parser 的因果連結 | **跨功能待整合／Client 待逆向** |
| 名字與異常資料測試 | record row UTF-16LE terminator / +2A..+34 fields; len<2、len<65、N0、合法/非法 slot 分支 | **已證有限靜態邊界** |
| 成功/重名/已滿/重複/取消/斷線/retry | 缺原版 Server reply 與原版 Client runtime positive pairing | **待遊玩驗證／Server 待開發** |
| T01/S00 | 本報只供 R0–R2 限定審核；`GAP-CHAR-0003` 仍 OPEN，`SPEC-CHAR-0001`、`SPEC-FLOW-0001` 仍 DRAFT/不得 STABLE | **不可逕升級** |

**建議但非既存 Test ID**：`CREATE-NAME-ROW-TERMINATOR`（NUL within first42B）；`ROSTER-HEADER-65-2-SEPARATION`；`DISPATCH-LOCAL-0x33-FALLBACK`；`CREATE-REQUEST-NAME-TRACE`；`CREATE-S2C-ACCEPT-REJECT`；`CREATE-DUPLICATE-DISCONNECT-IDEMPOTENCE`。不得把此合成測試當原版封包證明。

**可解除阻塞的必要資料（由小到大）**：

1. **靜態 Client 正向鏈**：同版 KR GUI layout/字串輸入 control 屬性、其 callback→含欄位的 `vtable+0x10 send` builder，以及 matching scene/handler→specific record/UI writer，逐個排除間接 caller 和 scene table dynamic override。
2. **原版外部證據**：同 build 官方 Server 多 Conn key/marker 已解碼 capture，包括至少 create 成功、重名、角色數滿、重試/斷線時序，或可信的官方 Server handler/source。必須保留命令 domain、方向、frame、slot、body，不可用 `request+1` 推測。
3. **授權的原 Client 執行觀察**：只有使用者另行明確授權時才作；若對接自建 Server，僅能聲稱 *compatibility*，不能聲稱原版 Server 規則。

## 7. 可重現驗證與停止判定

```bash
sha256sum Tartaros.bin Tartaros.exe
python RR0010-E72-verify.py /path/to/Tartaros.bin
# 僅靜態反組譯 .text：
dd if=Tartaros.bin of=/tmp/rr10-text.bin bs=1 skip=1024 count=8192512
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4e1da0 --stop-address=0x4e23d1 /tmp/rr10-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4e2730 --stop-address=0x4e27a0 /tmp/rr10-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4d4150 --stop-address=0x4d419d /tmp/rr10-text.bin
```

`RR0010-E72-verify.py`：33項靜態 PASS；沒有執行原版 Client，也沒有證明成功建立新角色。**研究狀態維持 BLOCKED（已充分記錄的新/舊靜態搜尋邊界），未提交正式 RR SUBMITTED。** `RR-0002/RR-0007/RR-0008/RR-0009` 不更動；T03 既有 T01 `NEEDS_FIX` 不更動。新入口是解碼/連回 `004B7D40` scene vtable `+0xC`、`004E1DA0` default 呼叫者，以及真正建角 GUI name producer。