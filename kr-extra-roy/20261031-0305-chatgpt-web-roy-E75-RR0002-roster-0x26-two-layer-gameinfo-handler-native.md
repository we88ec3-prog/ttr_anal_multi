# E75 — KR RR-0002：角色名單後 `C→S 0x0026` 的第二層 `CGameInfo` S→C 處理鏈，5-byte record 與 `F4261` 事件

> 2026-10-31 03:05 Asia/Taipei｜chatgpt-web roy｜跨 Task 研究分支 `extra/roy1`｜接續 E61–E68 及 E74 的新原生查核，**不覆寫前稿**。原件 `Tartaros.bin` 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，原件 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`（本稿限定驗證器僅核 BIN）。PE32/x86 ImageBase `0x400000`，`.text` VA `0x401000` raw `0x400`。原始 BIN 以**唯讀方式**驗證，未執行 Client、未連官方 Server、未抓官方封包、未更改原件。61 項分支、函式呼叫、位元組、RTTI、表槽及原始哈希斷言全部 PASS；這不是 T01 FULL-PASS／原版交易實測。

## 0. RR 台帳與本次研究定位

查核 GitHub `main` `afc0b1fe661796912a59250bb1968ae48c727843`：共有 RR-0001～RR-0010 十項，**無 QUEUED 可重新認領**；RR-0005 `ACCEPTED`；RR-0001/0003/0004/0006/0007/0008 `IN_REVIEW`；RR-0009 `SUBMITTED`；**RR-0002 與 RR-0010 `BLOCKED`**。RR-0002 的既有 `claim.actor=chatgpt-web roy`、`claim.branch=extra/roy1`，本次使用者要求繼續其他 RR 並上 Git，因此在此原有已認領研究分支**補充新的來源級證據**；依 `research/dispatch/README.md`，S00 須先將 `BLOCKED` 重派為 `QUEUED` 才能啟動新的正式 RR 狀態鏈。**本稿不假冒重新認領、SUBMITTED 或 ACCEPTED，亦不改 main 台帳。**

使用者本次明確指定 RR 工作，故 T03 README 原有 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX` 暫緩；此問題是另一條 T01 修復流程，不聲稱修復。

本輪研究從新近 E74 得到的 `S→C app2` 角色清單逐角色發出 `C→S app 0x0026`（3 bytes、queue slot0）、清單結尾發 `C→S app 0x0024`（2 bytes）出發，向反方向查證 **S→C 0x0026** 是否真的有接收者及可提供何種角色初始化資料。不得僅按相同 opcode 推成官方 request–reply，更不得把此鏈混作 **C→S 0x0042 既有角色選角**的確認回覆。

## 1. 角色名單實際送出 0x26/0x24 的限定前提（復核 E61／E74）

`0x4B7F00` 是 incoming `app2` handler；`0x4B8923..4B8A16` 在有足夠 `65+53N` 資料時遍歷 53-byte role record。每筆 `0x4B89DC mov edx,0x26`，於 `0x4B89E6` 放入 row+0x2E 的 BYTE；`0x4B89F7 push 3`、`0x4B89FE push 0`，透過 manager vtable+0x10 發 `26 00 <roleByte>` **內層 app**。此處 `FBA798!=0` 會跳過發送。結尾 `0x4B8AC4 mov ecx,0x24`、`0x4B8ADB push 2` 及 queue slot0 發 `24 00`（同受 gate），即使 N=0 仍可經此路徑。**這只是發送入口，不證 Server 收到，也不證另一個相同 opcode 的 S2C 必然是對它的回覆。**

## 2. 原生 S→C app 0x0026：基底 scene table 正向註冊

`0x4ADD50..` 初始化 `0xBD5` 個 stride8 handler 槽位，預設是 `0x4B7D40`（tail `jmp vtable+0xC`）。該 initializer 有精確覆寫：

```asm
4ADEED C7 80 34 01 00 00 60 30 4B 00  mov dword [eax+0x134],0x4B3060
```

基底槽位公式 `4+8*index`，故 `(0x134-4)/8=0x26`，真實 `S→C app index 0x26` **先到 `0x4B3060`**。在 `0x4ADD50..0x4AE380` 的本次 `C7 80 disp32 handler32` 逐項枚舉中，index `0x24` 沒有**直接覆寫**；這是**此 initializer 此種 opcode 形式的陰性結果**，不是證明 `S→C 0x0024` 絕對沒有 handler（可能 scene/virtual fallback/其它註冊）。

`0x4B3060` 並不直接讀出角色資料，而是另一層物件轉接：

```asm
4B3063 call 0x40F060             ; 取 singleton holder
4B3068 mov edx,[ebp+0x10]       ; 入站第 3 參數
4B306B mov ecx,[eax]            ; holder->object
4B306D mov eax,[ecx]            ; object->vptr
4B306F mov eax,[eax+4]          ; slot1
4B3072 push edx
4B3073 mov edx,[ebp+0x0C]
4B3076 push edx
4B3077 mov edx,[ebp+8]
4B307A push edx
4B307B call eax
4B307D xor eax,eax
4B3080 ret 0xC
```

**關鍵：**`0x4B3060` wrapper 無本地 payload parser，從 caller 得到 `(payload*, len, commandIndex)` 三個參數，虛擬呼叫後將外層回傳值重設為 0。只檢查這個 wrapper 很容易誤以為 S2C0x26 沒有行為；必須接著查 singleton 的實際 vptr 和第二層表。

## 3. `CGameInfo` 真實 owner / RTTI、第二層 index0x26 → `0x4DE020`

`0x40F060` 是從 `[0xFA B22C]` gate 懶初始化，返回**地址** `0xFAB130`；`0x4DEC90` 建立約 `0x5F24` bytes 的物件並於 `0x4DECDD..0x4DECE3` 存至 `[0xFAB130]`。它直接呼叫 `0x4DD700` ctor，後者 `0x4DD702` 寫 `vptr=0xC0CEA0`。MSVC RTTI 完整結構：

| 項目 | BIN 有界來源 |
|---|---|
| vptr | `0xC0CEA0` |
| `vptr[-1]` COL | `0xC6AE2C` |
| TypeDescriptor | `0xF7E8E0`，字串 `.?AVCGameInfo@@` |
| virtual slot1 | `[0xC0CEA0+4] = 0x4FDA30` |
| virtual slot3 | `[0xC0CEA0+0xC] = 0x4227F0`，記錄錯誤並回 `0x80004005` |

`0x4DD7A1` 的直接呼叫進 `0x4DD8F0`，後者填 `0xBD5 × 8` 個 handler/cookie 槽位，預設 `0x4B7D40`，並有精確第二層覆寫：

```asm
4DD8F1  lea eax,[ecx+8]
4DD8F4  mov edx,0xBD5
4DD900  mov dword [eax-4],0x4B7D40
4DD907  mov [eax],esi          ; cookie = BF2375
...
4DD963  C7 81 34 01 00 00 20 E0 4D 00
        mov dword [ecx+0x134],0x4DE020
```

`0x4FDA30` 處理第三參數的低 WORD：`4FDA3B movsx edi,cx`，在 `4FDA3E` 查 `[this+edi*8+4]` callback；非 NULL 在 `0x4FDA85..0x4FDA8A` 轉傳三參數，並對返回 `0x80004005` 做額外診斷；NULL fallback 走物件 `vtable+0xC`（目前 CGameInfo 是 `0x4227F0`）。所以 **base scene app 0x26 → `0x4B3060` → `CGameInfo::vslot1@0x4FDA30` → 二層表 index0x26 → `0x4DE020`** 是由原件 RTTI＋ctor table、native calls 正向支持的條件式 Client 處理鏈，不是以 opcode+1 推測。

必要前提：該場景基底分派有效；`0xFAB130` 已初始化、`CGameInfo` vptr 仍為所查版本、指派 index 為 `0x26`、各層表尚未被動態覆寫。當前證據不能宣稱所有場景/狀態一定採用這張表。

## 4. `0x4DE020` 實際資料結構與 local F4261

`0x4DE020` 使用 `[ebp+0xC]` **application payload length**：`0x4DE048 cmp eax,4`，若 `<4` 令 count0；否則 `0x4DE051..5B` 以 `0xCCCCCCCD` reciprocal 和 `shr edx,2` 算 `floor((len−4)/5)`。實際資料列：

```asm
4DE091 mov esi,[ebp+8]          ; incoming app payload
4DE094 add esi,4                ; row0 = payload+4
4DE0A0 mov eax,esi              ; row source
4DE0A2 call 0x4DE9C0            ; append/copy 5-byte record
4DE0A7 add esi,5
4DE0AA dec ebx
4DE0AB jne 4DE0A0
4DE0DD push 0xF4261             ; LOCAL event code (not wire)
4DE0E2 call 0x58AAD0            ; enqueue local notification
```

目的容器由 `CGameInfo+0x5ED8/+0x5EDC/+0x5EE0` 三個 pointer 位置參與處理；`0x4DE9C0` 的入列支路在 `0x4DE9FA..4DEA04` 複製一個 DWORD + 一個 BYTE，並把 destination end pointer 推進 `+5`。這說明 **S2C0x26 的資料主體是 4-byte prefix + 5*N records**（只能證 consumer 的 count、讀取來源，不能宣告原版 Server 實際完整封包、header+2/+3 或每 5-byte 的正式欄位名稱）。對照 E74 的 `C2S0x26` 是 **3-byte**，明確不是同 shape。

`0x4DE0DD` 不論 count 是否零都可能走本地 `F4261` 通知；`0x5DE800` 另外有一個 RTTI/類別相關方法直接返回 `F4261`，證明該常量至少被用於 **Client local event domain**，不是網路 `0xF4261` opcode。此研究尚未將 F4261 的 subscriber 完整追到 UI 可點擊或選角 ready，故**不能稱這份資料是選角批准**。

### 反例／異常分流（只對本次 handler）

- `len<4`：不執行 5-byte row loop；但本函式仍可走本地 `F4261`，不可說已拒絕整筆 frame。
- `len=4+5N+r (0<r<5)`：僅遍歷 N 筆，不代表 trailing bytes 已有完整記錄。未找到此處對 `r` 的明確錯誤結果。
- 物件沒有初始化或 handler 表有覆寫：本次靜態鏈的正向前提不成立；需另查動態設定，不能以空指標推定安全行為。
- 第三參數若不等於 `0x26`：CGameInfo 第二層使用 **實際第三參數**索引，不保證走 `0x4DE020`。
- `C2S0x26` 的發送 guard `FBA798!=0`：即使 roster 已寫入，也可能沒有送出該應用請求。
- 接受 `S2C0x26`：即使完成這條有界本地 handler，也沒有在此函式直接呼叫 `0x4A3B80` 選角 builder、`0x565720` 場景載入或 `app2` 的 53-byte 角色 record writer；不能把兩種不同 record 佈局混為同一表。

## 5. 對 RR-0002、RR-0010、S00 的精確交付與狀態

| 問題 | 本輪可用有限證據 | 仍必須保留的未知 |
| --- | --- | --- |
| RR-0002 roster→角色細節→選角 | app2 後逐 role `C2S26`；base scene S2C26→`CGameInfo` indexed handler→5B record writer→local F4261；C2S42 已是另一個 4B request | **S2C26 是否回覆前一筆 C2S26；F4261 是否使角色可選；C2S42 的真正批准/拒絕 S2C 和場景切換仍未證** |
| RR-0010 expedition naming | E73／E74 `C2S3E`、候選 `S2C4A`、app2 共享 name field，以及本次 roster 之後新 26 receive branch | `3E→4A→app2→26` 的真實官方 wire 時序與「新增 playable character」仍不成立 |
| S00 Server 開發 | DRAFT 可記錄 `C2S26` 每筆 3B、`S2C26` Client 有界解析 4+5N 及本地 F4261、`C2S24` 結尾 2B | 不能在 SPEC 宣稱已證 original Server request↔reply、first-tutorial、合法業務 byte 值或官方角色授權策略 |

**四類未解項：**

1. **Client 待逆向**：F4261 local consumer、UI enable gate、C2S42 正負結果 native handler 與實際場景切換；另查第二層表動態覆寫及其它 scene 覆蓋，仍須繼續靜態研究。
2. **Server 待開發，交 S00**：角色與遠征隊資料權威、依 Client 已確認的收發形狀配置回覆內容、選角授權／拒絕／斷線重登策略，去重現有 REQ-0003/0004 與 `SLICE-CREATE` 候選。未證欄位以 UNKNOWN 記，不反推原版官方 Server 的實作。
3. **跨功能待整合**：T02 frame/conn key、T04 可操作角色資料、T06 UI 事件資源、T05/T07 場景後續、S00 SPEC-CHAR-0001/SPEC-FLOW-0001、GAP-CHAR-0001/0003、相關 TEST；各 owner 及 RR 狀態不動。
4. **待遊玩驗證**：另經授權的原版 Client＋隔離自製 Server 覆蓋 0/1/多角色、角色細節回覆、按鈕啟用、選角成功／拒絕／重試／切線，標為相容性測試，不能冒充官方 Server 歷史封包。

RR-0002 與 RR-0010 的核心 Server 交易配對仍無確證，**本輪只是新的 Client 靜態證據與 S00 分流，不是 RR `ACCEPTED`，也不能自動把 `BLOCKED`→`SUBMITTED`**。解除條件：S00 發布允許的重新派工；研究者補出 `F4261→UI` 與 `0x42` 真實 handler/狀態 writer；或取得同版本合法原版 trace/來源／獲授權的隔離兼容測試（後者僅證相容）。

## 6. 驗證與來源

```bash
sha256sum Tartaros.bin
python -B kr-extra-roy/20261031-chatgpt-web-roy-E75-RR0002-verify.py /path/to/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4dd8f0 --stop-address=0x4dd9a1 extracted-kr-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4de020 --stop-address=0x4de100 extracted-kr-text.bin
```

腳本僅驗證所列 **61 項**原始 SHA、機器碼、call target、RTTI/name、dispatch index、record 語意指令；不包含執行版 Client、封包實測、全域 alias/CFG 窮舉、T01 全文驗收。

**引用的既有交付（不覆寫／不重新宣告其全部已驗證）：** E61–E67（RR-0002）、E68（RR-0008）、E73–E74（RR-0010）；正式 GitHub `main` `research/requests/index.json`、`design/requirements/README.md`、`research/dispatch/README.md` 和 `governance/s00-workflow.md`。E75 新發現是兩層 table owner/handler 與 5B record/event 分析，不能拿它重複宣稱已完成選角的 Server 端正負交易。
