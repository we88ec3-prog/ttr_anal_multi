# T03-18 — KR 0x4918xx 為 Print Screen／D3DX 畫面擷取支線：原生匯入表定性與 worker 來源隔離

- 研究者：chatgpt-web roy；時間：2026-10-29 00:12:16 Asia/Taipei（建立原稿當下本機時鐘）。
- 主要原件：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本段由 `sha256sum` 重新核對。
- PE32、.text VA `0x401000`、raw `0x400`；`.text` raw offset = VA − `0x400C00`。以下為原生 `objdump -D -Mintel -j .text`、`objdump -p` 的第一手證據；未執行或修改客戶端。
- GitHub：起始 `main...t03/roy/chatgpt-web` = ahead／behind 0；T03 專用分支。共用 FULL-PASS 請依 T01 索引判定，不將本局部分析自升級為 FULL-PASS。

## 重大新發現：T03-15～17 追查的介面原來是圖形擷取而非選角回覆

`0x491808` 將 Win32 `VK_SNAPSHOT` 鍵碼 `0x2C` 傳入 **GetAsyncKeyState**（PE IAT `0xBD2478`）；它並非一般未知遊戲 gate。其下游 `0x4918C1/0x491905` 對 `[local_source+0x10]` 的未知 COM 介面呼叫 `vtable+0x48`，後續至少一路明確進入 **D3DXSaveSurfaceToFileW**（IAT `0xBD25F4`），另一路進入 `0x6D7840`，呼叫 **D3DXCreateTexture**（IAT `0xBD2618`）和 **D3DXLoadSurfaceFromSurface**（IAT `0xBD2614`）。四個以上 Windows/D3DX 的原生 import 名稱與 callsite 相互補強，能有界地判斷這是一條**按鍵觸發的畫面擷取／圖片儲存流程**，而非 command `0x42` S→C handler；但本段仍不命名該 COM 介面具體類別或 vtable target。

前段 T03-15～17 對 output-slot alias 的 Assembly 描述仍可保留；其**角色業務意義應修正**：該 output-slot 位於獨立的圖形支線，不能單靠時間上鄰近 `0x49197F → 0x804740` 就當成角色登入／Server 回覆的資料來源。`0x49197F` 用到的 `[esp+0x20]` 若屬更高層物件，仍須完成跨分支 SSA／def-use 和來源追蹤；畫面擷取這一分支不能代替 worker vtable constructor 証據。

## 第 1 輪：IAT 綁定與上游 gate

原生 import-directory excerpt：

```text
007d2478  GetAsyncKeyState
007d25f4  D3DXSaveSurfaceToFileW
007d2614  D3DXLoadSurfaceFromSurface
007d2618  D3DXCreateTexture
007d20f8  GetLocalTime
```

注意 PE image base `0x400000`：`objdump -p` 印出的 `007d2478` 是 RVA-relative descriptor 輸出，程式實際 IAT VA 為 `0xBD2478`；不能混為程式碼 VA。

```asm
491808: 6a 2c                   push 0x2c
49180a: ff 15 78 24 bd 00      call dword ptr [0xbd2478]
491810: 84 c0                   test al,al
491812: 0f 84 13 01 00 00      je 0x49192b
491867: 80 3d 25 92 fb 00 01   cmp byte ptr [0xfb9225],1
491892: 75 47                   jne 0x4918db
4918a5: 8b 4c 24 3c            mov ecx,[esp+0x3c]
4918a9: 8b 41 10               mov eax,[ecx+0x10]
4918ba: 8b 10                  mov edx,[eax]
4918bc: 8b 52 48               mov edx,[edx+0x48]
4918c1: ff d2                  call edx
4918d3: ff 15 f4 25 bd 00      call dword ptr [0xbd25f4]
4918ed: 8b 46 10               mov eax,[esi+0x10]
491902: 8b 41 48               mov eax,[ecx+0x48]
491905: ff d0                  call eax
491913: e8 28 5f 24 00         call 0x6d7840
```

`GetAsyncKeyState(0x2C)` 對應 Windows Print Screen，並非已確認的「選角 state 0x2C」。`test al,al` 的判斷只反映低位元組狀態；無 runtime 不推斷按下事件被觸發的真實頻率。`[source+0x10]` 的 vtable+0x48 由圖形 IAT 下游文脈判定為圖形相關介面候選，**函式目標/具體 Direct3D interface 未辨識**。

## 第 2 輪：D3DXCreateTexture → D3DXLoadSurfaceFromSurface

```asm
6d7840: 55                    push ebp
6d785b: 56                    push esi
6d785d: 8b f2                 mov esi,edx
6d785f: 8b 06                 mov eax,[esi]
6d7861: 8b 50 30              mov edx,[eax+0x30]
6d786b: ff d2                 call edx
6d7879: 50                    push eax
6d787a: 6a 01                 push 1
6d787c: 6a 14                 push 0x14
6d787e: 6a 00                 push 0
6d7880: 6a 01                 push 1
6d7885: ff 15 18 26 bd 00     call dword ptr [0xbd2618]
6d788b: 8b 85 64 b1 ff ff     mov eax,[ebp-0x4e9c]
6d7891: 8b 08                 mov ecx,[eax]
6d789d: 8b 41 48              mov eax,[ecx+0x48]
6d78a0: ff d0                 call eax
6d78b6: ff 15 14 26 bd 00     call dword ptr [0xbd2614]
6d78ca: e8 e1 00 00 00        call 0x6d79b0
```

`vtable+0x48` at `0x6D789D` belongs to a temporary interface produced through `D3DXCreateTexture`, not proven to equal the earlier `[source+0x10]` interface. `0x6D7840` allocates a large stack frame (`0x4EA0`) and operates on surface/texture copies, reinforcing classification as graphics processing, not an S→C game opcode dispatcher. No wire opcode, socket or packet parse has been identified in this branch.

## 第 3 輪：反證與回到接收 worker 的正確界線

Worker processing continues along a **different** bounded chain already verified in T03-9～12:

```asm
49197f: 8b 7c 24 20           mov edi,[esp+0x20]
491983: 8d 9f 40 01 00 00     lea ebx,[edi+0x140]
491989: 53                    push ebx
49198a: e8 b1 2d 37 00        call 0x804740
804858: 8b 13                 mov edx,[ebx]
80485a: 8b 12                 mov edx,[edx]
80486d: ff d2                 call edx
```

`0x804740` consumes shared receive records and calls its worker vtable+0 with record parameters. This **does not** show the target implementation, its business opcode, or a matching response to command 42. The screenshot branch is not evidence that its graphics surface pointers are stored at worker+0; do not transfer vtable identity across classes merely because offsets match.

- Concrete correction to T03-17: earlier statement "IAT `0xBD2478` name not bound" is superseded by verified `GetAsyncKeyState` import. Earlier vtable/slot byte addresses remain valid, but the previously open *business relevance* is now bounded as screenshot graphics context.
- Concrete correction to T03-15/16: an output-slot alias can be true as a local stack fact while being irrelevant to game packet decoding. Preserve facts, retract unjustified application semantics.
- Source-derived vs inference: names of imported D3DX and Win32 API are **native**; calling this a screenshot processing branch is a highly supported functional inference; naming any original C++ class or identifying worker vtable remains **unknown**.

## 玩家情境矩陣及需求分類

| 情境 | C→S | S→C | Client/UI 效果 | 證據分級 |
|---|---|---|---|---|
| 玩家觸發 Print Screen | 無新增網路指令確認 | 不適用 | Print Screen gate → graphics interface → D3DX surface save/transfer | 原生 IAT + native call; 圖形用途高度可信 |
| 玩家選擇角色 | T03-3 已有 `0x42` 4-byte builder；T03-4～6 傳送通道仍有 gate | Command 42 reply unknown | 本段不新增批准、拒絕或世界切換結論 | 部分確認 |
| Client 收到一般 frame | T03-7～9 解框/中繼 | Shared worker vtable+0 尚未解釋 | 不足以定位角色 UI | 有界原生，業務未知 |

- **Client 待逆向**：辨識 `parent+0x140` 真正的 first-DWORD vtable 寫入／callback target，找到 command 0x42 可能的 S→C business handler 和對應角色狀態更新。
- **Server 待開發**：在 Client 接收 parser 格式與結果效果查明後才定義相容回覆，不臆測原版 Server 規則。
- **跨功能待整合**：T03 成功選角與 T05 世界/場景接續。
- **待遊玩驗證**：完整 C→S/S→C 與實際 Client 行為尚未做 end-to-end 測試。

## 後續 T03-19

應先在接收 worker 的父物件建立/virtual table 賦值上做 *data-flow-based* xref，避免再以 `0x4918xx` 的 D3DX 圖形 branch 當作選角解析入口；必要時交叉引用 T02 transport dispatcher 的已界定原稿而不改寫 T02 文件。無法定位具體 callback 前，不能把任何測試 fixture 的 `42→43/69` 視為原生協定。

三輪：第一輪取得 GetAsyncKeyState 的原生語意；第二輪用兩個 D3DX imports 完成相鄰圖形支線交叉驗證；第三輪對照接收 worker 與先前錯誤假設，完成實質否證與研究路由修正。符合共用重大發現門檻；沒有捏造選角業務回覆。