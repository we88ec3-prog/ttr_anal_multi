# T16-96 — KR WSASend 實際入口、buffer 完成邊界與 Quest 封包未閉合之證據（BIN-first）

研究者 `chatgpt-web roy`。2026-10-28 Asia/Taipei。只進行 KR 原始 BIN 離線唯讀分析；沒有執行、修改或上傳遊戲二進位檔。原稿為 T16-96 三輪記錄。

## A. 來源識別及同步

- GitHub repo: `we88ec3-prog/ttr_anal_multi`，目標 `t16/roy/chatgpt-web`。
- 本次研究前 compare `main...t16/roy/chatgpt-web` 為 `ahead_by=5, behind_by=0`，`main` HEAD `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355`；不需要做新 merge commit。T16-95 已在分支。
- `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- VA/raw：`.text` RVA/VA `0x401000` / raw `0x400`，`raw=VA-0x400C00`。對所引程式碼以 BIN bytes 直接 objdump；名字皆為研究用暫名。
- 保留 T02 socket/framing 的主責，不修改其原稿；T16 只確定當前 Quest 候選連線的證據邊界。

## B. 第一輪 T16-96：從 import 反查原生 WSASend caller（重大進展）

精確 little-endian immediate 引用掃描在 `.text` 找到 `0xBD25B8` 一處：`0x806912` 的 `FF 15 B8 25 BD 00`，是 `call DWORD PTR [0xBD25B8]`。原始 PE import 表將此 IAT 項識別為 **WSASend**；並於 `0x806A4E` 有 `0xBD25BC` 的 **WSARecv** 直接呼叫。這是原始 Client 真實的 Winsock API 呼叫點，不是由 `WS2_32.dll` 字串存在推測。

`0x8068B0` 封裝的 `this=ECX`、`[EBP+8]` 通道參數、`[EBP+0xC]` data 長度/WSABUF 相關參數需以呼叫端反查繼續確證型別。本段確認 `[ESI]` 會被當 socket handle；構建位於 `[ESI+0xA050]` 的重疊 I/O 狀態與 WSABUF 類內嵌欄位：`0x8068FC` 寫入資料指標 `EDI` 到 `[base+0x18]`，`0x806905` 寫入長度到 `[base+0x14]`，`0x80690B` 到 `0x806912` 依逆序 push 七個參數進 WSASend。此解讀須以 caller 提供的 EDI/EDX 來源補證，不把 `0x8068B0` 生硬地稱為特定 Quest socket。

- 入口 gate：`0x8068BB` 確認非空 buffer pointer；`0x8068C3` 確認非零 length；`0x8068D1` 若 `[ESI+0xA0A8] != 0`，跳 `0x806993` 返回 -1。
- 發送：`0x806912` 真正 WSASend；`0x806920` 判 `eax == -1`，失敗時 `0x806925` 呼叫 `WSAGetLastError`（`[0xBD25CC]`）。
- Windows async：錯誤值 `0x3E5`（997，WSA_IO_PENDING）走 `0x806961`，呼叫 `[0xBD2284]` 並回傳 `2`；非待處理錯誤返回 `0`，可選記錄 error；同步正常進入 `0x80697A` 呼叫 `[0xBD2284]`，回傳 `1`。
- 其他 return：無效的參數/已在發送中返回 `-1`。

本輪具重大進展：T16-95 只確認 frame accumulation；此輪首次以原生 import + instruction boundary 識別具體 socket send API 及本地錯誤／pending／success 分流。但尚無 `0x807A70`／`0x807830` buffer → `0x8068B0` 的已證 caller/field flow；**不能聲稱 Quest 候選 payload 已真正發送**。

## C. 第二輪 T16-96-2：frame buffer 已送出位元組回收器

`0x8077B0` 讀 `[ESI+0x500C]` 累積長度；若成功完成 bytes 數 `EDI` 為負或大於未送出數，返回 false；否則 `0x8077C8` 扣除 `[ESI+0x500C]`。尚有殘餘時，先 `0x8077D2` 從 `[ESI+0x5004]` 調整 write cursor，再 `0x8077FD call 0x89DBD0` 搬移 buffer 中未消耗資料（左移），保持緩衝區連續。若全部消耗，`0x807810` 將 `cursor` 指向 `[ESI+4]` 起始。最後釋放 `[ESI]` 同步鎖：`0x807805 / 0x807819 call [0xBD2248]`。

和 T16-95 已確證的 `0x807A70` 及 `0x807830` 一起有**同一個通道 `+0x5004/+0x500C` buffer accounting 的 producer→post-consume 結構配對**：前者加長與移動 cursor，後者依已消費 count 扣長/compaction。不過 `0x8077B0` 的 caller 與 `0x8068B0` 之間仍缺少直接可驗證 xref，不可把此扣除動作直接稱為 WSASend 完成 callback，更不可宣稱每次呼叫已網路送達。

### 關於錯誤的 wire opcode 推定

`0x807A70` 在 `0x807A8A` 設立暫存 `0x1A68`，但 `0x807AE9` 寫入 buffer 的來源是 `[EBP-4]` 長度相關 word / DWORD；原始指令不支持「wire 第一個 word 就是 0x1A68」這個等式。因 buffer 筆頭、方向、flags 尚未閉合，Quest 的 `49 00 01 00` 目前僅原生內部 queue payload 確認，不能從它推導 Quest opcode。另一模式 `0x807830` 使用 XOR `0xB6`，但不能直接視為全部送出資料的加密算法。

## D. 第三輪 T16-96-3：反向 caller 與封包邊界反證

本輪以原始 `.text` 進行 `E8 rel32` 精確目標掃描：對 `0x8068B0` 沒有找到直接 `E8` caller；同時掃描 4-byte little endian absolute immediate (`0x8068B0`) 在 `.text` 也無直接命中。相對地 `0x8077B0` 在相同直接 E8 與 absolute scan 未發現直接 caller。**掃描陰性只界定這兩種引用形式，在虛擬方法、間接調用、cross-section pointer、資料表、Thunk 等情況下不能解讀為「此函式無人使用」**。

此結果仍未足以把 `0x8068B0` 的 WSASend `this` 與 `[+0x500C]` frame owner 接成同一實例。下一步須對 I/O completion callback、channel 建構時的 method registration、`0x8077B0` vtable/函式指標和 `0x8068B0` callsite 做更大範圍的型別/CFG 還原。以此三輪視為 T16-96 一個研究段落；停止原因：第一輪已找到真實 socket send 和有界結果分流，第二輪確認 frame 回收，第三輪反證 **無法僅靠 direct refs 閉合它們**，保留下一段明確缺口。

## E. 目前玩家情境與 Client↔Server 矩陣

| 玩家情境 | Client 本地 gate | C→S 原生證據 | S→C 回覆 | Client 可見結果 | 伺服器相容需求／未知 |
|---|---|---|---|---|---|
| Quest 相關候選互動（T16-93） | `[ESI+5]!=0`、全域抑制旗標允許 | `49 00 01 00` 已有條件排入內部 queue（T16-94），有條件被 T16-95 serializer 接收；尚未證明此 payload 到達 `0x8068B0` | unknown | NPC/UI 與 controller 消費端已有局部證據 | 不能據此發明 quest request opcode |
| 內部 send buffer 有待處理 bytes | 送出包裝器檢查 handle、非零長度、in-flight flag | `0x8068B0 → WSASend 0x806912`：**真正 socket API 入口存在**；並非已確認這是該 Quest payload 的發送 | unknown | 同步 success / pending / failure 由 return 1/2/0/-1 區別 | 需 completion callback 和 socket-queue 關聯 |
| frame 消費/回收 | `0<=consumed<=pending` | `0x8077B0` 減 `+0x500C` 並 compact；真正回傳 bytes 來源 unknown | unknown | pending buffer 被消耗或重置 cursor | 需追 completion/event loop |
| Quest16→Quest15 解鎖並接取 | unknown | Quest accept opcode/length/fields unknown | Quest dynamic writer/dispatcher unknown | unknown | 原版 Server 規則未知，待用 KR traffic 或 Client handler 驗證 |

## F. 有界 C++ 偽碼（供導航，非原始可編譯來源）

```cpp
int native_send_wrapper_8068B0(Context* ctx, Channel* ch, void* ptr, uint32_t len, uint32_t* out) {
  if (!ptr || !len || ch->flag_A0A8) return -1;
  // Initializes ch->overlapped_A050, WSABUF pointer/size and sends via ch->socketAt0
  int r = WSASend(ch->socketAt0, /* built WSABUF */, 1, out, 0, /* overlapped */, 0);
  if (r == SOCKET_ERROR) {
    int err = WSAGetLastError();
    if (err == WSA_IO_PENDING) return 2;
    return 0;
  }
  return 1;
}

bool compact_pending_8077B0(Channel* ch, int consumed) {
  if (consumed < 0 || consumed > ch->pending500C) return false;
  ch->pending500C -= consumed;
  if (ch->pending500C) { /* memmove tail to ch+4 and adjust cursor */ }
  else ch->cursor5004 = &ch->bufferAt4;
  return /* bounded success */;
}
```

## G. 下一正式段 T16-97

1. 以 `0x8068B0` 與 `0x8077B0` 的非直接引用/初始化反查其 caller、callback registration、WSAOverlapped completion 的實際 status handling，明確 frame producer→socket 關聯。
2. 以 `0x807A70` 真實 bytes 與 `0x807830` XOR 分支重建封包 boundary；確定哪一模式才會承載 Quest 候選 `49 00 01 00`。
3. 獨立從 T02 S→C dispatcher 追查 Quest 接受／拒絕／完成 handler 與 dynamic writer；不得把 QuestInfo XML 靜態 owner 誤用為 dynamic quest state。

## H. 原始 BIN 組語附錄（source bytes 直接反組譯）

### Direct WSASend caller, 0x8068B0 through 0x80699A

VA `0x008068B0`–`0x0080699B`，raw `0x00405CB0`–`0x00405D9B`。

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
  80699a:	c2               	ret    0x10
```

### Frame buffer post-send advance and compaction, 0x8077B0

VA `0x008077B0`–`0x00807824`，raw `0x00406BB0`–`0x00406C24`。

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
```

### Frame build, 0x807A70

VA `0x00807A70`–`0x00807B30`，raw `0x00406E70`–`0x00406F30`。

```asm
00807a70 <.data+0x406e70>:
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
  807b2e:	ff 15        	call   DWORD PTR ds:0xbd2248
```

### Alternate frame writer tail, 0x8079F0

VA `0x008079F0`–`0x00807A6D`，raw `0x00406DF0`–`0x00406E6D`。

```asm
008079f0 <.data+0x406df0>:
  8079f0:	8b 85 f8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1008]
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
  807a6c:	c2               	ret    0x8
```
