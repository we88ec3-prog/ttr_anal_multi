# T10-112 — KR 連線虛表實證、出站待送佇列、Frame 組合與 Winsock 邊界

## 0. 實體來源與工作範圍

研究時間 20261028-204914 Asia/Taipei。KR 原生 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。直接執行本環境 `objdump -D -Mintel`、用 Python struct 讀 PE 原始 `.rdata` DWORD。`.text` VA401000/raw400，映射 raw=VA-400C00；`.rdata` VABD2000/raw7D0600，映射 raw=VA-401A00。僅靜態讀取，不執行或修改 Client，不提出沒有原始樣本的 wire 封包與 Server 規則。

於研究開始前，GitHub 最新 `main` 已透過 PR #10 合入 `t10/roy/chatgpt-web`，Merge SHA `9aaf1c06626377c070ddf4967e0b5f04d59fcc09`。此段從 T10-111 既有 WSASend/WSARecv 呼叫址前進，不把其原稿再次視作新增證據。本研究未涉及除 T10 以外的 Task 修改。

## 1. 第一輪重要新發現：同一張連線 vtable 的實際構造者已定位

T10-111 對 `0x8068B0` / `0x806A00` / `0x806AD0` 的 E8 直接呼叫掃描皆 0 次，此前沒有建立它們的實際 virtual ownership。這次在 `.rdata` 精確找到各地址在同一組連續 DWORD；vtable 真實起點是 **`0xC51748`**，不是 `0xC51744`（後者是前置 DWORD `0xC812E8`，不應當 slot 0）。表內容：

| vtable entry VA | byte slot | native target |
|---|---:|---|
| `0x00C51748` | `+0x0` | `0x00806670` |
| `0x00C5174C` | `+0x4` | `0x00806CF0` |
| `0x00C51750` | `+0x8` | `0x00806850` |
| `0x00C51754` | `+0xC` | `0x008068B0` |
| `0x00C51758` | `+0x10` | `0x008069A0` |
| `0x00C5175C` | `+0x14` | `0x00806A00` |
| `0x00C51760` | `+0x18` | `0x00806AD0` |
| `0x00C51764` | `+0x1C` | `0x00806F60` |
| `0x00C51768` | `+0x20` | `0x00806F80` |
| `0x00C5176C` | `+0x24` | `0x00806FC0` |
| `0x00C51770` | `+0x28` | `0x00807090` |

在 `0x8046D9` 先以 `push 0x5C; call 0x891268` 配置 0x5C-byte 物件，`0x8046F2 call 0x803D60` 執行 base 初始化，**`0x8046F7 mov [esi],0xC51748`** 把上述表指派到新建物件，`0x80470A mov edx,[ecx]`、`0x80470C mov eax,[edx+8]`、`0x804715 call eax` 以 slot+8 啟動實作 `0x806850`。同時 `0x80470F` 保存物件到全域 `0xFBA854`。

因此這不是單純在可執行檔中存在幾個未被調用的 API helper：已確認有具體連線型態物件分配、vptr 寫入、第一次虛方法呼叫（slot+8）。但**此時未逐一反推 vtable+0xC/+0x14/+0x18 的所有呼叫位置**，不能說每次玩家 Z 封包都來自該物件或必經該 vptr。`0x8066CB` 在析構過程也將 `[edi]=0xC51748`，支持同一類型之生命週期。沒有原版 C++ RTTI 類名的確定證據，「連線物件」是暫名。

**重要修正**：`0xC51744` 位於指標序列前一格，不能因其接近表頭就錯把 `0x806670` 當成 slot0；slot0 實際值 `0x806670` 位於 `0xC51748`。這讓 send、receive、初始化 slot 分別定位為 `+0xC`、`+0x14`、`+0x18`。

## 2. 待送資料入列與佇列所有權

`0x8060D0` 保留本地 connection `ESI=ECX`，讀 `[ebp+8]` buffer ptr、`[ebp+C]` len，先以 `[esi+A0A4] > 0x12C` 拒絕（return0）；當 len<=0x1000 才複製原始 bytes 至獨立配置/暫存 record `record+8`，`[record+4]=len`。若 len>0x1000，分支跳過複製，但**仍續行 `push record`、`call 0x806060`**；本函式的入列成功不代表傳送了原輸入 bytes，亦不能直接聲稱安全拒絕過長輸入。

`0x806060` 依 connection 的 `[esi+A0D4]` mutex/critical section IAT 操作，將 caller 給的 record 指標插入 `[esi+A074]` sentinel list，並遞增 `[esi+A078]` count，再釋放鎖並寫 `[esi+A024]=1`。已證是 owner 的 local pending list writer，**不是 `WSASend` 本身**，也非遊戲技能佇列。

**邊界核對**：`[esi+A0A4]` 的 `0x12C` 與傳入 len 的 `0x1000` 是兩種不同門檻；不可合併說『最多300 bytes 封包』。0x12C 是在本函式測試的 owner field（確切語義未解），0x1000 是 copy 門檻。`0x8060D0` 的 caller 尚未以直接 E8 定位；不能將其等同 T10-101 的 `000A` builder 的直接 callee。

## 3. Pending list 的消費與出站 Frame

`0x8061A0` 使用傳入 connection 指標 `[ebp+8]`，先進入 mutex，再由 `[esi+A074]` 的 sentinel list 逐項取 `node+8` record。對每個 record：`[edi+4]` 是長度，`record+8` 是 payload；以 `[esi+A02C]` 選分支，**選擇條件為0 時經 `0x80623A call 0x807A70`** 將 pending payload 包成輸出框架，其他值會先走 `0x807830` 轉換，失敗再 fallback 至 `0x807A70`。此路徑具體區分傳輸 framing / transform，與 gameplay 普攻 combo unrelated。

成功生成 frame 後 `0x80624F..0x806275` 抽離該 pending list 節點，呼叫 `0x89120C` 釋放並遞減 `[esi+A078]`。失敗分支 `0x8063A4..0x8063BA` 只在 owner+A0B4==1 且另一結果旗標為0時改變本函式的局部回傳；不能把這個 return0 當伺服器拒絕攻擊。`0x8063BA` 解 mutex，`ret 4`。本輪還重讀 `0x8063E0` 附近另一個待送節點資源收集函式，其 `[esi+A074]`/`+A078` 關聯相同，但不把資源回收誤作送包。

**仍缺下游**：`0x8061A0` 把資料整理至 `owner+0x501C` 的 pending frame buffer，**本段未在這個函式內看到直接 `WSASend`**。真正何時以 `owner+0x501C` 的有效範圍交給 virtual+0xC (`0x8068B0`) 必須追 pump/flush caller 的間接虛呼叫，不能因這兩段同屬連線類別就宣稱全部已完成。

## 4. 原生 caller 與資料分工矩陣

| 玩家或網路情境 | Client 證實的本地路徑 | C→S 狀態 | S→C 狀態 | 動作結果 | Server 分工／未知 |
|---|---|---|---|---|---|
| 按 Z，當前 bank 對應 ID13 | 前段 phase1/2→bit0→條件 `000A` builder；本段沒有新增鍵位 producer | `000A` 到 `0x8060D0` 的動態/靜態 caller 未閉合；不可宣稱每按一次必 WSASend | 未對上該次按鍵的收包 | 起手、是否先播 unknown | 攻擊 accept/reject、combo 仍待第一手驗證 |
| 出站資料交給 `0x8060D0` | 在 `owner+A0A4` gate 與長度條件下配置 record/複製，再 `0x806060` 入待送 list | 僅證實 buffer enqueue，不是 socket 已寫 | 非此入口 | 不構成 attack motion 證據 | 需追實際 caller 與 flush |
| pending record 有有效內容且 mode0 | `0x8061A0` 迭代 list，`0x807A70` 建立 frame，成功刪節點 | 已證暫存資料進 framing buffer，但未在這條函式直接呼叫 WSASend | 非此入口 | 無此函式內 actor 動作證據 | 需追 `owner+501C` consumer |
| pending record mode!=0 | `0x807830` 轉換或 fallback `0x807A70` | framing 成功才從 list 移除；不能猜轉換 schema | 非此入口 | 無直接動作 | 需查安全和壓縮/加密類型 |
| I/O 傳送成功/等待 | T10-111 `virtual+0xC = 0x8068B0`，WSASend 與 A050 OVERLAPPED | 通用傳送接口已證 | completion 不代表 ACK | 與技能是否已起手無因果 | socket 提交不等於 Server 接受 |
| 接收成功 | T10-111 `virtual+0x14=0x806A00`，WSARecv A030、IOCP receive、frame parser | 非此入口 | 通用 receive 骨架已證，未對應 Z 專屬 S2C | actor motion unknown | 不自造 combo/cancel 時窗 |

## 5. 檢索、反證、三輪深入規則

在 `.text` raw `[0x400,0x7D0600)` byte-wise E8 rel32 候選搜尋，`0x8068B0`、`0x806A00`、`0x806AD0`、`0x8060D0`、`0x8061A0` 為0；但 `.rdata` 直接指標分別定位於 `0xC51754`、`0xC5175C`、`0xC51760`，並由 `0x8046F7` 原生 vptr store 及 `0x804715` 間接呼叫確立**至少此一類別有實際可到達的 dispatch**。零直接 E8 不等於不可達；虛表 slot 與具體 caller 仍需更詳細檢查。`0x8060D0/0x8061A0` 的上游可能是 callback、函式指標或 register jump，不可只憑本次掃描排除。

**第 1 輪重大進展**：獨立補上連線 vtable 的 constructor store / 首次 virtual call，與 pending list `0x8060D0→0x806060→0x8061A0→0x807A70` 兩個可證的局部 writer/consumer（跨函式時需滿足同 owner、呼叫順序）。依共用門檻 T10-112-2/112-3 未啟動；注意此僅本段 pending send subject 的有界閉環，不代表普通攻擊 end-to-end 已完成。下一段：定位 `0x8061A0` 的實際 pump caller 與 `0x8068B0` 虛呼叫、`0x8060D0` 上游的 packer，對 C2S000A 經 `0x5452C0` 進入連線型態的路徑做 connector proof；另接回 S2C key13 actor motion。

## 6. 可重現命令

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -D -Mintel --start-address=0x8046d9 --stop-address=0x804727 Tartaros.bin
objdump -D -Mintel --start-address=0x8060d0 --stop-address=0x80618f Tartaros.bin
objdump -D -Mintel --start-address=0x8061a0 --stop-address=0x80627c Tartaros.bin
objdump -D -Mintel --start-address=0x8068b0 --stop-address=0x806950 Tartaros.bin
```

## 7. 本輪原始 BIN assembly 附錄

### 連線物件虛表指派及首次呼叫 — VA 0x008046D9–0x00804727; raw 0x403AD9–0x403B27

```asm
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
  804724:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
```

### 輸出佇列插入 — VA 0x00806060–0x008060CE; raw 0x405460–0x4054CE

```asm
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
```

### 輸出資料入列與上限 — VA 0x008060D0–0x0080618F; raw 0x4054D0–0x40558F

```asm
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
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
  80618e:	c2               	ret    0x8
```

### 待送節點處理及 frame builder — VA 0x008061A0–0x0080627C; raw 0x4055A0–0x40567C

```asm
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
  80627b:	f6       	test   BYTE PTR ds:0xfe3354,0x1
```

### pending frame 整理及回傳 — VA 0x008063A4–0x008063DD; raw 0x4057A4–0x4057DD

```asm
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
  8063db:	c2 04              	ret    0x4
```

### 另一支待送回收 — VA 0x008063E0–0x00806566; raw 0x4057E0–0x405966

```asm
  8063e0:	55                   	push   ebp
  8063e1:	8b ec                	mov    ebp,esp
  8063e3:	6a ff                	push   0xffffffff
  8063e5:	68 fe 98 90 00       	push   0x9098fe
  8063ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8063f0:	50                   	push   eax
  8063f1:	83 ec 18             	sub    esp,0x18
  8063f4:	53                   	push   ebx
  8063f5:	56                   	push   esi
  8063f6:	57                   	push   edi
  8063f7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8063fc:	33 c5                	xor    eax,ebp
  8063fe:	50                   	push   eax
  8063ff:	8d 45 f4             	lea    eax,[ebp-0xc]
  806402:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  806408:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  80640b:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806411:	50                   	push   eax
  806412:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806418:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  80641e:	8b 18                	mov    ebx,DWORD PTR [eax]
  806420:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  806423:	3b d8                	cmp    ebx,eax
  806425:	0f 84 fe 00 00 00    	je     0x806529
  80642b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806432:	75 27                	jne    0x80645b
  806434:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80643b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806442:	e8 d9 0c 00 00       	call   0x807120
  806447:	68 90 0b bd 00       	push   0xbd0b90
  80644c:	e8 c9 be 08 00       	call   0x89231a
  806451:	83 c4 04             	add    esp,0x4
  806454:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80645b:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806460:	8b 73 08             	mov    esi,DWORD PTR [ebx+0x8]
  806463:	50                   	push   eax
  806464:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  806467:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80646d:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  806473:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  80647a:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  80647f:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  806485:	03 c8                	add    ecx,eax
  806487:	f6 c1 03             	test   cl,0x3
  80648a:	75 18                	jne    0x8064a4
  80648c:	83 c0 04             	add    eax,0x4
  80648f:	c1 e8 02             	shr    eax,0x2
  806492:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  806498:	77 0a                	ja     0x8064a4
  80649a:	68 64 33 fe 00       	push   0xfe3364
  80649f:	e8 cc 0a e3 ff       	call   0x636f70
  8064a4:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8064aa:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8064b0:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  8064b5:	8b f7                	mov    esi,edi
  8064b7:	c1 ee 02             	shr    esi,0x2
  8064ba:	3b c6                	cmp    eax,esi
  8064bc:	77 02                	ja     0x8064c0
  8064be:	2b f0                	sub    esi,eax
  8064c0:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  8064c6:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  8064ca:	75 1b                	jne    0x8064e7
  8064cc:	6a 10                	push   0x10
  8064ce:	e8 95 ad 08 00       	call   0x891268
  8064d3:	83 c4 04             	add    esp,0x4
  8064d6:	85 c0                	test   eax,eax
  8064d8:	0f 84 a8 00 00 00    	je     0x806586
  8064de:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  8064e4:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  8064e7:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  8064ec:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  8064ef:	83 e7 03             	and    edi,0x3
  8064f2:	8d 04 b9             	lea    eax,[ecx+edi*4]
  8064f5:	85 c0                	test   eax,eax
  8064f7:	74 05                	je     0x8064fe
  8064f9:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  8064fc:	89 10                	mov    DWORD PTR [eax],edx
  8064fe:	b8 01 00 00 00       	mov    eax,0x1
  806503:	01 05 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,eax
  806509:	29 05 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,eax
  80650f:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806514:	50                   	push   eax
  806515:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80651b:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  80651d:	3b 5d ec             	cmp    ebx,DWORD PTR [ebp-0x14]
  806520:	0f 85 05 ff ff ff    	jne    0x80642b
  806526:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806529:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  80652f:	8b 01                	mov    eax,DWORD PTR [ecx]
  806531:	89 09                	mov    DWORD PTR [ecx],ecx
  806533:	8b 8e 74 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa074]
  806539:	89 49 04             	mov    DWORD PTR [ecx+0x4],ecx
  80653c:	c7 86 78 a0 00 00 00 	mov    DWORD PTR [esi+0xa078],0x0
  806543:	00 00 00 
  806546:	3b 86 74 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa074]
  80654c:	74 17                	je     0x806565
  80654e:	8b ff                	mov    edi,edi
  806550:	8b 38                	mov    edi,DWORD PTR [eax]
  806552:	50                   	push   eax
  806553:	e8 b4 ac 08 00       	call   0x89120c
  806558:	83 c4 04             	add    esp,0x4
  80655b:	8b c7                	mov    eax,edi
  80655d:	3b be 74 a0 00 00    	cmp    edi,DWORD PTR [esi+0xa074]
  806563:	75 eb                	jne    0x806550
  806565:	8b         	mov    eax,DWORD PTR [esi+0xa0d4]
```

### WSASend 提交接口 — VA 0x008068B0–0x00806950; raw 0x405CB0–0x405D50

```asm
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
```

### WSARecv 提交接口 — VA 0x00806A00–0x00806A92; raw 0x405E00–0x405E92

```asm
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
  806a91:	68           	push   0xc51658
```

### 連線初始化分類 writer — VA 0x00806AD0–0x00806B54; raw 0x405ED0–0x405F54

```asm
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
```