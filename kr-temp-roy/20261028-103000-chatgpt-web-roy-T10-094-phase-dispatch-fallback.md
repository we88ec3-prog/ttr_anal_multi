# T10-094 — 0x5961C0 phase1／phase3 fallback 之非對稱性



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段新證據
`0x596267` 比對 phase==1，先向候選子物件的 vtable `+0xEC` 傳入 ID (`push edi`)；返回 `AL` 若為真，短路 this 事件，若為假經 `0x596140` 的條件 helper 後才可能呼叫 this vtable `+0xEC`。這是有序的 **handled / fallback** 路徑，而非保證每個按鍵觸發角色動作。

phase==3 在 `0x5962BC` 分支先向候選子物件的 `+0xF0` 傳 ID；回傳真寫局部 `[ebp-0xE]=1`，然後依旗標可能進入 this+0x80 的關聯節點查找 `0x82EF00`，在節點上的其他 listener 再各自呼叫 vtable `+0xF0`。這段具有多 listener 的通知語義，不能未驗證命名為連段佇列。

`0xFB73E8 != 0` 時的 13／14 ID 特例發生在讀 phase **之後**、vtable 處理之前，因此是此派送路徑的 gate；不代表映射表刪除 15、16，也不代表全局停用其他鍵。

**缺口**：vtable owner 與實際 overrides、`0x596140` helper 可否處理鍵 ID 的具體語義、原生角色 motion writer。


## BIN 指令證據（可依 VA 重現）

### 0x596245 .. 0x5962bc

```asm

  596245:	8b f7                	mov    esi,edi
  596247:	c6 45 f2 00          	mov    BYTE PTR [ebp-0xe],0x0
  59624b:	89 7d dc             	mov    DWORD PTR [ebp-0x24],edi
  59624e:	e8 8d ea 13 00       	call   0x6d4ce0
  596253:	80 7d f1 00          	cmp    BYTE PTR [ebp-0xf],0x0
  596257:	74 0e                	je     0x596267
  596259:	83 ff 0d             	cmp    edi,0xd
  59625c:	74 09                	je     0x596267
  59625e:	83 ff 0e             	cmp    edi,0xe
  596261:	0f 85 1f 01 00 00    	jne    0x596386
  596267:	83 f8 01             	cmp    eax,0x1
  59626a:	75 50                	jne    0x5962bc
  59626c:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  59626f:	85 c9                	test   ecx,ecx
  596271:	74 11                	je     0x596284
  596273:	8b 11                	mov    edx,DWORD PTR [ecx]
  596275:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  59627b:	57                   	push   edi
  59627c:	ff d0                	call   eax
  59627e:	84 c0                	test   al,al
  596280:	b0 01                	mov    al,0x1
  596282:	75 03                	jne    0x596287
  596284:	8a 45 f2             	mov    al,BYTE PTR [ebp-0xe]
  596287:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  59628b:	0f 85 bc 00 00 00    	jne    0x59634d
  596291:	84 c0                	test   al,al
  596293:	0f 85 b8 00 00 00    	jne    0x596351
  596299:	6a 01                	push   0x1
  59629b:	8b c3                	mov    eax,ebx
  59629d:	e8 9e fe ff ff       	call   0x596140
  5962a2:	84 c0                	test   al,al
  5962a4:	0f 85 a7 00 00 00    	jne    0x596351
  5962aa:	8b 13                	mov    edx,DWORD PTR [ebx]
  5962ac:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  5962b2:	57                   	push   edi
  5962b3:	8b cb                	mov    ecx,ebx
  5962b5:	ff d0                	call   eax
  5962b7:	e9 91 00 00 00       	jmp    0x59634d

```

### 0x5962bc .. 0x596352

```asm

  5962bc:	83 f8 03             	cmp    eax,0x3
  5962bf:	0f 85 c1 00 00 00    	jne    0x596386
  5962c5:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  5962c8:	85 c9                	test   ecx,ecx
  5962ca:	74 13                	je     0x5962df
  5962cc:	8b 11                	mov    edx,DWORD PTR [ecx]
  5962ce:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5962d4:	57                   	push   edi
  5962d5:	ff d0                	call   eax
  5962d7:	84 c0                	test   al,al
  5962d9:	74 04                	je     0x5962df
  5962db:	c6 45 f2 01          	mov    BYTE PTR [ebp-0xe],0x1
  5962df:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  5962e3:	75 65                	jne    0x59634a
  5962e5:	80 7d f2 00          	cmp    BYTE PTR [ebp-0xe],0x0
  5962e9:	75 66                	jne    0x596351
  5962eb:	8d 4d e8             	lea    ecx,[ebp-0x18]
  5962ee:	51                   	push   ecx
  5962ef:	8d 8b 80 00 00 00    	lea    ecx,[ebx+0x80]
  5962f5:	8d 45 e0             	lea    eax,[ebp-0x20]
  5962f8:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5962fb:	e8 00 8c 29 00       	call   0x82ef00
  596300:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  596303:	3b 83 84 00 00 00    	cmp    eax,DWORD PTR [ebx+0x84]
  596309:	74 30                	je     0x59633b
  59630b:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  59630e:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  596311:	8b 31                	mov    esi,DWORD PTR [ecx]
  596313:	8b d9                	mov    ebx,ecx
  596315:	3b f3                	cmp    esi,ebx
  596317:	74 1f                	je     0x596338
  596319:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  596320:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  596323:	8b 11                	mov    edx,DWORD PTR [ecx]
  596325:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  59632b:	57                   	push   edi
  59632c:	ff d0                	call   eax
  59632e:	84 c0                	test   al,al
  596330:	75 1f                	jne    0x596351
  596332:	8b 36                	mov    esi,DWORD PTR [esi]
  596334:	3b f3                	cmp    esi,ebx
  596336:	75 e8                	jne    0x596320
  596338:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  59633b:	8b 13                	mov    edx,DWORD PTR [ebx]
  59633d:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  596343:	57                   	push   edi
  596344:	8b cb                	mov    ecx,ebx
  596346:	ff d0                	call   eax
  596348:	eb 03                	jmp    0x59634d
  59634a:	8a 45 f2             	mov    al,BYTE PTR [ebp-0xe]
  59634d:	84 c0                	test   al,al
  59634f:	74 35                	je     0x596386
  596351:	8b               	mov    ebx,DWORD PTR [ebp+0x8]

```

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
