# T16-14 — KR `0x0053EBA0` 16-byte 記錄輸出與 buffer 擴充

- 研究時間：20261028-020402 Asia/Taipei（本機 UTC 時間換算）
- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。
- 分支基準：本批開始時 GitHub `main` `69911d157697ede14e1507109b936620416048a8`，但提交前必須再核對。
- 證據策略：本批的機器碼來自當前唯讀 KR BIN 直接 objdump；無法取得原版 Lua/XML 正文或 TC BIN，業務語義不得假定。
- 原始檔沒有執行、附加或修改；只提交分析者個人目錄完整 Markdown，保留其他任務的 owner 與 catalog。

## 核心問題
T16-9 可見 `0x004AE8A9` 讀取 tree node `+0x10`，`0x004AE8C7` 呼叫 `0x0053EBA0`。本段檢查其輸出資料型別與邊界，防止把純客戶端資料轉換誤命名為伺服器任務進度。

## BIN 組語直接證據
`0x0053EBA0` 到下一方法入口：

```asm
0053eba0 <.text+0x13dba0>:
  53eba0:	56                   	push   esi
  53eba1:	8b f0                	mov    esi,eax
  53eba3:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  53eba6:	3b f0                	cmp    esi,eax
  53eba8:	73 1b                	jae    0x53ebc5
  53ebaa:	8b 0f                	mov    ecx,DWORD PTR [edi]
  53ebac:	3b ce                	cmp    ecx,esi
  53ebae:	77 15                	ja     0x53ebc5
  53ebb0:	2b f1                	sub    esi,ecx
  53ebb2:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  53ebb5:	75 07                	jne    0x53ebbe
  53ebb7:	8b cf                	mov    ecx,edi
  53ebb9:	e8 42 00 00 00       	call   0x53ec00
  53ebbe:	83 e6 f0             	and    esi,0xfffffff0
  53ebc1:	03 37                	add    esi,DWORD PTR [edi]
  53ebc3:	eb 0c                	jmp    0x53ebd1
  53ebc5:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  53ebc8:	75 07                	jne    0x53ebd1
  53ebca:	8b cf                	mov    ecx,edi
  53ebcc:	e8 2f 00 00 00       	call   0x53ec00
  53ebd1:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  53ebd4:	85 c0                	test   eax,eax
  53ebd6:	74 16                	je     0x53ebee
  53ebd8:	8b 0e                	mov    ecx,DWORD PTR [esi]
  53ebda:	89 08                	mov    DWORD PTR [eax],ecx
  53ebdc:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  53ebdf:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  53ebe2:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  53ebe5:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  53ebe8:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  53ebeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53ebee:	83 47 04 10          	add    DWORD PTR [edi+0x4],0x10
  53ebf2:	5e                   	pop    esi
  53ebf3:	c3                   	ret
```

`0x0053EC00` 擴充容量：

```asm
0053ec00 <.text+0x13dc00>:
  53ec00:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  53ec03:	56                   	push   esi
  53ec04:	8b 31                	mov    esi,DWORD PTR [ecx]
  53ec06:	2b c6                	sub    eax,esi
  53ec08:	c1 f8 04             	sar    eax,0x4
  53ec0b:	3d fe ff ff 0f       	cmp    eax,0xffffffe
  53ec10:	76 0a                	jbe    0x53ec1c
  53ec12:	68 78 23 bf 00       	push   0xbf2378
  53ec17:	e8 14 ef 33 00       	call   0x87db30
  53ec1c:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  53ec1f:	2b d6                	sub    edx,esi
  53ec21:	40                   	inc    eax
  53ec22:	c1 fa 04             	sar    edx,0x4
  53ec25:	3b c2                	cmp    eax,edx
  53ec27:	76 2d                	jbe    0x53ec56
  53ec29:	57                   	push   edi
  53ec2a:	8b f2                	mov    esi,edx
  53ec2c:	d1 ee                	shr    esi,1
  53ec2e:	bf ff ff ff 0f       	mov    edi,0xfffffff
  53ec33:	2b fe                	sub    edi,esi
  53ec35:	3b fa                	cmp    edi,edx
  53ec37:	5f                   	pop    edi
  53ec38:	73 0f                	jae    0x53ec49
  53ec3a:	33 d2                	xor    edx,edx
  53ec3c:	3b d0                	cmp    edx,eax
  53ec3e:	0f 42 d0             	cmovb  edx,eax
  53ec41:	52                   	push   edx
  53ec42:	e8 19 2c ff ff       	call   0x531860
  53ec47:	5e                   	pop    esi
  53ec48:	c3                   	ret
  53ec49:	03 d6                	add    edx,esi
  53ec4b:	3b d0                	cmp    edx,eax
  53ec4d:	0f 42 d0             	cmovb  edx,eax
  53ec50:	52                   	push   edx
  53ec51:	e8 0a 2c ff ff       	call   0x531860
  53ec56:	5e                   	pop    esi
  53ec57:	c3                   	ret
```

呼叫者給定資料：

```asm
004ae89a <.text+0xad89a>:
  4ae89a:	3b 0d e0 18 fe 00    	cmp    ecx,DWORD PTR ds:0xfe18e0
  4ae8a0:	74 2e                	je     0x4ae8d0
  4ae8a2:	8a 43 fd             	mov    al,BYTE PTR [ebx-0x3]
  4ae8a5:	88 44 24 44          	mov    BYTE PTR [esp+0x44],al
  4ae8a9:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  4ae8ac:	8b 0d ec 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe18ec
  4ae8b2:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  4ae8b6:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae8ba:	bf cc 18 fe 00       	mov    edi,0xfe18cc
  4ae8bf:	89 74 24 48          	mov    DWORD PTR [esp+0x48],esi
  4ae8c3:	89 4c 24 50          	mov    DWORD PTR [esp+0x50],ecx
  4ae8c7:	e8 d4 02 09 00       	call   0x53eba0
  4ae8cc:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
```

## 結構證據與控制流程
- `[edi]`, `[edi+4]`, `[edi+8]` 是 begin/end/capacity 風格的指標集合；`0x53eba3` 讀 end，`0x53ebb2` 比 capacity，等量時轉 `0x53ec00`。
- `0x53eba3..0x53ebc3` 警惕**來源別名**：若 `esi` 位於現有 begin/end 範圍，就把偏移調整到新配置的記憶體位置（`and esi, 0xFFFFFFF0`）。
- `0x53ebd8..0x53ebeb` 搬移 **4 個 dword，共 16 bytes**；`0x53ebee` 將 `[edi+4]` 加上 0x10。
- `0x53ec06..0x53ec25` 以 >>4 計算已用與容量元素數量，`0x53ec49..0x53ec51` 呼叫 `0x531860` 進行緩衝區增加。
- `0x004AE8A2` 取 `[ebx-3]` 一個 byte、`0x004AE87C` 取 `[ebx]` WORD 作為 key；`0x004AE8A9` 取索引節點的 `+0x10` payload，再配全域 `[0xFE18EC]`，形成四欄位候選輸出。
- 該全域 payload **沒有**證據是 QuestId、QuestStep 或 NPC ID。

## 局部偽碼
```cpp
struct Vec16 { unsigned char* begin, *end, *capacity_end; };
void append_16_bytes(Vec16* v, const void* record) {
    // 視 record 是否別名指向 v->buffer 再增容，避免悬空指標。
    if (v->end == v->capacity_end) grow_for_one(v);
    copy_16_bytes(v->end, record);
    v->end += 16;
}
```
本偽碼省略指令實際的別名重算與 grow 前後順序，僅為 high-level 示意。

## 反證與下一步
先前把 `0xFE18DC` 命名為 Quest Progress DB 沒有 native 支持。反之，本次已確認「整數 key 查表 → payload → 16 byte client-side vector」，但仍不知道這 16 bytes 是哪類業務紀錄。

## 統一證據定性
- **原生已確認**：精確 x86 位址、指令、可辨識的比較與資料搬移。
- **部分確認**：資料結構模式；未還原型別、上游物件語義或真正業務含義。
- **合理推測**：可能為通用 tree/vector 元件，僅根據指令形態。
- **資訊缺失**：任務 ID、教學步驟、首次主線、權威伺服器、跨登入保存、TC 對應。
- **AI 替代／待補開發**：本段沒有使用 AI fixture 作為原生證據，也沒有進行實作。

## KR/TC、跨 Task 邊界與驗收
| 項目 | KR | TC | 是否可玩驗收 |
|---|---|---|---|
| 此處指令路徑 | KR BIN 直接驗證，精確 VA 如下 | 原始 TC BIN 未提供，不能套 KR 位址 | 未測試 |
| 教學進度/主線任務 | 尚無原版 Lua/XML 和伺服器資料 | unknown | 未測試 |
| 任務封包與伺服器權威 | 未追到已證實的 quest-state writer | unknown | 未測試 |

T16 只研究任務資料消費及進度語義。T02 負責封包框架；T03/T04 已存在角色狀態；T07 場景進出；T14 關卡結果；T15 資料保存。不得將通用容器機制認領為新 T16 主責方法。

## 下一段交接
T16-15 追寫入索引的 parser 鍵值來源與初始化旗標，檢查 reader / writer 是否真屬相同資料域。