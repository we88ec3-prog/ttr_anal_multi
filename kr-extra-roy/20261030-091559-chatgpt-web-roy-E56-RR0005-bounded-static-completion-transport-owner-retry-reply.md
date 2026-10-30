# E56 — RR-0005／KR T02：目標導向靜態審查交付，選服／三 Conn／首包／關閉、重連／初始回覆的有界契約

> **重要分界**：本文為 **Client 靜態證據已能交付的 bounded research report**；`SUBMITTED` 僅表示請 S00/T01 審查，不表示 S00 `ACCEPTED`、T01 `FULL-PASS`、原版 Server 已重建或 Runtime 已驗證。對無法從 Client 靜態證明的情境明確保留 U；不以新發現、固定子段數或寫完 Markdown 作為停止理由。

- 調查日期：2026-10-30，Asia/Taipei；研究者 `chatgpt-web roy`。文件名稱時間使用實際檔案建立時間。
- 原始檔：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**全程唯讀，未執行 Client／未連原版 Server。**
- PE mapping：`.text` RVA/VA `0x401000`、raw `0x400`、size `0x7D01F0`；`.rdata` VA `0xBD2000`、raw `0x7D0600`。本稿附錄用原始 `.text` 切片（從正確已知入口）獨立 GNU objdump 反組譯。raw = `VA - 0x400C00` （只限此 `.text`）；非函式入口的指令片段若無分支邊界，僅作旁證。
- Task：KR T02，封包／連線角色／分派；不越權聲稱 T03 UI 業務、Server DB 或官方機器的原始實作。RR-0005／GAP-NET-0002。
- 本次 Git 讀取時 `main=9880a74f44b2b1b692d8e97c82b3d26ccc2c71d4`、`extra/roy1=08acd4a84d3476daa4456cd11d5a529abe91263f`，RR-0005 `ACTIVE/IN_PROGRESS`；下列 SHA 不可誤作後續提交結果。

## 一、正式問題和研究終點（完整，不縮題）

RR-0005 `question`：Join T03 `0x13` response and choice UI with KR `0x495610/0x4957C0` Connect call sites; derive actual conditions/order, close/retry/slot ownership and initial frame per connection. Separate legacy static port values from server deployment recommendations.

RR-0005 acceptance：Bound actual KR Client Connect/close/port roles and `0x13` login-to-choice handoff sequence including first sender/response, error/retry behavior, without inventing endpoint authority.

本報告分別回答 **S2C list→UI→Connect、key1 與 key0/key2 角色和失敗／重試範圍、socket／Conn／map 的不同所有權、首包 local producer→send pump、回覆可達處理器以及不可由 Client 判斷的 server-first response、舊 port constants**。只做靜態 Client 範圍的正反雙向結論。**特別不要求「每次網路 session 必然同樣排序」、「所有已失效 Conn 必然立刻釋放」或「原版 Server 官方 IP」等超出原件的全稱事實。**

## 二、已保存原稿、可追溯 blob 與跨段複查

| 來源 | 已核對 Git blob／來源 | 本報告使用的有界範圍 |
|---|---|---|
| E44 | `3b3aa88bcb7de51440a31b8798121b2aa53a43f3` | 0x13／0x7A 第二級 callback→0x4C3080→FE1B54→UI |
| E45 | `0ff5b0d86ddac2a6b75e8922a48cd3cd2f02a9a9` | 四 octets→`%d.%d.%d.%d` → 0x60-byte record+0x0C 的文字 endpoint |
| E50 | `f4bd62ce69cf96cc35b566bf62721a586f4f51c7` | Map replacement、Pool+0x48 兩條 producer |
| E51 | `356d4659d8069c42f05492002b00476a778171bb` | Manager vtable、WSASend/WSARecv、A0B8 的 SEND accounting |
| E52 | `6fb5baab06fc9d564ed296742d092973b7bf1779` | queue drain ≠ closesocket、fresh/reuse throttle gate |
| E53 | `659e26be843cb29e6fdfc1f14246fb8357c1aca9` | Pool+0x28→+0x48 與 Client virtual tick |
| E54 | `d0e4153c4998132cb231c964c88255b95dda2141` | 0x0001 local send→send pump→framing→queue→UI callback |
| E55 | `a9594a1933472f1f42e2618b07682e26b98435cd` | 六 key1 caller、slot、fail、first-candidate matrix |

以上是原稿識別及局部證據重用，**不是**這些報告已通過 T01 FULL-PASS。

## 三、首尾功能鏈：輸入與輸出之間的正確方向

```
[前一階段 S2C 包含 WORD 0x0013（mode0 且字串／列表合法）或 0x007A]
  WSARecv + GQCS -> 0x807B40 decode/frame -> FC10D0 app queue
  -> 0x804740 mainloop virtual 0x4930E0 -> 0x4C4670 secondary dispatch
  -> 0x4C37A0 / 0x4C3C10 -> 0x4C3080 group list -> FE1B54
  -> 0x66B910/0x66C620 selection UI -> 0x66C090
  -> record+0x0C = inbound octets 製成的 dotted IPv4 ASCII
  -> 0x4957C0 -> key0:port 0x20E0、key2:port 0x20DE
  -> 兩者均非 NULL 才排 key0 的 0x39 bytes、post recv、寫 BF64/BF68
  -> 0x8069A0 / 0x8060D0 pending queue -> 0x804A40 / 0x8061A0 -> 0x8068B0 WSASend
  -> recv IOCP / frame/handler（*沒有證據保證選服後第一個 S2C 就是 0x0013*）

[其他 key1 caller]
  0x6D6377/6424/6508/65C8/670C/696C -> 0x495610
  -> key1:port 0x20DF lane2，第三參數為1時還先 shutdown key0/key2
  -> 部分上游只有 callback，另有 0x38/0x68/0x2CE bytes local candidate
  -> 回覆可由同一 IOCP/frame 機制接收，但不因此知道相應 session 第一個 S2C
```

這個方向不能倒轉：`0x0013/0x007A` 是**取得選服資料**所需的前置 inbound 候選，不能推論為**選服後** key0 initial 0x0001 的確認回覆。0x70A/0x578 是本地 UI event；0x2633/0x0BBB/0x1A68/0x22D7 是 frame markers；以上識別碼不得混用。

## 四、可提交的逐情境 static contract（N／C／U）

| 情境／接受條件 | 來源與已證 (N) 的 code-level outcome | 限定條件或不可證 (C/U) | S00 用途 |
|---|---|---|---|
| 0x0013 登入返回 | 二級 table 0x13→0x4C37A0；mode0 + UTF16 非空 → 0x4C3080；mode5／error 走別支 | 單靠 Client 不能宣稱 Server 每次都選 mode0；最小安全長度不等於 parser 有檢查 | 正常／錯誤回覆分開規格 |
| 0x007A 列表增補 | 二級 table 0x7A→0x4C3C10→0x4C3080 | 不證實一定先/後收到 0x0013 | 可用列表輸入 |
| record→UI→Connect | 10-byte 子記錄四 octets → IPv4 dotted-decimal ASCII → record+0xC → UI lookup，0x66C1A7/247 兩 direct caller | 不是 Client 靜態可知的官方 IP；ui gate 有多個分支 | Host 來源，不猜部署 endpoint |
| key0/key2 Connect | 0x4957C0 先 key0 `0x20E0`，再 key2 `0x20DE`，兩個 lane=2；兩者 Conn* 非0才後續 enqueue/post recv/slot save | 非 NULL 不代表原版 Server 接受連線，也不代表完成 I/O | Connect 本地控制排序 |
| key0 first local candidate | 雙成功後 0x495935 vtable+0x10，長0x39，首 WORD 0x0001 | local queue≠WSASend≠first wire；前置變換與排程可能影響 bytes | 初始相容封包候選 |
| key2 first local candidate | 0x4957C0 **本函式無 key2 直接 send**，但有 key2 post-recv | 不得升級為整個應用 key2 永不 send | 排除錯誤固定初始包 |
| key0 only succeeded | key2 NULL 時 key0 走 vtable+0x20 shutdown by key、回0；沒見本函式 close-by-Conn/retry | 其他 callback 可能再次連，非此函式內的動作 | 失敗/清理有界規格 |
| key2 only succeeded | key0 NULL 時 key2 類似 shutdown、回0 | 不推成全域保證 close 完成 | 同上 |
| key1 helper | 0x495610 使用 `0x20DF`、key1、lane2；第3參數=1 時先 shutdown key0/key2，BF60 非NULL gate 決定是否略過新 connect | 上層 6 direct callers 不等價；也可能存在間接 caller | 必分割場景 |
| key1 local first candidate | 上層 0x6D6508/65C8/670C/696C 成功後可排 0x38/0x68/0x2CE/0x2CE；另外兩支只觸發 callback | 尚未證明哪個在任意 runtime session 真正先送 wire；718 byte 需 builder 證據 | 不應硬編固定 key1 首包 |
| Manager same-key map replace | 0x806C9E 查 map；0x806CB3/0x7B6890 刪**tree node**；0x806CC7/0x806CD2 插入新映射 | **此函式內不保證舊 Conn 被 close**；也不證必然 leak，可能後續其他 owner 清理 | 明確取消「replace = oldConn release」錯誤規格 |
| Close-by-Conn | 0x806FC0 gate A0A8==0 且 socket 有效時 shutdown/closesocket，之後 Pool+28 tracking；0x490FE0 特定狀態推到 Pool+48，0x805B40 A0B8==0 才 reset→free vector | stale Conn 是否會收到 completion/進入該鏈未作所有路徑保證；IOCP 同步競態只可條件解釋 | 需要的 state/owner guard |
| Connect error | 0x806B8C connect 或後續 setsockopt 失敗→0x805AF0 Pool+48；0x805F50/8063E0 reset/queue drain | 在這兩函式可見 CFG **找不到 closesocket**；不可據此認定所有錯誤 socket 被正確關閉，也不直接推斷實際漏 handle 數 | Socket cleanup 風險／負向測試 |
| Initial S2C after new Connect | recv bytes → frame parser → lane queue → callback；0x0013/0x007A **有條件可達** | **沒有原版 Server/same-session capture，不能給出可靠 first-response opcode、bytes 或順序** | Server 設計 ADR/GAP；禁止冒稱原生 |
| legacy static ports | 0x20DE/0x20DF/0x20E0 = 8414/8415/8416 | 原始 Client 硬編值不是新 Server 必須使用的部署決策 | 由 S00 ADR 決定實際配置 |

**可交付成果的性質**：上表是 Client 靜態可驗證的「條件式行為契約」。已完整回答 `question/acceptance_criteria` 在 Client 原件能回答的範圍，包括未知的精確原因；這不構成「所有 runtime 連線時序已證」或「原版 Server first-response 已解析」的全稱主張。由 S00 判斷是否接受此 scope 或提出 NEEDS_REVISION。

## 五、補查／修正：`Client+BF58` 並非已證的 key-slot owner

從已知 Client 建構函式 `0x48AB70` 起，`0x48ACB6/48ACBC/48ACC2` **明確分別清零** `+BF60/+BF64/+BF68`（以及後續欄位），`0x48B0EA` **把另一個配置的 pointer 寫 +BF5C**；可重現 local constructor 搜尋未直接寫 +BF58。另一方面 `0x490FE0` 的 `0x4910C5` 比較 `[arg+BF58] == [Pool+28 node+8]`，若相等額外呼叫 `0x6D6300` 衍生 callback，**Pool+48 轉移在兩個分支後仍繼續**。不能由欄位數字靠近而把 BF58 當作同 key Conn owner，亦不能因 `.text` 直接常量只有一個匹配就斷定全域無間接 writer。

- 陰性掃描：對 `.text` `0x7D01F0` bytes 尋 `58 BF 00 00` 只命中 displacement `0x4910C7`；直接寫入證據仍缺。但 `LEA`／基址調整／結構拷貝／配置後初始化、DLL 等可能繞過 constant encoding。
- **RR slot ownership 已有足夠獨立正證**：BF60（key1）、BF64（key0）、BF68（key2）的 constructor+connect success writer；`BF58` 縱然未知，不阻礙 `806FC0`→Pool28→Pool48 的基本條件式鏈。它是額外別名／callback 範圍，不應用來編造第四個 key。

## 六、same-key old Conn 與 socket handle：不可提升的全稱結論

1. `0x806AD0` 對新 Conn 執行 connect/setsockopt、IOCP bind；在同 key map replacement `0x806C9E..806CD2` **讀／操作的是 map-node/樹迭代器**。已檢查此函式的舊 Conn pointer 沒有被直接送 `0x806FC0`。
2. `0x7B6890` 的 tree-node `0x89120C` deallocate 只證已移除節點，不證 Conn / socket 被 deallocate/closed。**Map ownership 與 socket ownership 分離**。
3. `0x806FC0` 依有效 socket + A0A8 gate 可執行 shutdown、closesocket、Pool28；`0x490FE0` 條件式轉 Pool48，`0x805B40` 待 A0B8 零再 reset。Manager destructor `0x8066A0` 只枚舉 **仍 map reachable** 的 Conn 加入 Pool48，並非證明已被 map 取代的舊 Conn 會被收集。
4. 因此 **no guaranteed synchronous old close** 是真正 Client 靜態規格；至於可能 IOCP completion、其他 Client alias 或 process-exit owner 在何時使它被釋放，不能由此列局部 CFG 得出全稱。必要的動態併發驗證應獨立處理。
5. **connect 失敗清理風險（新增有界提醒）**：`0x806B82 socket`、`0x806B8C connect` 將 SOCKET 寫 `Conn+0`，`0x806BD4/806BFB` 失敗分支只將 Conn 排至 Pool48；`0x805B40` 可進 `0x805F50` 並把 `Conn+0` 設 -1，未在兩個函式內 `closesocket`。這是 static missing-cleanup path 的風險，**不是**實際 Windows handle-leak 數量或必然穩定可重現的證明。若 S00 需安全可玩 Server，應規劃斷線/重連容忍及觀察測試。

## 七、retry 的精確否定範圍、回覆的 source-limit

- `0x4957C0` 的部分成功分支呼叫 shutdown-by-key **並 return 0**，在此函式內未重做 Connect；不能宣稱其他 UI/event 不再嘗試。兩處直接呼叫 `0x66C1A7/0x66C247` 由同一 UI resolver `0x66C090` 分支而來，具再次透過 UI 行為觸發的靜態可能；沒有 runtime 時序，不能命名成 timer retry。
- `0x495610` 六 direct-callsite `0x6D6377/6424/6508/65C8/670C/696C`，第3引數有 0 與 1；不能合併成單一重試 policy。`0x495610` 無成功時也不會在自己函式內 retry；可以由上游事件再次呼叫，但不是已證自動重試。間接 CALL 未被純 E8 搜尋涵蓋。
- IOCP frame decoder 可從合法解碼 payload 以 lane2 到二級 0x13/0x7A handler，但這些 handler 是**取得選服列表的已知入站類型**。每個新 key 首次收到哪個 S2C opcode 由對端在該次 session 發送決定；原始 Client 單獨不包含這個輸入事實。**所以「Server first response：unknown」是由 evidence domain 決定，而非草率停止可靜態追查的 Client callgraph。**
- 發送的 0x39/0x38/0x68/0x2CE 皆須經 queue、send pump、frame transform 與 Winsock；不能以本地長度替代 wire packet 長度、完整 raw payload 或 Winsock 成功完成事實。

## 八、S00／T01 限定審查與交付

| 類別 | 結論或工作項 | 交付方向 |
|---|---|---|
| Client 可證、供 SPEC | 三 key legacy port/lane，selector IPv4 source，0x13/0x7A conditional UI reachability，雙 Connect 成功／單失敗分支、Conn 槽、已知 send producers、frame/dispatcher | `GAP-NET-0002` 對應 draft-compatible contract |
| Client 不可泛化 | 同 key map erase≠socket close，Pool28/48 recycle gate，connect error 缺少局部 closesocket，BF58 alias callback 未證作 key slot | `GAP-NET-0002` 風險／負面 invariant，不寫成保證 |
| Server 待開發 | 適配 `0x0013/0x007A` 的有效資料、選服 endpoint 分配、key0/1/2 不同初始候選的會話狀態，斷線/重連策略 | S00 ADR／SPEC／TEST；不得冒稱官方私有 policy |
| 跨功能待整合 | T03 登入/UI state 的觸發時序與 T02 socket 接收、T01 對證據主張的嚴格複驗 | 以精確 commit/blob 跨 Task 邊界引用 |
| 待實測 | 每個 key 的 first wire bytes、原版 first S2C、winsock interleaving、並發 socket lifetime、場景可玩 | 受控測試／原版封包才可解鎖，**不阻止** Client bounded research 交付 |

**提交判準**：這是一份已回答 RR-0005 所列 Client 靜態操作、分支和邊界的 *bounded analysis*，作者可將它送正式 `SUBMITTED` 供 S00／T01 審查，但無權自行標為 `ACCEPTED` 或共享 FULL-PASS。若 S00 要求「原版首筆 S2C opcode／特定次序必然發生」，應針對 Client-only evidence 不足提出獨立原件依賴或新增 RR，不能由本報告捏造答案。若 S00 對 BF58 或同 key lifetime 全稱要求更嚴，需在 `NEEDS_REVISION` 指明驗收擴展，而不自行抹掉此次有限結論。

## 附錄 A — 可重做的 raw-search 方法及完整條件式指令證據

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
python3 - <<'PYCHECK'
from pathlib import Path
import hashlib
x=Path('Tartaros.bin').read_bytes()
assert hashlib.sha256(x).hexdigest() == '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
Path('kr_text.bin').write_bytes(x[0x400:0x400+0x7D01F0])
print('verified source length:', len(x))
PYCHECK
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x806ad0 --stop-address=0x806cf0 kr_text.bin
```

- `E8 rel32` 掃描只列 direct-call **候選**，必須以正確入口反組譯確認指令；無法排除 vtable、call reg、jump table。
- `0xBF58` disp32 小端模式只限四位元組 `58 BF 00 00`，不能排除 alias writer。PE `.text` 裡只命中位址 `0x4910C7`，從 `0x4910C5` 解碼。
- 各下列片段（含原始 bytes）均從原始 `.text` 切片於已知函式入口或已知 basic-block 過渡處抽取，僅局部片段不推定必然 runtime。

### A.1 Manager::Connect 取得 Conn，Winsock 建連，返回與失敗後 recycle — VA `0x806ad0..0x806cf0`

```asm
Disassembly of section .data:

00806ad0 <.data+0x405ad0>:
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15 c0 25 bd 00    	call   DWORD PTR ds:0xbd25c0
  806b3f:	0f bf 48 0a          	movsx  ecx,WORD PTR [eax+0xa]
  806b43:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  806b46:	8b 02                	mov    eax,DWORD PTR [edx]
  806b48:	51                   	push   ecx
  806b49:	50                   	push   eax
  806b4a:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  806b4e:	51                   	push   ecx
  806b4f:	e8 7c 70 09 00       	call   0x89dbd0
  806b54:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  806b57:	83 c4 0c             	add    esp,0xc
  806b5a:	ba 02 00 00 00       	mov    edx,0x2
  806b5f:	50                   	push   eax
  806b60:	66 89 54 24 20       	mov    WORD PTR [esp+0x20],dx
  806b65:	ff 15 a8 25 bd 00    	call   DWORD PTR ds:0xbd25a8
  806b6b:	6a 01                	push   0x1
  806b6d:	6a 00                	push   0x0
  806b6f:	6a 00                	push   0x0
  806b71:	6a 00                	push   0x0
  806b73:	6a 01                	push   0x1
  806b75:	6a 02                	push   0x2
  806b77:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  806b7c:	ff 15 d0 25 bd 00    	call   DWORD PTR ds:0xbd25d0
  806b82:	6a 10                	push   0x10
  806b84:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  806b88:	51                   	push   ecx
  806b89:	50                   	push   eax
  806b8a:	89 03                	mov    DWORD PTR [ebx],eax
  806b8c:	ff 15 c4 25 bd 00    	call   DWORD PTR ds:0xbd25c4
  806b92:	83 f8 ff             	cmp    eax,0xffffffff
  806b95:	75 7f                	jne    0x806c16
  806b97:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806b9b:	74 19                	je     0x806bb6
  806b9d:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806ba3:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806ba6:	50                   	push   eax
  806ba7:	68 ac 16 c5 00       	push   0xc516ac
  806bac:	6a 02                	push   0x2
  806bae:	e8 4d 98 ee ff       	call   0x6f0400
  806bb3:	83 c4 0c             	add    esp,0xc
  806bb6:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806bbd:	75 35                	jne    0x806bf4
  806bbf:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806bc6:	74 27                	je     0x806bef
  806bc8:	e8 93 43 c9 ff       	call   0x49af60
  806bcd:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bd3:	53                   	push   ebx
  806bd4:	e8 17 ef ff ff       	call   0x805af0
  806bd9:	33 c0                	xor    eax,eax
  806bdb:	5f                   	pop    edi
  806bdc:	5e                   	pop    esi
  806bdd:	5b                   	pop    ebx
  806bde:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806be2:	33 cc                	xor    ecx,esp
  806be4:	e8 18 a4 08 00       	call   0x891001
  806be9:	8b e5                	mov    esp,ebp
  806beb:	5d                   	pop    ebp
  806bec:	c2 10 00             	ret    0x10
  806bef:	e8 0c 44 c9 ff       	call   0x49b000
  806bf4:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bfa:	53                   	push   ebx
  806bfb:	e8 f0 ee ff ff       	call   0x805af0
  806c00:	33 c0                	xor    eax,eax
  806c02:	5f                   	pop    edi
  806c03:	5e                   	pop    esi
  806c04:	5b                   	pop    ebx
  806c05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806c09:	33 cc                	xor    ecx,esp
  806c0b:	e8 f1 a3 08 00       	call   0x891001
  806c10:	8b e5                	mov    esp,ebp
  806c12:	5d                   	pop    ebp
  806c13:	c2 10 00             	ret    0x10
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  806c31:	00 
  806c32:	ff d7                	call   edi
  806c34:	83 f8 ff             	cmp    eax,0xffffffff
  806c37:	74 c7                	je     0x806c00
  806c39:	6a 04                	push   0x4
  806c3b:	8d 44 24 14          	lea    eax,[esp+0x14]
  806c3f:	50                   	push   eax
  806c40:	68 02 10 00 00       	push   0x1002
  806c45:	68 ff ff 00 00       	push   0xffff
  806c4a:	56                   	push   esi
  806c4b:	c7 44 24 24 00 40 00 	mov    DWORD PTR [esp+0x24],0x4000
  806c52:	00 
  806c53:	ff d7                	call   edi
  806c55:	83 f8 ff             	cmp    eax,0xffffffff
  806c58:	74 a6                	je     0x806c00
  806c5a:	6a 04                	push   0x4
  806c5c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  806c60:	51                   	push   ecx
  806c61:	68 01 10 00 00       	push   0x1001
  806c66:	68 ff ff 00 00       	push   0xffff
  806c6b:	56                   	push   esi
  806c6c:	c7 44 24 24 00 80 00 	mov    DWORD PTR [esp+0x24],0x8000
  806c73:	00 
  806c74:	ff d7                	call   edi
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
  806ce0:	33 cc                	xor    ecx,esp
  806ce2:	e8 1a a3 08 00       	call   0x891001
  806ce7:	8b e5                	mov    esp,ebp
  806ce9:	5d                   	pop    ebp
  806cea:	c2 10 00             	ret    0x10
  806ced:	cc                   	int3
  806cee:	cc                   	int3
  806cef:	cc                   	int3
```

### A.2 同 key map 替換：取得 key、刪節點、插入新 Conn — VA `0x806c8d..0x806ced`

```asm
Disassembly of section .data:

00806c8d <.data+0x405c8d>:
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
  806ce0:	33 cc                	xor    ecx,esp
  806ce2:	e8 1a a3 08 00       	call   0x891001
  806ce7:	8b e5                	mov    esp,ebp
  806ce9:	5d                   	pop    ebp
  806cea:	c2 10 00             	ret    0x10
```

### A.3 CloseByPtr：shutdown、closesocket、Pool+28 — VA `0x806fc0..0x807090`

```asm
Disassembly of section .data:

00806fc0 <.data+0x405fc0>:
  806fc0:	55                   	push   ebp
  806fc1:	8b ec                	mov    ebp,esp
  806fc3:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806fca:	75 15                	jne    0x806fe1
  806fcc:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806fd3:	74 07                	je     0x806fdc
  806fd5:	e8 86 3f c9 ff       	call   0x49af60
  806fda:	eb 05                	jmp    0x806fe1
  806fdc:	e8 1f 40 c9 ff       	call   0x49b000
  806fe1:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  806fe6:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  806fe9:	56                   	push   esi
  806fea:	57                   	push   edi
  806feb:	51                   	push   ecx
  806fec:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806ff2:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  806ff5:	83 bf a8 a0 00 00 00 	cmp    DWORD PTR [edi+0xa0a8],0x0
  806ffc:	8b 37                	mov    esi,DWORD PTR [edi]
  806ffe:	75 4a                	jne    0x80704a
  807000:	85 f6                	test   esi,esi
  807002:	74 46                	je     0x80704a
  807004:	83 fe ff             	cmp    esi,0xffffffff
  807007:	74 41                	je     0x80704a
  807009:	80 7d 0c 00          	cmp    BYTE PTR [ebp+0xc],0x0
  80700d:	75 1e                	jne    0x80702d
  80700f:	6a 04                	push   0x4
  807011:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  807014:	51                   	push   ecx
  807015:	68 80 00 00 00       	push   0x80
  80701a:	68 ff ff 00 00       	push   0xffff
  80701f:	56                   	push   esi
  807020:	c7 45 0c 01 00 00 00 	mov    DWORD PTR [ebp+0xc],0x1
  807027:	ff 15 ac 25 bd 00    	call   DWORD PTR ds:0xbd25ac
  80702d:	6a 02                	push   0x2
  80702f:	56                   	push   esi
  807030:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  807036:	56                   	push   esi
  807037:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  80703d:	57                   	push   edi
  80703e:	e8 2d 40 c9 ff       	call   0x49b070
  807043:	8b f8                	mov    edi,eax
  807045:	e8 36 ea ff ff       	call   0x805a80
  80704a:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  807051:	5f                   	pop    edi
  807052:	5e                   	pop    esi
  807053:	75 27                	jne    0x80707c
  807055:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  80705c:	74 19                	je     0x807077
  80705e:	e8 fd 3e c9 ff       	call   0x49af60
  807063:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  807069:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  80706c:	50                   	push   eax
  80706d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807073:	5d                   	pop    ebp
  807074:	c2 08 00             	ret    0x8
  807077:	e8 84 3f c9 ff       	call   0x49b000
  80707c:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  807082:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  807085:	50                   	push   eax
  807086:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80708c:	5d                   	pop    ebp
  80708d:	c2 08 00             	ret    0x8
```

### A.4 Pool 取用，新建及重用差異 — VA `0x805950..0x805a7e`

```asm
Disassembly of section .data:

00805950 <.data+0x404950>:
  805950:	55                   	push   ebp
  805951:	8b ec                	mov    ebp,esp
  805953:	6a ff                	push   0xffffffff
  805955:	68 2b 5a 91 00       	push   0x915a2b
  80595a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805960:	50                   	push   eax
  805961:	83 ec 0c             	sub    esp,0xc
  805964:	53                   	push   ebx
  805965:	56                   	push   esi
  805966:	57                   	push   edi
  805967:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80596c:	33 c5                	xor    eax,ebp
  80596e:	50                   	push   eax
  80596f:	8d 45 f4             	lea    eax,[ebp-0xc]
  805972:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805978:	8b f9                	mov    edi,ecx
  80597a:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  80597d:	50                   	push   eax
  80597e:	33 f6                	xor    esi,esi
  805980:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805986:	39 77 20             	cmp    DWORD PTR [edi+0x20],esi
  805989:	74 73                	je     0x8059fe
  80598b:	8d 45 e8             	lea    eax,[ebp-0x18]
  80598e:	8d 4f 10             	lea    ecx,[edi+0x10]
  805991:	e8 7a c8 d3 ff       	call   0x542210
  805996:	8b 08                	mov    ecx,DWORD PTR [eax]
  805998:	85 c9                	test   ecx,ecx
  80599a:	75 04                	jne    0x8059a0
  80599c:	33 d2                	xor    edx,edx
  80599e:	eb 02                	jmp    0x8059a2
  8059a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  8059a2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  8059a5:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  8059a8:	8b c1                	mov    eax,ecx
  8059aa:	c1 e8 02             	shr    eax,0x2
  8059ad:	83 e1 03             	and    ecx,0x3
  8059b0:	3b f0                	cmp    esi,eax
  8059b2:	77 02                	ja     0x8059b6
  8059b4:	2b c6                	sub    eax,esi
  8059b6:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  8059b9:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  8059bc:	8b 34 88             	mov    esi,DWORD PTR [eax+ecx*4]
  8059bf:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  8059c2:	85 c0                	test   eax,eax
  8059c4:	74 23                	je     0x8059e9
  8059c6:	8b 57 18             	mov    edx,DWORD PTR [edi+0x18]
  8059c9:	ff 47 1c             	inc    DWORD PTR [edi+0x1c]
  8059cc:	03 d2                	add    edx,edx
  8059ce:	03 d2                	add    edx,edx
  8059d0:	3b 57 1c             	cmp    edx,DWORD PTR [edi+0x1c]
  8059d3:	77 07                	ja     0x8059dc
  8059d5:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059dc:	48                   	dec    eax
  8059dd:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  8059e0:	75 07                	jne    0x8059e9
  8059e2:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
  8059fc:	eb 60                	jmp    0x805a5e
  8059fe:	39 75 08             	cmp    DWORD PTR [ebp+0x8],esi
  805a01:	74 5b                	je     0x805a5e
  805a03:	68 d8 a0 00 00       	push   0xa0d8
  805a08:	e8 5b b8 08 00       	call   0x891268
  805a0d:	83 c4 04             	add    esp,0x4
  805a10:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a13:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805a16:	3b c6                	cmp    eax,esi
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
  805a5e:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  805a61:	52                   	push   edx
  805a62:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  805a68:	8b c6                	mov    eax,esi
  805a6a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805a6d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805a74:	59                   	pop    ecx
  805a75:	5f                   	pop    edi
  805a76:	5e                   	pop    esi
  805a77:	5b                   	pop    ebx
  805a78:	8b e5                	mov    esp,ebp
  805a7a:	5d                   	pop    ebp
  805a7b:	c2 04 00             	ret    0x4
```

### A.5 Pool+48 producer 與 +28/48 consumer — VA `0x805af0..0x805c93`

```asm
Disassembly of section .data:

00805af0 <.data+0x404af0>:
  805af0:	55                   	push   ebp
  805af1:	8b ec                	mov    ebp,esp
  805af3:	ff 4e 44             	dec    DWORD PTR [esi+0x44]
  805af6:	57                   	push   edi
  805af7:	8b 7e 48             	mov    edi,DWORD PTR [esi+0x48]
  805afa:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  805afd:	8d 45 08             	lea    eax,[ebp+0x8]
  805b00:	50                   	push   eax
  805b01:	51                   	push   ecx
  805b02:	57                   	push   edi
  805b03:	e8 f8 7b f4 ff       	call   0x74d700
  805b08:	8b 4e 4c             	mov    ecx,DWORD PTR [esi+0x4c]
  805b0b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  805b10:	2b d1                	sub    edx,ecx
  805b12:	83 fa 01             	cmp    edx,0x1
  805b15:	73 0a                	jae    0x805b21
  805b17:	68 34 20 bf 00       	push   0xbf2034
  805b1c:	e8 0f 80 07 00       	call   0x87db30
  805b21:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  805b24:	41                   	inc    ecx
  805b25:	89 4e 4c             	mov    DWORD PTR [esi+0x4c],ecx
  805b28:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  805b2b:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  805b2e:	89 01                	mov    DWORD PTR [ecx],eax
  805b30:	c7 42 14 00 00 00 00 	mov    DWORD PTR [edx+0x14],0x0
  805b37:	5f                   	pop    edi
  805b38:	5d                   	pop    ebp
  805b39:	c2 04 00             	ret    0x4
  805b3c:	cc                   	int3
  805b3d:	cc                   	int3
  805b3e:	cc                   	int3
  805b3f:	cc                   	int3
  805b40:	55                   	push   ebp
  805b41:	8b ec                	mov    ebp,esp
  805b43:	83 ec 18             	sub    esp,0x18
  805b46:	53                   	push   ebx
  805b47:	56                   	push   esi
  805b48:	57                   	push   edi
  805b49:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  805b4c:	8b 5f 28             	mov    ebx,DWORD PTR [edi+0x28]
  805b4f:	8b 03                	mov    eax,DWORD PTR [ebx]
  805b51:	3b c3                	cmp    eax,ebx
  805b53:	74 33                	je     0x805b88
  805b55:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  805b58:	83 79 14 00          	cmp    DWORD PTR [ecx+0x14],0x0
  805b5c:	75 24                	jne    0x805b82
  805b5e:	8b 30                	mov    esi,DWORD PTR [eax]
  805b60:	3b 47 28             	cmp    eax,DWORD PTR [edi+0x28]
  805b63:	74 19                	je     0x805b7e
  805b65:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805b68:	89 32                	mov    DWORD PTR [edx],esi
  805b6a:	8b 08                	mov    ecx,DWORD PTR [eax]
  805b6c:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805b6f:	50                   	push   eax
  805b70:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  805b73:	e8 94 b6 08 00       	call   0x89120c
  805b78:	83 c4 04             	add    esp,0x4
  805b7b:	ff 4f 2c             	dec    DWORD PTR [edi+0x2c]
  805b7e:	8b c6                	mov    eax,esi
  805b80:	eb 02                	jmp    0x805b84
  805b82:	8b 00                	mov    eax,DWORD PTR [eax]
  805b84:	3b c3                	cmp    eax,ebx
  805b86:	75 cd                	jne    0x805b55
  805b88:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  805b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  805b8d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805b90:	3b c1                	cmp    eax,ecx
  805b92:	75 0f                	jne    0x805ba3
  805b94:	5f                   	pop    edi
  805b95:	5e                   	pop    esi
  805b96:	5b                   	pop    ebx
  805b97:	8b e5                	mov    esp,ebp
  805b99:	5d                   	pop    ebp
  805b9a:	c2 04 00             	ret    0x4
  805b9d:	8d 49 00             	lea    ecx,[ecx+0x0]
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
  805bbc:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  805bbf:	8b 57 1c             	mov    edx,DWORD PTR [edi+0x1c]
  805bc2:	83 c7 10             	add    edi,0x10
  805bc5:	03 d0                	add    edx,eax
  805bc7:	f6 c2 03             	test   dl,0x3
  805bca:	75 11                	jne    0x805bdd
  805bcc:	83 c0 04             	add    eax,0x4
  805bcf:	c1 e8 02             	shr    eax,0x2
  805bd2:	39 47 08             	cmp    DWORD PTR [edi+0x8],eax
  805bd5:	77 06                	ja     0x805bdd
  805bd7:	57                   	push   edi
  805bd8:	e8 93 13 e3 ff       	call   0x636f70
  805bdd:	8b 5f 0c             	mov    ebx,DWORD PTR [edi+0xc]
  805be0:	03 5f 10             	add    ebx,DWORD PTR [edi+0x10]
  805be3:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  805be6:	8b f3                	mov    esi,ebx
  805be8:	c1 ee 02             	shr    esi,0x2
  805beb:	3b c6                	cmp    eax,esi
  805bed:	77 02                	ja     0x805bf1
  805bef:	2b f0                	sub    esi,eax
  805bf1:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  805bf4:	83 3c b0 00          	cmp    DWORD PTR [eax+esi*4],0x0
  805bf8:	75 14                	jne    0x805c0e
  805bfa:	6a 10                	push   0x10
  805bfc:	e8 67 b6 08 00       	call   0x891268
  805c01:	83 c4 04             	add    esp,0x4
  805c04:	85 c0                	test   eax,eax
  805c06:	74 63                	je     0x805c6b
  805c08:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  805c0b:	89 04 b1             	mov    DWORD PTR [ecx+esi*4],eax
  805c0e:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  805c11:	8b 04 b2             	mov    eax,DWORD PTR [edx+esi*4]
  805c14:	83 e3 03             	and    ebx,0x3
  805c17:	8d 1c 98             	lea    ebx,[eax+ebx*4]
  805c1a:	85 db                	test   ebx,ebx
  805c1c:	74 05                	je     0x805c23
  805c1e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805c21:	89 0b                	mov    DWORD PTR [ebx],ecx
  805c23:	ff 47 10             	inc    DWORD PTR [edi+0x10]
  805c26:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805c29:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  805c2c:	8b 30                	mov    esi,DWORD PTR [eax]
  805c2e:	3b 47 48             	cmp    eax,DWORD PTR [edi+0x48]
  805c31:	74 19                	je     0x805c4c
  805c33:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805c36:	89 32                	mov    DWORD PTR [edx],esi
  805c38:	8b 08                	mov    ecx,DWORD PTR [eax]
  805c3a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805c3d:	50                   	push   eax
  805c3e:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  805c41:	e8 c6 b5 08 00       	call   0x89120c
  805c46:	83 c4 04             	add    esp,0x4
  805c49:	ff 4f 4c             	dec    DWORD PTR [edi+0x4c]
  805c4c:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805c4f:	eb 05                	jmp    0x805c56
  805c51:	8b 00                	mov    eax,DWORD PTR [eax]
  805c53:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805c56:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  805c59:	3b 4f 48             	cmp    ecx,DWORD PTR [edi+0x48]
  805c5c:	0f 85 3e ff ff ff    	jne    0x805ba0
  805c62:	5f                   	pop    edi
  805c63:	5e                   	pop    esi
  805c64:	5b                   	pop    ebx
  805c65:	8b e5                	mov    esp,ebp
  805c67:	5d                   	pop    ebp
  805c68:	c2 04 00             	ret    0x4
  805c6b:	8d 55 f4             	lea    edx,[ebp-0xc]
  805c6e:	52                   	push   edx
  805c6f:	8d 4d e8             	lea    ecx,[ebp-0x18]
  805c72:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  805c79:	e8 2b b4 08 00       	call   0x8910a9
  805c7e:	68 a8 57 c8 00       	push   0xc857a8
  805c83:	8d 45 e8             	lea    eax,[ebp-0x18]
  805c86:	50                   	push   eax
  805c87:	c7 45 e8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x18],0xbd2ca4
  805c8e:	e8 5d 6d 09 00       	call   0x89c9f0
```

### A.6 Conn reset：否定其等同 closesocket — VA `0x805f50..0x806051`

```asm
Disassembly of section .data:

00805f50 <.data+0x404f50>:
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
  805fca:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
  805fdf:	89 9e c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],ebx
  805fe5:	89 9e c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],ebx
  805feb:	89 9e c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],ebx
  805ff1:	89 9e cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],ebx
  805ff7:	89 9e d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],ebx
  805ffd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  806003:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80600a:	00 00 00 
  80600d:	5b                   	pop    ebx
  80600e:	c3                   	ret
  80600f:	cc                   	int3
  806010:	56                   	push   esi
  806011:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  806017:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  80601e:	00 00 00 
  806021:	e8 ba 03 00 00       	call   0x8063e0
  806026:	33 c0                	xor    eax,eax
  806028:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  80602e:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  806034:	89 86 c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],eax
  80603a:	89 86 cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],eax
  806040:	89 86 d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],eax
  806046:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80604d:	00 00 00 
  806050:	c3                   	ret
```

### A.7 Manager destructor：僅 map 可達 Conn 加入 Pool+48 — VA `0x8066a0..0x80683a`

```asm
Disassembly of section .data:

008066a0 <.data+0x4056a0>:
  8066a0:	55                   	push   ebp
  8066a1:	8b ec                	mov    ebp,esp
  8066a3:	6a ff                	push   0xffffffff
  8066a5:	68 d6 44 91 00       	push   0x9144d6
  8066aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8066b0:	50                   	push   eax
  8066b1:	51                   	push   ecx
  8066b2:	53                   	push   ebx
  8066b3:	56                   	push   esi
  8066b4:	57                   	push   edi
  8066b5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8066ba:	33 c5                	xor    eax,ebp
  8066bc:	50                   	push   eax
  8066bd:	8d 45 f4             	lea    eax,[ebp-0xc]
  8066c0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8066c6:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  8066c9:	c7 07 48 17 c5 00    	mov    DWORD PTR [edi],0xc51748
  8066cf:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  8066d6:	8b 47 1c             	mov    eax,DWORD PTR [edi+0x1c]
  8066d9:	8b 30                	mov    esi,DWORD PTR [eax]
  8066db:	3b f0                	cmp    esi,eax
  8066dd:	0f 84 ed 00 00 00    	je     0x8067d0
  8066e3:	8b 3d 58 a8 fb 00    	mov    edi,DWORD PTR ds:0xfba858
  8066e9:	85 ff                	test   edi,edi
  8066eb:	75 4f                	jne    0x80673c
  8066ed:	39 3d 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,edi
  8066f3:	74 0d                	je     0x806702
  8066f5:	e8 66 48 c9 ff       	call   0x49af60
  8066fa:	8b 3d 58 a8 fb 00    	mov    edi,DWORD PTR ds:0xfba858
  806700:	eb 3a                	jmp    0x80673c
  806702:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  806709:	75 26                	jne    0x806731
  80670b:	83 0d 00 12 fc 00 01 	or     DWORD PTR ds:0xfc1200,0x1
  806712:	68 08 12 fc 00       	push   0xfc1208
  806717:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  80671b:	e8 40 ed ff ff       	call   0x805460
  806720:	68 70 e6 bc 00       	push   0xbce670
  806725:	e8 f0 bb 08 00       	call   0x89231a
  80672a:	83 c4 04             	add    esp,0x4
  80672d:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  806731:	bf 08 12 fc 00       	mov    edi,0xfc1208
  806736:	89 3d 58 a8 fb 00    	mov    DWORD PTR ds:0xfba858,edi
  80673c:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  80673f:	ff 4f 44             	dec    DWORD PTR [edi+0x44]
  806742:	8b 5f 48             	mov    ebx,DWORD PTR [edi+0x48]
  806745:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806748:	8d 4d f0             	lea    ecx,[ebp-0x10]
  80674b:	51                   	push   ecx
  80674c:	52                   	push   edx
  80674d:	53                   	push   ebx
  80674e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806751:	e8 aa 6f f4 ff       	call   0x74d700
  806756:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  806759:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  80675e:	2b d1                	sub    edx,ecx
  806760:	83 fa 01             	cmp    edx,0x1
  806763:	0f 82 d1 00 00 00    	jb     0x80683a
  806769:	41                   	inc    ecx
  80676a:	89 4f 4c             	mov    DWORD PTR [edi+0x4c],ecx
  80676d:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  806770:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  806773:	89 01                	mov    DWORD PTR [ecx],eax
  806775:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806778:	c7 40 14 00 00 00 00 	mov    DWORD PTR [eax+0x14],0x0
  80677f:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  806783:	75 3d                	jne    0x8067c2
  806785:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  806788:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  80678c:	75 16                	jne    0x8067a4
  80678e:	8b f0                	mov    esi,eax
  806790:	8b 06                	mov    eax,DWORD PTR [esi]
  806792:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  806796:	75 2a                	jne    0x8067c2
  806798:	8b f0                	mov    esi,eax
  80679a:	8b 06                	mov    eax,DWORD PTR [esi]
  80679c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067a0:	74 f6                	je     0x806798
  8067a2:	eb 1e                	jmp    0x8067c2
  8067a4:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  8067a7:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067ab:	75 13                	jne    0x8067c0
  8067ad:	8d 49 00             	lea    ecx,[ecx+0x0]
  8067b0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  8067b3:	75 0b                	jne    0x8067c0
  8067b5:	8b f0                	mov    esi,eax
  8067b7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  8067ba:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  8067be:	74 f0                	je     0x8067b0
  8067c0:	8b f0                	mov    esi,eax
  8067c2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  8067c5:	3b 71 1c             	cmp    esi,DWORD PTR [ecx+0x1c]
  8067c8:	0f 85 15 ff ff ff    	jne    0x8066e3
  8067ce:	8b f9                	mov    edi,ecx
  8067d0:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  8067d7:	75 35                	jne    0x80680e
  8067d9:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  8067e0:	33 c0                	xor    eax,eax
  8067e2:	50                   	push   eax
  8067e3:	50                   	push   eax
  8067e4:	50                   	push   eax
  8067e5:	6a ff                	push   0xffffffff
  8067e7:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  8067ec:	a3 bc 33 fe 00       	mov    ds:0xfe33bc,eax
  8067f1:	a3 c0 33 fe 00       	mov    ds:0xfe33c0,eax
  8067f6:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  8067fc:	68 b0 0b bd 00       	push   0xbd0bb0
  806801:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806806:	e8 0f bb 08 00       	call   0x89231a
  80680b:	83 c4 04             	add    esp,0x4
  80680e:	be b8 33 fe 00       	mov    esi,0xfe33b8
  806813:	e8 08 17 00 00       	call   0x807f20
  806818:	8b cf                	mov    ecx,edi
  80681a:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  806821:	e8 9a d6 ff ff       	call   0x803ec0
  806826:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806829:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806830:	59                   	pop    ecx
  806831:	5f                   	pop    edi
  806832:	5e                   	pop    esi
  806833:	5b                   	pop    ebx
  806834:	8b e5                	mov    esp,ebp
  806836:	5d                   	pop    ebp
  806837:	c2 04 00             	ret    0x4
```

### A.8 Client virtual tick：Pool+28→Pool+48，BF58 compare — VA `0x490fe0..0x491239`

```asm
Disassembly of section .data:

00490fe0 <.data+0x8ffe0>:
  490fe0:	55                   	push   ebp
  490fe1:	8b ec                	mov    ebp,esp
  490fe3:	83 e4 f8             	and    esp,0xfffffff8
  490fe6:	6a ff                	push   0xffffffff
  490fe8:	68 d0 98 94 00       	push   0x9498d0
  490fed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  490ff3:	50                   	push   eax
  490ff4:	81 ec 40 03 00 00    	sub    esp,0x340
  490ffa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  490fff:	33 c4                	xor    eax,esp
  491001:	89 84 24 38 03 00 00 	mov    DWORD PTR [esp+0x338],eax
  491008:	53                   	push   ebx
  491009:	56                   	push   esi
  49100a:	57                   	push   edi
  49100b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  491010:	33 c4                	xor    eax,esp
  491012:	50                   	push   eax
  491013:	8d 84 24 50 03 00 00 	lea    eax,[esp+0x350]
  49101a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  491020:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  491023:	33 f6                	xor    esi,esi
  491025:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  491029:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49102f:	75 14                	jne    0x491045
  491031:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491037:	74 07                	je     0x491040
  491039:	e8 22 9f 00 00       	call   0x49af60
  49103e:	eb 05                	jmp    0x491045
  491040:	e8 bb 9f 00 00       	call   0x49b000
  491045:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  49104b:	8b 41 34             	mov    eax,DWORD PTR [ecx+0x34]
  49104e:	50                   	push   eax
  49104f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  491055:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49105b:	75 14                	jne    0x491071
  49105d:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491063:	74 07                	je     0x49106c
  491065:	e8 f6 9e 00 00       	call   0x49af60
  49106a:	eb 05                	jmp    0x491071
  49106c:	e8 8f 9f 00 00       	call   0x49b000
  491071:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491077:	8b 4a 28             	mov    ecx,DWORD PTR [edx+0x28]
  49107a:	8b 01                	mov    eax,DWORD PTR [ecx]
  49107c:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  491080:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  491084:	3b c1                	cmp    eax,ecx
  491086:	0f 84 4a 01 00 00    	je     0x4911d6
  49108c:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  49108f:	39 b3 ac a0 00 00    	cmp    DWORD PTR [ebx+0xa0ac],esi
  491095:	75 0b                	jne    0x4910a2
  491097:	8b 00                	mov    eax,DWORD PTR [eax]
  491099:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  49109d:	e9 2c 01 00 00       	jmp    0x4911ce
  4910a2:	a1 04 f7 fd 00       	mov    eax,ds:0xfdf704
  4910a7:	bf 01 00 00 00       	mov    edi,0x1
  4910ac:	03 c7                	add    eax,edi
  4910ae:	50                   	push   eax
  4910af:	68 68 58 c0 00       	push   0xc05868
  4910b4:	a3 04 f7 fd 00       	mov    ds:0xfdf704,eax
  4910b9:	e8 a6 20 40 00       	call   0x893164
  4910be:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4910c2:	83 c4 08             	add    esp,0x8
  4910c5:	39 98 58 bf 00 00    	cmp    DWORD PTR [eax+0xbf58],ebx
  4910cb:	75 50                	jne    0x49111d
  4910cd:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4910d4:	75 35                	jne    0x49110b
  4910d6:	09 3d d0 ac fb 00    	or     DWORD PTR ds:0xfbacd0,edi
  4910dc:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4910e3:	89 35 d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,esi
  4910e9:	e8 12 52 24 00       	call   0x6d6300
  4910ee:	68 70 d6 bc 00       	push   0xbcd670
  4910f3:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4910f8:	e8 1d 12 40 00       	call   0x89231a
  4910fd:	83 c4 04             	add    esp,0x4
  491100:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491107:	ff ff ff ff 
  49110b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491111:	3b ce                	cmp    ecx,esi
  491113:	74 08                	je     0x49111d
  491115:	8b 11                	mov    edx,DWORD PTR [ecx]
  491117:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  49111a:	57                   	push   edi
  49111b:	ff d0                	call   eax
  49111d:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491122:	3b c6                	cmp    eax,esi
  491124:	75 56                	jne    0x49117c
  491126:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  49112c:	74 0c                	je     0x49113a
  49112e:	e8 2d 9e 00 00       	call   0x49af60
  491133:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491138:	eb 42                	jmp    0x49117c
  49113a:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  491141:	75 2f                	jne    0x491172
  491143:	09 3d 00 12 fc 00    	or     DWORD PTR ds:0xfc1200,edi
  491149:	68 08 12 fc 00       	push   0xfc1208
  49114e:	89 bc 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],edi
  491155:	e8 06 43 37 00       	call   0x805460
  49115a:	68 70 e6 bc 00       	push   0xbce670
  49115f:	e8 b6 11 40 00       	call   0x89231a
  491164:	83 c4 04             	add    esp,0x4
  491167:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49116e:	ff ff ff ff 
  491172:	b8 08 12 fc 00       	mov    eax,0xfc1208
  491177:	a3 58 a8 fb 00       	mov    ds:0xfba858,eax
  49117c:	ff 48 44             	dec    DWORD PTR [eax+0x44]
  49117f:	8b 78 48             	mov    edi,DWORD PTR [eax+0x48]
  491182:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  491185:	8d 70 48             	lea    esi,[eax+0x48]
  491188:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  49118c:	51                   	push   ecx
  49118d:	52                   	push   edx
  49118e:	57                   	push   edi
  49118f:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  491193:	e8 68 c5 2b 00       	call   0x74d700
  491198:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  49119b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  4911a0:	2b d1                	sub    edx,ecx
  4911a2:	83 fa 01             	cmp    edx,0x1
  4911a5:	72 46                	jb     0x4911ed
  4911a7:	41                   	inc    ecx
  4911a8:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  4911ab:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4911ae:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4911b1:	89 01                	mov    DWORD PTR [ecx],eax
  4911b3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911b7:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  4911be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4911c0:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4911c4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4911c8:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911cc:	33 f6                	xor    esi,esi
  4911ce:	3b c1                	cmp    eax,ecx
  4911d0:	0f 85 b6 fe ff ff    	jne    0x49108c
  4911d6:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  4911dc:	75 1e                	jne    0x4911fc
  4911de:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  4911e4:	74 11                	je     0x4911f7
  4911e6:	e8 75 9d 00 00       	call   0x49af60
  4911eb:	eb 0f                	jmp    0x4911fc
  4911ed:	68 34 20 bf 00       	push   0xbf2034
  4911f2:	e8 39 c9 3e 00       	call   0x87db30
  4911f7:	e8 04 9e 00 00       	call   0x49b000
  4911fc:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491202:	52                   	push   edx
  491203:	e8 38 49 37 00       	call   0x805b40
  491208:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49120e:	75 14                	jne    0x491224
  491210:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491216:	74 07                	je     0x49121f
  491218:	e8 43 9d 00 00       	call   0x49af60
  49121d:	eb 05                	jmp    0x491224
  49121f:	e8 dc 9d 00 00       	call   0x49b000
  491224:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491229:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  49122c:	50                   	push   eax
  49122d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  491233:	bf 01 00 00 00       	mov    edi,0x1
  491238:	29         	sub    DWORD PTR ds:0xf7dd78,edi
```

### A.9 Client 建構：BF60、BF64、BF68 與 BF5C 初始化 — VA `0x48ac68..0x48acfb`

```asm
Disassembly of section .data:

0048ac68 <.data+0x89c68>:
  48ac68:	0f bf 0d aa 92 fb 00 	movsx  ecx,WORD PTR ds:0xfb92aa
  48ac6f:	eb 05                	jmp    0x48ac76
  48ac71:	b9 00 04 00 00       	mov    ecx,0x400
  48ac76:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  48ac79:	8d 77 08             	lea    esi,[edi+0x8]
  48ac7c:	e8 1f 3e 25 00       	call   0x6deaa0
  48ac81:	8d 87 48 01 00 00    	lea    eax,[edi+0x148]
  48ac87:	e8 f4 96 37 00       	call   0x804380
  48ac8c:	c7 87 00 02 00 00 38 	mov    DWORD PTR [edi+0x200],0xc05b38
  48ac93:	5b c0 00 
  48ac96:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	5b c0 00 
  48acb6:	89 9f 60 bf 00 00    	mov    DWORD PTR [edi+0xbf60],ebx
  48acbc:	89 9f 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],ebx
  48acc2:	89 9f 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],ebx
  48acc8:	89 9f 6c bf 00 00    	mov    DWORD PTR [edi+0xbf6c],ebx
  48acce:	c7 87 70 bf 00 00 64 	mov    DWORD PTR [edi+0xbf70],0x64
  48acd5:	00 00 00 
  48acd8:	89 9f 74 bf 00 00    	mov    DWORD PTR [edi+0xbf74],ebx
  48acde:	89 9f 78 bf 00 00    	mov    DWORD PTR [edi+0xbf78],ebx
  48ace4:	89 9f 7c bf 00 00    	mov    DWORD PTR [edi+0xbf7c],ebx
  48acea:	89 9f 80 bf 00 00    	mov    DWORD PTR [edi+0xbf80],ebx
  48acf0:	6a 3e                	push   0x3e
  48acf2:	8d 8f 95 bf 00 00    	lea    ecx,[edi+0xbf95]
  48acf8:	33 c0                	xor    eax,eax
  48acfa:	33                 	xor    edx,edx
```

### A.10 Client BF5C setter、destructor 對照 — VA `0x48b0b6..0x48b154`

```asm
Disassembly of section .data:

0048b0b6 <.data+0x8a0b6>:
  48b0b6:	c6 45 fc 0b          	mov    BYTE PTR [ebp-0x4],0xb
  48b0ba:	6a 28                	push   0x28
  48b0bc:	89 87 e4 bf 00 00    	mov    DWORD PTR [edi+0xbfe4],eax
  48b0c2:	e8 a1 61 40 00       	call   0x891268
  48b0c7:	83 c4 04             	add    esp,0x4
  48b0ca:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  48b0cd:	c6 45 fc 17          	mov    BYTE PTR [ebp-0x4],0x17
  48b0d1:	3b c3                	cmp    eax,ebx
  48b0d3:	74 08                	je     0x48b0dd
  48b0d5:	50                   	push   eax
  48b0d6:	e8 f5 b9 07 00       	call   0x506ad0
  48b0db:	eb 02                	jmp    0x48b0df
  48b0dd:	33 c0                	xor    eax,eax
  48b0df:	c6 45 fc 0b          	mov    BYTE PTR [ebp-0x4],0xb
  48b0e3:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  48b0ea:	89 87 5c bf 00 00    	mov    DWORD PTR [edi+0xbf5c],eax
  48b0f0:	75 21                	jne    0x48b113
  48b0f2:	83 0d d4 f3 fd 00 01 	or     DWORD PTR ds:0xfdf3d4,0x1
  48b0f9:	c6 45 fc 18          	mov    BYTE PTR [ebp-0x4],0x18
  48b0fd:	e8 7e 92 26 00       	call   0x6f4380
  48b102:	68 d0 e6 bc 00       	push   0xbce6d0
  48b107:	e8 0e 72 40 00       	call   0x89231a
  48b10c:	83 c4 04             	add    esp,0x4
  48b10f:	c6 45 fc 0b          	mov    BYTE PTR [ebp-0x4],0xb
  48b113:	68 b0 55 c0 00       	push   0xc055b0
  48b118:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48b11d:	e8 2e 99 26 00       	call   0x6f4a50
  48b122:	68 bc 55 c0 00       	push   0xc055bc
  48b127:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48b12c:	e8 1f 99 26 00       	call   0x6f4a50
  48b131:	68 c8 55 c0 00       	push   0xc055c8
  48b136:	b9 c8 f3 fd 00       	mov    ecx,0xfdf3c8
  48b13b:	e8 10 99 26 00       	call   0x6f4a50
  48b140:	8b c7                	mov    eax,edi
  48b142:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  48b145:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  48b14c:	59                   	pop    ecx
  48b14d:	5f                   	pop    edi
  48b14e:	5e                   	pop    esi
  48b14f:	5b                   	pop    ebx
  48b150:	8b e5                	mov    esp,ebp
  48b152:	5d                   	pop    ebp
  48b153:	c2               	ret    0x4
```

### A.11 key1 helper：前置 shutdown gate 與 conn slot — VA `0x495610..0x4957ba`

```asm
Disassembly of section .data:

00495610 <.data+0x94610>:
  495610:	55                   	push   ebp
  495611:	8b ec                	mov    ebp,esp
  495613:	83 e4 f8             	and    esp,0xfffffff8
  495616:	6a ff                	push   0xffffffff
  495618:	68 7c 1c 94 00       	push   0x941c7c
  49561d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  495623:	50                   	push   eax
  495624:	83 ec 08             	sub    esp,0x8
  495627:	53                   	push   ebx
  495628:	56                   	push   esi
  495629:	57                   	push   edi
  49562a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49562f:	33 c4                	xor    eax,esp
  495631:	50                   	push   eax
  495632:	8d 44 24 18          	lea    eax,[esp+0x18]
  495636:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49563c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  49563f:	33 ff                	xor    edi,edi
  495641:	83 ce ff             	or     esi,0xffffffff
  495644:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  49564b:	75 21                	jne    0x49566e
  49564d:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  495654:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  495658:	e8 33 bf 04 00       	call   0x4e1590
  49565d:	68 80 cc bc 00       	push   0xbccc80
  495662:	e8 b3 cc 3f 00       	call   0x89231a
  495667:	83 c4 04             	add    esp,0x4
  49566a:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  49566e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  495675:	89 3d c0 41 f9 00    	mov    DWORD PTR ds:0xf941c0,edi
  49567b:	75 25                	jne    0x4956a2
  49567d:	b8 01 00 00 00       	mov    eax,0x1
  495682:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  495688:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  49568c:	e8 ff be 04 00       	call   0x4e1590
  495691:	68 80 cc bc 00       	push   0xbccc80
  495696:	e8 7f cc 3f 00       	call   0x89231a
  49569b:	83 c4 04             	add    esp,0x4
  49569e:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4956a2:	6a 0a                	push   0xa
  4956a4:	68 fc d1 be 00       	push   0xbed1fc
  4956a9:	6a 0b                	push   0xb
  4956ab:	68 c4 41 f9 00       	push   0xf941c4
  4956b0:	e8 49 e9 3f 00       	call   0x893ffe
  4956b5:	83 c4 10             	add    esp,0x10
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2 0c 00             	ret    0xc
```

### A.12 key0/key2 helper：建連、局部首包與部分失敗 — VA `0x4957c0..0x4959e1`

```asm
Disassembly of section .data:

004957c0 <.data+0x947c0>:
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
  495872:	68 90 01 00 00       	push   0x190
  495877:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00 00       	mov    ecx,0x1
  495884:	66 89 4d c0          	mov    WORD PTR [ebp-0x40],cx
  495888:	89 45 c6             	mov    DWORD PTR [ebp-0x3a],eax
  49588b:	89 45 ca             	mov    DWORD PTR [ebp-0x36],eax
  49588e:	89 45 ce             	mov    DWORD PTR [ebp-0x32],eax
  495891:	89 45 d2             	mov    DWORD PTR [ebp-0x2e],eax
  495894:	89 45 d6             	mov    DWORD PTR [ebp-0x2a],eax
  495897:	66 89 4d da          	mov    WORD PTR [ebp-0x26],cx
  49589b:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  49589e:	88 45 e0             	mov    BYTE PTR [ebp-0x20],al
  4958a1:	89 45 e1             	mov    DWORD PTR [ebp-0x1f],eax
  4958a4:	89 45 e5             	mov    DWORD PTR [ebp-0x1b],eax
  4958a7:	89 45 e9             	mov    DWORD PTR [ebp-0x17],eax
  4958aa:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  4958ad:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  4958b0:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  4958b3:	e8 e8 f2 f6 ff       	call   0x404ba0
  4958b8:	8b 90 e0 67 00 00    	mov    edx,DWORD PTR [eax+0x67e0]
  4958be:	89 55 c2             	mov    DWORD PTR [ebp-0x3e],edx
  4958c1:	e8 da f2 f6 ff       	call   0x404ba0
  4958c6:	6a 0a                	push   0xa
  4958c8:	05 e4 67 00 00       	add    eax,0x67e4
  4958cd:	50                   	push   eax
  4958ce:	8d 45 c6             	lea    eax,[ebp-0x3a]
  4958d1:	6a 0a                	push   0xa
  4958d3:	50                   	push   eax
  4958d4:	e8 25 e7 3f 00       	call   0x893ffe
  4958d9:	e8 c2 f2 f6 ff       	call   0x404ba0
  4958de:	6a 0a                	push   0xa
  4958e0:	05 fa 67 00 00       	add    eax,0x67fa
  4958e5:	50                   	push   eax
  4958e6:	8d 4d e5             	lea    ecx,[ebp-0x1b]
  4958e9:	6a 0a                	push   0xa
  4958eb:	51                   	push   ecx
  4958ec:	e8 0d e7 3f 00       	call   0x893ffe
  4958f1:	c6 45 da 01          	mov    BYTE PTR [ebp-0x26],0x1
  4958f5:	e8 a6 f2 f6 ff       	call   0x404ba0
  4958fa:	8a 90 98 68 00 00    	mov    dl,BYTE PTR [eax+0x6898]
  495900:	88 55 db             	mov    BYTE PTR [ebp-0x25],dl
  495903:	e8 98 f2 f6 ff       	call   0x404ba0
  495908:	05 99 68 00 00       	add    eax,0x6899
  49590d:	50                   	push   eax
  49590e:	8d 45 dc             	lea    eax,[ebp-0x24]
  495911:	6a 05                	push   0x5
  495913:	50                   	push   eax
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
  4959e0:	8b                 	mov    esp,ebp
```

### A.13 IOCP worker：recv、send completion、close-by-pointer — VA `0x806cf0..0x806f50`

```asm
Disassembly of section .data:

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
  806f4d:	e8 af a0         	call   0x891001
```

### A.14 接收 framing：byte 門檻與 marker 分流 — VA `0x807b40..0x807e30`

```asm
Disassembly of section .data:

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
```

### A.15 本地 mainloop 消費並分派 — VA `0x49191b..0x4919a0`

```asm
Disassembly of section .data:

0049191b <.data+0x9091b>:
  49191b:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  49191f:	3b c3                	cmp    eax,ebx
  491921:	74 08                	je     0x49192b
  491923:	8b 10                	mov    edx,DWORD PTR [eax]
  491925:	50                   	push   eax
  491926:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  491929:	ff d0                	call   eax
  49192b:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  491932:	75 3a                	jne    0x49196e
  491934:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  49193b:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xb
  491942:	0b 00 00 00 
  491946:	89 1d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,ebx
  49194c:	e8 af 49 24 00       	call   0x6d6300
  491951:	68 70 d6 bc 00       	push   0xbcd670
  491956:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  49195b:	e8 ba 09 40 00       	call   0x89231a
  491960:	83 c4 04             	add    esp,0x4
  491963:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49196a:	ff ff ff ff 
  49196e:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491974:	3b cb                	cmp    ecx,ebx
  491976:	74 07                	je     0x49197f
  491978:	8b 11                	mov    edx,DWORD PTR [ecx]
  49197a:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49197d:	ff d0                	call   eax
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  491996:	75 2f                	jne    0x4919c7
  491998:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  49199f:	c7       	mov    DWORD PTR [esp+0x358],0xc
  4919a6:
```

### A.16 S2C 0x0013 處理及列表上游 — VA `0x4c37a0..0x4c3a40`

```asm
Disassembly of section .data:

004c37a0 <.data+0xc27a0>:
  4c37a0:	55                   	push   ebp
  4c37a1:	8b ec                	mov    ebp,esp
  4c37a3:	6a ff                	push   0xffffffff
  4c37a5:	68 3c 07 94 00       	push   0x94073c
  4c37aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c37b0:	50                   	push   eax
  4c37b1:	81 ec 4c 04 00 00    	sub    esp,0x44c
  4c37b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c37bc:	33 c5                	xor    eax,ebp
  4c37be:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c37c1:	53                   	push   ebx
  4c37c2:	56                   	push   esi
  4c37c3:	57                   	push   edi
  4c37c4:	50                   	push   eax
  4c37c5:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c37c8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c37ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c37d1:	33 db                	xor    ebx,ebx
  4c37d3:	8d 46 20             	lea    eax,[esi+0x20]
  4c37d6:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c37dc:	89 8d b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],ecx
  4c37e2:	66 39 18             	cmp    WORD PTR [eax],bx
  4c37e5:	74 3a                	je     0x4c3821
  4c37e7:	8b 15 08 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba808
  4c37ed:	53                   	push   ebx
  4c37ee:	53                   	push   ebx
  4c37ef:	68 00 04 00 00       	push   0x400
  4c37f4:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  4c37fa:	51                   	push   ecx
  4c37fb:	6a ff                	push   0xffffffff
  4c37fd:	50                   	push   eax
  4c37fe:	53                   	push   ebx
  4c37ff:	52                   	push   edx
  4c3800:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  4c3806:	6a 32                	push   0x32
  4c3808:	8d 85 f0 fb ff ff    	lea    eax,[ebp-0x410]
  4c380e:	50                   	push   eax
  4c380f:	68 97 00 00 00       	push   0x97
  4c3814:	68 00 a7 fb 00       	push   0xfba700
  4c3819:	e8 cd 20 3d 00       	call   0x8958eb
  4c381e:	83 c4 10             	add    esp,0x10
  4c3821:	8a 56 16             	mov    dl,BYTE PTR [esi+0x16]
  4c3824:	80 fa 05             	cmp    dl,0x5
  4c3827:	0f 85 1c 01 00 00    	jne    0x4c3949
  4c382d:	6a 34                	push   0x34
  4c382f:	e8 34 da 3c 00       	call   0x891268
  4c3834:	8b f8                	mov    edi,eax
  4c3836:	83 c4 04             	add    esp,0x4
  4c3839:	89 bd b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],edi
  4c383f:	33 c0                	xor    eax,eax
  4c3841:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c3844:	3b f8                	cmp    edi,eax
  4c3846:	74 4a                	je     0x4c3892
  4c3848:	33 c9                	xor    ecx,ecx
  4c384a:	50                   	push   eax
  4c384b:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c3852:	68 fc d1 be 00       	push   0xbed1fc
  4c3857:	8d 8d b8 fb ff ff    	lea    ecx,[ebp-0x448]
  4c385d:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c3864:	00 00 00 
  4c3867:	89 85 c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],eax
  4c386d:	e8 ee e8 f3 ff       	call   0x402160
  4c3872:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4c3876:	0f be 4e 16          	movsx  ecx,BYTE PTR [esi+0x16]
  4c387a:	8d 95 b8 fb ff ff    	lea    edx,[ebp-0x448]
  4c3880:	52                   	push   edx
  4c3881:	bb 01 00 00 00       	mov    ebx,0x1
  4c3886:	57                   	push   edi
  4c3887:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c388d:	e8 6e 06 29 00       	call   0x753f00
  4c3892:	50                   	push   eax
  4c3893:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4c389a:	e8 b1 71 0c 00       	call   0x58aa50
  4c389f:	83 ce ff             	or     esi,0xffffffff
  4c38a2:	83 c4 04             	add    esp,0x4
  4c38a5:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c38a8:	f6 c3 01             	test   bl,0x1
  4c38ab:	74 35                	je     0x4c38e2
  4c38ad:	83 bd cc fb ff ff 08 	cmp    DWORD PTR [ebp-0x434],0x8
  4c38b4:	72 0f                	jb     0x4c38c5
  4c38b6:	8b 85 b8 fb ff ff    	mov    eax,DWORD PTR [ebp-0x448]
  4c38bc:	50                   	push   eax
  4c38bd:	e8 4a d9 3c 00       	call   0x89120c
  4c38c2:	83 c4 04             	add    esp,0x4
  4c38c5:	33 ff                	xor    edi,edi
  4c38c7:	33 c9                	xor    ecx,ecx
  4c38c9:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c38d0:	00 00 00 
  4c38d3:	89 bd c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],edi
  4c38d9:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c38e0:	eb 02                	jmp    0x4c38e4
  4c38e2:	33 ff                	xor    edi,edi
  4c38e4:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4c38eb:	75 2e                	jne    0x4c391b
  4c38ed:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  4c38f4:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  4c38fb:	89 3d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,edi
  4c3901:	e8 fa 29 21 00       	call   0x6d6300
  4c3906:	68 70 d6 bc 00       	push   0xbcd670
  4c390b:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4c3910:	e8 05 ea 3c 00       	call   0x89231a
  4c3915:	83 c4 04             	add    esp,0x4
  4c3918:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c391b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  4c3921:	3b cf                	cmp    ecx,edi
  4c3923:	74 08                	je     0x4c392d
  4c3925:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c3927:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4c392a:	57                   	push   edi
  4c392b:	ff d0                	call   eax
  4c392d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4c3933:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c3935:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  4c3938:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  4c393e:	6a 01                	push   0x1
  4c3940:	6a 01                	push   0x1
  4c3942:	ff d0                	call   eax
  4c3944:	e9 10 02 00 00       	jmp    0x4c3b59
  4c3949:	84 d2                	test   dl,dl
  4c394b:	0f 85 df 00 00 00    	jne    0x4c3a30
  4c3951:	8d 7e 02             	lea    edi,[esi+0x2]
  4c3954:	8b c7                	mov    eax,edi
  4c3956:	8d 48 02             	lea    ecx,[eax+0x2]
  4c3959:	89 8d a8 fb ff ff    	mov    DWORD PTR [ebp-0x458],ecx
  4c395f:	90                   	nop
  4c3960:	66 8b 08             	mov    cx,WORD PTR [eax]
  4c3963:	83 c0 02             	add    eax,0x2
  4c3966:	66 85 c9             	test   cx,cx
  4c3969:	75 f5                	jne    0x4c3960
  4c396b:	2b 85 a8 fb ff ff    	sub    eax,DWORD PTR [ebp-0x458]
  4c3971:	d1 f8                	sar    eax,1
  4c3973:	0f 84 b7 00 00 00    	je     0x4c3a30
  4c3979:	8b 5e 18             	mov    ebx,DWORD PTR [esi+0x18]
  4c397c:	e8 1f 12 f4 ff       	call   0x404ba0
  4c3981:	89 98 e0 67 00 00    	mov    DWORD PTR [eax+0x67e0],ebx
  4c3987:	e8 14 12 f4 ff       	call   0x404ba0
  4c398c:	85 ff                	test   edi,edi
  4c398e:	74 13                	je     0x4c39a3
  4c3990:	6a 0a                	push   0xa
  4c3992:	57                   	push   edi
  4c3993:	05 e4 67 00 00       	add    eax,0x67e4
  4c3998:	6a 0b                	push   0xb
  4c399a:	50                   	push   eax
  4c399b:	e8 5e 06 3d 00       	call   0x893ffe
  4c39a0:	83 c4 10             	add    esp,0x10
  4c39a3:	0f b6 7e 17          	movzx  edi,BYTE PTR [esi+0x17]
  4c39a7:	e8 f4 11 f4 ff       	call   0x404ba0
  4c39ac:	89 b8 b4 68 00 00    	mov    DWORD PTR [eax+0x68b4],edi
  4c39b2:	8a 9e 90 00 00 00    	mov    bl,BYTE PTR [esi+0x90]
  4c39b8:	e8 e3 11 f4 ff       	call   0x404ba0
  4c39bd:	88 98 b0 68 00 00    	mov    BYTE PTR [eax+0x68b0],bl
  4c39c3:	8a 96 86 00 00 00    	mov    dl,BYTE PTR [esi+0x86]
  4c39c9:	8b 9e 8c 00 00 00    	mov    ebx,DWORD PTR [esi+0x8c]
  4c39cf:	88 95 b4 fb ff ff    	mov    BYTE PTR [ebp-0x44c],dl
  4c39d5:	e8 c6 11 f4 ff       	call   0x404ba0
  4c39da:	8b f8                	mov    edi,eax
  4c39dc:	8a 85 b4 fb ff ff    	mov    al,BYTE PTR [ebp-0x44c]
  4c39e2:	8d 8e 87 00 00 00    	lea    ecx,[esi+0x87]
  4c39e8:	51                   	push   ecx
  4c39e9:	8d 97 99 68 00 00    	lea    edx,[edi+0x6899]
  4c39ef:	6a 05                	push   0x5
  4c39f1:	52                   	push   edx
  4c39f2:	88 87 98 68 00 00    	mov    BYTE PTR [edi+0x6898],al
  4c39f8:	e8 5c 01 3d 00       	call   0x893b59
  4c39fd:	89 9f a0 68 00 00    	mov    DWORD PTR [edi+0x68a0],ebx
  4c3a03:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  4c3a06:	83 c4 0c             	add    esp,0xc
  4c3a09:	50                   	push   eax
  4c3a0a:	8d 8e 92 00 00 00    	lea    ecx,[esi+0x92]
  4c3a10:	e8 6b f6 ff ff       	call   0x4c3080
  4c3a15:	80 be 90 00 00 00 00 	cmp    BYTE PTR [esi+0x90],0x0
  4c3a1c:	75 0b                	jne    0x4c3a29
  4c3a1e:	8b bd b0 fb ff ff    	mov    edi,DWORD PTR [ebp-0x450]
  4c3a24:	e8 47 f7 ff ff       	call   0x4c3170
  4c3a29:	33 c0                	xor    eax,eax
  4c3a2b:	e9 34 01 00 00       	jmp    0x4c3b64
  4c3a30:	0f be ca             	movsx  ecx,dl
  4c3a33:	51                   	push   ecx
  4c3a34:	68 e4 72 c0 00       	push   0xc072e4
  4c3a39:	e8 22 a1 22 00       	call   0x6edb60
  4c3a3e:	6a 34                	push   0x34
```

### A.17 S2C 0x007A 處理 — VA `0x4c3c10..0x4c3c58`

```asm
Disassembly of section .data:

004c3c10 <.data+0xc2c10>:
  4c3c10:	55                   	push   ebp
  4c3c11:	8b ec                	mov    ebp,esp
  4c3c13:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c3c16:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4c3c19:	51                   	push   ecx
  4c3c1a:	8d 48 06             	lea    ecx,[eax+0x6]
  4c3c1d:	e8 5e f4 ff ff       	call   0x4c3080
  4c3c22:	33 c0                	xor    eax,eax
  4c3c24:	5d                   	pop    ebp
  4c3c25:	c2 0c 00             	ret    0xc
  4c3c28:	cc                   	int3
  4c3c29:	cc                   	int3
  4c3c2a:	cc                   	int3
  4c3c2b:	cc                   	int3
  4c3c2c:	cc                   	int3
  4c3c2d:	cc                   	int3
  4c3c2e:	cc                   	int3
  4c3c2f:	cc                   	int3
  4c3c30:	55                   	push   ebp
  4c3c31:	8b ec                	mov    ebp,esp
  4c3c33:	6a ff                	push   0xffffffff
  4c3c35:	68 4c 4e 92 00       	push   0x924e4c
  4c3c3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c3c40:	50                   	push   eax
  4c3c41:	53                   	push   ebx
  4c3c42:	56                   	push   esi
  4c3c43:	57                   	push   edi
  4c3c44:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c3c49:	33 c5                	xor    eax,ebp
  4c3c4b:	50                   	push   eax
  4c3c4c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c3c4f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c3c55:	bb 01 00         	mov    ebx,0x1
```

### A.18 UI resolver 轉 0x4957c0 — VA `0x66c090..0x66c270`

```asm
Disassembly of section .data:

0066c090 <.data+0x26b090>:
  66c090:	55                   	push   ebp
  66c091:	8b ec                	mov    ebp,esp
  66c093:	83 e4 f8             	and    esp,0xfffffff8
  66c096:	6a ff                	push   0xffffffff
  66c098:	68 7a 61 94 00       	push   0x94617a
  66c09d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  66c0a3:	50                   	push   eax
  66c0a4:	83 ec 10             	sub    esp,0x10
  66c0a7:	53                   	push   ebx
  66c0a8:	56                   	push   esi
  66c0a9:	57                   	push   edi
  66c0aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  66c0af:	33 c4                	xor    eax,esp
  66c0b1:	50                   	push   eax
  66c0b2:	8d 44 24 20          	lea    eax,[esp+0x20]
  66c0b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  66c0bc:	8b f9                	mov    edi,ecx
  66c0be:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  66c0c1:	8b 81 f0 00 00 00    	mov    eax,DWORD PTR [ecx+0xf0]
  66c0c7:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c0cd:	85 c0                	test   eax,eax
  66c0cf:	74 1c                	je     0x66c0ed
  66c0d1:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c0d7:	85 c0                	test   eax,eax
  66c0d9:	75 09                	jne    0x66c0e4
  66c0db:	83 c8 ff             	or     eax,0xffffffff
  66c0de:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0e2:	eb 11                	jmp    0x66c0f5
  66c0e4:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c0e7:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0eb:	eb 08                	jmp    0x66c0f5
  66c0ed:	c7 44 24 10 ff ff ff 	mov    DWORD PTR [esp+0x10],0xffffffff
  66c0f4:	ff 
  66c0f5:	85 ff                	test   edi,edi
  66c0f7:	75 2b                	jne    0x66c124
  66c0f9:	8b 81 f4 00 00 00    	mov    eax,DWORD PTR [ecx+0xf4]
  66c0ff:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c105:	85 c0                	test   eax,eax
  66c107:	74 18                	je     0x66c121
  66c109:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c10f:	85 c0                	test   eax,eax
  66c111:	75 07                	jne    0x66c11a
  66c113:	83 c8 ff             	or     eax,0xffffffff
  66c116:	8b f8                	mov    edi,eax
  66c118:	eb 0a                	jmp    0x66c124
  66c11a:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c11d:	8b f8                	mov    edi,eax
  66c11f:	eb 03                	jmp    0x66c124
  66c121:	83 cf ff             	or     edi,0xffffffff
  66c124:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  66c128:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  66c12e:	57                   	push   edi
  66c12f:	50                   	push   eax
  66c130:	8b c6                	mov    eax,esi
  66c132:	e8 89 b7 e9 ff       	call   0x5078c0
  66c137:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  66c13b:	57                   	push   edi
  66c13c:	8b d8                	mov    ebx,eax
  66c13e:	51                   	push   ecx
  66c13f:	8b c6                	mov    eax,esi
  66c141:	e8 0a b6 e9 ff       	call   0x507750
  66c146:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  66c14d:	8b f0                	mov    esi,eax
  66c14f:	75 2a                	jne    0x66c17b
  66c151:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  66c158:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  66c15f:	00 
  66c160:	e8 2b 54 e7 ff       	call   0x4e1590
  66c165:	68 80 cc bc 00       	push   0xbccc80
  66c16a:	e8 ab 61 22 00       	call   0x89231a
  66c16f:	83 c4 04             	add    esp,0x4
  66c172:	83 cf ff             	or     edi,0xffffffff
  66c175:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  66c179:	eb 03                	jmp    0x66c17e
  66c17b:	83 cf ff             	or     edi,0xffffffff
  66c17e:	83 3d 94 42 f9 00 00 	cmp    DWORD PTR ds:0xf94294,0x0
  66c185:	0f 84 92 00 00 00    	je     0x66c21d
  66c18b:	85 db                	test   ebx,ebx
  66c18d:	0f 84 8a 00 00 00    	je     0x66c21d
  66c193:	85 f6                	test   esi,esi
  66c195:	0f 84 1e 03 00 00    	je     0x66c4b9
  66c19b:	e8 e0 84 da ff       	call   0x414680
  66c1a0:	56                   	push   esi
  66c1a1:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c1a7:	e8 14 96 e2 ff       	call   0x4957c0
  66c1ac:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  66c1af:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  66c1b5:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c1bb:	85 c0                	test   eax,eax
  66c1bd:	74 43                	je     0x66c202
  66c1bf:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c1c5:	85 c0                	test   eax,eax
  66c1c7:	75 1c                	jne    0x66c1e5
  66c1c9:	8b c7                	mov    eax,edi
  66c1cb:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c1d0:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c1d4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c1db:	59                   	pop    ecx
  66c1dc:	5f                   	pop    edi
  66c1dd:	5e                   	pop    esi
  66c1de:	5b                   	pop    ebx
  66c1df:	8b e5                	mov    esp,ebp
  66c1e1:	5d                   	pop    ebp
  66c1e2:	c2 04 00             	ret    0x4
  66c1e5:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c1e8:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c1ed:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c1f1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c1f8:	59                   	pop    ecx
  66c1f9:	5f                   	pop    edi
  66c1fa:	5e                   	pop    esi
  66c1fb:	5b                   	pop    ebx
  66c1fc:	8b e5                	mov    esp,ebp
  66c1fe:	5d                   	pop    ebp
  66c1ff:	c2 04 00             	ret    0x4
  66c202:	89 3d cc 3d d6 00    	mov    DWORD PTR ds:0xd63dcc,edi
  66c208:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c20c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c213:	59                   	pop    ecx
  66c214:	5f                   	pop    edi
  66c215:	5e                   	pop    esi
  66c216:	5b                   	pop    ebx
  66c217:	8b e5                	mov    esp,ebp
  66c219:	5d                   	pop    ebp
  66c21a:	c2 04 00             	ret    0x4
  66c21d:	83 fb 04             	cmp    ebx,0x4
  66c220:	74 52                	je     0x66c274
  66c222:	85 db                	test   ebx,ebx
  66c224:	0f 84 bc 01 00 00    	je     0x66c3e6
  66c22a:	83 fb 05             	cmp    ebx,0x5
  66c22d:	0f 84 bc 01 00 00    	je     0x66c3ef
  66c233:	85 f6                	test   esi,esi
  66c235:	0f 84 7e 02 00 00    	je     0x66c4b9
  66c23b:	e8 40 84 da ff       	call   0x414680
  66c240:	56                   	push   esi
  66c241:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c247:	e8 74 95 e2 ff       	call   0x4957c0
  66c24c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c24f:	8b 80 f0 00 00 00    	mov    eax,DWORD PTR [eax+0xf0]
  66c255:	e8 d6 02 dc ff       	call   0x42c530
  66c25a:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c25f:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c263:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c26a:	59                   	pop    ecx
  66c26b:	5f                   	pop    edi
  66c26c:	5e                   	pop    esi
  66c26d:	5b                   	pop    ebx
  66c26e:	8b e5                	mov    esp,ebp
```

### A.19 map tree erase 節點與 free（非 Conn socket） — VA `0x7b6890..0x7b6b00`

```asm
Disassembly of section .data:

007b6890 <.data+0x3b5890>:
  7b6890:	55                   	push   ebp
  7b6891:	8b ec                	mov    ebp,esp
  7b6893:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b6896:	83 ec 08             	sub    esp,0x8
  7b6899:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b689d:	74 0a                	je     0x7b68a9
  7b689f:	68 28 d2 be 00       	push   0xbed228
  7b68a4:	e8 d4 72 0c 00       	call   0x87db7d
  7b68a9:	53                   	push   ebx
  7b68aa:	56                   	push   esi
  7b68ab:	8b d8                	mov    ebx,eax
  7b68ad:	57                   	push   edi
  7b68ae:	8d 45 10             	lea    eax,[ebp+0x10]
  7b68b1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7b68b4:	e8 e7 7d ce ff       	call   0x49e6a0
  7b68b9:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b68bb:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b68bf:	74 05                	je     0x7b68c6
  7b68c1:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7b68c4:	eb 17                	jmp    0x7b68dd
  7b68c6:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b68c9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b68cd:	74 04                	je     0x7b68d3
  7b68cf:	8b f9                	mov    edi,ecx
  7b68d1:	eb 0a                	jmp    0x7b68dd
  7b68d3:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b68d6:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  7b68d9:	3b c3                	cmp    eax,ebx
  7b68db:	75 7c                	jne    0x7b6959
  7b68dd:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b68e1:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  7b68e4:	75 03                	jne    0x7b68e9
  7b68e6:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b68e9:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b68ec:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b68ef:	39 58 04             	cmp    DWORD PTR [eax+0x4],ebx
  7b68f2:	75 05                	jne    0x7b68f9
  7b68f4:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  7b68f7:	eb 0b                	jmp    0x7b6904
  7b68f9:	39 1e                	cmp    DWORD PTR [esi],ebx
  7b68fb:	75 04                	jne    0x7b6901
  7b68fd:	89 3e                	mov    DWORD PTR [esi],edi
  7b68ff:	eb 03                	jmp    0x7b6904
  7b6901:	89 7e 08             	mov    DWORD PTR [esi+0x8],edi
  7b6904:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b6907:	39 18                	cmp    DWORD PTR [eax],ebx
  7b6909:	75 24                	jne    0x7b692f
  7b690b:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b690f:	74 04                	je     0x7b6915
  7b6911:	8b ce                	mov    ecx,esi
  7b6913:	eb 15                	jmp    0x7b692a
  7b6915:	8b 07                	mov    eax,DWORD PTR [edi]
  7b6917:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b691b:	8b cf                	mov    ecx,edi
  7b691d:	75 0b                	jne    0x7b692a
  7b691f:	90                   	nop
  7b6920:	8b c8                	mov    ecx,eax
  7b6922:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6924:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b6928:	74 f6                	je     0x7b6920
  7b692a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b692d:	89 08                	mov    DWORD PTR [eax],ecx
  7b692f:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6932:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  7b6935:	39 59 08             	cmp    DWORD PTR [ecx+0x8],ebx
  7b6938:	75 7c                	jne    0x7b69b6
  7b693a:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b693e:	74 07                	je     0x7b6947
  7b6940:	8b c6                	mov    eax,esi
  7b6942:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6945:	eb 6f                	jmp    0x7b69b6
  7b6947:	8b c7                	mov    eax,edi
  7b6949:	e8 32 d2 06 00       	call   0x823b80
  7b694e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7b6951:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6954:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6957:	eb 5d                	jmp    0x7b69b6
  7b6959:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b695c:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b695e:	89 08                	mov    DWORD PTR [eax],ecx
  7b6960:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b6963:	75 04                	jne    0x7b6969
  7b6965:	8b f0                	mov    esi,eax
  7b6967:	eb 1a                	jmp    0x7b6983
  7b6969:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b696d:	8b 70 04             	mov    esi,DWORD PTR [eax+0x4]
  7b6970:	75 03                	jne    0x7b6975
  7b6972:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b6975:	89 3e                	mov    DWORD PTR [esi],edi
  7b6977:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b697a:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  7b697d:	8b 53 08             	mov    edx,DWORD PTR [ebx+0x8]
  7b6980:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  7b6983:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6986:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  7b6989:	39 59 04             	cmp    DWORD PTR [ecx+0x4],ebx
  7b698c:	75 05                	jne    0x7b6993
  7b698e:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b6991:	eb 0e                	jmp    0x7b69a1
  7b6993:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7b6996:	39 19                	cmp    DWORD PTR [ecx],ebx
  7b6998:	75 04                	jne    0x7b699e
  7b699a:	89 01                	mov    DWORD PTR [ecx],eax
  7b699c:	eb 03                	jmp    0x7b69a1
  7b699e:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b69a1:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7b69a4:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  7b69a7:	8a 53 14             	mov    dl,BYTE PTR [ebx+0x14]
  7b69aa:	8a 48 14             	mov    cl,BYTE PTR [eax+0x14]
  7b69ad:	88 50 14             	mov    BYTE PTR [eax+0x14],dl
  7b69b0:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69b3:	88 4b 14             	mov    BYTE PTR [ebx+0x14],cl
  7b69b6:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7b69b9:	b3 01                	mov    bl,0x1
  7b69bb:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b69be:	0f 85 ff 00 00 00    	jne    0x7b6ac3
  7b69c4:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b69c7:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b69ca:	0f 84 f0 00 00 00    	je     0x7b6ac0
  7b69d0:	38 5f 14             	cmp    BYTE PTR [edi+0x14],bl
  7b69d3:	0f 85 e7 00 00 00    	jne    0x7b6ac0
  7b69d9:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b69db:	3b f9                	cmp    edi,ecx
  7b69dd:	75 69                	jne    0x7b6a48
  7b69df:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69e2:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b69e6:	75 15                	jne    0x7b69fd
  7b69e8:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b69eb:	52                   	push   edx
  7b69ec:	8b ce                	mov    ecx,esi
  7b69ee:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b69f2:	e8 69 d5 fa ff       	call   0x763f60
  7b69f7:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69fa:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69fd:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a01:	75 78                	jne    0x7b6a7b
  7b6a03:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a05:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a08:	75 08                	jne    0x7b6a12
  7b6a0a:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a0d:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a10:	74 65                	je     0x7b6a77
  7b6a12:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a15:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a18:	75 15                	jne    0x7b6a2f
  7b6a1a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a1c:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a1f:	52                   	push   edx
  7b6a20:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a24:	e8 47 7c c8 ff       	call   0x43e670
  7b6a29:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b6a2c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a2f:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6a32:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6a35:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6a38:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  7b6a3b:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a3e:	52                   	push   edx
  7b6a3f:	8b ce                	mov    ecx,esi
  7b6a41:	e8 1a d5 fa ff       	call   0x763f60
  7b6a46:	eb 78                	jmp    0x7b6ac0
  7b6a48:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b6a4c:	75 14                	jne    0x7b6a62
  7b6a4e:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a51:	52                   	push   edx
  7b6a52:	8b ce                	mov    ecx,esi
  7b6a54:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b6a58:	e8 13 7c c8 ff       	call   0x43e670
  7b6a5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6a5f:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a62:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a66:	75 13                	jne    0x7b6a7b
  7b6a68:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a6b:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a6e:	75 1e                	jne    0x7b6a8e
  7b6a70:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a72:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a75:	75 17                	jne    0x7b6a8e
  7b6a77:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a7b:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6a7e:	8b fe                	mov    edi,esi
  7b6a80:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  7b6a83:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b6a86:	0f 85 44 ff ff ff    	jne    0x7b69d0
  7b6a8c:	eb 32                	jmp    0x7b6ac0
  7b6a8e:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a90:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a93:	75 15                	jne    0x7b6aaa
  7b6a95:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a98:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a9b:	52                   	push   edx
  7b6a9c:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6aa0:	e8 bb d4 fa ff       	call   0x763f60
  7b6aa5:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6aa7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6aaa:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6aad:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6ab0:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6ab3:	8b 09                	mov    ecx,DWORD PTR [ecx]
  7b6ab5:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6ab8:	52                   	push   edx
  7b6ab9:	8b ce                	mov    ecx,esi
  7b6abb:	e8 b0 7b c8 ff       	call   0x43e670
  7b6ac0:	88 5f 14             	mov    BYTE PTR [edi+0x14],bl
  7b6ac3:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b6ac6:	52                   	push   edx
  7b6ac7:	e8 40 a7 0d 00       	call   0x89120c
  7b6acc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6acf:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6ad2:	83 c4 04             	add    esp,0x4
  7b6ad5:	5f                   	pop    edi
  7b6ad6:	5e                   	pop    esi
  7b6ad7:	5b                   	pop    ebx
  7b6ad8:	85 c0                	test   eax,eax
  7b6ada:	74 04                	je     0x7b6ae0
  7b6adc:	48                   	dec    eax
  7b6add:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6ae0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7b6ae3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b6ae6:	89 08                	mov    DWORD PTR [eax],ecx
  7b6ae8:	8b e5                	mov    esp,ebp
  7b6aea:	5d                   	pop    ebp
  7b6aeb:	c2 0c 00             	ret    0xc
  7b6aee:	cc                   	int3
  7b6aef:	cc                   	int3
  7b6af0:	55                   	push   ebp
  7b6af1:	8b ec                	mov    ebp,esp
  7b6af3:	6a ff                	push   0xffffffff
  7b6af5:	68 a8 19 91 00       	push   0x9119a8
  7b6afa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
```

### A.20 本地 Conn 發送 pump（送出依賴） — VA `0x804a40..0x804bc0`

```asm
Disassembly of section .data:

00804a40 <.data+0x403a40>:
  804a40:	55                   	push   ebp
  804a41:	8b ec                	mov    ebp,esp
  804a43:	83 ec 18             	sub    esp,0x18
  804a46:	53                   	push   ebx
  804a47:	8b 1d a0 25 bd 00    	mov    ebx,DWORD PTR ds:0xbd25a0
  804a4d:	56                   	push   esi
  804a4e:	57                   	push   edi
  804a4f:	ff d3                	call   ebx
  804a51:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  804a58:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  804a5b:	89 47 48             	mov    DWORD PTR [edi+0x48],eax
  804a5e:	75 15                	jne    0x804a75
  804a60:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  804a67:	74 07                	je     0x804a70
  804a69:	e8 f2 64 c9 ff       	call   0x49af60
  804a6e:	eb 05                	jmp    0x804a75
  804a70:	e8 8b 65 c9 ff       	call   0x49b000
  804a75:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  804a7b:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  804a7e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804a85:	ff d3                	call   ebx
  804a87:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  804a8d:	2b c8                	sub    ecx,eax
  804a8f:	bb 01 00 00 00       	mov    ebx,0x1
  804a94:	83 f9 21             	cmp    ecx,0x21
  804a97:	76 09                	jbe    0x804aa2
  804a99:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  804a9f:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  804aa2:	8b 7e 04             	mov    edi,DWORD PTR [esi+0x4]
  804aa5:	2b 3e                	sub    edi,DWORD PTR [esi]
  804aa7:	33 c0                	xor    eax,eax
  804aa9:	c1 ff 02             	sar    edi,0x2
  804aac:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  804aaf:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  804ab2:	85 ff                	test   edi,edi
  804ab4:	0f 84 a1 01 00 00    	je     0x804c5b
  804aba:	eb 07                	jmp    0x804ac3
  804abc:	8d 64 24 00          	lea    esp,[esp+0x0]
  804ac0:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  804b1a:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  804b21:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  804b28:	0f 84 1d 01 00 00    	je     0x804c4b
  804b2e:	8b 86 b8 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0b8]
  804b34:	85 c0                	test   eax,eax
  804b36:	0f 8f 0f 01 00 00    	jg     0x804c4b
  804b3c:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  804b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b48:	8b 11                	mov    edx,DWORD PTR [ecx]
  804b4a:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  804b4d:	8d 7d ec             	lea    edi,[ebp-0x14]
  804b50:	57                   	push   edi
  804b51:	50                   	push   eax
  804b52:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  804b58:	50                   	push   eax
  804b59:	56                   	push   esi
  804b5a:	ff d2                	call   edx
  804b5c:	85 c0                	test   eax,eax
  804b5e:	75 1c                	jne    0x804b7c
  804b60:	56                   	push   esi
  804b61:	e8 7a 18 00 00       	call   0x8063e0
  804b66:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b6c:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b6e:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b71:	6a 00                	push   0x0
  804b73:	56                   	push   esi
  804b74:	ff d2                	call   edx
  804b76:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804b7c:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  804b83:	74 16                	je     0x804b9b
  804b85:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b8d:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b90:	6a 00                	push   0x0
  804b92:	56                   	push   esi
  804b93:	ff d2                	call   edx
  804b95:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804b9b:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  804ba2:	01 00 00 
  804ba5:	0f 8e 9d 00 00 00    	jle    0x804c48
  804bab:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  804bb2:	0f 85 90 00 00 00    	jne    0x804c48
  804bb8:	56                   	push   esi
  804bb9:	e8 22 18 00 00       	call   0x8063e0
  804bbe:	8b 45              	mov    eax,DWORD PTR [ebp+0x8]
```

## 附錄 B — 研究完成／驗證的不同階段

1. **研究者已完成可證的 Client 靜態邊界報告**：對 RR-0005 的每個 clause 提供具體地址、分支、首包方向與正/負限定，不用固定函式數或重大發現門檻。
2. `SUBMITTED` 後由 T01/S00 決定是否 `IN_REVIEW / NEEDS_REVISION / ACCEPTED`；提交不授權作者自行提高任何證據級別。
3. `原版 Server 首回覆`、`wire-first bytes`、`I/O race`、`原版 IP` 保持 U；不得因這些 Client-only 靜態原件天然無法決定的事實，反向聲稱其它有界 Client 證據不存在。
4. `BF58` 間接 writer／替換 old Conn 全程終態不可宣告 N。這些是否須列為新的 Client 靜態研究缺口或 S00 需要的安全規範，交由審查時精確決定；現有程式路徑的行為已給出其限制。
