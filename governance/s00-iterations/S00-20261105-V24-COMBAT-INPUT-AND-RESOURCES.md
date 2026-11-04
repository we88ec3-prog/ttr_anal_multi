# v24：普攻輸入回復、資源顯示與不可用技能移動

## 使用者觀察（GAME_RUNTIME_OBSERVATION）

v23廣場操控與村落NPC短卡已通過；使用者自行繼續Quest119副本後回報：普攻連技常要等動畫結束，伊希莉雅Z+C不發動。追加觀察：先用過X，後來X也不能施放；角色介面能量條仍滿，無法確認不足；行走中或先按不可用技能再行走會卡住，沒有實際施放就不應受影響。這是新的戰鬥範圍，不能撤銷或擴大前輪非戰鬥短卡。

現行v23 build08a99617bb84cbe0725debc5d20f1377e3a3685f，工作副本EXE SHA6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c；Client未修改。快照保存在本機v23-combat-complaint-snapshot，公開只放摘要／來源hash，不上傳raw連線。

## 時序與根因界線

- 副本raw input包含mask5；因此不是Z+C組合未辨識。兩次本機角色motion108成功出站，沒有109；現行各次X消耗35SP且無回復，推得100→65→30，低於Z+C需求80，後來也低於X需求35。是Server狀態／消耗政策推算，原journal沒有完整actor資源回覆，不能偽稱讀到Client記憶體或完整UI值。
- 普攻常見101→102間隔約0.35～0.40秒，之後再等到102名義片段1.25秒結束。0D先要求SkillState13，已查該state的collector gates可封鎖後續輸入；舊Server若沒有收到freshBasic，就等整段deadline才送idle。更錯誤地把最初held row在0.4秒內又當fresh輸入，自行續出第二段，隨後失去新row直到片段結束。合成測試一直餵row，先前沒涵蓋原生受gate而沉默的節奏。
- 原資料SkillActiveTable no30/LEVEL1 ACTIVEINFO sp=-35/mp=-30/cooltime60，no31 sp=-80/mp0/cooltime80；數值支持既有X35SP/30MP與Z+C80SP候選，並非要求為了成功而取消消耗。Skill49/50/52與active29/30/31的舊工作副本關聯沿歷史有限證據，不宣稱由skill ID直接等於active ID。
- 舊資源只發0000 normalized actor bar參數，沒有同步0034 typed absolute資源／RoleStore；這是滿能量顯示的具體缺失候選，實際HUD修正仍需真人。

## 本批修正方案

1. 普攻輸入回復deadline與名義動畫長度分離：沿用Server候選0.35秒／命中0.2秒，在回復點即使沒收到下一筆raw row也送idle重新開放原生輸入；有新候選則只消費一個buffer續段。原launch row不再自己重播為第二次輸入。名義片段長度保留作presentation／連段grace參考，不以加快動畫speed偽裝。
2. 仍保留0.4秒單格basic／latest-skill候選buffer、單次成本與CD；這些是Server選擇，不是官方queue容量、取消點或時間已還原。
3. 戰鬥發布owner-only012A可用性快照：明確支持的basic/X/Z+C、資源與ServerCD分開。其他未支持matrix key或不足資源者以場景不可用counter阻擋；合法CD用剩餘時間counter，Server到期重發。這使原生availability能清除不可用action候選並繼續移動report，並不是從原action-only反推physical held。
4. 若晚到的技能row被拒絕，Server只同步可用性／資源，不發0B停止、0C待機或估算座標回拉；等後續原生movement/neutral report解析位置生命週期。只有真正受理的cast或既有hurt才阻擋移動。queued skill拒絕回覆也不能被當作施放成功而漏掉input reopen。
5. 用0034的18B typed row同步最大／目前HP、MP、SP，並保留既有normalized actor bar，於角色綁定、消耗、受擊與拒絕回覆更新。type2/3/4與HP/MP/SP對應仍為工作副本candidate；其role字段/actor writer由4B3090 source形狀支持，HUD語意需本輪人測。新增0034固定56B的安全日誌白名單，可直接保留後續資源值，不提升任意payload日誌限制。
6. 保留消耗與不足檢查，不額外虛構SP自然回復／命中回復。補齊完整資源恢復與平衡屬既有戰鬥待辦，不能為了技能每次都能發動而偷偷補滿。

## 原生／資源來源範圍

既有T10 input-contract/action-buffer-state-machine/buffer-s2c證據為主。追加按已存在Git bulk的4B3090有界讀取：type2寫actor3BC/3C8及role40/34，type3寫3C0/3CC及44/38，type4寫3C4/3D0及48/3C；0x5C writer則只供部分基本欄，不能作資源current快照替代。沒有重新開原BIN／附加Client／MEF搜尋／新原件FULL-PASS。來源與指定XML member hashes另在evidence/20261105-v24-combat/。

## 工程驗證／下一輪

37項Category=HappyPath全部通過57秒，含「模擬原生SkillState期間不送row，idle重開後才送下一段」101～107、單次不憑舊row自續段、滿資源Z+C一次109扣80SP、消耗後X不可用時保留行走與放開／同方向恢復，以及原完整教學／廣場／村落／主線TCP/SQLite旅程。此不可用技能案例是使用者本次明確回報的正常操作重現，不執行其它暫緩錯誤／邊界／壓測套件。

第一次原37前的36項有一舊測試仍期待第二段名義動畫期間一直IsCasting，已改為回復點重開輸入；保留其後不憑舊tap重播及Z+C結束檢查。另一較早兩個skill-buffer案例在500ms才送已不在新basic鎖內，改為200ms命中後入buffer、350ms消費；沒有刪除舊功能或把紅燈隱藏。最後完整37項才是本批綠燈。

人測PENDING：指定Road191單人副本，先連點Z看連段是否不再等全片；再滿SP下Z+C一次，檢視SP應100→20；動作完成後X因不足不應施放，但移動＋X及之後行走不該卡。停在目前圖，不走出口。37個合成案例不等於實機手感／HUD／原件或正式主線驗收。

## 換版紀錄

Server main83172125f393273b635cc8d4d1ef559133b2907d已推送並啟用v24；只替換已核對的loopback v23 Host，先備份隔離SQLite。認證／旅程／劇情健康檢查正常，日誌丟棄0，EXE hash與v23相同。公開deployment.json保留元件hash與來源；路徑／PID／原始連線receipt留本機。已發Road191三項短卡，人測仍PENDING。
