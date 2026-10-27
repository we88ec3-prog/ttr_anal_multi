# T16-6 — KR 任務候選索引的樹節點配置與插入

- 執行時間（Asia/Taipei）：20261028-014323
- 任務：T16 Quest & Story Progression，版本 KR（TC 本輪僅索引，不做異版推定）
- 第一手映像：Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，以唯讀靜態 objdump 驗證
- VA 對映：KR PE `.text` 0x401000 ↔ raw 0x400；`.rdata` 0xBD2000 ↔ raw 0x7D0600
- 工作基準：GitHub main `e1591500bef6f35acff736615109e1010264dc75`（提交前再次核對）；已有 T16-1～T16-4 研究
- 研究範圍：已存在角色的任務／教學；不重做 T03/T04/T07/T14/T15/T02；未執行遊戲、未修改客戶端或原始證據
- 分級：`native-confirmed` = 指令／常數；`native-partial` = 行為語義局部；`hypothesis` = 未完成 caller/consumer；`missing` = 沒有原版來源。

## 本段研究問題與結論
## 新確認的 0xFE18DC 插入機制
`0x0053FDF7..0x0053FE23` 先備妥 key/value 結構，`mov esi,0xFE18DC`，呼叫 `0x0057EF20` 配置節點，再經 `0x0057E850` 插入。`0x0057EF20` 直接 `push 0x18` 呼叫 `0x891268`；節點 `[0],[+4],[+8]` 初始指向 sentinel，`+0x0C` 起拷貝 key/value，`+0x14` 清零。`0x0057E850` 使用節點 `[+0x0c]` 整數比較、左右子節點 `[0],[+8]` 尋找插入位置，`[+0x15]` 作為 sentinel 屬性判定。

**高價值更正**：這是符合平衡樹／ordered-map 的原生結構特徵，但樹 root pointer、`0xFE18DC` 對象生命周期與全部 consumer 未閉合，尚不可把它稱為「玩家當前任務狀態」。T16-4 所見 loader 解析器與這個 writer 也尚未證明來自同一個 XML。

## 觀察到的節點配置布局（假設性型別命名）
| node offset | assembly observed | semantic status |
|---|---|---|
| +0x00 | set to `[esi+4]`, next tree link | native-confirmed pointer |
| +0x04 | set to `[esi+4]`, next tree link | native-confirmed pointer |
| +0x08 | set to `[esi+4]`, next tree link | native-confirmed pointer |
| +0x0C | copied from `[edi]`, signed compare in insertion | native-confirmed 32-bit key candidate |
| +0x10 | copied from `[edi+4]` | native-confirmed field, meaning unknown |
| +0x14 | WORD zeroed; byte sentinel at +0x15 used in lookup | native-confirmed bits, exact flag names unknown |

## 局部偽碼
```cpp
Node* allocate_tree_node(KeyValue *kv, Container *tree) {
  Node* n=(Node*)allocate(0x18);
  if (!n) /*exception path*/;
  n->left=n->parent=n->right=tree->sentinel;
  n->key=kv->word0; n->payload=kv->word1;
  *(uint16_t*)&n->flags=0;
  return n;
}
// 0x57E850 uses signed less-than on key at +0x0c and calls 0x44BD00
// for insertion/rebalancing. No evidence yet for cross-login storage.
```

### KR VA `0x0053FDF7..0x0053FE27`（原生指令）
```asm
0053fdf7 <.text+0x13edf7>:
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe      	jne    0x53fcf5
```
### KR VA `0x0057EF20..0x0057EF85`（原生指令）
```asm
0057ef20 <.text+0x17df20>:
  57ef20:	55                   	push   ebp
  57ef21:	8b ec                	mov    ebp,esp
  57ef23:	83 ec 10             	sub    esp,0x10
  57ef26:	6a 18                	push   0x18
  57ef28:	e8 3b 23 31 00       	call   0x891268
  57ef2d:	33 d2                	xor    edx,edx
  57ef2f:	83 c4 04             	add    esp,0x4
  57ef32:	3b c2                	cmp    eax,edx
  57ef34:	74 2a                	je     0x57ef60
  57ef36:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef39:	89 08                	mov    DWORD PTR [eax],ecx
  57ef3b:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef3e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  57ef41:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef44:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  57ef47:	8d 48 0c             	lea    ecx,[eax+0xc]
  57ef4a:	66 89 50 14          	mov    WORD PTR [eax+0x14],dx
  57ef4e:	3b ca                	cmp    ecx,edx
  57ef50:	74 0a                	je     0x57ef5c
  57ef52:	8b 17                	mov    edx,DWORD PTR [edi]
  57ef54:	89 11                	mov    DWORD PTR [ecx],edx
  57ef56:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  57ef59:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  57ef5c:	8b e5                	mov    esp,ebp
  57ef5e:	5d                   	pop    ebp
  57ef5f:	c3                   	ret
  57ef60:	8d 45 fc             	lea    eax,[ebp-0x4]
  57ef63:	50                   	push   eax
  57ef64:	8d 4d f0             	lea    ecx,[ebp-0x10]
  57ef67:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  57ef6a:	e8 3a 21 31 00       	call   0x8910a9
  57ef6f:	68 a8 57 c8 00       	push   0xc857a8
  57ef74:	8d 4d f0             	lea    ecx,[ebp-0x10]
  57ef77:	51                   	push   ecx
  57ef78:	c7 45 f0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x10],0xbd2ca4
  57ef7f:	e8 6c da 31 00       	call   0x89c9f0
  57ef84:	cc                   	int3
```
### KR VA `0x0057E850..0x0057E914`（原生指令）
```asm
0057e850 <.text+0x17d850>:
  57e850:	55                   	push   ebp
  57e851:	8b ec                	mov    ebp,esp
  57e853:	83 ec 08             	sub    esp,0x8
  57e856:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  57e859:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e85c:	53                   	push   ebx
  57e85d:	57                   	push   edi
  57e85e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  57e861:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  57e864:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e868:	b1 01                	mov    cl,0x1
  57e86a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e86d:	75 1f                	jne    0x57e88e
  57e86f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  57e872:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  57e875:	8b f8                	mov    edi,eax
  57e877:	0f 9c c1             	setl   cl
  57e87a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e87d:	84 c9                	test   cl,cl
  57e87f:	74 04                	je     0x57e885
  57e881:	8b 00                	mov    eax,DWORD PTR [eax]
  57e883:	eb 03                	jmp    0x57e888
  57e885:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  57e888:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e88c:	74 e4                	je     0x57e872
  57e88e:	8b df                	mov    ebx,edi
  57e890:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  57e893:	84 c9                	test   cl,cl
  57e895:	74 3a                	je     0x57e8d1
  57e897:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  57e89a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  57e89d:	3b 38                	cmp    edi,DWORD PTR [eax]
  57e89f:	75 22                	jne    0x57e8c3
  57e8a1:	52                   	push   edx
  57e8a2:	6a 01                	push   0x1
  57e8a4:	8d 55 0c             	lea    edx,[ebp+0xc]
  57e8a7:	8b c7                	mov    eax,edi
  57e8a9:	52                   	push   edx
  57e8aa:	8b f9                	mov    edi,ecx
  57e8ac:	e8 4f d4 ec ff       	call   0x44bd00
  57e8b1:	8b 00                	mov    eax,DWORD PTR [eax]
  57e8b3:	5f                   	pop    edi
  57e8b4:	89 06                	mov    DWORD PTR [esi],eax
  57e8b6:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8ba:	8b c6                	mov    eax,esi
  57e8bc:	5b                   	pop    ebx
  57e8bd:	8b e5                	mov    esp,ebp
  57e8bf:	5d                   	pop    ebp
  57e8c0:	c2 08 00             	ret    0x8
  57e8c3:	8d 45 fc             	lea    eax,[ebp-0x4]
  57e8c6:	e8 d5 0f fc ff       	call   0x53f8a0
  57e8cb:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  57e8ce:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e8d1:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  57e8d4:	52                   	push   edx
  57e8d5:	3b 4a 0c             	cmp    ecx,DWORD PTR [edx+0xc]
  57e8d8:	7d 24                	jge    0x57e8fe
  57e8da:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  57e8dd:	52                   	push   edx
  57e8de:	8d 45 0c             	lea    eax,[ebp+0xc]
  57e8e1:	50                   	push   eax
  57e8e2:	8b c7                	mov    eax,edi
  57e8e4:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  57e8e7:	e8 14 d4 ec ff       	call   0x44bd00
  57e8ec:	8b 08                	mov    ecx,DWORD PTR [eax]
  57e8ee:	5f                   	pop    edi
  57e8ef:	89 0e                	mov    DWORD PTR [esi],ecx
  57e8f1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8f5:	8b c6                	mov    eax,esi
  57e8f7:	5b                   	pop    ebx
  57e8f8:	8b e5                	mov    esp,ebp
  57e8fa:	5d                   	pop    ebp
  57e8fb:	c2 08 00             	ret    0x8
  57e8fe:	e8 09 29 31 00       	call   0x89120c
  57e903:	83 c4 04             	add    esp,0x4
  57e906:	5f                   	pop    edi
  57e907:	89 1e                	mov    DWORD PTR [esi],ebx
  57e909:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  57e90d:	8b c6                	mov    eax,esi
  57e90f:	5b                   	pop    ebx
  57e910:	8b e5                	mov    esp,ebp
  57e912:	5d                   	pop    ebp
  57e913:	c2               	ret    0x8
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