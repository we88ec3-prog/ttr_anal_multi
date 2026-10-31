# E85 — C04-E2b：KR 登入 C2S Transport／Frame 原生契約；RR-0001／0004／0006／0007 跨 RR 有界補證

> 2026-11-01（Asia/Taipei）；研究者 chatgpt-web roy；T02，原始 KR Client；本稿是 **C04-KR-FIRST-WIRE-EVIDENCE** 的原生 Client 靜態研究交付，不是 Runtime Client-in-loop、原版 Server packet capture、T01 FULL-PASS、RR ACCEPTED 或 S00 的 `NativeContractAdmission` 啟用授權。沿用既有 T02 工作分支，不另開 branch。S00 最新基準見 GitHub `governance/s00-iterations/S00-20261101-C04-NATIVE-LOGIN-EXECUTION-READY-HANDOFF.md` 第 40～46、74～84 行及 Iteration40 C04-E2b。

## 0. 正式目標、第一手來源、身分與舊研究去重

- GitHub 起始 `main=f9913c4da0e4afaa3a6f8aca9a5d69919912eb5c`；RR-0001／0004／0006／0007 主責均 T02、`IN_REVIEW`；既有原稿 E57（首幀）、E58（A02C）、E59（接收 parser／錯誤）、E60（命令→場景）、E84（外層路由）皆已提交。不回退 RR、不覆寫其提交或 T01 部分驗收。T02 README 於本次基準無新的「NEEDS_FIX」專區；其固定主責為 Transport／Frame／Dispatch，不負責登入密碼政策。共用 FULL-PASS 庫未包含能把本篇整份認證為 FULL-PASS 的結論。
- 原始唯讀 `Tartaros.bin`：**12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**。KR PE32 x86 ImageBase `0x400000`；`.text` VA `0x401000`、file raw `0x400`、VirtualSize `0x7D01F0`、SizeOfRawData `0x7D0200`；raw offset for executable `.text` VA `A`: `A−0x400C00`。`.rdata` VA `0xBD2000` raw `0x7D0600`，**不可**套 `.text` 位移。
- 定向第一手核對：`0x495610/0x4957C0/0x6D6300/0x6D64C0/0x440790/0x4A31B0/0x4A3360/0x8069A0/0x8060D0/0x8061A0/0x807830/0x807A70/0x804A40/0x805190/0x8068B0/0x806AD0/0x806CF0/0x807B40/0x4930E0`；對每一段只保證列出的 opcode／CFG 及關係。驗證腳本以第一手 bytes／PE section／vtable／合成 codec 檢查 **90 項 PASS**，合成測試不是 wire 或 live Client。更全面的 E57–E60 反組譯附錄及 T01 R0–R2 同時沿用，**不是**以新的 90 項抽樣自動升格整篇 FULL-PASS。
- T01 來源：`research/handoffs/t01-20261030-rr0001-rr0004-bounded-r2/README.md` 與 E60/SRC-0472 等；S00 `SPEC-NET-0001/0002/0003`、`SPEC-AUTH-0001` 與 S00 C04-E2b 是交付對象。原版 Server 內部規則**不是**本輪目標，Client 必須接收／送出的 bytes／slot 才是。

## 1. LOGIN Socket 的 source／address／slot／lane／初始化／前置條件

### 1.1 唯一已正向定位的 Login helper：`0x495610`（key1）

`0x495610(this=Client*, arg[0]=address, arg[1]=...)` 從呼叫者取 IP/host 文字，**不是此 helper 內硬編一個官方 IPv4**。`0x6D6350` 等多條上游的 `(arg[0] string)+0x0C` 使用 SSO-string 規則（長度 >=0x10 時解指標）再傳到 `0x495610`，以及 `0x6D64C0` 的 `0x6D64F4..0x6D6508`、`0x6D6590` 的 `0x6D65B4..0x6D65C8`。上游最終 DNS／Launcher／設定檔／文字控制來源仍**未**從全部 caller 閉合，不可聲稱官方固定 IP，亦不得任意將此指標當成伺服器可信 identity。

```asm
4956b8 39 7d 10             cmp [ebp+10],edi       ; 第三參數控制是否先 shutdown old keys
4956f7 6a 01                push 1                ; shutdown key0 branch
4956f9 57                   push edi
4956fa ff d2                call manager.v+20
495707 6a 01                push 1                ; shutdown key2 branch
495709 6a 02                push 2
49570b ff d2                call manager.v+20
49573b 39 bb 60 bf 00 00    cmp [ebx+BF60],edi   ; 既有 key1 Conn，無需一律新連
49574b 8b 55 0c             mov edx,[ebp+0c]     ; address（上游 string/host）
49574e 8b 40 18             mov eax,[eax+18]     ; NetworkManager::Connect virtual
495751 6a 02                push 2                ; lane=2
495753 6a 01                push 1                ; map key / slot=1
495755 68 df 20 00 00       push 0x20DF           ; 8415
49575a 52                   push edx              ; caller supplied host
49575b ff d0                call eax
49575d 8b f0                mov esi,eax
49575f 3b f7                cmp esi,edi           ; NULL => fail / return0
495781 8b 0d 54 a8 fb 00    mov ecx,[FBA854]
495789 8b 42 14             mov eax,[edx+14]     ; post WSARecv for new Conn
49578f 68 f4 01 00 00       push 0x1f4           ; Sleep(500) if new Conn
495794 89 b3 60 bf 00 00    mov [Client+BF60],esi
49579a ff 15 04 23 bd 00    call [Sleep]
```

既有 key1 pointer 在 `[Client+BF60]`，有的可達路徑在未重新 Connect 前便返回 1；若 `arg3` 非零先嘗試 key0/key2 old Conn 關閉。**不保證**每次進入函式都新建 Socket，不保證任何 OS TCP 三向交握成功，更不能把 Sleep(500) 定義成 Server 必須等待半秒。其餘選服後 key0、key2 分別為 port 8416、8414、lane2（`0x4957C0`），不是當前登入 slot；同一登入階段可能存在先前 key1/後來 key0/2 多 Socket，Server 需逐連線區分。

### 1.2 Manager Connect 與真實 socket 地址生成

`NetworkManager` 使用 `.rdata` **vtable `0xC51748`**。第一手 DWORD：

| vtable 偏移 | RVA/VA | 原生用途（有界） |
|---:|---|---|
| `+0x04` | `0x806CF0` | IOCP completion thread |
| `+0x0C` | `0x8068B0` | WSASend submit |
| `+0x10` | `0x8069A0` | 根據 map key 查 Conn，交 `0x8060D0` queue |
| `+0x14` | `0x806A00` | post WSARecv |
| `+0x18` | `0x806AD0` | 建立 Conn／socket／connect／map register |
| `+0x24` | `0x806FC0` | 有條件關閉 Conn |

`0x806AD0` 的可核引數：`[ebp+8]` hostname 地址、`[ebp+C]` port、`[ebp+10]` slot、`[ebp+14]` lane。`806B14` 取得 Pool Conn，`806B29` 設 `Conn+A0B4=2`，`806B25/806B33` 把 lane 寫 `Conn+A080`，`806B28 push address→806B39 call [BD25C0] (WS2_32 ordinal52)`，`806B54` 讀 port 並於 `806B65 call [BD25A8] (ordinal9)` 組 network-order port，`806B7C WSASocketA`，`806B8C call [BD25C4]` (= WS2_32 ordinal4 connect)，接著 setsockopt、`806C87` associate IOCP、map key `806C9E..806CD2`。`806B92` connect fail 跳 Pool 錯誤分支（舊 E56 另有局部 socket-cleanup 風險），不能把「Conn* 非 NULL」等同 remote greeting 已收到；此 function 的 socket map/recycle lifetime 由 E56 RR-0005 正式交叉引用。

**Server 必要**：若以未修改的相同 KR Client 連線，必須按 Client 實際 endpoint／Port 監聽；部署 IP/Port／DNS 指向方式由操作者配置，不可把舊 literal 8415 當作現代部署強制設定；版本、來源地址和 Client-in-loop 尚須另外驗證。

## 2. Auth Source → Manager Queue → Conn Frame → WSASend；不同層不得折疊

### 2.1 Auth producer（T03 RR-0003，T02 定向核 caller）

```asm
6D6321 c7 00 1c b0 bf 00      mov dword [eax],0xBFB01C ; 某物件的 vtable
6D6340 c7 40 08 52 00 00 00   mov dword [eax+8],0x52  ; 此建構器之 default mode
440793 8b 41 08               mov eax,[ecx+8]           ; Auth mode
440796 83 f8 52               cmp eax,0x52
4407C2 e8 99 2b 06 00         call 0x4A3360             ; E8 variant
4407CB 83 f8 54               cmp eax,0x54
4407F7 e8 b4 29 06 00         call 0x4A31B0             ; 0F variant
440822 e8 89 29 06 00         call 0x4A31B0             ; other mode fallback
4A34FC 6a 70                  push 112                  ; 00E8 decoded app bytes
4A3503 6a 01                  push slot1
4A3505 ff d2                  call manager.v+10        ; queue
4A32B6 68 d6 00 00 00         push 214                  ; 000F decoded app bytes
4A32C2 6a 01                  push slot1
4A32C4 ff d2                  call manager.v+10
```

**注意：`mode=0x52/0x54` 是 Auth/角色物件的訊息選擇，與 Connection 的 `A02C` framing mode 完全不同。** `0x6D6340` default0x52 只證明此建構函式的初始值，不能證每次登入都使用 E8 或絕對不發 000F。`C2S0xE8` 長112：`+0..1=E8 00`，`+2..52`、`+53..103` 各51 narrow bytes，`+104..109` 六個 opaque bytes（本 builder **未證直接初始化**），`+110..111` 來自 `[FB1318]+BF80` WORD；`000F` 長214：`+0..1=0F 00`，`+2..103`、`+104..205` 各51個 UTF-16LE code units，`+206..209=0x00010001`、`+210..211=0x0034`、`+212..213` 相同 WORD。完整業務欄位和 CP_ACP source 由 T03 E69/E83 和 `SPEC-AUTH-0001`；不能把 opaque 當固定零，也不能把 encoded frame length 誤用於 payload length。

### 2.2 固定 NetworkManager vtable、連線 Map 查找和成功前提

```asm
8069B1 8d 4e 18             lea ecx,[esi+18]         ; manager key→connection tree
8069B7 e8 04 cf 03 00       call 8438C0             ; map lookup
8069BF 3b 46 1c             cmp eax,[esi+1C]        ; end/sentinel gate
8069C5 8b 48 10             mov ecx,[eax+10]        ; Conn* nonnull gate
8069D7 85 c0                test eax,eax            ; bytes len=0 special return1
8069EB e8 e0 f6 ff ff       call 8060D0             ; queue packet onto selected Conn
8060FA 81 be a4 a0 00 00 2c 01 00 00  cmp [conn+A0A4],300 ; throttle
80615B 81 fb 00 10 00 00    cmp ebx,4096           ; payload source length bound
80616C e8 5f 7a 09 00       call 89DBD0             ; copy bytes into queue node+8
806174 89 5f 04             mov [edi+4],ebx        ; node length
806178 e8 e3 fe ff ff       call 806060             ; linked-list insertion
```

`0x8069A0` 第三層 map key=**slot1**，不是 lane2。若 key1 Conn 不存在/NULL，回 0 且 **不會**神奇另挑 key0／key2；有些 len0 走回1分支，但不是合法登入。queue 在 `0x8060D0` 驗 throttle/size、Pool node、byte copy、append；**不等於資料已被編碼，更不是 OS 成功發送**。`0x8060D0` 在 n>4096 時不採成功 copy 路徑，Server 應以有界有效登入封包而非模仿錯誤 node 效果做解析。queue 狀態在 Conn+`A074` list、`A078` count、`A0A4` throttle，不要把所有 `A0xx` 當 queue count。

### 2.3 Frame drain、兩個 timer/worker pump 和 socket descriptor

```asm
804AC8 83 be ac a0 00 00 00 cmp [Conn+A0AC],0  ; active gate
804AD6 e8 c5 16 00 00       call 8061A0        ; frame queue→Tx
805228 e8 73 0f 00 00       call 8061A0        ; other pump also drains
8061E6 8b 86 74 a0 00 00    mov eax,[Conn+A074]
8061F6 8b 7b 08             mov edi,[node+8]
8061F9 8b 57 04             mov edx,[payload+4] ; decoded payload n
806202 0f be 86 2c a0 00 00 movsx eax,byte[Conn+A02C]
806218 74 15                je 80622F          ; mode==0: direct plain
806223 e8 08 16 00 00       call 807830        ; 0BBB first attempt
80622A 75 23                jne 80624F         ; success, skip fallback
80623A e8 31 18 00 00       call 807A70        ; 1A68 direct or fallback
806246 0f 84 58 01 00 00    je 8063A4         ; both fail: retain node
80624F ...                  success-only list unlink and recycle
806275 ff 8e 78 a0 00 00    dec dword[Conn+A078]
804B21 83 be 28 a0 00 00 00 cmp [Conn+A028],0 ; Tx framed bytes available
804B2E 8b 86 b8 a0 00 00    mov eax,[Conn+A0B8] ; in-flight submissions
804B4A 8b 52 0c             mov edx,[mgr.vptr+0x0c] ; 8068B0
804B52 8d 86 20 50 00 00    lea eax,[Conn+5020] ; framed data
804B5A ff d2                call edx           ; submit WSASend
8052AC ff d2                call edx           ; 2nd pump equivalent
```

`0x8061A0` 成功只代表 Tx buffer append，並會回收 source queue；已產生的多個完整 frame **可能**在同一個 `WSASend` 缓冲区被批次送出。Send pump 有 `Conn+A0AC`、`Conn+A028`、`Conn+A0B8`、`Conn+A0B0`、`Conn+A0A8` 等多個 gate，另有 throttle/state／close checks。不能把 *Queue First*、*Frame Append*、*WSASend submit*、*OS completion*、*Server reads TCP bytes* 五者畫成同一事件。`WSASend` 不是按 app opcode 挑 socket，而是接收 **當前 Conn* 的 socket handle `[Conn+0]`**，其身份在 Manager map lookup 階段已決定。

### 2.4 OS call ABI：避免歷史 T03／T16 退回的 offset 混淆

```asm
8068D1 83 be a8 a0 00 00 00 cmp [Conn+A0A8],0 ; closing gate
8068DE 8d 86 50 a0 00 00    lea eax,[Conn+A050] ; OVERLAPPED
8068F3 50                   push eax            ; OVERLAPPED arg
8068F7 8d 48 14             lea ecx,[eax+14]  ; WSABUF at Conn+A064
8068FC 89 78 18             mov [eax+18],edi   ; WSABUF.buf source framed data
806905 89 11                mov [ecx],edx      ; WSABUF.len
806909 51                   push ecx           ; WSABUF pointer
80690A 52                   push edx           ; SOCKET [Conn+0]
806912 ff 15 b8 25 bd 00    call [BD25B8]     ; WSASend
80692D 81 ff e5 03 00 00    cmp edi,997      ; WSA_IO_PENDING
806961 81 c6 b8 a0 00 00    add esi,A0B8     ; counter ADDRESS
806968 ff 15 84 22 bd 00    call [BD2284]    ; InterlockedIncrement
80697A 81 c6 b8 a0 00 00    add esi,A0B8
806981 ff 15 84 22 bd 00    call [BD2284]
```

`Conn+A050` 是 **OVERLAPPED**，`Conn+A064` 是 **WSABUF**，`Conn+A0B8` 是 **pending counter**，三者不同。`WSASend` immediate success 與 `WSA_IO_PENDING(997)` 分別返回 1/2 並增計數；其它 WSA error 返回0。兩種前者均**不代表對端 Server 已接收**。IOCP completion (`0x806CF0`) 可能並發並有 close/drain/retry gate，Server 必須能容忍 TCP 分段與粘包。`0x806CF0` 的收包分支及 post-recv `0x806A00` 是 **Client 讀 Server→Client bytes**，不能用它指定 Client→Server 的外框格式。

## 3. `Conn+A02C` mode 的全部可證直接存取、alias 與 fallback

| 點 | 原生 bytes／限定結論 |
| --- | --- |
| `0x805D02` | `C6 86 2C A0 00 00 02` 新配置 Conn `BYTE +A02C=2`。Pool 預建與動態建構都使用 `0x805CA0`。 |
| `0x805F50`、`0x806010` | 已核重用/重設沒有直接寫 A02C；reuse 不必再 constructor；保留先前值**僅在無其他 alias writer 條件下**。 |
| `0x806202` | `0F BE 86 2C A0 00 00` signed load A02C；以 **zero vs nonzero** 分支；1/2/其他非零在這段沒有不同 codec。 |
| 全 `.text` 立即位移掃描 | `2C A0 00 00` **2 處**，位於 operand VA `0x805D04`、`0x806205`；已核指令起點只有 constructor writer 與 frame reader。這是 `direct disp` 的**陰性**，不是全程序 memory alias/writer 不存在證明。 |
| 間接 writer／指標 alias | 固定範圍查 `805CA0`、`805F50`、`8061A0`，以及 Tx used `+A028`、Tx cursor `+A020`、recv OVERLAPPED `+A030` 互不重疊。通用 `memcpy/memset`／computed address／異常記憶體覆寫／外部增補，**尚未有完整全域別名閉合**；不能從靜態一個 initializer 保證 runtime 永遠 mode2。 |

`0x807830`（0BBB）**失敗**：`n==0`、`n+6>4096`、當前 Tx framed `used+n+6>16384`、目的 start/end 在 Tx bounds 外、特殊內部資源失敗；失敗返回0，不會在該函式成功追加 frame。`0x807A70`（1A68）**獨立**檢查 `n==0`、`n+4>4096`、`used+n+4>16384`、指標是否合法。mode0直接 1A68；非0先 0BBB，若 0BBB fail 才改試 1A68；若兩者都 fail 在 `0x806246` 不走 success unlink。例子（需 Tx space）：n=4090 可0BBB；n=4091/4092 0BBB 長度失敗後可能 1A68；n=4093 二者均太大。**這是合成可達性，非已捕捉原版遊戲真的發過此大封包。**

## 4. C2S Frame 正向已證欄位、decoder、parser 與安全策略分界

### 4.1 Client **出站** writers（C2S）是 Server 可使用的主要證據

| 解碼器 | Byte Offset | Format | 當前可信度 |
|---|---|---|---|
| shared | `+0..1` | `u16le n` = **decoded application payload 的 byte 長度**，正常 outgoing 兩 writers n>=1 | 原生 `807870/80787A`、`807A70`；已證 bounded |
| shared | `+2..3` | `u16le marker`: `0x0BBB` bytes `BB 0B` 或 `0x1A68` bytes `68 1A` | 原生兩 writer；已證 bounded |
| BBB only | `+4..5` | `u16le sum(plaintext payload bytes) mod 65536`，**不是 CRC32** | `8079EF/8079F8`；已證 bounded |
| BBB only | `+6..5+n` | n encrypted bytes，首位元 `c[0]=p[0] XOR 0xB6`，其餘 `c[i]=p[i] XOR p[i-1]` | `807901` 及後續 XOR loop；已證 bounded |
| 1A68 only | `+4..3+n` | n unmodified application bytes | `807A70`；已證 bounded |

**Server BBB decode**（不應先按 ciphertext 求 checksum）：

```python
# BYTES ARE SYNTHETIC EXAMPLE ONLY; no login credentials.
n, marker = u16le(frame,0), u16le(frame,2)
assert 1 <= n <= 4090 and marker == 0x0BBB
assert len(frame) == 6+n
plain = bytearray()
last = 0xB6
for c in frame[6:]:
    last = c ^ last
    plain.append(last)
if (sum(plain) & 0xFFFF) != u16le(frame,4):
    reject('BAD_CHECKSUM')
# only now dispatch LE16 opcode at plain[0:2], if len(plain)>=2.
```

Raw: `1<=n<=4092`, total size `4+n`。出站 local writer 的 **正常成功上限**：BBB n<=4090、1A68 n<=4092；源 queue 的 <=4096 不等於 writer 一定能產生 <=4096B **payload**，因 frame header 還佔4/6B、Tx cap和 pointer guard。BBB 與 raw 對相同 decoded app bytes 的示範：

```text
synthetic app:  01 00
0BBB frame :   02 00 BB 0B 01 00 B7 01
1A68 frame :   02 00 68 1A 01 00
```

C2S 登入內層兩種 payload n=112、214；當剛建 Conn+mode2+空 Tx 且 encoder success，可形成總長 **118／220B** 的 BBB 候選外框；若 raw 成功則 **116／218B**。同一 Conn 可能在登入前已有其它初始命令，不能稱這幾組字串就是第一個 TCP send／官方 Server handshake 固定包。

### 4.2 Server 安全、有界的 TCP stream decoder（Server 設計政策，不冒充原 Client 實作）

1. 每 Socket/ConnectionId 各自保留最多明確配置的 bounded RX byte accumulator；`recv==0` 表示 EOF，與 application opcode0 或空 frame 不同。
2. 少於4 bytes → `Incomplete`，**不能**立刻拒絕；否則讀 `u16le n`，n=0 或超過所啟用 C2S marker source bounds → `InvalidLength`。利用 size_t checked arithmetic 算 `header+n`，不能溢位。
3. marker 僅在 **C2S SOURCE REVIEW whitelist** 內接受：目前原生成功出站 writer 可證 `0x0BBB`／`0x1A68`。`0x2633`／`0x22D7` 是目前發現的 **Client 入站** parser marker，**沒有**它們在此次登入路徑中 C2S writer 的正向證據，預設 Unsupported，不要把它們轉成可直接認證登入的格式；未知 marker fail-closed。
4. 等完整 `header+n` bytes 才 decode；若不完整，不讀超界，不進 C02；多個 frame 相接時依 consumedBytes 逐個循環；若錯 frame 後還有好 frame，由經核准的 Server 錯誤政策決定 terminate/skip，不能把 Client 自身 pool recycle 行為直接鏡像成 Server 必須繼續。
5. BBB 還原後比 `checksum`；不符 → `BadChecksum`，**不產生 parsed app**。Raw 直接取 decoded payload。`decoded len>=2` 再讀 application opcode；只在版本、方向、Conn key1、phase、payload length 與登入類型都確認時進 E2a／E3b。登入`0x00E8` 應 112B、`0x000F` 應 214B；其它 command 不可當登入。
6. 密碼、帳號、opaque 原始 bytes、frame HEX 預設**不能寫入日誌**。Network bytes 分類 !=可信身份，`ServerConnectionId` 由 Server 自己建立；同 Conn 重送與重連需 Server-owned lease fencing；只有受信 request 明確符合 source gate 才呼叫 C02。

### 4.3 Client **入站** parser（S2C）僅作對照，不能授權 C2S marker

`806CF0` 收到 Server bytes 才由 `807B40` 用 marker 做分支：`0x2633` 是8B header（後4B本 parser 中語意未證）+ 0x7C XOR 解壓 `727190`；`0x0BBB` 6B header + B6 XOR/checksum；`0x1A68`、`0x22D7` 和 default 走4B header/raw。它的 `[frame+0]` n 1..4096 是 **inbound parser** 可接受範圍，**不等於**出站 writer n 的上限。checksum fail/inflate fail：該 frame 可被消耗但 decoded node length0、回收到 pool，**不派發業務**；n=0／>4096：parser status0、IOCP另走錯誤分支；frame incomplete 保留殘留。這些 E59/RR6 的 Client error/pool 語意只用於界定方向和安全測試，不規定新 Server 必然持續連線。

## 5. 登入首次收發、重試、lane／場景分派：肯定與否定實證

- **有界正向 Client→Server**：`6D64C0`／`6D6590` 若有效地址字串，經 `495610` 連 key1、可於成功分支排不同長度的初始應用命令（例：`6D6563 push0x38`、`6D6683 push0x68`）。另 0x6D6377／6424／670C／696C 也可呼叫 helper；直接 E8 caller 不保證 runtime 是同一場景、同一次 UI/帳密操作。`440790` 依 auth object mode 產生 `E8/000F` 放 slot1 Manager Queue；`8069A0` 有 Conn 才入隊；Conn pump 再送。這些發送路徑在**自身近端**沒有共同的「先收到某個 Server app0x13 才可 enqueue」必然檢查，但這不足以證明所有首次登入都一定 Client-first 或無任何前置握手。
- **有界 Server→Client**：LOGIN scene 有 `S2C app0x13→4C37A0` 與 `app0x7A→4C3C10`，必經 `0x806CF0→0x807B40→0x8040A0→0x804740→0x4930E0` 且 lane==2、有效 Client callback 和 LOGIN scene/表；不是兩個封包在任何時刻/任何 Socket 都能正確被 UI 接受。`0x4930E0` 的 `Client+BE8C` 是特定回傳 gate，**不是**每一個 handler 呼叫前都強制需要非零。
- **初次 wire 順序 UNKNOWN**：沒有同版實際 Client session 的 TCP trace，也沒有一條 Client 靜態 CFG 能將「最先 socket connected」與「Server 必先發某 marker／Client 必先發某 opcode」做全稱閉合。第三方 TCP排程、IOCP、Sleep、不同UI callback/scene 執行可交錯。嚴禁新 Server 先行硬塞「官方 greetings」、固定回覆0x13 或認定所有登入第一包都是 E8／000F。若需要啟用 runtime native profile，明確要求相同 `Tartaros.bin` SHA 的隔離連線與原始 bytes 去敏 header/meta trace，再由 T01/S00 source review。
- **重試不是自動同義詞**：`495610` Connect failure → return0；有些 UI caller 可重呼叫，卻不能因此宣稱 timer 自動重試，且 old Conn 在關閉／Pool reuse 有 racing completion。`8061A0` 兩 encoder 皆失敗時 **保留 node**，不是相同 application 在另一 Socket 自動重發。`8068B0` ERROR_IO_PENDING 表明 submitted, not OS completion。Server E2b 自訂安全超時／去重／只認當前 valid ConnectionId 和 phase。
- **權限與邊界**：S2C login result status0/nonempty UTF16 群組從 `+0x92`、`0x7A` 群組從 `+6` 是 T03 的 consumer；T02 對其 Frame/Scene gate 成立即可交 S00。不可把 `0x0BBB` 外框 `n` 當 app payload 含登入成功碼、不可把 `lane2` 當 `A02C mode2`、不可把 `C2S E8` 與 `S2C 0x13` 因功能相鄰就稱已捕獲 request→response 配對。

## 6. 最終獨立交接：**C04-E2b Server 可直接實作的 C2S Frame 契約表**

> 版本鎖定：`KR Tartaros.bin SHA256=9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**「可實作」指 source-backed 離線 codec、分層與安全驗證，可作 S00 DRAFT/審核的實作契約；不是已核准開啟真 Client 接收或 C02 Auth 的 RUN 時開關。**

| 項目／Server 實作介面 | Native 已證／證據 | C04-E2b 使用狀態 |
| --- | --- | --- |
| Build identity / direction | 本篇 KR SHA、`807830/807A70` Client 出站 writer | **可直接做離線條件式 C2S parser**；不同 SHA 不准當同版 |
| 實際 Socket／Endpoint | `495610` caller-supplied host；`+18 Connect`→`806AD0`，key1 port8415、lane2、保存 BF60 | **可做連線/來源設定與 metadata**；運行環境真正指向此 Port/DNS 須驗證 |
| Slot→Conn map | `4A3505/4A32C4` slot1→`8069A0` manager+0x18 tree→Conn+0 Socket | **已證可做配置式 slot1 gate**；不能從 TCP 位元組自行鑑定 Client 處於哪個內部 slot |
| Local auth producer | `440790` 0x52→E8/112、0x54/else→000F/214；both manager slot1 | **可實作離線 app layout、opcode/length**；opaque/codepage/真正 runtime mode 仍設資料欄位 unknown |
| BBB outer | LE16 n, LE16 0x0BBB, LE16 sum(plain), XOR seed B6、前一 plaintext | **可實作／合成測試**，n1..4090，frame6+n；checksum fails must not authenticate |
| Plain outer | LE16 n, LE16 0x1A68, raw n | **可實作／合成測試**，n1..4092，frame4+n |
| Outbound mode | new Conn A02C=2；非0優先 BBB、失敗1A68；mode0 raw | **可作解碼兩種候選**；不可讓 Server 強制認定全部 session 一律 BBB |
| Tx queue/OS | 8060D0/8061A0/804A40/805190/8068B0；A0AC/A028/A0B8/A0A8 gate | **可寫 Socket stream accumulator**；不把 queue 或 WSASend success 視為 Server RX 完成 |
| 分包/黏包/短幀/多幀 | 有界 frame header/length + TCP stream；Client inbound parser 亦保留不完整幀 | **Server 安全實作可直接做**，bounded per Conn、checked size/consumed count |
| 0x2633／0x22D7 C2S | 在 KR `807B40` **入站**路徑找到，不是登入出站 writer | **不能啟用為 native C2S login markers**；無來源時 Unsupported |
| S2C app13/7A gate | `4930E0 lane2`、有效 LOGIN scene/handler 和 payload | **只能供回覆狀態/場景設計**；不能當 C2S marker 或自動成功 ACK |
| First wire client-first/server-first | 多條 Conn/sender/recv callback 可交錯，尚無同版 runtime | **不能啟用固定握手／首包假設** |
| Native profile/TrustedLogin/C02 | 缺同版原始 Client-in-loop、T01 source Gate、安全隔離和 T03 opaque/完整配對 | **保持 OFF／fail-closed**；S00/T01 審核+使用者明確授權 runtime 才能評估啟用 |

**給 Server 工程的非規範型別參考**：`KrC2sFrameCandidate { clientSha, serverConnectionGuid, expectedConnSlot=1, direction=C2S, marker, encodedPayloadLen, decodedAppOpcode, decodedLen, payloadBytesSensitive, sourceGateRef, wireConsumedBytes, validity, errorReason }`。`ExpectedConnSlot` 只能由此 Server 的 **Port/connection phase 配置**及原始 Client 已證 callsite 作條件推導，不存在 wire 裡直接傳 `slot` 的證據。嚴禁未 source-reviewed 的 frame candidate 直接進 `TrustedLoginRequest`。

### 6.1 原生與合成驗證矩陣

| 測試 | 預期 | 性質 |
|---|---|---|
| 只收到 `02 00` | `Incomplete`, 不取 opcode | Server 設計+header 規格 |
| `02 00 BB 0B 01 00 B7 01` | decoded payload `01 00`、checksum1 | 合成 codec 正例，**非登入** |
| `02 00 68 1A 01 00` | decoded payload `01 00` | 合成 raw 正例 |
| BBB checksum byte 翻轉 | `BadChecksum`，不進 C02 | 合成負例 |
| `n=0`、`n=4093` | 拒絕/不屬兩 writer 正常發送 | Server 安全政策，源 writer bounds |
| `n=4091/4092`、Tx empty | 0BBB size fail → raw 可能成功 | **靜態可達/合成**，不能稱真業務出過 |
| 两 frame 黏包、frame 分段 | 正確 consumedLen，不把第二筆吃掉 | Server 安全設計測試 |
| C2S marker 2633/22D7 | 未核准、Unsupported | 方向專屬門檻 |
| login E8/000F 完整 C2S | only when opcode、decoded len、Build、slot/phase source gates match, then E2a | 尚未 native M1/M2 runtime PASS |

## 7. 未解與精確解除、交接責任

- **Client 待逆向**：所有 `Conn+A02C` pointer alias 的完整全程生命週期與有沒有 mode0 實際 writer；`0x6D63xx` host/port 最終 config/launcher 指向；`0x440790` 所有虛擬 caller 的 scene/phase 唯一性；第一次登入 是否先經某非登入 app/Server greeting。其靜態已查界線如第1～5節，解除方式為同版 constructor/xref 指標別名與 UI 生命周期定向加查；若超出 static，須同版明確授權的 Runtime header-only trace。**不要**以沒有官方 Server 程式碼當成唯一 blocker。
- **Server 待開發**：可先完成離線 `C04-E1b/E2a` 的源證 decoder/stream buffering；`C04-E2b/E3b` 要按照 S00 Gate/I40、Session/C02 安全/Provider 一致性審查及版本鎖定，不可由本稿自動打開 NativeContractAdmission。
- **跨功能待整合**：T03 RR-0003 的 E8 opaque、CP_ACP 與 `0x13/0x7A` 消費，T02 RR-0005 的登入到選服與原始 IP，T01 R0/R1/R2 審查；S00 合併現有 `SPEC-NET-0001/0002/0003`、`SPEC-AUTH-0001`、`SPEC-FLOW-0001`、`GAP-NET-0001/0003`、I39/I40 既有 Gate（去重，不新增影子 RR／TEST）。T03 的 RR0003 本次不是自動切換責任人。
- **待遊玩驗證**：同 SHA 原版 Client 於獨立 loopback/隔離 Server 的真正 Accept→RX frame→app variant→C02 decision（M1/M2）；另需真正 S2C reply→Client next scene（M3）；所有 runtime 行為均不能由本次 source-only 代替。

本稿只是 T02 對 RR-0001/0004/0006/0007 的 **額外原生證據交付**；四項形式上仍為 `IN_REVIEW`，T01/S00 審核及 SPEC 升級獨立。未修改原始二進位；不新增 branch；不覆寫任何研究原稿。

**重現**：`python -B kr-extra-roy/20261101-chatgpt-web-roy-E85-C04-E2b-verify.py /path/to/Tartaros.bin`（90 static/synthetic checks；成功回報 PASS，附來源 SHA）。
