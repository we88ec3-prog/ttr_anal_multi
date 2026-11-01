# S00 — 登入成功回覆候選與 group/channel 複製鏈補查

基線：S00 `4f00870b4cacde4715c088d3bbe8e98b8898ae5d`；Server `c41d09dc92f93229818d60730d5def8d712b6372`。本輪聚焦新帳號正常登入至教學／廣場，不執行停權等[暫緩測試](../../design/testing/TUTORIAL-HAPPY-PATH-AND-DEFERRED-TESTS.md)。

本稿是 **SOURCE_BACKED_PARTIAL／有界補查及 Server 設計候選**；不是新 T01 FULL-PASS、正式 CLM、RR ACCEPTED、SPEC STABLE 或 Client 登入成功。既有 T03 方法主責與原稿不變；不新增重複 RR／REQ，也不把工具啟動失敗登記為遊戲本身的 GAME_RUNTIME_OBSERVATION。

## 1. 來源與重現

唯讀原始 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，不是修改後測試 EXE。延續 [SPEC-AUTH-0001](../../spec/session-account/SPEC-AUTH-0001.md) 與 T03 已保存 REA：`kr-temp-roy/T03/evidence/rea-auth-followup-4c3080.json`，Evidence `ev_6dcd97bf2a64c269c70598547f4b07d92b2217b5ac3568880fa719e6f9cb57fc`、檔案 SHA256 `d628624ef9aa484f65c7dcca03b8cb1bbd8841e81da5acca214658ae0379e5cd`。

兩個 callee 的既有未全文審核偽碼及原始批次已在 bulk 保存：`functions/0x507510.c`（SHA256 `0f33451f883692b6f86227ef607b00f709fc83e000cad5fbfa38781fe2d0d29b`）、`functions/0x507610.c`（`e169a20175d16c11af197b615bffadd2a4b78c1f3faacb08f605beaa2ca4aa40`）；對應 `raw/20261025T182755495890-batch-20261025T184423681039-4304.json` SHA256 `18865faf00b5255467275cf74fe320d10f782bdde5832445a36716861a396162`，Evidence `ev_735b3aaf0a111c1edf37bcc24c51b79a9f81a05fd55cf2317832e842b9622739`。沒有把 bulk 存在當作審核通過。

本輪 REA `open_binary` 身分相符，`analyze_function(0x507610)` **300 秒逾時**，已關閉 session，不假造其成功 dossier。改用原始檔 bytes、PE section 映射及隔離安裝的 **Capstone 5.0.6** 做有限靜態核對。完整輸出：[KR-LOGIN-CHOICE-COPY-20261101.json](KR-LOGIN-CHOICE-COPY-20261101.json)；[唯讀重現工具](../verify_kr_login_choice_copy.py)：

```powershell
python -B governance/verify_kr_login_choice_copy.py ORIGINAL_KR_BIN --capstone-dir ISOLATED_CAPSTONE_DIRECTORY --output OUTPUT_JSON
```

核對結果：同版 SHA／PE32 x86 mapping、4 段完整線性 decode、17 個精確 instruction-start/bytes anchor 相符。這是 bytes/layout 核對，**不是全文 CFG／語意驗證或遊戲行為測試**；沒有宣稱新的 REA Evidence。

## 2. 解開的兩個局部問題

### Group ID 與 container index 不相等

`0x4C30BE` 將 wire group 的 WORD zero-extend 到 ECX，EDX 是 `FE1B54` manager；`0x4C30C4` 呼叫 `0x507510`。callee `0x507552` 將 group id 存進本地 row；`0x5075C0` 在 append **之前**讀取 `[manager+0x18]` 至 EDI，`0x5075CE` append，`0x5075E3` 把保留的 EDI 放 EAX 回傳。caller 保存 EAX，之後作為 `0x507610` 的 stack argument。

有界解讀：此路徑交給 child append 的是加入前的 group container count／ordinal，**不能以 raw group id 代替**。此段不證其他 caller、刪除／重排序後 container identity、或官方 group ID 政策。顯示名稱 map／fallback 仍依 raw id 查找。

### Child +9 不是 padding，+8 也不只控制是否加入

在 `0x4C3107`，wire child `+8` zero-extend 到 ECX，非零才進 append；`0x4C311A` 將 `+9` zero-extend 到 EDX。caller 中間沒有 call 改寫兩者，`0x4C312A` 進 `0x507610` 後：

| wire／引數 | callee 局部 stack write | 複製後的 child record 相對位置 |
| --- | --- | --- |
| child ID WORD | `0x507651` EDI → `[EBP-0x70]` | DWORD `+0` |
| child `+8` → ECX | `0x507654` → `[EBP-0x6C]` | DWORD `+4` |
| child `+9` → EDX | `0x507657` → `[EBP-0x68]` | DWORD `+8` |
| 格式化 IPv4 窄字串 | destination `[EBP-0x64]`，capacity20 | char 槽 `+0x0C` |
| child 名稱 map／fallback | destination `[EBP-0x50]`，capacity30 wchar | UTF-16 槽 `+0x20` |

`0x50771E` 把 `[EBP-0x70]` 交 EAX，`0x507721` 呼叫 `0x507B10`；既有偽碼／本次 bytes 顯示 append 複製 `0x18 DWORD = 0x60 bytes`。**只對表中欄位成立**，不聲稱剩餘 padding 都初始化。group/child 原始 `+2..3` 在已查 caller 沒有傳入此 append，仍保留未解，不定義為 port/load。

因此 Server serializer 必須原樣保存 raw group ID、child ID、child+2、IPv4 octets、+8 與 +9；不要將 group id 當 ordinal，也不要因偽碼少列 register argument 而丟棄 +9。+8/+9 的官方業務名稱與全值域政策仍未知。

## 3. Server 本輪可實作範圍

在私有 Server 庫新增獨立 `KrLoginReplyCandidateBuilder`，實作 application payload：

- `BuildSuccess`：`0x13`、status0、非空名稱、`+0x90=0` 的已觀察局部分支；prefix146B，group count at `+0x1C`、rows at `+0x92`。
- `BuildGroupRefresh`：`0x7A` 的 **6B** prefix，count at+2；不是 `0x13` 的別名、必要第二包或 ACK。
- 固定欄位 `+17/+18/+86/+87/+8C/+91` 由呼叫端明確提供，不從密碼、DB Guid 或 SessionLease 亂取，也不命名為已證官方 ticket。
- wire group 3B／child10B；所有 raw 欄位原樣寫入。候選中的顯示名1..9 printable ASCII、notice≤50 ASCII、narrow87≤4 ASCII、64 groups／4096B budget 及未消費 padding zero-fill，都是 **Server 候選 producer 政策**，不是官方允許值或完整 Client guard。
- 此 builder **未連入 Host、Tcp gateway 或 NativeContractAdmission**，沒有發送 fake success，沒有把 local-writer marker 當成已捕獲的 Server framing。原版 codec admission 與 normative source pin 不變。

只有兩項新的正向合成測試：一組正常 loopback channel 的 success payload、同一組資料的7A布局。與既有兩項正流程前置合計4項；198個其他方法仍暫緩。這些只是 serializer／登入前置證據，不能代替 M3 或教學／廣場。

## 4. 運行阻塞與下一個具體動作

指定工作副本 `Tartaros.ip-zh-tw-only-v2.exe` SHA256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c` 未修改。Computer Use 直接 `launch_app` 逾時；同工具能讀取 Explorer，raise 後能正常定位並雙擊指定 EXE。唯讀查到 EXE manifest 的 `requestedExecutionLevel level="requireAdministrator"`，Windows 已啟動 `consent.exe`，尚無遊戲程序／視窗。**真正阻塞是 Windows UAC 等待確認，不是帳號或 Server 連線失敗。**

使用者已授權開遊戲與要求自行排查；工具禁止代操作 Windows 身分確認，故已說明並請使用者只完成 UAC。沒有改 manifest、UAC／AppCompat 設定、注入或附加遊戲，沒有把 consent PID 當成遊戲執行證據。

下一步：Windows 確認後自行取得遊戲視窗，觀察本次唯一新帳號正常 E8/0F→現有 Host auth；按既有 REQ-0001 追加同會話去敏 GAME_RUNTIME_OBSERVATION。確認實際 scene／初包後，再審核候選回覆欄位來源、Server-owned identity／跨線交換及 TX framing，接到隔離工作副本 profile 驗證真正下一畫面。仍缺時不得把 candidate builder 宣稱完整相容 Server；保持廣場最終目標，不停在合成 PASS。
