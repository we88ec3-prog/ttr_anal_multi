# T10-093 — 0x6D4A30 初始化分支與事件容器實參



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段新證據
`0x490DFC` 呼叫前 `push 0xF95CD8` 與 `push [0xFAADFA]`；後者進入 `[ebp+8]` 的條件分支，前者為第二實參，並非按鍵事件 ID。`0x58A607` 則有不同的本地自鏈容器；同一函式可被不同初始化 owner 使用。`0x6D4A30` 的 `[ebp+8] != 0` 走 `0x6D4A68` 路徑，等於 0 走 `0x6D4B0A`。此分支影響初始化／重置先後，不能推斷為 key-down/key-up。

`0x6D4A93` 與 `0x6D4B69` 的 `xor eax,eax` 後連續寫入 `[0xFB9004..0xFB9028]` 十個 DWORD；這是 40 個普通 phase bytes 歸零，並非 phase 1／3 寫入。部分分支有 `0x6D0750`、`0x6D1DA0` lazy initialization guards（`0xFB7C14` 與 `0xFDF3EC` bit0）。由於初始化是有條件的，直接把它視作每次遊戲 frame 必然呼叫不成立。

**新限定結論**：reset 函式實參與兩個不同 caller 的存儲所有權不同；判定非零 writer 需要在上游事件 append / callback 查，而非把 reset 計為輸入生成。


## BIN 指令證據（可依 VA 重現）

### 0x490def .. 0x490e05

```asm

  490def:	0f b6 05 fa ad fa 00 	movzx  eax,BYTE PTR ds:0xfaadfa
  490df6:	68 d8 5c f9 00       	push   0xf95cd8
  490dfb:	50                   	push   eax
  490dfc:	e8 2f 3c 24 00       	call   0x6d4a30
  490e01:	83 c4 08             	add    esp,0x8
  490e04:	8b               	mov    ecx,DWORD PTR [ebp-0xc]

```

### 0x58a5db .. 0x58a644

```asm

  58a5db:	e8 88 6c 30 00       	call   0x891268
  58a5e0:	8b f0                	mov    esi,eax
  58a5e2:	33 ff                	xor    edi,edi
  58a5e4:	83 c4 04             	add    esp,0x4
  58a5e7:	3b f7                	cmp    esi,edi
  58a5e9:	0f 84 a0 01 00 00    	je     0x58a78f
  58a5ef:	89 36                	mov    DWORD PTR [esi],esi
  58a5f1:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  58a5f5:	89 76 04             	mov    DWORD PTR [esi+0x4],esi
  58a5f8:	8d 44 24 14          	lea    eax,[esp+0x14]
  58a5fc:	50                   	push   eax
  58a5fd:	6a 01                	push   0x1
  58a5ff:	c7 44 24 50 03 00 00 	mov    DWORD PTR [esp+0x50],0x3
  58a606:	00 
  58a607:	e8 24 a4 14 00       	call   0x6d4a30
  58a60c:	89 bb 3c 01 00 00    	mov    DWORD PTR [ebx+0x13c],edi
  58a612:	89 bb 40 01 00 00    	mov    DWORD PTR [ebx+0x140],edi
  58a618:	89 bb 44 01 00 00    	mov    DWORD PTR [ebx+0x144],edi
  58a61e:	66 89 bb 48 01 00 00 	mov    WORD PTR [ebx+0x148],di
  58a625:	c6 83 4a 01 00 00 00 	mov    BYTE PTR [ebx+0x14a],0x0
  58a62c:	c7 44 24 50 ff ff ff 	mov    DWORD PTR [esp+0x50],0xffffffff
  58a633:	ff 
  58a634:	8b 06                	mov    eax,DWORD PTR [esi]
  58a636:	83 c4 08             	add    esp,0x8
  58a639:	89 36                	mov    DWORD PTR [esi],esi
  58a63b:	89 76 04             	mov    DWORD PTR [esi+0x4],esi
  58a63e:	3b c6                	cmp    eax,esi
  58a640:	74 11                	je     0x58a653
  58a642:	8b 38                	mov    edi,DWORD PTR [eax]

```

### 0x6d4a58 .. 0x6d4af0

```asm

  6d4a58:	83 cb ff             	or     ebx,0xffffffff
  6d4a5b:	80 7d 08 00          	cmp    BYTE PTR [ebp+0x8],0x0
  6d4a5f:	8d 73 02             	lea    esi,[ebx+0x2]
  6d4a62:	0f 84 a2 00 00 00    	je     0x6d4b0a
  6d4a68:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4a6f:	75 22                	jne    0x6d4a93
  6d4a71:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4a77:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4a7e:	e8 cd bc ff ff       	call   0x6d0750
  6d4a83:	68 30 d5 bc 00       	push   0xbcd530
  6d4a88:	e8 8d d8 1b 00       	call   0x89231a
  6d4a8d:	83 c4 04             	add    esp,0x4
  6d4a90:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4a93:	33 c0                	xor    eax,eax
  6d4a95:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4a9c:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4aa1:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4aa6:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4aab:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4ab0:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4ab5:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4aba:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4abf:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4ac4:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4ac9:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4ace:	75 1e                	jne    0x6d4aee
  6d4ad0:	09 35 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,esi
  6d4ad6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d4ad9:	e8 c2 d2 ff ff       	call   0x6d1da0
  6d4ade:	68 30 e3 bc 00       	push   0xbce330
  6d4ae3:	e8 32 d8 1b 00       	call   0x89231a
  6d4ae8:	83 c4 04             	add    esp,0x4
  6d4aeb:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4aee:	bf 30          	mov    edi,0xfdf630

```

### 0x6d4b0a .. 0x6d4bd0

```asm

  6d4b0a:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4b11:	75 22                	jne    0x6d4b35
  6d4b13:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4b19:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  6d4b20:	e8 2b bc ff ff       	call   0x6d0750
  6d4b25:	68 30 d5 bc 00       	push   0xbcd530
  6d4b2a:	e8 eb d7 1b 00       	call   0x89231a
  6d4b2f:	83 c4 04             	add    esp,0x4
  6d4b32:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4b35:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  6d4b3c:	74 5f                	je     0x6d4b9d
  6d4b3e:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4b45:	75 22                	jne    0x6d4b69
  6d4b47:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4b4d:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  6d4b54:	e8 f7 bb ff ff       	call   0x6d0750
  6d4b59:	68 30 d5 bc 00       	push   0xbcd530
  6d4b5e:	e8 b7 d7 1b 00       	call   0x89231a
  6d4b63:	83 c4 04             	add    esp,0x4
  6d4b66:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4b69:	33 c0                	xor    eax,eax
  6d4b6b:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4b70:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4b75:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4b7a:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4b7f:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4b84:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4b89:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4b8e:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4b93:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4b98:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4b9d:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4ba4:	75 22                	jne    0x6d4bc8
  6d4ba6:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4bac:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  6d4bb3:	e8 98 bb ff ff       	call   0x6d0750
  6d4bb8:	68 30 d5 bc 00       	push   0xbcd530
  6d4bbd:	e8 58 d7 1b 00       	call   0x89231a
  6d4bc2:	83 c4 04             	add    esp,0x4
  6d4bc5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4bc8:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  6d4bcf:	74                 	je     0x6d4c06

```

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
