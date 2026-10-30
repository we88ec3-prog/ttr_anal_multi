# T08 / T01-RETURN-T08-LEGACY-MAPPING-001 — 24篇來源勘誤全覆蓋交付清單（作者修正已交；T01尚待複驗）

**時間** 2026-10-31 04:20 Asia/Taipei；研究者 chatgpt-web roy；Client=KR Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。全部提交至 `t08/roy/chatgpt-web`，原T01已拒的24個精確原稿blob仍保留於 main，沒有回寫。T01獨立審核政策仍按shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md。

## 1. 作者端勘誤交付完成的精確範圍

- **24/24篇已新建替代source**（T08-129～152，每篇1份v3）：所有原碼正/負面主張均不再直接繼承已FAIL的原稿；新版僅保留明確列出且由新原生修訂支撐的有限事實，其他原主張撤回為UNKNOWN，而不是用無根據的「整篇把VA−400」強行修正。每篇有**舊來源path/blob/SHA、原件SHA、修正主張、反證/未知、T01複驗門檻**。
- **18篇含T01原生行映射**（129、130、133–147、152）共**1263行**，每行列舊FAILING VA／真PE VA／原始bytes／E8/E9相對call目標重算。由T01的`mapping-findings.json`1263/1263 `affine_candidate_equal`證據逐篇搬入，GitHub遠端24篇源已逐一讀回核對行數和原始字串（核驗者：chatgpt-web roy）。**必須區分**：這是重用T01已核原件的code-row；沒有聲稱重新獨立反組譯全部1263行、完整CFG及語義FULL-PASS。
- **6篇沒有T01逐行映射**（131／132／148／149／150／151）以以前及本次直接Tartaros.bin核實的function entry十六進位、RTTI/vtable/分配與原生CFG修訂作為修正版支撐，不虛構不存在的1263映射；這六篇也都替換並撤回其餘未獲支持的舊全文主張。
- **特別撤回145～152 ABI假反證**：「7A8310／7A8E10／4CA660／7A3920落入半指令」是因PE錯偏。原始KR BIN真入口（HEX）分別 `55 8B EC 83 E4 F8`、`55 8B EC 83 EC 0C`、`8B 49 0C 85 C9`、`85 C9 74 09`。由MSVC RTTI COL及constructor互證，C4F6C0為CDoll offset+C的**三方法**表，C4F6CC是下一class COL；C4F67C primary+8=真producer 7A63C0。詳細source已在各篇連結到以前上傳完整原生資料。
- **地址類型不混用**：.text真PE raw=VA−0x400C00；.rdata raw=VA−0x401A00；TypeDescriptor在.data raw=VA−0x402800。絕不把.rdata真正指向code的DWORD值、其它literal常數減0x400；相對E8/E9目標採真指令VA重算。

## 2. 全部24篇精確新blob及歷史原稿對照

|T08篇號|已核錯row|完整替代技術source|新Git blob（v3）|歷史FAILED blob|T01狀態|
|---:|---:|---|---|---|---|
|129|20|[`20261031-041315-chatgpt-web-roy-T08-129-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-129-corrected-source-v3.md)|`2897225eafc93a8cc131eda649ee0cc7ea90d474`|`0023e1f4524453491e1dc42810969becd034c8ea`|待T01審核|
|130|21|[`20261031-041315-chatgpt-web-roy-T08-130-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-130-corrected-source-v3.md)|`b618658c67a1a4ad6f0c6ec93e53751f2b0fee49`|`5e7a513b87ea08a9f920377e526be8b444d79ab3`|待T01審核|
|131|0|[`20261031-041315-chatgpt-web-roy-T08-131-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-131-corrected-source-v3.md)|`596eeed7b31542a00838957c9c752f4f245fbfa7`|`f962c4d39b8469e11d4c763949d234a46a931147`|待T01審核|
|132|0|[`20261031-041315-chatgpt-web-roy-T08-132-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-132-corrected-source-v3.md)|`6e3f46126a79da6b7fd51a4b9519250549d452dd`|`3d35052d8bc09d70fe1394b6ac9380a5454b73a9`|待T01審核|
|133|127|[`20261031-041315-chatgpt-web-roy-T08-133-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-133-corrected-source-v3.md)|`7c293b7f021ed6a507ddd6986b56993f1eed766d`|`f466864d5317543d7f78863ede38355773eb25b9`|待T01審核|
|134|128|[`20261031-041315-chatgpt-web-roy-T08-134-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-134-corrected-source-v3.md)|`23f57b620ddfe0bc1e58b108b2aa38c9b1d68907`|`e00a3e06649983687ef227f550a756fee78a6128`|待T01審核|
|135|127|[`20261031-041315-chatgpt-web-roy-T08-135-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-135-corrected-source-v3.md)|`649037608b5d798f34c3fb712cc261720503c05d`|`b473d309ff90aaf638935c6a55a6d6b84f90b251`|待T01審核|
|136|168|[`20261031-041315-chatgpt-web-roy-T08-136-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-136-corrected-source-v3.md)|`3f98246a9ca014d7c4d228361057bc37d0023920`|`31bb246001362c2e15f4d94defdbd116add31204`|待T01審核|
|137|35|[`20261031-041315-chatgpt-web-roy-T08-137-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-137-corrected-source-v3.md)|`ac84e1ddaa09bd5b77fe46a0c657f6b7f89f6095`|`39bb9462451fa62b890c7e5c1fca225d9eb70ed6`|待T01審核|
|138|27|[`20261031-041315-chatgpt-web-roy-T08-138-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-138-corrected-source-v3.md)|`2e64c0891c23721595740d04d7165933e1ddd835`|`0f57fa53734a801984402bb13ac15617a3e01e76`|待T01審核|
|139|109|[`20261031-041315-chatgpt-web-roy-T08-139-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-139-corrected-source-v3.md)|`9f601666058eb46b146746f2fe7c6984e0d8c538`|`5ce4138eabb80f1a859b4801f075a56e4ac8167f`|待T01審核|
|140|35|[`20261031-041315-chatgpt-web-roy-T08-140-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-140-corrected-source-v3.md)|`ecc9092411c0ecd916bb2ebe3f0c804686605d58`|`471e5946d67fd02ad4f4390e6dedbfd1c2040430`|待T01審核|
|141|45|[`20261031-041315-chatgpt-web-roy-T08-141-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-141-corrected-source-v3.md)|`f50323e9c9c0390b588e6a0000f2cc5d427ebf85`|`0044621bfd57ae0a7a1ee5a8687a13b2654a1032`|待T01審核|
|142|172|[`20261031-041315-chatgpt-web-roy-T08-142-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-142-corrected-source-v3.md)|`ea1171a50bf45a7a07e1503aab0fd03652a5ce8c`|`05dfc203138c444e28c09fe8f910a3ed684ba2c5`|待T01審核|
|143|70|[`20261031-041315-chatgpt-web-roy-T08-143-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-143-corrected-source-v3.md)|`a831e119bf4b0f29d28b13dfeafd77c41b9b25d4`|`0c5f49419fdb626eca8d007186bffbe22c4c8349`|待T01審核|
|144|48|[`20261031-041315-chatgpt-web-roy-T08-144-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-144-corrected-source-v3.md)|`483a3fad44838992b4c6061606f6996f28971893`|`d1af4d9f33eaf7f55c72cc98f6c79169d867f58b`|待T01審核|
|145|38|[`20261031-041315-chatgpt-web-roy-T08-145-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-145-corrected-source-v3.md)|`90589ccf99e41f21e232f6c4c5fe832ecbc7e92d`|`f65fa24deba3bb11bb7e95c4fa04468b27b10f06`|待T01審核|
|146|41|[`20261031-041315-chatgpt-web-roy-T08-146-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-146-corrected-source-v3.md)|`bceeaff8cb6339135a6d6138adde752aab8d7a65`|`c80e130172d127172992f00f044a5af89e994174`|待T01審核|
|147|43|[`20261031-041315-chatgpt-web-roy-T08-147-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-147-corrected-source-v3.md)|`c41b442052c3da538f07db33e2bfd64e0ddd967d`|`795ae00b864bfb7929546313975550b437dbdab1`|待T01審核|
|148|0|[`20261031-041315-chatgpt-web-roy-T08-148-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-148-corrected-source-v3.md)|`0a7384b66888958050732b84e77fc4d5eed10453`|`731256d9263379c95a6a4c608b5ac22d727df14f`|待T01審核|
|149|0|[`20261031-041315-chatgpt-web-roy-T08-149-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-149-corrected-source-v3.md)|`be36fdaa23081a59832d9d7095f7dc9437ad25fa`|`7743ed6e56742780d400627bfbbffae316defec8`|待T01審核|
|150|0|[`20261031-041315-chatgpt-web-roy-T08-150-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-150-corrected-source-v3.md)|`8be0b6697429bbae01dc5ca519cf25a7b2c56f6a`|`8d2d45fa3eb94840ff4ae6b459ea38b04c254f50`|待T01審核|
|151|0|[`20261031-041315-chatgpt-web-roy-T08-151-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-151-corrected-source-v3.md)|`5d47cd07a15bbbb3d93a895c9b199e84e37be35a`|`d16ed4d133e88986f1f5867d287b2f44934f89a9`|待T01審核|
|152|9|[`20261031-041315-chatgpt-web-roy-T08-152-corrected-source-v3.md`](T01-legacy-pe-crosswalk/corrected-sources/20261031-041315-chatgpt-web-roy-T08-152-corrected-source-v3.md)|`d0ccb9830f6bd519a36741d3278dd6712fda98d9`|`6d50d49aa523a589714a76159169072b2a994145`|待T01審核|

**合計**：24篇，18篇有逐行對照、6篇無原T01逐行對照，**1263個錯誤code-row已全部具體修正位置**。數字是檔案與T01所列原碼行覆蓋，不是「所有144位址/所有歷史主張已被T01審核通過」。

## 3. 其它5筆T01獨立語義/ASM退回：已有完整v2替代稿，另修來源品質問題

|退回|獨立v2修正版（已在T08分支）|現在的限定狀態|
|---|---|---|
|T08-153 ABI|[`20261031-010500...T08-153...`](20261031-010500-chatgpt-web-roy-T08-153-T01-corrected-source-v2.md), **blob `5ac19f9003a104a174bb534bb6a8d57ea90d0c79`**|search key pointer和out iterator slot reuse重建；額外修正未展開日期模板文字，作者READY_FOR_REVIEW|
|T08-155 ASM|[`20261031-010500...T08-155...`](20261031-010500-chatgpt-web-roy-T08-155-T01-corrected-source-v2.md), blob `6f96b1996d57e14f8a438f0cd48f309d08ac50f2`|7B698E mov/7B6991 jmp 真根入口；作者READY_FOR_REVIEW|
|T08-157 ASM|[`20261031-010500...T08-157...`](20261031-010500-chatgpt-web-roy-T08-157-T01-corrected-source-v2.md), blob `bee44d5019ce224821a1ef1391d1337227f37130`|4B297A cmp、4B2980 je、4B2982 mov；作者READY_FOR_REVIEW|
|T08-183資料結構|[`20261031-010500...T08-183...`](20261031-010500-chatgpt-web-roy-T08-183-T01-corrected-source-v2.md), blob `29a337462476697cc1c83615031caa46d1cb314a`|7B8680為hash-index/list，不是RB-tree；作者READY_FOR_REVIEW|
|T08-187指令界線|[`20261031-010500...T08-187...`](20261031-010500-chatgpt-web-roy-T08-187-T01-corrected-source-v2.md), blob `1b35f545975e93901722326ccecacf01e3789ab9`|7F6FBF push30 /7F6FC1 mov edi,eax；作者READY_FOR_REVIEW|

**原T01已RESOLVED**：173、196，其各自177／197後續更正版保留，不重開。

## 4. 復現及靜態核驗分級

- 使用[`verify_legacy_corrected_sources.py`](T01-legacy-pe-crosswalk/verify_legacy_corrected_sources.py)（blob `028546a2f713d59ab658ac936a9f7abee56b69ad`）可在完整Git checkout＋本地原始KR BIN執行：

```sh
python -B kr-temp-roy/T01-legacy-pe-crosswalk/verify_legacy_corrected_sources.py --repo . --bin /path/to/Tartaros.bin
```

該腳本逐一要求24份原稿path/blob、全部1263行新VA+exact bytes與E8/E9 rel32、以及6份無row的若干真入口hex吻合。**腳本已提交，未在連接器的遠端checkout環境實際執行，因此不虛稱CI或本地自動測試已PASS**；T01可使用同SHA原件重跑。個別典型入口此次另於本地原始BIN直接獨立抽核。
- 本次Web作者已逐篇向GitHub connector讀回24個新source，逐行檢查T01 1263/1263表列重建、Git blob SHA存在；這只保證傳輸與T01 crosswalk轉錄，**不是**全24篇每一語義主張獲T01認證。
- 原T01主審仍須獨立重跑腳本、看根函式CFG/ABI、多型物件/生命週期與新v3有限正面主張；只有符合T01 FULL-PASS才可將精確限定主張收錄到shared/verified-knowledge/。**T08研究作者不代替T01宣告RESOLVED，不修改T01共用主審台帳**。

## 5. 勘誤完成 vs. 正式驗收與研究續段

**作者側修正/交付**：LEGACY 24份替代稿已交齊；五個個別T01退回均已具來源修正版；交付可進入T01複驗環節。**正式退回狀態**：截至開工時main的T01退回仍為NEEDS_FIX，完成新source不等於T01驗收RESOLVED。**T08-202** 尚有record alias writer及26/81跨owner欄位等未解事項，本次依使用者指定**暫停新分析**並不將202標FINISHED。

|對象|Client已確認|Client待逆向|Server待開發|跨功能／遊玩驗證|
|---|---|---|---|---|
|LEGACY B/CDoll→render結論|真PE、RTTI CModel/CDoll分型，B producer 7A63C0、priority consumer 7BB240、CModel 7D3470另寫全域bucket|B借用entry→CModel/global bucket的真執行因果、所有scene dispatch與資源生存期；不納入本次OLD source新版肯定主張|相容設計須依真wire，沒有官方Server因果證據|T01 bounded FULL-PASS、T06/T07場景與玩家實測|
|T08 Actor/P關聯|先前T08-202有界0007/000A writer與命令26/81特定clear差異|其它alias writer、全模式清理分支、真正Server收包鏈|由已證Client要求自行設計，不冒稱原版策略|T02/S00與可玩驗收|
