# T08-153～200：R0／R1 敘述萃取提案

48 份精確原稿均已讀取敘述並完成身分綁定；本範圍 R0／R1 剩餘 **0 篇**。其中45份提供新整合導航，158／177／197保留既有 `CLM-CLIENT-0001／0002／0003` 與 CONFLICT_CHECKED 關聯，不重寫其品質。

`proposal.json` 保存25個按功能去重的群組、48份來源的 SHA／Git blob、實際敘述行號、有限內容觀察及矛盾處置。新群組為18個PARTIAL、1個UNKNOWN、6個僅重用既有確證反駁的REFUTED。它們不因引用同一helper或正式CLM便繼承NATIVE_VERIFIED。

整合內容包括主樹移除／低byte篩選／整表清理、node erase與actor清理分層、具體derived vtable個案、128槽預清理與child+8介面、基底析構、nested resource release、defer／reuse／drain、manager名稱索引及wrapper橋接。未知的opcode、runtime、key schema、跨層實例同源與完整失敗／併發安全獨立保留；Server波次、AI及生成時點不可由這些helper推導。SPEC關聯尚未由S00指定，以空陣列及unknown明示。

已知衝突保持：153／157 erase ABI與157錯位、155碼塊錯位；173非零mode writer已由177修正但舊blob仍FAILED；183的hash/index不能稱ordered tree；187配置座標錯誤；196主／次樹混淆已由197修正但舊blob仍FAILED。200索引措辭維持歧義待澄清，已撤銷的lower-bound-only拒因不復活。原稿與歷史台帳均未改判。

本輪依 `governance/t01-integration-workflow.md` 在R1停止，未跑REA、未讀取遊戲執行檔作新深驗、未作全文碼塊原生驗收、未採未發布continuation-03草稿pass。作者研究輪次、Git操作及工具宣告僅作歷史自述。

基準main：`610a822b15346c9e0b69edd4e104c2076f2b59ac`；來源分支head：`5816884ef481995a9fe0d92277b1dde06aff32e8`。只寫本`late/`目錄，未修改global indices、Task、原稿、舊批或Git。

重跑：`python -B build_proposal.py`，再 `python -B validate.py`。`validation.json`只證明身分、引用、schema和防升格自洽，不是原生驗收或S00規格接受。`read_sources.py`提供原稿敘述的帶行號閱讀入口，排除碼塊以符合本輪有限R1範圍。
