# E31 — RR-0005／RR-0003：UI 事件接收器函式指標、樹節點回收與 0x13 橋接證據邊界

日期：2026-10-29（Asia/Taipei）。原始 KR Tartaros.bin 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，當次實際確認。原始資料唯讀，未執行。GitHub main 工作基準從開工確認；跨 Task E31 證據支援 T02 RR-0005／T03 RR-0003，不認領、不變更 RR 或主線。

## 第 1 輪：C1C4F0 方法表的實際覆蓋與缺失的物件建構證明

直接從原始 .rdata 以 `raw=VA−0xBD2000+0x7D0600` 解出 VA `0xC1C4B0..0xC1C54C` 的連續 dword：

```text
C1C4C0 5F5D10    C1C4C4 5F5D10
C1C4C8 550450    C1C4CC 406FD0
C1C4D0 74A120    C1C4D4 476430
C1C4D8 476430    C1C4DC 75B110
C1C4E0 4067E0    C1C4E4 4067E0
C1C4E8 476430    C1C4EC 476430
C1C4F0 66C620    <-- event receiver candidate
C1C4F4 757180    C1C4F8 403DB0
C1C4FC 757130    C1C500 406FC0
C1C504 476430    C1C508 8DC2F0
C1C50C 406F90    C1C510 4221E0
C1C514 745160    C1C518 756FB0
C1C51C 7569C0    C1C520 7567D0
C1C524 7569A0    C1C528 7569B0
C1C52C 00000000  C1C530 C6F3AC
```

在整個原始 BIN 尋找 little-endian `0x66C620` 出現 **一次**，位於 `.rdata` raw `0x81AAF0`，VA `0xC1C4F0`。這證明 **static function pointer table entry**；但不是已證「物件 vptr 安裝」：本輪對 table 內 `0xC1C480..0xC1C4F0` 每個 4-byte 對齊的候選表地址執行全檔 little-endian 直接常數搜尋，均未找到該候選地址本身的常數引用。這是 *negative limited scan*，不能排除 table 首址更早、非 4-byte 起點、基址+位移、relocation 修正、間接地址/動態指標，或其他 module 提供指標。

所以 E30 寫的「vtable-like」目前僅是**合理候選**，不是已證 class name、vtable start、slot offset、constructor。`0x66C620` 無直接 E8 caller，同樣不能斷定無間接 caller。接下來須先定位表起點或物件型別，再證事件 producer 到此方法。

## 第 2 輪：erase 操作的資料所有權嚴格辨認

`0x806C91..0x806CD2` 的重複鍵路徑：以 key address (`[ebp+0x10]`) 在 transport keyed tree 搜索 `0x8438C0`，若非 sentinel，呼叫 `0x7B6890` 移除先前 node，再以 `0x57EF20` 分配 node、`0x57E850` 執行有序插入。

`0x7B6890` 內直接有 parent/left/right relink、紅黑樹式再平衡，以及以下尾段（原始 BIN，objdump 指令邊界）：

```asm
7B6AB0 mov byte ptr [esi+0x14],bl
7B6AB3 mov ecx,[ecx]
7B6AB5 mov byte ptr [ecx+0x14],bl
7B6AB8 push edx
7B6AB9 mov ecx,esi
7B6ABB call 0x43E670
7B6AC0 mov byte ptr [edi+0x14],bl
7B6AC3 mov edx,[ebp-4]   ; removed node allocation
7B6AC6 push edx
7B6AC7 call 0x89120C    ; heap free
7B6ACC mov ecx,[ebp+8]  ; tree object
7B6ACF mov eax,[ecx+8]  ; count
7B6AD8 test eax,eax
7B6ADA je 0x7B6AE0
7B6ADC dec eax
7B6ADD mov [ecx+8],eax
7B6AE0 mov ecx,[ebp+0x10]
7B6AE3 mov eax,[ebp+0xC]
7B6AE6 mov [eax],ecx     ; returned iterator pointer
7B6AEB ret 0xC
```

`0x57EF20` 的 node allocation 為 `0x18` bytes，key 位於 node+0x0C，Conn* 位於 node+0x10。`0x7B6AC7` 所 free 的是 tree node，不是對 node+0x10 的 Conn* 解引用後呼叫 destructor。**已確認：舊 tree node 釋放、size 減一、iterator 輸出。未證：舊 socket 被 close、Conn* 被釋放、重連後事件順序。** 需要找 explicit close/socket dispose path，不能把 tree node remove 當成 connection lifetime end。

## 第 3 輪：0x13 packet result-to-UI bridge 搜尋結果與研究邊界

目前的 native chain 是 `0x66C620(event 0x70A/0x578, identity gate) -> 0x66C090 -> 0x4957C0 -> 0x806AD0(conn key0/2)`；其 event sender/registration upstream 尚未定位。已知 `0x66C620` 的函式指標表項 **不足以把它對應到 T03 auth S2C 0x13 consumer**；兩者的 input 不同（UI event object+0x10 vs network framed command/status），需要另有明確分派/回呼觸發證據。E31 不將二者硬接。

完成條件分層：
- **已確認**：static table entry 0xC1C4F0 -> 0x66C620，重複 keyed-tree node 的 erase/free/count/iterator 流程。
- **合理推測**：方法表可能供 UI 虛擬事件接收；具體 vptr 起點未證，故不能視為 class constructor identified。
- **Client 待逆向**：真正 event producer、method table owner、0x13 native consumer-to-event bridge、舊 Conn* close/reuse、每 connection first frame。
- **Server 待開發**：不得依 UI 值 0x578/0x70A 推測官方登入結果狀態或 server port policy。
- **跨功能待整合**：T02 RR-0005 與 T03 RR-0003、T03 RR-0002 及 T05 handoff。
- **待遊玩驗證**：原 Client↔新 Server trace，失敗/重連/首次封包。

三輪皆有記錄：第 1 輪確認 table-entry 並發現「無直接 vptr 常數」的明確反證；第 2 輪把 erase 的 heap/Conn ownership 拆開；第 3 輪確認尚無 0x13→UI bridge，不假稱完成正式 RR。下段優先進行 RTTI/function table owner 逆向、T03 0x13 receive parser/consumer 直接證據和 Conn* close callers。

### 重驗指令

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x7b6890 --stop-address=0x7b6aee Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x66c620 --stop-address=0x66c71b Tartaros.bin
```