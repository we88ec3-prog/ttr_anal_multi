# T01-20261028-20 — 連續驗收達成 10 份 FULL-PASS（限定各原稿自身正面主張）

> **判定基準非常重要**：FULL-PASS 代表此原稿**自己有界且肯定提出的技術主張**全部在現有 KR BIN 原始 bytes / 局部 CFG / rel32 / 字串資料下獲得可重現驗證，原稿明確寫作 unknown、推測、後續研究或缺失原件的內容保持原狀。**不是整個 Task、整個遊戲機制或原版 Server 已完整還原。**

## 環境、方法與獨立驗證

- 唯讀原件：`/mnt/data/Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。兩者本輪直接 sha256sum 驗算一致；沒有執行或 patch 遊戲。
- PE32 .text VA 0x00401000/raw 0x400，`.text` 內 VA→raw = VA-0x00400C00；非 text 位址依獨立 .rdata/.data mapping。
- 本輪執行 Python assertion 與唯讀 objdump，**56 項校驗全數相符**（包含多項完整 raw E8 目標候選集合、4-byte 地址引用、原始字串、具體 opcode bytes）。所有 E8 byte scans 明確只宣稱候選集合，不宣稱 scan hits 都有可執行 CFG 邊界。
- GitHub `main` 本輪再次逐檔 fetch 下表 **10/10 blob SHA 相符**；不覆寫 T08/T10/T16 原稿、不改 owner、catalog 或他人資料。
- 已核實的 T08-178 原有 FULL-PASS 經本輪 bytes/callsite 再覆核；其餘九份是從尚未 FULL-PASS 的候選中逐一進行本輪有界主張級驗收後採認。

## 逐份原稿與 FULL-PASS 主張矩陣

| # | 原稿（Git blob SHA） | 實際驗收的肯定主張 | 本次直接第一手證據 | 沒有越界宣稱的未知 |
|---|---|---|---|---|
| 1 | [T08-178](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-178-mode-two-container-callback-boundary.md) `a338ee89963c817f50010ddec3a2985d6603beee` | 模式啟用／停用兩集合的遍歷順序、+0x44/+0x30、vtable+4/+8 位置、直接 E8 候選。 | 0x7B7FFE b9 01 00 00 00；0x7B8006 89 4A 44；0x7B8045 e8 a6 51 02 00；0x7B804A c7 46 44 00 00 00 00；E8 targets 0x7B7FD0=1/0x7B8030=1/0x7DD1F0=2。 | 動態 vtable 實作、容器真實類型及 runtime 時序原稿列 unknown；未升級。 |
| 2 | [T10-089](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-089-event-container-callers.md) `b9522feee0464b68ead6ff1ea09f84e09a168510` | 0x6D4A30 的兩個直接 caller 使用不同來源容器；新建 0xC 自連結節點；其指令為清零非 phase=1/3 producer。 | 0x490DFC e8 2f 3c 24 00；0x58A607 e8 24 a4 14 00；0x58A5D1 6a 0c；0x6D4A93 33 c0；0x6D4A9C a3 04 90 fb 00；全段 E8 指向 0x6D4A30 僅兩處。 | 全域容器真正 producer、KeyMapping 上游與 phase 非零 writer，原稿明列未知。 |
| 3 | [T10-090](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-090-fb73e8-reader-audit.md) `d232cee52ae99734bdae7229a5c1e0e9f2451bd5` | 0xFB73E8 的 18 筆原始直接地址參照、初始化 zero store、getter 與狀態消費分支；不把 read 稱為 writer。 | 18 筆 xref 指令起點逐一與原稿相同：首 0x4A97FE，末 0x5A4614；0x560197 xor ebx,ebx；0x560239 mov [0xFB73E8],ebx；0x4A97FE mov eax,[0xFB73E8]；0x5A4614 cmp [0xFB73E8],ebx。 | 指標別名/間接 writer 不在 raw literal 枚舉；未推論旗標永遠為零。 |
| 4 | [T10-091](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-091-conditional-child-selector.md) `6f76c33948d04582983855a574dabe64eb185599` | 0x761010 有條件遍歷三個 bit，命中返回 node+8，否則 NULL；0x5961C0 caller 與 phase 1/3 回呼偏移。 | 0x761010 cmp [eax+68],0；0x76102C shr edx,19、0x761036 shr edx,8、0x76103E shr ecx,12；條件 !bit19 && bit8 && !bit12；0x5961EF call 0x761010；0x596275 vtable+0xEC、0x5962CE vtable+0xF0。 | 動態 override 與 gameplay motion 未確認，原稿無正面命名主張。 |
| 5 | [T16-53](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-53-KR-quest-native-string-xrefs.md) `8329a3d73f7b1cbf543e07a936bf46927bed6913` | 五個 Quest/Tutorial 原生字串及所記 raw/VA、引用位址一一相符；只計 byte-reference。 | TutoQuest raw 0x80D7A4/VA 0xC0F1A4/ref 0x532248；HasQuest 0x80DAEC/0xC0F4EC/ref 0x53FD85；HasCompletableQuest 0x80DAF8/0xC0F4F8/ref 0x53FD93；HasScenario 0x80DB0C/0xC0F50C/ref 0x53FDA3；RequestStartScenario 0x968568/0xD6AD68/ref 0x4AB8F9。 | 原稿 ASM 空視窗未視為證據；並未宣稱已確認 instruction boundary、Server 持久化。 |
| 6 | [T16-54](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-54-KR-tutorial-lua-direct-call-xrefs.md) `319c873eab18f80db3c464df38b51ab396dc80a7` | 五個目標的 raw E8 rel32 callsite 候選集合全部匹配，且按原稿聲明維持候選級別。 | 0x4A89C0：0x47BACE、0x4C1FFC；0x4A8A60：0x4C4D3F；0x4A8B90：0x47CA45、0x4C19AE、0x4C4E8A；0x6F4A50：15 sites；0x6F4DD0：0x4A8A46、0x4A8B74、0x5615D8；全部直接 byte scan 重算目的地一致。 | 原稿空 asm 區塊不視為完成 caller CFG；無 Lua 原文不驗具名腳本語義。 |
| 7 | [T16-55](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-55-KR-quest-loader-caller-evidence.md) `d8100e0a7989a4cc7619b6bf1796e2b0cab9d54d` | 兩個 reader 候選函式有相鄰的原生 direct call，原稿不把它推定為 server quest authority。 | 0x5043E9 e8 52 03 00 00 → 0x504740；0x5043EF e8 7c 11 00 00 → 0x505570；完整局部反組譯順序是 push edi、call 第一、push edi、call 第二。 | QuestInfo/QuestTalk id15/16 仍缺完整 XML；不推論任務先後。 |
| 8 | [T16-65](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-65-KR-FE187C-writer-callback-initialization.md) `c248ef57f8604d09ed0020c69533b236881cfd5e` | callback slot 靜態 setter、兩處全段 literal xref 與轉發鏈正確；只確認初始化已發生時能到候選 callback。 | 0x4AB8B8 c7 05 7c 18 fe 00 d0 a4 4a 00；0x4ACA16 8b 0d 7c 18 fe 00；0x4ACA20 call 0x4ACB70；slot literal bytes 只在 0x4AB8BA、0x4ACA18 出現；0x4AB90E call 0x6F55B0。 | 其他 alias writer、初始化次序、server ACK 原稿已標 unknown。 |
| 9 | [T16-66](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-66-KR-scenario40-message-dispatch.md) `fd1b40e6dfddc4eb4fd88d7515c6f70f5d674a44` | 0x4AA4D0 局部 4-byte buffer [0x0040,low16(value)]、0xFBA798 gate、虛方法 +0x10 的呼叫資料流、ret 4。 | 0x4AA4D4 83 3d 98 a7 fb 00 00；0x4AA4DF b8 40 00 00 00；0x4AA4E8 66 89 4d fe；0x4AA4F6 [vptr+0x10]；0x4AA501 ff d2；0x4AA506 c2 04 00；0x4ACBCA ff 55 08。 | socket/wire opcode、scenario14 結果以及實際 vtable target 未證；原稿均保留候選。 |
| 10 | [T16-67](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-67-KR-scenario-dispatch-state-versus-quest.md) `21e9facd60a283e4b9f097937b98b91defbdb53e` | 0x4AA5A0 對兩個不同 global slots 的 stores、0x4A8680 局部 vector 操作與 0x53FF09 呼叫鏈，未與 quest writer 合併。 | 0x4AA5AB a3 04 18 fe 00（[FE1804]=eax）；0x4AA5B7 89 1d 00 18 fe 00（[FE1800]=ebx）；0x4A8680 56 8b f0；0x4A86D6 83 47 04 04；0x53FF09 直接 call 0x4A8680。 | binding object 身分、S2C/Quest 進度與 XML 原件仍標 unknown。 |

## 驗收與證據門檻

1. **證據完成**：逐項列出的局部肯定主張有直接 BIN bytes/rel32/data flow；沒有把「只在文件裡出現」算驗證。
2. **候選不變正式結論**：T16-54 和 55 的 E8 xref 僅為原稿宣稱的 byte candidate／局部 caller；未憑 byte scan 宣稱整個 CFG、Lua event 或伺服器實作。
3. **負面結論精確限制**：T10-089 的 reset 不是正面 phase producer；T10-090 的唯一 literal 寫入 0 不代表全部間接 producer 不存在。兩份原稿的 unknown 判定及邊界均維持。
4. **嚴格保留原稿中的缺口**：T08-178 的 vtable 真正目標/型別/並發時序；T10 的 phase 非零 writer、dispatch override；T16 的 Quest 15/16 XML、Lua bytecode 原始語義、S2C/C2S wire chain、server-side Quest authority，都沒有得到假想的「通過」。
5. **完全通過的意思**：每份原稿所有肯定的**有界、可獨立審查的證據主張**通過；原稿自己未宣稱完成的未來研究項目不作為該份原稿的驗收缺陷。若後續取到矛盾的直接 bytes，應追加仲裁更正並重新分級。
6. **不算在 10 份的原稿**：T08-173 的入口曾遭 T08-177 更正，其他整體 actor/resource ownership 承諾較廣的原稿仍要更深 closure，本批未為湊數自動宣告它們通過。

## 直接證據復查範例

```sh
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -D -Mintel --start-address=0x761010 --stop-address=0x761057 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x4aa4d0 --stop-address=0x4aa509 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x4acb70 --stop-address=0x4acbe3 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x7b7fd0 --stop-address=0x7b8081 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x5043dc --stop-address=0x5043f4 /mnt/data/Tartaros.bin
```

## 可供下一次 T01 接手的狀態

- 本次 **SUCCESS：10 份限定範圍的 FULL-PASS 原稿**：T08-178；T10-089/090/091；T16-53/54/55/65/66/67。
- T01-07 收錄其餘 **70 份**仍按既有來源登記及尚未全部主張驗證的狀態，不因這批 10 份成功被一併提升。
- 早期 T01-013～018 的 PARTIAL-PASS 不算此批已完成，且未因這份報告改寫其原稿證據。
- 下一批應由尚未通過且主張範圍清晰的 T08/T10/T16 文檔開始；因缺資源的完整 Quest 流程仍維持 deferred。
- 本次只新增 T01 自有 integration 驗收報告；不更改 `shared/source-review-status.json`，因該共用狀態檔可能將「限定文件主張通過」誤解為「整體原生功能完成」。
