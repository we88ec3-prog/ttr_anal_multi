# KR T16-85 — 六個 UI 子項的容器尺寸調整、可重用項目與後續虛方法消費

- 研究日期：2026-10-28 20:02:58 UTC+08:00（Asia/Taipei UTC+08:00）；研究者 `chatgpt-web roy`。
- 僅 KR；原始資料唯讀，未執行、修改、附加 Client。GitHub 既有研究作導航，以下新指令由本次原始 BIN objdump 產生。
- KR BIN：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE32 x86；`.text` VA `0x00401000`, file offset `0x400`, size `0x007D01F0`，僅在 `.text` 以 `raw=VA−0x00400C00` 換算。原始封包流量與原版 Server 未取得。

## 1. 第 1 輪 T16-85：由 T16-84 的 0x630E40 進入 0x408920

上游 `0x630E49` 先取 `[this+0x124]` 子控件指標，再取其 `+0xCC` 容器；非零才以 `push 6; push container; call 0x408920`。此處 x86 stack arguments 對應 `0x408920` 的 `[ebp+8]` 容器、`[ebp+0xC]` 目標項目數 `6`。

可由入口直接證明：`count=([container+0xAC]-[container+0xA8])/4`；`count==target` 或 `[container+0xA4]==0` 則返回 false。否則呼叫 `0x408B60`；若 count>target 刪除／回收尾部項，若 count<target 藉 `0x408BF0` 和容器 vtable `+0x70` 增建／取得項目，`0x443D10` 將項目插入指標陣列；末段重設每項 `child+0x20` 序號，並寫 `[container+0xE4]=target+1`，返回 true。

兩個分支的關鍵 raw 對照：`0x408920→0x7D20`; `0x408980→0x7D80`; `0x408A43→0x7E43`; `0x408A6D→0x7E6D`。此功能是 UI 子項容器調整，無實際 Quest opcode 證據。

## 2. 第 1 輪延伸：減少、增加以及可重用子項的邊界

### count > target（尾部縮減）

- `0x408980..0x408991` 讀 `[container+0xAC]-4` 最後子項，再呼叫容器 vtable `+0x74`。
- `0x408993..0x408A00` 將項目保存到 `[container+0xB8..+0xC0]` 管理的另一個指標陣列候選，該陣列擴容呼叫 `0x4DEAB0`。
- `0x408A07..0x408A35` 把 active end pointer `+0xAC` 減少 4 並迴圈到指定數量；沒有動態執行觀察，不推定其 UI 可見副作用。

### count < target（新增／重用）

- `0x408A43` 呼叫 `0x408BF0`，後者優先查 `[esi+0xB8..+0xBC]` 的回收指標範圍，空時由 `[esi+0xA4]` 所屬 factory vtable `+0x28` 取得，非空時呼叫該 factory vtable `+0x2C`；具體 factory 物件類別 unknown。
- `0x408A4C..0x408A55` 呼叫容器 vtable `+0x70` 對取得的子項做初始化候選。
- `0x408A57..0x408A65` 經 `0x443D10` 追加到 active 陣列，並重複至 count==target。

### 收尾

- `0x408A74..0x408A83` 每項存 `child+0x20=index`；`0x408A85..0x408A93` 寫 `+0xE4=target+1`，傳回 AL=1；入口 count 同值或 factory 空時 `0x408A96..0x408A9D` 傳回 AL=0。

## 3. 第 2 輪 T16-85-2：重用／回收路徑與 0x408B60

`0x408B60` 查 `[esi+0xDC]` 與 `[esi+0xE0]`，掃描 `[esi+0xA8..+0xAC]` 子項指標，符合不同路徑時呼叫現有對象 vtable `+0xA0` 並清 `+0xDC`。可證實是容器附屬對象引用管理，不能在未核對 factory/owner 身分前斷言正式析構或 Quest state 清除。

## 4. 第 3 輪 T16-85-3：子項回填、虛呼叫與空值依賴

呼叫端 `0x630E40` 再從 `[list+0xA8]` 以 `i=0..5` 取出子項，無效索引／null list 時局部路徑設定 `ecx=0`，隨即 `mov [this+0x128+4*i],ecx; mov eax,[ecx]`，以 vtable `+0x198` 傳入 `0xC739`。因此雖有 resizing call，若 factory 或子項不滿足正常不變量，**靜態分析不能保證不會 null dereference**；不能宣稱程式已內建完整安全保護，也不能單憑其存在推論 Server quest 事件。

`0x630EC1..0x630F01` 後續遍歷 UI 層 `+0x64` 鏈表、呼叫符合條件的對象虛方法 `+0x30`，再呼叫 list 的 vtable `+0x128`；`0x630F02..0x630F1D` 將 `this+0x104/+0x108` 兩個控件的 `+0xC9` byte 置 0（前段僅見其中一個，這次確認兩個）。這條 consumer 只支持 UI 子項管理與本地控件狀態，不支持 Quest packet 命名。

## 5. 玩家情境與雙向封包證據矩陣

| 情境 | Client gate / 本地處理 | C→S | S→C | Quest/UI 結果 | 相容 Server 待開發 |
|---|---|---|---|---|---|
| 子視窗初始化 | 本地 list 存在、factory+0xA4 非零、resize 目標六筆；呼叫控件虛方法 | unknown | unknown | 6 個 UI 子項指標/索引調整已確認；具體畫面未知 | 不從此推定業務封包 |
| 玩家點選接取 Quest | 真正 callback 未定位 | unknown | unknown | Quest cache writer unknown | 接取確認/拒絕之原生欄位待證 |
| Quest16 完成→Quest15 可接 | unknown | unknown | unknown | cache/NPC 對應 unknown | Server 原版決策不在 Client 原生證據之內 |

## 6. 三輪判定與下段方向

- 第一輪建立 `0x630E40→0x408920` 的完整容器定長調整路徑，涉及增減雙路、factory 及重用陣列。
- 第二輪確認 `0x408B60` 對暫存附屬對象的釋放／清引用候選路徑及依賴條件，不能誤稱 Quest 刪除。
- 第三輪確認後續 `child+0x20` 編號、六筆虛呼叫、兩個控件旗標清零，以及正常路徑依賴，完成局部功能鏈，因此本段結束。
- 下一段 T16-86 不應再以一般 UI 容器 helper 作主線；優先從 Quest cache 結構／NPC click handler 或具實際 byte domain 的收包分派入口，反查網路 producer/consumer。若需要本地 UI 顯示的交叉驗證，再核對 `child vtable+0x198` 的真正動態型別。

## 7. BIN 原始 assembly（完整選定函式、供重現）

### 0x408920: six-item resize, downsize and grow
`.text` raw `0x7d20` → `0x7ea0`

```asm
00408920 <.text+0x7920>:
  408920:	55                   	push   ebp
  408921:	8b ec                	mov    ebp,esp
  408923:	51                   	push   ecx
  408924:	53                   	push   ebx
  408925:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  408928:	57                   	push   edi
  408929:	8b bb ac 00 00 00    	mov    edi,DWORD PTR [ebx+0xac]
  40892f:	2b bb a8 00 00 00    	sub    edi,DWORD PTR [ebx+0xa8]
  408935:	c1 ff 02             	sar    edi,0x2
  408938:	3b 7d 0c             	cmp    edi,DWORD PTR [ebp+0xc]
  40893b:	0f 84 55 01 00 00    	je     0x408a96
  408941:	83 bb a4 00 00 00 00 	cmp    DWORD PTR [ebx+0xa4],0x0
  408948:	0f 84 48 01 00 00    	je     0x408a96
  40894e:	56                   	push   esi
  40894f:	8b f3                	mov    esi,ebx
  408951:	e8 0a 02 00 00       	call   0x408b60
  408956:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  408959:	3b f9                	cmp    edi,ecx
  40895b:	0f 8e d7 00 00 00    	jle    0x408a38
  408961:	8b 83 ac 00 00 00    	mov    eax,DWORD PTR [ebx+0xac]
  408967:	2b 83 a8 00 00 00    	sub    eax,DWORD PTR [ebx+0xa8]
  40896d:	c1 f8 02             	sar    eax,0x2
  408970:	3b c1                	cmp    eax,ecx
  408972:	0f 8e f5 00 00 00    	jle    0x408a6d
  408978:	eb 06                	jmp    0x408980
  40897a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  408980:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  408986:	8b 71 fc             	mov    esi,DWORD PTR [ecx-0x4]
  408989:	8b 13                	mov    edx,DWORD PTR [ebx]
  40898b:	8b 42 74             	mov    eax,DWORD PTR [edx+0x74]
  40898e:	56                   	push   esi
  40898f:	8b cb                	mov    ecx,ebx
  408991:	ff d0                	call   eax
  408993:	8b 83 bc 00 00 00    	mov    eax,DWORD PTR [ebx+0xbc]
  408999:	8d 4d 08             	lea    ecx,[ebp+0x8]
  40899c:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  40899f:	3b c8                	cmp    ecx,eax
  4089a1:	73 3e                	jae    0x4089e1
  4089a3:	8b 8b b8 00 00 00    	mov    ecx,DWORD PTR [ebx+0xb8]
  4089a9:	8d 55 08             	lea    edx,[ebp+0x8]
  4089ac:	3b ca                	cmp    ecx,edx
  4089ae:	77 31                	ja     0x4089e1
  4089b0:	8b f2                	mov    esi,edx
  4089b2:	2b f1                	sub    esi,ecx
  4089b4:	c1 fe 02             	sar    esi,0x2
  4089b7:	3b 83 c0 00 00 00    	cmp    eax,DWORD PTR [ebx+0xc0]
  4089bd:	75 0b                	jne    0x4089ca
  4089bf:	8d 83 b8 00 00 00    	lea    eax,[ebx+0xb8]
  4089c5:	e8 e6 60 0d 00       	call   0x4deab0
  4089ca:	8b 83 bc 00 00 00    	mov    eax,DWORD PTR [ebx+0xbc]
  4089d0:	85 c0                	test   eax,eax
  4089d2:	74 2c                	je     0x408a00
  4089d4:	8b 8b b8 00 00 00    	mov    ecx,DWORD PTR [ebx+0xb8]
  4089da:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  4089dd:	89 10                	mov    DWORD PTR [eax],edx
  4089df:	eb 1f                	jmp    0x408a00
  4089e1:	3b 83 c0 00 00 00    	cmp    eax,DWORD PTR [ebx+0xc0]
  4089e7:	75 0b                	jne    0x4089f4
  4089e9:	8d 83 b8 00 00 00    	lea    eax,[ebx+0xb8]
  4089ef:	e8 bc 60 0d 00       	call   0x4deab0
  4089f4:	8b 83 bc 00 00 00    	mov    eax,DWORD PTR [ebx+0xbc]
  4089fa:	85 c0                	test   eax,eax
  4089fc:	74 02                	je     0x408a00
  4089fe:	89 30                	mov    DWORD PTR [eax],esi
  408a00:	83 83 bc 00 00 00 04 	add    DWORD PTR [ebx+0xbc],0x4
  408a07:	8b 83 ac 00 00 00    	mov    eax,DWORD PTR [ebx+0xac]
  408a0d:	39 83 a8 00 00 00    	cmp    DWORD PTR [ebx+0xa8],eax
  408a13:	74 09                	je     0x408a1e
  408a15:	83 c0 fc             	add    eax,0xfffffffc
  408a18:	89 83 ac 00 00 00    	mov    DWORD PTR [ebx+0xac],eax
  408a1e:	8b 83 ac 00 00 00    	mov    eax,DWORD PTR [ebx+0xac]
  408a24:	2b 83 a8 00 00 00    	sub    eax,DWORD PTR [ebx+0xa8]
  408a2a:	c1 f8 02             	sar    eax,0x2
  408a2d:	3b 45 0c             	cmp    eax,DWORD PTR [ebp+0xc]
  408a30:	0f 8f 4a ff ff ff    	jg     0x408980
  408a36:	eb 32                	jmp    0x408a6a
  408a38:	8b c1                	mov    eax,ecx
  408a3a:	2b c7                	sub    eax,edi
  408a3c:	85 c0                	test   eax,eax
  408a3e:	7e 2d                	jle    0x408a6d
  408a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  408a43:	8b f3                	mov    esi,ebx
  408a45:	e8 a6 01 00 00       	call   0x408bf0
  408a4a:	8b 13                	mov    edx,DWORD PTR [ebx]
  408a4c:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  408a4f:	50                   	push   eax
  408a50:	8b 42 70             	mov    eax,DWORD PTR [edx+0x70]
  408a53:	8b cb                	mov    ecx,ebx
  408a55:	ff d0                	call   eax
  408a57:	8d 45 fc             	lea    eax,[ebp-0x4]
  408a5a:	8d bb a8 00 00 00    	lea    edi,[ebx+0xa8]
  408a60:	e8 ab b2 03 00       	call   0x443d10
  408a65:	ff 4d 08             	dec    DWORD PTR [ebp+0x8]
  408a68:	75 d9                	jne    0x408a43
  408a6a:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  408a6d:	33 c0                	xor    eax,eax
  408a6f:	5e                   	pop    esi
  408a70:	85 c9                	test   ecx,ecx
  408a72:	7e 11                	jle    0x408a85
  408a74:	8b 93 a8 00 00 00    	mov    edx,DWORD PTR [ebx+0xa8]
  408a7a:	8b 14 82             	mov    edx,DWORD PTR [edx+eax*4]
  408a7d:	89 42 20             	mov    DWORD PTR [edx+0x20],eax
  408a80:	40                   	inc    eax
  408a81:	3b c1                	cmp    eax,ecx
  408a83:	7c ef                	jl     0x408a74
  408a85:	41                   	inc    ecx
  408a86:	5f                   	pop    edi
  408a87:	89 8b e4 00 00 00    	mov    DWORD PTR [ebx+0xe4],ecx
  408a8d:	b0 01                	mov    al,0x1
  408a8f:	5b                   	pop    ebx
  408a90:	8b e5                	mov    esp,ebp
  408a92:	5d                   	pop    ebp
  408a93:	c2 08 00             	ret    0x8
  408a96:	5f                   	pop    edi
  408a97:	32 c0                	xor    al,al
  408a99:	5b                   	pop    ebx
  408a9a:	8b e5                	mov    esp,ebp
  408a9c:	5d                   	pop    ebp
  408a9d:	c2 08 00             	ret    0x8
```

### 0x408B60: child state helper
`.text` raw `0x7f60` → `0x7fe4`

```asm
00408b60 <.text+0x7b60>:
  408b60:	8b 8e dc 00 00 00    	mov    ecx,DWORD PTR [esi+0xdc]
  408b66:	53                   	push   ebx
  408b67:	33 db                	xor    ebx,ebx
  408b69:	3b cb                	cmp    ecx,ebx
  408b6b:	74 75                	je     0x408be2
  408b6d:	8b 86 a8 00 00 00    	mov    eax,DWORD PTR [esi+0xa8]
  408b73:	38 9e e0 00 00 00    	cmp    BYTE PTR [esi+0xe0],bl
  408b79:	74 4c                	je     0x408bc7
  408b7b:	8b 96 ac 00 00 00    	mov    edx,DWORD PTR [esi+0xac]
  408b81:	3b c2                	cmp    eax,edx
  408b83:	74 0b                	je     0x408b90
  408b85:	39 18                	cmp    DWORD PTR [eax],ebx
  408b87:	74 1a                	je     0x408ba3
  408b89:	83 c0 04             	add    eax,0x4
  408b8c:	3b c2                	cmp    eax,edx
  408b8e:	75 f5                	jne    0x408b85
  408b90:	8b 01                	mov    eax,DWORD PTR [ecx]
  408b92:	8b 90 a0 00 00 00    	mov    edx,DWORD PTR [eax+0xa0]
  408b98:	53                   	push   ebx
  408b99:	ff d2                	call   edx
  408b9b:	89 9e dc 00 00 00    	mov    DWORD PTR [esi+0xdc],ebx
  408ba1:	5b                   	pop    ebx
  408ba2:	c3                   	ret
  408ba3:	8b 01                	mov    eax,DWORD PTR [ecx]
  408ba5:	8b 90 a0 00 00 00    	mov    edx,DWORD PTR [eax+0xa0]
  408bab:	53                   	push   ebx
  408bac:	ff d2                	call   edx
  408bae:	89 9e dc 00 00 00    	mov    DWORD PTR [esi+0xdc],ebx
  408bb4:	a1 00 00 00 00       	mov    eax,ds:0x0
  408bb9:	8b 90 a0 00 00 00    	mov    edx,DWORD PTR [eax+0xa0]
  408bbf:	6a 01                	push   0x1
  408bc1:	33 c9                	xor    ecx,ecx
  408bc3:	ff d2                	call   edx
  408bc5:	5b                   	pop    ebx
  408bc6:	c3                   	ret
  408bc7:	8b 8e ac 00 00 00    	mov    ecx,DWORD PTR [esi+0xac]
  408bcd:	3b c1                	cmp    eax,ecx
  408bcf:	74 0b                	je     0x408bdc
  408bd1:	39 18                	cmp    DWORD PTR [eax],ebx
  408bd3:	74 07                	je     0x408bdc
  408bd5:	83 c0 04             	add    eax,0x4
  408bd8:	3b c1                	cmp    eax,ecx
  408bda:	75 f5                	jne    0x408bd1
  408bdc:	89 9e dc 00 00 00    	mov    DWORD PTR [esi+0xdc],ebx
  408be2:	5b                   	pop    ebx
  408be3:	c3                   	ret
```

### 0x408BF0: factory/available-item selection
`.text` raw `0x7ff0` → `0x8036`

```asm
00408bf0 <.text+0x7bf0>:
  408bf0:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  408bf6:	8b 8e a4 00 00 00    	mov    ecx,DWORD PTR [esi+0xa4]
  408bfc:	8b 11                	mov    edx,DWORD PTR [ecx]
  408bfe:	3b 86 bc 00 00 00    	cmp    eax,DWORD PTR [esi+0xbc]
  408c04:	75 05                	jne    0x408c0b
  408c06:	8b 42 28             	mov    eax,DWORD PTR [edx+0x28]
  408c09:	ff e0                	jmp    eax
  408c0b:	8b 86 bc 00 00 00    	mov    eax,DWORD PTR [esi+0xbc]
  408c11:	57                   	push   edi
  408c12:	8b 78 fc             	mov    edi,DWORD PTR [eax-0x4]
  408c15:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  408c18:	57                   	push   edi
  408c19:	ff d0                	call   eax
  408c1b:	8b 86 bc 00 00 00    	mov    eax,DWORD PTR [esi+0xbc]
  408c21:	39 86 b8 00 00 00    	cmp    DWORD PTR [esi+0xb8],eax
  408c27:	74 09                	je     0x408c32
  408c29:	83 c0 fc             	add    eax,0xfffffffc
  408c2c:	89 86 bc 00 00 00    	mov    DWORD PTR [esi+0xbc],eax
  408c32:	8b c7                	mov    eax,edi
  408c34:	5f                   	pop    edi
  408c35:	c3                   	ret
```

### 0x630E40: owning UI consumer
`.text` raw `0x230240` → `0x230323`

```asm
00630e40 <.text+0x22fe40>:
  630e40:	55                   	push   ebp
  630e41:	8b ec                	mov    ebp,esp
  630e43:	51                   	push   ecx
  630e44:	53                   	push   ebx
  630e45:	56                   	push   esi
  630e46:	57                   	push   edi
  630e47:	8b f9                	mov    edi,ecx
  630e49:	8b 87 24 01 00 00    	mov    eax,DWORD PTR [edi+0x124]
  630e4f:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  630e55:	85 c0                	test   eax,eax
  630e57:	74 08                	je     0x630e61
  630e59:	6a 06                	push   0x6
  630e5b:	50                   	push   eax
  630e5c:	e8 bf 7a dd ff       	call   0x408920
  630e61:	33 f6                	xor    esi,esi
  630e63:	eb 0b                	jmp    0x630e70
  630e65:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  630e6c:	8d 64 24 00          	lea    esp,[esp+0x0]
  630e70:	8b 87 24 01 00 00    	mov    eax,DWORD PTR [edi+0x124]
  630e76:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  630e7c:	85 c0                	test   eax,eax
  630e7e:	74 23                	je     0x630ea3
  630e80:	83 fe ff             	cmp    esi,0xffffffff
  630e83:	7e 1e                	jle    0x630ea3
  630e85:	8b 88 ac 00 00 00    	mov    ecx,DWORD PTR [eax+0xac]
  630e8b:	2b 88 a8 00 00 00    	sub    ecx,DWORD PTR [eax+0xa8]
  630e91:	c1 f9 02             	sar    ecx,0x2
  630e94:	3b f1                	cmp    esi,ecx
  630e96:	7d 0b                	jge    0x630ea3
  630e98:	8b 90 a8 00 00 00    	mov    edx,DWORD PTR [eax+0xa8]
  630e9e:	8b 0c b2             	mov    ecx,DWORD PTR [edx+esi*4]
  630ea1:	eb 02                	jmp    0x630ea5
  630ea3:	33 c9                	xor    ecx,ecx
  630ea5:	89 8c b7 28 01 00 00 	mov    DWORD PTR [edi+esi*4+0x128],ecx
  630eac:	8b 01                	mov    eax,DWORD PTR [ecx]
  630eae:	8b 90 98 01 00 00    	mov    edx,DWORD PTR [eax+0x198]
  630eb4:	68 39 c7 00 00       	push   0xc739
  630eb9:	ff d2                	call   edx
  630ebb:	46                   	inc    esi
  630ebc:	83 fe 06             	cmp    esi,0x6
  630ebf:	7c af                	jl     0x630e70
  630ec1:	8b 8f 24 01 00 00    	mov    ecx,DWORD PTR [edi+0x124]
  630ec7:	8b 59 64             	mov    ebx,DWORD PTR [ecx+0x64]
  630eca:	8b 33                	mov    esi,DWORD PTR [ebx]
  630ecc:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  630ecf:	3b f3                	cmp    esi,ebx
  630ed1:	74 25                	je     0x630ef8
  630ed3:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  630ed6:	83 78 60 00          	cmp    DWORD PTR [eax+0x60],0x0
  630eda:	74 16                	je     0x630ef2
  630edc:	8b 50 1c             	mov    edx,DWORD PTR [eax+0x1c]
  630edf:	83 7a 08 06          	cmp    DWORD PTR [edx+0x8],0x6
  630ee3:	74 0d                	je     0x630ef2
  630ee5:	8b ca                	mov    ecx,edx
  630ee7:	8b 11                	mov    edx,DWORD PTR [ecx]
  630ee9:	50                   	push   eax
  630eea:	8b 42 30             	mov    eax,DWORD PTR [edx+0x30]
  630eed:	ff d0                	call   eax
  630eef:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  630ef2:	8b 36                	mov    esi,DWORD PTR [esi]
  630ef4:	3b f3                	cmp    esi,ebx
  630ef6:	75 db                	jne    0x630ed3
  630ef8:	8b 11                	mov    edx,DWORD PTR [ecx]
  630efa:	8b 82 28 01 00 00    	mov    eax,DWORD PTR [edx+0x128]
  630f00:	ff d0                	call   eax
  630f02:	8b 8f 04 01 00 00    	mov    ecx,DWORD PTR [edi+0x104]
  630f08:	c6 81 c9 00 00 00 00 	mov    BYTE PTR [ecx+0xc9],0x0
  630f0f:	8b 97 08 01 00 00    	mov    edx,DWORD PTR [edi+0x108]
  630f15:	5f                   	pop    edi
  630f16:	5e                   	pop    esi
  630f17:	c6 82 c9 00 00 00 00 	mov    BYTE PTR [edx+0xc9],0x0
  630f1e:	5b                   	pop    ebx
  630f1f:	8b e5                	mov    esp,ebp
  630f21:	5d                   	pop    ebp
  630f22:	c3                   	ret
```

## 8. 提交／邊界

僅 T16 `kr-temp-roy/` 本段原稿；不修改其他 Task、catalog、owner，不提交 BIN/EXE，保留 unknown。