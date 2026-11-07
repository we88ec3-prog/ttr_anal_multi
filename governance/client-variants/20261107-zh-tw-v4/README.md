# zh-TW v4 — 原遊戲目錄版（2026-11-07）

使用者已明確同意：製作 v4，沿用台版文字及補齊韓文字元的衍生字型，
直接從原遊戲目錄開啟 .exe，保留舊版與原始資源，不覆寫。
這是限定 Client 翻譯／分級圖授權，不擴及其他玩法修改。

## 本機新增五個檔案

- `Tartaros.ip-zh-tw-v4.exe`
- `TC_UI/Table.story-zh-tw-v4.stp`
- `UI/Fnt4.stp`
- `UI/Font/v4jh.ttf`
- `UI/Font/v4jhbd.ttf`

都位於 E:/Tartaros/workspace 下。直接從該目錄開啟 v4 EXE，不依賴先前
CLIENT/build/zh-tw-v3 測試目錄、CMD 或 junction。若使用自建捷徑，工作目錄
應是原遊戲目錄。既有 fcs.flu、pack.gms、DLL 與各資源目錄直接沿用。

## 來源、修改與界線

EXE以保留的 v3 工作副本為輸入，比對原 v2：
只改6 bytes（0xc2981、0xc298c、0x83f170、0x83f171、0x83f172、0xbe8a19）。
前兩項為已核對的年齡畫面visibility/counter調整；其餘為等長路徑改名。
PE header/section layout/檔案長度不變。EXE SHA256：
008712b39d367c1c7b5f5b962d94ec9cafdc97111f4742d7d874ce16525f5770。

Table直接沿用已製作的v3翻譯內容，SHA256不變：
2a5f74af1f779879ffd2bd0a051178f3d5e8ddbf214113c36fad6c0ed93ebaf5。
來源是KR對應工作檔結合經分類/ID核對的TC NPC及技能文字，不是整包改讀TC
Table。保留KR玩法欄位、既有劇情翻譯與未閉合欄位原文。顯示文字數值與
Server/KR玩法值可能不同，不能因翻譯而當成消耗/CD等已修正。

字型沿用已核對的TC msjh/msjhbd衍生檔，補入268個可見韓文回退字元；
向量glyph與TC水平metrics保留、hinting已移除，沒有安裝系統字型。
v4只改字型檔名。Font archive只改Chinese(Taiwan).FFT的兩個Path；
其餘3個member、86個FONTITEM與ClassName保留。檔案完整來源hash見manifest；
v3詳情與失敗歷史見 ../20261105-zh-tw-v3/README.md。

## 驗證與待測

獨立靜態檢查：PASS_STATIC_ONLY。79個既有EXE/BIN/DLL/STP/FLU/GMS/設定/字型
檔案在製作前後SHA相同；新翻譯檔逐byte等於核准的v3；每份字型所需1218字元
均無缺字。驗證器首輪字串切片少算結尾NUL，已修正為按literal長度核對；
不是EXE產物錯誤，也沒有因此改動EXE。未重新執行/附加遊戲。

原v3曾漏fcs.flu及pack.gms，保留退回紀錄；v4改採原目錄資源，不能僅因
靜態完整就宣稱3D異常已實機解決。人測尚待：啟動、分級圖跳過、水面/花草
透明、登入廣場人物/NPC及翻譯/字型顯示。Server原版相容性不升格。

Builder拒絕覆寫任一既有輸出，先核對輸入SHA及基準既有檔案，再建立五檔；
checker唯讀檢查遊戲檔，僅寫本機證據。重建工具放CLIENT/tools，需既有
stp_resources.py、build_zh_tw_v3_font.py及check_zh_tw_v3_glyphs.py。
原始資源、EXE、STP、TTF與glyph字元集合不放Git。

回復方式：關閉v4後開原v2即可；不需要還原覆寫檔案。舊v3保留供追溯，
後續以v4原目錄交付為準。
