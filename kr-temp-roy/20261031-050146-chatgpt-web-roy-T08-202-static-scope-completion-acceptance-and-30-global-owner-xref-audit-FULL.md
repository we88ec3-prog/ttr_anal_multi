# KR T08-202 — 原訂000A/Controller/26-81/reset靜態研究終點、30處owner-tree引用原生審計與正式段號完工判定

**作者** chatgpt-web roy，2026-10-31 05:01:46 Asia/Taipei。**證據基準** Tartaros.bin（12,472,320 bytes）SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪本機重hash一致。PE32 `.text` VA0x401000 raw0x400 ⇒ code raw=VA−0x400C00，`.rdata` VA0xBD2000 raw0x7D0600。以第一手PE machine code、全.text常數引用、vtable .rdata DWORD、direct E8/indirect virtual target、rooted CFG驗證。沒有執行或改寫Client、沒有原版Server內部資料，T01 FULL-PASS、S00規格與遊玩驗收分別列示。

## 0. 為什麼現在可以判定 T08-202「原訂有界靜態研究題」完成

以原始202交接 `/mnt/data/04-T08-NEXT-CHAT(10).md` §7 當時文字為來源，段號202必須回答：**000A怎麼寫Actor/owner關聯、哪些Controller持有Actor、26/81/reset如何解除、P+4/P+8在Actor刪除後誰寫/誰清、8-byte pair是否真的被使用**。應以已證/未知界線明確區分；**不得擅加「窮盡整個13MB Client所有未知virtual function與任意衍生型別」當成一個段號的必要條件**，但對此目標相關的真入口、寫入者、消費者、移除路徑不能留關鍵斷邊。

本次在已交付前置202研究後，實際找到之前缺少的最重要 downstream：
- local index10在特殊owner情況入列Controller 8-byte pair，**0x5452C0於0x5459B7起第二pass真實讀取並使用這個pair**，而不是僅在0x545390做index tree lookup；第一WORD對主Actor tree，第二WORD於0x545A86傳給Controller virtual+0x44 → 六型別均為0x546EF0，依目標Actor與目前Actor位置/狀態生成output flag。
- Controller tick 0x545B0E寫4byte+0x545B10寫1byte成5byte entry，若有記錄，0x545B71送至原生CIocpNetwork enqueue；前輪已證queue→mode2/XOR/checksum或fallback mode0→WSASend→成功GQCS消費同一Connection ring（條件性Client出站）。
- index7與index10 P+4/+8寫入均是**numeric actor key/composite值**，不是Actor*；index8新P初始化0，**同key刷新不清數值綁定**。命令26/81刪主Actor**沒有在本路顯式重寫P+4/+8**，而非必有漏free。讀P+4的Scene::CDuelDecision及4D6F00/4D70AB會**重新從有效Actor tree查找**，並有sentinel和payload guard；資料生命期需區分數值可能舊、P記憶體已free和真的Actor指標。
- 命令26在3 raw slot匹配WORD ID時才先Controller slot+14 logical clear，然後主Actor tree erase；命令81是Actor+88 composite key，直接call Actor自己的vptr+14 resource cleanup+deleting destructor、RB-tree erase，**在該本地caller無直接Controller slot+14**；不能宣稱不存在任何資源回調。另指定P `4BBAE0→4DFC30` owner+F8 cache invalidation、free P與P RB-node；reset16 (type0)刪主Actor、Controller slots、owner+F8，`4E1070`釋放全部P，二者和26/81不同。
- CCharacter、CMonster、CNPC、CEventObject四種0007 Actor ctor/vtable+14已證；CMonster的Actor+15C為CDoll，其child+8 interface vptr C4F6B0 +8是**7A57C0**的資源清理，非Controller slot14。六種Controller的slot14與deleting destructor不同；真正Controller析構繞回`544E80`釋放+48歷史H-tree、另一+88 tree及pair容量。既有`545040`負責slot指標與H樹建立／刷新；slot14只logically reset pair.end，不free H。這回答原訂「哪些Controller持有Actor、如何解除」在**已知原生型別/分支**中的可驗邊界。
- Scene::CDuelDecision primary vptr C070CC +30=4BD600，透過global P secondary tree查P+4數值ID，再查Actor主樹，有條件寫Scene+5EE0/+5ED0／Child+5EE8；補足原先P只有writer、沒下游consumer的斷鏈。其UI渲染具體時序仍跨T06/T07/T14。

**完成範圍嚴格限定**為以上 Client original KR 已發現 handler、已知Controller/Actor型別與具體scene消費者的條件性靜態功能鏈；不將所有未見Callback全球性副作用改稱「沒有」、不宣稱同幀/多執行緒無race，也不要求原版Server內部策略、runtime遊玩已驗證。下列仍未知事項是可延伸之**未覆蓋範圍或跨Task**，不是用假資料補齊202本來承諾的單一路徑。

## 1. 附加完整 `.text` 所有直接 `0xFAB148` literal xrefs：30/30 原始BIN定位

本次以原始BIN `.text` bytes `[raw0x400,raw0x7D0600)` 搜尋立即 little-endian `48 B1 FA 00`，精確得到**30個匹配**。所有匹配都可對照rooted GNU objdump有效指令，而不是把BSS或.rdata任意DWORD當callsite。按指令真VA分類：

|類型|全部真PE指令起點|數量|已證有界作用|
|---|---|---:|---|
|直接push全局P tree地址→`4E1070`|`42447A,48C4F5,4AF595,4BB65C,4BBD22,4BCD0B,4BE5E1,4C173B,4C33A5,4C4C11,4C5ADA`|11|按不同global/scenario/reset支線整樹清理，會free P資料及調整sentinel/count；不是只在index16清|
|mov ECX global P tree→`8438C0`查找|`4AE9EE,4AEC5A,4AF0A0,4AF612,4B06FF,4BD6FF,4D6F00,4D70AB,5086E8,54B95D,695476,6AEDA7,6C19B4,6C1A20,6C65B1,6C66E1`|16|P tree各場景讀者／handler、lookup，不能把所有node+10都視同寫P+4|
|其它P tree direct operation|`4DF124,4DF13B,6C646B`|3|tree析構/iterator/封裝讀取，另需按指標種類個別判斷|
|**總計**|**以真PE正確.code VA逐位元組重算**|**30**|**直接literal引用完整枚舉，不是所有間接別名引用的窮盡證明**|

**區分指令與立即值起點**：上列29筆指令中，地址立即數均從指令起點+1位元組；但 `4DF124 mov [ebp−0x18],0xFAB148` **立即數從指令起點+3** (`4DF127`)，不可通用「-1」回推；本輪Git驗證程式有特別判別。全部30筆原始 bytes的即時值位址集合與上列 `site+(3 for 4DF124 else 1)` 全部相同。

**新增實際P其他欄位的Client outbound readers**：
- 0x6C65B1進P-tree lookup，成功後`6C65C7`node+10=P，`6C65CE mov esi,[P+0]`讀P key，在gate `[0xFBA798]==0`下構造本地 `WORD 0x00C3` + DWORD key 共**6 byte**，`6C6616`呼叫`CIocpNetwork vtable+0x10`，push6等參數；**這是Client本地產生封包的證據**，不擅稱原版Server接受/處理業務opcode C3。
- 0x6C66E1同樣lookup P，`6C66F7` node+10=P，`6C66FE movzx esi,word [P+0x14]`，在gate通過後構造 `WORD 0x00C5` + `WORD(P+0x14)` 共**4 byte**，`6C6749`呼叫同網路enqueue；該P欄位**不是P+4/+8**。這反證把Owner P簡化成「僅0/+4/+8」的過度扁平化。
- 0x695476 lookup成功node+10=P，查看 P+0x28及+0x29兩bytes，透過其它物件vtable+0x94通知兩個狀態。0x6C19B4及6C1A20各lookup P後按條件進另一個動態switch/回調，不能把它們全標“完全無副作用”。這些路徑是本段保留的有界跨業務擴充，而非主Actor ID鏈的未證直接寫入者。

其它已見P+4數值讀者：`4BD728` Scene::CDuelDecision及`4D6F2C/4D70D7`均由node+10=P取得；經main Actor tree查Actor而非直接把DWORD當Actor*。**不聲稱所有可能的callbacks或memcpy都不會改P+4/+8；只證這30個原始全局直接literal站點及逐個主要P身份。**

## 2. 可重現原始BIN核驗（與研究結論不是同一層次）

同輪在本機原始BIN執行過**兩個獨立審核程序**：
1. `t08_202_verify.py` 原生 code：58個指定code byte anchors **PASS**，另外獨立核對錯位反例`545A93`，新Git驗證腳本合計**59個code byte anchors**；CController/CEmpty/CMission/CSingle/CTutorial/CTag的vptr+44六個DWORD均546EF0及CDoll offset+8子vptr C4F6B0+8 DWORD 7A57C0，共7個 **PASS**；三個E8 signed rel32真目標 **PASS**。特別檢出並修正 `545A93`不是`FF D2`，正確虛擬call是`545A97 FF D2`。
2. 獨立實作依 `.text` bytes查 `0xFAB148` 小端即時值：**30/30真指令即時數址PASS**，其中11 reset、16 lookup、3 other；已排除 `4DF124`立即數+3誤映射。

可在有相同SHA完整原件的工作站重跑已提交 [T08-202-native-final-reference-audit.py](T08-202-native-final-reference-audit.py)，精確檢查hash、30直接引用、58bytes、7 vtable slots、3 direct E8 edges。**新提交的本Python腳本作者側通過等價獨立本機Python測試組合；遠端GitHub/CI目前沒有執行該腳本的驗證結果，不寫「CI已PASS」。** 任何match只證當處bytes與直接指標，不能取代T01對整篇CFG/ABI語義FULL-PASS或遊玩。

## 3. 202原始目標逐項可交付核對矩陣

|原訂研究問題（202交接）|已完成的Client靜態證據|限定前提/不得外推|
|---|---|---|
|000A資料來源、Actor+98/+9C與owner P+4/+8|4AF920 B+2 owner、B+6 signed count、2WORD pair、special idA!=idB 分支；一般首列P+4/+8寫入、Actor+98/+9C更新|local index10 ≠已由T02獨立證實的完整wire business domain|
|000A特殊pair如何生效|5451D0→4FC620 8B row、5452C0第二pass 5459B7→545A86→Controller virtual+44=546EF0→5byte entry→CIocpNetwork|有控制器gate/Actor有效性/容量限制；不能當每幀必定發包|
|0007 Actor建立及record+4/+8綁定|4AE4D0 row26B, type0/1/6/7 ctor, 4AEC83→4C6E50在P+4==0時綁定；index8 P的真new/refresh；P readback Scene/4D6F|type IDs/packet per-row作用限原件已解分支；未核型別不得臆稱|
|哪些Controller持有Actor、歷史H與pair誰清|六種已知Controller primary vtables；545040三raw slot、H+48 tree建/改；slot14一般/Tag logical clear pair.end；真正析構各自到544E80 free H+48/+88/pair|slot14不是deleting destructor；不同type flags不同|
|26與81指定Actor移除、P是否同步清零|26匹配slot才Controller.slot14→4DFBC0；81 Actor+88 composite→Actor vptr+14/析構→7B6890；這兩條**不直接寫P+4/+8**，P另由4DFC30刪或4E1070 reset free|P+4/+8是數值ID；既有record可保留舊key，真Actortree lookup有guard；無法推出全Client所有callback無副作用|
|重要Scene及Client出站consumer|CDuelDecision vptr+30=4BD600讀P+4→Actor main tree→Scene+5EE0；其他P+4 key讀者；0x545B71→queue→framing→WSASend→GQCS成功消費|Scene具體畫面render、Server實際收包/業務裁決屬獨立驗收|
|三類非P同offset假writer|4BBDFF/4BBE02屬malloc0x18其他物件；4C1897/4C346F屬Controller+4；30個直接全局P tree literal站點核對|不把「未看到」變全Client排他定理|

**正常完成狀態**：上述**202原訂有界Client靜態功能鏈及移除責任邊界已具原始PE證據**；作者因此將正式**T08-202 = FINISHED (BOUNDED_STATIC_ANALYSIS)**，即本段的有界原生研究完成，**不是**T08 Task整體`native_complete=true`、不是T01整篇FULL-PASS/RESOLVED、不是S00 RR ACCEPTED、不是Server已實作或實機可玩。其餘跨領域/全域排他事項應作後續新目標，不假寫成本篇已證否定。

## 4. 已完成的scope與必須保留的下一題／Server-only及整合未知

**A. Client新研究可擴展（不是本段已證）**：①不直接常數引用P樹、而經owner+F8 cache、其他封裝成員、virtual callback、bulk copy取得P*的全程書寫及讀者全集；②CDoll子resource在7A57FF等虛擬調用的全型別下游及跨owner side-effect（已證直接CDoll+8 target7A57C0，不等於遞迴全部）；③Controller+48 H-tree在其它場景內的局部erase/rebind與同步可見結果；④更多場景class/renderer下游及各實例實際tick的runtime timing。這些**在本篇不寫成「不可能存在」**；如果新RR明確要求全Client排他性，須另以原件繼續做全域別名/CFG，不用202的限定完成標籤擋住後續研究。

**B. Server待開發（不得作Client阻塞藉口）**：玩家生成、死亡時機、關卡波次、控制權授權與重試，原版Server內部規則未知；相容Server依已核Client契約自行設計，並由S00記SPEC/ADR，不能由類別名或pair輸出推官方規則。

**C. 跨Task**：T02確認socket framing/decoder與本地Handler index跨domain對照；T06/T07/T14確認Spawn→Scene/UI可見結果與事件。已有Client資料鏈可供S00使用，但沒有接收側全域wire完整驗收的來源不能稱官方wire全部還原。

**D. 待實機/玩測**：使用者合法授權之Client執行測試、丟包/延遲、回收競態、Server相容操作；靜態有界研究的FINISHED不等於這些已PASS。

**E. T01**：原24篇legacy退回作者端已補24份v3，T08工作分支標READY_FOR_REVIEW，主審main仍可NEEDS_FIX；5筆其他語義退回待T01複驗。研究者不修改T01主審台帳，也不將此FINISHED當作T01 FULL-PASS。

## 5. 精確來源索引／完稿禁止混成其它段

- 既有正式201最完整的P-record、CMonster/CDoll建立原稿。
- [202此前P/init/0007/000A/26/81研究](20261031-043540-chatgpt-web-roy-T08-202-native-owner-record-0008-0007-000A-and-26-81-lifecycle-analysis.md)：建立、寫入與刪除根鏈。
- [四Actor RTTI/六Controller真正析構](20261031-044016-chatgpt-web-roy-T08-202-four-native-Actor-RTTI-virtual-cleanup-and-Controller-H-tree-destructor-evidence.md)。
- [Scene::CDuelDecision P+4 consumer](20261031-044536-chatgpt-web-roy-T08-202-Scene-CDuelDecision-actual-P4-numeric-Actor-consumer-and-fallback-native-chain.md)。
- [**本輪新pair/slot44/CDoll/負面P writers完整原生稿**](20261031-045459-chatgpt-web-roy-T08-202-pair-consumer-vtable-CDoll-P-field-BIN-final-evidence.md)，初次Git blob `240f947bd2fd9af66f9b1ba07d8cc298af0422c0`。
- [**原生驗證腳本**](T08-202-native-final-reference-audit.py)（本輪遠端讀回Git blob `447629a9375f9b3627e53ae64408b538182ecfed`；其中`4DF124`立即常數自+3起，其餘29處自+1起）。
- 既有202出站RX/TX更正如`20261031-035954` XOR 0BBB checksum，CIocpNetwork 034400/034500 WSASend/GQCS各有原生有界來源。

**最終裁決**：以原始04交接的202問題集為固定完成條件、以上BIN root/CFG/owner/consumer和反例已足夠封閉的**有界靜態研究**；新進一步全局 alias/indirect target、跨T02/S00與runtime不得冒充已完成，亦不得因非當前202範圍之其它資源行為未知就無限延遲本段完稿。
