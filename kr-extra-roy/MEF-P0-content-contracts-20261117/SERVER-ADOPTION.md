# P0 分析的 Server 開發交接

本文件沿上一批三項 P0 整理可實作接口；本 repo 保存研究與規格，沒有新增或執行 Server 產品程式。列號只供本文引用，並非新 REQ／RR。S00 應沿 REQ-0019、REQ-0021 及既有 SPEC／GAP 去重接收，正式狀態保持原值。

## 1. 採用入口及既有成果

現行主線候選與外部關卡已有分工。Q119 的 scene 鍵在主線候選：末圖入場是 119/3，清場是 119/4，返回是 119/5。外部關卡檔覆蓋戰鬥編排、旗標和出口等設定；其中沒有任意 Lua 命令列。本輪已對四份公開 JSON 作精確來源重算，見 [現行 Server 對照](integration/README.md)。

開發應保留已有主線版本、外部關卡 SHA、合併圖 SHA、任務完成前綴及既有點位／結果／資產邊界。P0 增加的是「這份內容以哪個 Client、哪組 ABI、哪些真實資源及哪些 owner 條件執行」的檢查；不是重寫既有戰鬥或發獎規則。

## 2. 三項 P0 的增量開發工作

| 工作 | 開發輸入 | Server／內容工具應做 | 完成條件 |
|---|---|---|---|
| ABI 採用 | 固定 121 binding 契約、原始 helper 轉換、觀察值語義、圖片勘誤 | 以精確版本載入規則；區分原內容審讀與新內容的嚴格編輯規則；拒絕未認得的 API／參數／結果用途及 stub 能力 | 同一內容與 ABI 版本不可錯配；錯誤回值不能當成功；所有原生差異和編輯政策可追溯 |
| 真實依賴 | scene selector、原 SEQ、正式與預掃描依賴、descriptor、payload、實際選檔來源 | 在選定發布品中分別驗「資料表有引用」「bytes 已有」「原 resolver 會選到」「此 context 可使用」；逐項保留缺件與曖昧 | 缺少必要 bytes、索引、mount 或受控 context 時維持 NOT_READY；不把候選 basename 變成已選 runtime path |
| 執行與收尾 | owner ledger、生命期補證、清理偏序、執行策略限制 | 為每份內容列取得的 owner、合法退出與後置條件；以既有場景／實例排程串接，保存發起、原回覆、業務提交和驗證狀態 | 不依數值真值、無producer回值、Q inactive 或預期時間推全部完成；下一段入口需符合其自己的前置 |

這些要求不改原 Client wire；Server 內部的 run、instance、generation 或 release identity 不能憑空要求 Client 回傳。已知封包 adapter 繼續使用原形狀，沒有新增 ACK、opcode 或任意腳本參數通道。

## 3. 發布審查資料應如何連接

建議將下列資訊接入現有內容建置／審查流程。這是實作所需的概念，**不是可直接送入現有 `.scenario.json` 的新欄位**；目前 schema 四層禁止未聲明欄位，需在原維護線做有版本的擴充或相容工具整合。

| 概念 | 必要關聯及拒絕條件 |
|---|---|
| Client identity | 指定 KR 原 BIN SHA；另一版本必須另核，不能只以遊戲名稱配對 |
| Source identity | 完整有效 SceneList、SEQ、qbase、ABI catalog、依賴 carrier 與有效索引的精確 hash；完整載體和 member 的 hash 分開 |
| Selector | 真實 quest/scene 與 funcName；保留重複鍵／覆寫規則，不能只取第一個同名檔 |
| Typed references | Q slot、model/action、world EntityId、map/field/BND、talk/portrait/voice、point category/key 各自型別；原 Chart node 與 Server node 分開 |
| Phase | 原 helper 在 prepass/formal 的實際轉換；動態 global 與引擎隱含動作是依賴，不得默默消去 |
| Resolution | basename 候選、catalog entry、cache／mount、directory+filename、選中的 bytes 及來源分欄；缺一層即留下未知 |
| Ownership | 取得、持有、更新、終止、實際釋放與觀察出口；共享 owner 不假裝每 run 隔離 |
| Exit | End 前仍可作用的清理、End 後正常循環的消費及無 ACK 項；同 run 與跨 run 策略各有條件 |
| Server result | 業務權威條件、保存及既有結果 adapter；演出結束與擊殺／清組／任務完成／獎勵不合併 |

## 4. 必須分開記錄的狀態

「研究包可重現」「呼叫編輯規則通過」「完整資源已選定」「可排程」「已發起」「原生結束回報」「Client 畫面與控制已核」「業務提交」各自有不同證據。實作者可沿現有狀態機表達，不需另造一套平行台帳；不能以其中一項自動寫滿其餘欄位。

例如收到已證形狀的 003F，只能使用它原有的有限語義。它沒有附帶資源載入、圖片釋放、camera 回復、model 工作佇列清空或所有內容成功的證明。適用的 00EB 只解除其既有等待；沒有新 cleanup ACK。對同一 Client context 的再使用政策應保留已有 seen／busy／scene 條件，不以連線重建或單純計時假定全新 context。

## 5. 正常流程驗收的接續工作

在原件與實際發布來源齊全後，第一條正常旅程應記錄：內容版本與選檔、正確 selector、入場與 prepass、完整視聽／對話、原生結束、控制及場景恢復、既有出口 Z 與業務結果。Q119/3 的本次資源審計不能自動涵蓋 119/4 的清場內容及 119/5 返回內容；要驗整條旅程，需使用它們各自的依賴／owner 契約。

本輪只運行原件／資料讀取和分析工具驗證，沒有啟動 Server、遊戲、Lua 或故障／重送測試。正式工程整合和指定 Client 的正常遊玩結果仍由其既有工作線記錄。P0 的未齊資源不阻擋不依賴它們的普通戰鬥、權威旗標、任務、NPC 服務及保存工作。
