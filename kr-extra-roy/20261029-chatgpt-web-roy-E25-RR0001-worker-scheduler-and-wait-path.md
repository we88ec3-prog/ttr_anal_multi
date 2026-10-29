# E25 — RR-0001／RR-0004：alternate scheduler 的 worker group、event wait 與第二條同型 socket send 路徑

研究日期：2026-10-29（Asia/Taipei）。本段從 E24 的 `0x491FDD→0x804A40` 與 `0x491FE6→0x804C70` 分岔開始，將 `0x805228` 第二 caller 追到 worker entry。原始 KR `Tartaros.bin` 12,472,320 bytes；當次 `sha256sum` = `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。指令 VA = 檔案 raw+0x400C00，使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 重驗。本研究支援 S00 RR-0001／0004（T02 P0），維持 owner、派工狀態及主線不變。

## 第一輪：重大新發現 — 0x804C70 不是「另一路直接送出」，而是 worker wait/group controller

```asm
804C70 push ebx
804C71 push edi
804C72 mov edi,[0xBD25A0]
804C78 call edi                   ; time source, exact API name pending import map
804C7A cmp dword [esi+0xA4],0    ; worker count flag
804C81 mov [esi+0x48],eax
804C84 jne 0x804C8C
804C86 push esi
804C87 call 0x804D20             ; initialize workers if count zero
804C8C xor ebx,ebx
804C8E call edi
804C90 mov ecx,[esi+0x88]
804C96 sub ecx,eax
804C98 cmp ecx,0x21              ; 0x21 threshold, unit not assumed
804C9D mov [esi+0x88],eax
804CA3 mov ebx,1
804CA8 mov edx,[esi+0x98]
804CAE sub edx,[esi+0x94]
804CB6 sar edx,2                 ; worker descriptor ptr array size
804CC2 mov eax,[esi+0x94]
804CC8 mov ecx,[eax+edi*4]       ; descriptor
804CCB mov byte [ecx+0x10],bl    ; worker flag
804CD4 mov eax,[edx+edi*4]
804CD7 mov ecx,[eax+8]           ; worker event handle
804CDA push ecx
804CDB call dword [0xBD20D0]    ; event signal, import name not independently proven
804CF5 mov eax,[esi+0xA8]
804CFB mov ecx,[esi+0xA4]
804D01 push -1
804D03 push 1
804D05 push eax
804D06 push ecx
804D07 call dword [0xBD22B4]    ; multihandle wait, API name provisional
804D0D call dword [0xBD25A0]    ; time source
804D14 mov [esi+0x4C],eax
804D18 ret
```

此迴圈遍歷 `[esi+0x94,esi+0x98)` 的 worker descriptor pointer array；每次寫 descriptor+0x10，並對 descriptor+8 的 handle 作 import-call，最後等待 `esi+0xA8` 結構對應的 handles。**0x21 不可直接宣稱 33ms tick**（需 import 時基），但可以確認它是用於決定是否設定 worker flag 的比較閾值。

## 第二輪：worker 建立與實際函式入口證據

```asm
804D20 push ebp
804D30 mov [ebp-0x24],eax
804D4B call dword [0xBD2118]    ; system data count source
804D57 mov [esi+0xA4],eax       ; worker count
804D74 push 0x18
804D76 call 0x891268           ; worker descriptor 24 bytes
804D82 mov [eax],edi
804D8D mov byte [eax+0x10],0
804DA6 mov [ebx],ecx           ; group field
804DAC mov [ebx+4],edx         ; worker index
804DAF call dword [0xBD22B8]  ; create first event handle
804DBD mov [ebx+8],eax
804DC3 call dword [0xBD22B8]  ; create second event handle
804DCC mov [ebx+0x0C],eax
804DCE push ebx                 ; argument = worker descriptor
804DCA push 0
804DCE push 0x805190           ; thread entry address
804DD3 mov [ebx+0x14],esi     ; parent scheduler context
804DD6 call 0x895D39           ; thread creation wrapper, exact CRT import uncertain
```

**注意：上方 0x804DCA/804DCE 的 push 順序必須以完整 objdump 逐條核對**：完整原生機器碼實際為 `804DC9 push ebx; 804DCA push 0; 804DCC push 0x805190; 804DD3 mov [ebx+0x14],esi; 804DD6 call 0x895D39`。這明確證明新工作入口是 `0x805190`，工作描述子有 parent `+0x14` 及 index `+4`，而不是原先不明的同步發送流程。

## 第三輪：0x805190 worker 與 0x804A40 是兩條同型 sender scheduler

```asm
805190 push ebp
805197 mov ebx,[ebp+8]          ; worker descriptor
8051A2 mov eax,[ebx+0x14]      ; parent context
8051A5 cmp dword [eax+0xA4],0  ; running count
8051B4 mov ecx,[ebx+8]         ; worker wake event
8051BA call dword [0xBD20FC]   ; wait primitive, likely blocking
8051D0 cmp dword [0xFBA858],0  ; global connection array
8051EE mov ecx,[0xFBA858]
8051F4 mov eax,[ecx+4]
8051F7 sub eax,[ecx]
8051FC sar eax,2               ; connection count
8051F9 mov edi,[ebx+4]        ; worker starting index
805215 mov ecx,[ecx]
805217 mov esi,[ecx+edi*4]    ; selected connection
80521A cmp dword [esi+0xA0AC],0
805227 push esi
805228 call 0x8061A0         ; frame builder, second direct caller
805273 cmp dword [esi+0xA028],0
805280 mov edx,[esi+0xA0B8]
805288 jg 0x8053A9           ; inflight send blocks
80528E mov eax,[esi+0xA028] ; buffered length
805294 mov ecx,[0xFBA854]   ; transport
80529C mov edx,[edx+0x0C]    ; virtual send target
8052A4 lea eax,[esi+0x5020] ; frame bytes
8052AC call edx
8052AE test eax,eax
8052B2 push esi              ; on zero return
8052B3 call 0x8063E0        ; pending-list flush
8052C0 mov edx,[eax+0x24]    ; close transport path
8052C6 call edx
8052C8 mov [esi+0xA0A8],1   ; disable
8052D2 cmp dword [esi+0xA0B0],0
8052E3 mov edx,[eax+0x24]   ; close on other condition
8052E9 call edx
8052F5 cmp dword [esi+0xA0A4],0x12C
805313 call 0x8063E0        ; threshold drain
8053A9 mov eax,[ebp+8]
8053AC add edi,[ebx]        ; worker stride
8053B1 cmp edi,eax          ; loop limit
8053B3 jb 0x805212
8053B9 mov ecx,[ebx+0x0C]  ; worker completion event
8053BD call dword [0xBD20D0]
8053C3 mov edx,[ebx+0x14]
8053C6 cmp dword [edx+0xA4],0
8053CD jne 0x8051B4        ; sleep next cycle
```

`0x8053AC add edi,[ebx]` 為 worker stride；在 descriptor 初始化 `[ebx]` 來自 worker count（`0x804D9A→0x804DA6`），所以每 worker 以固定 index stride 走同一全域連線陣列。這是與 E24 主 loop 的重要差異；兩者都共用建構器及 virtual send ABI。由 `0x491FD3` 判斷 context+0x90：零走 `0x804A40` 直接串行連線迴圈；非零走 `0x804C70` 管理 worker event/wait，worker 裡跑 `0x805190` 送出迴圈。此分流的「是否有 threading」更有機器碼依據，但精確 worker 數量需解 `0xBD2118` 系統資料來源。

### 可重現 C++ 近似（原生物件名暫定）

```cpp
void updateTransport(Context* ctx) {
  if (ctx->field90 == 0) schedulerSerial(ctx);    // 0x804A40
  else {
    if (ctx->workerCountA4 == 0) initializeWorkers(ctx); // 0x804D20
    maybeSetWorkerWakeFlags(ctx);                  // threshold 0x21, context+0x88
    signalWorkers(ctx);                           // workers+8 handles
    waitWorkerCompletion(ctx);                    // context+0xA8 handles
  }
}
void worker(Descriptor* d) {                      // 0x805190
  while (d->parent->workerCountA4 != 0) {
    waitEvent(d->wakeEvent);
    for (int i=d->startIndex; i<connectionCount; i+=d->stride) {
      Conn* c=connectionArray[i];
      if (!c->gateA0AC) continue;
      buildOneQueuedFrame(c);                     // 0x8061A0
      if (c->bufferedLengthA028 && c->inFlightA0B8<=0)
        transport->send(c,c->staging5020,c->bufferedLengthA028,...);
      // disabled/close/timeout threshold branches separately
    }
    signalEvent(d->completionEvent);
  }
}
```

### 邊界及後續

- **已確認**：`0x804C70` worker-controller、`0x804D20` descriptors/thread entry、`0x805190` worker event wait + strided per-connection loop + `0x8061A0` → vtable send。
- **不可宣稱**：`0x21` 是 ms；所有 import 名稱已逐一核對；`0xFBA858` 第一個 pointer 就是 login connection；worker 模式於首次登入實際啟用；收到 IOCP 後立刻 signal next send；RR-0001 的第一個 wire packet。
- **RR-0001**：仍需追第一筆資料來源及實際 wire type、首次收包與分派、connection-specific login handoff。**RR-0004**：A02C indirect writer + encoded/plain fallback 在 wire 上何時發生，仍未閉合。
- **Client 待逆向**：`0xBD2118`、`0xBD20D0`、`0xBD20FC`、`0xBD22B4` import 函式名原始 PE 解映、worker 啟動與停用 flag、第一筆 C2S。
- **Server 待開發**：按已證 framed send/receive 制訂相容測試，不能推官方後端政策。
- **跨功能待整合**：T02 first connection ↔ T03 auth/role-select ↔ scene。
- **待遊玩驗證**：原 Client + 新 Server 環境、實際 socket trace 與工作模式。
- 三輪紀錄：第 1 輪找到 alternate controller；第 2 輪確認 worker allocation/thread entry；第 3 輪從 worker 追到 build→vtable send，達重大完整有界進展。**E25 已完結，RR 未提交審核。**

重驗命令：
```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x804c70 --stop-address=0x804d20 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x804d20 --stop-address=0x804de0 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x805190 --stop-address=0x8053e9 Tartaros.bin
```
