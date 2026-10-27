# T10-20 — Z 連按與 Z 長按自動續段：現有證據矩陣

來源：2026-10-27 Asia/Taipei；KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，12,472,320 bytes。PE .text VA 0x401000 ↔ raw 0x400；BIN 唯讀，objdump i386 Intel 靜態反組譯。地址為 VA；未命名類型及 C++ 語義暫定。不執行／修改目標。

## 綜合結論
本批 T10-17～19 直接檢查 BIN 取得三種彼此不可混同的流程。
A：未知正常非零 writer -> [0xFB9004+key] 或擴展鍵 0xFDF630/node+0x10 -> 0x6D4CE0 -> 0x5961C0（0..39、擴展鍵兩階段）-> state 1/3 的 virtual +EC/+F0 和 0x596140 interception。前段找到的 0x6D4C20 只有清零 writer。
B：0xFB9014 -> 0x547240 (timeGetTime 門檻 500ms) -> 0x546780 input mask bits -> 0x546100 controller filter -> 0x5452C0 行動封包 0x000A。未連到已核對的 Z 對應 row。
C：0xFB9015..0xFB9018==1 -> 0x50C640/0x50CAC0 包裝 0x22；0xFB9004+[28..37]==1 -> 0x548918～0x5489B3 送出 0x68；其他控制器 byte -> 0x5489B9 命令 0x07。以上命令語義均未證實為普攻。

## 證據分級
已確認：以 BIN 核對 key index 遍歷/查詢、狀態值 1/3 的不同虛方法、發送命令 0x68/0x07、writer 清零、500ms 存在於另一相位機。合理候選：可能透過 keymapping 將 Z 配置導向某個 action；部分虛方法可能攔截按下或鬆開。尚未驗證：Z 在實際 Table/KeyMapping.xml 中的行、正常輸入事件寫非零 phase、普攻 motion 的 next-action consumer、動畫完成 callback、長按自動續段與連按的合流點、連段取消窗口。使用者提供兩種操作方法是研究線索，不可反向當作靜態函式已驗證的行為。

## T10-21 具體下一步
1. 從 0x5961C0 的 vtable/RTTI 或 function-pointer 引用定位真正主迴圈 owner；沿回呼追非零 writer，而不是只搜固定絕對位址。
2. 取得 Table/KeyMapping.xml 實檔，核對 Z key/action 的實際設定，區分外部 XML 與 fallback。
3. 由攻擊 motion animation completion 的 next-motion consumer 反向追到輸入狀態，分別驗證 pressed edge、held polling、cancel。
4. 必要時引用 T02 既有網路分析確認 send/receive 但不擅自改他人筆記；仍不採用 500ms 或本機 CHAIN_WINDOW=0.65 作原版連段窗。

## 協作與可重現性
本次只屬 T10 個人筆記；遵照專案共用規範，不修改 game、任務 owner、shared catalog 或其他 Agent 檔案。四段均為有限已核對函式片段，而非 111,054 函式全面審核。