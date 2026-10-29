# KR E02 — Event.stp 目錄索引與 SceneList.xml 封裝邊界（BIN-first / resource-first）

日期 2026-10-29（Asia/Taipei）。獨立研究段 E02，承接 `kr-extra-roy/20261029-chatgpt-web-roy-E01-Event-STP-native-Tutorial-Lua.md`。原檔唯讀，未執行 Client、Lua 或未確認的解碼器；只將分析證據寫入研究分支。

## 1. 原件、方法與證據等級

- `Event.stp`: 11,241,597 bytes；SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始 STP bytes[0:4]=`53 54 50 44` (`STPD`)，對檔案 bytes 逐位 `^ 0xff` 得到解碼 view。例：解碼 offset `0x10` 為 `<?xml version="1.0" encoding="euc-kr"?>`。
- 檔案解碼 offset `0x04` little-endian DWORD = `0x00A62AD4`；此處存在 `Event` 目錄結構，與本次目錄內容逐 byte 核對。**不是所有 Event.stp 版本通用格式的宣告**。

## 2. 一手目錄項 bytes 與連續索引：E02 重大增量

原始 STP XOR view 靠近 `0xAB87FD` 的四個檔案名稱，跟隨 4-byte 小端整數和隨後不變的 `00 00 00 00 64 9f 40` 節段。可直接解讀的相鄰條目如下：

| 名稱 | 名稱開始 XOR-view offset | 緊接名稱後的 4-byte index | Decimal |
|---|---:|---:|---:|
| `qbase.lua` | `0xAB87FD` | `D2 1C 00 00` | 7378 |
| `SceneList.xml` | `0xAB8819` | `D3 1C 00 00` | 7379 |
| `TutorialBase.lua` | `0xAB8839` | `D4 1C 00 00` | 7380 |
| `TutorialMain.lua` | `0xAB885C` | `D5 1C 00 00` | 7381 |

**精確限制**：索引值的「ordinal」身份有相鄰連號與實際 payload 排序支持；尚未以 Client 程式驗證此索引是資料庫 key、directory sequence 或另一種 ID。不能直接把 index 當 byte-offset。

## 3. 與已可獨立驗證 Lua payload 的交叉校驗

STP XOR-view 的下列 offset+0x10 是 Lua 5.1 chunk header `1B 4C 75 61 51 00 01 04 04 04 08 00`：

| 檔名 | 16-byte container header offset | chunk offset | chunk bytes | SHA256(chunk) |
|---|---:|---:|---:|---|
| `qbase.lua` | `0xA20800` | `0xA20810` | 11836 | `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3` |
| `TutorialBase.lua` | `0xA27000` | `0xA27010` | 1416 | `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` |
| `TutorialMain.lua` | `0xA27800` | `0xA27810` | 5480 | `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` |

三者 SHA 均與 T16-41／T16-46 來源紀錄相符，避免把誤判 block 或自造解碼稱為 native。這是 **STP 相鄰 index、payload 實際排序及跨 Task hash** 的三向驗證。

## 4. SceneList.xml 資料區、封裝欄位及反證

由 `qbase.lua` chunk 長 11836 bytes 的結束位置、後續 0x800 對齊 block，以及已驗證 `TutorialBase.lua` 的入口，可將相鄰 SceneList 候選 container 定位至 **`0xA23800..0xA26FFF`**，下一已證實 block 為 `0xA27000`。

- `0xA23800..0xA2380F` 的 16 bytes: `2b 2b 56 81 d7 58 2f 87 b6 3d f3 30 23 53 76 c9`。
- XOR-view `0xA23810..0xA2381F` 的 16 bytes: `45 58 01 00 a0 36 00 00 3d 6a 02 00 10 00 00 00`。
- 若作 LE32 四欄觀察，其值為 `88133, 13984, 158269, 16`；**各欄語意尚未由 BIN 驗證，不能逕命名為壓縮長度／原長度／索引。**
- 以第二欄 `0x36A0=13984` 為純候選長度，`0xA23820` 起連續 13984 bytes 的 SHA256 是 `5ecc916708a378e6732635e387ba69e057a216321acf899a42740a8a22c750c8`，便於下一輪重現相同位元組。
- `SceneList.xml` 候選 container `0xA23810..0xA26FFF`（14320 bytes）SHA256 `ca445c6ee80cfe984c16561ac2124e6a892b5782af45bc3a79825f07ba8c581b`。
- 整個候選區不是可見 `<?xml` 或 `<scene` plaintext；由 payload byte offsets 0、4、8、12、16、20、24、28、32 對 zlib raw/zlib/gzip 三種 header window 的直接嘗試都沒有成功。因此 **本輪確認定位 SceneList 的資料區，沒有宣稱已還原 XML schema**。不能據此推定使用哪種加密或壓縮演算法；單次 zlib 失敗也不排除自訂前綴或其它 codec。

## 5. 可重現的唯讀驗證程式

```python
from pathlib import Path
import hashlib, struct
blob = Path("Event.stp").read_bytes()
assert blob[:4] == b"STPD"
d = bytes(v ^ 0xff for v in blob)
assert struct.unpack_from("<I", d, 4)[0] == 0xA62AD4
for name, start, size, sha in [
    ("qbase.lua", 0xA20810, 11836, "d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3"),
    ("TutorialBase.lua", 0xA27010, 1416, "26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744"),
    ("TutorialMain.lua", 0xA27810, 5480, "662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809"),
]:
    assert hashlib.sha256(d[start:start+size]).hexdigest() == sha, name
scene = d[0xA23810:0xA27000]
assert hashlib.sha256(scene).hexdigest() == "ca445c6ee80cfe984c16561ac2124e6a892b5782af45bc3a79825f07ba8c581b"
print("SceneList candidate header LE32", struct.unpack("<4I", scene[:16]))
```

## 6. Client → Server 與玩家情境界線

- **Client 已證**：三個 Lua 5.1 bytecode chunk 屬於使用者上傳的 KR Event 容器；相鄰 SceneList 目錄 entry、candidate container 和 16-byte payload metadata 可重現。
- **Client 待逆向**：SceneList 真正解碼器；`Tutorial_EntryPoint` 到選角 S→C handler 與 Tutorial scene controller 的調用/狀態鏈；`0x42` 回覆 pairing。
- **Server 待開發**：首次登入狀態裁決與持久化的相容實作，但必須先以原生 Client 介面確認 wire payload 和 UI／場景讀取條件；不可臆造官方判斷。
- **跨 Task 整合**：T16-41、T16-46 的 Lua CFG 可直接引用，T07 原稿仍指 `005F type6` 原生建 `CDuelField`，不得使用測試修補的 Tutorial 分支當官方。
- **待遊玩驗證**：此為靜態唯一來源定位，不等於啟動原版 Tutorial 的驗收。

## 7. 三輪深入與停止理由

第 1 輪 E02：已完成，新增目錄 ordinal 7378–7381、SceneList 候選容器界限、metadata 與獨立 SHA 等完整可重現的原件錨點。這些不同於 E01 的單純 Lua chunk 提取，屬重大可驗證來源定位進展。依共用規則停止此段；E02-2／E02-3 未啟動，非宣稱 SceneList 已解壓。

下一段 E03：優先定位原生 STP 封裝 reader/codec（從 SceneList container metadata 及 Client BIN 內資源 loader 交叉驗證），取出完整 SceneList.xml 的原件解碼內容；再做 Lua tutorial API → C++ gateway／首次登入條件的資料流整合。

## 8. 分支整合與清理

獨立研究存 `extra/roy1:kr-extra-roy/`；保留 E01 和 E02 原稿直到 T01 明確完成稽核／吸收可追溯證據後，才按使用者規則在整合目標清理 `kr-extra-roy/`。此段不操作 main，也不先刪目錄。
