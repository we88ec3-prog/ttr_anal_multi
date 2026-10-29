# T03 → S00：選角UI、C2S builder與接收worker邊界

來源：`t03/roy/chatgpt-web@6dc876e84358c1f1ab343ce5b8899006574ddf26`，SRC-0329～0347。限KR原BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；不跨用TC位址。13項新增有限主張與10筆歸併引用見[動作紀錄](actions.json)。

**可交SPEC-CHAR-0001／SPEC-FLOW-0001的有限資訊：** 本地F42EF與665150是UI資料／通知，不是wire回覆；70A的record+5C gate只限該分支，其他caller不能借用。`4A3B80`的`42 00 XX YY`是四byte本地C2S payload，sender／slot／framing與狀態仍有前提。所有資料保持PARTIAL，這份交接不直接修改規範性MUST條款。

**可交SPEC-NET-0001／0002／0003的有限資訊：** 已有canonical framing／queue主張追加來源子集，不重複建立結論，也不改信心。WSASend pending／completion不等Server收到或業務ACK。T03-6 API layout錯誤已單獨REFUTED並退回；source-derived的其他有效條件保留。FE3358與FC10D0、getter與dispatcher、sender C51748與worker vtable不可混同。worker slot0實作及其命令域仍待定向查證。

**禁止採用的推導：** `42→43/69` fixture配對、`1001/1`場景key來自selection reply、Print Screen／D3DX output直接構成worker parent、所有caller均有同一roster gate、WSABUF/OVERLAPPED與A0B8 counter混名、`80004005`就是Server選角拒絕。REFUTED項不得作相容性規範來源；INFERRED screenshot分類只可協助排除錯誤研究方向。

**Server設計決策：** 未新增或批准ADR，未設計官方帳號／角色權威、批准／拒絕政策、持久化或場景預設。沒有將本地原生資料流冒稱原版Server演算法。

**RR／GAP／Owner：** 維持RR-0002／0007／0008及相關GAP原狀；T02管transport／dispatch，T03管登入選角業務，T04管權威資料、T05場景、T06UI。這批是可供S00查閱的來源交接，不是研究者已按新RR認領後SUBMITTED，也不是S00 ACCEPTED。S00需另核對其精確完成條件後決定規格用途。

**TEST：** 沒有新合法S2C回覆向量或真實Client／Server測試；原有離線合成framing／roster／auth向量只作回歸，不能由CI通過升STABLE。新增C2S局部形狀是否足以製作適用測試，由S00按來源條件審閱，先保留配對與狀態未知。既有contract-coverage與readiness阻塞不解除。
