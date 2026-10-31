# RR-0006／KR T02 補充研究：接收分包上界、節點借出後異常分支、錯誤幀與後續幀

> chatgpt-web roy，2026-11-01 02:04:29 Asia/Taipei。範圍：原已 `SUBMITTED → IN_REVIEW` 的 RR-0006，對 E59 增量深挖而非重寫原稿。**研究者不能自行把 RR 標成 ACCEPTED 或提升 FULL-PASS。**

## 0. 正式目標與版本

- Repository `we88ec3-prog/ttr_anal_multi`，工作分支 `extra/roy2`；進行調查時 origin/main `ec16f88347deeef894fa9fdebd3791fefe61da2c`，先將 main fast-forward 納入工作分支（沒有新增 branch）。
- 研究請求：`research/requests/index.json`，`RR-0006`（KR／T02，`GAP-NET-0003`），正式問題：沿 `0x807B40` 的 `0x2633`／`0x22D7`、`0x727190`、0BBB checksum mismatch、`0x807E50`、節點／pool 至下游進行靜態閉合，只回報對相容 Server 真正有意義的條件。最新 main 登錄狀態 `IN_REVIEW`；T01 已做 E59 的限定 R2，**不等於 S00 ACCEPTED／T01 FULL-PASS**。
- 已完整提交之權威技術原稿 **E59**：`kr-extra-roy/20261030-112205-chatgpt-web-roy-E59-RR0006-compressed2633-22D7-decode-checksum-pool-IOCP.md`，Git blob `c7c1474b6b3cf928b8031e17fad7761c488d9b18`；本檔僅補充有界控制流程與可反證條件，原稿不覆寫。
- 原始 KR `Tartaros.bin`：12,472,320 bytes，SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**，唯讀驗證；相符 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。PE `.text` VA `0x401000`、raw `0x400`，virtual `0x7D01F0`、raw-size `0x7D0200`；本節 raw offset = VA - `0x400C00`。
- 驗證方法：GNU objdump 對 **真實 PE32 `.text` 指令入口**反組譯，再核對原始 BIN 關鍵 bytes、跨函式 E8 rel32；在唯讀原件運行另附 audit code，結果 **34 native prefix checks / 4 precise call targets / 16 SYN mathematical tests 全通過**。SYN 不是 Client execution／官方 Server packet／pcap。

## 1. 新增研究結論：pool checkout 先於 frame 物理位址檢查

E59 已證對完整 frame 先借節點、正常成功解碼便投遞到 application queue，checksum/inflate 失敗會把 node+4=0 的節點返回 pool。本輪將 **另一條不經 `807D7F` 的分支**單獨追完：

```asm
807C34 8B CE                 mov ecx,esi                   ; outer wire n
807C36 8B 74 24 20           mov esi,[esp+20]              ; hdr 4/6/8
807C3A 03 CE                 add ecx,esi                   ; frame wire total
807C3C 3B C8                 cmp ecx,eax                   ; available?
807C3E 0F 8F 96 01 00 00     jg 807DDA                     ; incomplete: no pool node
807C7C BF 58 33 FE 00        mov edi,0xFE3358            ; packet pool
807C81 E8 2A F9 FF FF        call 8075B0                  ; borrow node; pool+54++
807C86 8D 3C 1E              lea edi,[esi+ebx]            ; payload start
807C8C 89 44 24 28           mov [esp+28],eax             ; node held on stack
807C90 8D 0C 3E              lea ecx,[esi+edi]            ; payload end
807C93 3B 7C 24 14           cmp edi,[esp+14]             ; below Rx base?
807C97 0F 82 39 01 00 00     jb 807DD6                    ; jump WITHOUT recycle
807CA7 3B FA                 cmp edi,edx                   ; >= Rx end?
807CA9 0F 83 27 01 00 00     jae 807DD6
807CAF 3B 4C 24 14           cmp ecx,[esp+14]             ; end below base?
807CB3 0F 82 1D 01 00 00     jb 807DD6
807CC3 3B CA                 cmp ecx,edx                   ; end >= Rx end?
807CC5 0F 83 0B 01 00 00     jae 807DD6
807DD6 8B 7C 24 14           mov edi,[esp+14]             ; no 807D83 len gate
807DDA 8B B7 00 50 00 00     mov esi,[edi+5000]           ; attempt compact
```

**有界靜態事實（N）**：`807C81` 在四種 `807C93..807CC5` 指標條件前借出 node；若這些跳轉成立，執行的是 `807DD6 → 807DDA`，沒有通過 `807D83` 的 len-gate、`807D90`／`807D97` 的 pool-return，也沒有通過 `807D9E` 的 application queue。`8075B0:8076C7 inc [pool+54]` 的活動計數在該條異常分支未配對 `8076F0:80771D dec [pool+54]`。因此在**此分支真的可達的前提下**，存在「本輪借出的節點失去局部引用／pool 活動計數未平衡」的靜態風險；這不是說實際正常玩家會造成 leak。

**不能提升的結論（U）**：本輪不證明有效 Conn 的合法 WSARecv 必然能走這條分支，也不以它聲稱真實記憶體洩漏量、可穩定觸發、原版 Server 曾發送如此 frame。要對 real-world exploitability 作主張須先證別名、競態、非法 Rx cursor 或實際 trace。

## 2. 新增有界排除：一般收包／partial frame 不會自然填滿 0x5000 緩衝區

### 2.1 原件接收大小（非推測）

```asm
806A22 8B 8E 18 50 00 00   mov ecx,[esi+5018]  ; current Rx write cursor
806A2B 89 48 18            mov [eax+18],ecx   ; WSARecv buffer ptr
806A3B C7 01 00 10 00 00   mov dword [ecx],0x1000 ; WSARecv WSABUF.len=4096
806A4C FF 15 BC 25 BD 00   call [0xBD25BC]    ; WSARecv import
806DE4 8D B8 30 A0 00 00   lea edi,[eax+A030] ; Rx OVERLAPPED
806E04 8D 50 18            lea edx,[eax+18]
806E08 E8 33 0D 00 00      call 807B40
```

`0x807B40` 明確拒絕 `n==0` 或 `n>0x1000`，而有效 frame 的最長外殼是 8 bytes (`0x2633`)；當可用資料少於 header 或完整 frame 時，未消費殘留在 `807DDA..807E14` 前移至 Rx base、並重設 cursor。對單一此解析器正向路徑、正常 cursor、單次 outstanding WSARecv、不存在併發修改的**條件式數量推導（C）**：

- incomplete frame 最多剩 `n+header-1 ≤4096+8-1=4103` bytes；header 不足時最多剩 3 bytes。
- 下一次 WSARecv 最多再添 `4096` bytes，暫時上界為 `4103+4096=8199 (=0x2007)`，**小於** Rx 物理區 `0x5000 (20480)`。
- 有效 frame pointer end 在正常合約下不會剛好碰到 `RxBase+0x5000` 的嚴格 `jae` 上界。故**不能**僅靠合法 TCP 分段／黏包，便宣稱上一節的 checkout-then-guard-jump 在正常運作路徑會被觸發。

該推導依賴 `807E14` compaction／cursor 正常、原版 Client 未被其他 pointer alias 破壞、單一 recv outstanding 等前提。若存在其他寫入者／結構重設／socket receive 併發導致 cursor 異常，仍須追實際前置；本稿沒有證實 **全域**不可能到達指標邊界分支。

## 3. 完整錯誤幀與下一個有效幀的**同一 callback**邊界

```asm
807D16 85 C0                 test eax,eax                ; 727190 status
807D18 75 65                 jne 807D7F                   ; bad inflate bypass copy
807D66 66 39 4B 04           cmp word [ebx+4],cx        ; 0BBB checksum
807D6A 75 13                 jne 807D7F                   ; checksum mismatch
807D7A E8 D1 00 00 00        call 807E50                  ; valid decoder path copy
807D83 83 78 04 00           cmp dword [eax+4],0        ; zero-length node gate
807D8D 75 0F                 jne 807D9E                   ; valid node -> app
807D90 E8 7B C5 FF FF        call 804310
807D97 E8 54 F9 FF FF        call 8076F0                  ; bad decoded node recycle
807D9E 8B 89 80 A0 00 00     mov ecx,[ecx+A080]         ; Conn lane
807DAD E8 EE C2 FF FF        call 8040A0                  ; app queue
807DB2 0F B7 13              movzx edx,word [ebx]         ; wire n
807DB5 03 54 24 20           add edx,[esp+20]            ; plus header length
807DC7 03 DA                 add ebx,edx                  ; frame consumed
807DCB 83 F8 04              cmp eax,4                   ; more full header?
807DCE 0F 83 DC FD FF FF     jae 807BB0                   ; parse *next frame*
807DDA ...                                              ; compact remaining bytes
807E16 B8 01 00 00 00        mov eax,1                    ; parser success
807E1D 33 C0                 xor eax,eax                  ; invalid boundary failure
```

在正確 header、length 和 Rx cursor 前提下，0BBB checksum 失配／2633 inflate 非零是 **完整錯誤 payload**，它不寫 node+4，會回收該 node，**但仍前進 `wire_n + header_len`，且可能處理同一接收批次中緊接的下一個 frame**。這是 E59 所列局部成功／失敗路徑的精確新組合情境；`0x0BBB` 不需要 Client Socket 立即斷線才能丟棄壞的 frame。反例：`n=0` 或 `n>4096` 在 `807BB8/807BC6` 轉 `807E1D return0`，根本沒有 node checkout，IOCP caller 走不同狀態處理：

```asm
806E08 E8 33 0D 00 00       call 807B40
806E0D 85 C0                 test eax,eax
806E12 74 0F                 je 806E23                    ; parser0
806E14 ...                  ; parser1 -> manager vtable+14 next recv
806E23 39 B0 B0 A0 00 00    cmp [eax+A0B0],esi          ; if already nonzero -> loop
806E29 0F 85 01 FF FF FF    jne 806D30
806E6E C7 80 B0 A0 00 00 01 00 00 00
                               mov dword [eax+A0B0],1     ; guarded stop flag
```

`806E23..806E6E` 涉及 manager+0x58 是否 logging 的分支，**不能**簡化成所有 parser0 立刻 closesocket；也不能反向稱壞 checksum 一定會 post 下一個 recv（仍受狀態與 manager callback 約束）。`0x22D7`／未知 marker 在此 parser 的 4-byte raw 分支，和 0x1A68 共享 raw-copy 路徑；這不是原版 Server 對任意 marker 的允許清單。

## 4. 另一個有界 OOM 異常：`0x8075B0` 新節點配置

```asm
8075D0 68 0C 10 00 00      push 0x100C
8075D5 E8 8E 9C 08 00      call 891268                 ; allocate
8075DC 33 C0                xor eax,eax
8075E1 3B F0                cmp esi,eax
8075E3 74 1F                je 807604                   ; if allocation returned null
807604 33 F6                xor esi,esi
80760F 89 86 08 10 00 00   mov [esi+0x1008],eax       ; would write null+0x1008
```

**僅條件式分支結論**：如果配置器 `0x891268` 正常返回零且沒有先丟出 exception／terminate，`0x8075B0` 沒有在 `0x80760F` 前退出，而會對零基址偏移 `0x1008` 嘗試寫入。這是 Client 本地可見的未妥善保護之條件式失敗路徑；**不證明 allocator 實際會返回零、實際發生過 crash、或 Server 自身應實作特定修補**。在未取得明確授權前不 patch 原始 Client。

## 5. 格式、解壓與相容性主張表（復用 E59 原生證據）

| inbound marker / case | parser header／動作 | node 結果與下游 | 信心與邊界 |
|---|---|---|---|
| `0x2633`，n 1..4096、完整 | header 8，使用 `0x7C` rolling XOR 後 register/stack 參數呼叫 `0x727190`，out cap 4096 | decode status0 且 out_len>0 才可 copy 到 node+8，然後 queue | **N/C**；+4..+7 四 bytes 在 807B40 不讀為 checksum/output len；不能猜 Server-side 語意 |
| `0x0BBB` 完整 | header 6；`0xB6` XOR，16-bit sum 與 +4..5 比較 | mismatch：len0→pool、可消費幀並續下一包 | **N**；不是 TCP/zlib checksum |
| `0x22D7` | header4，raw copy | n>0 時一般 node→業務佇列 | **N**；unknown marker 在本函式同採 header4，非正式 allowlist |
| 未滿4 bytes 或未滿 n+header | 等待、compact 殘留，未 checkout node | 接下次 WSARecv | **N/C**，依合法 cursor／正常 I/O 前提 |
| n==0 或 n>4096 | parser0，不 checkout | IOCP guarded A0B0 狀態分支 | **N**，非 checksum 失敗同一路 |
| 完整 bad 0BBB／bad 2633 後同批 valid raw | 壞 frame 回收後仍加 wire n+header，迴圈有 ≥4 bytes 則重進 | 後續 frame 可再配 node 並 app enqueue | **N/C** 有條件鏈，16 組 SYN 測試中驗證數學模型；並未執行 Client |
| 指標範圍超界，前置通過 length availability | `0x807C81` 已 checkout，`807DD6` bypass recycle | 條件式 pool active-count 不平衡 | **N/C**；合法收包是否能觸發**未證**，正常單 recv bound 排除簡單溢出假設 |

`0x727190` 仍有初始化 `0x727310`、通用 inflate `0x7274B0`、cleanup `0x728940`；其接收 caller 在 `0x807D0E` 返回零才會走 decoded node。合成 zlib 資料不證明官方選用的 wrapper 或原版 compressed bytes；後續 UI 的 T03 `0x0013/0x007A` 也僅在 **decoded payload+lane2+已裝 receiver** 條件下可達，不是任何外層 marker 本身就是登入 opcode。

## 6. 迴歸驗證與重現方式

- GitHub 同分支附 `kr-extra-roy/tools/rr6_rx_boundary_audit.py`（標準 Python，檔案唯讀）；指令 `python -B kr-extra-roy/tools/rr6_rx_boundary_audit.py <原始KR Tartaros.bin路徑>`。
- 原件驗證輸出：原始 SHA256 match、PE section match、**34 native instruction prefix checks**、**4 組 E8 rel32 target**（`0x807B40 ← 0x806E08`、`0x8075B0 ← 0x807C81`、`0x8076F0 ← 0x807D97`、`0x807E50 ← 0x807D7A`）、**16 synthetic checks**，結果 PASS。以 GNU objdump 在 `807B40..807E50`、`8075B0..80772A`、`806A00..806ACF`、`806DE4..806E78` 對應真實 PE code 反組譯驗證指令邊界。
- 合成測試包含 2633 兩種不同 +4..+7 占位、0BBB 正常／checksum 錯、22D7、未知 marker、partial frame、壞0BBB後接良好 raw frame、兩種無效長度、最多 RX staging 的算術上界。
- **測試採自行建立的 Python zlib stream／XOR 模型；沒有執行原版 Client，沒有證明其接受同一 stream；不計為官方封包抓包或 T01 FULL-PASS**。

## 7. RR 完成範圍／仍未知與 S00 交接

- **Client 已確認**：本次原生位元組和上下游新確認了 `807C81` 提前 pool checkout、`807DD6` 指標失敗跳過歸還、正常 WSARecv 長度 `0x1000`、error-frame 消費後同批下一幀路由、`806E23` parser0 guarded Conn flag，以及 `8075B0` allocator-null 條件式無保護使用。E59 的 2633/22D7/727190/checksum/pool 已完整提交並在審核中。
- **Client 待逆向**：若要聲稱 post-checkout pointer-bounds branch 在正常執行中可達，需找 Rx cursor/WSARecv 併發與 alias writers 實證；若要聲稱 OOM 崩潰，需查 allocator `0x891268` null-return/exception contract。兩個風險**不是**目前合法 Client wire 相容必需規格，不能藉此把 RR6 已有的有界研究重標 BLOCKED。
- **Server 待開發**：需要處理多幀黏包、分段與合法 n；異常完整 payload 不應當成有效業務指令；相容性 contract 僅依已證的 Client parser guard 建模。是否主動輸出 2633、對未認識 marker 採嚴格拒絕、重試或斷線政策仍由 S00 自訂 ADR／TEST，不得稱原版 Server 規則。
- **跨 Task 待整合**：T02 frame/IOCP 與 T03（0x13/0x7A）下游 handler，引用 E59/E56 等限定證據；GAP-NET-0003 仍需 S00 基於此完整研究作審核決策。
- **待遊玩驗證**：同 KR 版本受控雙向 capture/同 session runtime trace 才能確認實際 wire marker、Server first reply、壞包後 socket 真實行為及 UI 更新；沒有以上來源不造數據。

**提交說明**：保留 RR6 在 main 的 `IN_REVIEW`（已經 `SUBMITTED`），不改 append-only dispatch events，不標 `ACCEPTED`；提交本檔作為可供 T01/S00 使用的增量有界研究。完整 E59 原稿照舊；不修改 T02 owner、其他 Task notes、原版 EXE/BIN 或 Client。
