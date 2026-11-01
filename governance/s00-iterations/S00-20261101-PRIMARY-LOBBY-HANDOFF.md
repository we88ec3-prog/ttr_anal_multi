# S00 — 登入到主 Lobby 的欄位回傳與 Session 交接

基線：S00 `fe53c47d978c09cd87e671fead2954ee59f9d2b3`；私有 Server `cc50f539da18b6b09c96a0088e01b69e9732b57d`。使用者表示短時間不能操作電腦，要求先繼續開發；本輪不啟動遊戲、不重試 UAC。目標維持新帳號完成教學後進廣場，本稿只交付登入跨線所需的一段工程。

**SOURCE_BACKED_PARTIAL + SERVER_DESIGN_CHOICE + OFFLINE_SYNTHETIC。** 不新增／提升正式 REQ/RR/GAP/CLM/SPEC/ADR，不宣稱原版 Server 的 ticket 算法、request/reply pairing 或實際 Client 可玩。尤其不把僅有的 source-shaped 模擬器稱作原 Client。

## 1. 來源與有限核對

原始唯讀 KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。延續 [SPEC-AUTH-0001](../../spec/session-account/SPEC-AUTH-0001.md)、[上一輪登入回覆候選](S00-20261101-LOGIN-CHOICE-COPY-AND-REPLY-CANDIDATE.md) 與既有 T02/T03 handoff；不是重新要求官方 Server 或全面重做反編譯。

- 已存 REA 導航：`kr-temp-roy/T03/evidence/rea-t02-channel-interface-callers-4957c0.json`，Evidence `ev_a9d55e94565cba534f09d3b32af08c058ee7414157a8eec46b09d0d1f6c2770e`；僅按其原始 operation 範圍使用，不冒稱其中含完整新 assembly。
- 保存偽碼：`kr-bulk-roy/<KR-SHA>/functions/0x4957c0.c` SHA256 `9fefbc88f0ac78bc179be74b73db5d6310b1ad9f03ddeb9ec28655027fb25593`；原始批次 `raw/20261025T182755495890-batch-20261025T184253968363-2704.json` SHA256 `f7591e951e9415b3508a7b6520c3b28c93977af61738c2bacb2bc3976d3dc6f4`。原 bulk 的 saved-unreviewed 標記維持。
- 原始檔補查：沿用已隔離安裝的 Capstone5.0.6，只讀 PE 映射後的 `0x4957C0..0x49597D` **成功路徑片段**；28個 instruction-start／bytes anchor 相符。新輸出 [KR-PRIMARY-LOBBY-HANDOFF-20261101.json](KR-PRIMARY-LOBBY-HANDOFF-20261101.json)，不是新 REA dossier 或 T01 FULL-PASS。片段之外的失敗分支、完整 CFG、實際 Socket completion 不在本次結論。

```powershell
python -B governance/verify_kr_login_choice_copy.py ORIGINAL_KR_BIN --capstone-dir ISOLATED_CAPSTONE_DIRECTORY --scope handoff --output OUTPUT_JSON
```

## 2. 已見的成功路徑與不能推廣的地方

`0x4957C0` 在這條分支要求兩個新 Conn 返回非空：key0/port8416/lane2（`0x4957E0..EA`）與 key2/port8414/lane2（`0x4957F2..5803`）。舊 login Conn 若存在，會清其 queue、加入 local app`0x7E` 2B、設 close flag、清 `Client+BF60`，再 Sleep(400)，最後向 **key0** enqueue app1／57B（`0x495935..93D`）並 post兩個新 Conn 的 receive。

這證明局部 **queue／狀態操作順序**，不證 app7E 必然抵達 Server、不證 TCP EOF 必然早於 app1，也不保證所有 UI/Conn 路徑都進此分支。新 Server 應容許正常交接中的登入側結束；不得把 key2 當作另一次主 Session Claim，亦不從這段猜 key2 第一個業務封包。

以 `[EBP-0x40]` 為 payload 起點，已見的57B builder：

| payload offset | 長度 | Client 來源／寫入 | 本輪地位 |
| --- | --- | --- | --- |
| +0 | 2 | LE16 app1，`0x495884` | 已見 local builder；非首次 wire 配對 |
| +2 | 4 | `Client+67E0` → `[EBP-3E]`，`0x4958B8/BE` | 與13 consumer的 `+18` store 接續；正式業務名未知 |
| +6 | 20 | `Client+67E4` 寬字串，capacity10/count10，`0x4958C8..D4` | 與13 consumer的 `+2` 名稱接續；Producer保守用1..9 ASCII |
| +26 | 1 | 明寫1，`0x4958F1` | 常量，不混成整個 WORD=1 |
| +27 | 1 | `Client+6898` → `[EBP-25]`，`0x4958FA/5900` | 與13 `+86` store接續 |
| +28 | 5 | `Client+6899` narrow NUL字串，capacity5，`0x495908..14` | 與13 `+87` store接續；安全長度不等於官方ticket算法 |
| +33 | 4 | `Client+68A0` → `[EBP-1F]`，`0x495921/27` | 與13 `+8C` store接續 |
| +37 | 20 | **另一來源** `Client+67FA`，`0x4958E0..EC` | 本輪不命名／不當認證憑證；不可假稱它由13同名稱slot而來 |

可有限推論「上述幾個欄位可從13消費者，經Client物件，再進key0的57B producer」。**仍不能**推出官方 `E8→13→1→2` 必然交易、13必是第一回覆、app1必回角色清單、完整header、或工作副本實際scene可達。

## 3. Server-owned、可獨立實作的交接策略

目前接收器在登入連線結束時 `DisconnectAsync(sourceLease)`。若未另設交接保留，它可能在主 Lobby 候選驗證前刪去該登入的 Session。這是從 **Server程式與局部Client路徑推導的整合風險**，不是新觀察到的遊戲Runtime bug。

本輪私庫實作 `LocalLobbyHandoffBroker` 與 SQLite `IPrimaryLobbySessionStore`，**未接入Host／Listener／原生admission**：

1. 受信Server入口先持有C02當前完整lease，才可簽發一次待交接grant；每個相同lease只留一筆，process-local最多64筆。
2. 配置一個非零隨機UInt32 **wire alias**，只作本次Session相容別名，不截斷DB UUID，也不宣稱它就是官方account ID。交接結果保留alias，供之後Lobby context使用。
3. 在已見可回傳的 `+86/+87/+8C` 三處填Server自訂proof：隨機byte＋4個base64url ASCII字元＋NUL＋隨機DWORD。**secret entropy64bit**（8+24+32；不是256bit），alias不計入secret強度；不適合據此直接核准對外服務。完整SessionId/ConnectionId/密碼不作wire bearer。
4. 把 app1 前37B（命令、alias、zero-padded名稱、constant1、proof）做SHA256，broker僅保留digest→sourceLease/expiry/alias；grant自有敏感buffer，dispose歸零，預設字串表示遮蔽。暫存字串的完整記憶體清除不在本輪保證。
5. lifetime1秒至2分鐘，典型60秒，且不超過原lease deadline。正常登入側結束若仍有grant則保留交接；沒有grant則走既有exact-lease清理。這是正常ownership交接，不是中途斷線／恢復的測試。
6. 候選57B經同版SHA/局部shape與本Server producer限制檢查後，先原子移除一次性digest，再用SQLite單一交易將**同一當前lease**移至新Server-generated主連線Guid。WHERE核對account/session/connection/revision/有效期限/未選角與既有帳號條件；保留SessionId／原expiry、revision+1；不能fallback重新Claim。
7. 得到 `LocalPrimaryLobbyAdmission { Lease, WireAlias }` 後，既有transaction-fenced角色服務可讀空清單、建立第一個角色並選取；此處只是domain資料，沒有捏造app2 header／角色初值或UI ready。

此SQLite路徑**不新增schema版本、不遷移目前使用者DB**；測試與CLI用獨立檔案。PostgreSQL／多process、key2 auxiliary綁定、持久化grant、正式安全准入與錯誤回覆為後續工作。未修改既有 native admission、normative pin、歷史測試或使用者遊戲EXE。

## 4. 本輪真的執行了什麼

- 原BIN唯讀檢查：同版SHA／PE32 mapping、1段線性decode、28 instruction anchors相符；只證限定bytes。
- 新增兩項 `Category=HappyPath`：正常57B candidate prefix，以及真SQLite新帳號→正確認證→candidate13→模擬Client欄位copy→正常主線交接→空清單→創建／選擇第一角色。
- `Tartaros.LocalDev --db DISPOSABLE_DB` 走相同正向資料路徑，輸出OFFLINE_SYNTHETIC，不建立TCP或啟動Client。
- 與既有4項合計6項正流程前置；方法來源盤點204＝6 active＋198 deferred（Theory資料列未展開）。**沒有執行下面的負向／邊界／故障等案例**。

這不是遊戲畫面、tutorial或square驗證；最終目標未完成。實際Host仍維持先前auth-only模式；此broker不能在未接線時自動修正當前Host的Session清理。後續接線需用該broker統一處理登入側完成與主Lobby接收，不可只加一個parser就宣稱Session可續接。

## 5. 待測與下一個依賴

詳細新增待測項目併入[唯一排程清單](../../design/testing/TUTORIAL-HAPPY-PATH-AND-DEFERRED-TESTS.md#主-lobby-交接新增待測案例)，不建第二份TEST台帳。原有23類不變；wrong proof、到期、重放、雙登入、順序競爭、provider故障、版本／編碼及key2不得夾帶到目前6個正向案例。

實際Client登入／scene gate仍待使用者方便時完成UAC；本輪依其指示繼續無畫面工程，不要求其立即操作。完成runtime後再沿既有REQ-0001追加GAME_RUNTIME_OBSERVATION；未知的C2S1→S2C roster／空名單到命名／真正playable-character create仍走既有GAP/RR，不以Server-owned broker升格原生契約。
