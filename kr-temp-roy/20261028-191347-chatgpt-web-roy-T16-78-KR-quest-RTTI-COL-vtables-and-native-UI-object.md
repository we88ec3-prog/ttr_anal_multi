# KR T16-78 — Quest UI 原生 RTTI → Complete Object Locator → vtable → 物件初始化與釋放路徑

- 研究時間：2026-10-28 19:13:47 CST（Asia/Taipei）；研究者 chatgpt-web roy；**KR only**。
- 原始 BIN 唯讀：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`（本輪實檔核對）。
- PE `.text` VA `0x00401000` raw `0x400`；`.rdata` VA `0x00BD2000` raw `0x7D0600`；`.data` VA `0x00D61000` raw `0x95E800`。使用 `objdump -h` 核對。
- 不啟動、patch、注入或擷取動態封包。此筆記沒有猜測官方 Server 行為。

## 研究脈絡與目的

T16-77 僅找到 Quest UI 類別的裝飾名稱與 TypeDescriptor。T16-78 使用原始 BIN 的 little-endian pointer chain 將 `TypeDescriptor → MSVC x86 RTTI Complete Object Locator (COL) → vtable[-1] → vtable` 接起，並在 `.text` 找到將 vtable 寫入實際物件的指令。**本輪重大增量是具體虛表及 vptr writer 的閉合；並非 Quest 業務封包已還原。**

## 第一輪 T16-78 — 原生連續指標鏈

判定方式：在 type descriptor raw 引用 `p` 附近，若 `DWORD[p-12]==0` 且 `[p-8]` 為 this offset，而 `[p]` 為 type descriptor VA，則 `p-12` 是 x86 COL 候選；搜尋 `VA(p-12)` 的 little-endian 指標，命中 `.rdata` 位置作為 `vtable[-1]`，由下一 dword 開始為虛表。用 `.text` 中直接寫入該 vtable 的指令驗證，不僅依單一指標模式下結論。

| 原生 RTTI 名稱 | TypeDescriptor VA | COL VA | vtable VA | vtable[0] VA | `.text` vptr direct hit (VA) |
|---|---|---|---|---|---|
| CQuestListDlg | `0x00F80B04` | `0x00C6EA14` | `0x00C1BB50` | `0x005A0B10` | `0x005A0B39`, `0x005A2208` |
| CQuestListItem | `0x00F85574` | `0x00C75E40` | `0x00C2DBAC` | `0x00466DE0` | `0x006308C6`, `0x00630979`, `0x00630A1F` |
| CTutorialQuestDlg | `0x00F827B8` | `0x00C70FB4` | `0x00C1ECA4` | `0x005BF920` | `0x005BF94B`, `0x005C13EB` |
| CMissionConditionQuestList | `0x00F86198` | `0x00C776B0` | `0x00C3361C` | `0x00466DE0` | `0x00657478`, `0x00657500`, `0x0065779A`, `0x0065C032` |
| CQuestNormalDetailDlg | `0x00F80AC0` | `0x00C6E9C8` | `0x00C1BB68` | `0x005A0B90` | `0x005A0BBB`, `0x005A228A` |
| CQuestScenarioDetailDlg | `0x00F80A78` | `0x00C6E97C` | `0x00C1BB80` | `0x005A0C10` | `0x005A0C3B`, `0x005A230B` |

註：表內 `.text` direct hits 指精確 DWORD 值出現在程式範圍；其中 `CQuestListDlg` 的 2 筆已進一步反組譯確認是 `mov [reg], imm32` 的 vptr write；其他 direct hits 在本輪為**候選導航**，不可一律當成獨立 constructor。物件名稱由 RTTI 與 COL 指標鏈支持，虛表指標來源為 BIN 本身。

### 1.1 可直接再現的原生 bytes/VA/raw

- `CQuestListDlg` COL VA `0x00C6EA14`、raw `0x86D014`； `vtable[-1]` VA `0x00C1BB4C`、raw `0x81A14C`； `vtable[0]` VA `0x00C1BB50`、raw `0x81A150`； `vtable[0]` 內容 `0x005A0B10`。
- `.text` VA `0x005A0B39`、raw `0x19FF39` bytes `c7 06 50 bb c1 00` → `mov dword ptr [esi],0x00C1BB50`。
- `.text` VA `0x005A2208`、raw `0x1A1608` bytes `c7 07 50 bb c1 00` → `mov dword ptr [edi],0x00C1BB50`。

```asm
005a0b34: 8b f1                 mov esi,ecx
005a0b39: c7 06 50 bb c1 00     mov dword ptr [esi],0xc1bb50
005a0b46: 8b 4e 0c              mov ecx,[esi+0xc]
005a0b49: 85 c9                 test ecx,ecx
005a0b4b: 74 10                 je 0x5a0b5d
005a0b4d: 8b 01                 mov eax,[ecx]
005a0b4f: 8b 50 1c              mov edx,[eax+0x1c]
005a0b52: 6a 01                 push 1
005a0b54: ff d2                 call edx
005a0b56: c7 46 0c 00 00 00 00 mov dword ptr [esi+0xc],0
005a0b5d: f6 45 08 01           test byte ptr [ebp+8],1
005a0b61: c7 05 9c 2c fe 00 00 00 00 00 mov dword ptr [0xfe2c9c],0
005a0b6b: c7 06 b4 29 bf 00     mov dword ptr [esi],0xbf29b4
005a0b73: 56                    push esi
005a0b74: e8 93 06 2f 00        call 0x89120c
005a0b8d: c2 04 00              ret 4
```

`0x005A0B10` 第一個虛方法從這個 CFG 判斷更符合 **destructor / deleting destructor**，不能當成點擊或接受任務 callback。其 `+0x0C` 子物件先虛擬釋放、清零，最後可條件性釋放自身。基底 vptr `0xBF29B4` 被覆寫是析構分階段切換的特徵。

## 第二輪 T16-78-2 — 直接建構／初始化證據

```asm
005a21f5: 8b 7d 08              mov edi,[ebp+8]
005a21f8: 33 f6                 xor esi,esi
005a21fa: 89 77 04              mov [edi+4],esi
005a21fd: 89 77 08              mov [edi+8],esi
005a2203: 68 30 01 00 00        push 0x130
005a2208: c7 07 50 bb c1 00     mov dword ptr [edi],0xc1bb50
005a220e: e8 55 fe 2e 00        call 0x892068
005a2216: 89 45 f0              mov [ebp-0x10],eax
005a221d: 3b c6                 cmp eax,esi
005a221f: 74 09                 je 0x5a222a
005a2223: e8 58 c0 08 00        call 0x62e280
005a222c: 89 47 0c              mov [edi+0xc],eax
005a222f: c7 47 04 eb 00 00 00  mov dword ptr [edi+4],0xeb
005a2248: c2 04 00              ret 4
```

可確認：此函式使用外來的 `[ebp+8]` 指向 UI wrapper、寫入 `CQuestListDlg` vptr、將 wrapper `+4/+8` 清零、配置 `0x130` bytes 並在非零時呼叫 `0x62E280` 初始化配置物件，再放到 wrapper `+0xC`，把 `wrapper+4` 寫成 `0xEB`。`0x130` 是**內部配置大小**；`0xEB` 是 wrapper 欄位值，語義待驗證，不能猜作任務 ID、封包 opcode 或 widget ID。

有條件的偽碼（非官方原始 C++）：

```cpp
UIWrapper* init_quest_list_wrapper(UIWrapper* w) {
    w->vptr = (void*)0x00C1BB50;
    w->field04 = 0; w->field08 = 0;
    void* p = allocate(0x130); // allocate callee at 0x892068; exact allocator contract unknown
    if (p) p = init_allocated_quest_ui(p); // 0x62E280
    w->field0C = p;
    w->field04 = 0xEB; // meaning unknown
    return w;
}
```

配對的析構途徑在 `0x005A0B10` 出現 `wrapper+0xC` 的虛方法 `+0x1C` 與置零；這是資源所有權的實質閉合進展，但**其 UI 操作／網路封包尚未閉合**。

## 第三輪 T16-78-3：未啟動與停止門檻

第 1、2 輪已取得 `RTTI → COL → vtable[-1] → vtable → writer → 0x130 allocation → initializer → wrapper field → deleting destructor` 的新且有界、可核對完整原生鏈，符合共用「完整功能鏈進展／重大新發現」門檻。故第 3 輪**未啟動**，避免為湊輪次擴展無關引用。下一段應追 `0x62E280` 與 UI 動作 callback；本段不假稱已找到 Quest packet producer。

## Player scenario / client-server evidence matrix

| 情境 | Client 本地證據 | C→S | S→C | Quest/UI 效果 | Server 待開發 |
|---|---|---|---|---|---|
| 任務列表被初始化 | `0x5A2208` 寫 `CQuestListDlg` vtable； `0x130` allocate、`0x62E280` init、wrapper+0xC 指向物件 | unknown | unknown | UI 物件實際建立／初始化鏈 **部分確認**；顯示時機 unknown | 無法由 UI 初始化推導 Server 封包 |
| 開啟任務列表 | 型別/配置已確認，UI 顯示 callback unknown | unknown | unknown | 顯示內容 unknown | 未知 |
| 點 NPC 接受任務 | click producer unknown | opcode/len/fields unknown | accept/failed handler unknown | Quest cache writer unknown | 待 Client 原生 wire 證據 |
| Quest16 完成→Quest15 可接 | unknown | unknown | unknown | unknown | 不推斷官方前置或 DB 更新 |

## 後續入口、證據限制與協作

- T16-79：追 `0x62E280` 的 vptr 寫入、UI handler、subobject 欄位與具體 click dispatch，再反向對照 `0xFBA854` 的 send queue；也可由 Quest cache writer 反查 S→C handler。
- `CQuestListItem` vtable `0xC2DBAC`、`CTutorialQuestDlg` vtable `0xC1ECA4` 可作平行入口。vtable 第一個 virtual call 是析構候選，不是操作 callback。
- Client Quest accept / complete 的官方 wire opcode、payload、Quest16/15 mapping、S→C 邏輯仍 unknown。不能從 T16-75 已否證的本地化 message ID 回填。
- T02/T07/T14/T15 擁有各自分工；本段不修改其文件、catalog、owner 或遊戲二進位。