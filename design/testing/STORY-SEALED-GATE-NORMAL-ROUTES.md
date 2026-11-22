# Q119 真正封路候選的正常通關採用

2026-11-23。SERVER_DESIGN_CHOICE／**NOT_NATIVE_MEF**。本批把先前僅靜態分析的
[占點開門候選](../../kr-extra-roy/MEF-P0-level-execution-20261118/gates-transitions/report.md)
接進現有 Q119 逐輪擊倒／首次入場演出版本，沒有新增原生格式或 opcode。
一般狩獵場 Case693 的波次、頭目階段、機關、兩分支與結算完整副本仍保留；本批補的是
Story adapter 的「真能隔開出口」內容採用及實際正常移動證據，不取代 Case693。

## 內容與來源

[新內容](../scenario-content/story-q119-sealed-hold-gate.scenario.json)
SHA256 `9e65baa388571a3827ce70e36f39597cec4a4771239dee12586f439200979fb5`。
以 `story-q119-monster-defeat-firstvisit-entry.scenario.json`（SHA256
`31f4f544ee0183298891c3a2ffdb2cd04b16be0d69a0ee86072fa043ca7f3464`）為基準，
僅末節點4的 `barriers`、`portal`、`signals` 三欄完整採用原 RegionHeld 候選
（原候選 SHA256 `c637fbabed346421e419efde3efcff045460ea6697230550c75faa5794388f6a`）。
前三圖、原出生／必要怪、逐輪死亡事件／增援、FirstVisit、迴圈／重置與所有獎勵保持。
這是另存新版，沒有改寫先前候選或指定測試 Client。

| 末圖 Map635／node4 | 本版 |
|---|---|
| 原始 BND | mushroom12.bnd，SHA256 `0adeeef7c1a183642a3e49a321e80c191b6dd3c8243f4e2f4ff7d16b5290c653` |
| Server 封口 | `[427,428) × [397,405)`，8 格 |
| 門前標記 | category0／key65011，`(425.5,401.5)`，r1 |
| 出口 | category0／key4，移至 `(431.5,401.5)`，Server r2；Client 候選作用半徑約1.6 |
| 連續占點 | `(379.5,399.5)`，r2，2.5秒後設 `exit-gate-open` |
| 清場後重建 | 出口與標記均先以關閉狀態出現在完整0027，後各收到一次0048開啟 |

占點的原定義可以在清場前成立；本批正常路線在清場演出後才占點，不能據此宣稱「必須先清場才計時」。
出口仍需要清除原必要怪才可使用。r1 marker 的操作／外觀與 Server 封口矩形是分開的身分。

## 驗證結果

[最終收據](story-sealed-gate-20261123.receipt.json)，SHA256
`6971ce6a1e0d6d663ef5db0226031ec66d6acb49ea66adbdfca6c9841fc6ee03`。

- 重新核對來源 SHA，從本版 Server 匯出地形重算完整四鄰與保守八鄰連通，沒有重跑舊原件掃描。
  開門出生區27,891格；關門出生區27,830格、出口區53格、封口8格，集合恰好分割原區域。
  容許所有對角方向的保守關門出生區仍27,830格，出口不可繞到。
- Server 實際 `WithBarriers/CanStand` 全圖檢查為關門新增8格、開門0格，原561,928格牆不變；
  規劃器遮罩與 Server 完整遮罩 SHA 相同。Server r2／Client 候選約r1.6出口圓保守覆蓋各21格，
  全在53格出口側；占點圓21格、標記圓9格全在出生側。
- 來源 cap 一路、舊 FirstVisit 停止／三輪兩路、保存配套停止／三輪兩路，共五條 TCP。
  舊路保留原幾何，正常5936／5984EXP不變；保存新路先正常走到封口前，向東移動被擋，
  再走至占點區，未滿2.5秒保持關閉、滿時旗標／門／出口開啟，最後實際走入約1.6半徑才按出口。
  TCP 使用測試時計，與下列獨立 Host 分開記錄。
- 管理端正式預覽、儲存、匯出 scenario／AI／experiencePolicy／manifest 四檔，原預覽範圍
  5936～5984EXP、最大8次節點訪問不變。新 `--scenario` 只接受明確提供的候選，原生成命令保持。
- 保存同一配套的兩個獨立真實時計 Host 各完成停止4訪問／三輪8訪問，無測試時計／遊戲內部
  Handle/Poll 呼叫。唯讀診斷保留六階段：封口前、受阻、占點開始、未滿、已開、穿越；
  全屬同一末圖訪問。實際0027兩點關閉，0048 key4／65011各開一次。
- 兩 Host SQLite 各只保存一次Q119 5880EXP／40熟練，總EXP增量5936／5984，游標Q120，
  Town1／Map182原隊伍返回；不是重新建立替代隊伍。種子資料庫不變，各自測試 Host／Admin 已停止。
- Host、Inspect、Admin 三個 Release 建置零警告／錯誤；793 HappyPath 全通過，零失敗／略過。
  本批沒有修改 runtime 引擎／schema／遊戲協定，增加內容採用、正常 TCP／Host 操作與稽核工具。

## 邊界與後續

這證明 Server 平面格點規則封住出口，**未證明 Client 動態物理門、門模型／動畫、角色寬度或3D碰撞**。
沒有啟動／附加／修改遊戲，沒有 Client 播放 ACK。帳號前置沿用隔離教學／Q15／等級準備，
不是自然全新帳號到 Q119 的實機驗收；指定 v2／其餘機關外觀與原延後測試仍各自保留。
本版採用 RegionHeld；另一個 clear-delay 靜態候選仍未採用，不混算完成。
管理配套是隔離儲存／驗證，沒有自動部署到使用者現用服務；完整 MEF 目標仍依
[功能追蹤](../../governance/MEF-FUNCTIONAL-COMPLETION.md)繼續。
