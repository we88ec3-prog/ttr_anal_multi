# KR E01 — Event.stp 原生教學 Lua 還原與跨 Task 證據邊界

日期：2026-10-29（Asia/Taipei）。唯讀研究，未執行或修改 Client，未執行 Lua。目標分支 `extra/roy1`，暫存路徑 `kr-extra-roy/`。

## 一、原件及解碼證據

- 使用者提供 `Event.stp`，11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- 前 4 bytes 為 `53 54 50 44` / ASCII `STPD`；檔案其餘 byte 經 `XOR 0xFF` 可讀。解碼後 offset `0x10` 可見 `<?xml version="1.0" encoding="euc-kr"?>`。
- 解碼後 offset `0x04` LE32 為 `0x00A62AD4`，該處可見 `Event` 目錄及 `qbase.lua`、`SceneList.xml`、`TutorialBase.lua`、`TutorialMain.lua` 項目。
- 本段並未推定所有 STP 版本皆使用同一結構，也尚未完整還原目錄 entry 之 offset/size 計算。

## 二、三個原生 Lua chunk：SHA256 與歷史 T16 資料完全匹配

| Event 內檔名 | XOR 解碼後的原 STP offset | bytes | SHA256 |
|---|---:|---:|---|
| TutorialBase.lua | 0xA27010 | 1416 | `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` |
| TutorialMain.lua | 0xA27810 | 5480 | `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` |
| qbase.lua | 0xA20810 | 11836 | `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3` |

三個 chunk 均以 `1B 4C 75 61 51 00 01 04 04 04 08 00` 開頭，是 **Lua 5.1 binary bytecode**，不是 Lua 原始文字。上述 offset/長度是本次檔案已驗證定位，不宣稱通用 STP 解包器已完成。可用下列程式再現三個 SHA：

```python
from pathlib import Path
from hashlib import sha256
src = Path("Event.stp").read_bytes()
assert src[:4] == b"STPD"
decoded = bytes(x ^ 0xFF for x in src)
for name, start, size in [
    ("TutorialBase.lua", 0xA27010, 1416),
    ("TutorialMain.lua", 0xA27810, 5480),
    ("qbase.lua", 0xA20810, 11836),
]:
    data = decoded[start:start+size]
    assert len(data) == size and data.startswith(b"\x1bLuaQ")
    print(name, len(data), sha256(data).hexdigest())
```

## 三、原生 Lua 靜態內容

TutorialBase.lua 字串區已核實：`CHECKPOINT_CATEGORY`、`PORTAL`、`SAVEPOINT`、`MARKET`、`TUTORIAL_POINT`、`CLIENT_CUSTOM`、`CHECKPOINT_STATUS`、`ST_CLOSE`、`ST_OPEN`、`ST_MAX`；`TUTORIAL_PROGRESS_NUMBER`、`TUTORIAL_KEYBOARD`、`TUTORIAL_MOUSE`、`TUTORIAL_CAMERA`、`TUTORIAL_LEADER_CHANGE`、`TUTORIAL_LC_DLG_OPENED`、`TUTORIAL_GOTO_NPC`、`TUTORIAL_EMPTY`、`TUTORIAL_PINKOHOUSE`、`TUTORIAL_STARTSCENARIO`、`TUTORIAL_CHANGEKEYTYPE`；`t_executeCoFunction`、`t_doCoTask`、`t_removeAllCoroutines`、`t_removeCoroutine`、`t_isCoroutineAlive`、`EndCutScene` 等。

TutorialMain.lua 字串區直接包含：`Tutorial_EntryPoint`、`Tutorial_Part1`、`Tutorial_Part2`、`GetTutorialState`、`InsertTutorialCheckPoint`、`SetCheckPointStatus`、`RequestStartScenario`、`IsScenarioEnded`、`g_TutoEmployCharQuery`、`PostUIMessage_EmployChar`。

T16-46 原稿已分析 TutorialMain Lua opcode/prototypes，Part2 的 `g_TutoEmployCharQuery` 兩組等待/清零迴圈；本段補上之前缺少的 **TutorialBase 原生全部 bytes**。只靠字串不可推斷方法呼叫順序，更不可宣稱首次登入分流或 S→C 協定已被證實。

## 四、AN／SV 更新與明確限制

- AN-04：`Event/TutorialBase.lua` 不再屬「需要使用者上傳」；本次 Event.stp 內已存在其完整位元組，且 SHA256 對上 T16 原稿。
- AN-03/AN-05：尚須從教學 Lua API 回追 Client BIN registration、state writer、教學入口條件。選角 request `0x42` 並不自動構成 S→C 回覆的配對證明。
- SV-04～SV-07：仍缺實際網路 handler、server decision、scene controller 與 ready/ack 的閉環。T07 原稿指明原生 `005F type6` 為 `CDuelField`；不可用測試修補 Tutorial 替代。
- `Event/SceneList.xml` 存在於本次 STP 目錄，暫不需再次向使用者索取；本段尚未還原其內容位移及 schema。
- 本段沒有執行 Client、沒有輸出或修改商用遊戲完整素材至 GitHub，僅交付可重現指標、雜湊、有限觀察與實作缺口。

## 五、下一段與整合清理

1. 逆向 STP 目錄 entry 和各檔 offset/size，直接提取並核對 SceneList.xml。
2. 針對 TutorialBase/TutorialMain 的 bytecode 做 RK 常數與 CFG 連接，回追 `Tutorial_EntryPoint` 與 scenario request 的 C++ gateway。
3. 再從 T03 receive handler、T07 場景選擇尋找有證據的首登觸發；不能將假設寫成官方 Server protocol。
4. 將資料交 T01 正式整合。**只有確認整合目標已吸收所有結論、SHA/offset/原稿 provenance 並可稽核後，才在整合目標刪除 `kr-extra-roy/`；此輪絕不提前刪。**

相關舊來源：`kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-41-KR-tutorial-Lua-provenance-and-entry.md` (main blob `46d93721bb6a343d83a00fa5cfe2283b33e16337`)；`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md` (main blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`)。
