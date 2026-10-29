# T10-46 — 一般索引鍵狀態讀取、清零與雙來源的分離

- 產生時間：2026-10-28T01:40:26+08:00（Asia/Taipei）
- BIN：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE：`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- BIN PE `.text` 解碼採 VA = `0x401000 + (file_offset - 0x400)`；以下 raw offset = VA − 0x401000 + 0x400，僅適用 `.text`。
- 只做唯讀靜態分析；沒有啟動／附加／修改遊戲，也沒有把 AI fixture 視為原生結論。
- T10-45 後續連號；REBASE-01/02 不佔正式段號；過去筆記的主張須與 T01 限定整合及 BIN 直接核對分開。

## 本段原生核對與限定結論

### 已確認資料流
- `0x6D4CE0` 入口的 key 值在 ESI；先用 `key-0x2711` 與 `0x270E` 無號比較。進入特殊域時，呼叫 `0x82EF00` 以 `0xFDF630` 管理樹讀取，命中時讀節點 `+0x10` 單位 byte；非特殊域僅在 `key<=0x27` 時讀取 `BYTE PTR [0xFB9004+key]`，其餘落至零回傳。此處是 **reader** 而非 writer。
- `0x6D4A30` 在有條件的分支中直接連續清 `0xFB9004...0xFB9028` 十個 DWORD，共 40 bytes，不能把它稱作每一鍵之非零事件 writer。清零分支與一次性初始化旗標、容器建構有關，未從此判定每幀頻率。
- `0x6D4DC0` 是另外一個映射集合查詢，對特殊域與一般域查不同容器，結果附加至呼叫者提供的 vector；不能將 `0x6D4CE0` 單 byte state 與 `0x6D4DC0` 的 DWORD 映射元素當同一型別。
### 反證與缺口
- 沒有觀測任何對 `0xFB9004+key` 寫入非零 byte 的完整可達路徑；缺少 direct xref 不能證明不存在間接 pointer writer。
- 尚未證實一般域 key index 與 Z/X/C/V 的 XML action row、VK、組合輸入的對應。
- `0x2711...` 特殊鍵域的語意未命名；容器樹 `+0x10` 是被讀取者，不足以命名 keyboard phase。
### 後續可接續的追查
1. 在 `0x6D4CE0` xrefs 中辨識傳入 ESI 的來源；追該來源是否是 XML 加載的 action row 或掃描碼。
2. 用 address-literal + pointer-indexed xrefs 分離直接和間接對 `0xFB9004` 的 write；對命中者原始 BIN 核對其非零來源。
3. 對 `0xFDF630` 建構與節點 `+0x10` 寫入者做實例限定。


## 目標位址與原始 PE bytes 證據

### VA `0x006D4CE0` / raw `0x002D40E0` / window `213` bytes

[code block separately checked in preflight]

### VA `0x006D4A30` / raw `0x002D3E30` / window `224` bytes

[code block separately checked in preflight]

### VA `0x006D4DC0` / raw `0x002D41C0` / window `352` bytes

[code block separately checked in preflight]

## Direct E8 relative call 候選（機械搜尋，不等同完整 CFG）

- `0x006D4CE0`：2 個候選指令位址：`0x0059624E`, `0x0059643F`

- `0x006D4A30`：2 個候選指令位址：`0x00490DFC`, `0x0058A607`

- `0x006D4DC0`：29 個候選指令位址：`0x00594672`, `0x005946CB`, `0x0059471B`, `0x005947FD`, `0x0059484D`, `0x0059492F`, `0x0059497F`, `0x00594CD4`, `0x00594DC4`, `0x00594EB4`, `0x00594FA4`, `0x00595094`, `0x00595184`, `0x00595274`, `0x00595364`, `0x00595454`, `0x00595544`, `0x00595634`, `0x00595724`, `0x00595814`, `0x00595901`, `0x005959F4`, `0x005CD68A`, `0x005CE5BA`, `0x0062B5BA`, `0x00650E96`, `0x00650F48`, `0x00650FF6`, `0x006510A4`

## 記錄品質／驗收界線
- 本段第一手原始 bytes 是上述每段 BIN window，由 GNU objdump i386 解析；窗口起點選自既有函式入口，遇內部跳轉目標超出窗口時需另定位反組譯，不能把未列入的分支稱不存在。
- E8 搜尋依 direct rel32 靜態匹配（可能偽陽性），只屬候選來源，不包含 indirect/vtable/tailcall。
- PE raw vs flat 位址混淆應每次由原始 PE section header 檢查，絕不把本報告的局部核對推廣為整個反編譯索引皆正確。
- 本段不宣稱 Z/X/C/V 特定綁定、V 蓄氣、Z held 自動續段、queue/cancel 已閉合；亦不新增動作／伺服器規則或修改程式。
- GitHub 送交狀態以實際遠端 Commit+讀回為準；本檔在本機完成不等於已提交。