# S00：v12進村人測結果與三項修正

測試版本：私有Server `f1261c82d76b43918a8c268ed607a898d7341af6`，指定工作副本
SHA256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
玩家依本機新帳號完整教學至馮德斯村測試卡操作；本輪不操作／修改Client。

## 人工結果

玩家先回覆「已到馮德斯村，人物／NPC正常且可移動停止」，再補充：

1. 任務NPC第一段劇情結束後，NPC對話窗與第二段劇情重疊。
2. 清怪後應走入傳送點，才進入下一圖或完成副本；v12卻自動推進。
3. 按一下前進再連按Z，走路不會立即停下。
4. 換場畫面有出現、正常運作，算通過。

**到達／人物／NPC／村內移動停止與本輪換場畫面可見通過；整段體驗有三項待修，不能稱乾淨全通過。**
換場可見性只限本次測試路線／工作副本，不擴張成所有場景或未修改原版驗收。
沒有測三角色跟隨、蘋果出戰、Quest117之後、官方MEF或重登／異常流程。

## 唯讀保存核對

[去敏保存證據](evidence/S00-20261103-PHINDOS-HUMAN-PASS.json)：
本輪stage1/2/3/4皆存在、role4，最終ArrivalAuthorized；與教學transfer／settlement
相同connection與revision的關聯1筆。前置仍為14/16，Quest16 raw2/50仍
PENDING_NATIVE_PUBLICATION。沒有Quest15完成key、paid獎勵或下一主線完成證據。
未公開帳號、冒險團名稱、session識別、帳密或DB。

## 三項修正候選

- [NPC對話來源](S00-20261103-PHINDOS-ACCEPTANCE-UI.md)：40/status0會開啟接取對話
  呈現事件，並非安靜ACK。移除15/1後與47/15/2同批的40；不補猜替代封包／固定sleep。
- 一般主線兩圖的勝利保存只開啟傳送點；玩家踩入原生category0自動checkpoint，
  送1C(category0,currentKey)，Server核對自身位置與已保存勝利後，才切map2或進22結果。
  生成位置與key／radius是明示Server配置，不聲稱官方MEF佈點。教學專用戰鬥不因此改為一般副本。
- 新攻擊意圖優先於快取walking bit；動作回復期間不把舊moving bit送回連段狀態或自動恢復。
  首次從走路進攻擊時先同步停止movement／idle／Server位置，再播攻擊，保留已有連段buffer。

修正程式的合成測試、Git提交與下一次人測另記，不能把本次v12回覆視為修正版已驗收。
REQ-0018／0019／0016／0017依各自範圍追加GAME_RUNTIME_OBSERVATION；正式批准狀態不變。
