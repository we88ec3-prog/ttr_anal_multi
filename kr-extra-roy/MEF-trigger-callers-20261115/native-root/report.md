# MEF 觸發來源：MapList 根別名與具體名稱 consumer

## 本輪答案與證據等級

**本支線尚未找到把 `MapList.TRIGGER` 名稱交給 `.mef` 檔案 loader／parser／executor 的新 caller。** 本輪實際追到一條先前未列入根別名盤點的「名稱被使用」路徑，但原件能把它正面辨識為 `Table/_DamageSound.xml` 的傷害音效名稱：`FB7470+0xA0 → 4F6F70 → 5521D0 → 550580 → 80AF10 → 80E230 → vtable+0x0C → 80E4C0 → 80AB00`。這條路徑不應誤列為 `.mef` 入口。

另一項增量是原本 `425330` accessor 的 32 個候選中，四個保存 root 至 ESI／EDI 的 callsite 已向後追到 caller 的覆寫／epilogue；另外定向盤點 **root `FB7470` 本身的 155 個 literal 引用**，補上直接取得 root 再計算成員的候選。這是對舊 `FB74C0` literal 掃描與 accessor「第一 consumer」邊界的補強，並不是把舊陰性重算成新成果。

本報告採 **有界原件證據、階段性未完成** 狀態。沒有取得 `.mef` 新檔首次載入 caller，因此不能回答「所有 `.mef` 由誰觸發」，也不能由本文推出「整個 Client 沒有 `.mef` 支援」。部分保留暫存器跨過冷啟動 helper 或通用 virtual sender 的路徑，本文核到 caller 的實際消滅點及直接參數，沒有對其所有被呼叫函式建立無界傳遞閉包。

## 來源與本輪檔案

原件固定為 KR `02-Tartaros.bin`，大小 12,472,320 bytes，SHA256：

```text
9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
```

主線導覽來源固定 `e66dadaa721671919cbbeb228ae3f26ad990c9e3`；本工作線既有報告固定 `0a2503db089a4867cff5ef8bf6d7689333f12fd1`。所有來源的 repository path、commit、Git blob ID、SHA256、長度在 `source-manifest.json`。偽碼僅用於定位；下述新增欄位、caller、暫存器覆寫、字串與 vtable 綁定均從原件機器碼／資料讀回。

- `native-records.json`：原件 VA、raw offset、長度、hex、SHA256、指令或資料字串；record ID 可由本文直接查找。
- `native-records.asm`：相同 code windows 的 objdump 結果。
- `root-alias-census.json`：只針對 `FB7470` 的新 literal 候選與第一 transfer 分類。
- `verify_native.py`：只讀原件，核對來源、PE 映射、所有 windows、155 個根 literal、重要 E8 邊與具體 vtable slot；可選擇核對固定 commit/path 的 Git tree blob ID。

驗證器通過代表包內 bytes／scope／指定呼叫邊一致，**不等於 T01 FULL-PASS、整函式語意驗收、所有間接 caller 已窮盡或實機執行通過**。按下一個已知函式入口擷取的 body window 也不自動涵蓋 out-of-line exception chunks。

## 1. 明確復用的舊結果

以下均是既有結論，本文不把它們列為新增發現。

| 舊來源 | 本輪復用範圍 |
|---|---|
| `kr-extra-roy/MEF-parser-executor-storage-20261114/storage.md` | `FB74C0` 保存 map ID 對應的自有窄字串；不是 MEF bytes buffer。`FB7470` 為 collection root，TRIGGER 容器在 `+0x50`、head 在 `+0x54`。 |
| 同目錄 `alias-census.json` | `4F3D80` 的 165 個 E8 候選及 `425330` 的 32 個 E8 候選；本輪不重建這兩個候選集合。 |
| `kr-extra-roy/MEF-entry-lifecycle-events-20261114/entry.md` | `.mef` 新檔載入與舊事件 continuation 分開；已載入狀態的續行不能代替新檔首載 caller。 |
| `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md` | `4DF510` 的 `4DF5EA/4DF69B → 4F6E80` 使用另一張 `+0xE0/+0xE4` 資源名稱表。 |
| `governance/client-variants/20261107-mef-resume/native/{README.md,findings.json}` | `4DF58D → 4F7DF0` 取得 TRIGGER 名稱後，已初始化分支在 `4DF5B9` 覆寫 EAX；未初始化分支進固定 `4F3D80 → 4F4960` 初始化，並不把傳回名稱當 filename。兩條分支的既有陰性均保留。 |

主線舊稿只閉合 `4DF510` 的兩處 root→`4F6E80`，不包含全部直接 `FB7470` 指令的盤點。因此本輪新增的 root-literal 範圍有其必要性；沒有再掃 `.mef` 名稱、所有 BSS、舊 `FB74C0` literal、舊 16 個 lookup caller 或重新解包 STP。

## 2. 四個保存 root 的 accessor caller：向後追至何處

### 2.1 總表

| 已有 accessor callsite | 保存／第一 consumer | 本輪新增的後續資料流 | 能支持的結論 |
|---|---|---|---|
| `491FC7 → 425330` | `491FCC mov esi,eax`；`491FCE → 4F6B80` | owner `EBX+0x90` 非零時，`491FE4 mov esi,ebx`；為零時經 `804A40`，該 helper 在 `804A75` 改以 `FBA858` 為 ESI。共用尾段 `804FC0` 在 `804FE0` 先以 owner `EBX+0x3C` 覆寫 ESI。caller 在 `492005 pop esi` 還原上層值。 | root 沒有在此 caller 另加 `+0x50` 或寫入 owner；第一 consumer 的 `+0x110/+0x130` 名稱請求向量用途是舊結果。 |
| `49678E → 425330` | `496793 mov edi,eax`；`49679B → 4F6B20` | `4967BC lea edi,[edx+8]` 在下個 call／分支前消滅 root。 | 這個保存值已閉合到明確覆寫；其間沒有 TRIGGER 投射或 root escape。 |
| `4D607A → 425330` | `4D607F mov edi,eax`；`4D6081 → 4F6D20` | name lookup 成功才進 world lookup `40F060 → 4DFAD0`；有非零 WORD 結果才經 `414680 → 4A4240` 建構固定 `0x00C6` 封包。成功與失敗路徑都經字串 cleanup 至 `4D657C`，`4D6587 pop edi` 消滅該保存值。 | caller 後續使用的是名稱反查出的 ID／world result；EDI root 本身沒有被解參照、入參傳送或保存至 owner。固定封包不是 MEF filename／bytes。 |
| `53CC2E → 425330` | `53CC33 mov edi,eax`；`53CC38 → 4F6B20` | 跨過 `4054C0` getter 與 `402250` 字串建構後，`53CC5E mov edi,[ebp-48]`，短字串分支再 `53CC63 lea edi,[ebp-48]`。 | caller 轉而使用本地寬字串；沒有再由保存 root 取得 `+0x50`。 |

對應 records：`saved-491fc7`、`saved-49678e`、`saved-4d607a`、`saved-4d5f04`、`saved-4d657c`、`saved-53cc2e`、`tail-804a40`、`tail-804fc0`。覆寫點原件 bytes：

```text
491FE4  8B F3             mov esi,ebx
492005  5E                pop esi
4967BC  8D 7A 08          lea edi,[edx+8]
4D6587  5F                pop edi
53CC5E  8B 7D B8          mov edi,[ebp-48h]
804A75  8B 35 58 A8 FB 00 mov esi,[FBA858]
804FE0  8B 73 3C          mov esi,[ebx+3Ch]
```

### 2.2 保留的精確邊界

`491FCC` 的零分支在改寫 ESI 前可呼叫 `49AF60/49B000`；這兩個初始化 helper 給 `805460` 的明確建構參數是固定 `FC1208`，`805488` 把 ESI 改成該參數。此處沒有把 root 參數送進這個 constructor。

`53CC33` 的 `4054C0` 有冷啟動 `587480` 分支；`4D607F` 的 `40F060` 有冷啟動 `4DEC90` 分支，`4A4240` 最後還有通用 virtual sender。本文沒有把這些冷啟動子圖及通用 sender 的所有傳遞性 callees 逐一重新驗證。能確認的是實際 caller 與已列直接 helper 沒有把保存 root 當 TRIGGER／檔名參數使用；不能把保留於 callee-saved register、沒有 caller 顯式用途的值直接推論為「任意間接子圖絕無隱藏消費」。後續若把這些極少數冷路徑列為候選，應沿具體 input register 的 use-before-def 追查，不能再次把 32 個原集合當新清單。

## 3. 直接 `FB7470` root literal 的新增定向盤點

搜尋範圍只有原件 raw-backed `.text/.rdata/.data` 內 little-endian DWORD `70 74 FB 00`。全部 **155** 個命中都位於 `.text`，由已知函式入口反組譯後，對應 **120** 個函式的有效 immediate 指令；沒有 `.rdata/.data` 直接指標命中。每個 literal 的精確指令及第一 call／ret 都在 `root-alias-census.json`。

| 第一 transfer | 數量 | root 的實際用途 | 本輪性質 |
|---|---:|---|---|
| `4F6A30` | 94 | `+0x100/+0x104` 寬字串 cache，缺項可進 `+0x110` pending-ID vector | helper 語意復用；新增直接 root 引用關聯 |
| `4F7A70` | 21 | `+0x00/+0x04` 主 Actor record tree | 同上 |
| `4F6950` | 10 | `+0x100/+0x104` 寬字串 cache writer | 同上 |
| `4F6E80` | 8 | `+0xE0/+0xE4` 資源名稱表 | 舊稿僅列其中兩處；本輪補其餘直接 root 關聯 |
| `4F7370` | 5 | `+0x120/+0x124` 寬字串 cache，缺項可進 `+0x130` pending IDs | helper 語意復用；新增直接 root 引用關聯 |
| `4F7280` | 4 | 寫 `+0x120/+0x124` 寬字串及額外 DWORD；特定條件使用 `+0x130` 向量 | 新 helper contract |
| `4F6DC0` | 1 | 遍歷 `+0x104`，由寬字串反查 ID | helper 語意復用 |
| `4F8B60 / 4F8BC0` | 3 + 3 | `root+4` 的主樹旋轉；節點 child／parent 指標 | 新 helper contract |
| `4F8AC0` | 1 | 主樹節點遞迴析構；傳入 ECX=root 未被函式讀取 | 新 helper contract |
| `4F6F70` | 1 | `+0xA4` 傷害音效名稱樹 | 新增且追到實際 consumer，見下節 |
| constructor／destructor 的第一 call | 2 | root 保存於初始化／析構 local；分別先到 `8404D0/89120C` | 生命週期復用，不當載入 caller |
| `ret` | 2 | `425330` 與 constructor 回傳 root | 既有 accessor／initializer census 復用 |

這個表只主張列出的**第一 consumer**，不冒充 root 任意 alias／返回值／後續多層間接呼叫的完整閉包。尤其 `mov edi,FB7470 → 4F6E80` 的 8 處會保留 EDI，本輪另列 caller 後續：

| root 指令 | caller 內最後用途／覆寫點 |
|---|---|
| `4B4152` | 中途只有 `mov edi,edi` NOP；`4B421D mov edi,10h` 改寫。跨過字串 helper 及可選固定 singleton 初始化。 |
| `4BAD73` | 經資源名稱流程；`4BAEAD/4BAEB4` 兩個分支改以固定字串 VA 覆寫 EDI。 |
| `4DF5E5` | `4DF5EF mov edi,1`，舊 map 路徑。 |
| `4DF696` | `4DF6A0 mov edi,[ebp+0C]`，舊 map 路徑。 |
| `564049` | `564053 mov edi,1`。 |
| `564108` | `564112 mov edi,1`。 |
| `6D951D` | `6D9527 mov edi,eax`，變成 lookup 傳回的資源字元指標。 |
| `6D9616` | caller 不再讀 EDI root；`6D9675 pop edi`。跨過可選初始化與資源處理 `6D9B30`。 |

records 為 `literal-tail-*`。三處較長 cold-call 子圖的任意傳遞性 callee 沒有被本文整體重新驗收，故不把「caller 無顯式 root 消費」擴張為全子圖不存在 consumer。

`4F7280` 的關鍵證據為 `4F7292 lea edi,[ebx+130h]`、`4F72AA lea esi,[ebx+120h]`、`4F72BE cmp eax,[ebx+124h]`，以及成功路徑的寬字串複製、`value+1C` 附加欄位。`4F8B60/4F8BC0` 的參數 `root` 僅透過 `root+4` 找樹 head 進行旋轉。注意 **node 的 `+0x50` 欄位不等於 collection root 的 TRIGGER `+0x50`**；必須先辨識 base object 才能判斷。

## 4. 新找到的名稱 consumer：完整閉合為 DamageSound

### 4.1 writer 的原生檔名與 XML 欄位

`4F6630` 以 `C0D5BC` 固定名稱建 XML reader，`4F666A → 72EE30`、`4F6694 → 72F110`。原件資料如下，均含 NUL 並保存各自 VA/raw/hash：

| VA | 原件字串 | 用途 |
|---|---|---|
| `C0D5BC` | `Table/_DamageSound.xml` | 此表固定載入名稱 |
| `C0D5D4` | `DAMAGESOUNDS` | 根元素 |
| `C0D5E4` | `BaseFolder` | 基礎路徑元素 |
| `C0D5F0` | `PATH` | 基礎路徑欄位 |
| `C0D5F8` | `DSOUND` | 逐筆元素 |
| `C0D600` | `ATTACK` | key 高 5 bits 來源 |
| `C0D608` | `DEFENSE` | key 低 3 bits 來源 |
| `C0561C` | `FILE` | 音效名稱欄位 |

兩個數值先轉整數；`4F6819–4F6839` 的 AND／倍增／OR 產生 byte key：

```text
key = ((ATTACK & 0x1F) << 3) | (DEFENSE & 0x07)
name = BaseFolder.PATH + DSOUND.FILE
```

名稱串接在本地 narrow string；`4F684F mov ecx,FB7510`、`4F6858 → 4F9A60` 配置 0x30-byte node，`4F9ACE` 讀入 byte key 放至 `node+0x0C`，`node+0x10` 建 narrow string 並複製名稱。`4F685E push FB7510`、`4F6869 → 4F90B0` 將 node 交給同一容器插入路徑。

`FB7510 = FB7470 + 0xA0`；getter 的 head 地址 `FB7514 = root + 0xA4`。因此這裡的 root field 身分由 writer、原字串、node 型態與 reader 四者交叉建立，並非只依 offset 猜測「不是 TRIGGER」。

### 4.2 getter 返回的是音效字元指標

`4F6F70` 接收 ESI=root、DL=byte key。`4F6F73` 讀 `[esi+A4h]`，依 `node+0x0C` byte key 搜樹；不存在時回傳 0。存在時 `4F6FC6 add eax,10h` 得到 narrow string object，再按 `string+0x14` 容量選 inline 或 heap 字元，最終返回字元指標。

`5521D0` 的具體鏈：

```text
552289  mov dl,[ebp+1Ch]
55228C  mov esi,FB7470
552291  call 4F6F70
55229D  mov esi,eax        ; ESI 不再是 collection root
...
5522F0  push esi           ; 550580 的第二個 stack argument
5522F7  call 550580
```

`550580` 在 `5505A7` 把第二參數讀進 EBX；只有非 null、非空名稱才進聲音物件請求。`55067B mov ecx,ebx`、`55067D → 80AF10` 使這個字元指標確實被 consumer 取得。這是本輪的正面名稱使用鏈，不是僅發現一個查表 call 後就停止。

### 4.3 間接呼叫 target 已由建構子與原件 vtable 閉合

`80AF10` 配置 0x2C-byte 物件，在 `80AF98 → 80E230` 建構；`80E260` 原件寫入 `object->vtable = C51B50`，將名稱複製到 `object+8`。

`550686` 把物件存入本地效果 owner 的 `+0x28`；`55068D` 取 `[vtable+0x0C]`，`550691 call eax`。原件 `C51B5C` 的 DWORD 是 `80E4C0`，所以這個間接呼叫的實際 target 可確定，無須把未知 virtual call 留作猜測。

`80E4C0` 將 `object+8` 名稱交給 `80AB00`；對應實際 callsite `80E530`。`80AB00` 在 `80AB65` 使用原字串 `C517F0 = "Requested sound %s\n"`；其後查找聲音 cache，已有條目時使用或啟動其請求，無條目時配置 0x5C-byte 資源物件並進相同聲音請求路徑。本文將此界線記為**傷害音效資源請求／播放物件建立**，不延伸分析音訊 codec 或聲音裝置。

由固定 `_DamageSound.xml`、`DSOUND/FILE`、byte key writer、具體聲音物件 vtable、`Requested sound` consumer 形成互相一致的證據。**可以排除這個具體 root+A0 名稱 consumer 作為 `MapList.TRIGGER` 的 `.mef` 新檔首載 caller。** 本文未把該音效路徑的存在推成「所有副檔名都不能送到此函式」，也沒有以任意替換 XML 內容作實機試驗。

## 5. 對使用者目標的實際意義

### Client 待逆向

仍缺一條已證鏈將 `.mef` 名稱或對應 bytes 接到真正 reader，再接 parser／executor。就 MapList 方向而言，普通 map caller 已有未消費結論；本輪直接 root alias 補強也沒有得到新的 TRIGGER consumer。不能再用「TRIGGER 欄位存在」「root accessor 可達」「某個事件會續行」三者任一取代首次載入的實證。

未覆蓋的任意 computed alias、資料複製後 consumer、未知間接呼叫仍保留為未知；其下一步必須有具體指標／返回值／register-use 候選，而不是重跑本報告的 155 命中或先前 32/165 清單。

### Server 待開發

Server 仍須為已確認的地圖／任務流程提供相容狀態與資料，並在正式取得原生事件啟動介面後實作相對應的決策與回覆。**本文沒有新增可供 Server 傳送 `.mef` bytes 的 opcode、欄位或時機規格**；也沒有證據支持只填 MapList `trigger` 即可啟動。將未知 wire/parser 全部歸成 Server 自行設計會失去原版 Client 相容性，因此該界面仍屬 Client 待逆向；原版 Server 的內部決策與持久化則列 Server 開發需求，不要求還原官方演算法。

### 跨功能整合與待遊玩驗證

本支線可與其他已證 native loader／Lua state／事件 continuation 研究整合，但只有真正共用 filename 或 bytes 的 dataflow 才能把鏈接起來。單純相鄰函式、相同事件名稱或相近呼叫時間不足以接線。本文未執行 Client、Lua、Server 或遊玩測試，亦未修改原件。

## 6. 只讀重驗

將此資料夾放在任意位置後執行：

```bash
python -B verify_native.py /absolute/path/to/02-Tartaros.bin
```

如另有含上述固定 commits 的研究 repo，可同時核對 source manifest：

```bash
python -B verify_native.py /absolute/path/to/02-Tartaros.bin --repo /absolute/path/to/ttr_anal_multi
```

驗證器只讀提供的原件與 JSON，選用 `--repo` 時透過 `git ls-tree` 核對指定 commit/path 的 blob ID，不觸發缺少的 blob 下載。偽碼內容 SHA-256 已在本輪組包時核對；選用模式只驗 tree pin，兩者不混稱。驗證器不執行遊戲原件、Lua 或歷史證據腳本。組包用的 scratch 導覽索引、下載的偽碼副本與中間 slices 不屬必要交付內容；必要交付為本文與五個 evidence／verifier 檔案。
