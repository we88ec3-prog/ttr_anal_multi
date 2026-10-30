# T10-108 — KR 解析後收包→queue producer→分類取出→應用分派：BIN-first 有界閉環

## 0. 版本、原稿、變更權限

2026-10-28 Asia/Taipei，唯讀靜態分析 `/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。KR PE32 `.text` VA=raw+0x400C00；所有列出的 bytes/VA 從本次 `objdump -D -Mintel` 擷取。研究只對明確反組譯視窗成立；既有 T10-106 原稿作導航，不替代本次機器碼。未執行/patch Client，無線上封包樣本。分支 `t10/roy/chatgpt-web`；`main` 未修改。

前置歷史：工作分支已 merge `roy/t10-101-103-20261028`，完整 101～106 及另一組 101/102 原稿保留；107 是整合/勘誤導覽，不是 BIN-first 正式分析。T10-108 以 T10-106「queue record+8 資料來源未閉合」作入口，追到收包 frame 處理層；不把應用 key 直接升格成 socket 原始 wire opcode。

## 1. 新 native 鏈：frame consumer `0x807B60` 的邊界

在 `0x807B85..0x807BD0`，參數/暫存器沿用調用時 ABI：`EDI=EDX` 為緩衝區 owner 候選，`[edi+0x5000]` 為目前有效範圍終點，`EBX=EDI` 指向目前 frame，`EDI` 與 owner 的具體 C++ 符號未知。`0x807BB0 movzx esi,word [ebx]` 讀首 WORD 作 frame payload length 候選；值 0 或 >0x1000 都跳 `0x807E1D`，不是任意長度直送。`0x807BD4 movzx ecx,word [ebx+2]` 讀另一 WORD；若為 `0x2633` 則總前綴 8 bytes，若 `0x0BBB` 則 6 bytes，通常 4 bytes。`0x1A68`/`0x22D7` 均仍為4。這些值在 frame 層作分支，不是 T10 已確認的技能 opcode。`0x807C34` 使用 `len + prefix` 對剩餘緩衝長度做有界檢查，需足夠才解資料。對 packed/protected 的不同 frame，payload 實際取得路徑不同。

```asm
807b85  mov eax,[ebp+8]
807b88  mov edi,edx
807b8a  add [edi+0x5000],ecx
807b94  mov eax,[edi+0x5000]
807b9a  sub eax,edi
807bb0  movzx esi,word [ebx]
807bb5  cmp si,cx
807bb8  je 807e1d
807bbe  mov edx,0x1000
807bc3  cmp si,dx
807bc6  ja 807e1d
807bd4  movzx ecx,word [ebx+2]
807be5  cmp cx,0x2633
807bea  mov [esp+0x18],1
807bf2  mov [esp+0x20],8
807bfc  cmp cx,0x0bbb
807c06  mov [esp+0x1c],1
807c0e  mov [esp+0x20],6
807c34  mov ecx,esi
807c36  mov esi,[esp+0x20]
807c3a  add ecx,esi
807c3c  cmp ecx,eax
807c3e  jg 807dda
```

**重要限制**：這是解析器收到其所需 buffer 的證據；本段尚未定位 WinSock recv 的確切 caller 與 wire 原始數據是否經其他轉換，故稱「frame consumer」，不稱原始線上 packet bytes schema。

## 2. frame→queue 的兩條明確出口

`0x807D2C..0x807D75` 確認有條件的 per-byte XOR/checksum 型步驟：首位 `xor 0xB6`，其後與局部既有 bytes XOR，並累加 `CX`；與 `[ebx+4]` WORD 比對，不同就 `jne 0x807D7F`。這是 native 校驗分支，不能自行宣稱標準壓縮或加密演算法。另一條在 `0x807CF4` 呼叫 `0x727190`，其返回值0時走 `0x807D1A..D2A`，以局部輸出陣列進入共同 copy helper `0x807E50`。未分析 `0x727190` 完整語意，故其轉換類型未知。

`0x807E50` 是可驗證的 bounded copy，ESI 是長度且必須 `<=0x1000`；`memcpy` 型 callee `0x89DBD0` 的輸入是 caller 推入的 payload buffer，目的 `EDI+8`，完成後 `[EDI+4]=ESI`，成功 AL=1；超過界限 AL=0。從這裡可直接得出 queue record `[+4]` 長度、`[+8]` buffer，**不需要用類名推測**。

```asm
807e53  cmp esi,0x1000
807e59  jbe 807e61
807e5b  xor al,al
807e5e  ret 4
807e61  mov eax,[ebp+8]
807e64  push esi
807e65  push eax
807e66  lea ecx,[edi+8]
807e69  push ecx
807e6a  call 0x89dbd0
807e72  mov [edi+4],esi
807e75  mov al,1
807e78  ret 4
```

**新增 producer 關聯**：`0x807D7F..0x807DB2` 在 copy/校驗處理後，`[esp+0x28]` 指向 frame/queue 暫存項，從 `[item+4]` 檢查長度。若為零，呼叫 `0x804310` 初始化單例並進 `0x8076F0`；若非零，從 caller context 的 `+0xA080` 取選擇參數，呼叫 `0x489920`，其後 **唯一明確的 `call 0x8040A0` 在 `0x807DAD`**。原生 E8 bytes `e8 ee c2 ff ff`。從 `0x807D9E` 開始：

```asm
807d7f mov eax,[esp+0x28]
807d83 cmp dword [eax+4],0
807d87 mov ecx,[esp+0x24]
807d8b mov [eax],ecx
807d8d jne 807d9e
807d8f push eax
807d90 call 804310
807d97 call 8076f0
807d9e mov ecx,[ecx+0xa080]
807da4 push ecx
807da5 push eax
807da6 call 489920
807dab mov edi,eax
807dad call 8040a0
```

這條有界 producer 可追至前段 T10-106 的全域 queue owner `0xFC10D0`；但 `0x489920` 返回值 EAX 與進入 `0x8040A0` 所需 EDI/EBX 的完整 def-use，仍應核對其實作、類別 selector 實際值與接收執行緒。**不可直接宣稱所有 000A/000D 相關封包一定經這條特定 queue**。

## 3. queue ownership 與多類 drain 的原生控制

`0x8040A0` 以 caller EDI 作 queue owner、`[ebp+C]` 作分類，透過 `[edi+0x124]` 作同步鎖操作，按 `[ebx+edi+0x128]` toggle 及 `2*category + toggle` 定位 24-byte 子容器，然後 `call 0x804260` append item。`0x804260` 使用 `[esi+8]`、`+0xC`、`+0x10` 控制 ring-like segmented storage，必要時配置0x10 bytes的小塊並寫入傳入 DWORD；本段僅稱 queue record 指標存取，不擴展為所有 Game 消息的調度規則。

`0x804100` 是 consumer：從 `category` / toggle 定位當前 24-byte bucket；有元素時用 `0x542210` 取元素，寫到 caller-supplied output pointer，並更新 container index/count。**新增失敗路徑**：若第一候選 bucket count==0，`0x804196` 開始選擇 alternate toggle bucket；如果也空則 `0x804253` 返回 AL=0，否則複製 DWORD 後 AL=1。`0x8041BA..D8` 有同步的 toggle 更新，不能把此策略簡化為單一 FIFO；也不能僅因 alternate 命中就假設嚴格 chronological ordering。

`0x804740` 的 drain 成對調用 `0x804100`：第一次 `0x804841` 取得 item，callback 之後若條件允許 `0x8049B2` 再取；外層在 `0x8049CD..E1` 循環分類範圍，`inc esi` 到6為止（本段可見是6類迭代，不能稱恰有6種 wire opcode）。實際 callback 參數來自 queue item 的 `+0`, `+4`, `+8`，另帶 category。`0x4930E0` 在 category==2 且 length 非零時讀 payload 首 WORD 當應用 key，走前段 T10-106 已確認的 `0x48AAD0 → active state → ParamUpdate` 條件路徑。

```asm
804837 push esi
804838 lea eax,[ebp-0x10]
80483b push eax
80483c mov eax,0xfc10d0
804841 call 804100
804846 test al,al
804848 je 8049d0
80485f mov eax,[esi+4]
804862 push ecx
804863 push eax
804864 lea eax,[esi+8]
804867 push eax
804868 mov eax,[esi]
80486a push eax
80486d call edx
8049a5 mov eax,[ebp+8]
8049ad mov eax,0xfc10d0
8049b2 call 804100
8049bf jne 804850
8049da inc esi
8049de cmp esi,6
8049e1 jl 804826
```

`0x4930ED` 對 `payload[0:2]` 的 WORD 讀取出現在 `length==0` 測試前，**本函式本體沒有 len>=2 的保護**；即使 queue record+8 物理上帶固定緩衝，也不能由此推出入隊資料必大於等於2。`0x807E50` 允許 length0 copy，此路徑或其他上游約束是否保證分類2永不為0需更完整驗證。

## 4. 生命週期、分支與不得跨越的結論

本段新證據比 T10-106 更進一步：有至少一個 **frame parser → bounded copy → queue append → category/toggle drain → virtual callback** 的條件控制流；上段已確認 category2 callback 後才讀 P 首 WORD 作應用 key。**它閉合 queue producer 的一條結構性支鏈**，但不能當成已見實際 socket recv、原始 wire key、伺服器接受普攻或技能動作。不同 frame signature `0x2633`, `0x0BBB` 是 frame 分支常數，不是 gameplay opcode。

| 玩家情境 | Client / producer | C→S | S→C | motion / 分工 |
|---|---|---|---|---|
| Z 按下（確實映射 ID13） | 既有原稿條件鏈可至000A；本段不重驗 sender | 條件式有編碼路徑，並非每按必發 | **未建立**000A→本 receive queue 的因果 | 本地起手、接受/拒絕仍 unknown |
| 長按 / 放開 Z | T10-101 phase1/2/3 的 producer 已有條件證據 | 封包次數、節流仍 unknown | 回包是否逐次仍 unknown | 續段/取消 unknown |
| 收到合法長度且通過前處理的 frame | `0x807B60` 判 len及prefix，`0x807E50` 複製 | 本段不涉及上行 | 可有條件 append，之後 queue drain | category2 才會進指定 app dispatcher；不同分類不可混同 |
| queue bucket 目前為空 | 先切 alternate bucket 再取，兩者空才 false | 無本段上行證據 | 取不到 item 無 callback | 不是沒有 server 送包之證明 |
| category2 且 app key0 | 本地 header 與分派見 T10-106 | 不是已證對000A的 ack | 有條件進 ParamUpdate property4 setter | 動作/攻擊因果仍未知 |
| 技能施放中鍵盤或滑鼠移動 | 本段沒檢驗移動 producer | unknown | unknown | 不套此 queue 推定取消規則 |

## 5. 證據分級、重驗與正式段門檻

- **原生已確認**：frame len 0/超0x1000擋住、signature分類決定4/6/8前綴、`len+prefix` 邊界、XOR/checksum有界視窗、`0x807E50` 0x1000 copy限額、`0x807DAD→0x8040A0` direct call、`0x804100` alternate bucket、`0x804740` 循環6分類與2個取出 site。
- **部分確認**：`0x489920` 與 queue owner 的具體記錄/selector、所有 frame 是否必經此 parser、signature 的完整語意、分類2究竟如何在 producer 指定、`0x727190` 的轉換。
- **尚待驗證**：socket recv/解碼到 `0x807B60` 的 caller、queue 到接收網路原始 bytes 的全鏈、000A對應的回覆、000D motion的本地/遠端差別、施放中輸入、原版Server裁決。

本次第1輪已取得 T10-106 明示欠缺的 queue producer 入口 `0x807DAD` 及 frame branch/bounded copy/alternate toggle 的**重大原生增量**，因此不啟動108-2/108-3；這不等於 Task FULL PASS 或封包端到端完成。下一段先以`0x807B60` 的真實上游 socket caller 和 `0x489920` record classification、`0x727190` 轉換為優先；務必另取得 S→C motion handler 對照及原版 SkillMatrix 值，拒絕自製 combo 時窗。

## 6. 重現指令

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -D -Mintel --start-address=0x807b60 --stop-address=0x807e20 Tartaros.bin
objdump -D -Mintel --start-address=0x807e50 --stop-address=0x807e7b Tartaros.bin
objdump -D -Mintel --start-address=0x8040a0 --stop-address=0x804260 Tartaros.bin
objdump -D -Mintel --start-address=0x804740 --stop-address=0x8049e5 Tartaros.bin
objdump -D -Mintel --start-address=0x4930e0 --stop-address=0x493161 Tartaros.bin
```