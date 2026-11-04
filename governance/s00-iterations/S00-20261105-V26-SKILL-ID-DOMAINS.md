# v26：修正Practice ID與active skill timer鍵混用

## GAME_RUNTIME_OBSERVATION

v25人測退回：使用者未注意廣場，進副本後快捷列仍整排空白。Server191aa20e29be4f73022faf162fa66ae79ae3c6dd，EXE SHA6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c未變。38項合成通過不證明UI；v25只改先後順序未解決本次現象，原戰鬥三項短卡仍未完成。

本機v25-empty-shortcuts-snapshot保留status/input/outbound/story與完整gameplay journal。Road191後明確記錄126=260104310001003200010034000100、127=2701040001310001003200010034000100、12C=2C0104000000000000，Server完成出站不等於Client消費。這排除本輪「Server沒有發三包」的說法，但尚未證明快捷列空白唯一成因。

## 確定的ID域錯誤

原始與工作Table.stp的7個指定member逐一SHA相同。唯讀既有解包器讀指定技能／矩陣XML；不掃MEF、不修改Client、不上傳原始資源或ZIP。公開只保存member來源hash與短欄位投影。

- Practice49/50/52，Char4，Level1的SkillLevel modifiers分別指向active29/30/31。
- CharacterMatrices Char4/Matrix0/Tier0，column1/2/5分別29/30/31，恰為Z/X/Z+C availability查詢。49/50/52是學習／預設項目，不能充當其timer key。
- 4E46D0/4E48A0接收Practice rows，41D5F0取得其等級modifier，再由825FA0彙成skill cache。545E20/54F270使用active matrix skill鍵。既有Git偽碼有界引用，不升級新的原件FULL-PASS。
- v24/v25 CombatAvailability錯把49/50/52當支持的timer keys，於滿資源也把真正29/30/31全部設為int.MaxValue不可用。這是可確定的Server缺陷；原先只驗Practice IDs的測試漏掉了原生matrix域。學習封包49/50/52本身不應改成29/30/31。

## 修正範圍

建立明確PracticeId/ActiveSkillId配對來源：Skills序列化取PracticeId；availability取ActiveSkillId。伊希莉雅放行29/30/31；資源不足、CD時只對正確active鍵更新。保留原消耗、資源同步、input reopen、v25發布順序與固定診斷。廣場原本依所有matrix keys設互動限制，沒有以Practice域替代，不回退已通過的廣場操控。

現行角色3候選Practice33/35/36對應active20/24/22，timer也按該配對修正；但原生Char3 column2是21，舊X選用Practice35而非34另有內容不一致。本輪不偷偷換技能／motion，列入既有SFD-0012並保留未驗收，不能聲稱所有角色技能皆已修復。角色1配對同號，未受本次轉換影響。

新增正常案例以原生Char4 column1/2/5的29/30/31重播reset與timer，驗滿資源全可用、Z+C消耗至SP20後basic仍可用而X/Z+C不可用；126仍是49/50/52。原Road191/192與TCP旅程保留。新增案例初次因缺namespace/ushort cast未編譯，之後因fixture忘開expanded消耗模式未到SP20失敗；補上實際模式與SP20前置斷言後必須重跑整批綠燈，不能隱藏失敗。真人HUD仍需確認。

## 驗收狀態

人測PENDING，先確認伊希莉雅副本快捷列，再續原Z連段、Z+C一次與不足X行走；空白即停。不測其它暫緩項目。快捷列空白的直接呈現鏈尚未完整閉合，不以timer錯誤已修正代替實機通過。

整批最終結果：39項Category=HappyPath通過58秒；未執行暫緩套件，尚未部署／人測。

## 部署

Server maina068117789645d68d7aee44d51afe7c87659de3a已推送並啟用v26。先核對v25 Host路徑／PID，再備份隔離SQLite並驗完整性，僅替換本任務loopback Server；認證／旅程／劇情健康正常，丟棄0，Client hash未變。真人圖示優先短卡已發出，結果PENDING。
