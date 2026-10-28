# T10-100 — 百段階段核對：KeyMapping、phase、listener、結果容器與動作缺口

## 原始來源
KR PE32 x86 Tartaros.bin; SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91; EXE SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f. Both re-hashed locally. BIN .text VA 0x401000/raw 0x400, .rdata VA 0xBD2000/raw 0x7D0600, .data VA 0xD61000/raw 0x95E800 (verified via objdump -h). Static read-only disassembly, no program execution.

## 目前可獨立重現的鏈
1. KR KeyMapping 原件在 kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt；Type0 MapButton 13..16 的 Key=44..47、ModKey=0 是原始 XML 字面值。DIK Z/X/C/V 為掃描碼慣例候選，尚未核對輸入裝置 producer。
2. 0x6D1A70/0x6D4DC0 是映射 bank 選擇/配置查詢，0x4A1440/0x6D0D10 分別涉 Type0/1 複製到第三工作 bank 與外部配對資料回填。MapButton 是映射 ID，不能未經資料流證明直接當 action opcode。
3. 0x6D4CE0 讀普通 ID 0..39 的 byte[0xFB9004+ID]，以及高 ID 關聯容器；0x6D4A30 的絕對位址 DWORD writes 和事件迭代 stores 都屬清零，不是非零 phase writer。
4. 0x5961C0 遍歷 40 個普通事件 ID，phase 1/3 通過 0x761010 候選子物件、0x596140 listener bucket、owner 自身 vtable +0xEC/+0xF0；當 0xFB73E8 非零時，此條函式只放行 ID13/14。
5. **新確認**：成功事件可流向 0x596351，呼叫 0x74D700 配置 12-byte node，插入呼叫者提供的結果容器並增加 count。這只是「回調成功結果列表」，不是原生攻擊連段 queue。
6. 0xFB73E8 的明確直接 writer 0x560239 是零初始化。0x5A4614 依其真假與 owner+0x154 做狀態比較，經 0x5A55E0 更新 +0x158/+0x15C 並分配子物件；尚不能確定對應角色動作。

## T10-097～100 新增與可否驗收
T10-097：成功結果節點 allocation/append 結構定錨（已確認）。T10-098：物件旗標篩選與 listener bucket 早停（已確認）。T10-099：0xFB73E8 little-endian literal xref 集合，仍缺 nonzero writer（部分確認）。T10-100：將兩條半鏈分層、禁止誤認 combo queue（結論性邊界）。沒有發現足以將 T10 標 native_complete 的證據。

## T10-101 下一段優先
(A) 追成功結果 list 的呼叫者與後續 consumer（0x596351 之 [ebp+8] 來源及其元素生命週期）；(B) 查找 +0xEC/+0xF0 overrides 的實際 vptr，確認是否接觸 controller/motion；(C) 以 dataflow 追 [0xFB9004+ID] 的非零 phase writer，不能再重述 reset；(D) 查 0xFB73E8 的間接/別名非零寫入；(E) 查 Key44..47 裝置 producer、Type1 fallback 與玩家現用自訂配置。若無一手證據，不填原版連段秒數，不使用 AI CHAIN_WINDOW=0.65 或 >500ms/AI server 排程替代。

## 原始限制與版本管理
唯讀 KR BIN、GitHub KR 原 XML；不同 Task 的成果僅引用，不改 owner/catalog，不上傳原始遊戲檔。此處每條確認只達到列出的 VA 指令資料流，不等於整個 gameplay 功能可玩驗收。
