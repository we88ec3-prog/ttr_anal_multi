# E04 — Event/SceneList.xml 與 Table/SceneList.xml：Client BIN 雙來源字串核查、EX 解碼器定位界線

日期：2026-10-29，研究分支 extra/roy1；只讀原始 Event.stp、Tartaros.bin。承接 E01–E03。本段為有界增量，**未完成 EX codec**。

## 原始來源
- Event.stp：11,241,597 bytes；SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- Tartaros.bin：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- BIN `.rdata` raw `0x7D0600`、VA `0xBD2000`；VA = raw + `0x401A00`（僅此 section）。
- E03 已定位 STP XOR-view SceneList 候選 `0xA23810–0xA26FFF`，16-byte header `45 58 01 00 A0 36 00 00 3D 6A 02 00 10 00 00 00`，未解碼。

## 本段直接 BIN 驗證的新事實

對原始 BIN 搜尋有別於一般短 `EX` 命中的完整 byte string：

| 字串 | BIN raw offset | 依 .rdata 映射的 VA | 備註 |
|---|---:|---:|---|
| `Table/SceneList.xml` | `0x8018C8` | `0xC032C8` | 原字串完整可讀；**不是** Event/SceneList.xml |
| `Event/SceneList.xml` | `0x80EC68` | `0xC10668` | 旁邊有 `Event/qbase.lua`、`SCENESET`、`questIdx`、`funcName`、`f_doCoTask` |
| `Event/TutorialBase.lua` | `0x804E64` | `0xC06864` | 相鄰 Tutorial entrypoint 字串 |
| `Event/TutorialMain.lua` | `0x804E7C` | `0xC0687C` | 相鄰 `Tutorial_EntryPoint`、`Synopsis_EntryPoint` |

**重要校正**：同名基底 SceneList.xml 在 KR Client 有 `Table/` 和 `Event/` 兩條不同路徑。E02/E03 Event.stp 研究只約束 `Event/SceneList.xml`，不能將 Table 版 schema 混入。二者各自的載入者尚未完成控制流匹配。

對完整 `Tartaros.bin` bytes 掃描，沒有找到明文 `STPD` 及 `EX 01 00`。這只能排除 **BIN 中這兩個 exact contiguous ASCII/immediate byte pattern**，不能證明 Client 無封裝 reader：原生 code 可能拆開比較、動態計算、字節序不同或透過外部模組。

對四個字串採 `.rdata` VA 計算後搜尋等值 little-endian DWORD，在本次全 BIN 沒有 direct exact-pointer hits。這不能否定存在相對尋址、其他片段形成的字串指標、array/indirect xref；須查函式和 GOT/init 層。亦不意味字串未被使用。

## 核對方式

```python
from pathlib import Path
import hashlib,struct
b=Path("Tartaros.bin").read_bytes()
assert hashlib.sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
for name, raw in [
 ("Table/SceneList.xml",0x8018C8),
 ("Event/SceneList.xml",0x80EC68),
 ("Event/TutorialBase.lua",0x804E64),
 ("Event/TutorialMain.lua",0x804E7C),
]:
 assert b[raw:raw+len(name)] == name.encode()
 print(name,hex(raw+0x401A00))
assert b.find(b"STPD") == -1 and b.find(b"EX\x01\x00")==-1
```

## 證據界線與後續

- XML codec 尚未還原，不能宣稱 `SceneList.xml` 已解出，亦不應猜測 `EX` 是特定 compression cipher。
- 第一輪新增 `Table/` 與 `Event/` 雙路徑的原生分離、具體 VA 與相鄰 loader/API 字串，屬來源辨識的實質增量；本段不假裝已達 opcode→scene 整體閉環。
- E05 優先：從 `Event/SceneList.xml` VA `0xC10668` 及 `Table/SceneList.xml` VA `0xC032C8` 追間接引用、函式與 reader；再對 STP EX container `0xA23810` 的 `0x36A0`、`0x26A3D`、`0x10` 找讀取/解碼語意。若缺原生 module 或 asset parser，明示 blocker，不以猜測取代。
- E01-E04 仍留在 `extra/roy1:kr-extra-roy/`；T01 完整整合、確認 source SHA/provenance 已吸收後才清理。
