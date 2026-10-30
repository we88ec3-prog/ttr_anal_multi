# E59 — T02 RR-0006：KR Client `0x2633` 壓縮封包、`0x22D7` 分支、`0x727190`、checksum failure 與封包節點生命週期（原生 BIN-first）

> **研究目標**：回答正式 RR-0006／GAP-NET-0003 的 `0x807B40 → 0x727190 / 0x807E50 → 0x8076F0` 邊界，特別區分**壓縮解碼失敗**、**`0x0BBB` checksum 失敗**、**外層框架無效**、**部分幀不足**、**raw `0x22D7` / 未識別 marker** 與 **Client 程式所允許的 T03 relevant S2C dispatch**。本稿僅供 T01/S00 對有界原生主張審查；原版 Server 真實封包未錄製，無任何 Client runtime 測試。重大新進展或固定子段數均不是停止原因。

- 研究日期：2026-10-30T11:22:05+08:00，操作 `chatgpt-web roy`，KR Client only。
- `Tartaros.bin`: 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；**原件唯讀**；PE `.text` VA=0x401000, raw=0x400, raw size=0x7D01F0； `.text` `raw=VA-0x400C00`。下文所有 VA 僅此版本。
- 所有帶 `N` 是經原始 BIN bytes 及從**已知入口** objdump 再反組譯；`C` 是受前提保護的靜態推論；`U` 是原件不足以判斷；`SYN` 僅本機自行建立合成樣例，不是原版 packet capture。
- 來源延續：T02 RR-0001 E57（first-frame、0BBB checksum）、RR-0004 E58（A02C 出站 mode／fallback）、RR-0005 E56（連線／handler gate）。此次不重作已知 Socket API 發現，只做 RR-0006 的接收錯誤／壓縮／物件壽命有界深挖。
- 啟動時 S00 RR 台帳 RR-0006 `QUEUED`, owner=T02, KR, priority=P1, GAP-NET-0003；正式認領已由 PR #36 Merge main，RR-0007 不受影響。實際 submission/blob SHA 以完成提交後遠端驗證為準。

## 一、玩家視角：這份研究要確定什麼？

遊戲收到了伺服器傳來的一封「包裹」。若包裹標示 0x2633，Client 把資料做逐位元組還原、交給內建解壓縮函式，再決定是否交給登入／選角邏輯。若資料損壞或無法解壓，不能把壞內容當成有效命令；還要知道暫存封包節點如何歸還，避免誤判為必定斷線。

## 二、驗收主張矩陣（研究終點與 Server 意義）

| 正式研究項 | 可證答案與限制 | 類別 | 對 S00 的有界使用建議 |
| --- | --- | --- | --- |
| `0x2633` schema | header `u16 payload_len`、`u16 marker=0x2633`、**再 4 bytes 的值在本 parser 無明確消費**，故總 header8；payload 先 XOR-chain、再呼叫 decompress；壓縮內容原始語意需以內部膨脹器與更大情境驗證 | N/C | 應以8-byte header分割；不要發明 +4 四 bytes 的官方欄位名稱 |
| `0x22D7` schema | 特別比較 0x22D7 但採 4-byte header、raw copy；**unknown marker 在這個 parser 亦保持預設 header4/raw** | N | 只證 parser 本地 acceptance，不能當官方明文封包白名單 |
| `0x727190` | 初始化內部 inflate-like state（0x727310，window bits 15）、循環呼叫 0x7274B0、成功時更新 output-count，回收 0x728940；parser 只以 return==0 判成功 | N/C | 壓縮 output 最多 0x1000，錯誤不得投遞業務 handler；不要假造官方 compressed bytes |
| `0x0BBB` checksum | XOR-chain 先還原 plaintext，累加 bytes mod 65536，比 header+4 16-bit； mismatch 走失敗歸還而非 copy | N | 不把 checksum 不匹配資料作業務訊息 |
| `0x2633` 失敗 | 727190 nonzero 直接跳 807D7F，不設定 node+4 length；同一 node 回收，當幀仍被計入 consume | N | 區分壓縮失敗與 framing fatal，不能推論固定斷線 |
| frame 壞長度 | payload len==0 或 >0x1000 走 807E1D return0，不走已就緒的 dispatch；IOCP caller 對 return0 與 return1 有不同後續 | N/C | 不應把錯長度視為空的有效 command |
| frame 尚不完整 | header不足4B、或 header+payload 尚未收滿，進 807DDA 殘留 compact，等後續 receive | N | 需要支援 TCP 分段及粘包；不可每次 WSARecv 等於一完整 frame |
| node/pool | 0x8075B0 從 FE3358 取 node；`+4` length 初始零、`+8` payload、node allocation 0x100C；長度零 `804310→8076F0` 還池；有正長度則 `489920→8040A0` 經 Conn+A080 lane 投遞 | N/C | 壞 payload 不進上層；不等於 socket 必定關閉 |
| 0x0013/0x007A T03 consumer | 必須是合法的 decoded **application payload**、非空，lane2 和 callback/vtable/handler table gate 達成，才有到 0x4930E0→0x4C4670→0x4C37A0/0x4C3C10 的靜態可達性 | C | 不把外層 marker 當登入/選服 command，亦不可聲稱已捕獲伺服器首回覆 |
| 原版 Server 壓縮決策或 checksum policy | Client DLL/BIN 靜態只給 receiver 能接受及拒絕的條件；無原版 Server/pcap 不知哪個封包先被採用 | U | 留給 Server implementation / integration / runtime validation |

## 三、`807B40` frame parser：接收、分類與邊界

### 3.1 從 Windows IOCP 到 frame parser 的正向呼叫

`806CF0` IOCP thread 的 receive OVERLAPPED 分支在 `806DE4–806E08` 判定 `Conn+A030`，增加 recv completion/bytes counters，並在 `Conn+A0AC` 有效時以 `ECX=completed_bytes`、`EDX=Conn+0x18`、stack arg `Conn*` 呼叫 `0x807B40`。`806E0D` 接受 parser status；**return1 走 manager vtable+0x14 再 post recv；return0 走 `806E23` 的 Conn+A0B0 / manager+0x58 判斷與可能 stop**。因此解析異常、checksum 失配不一定等於同一種斷線行為。

**正向 N 證據節錄：**

```asm
806de4: lea edi,[eax+0xa030]
806dea: cmp edx,edi
806df2: add DWORD PTR [ebx+0x2c],ecx
806df5: inc DWORD PTR [ebx+0x3c]
806dfe: je 0x806d30
806e04: lea edx,[eax+0x18]
806e07: push eax
806e08: call 0x807b40
806e0d: test eax,eax
806e12: je 0x806e23
806e14: mov edx,DWORD PTR [ebx]
806e16: mov edx,DWORD PTR [edx+0x14]
806e1c: call edx
```

### 3.2 當前積累與完整帧判斷

- `807B8A` 把輸入 byte count `ECX` 加到 `[RxBase+0x5000]`（接收寫入游標，非純長度欄），以 `ebx=RxBase` 由 offset0 逐個讀框。
- `<4 bytes` 時進尾端 compact，保留殘留，等待下次 WSARecv；`n==0`／`n>0x1000` 是 invalid，`807E1D` return0；不應宣稱 payload 可為 zero-length valid frame。
- 用 `[ebx+2]` 比 marker：`0x2633` 標記 compressed，header8；`0x0BBB` 標記 XOR/checksum，header6；`0x1A68` 或 `0x22D7` 均 header4；**其他 marker 也維持預設 header4**，並非本函式強制拒絕未認識的 marker。
- `[ebx]=n`，只有 `n+header_bytes<=available_bytes` 才往下分配 node；不足時保留資料。`807C93..807CC5` 還檢查 payload pointer/end 在 `RxBase..RxBase+0x5000` 範圍，超界走殘留處理，不能虛構 opcode。
- 這裡的 `n` 是 framing payload length，不是 `0x2633` 解壓後長度；+4...+7 四 bytes 在本解析程式內**跳過而未用作解壓目標長度/校驗**（其後其他 consumer 可能另有用途未證）。

```asm
807bb0: movzx esi,WORD PTR [ebx]
807bb5: cmp si,cx
807bb8: je 0x807e1d
807bbe: mov edx,0x1000
807bc3: cmp si,dx
807bc6: ja 0x807e1d
807bd4: movzx ecx,WORD PTR [ebx+2]
807be5: cmp cx,0x2633
807bea: mov DWORD PTR [esp+0x18],1
807bf2: mov DWORD PTR [esp+0x20],8
807c04: cmp cx,0x0bbb
807c06: mov DWORD PTR [esp+0x1c],1
807c0e: mov DWORD PTR [esp+0x20],6
807c22: mov edx,0x22d7
807c27: cmp cx,dx
807c2c: mov DWORD PTR [esp+0x20],4
```

### 3.3 `0x22D7` vs 任意 marker：不能誇大

原始 `807BDD` 先把 header =4。若 marker=0x2633/0x0BBB 改 header；若 marker=0x1A68 導向 `807C2C` 再設定4；若 marker=0x22D7 同；若**其他 marker**，`807C2A jne 807C34`，並未在這一函式拒絕，也不設 compressed/XOR flag。如此仍可能以 raw bytes+4 進 node+8；**上層 handler 可能因 payload 不是已註冊命令而拒絕**，不能倒推原版 Server 保證使用該 marker。

## 四、`0x2633` 的逐位元組解碼及壓縮器接合

### 4.1 為何它是8-byte header，及 bytes+4...+7 的證據界線

`807BEA` 對 marker 0x2633 設 `[esp+0x18]=1`, `[esp+0x20]=8`；`807C86` 先將 payload 起點選為 `ebx+8`；`807CD2` 讀該位置第一個 byte，而**非** frame+4；0x2633 frame header 的後4 bytes在此 parser內沒有取成膨脹長度／checksum 的讀取。不得命名為官方 `compressed_size`、`original_size` 或 Adler32。`[ebx]` 才是 encrypted/compressed input length。

### 4.2 XOR 解開 compressed stream（非 0x0BBB 的演算法）

`0x2633` 使用 `0x7C` 種子，首 byte `d[0]=cipher[0] XOR 0x7C`；後續 `d[i]=cipher[i] XOR d[i-1]`，解出的所有 bytes 放 stack scratch `esp+0x2C`，長度 `n` 不大於 0x1000。這與 `0x0BBB` 的 0xB6 seed 不同，**不可混用**。

```asm
807cd2: mov dl,BYTE PTR [edi]
807cd4: xor dl,0x7c
807cdc: mov BYTE PTR [esp+0x2c],dl
807ce4: mov cl,BYTE PTR [edi+eax]
807ce7: xor cl,BYTE PTR [esp+eax+0x2b]
807cec: mov BYTE PTR [esp+eax+0x2b],cl
807cf4: lea edx,[esp+0x102c]
807cfc: mov ecx,esi
807d02: lea edi,[esp+0x1c]
807d06: mov DWORD PTR [esp+0x1c],0x1000
807d0e: call 0x727190
```

**ABI 實際輸入**（從 callsite 推導，重要）：`0x727190` 不是傳統 `cdecl(out,cap,in,len)`，而是本地自定義 register/stack：`EAX=stack decoded input ptr`, `ECX=compressed_len`, `EDI=pointer_to_max_out_size`, stack arg=`output_buffer_ptr`。回傳 `EAX` 成功（0）／非零失敗，成功將輸出長度寫回 `[EDI]`。不能以同地址在其他 caller 上的假設直接套用。

### 4.3 decompress `0x727190`：成功與錯誤返回

`727190` 先保存 input/output 相關 state，`EAX=15` 呼叫 `727310` 初始化 inflator，`7271CE` 呼叫 `7274B0` 執行 inflate-like 過程，`7271D8` `EBX==1` 是 end-of-stream；`727206` 更新 caller 的 output-size pointer，`72720C` 呼叫 `728940` cleanup，並把 cleanup 的 return 值留在 `EAX`。原件 `72897A xor eax,eax` 確認正常 cleanup 回傳0。其餘情況可能保留負的解壓 status、返回 -3 或 init error，網路 parser 不細分：`807D16 test eax; jne 807D7F` 一律不交給 807E50。

**有界格式推論**：內部 `7274B0` 有 DEFLATE-like Huffman/table state 與 zlib-style header 字段檢查（`0x7275D5 div 31`, `0x7275E7 cmp dl,8`）、通用引擎某些狀態處理 `0x1F8B` gzip signature；但不能由此保證此網路 caller 的 window/config 可接受 gzip/所有 deflate 封裝，也不能宣稱原版 Server 實際採用某種 zlib 參數。最可靠的本地行為是「對長度 n 的先 XOR bytes 呼叫 727190，以0判成功」。

### 4.4 膨脹的目的緩衝區／上限

`807D06` 把局部 `out_capacity=0x1000` 放在被呼叫者讀取的 output length 地址；`807D13` 返回0後 `807D1A` 讀 `[esp+0x18]` 作為實際膨脹長度，`807D22` 將輸出 stack buffer `esp+0x102C` 交 `807E50`；後者在 `ESI>0x1000` 時拒絕寫入。**解壓成功和 command valid 仍是兩件事**，若膨脹結果 0 長或後續無 handler，均不能把它說成有效登入/選角命令。

## 五、checksum 失配、decompress 失敗、無效長度：三條不同錯誤路

### 5.1 `0x0BBB`: checksum 验证失敗

`807D33` 先 `cipher[0] ^ 0xB6`，後續逐 byte XOR 上一解出 bytes，對 plaintext bytes 做 16-bit 加總；`807D66 cmp WORD [ebx+4],cx`；**不等**時 `807D6A→807D7F`，**直接略過 `807E50` payload copy**。這裡的 checksum 不等於 TCP/IP checksum，也不等於 zlib 的 Adler/CRC；它是 **`0x0BBB` 外層2-byte sum**。`0x2633` 不經此比較。

### 5.2 `0x2633`: 解壓縮返回非零

`807D16 test eax; 807D18 jne 807D7F`。與 checksum 失配相同，跳過 `807E50` 的成功 payload copy，導向 node length zero 的回收判定，**不是**直接由 `727190` 觸發 `closesocket`。同時這個 frame 被迴圈消費。下次收包是否成功/原版 Server 是否重發不在此 Client parser 中可知。

### 5.3 malformed frame length: return0 的較嚴重 parser branch

`807BB5/807BC3` 的 `n==0` 和 `n>0x1000` 直接 `807E1D xor eax,eax`；**在這條路上甚至還沒從 pool 取 node**，因此與 checksum/decompress failure「取 node 後回收」不同。IOCP caller 檢查 parser 0 時轉入 `806E23` Conn flag 的後續分支；不能簡化為所有壞包都立刻 `closesocket`。

### 5.4 frame 不完整與完整後失敗也不同

若收不到4-byte header，或已有 header 但其宣告 payload 尚未完整，跳 `807DDA`，`807E03..807E14` 將餘留 bytes memcpy 到接收 buffer 前端，更新 Rx write cursor；保留到下次 receive。跟 checksum mismatch 相反，此時**尚未判定 frame 壞掉**。

## 六、`0x807E50` → node/pool → application dispatcher 的精確鏈

### 6.1 pool node 生命週期

`807C7C mov edi,0xFE3358; call 8075B0`：FE3358 是接收 frame/node pool 入口。`8075B0` 初次填空時對每 node `malloc(0x100C)`，設 `node+0=0`, `node+4=0`, `node+8` 開始 4096 bytes，`node+0x1008` 為內部元資料/序號。`pool+0x3C` 是空閒 queue／容器，`pool+0x54` 是活動個數。`8075B0` 選出節點時再將 `node+0/+4` 清0。

`807E50` 若解出的長度 `ESI <= 0x1000`，呼叫 `0x89DBD0` 複製 `ESI` 到 `[node+8]`，成功後**寫 `[node+4]=ESI`**；若長度太大返回0、不寫長度。故 `node+4>0` 是是否有有效 decoded payload 的本地 gate。

```asm
807e50: push ebp
807e53: cmp esi,0x1000
807e59: jbe 0x807e61
807e5b: xor al,al
807e61: mov eax,DWORD PTR [ebp+0x8]
807e66: lea ecx,[edi+8]
807e6a: call 0x89dbd0
807e72: mov DWORD PTR [edi+4],esi
807e75: mov al,1
```

### 6.2 Failed frame: 先返 pool，並非消費業務

當 checksum 不符合／inflate 失敗時，節點先前由 `0x8075B0` 初始化為 `length=0`，且沒有呼叫 `807E50`，所以 `807D83 cmp DWORD [node+4],0` 為真，接著 `0x804310→0x8076F0` 重設 node+0/+4，在 FE3358 空閒池排回並減少使用計數。**沒有呼叫 `0x489920→0x8040A0` 上層 dispatch**。

`807DB2–807DCE` 仍加上 `header + wire_length` 移動 `EBX` 到下一個 frame，後續 `807DDA..807E16` 對剩餘 bytes compact。若所有邊界有效，函式返回1，IOCP 有機會重新 post recv。這是「壞 payload 被丟棄但 socket 不必然立即關閉」的有界靜態規格。

### 6.3 Good frame: lane2 與 T03 消費者

如果 `node+4>0`，`807D9E` 取當次 `Conn+A080` 作應用 lane，呼叫 `489920 → 8040A0` 把 node 發往全域應用佇列（E54 verified boundary）。後續 Main loop 的 `804740 → 80486D → 4930E0` 在**lane=2、有效 client vtable、payload WORD、handler table 及 receiver 已安裝**時，才可有條件到 S2C command `0x0013` receiver `0x4C37A0`、`0x007A` receiver `0x4C3C10` 等 T03 選服命令。**此跨 Task chain 是條件式**，不代表 `0x2633` 必然帶 0x0013、不代表任何原版 server-first reply。

## 七、相容 Server 對應的有限規格、反證與測試

| 類別 | 可轉交內容 | 不能承諾的事 |
| --- | --- | --- |
| Client 原生相容界面 | framing header `n,marker`, `n` 1..0x1000, 2633 header8，2633 XOR(seed7C) 再 inflate；0BBB header6 XOR(seedB6) +16-bit sum；22D7/raw header4 | 不能把 22D7 宣稱唯一 raw marker；不能將 2633 +4 bytes 猜作官方 checksum |
| Client 本地失敗與回收 | payload 非法時 node 不交業務；壓縮／checksum 失敗會回收 node；無效 n 時 parser return0；partial TCP frame 保留 | 不能推論原版 Server 是否重傳／斷線或重試政策 |
| Server 待開發 | S00 可建立 **非生產** test vectors（合法/錯 checksum/壞 zlib/不完整/多 frame/unknown marker），記錄 Client 解碼/丟棄行為；選擇是否輸出 2633 是 Server 端設計決策 | synthetic vector≠原版 server wire；本稿未測真 Client 動態反應 |
| 跨功能待整合 | 合法解析的 decoded bytes 才能到 T03 的 0x0013/0x007A 等業務 handler；具體業務 schema 由 T03 依原生證據完成 | 不重寫 T03 選服語意或角色狀態判定 |
| 待遊玩驗證 | 真實接收分段、IOCP scheduling、異常訊息導致何時 UI 更新／斷線 | 單一靜態函式無法驗證實際網路時序 |

**設計要點**：伺服器不應依「Client 對未知 marker 仍可作4B raw copy」推論原版官方協定正式允許所有 marker。S00 可按 Client 可證範圍設計兼容測試和安全的 Server policy（需 ADR），正式 MUST/SHOULD 仍需 T01 定向審查原件。

## 八、限定的局部合成校驗（SYN，非 runtime／PCAP）

用 Python zlib.compress 建一個假想 decoded command `13 00 01 02`；合成壓縮序列：`78 9c 13 66 60 64 02 00 00 54 00 17`。依原件逐 byte inverse/XOR seed0x7C 模擬成 wire payload：`04 e4 8f 75 06 04 66 02 00 54 54 17`；逆轉換回：`78 9c 13 66 60 64 02 00 00 54 00 17`。將 `WORD len=12` + marker `33 26` + 4 bytes **僅作占位**（`00 00 00 00`）+ cipher 可構成**理論示例**；原始 Client 沒有實際執行，也沒有實證接受此組 bytes。此算術檢查只能證明本文推導的 rolling XOR chain 是自洽的；不能把 zlib.compress 的結果稱為原版 Server 壓縮流。

## 九、來源 cross-references／反例測試索引

| 已核對 caller | 原始 `.text` `E8 rel32` 命中 | 意義 |
| --- | --- | --- |

| `0x807B40` | `0x806E08` | RR6 相關 native target caller |

| `0x727190` | `0x47FBE2`, `0x49946A`, `0x72F54A`, `0x7EA551`, `0x7EA8A3`, `0x7EAB4D`, `0x807D0E`, `0x82F7A3`, `0x82F994` | 多來源公共函式；網路只使用列舉的一支 |

| `0x807E50` | `0x807D7A` | RR6 相關 native target caller |

| `0x8075B0` | `0x807C81` | RR6 相關 native target caller |

| `0x8076F0` | `0x807D97` | RR6 相關 native target caller |

| `0x804310` | `0x807D90` | RR6 相關 native target caller |

| `0x8040A0` | `0x807DAD` | RR6 相關 native target caller |

**來源限制**：直接 E8 相對呼叫搜尋只支援標示的 callsites，不能排除 virtual call／jump／alias；並不因看到 727190 其餘 8 個 caller 就把它們的其他資源解壓語意套到網路。`0x727190` 第一手地址保持一致；本稿沒有外部 symbol map 的函數原名鑑定。

### 實際可區分的資料處理結果（無人為補值）

| Input 類別 | parser output 判定 | pool node | 回覆 handler |
| --- | --- | --- | --- |
| 未滿 header / frame | 等收包／compaction、return1 若 bounds 有效 | 不先分配未完成 node | 無 |
| payload n=0／>0x1000 | return0 | 不分配 | 無 |
| 0x0BBB checksum mismatched | 該 frame 消費後通常 return1 | 先分配 node, len0 → pool | 無 |
| 0x2633 inflate return nonzero | 同上 | 先分配 node, len0 → pool | 無 |
| 0x2633 inflate success 且 size>0 | 拷貝 decoded payload | node len>0 → app queue | 僅條件式可達 |
| 0x1A68/0x22D7/unknown raw with >0 | raw copy | node len>0 → app queue | 僅條件式可達 |

## 十、未解範圍與結束判定

1. **Client 靜態已完成的 RR-0006 最小閉合問題**：2633/22D7 parser、727190 接口/成功條件、0BBB checksum mismatch、807E50 node+4、8075B0/8076F0 pool、IOCP 回呼 0 vs1 與 app lane gate 均有原始 bytes/CFG。已可交正式 bounded 原生研究審查，並且不是單純「發現重大突破」停止。
2. **不屬 Client-only 可證的 Server 行為**：原版後端真正是否／何時採 2633、+4..+7 的 Server-side 語意、同一玩家實際 S2C 序列、runtime IOCP 對端重傳、特定 UI 是否隨之更新；列為待 Server 規格／待遊玩驗證，不能冒稱 T02 未做 Client 靜態查驗。
3. **局部仍未知、待 T01 審查的部分**：727190 generic inflate 支援的每一種 wrapper/config 細節、unknown marker 是否被更上層 application 拒絕、`0x8075B0` OOM 或異常 memory 行為，這些不應從此片段推成原版官方伺服器規則。若 S00 的特定設計需要上游更多實證，可提出有界退回或下一 RR，不會因保留 unknown 就自動把已證的錯誤/回收鏈說成不存在。
4. **下一步**：研究原稿上傳、blob SHA readback、正式 RR `CLAIMED→IN_PROGRESS→SUBMITTED`，T01 執行 R1/R2/R3 native review，最後只有 S00 可按 acceptance 決定 ACCEPTED。RR-0007 的 scene business command 個別細節留其 owner；不擅自認領。

## 附錄 A：原始 BIN 組合語言（完整目標視窗）

以下 asm **由本次重讀相同 SHA 的 `.text` slice** 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000` 直接抽取，每個 disassembly 都從已知函式入口或以函式入口為主，非失準地址拼湊。個別函式之後接其他函式的尾端顯示，只是 address range 邊界參考，不暗示它們屬同一函式。大量重複 WinSock 既知部分不等同新增發現。

### A.1 `0x807B40..0x807E50`: 接收 frame parser 完整已知入口

原生證據包括所有 frame marker、XOR/checksum、inflate call、node dispatch 和 leftover compact。

```asm
00807b40 <.data+0x406b40>:
  807b40:	55                   	push   ebp
  807b41:	8b ec                	mov    ebp,esp
  807b43:	83 e4 f8             	and    esp,0xfffffff8
  807b46:	6a ff                	push   0xffffffff
  807b48:	68 be 98 90 00       	push   0x9098be
  807b4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  807b53:	50                   	push   eax
  807b54:	51                   	push   ecx
  807b55:	b8 24 20 00 00       	mov    eax,0x2024
  807b5a:	e8 11 8b 0a 00       	call   0x8b0670
  807b5f:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b64:	33 c4                	xor    eax,esp
  807b66:	89 84 24 20 20 00 00 	mov    DWORD PTR [esp+0x2020],eax
  807b6d:	53                   	push   ebx
  807b6e:	56                   	push   esi
  807b6f:	57                   	push   edi
  807b70:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807b75:	33 c4                	xor    eax,esp
  807b77:	50                   	push   eax
  807b78:	8d 84 24 38 20 00 00 	lea    eax,[esp+0x2038]
  807b7f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  807b85:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807b88:	8b fa                	mov    edi,edx
  807b8a:	01 8f 00 50 00 00    	add    DWORD PTR [edi+0x5000],ecx
  807b90:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807b94:	8b 87 00 50 00 00    	mov    eax,DWORD PTR [edi+0x5000]
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
  807c44:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  807c4b:	75 2f                	jne    0x807c7c
  807c4d:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  807c54:	c7 84 24 40 20 00 00 	mov    DWORD PTR [esp+0x2040],0x0
  807c5b:	00 00 00 00 
  807c5f:	e8 bc f4 ff ff       	call   0x807120
  807c64:	68 90 0b bd 00       	push   0xbd0b90
  807c69:	e8 ac a6 08 00       	call   0x89231a
  807c6e:	83 c4 04             	add    esp,0x4
  807c71:	c7 84 24 40 20 00 00 	mov    DWORD PTR [esp+0x2040],0xffffffff
  807c78:	ff ff ff ff 
  807c7c:	bf 58 33 fe 00       	mov    edi,0xfe3358
  807c81:	e8 2a f9 ff ff       	call   0x8075b0
  807c86:	8d 3c 1e             	lea    edi,[esi+ebx*1]
  807c89:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807c8c:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  807c90:	8d 0c 3e             	lea    ecx,[esi+edi*1]
  807c93:	3b 7c 24 14          	cmp    edi,DWORD PTR [esp+0x14]
  807c97:	0f 82 39 01 00 00    	jb     0x807dd6
  807c9d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807ca1:	81 c2 00 50 00 00    	add    edx,0x5000
  807ca7:	3b fa                	cmp    edi,edx
  807ca9:	0f 83 27 01 00 00    	jae    0x807dd6
  807caf:	3b 4c 24 14          	cmp    ecx,DWORD PTR [esp+0x14]
  807cb3:	0f 82 1d 01 00 00    	jb     0x807dd6
  807cb9:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807cbd:	81 c2 00 50 00 00    	add    edx,0x5000
  807cc3:	3b ca                	cmp    ecx,edx
  807cc5:	0f 83 0b 01 00 00    	jae    0x807dd6
  807ccb:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  807cd0:	74 5a                	je     0x807d2c
  807cd2:	8a 17                	mov    dl,BYTE PTR [edi]
  807cd4:	80 f2 7c             	xor    dl,0x7c
  807cd7:	b8 01 00 00 00       	mov    eax,0x1
  807cdc:	88 54 24 2c          	mov    BYTE PTR [esp+0x2c],dl
  807ce0:	3b f0                	cmp    esi,eax
  807ce2:	76 10                	jbe    0x807cf4
  807ce4:	8a 0c 07             	mov    cl,BYTE PTR [edi+eax*1]
  807ce7:	32 4c 04 2b          	xor    cl,BYTE PTR [esp+eax*1+0x2b]
  807ceb:	40                   	inc    eax
  807cec:	88 4c 04 2b          	mov    BYTE PTR [esp+eax*1+0x2b],cl
  807cf0:	3b c6                	cmp    eax,esi
  807cf2:	72 f0                	jb     0x807ce4
  807cf4:	8d 94 24 2c 10 00 00 	lea    edx,[esp+0x102c]
  807cfb:	52                   	push   edx
  807cfc:	8b ce                	mov    ecx,esi
  807cfe:	8d 44 24 30          	lea    eax,[esp+0x30]
  807d02:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  807d06:	c7 44 24 1c 00 10 00 	mov    DWORD PTR [esp+0x1c],0x1000
  807d0d:	00 
  807d0e:	e8 7d f4 f1 ff       	call   0x727190
  807d13:	83 c4 04             	add    esp,0x4
  807d16:	85 c0                	test   eax,eax
  807d18:	75 65                	jne    0x807d7f
  807d1a:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  807d1e:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d22:	8d 84 24 2c 10 00 00 	lea    eax,[esp+0x102c]
  807d29:	50                   	push   eax
  807d2a:	eb 4e                	jmp    0x807d7a
  807d2c:	83 7c 24 1c 00       	cmp    DWORD PTR [esp+0x1c],0x0
  807d31:	74 44                	je     0x807d77
  807d33:	8a 07                	mov    al,BYTE PTR [edi]
  807d35:	34 b6                	xor    al,0xb6
  807d37:	0f b6 c8             	movzx  ecx,al
  807d3a:	8b d1                	mov    edx,ecx
  807d3c:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  807d40:	ba 01 00 00 00       	mov    edx,0x1
  807d45:	88 44 24 2c          	mov    BYTE PTR [esp+0x2c],al
  807d49:	3b f2                	cmp    esi,edx
  807d4b:	76 19                	jbe    0x807d66
  807d4d:	8d 49 00             	lea    ecx,[ecx+0x0]
  807d50:	8a 04 3a             	mov    al,BYTE PTR [edx+edi*1]
  807d53:	32 44 14 2b          	xor    al,BYTE PTR [esp+edx*1+0x2b]
  807d57:	42                   	inc    edx
  807d58:	88 44 14 2b          	mov    BYTE PTR [esp+edx*1+0x2b],al
  807d5c:	0f b6 c0             	movzx  eax,al
  807d5f:	66 03 c8             	add    cx,ax
  807d62:	3b d6                	cmp    edx,esi
  807d64:	72 ea                	jb     0x807d50
  807d66:	66 39 4b 04          	cmp    WORD PTR [ebx+0x4],cx
  807d6a:	75 13                	jne    0x807d7f
  807d6c:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d70:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  807d74:	51                   	push   ecx
  807d75:	eb 03                	jmp    0x807d7a
  807d77:	57                   	push   edi
  807d78:	8b f8                	mov    edi,eax
  807d7a:	e8 d1 00 00 00       	call   0x807e50
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
  807db2:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  807db5:	03 54 24 20          	add    edx,DWORD PTR [esp+0x20]
  807db9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  807dbd:	8b 80 00 50 00 00    	mov    eax,DWORD PTR [eax+0x5000]
  807dc3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dc7:	03 da                	add    ebx,edx
  807dc9:	2b c3                	sub    eax,ebx
  807dcb:	83 f8 04             	cmp    eax,0x4
  807dce:	0f 83 dc fd ff ff    	jae    0x807bb0
  807dd4:	eb 04                	jmp    0x807dda
  807dd6:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dda:	8b b7 00 50 00 00    	mov    esi,DWORD PTR [edi+0x5000]
  807de0:	8d 87 00 50 00 00    	lea    eax,[edi+0x5000]
  807de6:	2b f3                	sub    esi,ebx
  807de8:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807dec:	8d 0c 1e             	lea    ecx,[esi+ebx*1]
  807def:	3b df                	cmp    ebx,edi
  807df1:	72 2a                	jb     0x807e1d
  807df3:	3b d8                	cmp    ebx,eax
  807df5:	73 26                	jae    0x807e1d
  807df7:	3b cf                	cmp    ecx,edi
  807df9:	72 22                	jb     0x807e1d
  807dfb:	3b c8                	cmp    ecx,eax
  807dfd:	73 1e                	jae    0x807e1d
  807dff:	85 f6                	test   esi,esi
  807e01:	78 1a                	js     0x807e1d
  807e03:	56                   	push   esi
  807e04:	53                   	push   ebx
  807e05:	57                   	push   edi
  807e06:	e8 e5 94 08 00       	call   0x8912f0
  807e0b:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  807e0f:	83 c4 0c             	add    esp,0xc
  807e12:	03 fe                	add    edi,esi
  807e14:	89 38                	mov    DWORD PTR [eax],edi
  807e16:	b8 01 00 00 00       	mov    eax,0x1
  807e1b:	eb 02                	jmp    0x807e1f
  807e1d:	33 c0                	xor    eax,eax
  807e1f:	8b 8c 24 38 20 00 00 	mov    ecx,DWORD PTR [esp+0x2038]
  807e26:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  807e2d:	59                   	pop    ecx
  807e2e:	5f                   	pop    edi
  807e2f:	5e                   	pop    esi
  807e30:	5b                   	pop    ebx
  807e31:	8b 8c 24 20 20 00 00 	mov    ecx,DWORD PTR [esp+0x2020]
  807e38:	33 cc                	xor    ecx,esp
  807e3a:	e8 c2 91 08 00       	call   0x891001
  807e3f:	8b e5                	mov    esp,ebp
  807e41:	5d                   	pop    ebp
  807e42:	c2 04 00             	ret    0x4
  807e45:	cc                   	int3
  807e46:	cc                   	int3
  807e47:	cc                   	int3
  807e48:	cc                   	int3
  807e49:	cc                   	int3
  807e4a:	cc                   	int3
  807e4b:	cc                   	int3
  807e4c:	cc                   	int3
  807e4d:	cc                   	int3
  807e4e:	cc                   	int3
  807e4f:	cc                   	int3
  807e50:	55                   	push   ebp
  807e51:	8b ec                	mov    ebp,esp
  807e53:	81 fe 00 10 00 00    	cmp    esi,0x1000
  807e59:	76 06                	jbe    0x807e61
  807e5b:	32 c0                	xor    al,al
  807e5d:	5d                   	pop    ebp
  807e5e:	c2 04 00             	ret    0x4
  807e61:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807e64:	56                   	push   esi
  807e65:	50                   	push   eax
  807e66:	8d 4f 08             	lea    ecx,[edi+0x8]
  807e69:	51                   	push   ecx
  807e6a:	e8 61 5d 09 00       	call   0x89dbd0
  807e6f:	83 c4 0c             	add    esp,0xc
  807e72:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  807e75:	b0 01                	mov    al,0x1
  807e77:	5d                   	pop    ebp
  807e78:	c2 04 00             	ret    0x4
  807e7b:	cc                   	int3
  807e7c:	cc                   	int3
  807e7d:	cc                   	int3
  807e7e:	cc                   	int3
  807e7f:	cc                   	int3
  807e80:	55                   	push   ebp
  807e81:	8b ec                	mov    ebp,esp
  807e83:	83 e4 f8             	and    esp,0xfffffff8
  807e86:	83 ec 2c             	sub    esp,0x2c
  807e89:	53                   	push   ebx
  807e8a:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  807e8d:	56                   	push   esi
  807e8e:	57                   	push   edi
  807e8f:	8d 44 24 14          	lea    eax,[esp+0x14]
  807e93:	50                   	push   eax
  807e94:	ff 15 18 21 bd 00    	call   DWORD PTR ds:0xbd2118
  807e9a:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807e9e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  807ea1:	8d 7c 3f 02          	lea    edi,[edi+edi*1+0x2]
  807ea5:	89 79 04             	mov    DWORD PTR [ecx+0x4],edi
  807ea8:	33 c9                	xor    ecx,ecx
  807eaa:	8b c7                	mov    eax,edi
  807eac:	ba 04 00 00 00       	mov    edx,0x4
  807eb1:	f7 e2                	mul    edx
  807eb3:	0f 90 c1             	seto   cl
  807eb6:	f7 d9                	neg    ecx
  807eb8:	0b c8                	or     ecx,eax
  807eba:	51                   	push   ecx
  807ebb:	e8 7d 5d 07 00       	call   0x87dc3d
  807ec0:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  807ec3:	83 c4 04             	add    esp,0x4
  807ec6:	33 f6                	xor    esi,esi
  807ec8:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  807ecb:	85 ff                	test   edi,edi
  807ecd:	7e 43                	jle    0x807f12
  807ecf:	8d 54 24 10          	lea    edx,[esp+0x10]
  807ed3:	52                   	push   edx
  807ed4:	6a 00                	push   0x0
  807ed6:	53                   	push   ebx
  807ed7:	68 90 7f 80 00       	push   0x807f90
  807edc:	6a 00                	push   0x0
  807ede:	6a 00                	push   0x0
  807ee0:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  807ee7:	00 
  807ee8:	e8 3f e2 08 00       	call   0x89612c
  807eed:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  807ef0:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  807ef3:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  807ef6:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807efa:	50                   	push   eax
  807efb:	8b ce                	mov    ecx,esi
  807efd:	ba 74 17         	mov    edx,0xc51774
```

### A.2 `0x727190` inflate wrapper/init/cleanup

從 0x727190 正式入口；後續同一視窗會包含鄰近 helper，勿將其他入口視為 wrapper 一部分。

```asm
00727190 <.data+0x326190>:
  727190:	55                   	push   ebp
  727191:	8b ec                	mov    ebp,esp
  727193:	83 e4 f8             	and    esp,0xfffffff8
  727196:	83 ec 38             	sub    esp,0x38
  727199:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  72719c:	89 04 24             	mov    DWORD PTR [esp],eax
  72719f:	8b 07                	mov    eax,DWORD PTR [edi]
  7271a1:	53                   	push   ebx
  7271a2:	33 db                	xor    ebx,ebx
  7271a4:	56                   	push   esi
  7271a5:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  7271a9:	8d 43 0f             	lea    eax,[ebx+0xf]
  7271ac:	8d 74 24 08          	lea    esi,[esp+0x8]
  7271b0:	89 4c 24 0c          	mov    DWORD PTR [esp+0xc],ecx
  7271b4:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  7271b8:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  7271bc:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  7271c0:	e8 4b 01 00 00       	call   0x727310
  7271c5:	3b c3                	cmp    eax,ebx
  7271c7:	75 48                	jne    0x727211
  7271c9:	8b ce                	mov    ecx,esi
  7271cb:	6a 04                	push   0x4
  7271cd:	51                   	push   ecx
  7271ce:	e8 dd 02 00 00       	call   0x7274b0
  7271d3:	8b d8                	mov    ebx,eax
  7271d5:	83 c4 08             	add    esp,0x8
  7271d8:	83 fb 01             	cmp    ebx,0x1
  7271db:	74 29                	je     0x727206
  7271dd:	e8 5e 17 00 00       	call   0x728940
  7271e2:	83 fb 02             	cmp    ebx,0x2
  7271e5:	74 14                	je     0x7271fb
  7271e7:	83 fb fb             	cmp    ebx,0xfffffffb
  7271ea:	75 07                	jne    0x7271f3
  7271ec:	83 7c 24 0c 00       	cmp    DWORD PTR [esp+0xc],0x0
  7271f1:	74 08                	je     0x7271fb
  7271f3:	8b c3                	mov    eax,ebx
  7271f5:	5e                   	pop    esi
  7271f6:	5b                   	pop    ebx
  7271f7:	8b e5                	mov    esp,ebp
  7271f9:	5d                   	pop    ebp
  7271fa:	c3                   	ret
  7271fb:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  727200:	5e                   	pop    esi
  727201:	5b                   	pop    ebx
  727202:	8b e5                	mov    esp,ebp
  727204:	5d                   	pop    ebp
  727205:	c3                   	ret
  727206:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  72720a:	89 17                	mov    DWORD PTR [edi],edx
  72720c:	e8 2f 17 00 00       	call   0x728940
  727211:	5e                   	pop    esi
  727212:	5b                   	pop    ebx
  727213:	8b e5                	mov    esp,ebp
  727215:	5d                   	pop    ebp
  727216:	c3                   	ret
  727217:	cc                   	int3
  727218:	cc                   	int3
  727219:	cc                   	int3
  72721a:	cc                   	int3
  72721b:	cc                   	int3
  72721c:	cc                   	int3
  72721d:	cc                   	int3
  72721e:	cc                   	int3
  72721f:	cc                   	int3
  727220:	55                   	push   ebp
  727221:	8b ec                	mov    ebp,esp
  727223:	83 ec 38             	sub    esp,0x38
  727226:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  727229:	56                   	push   esi
  72722a:	8b 75 0c             	mov    esi,DWORD PTR [ebp+0xc]
  72722d:	57                   	push   edi
  72722e:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  727231:	8b 06                	mov    eax,DWORD PTR [esi]
  727233:	6a 00                	push   0x0
  727235:	89 45 d8             	mov    DWORD PTR [ebp-0x28],eax
  727238:	6a 0f                	push   0xf
  72723a:	6a ff                	push   0xffffffff
  72723c:	8d 45 c8             	lea    eax,[ebp-0x38]
  72723f:	89 4d cc             	mov    DWORD PTR [ebp-0x34],ecx
  727242:	89 55 d4             	mov    DWORD PTR [ebp-0x2c],edx
  727245:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  72724c:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  727253:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  72725a:	e8 01 25 00 00       	call   0x729760
  72725f:	83 c4 0c             	add    esp,0xc
  727262:	85 c0                	test   eax,eax
  727264:	75 3a                	jne    0x7272a0
  727266:	6a 04                	push   0x4
  727268:	8d 7d c8             	lea    edi,[ebp-0x38]
  72726b:	e8 b0 27 00 00       	call   0x729a20
  727270:	8b f8                	mov    edi,eax
  727272:	83 c4 04             	add    esp,0x4
  727275:	83 ff 01             	cmp    edi,0x1
  727278:	74 19                	je     0x727293
  72727a:	8d 75 c8             	lea    esi,[ebp-0x38]
  72727d:	e8 5e 2f 00 00       	call   0x72a1e0
  727282:	b8 fb ff ff ff       	mov    eax,0xfffffffb
  727287:	85 ff                	test   edi,edi
  727289:	74 15                	je     0x7272a0
  72728b:	8b c7                	mov    eax,edi
  72728d:	5f                   	pop    edi
  72728e:	5e                   	pop    esi
  72728f:	8b e5                	mov    esp,ebp
  727291:	5d                   	pop    ebp
  727292:	c3                   	ret
  727293:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  727296:	89 0e                	mov    DWORD PTR [esi],ecx
  727298:	8d 75 c8             	lea    esi,[ebp-0x38]
  72729b:	e8 40 2f 00 00       	call   0x72a1e0
  7272a0:	5f                   	pop    edi
  7272a1:	5e                   	pop    esi
  7272a2:	8b e5                	mov    esp,ebp
  7272a4:	5d                   	pop    ebp
  7272a5:	c3                   	ret
  7272a6:	cc                   	int3
  7272a7:	cc                   	int3
  7272a8:	cc                   	int3
  7272a9:	cc                   	int3
  7272aa:	cc                   	int3
  7272ab:	cc                   	int3
  7272ac:	cc                   	int3
  7272ad:	cc                   	int3
  7272ae:	cc                   	int3
  7272af:	cc                   	int3
  7272b0:	33 c9                	xor    ecx,ecx
  7272b2:	3b d1                	cmp    edx,ecx
  7272b4:	74 4d                	je     0x727303
  7272b6:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  7272b9:	3b c1                	cmp    eax,ecx
  7272bb:	74 46                	je     0x727303
  7272bd:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  7272c0:	89 4a 14             	mov    DWORD PTR [edx+0x14],ecx
  7272c3:	89 4a 08             	mov    DWORD PTR [edx+0x8],ecx
  7272c6:	89 4a 18             	mov    DWORD PTR [edx+0x18],ecx
  7272c9:	c7 42 30 01 00 00 00 	mov    DWORD PTR [edx+0x30],0x1
  7272d0:	89 08                	mov    DWORD PTR [eax],ecx
  7272d2:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  7272d5:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  7272d8:	89 48 20             	mov    DWORD PTR [eax+0x20],ecx
  7272db:	89 48 28             	mov    DWORD PTR [eax+0x28],ecx
  7272de:	89 48 2c             	mov    DWORD PTR [eax+0x2c],ecx
  7272e1:	89 48 30             	mov    DWORD PTR [eax+0x30],ecx
  7272e4:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  7272e7:	89 48 3c             	mov    DWORD PTR [eax+0x3c],ecx
  7272ea:	8d 88 30 05 00 00    	lea    ecx,[eax+0x530]
  7272f0:	c7 40 14 00 80 00 00 	mov    DWORD PTR [eax+0x14],0x8000
  7272f7:	89 48 6c             	mov    DWORD PTR [eax+0x6c],ecx
  7272fa:	89 48 50             	mov    DWORD PTR [eax+0x50],ecx
  7272fd:	89 48 4c             	mov    DWORD PTR [eax+0x4c],ecx
  727300:	33 c0                	xor    eax,eax
  727302:	c3                   	ret
  727303:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  727308:	c3                   	ret
  727309:	cc                   	int3
  72730a:	cc                   	int3
  72730b:	cc                   	int3
  72730c:	cc                   	int3
  72730d:	cc                   	int3
  72730e:	cc                   	int3
  72730f:	cc                   	int3
  727310:	53                   	push   ebx
  727311:	33 db                	xor    ebx,ebx
  727313:	57                   	push   edi
  727314:	8b f8                	mov    edi,eax
  727316:	3b f3                	cmp    esi,ebx
  727318:	0f 84 83 00 00 00    	je     0x7273a1
  72731e:	89 5e 18             	mov    DWORD PTR [esi+0x18],ebx
  727321:	39 5e 20             	cmp    DWORD PTR [esi+0x20],ebx
  727324:	75 0a                	jne    0x727330
  727326:	c7 46 20 c0 b9 72 00 	mov    DWORD PTR [esi+0x20],0x72b9c0
  72732d:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  727330:	39 5e 24             	cmp    DWORD PTR [esi+0x24],ebx
  727333:	75 07                	jne    0x72733c
  727335:	c7 46 24 e0 b9 72 00 	mov    DWORD PTR [esi+0x24],0x72b9e0
  72733c:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  72733f:	8b 4e 20             	mov    ecx,DWORD PTR [esi+0x20]
  727342:	68 30 25 00 00       	push   0x2530
  727347:	6a 01                	push   0x1
  727349:	50                   	push   eax
  72734a:	ff d1                	call   ecx
  72734c:	83 c4 0c             	add    esp,0xc
  72734f:	3b c3                	cmp    eax,ebx
  727351:	75 08                	jne    0x72735b
  727353:	5f                   	pop    edi
  727354:	b8 fc ff ff ff       	mov    eax,0xfffffffc
  727359:	5b                   	pop    ebx
  72735a:	c3                   	ret
  72735b:	89 46 1c             	mov    DWORD PTR [esi+0x1c],eax
  72735e:	3b fb                	cmp    edi,ebx
  727360:	7d 07                	jge    0x727369
  727362:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  727365:	f7 df                	neg    edi
  727367:	eb 11                	jmp    0x72737a
  727369:	8b d7                	mov    edx,edi
  72736b:	c1 fa 04             	sar    edx,0x4
  72736e:	42                   	inc    edx
  72736f:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  727372:	83 ff 30             	cmp    edi,0x30
  727375:	7d 03                	jge    0x72737a
  727377:	83 e7 0f             	and    edi,0xf
  72737a:	8d 4f f8             	lea    ecx,[edi-0x8]
  72737d:	83 f9 07             	cmp    ecx,0x7
  727380:	77 0f                	ja     0x727391
  727382:	89 78 24             	mov    DWORD PTR [eax+0x24],edi
  727385:	5f                   	pop    edi
  727386:	89 58 34             	mov    DWORD PTR [eax+0x34],ebx
  727389:	8b d6                	mov    edx,esi
  72738b:	5b                   	pop    ebx
  72738c:	e9 1f ff ff ff       	jmp    0x7272b0
  727391:	8b 56 28             	mov    edx,DWORD PTR [esi+0x28]
  727394:	50                   	push   eax
  727395:	8b 46 24             	mov    eax,DWORD PTR [esi+0x24]
  727398:	52                   	push   edx
  727399:	ff d0                	call   eax
  72739b:	83 c4 08             	add    esp,0x8
  72739e:	89 5e 1c             	mov    DWORD PTR [esi+0x1c],ebx
  7273a1:	5f                   	pop    edi
  7273a2:	b8 fe ff ff ff       	mov    eax,0xfffffffe
  7273a7:	5b                   	pop    ebx
  7273a8:	c3                   	ret
  7273a9:	cc                   	int3
  7273aa:	cc                   	int3
  7273ab:	cc                   	int3
  7273ac:	cc                   	int3
  7273ad:	cc                   	int3
  7273ae:	cc                   	int3
  7273af:	cc                   	int3
  7273b0:	55                   	push   ebp
  7273b1:	8b ec                	mov    ebp,esp
  7273b3:	53                   	push   ebx
  7273b4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7273b7:	56                   	push   esi
  7273b8:	8b 73 1c             	mov    esi,DWORD PTR [ebx+0x1c]
  7273bb:	83 7e 34 00          	cmp    DWORD PTR [esi+0x34],0x0
  7273bf:	57                   	push   edi
  7273c0:	8b f8                	mov    edi,eax
  7273c2:	75 2a                	jne    0x7273ee
  7273c4:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7273c7:	8b 53 20             	mov    edx,DWORD PTR [ebx+0x20]
  7273ca:	b8 01 00 00 00       	mov    eax,0x1
  7273cf:	d3 e0                	shl    eax,cl
  7273d1:	8b 4b 28             	mov    ecx,DWORD PTR [ebx+0x28]
  7273d4:	6a 01                	push   0x1
  7273d6:	50                   	push   eax
  7273d7:	51                   	push   ecx
  7273d8:	ff d2                	call   edx
  7273da:	83 c4 0c             	add    esp,0xc
  7273dd:	89 46 34             	mov    DWORD PTR [esi+0x34],eax
  7273e0:	85 c0                	test   eax,eax
  7273e2:	75 0a                	jne    0x7273ee
  7273e4:	5f                   	pop    edi
  7273e5:	5e                   	pop    esi
  7273e6:	b8 01 00 00 00       	mov    eax,0x1
  7273eb:	5b                   	pop    ebx
  7273ec:	5d                   	pop    ebp
  7273ed:	c3                   	ret
  7273ee:	33 c0                	xor    eax,eax
  7273f0:	39 46 28             	cmp    DWORD PTR [esi+0x28],eax
  7273f3:	75 13                	jne    0x727408
  7273f5:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7273f8:	ba 01 00 00 00       	mov    edx,0x1
  7273fd:	d3 e2                	shl    edx,cl
  7273ff:	89 46 30             	mov    DWORD PTR [esi+0x30],eax
  727402:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  727405:	89 56 28             	mov    DWORD PTR [esi+0x28],edx
  727408:	2b 7b 10             	sub    edi,DWORD PTR [ebx+0x10]
  72740b:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  72740e:	3b f8                	cmp    edi,eax
  727410:	72 27                	jb     0x727439
  727412:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  727415:	8b 56 34             	mov    edx,DWORD PTR [esi+0x34]
  727418:	50                   	push   eax
  727419:	2b c8                	sub    ecx,eax
  72741b:	51                   	push   ecx
  72741c:	52                   	push   edx
  72741d:	e8 ae 67 17 00       	call   0x89dbd0
  727422:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  727425:	83 c4 0c             	add    esp,0xc
  727428:	5f                   	pop    edi
  727429:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  72742c:	c7 46 30 00 00 00 00 	mov    DWORD PTR [esi+0x30],0x0
  727433:	5e                   	pop    esi
  727434:	33 c0                	xor    eax,eax
  727436:	5b                   	pop    ebx
  727437:	5d                   	pop    ebp
  727438:	c3                   	ret
  727439:	2b 46 30             	sub    eax,DWORD PTR [esi+0x30]
  72743c:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  72743f:	3b c7                	cmp    eax,edi
  727441:	76 05                	jbe    0x727448
  727443:	89 7d 08             	mov    DWORD PTR [ebp+0x8],edi
  727446:	8b c7                	mov    eax,edi
  727448:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  72744b:	8b 56 34             	mov    edx,DWORD PTR [esi+0x34]
  72744e:	03 56 30             	add    edx,DWORD PTR [esi+0x30]
  727451:	50                   	push   eax
  727452:	2b cf                	sub    ecx,edi
  727454:	51                   	push   ecx
  727455:	52                   	push   edx
  727456:	e8 75 67 17 00       	call   0x89dbd0
  72745b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  72745e:	83 c4 0c             	add    esp,0xc
  727461:	2b f9                	sub    edi,ecx
  727463:	74 23                	je     0x727488
  727465:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  727468:	8b 4e 34             	mov    ecx,DWORD PTR [esi+0x34]
  72746b:	57                   	push   edi
  72746c:	2b c7                	sub    eax,edi
  72746e:	50                   	push   eax
  72746f:	51                   	push   ecx
  727470:	e8 5b 67 17 00       	call   0x89dbd0
  727475:	8b 56 28             	mov    edx,DWORD PTR [esi+0x28]
  727478:	83 c4 0c             	add    esp,0xc
  72747b:	89 7e 30             	mov    DWORD PTR [esi+0x30],edi
  72747e:	5f                   	pop    edi
  72747f:	89 56 2c             	mov    DWORD PTR [esi+0x2c],edx
  727482:	5e                   	pop    esi
  727483:	33 c0                	xor    eax,eax
  727485:	5b                   	pop    ebx
  727486:	5d                   	pop    ebp
  727487:	c3                   	ret
  727488:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  72748b:	01 4e 30             	add    DWORD PTR [esi+0x30],ecx
  72748e:	39 46 30             	cmp    DWORD PTR [esi+0x30],eax
  727491:	75 07                	jne    0x72749a
  727493:	c7 46 30 00 00 00 00 	mov    DWORD PTR [esi+0x30],0x0
  72749a:	8b 56 2c             	mov    edx,DWORD PTR [esi+0x2c]
  72749d:	3b d0                	cmp    edx,eax
  72749f:	73 05                	jae    0x7274a6
  7274a1:	03 d1                	add    edx,ecx
  7274a3:	89 56 2c             	mov    DWORD PTR [esi+0x2c],edx
  7274a6:	5f                   	pop    edi
  7274a7:	5e                   	pop    esi
  7274a8:	33 c0                	xor    eax,eax
  7274aa:	5b                   	pop    ebx
  7274ab:	5d                   	pop    ebp
  7274ac:	c3                   	ret
  7274ad:	cc                   	int3
  7274ae:	cc                   	int3
  7274af:	cc                   	int3
  7274b0:	55                   	push   ebp
  7274b1:	8b ec                	mov    ebp,esp
  7274b3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7274b6:	83 ec 30             	sub    esp,0x30
  7274b9:	57                   	push   edi
  7274ba:	85 c0                	test   eax,eax
  7274bc:	0f 84 e2 13 00 00    	je     0x7288a4
  7274c2:	8b 78 1c             	mov    edi,DWORD PTR [eax+0x1c]
  7274c5:	85 ff                	test   edi,edi
  7274c7:	0f 84 d7 13 00 00    	je     0x7288a4
  7274cd:	83 78 0c 00          	cmp    DWORD PTR [eax+0xc],0x0
  7274d1:	0f 84 cd 13 00 00    	je     0x7288a4
  7274d7:	83 38 00             	cmp    DWORD PTR [eax],0x0
  7274da:	75 0a                	jne    0x7274e6
  7274dc:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
```

### A.3 `0x7274B0` 通用 inflate engine 的入口節錄

只截取已知入口頭段，足以支援 state and header bit tests；深層所有 Huffman branch 不列為本 RR 對 native wire 的獨立保證。

```asm
007274b0 <.data+0x3264b0>:
  7274b0:	55                   	push   ebp
  7274b1:	8b ec                	mov    ebp,esp
  7274b3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7274b6:	83 ec 30             	sub    esp,0x30
  7274b9:	57                   	push   edi
  7274ba:	85 c0                	test   eax,eax
  7274bc:	0f 84 e2 13 00 00    	je     0x7288a4
  7274c2:	8b 78 1c             	mov    edi,DWORD PTR [eax+0x1c]
  7274c5:	85 ff                	test   edi,edi
  7274c7:	0f 84 d7 13 00 00    	je     0x7288a4
  7274cd:	83 78 0c 00          	cmp    DWORD PTR [eax+0xc],0x0
  7274d1:	0f 84 cd 13 00 00    	je     0x7288a4
  7274d7:	83 38 00             	cmp    DWORD PTR [eax],0x0
  7274da:	75 0a                	jne    0x7274e6
  7274dc:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  7274e0:	0f 85 be 13 00 00    	jne    0x7288a4
  7274e6:	83 3f 0b             	cmp    DWORD PTR [edi],0xb
  7274e9:	75 06                	jne    0x7274f1
  7274eb:	c7 07 0c 00 00 00    	mov    DWORD PTR [edi],0xc
  7274f1:	8b 48 0c             	mov    ecx,DWORD PTR [eax+0xc]
  7274f4:	8b 10                	mov    edx,DWORD PTR [eax]
  7274f6:	89 4d e8             	mov    DWORD PTR [ebp-0x18],ecx
  7274f9:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  7274fc:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  7274ff:	53                   	push   ebx
  727500:	8b 5f 38             	mov    ebx,DWORD PTR [edi+0x38]
  727503:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  727506:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  727509:	8b 07                	mov    eax,DWORD PTR [edi]
  72750b:	56                   	push   esi
  72750c:	8b 77 3c             	mov    esi,DWORD PTR [edi+0x3c]
  72750f:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  727512:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  727515:	89 4d e0             	mov    DWORD PTR [ebp-0x20],ecx
  727518:	c7 45 d8 00 00 00 00 	mov    DWORD PTR [ebp-0x28],0x0
  72751f:	83 f8 1c             	cmp    eax,0x1c
  727522:	0f 87 2a 12 00 00    	ja     0x728752
  727528:	ff 24 85 b0 88 72 00 	jmp    DWORD PTR [eax*4+0x7288b0]
  72752f:	83 7f 08 00          	cmp    DWORD PTR [edi+0x8],0x0
  727533:	75 0b                	jne    0x727540
  727535:	c7 07 0c 00 00 00    	mov    DWORD PTR [edi],0xc
  72753b:	e9 07 12 00 00       	jmp    0x728747
  727540:	83 fe 10             	cmp    esi,0x10
  727543:	73 22                	jae    0x727567
  727545:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  727549:	0f 84 52 12 00 00    	je     0x7287a1
  72754f:	0f b6 02             	movzx  eax,BYTE PTR [edx]
  727552:	ff 4d fc             	dec    DWORD PTR [ebp-0x4]
  727555:	8b ce                	mov    ecx,esi
  727557:	d3 e0                	shl    eax,cl
  727559:	42                   	inc    edx
  72755a:	83 c6 08             	add    esi,0x8
  72755d:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  727560:	03 d8                	add    ebx,eax
  727562:	83 fe 10             	cmp    esi,0x10
  727565:	72 de                	jb     0x727545
  727567:	f6 47 08 02          	test   BYTE PTR [edi+0x8],0x2
  72756b:	74 3c                	je     0x7275a9
  72756d:	81 fb 1f 8b 00 00    	cmp    ebx,0x8b1f
  727573:	75 34                	jne    0x7275a9
  727575:	6a 00                	push   0x0
  727577:	6a 00                	push   0x0
  727579:	33 c9                	xor    ecx,ecx
  72757b:	e8 60 41 00 00       	call   0x72b6e0
  727580:	6a 02                	push   0x2
  727582:	8d 4d ec             	lea    ecx,[ebp-0x14]
  727585:	89 47 18             	mov    DWORD PTR [edi+0x18],eax
  727588:	66 89 5d ec          	mov    WORD PTR [ebp-0x14],bx
  72758c:	e8 6f 41 00 00       	call   0x72b700
  727591:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  727594:	83 c4 0c             	add    esp,0xc
  727597:	33 db                	xor    ebx,ebx
  727599:	89 47 18             	mov    DWORD PTR [edi+0x18],eax
  72759c:	33 f6                	xor    esi,esi
  72759e:	c7 07 01 00 00 00    	mov    DWORD PTR [edi],0x1
  7275a4:	e9 9e 11 00 00       	jmp    0x728747
  7275a9:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  7275ac:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  7275b3:	85 c0                	test   eax,eax
  7275b5:	74 07                	je     0x7275be
  7275b7:	c7 40 30 ff ff ff ff 	mov    DWORD PTR [eax+0x30],0xffffffff
  7275be:	f6 47 08 01          	test   BYTE PTR [edi+0x8],0x1
  7275c2:	0f 84 95 00 00 00    	je     0x72765d
  7275c8:	0f b6 c3             	movzx  eax,bl
  7275cb:	c1 e0 08             	shl    eax,0x8
  7275ce:	8b cb                	mov    ecx,ebx
  7275d0:	c1 e9 08             	shr    ecx,0x8
  7275d3:	03 c1                	add    eax,ecx
  7275d5:	33 d2                	xor    edx,edx
  7275d7:	b9 1f 00 00 00       	mov    ecx,0x1f
  7275dc:	f7 f1                	div    ecx
  7275de:	85 d2                	test   edx,edx
  7275e0:	75 7b                	jne    0x72765d
  7275e2:	8b d3                	mov    edx,ebx
  7275e4:	80 e2 0f             	and    dl,0xf
  7275e7:	80 fa 08             	cmp    dl,0x8
  7275ea:	74 12                	je     0x7275fe
  7275ec:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7275ef:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  7275f2:	c7 40 18 fc 49 c4 00 	mov    DWORD PTR [eax+0x18],0xc449fc
  7275f9:	e9 43 11 00 00       	jmp    0x728741
  7275fe:	c1 eb 04             	shr    ebx,0x4
  727601:	8b cb                	mov    ecx,ebx
  727603:	83 e1 0f             	and    ecx,0xf
  727606:	83 c1 08             	add    ecx,0x8
  727609:	83 ee 04             	sub    esi,0x4
  72760c:	3b 4f 24             	cmp    ecx,DWORD PTR [edi+0x24]
  72760f:	76 12                	jbe    0x727623
  727611:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  727614:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  727617:	c7 41 18 18 4a c4 00 	mov    DWORD PTR [ecx+0x18],0xc44a18
  72761e:	e9 1e 11 00 00       	jmp    0x728741
  727623:	ba 01 00 00 00       	mov    edx,0x1
  727628:	d3 e2                	shl    edx,cl
  72762a:	6a 00                	push   0x0
  72762c:	33 c0                	xor    eax,eax
  72762e:	33 c9                	xor    ecx,ecx
  727630:	89 57 14             	mov    DWORD PTR [edi+0x14],edx
  727633:	e8 38 3a 00 00       	call   0x72b070
  727638:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  72763b:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  72763e:	c1 eb 08             	shr    ebx,0x8
  727641:	f7 d3                	not    ebx
  727643:	83 e3 02             	and    ebx,0x2
  727646:	83 cb 09             	or     ebx,0x9
  727649:	89 47 18             	mov    DWORD PTR [edi+0x18],eax
  72764c:	89 41 30             	mov    DWORD PTR [ecx+0x30],eax
  72764f:	89 1f                	mov    DWORD PTR [edi],ebx
  727651:	83 c4 04             	add    esp,0x4
  727654:	33 db                	xor    ebx,ebx
  727656:	33 f6                	xor    esi,esi
  727658:	e9 ea 10 00 00       	jmp    0x728747
  72765d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  727660:	c7 42 18 e4 49 c4 00 	mov    DWORD PTR [edx+0x18],0xc449e4
  727667:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  72766a:	e9 d2 10 00 00       	jmp    0x728741
  72766f:	83 fe 10             	cmp    esi,0x10
  727672:	73 22                	jae    0x727696
  727674:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  727678:	0f 84 23 11 00 00    	je     0x7287a1
  72767e:	0f b6 02             	movzx  eax,BYTE PTR [edx]
  727681:	ff 4d fc             	dec    DWORD PTR [ebp-0x4]
  727684:	8b ce                	mov    ecx,esi
  727686:	d3 e0                	shl    eax,cl
  727688:	42                   	inc    edx
  727689:	83 c6 08             	add    esi,0x8
  72768c:	89 55 f8             	mov    DWORD PTR [ebp-0x8],edx
  72768f:	03 d8                	add    ebx,eax
  727691:	83 fe 10             	cmp    esi,0x10
  727694:	72 de                	jb     0x727674
  727696:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  727699:	80 fb 08             	cmp    bl,0x8
  72769c:	74 0f                	je     0x7276ad
  72769e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7276a1:	c7 41 18 fc 49 c4 00 	mov    DWORD PTR [ecx+0x18],0xc449fc
  7276a8:	e9 94 10 00 00       	jmp    0x728741
  7276ad:	f7 c3 00 e0 00 00    	test   ebx,0xe000
  7276b3:	74 0f                	je     0x7276c4
  7276b5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7276b8:	c7 40 18 2c 4a c4 00 	mov    DWORD PTR [eax+0x18],0xc44a2c
  7276bf:	e9 7d 10 00 00       	jmp    0x728741
  7276c4:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  7276c7:	85 c0                	test   eax,eax
  7276c9:	74 0a                	je     0x7276d5
  7276cb:	8b cb                	mov    ecx,ebx
  7276cd:	c1 e9 08             	shr    ecx,0x8
  7276d0:	83 e1 01             	and    ecx,0x1
  7276d3:	89 08                	mov    DWORD PTR [eax],ecx
  7276d5:	f7 47 10 00 02 00 00 	test   DWORD PTR [edi+0x10],0x200
  7276dc:	74 1f                	je     0x7276fd
  7276de:	8b 47 18             	mov    eax,DWORD PTR [edi+0x18]
  7276e1:	88 5d ec             	mov    BYTE PTR [ebp-0x14],bl
  7276e4:	c1 eb 08             	shr    ebx,0x8
  7276e7:	6a 02                	push   0x2
  7276e9:	8d 4d ec             	lea    ecx,[ebp-0x14]
  7276ec:	88 5d ed             	mov    BYTE PTR [ebp-0x13],bl
  7276ef:	e8 0c 40 00 00       	call   0x72b700
  7276f4:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  7276f7:	83 c4 04             	add    esp,0x4
  7276fa:	89 47 18             	mov    DWORD PTR [edi+0x18],eax
  7276fd:	33 db                	xor    ebx,ebx
  7276ff:	33 f6                	xor    esi,esi
  727701:	c7 07 02 00 00 00    	mov    DWORD PTR [edi],0x2
  727707:	eb 07                	jmp    0x727710
  727709:	83 fe 20             	cmp    esi,0x20
  72770c:	73 24                	jae    0x727732
  72770e:	8b ff                	mov    edi,edi
  727710:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  727714:	0f 84 87 10 00 00    	je     0x7287a1
```

### A.4 `0x806CF0` IOCP recv completion → parser → next recv

和既有 T02 Socket 有界邊界接合；顯示 parser return 1/0 的不同追蹤。

```asm
00806cf0 <.data+0x405cf0>:
  806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
  806d9e:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  806da1:	3b d6                	cmp    edx,esi
  806da3:	75 1b                	jne    0x806dc0
  806da5:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806da8:	3b fe                	cmp    edi,esi
  806daa:	74 84                	je     0x806d30
  806dac:	68 04 17 c5 00       	push   0xc51704
  806db1:	6a 02                	push   0x2
  806db3:	e8 48 96 ee ff       	call   0x6f0400
  806db8:	83 c4 08             	add    esp,0x8
  806dbb:	e9 70 ff ff ff       	jmp    0x806d30
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7 80 a8 a0 00 00 01 	mov    DWORD PTR [eax+0xa0a8],0x1
  806f26:	00 00 00 
  806f29:	e9 02 fe ff ff       	jmp    0x806d30
  806f2e:	8b 5b 58             	mov    ebx,DWORD PTR [ebx+0x58]
  806f31:	3b de                	cmp    ebx,esi
  806f33:	74 10                	je     0x806f45
  806f35:	68 f4 16 c5 00       	push   0xc516f4
  806f3a:	56                   	push   esi
  806f3b:	8b fb                	mov    edi,ebx
  806f3d:	e8 be 94 ee ff       	call   0x6f0400
  806f42:	83 c4 08             	add    esp,0x8
  806f45:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  806f48:	5f                   	pop    edi
  806f49:	5e                   	pop    esi
  806f4a:	33 cd                	xor    ecx,ebp
  806f4c:	5b                   	pop    ebx
  806f4d:	e8 af a0 08 00       	call   0x891001
  806f52:	8b e5                	mov    esp,ebp
  806f54:	5d                   	pop    ebp
  806f55:	c3                   	ret
  806f56:	cc                   	int3
  806f57:	cc                   	int3
  806f58:	cc                   	int3
  806f59:	cc                   	int3
  806f5a:	cc                   	int3
  806f5b:	cc                   	int3
  806f5c:	cc                   	int3
  806f5d:	cc                   	int3
  806f5e:	cc                   	int3
  806f5f:	cc                   	int3
  806f60:	55                   	push   ebp
  806f61:	8b ec                	mov    ebp,esp
  806f63:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f66:	8b 08                	mov    ecx,DWORD PTR [eax]
  806f68:	6a 01                	push   0x1
  806f6a:	51                   	push   ecx
  806f6b:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806f71:	5d                   	pop    ebp
  806f72:	c2 04 00             	ret    0x4
  806f75:	cc                   	int3
  806f76:	cc                   	int3
  806f77:	cc                   	int3
  806f78:	cc                   	int3
  806f79:	cc                   	int3
  806f7a:	cc                   	int3
  806f7b:	cc                   	int3
  806f7c:	cc                   	int3
  806f7d:	cc                   	int3
  806f7e:	cc                   	int3
  806f7f:	cc                   	int3
  806f80:	55                   	push   ebp
  806f81:	8b ec                	mov    ebp,esp
  806f83:	51                   	push   ecx
  806f84:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f87:	56                   	push   esi
  806f88:	8b f1                	mov    esi,ecx
  806f8a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  806f8d:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  806f90:	51                   	push   ecx
  806f91:	8d 4e 18             	lea    ecx,[esi+0x18]
  806f94:	8d 45 fc             	lea    eax,[ebp-0x4]
  806f97:	e8 24 c9 03 00       	call   0x8438c0
  806f9c:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  806f9f:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  806fa2:	5e                   	pop    esi
  806fa3:	74 12                	je     0x806fb7
  806fa5:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  806fa8:	85 c0                	test   eax,eax
  806faa:	74 0b                	je     0x806fb7
  806fac:	8b 10                	mov    edx,DWORD PTR [eax]
  806fae:	6a 01                	push   0x1
  806fb0:	52                   	push   edx
  806fb1:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806fb7:	8b e5                	mov    esp,ebp
  806fb9:	5d                   	pop    ebp
  806fba:	c2 08 00             	ret    0x8
  806fbd:	cc                   	int3
  806fbe:	cc                   	int3
  806fbf:	cc                   	int3
  806fc0:	55                   	push   ebp
  806fc1:	8b ec                	mov    ebp,esp
  806fc3:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806fca:	75 15                	jne    0x806fe1
  806fcc:	83 3d 5c a8    	cmp    DWORD PTR ds:0xfba85c,0x0
```

### A.5 `0x8075B0` 取得 node / `0x8076F0` 歸還 pool

包含初次 node allocation 0x100C、+4 長度初始化、+0x3C pool queue、+0x54 active counter。

```asm
008075b0 <.data+0x4065b0>:
  8075b0:	55                   	push   ebp
  8075b1:	8b ec                	mov    ebp,esp
  8075b3:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  8075b6:	83 ec 10             	sub    esp,0x10
  8075b9:	53                   	push   ebx
  8075ba:	56                   	push   esi
  8075bb:	50                   	push   eax
  8075bc:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8075c2:	83 7f 4c 00          	cmp    DWORD PTR [edi+0x4c],0x0
  8075c6:	0f 85 8e 00 00 00    	jne    0x80765a
  8075cc:	33 db                	xor    ebx,ebx
  8075ce:	8b ff                	mov    edi,edi
  8075d0:	68 0c 10 00 00       	push   0x100c
  8075d5:	e8 8e 9c 08 00       	call   0x891268
  8075da:	8b f0                	mov    esi,eax
  8075dc:	33 c0                	xor    eax,eax
  8075de:	83 c4 04             	add    esp,0x4
  8075e1:	3b f0                	cmp    esi,eax
  8075e3:	74 1f                	je     0x807604
  8075e5:	68 00 10 00 00       	push   0x1000
  8075ea:	50                   	push   eax
  8075eb:	8d 4e 08             	lea    ecx,[esi+0x8]
  8075ee:	51                   	push   ecx
  8075ef:	89 06                	mov    DWORD PTR [esi],eax
  8075f1:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  8075f4:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8075fa:	e8 61 72 09 00       	call   0x89e860
  8075ff:	83 c4 0c             	add    esp,0xc
  807602:	eb 02                	jmp    0x807606
  807604:	33 f6                	xor    esi,esi
  807606:	8b 47 2c             	mov    eax,DWORD PTR [edi+0x2c]
  807609:	8d 50 01             	lea    edx,[eax+0x1]
  80760c:	89 57 2c             	mov    DWORD PTR [edi+0x2c],edx
  80760f:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  807615:	8d 45 fc             	lea    eax,[ebp-0x4]
  807618:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  80761b:	50                   	push   eax
  80761c:	8d 77 3c             	lea    esi,[edi+0x3c]
  80761f:	e8 3c cc ff ff       	call   0x804260
  807624:	8b 77 30             	mov    esi,DWORD PTR [edi+0x30]
  807627:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  80762a:	8d 4d fc             	lea    ecx,[ebp-0x4]
  80762d:	51                   	push   ecx
  80762e:	52                   	push   edx
  80762f:	56                   	push   esi
  807630:	e8 cb 60 f4 ff       	call   0x74d700
  807635:	8b 4f 34             	mov    ecx,DWORD PTR [edi+0x34]
  807638:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  80763d:	2b d1                	sub    edx,ecx
  80763f:	83 fa 01             	cmp    edx,0x1
  807642:	72 2b                	jb     0x80766f
  807644:	41                   	inc    ecx
  807645:	89 4f 34             	mov    DWORD PTR [edi+0x34],ecx
  807648:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  80764b:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  80764e:	43                   	inc    ebx
  80764f:	89 01                	mov    DWORD PTR [ecx],eax
  807651:	83 fb 32             	cmp    ebx,0x32
  807654:	0f 8c 76 ff ff ff    	jl     0x8075d0
  80765a:	8d 45 f0             	lea    eax,[ebp-0x10]
  80765d:	8d 4f 3c             	lea    ecx,[edi+0x3c]
  807660:	e8 ab ab d3 ff       	call   0x542210
  807665:	8b 08                	mov    ecx,DWORD PTR [eax]
  807667:	85 c9                	test   ecx,ecx
  807669:	75 0e                	jne    0x807679
  80766b:	33 d2                	xor    edx,edx
  80766d:	eb 0c                	jmp    0x80767b
  80766f:	68 34 20 bf 00       	push   0xbf2034
  807674:	e8 b7 64 07 00       	call   0x87db30
  807679:	8b 11                	mov    edx,DWORD PTR [ecx]
  80767b:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  80767e:	8b c1                	mov    eax,ecx
  807680:	83 e1 03             	and    ecx,0x3
  807683:	8b d9                	mov    ebx,ecx
  807685:	8b 4a 08             	mov    ecx,DWORD PTR [edx+0x8]
  807688:	c1 e8 02             	shr    eax,0x2
  80768b:	3b c8                	cmp    ecx,eax
  80768d:	77 02                	ja     0x807691
  80768f:	2b c1                	sub    eax,ecx
  807691:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  807694:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  807697:	8b 1c 98             	mov    ebx,DWORD PTR [eax+ebx*4]
  80769a:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  80769d:	85 c0                	test   eax,eax
  80769f:	74 23                	je     0x8076c4
  8076a1:	8b 57 44             	mov    edx,DWORD PTR [edi+0x44]
  8076a4:	ff 47 48             	inc    DWORD PTR [edi+0x48]
  8076a7:	03 d2                	add    edx,edx
  8076a9:	03 d2                	add    edx,edx
  8076ab:	3b 57 48             	cmp    edx,DWORD PTR [edi+0x48]
  8076ae:	77 07                	ja     0x8076b7
  8076b0:	c7 47 48 00 00 00 00 	mov    DWORD PTR [edi+0x48],0x0
  8076b7:	48                   	dec    eax
  8076b8:	89 47 4c             	mov    DWORD PTR [edi+0x4c],eax
  8076bb:	75 07                	jne    0x8076c4
  8076bd:	c7 47 48 00 00 00 00 	mov    DWORD PTR [edi+0x48],0x0
  8076c4:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  8076c7:	ff 47 54             	inc    DWORD PTR [edi+0x54]
  8076ca:	50                   	push   eax
  8076cb:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8076d1:	5e                   	pop    esi
  8076d2:	c7 03 00 00 00 00    	mov    DWORD PTR [ebx],0x0
  8076d8:	c7 43 04 00 00 00 00 	mov    DWORD PTR [ebx+0x4],0x0
  8076df:	8b c3                	mov    eax,ebx
  8076e1:	5b                   	pop    ebx
  8076e2:	8b e5                	mov    esp,ebp
  8076e4:	5d                   	pop    ebp
  8076e5:	c3                   	ret
  8076e6:	cc                   	int3
  8076e7:	cc                   	int3
  8076e8:	cc                   	int3
  8076e9:	cc                   	int3
  8076ea:	cc                   	int3
  8076eb:	cc                   	int3
  8076ec:	cc                   	int3
  8076ed:	cc                   	int3
  8076ee:	cc                   	int3
  8076ef:	cc                   	int3
  8076f0:	55                   	push   ebp
  8076f1:	8b ec                	mov    ebp,esp
  8076f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8076f6:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  8076fc:	c7 40 04 00 00 00 00 	mov    DWORD PTR [eax+0x4],0x0
  807703:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  807706:	56                   	push   esi
  807707:	50                   	push   eax
  807708:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80770e:	8d 4d 08             	lea    ecx,[ebp+0x8]
  807711:	51                   	push   ecx
  807712:	8d 77 3c             	lea    esi,[edi+0x3c]
  807715:	e8 46 cb ff ff       	call   0x804260
  80771a:	8b 57 58             	mov    edx,DWORD PTR [edi+0x58]
  80771d:	ff 4f 54             	dec    DWORD PTR [edi+0x54]
  807720:	52                   	push   edx
  807721:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807727:	5e                   	pop    esi
  807728:	5d                   	pop    ebp
  807729:	c2 04 00             	ret    0x4
  80772c:	cc                   	int3
  80772d:	cc                   	int3
  80772e:	cc                   	int3
  80772f:	cc                   	int3
```

### A.6 `0x807E50` packet payload copy（native）

```asm
807e50: 55                    push ebp
807e51: 8b ec                 mov ebp,esp
807e53: 81 fe 00 10 00 00     cmp esi,0x1000
807e59: 76 06                 jbe 0x807e61
807e5b: 32 c0                 xor al,al
807e5d: 5d                    pop ebp
807e5e: c2 04 00              ret 0x4
807e61: 8b 45 08              mov eax,DWORD PTR [ebp+0x8]
807e64: 56                    push esi
807e65: 50                    push eax
807e66: 8d 4f 08              lea ecx,[edi+0x8]
807e69: 51                    push ecx
807e6a: e8 61 5d 09 00        call 0x89dbd0
807e6f: 83 c4 0c              add esp,0xc
807e72: 89 77 04              mov DWORD PTR [edi+0x4],esi
807e75: b0 01                 mov al,0x1
807e77: 5d                    pop ebp
807e78: c2 04 00              ret 0x4
```

### A.7 `0x728940` inflate cleanup return value（native）

```asm
728940: test esi,esi
728942: je 0x72897d
728944: mov eax,DWORD PTR [esi+0x1c]
728947: test eax,eax
728949: je 0x72897d
72894b: mov ecx,DWORD PTR [esi+0x24]
72894e: test ecx,ecx
728950: je 0x72897d
728952: mov eax,DWORD PTR [eax+0x34]
728957: je 0x728963
728959: push eax
72895a: mov eax,DWORD PTR [esi+0x28]
72895d: push eax
72895e: call ecx
728963: mov ecx,DWORD PTR [esi+0x1c]
728966: mov edx,DWORD PTR [esi+0x28]
728969: mov eax,DWORD PTR [esi+0x24]
72896c: push ecx
72896d: push edx
72896e: call eax
728973: mov DWORD PTR [esi+0x1c],0
72897a: xor eax,eax
72897c: ret
72897d: mov eax,0xfffffffe
728982: ret
```

