# KR T08-154 — actor removal upstream callers

- 研究時間：2026-10-28T01:43:15+08:00 Asia/Taipei；研究者：`chatgpt-web roy`。
- KR 原始檔：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本地實際重新核對）；唯讀靜態分析，未啟動或修改程式。
- 原始碼來源：本次使用 GNU objdump 對 PE32 `.text` 的 VA 反組譯及 E8 相對目的地直接核查。**完整 `.text` 線性反組譯掃描只建立 direct-call 候選集合，不等同完整 CFG，亦可能包括誤解碼區。**
- GitHub 整合：前次查核 main HEAD `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；最新 HEAD 需於提交前複核。正式 T08 為 0007 建立／登記／移除資料介面；不替代 T02/T06/T07 分工。
- 歷史來源：T08-153 及整合重審-01/02；保留本次覆核與舊報告證據等級差異。

## 本批目標及主要結論

從 153 的 `0x4DFBC0 / 0x4DFC90 / 0x4DFD40 / 0x4DFE90` 反追**直接上游**。第一手確認 `0x4B2A...` 確實由封包形式資料提取每筆 WORD ID，`0x4B3710` 以另一個資料結構的 WORD 清單做按欄位批次移除。兩者並非同一種刪除鍵；完整指令如下。

### 1. 以 actor ID 單筆移除：`0x4B2A...` → `0x4DFBC0`

`0x4B2AB5` 取迴圈資料指標，`0x4B2AB9` 讀 `WORD [eax]`，`0x4B2ABC push ecx`，`0x4B2ABD mov eax,0xFAB130`，`0x4B2AC2 call 0x4DFBC0`。之後 `0x4B2AC7` 指標加 2、`0x4B2ACC` 計數遞減、`0x4B2AD0` 非零回跳到 `0x4B2928`。**這是上游 2-byte ID 陣列迭代確證；本段未把 0x4B2928 的接收命令編號命名為某個 opcode，仍需追 dispatch 登錄。**

函式局部還掃描 `[0xFBA7A4]` 控制器的三槽資料，`0x4B2A6B cmp word [edi+4],si` 先核對目前 actor ID、選擇虛擬 `+0x14` 的分支；不能只因之後還呼叫 `4DFBC0` 就認為前置控制器 call 是所有物件的通用生命週期。

```asm
  4b2a56:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4b2a5c:	66 8b 76 04          	mov    si,WORD PTR [esi+0x4]
  4b2a60:	33 c0                	xor    eax,eax
  4b2a62:	8d 51 0c             	lea    edx,[ecx+0xc]
  4b2a65:	8b 3a                	mov    edi,DWORD PTR [edx]
  4b2a67:	85 ff                	test   edi,edi
  4b2a69:	74 06                	je     0x4b2a71
  4b2a6b:	66 39 77 04          	cmp    WORD PTR [edi+0x4],si
  4b2a6f:	74 0c                	je     0x4b2a7d
  4b2a71:	03 c3                	add    eax,ebx
  4b2a73:	83 c2 0c             	add    edx,0xc
  4b2a76:	83 f8 03             	cmp    eax,0x3
  4b2a79:	7c ea                	jl     0x4b2a65
  4b2a7b:	eb 0c                	jmp    0x4b2a89
  4b2a7d:	83 f8 ff             	cmp    eax,0xffffffff
  4b2a80:	74 07                	je     0x4b2a89
  4b2a82:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b2a84:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b2a87:	ff d2                	call   edx
  4b2a89:	84 1d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,bl
  4b2a8f:	75 24                	jne    0x4b2ab5
  4b2a91:	09 1d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ebx
  4b2a97:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  4b2a9b:	e8 f0 c1 02 00       	call   0x4dec90
  4b2aa0:	68 30 ce bc 00       	push   0xbcce30
  4b2aa5:	e8 70 f8 3d 00       	call   0x89231a
  4b2aaa:	83 c4 04             	add    esp,0x4
  4b2aad:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  4b2ab4:	ff 
  4b2ab5:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4b2ab9:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4b2abc:	51                   	push   ecx
  4b2abd:	b8 30 b1 fa 00       	mov    eax,0xfab130
  4b2ac2:	e8 f9 d0 02 00       	call   0x4dfbc0
  4b2ac7:	83 44 24 14 02       	add    DWORD PTR [esp+0x14],0x2
  4b2acc:	29 5c 24 18          	sub    DWORD PTR [esp+0x18],ebx
  4b2ad0:	0f 85 52 fe ff ff    	jne    0x4b2928
  4b2ad6:	33 c0                	xor    eax,eax
  4b2ad8:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  4b2adc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b2ae3:	59                   	pop    ecx
  4b2ae4:	5f                   	pop    edi
  4b2ae5:	5e                   	pop    esi
  4b2ae6:	5b                   	pop    ebx
  4b2ae7:	8b e5                	mov    esp,ebp
  4b2ae9:	5d                   	pop    ebp
  4b2aea:	c2               	ret    0xc
```

### 2. 另一個單 ID API `0x4A9FE0` → `0x4DFBC0`

`0x4AA009` 從 `[ebp+8]` 提取**低一 byte**，建構 WORD local（高 byte 零），之後 `0x4AA04C movzx edx,word [esp+8]`、`0x4AA052 mov eax,0xFAB130`、`0x4AA057 call 0x4DFBC0`。與上節收取完整 WORD 的路徑不同，這條入口可能只能傳 0..255 key；**僅此限定入口成立，不能改寫 4DFBC0 自身的 key 寬度。** `0xFAB22C` bit0 是一次性 init guard，不是刪除執行資格證明。

```asm
  4a9fe0:	55                   	push   ebp
  4a9fe1:	8b ec                	mov    ebp,esp
  4a9fe3:	83 e4 f8             	and    esp,0xfffffff8
  4a9fe6:	6a ff                	push   0xffffffff
  4a9fe8:	68 fe 6e 93 00       	push   0x936efe
  4a9fed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a9ff3:	50                   	push   eax
  4a9ff4:	83 ec 0c             	sub    esp,0xc
  4a9ff7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a9ffc:	33 c4                	xor    eax,esp
  4a9ffe:	50                   	push   eax
  4a9fff:	8d 44 24 10          	lea    eax,[esp+0x10]
  4aa003:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aa009:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4aa00c:	33 c0                	xor    eax,eax
  4aa00e:	66 89 44 24 08       	mov    WORD PTR [esp+0x8],ax
  4aa013:	88 4c 24 09          	mov    BYTE PTR [esp+0x9],cl
  4aa017:	b9 01 00 00 00       	mov    ecx,0x1
  4aa01c:	88 44 24 08          	mov    BYTE PTR [esp+0x8],al
  4aa020:	84 0d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,cl
  4aa026:	75 24                	jne    0x4aa04c
  4aa028:	09 0d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ecx
  4aa02e:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4aa032:	e8 59 4c 03 00       	call   0x4dec90
  4aa037:	68 30 ce bc 00       	push   0xbcce30
  4aa03c:	e8 d9 82 3e 00       	call   0x89231a
  4aa041:	83 c4 04             	add    esp,0x4
  4aa044:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4aa04b:	ff 
  4aa04c:	0f b7 54 24 08       	movzx  edx,WORD PTR [esp+0x8]
  4aa051:	52                   	push   edx
  4aa052:	b8 30 b1 fa 00       	mov    eax,0xfab130
  4aa057:	e8 64 5b 03 00       	call   0x4dfbc0
  4aa05c:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4aa060:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aa067:	59                   	pop    ecx
  4aa068:	8b e5                	mov    esp,ebp
  4aa06a:	5d                   	pop    ebp
  4aa06b:	c2               	ret    0x4
```

### 3. `0x4B3710` → `0x4DFC90`：不同 key domain

`0x4B3713` 載入 `[ebp+0xC]`，對小於 2 的長度採零筆，其他走 `(len-2)>>1`；迴圈從 buffer+2 讀取 WORD，以 `OR 0x06000000` 建立**複合 DWORD**，`push` 後 `0x40F060` 轉換／定位，`0x4B373E` 再呼叫 `0x4DFC90`（重要：需核對 `40F060` 的回傳參數／寄存器及該 callee 的 ABI；不能直接說是 raw packet actor ID）。`4DFC90` 以 `actor+0x88` 比較輸入 key，不等同 `actor+0x04`。

```asm
  4b3710:	55                   	push   ebp
  4b3711:	8b ec                	mov    ebp,esp
  4b3713:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b3716:	57                   	push   edi
  4b3717:	83 f8 02             	cmp    eax,0x2
  4b371a:	73 04                	jae    0x4b3720
  4b371c:	33 ff                	xor    edi,edi
  4b371e:	eb 05                	jmp    0x4b3725
  4b3720:	8d 78 fe             	lea    edi,[eax-0x2]
  4b3723:	d1 ef                	shr    edi,1
  4b3725:	85 ff                	test   edi,edi
  4b3727:	74 21                	je     0x4b374a
  4b3729:	56                   	push   esi
  4b372a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b372d:	83 c6 02             	add    esi,0x2
  4b3730:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4b3733:	0d 00 00 00 06       	or     eax,0x6000000
  4b3738:	50                   	push   eax
  4b3739:	e8 22 b9 f5 ff       	call   0x40f060
  4b373e:	e8 4d c5 02 00       	call   0x4dfc90
  4b3743:	83 c6 02             	add    esi,0x2
  4b3746:	4f                   	dec    edi
  4b3747:	75 e7                	jne    0x4b3730
  4b3749:	5e                   	pop    esi
  4b374a:	33 c0                	xor    eax,eax
  4b374c:	5f                   	pop    edi
  4b374d:	5d                   	pop    ebp
  4b374e:	c2 0c              	ret    0xc
```

### 4. `0x4DFD40` 8 個直接入口及類型篩選

線性 direct-call 命中集中於 `0x4B1A39 / 4B1A79 / 4B1A99 / 4B1B16 / 4B1B4E / 4B1B8A / 4B1BB9 / 4B1BD9`，其中已可由 caller 的 `push immediate` 確認常數類型 `0x02/0x09/0x08/0x07/0x03` 等，但必須與 `4DFD40` 內從 `actor+4` 讀取 BYTE 的實際比較結合；不能稱其會以完整 WORD actor ID 移除全部實體。

```asm
  4b1b00:	16                   	push   ss
  4b1b01:	08 3e                	or     BYTE PTR [esi],bh
  4b1b03:	00 83 c4 04 c7 44    	add    BYTE PTR [ebx+0x44c704c4],al
  4b1b09:	24 18                	and    al,0x18
  4b1b0b:	ff                   	(bad)
  4b1b0c:	ff                   	(bad)
  4b1b0d:	ff                   	(bad)
  4b1b0e:	ff 6a 02             	jmp    FWORD PTR [edx+0x2]
  4b1b11:	b9 30 b1 fa 00       	mov    ecx,0xfab130
  4b1b16:	e8 25 e2 02 00       	call   0x4dfd40
  4b1b1b:	84 1d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,bl
  4b1b21:	75 24                	jne    0x4b1b47
  4b1b23:	09 1d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ebx
  4b1b29:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  4b1b2d:	e8 5e d1 02 00       	call   0x4dec90
  4b1b32:	68 30 ce bc 00       	push   0xbcce30
  4b1b37:	e8 de 07 3e 00       	call   0x89231a
  4b1b3c:	83 c4 04             	add    esp,0x4
  4b1b3f:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4b1b46:	ff 
  4b1b47:	6a 09                	push   0x9
  4b1b49:	b9 30 b1 fa 00       	mov    ecx,0xfab130
  4b1b4e:	e8 ed e1 02 00       	call   0x4dfd40
  4b1b53:	84 1d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,bl
  4b1b59:	75 28                	jne    0x4b1b83
  4b1b5b:	09 1d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ebx
  4b1b61:	c7 44 24 18 02 00 00 	mov    DWORD PTR [esp+0x18],0x2
  4b1b68:	00 
  4b1b69:	e8 22 d1 02 00       	call   0x4dec90
  4b1b6e:	68 30 ce bc 00       	push   0xbcce30
  4b1b73:	e8 a2 07 3e 00       	call   0x89231a
  4b1b78:	83 c4 04             	add    esp,0x4
  4b1b7b:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4b1b82:	ff 
  4b1b83:	6a 08                	push   0x8
  4b1b85:	b9 30 b1 fa 00       	mov    ecx,0xfab130
  4b1b8a:	e8 b1 e1 02 00       	call   0x4dfd40
  4b1b8f:	33 c0                	xor    eax,eax
  4b1b91:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4b1b95:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b1b9c:	59                   	pop    ecx
  4b1b9d:	5b                   	pop    ebx
  4b1b9e:	8b e5                	mov    esp,ebp
  4b1ba0:	5d                   	pop    ebp
  4b1ba1:	c2 0c 00             	ret    0xc
  4b1ba4:	cc                   	int3
  4b1ba5:	cc                   	int3
  4b1ba6:	cc                   	int3
  4b1ba7:	cc                   	int3
  4b1ba8:	cc                   	int3
  4b1ba9:	cc                   	int3
  4b1baa:	cc                   	int3
  4b1bab:	cc                   	int3
  4b1bac:	cc                   	int3
  4b1bad:	cc                   	int3
  4b1bae:	cc                   	int3
  4b1baf:	cc                   	int3
  4b1bb0:	6a 07                	push   0x7
  4b1bb2:	e8 a9 d4 f5 ff       	call   0x40f060
  4b1bb7:	8b c8                	mov    ecx,eax
  4b1bb9:	e8 82 e1 02 00       	call   0x4dfd40
  4b1bbe:	33 c0                	xor    eax,eax
  4b1bc0:	c2 0c 00             	ret    0xc
  4b1bc3:	cc                   	int3
  4b1bc4:	cc                   	int3
  4b1bc5:	cc                   	int3
  4b1bc6:	cc                   	int3
  4b1bc7:	cc                   	int3
  4b1bc8:	cc                   	int3
  4b1bc9:	cc                   	int3
  4b1bca:	cc                   	int3
  4b1bcb:	cc                   	int3
  4b1bcc:	cc                   	int3
  4b1bcd:	cc                   	int3
  4b1bce:	cc                   	int3
  4b1bcf:	cc                   	int3
  4b1bd0:	6a 03                	push   0x3
  4b1bd2:	e8 89 d4 f5 ff       	call   0x40f060
  4b1bd7:	8b c8                	mov    ecx,eax
  4b1bd9:	e8 62 e1 02 00       	call   0x4dfd40
  4b1bde:	33 c0                	xor    eax,eax
  4b1be0:	c2 0c 00             	ret    0xc
  4b1be3:	cc                   	int3
  4b1be4:	cc                   	int3
```

### 5. 已核對 direct-call 候選清單（非完整動態 caller 集合）

```text
[4DFBC0]
4aa057:	e8 64 5b 03 00       	call   0x4dfbc0
4b2ac2:	e8 f9 d0 02 00       	call   0x4dfbc0
[4DFC90]
4b373e:	e8 4d c5 02 00       	call   0x4dfc90
[4DFD40]
4b1a39:	e8 02 e3 02 00       	call   0x4dfd40
4b1a79:	e8 c2 e2 02 00       	call   0x4dfd40
4b1a99:	e8 a2 e2 02 00       	call   0x4dfd40
4b1b16:	e8 25 e2 02 00       	call   0x4dfd40
4b1b4e:	e8 ed e1 02 00       	call   0x4dfd40
4b1b8a:	e8 b1 e1 02 00       	call   0x4dfd40
4b1bb9:	e8 82 e1 02 00       	call   0x4dfd40
4b1bd9:	e8 62 e1 02 00       	call   0x4dfd40
[4DFE90]
424448:	e8 43 ba 0b 00       	call   0x4dfe90
4ba9c9:	e8 c2 54 02 00       	call   0x4dfe90
4bb62a:	e8 61 48 02 00       	call   0x4dfe90
4bbcf0:	e8 9b 41 02 00       	call   0x4dfe90
4bc423:	e8 68 3a 02 00       	call   0x4dfe90
4bccda:	e8 b1 31 02 00       	call   0x4dfe90
4be5af:	e8 dc 18 02 00       	call   0x4dfe90
4c1706:	e8 85 e7 01 00       	call   0x4dfe90
4c33e6:	e8 a5 ca 01 00       	call   0x4dfe90
4c4be3:	e8 a8 b2 01 00       	call   0x4dfe90
4c5aa8:	e8 e3 a3 01 00       	call   0x4dfe90
```

## 可驗證資料流與跨任務邊界

```cpp
// 僅限 0x4B2AB5 分支所見；完整接收器及長度驗證尚待核對。
while (count != 0) {
    uint16_t id = readLE16(cursor);
    eraseActorCandidate((GameInfoLike*)0xFAB130, id); // 4DFBC0
    cursor += 2; --count;
}
// 不同的 4B3710：從 length 計算個數，構造 0x06000000|word，
// 經 40F060，送 4DFC90；不是上述 actor-ID erase。
```

- **已確認**：E8 目的地、局部推入參數、buffer 每筆寬度與迴圈增量、主 receiver 常量 `0xFAB130`。
- **部分確認**：這些路徑是封包形狀的接收端；尚未在本段證明其實際 dispatcher 的命令編號，不能替 T02 完成封包編號宣告。
- **待查**：`0x4B2928` 完整封包讀取失敗分支、`0x40F060` 回傳語意、 `0x4B1A...` 的上游命令註冊與 0007 的 owner 關係。
- **反證**：單純 `call 4DFBC0` 或  `call 4DFE90` 不等於「怪物死亡事件」，亦不等於「每波生成自動回收」。

下一段 T08-155 追 `0x7B6890` 容器節點 erase 本體與 caller 所有權。