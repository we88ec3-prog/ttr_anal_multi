# 一次性區域完成後退訂

2026-11-24追加：[占點期限前省略](HOLD-DEADLINE-SCHEDULING.md)在既有pending mask之上，
同位置且未到最早期限時不重掃未完成占點；移動、暫停及新節點仍失效／重設。
812HappyPath與正常TCP／Host證據另存，不改下文歷史成果。

2026-11-23。SERVER_DESIGN_CHOICE／**NOT_NATIVE_MEF**。完成
[D06](../../kr-extra-roy/MEF-level-functional-closure-20261118/DEVELOPMENT-PLAN.md)
的一次性區域退訂部分，沿用 RegionEntered／RegionHeld 的事件來源、半徑與時計。
沒有新規則語法、opcode、Client 行為或關卡配置變更。

## 可供實作者採用的契約

每次正式 Enter，在原旗標 scope reset、占點時計重設、旗標數量閉包完成後，
依該節點的來源順序建立兩組尚未滿足的區域訂閱。現有 catalog 限制整份 definition
最多64筆 signal，因此每實例各一個64位元 mask 可保存原 signal 索引；最低位起處理
即保留原宣告順序。不可把完成狀態寫回共用 definition／index。

- RegionEntered：位置仍用既有精確圓判定；首次命中經原 RecordFlag 提交，隨即退訂。
  已有旗標在入場時不再訂閱。沒有新增跨區段掃掠觸發或擴大作用半徑。
- RegionHeld：尚未完成時持續觀察位置；出區、位移回呼及 canHold=false 仍重設未完成時計，
  再進區重新起算。只有原占點秒數真正滿足、經原 RecordFlag 成立後才退訂並移除時計。
  不把「進過」當作連續占點，也不把完成區域重新加入。
- Fork：複製各自 mask、時計及工作量數值；原與分支後續操作互不影響。
- 換圖／同 node 循環重入：先沿原旗標 scope 清除政策，再重新建立訂閱。
  被清掉的區域旗標可以重新完成，保留的旗標不重新訂閱。新的節點只訂閱自己的區域。
- 已完成／未入場／無效位置的原短路、旗標依賴與順序、清場時計、出口選擇、0027／0048
  與獎勵提交政策保持。危險區與未完成占點不能因本批退訂而停止觀察出區。

內部唯讀診斷增加 `regionObservationWork`：原事件索引候選列下界、實際訪問列、精確圓判定、
完成退訂數、入場 seed 數與兩種 pending 數。這些是工作量，**不是 CPU 百分比或 Client 卸載**。
沒有加入跨實例全域 mutable 區域集合；選定版的 actor／旗標／時間仍由原 Server adapter 權威處理。

## 驗證

[最終收據](../testing/region-retirement-20261123.receipt.json)，SHA256
`37ba35f0b8af9a1c59dcfa60600f07575df47d3f45a9b328120f138443333848`。

三個新增 HappyPath 正流程：獨立原完整掃描 oracle 對照進區、離區、重新占點、暫停占點和完成；
部分占點的 fork 隔離及換圖；真實有限循環兩次重入重新完成區域。
完成後20次正常位置觀察不再增加候選訪問／精確判定。所有796 HappyPath 通過，零失敗／略過；
Host／Inspect／Admin 三個 Release 零警告／錯誤。

沿用[Q119封路版本](../testing/STORY-SEALED-GATE-NORMAL-ROUTES.md)，內容 SHA256
`9e65baa388571a3827ce70e36f39597cec4a4771239dee12586f439200979fb5`，原 AI／EXP policy 不變。
管理端重新正常預覽、保存及匯出四檔配套，停止／三輪各有舊幾何控制與保存封路版，共四條 TCP，
仍5936／5984EXP、一次Q119、Q120游標與原村原隊伍返回。
保存封路版仍先走到關門通道受阻，連續占點2.5秒、點位各開一次後實際穿越。
三輪 TCP 在開門後至出口，候選訪問／精確判定保持147，原候選列下界由149增加到168。

另以相同 Inspector、相同配套分別載入保留的舊 DLL 與新 DLL，擷取整條三輪正常路線的
1,676個 primary application 回包。原始 SHA 因帳號 wireAlias 不同而不同；只在已有寫入依據
的欄位正規化帳號識別：既有124列，加一筆61-byte `002A/+2` 熟練度快照。
後者直接對照 `KrSkillPracticeProtocol.StandaloneMasterySnapshot` 與發布端 `wireAlias` 實參，
沒有清除熟練度／錢包／Garnet 或其他欄位。正規化後全部回包 bytes 及順序一致，SHA256
`02f2033a5344d4562a38fbb6cd8fbc010b24cad984b373551080a9ac2862482b`。
首次比較器漏列這個快照識別欄，保留兩份擷取並修正比較器重讀，沒有為此重跑玩法或修改 runtime。

保存同版的獨立真實時計 Host 完成八次訪問、一次Q119 5880EXP／40熟練，SQLite總增量5984，
Town1／Map182原隊伍返回。該路線開門後至出口，候選訪問／精確判定保持120，原列下界120→136。
時計不同所以不把兩組數字互相比成性能比例。沒有測試時計／內部 Handle/Poll，隔離 Host／Admin
已停止、種子資料庫不變；使用者現用服務、Client 與原件保持。

本批只完成 RegionEntered／RegionHeld 退訂；空間粗篩、危險區期限、其餘D06／3D門、
指定v2與自然新帳號仍另列。未執行延後的錯誤／邊界、重送／重登、故障、併發、安全或壓測。
