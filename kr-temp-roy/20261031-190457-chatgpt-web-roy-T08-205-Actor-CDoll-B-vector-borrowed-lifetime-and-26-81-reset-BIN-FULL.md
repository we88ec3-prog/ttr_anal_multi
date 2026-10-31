# T08-205 — KR Actor 刪除、CDoll 強持有與 B-vector 借用 entry 的跨生命期一致性（BIN-first 原生有界完成稿）

- 研究者：chatgpt-web roy；研究時間：2026-10-31 19:04:57 Asia/Taipei。
- Task：T08；唯一研究分支：t08/roy/chatgpt-web；原生版本：KR（不得套到 TC）。
- 原始文件：Tartaros.bin，12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；同版 Tartaros.exe SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。兩檔已於本次重新讀取並計算 hash。
- PE32/I386：image base 0x400000；.text VA 0x00401000/raw 0x400，程式碼 raw=VA−0x400C00；.rdata VA 0x00BD2000/raw 0x007D0600，資料 raw=VA−0x401A00。全部地址為 **PE VA**；不得把 .text 公式用於 .rdata。
- 方法：唯讀、離線；以原始 BIN 和 llvm-objdump x86 Intel disassembly 回核，並以獨立 Python 靜態工具核對 PE/hash/code bytes/vtable/rel32；未執行、patch、附加 Client。
- Git 基準：main ad1fda170734767c67dd0f62066a34ece34e118a → t08/roy/chatgpt-web 真實 Merge commit 85cc358b6624e857f9167d45a29e39d9d50c7716；比較 main...T08 後 behind=0。T08 S00 inbox 無待處理 KR RR；T01 舊退回作者側已有 READY_FOR_REVIEW，主審未因此自動通過。
- 歷史直接前件：T08-202（000A/26/81、P/Controller）、T08-203（0007/2+26N Actor）、T08-204（Monster/NPC → CDoll → B-vector → 7A8310）。本段不冒充重新首次發現那些既有流程。

## 0. 原定研究終點、證據主張及不納入的問題

T08-204 指定下一題：命令26／81、全場清除時 Actor/CDoll 與 display manager 的 CDoll+0x0C 借用 entry 是否各有持有與取消路徑，Controller/owner P/Scene 的引用如何清理；實際先後順序不足時保留可操作的靜態與 runtime 界線。以 Client 原生機器碼完成：

1. 兩類 Actor（type1 Monster、type6 NPC）的 vtable slot14/slot0 → 共用 Actor 解構 → CDoll shared control block 的確切強參照釋放；
2. B-vector entry 的資料型態、append 與真正 consumer，辨認持有與非持有，限定 logical clear/manager teardown；
3. 命令26、81、whole-scene Actor tree reset 的清理順序及 Controller 回呼差異；
4. 列出「何時可能有舊借用指標」需要補證的先後與其它 owner 情況，不能將有風險直接等同發生 UAF；
5. 對 owner P、Controller 與 scene 消費者標明有界引用範圍和跨 Task 交接。

**結論狀態：T08-205 = FINISHED（BOUNDED_CLIENT_STATIC_LIFETIME）；這是上述 Client 靜態功能鏈的完成，不是「無 UAF 安全證明」、真正 UAF 已發生、T01 FULL-PASS、S00 ACCEPTED、Server 已完成或可玩驗收。** 間接別名全集、事件與 render 的 runtime 排程屬明列未證／待補，不用原版 Server-only 未知阻擋 Client 已達標範圍。

## 1. 身分、持有者、借用者：不能混淆的四層

| 層 | 指標/結構 | 已證持有與用途 | 不能由此推論 |
| --- | --- | --- | --- |
| Actor 主樹 | 全域 manager [0xFAB130]；key查找 [0xFAB138]；node+0x10 → Actor | 26/81/reset 以 ID 或 composite 取 Actor 並呼叫其虛擬清理、解構、tree erase | Actor 主樹 erase **不等於** B-vector 同步移除該 CDoll |
| Actor shared holder | Actor+0x15C CDoll*，Actor+0x160 control* | 0x4C7B90 釋放一筆 **強參照**；最後強 owner 才觸發 CDoll managed object deleter | Actor 被刪 **不保證 CDoll 當下 freed**；也不保證另有 owner |
| CDoll B-vector | 全域 [0xFBA838] manager；manager+0xB4/+0xB8/+0xBC | 0x7A63C0 在有效 gate 後推入 4-byte **CDoll+0x0C 嵌入介面指標**；0x7BB240 dereference 並派送 vptr+4 | append 沒有控制塊強引用增加；不能把它視為 shared_ptr、場景主樹或 FB7740 的22桶 |
| Controller/owner P | Controller [0xFBA7A4] 的 raw Actor 槽；獨立 P owner-record tree；Scene/CDoll 資源 | 26、81、reset 呼叫不同的 Controller/Actor cleanup；P 的清除由其自身函式進行 | 不能把 Controller slot14、Actor slot14、P、B-vector 四者當一個 owner |

CMonster primary vtable 0x00C0C9DC：slot+0=0x004D18D0，slot+0x14=0x004D1F80。
CNPC primary vtable 0x00C0CA9C：slot+0=0x004D2280，slot+0x14=0x004D2860。
CDoll primary vtable 0x00C4F67C：slot+0=0x007A4FF0，slot+8=0x007A63C0。
CDoll+8 embedded vptr=0x00C4F6B0：slot+8=0x007A57C0。
CDoll+0x0C embedded vptr=0x00C4F6C0：slot+4=0x007A8310。
CDoll shared control vptr=0x00C0760C：slot+0=0x004CA660。
Scene/B-manager vptr=0x00C4FC8C：slot+4=0x007B8C80。

上述 vtable DWORD 均由 .rdata 的實值解析，而非由函式類似名稱猜測。Actor slot14 清理子資源與 Actor slot0 deleting destructor **不是同一個函式**。

## 2. 205-01 — Actor 解構與 CDoll 強參照回收的原生閉合鏈

### 2.1 Monster / NPC 原生動態派送

- Monster：0x4D1F80 E8 DB 63 FF FF → 0x4C8360（slot14）；0x4D18D0 deleting destructor，0x4D18E6 E8 ... → 0x4C7B90，arg+8 bit0 置位時還呼叫 0x89120C free Actor。
- NPC：0x4D2860 → 0x4C8360（slot14）；0x4D2280 deleting destructor 在 0x4D22C1 先讀 Actor+0x420、有效時經 0x4C7DB0 清理，0x4D22E3 再 call 0x4C7B90，arg+8 bit0 置位時 free Actor。
- 0x4C8360：首先讀 Actor+0x15C；非零時將 this 切換成 CDoll+8 embedded interface，透過該 interface 的 vptr+8（原生 0x7A57C0）清理相關資源；之後 Actor+0x364 與 128 個狀態資源也有處置。這步不是 CDoll 整體 deleting destructor。

真 BIN 代表性位置（va / bytes / assembly）：

    0x004D1F80  E8 DB 63 FF FF      call 0x004C8360
    0x004C8365  8B 87 5C 01 00 00 mov eax,[edi+0x15C]
    0x004D22E3  E8 ...              call 0x004C7B90
    0x004C7C19  8B B3 60 01 00 00 mov esi,[ebx+0x160]
    0x004C7C21  89 83 60 01 00 00 mov [ebx+0x160],eax    ; eax=0
    0x004C7C27  89 83 5C 01 00 00 mov [ebx+0x15C],eax
    0x004C7C37  F0 0F C1 08       lock xadd [eax],ecx      ; ctrl+4，ecx=-1
    0x004C7C3B  75 1D             jne 0x4C7C5A          ; 仍有強持有
    0x004C7C43  FF D0             call eax               ; ctrl vptr+0
    0x004C7C4B  F0 0F C1 11       lock xadd [ecx],edx  ; ctrl+8

原生意義：清掉 Actor 欄位，再對 control+4 strong 做原子減一；若這次降到零，經 control vptr+0 銷毀 managed object，之後 control+8 弱持有計數也減一，依結果釋放 control 本身。若其它 strong owner 存在，CDoll 可繼續存活。不能把 control+8 與 CDoll+8 介面混同。

control vptr+0=0x4CA660 的實體行為：

    0x004CA660  8B 49 0C          mov ecx,[ecx+0xC]       ; managed CDoll*
    0x004CA663  85 C9             test ecx,ecx
    0x004CA667  8B 01             mov eax,[ecx]
    0x004CA669  8B 10             mov edx,[eax]
    0x004CA66B  6A 01             push 1
    0x004CA66D  FF D2             call edx                 ; CDoll primary vptr+0

CDoll primary+0=0x7A4FF0 → 0x7A51C0 CDoll destructor，條件性釋放 CDoll 本體。這條鏈由 vtable、強參照欄位及實際 call 證成「Actor 持有者釋放 → 最後強參照 → CDoll deleting destructor」，不是只靠偽碼推測。未沿所有可額外增加 ctrl+4 的 alias 做排他枚舉，不能認定 Actor 是唯一持有者。

### 2.2 解構前 callback 不等於 B-vector 撤銷

Monster/NPC 的 slot14→0x4C8360 主要處理 CDoll+8 interface 及 Actor 子資源。0x4C7B90 對 Actor+0x15C/+0x160 清空並 strong release。已核對這些**指定核心路徑**均沒有一個能直接與 B manager+0xB4/+0xB8 中的 CDoll+0x0C 指標配對刪除的明示呼叫；但 CDoll destructor 0x7A51C0 本身仍有眾多 indirect callbacks，這不構成「全程沒有清理其它別名」的排他證明。

## 3. 205-02 — CDoll+B-vector 借用指標從入列到 dispatch／logical clear

### 3.1 Producer（0x7A63C0）

既有204確認 eligibility：CDoll+0x1C 非零、CDoll+0x124 非零及後續 resource/state gates，經 0x7A65D9 寫入 scene manager：

    0x007A65D9  8B 35 38 A8 FB 00 mov esi,[0xFBA838]
    0x007A65DF  8B 86 B8 00 00 00 mov eax,[esi+0xB8] ; end
    0x007A65E5  83 C7 0C          add edi,0x0C       ; CDoll* → embedded entry*
    0x007A664F  89 38             mov [eax],edi
    0x007A6651  83 86 B8 00 00 00 04 add [esi+0xB8],4

0x7A65F0～0x7A664D 有別名/容量判斷及 grow 例外分支，成功時 entry 仍是 4-byte borrowed pointer。**在這個已核 producer 分支找不到 control+4 strong 增加；單就此路徑 B-vector 不擁有 CDoll lifetime。** 不把 append 的跨界安全性推成「永久固定地址」。

### 3.2 Consumer（0x7BB240）

原生 caller 的 E8 rel32 已定位：0x00799F94、0x007BA879 均 call 0x007BB240（兩處可直接驗證的相對呼叫），而不是僅有孤立函式。前者 0x799F8E 取得 [0xFBA838]；後者屬 manager 更新序列。不能因此推斷與 S2C 移除封包的 tick 相對順序。

    0x007BB264  8B 86 B8 00 00 00 mov eax,[esi+0xB8]
    0x007BB26A  2B 86 B4 00 00 00 sub eax,[esi+0xB4]
    0x007BB276  C1 F8 02          sar eax,2           ; count
    0x007BB270  8B 9E C4 00 00 00 mov ebx,[esi+0xC4] ; dispatch upper bound
    0x007BB2DC  E8 CF 00 00 00    call 0x7BB3B0      ; sorting/prioritization candidate
    0x007BB2F0  8B 8E B4 00 00 00 mov ecx,[esi+0xB4]
    0x007BB2F6  8B 0C B9          mov ecx,[ecx+edi*4] ; entry=CDoll+C*
    0x007BB2F9  8B 11             mov edx,[ecx]       ; embedded vptr
    0x007BB2FB  8B 42 04          mov eax,[edx+4]
    0x007BB2FE  FF D0             call eax
    0x007BB330  89 9E B8 00 00 00 mov [esi+0xB8],ebx ; end←begin

此處對 entry **沒有逐筆 strong acquire**，執行 virtual+4 前也沒有在 7BB2F6～7BB2FE 建立空指標／allocator 健全檢查。對原生 CDoll+C embedded vptr 0xC4F6C0，+4=0x7A8310（有 resource/render-like 虛擬鏈，見204）；不存在「只刪主樹就自然令這個 raw 指標安全」的證據。

上限 C4 可能使實際消費項目少於 enqueued 項目；其後仍以 manager+B8=manager+B4 **logical clear 所有有效 entry**。重要區別：重設 end 並不逐一清零舊陣列 slot 的 bytes，舊值仍可能留在已配置 memory，但已不在 begin..end 有效區間；不能把殘留 raw word 當成下一輪仍會必然派送。

### 3.3 Manager 初始與整體解構

- 0x7AAB41 檢查 [0xFBA838]，不存在時配置 0x10C bytes；0x7B8A50 管理器 constructor 將 manager+B4/B8/BC 初始化為空 vector。
- Manager vtable 0xC4FC8C+4=0x7B8C80 → 0x7B8CB0 destructor。
- 0x7B8DCF 讀 manager+B4；0x7B8DDA 呼叫 0x89120C **free vector storage**；0x7B8DE2、7B8DE8、7B8DEE 將 begin/end/capacity 三指標歸零。
- 這條 manager destructor 處理 **指標陣列的所有權**，未有逐筆 CDoll refcount-release；是 borrowed vector 的又一獨立證據。它只說明 manager 最終解構時會銷毀陣列，不代表 Actor 被刪時 manager 都會同步析構。

## 4. 205-03 — 本地命令26、81與場景整批 reset 的精確路徑對比

命令識別採 T08/T02 **本地 dispatcher 命令域**；尚未完整核實 socket framing 層的 true wire opcode/domain，禁止直接將「26／81」命名為原版 Server 真正 wire opcode。

### 4.1 命令26，0x004B28D0

輸入長度 L≥4 才處理，row count= floor((L−4)/2)，由 buffer+4 讀 16-bit ID。0x4B296C 查 [0xFAB138] Actor tree（0x82EF00）；未命中診斷／跳過；type0/1/6/7 在 Actor+0x15C≠0 且 Actor+0x370≠0 時，依 0x4B29E5 → 0x7A7CC0、0x4B2A10 → 0x7A7BF0 更新 CDoll/資源內部狀態。這兩者只是 **移除前 visual/resource stage**，不等同已證 fade、延遲刪除、render cache 取消或可見畫面結果。

真正刪除步驟：

    0x004B2A56 8B 0D A4 A7 FB 00 mov ecx,[0xFBA7A4]
    0x004B2A65 .. 0x004B2A7B     掃 3 個 Controller raw Actor slot，匹配 16-bit ID
    0x004B2A82 8B 01             mov eax,[ecx]
    0x004B2A84 8B 50 14          mov edx,[eax+0x14]
    0x004B2A87 FF D2             call edx                ; Controller slot14
    0x004B2ABC 51                push ecx               ; ID
    0x004B2ABD B8 30 B1 FA 00    mov eax,0xFAB130
    0x004B2AC2 E8 F9 D0 02 00    call 0x4DFBC0

0x4DFBC0 從 Actor main tree 再查 ID；找到後**在 Actor 刪除前**依次將 i=0..2 送入 Controller vptr+0x1C callback，再呼叫 **Actor 自身** vptr+0x14 做資源 cleanup、Actor vptr+0（push 1）delete，令 node+0x10=0，最後 0x7B6890 erase tree。Controller slot14 和 Actor slot14 不是同一 interface；同樣 Controller slot0 deleting destructor 不是這裡的 slot14。

    0x004DFBE4 8B 0D A4 A7 FB 00 mov ecx,[0xFBA7A4]
    0x004DFBEC 8B 42 1C          mov eax,[edx+0x1C] ; controller callback
    0x004DFBF8 8B 4F 10          mov ecx,[edi+0x10] ; Actor
    0x004DFC00 FF D0             call eax           ; Actor slot14
    0x004DFC0D 6A 01 FF D0       push 1; call eax  ; Actor slot0
    0x004DFC1E E8 6D 6C 2D 00   call 0x7B6890     ; tree erase

因此26的**本地已證步驟**為 Controller slot14（符合 ID 時）→ Controller slot1C×3（成功刪除時）→ Actor slot14 → Actor deleting destructor/shared-CDoll release → 主樹 erase。沒有在這條直接流程看到按照 CDoll+C 借用指標搜尋 B-vector 的 erase。

### 4.2 命令81，0x004B3710

L≥2 時 count=floor((L−2)/2)，從 buffer+2 各讀 WORD；0x4B3733 OR 0x06000000，再經 0x40F060；0x4B373E 直接 call 0x4DFC90。在 0x4DFC90 逐樹節點比 Actor+0x88 composite、匹配後：

    0x004DFCB6 39 81 88 00 00 00 cmp [ecx+0x88],eax
    0x004DFCC0 8B 42 14          mov eax,[edx+0x14]
    0x004DFCC3 FF D0             call eax           ; Actor slot14
    0x004DFCD0 6A 01             push 1
    0x004DFCD2 FF D0             call eax           ; Actor slot0
    ...                           node+0x10←0, 7B6890 erase

**不同於26**：本函式沒有看到先跑 Controller 三個 raw slot 和三次 slot1C 掃描，也沒有 26 的 0x7A7CC0/0x7A7BF0 CDoll 前置更新。這是具體 handler 的局部差異；不能提升成「81 之後 Controller 全局必定殘留」或「沒有其它上游會清理」。

### 4.3 全場 Actor tree reset，0x004DFE90

用 tree manager+8/+C 逐筆取 Actor，先 Actor vptr+0x14，再 vptr+0（push1），按 tree traversal 處理完後呼叫 0x823850 清樹，最後取得 [0xFBA7A4] Controller 並呼叫其 vptr+0x14。

    0x004DFEA9 8B 07              mov eax,[edi]
    0x004DFEAB 8B 50 14           mov edx,[eax+0x14]
    0x004DFEB0 FF D2              call edx     ; Actor slot14
    0x004DFEB6 6A 01 8B CF FF D2  push 1... ; Actor slot0
    0x004DFF0A E8 41 39 34 00     call 0x823850 ; clear tree
    0x004DFF0F 8B 0D A4 A7 FB 00 mov ecx,[0xFBA7A4]
    0x004DFF17 8B 50 14           mov edx,[eax+0x14]
    0x004DFF1A FF D2              call edx     ; Controller slot14

此 reset 的 Controller slot14 是**在所有 Actor virtual delete 之後**，與26先找 Controller、再刪 Actor 的順序不同。0x4DFE90 函式本身無直接讀寫 [0xFBA838] B queue；不能由此推出完整 Scene shutdown 的其它上游不存在先清空 B-vector。

## 5. 205-04 — 刪除與畫面佇列是否一致：有界驗收矩陣

| 玩家/場景情境 | Client 靜態已證 | B-vector、Controller／P 的邊界 | 是否證明 UAF／安全 |
| --- | --- | --- | --- |
| S2C 本地命令26刪 Monster | 先CDoll條件更新、Controller局部回呼，再 Actor slot14/0、shared release、樹erase | 26 和 4DFBC0 未明示一筆 CDoll+C queue erase；manager可能另行 reset | **未知**：取決於是否已有 queue entry、其它 owner、frame 順序 |
| S2C 本地命令26刪 NPC | 同一樹與 Actor 虛擬介面，NPC 自身 vptr+0 有 +420 額外清理 | 同上，還須區分 NPC 資源 callback | **未知**，非「必定出錯」 |
| 本地命令81移除 | composite lookup→Actor slot14→Actor deleting destructor→樹 erase | 這條沒有26 的 Controller slot14/slot1C 和 CDoll前置更新 | **未知**，不可宣稱其它 Controller 完全未處理 |
| 全場 Actor tree reset | 逐Actor slot14/0→clear tree→Controller slot14 | 這個函式未直接 flush FBA838 B vector；Scene 上游可能另外清 | **未知**，不得由局部無呼叫推全局無清理 |
| Actor 釋放時另一 owner 還持有 CDoll | ctrl+4 減一但非最後強參照，managed CDoll 不在本次被 delete | B entry 仍是 raw pointer，但 CDoll 可能因此存活 | **在其它 owner 保留期間可避免立即 freed，未證整段時序安全** |
| 最後強持有者釋放 CDoll，而 B entry 尚在有效區間 | ctrl vptr+0 → CDoll vptr+0，B 不增加強參照；7BB2FE 直接 virtual call | 若同一 CDoll 的 raw entry 仍可被 dispatch，存在懸空指標所需條件 | **條件式風險推論**，尚未證此順序確實可達 |
| B manager 正常完成 7BB240 consumer | 讀取 entry virtual+4（CDoll+0x0C → 7A8310），最後 end←begin | logical empty；舊slot bytes可殘留但不在有效區間 | **不等於**某次 Actor delete 前已完成清空 |
| Manager 真解構 | 7B8CB0 free B vector allocated storage、清三指標 | 對 entries 不逐筆 release；與 CDoll 強持有分離 | 只證 storage finalizer，不證跨 frame 順序 |

**必要的風險成立條件（非已證 runtime 事實）**：

    A. CDoll 的 7A63C0 成功把 CDoll+0x0C 放入 B[begin,end)；
    B. 在該筆 entry 被 7BB240 消費或 queue 清空之前，所有 ctrl+4 strong owners 釋放；
    C. CDoll vptr+0 完成 managed object 解構/釋放；
    D. 7BB240 仍以舊 entry 解參照並呼叫 embedded vptr+4。

A 的 producer、C 的有條件 deleter、D 的 consumer 及各自的存在性已由原始BIN證明。**A→B→C→D 的特定 runtime happens-before 未證**，包括收包 callback lane、frame render staging、同步/鎖與 Scene reset 的相對順序；不能報告確定存在 UAF、crash 或 CVE，也不能宣稱確保沒有 UAF。

## 6. 205-05 — owner P／Controller／Scene 的界線與可供其它 Task 使用的介面

1. **Owner P**：既有T08-201/202確認 P 為 0x2C owner-record，P+4/P+8 為數值角色關聯、不是本段的 CDoll shared_ptr 或 B pointer；指定 P erase 是 0x4BBAE0→0x4DFC30，依 owner+0xF8 和 P tree 修復。26/81 主 Actor erase 的本地函式不應被誤寫為同時必然 P delete。對 P+4/+8 的其它間接 writer 仍非完整全集，交既有T08-208/相關後續；本205不修改其所有權主張。
2. **Controller**：0xFBA7A4 3 個 raw Actor slots 的匹配、三個 slot1C callback 與 slot14 clear 類型在 26/81/reset 的前後順序有明確差異。Controller 真 deleting destructor slot0 和 H-tree cleanup 是另一生命期，不把「slot14清槽」說成解構整個 Controller。
3. **Scene/B manager**：[FBA838] 的 B4/B8/BC 只保有 queue pointer storage；0x7BB240 兩個已證 direct callers 0x799F94/0x7BA879。Scene 的每幀進入時機及相對於命令26/81的串行/並行先後，需 T07 配合原生 dispatcher/task scheduler 資料核對；不跨界宣稱 GPU 完成。
4. **T02**：補 wire socket receive/framing→本地命令26、81 的確切 opcode/domain，及這些 callback 是否在同一 serialized lane。這是 Client 原生缺口，不得推給新 Server 猜想。
5. **T06**：CDoll+0x1C active resource、+0x124 visual eligibility、+0x8C 與外部資源，與解構時 7A51C0 各 indirect callbacks 所持其它 alias 的資產側依賴。
6. **S00 / Server 待開發**：相容 Server 需讓 Client 既有物件移除/全場清理行為在正確 stage 觸發，但原版 Server 何時刪怪、切波、生成與何時推送命令不是本 Client 靜態資料可以決定的官方規則；由 S00 依既有 REQ/SPEC/GAP/ADR 收件，不能以本205冒稱原版波次政策已被證明。
7. **待遊玩驗證**：在合法且完整的相依原件及 runtime 觀察條件下，分別測 Monster/NPC：spawn→visual B enqueue→26/81/reset→render callback 次序；用 CDoll/control strong count、B begin/end、Controller slot及實際 scene tick time-stamp 對照，同時看多個相同 ID/多個強 owner、切圖、佇列滿／容量擴展。

## 7. 可操作的後續地址與排他主張的限定

### 已從原始BIN直接核過的重點入口

- 收到本地命令：0x4B28D0（26）、0x4B3710（81）；Actor 樹操作 0x4DFBC0、0x4DFC90、0x4DFE90。
- Actor vtables：0xC0C9DC、0xC0CA9C；清理 0x4C8360；共通 destructor 0x4C7B90；shared deleter 0x4CA660；CDoll destructor 0x7A4FF0→0x7A51C0。
- B queue：global pointer [0xFBA838]；producer 0x7A63C0（append 0x7A65D9～0x7A6658）；consumer 0x7BB240（dispatch 0x7BB2F0～0x7BB330）；caller 0x799F94、0x7BA879；manager ctor 0x7B8A50、dtor 0x7B8C80→0x7B8CB0。
- P erase（前段有界來源）：0x4BBAE0→0x4DFC30；Controller [0xFBA7A4]。

### 尚不能下的強結論

- 找不到在 **已列出的這些局部 native call paths** 同步移除 CDoll+C queue slot ≠ 已證全Client沒有間接 cancel／別的持有者。
- Actor/Controller cleanup 的前後排列 ≠ socket callback、render thread 或 frame tick 的實際 happens-before。
- queue end←begin ≠ bytes全清零／CDoll個別刪除／GPU flushed；manager free vector ≠ CDoll freed。
- CDoll raw pointer 與最後 strong release 在靜態上容許討論懸空風險 ≠ 原版遊戲已可觸發 UAF／實測崩潰。
- CDoll CModel 是不同物件；B-vector 不等於 CModel [0xFB7740] 22個桶，不能擅改204與legacy的否證。
- 不能由缺原版 Server 程式就停止仍有來源可查的 Client frame dispatch；也不能憑 Client 推回官方 Server 決策。

### 靜態驗證及重現

本次以原始 KR Tartaros.bin 實際執行同版 Python 檢查：
- size/SHA256、PE MZ/PE00/I386/section VA→raw mapping **PASS**；
- **47/47** 預先固定的 code instruction-byte anchors **PASS**；
- **10/10** 真 .rdata vtable DWORD target **PASS**；
- **8/8** E8 rel32 呼叫目標重算 **PASS**。

對應完整檢查工具另存 T08-205-native-lifetime-verifier.py，運行：
    python -B kr-temp-roy/T08-205-native-lifetime-verifier.py /path/to/Tartaros.bin

腳本只讀 BIN，不執行 Client，且固定 bytes/vtable/calls 以防來源/位址映射錯置；**不是整個程式所有間接 alias 已檢驗、不是T01全文FULL-PASS，也不是GitHub Actions 已在CI執行此本地BIN測試**。

## 8. 後續接棒與完成判定

本205把本題需要的 Actor→CDoll持有、刪除/Controller差異、Borrowed B queue producer/consumer、logical clear/manager teardown 以原始 BIN 和可重現 anchors 閉合，因此按共同規則 **正式完成 T08-205 的有界 Client 靜態目標**。留下的具體 **Client 待逆向**：7A51C0 各 indirect callback/其它 shared owner alias 是否接觸 B entry；T07 render frame dispatcher 的完整時間順序；T02 真 socket wire 與命令 lane；若需全局安全性排他證明，另專題深查所有 B4/B8 間接修改者。**跨功能待整合**：T02/T06/T07 的對應證據；**Server 待開發**：原版不可證的生成/移除策略，由 S00收件；**待遊玩驗證**：實際封包刪除交錯渲染及多 owner 的 runtime case。這些未知不是本有界 Client 主張的假證據，也不能改寫 T08 整體 task.json native_complete、T01 原生審核狀態或任何 RR 的 ACCEPTED。

下一靜態研究若用 T08-206 段號，建議從 B manager/scene tick→7BB240 的 callback scheduling 和 CDoll destructor indirect alias 實際 writer 追起；先查 T07/T02 可信既有成果後再回 BIN，勿原地重做 T08-203/204。