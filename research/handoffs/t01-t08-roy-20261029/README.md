# T01：t08/roy/chatgpt-web 新通道整合

2026-10-29，T01 integrator。使用者指定整合 `t08/roy/chatgpt-web`；先取得最新main再依[新T01方法](../../../governance/t01-integration-workflow.md)處理。基準main：`610a822b15346c9e0b69edd4e104c2076f2b59ac`；來源head：`5816884ef481995a9fe0d92277b1dde06aff32e8`。

**本分支138份T08原稿的來源／有限主張整合完成，剩餘0份。** 這些原稿原已在main完整保存，本次沒有重複匯入或merge整個分支。分支額外的`03-PROJECT-T08-INSTRUCTIONS.md`未作為main政策帶入。原文與blob皆未改。

## 實際整合差額

開始時138份中，123份已在新SRC台帳，只有158／177／197的3份完成CONFLICT_CHECKED；120份只有REGISTERED，另15份早期／090／reaudit／知識彙編尚未在此新台帳登錄。

- 已核對138份分支／main／工作檔的blob及SHA256完全一致；補登15份為SRC-0348～SRC-0362，保留既有歷史bounded/source-level審核metadata，不倒寫新判決。[來源清單](sources.json)、[R0紀錄](r0-actions.json)。
- 42份early、48份middle、48份late的實際narrative完成有限主張／限制／已知衝突查對。135份由REGISTERED進入CONFLICT_CHECKED，既有3份及其原有正式關聯保持。
- 61個功能提案群經整合者查閱後，4組跨區相同功能問題歸併、2組引用既有canonical；新增55項主張：**37 PARTIAL、12 UNKNOWN、6沿用既有確證的REFUTED**。另建立233筆有子範圍／品質不繼承標記的追加來源引用。沒有新NATIVE_VERIFIED或全文FULL-PASS。
- 全庫新台帳為362個SRC、88個CLM。原318版中的待萃取由314降至**194份**，歷史全文通過仍3／318、未通過315，兩軸不互相覆寫。
- 未新增作者退回、未把既有NEEDS_FIX／RESOLVED重設，也未改Task owner／task.json／catalog、RR／SPEC／GAP／ADR／TEST或S00決議。SPEC_CONSUMABLE及S00用途接受均為0。

[功能主張與歸併表](claim-map.md)｜[逐來源處置及行號](source-dispositions.json)｜[整合動作](actions.json)｜[Server影響交接](server-impact.md)｜[驗證結果](validation.json)

## 原文閱讀與來源子範圍

| 區段 | 來源數 | 個別提案 | 有限內容 |
| --- | ---: | --- | --- |
| 早期、79～105（含090／105雙稿、reaudit及KB） | 42 | [early](early/README.md)、[proposal](early/proposal.json) | component／actor介面、lookup、wrapper／resource、Provider／Binding、幾何係數及22桶producer |
| 106～152（含129雙稿） | 48 | [middle](middle/README.md)、[proposal](middle/proposal.json) | bucket／callback／owner、plane更新、B queue／Host，及24份映射失敗來源隔離 |
| 153～200 | 48 | [late](late/README.md)、[proposal](late/proposal.json) | actor索引與移除、virtual預清理／deleting wrapper、pool／mode／計數與精確反證；保留3個既有正式scope |

行號及原文摘錄綁定各自SHA／blob。作者說「已確認」不是T01此次品質認證；ASM／示意碼、工具執行史與研究輪次保留原文，本次不宣稱重做全部機器碼／CFG。以已歸因內容萃取有界導航，不以檔名或hash生成語意。完成身份、有限用途及已知衝突後，依R1停止條件停止一般重驗。

## 必須保留的衝突及更正

1. **24個映射FAILED版本**是129-resolved與130～152，不只是140～152。這些精確blob只連UNKNOWN／修復導航；錯標VA衍生的caller、owner closure及ABI斷言不作正面原生依據。129-static另為不同來源。舊flat文字區與PE的0x400差異按既有[映射裁決](../../../shared/integrations/T01-20261029-semantic-review/t08-early/mapping-reviews.json)處理，不全量平移資料節或vtable。
2. **owner／更新未知**：早稿沒直接讀global不證明不同實例，相同stride不證明同一；129後稿聲稱閉合因上述FAILED不能擇新覆舊。089／090／092當時未見resource+20 reader，不得覆蓋093後續reader導航；102～105的writer未知不能解作現在不存在writer，118～120後稿仍只PARTIAL。外層觸發、頻率、plane物理意義及B entry→22桶因果仍UNKNOWN。
3. **Provider與容器**：096／097的0x8C manager不能直接等同heap多型Provider，098～100的ID／地址對內容／0xB4 Provider更正另追。heap名稱索引的hash／bucket／list不能稱有序樹；相鄰內嵌樹不連帶撤銷。wrapper+2C中的resource、wrapper自身同offset欄位及Binding介面分層。
4. **既有精確REFUTED**：153／157的key slot對out-iterator混淆、155錯位碼塊、173可變ECX說法、183將hash/list稱樹、187指令座標、196錯分主／次樹，僅沿用既有反證。173／196的退回已由177／197結案，舊稿FAILED不變；本批不重新開相同問題。
5. **已撤銷拒因與歧義**：82EF00無equality gate的舊拒因維持撤銷；200「索引」可指key域或容器，仍以PARTIAL／澄清處置，不新增確證錯誤。158 getter、177 mode與197次級移除的既有CLM-CLIENT-0001～0003只在原精確scope使用。新增來源不借其NATIVE_VERIFIED；154／156舊converter假設僅作REFUTED歷史關聯。

所有衝突保留[Task README既有退回](../../../kr/tasks/T08/README.md)與各區proposal中的精確版本／引用。本批未採用本機continuation-03尚未提交的candidate FULL_PASS，也未新增REA／BIN深驗或執行目標。

## S00用途與剩餘工作

這些是Client資料結構、生命週期、幾何／調度及原稿錯誤的有限導航；沒有已證的現行Phase-B SPEC直接依賴，故`affected_spec_ids=[]`並明示等待S00具體用途。Task的「0007」研究標籤不等於已驗wire opcode，不能由Client helper反推Server出生時機、波次、AI／權威或完整任務規則。

當前T01收件箱無SUBMITTED／IN_REVIEW請求；原RR仍QUEUED，不代認領或結案，也不造S00審查決議。S00遇到具體協定／設計阻塞時再定向派R2/R3，未通過的必要欄位／時序仍UNKNOWN。**本分支新通道剩0份；原318版待萃取194份。**

發布前main先後新增S00 Iteration06／07，本工作分支已同步並以`fa3174747`為發布基準，來源快照與舊歷史比較仍固定在上述初始基準。驗證依最新main的12組CI門檻（含S00決議、唯讀Phase-B worklist及submission preflight檢查），另核138份blob、來源行號、功能引用、既有品質／歷史及Task研究正文保持。機械與離線合成檢查不代表原生語意、Client／Server相容性或遊玩完成。
