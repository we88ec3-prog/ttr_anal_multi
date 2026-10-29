# E09 — KR tutorial_start.seq 目錄索引／Lua payload／SceneList 雙鍵映射與執行鏈邊界

日期：2026-10-29（Asia/Taipei）。承接 E08。僅唯讀原始 `Event.stp`、`Tartaros.bin`；沒有執行 Client、Lua 或伺服器。工作分支 `extra/roy1`、暫存目錄 `kr-extra-roy/`。

## 來源

- `Event.stp`：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- E06 還原 `Event/SceneList.xml` SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`。
- E08 blob `008442a5a8dc809df06d90e43612c86f7457bee1`；主線 T16-46 Lua bytecode 證據 blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`。

## 第 1 輪：STP 原生目錄中的兩個相鄰 tutorial seq entry

對 STP 逐 byte XOR 0xFF 後，兩個相鄰 entry 的目錄資訊：

| 名稱 | name offset (XOR view) | 名稱前 16-bit len | 名稱後 5-byte 00 padding | 後續 LE32 ordinal |
|---|---:|---:|---|---:|
| `tutorial5_1.seq` | `0xAB861E` | `0x000F` (=15) | `00 00 00 00 00` | `0x1CC4` (=7364) |
| `tutorial_start.seq` | `0xAB8640` | `0x0012` (=18) | `00 00 00 00 00` | `0x1CC5` (=7365) |
| `qbase.lua` | `0xAB87FD` | `0x0009` (=9) | `00 00 00 00 00` | `0x1CD2` (=7378) |
| `SceneList.xml` | `0xAB8819` | `0x000D` (=13) | `00 00 00 00 00` | `0x1CD3` (=7379) |

位元組對照顯示檔名字串前的 LE16 長度與實際名稱 byte 長度一致，名稱後五個零 byte 再接 LE32 的連續 ID。**這是本段新的目錄 entry layout 證據。** 但 `ordinal` 的完整用途、其他 metadata `64 9F 40` 的語意尚未由 Client 資源 reader 逐指令證實；不可把 ordinal 當 raw offset。

## 第 1 輪：原始 tutorial_start Lua / XML 的獨立來源相互吻合

- STP XOR view `0xA1C010..0xA1C219` 的可讀 522-byte Lua source snippet SHA256 `1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc`，包含 `-- Quest #1001 / Scene #1 - Function tutorial_start`、`function tutorial_start()`、`Register(tutorial_start)`。
- 注意此 522-byte snippet 的後方在 `0xA1C21A` 尚有 `0D 0A`，所以**不能把已截取 snippet 恰好 522 bytes 冒充 STP 目錄記錄的最終原生檔案長度**；完整 payload size 仍要從目錄查得。
- E06 `Event/SceneList.xml` 的獨立 row `questIdx=1001,sceneIdx=1,funcName=tutorial_start,endBehavior=0`。一邊是 XML 兩鍵對應，一邊是同一版本 STP 中的 Lua source，此外有實際 `.seq` 目錄項；三者一致，**靜態來源關係已可確認**。
- E08 的 Client `0x5607D0 → 0x568950 → 0x568680` 建立 `(questIdx,sceneIdx)` 雙鍵有序表。E09 再檢查原始 BIN `0x5609B3 call 0x568950`、`0x5609C4 call 0x568680` 指令，證明其承接解析出來的行資料。
- `tutorial_start` 原文作 `LoadMap("town000D.map")`、`PlayCamera("tutorial_00_1.cam",...)`、`RestoreMap()`。這是腳本靜態意圖，不證明執行時網路下發該地圖。

## 第 2 輪：Client index owner / reference 界線和反證

用 original BIN byte 搜尋 `0xFB73C8` little-endian raw DWORD，得到的直接命中僅為：
`0x5605B6`、`0x56085D`、`0x5609A3`、`0x5609BE`（VA；原始 BIN raw=VA-`0x400C00`）。這將 `0xFB73C8` 的**直接立即數引用**集中於索引初始化與 SceneList 匯入路徑；並不證明不存在 runtime reader，因 reader 可能透過物件指標或函式間接傳遞。

`tutorial_start` ASCII 在原始 BIN 中未找到，而 `Tutorial_EntryPoint` 存在於 Lua bytecode/原始 BIN 的另一路徑；不能把其名稱近似視為 direct call evidence。Event `Register(tutorial_start)` 是 Lua source-level 註冊，但尚未對應到 C++ Lua bridge 的 virtual callback address。

因此 E09 仍**不能**作出「選角 `0x42` response 直接決定 `1001/1`」的判定；需找到讀取雙鍵表的 caller、從 `funcName` 轉 `.seq` 的 locator、Lua `Register` 及腳本的 scene Start 消費者。

## 第 3 輪：原生 resource 指標與下一個可證目標

依 E05 已證 `0x72F110` → `0x714770` resource lookup、`0x72F260` → EX v1 解碼；這是**一般檔案取得**。E06 已證其中 EX sample 的 codec，不能反推 `tutorial_start.seq` 一定使用同一 EX 封裝；本段的 source 在 STP XOR-view 中直接可見，反而應先確定 reader 如何交付 `.seq` 文字給 Lua。

最小後續證據鏈：

1. 原版 BIN 追查接收 `questIdx`、`sceneIdx` pair 的呼叫者／讀者，找真正 `0xFB73C8` 表索引。
2. 比較 `funcName` 到 `*.seq` path transform 的原生 code。
3. 查 `Register` Lua API 誰消費、Lua runtime 執行後何時載入／調用 `tutorial_start`。
4. 連到 T03 `0x42` 回覆 handler 和 T07 場景 controller，才能界定首次登入場景觸發的 S→C 規格。

三輪均為**同一 E09** 的定向核對：第 1 輪目錄 layout 與三方來源、第 2 輪 index xref 反證界線、第 3 輪資源 reader 對接接口。此次新證是有界靜態來源鏈，而非 runtime scene dispatch 已閉合。

## 唯讀重現

```python
from pathlib import Path
from hashlib import sha256
import struct
d=bytes(x^255 for x in Path("Event.stp").read_bytes())
for name,expected_index in [
 ("tutorial5_1.seq",7364),("tutorial_start.seq",7365),
 ("qbase.lua",7378),("SceneList.xml",7379)]:
    b=name.encode("ascii")
    o=d.index(b)
    assert struct.unpack_from("<H",d,o-2)[0]==len(b)
    assert d[o+len(b):o+len(b)+5]==b"\0"*5
    assert struct.unpack_from("<I",d,o+len(b)+5)[0]==expected_index
    print(name,hex(o),expected_index)
script=d[0xA1C010:0xA1C21A]
assert sha256(script).hexdigest()=="1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc"
assert b"Register(tutorial_start)" in script
```

## 玩家流程與整合狀態

AN-04/05：Client 靜態 XML pair、`.seq` source/ordinal、Lua Register 存在；**實際首登 scene selector 與 runtime dispatch 待逆向**。SV-05/07：可利用 `questIdx`、`sceneIdx` 明確場景表對照作資料模型參考，不得冒充官方 Server packet。跨 Task T03/T07/T16 已有研究，應復用並要求 T01 整合驗證；不擅自升格 FULL-PASS。

所有 E01–E09 原稿保留在 `extra/roy1:kr-extra-roy/`；等 T01 確認正式整合且來源可追溯後，依使用者規則清理整合目標暫存資料夾。此輪不動 `main`。
