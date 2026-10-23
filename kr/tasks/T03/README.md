# T03 登入與角色選擇

狀態：bounded-review-handoff；負責人未認領。

## 範圍

登入選服選角與連線切換；不決定角色世界內初值

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：官方驗證規則與完整登入順序缺失；本機帳號規則是替代實作
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。官方驗證規則與完整登入順序缺失；本機帳號規則是替代實作
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：T02。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [16-account-character-roster.md](../../../unclassified/evidence/292f798fe04079370dd65d31a03b7cca5a14a84a9524da3903a25d6ff6c10047.txt)
- [09-login-protocol.md](../../../unclassified/evidence/2b1f41d382423fd4cfd24102920730e0af4ccb211b11877a4f72f76faf5692f7.txt)
- [native-index/login-module-command-parser.txt](../../../unclassified/evidence/2cf621bbf71d306f38b21b2bd70fd82a31b92fcebff95912c21cd47c3fd8c951.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [audit_login_module_command_line.py](../../../kr/evidence/31a96a34214d44d09f2c5c6d16066da2bea5a9312a5d7061da19c419af1758a6.txt)
- [native-index/login-module-endpoint-initializer.txt](../../../unclassified/evidence/485041721397e0db11328939517849f8b0755166a326d96881b34284022046de.txt)
- [native-index/login-module-auth-command-000f.txt](../../../unclassified/evidence/4cb0b42cbee49f5e05fff20c2ff5f5eca257c24c0fbe060371bc59ec0e1177e8.txt)
- [06-runtime-login-fix.md](../../../unclassified/evidence/4d4a53d916b03a6766d33001449ed765af88a1cd1088471dc5bd2b4c6e0c72db.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [native-index/login-module-gsp-constructor.txt](../../../unclassified/evidence/5132ac5f0b3be3b23c6873ee0ad08435d0e66c438f7d8929ad457548ea92905c.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [native-index/login-module-auth-dispatch.txt](../../../unclassified/evidence/9e426b693565220e79df086be2546a876b57de7e42fee9986121d10f941e8d5b.txt)
- [LOGIN-MODULE-COMMAND-LINE-AND-AUTH.md](../../../kr/evidence/a888e1ad136c9548255924ebd455847b05f6e9ce5e560f8a46d00b2b0826cde9.txt)
- [native-index/login-module-singleton-getter.txt](../../../unclassified/evidence/b110e18c90fc68d61fb96a5c8bb7b97bd1436cd507800942d52a2e0a542e9af0.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [native-index/login-module-ip-formatter.txt](../../../unclassified/evidence/c2348e529f4b85b2db1aaa48bc48bbdfe0e252369c2900412f460532a7af5ef9.txt)
- [native-index/login-module-auth-command-00e8.txt](../../../unclassified/evidence/d4184e747c61654be90f36a379cb745f17e882bcf67fdcd266156acb53a84360.txt)
- [native-index/login-module-command-audit.json](../../../kr/evidence/e24230acf525e80f0bc15af6b510eab1aed53b21e7131790c1ca0fc5229d7230.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
