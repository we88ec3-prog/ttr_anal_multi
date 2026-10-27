# T16-13 — KR `0x008438C0` 整數鍵樹查找與 caller ABI

- 研究時間：20261028-020402 Asia/Taipei（本機 UTC 時間換算）
- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。
- 分支基準：本批開始時 GitHub `main` `69911d157697ede14e1507109b936620416048a8`，但提交前必須再核對。
- 證據策略：本批的機器碼來自當前唯讀 KR BIN 直接 objdump；無法取得原版 Lua/XML 正文或 TC BIN，業務語義不得假定。
- 原始檔沒有執行、附加或修改；只提交分析者個人目錄完整 Markdown，保留其他任務的 owner 與 catalog。

## 研究目標與前批結論校正
由 T16-9 `0x004AE888` 使用全域 `0x00FE18DC` 追入 `0x008438C0`。本段要證明 lookup 的 ABI、整數比較、節點／哨兵規則，而非宣稱這是 Quest DB。

## 原生指令與路徑證據
`0x008438C0..0x00843925` 完整方法尾端與 ret 4：

```asm
008438c0 <.text+0x4428c0>:
  8438c0:	55                   	push   ebp
  8438c1:	8b ec                	mov    ebp,esp
  8438c3:	51                   	push   ecx
  8438c4:	53                   	push   ebx
  8438c5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  8438c8:	56                   	push   esi
  8438c9:	8b f1                	mov    esi,ecx
  8438cb:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  8438ce:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  8438d1:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438d5:	75 1e                	jne    0x8438f5
  8438d7:	57                   	push   edi
  8438d8:	8b 3b                	mov    edi,DWORD PTR [ebx]
  8438da:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  8438e0:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  8438e3:	7d 05                	jge    0x8438ea
  8438e5:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  8438e8:	eb 04                	jmp    0x8438ee
  8438ea:	8b d1                	mov    edx,ecx
  8438ec:	8b 09                	mov    ecx,DWORD PTR [ecx]
  8438ee:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438f2:	74 ec                	je     0x8438e0
  8438f4:	5f                   	pop    edi
  8438f5:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  8438f8:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  8438fb:	3b d1                	cmp    edx,ecx
  8438fd:	74 16                	je     0x843915
  8438ff:	8b 33                	mov    esi,DWORD PTR [ebx]
  843901:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  843904:	7c 0f                	jl     0x843915
  843906:	8d 4d 08             	lea    ecx,[ebp+0x8]
  843909:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84390b:	5e                   	pop    esi
  84390c:	89 08                	mov    DWORD PTR [eax],ecx
  84390e:	5b                   	pop    ebx
  84390f:	8b e5                	mov    esp,ebp
  843911:	5d                   	pop    ebp
  843912:	c2 04 00             	ret    0x4
  843915:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  843918:	8d 4d fc             	lea    ecx,[ebp-0x4]
  84391b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84391d:	5e                   	pop    esi
  84391e:	89 08                	mov    DWORD PTR [eax],ecx
  843920:	5b                   	pop    ebx
  843921:	8b e5                	mov    esp,ebp
  843923:	5d                   	pop    ebp
  843924:	c2 04 00             	ret    0x4
```

`0x004AE87C..0x004AE8D0` lookup consumer：

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
  4ae8d0:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4ae8d4:	eb 41                	jmp    0x4ae917
```

## 直接可證實的欄位與分支
1. `this` 使用 ECX（`0x8438c9 mov esi,ecx`），`[this+4]` 是 head/sentinel 候選；`[head+4]` 作起始節點。
2. `0x8438d1 / 0x8438ee` 讀取 `[node+0x15]` 判斷節點特殊標記；`0x8438e0` 以 signed `jge` 比較 `[node+0x0C]` 和查找鍵 `edi=[key_ptr]`。
3. `0x8438e5` 選 `[node+8]`、`0x8438ec` 選 `[node]`，反覆下降至特殊節點；候選保存至 EDX。
4. `0x8438ff` 用查找鍵與候選 `[node+0x0C]` 再比較，`0x84390b / 0x84391e` 透過 EAX 所指輸出地址寫入候選或 sentinel，`ret 4` 消耗 stack key pointer。
5. 在 `0x004AE883` 入參中，`push edx` 指向本地 key；`ecx=0x00FE18DC`，`0x004AE896` 取輸出節點指標後與 `[0x00FE18E0]` 比較，證明缺失分支但不代表 quest unknown/ready。

## 局部偽碼（抽象）
```cpp
Node* integer_tree_lower_bound(Tree* self, int32_t* key) {
    Node* head = self->sentinel;
    Node* best = head;
    Node* p = head->parent;
    while (!p->special_flag_15) {
        if (p->key_0C < *key) p = p->right_08;
        else { best = p; p = p->left_00; }
    }
    if (best == head || *key > best->key_0C) return head;
    return best;
}
```
抽象 left/right 名稱根據比較及分支方向而來；不等於程式符號名稱，實際回傳走 hidden EAX 指標。

## 尚未閉合
- EAX 隱式輸出位置與呼叫約定需跨 caller 再檢查。
- `node+0x10` 的 payload ownership、key namespace、初始化來源 unknown。
- 只證明 client-side 整數索引，非任務旗標或伺服器 authoritative state。

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
T16-14 深入 `0x0053EBA0` 的 16-byte 記錄追加，確認該索引 consumer 將哪些數值複製到陣列。