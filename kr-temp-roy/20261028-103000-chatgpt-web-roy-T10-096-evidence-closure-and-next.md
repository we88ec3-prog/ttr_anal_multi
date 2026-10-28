# T10-096 — T10-89～96 功能鏈矩陣與 producer 缺口再定位



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段交叉驗證結論
| 分段 | 已確認事項 | 尚未確認事項 |
|---|---|---|
| 配置 | 原始 KeyMapping Type0 的 MapButton13～16=Key44..47；三 bank 與工作 bank2 | 自訂檔 writer、實際玩家模式、scan-code producer |
| phase | `[0xFB9004+ID]` reader；`0x6D4A30` 多路清零 | 寫入 phase=1/3 的非零 producer |
| dispatch | `0x5961C0` 依狀態分派候選子物件和 listener 的 +0xEC/+0xF0 | 動作 override/vtable owner 及 motion/queue |
| mode | `0xFB73E8` gate；`0x5A55E0` mode，`0x5A5760/0x5A57A0` 選子物件並派發 | 非零 gate writer、+0xB4 implementer、狀態業務語義 |

### T10-97 優先方案
1. 定位 `0x5961C0` 真正 vptr 及 +0xEC / +0xF0 / +0xB4 覆寫地址，查 vtable 在 `.rdata` 的實際物件與生命週期。
2. 逆追 `0x490DFC`、`0x58A607` 上游事件 append/producer；不要再將 reset 當非零 writer。
3. 對 `[0xFB9004+ID]` 的 alias-based stores 使用 register-def/use 或局部資料流掃描；絕對位址負結果不足以排除。
4. 對 `0xFB73E8` 按 base+offset 別名查來源，確定是否與角色／ UI 模式相關。
5. 連接真正 motion/queue/cancel 前，不把 XML MapButton13～16 硬命名為攻擊技能，也不採 AI `CHAIN_WINDOW=0.65`、>500ms 等替代。

### 證據限制
本段新增局部實作路由，但沒有找到 phase 非零 writer、完整角色 motion 或 native combo 時窗。原始檔不提交 GitHub；其他 Task 的主責範圍不修改。


## BIN 指令證據（可依 VA 重現）

### 0x6d4d8e .. 0x6d4da3

```asm

  6d4d8e:	1b 00                	sbb    eax,DWORD PTR [eax]
  6d4d90:	83 c4 04             	add    esp,0x4
  6d4d93:	83 fe 27             	cmp    esi,0x27
  6d4d96:	77 16                	ja     0x6d4dae
  6d4d98:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  6d4d9f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4da2:	64       	mov    DWORD PTR fs:0x0,ecx

```

### 0x596245 .. 0x5962b9

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
  5962b7:	e9 91          	jmp    0x59634d

```

### 0x5a5760 .. 0x5a57d0

```asm

  5a5760:	55                   	push   ebp
  5a5761:	8b ec                	mov    ebp,esp
  5a5763:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5a5766:	56                   	push   esi
  5a5767:	8b b1 58 01 00 00    	mov    esi,DWORD PTR [ecx+0x158]
  5a576d:	4e                   	dec    esi
  5a576e:	74 0b                	je     0x5a577b
  5a5770:	4e                   	dec    esi
  5a5771:	75 25                	jne    0x5a5798
  5a5773:	8b 89 48 01 00 00    	mov    ecx,DWORD PTR [ecx+0x148]
  5a5779:	eb 06                	jmp    0x5a5781
  5a577b:	8b 89 40 01 00 00    	mov    ecx,DWORD PTR [ecx+0x140]
  5a5781:	2b 51 08             	sub    edx,DWORD PTR [ecx+0x8]
  5a5784:	01 51 08             	add    DWORD PTR [ecx+0x8],edx
  5a5787:	01 51 10             	add    DWORD PTR [ecx+0x10],edx
  5a578a:	2b 41 0c             	sub    eax,DWORD PTR [ecx+0xc]
  5a578d:	01 41 0c             	add    DWORD PTR [ecx+0xc],eax
  5a5790:	01 41 14             	add    DWORD PTR [ecx+0x14],eax
  5a5793:	e8 d8 17 1a 00       	call   0x746f70
  5a5798:	5e                   	pop    esi
  5a5799:	5d                   	pop    ebp
  5a579a:	c2 04 00             	ret    0x4
  5a579d:	cc                   	int3
  5a579e:	cc                   	int3
  5a579f:	cc                   	int3
  5a57a0:	8b 81 58 01 00 00    	mov    eax,DWORD PTR [ecx+0x158]
  5a57a6:	48                   	dec    eax
  5a57a7:	74 15                	je     0x5a57be
  5a57a9:	48                   	dec    eax
  5a57aa:	75 23                	jne    0x5a57cf
  5a57ac:	8b 89 48 01 00 00    	mov    ecx,DWORD PTR [ecx+0x148]
  5a57b2:	8b 01                	mov    eax,DWORD PTR [ecx]
  5a57b4:	52                   	push   edx
  5a57b5:	8b 90 b4 00 00 00    	mov    edx,DWORD PTR [eax+0xb4]
  5a57bb:	ff d2                	call   edx
  5a57bd:	c3                   	ret
  5a57be:	8b 89 40 01 00 00    	mov    ecx,DWORD PTR [ecx+0x140]
  5a57c4:	8b 01                	mov    eax,DWORD PTR [ecx]
  5a57c6:	52                   	push   edx
  5a57c7:	8b 90 b4 00 00 00    	mov    edx,DWORD PTR [eax+0xb4]
  5a57cd:	ff d2                	call   edx
  5a57cf:	c3                   	ret

```

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
