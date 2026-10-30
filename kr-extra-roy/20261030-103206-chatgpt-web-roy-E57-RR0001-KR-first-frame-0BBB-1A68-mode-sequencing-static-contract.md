# E57 — RR-0001／KR T02：三條連線的初始 frame／0x0BBB-XOR／0x1A68 fallback／S2C marker／模式來源（目標導向 BIN-first 交付）

> **範圍及誠實完成聲明**：本文回答 RR-0001 在 **KR Client 靜態可證** 層級的全部必要問題，附現場重新抽取原始 BIN 的直接指令、收發 schema、失敗條件、分 Conn 事件矩陣及跨 RR 依賴。它不是原版 Server 首包錄製或真實 socket 事件排序證明。研究者可將本文提交 S00/T01 審查，只有 S00 可決定 RR `ACCEPTED`，T01 FULL-PASS 仍另算。不以重大發現、子段數、篇幅做停止點。

- 研究時間：2026-10-30T10:32:06+08:00；操作者 `chatgpt-web roy`；來源檔僅唯讀，**未執行遊戲或連線**。
- KR `Tartaros.bin`：size=12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- PE section (`.text`) VA `0x00401000`，raw `0x00000400`，raw bytes `0x7D01F0`；本稿所有 `.text` 指令使用 `raw_offset = VA - 0x400C00`；此公式**不適用**其他 section。
- 題目與目前認領：`RR-0001 / GAP-NET-0001`，`T02`，`CLAIMED`，認領分支 `rr/t02/roy/rr-0001`；本次資料在 2026-10-30 開工時 `main=95363f4ae8c203b6f6c35d586f990117a5274283`。發表後以遠端 read-back 的 SHA 為準。
- 對照既有 `extra/roy1`：E44／E45（S2C 0x0013/0x007A→選服→key0/key2），E51–E54（Pool、send pump、IOCP、queue），E55／E56（key1 六個 caller/送包候選），不重複「發現已知函式」；以下為本次重新讀原件的證據與新增位元組級結論。
- 其他 RR：**RR-0004 留待獨立研究**，其 `A02C` 間接 alias／plaintext fallback 全域分析不是本次接手；與 RR-0001 在「預設模式來源與可證分支」交界做有界核對，不把全域沒找到當成不存在。

## 1. 正式 RR question 和靜態研究終點

正式問題：已知 `0x8068B0 WSASend`、`0x806CF0 WSARecv/IOCP`、`0x4930E0 downstream dispatch`，須釐清首個 C2S/S2C frame type、`Conn+A02C` 條件切換、每連線初始訊息順序，**不重新發現已知 socket 函式**；`GAP-NET-0001` 再要求 **有界 S2C 類型、A02C writer/aliases、first-message sequencing**。

具體完成矩陣（`N`=raw native 已證；`C`=靜態條件式；`U`=Client 無法給出全稱／仍需補證）：

| 子問題 | 原件結果 | 級別 |
| --- | --- | --- |
| Client 預設新 Conn mode | `805D02` 寫 `BYTE [Conn+A02C]=2`；`806202` 讀 signed byte；非零先嘗試 `807830` | N |
| 模式選擇（包括重用） | mode==0 → `807A70`；mode!=0 → `807830`，失敗才 `807A70`；reuse reset `805F50` 內未見寫 A02C | N/C |
| 0x0BBB 真實 header | 2B payload length LE + 2B `BB 0B` + 2B checksum LE + XOR-chain payload | N |
| 0x1A68 真實 header | 2B payload length LE + 2B `68 1A` + raw payload | N |
| 0x0BBB 發送 encoder 失敗條件 | 非零長度、`n+6<=0x1000`、累積 Tx `+n+6<=0x4000`、指標範圍，其他路徑 ret0 | N/C |
| 0x1A68 fallback 失敗條件 | 非零長度、`n+4<=0x1000`、累積 Tx `+n+4<=0x4000`、指標範圍 | N/C |
| 接收端可接受格式／如何選擇 | `807B40` 依 inbound marker `0x2633`,`0x0BBB`,`0x1A68`,`0x22D7` 做 8/6/4-byte header gate；非 `A02C` 直接決定 | N |
| 接收 0x0BBB checksum | 解出 XOR-chain，sum(plaintext bytes) mod 65536 與 header+4 WORD 比；失配沒有正長度 payload 交業務處理 | N/C |
| 初次出站 key0 | key0/key2 都成功才 key0 local queue `n=0x39`，首 cmd WORD=0x0001；若 mode2/encoder成功，0x0BBB outer frame total 63B | N/C |
| 初次出站 key1 | 六處直接 `495610` caller，四處成功後 local enqueue `0x38`,`0x68`,`0x2CE`,`0x2CE`；另兩處 callback-only；不同條件，不能合一 | N/C |
| key2 初次出站 | `4957C0` 自身不對 key2 enqueue；僅 post recv，後續其他上游 producer 尚可發送 | N/C |
| first inbound **實際** frame／跨 socket wall-clock 順序 | Client parser 不是 Server 事件紀錄；找不到原版 Server 或可靠同 session pcap 時不可推出唯一原版先送 marker/opcode；只給 Client 接受集合及 gate | U (由來源種類限制) |
| `A02C` 全部間接 alias writer | 在 `.text` 直接 `A02C` displacement 僅兩處；此為已限定搜尋的陰性結果，非全程別名不存在保證 | C/U；RR-0004 待查 |

## 2. 功能圖／封包方向與位元組層級

```text
S2C (預選服；Server 發來什麼由對方決定)
  WSARecv/IOCP 806CF0 → 807B40 依 header marker 解包
  → [非零 decoded bytes] 8040A0/FC10D0 → 804740／4930E0 (需 lane2 等 gate)
  → command 0x0013/0x007A （是 application WORD，不是 frame marker）
  → 4C3080／FE1B54 選服 table → UI 66C090
  → 4957C0 建立 key0(port0x20E0,lane2) 再 key2(port0x20DE,lane2)

C2S (遊戲選服後，本地 enqueue 不是首個 wire completion)
  [key0/key2 都返回 Conn*] key0 495935 queue 57-byte payload，cmd0x0001
  → 8069A0 → 8060D0 → Conn send queue → 804A40/8052xx send pump
  → 8061A0 檢查 Conn+A02C：mode !=0 時先 807830(0BBB)
                                  mode ==0／0BBB失敗時 807A70(1A68)
  → Conn TX buffer → Manager virtual+0x0C=8068B0 WSASend
  → send completion 806CF0 / pending count A0B8（不代表 TCP 對端收到）

其它 C2S key1
  6D6377/6D6424/6D6508/6D65C8/6D670C/6D696C → 495610
  → key1 (port0x20DF,lane2)，只有部分 callers 建立本地 first candidate

S2C 收包後再發送是獨立上層行為；不要把 S2C 0x0013/0x007A 認成選服後新 key0 的 ACK。
```

外層 frame 與內層 native command 嚴格區分：`0x0BBB`,`0x1A68`,`0x2633`,`0x22D7` 是 **framing marker**，`0x0001` (key0 C2S) 與 `0x0013/0x007A` (上層 S2C) 是 **decoded payload**。`key0/1/2` 是 Conn map key，`Conn+A080=2` 是應用 lane，**`Conn+A02C=2` 是另一個欄位**；數字相同不能混為同一物件語意。

## 3. 核實 constructor／reset／A02C 位移 xref

直接原始 machine-code bytes：

```asm
805CFC: 89 be 1c 50 00 00          mov DWORD PTR [esi+0x501c], edi
805D02: c6 86 2c a0 00 00 02    mov BYTE PTR [esi+0xa02c],0x2
806202: 0f be 86 2c a0 00 00    movsx eax,BYTE PTR [esi+0xa02c]
806218: 74 15                   je 0x80622f   ; mode0 direct plaintext
806223: e8 08 16 00 00          call 0x807830 ; mode!=0 encoded attempt
806228: 85 c0                   test eax,eax
80622a: 75 23                   jne 0x80624f   ; success skips plaintext
806234: e8 31 18 00 00          call 0x807a70 ; fallback/direct plaintext
```

對整段 `.text` bytes `0x400..0x7D05F0` 搜尋 4-byte disp `2c a0 00 00`，原件**只有**兩處，分別位於 VA `0x805D04`、`0x806205`（各是上述指令的 displacement，不是 opcode 的起點），無其他直接使用相同 displacement 的 x86 指令候選。`.text` 中 `E8 rel32` 直接 `807830` 與 `807A70` 的 calls 各只有 `806223`／`80623A`；這同樣是**該 opcode 模式的搜尋範圍**，不是所有虛擬／間接 alias 或跨區寫入的不存在證明。已在 E52 對 `805F50` 重用 Reset 核對沒有另一個 A02C direct reset；因此 default 新 Conn=2，重用 Conn 是否仍為2依其先前狀態。

簡化偽碼（限本地封裝選擇）：

```cpp
// Conn+A02C: signed byte; only zero vs nonzero controls this branch.
for (auto *packet : conn.pending_send_queue) {
    bool done = false;
    if (conn.frame_mode_byte != 0)
        done = encode_0BBB(packet.bytes, packet.length, conn.tx_buffer);
    if (!done)
        done = encode_1A68(packet.bytes, packet.length, conn.tx_buffer);
    if (!done) {
        // Body has a failure/partial-progress gate; no successful output frame promised.
        break;
    }
    remove_and_recycle_queue_node(packet);
}
```

注意：`A02C==1`、`==2`、其它非零值在**這條 `8061A0` 可見條件**皆嘗試 0BBB；不能按值=2 推論另有第三種編碼。不能將 absence of a direct writer 改寫為「任何 runtime 都不可能寫零」。

## 4. `0x0BBB` 編碼／checksum／fallback 的真正 schema

`807830` 以 `ECX=Conn+0x501C`、`arg0=payload_ptr`、`arg1=payload_len`，在 Tx 緩衝區內追加 `payload_len+6`。header 據 `807870` 構造的 DWORD `0x7D810BBB`、`80787A` 寫入長度 WORD 以及 `8079EF..8079FC` 最後將 header+4 兩 bytes 改寫為 checksum；`0x7D81` 是臨時 stack initializer 的高 WORD，**不是 wire 上固定的第五／第六 bytes**。

```text
0x0BBB encoded frame（每一 frame 自身）
  +0x00  u16le  n = plaintext payload length
  +0x02  u16le  0x0BBB  (wire bytes BB 0B)
  +0x04  u16le  checksum = sum(plaintext[i]) mod 65536
  +0x06  u8[n]  ciphertext
            cipher[0] = plaintext[0] XOR 0xB6
            cipher[i] = plaintext[i] XOR plaintext[i-1] (i>=1)
  total = n + 6 bytes

0x1A68 plaintext frame:
  +0x00  u16le  n
  +0x02  u16le  0x1A68  (wire bytes 68 1A)
  +0x04  u8[n]  unchanged payload
  total = n + 4 bytes
```

接收 `0x0BBB` 在 `807D33` 先 `cipher[0]^0xB6`，再依 `807D50–807D66` 逐位 XOR 前一解出的 byte，累加原文 BYTE 值，`cmp WORD [frame+4],CX`，失敗時跳過 `807E50` 正長度 payload copy。不代表外層 TCP 連線必然立即中斷。`0x1A68` 在 `807D2C` 的非壓縮非 0BBB 路徑直接 copy payload。

`0x0BBB` encoder `807887` 要求 `n+6<=0x1000`、`n!=0`；`80789A..8078B6` 以目前 tx length 限定累積 `<=0x4000`；`8078D3..8078ED` 檢查目的區間在 Conn tx buffer 的合法內部範圍。任何一項不成立會返回0，`80622A` 才走 `807A70` fallback；後者 `n+4<=0x1000`、`n!=0`、累積 `<=0x4000` 與目的指標合法，失敗時不保證已產生 frame。故 **「0BBB encoder 回傳0」與「整體 send 失敗」不等價**，更不能說 0BBB 失敗就一定發出 plaintext。長度 `n=4091/4092` 可能在 0BBB 因 +6 超限但仍符合 +4（若 Tx 可容納）而走 1A68；`n>4092` 兩者均不符合單-frame上限。

### 合成 codec 驗算（不是原版 pcap）

以合成 decoded payload `01 00`：

- 0x0BBB wire：`02 00 BB 0B 01 00 B7 01`。0x0BBB 某一條件發送的**外層 n=2**，checksum=1，cipher `B7 01`；接收 XOR 還原 `01 00`，sum=1。
- 0x1A68 wire：`02 00 68 1A 01 00`。本例僅展示 header/marker，**不得稱為實際遊戲發出的第一包**。
- key0 當 `0x495935` 本地 `n=0x39` 且 fresh Conn mode2、encoder成功、Send Pump實際消費該 queue item 時，候選 frame 佔 `0x39+6=0x3F` (=63) bytes。相同條件若改 fallback 才是 `0x39+4=0x3D` (=61) bytes。這只是生成 buffer 大小，不是 socket write callback 的 OS completion 或 Server 觀測。

可重算的合成測試：

```python
def encode_0bbb(plain: bytes) -> bytes:
    assert 1 <= len(plain) <= 0x1000 - 6
    cipher = bytes([plain[0] ^ 0xB6] +
                   [plain[i] ^ plain[i-1] for i in range(1, len(plain))])
    return (len(plain).to_bytes(2, 'little') +
            (0x0BBB).to_bytes(2, 'little') +
            (sum(plain) & 0xFFFF).to_bytes(2, 'little') + cipher)

def decode_0bbb(frame: bytes) -> bytes:
    n = int.from_bytes(frame[0:2], 'little')
    assert int.from_bytes(frame[2:4], 'little') == 0x0BBB
    assert len(frame) == n + 6 and n > 0
    cipher = frame[6:]
    out = [cipher[0] ^ 0xB6]
    for b in cipher[1:]:
        out.append(b ^ out[-1])
    assert (sum(out) & 0xffff) == int.from_bytes(frame[4:6], 'little')
    return bytes(out)

assert encode_0bbb(b'\x01\x00') == bytes.fromhex('02 00 bb 0b 01 00 b7 01')
assert decode_0bbb(bytes.fromhex('02 00 bb 0b 01 00 b7 01')) == b'\x01\x00'
```

**反證／留待 T01**：這份 schema 是從特定 `807830` 本地實作還原；若 S00 要規格化 production MUST，T01 仍需獨立驗證每一條 byte transform、checksum 和編碼長度。不得將本地合成資料提升為 KR 原生封包紀錄。

## 5. S2C receive marker／error bounds：Client 能解 ≠ Server 第一個實送

`807B40` 對 Conn+0x5000 累積接收 bytes 後，至少 4-byte 才讀 `[frame+0]=WORD len`（`1..0x1000`）及 `[frame+2]=WORD marker`。按 marker 選 header 長度：

| Marker | Header | 分支 | 不能推論 |
| --- | ---: | --- | --- |
| `0x2633` | 8 | `807BE5–807BFA` 標記壓縮、`807CD2–807D13` 做 XOR／呼叫 `0x727190` 解壓，再準備 decoded buffer | 沒證明它是登入首回覆；詳細 727190/失敗下游是 RR-0006 |
| `0x0BBB` | 6 | `807BFC–807C16` 標記 checksum/XOR；`807D33–807D6A` byte decode+sum 比對 | 即使 Client 預設 sender 使用 0BBB，**也不能**推導 Server 必須回 0BBB |
| `0x1A68` | 4 | `807C18–807C2C`；一般 raw payload copy | 不表示 Server 一定回 plaintext |
| `0x22D7` | 4 | 特別比對但保持 header4；本函式後段與 raw path 匯合 | 不宣稱此 marker 有何業務意義；細追屬 RR-0006 |
| 其他 marker | 4（可見 default） | 不在上面 markers 仍按 header4 gate 通過後處理；需符合 bytes-length等限制 | 不能稱所有未知 marker 都是官方支援的協定 |

接收資料足夠一個 frame (`len+hdr<=accumulated`) 才處理，成功組包經 `807E50` 放入有 `+4` 長度欄的 node；長度零／copy 失敗則回收（`8076F0`），長度正才依 `Conn+A080` lane 投遞 `8040A0`。後續上層主循環 `804740→4930E0` 的 lane2、非零、handler table/receiver gate 成立時，可達 `0x0013→0x4C37A0` 與 `0x007A→0x4C3C10`。兩 command 是**登入／伺服器列表上游**的候選 S2C，不是 key0 新 Connect 後的第一 reply 有保證。`A02C` 的讀取位於 **send wrapper 8061A0**；本段 `807B40` 的 inbound marker 判定並未依 Conn+A02C 去固定接受哪個 marker。

**研究目的上的可達性和不可知邊界**：Client 原件無法演繹「官方 Server 在某個 session 首次發哪個 header+命令」，因為上游 peer 的選擇不是由 Client 這段 code 決定。除非可靠伺服器原件、原版同 session pcap 或相當資料，S00 應把 first-inbound 寫成 peer-side `UNKNOWN`，Client parser 能接受的組合才列為相容能力，切勿猜 first reply 或固定整條 login wire ordering。

## 6. key0／key1／key2 first local producer 與先後關係

| Conn map key | Connect 原生觸發 | 初始候選 C2S／條件 | 以 fresh A02C=2 且 0BBB encoder成功時 candidate encoded frame bytes | 其它 S2C／條件 |
| --- | --- | --- | ---: | --- |
| key0 | `0x4957C0`先 Connect key0 port `0x20E0`、lane2 | 只有 key0/key2 都非 NULL，才 `0x495935` queue `0x39` (=57) bytes，本地第一個 WORD `0x0001` | 57+6=**63** | vtable+0x14 `WSARecv` 之後 IOCP，實際 Server 初次 reply U |
| key2 | 同 helper 第二 Connect key2 port `0x20DE`、lane2 | 本函式**無** key2 對應的初始 queue；後續 sender 不在此閉包限定 | 不適用 | 同上，獨立 Conn/IOCP 收包 U |
| key1 | `0x495610` 六個 caller、port `0x20DF`、lane2 | `6D6508→0x38` (=56)、`6D65C8→0x68` (=104)、`6D670C→0x2CE` (=718)、`6D696C→0x2CE` (=718)；`6D6377/6D6424` 在已核區段只見 callback-side，無同函式直送；皆有各自上游條件 | **62、110、724、724**（條件式；非固定唯一初包） | 可在部分選服狀態前/後另行 Connect；不能以 key0 時序取代 key1 |

`0x495610` 的 `[EBP+0x10]` 第三參數非零時**先**對 key0/2 vtable+0x20 shutdown；在 `BF60` 已有 pointer 時可對 key1 shutdown／清 BF60，非零／零 gate 影響新 Connect。key1 的六個 caller，第三參數並非全部相同： `6D6508` 用 `1`，其它直接 caller 可見 `0`；key1 可能在 0/2 之前、之後或獨立流程建立，不能推全域固定 key1→key0→key2。`0x4957C0` 局部 CPU CALL 次序可證 key0 Connect call first→key2 Connect call second，然而接收／送出由背景 send pump/IOCP 排程，**wire event 先後不一定同 CPU call 次序**。

`0x4957C0` 中 key0/key2 任一 `NULL` 時走局部錯誤與 shutdown branch，不會執行 key0 57-byte queue；未證明 Server 全域重試策略或 old Conn 必定收掉。`WSARecv` 對二 Conn 的 post 發生在 queue 之後的本地呼叫路徑，不意味任何對端先收哪個 socket 的 bytes。`Conn+A0AC!=0`、send queue、`Conn+A028`、`A0B8`（SEND pending count）、`A0A8` closing gates 影響何時由 `804A40` / `8052xx` 將已框好的 bytes 交給 `WSASend`，不能將「queued first」等同「wire first」。

多次發送時單 Conn Tx buffer 會累積 frames（上限、已輸出部分及 pump 控制）；WSASend 可以回即時成功或 WSA_IO_PENDING，不保證立即交付應用層。不同連線的 TCP 流沒有天然跨 socket 全域先後序。

## 7. 程式碼級契約（非原版 Server 規則、不可當 runtime 證據）

```cpp
struct FramingObservation {
  // All fields below are derived at known native call points only.
  uint16_t payload_len;       // 1..0x1000; successful 0BBB max 4090, 1A68 max 4092
  uint16_t frame_marker;      // 0x0BBB for encoded; 0x1A68 for direct/fallback
};

void schedule_local_payload(Conn &c, Bytes command) {
  // enqueue does not guarantee framing or wire send
  assert(command.size() <= 0x1000); // caller still must satisfy queue/backpressure gates
  enqueue(c, command);
}

void flush_pending(Conn &c) {
  for (auto &cmd : c.queue) {
    bool ok = (c.mode_A02C != 0) && try_0BBB(c.tx, cmd);
    if (!ok) ok = try_1A68(c.tx, cmd);
    if (!ok) break;
    recycle_queue_item(cmd);
  }
  // separately: if send-in-flight and close gates allow, call WSASend over tx bytes
}

void receive_bytes(Conn &c, Bytes data) {
  append(c.rx, data);
  while (c.rx.has_full_header_and_length()) {
    auto marker = c.rx.u16le(2); // peer chooses marker
    if (marker == 0x0BBB) validate_and_unpack_xor_checksum();
    else if (marker == 0x2633) decode_compressed_conditional();
    else copy_direct_payload_when_length_valid();
    // enqueue decoded node only if actual decoded length > 0
  }
}
```

**禁止把此偽碼當做原樣可編譯復刻。** 真實 Client 的 queue、buffer、overlapped、worker counters、critical sections 及錯誤分支需以下列 assembly/前段 E51–E56 為準；相容 Server 需要另作 ADR 及測試，不應仿造可疑 memory safety 行為。

## 8. 已搜尋的證據／反例與交付界線

- 直接 xref 以所有 `.text` raw bytes 的 `E8 rel32` 掃描，僅代表直接 CALL 候選；`0x8068B0` 與 `0x806CF0` 透過 vtable/worker 回呼進入，**因此直接 CALL 搜到零並非未使用**。
- `Conn+A02C` 直接 disp `2c a0 00 00` 命中 `{', '.join(hex(x) for x in idx)}`；只有在已確認指令邊界下分別是 `0x805D02` 和 `0x806202`，且 E52 reset 無 A02C direct write。**RR-0004** 須後續再查 computed-pointer、memcpy、初始化寫入與總體 alias graph；RR-0001 不聲稱 mode0 無法達到。
- `0x807830` direct caller: `{', '.join(hex(x) for x in calls[0x807830])}`；`0x807A70` direct caller: `{', '.join(hex(x) for x in calls[0x807a70])}`；`0x8061A0` direct callers: `{', '.join(hex(x) for x in calls[0x8061a0])}`（此掃描不含 indirect）。
- `0x495610` direct caller set: `{', '.join(hex(x) for x in calls[0x495610])}`；`0x4957C0` direct caller set: `{', '.join(hex(x) for x in calls[0x4957c0])}`。本段分 Conn matrix 由這些 caller 前後的實際 enqueue/body code 與 E56 的來源身份交叉核對；沒有把 six caller 各自等同一次網路事件。
- 「選擇 inbound marker 的 S2C Server 邏輯」和「跨 Conn wire event 的真實先後」在 KR Client BIN 中未觀測到對方行為，需第一手 Server 程式、原版同 session trace、或明確限定的相容 Server 測試去解除。**這是本來源對 peer event 的證據種類限制，不是因懶得追 Client static graph 而停止。**
- 0x2633 的演算法／失敗下游屬 `RR-0006`；S2C 0x0013 handler 的完整 schema 屬 `T03/RR-0002/0003`；本稿只追 RR-0001 初始 frame／連線與 dispatch 交界，不改其他 Task。所有未核原生 Server 端動作分類 `Server 待開發／待遊玩驗證`，不是「原版官方 Server 已證」。

## 9. S00/T01 接收用的有界 SPEC／GAP／TEST 對應

| 消費者 | 可以引用的 Client 靜態主張 | 不可從本文升格的事實 | 建議驗收／測試 |
| --- | --- | --- | --- |
| S00 SPEC session transport | 0BBB XOR+sum/6B header；1A68 raw/4B；每 Conn outgoing mode gate；receiver marker dynamic | 官方 first S2C marker/opcode、原版伺服器 IP、真實傳送順序 | 合成 0BBB header/chain/sum vector 及反向 decode，明標 synthetic；0/1/4090/4091/4092 payload bound 測試 |
| S00 SPEC login／connect | key0/1/2 port、lane、local initial candidate / null gates；C2S0x0001 57B only key0 after two-Conn return | 不應推「3 TCP 都固定按同一順序啟動」、「每個 key 都有相同首包」 | key1 多分支、key0/2 partially failed、send queued vs WSASend 分離 |
| GAP-NET-0001 | bounded first-framing choices and A02C visible writer/read | A02C alias global proof 尚在 RR-0004；legacy Server first-frame unknown | 先據 bounded 客戶端事實建 DRAFT，不為第一回覆猜固定 byte |
| T01 R1/R2/R3 | 任一 claim 附 VA/bytes/CFG/反證，支持定向獨立驗證 | 單份報告不能自動 FULL-PASS，合成 vector 不是 native pcap | 指令邊界、checksum 計算、接收錯包 drop、各表變更對應證據 |

**研究者聲明**：RR-0001 的 Client **可靜態回答**部分已整合為可審查的 bounded contract；peer first-reply 和跨 Conn wire 時序屬已明確列出解除證據的 U。申請 `SUBMITTED`（由 T01/S00 決定是否滿足正式 RR acceptance criteria）；**不**在沒有審查前寫成 `ACCEPTED`、`FULL-PASS`、`GAP RESOLVED`、SPEC STABLE。`RR-0004` 保持 `QUEUED`，未經用戶授權不得同時認領。

## 10. 第一手 BIN disassembly 附錄與重現方法

所有原始指令都從本次 SHA 核對的 `/mnt/data/Tartaros.bin` `.text` 區段複製至獨立 raw slice 後，以 GNU objdump 反組譯；下列 append 原文，未由既有 Markdown 複製。注意獨立反組譯不能從任意機器碼的中間 byte 起始；已知函式 entry 對齊時才視作指令證據。raw offset 公式見首頁。方法：

```bash
python - <<'PY2'
from pathlib import Path
b=Path('Tartaros.bin').read_bytes()
Path('text.bin').write_bytes(b[0x400:0x400+0x7D01F0])
PY2
objdump -b binary -m i386 -M intel --adjust-vma=0x401000 \
  -D --start-address=0x8061A0 --stop-address=0x8063E0 text.bin
```

附錄全文保留精確地址及原指令 bytes；跨函式拼接範圍只在所註明的 entry／block 邊界下作正證。

### A. 出站 queue drain/mode branch `0x8061A0–0x8063E0`

直接證據：A02C byte 讀取、0BBB→1A68 fallback、append 成功才移除 node，失敗 ret flag。

```asm
008061a0 <.data+0x4051a0>:
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]
  80627b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806282:	8b d9                	mov    ebx,ecx
  806284:	75 27                	jne    0x8062ad
  806286:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80628d:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806294:	e8 87 0e 00 00       	call   0x807120
  806299:	68 90 0b bd 00       	push   0xbd0b90
  80629e:	e8 77 c0 08 00       	call   0x89231a
  8062a3:	83 c4 04             	add    esp,0x4
  8062a6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8062ad:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  8062b2:	50                   	push   eax
  8062b3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8062b9:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  8062bf:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  8062c6:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  8062cb:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  8062d1:	03 c8                	add    ecx,eax
  8062d3:	f6 c1 03             	test   cl,0x3
  8062d6:	75 18                	jne    0x8062f0
  8062d8:	83 c0 04             	add    eax,0x4
  8062db:	c1 e8 02             	shr    eax,0x2
  8062de:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  8062e4:	77 0a                	ja     0x8062f0
  8062e6:	68 64 33 fe 00       	push   0xfe3364
  8062eb:	e8 80 0c e3 ff       	call   0x636f70
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
  80637f:	50                   	push   eax
  806380:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806383:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  80638a:	e8 1a ad 08 00       	call   0x8910a9
  80638f:	68 a8 57 c8 00       	push   0xc857a8
  806394:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806397:	51                   	push   ecx
  806398:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  80639f:	e8 4c 66 09 00       	call   0x89c9f0
  8063a4:	83 be b4 a0 00 00 01 	cmp    DWORD PTR [esi+0xa0b4],0x1
  8063ab:	75 0d                	jne    0x8063ba
  8063ad:	83 7d e8 00          	cmp    DWORD PTR [ebp-0x18],0x0
  8063b1:	75 07                	jne    0x8063ba
  8063b3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  8063ba:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8063c0:	52                   	push   edx
  8063c1:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8063c7:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  8063ca:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8063cd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  8063d4:	59                   	pop    ecx
  8063d5:	5f                   	pop    edi
  8063d6:	5e                   	pop    esi
  8063d7:	5b                   	pop    ebx
  8063d8:	8b e5                	mov    esp,ebp
  8063da:	5d                   	pop    ebp
  8063db:	c2 04 00             	ret    0x4
  8063de:	cc                   	int3
  8063df:	cc                   	int3
```

### B. 出站 0BBB 和 1A68 encoder `0x807830–0x807B40`

正向 checksum/XOR 與 send buffer bounds；每個 header 的 literal bytes 都在此。

```asm
00807830 <.data+0x406830>:
  807830:	55                   	push   ebp
  807831:	8b ec                	mov    ebp,esp
  807833:	b8 38 10 00 00       	mov    eax,0x1038
  807838:	e8 33 8e 0a 00       	call   0x8b0670
  80783d:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807842:	33 c5                	xor    eax,ebp
  807844:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  807847:	53                   	push   ebx
  807848:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80784b:	56                   	push   esi
  80784c:	8b f1                	mov    esi,ecx
  80784e:	8b 06                	mov    eax,DWORD PTR [esi]
  807850:	57                   	push   edi
  807851:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  807854:	50                   	push   eax
  807855:	89 b5 cc ef ff ff    	mov    DWORD PTR [ebp-0x1034],esi
  80785b:	89 9d d4 ef ff ff    	mov    DWORD PTR [ebp-0x102c],ebx
  807861:	89 85 f0 ef ff ff    	mov    DWORD PTR [ebp-0x1010],eax
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
  8078ef:	33 c0                	xor    eax,eax
  8078f1:	89 85 ec ef ff ff    	mov    DWORD PTR [ebp-0x1014],eax
  8078f7:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078fd:	8a 03                	mov    al,BYTE PTR [ebx]
  8078ff:	8a d0                	mov    dl,al
  807901:	80 f2 b6             	xor    dl,0xb6
  807904:	88 95 fc ef ff ff    	mov    BYTE PTR [ebp-0x1004],dl
  80790a:	0f b6 d0             	movzx  edx,al
  80790d:	b8 01 00 00 00       	mov    eax,0x1
  807912:	89 95 f8 ef ff ff    	mov    DWORD PTR [ebp-0x1008],edx
  807918:	3b f8                	cmp    edi,eax
  80791a:	0f 86 c9 00 00 00    	jbe    0x8079e9
  807920:	8d 57 ff             	lea    edx,[edi-0x1]
  807923:	83 fa 02             	cmp    edx,0x2
  807926:	0f 8c 8d 00 00 00    	jl     0x8079b9
  80792c:	8d 8d fd ef ff ff    	lea    ecx,[ebp-0x1003]
  807932:	83 c7 fd             	add    edi,0xfffffffd
  807935:	8b d3                	mov    edx,ebx
  807937:	2b d1                	sub    edx,ecx
  807939:	8d b5 fc ef ff ff    	lea    esi,[ebp-0x1004]
  80793f:	2b cb                	sub    ecx,ebx
  807941:	2b f3                	sub    esi,ebx
  807943:	d1 ef                	shr    edi,1
  807945:	47                   	inc    edi
  807946:	89 8d d0 ef ff ff    	mov    DWORD PTR [ebp-0x1030],ecx
  80794c:	8d 4c 3f 01          	lea    ecx,[edi+edi*1+0x1]
  807950:	8d 43 01             	lea    eax,[ebx+0x1]
  807953:	89 b5 c8 ef ff ff    	mov    DWORD PTR [ebp-0x1038],esi
  807959:	89 8d e0 ef ff ff    	mov    DWORD PTR [ebp-0x1020],ecx
  80795f:	eb 06                	jmp    0x807967
  807961:	8b b5 c8 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1038]
  807967:	8a 08                	mov    cl,BYTE PTR [eax]
  807969:	03 f0                	add    esi,eax
  80796b:	0f b6 1c 16          	movzx  ebx,BYTE PTR [esi+edx*1]
  80796f:	32 d9                	xor    bl,cl
  807971:	0f b6 c9             	movzx  ecx,cl
  807974:	66 01 8d ec ef ff ff 	add    WORD PTR [ebp-0x1014],cx
  80797b:	8a 48 01             	mov    cl,BYTE PTR [eax+0x1]
  80797e:	88 1e                	mov    BYTE PTR [esi],bl
  807980:	0f b6 18             	movzx  ebx,BYTE PTR [eax]
  807983:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  807989:	32 d9                	xor    bl,cl
  80798b:	0f b6 c9             	movzx  ecx,cl
  80798e:	66 01 8d f4 ef ff ff 	add    WORD PTR [ebp-0x100c],cx
  807995:	88 1c 06             	mov    BYTE PTR [esi+eax*1],bl
  807998:	83 c0 02             	add    eax,0x2
  80799b:	4f                   	dec    edi
  80799c:	75 c3                	jne    0x807961
  80799e:	8b 85 e0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1020]
  8079a4:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8079a7:	8b b5 cc ef ff ff    	mov    esi,DWORD PTR [ebp-0x1034]
  8079ad:	8b 9d d4 ef ff ff    	mov    ebx,DWORD PTR [ebp-0x102c]
  8079b3:	8b 8d dc ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1024]
  8079b9:	3b c7                	cmp    eax,edi
  8079bb:	73 1a                	jae    0x8079d7
  8079bd:	8a 14 03             	mov    dl,BYTE PTR [ebx+eax*1]
  8079c0:	8a 5c 03 ff          	mov    bl,BYTE PTR [ebx+eax*1-0x1]
  8079c4:	32 da                	xor    bl,dl
  8079c6:	0f b6 d2             	movzx  edx,dl
  8079c9:	66 01 95 f8 ef ff ff 	add    WORD PTR [ebp-0x1008],dx
  8079d0:	88 9c 05 fc ef ff ff 	mov    BYTE PTR [ebp+eax*1-0x1004],bl
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01 86 0c 50 00 00    	add    DWORD PTR [esi+0x500c],eax
  807a25:	01 86 04 50 00 00    	add    DWORD PTR [esi+0x5004],eax
  807a2b:	83 c4 0c             	add    esp,0xc
  807a2e:	52                   	push   edx
  807a2f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a35:	5f                   	pop    edi
  807a36:	5e                   	pop    esi
  807a37:	b8 01 00 00 00       	mov    eax,0x1
  807a3c:	5b                   	pop    ebx
  807a3d:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a40:	33 cd                	xor    ecx,ebp
  807a42:	e8 ba 95 08 00       	call   0x891001
  807a47:	8b e5                	mov    esp,ebp
  807a49:	5d                   	pop    ebp
  807a4a:	c2 08 00             	ret    0x8
  807a4d:	8b 8d f0 ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1010]
  807a53:	51                   	push   ecx
  807a54:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a5a:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a5d:	5f                   	pop    edi
  807a5e:	5e                   	pop    esi
  807a5f:	33 cd                	xor    ecx,ebp
  807a61:	33 c0                	xor    eax,eax
  807a63:	5b                   	pop    ebx
  807a64:	e8 98 95 08 00       	call   0x891001
  807a69:	8b e5                	mov    esp,ebp
  807a6b:	5d                   	pop    ebp
  807a6c:	c2 08 00             	ret    0x8
  807a6f:	cc                   	int3
  807a70:	55                   	push   ebp
  807a71:	8b ec                	mov    ebp,esp
  807a73:	83 ec 08             	sub    esp,0x8
  807a76:	53                   	push   ebx
  807a77:	56                   	push   esi
  807a78:	8b 37                	mov    esi,DWORD PTR [edi]
  807a7a:	56                   	push   esi
  807a7b:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  807a7e:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2 08 00             	ret    0x8
  807b19:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  807b1c:	52                   	push   edx
  807b1d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b23:	5e                   	pop    esi
  807b24:	33 c0                	xor    eax,eax
  807b26:	5b                   	pop    ebx
  807b27:	8b e5                	mov    esp,ebp
  807b29:	5d                   	pop    ebp
  807b2a:	c2 08 00             	ret    0x8
  807b2d:	56                   	push   esi
  807b2e:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b34:	5e                   	pop    esi
  807b35:	33 c0                	xor    eax,eax
  807b37:	5b                   	pop    ebx
  807b38:	8b e5                	mov    esp,ebp
  807b3a:	5d                   	pop    ebp
  807b3b:	c2 08 00             	ret    0x8
  807b3e:	cc                   	int3
  807b3f:	cc                   	int3
```

### C. 進站 frame parser `0x807B40–0x807E50`

入站 marker/classification、校驗、壓縮 branch 與 node/queue 投遞。

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
```

### D. Conn 構造／初始化 `0x805950–0x806070`

包含 0x805D02 A02C=2，亦含 pool reuse 分支上下文。

```asm
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
  805a7e:	cc                   	int3
  805a7f:	cc                   	int3
  805a80:	55                   	push   ebp
  805a81:	8b ec                	mov    ebp,esp
  805a83:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  805a86:	8b 01                	mov    eax,DWORD PTR [ecx]
  805a88:	56                   	push   esi
  805a89:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a8c:	3b c1                	cmp    eax,ecx
  805a8e:	74 0b                	je     0x805a9b
  805a90:	39 70 08             	cmp    DWORD PTR [eax+0x8],esi
  805a93:	74 48                	je     0x805add
  805a95:	8b 00                	mov    eax,DWORD PTR [eax]
  805a97:	3b c1                	cmp    eax,ecx
  805a99:	75 f5                	jne    0x805a90
  805a9b:	ff 15 d4 22 bd 00    	call   DWORD PTR ds:0xbd22d4
  805aa1:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  805aa7:	8b 77 28             	mov    esi,DWORD PTR [edi+0x28]
  805aaa:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  805aad:	8d 45 08             	lea    eax,[ebp+0x8]
  805ab0:	50                   	push   eax
  805ab1:	51                   	push   ecx
  805ab2:	56                   	push   esi
  805ab3:	e8 48 7c f4 ff       	call   0x74d700
  805ab8:	8b 4f 2c             	mov    ecx,DWORD PTR [edi+0x2c]
  805abb:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  805ac0:	2b d1                	sub    edx,ecx
  805ac2:	83 fa 01             	cmp    edx,0x1
  805ac5:	73 0a                	jae    0x805ad1
  805ac7:	68 34 20 bf 00       	push   0xbf2034
  805acc:	e8 5f 80 07 00       	call   0x87db30
  805ad1:	41                   	inc    ecx
  805ad2:	89 4f 2c             	mov    DWORD PTR [edi+0x2c],ecx
  805ad5:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805ad8:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  805adb:	89 01                	mov    DWORD PTR [ecx],eax
  805add:	5e                   	pop    esi
  805ade:	5d                   	pop    ebp
  805adf:	c2 04 00             	ret    0x4
  805ae2:	cc                   	int3
  805ae3:	cc                   	int3
  805ae4:	cc                   	int3
  805ae5:	cc                   	int3
  805ae6:	cc                   	int3
  805ae7:	cc                   	int3
  805ae8:	cc                   	int3
  805ae9:	cc                   	int3
  805aea:	cc                   	int3
  805aeb:	cc                   	int3
  805aec:	cc                   	int3
  805aed:	cc                   	int3
  805aee:	cc                   	int3
  805aef:	cc                   	int3
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
  805c93:	cc                   	int3
  805c94:	cc                   	int3
  805c95:	cc                   	int3
  805c96:	cc                   	int3
  805c97:	cc                   	int3
  805c98:	cc                   	int3
  805c99:	cc                   	int3
  805c9a:	cc                   	int3
  805c9b:	cc                   	int3
  805c9c:	cc                   	int3
  805c9d:	cc                   	int3
  805c9e:	cc                   	int3
  805c9f:	cc                   	int3
  805ca0:	55                   	push   ebp
  805ca1:	8b ec                	mov    ebp,esp
  805ca3:	6a ff                	push   0xffffffff
  805ca5:	68 dc 99 90 00       	push   0x9099dc
  805caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805cb0:	50                   	push   eax
  805cb1:	83 ec 10             	sub    esp,0x10
  805cb4:	53                   	push   ebx
  805cb5:	56                   	push   esi
  805cb6:	57                   	push   edi
  805cb7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  805cbc:	33 c5                	xor    eax,ebp
  805cbe:	50                   	push   eax
  805cbf:	8d 45 f4             	lea    eax,[ebp-0xc]
  805cc2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805cc8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805ccb:	8d 46 18             	lea    eax,[esi+0x18]
  805cce:	6a 18                	push   0x18
  805cd0:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805cd6:	e8 8d b5 08 00       	call   0x891268
  805cdb:	8b f8                	mov    edi,eax
  805cdd:	33 db                	xor    ebx,ebx
  805cdf:	83 c4 04             	add    esp,0x4
  805ce2:	3b fb                	cmp    edi,ebx
  805ce4:	74 0e                	je     0x805cf4
  805ce6:	68 a0 0f 00 00       	push   0xfa0
  805ceb:	57                   	push   edi
  805cec:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805cf2:	eb 02                	jmp    0x805cf6
  805cf4:	33 ff                	xor    edi,edi
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805d1b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  805d1e:	89 9e 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],ebx
  805d24:	33 c0                	xor    eax,eax
  805d26:	89 86 30 a0 00 00    	mov    DWORD PTR [esi+0xa030],eax
  805d2c:	89 86 34 a0 00 00    	mov    DWORD PTR [esi+0xa034],eax
  805d32:	89 86 38 a0 00 00    	mov    DWORD PTR [esi+0xa038],eax
  805d38:	89 86 3c a0 00 00    	mov    DWORD PTR [esi+0xa03c],eax
  805d3e:	89 86 40 a0 00 00    	mov    DWORD PTR [esi+0xa040],eax
  805d44:	89 9e 48 a0 00 00    	mov    DWORD PTR [esi+0xa048],ebx
  805d4a:	89 9e 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],ebx
  805d50:	89 86 50 a0 00 00    	mov    DWORD PTR [esi+0xa050],eax
  805d56:	89 86 54 a0 00 00    	mov    DWORD PTR [esi+0xa054],eax
  805d5c:	89 86 58 a0 00 00    	mov    DWORD PTR [esi+0xa058],eax
  805d62:	89 86 5c a0 00 00    	mov    DWORD PTR [esi+0xa05c],eax
  805d68:	89 86 60 a0 00 00    	mov    DWORD PTR [esi+0xa060],eax
  805d6e:	89 9e 68 a0 00 00    	mov    DWORD PTR [esi+0xa068],ebx
  805d74:	6a 0c                	push   0xc
  805d76:	89 9e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ebx
  805d7c:	e8 e7 b4 08 00       	call   0x891268
  805d81:	83 c4 04             	add    esp,0x4
  805d84:	3b c3                	cmp    eax,ebx
  805d86:	0f 84 b6 00 00 00    	je     0x805e42
  805d8c:	89 86 74 a0 00 00    	mov    DWORD PTR [esi+0xa074],eax
  805d92:	89 00                	mov    DWORD PTR [eax],eax
  805d94:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  805d9a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  805d9d:	33 c0                	xor    eax,eax
  805d9f:	b9 01 00 00 00       	mov    ecx,0x1
  805da4:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  805da7:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805dad:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805db3:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805db9:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805dbf:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805dc5:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805dcb:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805dd1:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805dd7:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805ddd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  805de3:	89 8e b4 a0 00 00    	mov    DWORD PTR [esi+0xa0b4],ecx
  805de9:	89 9e b8 a0 00 00    	mov    DWORD PTR [esi+0xa0b8],ebx
  805def:	6a 18                	push   0x18
  805df1:	89 9e bc a0 00 00    	mov    DWORD PTR [esi+0xa0bc],ebx
  805df7:	e8 6c b4 08 00       	call   0x891268
  805dfc:	8b f8                	mov    edi,eax
  805dfe:	83 c4 04             	add    esp,0x4
  805e01:	3b fb                	cmp    edi,ebx
  805e03:	74 0e                	je     0x805e13
  805e05:	68 a0 0f 00 00       	push   0xfa0
  805e0a:	57                   	push   edi
  805e0b:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805e11:	eb 02                	jmp    0x805e15
  805e13:	33 ff                	xor    edi,edi
  805e15:	89 be d4 a0 00 00    	mov    DWORD PTR [esi+0xa0d4],edi
  805e1b:	e8 30 01 00 00       	call   0x805f50
  805e20:	89 b6 6c a0 00 00    	mov    DWORD PTR [esi+0xa06c],esi
  805e26:	89 b6 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],esi
  805e2c:	8b c6                	mov    eax,esi
  805e2e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805e31:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805e38:	59                   	pop    ecx
  805e39:	5f                   	pop    edi
  805e3a:	5e                   	pop    esi
  805e3b:	5b                   	pop    ebx
  805e3c:	8b e5                	mov    esp,ebp
  805e3e:	5d                   	pop    ebp
  805e3f:	c2 04 00             	ret    0x4
  805e42:	8d 4d f0             	lea    ecx,[ebp-0x10]
  805e45:	51                   	push   ecx
  805e46:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  805e49:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  805e4c:	e8 58 b2 08 00       	call   0x8910a9
  805e51:	68 a8 57 c8 00       	push   0xc857a8
  805e56:	8d 55 e4             	lea    edx,[ebp-0x1c]
  805e59:	52                   	push   edx
  805e5a:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  805e61:	e8 8a 6b 09 00       	call   0x89c9f0
  805e66:	cc                   	int3
  805e67:	cc                   	int3
  805e68:	cc                   	int3
  805e69:	cc                   	int3
  805e6a:	cc                   	int3
  805e6b:	cc                   	int3
  805e6c:	cc                   	int3
  805e6d:	cc                   	int3
  805e6e:	cc                   	int3
  805e6f:	cc                   	int3
  805e70:	55                   	push   ebp
  805e71:	8b ec                	mov    ebp,esp
  805e73:	6a ff                	push   0xffffffff
  805e75:	68 9c 99 90 00       	push   0x90999c
  805e7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  805e80:	50                   	push   eax
  805e81:	56                   	push   esi
  805e82:	57                   	push   edi
  805e83:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  805e88:	33 c5                	xor    eax,ebp
  805e8a:	50                   	push   eax
  805e8b:	8d 45 f4             	lea    eax,[ebp-0xc]
  805e8e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  805e94:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805e97:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  805e9e:	e8 ad 00 00 00       	call   0x805f50
  805ea3:	8b be d4 a0 00 00    	mov    edi,DWORD PTR [esi+0xa0d4]
  805ea9:	85 ff                	test   edi,edi
  805eab:	74 1a                	je     0x805ec7
  805ead:	57                   	push   edi
  805eae:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  805eb4:	57                   	push   edi
  805eb5:	e8 52 b3 08 00       	call   0x89120c
  805eba:	83 c4 04             	add    esp,0x4
  805ebd:	c7 86 d4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0d4],0x0
  805ec4:	00 00 00 
  805ec7:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  805ecd:	8b 01                	mov    eax,DWORD PTR [ecx]
  805ecf:	89 09                	mov    DWORD PTR [ecx],ecx
  805ed1:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  805ed7:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  805eda:	c7 86 78 a0 00 00 00 	mov    DWORD PTR [esi+0xa078],0x0
  805ee1:	00 00 00 
  805ee4:	3b 86 74 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa074]
  805eea:	74 19                	je     0x805f05
  805eec:	8d 64 24 00          	lea    esp,[esp+0x0]
  805ef0:	8b 38                	mov    edi,DWORD PTR [eax]
  805ef2:	50                   	push   eax
  805ef3:	e8 14 b3 08 00       	call   0x89120c
  805ef8:	83 c4 04             	add    esp,0x4
  805efb:	8b c7                	mov    eax,edi
  805efd:	3b be 74 a0 00 00    	cmp    edi,DWORD PTR [esi+0xa074]
  805f03:	75 eb                	jne    0x805ef0
  805f05:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  805f0b:	50                   	push   eax
  805f0c:	e8 fb b2 08 00       	call   0x89120c
  805f11:	8b be 1c 50 00 00    	mov    edi,DWORD PTR [esi+0x501c]
  805f17:	83 c4 04             	add    esp,0x4
  805f1a:	85 ff                	test   edi,edi
  805f1c:	74 1a                	je     0x805f38
  805f1e:	57                   	push   edi
  805f1f:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  805f25:	57                   	push   edi
  805f26:	e8 e1 b2 08 00       	call   0x89120c
  805f2b:	83 c4 04             	add    esp,0x4
  805f2e:	c7 86 1c 50 00 00 00 	mov    DWORD PTR [esi+0x501c],0x0
  805f35:	00 00 00 
  805f38:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805f3b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  805f42:	59                   	pop    ecx
  805f43:	5f                   	pop    edi
  805f44:	5e                   	pop    esi
  805f45:	8b e5                	mov    esp,ebp
  805f47:	5d                   	pop    ebp
  805f48:	c2 04 00             	ret    0x4
  805f4b:	cc                   	int3
  805f4c:	cc                   	int3
  805f4d:	cc                   	int3
  805f4e:	cc                   	int3
  805f4f:	cc                   	int3
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
  806051:	cc                   	int3
  806052:	cc                   	int3
  806053:	cc                   	int3
  806054:	cc                   	int3
  806055:	cc                   	int3
  806056:	cc                   	int3
  806057:	cc                   	int3
  806058:	cc                   	int3
  806059:	cc                   	int3
  80605a:	cc                   	int3
  80605b:	cc                   	int3
  80605c:	cc                   	int3
  80605d:	cc                   	int3
  80605e:	cc                   	int3
  80605f:	cc                   	int3
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd     	call   DWORD PTR ds:0xbd224c
```

### E. Conn reset `0x805F50–0x806100`

獨立已知 entry，其 body 不重寫 A02C。

```asm
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
  806051:	cc                   	int3
  806052:	cc                   	int3
  806053:	cc                   	int3
  806054:	cc                   	int3
  806055:	cc                   	int3
  806056:	cc                   	int3
  806057:	cc                   	int3
  806058:	cc                   	int3
  806059:	cc                   	int3
  80605a:	cc                   	int3
  80605b:	cc                   	int3
  80605c:	cc                   	int3
  80605d:	cc                   	int3
  80605e:	cc                   	int3
  80605f:	cc                   	int3
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806071:	8b be 74 a0 00 00    	mov    edi,DWORD PTR [esi+0xa074]
  806077:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  80607a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  80607d:	51                   	push   ecx
  80607e:	52                   	push   edx
  80607f:	57                   	push   edi
  806080:	e8 7b 76 f4 ff       	call   0x74d700
  806085:	8b 8e 78 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa078]
  80608b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  806090:	2b d1                	sub    edx,ecx
  806092:	83 fa 01             	cmp    edx,0x1
  806095:	73 0a                	jae    0x8060a1
  806097:	68 34 20 bf 00       	push   0xbf2034
  80609c:	e8 8f 7a 07 00       	call   0x87db30
  8060a1:	41                   	inc    ecx
  8060a2:	89 8e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ecx
  8060a8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  8060ab:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8060ae:	89 01                	mov    DWORD PTR [ecx],eax
  8060b0:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8060b6:	52                   	push   edx
  8060b7:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8060bd:	c6 86 24 a0 00 00 01 	mov    BYTE PTR [esi+0xa024],0x1
  8060c4:	b8 01 00 00 00       	mov    eax,0x1
  8060c9:	5f                   	pop    edi
  8060ca:	5d                   	pop    ebp
  8060cb:	c2 04 00             	ret    0x4
  8060ce:	cc                   	int3
  8060cf:	cc                   	int3
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00  	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	   
```

### F. key0 初始 local payload queue `0x4958D0–0x495980`

第一行 0x4958D0 為截取於前一指令尾部的 raw decodable noise，**不得引用該行為證據**；有效 code 0x4958D1 起，0x495935 push 0x39。

```asm
004958d0 <.data+0x948d0>:
  4958d0:	c6                   	(bad)
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
  49597e:	8b 0d        	mov    ecx,DWORD PTR ds:0xfba854
```

### G. key1 caller 6D6508/send 0x38

本地 0x38 queue 在 manager vtable+0x10，非 wire。

```asm
006d64f0 <.data+0x2d54f0>:
  6d64f0:	5d                   	pop    ebp
  6d64f1:	c2 08 00             	ret    0x8
  6d64f4:	83 c0 0c             	add    eax,0xc
  6d64f7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d64fb:	72 02                	jb     0x6d64ff
  6d64fd:	8b 00                	mov    eax,DWORD PTR [eax]
  6d64ff:	6a 01                	push   0x1
  6d6501:	50                   	push   eax
  6d6502:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d6507:	50                   	push   eax
  6d6508:	e8 03 f1 db ff       	call   0x495610
  6d650d:	85 c0                	test   eax,eax
  6d650f:	74 cf                	je     0x6d64e0
  6d6511:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6d6514:	8b d6                	mov    edx,esi
  6d6516:	57                   	push   edi
  6d6517:	8d 74 24 08          	lea    esi,[esp+0x8]
  6d651b:	e8 50 06 00 00       	call   0x6d6b70
  6d6520:	e8 7b e6 d2 ff       	call   0x404ba0
  6d6525:	8a 88 98 68 00 00    	mov    cl,BYTE PTR [eax+0x6898]
  6d652b:	88 4c 24 32          	mov    BYTE PTR [esp+0x32],cl
  6d652f:	e8 6c e6 d2 ff       	call   0x404ba0
  6d6534:	05 99 68 00 00       	add    eax,0x6899
  6d6539:	50                   	push   eax
  6d653a:	8d 54 24 37          	lea    edx,[esp+0x37]
  6d653e:	6a 05                	push   0x5
  6d6540:	52                   	push   edx
  6d6541:	e8 13 d6 1b 00       	call   0x893b59
  6d6546:	83 c4 0c             	add    esp,0xc
  6d6549:	e8 52 e6 d2 ff       	call   0x404ba0
  6d654e:	8b 80 a0 68 00 00    	mov    eax,DWORD PTR [eax+0x68a0]
  6d6554:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d655a:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  6d655e:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d6560:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6563:	6a 38                	push   0x38
  6d6565:	8b c6                	mov    eax,esi
  6d6567:	50                   	push   eax
  6d6568:	6a 01                	push   0x1
  6d656a:	ff d2                	call   edx
  6d656c:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  6d6570:	5e                   	pop    esi
  6d6571:	33 cc                	xor    ecx,esp
  6d6573:	b8 01 00 00 00       	mov    eax,0x1
  6d6578:	e8 84 aa 1b 00       	call   0x891001
  6d657d:	8b e5                	mov    esp,ebp
  6d657f:	5d                   	pop    ebp
  6d6580:	c2 08 00             	ret    0x8
  6d6583:	cc                   	int3
  6d6584:	cc                   	int3
```

### H. key1 caller 6D65C8/send 0x68

本地 0x68 queue 在 manager vtable+0x10，非 wire。

```asm
006d65a0 <.data+0x2d55a0>:
  6d65a0:	89 44 24 78          	mov    DWORD PTR [esp+0x78],eax
  6d65a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d65a7:	8b 00                	mov    eax,DWORD PTR [eax]
  6d65a9:	56                   	push   esi
  6d65aa:	8b f1                	mov    esi,ecx
  6d65ac:	85 c0                	test   eax,eax
  6d65ae:	0f 84 85 00 00 00    	je     0x6d6639
  6d65b4:	83 c0 0c             	add    eax,0xc
  6d65b7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d65bb:	72 02                	jb     0x6d65bf
  6d65bd:	8b 00                	mov    eax,DWORD PTR [eax]
  6d65bf:	6a 00                	push   0x0
  6d65c1:	50                   	push   eax
  6d65c2:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d65c7:	50                   	push   eax
  6d65c8:	e8 43 f0 db ff       	call   0x495610
  6d65cd:	85 c0                	test   eax,eax
  6d65cf:	75 7c                	jne    0x6d664d
  6d65d1:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d65d7:	68 c4 0a c4 00       	push   0xc40ac4
  6d65dc:	83 c2 08             	add    edx,0x8
  6d65df:	e8 1c 87 00 00       	call   0x6ded00
  6d65e4:	83 c4 04             	add    esp,0x4
  6d65e7:	c7 44 24 0c 81 01 00 	mov    DWORD PTR [esp+0xc],0x181
  6d65ee:	00 
  6d65ef:	e8 bc ee ea ff       	call   0x5854b0
  6d65f4:	8b f0                	mov    esi,eax
  6d65f6:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  6d65fa:	51                   	push   ecx
  6d65fb:	8d 44 24 0c          	lea    eax,[esp+0xc]
  6d65ff:	8b ce                	mov    ecx,esi
  6d6601:	e8 ea da e9 ff       	call   0x5740f0
  6d6606:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  6d660a:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d660d:	74 0d                	je     0x6d661c
  6d660f:	83 c0 10             	add    eax,0x10
  6d6612:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d6616:	72 0a                	jb     0x6d6622
  6d6618:	8b 00                	mov    eax,DWORD PTR [eax]
  6d661a:	eb 06                	jmp    0x6d6622
  6d661c:	cc                   	int3
  6d661d:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d6622:	6a 00                	push   0x0
  6d6624:	6a 00                	push   0x0
  6d6626:	68 fc d1 be 00       	push   0xbed1fc
  6d662b:	50                   	push   eax
  6d662c:	68 ca 00 00 00       	push   0xca
  6d6631:	e8 da e4 d2 ff       	call   0x404b10
  6d6636:	83 c4 14             	add    esp,0x14
  6d6639:	33 c0                	xor    eax,eax
  6d663b:	5e                   	pop    esi
  6d663c:	8b 4c 24 78          	mov    ecx,DWORD PTR [esp+0x78]
  6d6640:	33 cc                	xor    ecx,esp
  6d6642:	e8 ba a9 1b 00       	call   0x891001
  6d6647:	8b e5                	mov    esp,ebp
  6d6649:	5d                   	pop    ebp
  6d664a:	c2 04 00             	ret    0x4
  6d664d:	6a 66                	push   0x66
  6d664f:	8d 44 24 16          	lea    eax,[esp+0x16]
  6d6653:	ba e1 00 00 00       	mov    edx,0xe1
  6d6658:	6a 00                	push   0x0
  6d665a:	50                   	push   eax
  6d665b:	66 89 54 24 1c       	mov    WORD PTR [esp+0x1c],dx
  6d6660:	e8 fb 81 1c 00       	call   0x89e860
  6d6665:	83 c4 0c             	add    esp,0xc
  6d6668:	56                   	push   esi
  6d6669:	8d 4c 24 16          	lea    ecx,[esp+0x16]
  6d666d:	6a 33                	push   0x33
  6d666f:	51                   	push   ecx
  6d6670:	e8 d8 c7 1b 00       	call   0x892e4d
  6d6675:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d667b:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d667d:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6680:	83 c4 0c             	add    esp,0xc
  6d6683:	6a 68                	push   0x68
  6d6685:	8d 44 24 14          	lea    eax,[esp+0x14]
  6d6689:	50                   	push   eax
  6d668a:	6a 01                	push   0x1
  6d668c:	ff d2                	call   edx
  6d668e:	8b 4c 24 7c          	mov    ecx,DWORD PTR [esp+0x7c]
  6d6692:	5e                   	pop    esi
  6d6693:	33 cc                	xor    ecx,esp
  6d6695:	b8 01 00 00 00       	mov    eax,0x1
  6d669a:	e8 62 a9 1b 00       	call   0x891001
  6d669f:	8b e5                	mov    esp,ebp
  6d66a1:	5d                   	pop    ebp
  6d66a2:	c2 04 00             	ret    0x4
  6d66a5:	cc                   	int3
  6d66a6:	cc                   	int3
  6d66a7:	cc                   	int3
  6d66a8:	cc                   	int3
  6d66a9:	cc                   	int3
  6d66aa:	cc                   	int3
  6d66ab:	cc                   	int3
  6d66ac:	cc                   	int3
  6d66ad:	cc                   	int3
  6d66ae:	cc                   	int3
  6d66af:	cc                   	int3
```

### I. key1 caller 6D670C/send 0x2CE

本地 0x2CE queue 在 manager vtable+0x10，非 wire。

```asm
006d66e0 <.data+0x2d56e0>:
  6d66e0:	08 8b 00 8b 7d 0c    	or     BYTE PTR [ebx+0xc7d8b00],cl
  6d66e6:	33 db                	xor    ebx,ebx
  6d66e8:	8b f2                	mov    esi,edx
  6d66ea:	89 8d c8 fc ff ff    	mov    DWORD PTR [ebp-0x338],ecx
  6d66f0:	3b c3                	cmp    eax,ebx
  6d66f2:	0f 84 8b 00 00 00    	je     0x6d6783
  6d66f8:	83 c0 0c             	add    eax,0xc
  6d66fb:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d66ff:	72 02                	jb     0x6d6703
  6d6701:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6703:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d6709:	53                   	push   ebx
  6d670a:	50                   	push   eax
  6d670b:	52                   	push   edx
  6d670c:	e8 ff ee db ff       	call   0x495610
  6d6711:	85 c0                	test   eax,eax
  6d6713:	75 75                	jne    0x6d678a
  6d6715:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d671b:	68 c4 0a c4 00       	push   0xc40ac4
  6d6720:	83 c2 08             	add    edx,0x8
  6d6723:	e8 d8 85 00 00       	call   0x6ded00
  6d6728:	83 c4 04             	add    esp,0x4
  6d672b:	c7 85 c4 fc ff ff 81 	mov    DWORD PTR [ebp-0x33c],0x181
  6d6732:	01 00 00 
  6d6735:	e8 76 ed ea ff       	call   0x5854b0
  6d673a:	8b f0                	mov    esi,eax
  6d673c:	8d 85 c4 fc ff ff    	lea    eax,[ebp-0x33c]
  6d6742:	50                   	push   eax
  6d6743:	8d 85 c8 fc ff ff    	lea    eax,[ebp-0x338]
  6d6749:	8b ce                	mov    ecx,esi
  6d674b:	e8 a0 d9 e9 ff       	call   0x5740f0
  6d6750:	8b 85 c8 fc ff ff    	mov    eax,DWORD PTR [ebp-0x338]
  6d6756:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d6759:	74 0d                	je     0x6d6768
  6d675b:	83 c0 10             	add    eax,0x10
  6d675e:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d6762:	72 0a                	jb     0x6d676e
  6d6764:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6766:	eb 06                	jmp    0x6d676e
  6d6768:	cc                   	int3
  6d6769:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d676e:	53                   	push   ebx
  6d676f:	53                   	push   ebx
  6d6770:	68 fc d1 be 00       	push   0xbed1fc
  6d6775:	50                   	push   eax
  6d6776:	68 ca 00 00 00       	push   0xca
  6d677b:	e8 90 e3 d2 ff       	call   0x404b10
  6d6780:	83 c4 14             	add    esp,0x14
  6d6783:	33 c0                	xor    eax,eax
  6d6785:	e9 5f 01 00 00       	jmp    0x6d68e9
  6d678a:	68 00 02 00 00       	push   0x200
  6d678f:	8d 95 ce fc ff ff    	lea    edx,[ebp-0x332]
  6d6795:	b9 e2 00 00 00       	mov    ecx,0xe2
  6d679a:	53                   	push   ebx
  6d679b:	52                   	push   edx
  6d679c:	66 89 8d cc fc ff ff 	mov    WORD PTR [ebp-0x334],cx
  6d67a3:	e8 b8 80 1c 00       	call   0x89e860
  6d67a8:	6a 66                	push   0x66
  6d67aa:	8d 85 ce fe ff ff    	lea    eax,[ebp-0x132]
  6d67b0:	53                   	push   ebx
  6d67b1:	50                   	push   eax
  6d67b2:	e8 a9 80 1c 00       	call   0x89e860
  6d67b7:	6a 66                	push   0x66
  6d67b9:	8d 8d 34 ff ff ff    	lea    ecx,[ebp-0xcc]
  6d67bf:	53                   	push   ebx
  6d67c0:	51                   	push   ecx
  6d67c1:	e8 9a 80 1c 00       	call   0x89e860
  6d67c6:	56                   	push   esi
  6d67c7:	8d 95 ce fe ff ff    	lea    edx,[ebp-0x132]
  6d67cd:	6a 33                	push   0x33
  6d67cf:	52                   	push   edx
  6d67d0:	e8 78 c6 1b 00       	call   0x892e4d
  6d67d5:	57                   	push   edi
  6d67d6:	8d 7d 9c             	lea    edi,[ebp-0x64]
  6d67d9:	e8 62 8d da ff       	call   0x47f540
  6d67de:	83 c4 34             	add    esp,0x34
  6d67e1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d67e4:	be 0f 00 00 00       	mov    esi,0xf
  6d67e9:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  6d67ec:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  6d67ef:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  6d67f2:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  6d67f6:	83 7d b0 10          	cmp    DWORD PTR [ebp-0x50],0x10
  6d67fa:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  6d67fd:	73 02                	jae    0x6d6801
  6d67ff:	8b cf                	mov    ecx,edi
  6d6801:	8b 45 ac             	mov    eax,DWORD PTR [ebp-0x54]
  6d6804:	50                   	push   eax
  6d6805:	8d 7d d4             	lea    edi,[ebp-0x2c]
  6d6808:	e8 c3 d5 05 00       	call   0x733dd0
  6d680d:	83 ec 18             	sub    esp,0x18
  6d6810:	8b cc                	mov    ecx,esp
  6d6812:	89 a5 c4 fc ff ff    	mov    DWORD PTR [ebp-0x33c],esp
  6d6818:	6a ff                	push   0xffffffff
  6d681a:	53                   	push   ebx
  6d681b:	8b d7                	mov    edx,edi
  6d681d:	89 71 14             	mov    DWORD PTR [ecx+0x14],esi
  6d6820:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  6d6823:	52                   	push   edx
  6d6824:	88 19                	mov    BYTE PTR [ecx],bl
  6d6826:	e8 15 c8 d2 ff       	call   0x403040
  6d682b:	8d 4d b8             	lea    ecx,[ebp-0x48]
  6d682e:	e8 8d 7b d9 ff       	call   0x46e3c0
  6d6833:	83 c4 1c             	add    esp,0x1c
  6d6836:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6d683a:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  6d683d:	be 08 00 00 00       	mov    esi,0x8
  6d6842:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  6d6845:	73 03                	jae    0x6d684a
  6d6847:	8d 45 b8             	lea    eax,[ebp-0x48]
  6d684a:	50                   	push   eax
  6d684b:	8d 85 34 ff ff ff    	lea    eax,[ebp-0xcc]
  6d6851:	6a 33                	push   0x33
  6d6853:	50                   	push   eax
  6d6854:	e8 f4 c5 1b 00       	call   0x892e4d
  6d6859:	8b 8d c8 fc ff ff    	mov    ecx,DWORD PTR [ebp-0x338]
  6d685f:	51                   	push   ecx
  6d6860:	8d 95 ce fc ff ff    	lea    edx,[ebp-0x332]
  6d6866:	68 00 01 00 00       	push   0x100
  6d686b:	52                   	push   edx
  6d686c:	e8 dc c5 1b 00       	call   0x892e4d
  6d6871:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d6877:	8b 01                	mov    eax,DWORD PTR [ecx]
  6d6879:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  6d687c:	83 c4 18             	add    esp,0x18
  6d687f:	68 ce 02 00 00       	push   0x2ce
  6d6884:	8d 95 cc fc ff ff    	lea    edx,[ebp-0x334]
  6d688a:	52                   	push   edx
  6d688b:	6a 01                	push   0x1
  6d688d:	ff d0                	call   eax
  6d688f:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  6d6892:	72 0c                	jb     0x6d68a0
  6d6894:	8b 4d b8             	mov    ecx,DWORD PTR [ebp-0x48]
  6d6897:	51                   	push   ecx
  6d6898:	e8 6f a9 1b 00       	call   0x89120c
  6d689d:	83 c4 04             	add    esp,0x4
```

### J. 主要 send pump `0x804A40–0x804B50`

Pool 陣列+Conn alive gate 再呼叫 8061A0。

```asm
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
```

### K. 補充 send pump `0x8051B0–0x805310`

直接另一個 `0x805228` caller 的局部上下文。

```asm
008051b0 <.data+0x4041b0>:
  8051b0:	00 00                	add    BYTE PTR [eax],al
  8051b2:	56                   	push   esi
  8051b3:	57                   	push   edi
  8051b4:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  8051b7:	6a ff                	push   0xffffffff
  8051b9:	51                   	push   ecx
  8051ba:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  8051c0:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  8051c3:	83 ba a4 00 00 00 00 	cmp    DWORD PTR [edx+0xa4],0x0
  8051ca:	0f 84 03 02 00 00    	je     0x8053d3
  8051d0:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  8051d7:	75 15                	jne    0x8051ee
  8051d9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8051e0:	74 07                	je     0x8051e9
  8051e2:	e8 79 5d c9 ff       	call   0x49af60
  8051e7:	eb 05                	jmp    0x8051ee
  8051e9:	e8 12 5e c9 ff       	call   0x49b000
  8051ee:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  8051f4:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  8051f7:	2b 01                	sub    eax,DWORD PTR [ecx]
  8051f9:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  8051fc:	c1 f8 02             	sar    eax,0x2
  8051ff:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  805202:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805205:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  805208:	3b f8                	cmp    edi,eax
  80520a:	0f 83 a9 01 00 00    	jae    0x8053b9
  805210:	eb 03                	jmp    0x805215
  805212:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805215:	8b 09                	mov    ecx,DWORD PTR [ecx]
  805217:	8b 34 b9             	mov    esi,DWORD PTR [ecx+edi*4]
  80521a:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  805221:	0f 84 85 01 00 00    	je     0x8053ac
  805227:	56                   	push   esi
  805228:	e8 73 0f 00 00       	call   0x8061a0
  80522d:	85 c0                	test   eax,eax
  80522f:	74 28                	je     0x805259
  805231:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  805237:	ff 86 94 a0 00 00    	inc    DWORD PTR [esi+0xa094]
  80523d:	83 f8 05             	cmp    eax,0x5
  805240:	73 0c                	jae    0x80524e
  805242:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  805249:	00 00 00 
  80524c:	eb 1e                	jmp    0x80526c
  80524e:	83 c0 fb             	add    eax,0xfffffffb
  805251:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  805257:	eb 13                	jmp    0x80526c
  805259:	80 7b 10 00          	cmp    BYTE PTR [ebx+0x10],0x0
  80525d:	74 0d                	je     0x80526c
  80525f:	ff 86 84 a0 00 00    	inc    DWORD PTR [esi+0xa084]
  805265:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  80526c:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  805273:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  80527a:	0f 84 29 01 00 00    	je     0x8053a9
  805280:	8b 96 b8 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0b8]
  805286:	85 d2                	test   edx,edx
  805288:	0f 8f 1b 01 00 00    	jg     0x8053a9
  80528e:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  805294:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  80529a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80529c:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  80529f:	8d 7d f4             	lea    edi,[ebp-0xc]
  8052a2:	57                   	push   edi
  8052a3:	50                   	push   eax
  8052a4:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  8052aa:	50                   	push   eax
  8052ab:	56                   	push   esi
  8052ac:	ff d2                	call   edx
  8052ae:	85 c0                	test   eax,eax
  8052b0:	75 20                	jne    0x8052d2
  8052b2:	56                   	push   esi
  8052b3:	e8 28 11 00 00       	call   0x8063e0
  8052b8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052be:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052c0:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052c3:	6a 00                	push   0x0
  8052c5:	56                   	push   esi
  8052c6:	ff d2                	call   edx
  8052c8:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052cf:	00 00 00 
  8052d2:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  8052d9:	74 1a                	je     0x8052f5
  8052db:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052e1:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052e3:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052e6:	6a 00                	push   0x0
  8052e8:	56                   	push   esi
  8052e9:	ff d2                	call   edx
  8052eb:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052f2:	00 00 00 
  8052f5:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  8052fc:	01 00 00 
  8052ff:	0f 8e a1 00 00 00    	jle    0x8053a6
  805305:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  80530c:	0f 85 94 00      	jne    0x8053a6
```

### L. manager sendbykey/recvpost `0x8069A0–0x806B20`

vtable+0x10/+0x14 服務，用途與當前 caller 交叉查。

```asm
008069a0 <.data+0x4059a0>:
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2 0c 00             	ret    0xc
  8069f6:	cc                   	int3
  8069f7:	cc                   	int3
  8069f8:	cc                   	int3
  8069f9:	cc                   	int3
  8069fa:	cc                   	int3
  8069fb:	cc                   	int3
  8069fc:	cc                   	int3
  8069fd:	cc                   	int3
  8069fe:	cc                   	int3
  8069ff:	cc                   	int3
  806a00:	55                   	push   ebp
  806a01:	8b ec                	mov    ebp,esp
  806a03:	51                   	push   ecx
  806a04:	53                   	push   ebx
  806a05:	56                   	push   esi
  806a06:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806a09:	57                   	push   edi
  806a0a:	8d 86 30 a0 00 00    	lea    eax,[esi+0xa030]
  806a10:	8b f9                	mov    edi,ecx
  806a12:	33 c9                	xor    ecx,ecx
  806a14:	89 08                	mov    DWORD PTR [eax],ecx
  806a16:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  806a19:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  806a1c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  806a1f:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  806a22:	8b 8e 18 50 00 00    	mov    ecx,DWORD PTR [esi+0x5018]
  806a28:	6a 00                	push   0x0
  806a2a:	50                   	push   eax
  806a2b:	89 48 18             	mov    DWORD PTR [eax+0x18],ecx
  806a2e:	8d 48 14             	lea    ecx,[eax+0x14]
  806a31:	8d 45 fc             	lea    eax,[ebp-0x4]
  806a34:	50                   	push   eax
  806a35:	8d 45 08             	lea    eax,[ebp+0x8]
  806a38:	50                   	push   eax
  806a39:	6a 01                	push   0x1
  806a3b:	c7 01 00 10 00 00    	mov    DWORD PTR [ecx],0x1000
  806a41:	8b 16                	mov    edx,DWORD PTR [esi]
  806a43:	51                   	push   ecx
  806a44:	52                   	push   edx
  806a45:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806a4c:	ff 15 bc 25 bd 00    	call   DWORD PTR ds:0xbd25bc
  806a52:	83 f8 ff             	cmp    eax,0xffffffff
  806a55:	75 54                	jne    0x806aab
  806a57:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806a5d:	8b d8                	mov    ebx,eax
  806a5f:	81 fb e5 03 00 00    	cmp    ebx,0x3e5
  806a65:	74 44                	je     0x806aab
  806a67:	8b 17                	mov    edx,DWORD PTR [edi]
  806a69:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806a6c:	6a 00                	push   0x0
  806a6e:	56                   	push   esi
  806a6f:	8b cf                	mov    ecx,edi
  806a71:	ff d0                	call   eax
  806a73:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	00 00 00 
  806a7d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806a81:	74 1d                	je     0x806aa0
  806a83:	8b 36                	mov    esi,DWORD PTR [esi]
  806a85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806a8b:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806a8e:	50                   	push   eax
  806a8f:	53                   	push   ebx
  806a90:	56                   	push   esi
  806a91:	68 58 16 c5 00       	push   0xc51658
  806a96:	6a 02                	push   0x2
  806a98:	e8 63 99 ee ff       	call   0x6f0400
  806a9d:	83 c4 14             	add    esp,0x14
  806aa0:	5f                   	pop    edi
  806aa1:	5e                   	pop    esi
  806aa2:	33 c0                	xor    eax,eax
  806aa4:	5b                   	pop    ebx
  806aa5:	8b e5                	mov    esp,ebp
  806aa7:	5d                   	pop    ebp
  806aa8:	c2 04 00             	ret    0x4
  806aab:	e8 00 fb ff ff       	call   0x8065b0
  806ab0:	83 f8 01             	cmp    eax,0x1
  806ab3:	75 0c                	jne    0x806ac1
  806ab5:	8b 17                	mov    edx,DWORD PTR [edi]
  806ab7:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806aba:	6a 00                	push   0x0
  806abc:	56                   	push   esi
  806abd:	8b cf                	mov    ecx,edi
  806abf:	ff d0                	call   eax
  806ac1:	5f                   	pop    edi
  806ac2:	5e                   	pop    esi
  806ac3:	b8 01 00 00 00       	mov    eax,0x1
  806ac8:	5b                   	pop    ebx
  806ac9:	8b e5                	mov    esp,ebp
  806acb:	5d                   	pop    ebp
  806acc:	c2 04 00             	ret    0x4
  806acf:	cc                   	int3
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
  806b1f:	0f         	je     0x806cd7
```

### M. key1/key0/key2 建連 helpers `0x495610–0x4959E0`

不同 key0/1/2 與 NULL/error 分支、slot，來源 E56 對照。

```asm
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
  4957ba:	cc                   	int3
  4957bb:	cc                   	int3
  4957bc:	cc                   	int3
  4957bd:	cc                   	int3
  4957be:	cc                   	int3
  4957bf:	cc                   	int3
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
```

### N. lane2 application dispatch `0x4930E0–0x493190`

該入口有自身 gate，不能直接從收到 marker 推出業務結果。

```asm
004930e0 <.data+0x920e0>:
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10 00             	ret    0x10
  493161:	cc                   	int3
  493162:	cc                   	int3
  493163:	cc                   	int3
  493164:	cc                   	int3
  493165:	cc                   	int3
  493166:	cc                   	int3
  493167:	cc                   	int3
  493168:	cc                   	int3
  493169:	cc                   	int3
  49316a:	cc                   	int3
  49316b:	cc                   	int3
  49316c:	cc                   	int3
  49316d:	cc                   	int3
  49316e:	cc                   	int3
  49316f:	cc                   	int3
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
```

