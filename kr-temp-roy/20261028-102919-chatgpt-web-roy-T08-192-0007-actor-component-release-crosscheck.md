# T08-192 — 正式 0007 的 Actor 登記／移除與資源回收之有界交會

- 研究時間（Asia/Taipei）：2026-10-28T10:29:19+08:00
- 研究者：`chatgpt-web roy`；範圍：KR T08 靜態研究／正式 0007 實體建立、登記、移除之介面（資源管理為上下游線索）
- 證據：原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算一致）。PE `.text` VA `0x401000`/raw `0x400`、section size `0x7D01F0`（以 `objdump -h` 檢視）；唯讀，未執行遊戲。
- GitHub：`we88ec3-prog/ttr_anal_multi` `main`；沿 T08-185～188 證據線索接續。以下皆以 RVA 映射實際機器碼獨立檢視；舊筆記不取代第一手驗證。

## 本段實質研究結果及證據等級

1. **已確認** `0x004DFF30` 進行 actor key 查找及樹插入（`0x0082EF00/0x0082F200`）；入口不是 resource pool 自身的建立或 drain。

2. **已確認** `0x004DFBC0` 查找待移除 key，包含多型 callback 與 `0x007B6890` 節點刪除；callsite 不直接指向 `0x007DD1F0`，不能將單個 actor erase 等價於清空共享資源池。

3. **已確認** 場景物件/元件清理 `0x004C83C0` 附近與 `0x007BE5F0` 存在直接引用，提供有限的中介接口。這只是證明部分清理路徑可達 resource release，不證明所有 actor 一律持有資源 wrapper。

4. **部分確認** 正式 0007 的 `0x004AE4D0 -> 0x004D1710 -> 0x004DFF30` 與物件 registry 的生成／登記資料介面已有先前證據；本段未驗證任何 server 生成時機、波次或 AI 決策。

5. **未決** 需要把實際 actor vptr / `+0xF4` component slot，映射到某個具體 wrapper 的 `+0x2C` resource，再追 manager owner；沒有完成前不能宣稱 scene actor tree 與 name index 合併。

## 相關函式與前段差異

此段刻意建立可反證的介面矩陣：actor registry（0007 主責）→多型 component cleanup（可能）→底層 resource release（有限呼叫點）→pool enqueue/立即釋放（依模式）。有界連結成立，不代表所有 runtime 實體都沿完整鏈。

## E8 相對位移重新實算（僅 byte 候選，不是完整 CFG）

- 目標 `0x004DFF30`：5 候選：`0x004A11B6` (`e875ed0300`), `0x004AA222` (`e8095d0300`), `0x004AEC03` (`e828130300`), `0x004AF4F7` (`e8340a0300`), `0x004B2F83` (`e8a8cf0200`)
- 目標 `0x004DFBC0`：2 候選：`0x004AA057` (`e8645b0300`), `0x004B2AC2` (`e8f9d00200`)
- 目標 `0x004C83C0`：1 候選：`0x004C86DA` (`e8e1fcffff`)
- 目標 `0x007BE5F0`：42 候選：`0x004C7C8F` (`e85c692f00`), `0x004C7DB4` (`e837682f00`), `0x004C838C` (`e85f622f00`), `0x004C83AF` (`e83c622f00`), `0x004C8411` (`e8da612f00`), `0x004C902C` (`e8bf552f00`), `0x004C9066` (`e885552f00`), `0x004C9074` (`e877552f00`), `0x004CAFF4` (`e8f7352f00`), `0x004CC867` (`e8841d2f00`), `0x004CC89A` (`e8511d2f00`), `0x004CDDF1` (`e8fa072f00`), `0x004CE927` (`e8c4fc2e00`), `0x004CEC2C` (`e8bff92e00`), `0x004CECA7` (`e844f92e00`), `0x004D0330` (`e8bbe22e00`), `0x004D1333` (`e8b8d22e00`), `0x004D16B8` (`e833cf2e00`), `0x004D2449` (`e8a2c12e00`), `0x004D2497` (`e854c12e00`), `0x004D2522` (`e8c9c02e00`), `0x004D25A6` (`e845c02e00`), `0x004D2632` (`e8b9bf2e00`), `0x004D26BE` (`e82dbf2e00`), `0x004D2772` (`e879be2e00`), `0x004D287D` (`e86ebd2e00`), `0x00543B98` (`e853aa2700`), `0x00543FDF` (`e80ca62700`), `0x0054480B` (`e8e09d2700`), `0x00550B7D` (`e86eda2600`), `0x00550DAE` (`e83dd82600`), `0x00550EF9` (`e8f2d62600`), `0x00550EFE` (`e8edd62600`), `0x00550FB5` (`e836d62600`), `0x00552380` (`e86bc22600`)；其餘略

**限制**：此掃描在 `.text` 每 byte 搜索 `E8 + signed rel32`，可能包含非指令邊界，亦不包含 FF/2、vtable 或反常 CFG；只可當交叉參照候選。

## 有界資料流與 ABI 注意

下列地址窗口從明示 VA 分段反組譯；函式入口／呼叫慣例需依 prologue、callsite 和實際 CFG 共同確認。若觀察到 `+0x44/+0x5C/+0x60` 等相同欄位，**只有在 pointer provenance 相同時**才視為同一結構；不得以同 offset 合併 actor、resource、registry、wrapper。

## 待查問題及下一段入口

1. 由 actor vtable 分派定位實際析構入口，核對已辨識 component slot。
2. 查找同一個資源 owner 實例的構造點、呼叫端與物件綁定來源。
3. 與 T01 新的 source-review-status 保留證據等級；不做伺服器 AI/波次規則推論。

## 附錄：原始 BIN 組語（objdump x86 Intel，指定 VA 有界解碼）

### `0x004DFF30` ～ `0x004DFFE5`

```asm
  4dff30:	55                   	push   ebp
  4dff31:	8b ec                	mov    ebp,esp
  4dff33:	83 ec 10             	sub    esp,0x10
  4dff36:	53                   	push   ebx
  4dff37:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dff3a:	56                   	push   esi
  4dff3b:	57                   	push   edi
  4dff3c:	8b f8                	mov    edi,eax
  4dff3e:	85 ff                	test   edi,edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dff50:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dff53:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4dff56:	8d 73 08             	lea    esi,[ebx+0x8]
  4dff59:	51                   	push   ecx
  4dff5a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dff5d:	8b ce                	mov    ecx,esi
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4dff67:	3b 53 0c             	cmp    edx,DWORD PTR [ebx+0xc]
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dff6f:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4dff72:	8d 7d f4             	lea    edi,[ebp-0xc]
  4dff75:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   eax
  4dff7e:	56                   	push   esi
  4dff7f:	8d 75 f4             	lea    esi,[ebp-0xc]
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    edi
  4dff88:	5e                   	pop    esi
  4dff89:	5b                   	pop    ebx
  4dff8a:	8b e5                	mov    esp,ebp
  4dff8c:	5d                   	pop    ebp
  4dff8d:	c2 04 00             	ret    0x4
  4dff90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4dff93:	51                   	push   ecx
  4dff94:	68 f0 ce c0 00       	push   0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    esp,0x8
  4dffa1:	5f                   	pop    edi
  4dffa2:	5e                   	pop    esi
  4dffa3:	5b                   	pop    ebx
  4dffa4:	8b e5                	mov    esp,ebp
  4dffa6:	5d                   	pop    ebp
  4dffa7:	c2 04 00             	ret    0x4
  4dffaa:	cc                   	int3
  4dffab:	cc                   	int3
  4dffac:	cc                   	int3
  4dffad:	cc                   	int3
  4dffae:	cc                   	int3
  4dffaf:	cc                   	int3
  4dffb0:	55                   	push   ebp
  4dffb1:	8b ec                	mov    ebp,esp
  4dffb3:	83 e4 f8             	and    esp,0xfffffff8
  4dffb6:	6a ff                	push   0xffffffff
  4dffb8:	68 de ed 93 00       	push   0x93edde
  4dffbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4dffc3:	50                   	push   eax
  4dffc4:	83 ec 10             	sub    esp,0x10
  4dffc7:	53                   	push   ebx
  4dffc8:	56                   	push   esi
  4dffc9:	57                   	push   edi
  4dffca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4dffcf:	33 c4                	xor    eax,esp
  4dffd1:	50                   	push   eax
  4dffd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  4dffd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4dffdc:	8b f1                	mov    esi,ecx
  4dffde:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dffe1:	8b 3e                	mov    edi,DWORD PTR [esi]
  4dffe3:	b8 01          	mov    eax,0x1
```

### `0x004DFBC0` ～ `0x004DFC50`

```asm
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4
  4dfc2c:	cc                   	int3
  4dfc2d:	cc                   	int3
  4dfc2e:	cc                   	int3
  4dfc2f:	cc                   	int3
  4dfc30:	55                   	push   ebp
  4dfc31:	8b ec                	mov    ebp,esp
  4dfc33:	51                   	push   ecx
  4dfc34:	53                   	push   ebx
  4dfc35:	57                   	push   edi
  4dfc36:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfc39:	8d 5e 18             	lea    ebx,[esi+0x18]
  4dfc3c:	50                   	push   eax
  4dfc3d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfc40:	8b cb                	mov    ecx,ebx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfc4a:	3b 7e 1c             	cmp    edi,DWORD PTR [esi+0x1c]
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b         	mov    eax,DWORD PTR [esi+0xf8]
```

### `0x004C83C0` ～ `0x004C8480`

```asm
  4c83c0:	55                   	push   ebp
  4c83c1:	8b ec                	mov    ebp,esp
  4c83c3:	83 ec 0c             	sub    esp,0xc
  4c83c6:	56                   	push   esi
  4c83c7:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c83ca:	83 be 6c 03 00 00 00 	cmp    DWORD PTR [esi+0x36c],0x0
  4c83d1:	75 6d                	jne    0x4c8440
  4c83d3:	53                   	push   ebx
  4c83d4:	57                   	push   edi
  4c83d5:	33 ff                	xor    edi,edi
  4c83d7:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4c83da:	8d 9e 64 01 00 00    	lea    ebx,[esi+0x164]
  4c83e0:	0f b7 c7             	movzx  eax,di
  4c83e3:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4c83e6:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  4c83e9:	51                   	push   ecx
  4c83ea:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c83ed:	8d 8e f0 03 00 00    	lea    ecx,[esi+0x3f0]
  4c83f3:	e8 88 de 35 00       	call   0x826280
  4c83f8:	8b 10                	mov    edx,DWORD PTR [eax]
  4c83fa:	3b 96 f4 03 00 00    	cmp    edx,DWORD PTR [esi+0x3f4]
  4c8400:	75 2d                	jne    0x4c842f
  4c8402:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c8404:	85 c0                	test   eax,eax
  4c8406:	74 27                	je     0x4c842f
  4c8408:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c840c:	8d 70 24             	lea    esi,[eax+0x24]
  4c840f:	74 05                	je     0x4c8416
  4c8411:	e8 da 61 2f 00       	call   0x7be5f0
  4c8416:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c8418:	85 c0                	test   eax,eax
  4c841a:	74 10                	je     0x4c842c
  4c841c:	8b f8                	mov    edi,eax
  4c841e:	e8 8d f9 ff ff       	call   0x4c7db0
  4c8423:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4c8426:	c7 03 00 00 00 00    	mov    DWORD PTR [ebx],0x0
  4c842c:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c842f:	47                   	inc    edi
  4c8430:	83 c3 04             	add    ebx,0x4
  4c8433:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4c8436:	81 ff 80 00 00 00    	cmp    edi,0x80
  4c843c:	7c a2                	jl     0x4c83e0
  4c843e:	5f                   	pop    edi
  4c843f:	5b                   	pop    ebx
  4c8440:	5e                   	pop    esi
  4c8441:	8b e5                	mov    esp,ebp
  4c8443:	5d                   	pop    ebp
  4c8444:	c2 04 00             	ret    0x4
  4c8447:	cc                   	int3
  4c8448:	cc                   	int3
  4c8449:	cc                   	int3
  4c844a:	cc                   	int3
  4c844b:	cc                   	int3
  4c844c:	cc                   	int3
  4c844d:	cc                   	int3
  4c844e:	cc                   	int3
  4c844f:	cc                   	int3
  4c8450:	55                   	push   ebp
  4c8451:	8b ec                	mov    ebp,esp
  4c8453:	51                   	push   ecx
  4c8454:	8b 80 68 03 00 00    	mov    eax,DWORD PTR [eax+0x368]
  4c845a:	85 c0                	test   eax,eax
  4c845c:	74 13                	je     0x4c8471
  4c845e:	50                   	push   eax
  4c845f:	8d 45 fc             	lea    eax,[ebp-0x4]
  4c8462:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4c8466:	e8 65 ca 2e 00       	call   0x7b4ed0
  4c846b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c846e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  4c8471:	8b e5                	mov    esp,ebp
  4c8473:	5d                   	pop    ebp
  4c8474:	c2 04 00             	ret    0x4
  4c8477:	cc                   	int3
  4c8478:	cc                   	int3
  4c8479:	cc                   	int3
  4c847a:	cc                   	int3
  4c847b:	cc                   	int3
  4c847c:	cc                   	int3
  4c847d:	cc                   	int3
  4c847e:	cc                   	int3
  4c847f:	cc                   	int3
```

### `0x007BE5F0` ～ `0x007BE655`

```asm
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
  7be647:	b8 01 00 00 00       	mov    eax,0x1
  7be64c:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be652:	c3                   	ret
  7be653:	cc                   	int3
  7be654:	cc                   	int3
```