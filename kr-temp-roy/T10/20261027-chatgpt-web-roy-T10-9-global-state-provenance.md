# KR T10-9 — FB9014 來源邊界與正常事件 writer 缺口

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 研究問題與方法
沿 T10-8 提出的 `0xFB9014` 寫入者問題，從原始 BIN 掃描四位元組 little-endian 位址的所有精確出現位置，再對涉及位置逐址反組譯。這種搜尋只能保證**直接使用完整絕對位址**的引用；無法涵蓋基底指標 + offset、別名、表格、DLL 或非靜態構造地址。

## 新證據
精確模式 `14 90 FB 00` 在本 BIN 出現 5 次：raw `0x146693`（指令 VA `0x547290`）、`0x2CFC8A`（`0x6D088A`）、`0x2D0F17`（`0x6D1B17`）、`0x2D3EB1`（`0x6D4AB1`）、`0x2D3F80`（`0x6D4B80`）；VA 對應是按 `.text` raw/VA 映射推算的包含常數所在指令地址（注意 raw 所指的是指令內 immediate，故這裡實際操作碼起始 VA 可能早數位元組）。

兩個已核對的寫入者是 `0x6D4AB0` 與 `0x6D4B7F`，均將 EAX 清為 0 後直接 `mov ds:[0xFB9014],eax`。其他位置目前與既有初始化及狀態讀取路徑相符，不構成正常按鍵按下／放開的 writer 證明。

### 原始 BIN 節錄：多欄位批次清零
```asm
6d4a93:	33 c0                	xor    eax,eax
  6d4a95:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4a9c:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4aa1:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4aa6:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4aab:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4ab0:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4ab5:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4aba:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4abf:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4ac4:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4ac9:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
```

### 原始 BIN 節錄：第二個批次清零
```asm
6d4b69:	33 c0                	xor    eax,eax
  6d4b6b:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4b70:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4b75:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4b7a:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4b7f:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4b84:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4b89:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4b8e:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4b93:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4b98:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
```

### 原始 BIN 節錄：相位機取樣
```asm
54728e:	8b 0e                	mov    ecx,DWORD PTR [esi]
  547290:	0f b6 05 14 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9014
  547297:	83 f9 03             	cmp    ecx,0x3
  54729a:	0f 87 be 00 00 00    	ja     0x54735e
  5472a0:	ff 24 8d 70 73 54 00 	jmp    DWORD PTR [ecx*4+0x547370]
```

## 可確認之資料流
`0x6D4A93/0x6D4B69` 清零 `[0xFB9004..0xFB9028]` → `0x547290` 讀 `BYTE [0xFB9014]` → `0x547240` 相位機更新其獨立 `esi` state/timestamp → caller `0x546780` 根據返回碼組裝 mask。**不成立的推論**：清零函式就是 Z keyup handler；或掃描不到 writer 就代表沒有 writer。這一段沒有找出正常運作下把 1/2/3 寫進 `FB9014` 的程式碼。

## 暫定 C++ 草圖
```cpp
void resetInputGlobalBlock() {
  for (int i=0; i<10; ++i) global_dword_FB9004[i] = 0; // 此處兩個已觀察清零路徑
}
unsigned samplePhase(PhaseState* st) {
  auto physicalOrMapped = *(uint8_t*)0xFB9014; // 真正 writer 未確認
  return phaseTransition(st, physicalOrMapped);
}
```

## 未解 / 下一段
- 必須追 `0xFB9004` 基底或指標的**間接寫入**，不能靠單一地址匹配排除 key events。
- 需由輸入資料管理器上游解析 key->action，且讀取該版本的 `Table/KeyMapping.xml`。
- `Z` 是使用者操作，並未在本證據被定位成某個 Bank row 或 `0xFB9014`。
- T10-10 追查其他路徑，先將方向合成與戰鬥 action 分離。