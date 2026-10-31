# E82 — KR RR-0001：初始 key0 57-byte request 的逐欄位原生來源、排程與 Server 相容交接

> 2026-11-01 (Asia/Taipei)｜KR T02 / chatgpt-web roy｜RR-0001 正式認領分支 `rr/t02/roy/rr-0001`。基準 `main=b34afcb6386d391032bff2ac31fafbe4915ddc85`；該分支原本是 main 祖先，先行非強制 fast-forward 同步 main，未建立新分支。本稿補強既有 E57/T01 有界驗證，不修改原稿與 S00 RR 台帳。**Client static evidence**，不是 Client runtime、真實 wire capture 或原版 Server 內部時序。

## 1. 研究終點與來源身分

正式 `research/requests/index.json`：RR-0001 = **IN_REVIEW**，`owner_task=T02`、`GAP-NET-0001`；問題是已知 `0x8068B0 WSASend`、`0x806CF0 WSARecv/IOCP`、`0x4930E0` 分派之後，釐清 first outgoing/incoming frame、`Conn+A02C` switch 與 connection-specific 初始順序，**不可重做已知函式發現**。E57 原稿已於 main 的 `kr-extra-roy/20261030-103206-chatgpt-web-roy-E57-RR0001-KR-first-frame-0BBB-1A68-mode-sequencing-static-contract.md`（Git blob `a379f776b9a1d7566de539daa7153f33b9b91e36`），並已受 T01 `research/handoffs/t01-20261030-rr0001-rr0004-bounded-r2/README.md` 的 R0/R1/有界 R2 核對。E58（RR-0004）已另追 `A02C` aliases 與 fallback，不在此假稱重驗整個 T02。

原件：`Tartaros.bin` 大小 **12,472,320**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。PE32 x86 ImageBase=0x400000，`.text` VA0x401000、raw0x400、**raw size=0x7D0200**；程式碼此區 `fileOffset = VA−0x400C00`，其它 section 必須依 PE section table；唯讀原始機器碼 + GNU objdump。該映射也修訂 E57 部分段落記載 `.text raw 0x7D01F0` 的描述，不能將 raw size 與 virtual size/末端候選誤混。E57 第8節 `{', '.join(...) }` 一類未展開模板不能引用為完整 xref 清單；T01 已對主要有限 xref 從原件重算，本稿明確勘誤但保留舊 Git blob 不覆寫。

## 2. 首個 key0 request（在**該條可達 Client local path**）的 57B 欄位全圖

先決條件 `0x4957C0`：manager virtual+0x18 先以 (endpoint, 8416, key0, lane2) Connect，於 `0x4957EA` 呼叫；然後以 (同 endpoint, 8414, key2, lane2) Connect，於 `0x495803` 呼叫。任一返回 NULL 進不同錯誤/shutdown 路徑，不應宣稱 key0 request 一定送出。成功時 `0x495872 push 0x190` → `0x495877 call [IAT]`（既有 Sleep import 解析可交 T01），**其後** `0x49587F..0x49593D` 組第一筆本地 key0 應用 payload，manager virtual+0x10(queue slot0, ptr, len0x39)。這是 **queue 的 CPU 呼叫次序**，不是 WSASend、TCP 對端到達或不同 Conn 全域先後。

此函式令 `P = EBP−0x40`，所有偏移皆相對 **內層 application payload P**，而非外層 TCP frame。完整 57 bytes 每一位元組有在該路徑上的明確寫入／初始化來源：

| P offset | size | source-level native fact | 重要限界 |
| --- | ---: | --- | --- |
| +0 | 2 | `0x49587F mov ecx,1; 0x495884 mov word [ebp−0x40],cx` | decoded C2S **0x0001**，不是 outer marker |
| +2 | 4 | `0x4958B3 call 0x404BA0; 0x4958B8 read [eax+0x67E0]; 0x4958BE store [ebp−0x3E]` | 來源是 **0x404BA0 返回的物件+0x67E0**；業務語意 UNKNOWN，不可稱 ticket/key |
| +6 | 20 | `0x4958C1 call 0x404BA0; +0x67E4` → `0x893FFE` 以 **10 WCHAR** capacity/copy count 寫到 `[ebp−0x3A]` | UTF-16LE 10 WCHAR 容量；最長安全有效名稱需考慮 NUL，不能當作 10 個字一定可送 |
| +26 | 1 | `0x4958F1 mov byte [ebp−0x26],1` | 固定 Byte=1；函式先存 WORD 1，後 Byte+27 被覆寫，故不能把 +26..27 當不變 WORD 1 |
| +27 | 1 | `0x4958F5 call 0x404BA0; 0x4958FA read [eax+0x6898]` → `0x495900 [ebp−0x25]` | 原生 BYTE，業務 UNKNOWN |
| +28 | 5 | `0x495903 call 0x404BA0; 0x495908 add eax,0x6899` → `0x893B59` 以容量 **5 bytes** copy 至 `[ebp−0x24]` | narrow bytes，不與 UTF16 欄位混淆；字元 encoding 未由 helper 自身指定 |
| +33 | 4 | `0x49591C call 0x404BA0; 0x495921 read [eax+0x68A0]` → `0x495927 store [ebp−0x1F]` | DWORD，語意 UNKNOWN |
| +37 | 20 | `0x4958A4..0x4958B0` 等處把 DWORD [ebp−0x1B], −0x17, −0x13, −0xF, −0xB 逐一初始化零 | 在此 construction branch 固定零；不可擴展到其它 Client producer |

精確來源例：
```asm
4957E0 push 2       ; lane2
4957E2 push 0       ; Conn map key0
4957E4 push 0x20E0  ; port 8416
4957EA call edx     ; Connect via manager
4957F2 push 2; push 2; 4957FD push 0x20DE ; key2 port8414
495803 call edx
495807 test edi,edi ; 49580F test ebx,ebx ; either NULL -> failure, no 57B enqueue
495872 push 0x190; 495877 call [0xBD2304] ; Sleep import path
495884 mov word [ebp−0x40],cx             ; opcode 0x0001
4958B8 mov edx,[eax+0x67E0]; 4958BE mov [ebp−0x3E],edx
4958C6 push 0xA; 4958C8 add eax,0x67E4
4958CE lea eax,[ebp−0x3A]; 4958D1 push 0xA; 4958D4 call 0x893FFE
4958F1 mov byte [ebp−0x26],1
4958FA mov dl,[eax+0x6898]; 495900 mov [ebp−0x25],dl
495908 add eax,0x6899; 495911 push 5; 495914 call 0x893B59
495921 mov ecx,[eax+0x68A0]; 495927 mov [ebp−0x1F],ecx
495935 push 0x39; 495937 lea eax,[ebp−0x40]
49593B push 0; 49593D call edx             ; queue slot0, len57
49594B call edx; 495959 call edx            ; key0/key2 vtable+0x14 receive post
```

**兩個 copy helper 可能失敗，caller 並沒有在 queue 之前以 helper 的 return code 作相應條件阻擋**：`0x893FFE` 中 `0x89407A/7E` 以 WORD 為單位取寫，容量耗盡 `0x8940B7` 清空目的首 WCHAR；`0x893B59` 中 `0x893B90/92` 以 BYTE 取寫，容量耗盡時 `0x893BA1` 清空目的首 BYTE。上游若另有限長，不在這條函式局部可證的完整成功契約內；新 Server 必須驗證長度和格式，不可依賴 Client helper 一定成功。

## 3. 還有**同一建立函式**中的 key1 舊連線清場，不能把它當成新 key0 第一包

`0x495817` 測 `manager+0xBF60` 的**舊 key1 Conn 指標**：若非 NULL，`0x495848 mov WORD[ebp−0x42],0x007E`，`0x495843` 長度2、`0x495853 call 0x8060D0` 對該舊連線本地 enqueue；`0x495839 call 0x8063E0` 與 `0x49585E` 寫 `oldConn+A0B0=1`、`0x495868` 清 owner pointer。此路徑發生於 `Sleep(400)` 與新 key0 的 57B queue **之前**，但**不同 Conn／可能被關閉**，不得推「第一包必為0x7E」。同樣 `0x495610` 的 key1（port8415）有六個直接 caller、不同初始 payload 邊界，已由 E55–E57 說明，不能把三個 socket 併成一條 TCP。

## 4. 排程／frame mode／S2C：靜態契約閉合與不可冒稱的外部條件

正常新建 Conn `0x805D02` 寫 `Conn+A02C=2`；本地 send queue 由 `0x8061A0` 處理，非零優先 `0x807830` encoder，成功 frame header `u16(n),u16(0x0BBB),u16(checksum)`、payload XOR-chain；若 encoder 返回失敗，`0x807A70` 嘗試 `u16(n),u16(0x1A68),raw body`。已被 RR-0004/E58 處理的非直達 alias 和 reuse 保留未知，不重做也不寫成 A02C 永遠2。

若 **P 真的有 57B 且 mode 非零/tx 空間充足/encoder success/後續 send pump 到 WSASend**，0x0BBB outer frame 共 **63B**；若明文 fallback success 則 **61B**。這是條件式大小，不是從原版網路錄製的第一個封包。外層 0x0BBB checksum 為 `sum(P)&0xffff`，取值視 +2/+6/+27/+28/+33 等 runtime 資料而變；**不可因這篇已找到 schema 就硬編 checksum 固定2**。合成零值資料（保留 opcode 0x0001、+26=1）才會 sum=2。

`0x8068B0 WSASend` 的 arg 指標界線：`0x8068DE lea eax,[esi+A050]` 是 **OVERLAPPED**，`0x8068F7 lea ecx,[eax+14h]` 是 **WSABUF at Conn+A064**，而 `Conn+A0B8` 是與完成管理相關的計數欄位，不是 OVERLAPPED 指標。和 T03/T01 退回的同類命名風險隔離。**Manager queue≠framed buffer≠WSASend submitted≠OS completed≠remote received**。

S2C 可接受集合（E57、RR6 鄰接）包括 marker `0x2633,0x0BBB,0x1A68,0x22D7` 的不同 header/解壓/校驗路徑；marker 是由 incoming bytes 判定，與本 Conn 出站 mode A02C 沒有必然同值約束。**Client 靜態資料不能證明原版 Server 的首次來包 marker、是否主動發 greeting 或跨 socket 真正完成的總序**。這不是需要還原原版 Server 內部演算法才能規劃新 Server；只代表 S00 應把選擇作**自訂相容測試假設**並以實際 Client TCP trace 驗證。

## 5. RR 五個驗證面向／交付狀態

| RR-0001 問題 | E57+T01+E82 現有依據 | disposition |
| --- | --- | --- |
| key0/1/2 Conn first producer 和條件 | key0 connect0→2、舊 key1 queue7E 可選、Sleep、key0 first local cmd1 57B 新增完整 layout；key1 六 caller E57 | **Client static bounded CLOSED**，其它路徑仍另證 |
| outgoing frame 的 mode、fallback、完成關係 | 0x0BBB / 0x1A68、A02C=2 fresh constructor、fallback、WSASend submit vs completion | **Client static bounded CLOSED**；所有 runtime alias RR4 |
| inbound marker 消費以及受何者控制 | 807B40 依實際 marker/length；0BBB checksum、2633 decode 分支 | **bounded**；compression error 下游 RR6 |
| actual first S2C marker／跨 socket wire 全域順序 | peer-side 行為非 Client 靜態來源；不假定官方唯一值 | **UNKNOWN**；只接受相容 Server synthetic/real capture 鑑別 |
| 改版新 Server 可採用的固定欄位/測試 | 本篇 57B layout、端口/連線權威、編碼條件、拒絕/短包/跨 Conn 排程測試 | **READY FOR S00 REVIEW**；不能自稱 RR ACCEPTED |

## 6. Server 設計交接及分工

**Client 已證**：新 Server 可依已核範圍實作 slot0 初始 cmd1 parser（長度57）及欄位範圍 guard；同一條 Conn 的 0BBB/1A68 接收框架依 marker 解碼；不同 TCP Conn 獨立維持 frame buffer、payload queue、correlation 和限額，絕不可把 `Conn+A02C=2` 當 inbound marker 強制判斷。**沒有證據允許 Server 使用 P+2／+27／+33 的內容作身份權威或登入通行證。**

**Server 待開發**：決定 startup/handshake/session mapping、來源端口對應、未知欄位驗證寬鬆/嚴格程度和拒絕動作、監控和恢復。對未證 Client 前置條件採 fail-closed/隔離測試，不硬填 Server-First greeting 或原版業務規則。

**Client 待逆向**：其他 key1 初始 sender 的完整 body 由 T02 依既有資料繼續，若有新第一手版本/Runtime 進行更細 mapping；`A02C` 間接 alias 的全域保留 RR-0004；E57+E82 尚不能證明所有 Socket 排程都只有這些 producer，不能用 bounded xref 排除 indirect callbacks。

**跨功能待整合**：S00 `SPEC-NET-0001` / `SPEC-NET-0002` / `SPEC-FLOW-0001`、`GAP-NET-0001`、`TEST-NET-0001/0002`，C04-E1 frame decoder/first gateway（Iteration39）；T02 RR4/6/7，T03 RR3、S00 review。建議正式新增 *TEST 候選*（非現有正式 ID）：KEY0-INITIAL-57-LAYOUT、KEY0-STRING-OVERFLOW、OLD-KEY1-7E-CLOSE-RACE、DUAL-CONN-CONNECT-ONE-FAIL、FRAMING-MARKER-INDEPENDENCE、CONN-QUEUE-VS-WSASEND。由 S00 去重後登錄。

**待遊玩驗證**：在原版 Client 和隔離的新 Server 測 startup first inbound frame、E8/0F login 和 key0 57B cmd1 的 runtime 順序、session/correlation 和 UI：以 *synthetic compatibility* 標註，不把新 Server 設計上升成已還原原版 Server 歷史資料。

## 7. 重現與原稿修訂歷史

驗證器 `kr-extra-roy/20261101-chatgpt-web-roy-E82-RR0001-verify.py` 執行
```bash
python -B kr-extra-roy/20261101-chatgpt-web-roy-E82-RR0001-verify.py Tartaros.bin
```
本輪 **74 項**原始 BIN bytes/call/PE/scope 與有明確標記的合成 frame tests PASS。這是**bytes-level asserts**，非 T01 全函式語意 FULL-PASS、Client runtime 或 Server 對端完成。原稿 E57 blob、T01 bounded R2、E58 與主線狀態保留；只有 S00 能依原 RR 成果標 `ACCEPTED`，研究者在已 `IN_REVIEW` 時不逆向變回 `SUBMITTED` 或改台帳。
