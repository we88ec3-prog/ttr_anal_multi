# T03-4 — KR command 0x42 的真實 vtable target、通道查找及 Queue-copy/send 邊界

- 研究者：chatgpt-web roy；實際整理時間：2026-10-28T21:26:12.663535+08:00
- 任務：T03 登入、角色選擇；本段承接已提交 T03-3 的 0x4A3B80 builder 與 `[0xFBA854]` 送出虛擬呼叫。**本文新增的是未知 virtual target、網路物件生成／清理、通道查找、Buffer copy／佇列插入及失敗返回的首手證據。**
- Source：唯讀 `/mnt/data/Tartaros.bin`，12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；用 `objdump -d -Mintel --start-address --stop-address` 定向反組譯，PE `.text` VA `0x00401000`, raw `0x400`; `.rdata` VA `0x00BD2000`, raw `0x007D0600`; `.data` VA `0x00D61000`, raw `0x0095E800`。`.text` raw = VA - 0x400C00，`.rdata` raw = VA - 0x401A00。地址是 KR VA，非 packet opcode。
- 不執行／附加／修改目標。T02 分派／socket 主責不變；研究 UI 業務連接與 T02 介面，未改 Task owner/catalog。無原版抓包、Server 原始碼，**不宣稱已找到 42→43/69 原生 pairing**。

## 0. GitHub 已有成果去重

T03-3 已證 `0x4A3B80` 以兩位元組 command 0x0042 加兩個 1-byte 參數組成 4-byte payload `42 00 XX YY`；`[0xFBA798]==0` 才以 `[0xFBA854]` 的 vtable `+0x10`、`push 4; push &buf; push 0` 呼叫。三個已證 caller：`0x5F47F5`、`0x5F48F7`、`0x673EAA`。**本文不將此舊事當新發現**，而是追其尚未解析的 virtual method、資料所在佇列、前置條件。

## 1. 第 1 輪（T03-4）真正 vtable 目標與物件生成

由原始 `.text` 全域位址 `0xFBA854` 的靜態引用掃描，只挑完整指令核對，關鍵位址如下：

- `0x8046D9`：要求配置 `0x5C` bytes，返回指標 `ESI`，`0x8046F2 call 0x803D60` 執行建構初始化；`0x8046F7 mov dword [esi],0xC51748` 設定實際最終 vptr；`0x80470F mov [0xFBA854],ecx`；`0x804715 call eax` 此時取 `vtable+8`。**這代表全域送出物件確實可能是此型別的實例，不只是由名字猜出的候選。** 資源配置失敗的 Null 路徑存在，卻不能以靜態碼證明遊戲 runtime 仍能安全到達呼叫。
- `0x8045DC` 讀舊 `[0xFBA854]`，非零時經 vtable `+0x0`、`push 1` 呼叫析構／釋放入口，`0x8045EE` 把全域指標清成 0。另 `0x803F76` 也能寫入全域的 0（此處為 EBX=0 限界內的清理段），不保證掃描涵蓋所有間接 writer。

`.rdata` 的 `0xC51748` vtable 由 BIN 原始 little-endian dword 逐項解碼（raw `0x84FD48`）：

| vtable offset | 目標 VA | 語意狀態 |
|---:|---:|---|
| `+0x00` | `0x00806670` | 清理/析構候選 |
| `+0x04` | `0x00806CF0` | 暫未展開 |
| `+0x08` | `0x00806850` | 初始化呼叫 |
| `+0x0C` | `0x008068B0` | 暫未展開 |
| `+0x10` | `0x008069A0` | 已定向反組譯的發送介面 |
| `+0x14` | `0x00806A00` | 相鄰虛擬方法 |
| `+0x18` | `0x00806AD0` | 另一虛擬方法 |
| `+0x1C` | `0x00806F60` | 暫未展開 |
| `+0x20` | `0x00806F80` | 其他控制方法 |
| `+0x24` | `0x00806FC0` | 暫未展開 |
| `+0x28` | `0x00807090` | 暫未展開 |

**新確認目標**：`vtable+0x10` = dword at `0xC51758` = **`0x8069A0`**。此值與 `0x4A3BAA mov eax,[eax+0x10]` 完全吻合，原始資料直接確認，不靠 PDB 或 Ghidra 函式名稱。

## 2. `0x8069A0` 實際傳送契約（新增）

定向原生 x86：

1. `0x8069AA–0x8069B7` 以 `receiver+0x18` 作容器入口，將 `[ebp+8]`（原始 `push 0` 引數）地址交給 `0x8438C0` lookup，返回 iterator/node 到 local `[ebp-4]`。
2. `0x8069BF` 對 node 與 `receiver+0x1C` sentinel 比對；若相等或 `node+0x10` 為 0，`0x8069CC` 返回 **0**，沒有向後呼叫真正 copy/queue 函式。
3. 若資料長度 `[ebp+0x10]==0`，`0x8069DB` 返回 **1**，同樣**沒有**呼叫 copy/queue；因此單靠真值返回不可證實資料已傳輸。
4. 有效 node 且長度非零：`0x8069E6–0x8069EB` 以 `push length; push data; call 0x8060D0`，把後者回值直接返回。`[ebp+0xC]` 即 UI 傳來的 payload 位址。此呼叫為**已證 upstream→downstream**。

因此原始 4-byte `42 00 XX YY` 會被交付給一個選擇通道後、依長度處理的 queue producer；**尚未證實其後以何格式包裹 socket framing，亦未知道何種 socket 何時 flush。**

## 3. `0x8060D0` → `0x806060`：copy 與佇列（新增）

觀察到 `0x8060D0` 以 ECX 接收 node+0x10 指向的下游物件、`[ebp+8]` = buffer 位址、`[ebp+0xC]` = length：

- `0x8060FA cmp [esi+0xA0A4],0x12C`，大於時直接返回 0。**無法從此單一條件推知 0xA0A4 是連線次數或發包計數的正式名稱**。
- `0x80615B cmp ebx,0x1000`，長度 `<=0x1000` 才執行 `0x806168–0x80616C`：將 input buffer、length 及 `entry+8` 交給 `0x89DBD0`（記憶體複製類呼叫），`0x806174 mov [edi+4],ebx` 寫 length；長度大於 0x1000 的分支**沒有這段 copy**，卻仍進下一處 `0x806177`。不能猜稱它已拒收所有過大 payload。
- `0x806177 push edi; call 0x806060`，真正 queue append helper。
- `0x806060` 先以 `[esi+0xA0D4]` 呼叫同步原語，再從 `[esi+0xA074]` 的 linked-list sentinel 取下一節點，`call 0x74D700` 插入新 node；`0x8060A1` 將 `[esi+0xA078]` 元素計數增加 1；`0x8060BD mov byte [esi+0xA024],1` 設置待處理標記，返回 1。中間有一個近似 0x3FFFFFFE 的數量檢查及失敗/診斷路徑，並非不受限的 buffer。

**本段重要判讀**：通道成功找到 + length=4 + 狀態門檻成立時，原始 command42 bytes 可以進入 queue。`virtual+10` **不是直接的 `send()` WinSock import**。確認的是「有條件 queueing」而不是完成物理線路傳輸、Server 接收或應答。

## 4. 同介面對照／反證

`0x4A3BC0` 相鄰 builder 是 2 bytes `44 00`，同樣受 `[0xFBA798]` gate、同樣 `[0xFBA854]` vtable `+0x10`，不同的是 `push 2`；`0x4A3BF0` 則建 `0xA1` 頭與數個欄位，長度 `0xA`，同樣進 vtable `+0x10`。**這可證該介面是多業務訊息共用的送出服務，而非只為 command42 建造**；不能以這種相鄰位置推論 44 就是 42 回覆。送出接口可回 0、1，原 UI caller 是否查此返回值須分呼叫點驗證；原版 Server 的接受/拒絕規則無法由 queueing 推出。

另外 `0x4956E0–0x49570B` 和 `0x48C259–0x48C288` 使用同一個 `[0xFBA854]` 但走 vtable `+0x20`、傳入小整數參數，與 vtable `+0x10` 的 `(slot, pointer, size)` 契約不同。**不可把它們誤作另一組 command42 payload 或 42 回覆**。

## 5. 情境／封包／玩家效果矩陣

| 情境 | Client 本地條件 | C→S / send queue | S→C handler | UI/世界結果 | 來源／界線 |
|---|---|---|---|---|---|
| 有效 UI 選角 `0x70A` 通過 +5C 檢查 | T03-3 控件與記錄閘成立；FBA798=0 | `42 00 XX 00` 4 bytes 送 v+10，`0x8069A0` 依 slot0 找 node、有效且長度非0則遞交 `0x8060D0` | **unknown** | **unknown** | 本段新增 virtual target + queue producer，非 TCP 已送達 |
| slot0 不存在或 node+10 為0 | 上游 builder 可呼叫 | `0x8069A0` 返回0；不進 `0x8060D0` | unknown | 不可推斷錯誤提示 | 原生返回 0 分支 |
| data 長度=0 | node 有效 | `0x8069A0` 返回1，但不 copy/queue | unknown | unknown | 返回 1 不代表資料入列 |
| `0x8060D0` 本地 +0xA0A4 超過 0x12C | node 有效；傳入非0長度 | 返回0，未到 `0x806060` | unknown | unknown | 無法命名欄位政策 |
| 4-byte `0x42` 長度且未被前述 gate 擋下 | 0x1000 以下進 copy 路徑 | 經 `0x89DBD0` copy 與 `0x806060` queue insert/flag | unknown | 不保證 server 收到 | 已證有條件 enqueue，T02 負責 flush/framing |

## 6. 尚未完成、跨 Task 接口

- **T02（socket 核心）**：查 `0x8061A0` 佇列取出、select/encode/framing / 實際 send import；`0x806060` 僅證加入；`0x8438C0` slot 選擇容器 key domain 與實際 socket 關係；核對佇列和不同執行緒的時序。
- **T03（業務回覆）**：從真正 S→C opcode dispatcher 追 42 請求導致的回覆、接受/拒絕 handler；目前沒有任何原版證據把本機 fixture `42→43/69` 確立為原生配對。角色切換後各 UI writer 尚需從回覆回溯，不靠附近的 44 builder 猜測。
- **T05/T04/T06**：角色選擇後世界切換與角色初值、UI 控件身分均維持其主責，引用不修改。
- **原件與時序**：無真實 pcap、官方 Server、線上 session、runtime 對象，對 socket 是否實際發生／何時 flush 保留資訊缺失，不以離線靜態分析推測。

## 7. 共用三輪深入規則執行狀態

- **第1輪 T03-4：已實際執行**。`[FBA854]` source writer → vptr `0xC51748` → virtual +0x10 `0x8069A0` → channel-gated `0x8060D0` → copy + `0x806060` queue append／pending flag 的有界、全新可驗證呼叫鏈；符合重大新發現，因此本段依 02 規則結束。
- 第2輪 T03-4-2：**未啟動**；理由：首輪已越過重大有界進展門檻。
- 第3輪 T03-4-3：**未啟動**；同上。
- 交付不是宣稱已完整還原網路協定，更不是選角功能已可玩。

## 8. 定向原始反組譯摘錄（真實 BIN）

下列 `objdump` 行為定向讀取。注意 `objdump --start-address` 在函式中段會從指定地址開始反組，若非指令邊界則需結合前後函式核查；以下選取的起點均已由前後上下文確認。

### A. client 42 builder — VA 0x4a3b80–0x4a3bbd

```asm
004a3b80 <.text+0xa2b80>:
  4a3b80:	55                   	push   ebp
  4a3b81:	8b ec                	mov    ebp,esp
  4a3b83:	51                   	push   ecx
  4a3b84:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3b8b:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3b8e:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3b91:	b8 42 00 00 00       	mov    eax,0x42
  4a3b96:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4a3b9a:	88 4d fe             	mov    BYTE PTR [ebp-0x2],cl
  4a3b9d:	88 55 ff             	mov    BYTE PTR [ebp-0x1],dl
  4a3ba0:	75 15                	jne    0x4a3bb7
  4a3ba2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3ba8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3baa:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3bad:	6a 04                	push   0x4
  4a3baf:	8d 55 fc             	lea    edx,[ebp-0x4]
  4a3bb2:	52                   	push   edx
  4a3bb3:	6a 00                	push   0x0
  4a3bb5:	ff d0                	call   eax
  4a3bb7:	8b e5                	mov    esp,ebp
  4a3bb9:	5d                   	pop    ebp
  4a3bba:	c2 08 00             	ret    0x8
```

### B. object installation — VA 0x8046d6–0x804737

```asm
008046d6 <.text+0x4036d6>:
  8046d6:	00 6a 5c             	add    BYTE PTR [edx+0x5c],ch
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
  804727:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80472a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804731:	59                   	pop    ecx
  804732:	5e                   	pop    esi
  804733:	8b e5                	mov    esp,ebp
  804735:	5d                   	pop    ebp
  804736:	c3                   	ret
```

### C. object clear — VA 0x8045d9–0x804608

```asm
008045d9 <.text+0x4035d9>:
  8045d9:	00 33                	add    BYTE PTR [ebx],dh
  8045db:	db 8b 0d 54 a8 fb    	fisttp DWORD PTR [ebx-0x457abf3]
  8045e1:	00 3b                	add    BYTE PTR [ebx],bh
  8045e3:	cb                   	retf
  8045e4:	74 0e                	je     0x8045f4
  8045e6:	8b 11                	mov    edx,DWORD PTR [ecx]
  8045e8:	8b 02                	mov    eax,DWORD PTR [edx]
  8045ea:	6a 01                	push   0x1
  8045ec:	ff d0                	call   eax
  8045ee:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
  8045f4:	8b 86 a8 00 00 00    	mov    eax,DWORD PTR [esi+0xa8]
  8045fa:	3b c3                	cmp    eax,ebx
  8045fc:	74 09                	je     0x804607
  8045fe:	50                   	push   eax
  8045ff:	e8 08 cc 08 00       	call   0x89120c
  804604:	83 c4 04             	add    esp,0x4
  804607:	89                   	.byte 0x89
```

### D. virtual+10 target — VA 0x8069a0–0x8069f6

```asm
008069a0 <.text+0x4059a0>:
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
```

### E. data transfer into queue — VA 0x8060d0–0x806192

```asm
008060d0 <.text+0x4050d0>:
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
  80618e:	c2 08 00             	ret    0x8
  806191:	cc                   	int3
```

### F. queue insertion — VA 0x806060–0x8060cf

```asm
00806060 <.text+0x405060>:
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
```

### G. adjacent 44 builder — VA 0x4a3bc0–0x4a3bef

```asm
004a3bc0 <.text+0xa2bc0>:
  4a3bc0:	55                   	push   ebp
  4a3bc1:	8b ec                	mov    ebp,esp
  4a3bc3:	51                   	push   ecx
  4a3bc4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3bcb:	b8 44 00 00 00       	mov    eax,0x44
  4a3bd0:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a3bd4:	75 15                	jne    0x4a3beb
  4a3bd6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3bdc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a3bde:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a3be1:	6a 02                	push   0x2
  4a3be3:	8d 45 fe             	lea    eax,[ebp-0x2]
  4a3be6:	50                   	push   eax
  4a3be7:	6a 00                	push   0x0
  4a3be9:	ff d2                	call   edx
  4a3beb:	8b e5                	mov    esp,ebp
  4a3bed:	5d                   	pop    ebp
  4a3bee:	c3                   	ret
```

### H. adjacent A1 builder — VA 0x4a3bf0–0x4a3c41

```asm
004a3bf0 <.text+0xa2bf0>:
  4a3bf0:	55                   	push   ebp
  4a3bf1:	8b ec                	mov    ebp,esp
  4a3bf3:	83 ec 0c             	sub    esp,0xc
  4a3bf6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3bfd:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3c00:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3c03:	b8 a1 00 00 00       	mov    eax,0xa1
  4a3c08:	66 89 45 f4          	mov    WORD PTR [ebp-0xc],ax
  4a3c0c:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4a3c0f:	88 4d f6             	mov    BYTE PTR [ebp-0xa],cl
  4a3c12:	8a 4d 14             	mov    cl,BYTE PTR [ebp+0x14]
  4a3c15:	88 55 f7             	mov    BYTE PTR [ebp-0x9],dl
  4a3c18:	8a 55 18             	mov    dl,BYTE PTR [ebp+0x18]
  4a3c1b:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  4a3c1e:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  4a3c21:	88 55 fd             	mov    BYTE PTR [ebp-0x3],dl
  4a3c24:	75 15                	jne    0x4a3c3b
  4a3c26:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3c2c:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3c2e:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3c31:	6a 0a                	push   0xa
  4a3c33:	8d 55 f4             	lea    edx,[ebp-0xc]
  4a3c36:	52                   	push   edx
  4a3c37:	6a 00                	push   0x0
  4a3c39:	ff d0                	call   eax
  4a3c3b:	8b e5                	mov    esp,ebp
  4a3c3d:	5d                   	pop    ebp
  4a3c3e:	c2 14 00             	ret    0x14
```

## 9. 研究版本與完整性界限

所有新正面主張以 BIN 上述位元組及 call target 為界；T03-3 的 UI gate 沿用上一段已驗證筆記，不當成本輪新驗收。未取得執行時 socket 與後端，故任何 Server 回覆、轉場完整性、成功率及連線狀態均標為 unknown。