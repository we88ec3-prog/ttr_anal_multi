# 全角色技能開放接續

本包是原始資源的欄位／SHA投影與Server隔離預覽候選，不是Client資源包或完整技能完成證明。

`runtime-unlock-candidates-v1.json`：索瑪1287與蘋果1289的兩個單clip候選、98個member身份與等價fingerprints。完整canonical ASD樹只留本機；公開檔不含raw XML。`project_equivalent_runtime.py`只更新這兩個role/practice/active的14個已核對配置slot，保留其餘資料，不會開放未解項。

`explicit-links-public.json`保留89個原未開項目的Practice／ActiveInfo欄位投影與輔助schemas調查：同鍵替換不等於動畫繼承，沒有可據以自動連動的已證bridge。這是有界查核，未證整個Client無任何關聯，也未證缺檔。
兩個候選之外仍87項未開：72新配置動作映射、13命名橋、2個不等價多Basis；另行逐項續查。所有動畫候選的傷害、命中、目標、持續、投射物與特性呈現仍須獨立實作／驗收。

後續瀏覽器已讀到使用者四份播放清單：索瑪、蘋果、舒博爾、柯摩托各27支。`user-video-index-108.json`保存實際可見標題／連結，`video-title-skill-join.json`以role+台版顯示名精確連到105項技能，其中40項尚未開放。這不是108支皆看完或影片可直接提供motion ID；只有索瑪電火球抽看約0/1/2/4秒畫面，保留藍球／前方impact的有限觀察，未據此自動開放技能。其餘五角色的清單不在這108支索引。

[cache-consumer](cache-consumer/README.md)另補閉合549980的原生成本ABI：cache word+4傳EAX、activeID傳ECX到HP/SP/MP getters。+6的MAX建構與真正呈現consumer分開，這條路線未給出新的active→motion映射，不因此開放87項。只收白名單9檔，18個既有bulk函式身份／6個指令區段及小型指令窗；未發布本機完整工作dump。
影片是使用者指定的台版Rebirth參考，不表示與本次KR原始build完全一致。

參見 [v35採用與需求](../../s00-iterations/S00-20261107-V35-NPC-MARKER-CHARGE-AND-SKILL-OPENING.md)。原始檔／完整ASD樹不推Git；工具需由操作者另備指定原件與既有metadata，不能直接把歷史路徑當已配置環境。
