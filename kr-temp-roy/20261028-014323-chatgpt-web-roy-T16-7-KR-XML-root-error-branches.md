# T16-7 — KR QuestInfo/QuestTalk 根節點與失敗分支補證

- 執行時間（Asia/Taipei）：20261028-014323
- 任務：T16 Quest & Story Progression，版本 KR（TC 本輪僅索引，不做異版推定）
- 第一手映像：Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，以唯讀靜態 objdump 驗證
- VA 對映：KR PE `.text` 0x401000 ↔ raw 0x400；`.rdata` 0xBD2000 ↔ raw 0x7D0600
- 工作基準：GitHub main `e1591500bef6f35acff736615109e1010264dc75`（提交前再次核對）；已有 T16-1～T16-4 研究
- 研究範圍：已存在角色的任務／教學；不重做 T03/T04/T07/T14/T15/T02；未執行遊戲、未修改客戶端或原始證據
- 分級：`native-confirmed` = 指令／常數；`native-partial` = 行為語義局部；`hypothesis` = 未完成 caller/consumer；`missing` = 沒有原版來源。

## 本段研究問題與結論
## 原生 XML parser 後續的限定追查
`QuestInfo` 資料載入函式 `0x00504740`、`QuestTalk` `0x00505570` 都使用 `0x0072EE30` → `0x0072F110`，其後從 XML 文檔字串找一個「預期 root」鍵。下面以直接读取 KR .rdata bytes 補明根名稱，不能推出 XML 實際內容：
- `0x00C0DB48` = `Table/QuestInfo.xml`；xref `0x50478c`
- `0x00C0DB5C` = `Table/QuestTalk.xml`；xref `0x5055b9`
- `0x00C0DB70` = `QuestInfo`；xref `0x504832`
- `0x00C0DB7C` = `Äù½ºÆ® Á¤º¸ ÆÄÀÏ ¼Õ»ó`；xref `0x504847`
- `0x00C0DC44` = `QuestTalk`；xref `0x505642`
- `0x00C0DC50` = `Äù½ºÆ® ´ëÈ­ ÆÄÀÏ ¼Õ»ó`；xref `0x505654`

**獨立早期失敗分支**：`0x005047D3 je 0x00504831`；若檢查未過，函式釋放暫存並 `xor eax,eax` 跳到 `0x005054D8`；QuestTalk 的 `0x005055F0 je 0x00505641` 與 `0x0050563A xor eax,eax` 類似。這裡只可稱「資源開啟／內容檢驗相關分支」，不能說明具體 XML bytes 與 quest IDs。

**取材缺口**：本次上傳的是 BIN 與 EXE，而不是實際 `QuestInfo.xml` / `QuestTalk.xml`；若沒有原始 XML，無法枚舉主線 ID 或 NPC key。不得從其名稱與歷史 fixture 直接填值。

## 預備後續資源 schema 問題清單
- root child schema 的 key 是何種字串？是否支援多語版？須以原版 XML 和 parser 實證。
- QuestInfo 和 QuestTalk 是同一 ID namespace 嗎？`unknown`。
- QuestTalk 的對話選項是否由 server 來過濾？`unknown`。
- `0x53FD76` 解析器是否消費其中某個 XML？`unknown`，仍無直接 caller argument 連線。

### KR VA `0x005047BE..0x0050486C`（原生指令）
```asm
005047be <.text+0x1037be>:
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  504850:	c7 84 24 64 02 00 00 	mov    DWORD PTR [esp+0x264],0xffffffff
  504857:	ff ff ff ff 
  50485b:	83 c4 04             	add    esp,0x4
  50485e:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  504865:	94 23 bf 00 
  504869:	39 9c 24     	cmp    DWORD PTR [esp+0x18c],ebx
```
### KR VA `0x005055E2..0x0050567A`（原生指令）
```asm
005055e2 <.text+0x1045e2>:
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  505631:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  505635:	e8 06 8a 22 00       	call   0x72e040
  50563a:	33 c0                	xor    eax,eax
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  505641:	68 44 dc c0 00       	push   0xc0dc44
  505646:	8d 44 24 28          	lea    eax,[esp+0x28]
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50 dc c0 00       	push   0xc0dc50
  505658:	e8 03 85 1e 00       	call   0x6edb60
  50565d:	c7 84 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],0xffffffff
  505664:	ff ff ff ff 
  505668:	83 c4 04             	add    esp,0x4
  50566b:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505672:	00 
  505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
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