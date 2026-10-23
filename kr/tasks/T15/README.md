# T15 遊玩資料保存與恢復

狀態：bounded-review-handoff；負責人未認領。

## 範圍

跨登入需要保存的資料與恢復順序；不宣稱還原官方後端

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：本機SQLite帳號任務道具是替代；原生profile清理呼叫不是遊戲存檔
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。本機SQLite帳號任務道具是替代；原生profile清理呼叫不是遊戲存檔
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：本機SQLite持久化只證明目前替代後端的行為，不是原版伺服器存檔格式。

## 依賴、接續與驗收

依賴：T02, T03, T04。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [kr-persistence-20261023/indirect-load-followup.json](../../../kr/evidence/00256315fc52e738582a7a64f066c39ed4bbe99295669dfe59c38d92d3118479.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/04-xref-fbab8c.json](../../../kr/evidence/07f93cc17b3475d34eb107dedae751443ce8a1921fc59cbd39a7710783e8f1f2.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/10-xref-fbabd4.json](../../../kr/evidence/0d176ddfdd67a743ba7ce4f61febb1882519c981752c12a65e41a80d5a6f171d.txt)
- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [kr-persistence-20261023/mcp-evidence/16-owner-6dada8.json](../../../kr/evidence/132e7827927f947be065697005f4f5d4c5a1271587a4e1cb9db323985027f7bf.txt)
- [kr-persistence-20261023/semantic-records.json](../../../kr/evidence/13439747a27c0e29869f23fba82e5a7e7397ed86ed24eab32e1e680eae3a3bfb.txt)
- [kr-persistence-20261023/mcp-evidence/03-xrefs-GetPrivateProfileStringA.json](../../../kr/evidence/14ed9c8f8bcb8c31d723fb885b73dc59b396704f667fcd4ee1edd0c5720582c3.txt)
- [kr-persistence-20261023/artifact-manifest.json](../../../kr/evidence/150f394ab912853e3e3e96076236d1ec8b1b21db06bc1106c9baf7473a519a42.txt)
- [kr-persistence-20261023/analyst-records.json](../../../unclassified/evidence/15cd66cc0d8b718f609732879a6a2e78b622e79ff05835f6d3df5f7243431f5d.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/07-xref-fbabb0.json](../../../kr/evidence/18600827e0054ba82f3b7393a3c115badb22feb92e76a8595466b14d5fd09e1a.txt)
- [kr-persistence-20261023/region-evidence.json](../../../kr/evidence/1aef869aff4583cf87d60b74e97640dd4e6c12af23ff37c9a671c2fc0f3e671d.txt)
- [kr-persistence-20261023/followup/mcp-evidence/04-function-440850.json](../../../kr/evidence/1ca66a85c135b005aa23dfcc7e32ee0067c0d65a99dab10a4314c62270022005.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/03-xref-fbab80.json](../../../kr/evidence/1e5a1234092c3c90029c9ee758a7d93665cf163bf6a21528b17fb9e2ed624ea3.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/06-xref-fbaba4.json](../../../kr/evidence/2733e0243de013ce2b3d6982bdecb4a34edaad401f8cc37aa0d948fa6e79ec23.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/12-xref-fbabec.json](../../../kr/evidence/2a2ff58588ba4fe32c127793eb625e1d3e02e9ee6d413e88b12f185fd36e746e.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [kr-persistence-20261023/followup/mcp-evidence/03-function-6edd50.json](../../../kr/evidence/2ee1d6406a1235aa37019e3ed81b503d50fbac5237105d99effdc28bc1daf709.txt)
- [MAINLINE-FLOW.md](../../../unclassified/evidence/3a6376c5d84b4f03edc301d4467746680dfa448efb1df1eb5d2c20e278a20690.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/11-xref-fbabe0.json](../../../kr/evidence/3b6da4d76e03d1ae2ada05b5272dd9bdaa91b4097ab2cb2e34113df1e4a584b7.txt)
- [kr-persistence-20261023/progress.json](../../../kr/evidence/40fec0cf5c0f883964e225e89a438bf69ddc3658b1197e7b9e4846ff65b264e7.txt)
- [kr-persistence-20261023/verify_delivery.py](../../../kr/evidence/421d254420e954eacffb7c6cbb9a7c49b24d0a8cfff0ac2e6752b32742d81dcd.txt)
- [kr-persistence-20261023/create_semantics.py](../../../unclassified/evidence/452757a407c0451e77494b7eb9c8e829272ecaab2da77968163174d09f31827e.txt)
- [kr-persistence-20261023/mcp-evidence/22-function-4405c0.json](../../../kr/evidence/488f687c14e706494b5fe5fa5471d988bc661c458f881064dd35378f100ff0d7.txt)
- [kr-persistence-20261023/build_contexts.py](../../../unclassified/evidence/49348e26f4819d5f58b42d616c50da265c23309d3da146e81b3d4b9fbb6c3700.txt)
- [kr-persistence-20261023/followup/mcp-evidence/06-export.json](../../../unclassified/evidence/4caf8747787875bea267be7e9f8b395eadd0bdfe757ded9f4d8850ab27a61210.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [kr-persistence-20261023/mcp-evidence/14-owner-4406b8.json](../../../kr/evidence/52a799545f3ae3eb206365ebb111a25641f3dabcaf291a89812f4f090c4ac090.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [kr-persistence-20261023/mcp-evidence/15-instruction-6dada8.json](../../../kr/evidence/550e40f7614d6d4e75f4f81afcd2c9a6d15d3a38836d90bd55b1d4827c68a41a.txt)
- [native-index/actor-model-and-state-tick-full.txt](../../../unclassified/evidence/55f98c310a0a6a3381e0511d2953997502d3fd37f426524c1af291118d111933.txt)
- [kr-persistence-20261023/verify_records.py](../../../kr/evidence/56a4a7ae64cd109803d86db2693ffedda697f91a55fb79ba942f942921c86221.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [kr-persistence-20261023/mcp-evidence/18-owner-6ede39.json](../../../kr/evidence/60dd77fb0881ed95def8cbacaf49fe4a040ef996f541aa580b878f6561ecfce7.txt)
- [kr-persistence-20261023/finalize_delivery.py](../../../kr/evidence/6216aa7bdd1b16f411a5f2d07c14044b25f3dbd295e95c9a2464b6047bf04446.txt)
- [kr-persistence-20261023/extract_frame_table.py](../../../kr/evidence/64a9b6b5ce02788a6c66e2149a2d6a54f443ea1175f0b94720345063b0cfaa98.txt)
- [kr-persistence-20261023/frame-consumer-plan.json](../../../unclassified/evidence/69edc7777bdc2e37687903ef643ff3969d63f6429a2b65590d9a86a4d5c3d48e.txt)
- [kr-persistence-20261023/delivery-validation.json](../../../kr/evidence/6a3b178652ee40f1da87de894ab8e718acfb7fa7256910e70cb328896dc6b0b9.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [kr-persistence-20261023/framecontrol-table.json](../../../kr/evidence/6e21430a8d3595ff357791f8de9757dcce2496ad60a5790c25dbe143db0d8ed8.txt)
- [SQLITE-ACCOUNTS.md](../../../unclassified/evidence/718cd3505c5c3777e22b034715e97c6b91487b76b31052f000bbb1f8367f8319.txt)
- [kr-persistence-20261023/followup/mcp-evidence/01-session-start.json](../../../unclassified/evidence/71be5c621604e2523fa7cf49ca1fa41623fc0554000b809e257d126332233922.txt)
- [kr-persistence-20261023/closeout.json](../../../kr/evidence/72e0b76eb2ee4da5935ff7b6aa9e6d24240ad7d786b7fac091395c570e60285d.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/05-xref-fbab98.json](../../../kr/evidence/74b594ae75539efaac77d30704305284a1978ce2b5b7fd9904f7fbcf9882e65c.txt)
- [kr-persistence-20261023/workbench/mcp-evidence/11-function-7a87d0.json](../../../kr/evidence/752cd473b7fbf2a24fdb62316dbb9598182b970f14dbc65de84e0ab7f8cdcc29.txt)
- [kr-persistence-20261023/followup/mcp-evidence/07-close.json](../../../unclassified/evidence/76ab24ca971a4e9b3fff61163870d810782d715f8d7ad4e50cdaca3f477b0788.txt)
- [kr-persistence-20261023/followup/mcp-evidence/05-function-7d2170.json](../../../kr/evidence/77a44c2d488546257f1279d6ce49b25495199b8062bc46ff6f17f2acc5e2647f.txt)
- [kr-persistence-20261023/mcp-evidence/21-function-6f0100.json](../../../kr/evidence/7c84b5d82653748ac2b6c5b86230b3d0b80c8b0ea7d536227f4e143bcfd277f5.txt)
- [kr-persistence-20261023/mcp-evidence/10-owner-6f0152.json](../../../kr/evidence/82dd4b4f4194ff8d511e734695532ace973906c85502524faec2399fd344f81a.txt)
- [kr-persistence-20261023/resumption-session.json](../../../unclassified/evidence/83e3521508f3889659df65a917ff8c6bf4cec6ff797d743440363f4cf60341d4.txt)
- [kr-persistence-20261023/mcp-evidence/23-function-6ede20.json](../../../kr/evidence/850a391156d4ff902a772b6baf6aad61f1bea316c0d2c1cb10c672031f300047.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/02-open.json](../../../kr/evidence/9795c0be73f9b83fe8878c9b0bd64a876b41e05fe1ae97e1e7451552946c04c7.txt)
- [plaza_npcs.py](../../../kr/evidence/9a9e396000323e0b7359afeb933922ce3ff40b50a4dedd982ed752b2fe228e49.txt)
- [kr-persistence-20261023/mcp-evidence/24-export.json](../../../unclassified/evidence/a0e9c8678a3850148f13787f355ea4f9ed52095755173c678da35ac4f0d146ba.txt)
- [kr-persistence-20261023/mcp-evidence/12-xrefs-WritePrivateProfileStringA.json](../../../kr/evidence/a1b036b73afbca3eec282cd7eb353905eca3fb68cdd1680d9cafc30f5eb99413.txt)
- [kr-persistence-20261023/validation.json](../../../kr/evidence/a748263f55082027021f46f607a76c273999bd10f5b358fa983814d433ec9dab.txt)
- [kr-persistence-20261023/mcp-evidence/04-instruction-6edeb0.json](../../../kr/evidence/af77180d563063093a6380413ee78ffe423cfe9e73950fc6233cd078641e8ac8.txt)
- [kr-persistence-20261023/build_regions.py](../../../kr/evidence/af88181eebe87af542184b2fbf97a8a6610f0bf9cbd2fc4b5a022118d631fde5.txt)
- [kr-persistence-20261023/mcp-evidence/07-instruction-6dad61.json](../../../kr/evidence/b284ec290f2b96b81911f2b6d46cdb2ea6e77f705d81f330d6982a275cecaa68.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [kr-persistence-20261023/battle-frame-contexts.json](../../../kr/evidence/ba6c120c80e55bf2d1f5bb2fcdd46c2ac320d94181aa0211f132abe7f052c94f.txt)
- [kr-persistence-20261023/mcp-evidence/19-function-6ede70.json](../../../kr/evidence/bcbcb0a39c95a53f7e87f1fe51ec36af677ffda483458f632fd2c5a4722457d8.txt)
- [kr-persistence-20261023/workbench/mcp-evidence/14-function-7a5c50.json](../../../kr/evidence/c12373d7e96ccc0227f59c7778dfdbb344fd84159d0e265ade0e4605b79b27f7.txt)
- [kr-persistence-20261023/input-provenance.json](../../../unclassified/evidence/c2e838e821524c0bc0d71b15e08d31015d75b927d8d75f32a9c53da344622a4b.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/13-export.json](../../../unclassified/evidence/c35168b683aca1934500802dfa790ab8ec3c62ca4e51e3c6720ff97881683374.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/14-close.json](../../../unclassified/evidence/c3790005092e881bf89ae71629ed572d373dc580af64f7e57f2f064a3e378cbc.txt)
- [kr-persistence-20261023/mcp-evidence/20-function-6dacd0.json](../../../kr/evidence/c62593016bc97a0ef96023019d33ce886c120a108a7cca27a0a2dbbf7f35bd90.txt)
- [kr-persistence-20261023/mcp-evidence/25-close.json](../../../unclassified/evidence/c79be18ca9e64c4ba9e513a1bb3130e47f81b67dea3a4a6cb45f721343f09030.txt)
- [kr-persistence-20261023/mcp-evidence/05-owner-6edeb0.json](../../../kr/evidence/c93dd0fa2f3c7b34906e7025b179734e9879437ca3131f5476650fdac44b2e73.txt)
- [kr-persistence-20261023/mcp-evidence/06-xrefs-GetPrivateProfileIntA.json](../../../kr/evidence/cb454cc1ee6a1cf9fb022177fa713d32aa83f9b4355a66d1c458a8b6f86298e4.txt)
- [kr-persistence-20261023/mcp-evidence/09-instruction-6f0152.json](../../../kr/evidence/cbb80fdf4713ce51a841c4837dbaebb4efe38d6133497ad0331f4f56c9d56d4d.txt)
- [kr-persistence-20261023/REPORT.md](../../../kr/evidence/cf7c2ed611795331d47c42b3edc4cc7b394968c0ae27546a4cf2e95a80cb2e5e.txt)
- [kr-persistence-20261023/unknowns.json](../../../kr/evidence/cfaa558f2fb5efa651e6a745dba22d0fc768f13b666c5a2068651107802a86d4.txt)
- [kr-persistence-20261023/mcp-evidence/17-instruction-6ede39.json](../../../kr/evidence/d2f597d2aa4b88ef30a08091faec3cc07e2a20078585dd8207ce50c3f24670ef.txt)
- [kr-persistence-20261023/workbench/mcp-evidence/12-function-7d28e0.json](../../../kr/evidence/d39d9622828a44ac1ad2044624a3c58d6068ca5ec3f742788cb568af752eb7a5.txt)
- [kr-persistence-20261023/followup-plan.json](../../../unclassified/evidence/d4bc12f66f13a1c893bb8302f93a159adb343dfff5c92b814fbe5406ba071b1a.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/08-xref-fbabbc.json](../../../kr/evidence/dd256d66384794d2efbfec1867c0f66587dafbdf1880796ebc19e884ab44fdb7.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/09-xref-fbabc8.json](../../../kr/evidence/e570cfb230d09663b5df1fe6e0d9aa6ce1a269172409af2597ca4a9024b5cbb6.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [kr-persistence-20261023/mcp-evidence/11-instruction-7d22f5.json](../../../kr/evidence/eb0ac5c0a035f534c00ec481cf04f912918cdcb84f6911c2573e1c6774cfc3cf.txt)
- [kr-persistence-20261023/build_records.py](../../../kr/evidence/eb4f93592f898091df040f272960a1c0575c86e0e56be5bd7aa2a01ef8b63e07.txt)
- [kr-persistence-20261023/import-seeds.json](../../../kr/evidence/ed9aa42617c39f1a59ca22fa8b9e4f051f32f025741175445fe71b5c549ea68a.txt)
- [kr-persistence-20261023/import-call-discovery.json](../../../kr/evidence/edd5d51052463b856648c0c92e8eaaa05e51dd50c0a178b99a86c42a367c2372.txt)
- [kr-persistence-20261023/frame-consumers/mcp-evidence/01-session-start.json](../../../unclassified/evidence/f0db5c3d4e918033bf197138a2810299dda098aa480feedfc72f4f132ab56665.txt)
- [kr-persistence-20261023/mcp-evidence/13-instruction-4406b8.json](../../../kr/evidence/f3f98eac0a609e18e9b168f9b8535b85ab12fa6f28171a2e3ddc350d1e2a92dd.txt)
- [kr-persistence-20261023/mcp-evidence/01-session-start.json](../../../unclassified/evidence/f5ba2e1e1df542c800b8190ead51444b61233d64877e40d3bc6fe54fe9ae62d7.txt)
- [kr-persistence-20261023/mcp-evidence/08-owner-6dad61.json](../../../kr/evidence/f7703561d42d8944ae34927e830d845a5fe9eefc18157f04430349bdce6f267c.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
