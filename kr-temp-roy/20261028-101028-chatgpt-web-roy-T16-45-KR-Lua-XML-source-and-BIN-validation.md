# KR T16-45 — Lua／XML 原始證據讀取與 BIN 閉合邊界

- 研究者：`chatgpt-web roy`；記錄時間：2026-10-28T10:10:28+08:00
- 任務：KR T16，僅靜態唯讀；未執行目標程式、未修改資源；未 Commit／Push。
- GitHub repo：`we88ec3-prog/ttr_anal_multi`，新對話讀得最近提交 `189dfd0051e1a1a7d7162a2b62a39a47f1313f7d`（commit 搜尋清單第一筆；非 git ref 原子讀值，視為最近提交候選）；交接快照 `6cc5c85a0e693ed40c242217c613d5e0518183e5`。
- KR BIN：size `12472320` bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- EXE：size `2594816` bytes；SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。僅標記已掛載可核對來源，不推斷兩檔相同程式內容。

## 1. 確認的來源層級與已有研究

讀取本地 02 共用、03 T16 固定、04 T16 KR-only 交接；GitHub `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、`kr/tasks/T16/README.md`、`kr/tasks/T16/task.json`、T01 整合 `README.md`、`resource-source-audit.json`、`NEXT-QUERIES.md`。T16-1～T16-44 原稿已由交接確認提交，尾段 T16-41～44 的四個 commit 已在交接列出；本次未逐一遠端讀回 44 個 Markdown 全文，不能宣稱已完成逐件內容審核。`owner:null / state:unclaimed / native_complete:false`，未擅自修改。

T01 整合清單所稱 Lua prototype/instruction words 數目屬資源稽核；直到本段讀取 GitHub evidence bytecode，才能確認腳本實際常數存在。原始 XML/bytecode 分開判斷。不可從前述稽核量推導任務規則。

## 2. GitHub evidence 存取攻堅：重要新結果

- `kr/evidence/662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809.txt`：使用 GitHub `fetch_file(encoding=base64)` 成功讀取二進位，Base64 解碼 **5480 bytes**；檔頭 `1B 4C 75 61 51 00 01 04 04 04 08 00 00 00`，即 `\x1bLua` + 0x51（Lua 5.1）與 chunk header 欄位。這是實際讀到的 Lua bytecode 而非 T01 統計摘要。此證據檔的 Git blob SHA `3131bf2248949a6d06b5634eec68f818bf57cc2f`，與來源內容 SHA256 是不同 hash 命名空間。
- `kr/evidence/d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3.txt`：同樣成功讀取 bytecode，**11836 bytes**，相同 Lua 5.1 header。來源歸屬 `Event/qbase.lua`；僅直接辨識部分字串，尚未完整重建 CFG／函式閉包。
- `kr/evidence/fe0a7131118ae804897ed8255da00f4cf8bad58bbe8fcc87ca2e5676146a2555.txt`：Base64 成功讀取 KR checkpoint XML，其原始 UTF-8 內容含四個元素；此次實際辨識結構如下。
- `kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt`：GitHub connector 使用 `start_line/end_line` 可讀取實際 XML 行。已讀第 1～42 行；其中 id=13 後緊接 id=17（以已讀視窗為限），未見 id=15/16。**不能由此推論這兩個 Quest 不存在於整份 4322 children 的檔案**。
- `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`：connector 嘗試原始或 Base64 並以行界限讀取皆得到空內容；不是證明 XML 空檔，而是這次工具無法傳回正文。
- `kr/evidence/26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744.txt` 和 `unclassified/evidence/` 同名：查找結果 404，尚未取得 TutorialBase 原始 bytes。
- `kr-temp-roy/T16-local-20261028/evidence/resources/kr/Event/TutorialMain.lua`、`.../evidence/lua-static/TutorialMain.lua.txt`：fetch 回 404。歷史本地路徑不一定被 Git 追蹤。

### 2.1 TutorialMain bytecode 中逐項實見的可印字串

`g_TutoEmployCharQuery`, `g_isTutorialRunning`, `PlayAndWaitForScene`, `PrepareSynopsis`, `SynopsisMain`, `EndSynopsis`, `Tutorial_Part1`, `Tutorial_Part2`, `PlaySynopsisMain`, `TutorialMain`, `Tutorial_EntryPoint`, `StartCutScene`, `IsCutSceneRunning`, `SetKeymapEnabled`, `PushCamera`, `RegisterSkipMessage`, `UI/ImageSets/Scenario_Skip.dds`, `PlayMusic`, `PostUIMessage_TutoMsg`, `TUTORIAL_PROGRESS_NUMBER`, `TUTORIAL_CHANGEKEYTYPE`, `GetTutorialState`, `TUTORIAL_KEYBOARD`, `InsertTutorialCheckPoint`, `SetCheckPointStatus`, `CHECKPOINT_CATEGORY`, `TUTORIAL_POINT`, `CHECKPOINT_STATUS`, `TUTORIAL_MOUSE`, `TUTORIAL_CAMERA`, `TUTORIAL_LEADER_CHANGE`, `TUTORIAL_LC_DLG_OPENED`, `TUTORIAL_GOTO_NPC`, `RequestStartScenario`, `IsScenarioEnded`, `TUTORIAL_PINKOHOUSE`, `TUTORIAL_STARTSCENARIO`.

**證據分類：原生已確認的是 Lua 常數／識別符存在；其動態呼叫次序、參數、分支條件、伺服器接收後的效果未完成完整指令級解碼，暫列待驗證。** `RequestStartScenario` 與 `IsScenarioEnded` 兩者同時存在不等於 Quest16 完成。`SetCheckPointStatus` 不自動代表 server writer。

### 2.2 qbase bytecode 中直接實見的代表字串

`f_doCoTask`, `g_scenePlaying`, `OnEndTalk`, `PlayCameraNoWait`, `PlayCamera`, `PlayMusic`, `StartLoading`, `EndLoading`, `PlaySound`, `PlayTalkSound`, `doCoTask`, `EndCutScene`, `IsEnded`, `Event/CameraWorks/`, `ScenarioTalkTable`, `StartSepia`, `EndSepia`, `StartSlowMotion`, `EndSlowMotion`, `DisableObjRender`, `EndCameraOverride`, `EnableObjRender`。

**證據分類：原生已確認字串，僅支持場景／過場協程或 API 界面的存在，沒有 Quest16/15 原版依賴結論。**

## 3. KR TutCheckPointList.xml 原文結構（實際讀取）

```xml
<TutCheckPointList>
  <CheckPoint id="1" x="311" y="149" range="30" active="1" effect="TUTPOINT" />
  <CheckPoint id="2" x="360" y="170" range="30" active="1" effect="TUTPOINT" />
  <CheckPoint id="3" x="383" y="315" range="100" active="1" effect="미사용" />
  <CheckPoint id="4" x="440" y="394" range="20" active="0" effect="TUTPOINT" />
</TutCheckPointList>
```

上述只摘出與機器可用欄位；原始 XML 還有韓文 `comment` 欄。`active=0` 第四節點的具體引擎是否忽略，尚待消費函式證據；這四個 CheckPoint 不必然等於完整 tutorial 節點數或全部劇情狀態。

## 4. QuestTalk.xml 實際開頭證據與 ID 邊界

已讀行中：`<Quest id="13" givertalk="387" givertotalk="389" finishertalk="390"/>` 後面是 `<Quest id="17" givertalk="2216" givertotalk="2219" finishertalk="2220"/>`。這表示 QuestTalk 已讀順序在該處跳過 14～16，但 XML 中 `QuestTalk` 對話映射不等於 `QuestInfo` 任務定義，也不能當作任務不存在或無法接取的證據。對話 ID `givertalk/givertotalk/finishertalk` 是獨立引用欄位，未見足夠依據與 Quest state ID 合併。

## 5. KR BIN PE header／VA→raw 驗證

從本次直接讀取 KR `Tartaros.bin` PE32：image base `0x00400000`。section：

| Section | RVA | VirtualSize | RawPointer | RawSize |
|---|---:|---:|---:|---:|
| `.text` | `0x1000` | `0x7D01F0` | `0x400` | `0x7D0200` |
| `.rdata` | `0x7D2000` | `0x18E07C` | `0x7D0600` | `0x18E200` |
| `.data` | `0x961000` | `0x2873D8` | `0x95E800` | `0x22B800` |
| `.rsrc` | `0xBE9000` | `0x5AF58` | `0xB8A000` | `0x5B000` |

`.data` VirtualSize 大於 RawSize 表示尾端有記憶體未初始化範圍；不可將其當作檔案 bytes 或整段有等值 PE raw 映射。

| BIN VA | Raw offset | 開頭 20 bytes（Hex） |
|---|---|---|
| `0x4A89C0` | `0xA7DC0` | `55 8b ec 6a ff 68 7e a4 93 00 64 a1 00 00 00 00 50 57 a1 20` |
| `0x4A8A60` | `0xA7E60` | `55 8b ec 6a ff 68 4c a4 93 00 64 a1 00 00 00 00 50 83 ec 08` |
| `0x4A8B90` | `0xA7F90` | `55 8b ec 83 ec 18 53 8b 5d 08 8b 03 56 57 68 d4 68 c0 00 6a` |
| `0x6F4A50` | `0x2F3E50` | `55 8b ec 83 e4 f8 81 ec 2c 02 00 00 a1 20 1f d6 00 33 c4 89` |
| `0x6F4DD0` | `0x2F41D0` | `55 8b ec 83 e4 f8 83 ec 14 53 56 57 8b f8 8b 37 8b 45 08 8d` |
| `0x504740` | `0x103B40` | `55 8b ec 83 e4 f8 6a ff 68 3d 42 92 00 64 a1 00 00 00 00 50` |
| `0x505570` | `0x104970` | `55 8b ec 83 e4 f8 6a ff 68 7b 28 92 00 64 a1 00 00 00 00 50` |

### 5.1 入口函式新一輪原始機器碼檢查

`0x004A89C0`：

```asm
004A89E3 lea edi,[esi+0x14]
004A89E6 mov dword ptr [0x00FBA7A0],0
004A89F0 call 0x00851420
004A89F5 test byte ptr [0x00FB7354],1
004A89FC jne 0x004A8A25
004A89FE or dword ptr [0x00FB7354],1
004A8A0C call 0x005533D0
004A8A11 push 0x00BCD100
004A8A16 call 0x0089231A
004A8A25 mov dword ptr [0x00FB73B4],1
004A8A31 push 0x00C0687C
004A8A36 call 0x006F4A50
```

此段 `push 0xC0687C / call 0x6F4A50` 是**原生已確認**的 loader 調用路徑；字串實際值需對 rdata 指向位元組解碼，不能只憑呼叫流程稱為 Quest state writer。

`0x004A8A60`：

```asm
004A8A87 lea edi,[esi+4]
004A8A8A mov dword ptr [0x00FBA7A0],0
004A8A94 call 0x00823850
004A8A99 lea edi,[esi+0x14]
004A8A9C call 0x00851420
004A8AA9 test byte ptr [0x00FB7354],bl
004A8AAF jne 0x004A8AD3
004A8AB1 or dword ptr [0x00FB7354],ebx
004A8ABE call 0x005533D0
004A8AC3 push 0x00BCD100
004A8AC8 call 0x0089231A
004A8AD3 mov dword ptr [0x00FB73B4],ebx
004A8AD9 test byte ptr [0x00FAADD4],bl
004A8ADF jne 0x004A8AFF
004A8AE1 or dword ptr [0x00FAADD4],ebx
004A8AEA call 0x00587480
004A8AEF push 0x00BCCCC0
004A8AF4 call 0x0089231A
```

實見初始化 guard／跨呼叫路徑；未有直接證據指出 `0x00FB73B4` 是任務完成位。這是原始 bytes／反組譯驗證，不等於全函式 CFG 還原。

`0x006F4A50`：

```asm
006F4A6A mov eax,[ebp+8]
006F4A78 sub edx,eax
006F4A80 mov cl,[eax]
006F4A82 mov [edx+eax],cl
006F4A85 inc eax
006F4A86 test cl,cl
006F4A88 jne 0x006F4A80
006F4A8E push 0x00BED1E0
006F4A93 push edx
006F4A99 call 0x00714770
006F4AA3 test edi,edi
006F4AA5 je 0x006F4BCF
```

這些指令顯示路徑字串複製後呼叫資源查找／開啟候選；`0x714770` 精確語義及 script bytes loader 還要追下游。`0x006F4DD0` 入口可見字串長度迴圈與 `call 0x006FEC70`，僅可列具名 Lua 呼叫候選。

`0x00504740` / `0x00505570`：函式入口分別透過 `mov ecx,0x00C0DB48 / call 0x0072EE30` 和 `mov ecx,0x00C0DB5C / call 0x0072EE30` 建立兩條 XML loader 相關路徑，兩者確實不是相同全域物件；具體 XML schema、Quest state 消費者仍不可倒推。

## 6. 需閉合的 Quest16 → Quest15 狀態矩陣

| 邊界 | 已取得第一手原件 | 目前證據結論 | 關鍵缺口 |
|---|---|---|---|
| 教學 script 入口 | BIN 0x4A89C0/0x4A8A60；TutorialMain Lua bytecode | 局部確認 | bytecode instruction→condition CFG、callback 實際順序 |
| checkpoint | TutCheckPointList 4 個節點；TutorialMain 常數 | 部分確認 | checkpoint 寫入與事件回調的實際參數／狀態作用域 |
| tutorial 開始關卡 | TutorialMain `RequestStartScenario` 與 `IsScenarioEnded` | 部分確認 | scenario ID、result validator、關卡回傳；T07／T14 主責 |
| server Quest16完成 | 目前無 server writer 原始證據 | **資訊缺失** | quest namespace、packet、權威轉換、持久化 |
| Quest15可接 | QuestTalk 的部分 mapping；QuestInfo 尚未讀到 | **資訊缺失** | QuestInfo 15/16 原件節點、前置／NPC／場景／通知 |
| 中斷重登 | 無經驗證任務級 snapshot | **資訊缺失** | server snapshot、T15 保存介面及恢復後事件 |

沒有任何一條證據足以將 `scenario14 → server Quest16 done → Quest15 available` 宣告已閉合。原版 `005F type6` 不得等同歷史 Tutorial patch。

## 7. DEFERRED-LOCAL-RESOURCE

1. `DEFERRED-LOCAL-RESOURCE`: `Event/TutorialBase.lua`, SHA256 `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`, 本地 `kr-temp-roy/T16-local-20261028/evidence/resources/kr/Event/TutorialBase.lua`；GitHub `kr/evidence/<SHA>.txt` 及 `unclassified/evidence/<SHA>.txt` 均 404；缺完整 Lua 6 prototypes/72 instructions、callback 和條件。
2. `DEFERRED-LOCAL-RESOURCE`: `Table/QuestInfo.xml`, SHA256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`, 候選 GitHub `kr/evidence/<SHA>.txt` 及本地 `.../Table/QuestInfo.xml`；connector 指定 1～12 行仍回空；缺 15/16 原件節點和依賴欄。
3. `DEFERRED-LOCAL-RESOURCE`（部分）：`Event/TutorialMain.lua`, SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`, 已讀完整 bytecode bytes、常數；**尚未完成各 prototype 指令解譯與 CFG**，不是資源不可讀。
4. `DEFERRED-LOCAL-RESOURCE`（部分）：`Event/qbase.lua`, SHA256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`, 同上。
5. `DEFERRED-LOCAL-RESOURCE`（部分）：`Table/QuestTalk.xml`, SHA256 `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`, 已讀指定開頭行；仍需定位 15/16（可能缺 mapping）與其他直接關聯項，不能從局部無命中下定論。

## 8. 下段接棒順序

- T16-46：將已可讀 TutorialMain/qbase Lua 5.1 bytecode 依大小端、prototype、opcode、constant map 完整解析；重建教學 callback／`GetTutorialState`／`RequestStartScenario`／checkpoint writer 的實際 data flow，並與 `0x004A89C0`、`0x004A8A60` 的 loader named call 對應。
- T16-47：再攻取 QuestInfo XML 指定行／本地素材，定位 Quest16/15 定義、NPC/scene/前置；QuestTalk 只當對話域，不取代 QuestInfo。
- T16-48：綁定 client notification→writer→server authority，從 T02/T14/T15 已驗證界面引用，不變更別的 Task。

本文件為 T16-45 本次原始技術研究記錄，非完成整個任務或全部 Lua 函式分析的宣稱。
