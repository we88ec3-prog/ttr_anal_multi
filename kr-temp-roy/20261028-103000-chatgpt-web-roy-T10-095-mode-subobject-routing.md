# T10-095 — 0x5A5760/0x5A57A0 mode 子物件路由



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段新證據
先前 `0x5A4614` 讀取 `0xFB73E8`，並在變化時呼叫 `0x5A55E0` 寫 `[owner+0x158]` mode。本次沿下游直接驗證 `0x5A5760` 的 `mode-1`、`mode-2` 分支：mode1 選 `[owner+0x140]`，mode2 選 `[owner+0x148]`，其他數值提前返回；針對該子物件把 `+8/+0x10` 與 `+0xC/+0x14` 作偏差調整，隨後呼叫 `0x746F70`。不能未核對其類型就命名為動畫插值。

`0x5A57A0` 用同一選擇規則，選中物件後取得 vptr，傳入 EDX 参数並呼叫 vtable `+0xB4`；mode 不是 1/2 則直接返回。`0x5A464A mov edx,0x66` 接 `0x5A57A0` 代表向選定子物件發送整數 `0x66`，**並不**證明這個數值是普通攻擊、施放或取消 opcode。

**新增已閉合局部鏈**：`[owner+0x158]` mode → mode1/2 子物件選擇 → vtable+0xB4。**未閉合**：vptr 具體值、+0xB4 implementer、角色 controller/motion、mode writer 的外部事件來源。


## BIN 指令證據（可依 VA 重現）

### 0x5a4614 .. 0x5a4670

```asm

  5a4614:	39 1d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,ebx
  5a461a:	8a 86 54 01 00 00    	mov    al,BYTE PTR [esi+0x154]
  5a4620:	0f 95 c3             	setne  bl
  5a4623:	84 c0                	test   al,al
  5a4625:	75 35                	jne    0x5a465c
  5a4627:	84 db                	test   bl,bl
  5a4629:	74 2d                	je     0x5a4658
  5a462b:	6a 02                	push   0x2
  5a462d:	32 c9                	xor    cl,cl
  5a462f:	8b d6                	mov    edx,esi
  5a4631:	e8 aa 0f 00 00       	call   0x5a55e0
  5a4636:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  5a4639:	81 ea 3b 01 00 00    	sub    edx,0x13b
  5a463f:	56                   	push   esi
  5a4640:	b8 05 00 00 00       	mov    eax,0x5
  5a4645:	e8 16 11 00 00       	call   0x5a5760
  5a464a:	ba 66 00 00 00       	mov    edx,0x66
  5a464f:	8b ce                	mov    ecx,esi
  5a4651:	e8 4a 11 00 00       	call   0x5a57a0
  5a4656:	eb 13                	jmp    0x5a466b
  5a4658:	84 c0                	test   al,al
  5a465a:	74 0f                	je     0x5a466b
  5a465c:	84 db                	test   bl,bl
  5a465e:	75 0b                	jne    0x5a466b
  5a4660:	6a 01                	push   0x1
  5a4662:	32 c9                	xor    cl,cl
  5a4664:	8b d6                	mov    edx,esi
  5a4666:	e8 75 0f 00 00       	call   0x5a55e0
  5a466b:	88 9e 54 01 00     	mov    BYTE PTR [esi+0x154],bl

```

### 0x5a5760 .. 0x5a579b

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
  5a579a:	c2               	ret    0x4

```

### 0x5a57a0 .. 0x5a57d0

```asm

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
