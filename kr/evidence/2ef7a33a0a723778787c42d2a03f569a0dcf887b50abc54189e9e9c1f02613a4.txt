# T08-083 復用池與管理器生命週期（完整本機原筆記另存，本檔為整合摘要）
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91

0x007DCFB0 取得資源時先檢查 manager+0x7C 與 +0x80，非空則自尾端取出，交給 0x007BE5B0 reset；空才新建。
```asm
007DCFC9 mov eax,[ebx+7Ch]
007DCFCC cmp eax,[ebx+80h]
007DCFD2 je 007DD00A
007DCFDA mov esi,[eax-04h]
007DCFDF call 007BE5B0
007DCFF2 mov [ebx+80h],eax
```
0x007AAF1F 上游呼叫啟用延遲回收 0x007B7FD0；0x007AB155 上游呼叫排空/停用 0x007B8030。0x007B8522 增 manager+0x5C，0x007DD12A 減，歸零時清理池。0x007DCFB0 增 manager+0x60、0x007BE5F0 減。池應稱為共享資源復用池而非僅待刪除佇列。
