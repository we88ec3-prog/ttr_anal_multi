# T10-073 — keymapping vector growth

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

`0x6D6240` 會以 DWORD 元素大小 `>>2` 計算容量與長度、檢查最大值 `0x3FFFFFFF`，並以 `capacity + capacity/2` 或需求數量調整容量。這支持它是映射 vector 容量管理 helper；實際配置由 `0x797980` 下游完成。

## 可複核第一手機器碼

### VA `0x006D6240–0x006D629F`（raw `0x2D5640–0x2D569F`）

```asm
; PE .text raw window bytes: 56 8b f0 8b 16 8b 46 04 57 2b c2 bf ff ff ff 3f c1 f8 02 2b f9 3b f8 73 0a 68 78 23 bf 00 e8 cd 78 1a 00 03 c1 8b 4e 08 2b ca c1 f9 02 3b c1 76 2c 8b d1 d1 ea bf ff ff ff 3f 2b fa 3b f9 73 10 33 c9 3b c8 0f 42 c8 51 e8 f3 16 0c 00 5f 5e c3 03 ca 3b c8 0f 42 c8 51 e8 e3 16 0c 00 5f 5e c3
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d6240:	56                   	push   esi
  6d6241:	8b f0                	mov    esi,eax
  6d6243:	8b 16                	mov    edx,DWORD PTR [esi]
  6d6245:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d6248:	57                   	push   edi
  6d6249:	2b c2                	sub    eax,edx
  6d624b:	bf ff ff ff 3f       	mov    edi,0x3fffffff
  6d6250:	c1 f8 02             	sar    eax,0x2
  6d6253:	2b f9                	sub    edi,ecx
  6d6255:	3b f8                	cmp    edi,eax
  6d6257:	73 0a                	jae    0x6d6263
  6d6259:	68 78 23 bf 00       	push   0xbf2378
  6d625e:	e8 cd 78 1a 00       	call   0x87db30
  6d6263:	03 c1                	add    eax,ecx
  6d6265:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6d6268:	2b ca                	sub    ecx,edx
  6d626a:	c1 f9 02             	sar    ecx,0x2
  6d626d:	3b c1                	cmp    eax,ecx
  6d626f:	76 2c                	jbe    0x6d629d
  6d6271:	8b d1                	mov    edx,ecx
  6d6273:	d1 ea                	shr    edx,1
  6d6275:	bf ff ff ff 3f       	mov    edi,0x3fffffff
  6d627a:	2b fa                	sub    edi,edx
  6d627c:	3b f9                	cmp    edi,ecx
  6d627e:	73 10                	jae    0x6d6290
  6d6280:	33 c9                	xor    ecx,ecx
  6d6282:	3b c8                	cmp    ecx,eax
  6d6284:	0f 42 c8             	cmovb  ecx,eax
  6d6287:	51                   	push   ecx
  6d6288:	e8 f3 16 0c 00       	call   0x797980
  6d628d:	5f                   	pop    edi
  6d628e:	5e                   	pop    esi
  6d628f:	c3                   	ret
  6d6290:	03 ca                	add    ecx,edx
  6d6292:	3b c8                	cmp    ecx,eax
  6d6294:	0f 42 c8             	cmovb  ecx,eax
  6d6297:	51                   	push   ecx
  6d6298:	e8 e3 16 0c 00       	call   0x797980
  6d629d:	5f                   	pop    edi
  6d629e:	5e                   	pop    esi
  6d629f:	c3                   	ret
```

## 資料流／分支推導

1. 計算 `(end-begin)>>2` 與 `(capacity-begin)>>2`，最大元素數 `0x3FFFFFFF`，超額走 `0x87DB30`。
2. `shr edx,1` 是配置擴容策略的 1/2，不是玩家長按閾值。
3. 本段僅對 `0x6D6240` 在映射 vector caller 的接收者作解釋，不推為所有 vector 實例相同語義。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
size_t need = currentElements + appended;
if (need > capacityElements)
  grow(max(need, capacityElements + capacityElements/2));
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：`0x797980` 實際重配置、舊資料複製與例外路徑未逐指令驗證。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。