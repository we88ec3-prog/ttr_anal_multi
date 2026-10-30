# T01 — T10-116～118 有界 R1/R2：000A row、selector tree、connect caller 與原稿反證

2026-10-30 Asia/Taipei；T01 canonical 整合，**不是**新的 T10 正式段號。KR 原始唯讀 BIN 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE 2,594,816 bytes SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本輪直接計算與原始檔吻合。PE32 .text VA401000 raw400 (raw=VA−400C00)、.rdata VABD2000 raw7D0600 (raw=VA−401A00)。沒有執行 Client、沒有原版 Server、沒有封包實測。

## 1. R0 來源與前序差異

| SRC | 段號 | 完整路徑 | Git blob SHA1 |
|---|---|---|---|
| SRC-0380 | T10-116 | `kr-temp-roy/20261028-213248-chatgpt-web-roy-T10-116-KR-000A-five-byte-row-field-provenance.md` | `8da51d9e77d3d900bc73743bddc82891f6829c15` |
| SRC-0381 | T10-117 | `kr-temp-roy/20261028-223848-chatgpt-web-roy-T10-117-KR-selector-registration-to-000A-transport-tree.md` | `01607b45a2decdc526063081ad6020b3d8742e0e` |
| SRC-0382 | T10-118 | `kr-temp-roy/20261028-224346-chatgpt-web-roy-T10-118-KR-selector0-category2-connect-callers.md` | `8f00225b580fab47b9d7964c9bdf6511047c911f` |

前序精確登記：`SRC-0379/CLM-COMBAT-0002` 已有 C2S000A 6+5N 和 selector0 conditional pending；`SRC-0383/CLM-COMBAT-0003` 已有 S2C key13 的9-byte row；`SRC-0384/CLM-COMBAT-0004` 有七張 actor vtable+58 的 B0 writer。網路 `CLM-NET-0007` 已包含 port8415/8416/8414、selector1/0/2、category2；`CLM-NET-0016` 有條件地處理舊 selector map node；`CLM-NET-0019` 有 selector0/2 連線建立與 return gate。**不**因本批內容再創建同義 port 或 generic socket claim。

本輪新增 `CLM-COMBAT-0019`（row 實際寫入與精確反例）、`CLM-NET-0036`（selector→Conn tree writer/read 成員）。`SRC-0382` 是 `CLM-NET-0036` 的限定共同來源，並補入既有 `CLM-NET-0007` additional_sources，不繼承品質；所有仍 PARTIAL。T10-116 的原稿無條件第五位元組結論出現**原生反證**，新增 T01 驗收退回 `T01-RETURN-T10-116-ROW5-PROVENANCE-001`；保留原稿及 SHA，不改其他 Task 的 owner/task.json、RR、SPEC、GAP、TEST。

## 2. 000A 初始 header／傳輸入口

```asm
545824 mov eax,6
545829 mov edx,0xA
54583C mov [FE48D0],eax
54584A mov [FE38D0],ecx
545850 mov WORD [FE38D4],dx
545B38 cmp DWORD [FE48D0],6
545B43 jbe 545B73              ; 0 row：此 builder 不呼叫傳輸
545B49 mov ecx,[FBA854]
545B66 mov edx,[edx+0x10]
545B69 push eax                 ; 6+5N
545B6A push FE38D0
545B6F push 0                   ; 連線 selector，不是 opcode
545B71 call edx
```

兩路獨立 5-byte row 的 append 都有 `length+5<=0x1000` gate，因此單就此緩衝的局部上界 N≤floor((4096−6)/5)=818，並非 Server 每 tick 允許的攻擊數。相同 `0x000A` 只可稱應用 buffer 首 WORD；其它 header 內容/Server 接受邊界未全證。`0x8069A0` lookup selector0 失敗時不呼叫 `0x8060D0`，有效 Conn 且 payload 長度非0才 enqueue；後續 `0x8061A0` pending pump 和 `0x8068B0` WSASend 仍有各自本地 gate。

## 3. Row A：12-byte slot、virtual48、R+4 和 local 第五位元組

`0x545895` 得 owner A；`0x54589C` 以 `A+0xC+12*i` 得 R pointer；`0x5458A5` NULL 或 `0x5458AB` slot+0x14 flag0 均不 append；`0x5458CE` 呼叫 A::virtual+0x48，依 AL 分流。

```asm
5458BB mov bl,BYTE [esi+0xB0]       ; 擷取當時 R+B0
5458C1 mov edx,[edx+0x48]           ; owner virtual48
5458CA mov BYTE [esp+0x20],bl       ; 在 push eax、push edi 後的 ESP
5458CE call edx
5458D8 cmp DWORD [eax+0x58],0
5458E0 mov WORD [esp+0x36],ax       ; nonzero branch 的 local high WORD 清零
5458E9 mov BYTE [esp+0x38],bl       ; nonzero branch 明確保存 B0 snapshot
5458EF mov edx,[edx+0x58]
5458F5 call edx
5458FB mov cl,BYTE [esp+0x38]
54590D mov ax,WORD [esi+4]
545911 mov WORD [esp+0x34],ax
54591E cmp edx,0x1000             ; 檢查+5
545926 mov edx,[esp+0x34]
545930 mov [eax],edx
545932 mov [eax+4],cl
545935 add DWORD [FE48D0],5
```

RowA[0:2] = 於 append 前從 R+4 讀的 WORD；RowA[2:4] = local high WORD（callback/high writer 未完整驗證）；RowA[4] = local[esp+38]。在 owner+58 非零且執行 `5458E9` 的支路有 R+B0 的明確捕捉寫入；但 owner+58==0 時略過 `5458E9`，不能將 `5458CA`（兩次 push 後的 `[esp+20]`）不經 callee retN/stack 分析當作同一個 `[esp+38]` 寫入。原稿 Row A 固定 B0 的廣義結論須限定，不能由局部 BL 讀取自動推論所有分支。

## 4. Row B：8-byte tree row、virtual44 與確定的 E4 例外

`5459B7..5459FC` 從 A+30 的 8-byte stride 取一個 WORD，查 `FAB13C` tree；node/sentinel 不符則不 append。通過才由 A::virtual+0x44 執行 row+2 WORD、R pointer、可修改 local。`545A9B` 判斷回傳值；return=0 必須 A+58 非零且 A+6A bit15 (`0x8000`) 成立才可走 fallback。兩個分支皆在 `545AFC cmp edx,0x1000` 前有長度+5 gate。

```asm
545A54 mov eax,[esi+0xE0]
545A63 mov [esp+0x2C],eax
545A67 mov cl,BYTE [esi+0xE4]
545A70 mov BYTE [esp+0x30],cl       ; 先保存 R+E4
545A78 mov bl,BYTE [esi+0xB0]      ; 另保存 R+B0 到 BL
545A97 call edx                     ; A::virtual+44
545A99 test eax,eax
545A9D cmp DWORD [edi+0x58],0
545AA1 je 545AD6                   ; return!=0 且 A+58==0 略過 AC8
545AAC cmp DWORD [edi+0x58],0
545AB7 test WORD [edi+0x6A],0x8000
545ABB je 545B1A                   ; fallback 閘未通過，不 append
545AC8 mov BYTE [esp+0x30],bl      ; only this branch R+B0 覆寫 local
545AD4 call edx                     ; R::virtual+58
545AD6 cmp DWORD [esp+0x18],0
545ADB mov cl,BYTE [esp+0x30]
545AEB mov dx,WORD [esi+4]
545AF4 mov WORD [esp+0x2C],dx
545AFC cmp edx,0x1000
545B04 mov edx,[esp+0x2C]
545B0E mov [eax],edx
545B10 mov BYTE [eax+4],cl
545B13 add DWORD [FE48D0],5
```

| A::virtual44 result | A+58 | A+6A bit15 | B-row append（尚須其它 gate） | row[4] 來源 |
|---|---:|---:|---|---|
| nonzero | **0** | irrelevant | 可能 | **R+E4**，跳過 `545AC8` |
| nonzero | nonzero | irrelevant | 可能 | 捕捉的 R+B0，執行 `545AC8` |
| 0 | 0 | irrelevant | 不會 | 無 row |
| 0 | nonzero | 0 | 不會 | 無 row |
| 0 | nonzero | 1 | 可能 | 捕捉的 R+B0，執行 `545AC8` |

**T01 反證：**原 T10-116 的兩條 row 共同 ABI 描述為固定 `u16(R+4) + u16(local_high_word) + u8(R+B0)`，卻存在 `545A67/70` 先寫 R+E4、`545A9D→545AA1→545AD6` 跳過 `545AC8`、`545ADB→545B10` 將未被 B0 覆寫的 local byte 寫入 row[4] 的可達 branch。因此 B row 第五位元組 **不是無條件 R+B0**。以上只對現有直接 store/dataflow 與獲得的 vcall 返回條件有效；虛回呼可能有額外 side effects，不能據此無條件宣告每種 runtime 類型的第五 byte。

## 5. T10-117：selector→Conn tree 寫入與讀取共用結構

```asm
806B25 mov eax,[ebp+0x14]          ; queue category，非 selector
806B33 mov [ebx+0xA080],eax       ; connection category writer
806C87 call DWORD [BD2278]       ; CreateIoCompletionPort，條件式 OS association
806C91 lea eax,[ebp+0x10]        ; selector arg10
806C94 lea esi,[edi+0x18]        ; manager+18 tree
806C9E call 8438C0               ; 查既有 key
806CA7 cmp eax,[edi+0x1C]        ; sentinel
806CB3 call 7B6890               ; existing node erase 候選
806CB8 mov edx,[ebp+0x10]
806CBF mov [esp+0x14],edx        ; key
806CC3 mov [esp+0x18],ebx        ; new Conn
806CC7 call 57EF20               ; 0x18 bytes node
806CD2 call 57E850               ; 比較/插入，duplicate 可不插入
57EF54 mov [node+0x0C],edx       ; selector key
57EF59 mov [node+0x10],edx       ; Conn pointer
8069B1 lea ecx,[esi+0x18]       ; 同一 manager tree
8069B7 call 8438C0
8069BF cmp eax,[esi+0x1C]
8069C5 mov ecx,[eax+0x10]        ; connection value
8069EB call 8060D0               ; 只在有效 Conn+len!=0
```

`0x57EF26 push0x18` 和兩個 DWORD node writes 已從 BIN 確認。`0x57E909` 在 duplicate/no-insert 分支寫 resultFlag0；呼叫 node constructor 與插入**不保證**每次成功。前段 `CLM-NET-0016` 已有舊 key map node conditional erase，保留其限定主張與 Conn/IOCP lifetime 未解，不把本次 writer/read 關聯偷換成所有重連必成功。`0x806AD0` 失敗分支可早於寫入 tree 返回。

## 6. T10-118：三個實際連線註冊 caller；只增補來源，不重建 NET0007

| call | port（十進位） | selector | category | 返回／下游 gate |
|---|---:|---:|---:|---|
| `4957EA` | 8416 (`0x20E0`) | 0 | 2 | EDI 保存，`495807 test edi`；失敗跳走 |
| `495803` | 8414 (`0x20DE`) | 2 | 2 | EBX 保存，`49580F test ebx`；獨立失敗路徑 |
| `49575B` | 8415 (`0x20DF`) | 1 | 2 | ESI 保存，失敗分支分離；成功可試 vtable+14 WSARecv |

```asm
495751 push 2; 495753 push 1; 495755 push 20DFh; 49575B call eax
4957E0 push 2; 4957E2 push 0; 4957E4 push 20E0h; 4957EA call edx
4957F2 push 2; 4957F4 push 2; 4957FD push 20DEh; 495803 call edx
495807 test edi,edi; 49580F test ebx,ebx
```

三個數字 namespace 不同：port 是 socket connect 目的埠候選、selector 是 manager tree key、category 是接收 queue lane；三者都不是應用 opcode `000A`。即使 selector0/2 init 函式 return1，還須執行時物件存活、合法 socket、pending+WSASend gates；不代表 Server 認證／進角色已成功。T10-118 的上述常數與現有 `CLM-NET-0007` assertion 相符，故將其加入 0007 的 additional_sources（品質仍 PARTIAL），不重建同義 assertion。

## 7. 與 S2C key13 及角色 B0 writer 的交叉界線

已收錄 T10-119 `0x4B01C0` S2C **9-byte rows**，在 conditional actor lookup 下 actor virtual+58 可被呼叫；T10-120 七個 vtable candidate 的 +58=`0x4C8C30` 把傳入 BYTE 寫 actor+B0。**不表示**本次 R 必使用這七張表，也不代表 S2C key13 就是 C2S 000A 的 ACK。來源區別是 R+E4、R+B0、local snapshot、row[4] 對每條 path 的具體最後 writer，而不是因名稱類似自行配對。

## 8. R2 複驗清單／結果

本輪對原始 BIN 使用 Python hashlib、struct、GNU objdump Intel x86，**19 個精確原生 bytes 視窗、45 個機器碼 byte asserts、5 個 .rdata vtable DWORD** 全通過。全項 JSON `20261030-163408-chatgpt-web-roy-T01-T10-116-118-R2-audit.json`；唯讀重跑 `python 20261030-163408-chatgpt-web-roy-T01-T10-116-118-revalidate.py Tartaros.bin 20261030-163408-chatgpt-web-roy-T01-T10-116-118-R2-audit.json`。`Tartaros.bin` raw→VA `.text` 補償 0x400C00、`.rdata` 補償 0x401A00。以下原生 SHA256 僅說明位元組視窗等同原件，不宣稱 all-caller CFG／完整原稿已驗收。

| 功能 | VA [start,end) | sha256 |
|---|---|---|
| C2S000A_header | 0x545824..0x545857 | `642308877ebd72d98c18c7eca57a7e6b7eb549353035210fa294db948c392195` |
| first_row | 0x545895..0x54593E | `728054a73b1e1430660351bb7964e8be652243dc2c6d65501d14488d0302bdd1` |
| second_row_tree | 0x5459B7..0x545A54 | `7e097d49a893eb83e9b7f4ad3243df06cf4098389b5427f2ec1b8998c802ef19` |
| second_row_writers | 0x545A54..0x545B1A | `061507199083913b66dc8b0a3efcbfd9bdb884c8cb361d5eadaa3f3b90e2f26d` |
| send_selector0 | 0x545B38..0x545B73 | `170e1d95e58df6a123a3f6bd63e7a28ed0d97a42895078d7e0d3d8adcb89fe6c` |
| manager_selector_reader | 0x8069A0..0x8069F6 | `15bfdafb9caef08f72626dffb2508c7568a9f251e13013959d0b965c1c16d3f1` |
| connection_setup_category | 0x806AD0..0x806B54 | `1f99e98411b4daf7989d7b77865404cbf96db3dda3327a97173ae303c24f5ce7` |
| connection_failure | 0x806BB6..0x806C13 | `e5323774797d682cb4d646873ce4fe43312ebd315db95071caf95d89988222c9` |
| selector_tree_writer | 0x806C7B..0x806CD7 | `db7ee6225101038a555f6f6a220713f6087deebd688eedbb4a7c63fd78fea1de` |
| tree_node_allocation | 0x57EF20..0x57EF60 | `1c10bc49692f53834b201855d977750cb83b2d08208edeb63e2c1a358faf3549` |
| tree_compare_insert | 0x57E850..0x57E916 | `901f1c11a1e8da353ea8b49a77f4e4eb09344a449cdc944334223a649d336fd8` |
| selector1_caller | 0x495743..0x49578F | `267ce8c4499becd6b23f4e4533a86c585aa70d93d01ead2eff1d52bcaff415fa` |
| selector0_selector2_callers | 0x4957C0..0x495817 | `6373b1194e5ce8a054156044d6e18c4a623da9d04f16ed86f410a4eb7d69a175` |
| selector_failure_and_recv | 0x495807..0x49596C | `9ad53e2cf94f46c1121d43ce632a8c3e6f231a340ba3514e537abca2dc2152e3` |
| pending_enqueuer | 0x8060D0..0x806191 | `b8a91d2db14f1edac4a7b379250ed8a006d4e5518958e978678a71f079df4509` |
| pending_list | 0x806060..0x8060CE | `378338fd62742a163bc08eeab6a1785f2c4ff089aa4706abf3de76b6a6738187` |
| vtable_constructor | 0x8046C0..0x804730 | `8415d3bb8075f17bf9cdddc88e02e0e346b15a7595747db5a57cca866996f217` |
| WSASend_wrapper | 0x8068B0..0x80699B | `abae75dd0e81616099da807611b697f5aade87d4e1bd9319210245a07fe84582` |
| S2C_key13_separate | 0x4B01C0..0x4B03C7 | `392721bb73509fd9f79883d36b6b717d84d6af5cd7c45526cc08bba3fcb50b72` |

完整 45 個 byte asserts 與 vtable pointer 值在 JSON；`0x545A54`、`0x545AD6`、`0x545B38`、`0x806C7B` 等使用合法指令入口。來源原稿當初的 3-round / 新發現即停行為不代表 T01 全文 FULL-PASS；本輪審查只對明列重要功能鏈與反證成立。

## 9. 正式 T01 退回的修復條件

`T01-RETURN-T10-116-ROW5-PROVENANCE-001 — NEEDS_FIX`：原稿 T10-116 blob 8da51d9e77d3d900bc73743bddc82891f6829c15；不可變更舊 SHA。原作者需提供勘誤，將 Row B 第五 byte 依 virtual44 return、owner+58、owner+6A bit15 逐分支分類；修正原稿「兩個 row 都必然 B0」；另就 Row A `[esp+20]` two-push 前後與 `[esp+38]`、callees retN、virtual58 的 stack/value effects 提供根據。T01 驗收依新版 blob 重驗受影響主張才能 RESOLVED；不因單一錯誤否定其它原稿獨立可用片段。

## 10. 玩家情境 × Client × C→S × S→C × motion × 責任

| 情境 | Client 已證條件 | C→S | S→C | local/remote motion | 分工／證據 |
|---|---|---|---|---|---|
| 短按 Z，active bank Key44→ID13 | 既有 phase/controller 有界輸入；000A row 在 local gates 後組包 | N>0、selector0 Conn 已存在、pending/transport gate 通過才可提交，非每按必送 | 未證因果 ACK | 未知 | Client 限定靜態；原版 Server 判斷不可猜 |
| Row A owner slot/virtual48 成功 | 低WORD R+4，高WORD local，byte local+38 | buffer+5<=4096 才 append | 未由此證 | 未知 | owner+58=0 的 byte writer/ABI 待追 |
| Row B virtual44 success、owner+58=0 | local+30=R+E4，不走 AC8 | 有條件 append | 未由此證 | 未知 | **明確反證**固定 R+B0 |
| Row B 走 AC8 的分支 | local+30 用此前擷取的 R+B0 覆寫 | 有條件 append | 未由此證 | 未知 | highWORD/virtual side effects 未證 |
| selector0/2 建立失敗、lookup 空 | 可能沒有有效 connection value | 本 builder 無法由該 selector enqueue | unknown | unknown | Client socket 失敗≠Server 拒絕普通攻擊 |

**Client 待逆向：** Row A local+38 完整 stack ABI 與 virtual callbacks，B row highWORD 及 R+E4/B0 的真正全部 writers，selector tree duplicate/reconnect、實際 000A 行動對應 socket completion，local/remote actor motion。

**Server 待開發：** 只有 Client 已證的欄位大小、條件式接收/送出入口可作候選契約；未知 row 高 WORD／第五 BYTE 的遊戲含義、combo/cancel 時窗與 Server 回覆，不可自行宣稱官方規則。

**跨功能待整合：** T02 的 RR-0005 連線所有權/IOCP/map 替換，T03 登入/選角何時建立 selector0，T08 actor 來源及 B0/E4，T09 motion consumer。**待遊玩驗證：** 無 Client runtime、原版 Server trace、封包實例或可玩驗收。

**本輪交付界線：** 127 份 T10 來源中，沿此 T01 canonical 有界來源連結 30→33，另94份待整合；Claim 142→144。只表示主張整合進度；無新增 FULL-PASS、NATIVE_VERIFIED、SPEC_CONSUMABLE、SPEC STABLE、RR ACCEPTED 或 Server 實作。
