# T03-7 — KR Client 接收流 framing、解碼、payload copy 與業務投遞缺口

- 建檔時間：2026-10-28T22:43:18.429921+08:00；研究者：chatgpt-web roy。
- 來源唯讀：`/mnt/data/Tartaros.bin`；實測 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 工作分支：`t03/roy/chatgpt-web`；先核對 GitHub `main` 相對分支 `behind_by=0`，因此本次開工沒有額外 Merge commit。
- 原生 x86 使用 `.text` VA 基址 `0x401000`、raw `0x400`；本節地址 raw=VA-`0x400C00`。反組譯以 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 讀原 BIN bytes，**非反編譯推測**。若使用 Ghidra 須重新核對 function body 非連續邊界。
- 正式段號依使用者指定為 `T03-7`；已完成 `T03-6` 原稿 `kr-temp-roy/20261028-223919-chatgpt-web-roy-T03-6-wsasend-completion-boundary.md`，本次不重新宣稱其發現。

## 1. 上一段入口，原始接收完成到 `0x807B40`

前段 `0x806DE4` 對 recv overlapped context (`channel+0xA030`) 分支，`0x806E08: call 0x807B40`，其參數與收包 channel 身分由 T03-6 留存；本次僅以此為有界入口，不另宣稱原版 Server opcode。

新核得 `0x807B40` 初始以 `EDX` 作接收緩衝物件，`ECX` 新增位元組數：`0x807B88 mov edi,edx`、`0x807B8A add [edi+0x5000],ecx`；`0x807BA2 cmp eax,4`，不足四 byte 時走 remainder。`0x807BB0 movzx esi,word ptr [ebx]` 取 16-bit 長度；長度 0 或大於 `0x1000` 則至 `0x807E1D` 失敗；**不要誤說函式已保證所有來源緩衝安全**。

### 1.1 多個 transport magic 與前綴大小（原生已確認）

| 16-bit magic 位址與值 | 前綴大小 | 處理模式 | 注意 |
|---|---:|---|---|
| `0x807BDA`: `0x2633` | 8 | stack+0x18 設為1 | 與其他 decode 分支不同；不能直接當 wire 業務 opcode |
| `0x807BFC`: `0x0BBB` | 6 | stack+0x1C 設為1 | 對應後續 checksum / XOR branch |
| `0x807C18`: `0x1A68` | 4 | 普通 buffer path | 與 T03-5 的 4-byte prefix 型態吻合，但未證明實際該次 packet |
| `0x807C22`: `0x22D7` | 4 | 普通 buffer path | 同前 |
| 不符合上述 magic | 初始值4 | 未直接 reject，依預設 route 繼續 | **不可**稱為 header whitelist |

`0x807C34` 將 `esi`(declared payload length)+ header size 做和，`0x807C3C` 比對本次已累積剩餘長度；不足便跳到 `0x807DDA` 保存 remainder。這是 stream framing，不是遊戲業務 command。`0x807C93..0x807CC5` 對 payload 起迄地址與緩衝邊界比較，不能抽離個別比較稱為完整安全防護。

## 2. 已辨識的 payload 解碼與驗證

- **0x2633（8 bytes）**：`0x807CD2` 起對 payload[0] XOR `0x7C`，後續用前一個已解碼 byte 做滾動 XOR；`0x807D0E` 呼叫 `0x727190`，非零結果跳過送交 helper，零時用 `stack+0x102C` buffer。這裡的 `0x727190` 仍需函式語意確認；**不可直接命名為確定的壓縮解壓規格**。
- **0x0BBB（6 bytes）**：`0x807D33` 先 XOR payload[0] `0xB6`，其餘 byte 依前一個明文 XOR；`0x807D5F` 累加明文 byte 並只保留 16-bit，`0x807D66 cmp word ptr [ebx+4],cx`；不符跳過 payload-copy。此為原始機器碼證實的 checksum check，不是官方 Server 回覆成功碼。
- **4-byte plain branch**：`0x807D77 push edi`→`0x807D7A call 0x807E50`，指向原 frame payload；在這個有界 branch 不是解密後才投遞。
- **payload-copy helper** `0x807E50` 在 `ESI>0x1000` 時回傳 false；正常時 `memcpy(EDI+8, src, ESI)` 且記錄 `DWORD [EDI+4]=ESI`，回傳 true。這裡是拷貝至 intermediate buffer，**不是直接 T03 業務 handler**。

## 3. frame 消耗、callback 閘門與待追接口

`0x807D7F..0x807DB2` 在 payload-copy 後依 interim 結構狀態，可能呼叫 `0x804310→0x8076F0` 或 `0x489920→0x8040A0`，這兩條後續是**下一段重點，尚未由本輪證明業務 dispatch 的實際 target / class type**。不可把 callback 消息推斷為選角批准/拒絕。

`0x807DB2` 重新取 frame 長度，加上前綴長度推進 EBX (`0x807DC7 add ebx,edx`)。只要剩餘 ≥4 bytes，會回到 `0x807BB0` 嘗試處理同個 recv buffer 中下一筆；尾部由 `0x807E06 call 0x8912F0` 將未完成 remainder 移至 buffer 起點，並更新末尾指標。此程序支援一批接收資料含多 frame 或不完整 frame 的有界模型，但跨異常／重試細節未全數核對。

`0x807C7C` 使用全域 `0xFE3358` 作中繼，`0x807C81 call 0x8075B0`；此函式會分配大小 `0x100C` 的節點、初始化 0x1000 byte 緩衝、插入列表，並從佇列取元素供下一階段處理。單憑它不能認定這就是 T03 command42 的 response handler。

## 4. 從玩家端角度的有界矩陣

| 玩家情境 | Client C→S | 此段 S→C bytes | 解碼/複製 | T03 結果 UI | Server 原始回覆 |
|---|---|---|---|---|---|
| 選角按下確認 | 前段已確認 builder `42 00 XX YY`、有 gate 的 queue/transport | **尚無實際回覆封包擷取可證明配對** | 一般 transport 可按 4/6/8 header 辨識及處理 | 未確立 | 資訊缺失 |
| 接收到以 `0x0BBB` 標記的資料 | 不必假設是選角回覆 | 長度+6-byte header+checksum | XOR 還原、核對 checksum；有效時送 intermediate copy | 尚未追到業務事件 | unknown |
| 4-byte framing 接收 | 不必假設是角色資料 | 長度+4-byte header | 直接拷貝 payload 至中繼 | unknown | unknown |
| 收到不足一個完整 frame | 不適用 | buffer 仍保留部分 bytes | remainder 待後續補齊 | 未觀察到已投遞 | unknown |

## 5. 三輪深入規則與進度門檻

- **第1輪 `T03-7`：已執行。** 取得 T03-6 之後原生 receive stream framing，四種 magic / 4、6、8-byte header、checksum 與 XOR、payload 中繼、loop/remainder，構成「recv completion → frame parser → 內容中繼 → 後續投遞入口」的重大且可追溯進展，相較只定位 `0x807B40` 新增多條資料/條件鏈。
- **`T03-7-2`：未啟動**，因第一輪已達重大發現門檻；並非宣稱完整選角結果已完成。
- **`T03-7-3`：未啟動**，同上。

## 6. 源碼級有界偽碼（非遊戲伺服器協定規格）

```cpp
// Based strictly on native branches listed above; omitted error/SEH state.
recv_end += new_bytes;
while (available >= 4) {
    uint16_t n = read_u16(frame);
    if (n == 0 || n > 0x1000) return failure;
    uint16_t magic = read_u16(frame+2);
    unsigned prefix = magic==0x2633 ? 8 : magic==0x0BBB ? 6 : 4;
    if (available < n + prefix) break;
    // 0x2633, 0x0BBB: gated transform; 0x0BBB verifies checksum at frame+4.
    // Other magic types default to 4-byte prefix; not necessarily rejected.
    intermediate = copy_or_decode_payload(frame+prefix,n);
    // queued output / message delivery: precise T03 target remains unproven.
    frame += n + prefix;
}
compact_partial_frame();
```

## 7. 反證界線與跨 Task

- 沒有 Server 原碼、實際抓包或此 recv frame 對應到 `command42` 的原生資料流，因此不推論 `42→43/69`；Fixture 配對仍為 AI 替代。
- `0x807B40`、`0x807E50` 屬 T02 通用 transport decode 類工作，T03 只引用，無權改 T02 owner/catalog/實作。
- `0x807D7F` 下游 `0x804310/0x8076F0/0x489920/0x8040A0` 是下一輪進入具體業務 dispatcher 的入口；T05 才有真正世界轉場主責。
- 此次無目標程式啟動、附加或 patch，未上傳 BIN；機器碼出處含於下列原樣摘錄，可逐地址重現。

## 8. 第一手原始反組譯選段（局部）

### receive-entry
```asm
00807b40 <.data+0x406f40>:
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
  807c44:	f6       	test   BYTE PTR ds:0xfe3354,0x1
```

### decode-and-dispatch
```asm
00807ccb <.data+0x4070cb>:
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
```

### remainder-buffer
```asm
00807db2 <.data+0x4071b2>:
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
```

### payload-copy
```asm
00807e50 <.data+0x407250>:
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
```