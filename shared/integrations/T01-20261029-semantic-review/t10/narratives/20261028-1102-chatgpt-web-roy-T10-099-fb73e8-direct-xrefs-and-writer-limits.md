# T10-099 — 全域 0xFB73E8 直接 xref 審核與 writer 搜尋界線

## 來源
KR PE32 x86 Tartaros.bin; SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91; EXE SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f. Both re-hashed locally. BIN .text VA 0x401000/raw 0x400, .rdata VA 0xBD2000/raw 0x7D0600, .data VA 0xD61000/raw 0x95E800 (verified via objdump -h). Static read-only disassembly, no program execution.

## 直接引用掃描方法
以 Python 在 BIN PE .text raw [0x400,0x7D0600) 搜尋 little-endian `e8 73 fb 00`，將 raw offset 按 VA=raw+0x400C00 轉換。找到立即值出現地址：0x4A97FF、0x4B25D0、0x4C8613、0x4E00FA、0x4E8C42、0x4F1E19、0x4FE21F、0x4FE4C5、0x53A32C、0x53ED1B、0x53FFAF、0x5548C7、0x56023B、0x59623D、0x5973F0、0x597467、0x59A288、0x5A4616。注意此清單是 4-byte literal 位置，通常落在指令中段，並非每一項都是合法 instruction start；不應拿來當函式入口。

## 實際寫入證據
[code block separately checked in preflight]

在 0x560239 時，EBX 可向前追到 0x560197 的 xor EBX,EBX，因此已觀測的明確 writer 是**初始化清零**。大量 CMP/讀取點使該全域具備門控多處流程的作用，但並不能倒推它曾在哪裡非零寫入，更不能自行命名為戰鬥狀態／技能狀態。0x59623B 以 EDI=0 判斷是否設過非零旗標，影響 ID 13/14 的派送。

## 限制與下一階段搜尋
這一輪的 raw literal 掃描無法排除 base+offset、指標別名、memcpy、間接回呼。若要宣布 writer 閉合，必須：定位全域持有者初始化、追址 0xFB73C0 附近結構的所有賦值來源；對每個 nonzero store 建立 register def-use；同時確認是否存在外部寫入。**沒有確認非零寫入者，亦沒有解析該旗標的業務語義**。
