# v23：展示頁沒有明確選角色時的廣場入口

v22使用者回覆「這次連廣場都無法進入」。本輪進場失敗保持GAME_RUNTIME_OBSERVATION，不回寫為通過，也不推成技能timer或村落Single候選已失敗。

本機journal明確只收一筆0042/4B，application `42 00 00 00`，未有43、世界初始化或技能timer出站。這輪卡在先前v21/v22共用的owned-role gate：0不在帳號擁有角色中，因此Server沒有回69。新控制策略尚未被執行，回退v21仍有同一gate。

已有來源4A3B80將兩個參數各一byte放入42；5F46D0按鈕路徑直接帶入page+C8，沒有1..9檢核；同頁list選擇事件在無child／選擇項時可得到index=-1再+1=0。因此0是此Client路徑可實際送到的值，不得靜默卡住。此為既有Git衍生碼與本輪raw觀察的有界交叉，不是官方Server語義FULL-PASS。

修正策略是Server選擇：只在已驗證登入、已存在saved-square resume、展示已送出、mode0/2及4B42成立時，role0改選已保存且owned的story role；沒有則取帳號既有最小role index。非0仍必須owned。無角色不建立role0，不創造擁有權，不修改Client、教學完成／主線／獎勵資料。明確選角仍沿用原路。自動F5仍不進廣場。

34項HappyPath再次通過49秒；在實際SQLite/session正向旅程增加展示未選角→role0→69/43→owned Soma1進廣場檢核，既有明確選1／2／3正向案例保留。其他暫緩套件未執行。

本輪v22原journal與status/hash已保存於本機v22-entry-failure-snapshot；不公開raw連線或帳號資料。v23將保留v22的非戰鬥availability／TownSingle整批修正，先解展示入口阻塞再驗證操控與NPC。實機PENDING，不能把合成34項當成方向＋Z或NPC已修好。

## v23本機發行

2026-11-05 00:35:16 +08:00核對v22 PID38440／精確路徑後替換，SQLite一致性備份驗證成功。v23 source08a99617bb84cbe0725debc5d20f1377e3a3685f，Host PID36128；Host DLLbad0d7987a92aad9f3836e2152e8c76875af7bebbbe02a1b8dae227e90fd78b4，Network DLLdfc93749c8e4583c385655969f458504b96bf16546a7423d6c09b3e2bdd6a392。story content與Client都不改。服務已啟動，34正向測試通過49秒；已發v23短卡取代v22，真人PENDING。
