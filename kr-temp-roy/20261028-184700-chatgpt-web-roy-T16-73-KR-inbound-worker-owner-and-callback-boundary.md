# KR T16-73 — 收包工作者的擁有者、物件內嵌偏移及虛擬分派邊界

- 研究日期：2026-10-28，Asia/Taipei；研究者：chatgpt-web roy；KR only。
- BIN `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，長度 12,472,320 bytes；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 靜態分析唯讀，未執行 Client。適用 `.text` VA/raw 換算 `raw=VA-0x00400C00`；以下各 VA 均在該區段內。反組譯工具 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`，須從確認的函式／指令入口解碼，避免裸掃描中間位元組假陽性。

## 1. 本輪 P0 命題與結論

目標：延續 T16-72 的 Queue B worker `0x804740`，追尋 vtable `+0` 的 owner／最終 handler，並確認它與任務狀態封包的關係。**本輪新增確定事項：`0x804740` 有一處靜態直接 E8 caller `0x49198A`；caller 傳入較大物件中 `+0x140` 位置的子物件指標，後續 `0x804740` 取參數作為 `ebx`，在 `0x80485A` 讀取子物件 vptr，並以其首個 slot 呼叫 `connection,payload,length,lane`。**

此新證據提供對象相對偏移及實際呼叫點，但**尚未確定 `+0x140` 子物件的建構器、vtable 常數、最終方法地址或 Quest opcode**。因而不得把 worker callback 寫成 Quest handler。

## 2. 第一手證據：直接呼叫與 owner offset

以 BIN `.text` 範圍內 E8 rel32 target=0x804740 進行位元組候選搜尋，得到一處 `0x49198A`；已用指令界線確認。

```asm
49197f: mov edi,[esp+0x20]
491983: lea ebx,[edi+0x140] ; inner worker/control subobject
491989: push ebx
49198a: call 0x804740      ; direct caller
49198f: test byte ptr [0xfc10cc],1
```

`edi` 的來源 `[esp+0x20]` 是此時函式 stack layout 的值；其更早來源與動態類型**待驗證**。切勿將偏移 `0x140` 套用到其他任務的 C++ 類型。

`0x804740`：

```asm
804768: mov ebx,[ebp+8]           ; exact pushed inner object
8047b2: lea edi,[ebx+4]
8047b5: mov ecx,0xb
8047ba: lea esi,[ebx+0x30]
8047bd: rep movsd                ; move 11 DWORDs (0x2C bytes)
804837: push esi                 ; lane candidate
804838: lea eax,[ebp-0x10]
80483b: push eax
80483c: mov eax,0xfc10d0
804841: call 0x804100            ; queue B dequeue
804846: test al,al
804848: je 0x8049d0
804852: mov esi,[ebp-0x10]      ; dequeued object
804855: mov ecx,[ebp+8]         ; compare original after register changes in context
804858: mov edx,[ebx]
80485a: mov edx,[edx]           ; vtable slot +0x00
80485f: mov eax,[esi+4]        ; length
804862: push ecx                ; lane, earlier caller loop variable
804863: push eax                ; length
804864: lea eax,[esi+8]
804867: push eax                ; payload start
804868: mov eax,[esi]
80486a: push eax                ; connection/context
80486b: mov ecx,ebx
80486d: call edx
80486f: mov [ebp-0x1c],eax
80487c: mov eax,[ebx]
80487e: mov edx,[eax+0xc]
804881: push edi                ; duration
804882: push esi                ; frame object
804883: push ecx                ; lane
804884: mov ecx,ebx
804886: call edx
804888: cmp edi,0x28
80488b: jbe 0x8048a3
804890: mov ecx,[ebp+8]
804892: mov edx,[ebx+0x8c]
804898: mov eax,[eax+8]        ; secondary callback (full context needed)
80489f: mov ecx,ebx
8048a1: call eax
8049b2: call 0x804100            ; dequeue follow-up
```

上述擷取中 `0x804855` 的 `[ebp+8]` 在 worker 內是傳入的 `inner object`，不能依單行立即斷定它是 lane；此處於前段摘要的「lane」有語意不一致風險。完整參數解讀應以 `0x804837` 到 `0x80486D` 的局部寄存器定義、最外層 loop 語意及編譯器 stack 佈局交叉驗證。最明確證據是 4 個 push 參數及 vptr+0 呼叫，不是各參數名稱。

## 3. 靜態上下游與暫定偽碼

```cpp
// Sketch only: all names are analytic labels, not recovered symbols.
void outer_periodic_worker(Outer* outer) {
    process_worker_inner((char*)outer + 0x140);
}
void process_worker_inner(void* inner) {
    // ...timing and lane iteration...
    if (dequeue_B(0xFC10D0, &frame)) {
        auto vt = *(void***)inner;
        vt[0](/* observed 4 pushed arguments, stack-order preserved */);
        vt[3](/* additional arguments incl. elapsed time */);
    }
}
```

待證：constructor 給 `outer+0x140` 寫入 vptr 的位置；若指向多個派生類 vtable，需逐一驗證真正 callback。Queue B 解出的 `frame+8` 是 payload，不應將 frame header `0x1A68` 等直接當任務業務 opcode。

## 4. 玩家情境 × 兩方向封包矩陣

| 情境 | Client 本地 gate | C→S | S→C | Client 改變 | Server 待開發 |
|---|---|---|---|---|---|
| Lua `RequestStartScenario(id)` | `0x004AA4D0` 的 `[FBA798]==0` | 已確認 4-byte 本地訊息 `40 00 id_lo id_hi` 及往下送出鏈；正式 wire opcode 與單次 socket 時機 unknown | unknown | unknown | 需提供可由原始 Client 消費的回覆；格式 unknown |
| 伺服器更新 Quest16 | unknown | unknown | 已知通用 WSARecv→解框→Queue B→worker 虛調用；Quest specific opcode/handler unknown | Quest16 state writer unknown | 任務更新/完成回覆要依實證後定義 |
| Quest15 變可接 | unknown | unknown | unknown | NPC/Quest UI consumer unknown | 可接清單或旗標模式 unknown |
| 玩家點 NPC 接取下一任務 | unknown | 尚未找到 quest accept producer | 尚未找到 quest ACK handler | unknown | ACK/拒絕格式 unknown |

## 5. 研究嘗試與三輪門檻

- **第 1 輪 T16-73**：BIN E8-rel32 精確 target 掃描；確認唯一直接 caller `0x49198A`，解碼 `outer+0x140` 的傳遞、worker 的 dereference 與 vtable+0 call。此是新上下游與 owner offset，但尚不足以宣稱 Quest 封包閉環。
- **第 2 輪 T16-73-2**：沿 caller `0x4917E0..0x491A20` 查證 thread/event 周期處理環境；`0x491818` 使用多個 Win32 API function pointers、`0x49196E` global observer，`0x49198A` 在主流程中呼叫 worker。仍未解析 subobject 建構器。
- **第 3 輪 T16-73-3**：尚未完成實質可驗證 vtable 寫入與目標定位；**此段不得宣稱已符合重大發現門檻**，應保持 T16-73 open，後續同段繼續深入，不提前跳 T16-74。

## 6. 待下一輪調查（不改其他 task）

1. 對 `0x49198A` 周圍 outer pointer 的早期來源與 outer constructor 逐次回推；蒐集所有 `[outer+0x140]` vptr 寫入 sites。
2. 取得 callback vtable `+0` 的確切地址後，以 first bytes / opcode reader / switch-dispatch 逐層連到 Quest state consumer。
3. 與 T02 已驗證的 framing/queue 範圍比對，但不修改 T02 原稿。
4. 另以 NPC 接取 UI 的 click handler 反向追 C→S packet producer。
5. 最終完成 `Quest16→Quest15` 需要 XML、S→C 原生 handler 及 field 證據；未取到前皆 unknown。

## 7. GitHub 和原始檔政策

本 MD 代表本次靜態調查的**有界工作原稿**，未主張 T16-73 完成；只允許提交本研究者 `kr-temp-roy/`，不提交二進位檔、其他任務或短期交接 04。任何 GitHub 提交狀態必須以 API 回傳 SHA 和讀回內容為準。