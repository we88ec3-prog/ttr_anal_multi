# T10-48 — 輸入→狀態→命令→動作的閉合邊界及下一輪精準追查

- 產生時間：2026-10-28T01:40:26+08:00（Asia/Taipei）
- BIN：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE：`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- BIN PE `.text` 解碼採 VA = `0x401000 + (file_offset - 0x400)`；以下 raw offset = VA − 0x401000 + 0x400，僅適用 `.text`。
- 只做唯讀靜態分析；沒有啟動／附加／修改遊戲，也沒有把 AI fixture 視為原生結論。
- T10-45 後續連號；REBASE-01/02 不佔正式段號；過去筆記的主張須與 T01 限定整合及 BIN 直接核對分開。

## 本段原生核對與限定結論

### 多條已驗證的**局部**路徑與未閉合接點
A. `0x6D4DC0` 可依兩域容器蒐集 key mapping DWORD → `0x594610` 按條件再查鄰近 mapping → `0x594A80`/`0x594570` 做輸出格式轉換。此路徑缺「設定／資源載入 writer」及「實時動作 reader」。

B. `0x6D4CE0` 以特殊域樹的 byte 或一般域 `0xFB9004 + index` 的 byte 回傳 key-state；`0x6D4A30` 可清後者的前 40 bytes。此路徑缺真正的非零事件 writer、觸發 frame/frequency、index→action mapping。

C. 前一輪證據指出 `0x546780` 會將 `0x547240` 的狀態值轉成 `0x0008/0x0080/0x0040` bit，並與 `0x546850/0x546B50/0x546D50` 合流；`0x548918` 有 28..37 phase index 相關 `0x68` command 產出。**本段仍未證明 B 的 key-state reader 必然流入 C 或 B/C 與 Z/V 的對應。**

D. 角色動畫動作啟動、motion completion、next-action queue／取消及 tier 真正 writer，目前沒有從上述特定資料流得到跨函式的同一 instance、同一 frame 的正向連結。故不推論連段窗口、蓄氣秒數、優先權、取消時間。

### 與 T01 限定整合的相容性
- `timeGetTime` 嚴格 `>500 ms` 只能稱有條件狀態機，非 Z combo window。
- command index `28..37` 只表述索引域，非十段普通攻擊。
- 三路 OR 與 byte 選擇有不同合成策略。
- SubAI 計數 >60 不代表玩家 V 的實時持續秒數；SubAI candidate 7/9 不是已證 tier。
- `FB9004` 被清零不是非零按鍵 phase writer，phase1/3 不逕自稱 keydown/keyup。

### 下一輪可直接實施的位址導向研究
1. 按鍵非零 phase writer：以 `0x6D4CE0` 的 direct caller、`0xFB9004` 的常數與指標引用交叉核實 `store` 指令，區分直接／間接 writer。
2. 來源鍵位載入：`0x6D4DC0` 所引用 `0xFB8834/0xFDF3F4` 的填充路徑與配置物件型別，檢查 XML action 名與實際值域。
3. 動作下游：以 `0x548918` `0x68` 命令的 consumer 與 actor receiver provenance 追 motion／queue，跨 T11 只引用其主責。
4. 舉證完成條件：每條有效連接至少需要 BIN assembly caller+callee、傳遞寄存器／stack 位址、同一實例/結構證據，並與來源SHA及同一 target version 對應。


## 目標位址與原始 PE bytes 證據

### VA `0x00546780` / raw `0x00145B80` / window `528` bytes

[code block separately checked in preflight]

### VA `0x00548918` / raw `0x00147D18` / window `341` bytes

[code block separately checked in preflight]

### VA `0x006D4CE0` / raw `0x002D40E0` / window `213` bytes

[code block separately checked in preflight]

### VA `0x00594610` / raw `0x00193A10` / window `384` bytes

[code block separately checked in preflight]

## Direct E8 relative call 候選（機械搜尋，不等同完整 CFG）

- `0x00546780`：1 個候選指令位址：`0x00546263`

- `0x00548918`：0 個候選指令位址：無 E8 direct hit

- `0x006D4CE0`：2 個候選指令位址：`0x0059624E`, `0x0059643F`

- `0x00594610`：9 個候選指令位址：`0x005CD91F`, `0x005D1B75`, `0x005D2DD5`, `0x005D4045`, `0x0060E06B`, `0x00651122`, `0x0065117E`, `0x006511DA`, `0x0065120A`

## 記錄品質／驗收界線
- 本段第一手原始 bytes 是上述每段 BIN window，由 GNU objdump i386 解析；窗口起點選自既有函式入口，遇內部跳轉目標超出窗口時需另定位反組譯，不能把未列入的分支稱不存在。
- E8 搜尋依 direct rel32 靜態匹配（可能偽陽性），只屬候選來源，不包含 indirect/vtable/tailcall。
- PE raw vs flat 位址混淆應每次由原始 PE section header 檢查，絕不把本報告的局部核對推廣為整個反編譯索引皆正確。
- 本段不宣稱 Z/X/C/V 特定綁定、V 蓄氣、Z held 自動續段、queue/cancel 已閉合；亦不新增動作／伺服器規則或修改程式。
- GitHub 送交狀態以實際遠端 Commit+讀回為準；本檔在本機完成不等於已提交。