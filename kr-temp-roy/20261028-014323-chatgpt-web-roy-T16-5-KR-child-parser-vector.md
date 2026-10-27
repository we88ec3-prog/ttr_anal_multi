# T16-5 — KR 任務候選屬性解析器／子節點容器

- 執行時間（Asia/Taipei）：20261028-014323
- 任務：T16 Quest & Story Progression，版本 KR（TC 本輪僅索引，不做異版推定）
- 第一手映像：Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，以唯讀靜態 objdump 驗證
- VA 對映：KR PE `.text` 0x401000 ↔ raw 0x400；`.rdata` 0xBD2000 ↔ raw 0x7D0600
- 工作基準：GitHub main `e1591500bef6f35acff736615109e1010264dc75`（提交前再次核對）；已有 T16-1～T16-4 研究
- 研究範圍：已存在角色的任務／教學；不重做 T03/T04/T07/T14/T15/T02；未執行遊戲、未修改客戶端或原始證據
- 分級：`native-confirmed` = 指令／常數；`native-partial` = 行為語義局部；`hypothesis` = 未完成 caller/consumer；`missing` = 沒有原版來源。

## 本段研究問題與結論
## 新證據與控制流程
`0x0053FEB0` 本段完整驗證至 `ret 4`。`push 0x00C0F4A0` → `call 0x72E2E0` 取得候選子節點。若空，直接回傳；若非空，呼叫物件虛擬槽 `+0x14` 取得元素，按 `[node+0x40]` 迭代。節點透過 `0x7300A0` 的字串常數查詢；查找到的物件在 `+0x30` 有帶 small-string optimization 檢查 `[ptr+0x14] >= 0x10`，之後使用 `0x8917B4` 做轉換，送入 `0x004A8680` 寫入 output。具體 key 的原始字串：
- `0x00c0f4a0` = `Shout`；KR .text xrefs：0x53eea2, 0x53f00b, 0x53feb6
- `0x00c0f4a8` = `talkidx`；KR .text xrefs：0x53eeec, 0x53fed4
- `0x00c0f4e4` = `Normal`；KR .text xrefs：0x53fd77

`0x004A8680` 有 vector-like `[edi] begin`, `[edi+4] end`, `[edi+8] capacity`；以四 byte 元素複製／追加，必要時呼叫 `0x6D6240` 擴容。**修正 T16-4 的籠統「任務旗標容器」說法**：這個 helper 在這條路徑中接收的是解析／轉換後的值，並無證據構成跨登入狀態。

## 局部偽碼（僅機器碼局部語義）
```cpp
void parse_child_elements(Node *node, VectorLike *out) {
  Node *list = lookup(node, KEY_C0F4A0);
  if (!list) return;
  for (Node *item = list->virtual_get_child(); item; item = item->next_at_0x40) {
    auto found = lookup_candidate(item, KEY_C0F4A8);
    uint32_t value = found ? convert(found->small_string_at_0x30) : 0;
    vector_append_or_relocate(out, value);
  }
}
```
`lookup_candidate` 的精確 ABI / string-at-0x30 解讀仍為 partial，不能當作官方 quest ID 列表。

### KR VA `0x0053FEB0..0x0053FF1D`（原生指令）
```asm
0053feb0 <.text+0x13eeb0>:
  53feb0:	55                   	push   ebp
  53feb1:	8b ec                	mov    ebp,esp
  53feb3:	51                   	push   ecx
  53feb4:	56                   	push   esi
  53feb5:	68 a0 f4 c0 00       	push   0xc0f4a0
  53feba:	e8 21 e4 1e 00       	call   0x72e2e0
  53febf:	8b f0                	mov    esi,eax
  53fec1:	85 f6                	test   esi,esi
  53fec3:	74 51                	je     0x53ff16
  53fec5:	57                   	push   edi
  53fec6:	8b 06                	mov    eax,DWORD PTR [esi]
  53fec8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  53fecb:	8b ce                	mov    ecx,esi
  53fecd:	ff d2                	call   edx
  53fecf:	85 c0                	test   eax,eax
  53fed1:	74 3b                	je     0x53ff0e
  53fed3:	68 a8 f4 c0 00       	push   0xc0f4a8
  53fed8:	8d 78 44             	lea    edi,[eax+0x44]
  53fedb:	e8 c0 01 1f 00       	call   0x7300a0
  53fee0:	85 c0                	test   eax,eax
  53fee2:	74 1a                	je     0x53fefe
  53fee4:	83 c0 30             	add    eax,0x30
  53fee7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53feeb:	72 02                	jb     0x53feef
  53feed:	8b 00                	mov    eax,DWORD PTR [eax]
  53feef:	85 c0                	test   eax,eax
  53fef1:	74 0b                	je     0x53fefe
  53fef3:	50                   	push   eax
  53fef4:	e8 bb 18 35 00       	call   0x8917b4
  53fef9:	83 c4 04             	add    esp,0x4
  53fefc:	eb 02                	jmp    0x53ff00
  53fefe:	33 c0                	xor    eax,eax
  53ff00:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53ff03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53ff06:	8d 45 fc             	lea    eax,[ebp-0x4]
  53ff09:	e8 72 87 f6 ff       	call   0x4a8680
  53ff0e:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  53ff11:	85 f6                	test   esi,esi
  53ff13:	75 b1                	jne    0x53fec6
  53ff15:	5f                   	pop    edi
  53ff16:	5e                   	pop    esi
  53ff17:	8b e5                	mov    esp,ebp
  53ff19:	5d                   	pop    ebp
  53ff1a:	c2 04 00             	ret    0x4
```
### KR VA `0x004A8680..0x004A86DC`（原生指令）
```asm
004a8680 <.text+0xa7680>:
  4a8680:	56                   	push   esi
  4a8681:	8b f0                	mov    esi,eax
  4a8683:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a8686:	3b f0                	cmp    esi,eax
  4a8688:	73 30                	jae    0x4a86ba
  4a868a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a868c:	3b ce                	cmp    ecx,esi
  4a868e:	77 2a                	ja     0x4a86ba
  4a8690:	2b f1                	sub    esi,ecx
  4a8692:	c1 fe 02             	sar    esi,0x2
  4a8695:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4a8698:	75 0c                	jne    0x4a86a6
  4a869a:	b9 01 00 00 00       	mov    ecx,0x1
  4a869f:	8b c7                	mov    eax,edi
  4a86a1:	e8 9a db 22 00       	call   0x6d6240
  4a86a6:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a86a9:	85 c0                	test   eax,eax
  4a86ab:	74 29                	je     0x4a86d6
  4a86ad:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a86af:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  4a86b2:	89 10                	mov    DWORD PTR [eax],edx
  4a86b4:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  4a86b8:	5e                   	pop    esi
  4a86b9:	c3                   	ret
  4a86ba:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4a86bd:	75 0c                	jne    0x4a86cb
  4a86bf:	b9 01 00 00 00       	mov    ecx,0x1
  4a86c4:	8b c7                	mov    eax,edi
  4a86c6:	e8 75 db 22 00       	call   0x6d6240
  4a86cb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a86ce:	85 c0                	test   eax,eax
  4a86d0:	74 04                	je     0x4a86d6
  4a86d2:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a86d4:	89 08                	mov    DWORD PTR [eax],ecx
  4a86d6:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  4a86da:	5e                   	pop    esi
  4a86db:	c3                   	ret
```

## 教學／主線節點矩陣（本段更新）
| state／節點 | evidence | 入口／觸發 | 權威／writer | 下一節點／續接 |
|---|---|---|---|---|
| Tutorial Lua 入口 | T16-1/2/3 native-partial | `0x004A8A60`, `0x004A89C0` | unknown | unknown |
| QuestInfo/QuestTalk 客戶端資料 | T16-4 native-partial | `0x00504740`, `0x00505570` | unknown | unknown |
| 首項教學目標／完成 | missing | unknown | unknown | unknown |
| 主線第一個 ID／NPC／交付 | missing | unknown | unknown | unknown |

## KR／TC 比較與驗收界線
| 項 | KR | TC | 驗收 |
|---|---|---|---|
| native SHA | 直接讀取與驗證 | `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873` 僅 repo 登記 | KR pass，TC 未直接驗證 |
| 函式／偏移 | 本篇所列只對 KR 有效 | unknown | 不得搬用 |
| 教學完整路線 | unknown | unknown | 未達標 |
| 首段主線閉環／伺服器授權 | unknown | unknown | 未達標 |
| 角色初始值 | T04 主責 | T04 主責 | 不在 T16 重作 |
| 可玩測試 | 未執行 | 未執行 | 未驗收 |

## 跨 Task 介面與後續查核
- T04 → T16：已有角色資料的教學適用條件／旗標來源 `unknown`。
- T02 ↔ T16：Quest 網路命令／權威 `unknown`；不可把 UI 或 Lua 呼叫視為伺服器寫入。
- T07/T14 → T16：關卡結果映射到 quest step `unknown`。
- T15 ↔ T16：保存與重登續接契約 `unknown`。
- 既有 `005F type6` 與歷史 tutorial fixture 無權擴大認定。
- 不以「反編譯已上傳」判定整體函式語義驗證完成。

## 提交狀態
本文件產生時不代表已 GitHub 提交；由本對話完成 T16-8 後逐檔提交及讀回核實。