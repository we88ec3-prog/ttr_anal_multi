# T16-16 — KR Quest/Tutorial 進度原生證據盤點與 T02 通知鏈阻塞

- 研究時間：20261028-020402 Asia/Taipei（本機 UTC 時間換算）
- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。
- 分支基準：本批開始時 GitHub `main` `69911d157697ede14e1507109b936620416048a8`，但提交前必須再核對。
- 證據策略：本批的機器碼來自當前唯讀 KR BIN 直接 objdump；無法取得原版 Lua/XML 正文或 TC BIN，業務語義不得假定。
- 原始檔沒有執行、附加或修改；只提交分析者個人目錄完整 Markdown，保留其他任務的 owner 與 catalog。

## 研究目標
在 T16-13～15 確立 client-side container 邊界後，整理真正缺失的任務更新、教學完成、第一主線與保存功能鏈。避免再次把通用容器操作誤標為 Quest Authority。

## 本批已形成的直接控制流（組合語言引用）
**教學腳本呼叫處**：
```asm
004a8b5d <.text+0xa7b5d>:
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4a8b79:	83 c4 0c             	add    esp,0xc
  4a8b7c:	8b               	mov    ecx,DWORD PTR [ebp-0xc]
```

**接收/顯示候選字串，不等於 server state writer**：
```asm
0050289a <.text+0x10189a>:
  50289a:	bf 0f 00 00 00       	mov    edi,0xf
  50289f:	68 b8 da c0 00       	push   0xc0dab8
  5028a4:	8d 47 fc             	lea    eax,[edi-0x4]
  5028a7:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  5028aa:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5028ad:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  5028b0:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  5028b4:	e8 57 8a f0 ff       	call   0x40b310
  5028b9:	89               	mov    DWORD PTR [ebp-0x4],esi
```

**索引 consumer 端**：
```asm
004ae87c <.text+0xad87c>:
  4ae87c:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  4ae87f:	8d 54 24 14          	lea    edx,[esp+0x14]
  4ae883:	52                   	push   edx
  4ae884:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae888:	b9 dc 18 fe 00       	mov    ecx,0xfe18dc
  4ae88d:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4ae891:	e8 2a 50 39 00       	call   0x8438c0
  4ae896:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
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

## 功能鏈矩陣：逐節點真實狀態
| 節點 | KR verified | 伺服器權威 | 重登恢復 | 必要補件 |
|---|---|---|---|---|
| existing role → tutorial entry | 有 `Tutorial_EntryPoint` 呼叫；選擇條件仍 unknown | unknown | unknown | T03/T04 真正欄位 + 原版 Lua |
| Lua tutorial script → first step | script file name and invocation only | unknown | unknown | `Event/TutorialMain.lua` 原始內容 |
| quest definition → accepted | parser strings、索引建立模式；未證實 task schema | unknown | unknown | `Table/QuestInfo.xml` + 伺服器封包 |
| objective update → UI | 僅 `QUEST_READY` UI 類字串 | unknown | unknown | T02 已核對 handler/payload + native quest business callback |
| tutorial completion → mainline first NPC | 無原生閉環 | unknown | unknown | 文字、XML、NPC/script and state write |
| saved quest snapshot → resume | 無 T16-side writer 的證據 | unknown | unknown | T15 interface + packet fields |
| TC equivalents | 只有 targets manifest，無實際 BIN | unknown | unknown | 版本一致 TC 原始資源 |

## 與 T02 的接續規則
已知專案有 T02 封包框架與歷史 `QUEST-STATE-NOTIFICATIONS` 研究；本段**沒有從原版封包直接確認 quest business opcode**。不得把舊 fixture 的 `005F type6` 直接認定教學；`HANDOFF.md` 已明確更正。下段必須：
1. 從 T02 已確認的 dispatcher 找到 quest candidate 的 handler 路徑與原生 bytes；
2. 查寫入欄位、顯示消費者、重登快照；
3. 取得原版資源正文以對應 node IDs；
4. 在有證據之前所有 QuestID／StepID／NPC ID/StateWriter 值維持 `unknown`。

## 雙版本差異欄位
| Key | KR | TC |
|---|---|---|
| image hash | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 已直接驗證 | `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873` 只由 targets.json 記錄 |
| Lua entry | `Tutorial_EntryPoint` 已在 KR 機器碼驗證 | unknown |
| Quest table | 檔名引用確認，未取得正文 | unknown |
| first mainline ID | unknown | unknown |
| authoritative flags | unknown | unknown |

## 結論與下一段優先
本批可成立的結論是「`0xFE18DC` 為 client-side 整數鍵查找、查表結果轉換為 16-byte 記錄」，而不是已找到玩家任務進度引擎。**T16-17 優先尋找與原生 quest packet business handler 真正關聯的 state writer，避免第三輪泛用容器深挖。**

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

## Commit/驗收
分析採唯讀方式，無遊戲執行測試；GitHub 提交狀態將於實際提交及遠端讀回後另報告，不預填成功。