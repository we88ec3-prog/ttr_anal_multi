# 技能候選動作：模型載體與依賴範圍

2026-11-08，SOURCE_BACKED_PARTIAL；沒有啟動、附加或修改Client，沒有新增動作配對。

本次沿用已固定的294個數字動作及其294份直接EFF引用，只核對既有EFF宣告的433個唯一檔名，沒有重掃MEF或全資源。421個`.gb3`名稱可在原始`Effect/Object.stp`找到同名`.emf`，另12個`.ptc`有精確檔名對應。433個member的工作副本與原件內容相同；421個EMF的gzip容器均可完整解壓並通過容器校驗。

## 有限原生回退證據

KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
從已保存函式6D7560的入口解碼，核對原始指令6D7672..6D7700：先呼叫714550；返回0且名稱長度大於4時，比較尾碼`.gb3`；相等分支將尾碼換成`.emf`，再呼叫714550。字串分別位於C40F60與C40F68。不是僅因相同檔名就宣稱存在原生轉換。

這段仍未證明每個EFF模型載入都會走進6D7560，也沒有在本次閉合714550的完整archive／disk搜尋路徑、前後載入規則或整函式語意。不能因此把所有模型標成已可載入。

## 對Server開發的意義

- 原先294動作的直接物件依賴，在這個有限命名範圍沒有找到缺少同名載體的項目；不是整個Client「沒有缺檔」的證明。
- gzip解壓後的內容仍保持不透明，沒有宣稱已解析模型、加解密、巢狀貼圖、材質、骨架或渲染相容性。
- 檔案齊全不會自動建立Active／ScriptLevel到motion的對應；目前62個缺口不因本次查核而解除。
- 這裡的EMF是上述物件載體，不能當成已找到原生MEF腳本、AI或傳檔opcode。Server自訂場景／AI仍明示NOT_NATIVE_MEF。
- 沒有改動Client配套、Server施法規則、白名單或目前Host；不以完整容器校驗取代實機比對。

[可重現查核程式](../../governance/client-variants/20261107-all-skills-unlock/audit_action_object_dependencies.py) 與 [有限證據](../../governance/client-variants/20261107-all-skills-unlock/action-object-dependency-availability-v1.json) 保存來源雜湊、原件／工作副本一致性、各member雜湊、gzip解壓後雜湊及原始指令視窗。不公開原始或解壓後遊戲資產。報告SHA256：`19ecc804c63eb024d2a60fd13476b81236e3cc91073103d42e31954b71c2f873`。
