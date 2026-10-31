# T01 KR T10 — W00～W05 來源整合與原生有界複驗

日期：2026-10-31 Asia/Taipei。整合至 **main**；研究來源 `t10/roy/chatgpt-web` HEAD `71d2856b3ac383d5c0e78653b645656db3f14da1`；基準 main `f6eeef02dfa3704aabb45349718cc9da4b35fbe0`，比較 ahead=10/behind=0。本批 **27 個新增 Git 檔案**（W00 七項退回作者勘誤、W00～W05 研究及 JSON/Python 證據工具），T10 其它既有原稿、README、task owner、RR 原樣保留。新登錄 `SRC-0599～SRC-0625`，保留精確 Git blob 及 UTF-8 SHA256。

## 實際 T01 BIN-first 限定驗證

本輪**直接開啟唯讀** KR `Tartaros.bin` 12,472,320 B（SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）、`Tartaros.exe`（SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`）、`Event.stp`（SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`）及 `Table.stp`（SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`）。檢查 MZ/PE 頭確認 PE32/x86，ImageBase 0x400000、.text VA0x401000 raw0x400（code raw=VA−0x400C00）、.rdata VA0xBD2000 raw0x7D0600。以 Python hashlib/struct 比對實際原生視窗和 bytes，`objdump -d -M intel` 自真正 PE .text 連續解碼 Row B 與函式邊界，**不是拿作者自稱 PASS 當自己的驗收**。

**獨立完成結果：W00 11/11 個原生窗口 SHA256 及 30/30 個指令 bytes assertion PASS；W01～W05 選定 12 個 SHA256 視窗、24 個 representative byte assertions 及 8 個 vtable DWORD 指標 PASS。** 這些是本輪實測的有界檢查，非執行所有作者 JSON 所載 hundreds of anchors、非根圖 exhaustive validation、非執行/連線 Client，也未實際驗證 socket 對端收到。

| 原稿 / 原始證據 | 本次限定檢驗與技術裁決 | 不能提升的聲明 |
| --- | --- | --- |
| **W00-116** `0x545A54..545B1A` | `545A67` 讀 actor+E4，`545A70` 存 local byte；`545A93` 是 `mov [esp+28],bl`、**`545A97` 才 call virtual+44**；`545AA1` 跳過 `545AC8` 的 B0 覆寫，`545ADB` 讀回 local，`545B10` 最終存 row+4 | virtual+44 可能改 output+4；不可說此支 row[4] 永遠 E4，更不可重用舊「兩路 row 皆固定 B0」 |
| **W00-055/056** | 修訂原錯位窗口頭／假 CALL 的精確原始 bytes 核對吻合；應由合法函式入口解碼 | 不能拿壞視窗作有效呼叫關係 |
| **W00-062/063** | 原生 bytes 支持普通 clear 先於特定 init 的相對順序、writer 不可繼承 reader gate | 未對所有 caller / alias 完全驗證 |
| **W00-007** | `5467F1` 是輸出指標 load，`5467F4` 才是 `mov word [edx],bx` | 不代表所有 combo 實際封包已證 |
| **W00-026** | `549C4E ret 10h`、`549C60` 新函式 prologue；`549D54` 的 call 屬後者 | 不能把 SubAI phase 的 caller 錯歸 `549980` |
| **W01/W02/W03** | 指定原生視窗支持 mapped press/held → controller bitmask、000A header/Row A producer 及 SkillMatrix 部分 gate | 真正在用的 KeyMapping bank、動態各 vtable/row 最終值、按鍵是否每次送包未知 |
| **W04** | RX/IOCP/frame 原生視窗一致；000B/000C/000D/0000 是不同角色更新 consumer 候選 | **不能把 S2C 當作 C2S 000A 的必然 ACK／拒絕** |
| **W05** | `54F200` timer local tick、`54F270` availability、`546780` output-mask 選定視窗相符 | timer 降 1 不等 1ms，非 Server 技能可用性／正式取消窗口 |

**T01 驗收狀態**：所有新來源 **R0 REGISTERED**；上述是**主張級、限定範圍 R2 支持**，仍未完成每篇完整肯定主張、caller/callee、虛函式動態分流、所有 CFG/資料流的 R3/FULL-PASS。故保留 T10 README 七筆既有 NEEDS_FIX／NEEDS_QUALIFICATION 退回，**不標 RESOLVED**；舊錯誤來源不覆寫，且不更改其他 Task RR、共用 verified-knowledge 或 S00 接受狀態。

## 玩家與 Server 需求界線

- Type0（或等價目前 bank）Z/X/C 分別邏輯13/14/15，在必要 gate 下組合出 bit0/1/2；Z+X、Z+C、X+C 候選 mask 0x03/05/06、SkillMatrix 欄4/5/6。**不因兩鍵合成就生出 000A 兩個 row**；000A Row A/B 是不同 object/handler producers，callback 可清掉 local bits。
- C→S 000A 是有條件 6+5N app payload，另外 0022/0068/0007 是不同 producer；queue/WSASend／失敗／原版 Server 受理次序尚須精確研究。S→C 000B/000C/000D/0000 可更新角色/子物件/狀態，但**原版 000A→特定 S2C ACK/動畫因果尚未驗證**。
- **Client 待逆向**：真 KeyMapping bank/mouse 動作、施放中移動、全部 callback/aliases、專屬動作與取消/連段時窗、完整網路與 Actor motion。
- **Server 待開發**：相容 Server 自行處理攻擊判定、合法連段、技能消耗/冷卻與同步；不可將 Client 本地 500ms V-state 或 AI `CHAIN_WINDOW=0.65` 冒稱原版 combo。
- **跨功能待整合**：T02 wire、T09 motion、T11 skill cost/CD、T12 damage、S00 SPEC/TEST。**待遊玩驗證**：原版 Client/相容 Server 的真實動作、傳輸及動畫。

## 完整來源身分列表

| SRC | Repo 相對路徑 | Git blob | UTF-8 SHA256 |
| --- | --- | --- | --- |
| SRC-0599 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-007-correction.md` | `586a1167c9187298d7ad42f6caf25736530ffab2` | `25d89f21a08671e79ab22608edc046fbac36467beec62b0dfae368f21e070851` |
| SRC-0600 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-026-correction.md` | `01aa3a4c78837a4c0fab9cc044e241ec72acc4d6` | `9f1f94197c6c717887910599d35633c68c8aaa34cb8fa0ffcc69c3fd5dc413a9` |
| SRC-0601 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-055-correction.md` | `2af4f42ee1b6468b0c5845429fb318aef36d010b` | `a4c2333ea496335b03aea7482516c78e0b33ba2b1b55da81a75fa5be6d044099` |
| SRC-0602 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-056-correction.md` | `e917b389c354addbae2236c98769156fe3477b72` | `49e37f1bde88ae3aafa2e01808f017fcb0c5be7adf864c35bbd61942d3d6b61a` |
| SRC-0603 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-062-correction.md` | `d2ab9bcc384cb7e08e2129495c517b9c1b408d5e` | `9a9e73746e36864824e0dd76258e84c4534037fd8f6470b063d1c74179dab340` |
| SRC-0604 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-063-correction.md` | `c5af48889e0a50f31ebf780c1ca2236426228699` | `5c5500ffa311bc4bb0fed8e6db21b476312f2cfcd6f14ad83554634a401d9127` |
| SRC-0605 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md` | `bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804` | `dc1b3ec08b5580fc9ba24a1d96968d0896b476672d1a9558fe0dbd54df6c665f` |
| SRC-0606 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-README.md` | `e916bde00bf469c8edd17a9c4bbb9f01166512df` | `d2eb9ca18cf9fdcbfd45a5014ab694ec945d03afbfb9aac00f4aaae3b0904a2d` |
| SRC-0607 | `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-native-byte-audit.json` | `2eedc400e79210637208c4c671d87962b404d97a` | `0b4a371804ad02244f95c03751c34efe47bc0286bd3a23e308a827d5be227f21` |
| SRC-0608 | `kr-temp-roy/T10/W01-20261031/20261031-154059-chatgpt-web-roy-T10-W01-input-source-to-action-gates.md` | `a5d6c4ca0104e8ffba51e151169f6072f09035d4` | `710a78d8cf68dd3133ad9a6706eaf5d474acb13d0f9231a6f2bc675c02c31450` |
| SRC-0609 | `kr-temp-roy/T10/W01-20261031/20261031-154059-chatgpt-web-roy-T10-W01-native-byte-audit.json` | `5996a29db4306bc0b2d4d7ac4159532f507daa3d` | `a3b6204a7b51487e30a429e8bafcc302c73e5250bc463c8f2eaee8708c9c0b6f` |
| SRC-0610 | `kr-temp-roy/T10/W01-20261031/20261031-154059-chatgpt-web-roy-T10-W01-verify-native.py` | `43860ae2aa318ebcdeb464329704ba20d73e1714` | `d8b325a708a8b191231cf026f1d8c5f03c9d1a060611712531f7c8597c41fb83` |
| SRC-0611 | `kr-temp-roy/T10/W02-20261031/20261031-163141-chatgpt-web-roy-T10-W02-basic-attack-as-skill-native-difference.md` | `e8a0cedc28c28968905e914d01379915fe9dc17f` | `8ceed5100b74b029226b635535937326ce2695044b3189a5c9692d27d93ccd1b` |
| SRC-0612 | `kr-temp-roy/T10/W02-20261031/20261031-163141-chatgpt-web-roy-T10-W02-native-audit.json` | `fbfaa29a413f3ba50f20b7793e953123edb8738a` | `cedcf558b864a649c34ebae6dbf50a419b21232e6b9547346a66ee5eb772b076` |
| SRC-0613 | `kr-temp-roy/T10/W02-20261031/20261031-163141-chatgpt-web-roy-T10-W02-verify-native.py` | `281d772c76c31b5aee6602be6917837d00bfa9f2` | `84078224c030caa56c45aa164a7caeba48df1be5b69192a981e24378e16a07ca` |
| SRC-0614 | `kr-temp-roy/T10/W03-20261031/20261031-165757-chatgpt-web-roy-T10-W03-action-transport-native.md` | `62d31e8b3d8a450e644362092fd04e7ae696c729` | `aee6f9e10a173fea2a8c316eb9d1f9a1df423001c8b6b888b95f22fa31d967bc` |
| SRC-0615 | `kr-temp-roy/T10/W03-20261031/20261031-165757-chatgpt-web-roy-T10-W03-native-audit.json` | `f041a7a8dd1fb38144f6b8bebaa92e9e8d2f5fe6` | `a43c6e757e7c5aec5a318317eb549bb4b0f064405de79c43fda4d2c5dcc7d7d4` |
| SRC-0616 | `kr-temp-roy/T10/W03-20261031/20261031-165757-chatgpt-web-roy-T10-W03-verify-native.py` | `804ea36f4e5313bbb7fe93292b0ea391d1954cbf` | `64a6c87473b9603cb74c66700ef7ec7b3dde95ab9ffd9aeaa7f9a03a70e60167` |
| SRC-0617 | `kr-temp-roy/T10/W03-20261031/20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md` | `0d17362eb300ab8ea002c3d6380d5a41039665bc` | `48ad49e2b3e32fdbcf1aa6ca56f0f206d22a9b1114b3e34182051cfe158a2d02` |
| SRC-0618 | `kr-temp-roy/T10/W03-20261031/W03-combo-native-audit.json` | `d4bf96ee9fe17bb24244a10af3517b3e94193f14` | `26fe56321b98fa516588f3bd5aea3317ed9599d005096aa0b365a733ac9c8b3c` |
| SRC-0619 | `kr-temp-roy/T10/W03-20261031/verify-native.py` | `40753d76a3bd0cba9697141628786e513086c05f` | `71f5f7c558919f5ec93ff5406c8cb3ae68796f35e5eedd807b70eebe6a7f4e70` |
| SRC-0620 | `kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-S2C-receive-actor-motion-native.md` | `8e915daab064177490d5de0b3f193810a5de2f41` | `4136c77df92fb90e556c92f2307f7eb30bf9ec74126518fb7fee1196286776ad` |
| SRC-0621 | `kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-native-audit.json` | `726415266945bc5c3fe3f3022476abf18a12f824` | `ed9bc923780838810e4811cb6e8b69ace95d447ba884c9307c3c64de7ef6999f` |
| SRC-0622 | `kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-verify-native.py` | `f74c91f280dc745293f96e01a6f66a4213b9a4fa` | `9dfdf54c642baec1acd5bfb9723179eaa4eab654f859168f1048d7f2e969c51f` |
| SRC-0623 | `kr-temp-roy/T10/W05-20261031/20261031-182635-chatgpt-web-roy-T10-W05-native-audit.json` | `79aedf4d2a931bf5c64f39e82ba6d4480b2beefe` | `6b5e88564bb7ab6421d1d0db822b0537577390e1e9462e4f77795ab045209ff1` |
| SRC-0624 | `kr-temp-roy/T10/W05-20261031/20261031-182635-chatgpt-web-roy-T10-W05-skillmatrix-resource-timing-T11-handoff.md` | `b3c0f31db311cce06f3a87fcbbf4f938171ce972` | `5ac9a34d1243a0c797679e3b53c02c542a380a3ed5b5919e14579a81fc1306e2` |
| SRC-0625 | `kr-temp-roy/T10/W05-20261031/20261031-182635-chatgpt-web-roy-T10-W05-verify-native.py` | `3aaf63fa7fc8e7d7f8f657dd896c3142825971ac` | `83d73d02824001425de5069e738177ec124699682935020376feee9c0ca823ff` |

此 T01 報告保留原始作者資料的具體限定結論，**不得自動提升來源全文 FULL-PASS 或原版 Server / 真實可玩**。
