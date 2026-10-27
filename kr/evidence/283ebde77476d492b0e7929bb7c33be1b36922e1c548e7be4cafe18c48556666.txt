# T08-082 共享資源池消費端（完整本機原筆記另存，本檔為整合摘要）
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91

0x007DD1F0 消費 manager+0x7C/+0x80 指標陣列：
```asm
007DD203 mov eax,[esi+7Ch]
007DD206 mov ecx,[esi+80h]
007DD20C sub ecx,eax
007DD20E sar ecx,2
007DD21B call 007BE0F0
007DD232 call 007BD850
007DD238 call 0089120C
```
0x007B8030 批次排空資源池並關閉延後模式，0x007B7FD0 啟用延後模式。0x007DD100 對 manager+0x5C 計數歸零執行清理，+0x60 是不同層級計數。+0x7C 容器的可復用能力在 T08-083 進一步確認。
