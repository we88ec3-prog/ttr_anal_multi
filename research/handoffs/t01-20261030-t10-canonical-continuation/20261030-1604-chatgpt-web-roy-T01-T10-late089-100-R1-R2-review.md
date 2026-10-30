# T01 — KR T10 late 089–100：R1 去重、原始 BIN R2 定向複核與 Canonical 整合

2026-10-30 Asia/Taipei；基準 main 5a38070c762855b73f5fb563f0e673df5e1f940f；T01 整合者 ChatGPT web。KR 原件 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；Tartaros.exe SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。

本次使用者授權繼續驗證並上 Git。本批以前一輪本地 40 組 early/middle 去重草案、15 視窗 BIN-first 驗證與前次 GitHub 四條 CLM-COMBAT-0001..0004 為底。完整先前階段 Markdown、JSON 與 Python 腳本仍原樣歸檔在本目錄，不得把原稿 PENDING 變成全文 FULL-PASS。

## 來源身份與分組

檢查 research/handoffs/t01-t10-roy-20261029/sources.json 的 127 篇 T10 完整來源；本輪針對 late 中 T10-089～100 的 12 篇取得全文，以完整 Git blob 路徑去重，非只依數字段號。T10-096/T10-100 只是當時研究缺口與跨段摘要；其中「非零 phase writer 尚未發現」在後來 T10-101 的 0x6D1480/0x6D19F2 已獲局部補證，不應將舊有限負面搜尋當成錯誤全文或最新缺口。

| SRC | 原研究主題 | Git blob SHA1 | 有界 CLM-COMBAT 尾號 |
|---|---|---|---|
| SRC-0218 | T10-089 reset caller | b9522feee0464b68ead6ff1ea09f84e09a168510 | 0005 |
| SRC-0219 | T10-090 FB73E8 direct refs | d232cee52ae99734bdae7229a5c1e0e9f2451bd5 | 0006 |
| SRC-0220 | T10-091 child selector | 6f76c33948d04582983855a574dabe64eb185599 | 0007 |
| SRC-0221 | T10-092 mapping consumers | 4902528ed87c5ecfc0477cb248794ea1bd937f4c | 0008 |
| SRC-0233 | T10-093 reset branches | 886c94170e3a83f5161c6df9608f2c874f6b3dee | 0005 |
| SRC-0234 | T10-094 fallback dispatch | f5534c77d75aab81b72a448c0901ec552a29a364 | 0009 |
| SRC-0235 | T10-095 mode routing | 1049f0f0c409d202a552ef35c673051fc0527f89 | 0010 |
| SRC-0236 | T10-096 historical matrix | 951336b952cd2bbf7bf19fa01eb6e31177027ea3 | 0005,0006,0007,0009,0010 |
| SRC-0253 | T10-097 result list | 4384b7604b9ece90d765978d426192585a383000 | 0011 |
| SRC-0254 | T10-098 selector/listeners | 868aa5369cb5c062dbe13dccaaeed7cc7da71f91 | 0007,0009 |
| SRC-0255 | T10-099 direct xref limits | ecaf018a76ba0e0ab11570a629dfa99fea3aa7f3 | 0006 |
| SRC-0256 | T10-100 historical matrix | 124e47117fee777aea6da73d9fb755fd1915fa9a | 0005,0006,0009,0011 |

## 七條有界 R1 / R2 主張

### CLM-COMBAT-0005：0x6D4A30 reset caller 與不同容器
0x490DEF movzx eax,byte[FAADFA]；0x490DF6 push F95CD8、0x490DFB push eax，0x490DFC call 6D4A30。另一 caller 0x58A5DB 分配 local 12-byte self-link node，0x58A607 才呼叫相同 reset。0x6D4A30 的 ordinary path 清 FB9004 起 40 byte，是 zero/reset，不是非零 phase producer。不能推該容器即 combo queue；global/stack 的指標來源需分開。

### CLM-COMBAT-0006：FB73E8 的直接引用與初始化
0x560197 xor ebx,ebx；0x560239 mov dword[FB73E8],ebx，確認一個直接 zero writer。0x59623B 與 0x5A4614 等取值/比較入口並非新的 writer。舊 T10-090/099 的 18 個小端 literal 位置是 bytes operand 集合，不能當函式入口，也不能排除別名、間接或外部 nonzero stores。FB73E8 不是 FB9004 phase array。

### CLM-COMBAT-0007：0x761010 有條件子物件 selector
owner+0x68 為空先 return null；owner+0x64 導向節點容器。迴圈讀 node+8 指向的 candidate，在 candidate+0x28 讀 DWORD；bit19==0、bit8==1、bit12==0 才返回該指標；不合格跳下一節點。這不是固定 accessor，不能從三個 bit 推 actor 種類、motion 或 action 成功。

### CLM-COMBAT-0008：兩個 MapButton domain caller
0x5CD67A push 2、0x5CD67C push 0x10、0x5CD68A call 6D4DC0；另一個 0x650E86 push 2、0x650E88 push 0x2904、0x650E96 call 6D4DC0。前者 MapButton=16，後者 10500，均屬設定/映射消費者，與其後向量及 UI 文字處理有界相關。MapButton 不能直接改名為 Client attack opcode 或 Server 命令。

### CLM-COMBAT-0009：phase1 / phase3 分派的非對稱 fallback
0x59624E call 6D4CE0 讀 ID phase；0x596267 cmp eax,1 先嘗試候選 child vtable+0xEC，返回 false 時可能走 0x596140 listener bucket、再 owner+0xEC；phase3 (0x5962BC) 是另一個 +0xF0 通知分支。0x596253..596261 對當前 gate 的 ID13/14 有特殊限制，不能推為全遊戲 input disable。各 virtual 真正覆寫類別、角色攻擊是否成功仍未知。

### CLM-COMBAT-0010：mode 1/2 兩個不同 child 的 +0xB4 路由
0x5A5767 取 owner+0x158，mode1 選 owner+0x140，mode2 選 owner+0x148，否則正常提前返回；0x5A57A0 類似選擇後以 child vtable+0xB4 呼叫。0x5A464A 的整數 0x66 是此路的傳參，不具原版 Server opcode 或必然 animation 的證據。具體 virtual override 尚待追。

### CLM-COMBAT-0011：成功事件結果鏈表不是已證連段 queue
0x596351 讀 caller 傳入 [ebp+8] result-list；0x59635F call 74D700；0x74D706 push 0xC 配置 12 bytes、node+0/+4/+8 寫入；0x596378 對容器 count+1，並調整 sentinel/節點 links。此資訊僅證在本有界 handled 分支記錄事件 ID，沒有驗到其下游 drain/next-action/attack queue。容量與 allocation 異常需更多 CFG。

## 本輪獨立 KR BIN 位元組區段 SHA256

使用只讀 Python hashlib 在原始 KR BIN 的 PE .text 映射 raw=VA−0x400C00 重新計算以下 [VA begin,VA end) 切片，並以 GNU objdump Intel x86 定向核對合法起點。每段都只是限定 R2，非函式/全文 R3。

| VA 視窗 [start,end) | SHA256 |
|---|---|
| 490DEF–490E05 | e3001c0d76e2d55155b4dadcd58adcc5f316a5d5d04ea466b132b53d5cae5431 |
| 58A5DB–58A612 | 39868c71b94f02bd23d4e0cdb597a89d079d12a768da8b5426e7c48a17d49b7b |
| 6D4A58–6D4B0A | 593c53b274e37605c6a849c72e120bf5f597ac5d3eea8bee1e254f3e6bd5c2bd |
| 761010–761057 | 8ac84207cf757118bcc814db7710aeae08615e38af449bb0491ab8cce3955ee6 |
| 596245–5962BF | 8b40f589e0a714c8f48060fca8c2ce7ca0d71f689adc3b67f8a91b7d61729920 |
| 596351–59638B | f8113405ae577978597d9ed1649e4a3fe6880e049a69356438215160bb0aaddd |
| 74D700–74D734 | bedd2ab40c898ea257b069900b22e9b49af60b3346a44d8c98dc1fcdb565d58e |
| 560197–560243 | 922b04d449ab4a9b0387513545b07f3a23607db13cce8ef571af6d4933ed7938 |
| 5A4614–5A4658 | 05ee41e1870fc25c57bce9a892ac17de022b902fa78c6e3725af3ab4d3d4c03a |
| 5A5760–5A57D1 | f5a629485a467897a6f03e58cc95cc2d83f9d7f7815298bc0d8b3a884b0ea5ea |
| 5CD67A–5CD69A | c672b58f63a2ab4490bd1453f0406d0873f43c212839c8e69c36c10ae00de1e4 |
| 650E80–650EA5 | fc43d9875edb73eeba8931c4f57310d109ccc3039db1e4473e57455b823a062c |
| 6D4DC0–6D4DF0 | aa4c848c325cba7ed6c8a5e1523c73343660e7c4762c5d610cc9d675c1237218 |

## Early/Middle R1 40 群的狀態

舊 early/proposal.json 24 群、middle/proposal.json 16 群，先前本地完整 cross-area 文件將它們分類為 phase writer、reader/reset、timer、input bit、bank/XML、mapping query、listener、local cmd68、availability、SubAI/owner/motion 等有界功能。該 crosswalk 是合併導航，不是 93 份原稿都重讀完成，也不允許把 UNKNOWN/REFUTED 的候選升為肯定 Client 事實。

特別保留：0x5467F1 是出參讀取，0x5467F4 才是 WORD store；0x596430 和 0x6D4BB0 在前一條指令 immediate 內，原 T01-RETURN-T10-055/056 等指令對齊退回仍有效。0x547240 >500 是局部計時差，非連段秒數。internal cmd0x68、C2S0x000A 與 S2C app key13 分屬獨立命名空間；其因果 ACK 未證。

## 未解/接續及權限界線

本輪 12 篇 late 來源依限定內容登記，與前次 4 篇 late 局部整合不重複：127 份 T10 來源中 16 份取得本流程 canonical 局部連結，剩 111 篇待逐來源整合（late 原 34 篇尚 18 篇）。有 R1 限定來源 ≠ 全文原生通過。

Client 待逆向：FB73E8 alias nonzero writer、結果 list owner/drain、active bank/Key44、角色 +EC/+F0/+B4 具體 vptr、phase override +80C/+810 producer、000A 五 byte row、S2C key13 與實際 motion/cancel 次序。Server 待開發：相容 Client 已證封包，但不猜原版 Server Combo 規則。跨 Task 待整合：T02 framing/IOCP、T08 actor、T09 motion。待遊玩驗證：沒有原版 Client+Server 運行或封包抓取。

保留既有 T01 退回和所有主張 PARTIAL/PENDING；不修改 owner、task.json、RR、SPEC、GAP、TEST 或 shared/verified-knowledge。GitHub CI 的 schema/hash/fixture 通過只能作機械驗證，不是 FULL-PASS 或可玩成功。
