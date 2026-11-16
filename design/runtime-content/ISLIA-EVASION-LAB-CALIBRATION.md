# 伊希莉亞閃避技能：測試場比較規則

2026-11-08，SERVER_DESIGN_CHOICE／SOURCE_BACKED_PARTIAL；已部署v80，原版Client驗收待完成。範圍補正：Practice54只宣告技能等級1..5，BuffExplain的6..11級不是額外可學等級，實作不接通6..11。

來源為既有`named-defensive-buff-text-candidates-v1.json`，SHA256
`e1a10b5ea0fab9eaf52dfaaea46c264f6ce5f3d05aa640db2cb827a22439f419`。
Role4／Active34與Buff6名稱相同；這是可審閱候選，不是原生授予／等級映射證明。
KR／TC數值相同：Buff等級1..11的迴避增幅為42、43、44、45、46、46、47、48、49、50、200%；rawTime全為10。等級6..10另描述攻速+6..10%，等級11未描述攻速，不能沿用等級10。

## 明示的Server測試假設

- 僅隔離SkillLab的Role4／Active34／Practice54宣告等級1..5，暫以ActiveLevel對應同等級Buff6，rawTime解讀成秒。
- 基準迴避率固定20%，不是角色實際屬性；有效測試機率為`20 × (100 + 來源迴避增幅) / 100`%。因此等級1為28.4%，等級5為29.2%。Buff11的200%原文保留但不接線，不當作機率或默默截成100%。
- 基準20%只在此Buff啟用時用於比較，**不是**普通角色的基礎閃避。沒有Buff的攻擊保持原行為。
- 機率判定在現有普通近戰命中範圍成立之後、減傷／有限護盾計次之前。閃避不扣HP、不觸發受傷硬直、不耗盾次數；敵方已開始的動作與冷卻仍照常。這個先後順序是Server選擇。
- 原型未接敵方命中／角色裝備公式，沒有創造MISS封包或特殊閃避動畫；避開的傷害沿用現有阻擋分支，不發傷害與受傷狀態。
- 採既有0077完整狀態清單候選發布Buff6等級1..5；其他owner／monster白名單保持原有等級限制。到期／死亡／世界替換依既有狀態生命週期清理。
- Buff6..11沒有技能可學等級／授予接線，6..10的攻速增幅因此也不套用，不修改連擊／收招時程；這次不是完整技能／原生玩法完成。

Buff6宣告`S_Buff_BasisEvasion01.eff`。原件／工作副本的`Effect/Assist/Buff/S_Buff_BasisEvasion01.eff`一致，SHA256
`3bc0bfe95552588fb924150083867de1b2f62239d9e1165ad2346882d242d2cc`。
這只證明直接EFF存在，沒有完成所有模型／貼圖依賴及實機顯示驗收。

## 驗證要求

正流程覆蓋5個可學來源等級、正常施放及付費一次、成功後回基礎組、機率兩種正常結果、到期後恢復受傷、既有護盾計次及0077集合保留。用可控隨機輸入驗證效果分支，不以抽樣頻率宣稱原版公式。其他暫緩套件不執行；不啟動或修改Client。62個新技能的動作缺口不因這次效果比較而解除。

實作已完成：286項HappyPath通過，0失敗／0略過；Host Release建置0警告／0錯誤，頁面流程檢查通過。新增7項效果案例，保留初版13案例中7項失敗及第一次完整套件的舊狀態預期失敗紀錄，未覆寫成成功。修正來源等級假設與舊測試預期，沒有增加可學等級或刪除原來無泛用傷害的斷言。

[來源查核程式](../../governance/client-variants/20261107-all-skills-unlock/audit_islia_evasion_source.py)、[來源界線](../../governance/client-variants/20261107-all-skills-unlock/islia-evasion-source-boundary-v1.json)、[測試結果](../../governance/client-variants/20261107-all-skills-unlock/v80-evasion-validation.json)、[v80部署紀錄](../../governance/client-variants/20261107-all-skills-unlock/host-v80-deployment.json)。實際Client的Buff6視效、迴避手感仍待驗收。
