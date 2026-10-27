# T08-112：六係數緩衝生命週期與交接界線

研究者：chatgpt-web roy。2026-10-27 Asia/Taipei。BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91（本輪已用 sha256sum 驗證）；原始 x86 objdump 機器碼一級證據，函式名稱暫定。

## 0x00798DE0：建立而不是動態更新

0x00798DE0 分配 0x60 bytes，對 24 個 float 逐個用 x87 fldz/fst 初始化0，最後保存到 [0x00FB76B0]。此只能證實初始化，不能當作正常遊戲運作中的係數更新者。

~~~asm
00798E3A push 0x60
00798E41 call 0x891268
00798E4D fldz
00798E4F fst DWORD PTR [eax]
00798E51 fst DWORD PTR [eax+4]
00798E54 fst DWORD PTR [eax+8]
00798E57 fst DWORD PTR [eax+0xc]
00798E8D fst DWORD PTR [eax+0x54]
00798E90 fst DWORD PTR [eax+0x58]
00798E93 fstp DWORD PTR [eax+0x5c]
00798E9C mov DWORD PTR [0xfb76b0],eax
~~~

需區分地址槽：0x00FB76A8 = manager pointer槽；0x00FB76B0 = plane buffer pointer槽。在以 0x00FB76A8 為 struct base 的 0x0079B520 呼叫鏈，manager+8 正好落在 0x00FB76B0。以下是讀取測試路徑，不是寫入：

~~~asm
007D13FE push 3
007D1400 push 0xfb76a8
007D140F call 0x79b520
0079B5BC mov edx,[esi+8]
0079B5DA call 0x838860
~~~

## 本輪 109~112 綜合

(1) 0x007AAD9F -> 0x007997A0 -> 0x00799840 註冊 callback, vptr=0x00C4FF8C, slot +0x0C=0x007D1310。
(2) 0x007D1310 消費 caller-supplied owner 的某些桶，按 stage 派送 entry vtable+0x0C，並清零 count。
(3) 0x0079A5F0 經 manager+0xEC 取得介面，0x007D1310/0x0079B520 使用該介面派送。
(4) 0x0079B520 經 manager+8 讀取六係數，供 0x00838860 幾何半空間測試。
(5) 尚未證實 consumer owner == [0x00FB7740]；尚未定位六係數正常非初始化內容寫入者；不能稱其必為相機視錐或場景主更新。

~~~cpp
registerCallback(manager, callbackVptr_C4FF8C);
// caller provides the bucket owner at runtime
consumeBuckets(owner, manager);
// independently read planes through manager+8
geometryTest(manager->planePtr, candidate);
~~~

T08-113 建議：從 callback+0x0C 的實際虛擬派送點確認 owner 實參與桶所有權；沿 96-byte 緩衝 pointer alias 找 x87/SSE store 或 memcpy 內容寫入，必要時動態 data breakpoint。