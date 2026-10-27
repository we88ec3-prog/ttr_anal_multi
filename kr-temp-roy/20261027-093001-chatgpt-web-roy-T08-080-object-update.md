# T08-080 共用更新與資源解除（由對話紀錄重建）
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91

0x004C8580 的直接轉接：0x004CDD49、0x004D0F84、0x004D1683、0x004D1AE0(jmp)、0x004D2894。object+0x36C 由更新函式遞減／重設30，後呼叫 0x004C83C0；更新函式另遍歷128槽並將關聯數據寫入 +0x28/+0x2C/+0x30，置 +0x70=1。

```asm
004C86BC mov eax,[ebx+36Ch]
004C86C7 mov [ebx+36Ch],eax
004C86CF mov dword ptr [ebx+36Ch],1Eh
004C86DA call 004C83C0
007BE5F9 dec dword ptr [eax+60h]
007BE60F call 007DD1A0
```
0x007BE5F0 是資源解除關聯並遞減管理器計數的入口，特定條件走同步容器，否則批次清理；返回會清掉持有指標。尚未確認固定 frame 頻率或全部虛擬呼叫者。
