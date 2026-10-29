# E24 — RR-0001：送出排程器、frame builder 和 vtable sender 的同迴圈整合（KR BIN-first）

時間：2026-10-29 Asia/Taipei。原始 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本段當次重新核對。BIN VA mapping .text raw=VA−0x400C00；不執行/patch 原 Client。前段 E21–E23 已證 0x8061A0 frame builder、0x804B5A vtable→0x8068B0 WSASend、0x806E7D completion→0x8077B0 buffer drain。

本次主題不混用兩種「完成」：WSASend accepted、IOCP completed、收到 Server 業務回覆各自獨立。正式 owner 為 T02；此處是 extra/roy1 跨 Task 支援，未做 RR CLAIMED/SUBMITTED/ACCEPTED。

## 第一輪：重大新結論 — 找到獨立的 per-tick / per-pass send scheduler

`0x804A40` 在同一個函式迴圈內：從全域連線陣列取物件、呼叫 `0x8061A0`（frame builder/drain pending list）、檢查 buffered bytes + pending I/O、透過 `[0xFBA854]` transport vtable +0x0C 啟動 send，然後移到下一個 connection。這是 E23 所缺的下一次送出「排程呼叫站」，不是 IOCP completion 內直接遞迴 WSASend。

### 原始組語：函式起點與容器巡覽

```asm
804A40 push ebp
804A41 mov ebp,esp
804A4F call ebx                   ; timing source from imported function
804A51 cmp dword [0xFBA858],0
804A58 mov edi,[ebp+8]            ; scheduler context
804A75 mov esi,[0xFBA858]         ; connection pointer array object
804AA2 mov edi,[esi+4]
804AA5 sub edi,[esi]
804AA7 xor eax,eax
804AA9 sar edi,2                  ; number of four-byte elements
804AB2 test edi,edi
804AB4 je 0x804C5B
804AC3 mov edx,[esi]
804AC5 mov esi,[edx+eax*4]        ; selected connection
804AC8 cmp dword [esi+0xA0AC],0  ; connection gate
804ACF je 0x804C4B
804AD5 push esi
804AD6 call 0x8061A0             ; frame build + drain one queued item
804ADB test eax,eax
804ADD je 0x804B07
```

### 原始組語：發送節流、虛擬呼叫、回傳後失敗處置

```asm
804B21 cmp dword [esi+0xA028],0   ; no buffered bytes => skip
804B28 je 0x804C4B
804B2E mov eax,[esi+0xA0B8]      ; in-flight operations
804B34 test eax,eax
804B36 jg 0x804C4B               ; positive => do not submit another send
804B3C mov eax,[esi+0xA028]      ; total bytes in connection local staging
804B42 mov ecx,[0xFBA854]        ; transport singleton interface
804B48 mov edx,[ecx]
804B4A mov edx,[edx+0x0C]        ; vcall target
804B4D lea edi,[ebp-0x14]
804B50 push edi                  ; output result ptr
804B51 push eax                  ; buffer byte count
804B52 lea eax,[esi+0x5020]
804B58 push eax                  ; buffer bytes
804B59 push esi                  ; connection
804B5A call edx                  ; vptr 0xC51748 => 0x8068B0 WSASend
804B5C test eax,eax
804B5E jne 0x804B7C
804B60 push esi
804B61 call 0x8063E0             ; failed send: batch pending-list drain
804B6C mov eax,[ecx]
804B6E mov edx,[eax+0x24]        ; transport-specific close action
804B71 push 0
804B73 push esi
804B74 call edx
804B76 mov [esi+0xA0A8],ebx      ; disable / transition flag (ebx=1)
804B9B cmp dword [esi+0xA0A4],0x12C
804BA5 jle 0x804C48
804BAB cmp dword [esi+0xA0A8],0
804BB2 jne 0x804C48
804BB8 push esi
804BB9 call 0x8063E0
804C48 mov edi,[ebp-8]
804C4B mov eax,[ebp-0xC]
804C4E add eax,ebx
804C50 mov [ebp-0xC],eax
804C53 cmp eax,edi
804C55 jb 0x804AC0
804C6D ret 4
```

`0xA0A4 > 0x12C` 檢查與固定代碼/計數分支有關，不能未核其 writer 就稱為網路 timeout 秒數。

## 第二輪：直接上游呼叫站（per-frame gate 具有另一模式）

在原始 BIN .text 逐位元組掃 E8 rel32（此搜尋可含不在有效 CFG 的假陽性，結果仍以 objdump 指令邊界確認），`0x804A40` 的 direct call site 為 **`0x491FDD`**。該 callsite 位在雙分支：

```asm
491FC7 call 0x425330
491FCC mov esi,eax
491FCE call 0x4F6B80
491FD3 cmp byte [ebx+0x90],0
491FDA jne 0x491FE4
491FDC push ebx
491FDD call 0x804A40        ; connection-array scheduler
491FE2 jmp 0x491FEB
491FE4 mov esi,ebx
491FE6 call 0x804C70        ; other task / mode path
491FEB push ebx
491FEC call 0x804FC0        ; shared downstream update
```

`[ebx+0x90]` 是 scheduler context 的 branch flag，**不是** connection 的 `+0x90`；必須按 object identity 分開。另一個 `0x804C70` 分支不能直接稱為純網路或完全停送，它自身還處理另一組連線／工作結構。

### 原始 E8 caller 分布

`0x8061A0`：direct callsites `0x804AD6`, `0x805228`。因此除 `0x804A40` 外，另有 `0x805228` 的排程/批次入口，仍需查其物件集；不能說唯一 sender。

`0x804A40`：direct callsite `0x491FDD`。但不排除 indirect callers，無直接 E8 也不等於沒有執行時間的上游；`0x491FDD` 證明實際一個 native direct scheduling branch。

## 第三輪：與 E22/E23 completion 的界線

完成端 `0x806E7D` 驗證 `connection+0xA050` send OVERLAPPED，`0x806EA1` 呼叫 `0x8077B0` 扣掉 completed bytes，`0x806EB4` 更新 `+0xA024`，`0x806EC4` 更新 `+0xA0B8`。下一次 `0x804A40` 掃描同 connection，`+A028>0` 且 `+A0B8<=0` 才有新的 send call。這是**兩條原生流程以共享欄位共同組成的 state-machine**，並不表示 IOCP 回呼直接呼叫 `0x804A40` 或保證完成回呼恰好下一 frame 觸發；頻率及第一個 frame 還需上游 timer/tick 研究。

有界偽碼：

```cpp
void scheduler(Context* ctx) {
  if (ctx->mode90 == 0) {
    for (Conn* c : globalConnectionArray) {
      if (!c->gateA0AC) continue;
      bool built = buildOneFrameFromQueue(c); // 0x8061A0
      updateRetryCounters(c, built);         // +A0A4 / +A094 etc.
      if (c->bufferedBytes_A028 && c->inFlight_A0B8 <= 0) {
        int result = transport->send(c, c->buffer_5020, c->bufferedBytes_A028, ...);
        if (result == 0) { flushPending(c); transport->close(c); c->flag_A0A8=1; }
      }
      handleThresholdAndNextConnection(c);
    }
  } else {
    alternateScheduler(ctx); // 0x804C70; detailed meaning not asserted
  }
  commonUpdate(ctx); // 0x804FC0
}
```

## RR、server 相容和後續

**RR-0001／RR-0004 保持未完成**：本段閉合原本缺少的「誰再次執行送出」native scheduler 入口，但尚無每條 connection 第一個 send builder payload、first S2C frame、`A02C` indirect alias writer 及 runtime packet order。E24 只證在 sender gate 成立時 native scheduler 可以發起下一次 send；不得冒稱 IOCP callback 自動 wake 或實際遊玩驗收成功。

Client 待逆向：`0x491FDD` 更上游的 tick schedule、`0x805228` 第二個 caller、第一筆 frame data/marker/opcode、`0x804C70` alternate path。Server 待開發：原 Client 所需要的 framing、ack timing 仍需 frame/message-level evidence。跨功能待整合：T02 初始連線與 T03 auth/scene。待遊玩驗證：pcap/本機 loopback 的第一筆資料及 timeout/retry behavior。

本段第一輪已產生重大有界關鍵呼叫鏈（`0x491FDD→0x804A40→0x8061A0→vtable+0x0C→0x8068B0`），第二輪核對另一排程模式與 callsite 分布，第三輪核對 IOCP+連線狀態字段配合；未宣稱比原生支持範圍更多。

### 原生重驗

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x804a40 --stop-address=0x804c70 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x491fc7 --stop-address=0x491ff2 Tartaros.bin
```
