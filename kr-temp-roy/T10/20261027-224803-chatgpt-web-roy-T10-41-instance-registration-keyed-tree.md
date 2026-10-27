# T10-41 — 工廠物件註冊：WORD key 與樹節點插入／重複鍵分流（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.715707+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】`0x4AEC01` 將 `esi` 中的實例放入 `eax`，並把 `0xFAB130` 放在堆疊，直接呼叫 `0x4DFF30`。`0x4DFF30` 在 `0x4DFF4C` 從 `[edi+4]` 取得 unsigned WORD 索引鍵，並用 `0x82EF00` 搜尋傳入容器 `ebx+8` 的樹。
- 【已確認】`0x4DFF67` 以 `[ebx+0xC]` 判斷是否走 missing 分支。missing 時準備 `{key, instance}` 寫入來源並呼叫 `0x82F200`；命中時走 `0x6EDB60` 的另一支線，**不是覆寫原節點已確認**。
- 【重要界線】此處只證實「物件到索引容器」；不能從 `0xFAB130` 推論它就是 `0x546100` 控制器物件 `[ecx+0xC]`。
- 【待查】找出容器 `0xFAB130` 的所有讀取 caller，以及 instance 指標是否複製至 controller +0xC 或 slot table。

## 呼叫與欄位證據
`0x4AEC03 → 0x4DFF30`，`0x4DFF30 → 0x82EF00 / 0x82F200 / 0x6EDB60`。物件 `esi+4` 為 WORD 鍵，容器 `ebx+8` 為樹搜尋入口。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x4aeb78–0x4aec18
```asm
004aeb78 <.text+0xadb78>:
  4aeb78:	8b 50 30             	mov    edx,DWORD PTR [eax+0x30]
  4aeb7b:	8b ce                	mov    ecx,esi
  4aeb7d:	ff d2                	call   edx
  4aeb7f:	8a 43 fc             	mov    al,BYTE PTR [ebx-0x4]
  4aeb82:	3c 01                	cmp    al,0x1
  4aeb84:	75 29                	jne    0x4aebaf
  4aeb86:	83 7c 24 20 00       	cmp    DWORD PTR [esp+0x20],0x0
  4aeb8b:	75 11                	jne    0x4aeb9e
  4aeb8d:	8b 86 68 03 00 00    	mov    eax,DWORD PTR [esi+0x368]
  4aeb93:	85 c0                	test   eax,eax
  4aeb95:	74 07                	je     0x4aeb9e
  4aeb97:	c7 40 24 00 00 00 00 	mov    DWORD PTR [eax+0x24],0x0
  4aeb9e:	33 c0                	xor    eax,eax
  4aeba0:	80 7b 13 04          	cmp    BYTE PTR [ebx+0x13],0x4
  4aeba4:	0f 94 c0             	sete   al
  4aeba7:	89 86 28 04 00 00    	mov    DWORD PTR [esi+0x428],eax
  4aebad:	eb 15                	jmp    0x4aebc4
  4aebaf:	3c 06                	cmp    al,0x6
  4aebb1:	75 11                	jne    0x4aebc4
  4aebb3:	8b 86 68 03 00 00    	mov    eax,DWORD PTR [esi+0x368]
  4aebb9:	85 c0                	test   eax,eax
  4aebbb:	74 07                	je     0x4aebc4
  4aebbd:	c7 40 24 00 00 00 00 	mov    DWORD PTR [eax+0x24],0x0
  4aebc4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aebcb:	75 2f                	jne    0x4aebfc
  4aebcd:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aebd4:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xd
  4aebdb:	0d 00 00 00 
  4aebdf:	e8 ac 00 03 00       	call   0x4dec90
  4aebe4:	68 30 ce bc 00       	push   0xbcce30
  4aebe9:	e8 2c 37 3e 00       	call   0x89231a
  4aebee:	83 c4 04             	add    esp,0x4
  4aebf1:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aebf8:	ff ff ff ff 
  4aebfc:	68 30 b1 fa 00       	push   0xfab130
  4aec01:	8b c6                	mov    eax,esi
  4aec03:	e8 28 13 03 00       	call   0x4dff30
  4aec08:	83 7b 0e 00          	cmp    DWORD PTR [ebx+0xe],0x0
  4aec0c:	0f 84 86 00 00 00    	je     0x4aec98
  4aec12:	f6                   	.byte 0xf6
  4aec13:	05 2c b2 fa 00       	add    eax,0xfab22c
```

### VA 0x4dff30–0x4dffaa
```asm
004dff30 <.text+0xdef30>:
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
```