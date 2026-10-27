# T16-3 — KR Tutorial/Synopsis 上游呼叫者、全域分支與腳本入口

- 日期：2026-10-28 Asia/Taipei；工作批次 `20261028-013531`
- 研究者：`chatgpt-web roy`；版本 KR；任務：T16 任務與劇情流程
- 第一手映像：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪直接核對）
- PE32 x86：`.text` VA `0x401000` → raw `0x400`；`.rdata` VA `0xBD2000` → raw `0x7D0600`。全部位址僅對 KR 適用。
- GitHub 啟動基準 HEAD `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；每次提交前再次核對。
- 分工：只記錄 T16 任務／教學接口，不改 T02/T03/T04/T07/T08/T14/T15 的主責。原檔未執行、未修改，靜態解析而非動態驗收。
- 證據定性：**原生已確認**指原映像的機器碼 bytes／靜態分支；**部分確認**指用途待上游或動態條件補證；**合理推測**不得當作官方行為；**未知**不以 fixture 補猜。

## 研究摘要

沿 T16-2 已驗證的 `0x4A89C0`（Synopsis 名稱分派）及 `0x4A8A60`（Tutorial 名稱分派）做整個 `.text` 範圍的 E8-relative 直接 call 交叉參照掃描。新增 **Synopsis 兩個靜態呼叫位址** `0x47BACE`、`0x4C1FFC`，**Tutorial 一個** `0x4C4D3F`；另定位 `0x4A8B90` 的三個直接呼叫位址。這些是控制圖，不代表所有間接呼叫或虛表呼叫都已尋獲。

## 原生證據 A：上游靜態 caller

| 調用點 | 指令目標 | 實參準備 | 判定 |
|---|---|---|---|
| `0x0047BACE` | `0x004A89C0` | `mov esi,0xFC0F84` | native direct E8 |
| `0x004C1FFC` | `0x004A89C0` | `mov esi,0xFC0F84` | native direct E8 |
| `0x004C4D3F` | `0x004A8A60` | `mov esi,0xFC0F84` | native direct E8 |
| `0x0047CA45` | `0x004A8B90` | `push 0xFC0F84` | native direct E8 |
| `0x004C19AE` | `0x004A8B90` | 待補 caller 局部狀態 | native direct E8 |
| `0x004C4E8A` | `0x004A8B90` | `push 0xFC0F84` | native direct E8 |

`0xFC0F84` 是共用的被傳入物件／記憶體位址 **候選**，其靜態數值可確認，物件角色不可單靠位址命名。

### 精確 caller snippets（objdump 直接讀 BIN）

```asm
  47bac5:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47bac9:	be 84 0f fc 00       	mov    esi,0xfc0f84
  47bace:	e8 ed ce 02 00       	call   0x4a89c0
  47bad3:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47bad7:	85 ff                	test   edi,edi
  4c1ff3:	88 5c 24 28          	mov    BYTE PTR [esp+0x28],bl
  4c1ff7:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c1ffc:	e8 bf 69 fe ff       	call   0x4a89c0
  4c2001:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4c2008:	ff 
  4c4d36:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4d3a:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d44:	33 c0                	xor    eax,eax
  4c4d46:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
```

## 原生證據 B：Tutorial 入口附近的早期條件

`0x4A8A60` 內有多組初始化／全域值檢查，不能直接解釋成「帳號是否已完成教學」。確定存在：`[0xFAadec]` 與常數 15 比較；不相等寫 `0xFAadf0=15`，相等走 `0x58A9A0`；`[0xFBA798]` 非零跳過虛擬方法呼叫，為零時呼叫 `[vptr+0x10]`，但 **兩個分支最後均載入 TutorialMain.lua 與呼叫 Tutorial_EntryPoint**。這一點排除「`0xFBA798 !=0` 直接跳過整個 Tutorial 入口」的草率推論。

```asm
  4a8aff:	b8 0f 00 00 00       	mov    eax,0xf
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b20:	09 1d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,ebx
  4a8b26:	68 10 cf bc 00       	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b30:	83 c4 04             	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00       	mov    eax,0xc
  4a8b3f:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee             	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                	push   0x6
  4a8b55:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8b58:	50                   	push   eax
  4a8b59:	6a 00                	push   0x0
  4a8b5b:	ff d2                	call   edx
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4a8b79:	83 c4 0c             	add    esp,0xc
```

### 控制流程（已驗證範圍）

```text
call 0x4A8A60
 ├─ 初始化及全域值條件（語義 unknown）
 ├─ [0xFAadec] == 15 ? call 0x58A9A0 : [0xFAadf0] = 15
 ├─ [0xFBA798] == 0 ? call virtual [vptr+0x10] with local record : skip virtual call
 └─ both arms → load TutorialMain.lua → invoke Tutorial_EntryPoint

call 0x4A89C0
 ├─ global init / [0xFB73B4] = 1
 └─ load TutorialMain.lua → invoke Synopsis_EntryPoint
```

局部偽碼（不宣稱型別／業務意義）：

```cpp
void tutorial_path_candidate(void* context) {
    init_unknown_globals();
    if (global_FAadec != 15) global_FAadf0 = 15; else helper_58A9A0();
    if (global_FBA798 == 0) dispatch_virtual_plus_10(local_record);
    load_lua(context, "Event/TutorialMain.lua");
    call_named_lua(context, "Tutorial_EntryPoint");
}
```

## 教學節點矩陣增量

| 節點 | 前置 | 客戶端觀察 | 伺服器權威 | writer | 通知／UI | 下一步與重登 | 證據 |
|---|---|---|---|---|---|---|---|
| synopsis-entry | unknown | 2 direct caller → `0x4A89C0` | unknown | `[0xFB73B4]` 寫入 1，語義 unknown | unknown | unknown | native call + global write |
| tutorial-entry | unknown | 1 direct caller → `0x4A8A60` | unknown | `[0xFAadf0]` 條件寫入 15，語義 unknown | unknown | unknown | native branch |
| tutorial-virtual-event | `[0xFBA798]==0`（僅 native 分支條件） | vptr+0x10 with locally built record | unknown | unknown | unknown | still invokes Tutorial entry | native control flow |
| actual-tutorial-step-1 | unknown | Lua content unavailable | unknown | unknown | unknown | unknown | information missing |

## 證據界線／反證

1. 不將全域位址寫入視為角色任務完成旗標，未追到保存/回復。
2. `0x4A8B90` 是額外上下游路徑，已觀測其透過腳本值解析與 `[argument+0x34]` 輸出 0/1，但未確認屬於 quest 教學進度，故僅列候選。
3. 靜態 direct-E8 掃描不包含 indirect call、函式指標；「兩個 caller」是已見直接呼叫數，不是全部可能的入口。
4. 缺 `TutorialMain.lua` 檔案實際內容、伺服器封包與 KR 動態事件，不可列出虛構步驟。

## TC 對照、cross-task、acceptance

TC 原生 BIN（repo 目標 SHA `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`）不在本機，所有 TC entry、state、task ID **unknown**。T03 提供已登入角色；T04 只提供已建立角色；T02/T07/T14/T15 各自維持封包、關卡、結算、持久化實作主責。可驗收：KR 直接呼叫路徑和上述分支；不可驗收：玩家何時看見教學、誰授權完成、重登續接。

## 下一段 T16-4

轉向 QuestInfo / QuestTalk XML loader 對照與 `HasQuest` 等解析器的 schema origin；若無資源，追原生 loader caller、錯誤分支及未解資料域。不因 lack of scripts 用歷史 fixture 補猜。