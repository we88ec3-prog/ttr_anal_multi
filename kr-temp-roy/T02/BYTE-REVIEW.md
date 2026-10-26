# KR T02 roy：局部來源與位元組驗收

來源 SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；模組 Tartaros.bin。分析者 roy，2026-10-25 Asia/Taipei。

驗收範圍：Python 3.10+ 標準函式庫 PE32 raw section mapping 對原檔唯讀核對；確切執行版本記在 byte-checks.json/source-checks.json。相關原生分析工具 REA6.5.0/Ghidra12.1.4；本小成果不依賴尚未成功回傳的函式查詢。

已觀察：目標雜湊與 shared/targets.json 一致；T02 原列50份證據 SHA 全相符。原檔六處 byte checks 分別為807BBE=BA00100000、807BD8=BA33260000、807BFC=BABB0B0000、807C18=BA681A0000、807C22=BAD7220000、807D35=34B6，與既有 parser listing 的長度/marker/XOR常數一致。

成立條件：每處 VA 經唯一且完整落於 file-backed section 的 raw mapping，完整來源SHA先行 assert；沒有執行歷史腳本、目標或目標API。raw-807b40-807e43.bin、raw-807830-807a70.bin、raw-807a70-807b40.bin 僅為包含相關位置的原始window，範圍末端exclusive，不當成完整函式body。

分類：上述常數與來源身分為局部原生位元組確認；既有分框分支為部分確認；login_protocol.py 是本機替代審核來源，payload 4090限制、只支援0BBB及例外策略尚未由本小成果驗收為原生全契約。合成帳號、角色、初值與出生點仍是AI替代/待開發，不提升為官方規則。

限制與推論：常數存在不證明所有分支可達、helper演算法、send/receive上下限一致、checksum錯誤策略、mode時序或官方後端。4090等於4096減6僅待查假說。50/50及6/6不是語意完成率，完整可玩流程未驗收。

遊玩影響與後續：正確分框是登入/選服/場景收包的前置。本成果提供可重現的來源定位，尚不足以改服務codec。下一步核對807A70/807830 sender容量與807B40 receiver，再核對8061A0/806AD0 mode及連線參數。T03/T04/T05/T06既有業務/資料/場景/資源依賴保持有效；不展開他人核心。

衝突檢查：未發現既有常數記錄與原檔相反；歷史報告/helper未驗收限制保留。原目標、anal、資源、帳號、存檔均唯讀。新的語意結果另行審核，不能隨此小成果自動提升。
