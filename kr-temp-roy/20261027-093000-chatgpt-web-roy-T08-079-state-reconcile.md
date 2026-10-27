# T08-079 狀態資源回收（由對話紀錄重建）
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91

0x004C83C0 在 object+0x36C 倒數為零時掃描 object+0x164 開始的128個指標。0x00826280 在 object+0x3F0 狀態樹查當前 stateId；不存在且槽非空，呼叫 0x004C7DB0 並清空槽。

```asm
004C83CA cmp dword ptr [esi+36Ch],0
004C83F3 call 00826280
004C8400 jne 004C842F
004C841E call 004C7DB0
004C8426 mov dword ptr [ebx],0
004C8436 cmp edi,80h
```

命令151更新樹卻不立刻清128槽，舊資源可以暫時保留。0x004C9840 直接按 stateId 索引槽，所核對指令沒有顯式 128 邊界；上游檢查仍待驗證，不能當作確認漏洞。
