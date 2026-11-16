# 全角色技能與V狀態的定向補證

基準 main b2d6a36ba2c87d58fd033c6752cfa784d977ab8a。這是正式RR-0011／0012的工作資料，不是另一本狀態台帳。使用者已要求完成全角色技能；無新分支，直接main，保留歷史原稿，T01既有退回規則仍適用。

## 已可用，禁止重做

- 243個distinct六鍵技能／945個位置、189個角色配置；156動畫候選、87未開。完整清單：governance/client-variants/20261107-all-skills-unlock/skill-opening-status-v35.json。
- 1448個Practice等級成本映射、攻擊係數／需求及608個Talent ScriptLevel資料：governance/client-variants/20261107-skill-levels/。已存在，不能以重解耗量當補上動作。
- 87項拆成72新matrix、13舊命名橋、2非等價多Basis。舊Practice/ActiveInfo、六份輔助schema、32份指定EFF均未找到可直接動作繼承的明確欄位。參見20261107-all-skills-unlock、20261107-v36-emission/effect-bridge-audit。
- cache+4是learned level費用路徑、+6為ScriptLevel MAX更新的有界證據；不是Skill→Motion橋。原件0D已顯式攜帶motion，不能把active整數當motion。
- 108支技能影片只有標題／連結索引，105項可按role＋台版名稱連到catalog，40項為未開。僅索瑪電火球少量畫面已看，其餘未審影片不當證據。不得以影片名稱直接推ID或命中數。
- v37 CForceState12的原生身份／動畫19／操作旗標已補證；不重做此身份定位。原生MEF仍無格式，不重新全庫掃檔。

## RR-0011：先交一條可用映射，再擴展

主責KR T11，優先13命名橋或2多Basis家族。選一項具確切active／Practice／名稱的例子，尋找可獨立證明的active→動作或資源alias，或明確的多Basis選擇／轉段規則。逐項提供來源SHA、字節／欄位、前後消費者及適用條件。名稱近似、同按鍵、泛用101起跳、連播所有Basis都不合格。
若Client僅接收Server給定motion，應提交精確受查界線及哪部分必須由Server設計，不以無限函式搜尋假稱能找出官方後端映射。已有陰性範圍不再重跑，只有明確新線索才追加。
不得修改／啟動／附加Client。需要影片視覺比對時只選已索引精確單技能，先說明同版與動作識別依據；不向上班中的使用者丟無時間碼影片作業。原始BIN／資源不提交Git。

## RR-0012：兩次短V與長V不可只用Server畫面互證

原始SkillExplain 67明說按一次集氣，69明說集氣中再按一次進第二次集氣，68明說保持氣按鈕進氣散發。故二段集氣文字存在，不只是使用者印象。
但現行Server ShortCharge兩次最後選row2、BeginHeldV也選row2；人測相同圖示只證實這個實作，不證明官方同組。原始TC逐技能氣散發條件命中48項，其中47位於投影row2，role9 active3049於row1保留差異。
需要定向核對：原始KR/TC矩陣完整四row及命名／有效欄位、67/68/69各來源的指向關係、actor+3E8如何進入實際row索引、原生可觀察的狀態更新／顯示入口，以及有無明確證據第二次短V和長V應同組。區分文字事實、原生Client索引、官方Server未知與測試場政策。
新界線：546100@5462B4從actor+3E8讀row並push入54F270，54F2F2取[ebp+C]入AL再呼叫81A8E0；本次只作定位，需原件指令及ABI完整核對才升級結論。5480E0、549980、549C60另有caller，不用其中一條覆蓋全部UI。
ForceState12本身不改charge tier。不要把FSM12、motion19、active68、row2混成同一ID域。缺官方回覆不能捏造3階／新增不存在的技能列。

## 回報

狀態只寫research/requests/index.json，經dispatch.py認領／提交；本文件不自動喚醒Web。先回一份最小可用報告，附相對路徑及Git blob，T01驗來源、S00決定可採用範圍。不存在新映射就明列未完成，不填Enabled=true以湊數。

## RR-0012後續限定補證（仍未結案）

新增 governance/client-variants/20261108-v-row-consumers/：actor+3E8→54F270 arg2→81A8E0 row的選定ABI與KR/TC126組矩陣已核對。後續不要重做這些；仍需釐清官方67/68/69的回覆／狀態政策，而非把當前Server row2畫面當證據。長V與release的0xC0本來略過普通row可用查詢，Server不應只因row2/col8為0拒絕此操作。
