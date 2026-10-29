# T16-97 — KR completion-port event consumer → send-buffer compaction (BIN-first)

研究者 `chatgpt-web roy`；2026-10-28 22:52:41 Asia/Taipei。目的為追查 T16-96 中已識別的 WSASend wrapper `0x8068B0` 與 frame 回收 `0x8077B0` 的原生上下游。**本段重大新發現：已從 native completion dispatcher `0x806CF0` 確認 send-side OVERLAPPED address 身分比較與 `0x8077B0` 的直接呼叫，不再只是 +0x500C producer/consumer 的間接類比。尚未證明 Quest 訊息已透過 socket 傳送。**

## 0. Git、來源與範圍

- 每次開工遠端查核 `main...t16/roy/chatgpt-web`：main `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355`；工作分支 behind=0、ahead=6，merge base 即 main HEAD。無需建立額外 merge commit；同步已確認。
- `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，長度 12,472,320 bytes；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 來源為靜態唯讀 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400C00` 與原始 E8 rel32 交叉掃描（候選指令入口還需組語確認）；`.text` raw offset = VA−0x400C00。下列針對 `.text` 的 VA/raw 以此換算；其他 section 不套用。
- T16-93～96 的 GitHub 研究原稿僅用於定位與限制，不取代本次原生位元組；未執行、修改、附加或上傳任何客戶端二進位資料。

## 1. 第一輪 T16-97：新確認完成事件到 send frame buffer 的原生連接（重大發現）

從 `0x806CF0` 函式入口可見 completion-event loop：讀取全域 `[0xFE33B8]`、呼叫 IAT `[0xBD2274]`，成功回傳後依 `completion key` 與 overlapped pointer 分流。IAT API 名稱仍應由相符 PE import table 獨立覆核；從參數形態與分派機制可標記為 **IOCP completion retrieval 候選**，不可僅以函式形態聲稱已驗證精確名稱。

在 `0x806E7D` 的分支中，將 event 取得的 `EDX` 與 `[EAX+0xA050]` 位址比對；**相等才進 send-side 路徑**。之後 `0x806E8B` 計入 `[EBX+0x28]`、`0x806E8E` 增加 `[EBX+0x38]`。只有 `[EAX+0xA0AC] != 0` 時，程式將 `ESI = EAX+0x501C`、`EDI=ECX (completion count)`，於 `0x806EA1` **直接 `call 0x8077B0`**。後者在 T16-96 已確認消費 `[channel+0x500C]` 並依位元組數 compact，從此可認定 completion dispatcher → send pending frame consumer 的一段真實連接。

精確資料路徑：`[EBP-0x1C]` = completion-associated channel instance（經 dispatcher 保存在 local），`EDX=[EBP-0x20]` = completion-overlapped pointer，`ECX=[EBP-0x24]` = transferred bytes 候選；`0x806E7D` 比 `EDX` 與 `EAX+0xA050`；`0x806E99` 設 `ESI=EAX+0x501C`，`0x806E9F` 把 `ECX` 搬到 `EDI`，`0x806EA1` 呼叫 buffer consumer。

## 2. 第二輪：與 WSASend 的 OVERLAPPED identity 配對與下游通知

T16-96 的原生 `0x8068B0` 在 `0x8068DE` 產生 `EAX=channel+0xA050`，清空該區起始多個 DWORD；`0x8068FC` 設 WSABUF 的 buffer pointer 到 `[EAX+0x18]`，`0x806905` 寫資料長度到 `[EAX+0x14]`；`0x806912` 透過 IAT `[0xBD25B8]` 呼叫 WSASend（T16-96 已經與 PE import cross-check）。完成事件的 `0x806E7D` 比較恰好也使用 `channel+0xA050`，**補齊了 send-side OVERLAPPED instance identity 的跨函式對應**。

對直接 call 的靜態全 `.text` E8 rel32 掃描：`0x8068B0` 命中 0 個（此函式仍可能經 vtable 或 function pointer 間接呼叫）；`0x8077B0` 命中 1 個，`0x806ea1`；`0x8061A0` 命中 2 個，`0x804ad6, 0x805228`。這是有限掃描而非否定所有 indirect callers。

同一 send-completion case 下：`0x806EAB` 以 `[channel+0xA028] > 0` 設置 `[channel+0xA024]` 旗標；`0x806EBD` 從 channel 建 `+0xA0B8` 地址，`0x806EC4` 呼叫 IAT `[0xBD227C]`（API 身分待 import 對照）；事件 loop 返回 `0x806D30`。因此不能把 `0x8077B0` 當作「收到 Quest 接取成功」：它只處理網路發送完成/緩衝消費。

另 `0x806E04` 收到不同 overlapped identity `[channel+0xA030]` 的事件後呼叫 `0x807B40`，與 `0x806E7D` 的 send-side 狀態分支相互區分；此分支尚不能稱為 Quest receive handler。

## 3. 三輪規則與反證／未解

第一輪已取得重大且可由原始 bytes 直接重現的 `completion dispatcher → OVERLAPPED 身分比較 → 0x8077B0 pending send buffer consumer`，第二輪擴大查明 `WSASend` wrapper 產生的同一 `channel+0xA050` identity。此為完整且有界的原生 socket completion 行為進展，按 02 規則第三輪**未啟動（已達重大發現門檻）**，不是捏造第三輪工作。

仍未閉合：

- `0x8068B0` 可能由 function pointer/vtable 呼叫；本輪沒有把 frame builder `0x807A70/0x807830` 的**同一 instance**嚴格追到 `WSASend` 實際 callsite。
- Quest 4 bytes `49 00 01 00` 是否為真正 wire payload、其進入 socket 的特定實例與時序，及 wire opcode/domain，仍 unknown；不能以 generic TCP 完成事件推認 Quest 送達 Server。
- S→C Quest reply dispatcher → state cache writer → UI/NPC consumer 和 Quest16→Quest15 仍 unknown。原版 Server 接受／解鎖規則不在 Client 原件可確認範圍。

## 4. 玩家情境矩陣

| 玩家事件 | Client gate / producer | C→S 實證 | S→C 實證 | 本地結果 | 待開發 Server / unknown |
|---|---|---|---|---|---|
| 操作 Quest/NPC 候選入口 | T16-93 的 conditional `0x00010049`；T16-94/95 佇列 | 局部入列/封裝確認；Quest wire opcode、socket 實例仍 unknown | Quest 回覆 unknown | 本地 Quest static reader 與佇列分離 | 需識別業務 request/response |
| 網路 send completion | WSASend wrapper 準備 `channel+0xA050` | `0x806CF0` completion dispatcher 命中該 OVERLAPPED identity，再 `0x8077B0` 扣緩衝 | 非 Quest 業務回包 | 出站 pending bytes 的本地回收已驗證 | 不等同 Server 已處理業務請求 |
| Quest16 完成並顯示 Quest15 | QuestInfo 靜態讀者已確認 | unknown | unknown | 動態 writer / NPC 更新 unknown | 相容伺服器需另依 Client 實際封包確定接口 |

## 5. 下一段 T16-98

1. 靜態尋找 `0x8068B0` 的 vtable/function-pointer references（非直接 E8），確認 frame builder `+0x500C`、completion `+0xA050`、WSASend 使用的 channel 物件同型、同實例、同時序；查送出條件/失敗重試。
2. 並行轉向 Quest 業務 `S→C` dispatcher → 動態 writer；不能只繼續盤點通用網路函式而忽略 T16 的 Quest 主題。
3. 如無外部原生封包，保持 opcode、伺服器決策未知，不捏造可玩完成狀態。

## 6. 原始 x86 反組譯摘錄（直接從相符 SHA BIN）

### VA 0x8068B0–0x80699D, raw 0x405CB0–0x405D9D

```asm
008068b0 <.data+0x405cb0>:
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
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2 10 00             	ret    0x10
```

### VA 0x806CF0–0x806DC0, raw 0x4060F0–0x4061C0

```asm
00806cf0 <.data+0x4060f0>:
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
```

### VA 0x806DB0–0x806F2E, raw 0x4061B0–0x40632E

```asm
00806db0 <.data+0x4061b0>:
  806db0:	00 6a 02             	add    BYTE PTR [edx+0x2],ch
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
```

### VA 0x8077B0–0x8078A0, raw 0x406BB0–0x406CA0

```asm
008077b0 <.data+0x406bb0>:
  8077b0:	53                   	push   ebx
  8077b1:	8b 1e                	mov    ebx,DWORD PTR [esi]
  8077b3:	53                   	push   ebx
  8077b4:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8077ba:	85 ff                	test   edi,edi
  8077bc:	78 5b                	js     0x807819
  8077be:	8b 86 0c 50 00 00    	mov    eax,DWORD PTR [esi+0x500c]
  8077c4:	3b c7                	cmp    eax,edi
  8077c6:	72 51                	jb     0x807819
  8077c8:	2b c7                	sub    eax,edi
  8077ca:	89 86 0c 50 00 00    	mov    DWORD PTR [esi+0x500c],eax
  8077d0:	74 3e                	je     0x807810
  8077d2:	8b 86 04 50 00 00    	mov    eax,DWORD PTR [esi+0x5004]
  8077d8:	8d 8e 04 50 00 00    	lea    ecx,[esi+0x5004]
  8077de:	8d 56 04             	lea    edx,[esi+0x4]
  8077e1:	2b c7                	sub    eax,edi
  8077e3:	3b d1                	cmp    edx,ecx
  8077e5:	73 32                	jae    0x807819
  8077e7:	3b c2                	cmp    eax,edx
  8077e9:	72 2e                	jb     0x807819
  8077eb:	3b c1                	cmp    eax,ecx
  8077ed:	73 2a                	jae    0x807819
  8077ef:	89 01                	mov    DWORD PTR [ecx],eax
  8077f1:	2b c6                	sub    eax,esi
  8077f3:	83 e8 04             	sub    eax,0x4
  8077f6:	50                   	push   eax
  8077f7:	8d 44 37 04          	lea    eax,[edi+esi*1+0x4]
  8077fb:	50                   	push   eax
  8077fc:	52                   	push   edx
  8077fd:	e8 ce 63 09 00       	call   0x89dbd0
  807802:	83 c4 0c             	add    esp,0xc
  807805:	53                   	push   ebx
  807806:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80780c:	b0 01                	mov    al,0x1
  80780e:	5b                   	pop    ebx
  80780f:	c3                   	ret
  807810:	8d 4e 04             	lea    ecx,[esi+0x4]
  807813:	89 8e 04 50 00 00    	mov    DWORD PTR [esi+0x5004],ecx
  807819:	53                   	push   ebx
  80781a:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807820:	32 c0                	xor    al,al
  807822:	5b                   	pop    ebx
  807823:	c3                   	ret
  807824:	cc                   	int3
  807825:	cc                   	int3
  807826:	cc                   	int3
  807827:	cc                   	int3
  807828:	cc                   	int3
  807829:	cc                   	int3
  80782a:	cc                   	int3
  80782b:	cc                   	int3
  80782c:	cc                   	int3
  80782d:	cc                   	int3
  80782e:	cc                   	int3
  80782f:	cc                   	int3
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
```