# KR T10-6 — 映射樹資料取得與靜態初始化邊界

紀錄日期：2026-10-27T19:11:40+08:00

## 0. 來源與限制
- 研究對象：韓版 KR T10「普通攻擊與連段」，使用者指出 Z 連按、Z 按住不放兩種操作。
- 原始檔 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；僅唯讀，PE `.text` VA `0x00401000` 對映檔案 raw `0x400`；GNU objdump `-b binary -mi386 -Mintel --adjust-vma`。**所有位址為 VA，函式名稱除符號佐證者均為暫定。**
- 已有 T10-1～T10-4 原稿作背景；本段新增事項皆以本次 raw BIN 讀取核對。未啟動／附加遊戲或修改任何原始資料。
- 原生證據只證明目前觀察到的機器碼與資料流；不可反推出 Z 對應 bit、實際連段時間、是否可玩。

## 1. 分析與證據
本段剖析上段查詢使用的 `0x6D43F0`，並確認 `0x6D1DA0` 並非每次按鍵觸發的「長按狀態更新」。

**樹查找**：`0x6D441A` 取 `[ebp+8]` 為被查容器，`0x6D4420` 取得樹 root；`0x6D4427` 讀節點 `+0x21` 哨兵標誌，循環在 `0x6D4430` 比較查詢 key `[edi]` 與 node `+0x0C`，沿 child 指標尋找 lower_bound 類候選。`0x6D4443～0x6D444F` 依找到與否決定進入建立路徑。`0x6D446E` 呼叫 `0x4FCAE0`，`0x6D447F` 呼叫 `0x6D48A0`（具容器變更副作用的候選）。其返回 `lea eax,[esi+0x10]` 指向**節點內欄位**，並非直接回傳單一 bool。

**初始化**：`0x6D1DA0` 對 `0xFDF3F4` 為起點的 16-byte 項目進行建構，傳入項目大小 `0x10`、數量 `3`，配置 `0x0C`、`0x18` 的容器管理記錄並初始化多組全域位址，相關地址為 `0xFDF624/0xFDF634/0xFDF644/0xFDF654`。這是初始化大型資料系統的局部證據，**不能宣稱它代表某個按鍵被按住**。

**暫定 C++ 邊界**：
```cpp
Value* getOrCreate(Tree& tree, Key key) {
  Node* candidate = lowerBound(tree, key);
  if (candidateNotExact(candidate, key)) candidate = insertNode(tree, key);
  return &candidate->value; // node + 0x10 in observed path
}
```

**重要區隔**：`0x6D43F0` 的節點比較、插入與 `0x54F4E0` 舊研究中的另一套樹不能只因 offset 相似即合併成同一資料型別。`0x6D1DA0` 的值是結構初始化，不是 500ms 計時器。所有推測以不同呼叫者與物件指標來源重新核對。

**證據分級**：確定＝節點哨兵、key 比較、`0xFDF3F4` 陣列建構、配置大小；合理推測＝map get-or-insert；未確認＝完整 key/value 類別、插入後內容來源、與 Z 事件語義。

**T10-7 接續方向**：轉回 runtime 控制器 `0x546780`，重建各輸入來源合併時的優先順序與 Word/Byte 位置。


## 2. 原始 BIN 組語摘錄（逐址重新反組譯）
### 0x6D43F0 的樹查找與可能插入 (VA `0x006D4418`)
```asm
  6d4418:	8b f9                	mov    edi,ecx
  6d441a:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  6d441d:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  6d4420:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  6d4423:	33 db                	xor    ebx,ebx
  6d4425:	8b f1                	mov    esi,ecx
  6d4427:	38 58 21             	cmp    BYTE PTR [eax+0x21],bl
  6d442a:	75 17                	jne    0x6d4443
  6d442c:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6d442e:	8b ff                	mov    edi,edi
  6d4430:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  6d4433:	73 05                	jae    0x6d443a
  6d4435:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  6d4438:	eb 04                	jmp    0x6d443e
  6d443a:	8b f0                	mov    esi,eax
  6d443c:	8b 00                	mov    eax,DWORD PTR [eax]
  6d443e:	38 58 21             	cmp    BYTE PTR [eax+0x21],bl
  6d4441:	74 ed                	je     0x6d4430
  6d4443:	3b 72 04             	cmp    esi,DWORD PTR [edx+0x4]
  6d4446:	74 07                	je     0x6d444f
  6d4448:	8b 07                	mov    eax,DWORD PTR [edi]
  6d444a:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  6d444d:	73 48                	jae    0x6d4497
  6d444f:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4452:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6d4454:	89 4d d0             	mov    DWORD PTR [ebp-0x30],ecx
  6d4457:	89 5d d4             	mov    DWORD PTR [ebp-0x2c],ebx
  6d445a:	89 5d d8             	mov    DWORD PTR [ebp-0x28],ebx
  6d445d:	89 5d dc             	mov    DWORD PTR [ebp-0x24],ebx
  6d4460:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  6d4463:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  6d4466:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  6d4469:	8d 7d d0             	lea    edi,[ebp-0x30]
  6d446c:	8b ca                	mov    ecx,edx
  6d446e:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  6d4472:	e8 69 86 e2 ff       	call   0x4fcae0
  6d4477:	50                   	push   eax
  6d4478:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d447b:	56                   	push   esi
  6d447c:	8d 75 08             	lea    esi,[ebp+0x8]
  6d447f:	e8 1c 04 00 00       	call   0x6d48a0
  6d4484:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  6d4487:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6d448a:	3b c3                	cmp    eax,ebx
  6d448c:	74 09                	je     0x6d4497
  6d448e:	50                   	push   eax
  6d448f:	e8 78 cd 1b 00       	call   0x89120c
  6d4494:	83 c4 04             	add    esp,0x4
  6d4497:	8d 46 10             	lea    eax,[esi+0x10]
  6d449a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d449d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d44a4:	59                   	pop    ecx
  6d44a5:	5f                   	pop    edi
  6d44a6:	5e                   	pop    esi
  6d44a7:	5b                   	pop    ebx
  6d44a8:	8b                   	.byte 0x8b
```

### 0x6D1DA0 建構輸入映射容器 (VA `0x006D1DC8`)
```asm
  6d1dc8:	68 b0 2c 6d 00       	push   0x6d2cb0
  6d1dcd:	68 40 2c 6d 00       	push   0x6d2c40
  6d1dd2:	6a 03                	push   0x3
  6d1dd4:	6a 10                	push   0x10
  6d1dd6:	33 f6                	xor    esi,esi
  6d1dd8:	68 f4 f3 fd 00       	push   0xfdf3f4
  6d1ddd:	c7 45 e8 f0 f3 fd 00 	mov    DWORD PTR [ebp-0x18],0xfdf3f0
  6d1de4:	89 35 f0 f3 fd 00    	mov    DWORD PTR ds:0xfdf3f0,esi
  6d1dea:	e8 14 02 1c 00       	call   0x892003
  6d1def:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d1df2:	6a 0c                	push   0xc
  6d1df4:	89 35 28 f6 fd 00    	mov    DWORD PTR ds:0xfdf628,esi
  6d1dfa:	e8 69 f4 1b 00       	call   0x891268
  6d1dff:	83 c4 04             	add    esp,0x4
  6d1e02:	3b c6                	cmp    eax,esi
  6d1e04:	0f 84 08 0e 00 00    	je     0x6d2c12
  6d1e0a:	a3 24 f6 fd 00       	mov    ds:0xfdf624,eax
  6d1e0f:	89 00                	mov    DWORD PTR [eax],eax
  6d1e11:	a1 24 f6 fd 00       	mov    eax,ds:0xfdf624
  6d1e16:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6d1e19:	bb 01 00 00 00       	mov    ebx,0x1
  6d1e1e:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  6d1e21:	6a 18                	push   0x18
  6d1e23:	89 35 38 f6 fd 00    	mov    DWORD PTR ds:0xfdf638,esi
  6d1e29:	e8 3a f4 1b 00       	call   0x891268
  6d1e2e:	83 c4 04             	add    esp,0x4
  6d1e31:	3b c6                	cmp    eax,esi
  6d1e33:	0f 84 b5 0d 00 00    	je     0x6d2bee
  6d1e39:	a3 34 f6 fd 00       	mov    ds:0xfdf634,eax
  6d1e3e:	89 00                	mov    DWORD PTR [eax],eax
  6d1e40:	a1 34 f6 fd 00       	mov    eax,ds:0xfdf634
  6d1e45:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6d1e48:	a1 34 f6 fd 00       	mov    eax,ds:0xfdf634
  6d1e4d:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6d1e50:	a1 34 f6 fd 00       	mov    eax,ds:0xfdf634
  6d1e55:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  6d1e58:	8b 0d 34 f6 fd 00    	mov    ecx,DWORD PTR ds:0xfdf634
  6d1e5e:	88 59 15             	mov    BYTE PTR [ecx+0x15],bl
  6d1e61:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6d1e65:	6a 18                	push   0x18
  6d1e67:	89 35 48 f6 fd 00    	mov    DWORD PTR ds:0xfdf648,esi
```

### 映射查詢時的 call-site (VA `0x006D4E27`)
```asm
  6d4e27:	fc                   	cld
  6d4e28:	00 00                	add    BYTE PTR [eax],al
  6d4e2a:	00 00                	add    BYTE PTR [eax],al
  6d4e2c:	e8 6f cf ff ff       	call   0x6d1da0
  6d4e31:	68 30 e3 bc 00       	push   0xbce330
  6d4e36:	e8 df d4 1b 00       	call   0x89231a
  6d4e3b:	83 c4 04             	add    esp,0x4
  6d4e3e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  6d4e45:	56                   	push   esi
  6d4e46:	8d 4d ec             	lea    ecx,[ebp-0x14]
  6d4e49:	e8 a2 f5 ff ff       	call   0x6d43f0
  6d4e4e:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  6d4e51:	2b 10                	sub    edx,DWORD PTR [eax]
  6d4e53:	c1 fa 02             	sar    edx,0x2
  6d4e56:	39 55 08             	cmp    DWORD PTR [ebp+0x8],edx
  6d4e59:	0f 83 9b 01 00 00    	jae    0x6d4ffa
  6d4e5f:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4e66:	75 27                	jne    0x6d4e8f
  6d4e68:	b8 01 00 00 00       	mov    eax,0x1
  6d4e6d:	09 05 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,eax
  6d4e73:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d4e76:	e8 25 cf ff ff       	call   0x6d1da0
  6d4e7b:	68 30 e3 bc 00       	push   0xbce330
  6d4e80:	e8 95 d4 1b 00       	call   0x89231a
  6d4e85:	83 c4 04             	add    esp,0x4
  6d4e88:	c7                   	.byte 0xc7
  6d4e89:	45                   	inc    ebp
  6d4e8a:	fc                   	cld
```