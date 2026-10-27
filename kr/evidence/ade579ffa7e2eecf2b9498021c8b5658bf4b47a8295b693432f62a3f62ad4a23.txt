# T08-126 — 全域桶15個 direct xref 完整分類與固定桶10證據

研究者：chatgpt-web roy｜2026-10-27 Asia/Taipei。來源：本機 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪使用 sha256sum 重新計算一致）；機器碼由已存在 `t08_current_disasm.txt` 及原始 PE 的 x86 objdump 核對。GitHub 已完成 T08-124；本輪研究自125接續。

**證據約定**：已確認＝BIN 可重現；推測＝語義未獲符號/實際呼叫驗證；未知＝仍無直接證據。相同欄位偏移不可跨 C++ 物件型別混用。這是按研究主題完整保留的分段原稿，不將負向搜尋冒充不存在證明。

## 搜尋方法、範圍
從 SHA 已驗證的 `Tartaros.bin` 對 32-bit little-endian immediate `0x00FB7740` 掃描，得到15處機器碼/資料位元組匹配；逐一在 objdump .text 映射下核實為指令 operand。這是**直接絕對位址引用普查**，不包括任何經參數、相鄰欄位、heap pointer alias 的間接引用。

| VA | 類別 | 主要證據 |
|---|---|---|
| 0x00798F78 | 初始化 | mov [0xFB7740],eax |
| 0x007995A6 | 釋放讀取 | mov eax,[0xFB7740] |
| 0x007995BA | 釋放置零 | mov [0xFB7740],edi |
| 0x0079CDA8 | producer | vtable+4 bucket index，+0x2000 count |
| 0x007BED5B | producer | 同上 |
| 0x007CD7C9 | producer | 同上 |
| 0x007D34EB | producer | 動態桶號／物件條件 |
| 0x007D357A | producer | 另一條物件條件路徑 |
| 0x007DC369 | producer | vtable+4 桶號 |
| 0x007DF5A7 | producer | vtable+4 桶號 |
| 0x007E6A52 | producer | vtable+4 桶號 |
| 0x007F24AE | producer | +0x84 子物件取值 |
| 0x007F96ED | producer | vtable+4 桶號 |
| 0x007FEC92 | producer | vtable+4 桶號 |
| 0x007FECE9 | producer | 固定第10桶追加 |

## BIN 核心摘錄
```asm
0079CDA8 mov edi,ds:0xfb7740
0079CDB0 call edx
0079CDB2 imul eax,eax,0x2004
0079CDB8 mov ecx,[eax+edi+0x2000]
0079CDC1 cmp ecx,0x800
0079CDC9 mov [eax+ecx*4],esi
0079CDCC inc dword ptr [eax+0x2000]

007F24AE mov edi,ds:0xfb7740
007F24B4 add esi,0x84
007F24BC call edx
007F24BE imul eax,eax,0x2004
007F24C4 mov ecx,[eax+edi+0x2000]
007F24CD cmp ecx,0x800
007F24D5 mov [eax+ecx*4],esi
007F24D8 inc dword ptr [eax+0x2000]

007FECE9 mov edx,ds:0xfb7740
007FECEF mov ecx,[edx+0x16028]
007FECF5 cmp ecx,0x800
007FECFD mov [edx+ecx*4+0x14028],esi
007FED04 inc dword ptr [edx+0x16028]
```

## 固定第10桶的算式
`10 × 0x2004 = 0x14028`；第10桶 count 置於 `0x14028+0x2000=0x16028`。原始 `0x007FECE9` 是有條件進入的固定桶10 enqueue；不能當成 consumer 或每幀清零。

## 偽碼與資料流
```cpp
auto* globalBuckets = *(Bucket**)0x00FB7740; // heap pointer
Bucket& b = globalBuckets[obj->virtual04()]; // no verified bounds check on index
if (b.count < 2048) b.entries[b.count++] = obj;
// special case index 10: same capacity guard
```
配置 `0x2C058=22×0x2004`，每個 entries 有2048個 pointer，count 4 bytes。未看到所有 producer 會做索引合法性檢查，故不可臆測 index 0～21 已全面保證。

## 證據限制
本輪 15 direct uses 分類為生命週期與 producer，**沒有找到直接使用全域立即位址的逐筆 consumer**；這不能證明不存在 alias consumer。參數地址 `0x00FB76A8+0x98=0x00FB7740` 使 `0x0079A3C0` 實際屬全域 producer（T08-107）；也證明僅以 direct xrefs 不能完整查找所有用戶。

**T08-127** 針對 `0x007D1310` 更晚的 bucket stages + 清零行為延伸，判斷它能否被提升為全域 consumer。