# 原版客戶端驗收前需排除的舊修補依賴（待整合）

這是歷史 AI／診斷腳本的來源審核，不是新的原生規則；本輪只讀取文件與程式文字，沒有執行 patch generator、遊戲或目標 API。

| 來源／位置 | 腳本明列行為 | 封包恢復路線的缺口 |
|---|---|---|
| `anal/make_character_probe.py`，`0x67355B` 呼叫攔截 | 對缺角色描述 selector 1、3 直接回報成功 | 原版 UI 所需角色描述與初始化必須另核對；不能以略過查詢證明回應完整。依賴 T02／T04 的資料契約。 |
| 同腳本 `--plaza`，`0x417FB0` | 商城分類負數時略過 `OnShow`；腳本自己標明 catalog 仍未初始化 | 核對商城／UI 初值與相應資料流程。不能直接推「發空清單」即可修復，也不能以此診斷繞過當成 Windows 相容性修復。 |
| 同腳本 `--plaza`，`0x50954F` | 將背包建構後 `+0xCA0/+0xCA4` 尾端計數器清零；來源註明等待真正 inventory packets | 原版背包資料／初值及先後關係仍需其主責任務核對。這是腳本對缺資料的補值，不是新驗收的原生封包 schema。 |
| `anal/make_tutorial_transition_probe.py`，`0x4B99C0` | 攔截場景分支，在 TUTO 路徑重建教學控制器等 | 與原版 `005F type 6 → CDuelField` 不同；兩村 packet-only 路線不能沿用修補的場景／控制結果。依賴 T07。 |
| `make_character_probe.py` 的 `--height-lift`／`--repair-zero-scale` 選項 | 腳本宣告診斷用高度偏移／零縮放修補 | 不納入兩村原版 spawn、bounds 或模型完整性證據；本輪沒有新增審核其整段實作。 |

`anal/19-plaza-cash-shop-crash.md` 記錄的是帶有 missing-character guard 等修補的測試副本；`anal/20-square-load-pending.md` 也明言當時未提供玩家／裝備／位置等世界初始化，不能宣稱可玩。歷史 runtime 敘述留作問題線索，不等於本輪重現或未修改原件的驗收。

腳本讀取 `Tartaros.local.fixed.exe` 作為基底，其完整修改血緣尚未在本輪核對。名稱 `fixed`、過去畫面、版本日期，都不能替代原始 BIN SHA 與每項差異分類。

後續順序：先補伺服器資料契約與跨任務依賴，再依使用者明確允許的方式驗收。不要先套用上述修補以繞過缺資料；若另有必要主程式調整，遵循[全任務政策](../../shared/CLIENT-MODIFICATION-POLICY.md)提出具體方案，原始證據保持唯讀。
