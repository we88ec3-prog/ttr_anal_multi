# T10-081 — KR KeyMapping 實體資源恢復、Z/X/C/V 預設配置定錨

- 記錄時間：2026-10-28T08:57:23+08:00
- 研究範圍：KR `Table/KeyMapping.xml`、`Table/KeyMappingExtra.xml`，與原版 `Tartaros.bin` XML 載入端；靜態唯讀。
- 原版 BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪本機重新計算一致）。
- GitHub 主線接續：T01-20261028-06 resource-source-audit；T10-069..080 的靜態研究。

## 新證據：原始資源可在正式證據庫取得

此前檢查 `kr-temp-roy/T16-local-20261028/evidence/resources/kr/Table/KeyMapping.xml` 得到 404，**不代表原件不在 GitHub**。T01 整合將內容以原始位元組導向的文字證據保存於：

1. `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt`：原 `Table/KeyMapping.xml`。
2. `kr/evidence/6c019693bf60589feb2f3ff6aec651f83ddc0d8103e1358f0ad9c19caf8ac973.txt`：原 `Table/KeyMappingExtra.xml`。

上述 SHA 由 `shared/integrations/T01-20261028-06/resource-source-audit.json` 原件欄提供：二者都由 KR `E:\\Tartaros\\origin\\Table.stp` 載體導出，載體 SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。目錄型態是內容相同的 `.txt` 證據鏡像，不可因副檔名為 txt 當作猜測版或手填配置。T01 記錄獨立成員解碼一致；本輪從 GitHub connector 直接讀到完整 XML 字串，但**尚未在此工具環境重新解包 Table.stp**。

## 原生 XML：預設 Type 0 的四按鍵對應

`<KeyMapping DefaultType="0">` 包含 `<Type idx="0">` 與 `<Type idx="1">`。對目前典型 PC 鍵盤 Z/X/C/V，若 `Key` 是符合 DirectInput DIK 慣例的鍵盤掃描碼（十進位 44/45/46/47；此慣例需由實際輸入 producer 進一步核對），原件中的**直接字面證據**為：

| 文字按鍵候選 | Key 值 | Type 0 MapButton | Type 0 ModKey | Type 1 MapButton | Type 1 ModKey |
|---|---:|---:|---:|---:|---:|
| Z | 44 | 13 | 0 | 10 | 0 |
| X | 45 | 14 | 0 | （XML 未列） | — |
| C | 46 | 15 | 0 | 11 | 0 |
| V | 47 | 16 | 0 | 12 | 0 |

**重點限制**：`MapButton` 是 XML 映射 ID，還不能直接聲稱它是普攻／蓄氣／技能／動作 opcode；`DefaultType=0` 是原件預設屬性，不代表玩家現用的配置必為 type 0。Type 1 缺少 Key45 的顯式列，不能推論執行時一定禁用 X，仍須查 fallback 和自訂覆寫。

XML 片段（直接由官方 KR 資源對照）：

```xml
<KeyMapping DefaultType="0">
  <Type idx="0">
    <Key MapButton="13" Key="44" ModKey="0" />
    <Key MapButton="14" Key="45" ModKey="0" />
    <Key MapButton="15" Key="46" ModKey="0" />
    <Key MapButton="16" Key="47" ModKey="0" />
  </Type>
  <Type idx="1">
    <Key MapButton="10" Key="44" ModKey="0" />
    <Key MapButton="11" Key="46" ModKey="0" />
    <Key MapButton="12" Key="47" ModKey="0" />
  </Type>
</KeyMapping>
```

以上是從完整原件摘出的**子集合**，不是 XML 全文重製；完整原件來源請取正式證據檔。

## KeyMappingExtra 的資料域

第二份 XML 也以 `DefaultType="0"`、`Type idx=0/1` 儲存，但 `MapButton` 主體落在 10500..10522 及 11000..11003，和基本映射 1..39 是不同 ID 範圍；不可把 `KeyMappingExtra` 當作 KeyMapping 第一份的覆寫而忽略兩者 domain 區分。

例子：

```xml
<Type idx="0">
  <Key MapButton="10500" Key="18" ModKey="0" />
  <Key MapButton="11002" Key="28" ModKey="0" />
  <Key MapButton="11002" Key="156" ModKey="0" />
</Type>
<Type idx="1">
  <Key MapButton="10500" Key="46" ModKey="29" />
  <Key MapButton="10501" Key="16" ModKey="29" />
</Type>
```

同一個 Key46 在 Extra Type1 附帶 ModKey29，**不能**和基本 Type1 `Key46, ModKey0, MapButton11` 視為完全相同的輸入條件。

## BIN-first 載入端抽樣驗證

將本機 raw `Tartaros.bin` 以 `VA = rawOffset + 0x400C00` 對 `.text` 對應區段反組譯（等價 `rawOffset = VA-0x401000+0x400`，只適用所核對段），`0x6D08F0` 載入流程入口 x86：

```asm
006d08f0: 55                    push ebp
006d08f1: 8b ec                 mov ebp,esp
006d08f3: 83 e4 f8              and esp,0xfffffff8
006d0930: 8d 44 24 24           lea eax,[esp+0x24]
006d0934: 50                    push eax
006d0935: b9 88 08 c4 00        mov ecx,0xc40888
006d093a: e8 f1 e4 05 00        call 0x72ee30
006d095d: 6a 00                 push 0
006d0963: e8 a8 e7 05 00        call 0x72f110
006d0968: 84 c0                 test al,al
006d096a: 0f 84 f8 02 00 00     je 0x6d0c68
```

該窗口證實所引用 VA 是本次 BIN 可反組譯的可執行函式入口及帶分支的流程；具體 XML 字串及其函式內用途沿用 T10-069～080 已記載的位址/引用，不能從此短窗口單獨證明它把 Z 指派為普通攻擊。

## 與 T10-069～080 相比的實質進展

此前已定位 `0x6D08F0` 讀取 `Table/KeyMapping.xml`、`0x6D1A70` 選擇映射 bank，但欠缺 XML 原件實際內容。本次藉 T01 的內容定址正式證據讀到原始資料，**消除 KR 預設表字面鍵碼/MapButton 的缺口**。最值得追蹤的 `Type0` 基本 MapButton 為 `13,14,15,16`。將舊記錄的「實體 KeyMapping 尚缺」改為「已取得；現用自訂配置及動作語義仍缺」。

## 待解與下一步 T10-82

1. 驗證 `Key=44..47` 在此客戶端的輸入事件 producer 是否確以 DIK scan code 解析（不是僅憑 PC 一般慣例）。
2. 找出基本 `MapButton=13/14/15/16` 的遊戲動作 consumer、具體物件、寫入的 phase bytes 以及映射模式切換。
3. 區分 `Type0` 預設與持久化自訂配置，檢查 Type1 Key45 缺列的 fallback。
4. `KeyMappingExtra` 類別化，辨認其 105xx/110xx consumer；避免混合成普攻組合鍵。
5. 從原生非零 phase writer 追到 controller/motion/queue/cancel，再判定 Z 普攻、V tap/hold 真正行為。

## 版本管理

本段只建立本機完整技術記錄；**沒有 Commit/Push**、沒有修改 owner/catalog，亦沒有上傳新增的遊戲原始程式或資源檔。正式 GitHub T01 已有相同來源內容定址證據，不需重複上傳原始檔。