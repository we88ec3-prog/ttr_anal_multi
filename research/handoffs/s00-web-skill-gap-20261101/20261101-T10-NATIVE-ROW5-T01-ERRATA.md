# KR T10 — 000A Row5 與 T01 退回事項：原始 BIN 定向勘誤（2026-11-01）

> **性質：有限原生複核／階段性未完成。** 不覆蓋 T10-116 舊稿，不宣稱 T01 FULL-PASS，也不更新正式 Task owner、RR 或退回狀態。此檔可由 T01 逐項複驗，但 T10-116 所有 ABI／callback 的閉合要求尚未完全達成。

## 0. 來源、工具與版本

- GitHub main baseline：`ac6aac673426459df2a778d20a80c623b8559a92`；本次新對話依 T10 規則 `main → t10/roy/chatgpt-web` **fast-forward**，同步後 compare `behind=0,ahead=0`。
- 交接工作卡：`research/handoffs/s00-web-skill-gap-20261101/README.md`，blob `cdfed8f0f09086f175c842ebef22ad97d2fd7c9f`，來源分支 `codex/s00-web-skill-gap-20261101`；其 `baseline.json` blob `485f80d797bf9931b23eb0bfcf378dfa15de0f8f`。
- 舊稿 `kr-temp-roy/20261028-213248-chatgpt-web-roy-T10-116-KR-000A-five-byte-row-field-provenance.md`，blob `8da51d9e77d3d900bc73743bddc82891f6829c15`；T01 反證 `research/handoffs/t01-20261030-t10-canonical-continuation/20261030-163408-chatgpt-web-roy-T01-T10-116-118-R1-R2-canonical-review.md`，blob `91a0ba540e79eafd0142e57c6461d5e7b24fa474`；退回權威 `kr/tasks/T10/README.md` blob `a409f168e9a67ae1cf6ba76393aad08a9caf37ad`。
- **本輪實際讀到** KR `Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 工具：Linux `llvm-objdump` LLVM 17.0.0、Python `hashlib`；唯讀離線 disassemble／byte window hash。PE32 .text VA `401000`、raw `400`，`raw = VA - 400C00`。沒有啟動／修改 Client 或接觸真實封包、原版 Server；下列 0xFE* 全域的 runtime 值不可從原始檔直接讀出。

## 1. Row B：T01 確定反證及更正後 branch matrix

共同前置：`5459B7..545A4E` 由 `owner+30` 8-byte stride 取 WORD，在 `FAB13C` tree 查 payload `R`；node 非法／payload null 不 append。後續 `owner::vtable+44` 以 row+2 WORD、R 與 local 指標作判定。

```asm
545A54 8B 86 E0 00 00 00    mov eax,[esi+E0]
545A63 89 44 24 2C          mov [esp+2C],eax
545A67 8A 8E E4 00 00 00    mov cl,[esi+E4]
545A70 88 4C 24 30          mov [esp+30],cl       ; 初始 R+E4
545A78 8A 9E B0 00 00 00    mov bl,[esi+B0]       ; 另一 byte snapshot
545A97 FF D2                call owner::virtual+44
545A99 85 C0                test eax,eax
545A9D 83 7F 58 00          cmp dword [edi+58],0
545AA1 74 33                je 545AD6             ; return!=0 && owner+58==0
545AB7 66 85 47 6A          test word [edi+6A],8000h
545ABB 74 5D                je 545B1A             ; return==0 fallback 失敗
545AC8 88 5C 24 30          mov [esp+30],bl       ; 僅經 virtual+58 的支路
545AD4 FF D2                call R::virtual+58
545ADB 8A 4C 24 30          mov cl,[esp+30]
545AEB 66 8B 56 04          mov dx,[esi+4]
545AF4 66 89 54 24 2C       mov [esp+2C],dx
545B0E 89 10                mov [eax],edx
545B10 88 48 04             mov [eax+4],cl
```

| virtual+44 return | owner+58 | owner+6A bit15 | 通往 append | row[4] 的**直接 local 來源** |
|---|---|---|---|---|
| 非零 | 0 | 無關 | 是（還須 lookup、容量 gate） | `R+E4` snapshot，**跳過 AC8** |
| 非零 | 非零 | 無關 | 是（還須容量 gate） | `R+B0` snapshot，AC8 覆寫 |
| 0 | 0 | 無關 | 否 | 不產生 row |
| 0 | 非零 | 0 | 否 | 不產生 row |
| 0 | 非零 | 1 | 是（還須容量 gate） | `R+B0` snapshot，AC8 覆寫 |

因此舊 T10-116「A/B 皆固定 `u16(R+4)+u16(local-highWORD)+u8(R+B0)`」的 **Row B 無條件 B0** 敘述撤銷。row[0..1] 最後 `545AEB/F4` 由 R+4 覆寫；row[2..3] 仍是 local DWORD 高字，callback 可能影響；上表指直接 writer 路徑，不保證各虛實作的全部副作用。容量 `545AFC <= 1000h`；`545B38` 檢查總長 >6 才 `545B71` 推給 selector0。**C→S 000A 的 app payload 6+5N 及條件式發送**並不等於已驗證 Server ACK／連擊判定。

## 2. Row A：push 後 ESP 位置及 remaining gap

```asm
5458BB 8A 9E B0 00 00 00    mov bl,[esi+B0]
5458C4 8D 44 24 34          lea eax,[esp+34]
5458C8 50                   push eax
5458C9 57                   push edi
5458CA 88 5C 24 20          mov [esp+20],bl       ; push 後 ESP = S-8，目標 = S+18
5458CE FF D2                call owner::virtual+48
5458D0 84 C0                test al,al
5458D6 74 66                je 54593E
5458D8 83 78 58 00          cmp dword [eax+58],0
5458DC 74 1D                je 5458FB
5458E0 66 89 44 24 36       mov word [esp+36],ax ; 此支清 highWORD
5458E9 88 5C 24 38          mov [esp+38],bl       ; 此支才直接定義 row[4] local
5458F5 FF D2                call R::virtual+58
5458FB 8A 4C 24 38          mov cl,[esp+38]
54590D 66 8B 46 04          mov ax,[esi+4]
545911 66 89 44 24 34       mov [esp+34],ax
545932 88 48 04             mov [eax+4],cl
```

以 `S` 表示 `5458C8` 兩次 push **之前**的 ESP。若 owner::virtual+48 使用正常 `ret 8` 還原 stack，`5458CA` 的 `[esp+20]` 是 `[S+18]`，`5458FB` 的 `[esp+38]` 是 **`[S+38]`**，不可誤當同址。具體 tutorial vtable+48 `548D10` 跳往 `546100`，其正常尾端 `5464B3 = C2 08 00 (ret 8)`，可支持**這個實作**的 ABI；不將其泛化至全部控制器。

- virtual+48 回非零且 `owner+58 !=0`：可證 `5458E9` 明確保存 BL 到 `[S+38]`，再進 virtual+58；若實作無額外 stack 異常，row byte local 有直接 `R+B0` snapshot 來源。
- virtual+48 回非零且 `owner+58 ==0`：略過 `5458E9`，在已檢查的 `5452C0..54593E` 直接 store 範圍**未閉合 `[S+38]` 的最後 writer**。不能宣稱該支為 `R+B0`，也不能僅據此斷言運行時資料必未初始化。需補其他 virtual+48 的 ABI／out parameter 寫入、alias 和先前 def-use。
- virtual+48 回零：此支不走 Row A 直接 append；`owner+58 !=0` 且 `owner+6A bit15` 才能進 `54594F..54598B` 的 callback／`5471B0` 另一種 append，**不可直接等同本 Row A 直接寫入器**。
- highWORD：`545857` 只清 `[S+34]` 低 WORD；`5458E0` 僅在 +58 非零時清 `[S+36]` 高 WORD；其餘高字來源需逐一查所有真實 virtual writers，不能在表內固定為零或 skill ID。

## 3. 其它既有 T01 通知的本輪有限原生錨點

本輪重新核對下表原始位元組及邊界；**只作地址／有界分支勘誤，不聲稱各舊稿的完整 caller/CFG 均完成**：

| T01 退回 ID | 原生直接證據與正確更正 |
|---|---|
| `T10-055-EVIDENCE-001` | `6D4BAC c7 45 fc 04 00 00 00` 是完整指令，`6D4BB0` 落在其 immediate；`6D4D3E 8D 4D F0`，`6D4D40` 落在 LEA 的 immediate，真正 push 從 `6D4D41` 開始。錯位線性解碼不可作證據。 |
| `T10-056-EVIDENCE-001` | `59642E e9 7a 01 00 00`，`596430` 落在 JMP rel32；`59643F e8 9c e8 13 00` 是 CALL `6D4CE0`，`596444 83 f8 01` 是 cmp，不能用錯位假 call。 |
| `T10-062-001` | `6D4A95` test `FDF3EC` → `6D4A9C..6D4AC9` ordinary40-byte stores → `6D4ACE` 選擇 → `6D4AD9` 可選 call `6D1DA0` → `6D4AF3` call `823850`。禁止「特殊初始化先於普通清零」。 |
| `T10-063-001` | `6D4C23` ESI−2711h，`6D4C29` cmp 270Eh，`6D4C2F` ja `6D4C82`，後到 `6D4CAE` store `byte [esi+FB9004]=0`；**該 writer 分支不存在 reader 的 `ESI<=27h` guard**，上游 list domain 未證。 |
| `T10-007-001` | `5467F1 8B 55 10` 是 `mov edx,[ebp+10]` pointer load；`5467F4 66 89 1A` 才是 `mov word [edx],bx`。 |
| `T10-026-001` | `549C4E C2 10 00` 是 `549980` 的 ret16；`549C60 55 8B EC 83 E4 F8` 是**新入口**，`549D54` 的 `54F270` 呼叫屬新入口，不是 `549980`。 |

## 4. 可重現 byte windows

讀取 `Tartaros.bin`，依 `raw=VA-0x400C00` 取 `[start,end)`，再 SHA256；固定下列精確視窗，不允許從 instruction immediate 中間起始解碼：

| 名稱 | VA 半開範圍 | 視窗 SHA256 |
|---|---|---|
| Row A | 545895..54593E | `728054a73b1e1430660351bb7964e8be652243dc2c6d65501d14488d0302bdd1` |
| Row B | 545A54..545B1A | `061507199083913b66dc8b0a3efcbfd9bdb884c8cb361d5eadaa3f3b90e2f26d` |
| 000A sender | 545B38..545B73 | `170e1d95e58df6a123a3f6bd63e7a28ed0d97a42895078d7e0d3d8adcb89fe6c` |
| 055 canonical | 6D4BAC..6D4BC5 | `4bd3c8f8b1f1b6233dcc3419af9b2fb82d281a5c33238427c9c748f1aeb589e5` |
| 056 canonical | 59642E..596448 | `2c705243467b8abd25f41ec45189d7020cb8f2173df2c5d2dee1de9d87c5c505` |
| 062 reset | 6D4A95..6D4AF9 | `d3e24b21fc18915d8fac862e163ca7691dbff51fc94c80394d477d9711dde506` |
| 063 clear | 6D4C20..6D4CB8 | `4c3360e76e546712cb9ab136a7e34f365c5d0a1975597cd3719d5fdc3deeeb1e` |

## 5. T10 玩家情境／Server 接口

| 玩家操作 | Client 靜態證據 | C→S | S→C | 動作／裁決 | 未解 |
|---|---|---|---|---|---|
| 短按普攻鍵 | 原有 T10 bank/phase/controller gated paths + 本次 000A row 來源更正 | 000A application 6+5N、`N>0` 才 selector0 虛傳輸；下游需有效 Conn 才可入列到 socket | 未證本次行為的特定 ACK | 本地先播未知 | Key input→實際 row 的所有角色路徑、玩家看得到的結果 |
| 按住／快速再按 | 已有片段不等於重複 producer 的完整生命週期 | 是否每次發、間隔未知 | 未證配對 | combo/window/取消未知 | 必追 keydown/keyup/hold、input buffer 的 clock/reset |
| 施放中再按／移動 | 與 T11/T09 的跨 Task gate 需交界 | 未閉合 | 未閉合 | 不能用 fixture 0.65 秒 | motion、collision、移動先後及打斷時機 |

**立即可供 Server 開發參考的有限資料：** 000A header/row 大小、append/容量 gate、selector0 的條件式傳輸；需容納兩種 Row B 直接來源路徑。**不可立刻定版：** Row A 第五 byte 全分支／row 高WORD 遊戲含義、連段時窗、Server 正規 ACK／傷害及取消邏輯。T12 專責傷害公式。

**下一步精確入口：** 逐一定位 controller virtual+48 全實作與 `R::virtual+58`，釐清 Row A +58=0 的 `[S+38]` def-use；再從 key snapshot / hold-release 到 Row A/B owner gate 作完整 CFG，最後對 T02 S2C key13 motion 的因果鏈。T01 NEEDS_FIX 與 NEEDS_QUALIFICATION **維持原狀**，需要完整相關 ABI／CFG 與新 blob 審核後才可改 `READY_FOR_REVIEW`。不得自行改成 `RESOLVED`。
