# T10-097 — phase dispatch 的成功結果容器與 12-byte node

## 來源
KR PE32 x86 Tartaros.bin; SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91; EXE SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f. Both re-hashed locally. BIN .text VA 0x401000/raw 0x400, .rdata VA 0xBD2000/raw 0x7D0600, .data VA 0xD61000/raw 0x95E800 (verified via objdump -h). Static read-only disassembly, no program execution.

## 新 BIN-first 指令
[code block separately checked in preflight]

## 資料流與推論界線
0x596351 由事件 listener 回傳非零後抵達，從呼叫者提供的 [ebp+8] 取得結果容器 EBX，讀 sentinel/首節點 [ebx]、節點 +4，並傳遞局部 [ebp-0x24] 地址給 0x74D700。該 helper 配置 0xC bytes 並以實參初始化 node+0、+4、+8；返回新指標後 callsite 增加 [ebx+4] count、修改前後指標。其 0x3ffffffe 容量保護走到 0x596433 錯誤路徑。**新增確認：這是多型分派成功後的結果鏈表追加，不是未經驗證的「普攻連段 queue」。** [ebp-0x24] 在讀取 ID 的循環中先寫 edi，故 node+8 對應本輪事件 ID 候選；不代表可持久排程下一次攻擊。

## 本段保留的差異與問題
該鏈表與全域 phase bytes [0xFB9004+ID]、特別事件容器 0xFDF630、owner+0x80 observer 結構皆不同；不可僅憑相同節點 offset 混同。需追呼叫者傳入 [ebp+8] 的容器所有權、清空/消費時序及結果 list 下一階段 consumer；但該追加呼叫發生在 phase reader 和虛擬回呼之後，不是產生 phase 1/3 的證據。此段尚未證實 Z、V 或 motion。
