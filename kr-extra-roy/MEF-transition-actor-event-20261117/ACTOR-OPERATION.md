# 二：可靠 world identity 上的有限外觀操作切片

本題選 `lb.SetActorAvatar`，不使用CreateObjectEx的猜測流水號，也不要求把世界生成或戰鬥判定交給Lua。它是**同場景、允許有限插播的相容內容設計**，不是官方MEF格式或全程不中斷控制的B方案。

## 1. 目標與完整鏈

```text
Server建立並保存明確的world actor身分與本次生命週期
  → 當前場景及模型/descriptor資源核對
  → 已配置有限Q入口、預掃描不改世界
  → native Start尾段結束後的正式callback
  → lb.SetActorAvatar(worldId,part,variant)
  → world tree查同一actor → metadata／CDoll條件分支
  → dirty → 原生模型工作佇列 → apply → draw
  → Q正常End／適用解除（不等於模型套用完成）
  → 使用另一次合法內容入口恢復可信的原part/variant，或按權威world生命週期重建
```

前後兩個操作必須對同一worldId、scene generation及actor lifetime；後兩者屬Server內部識別，不是這個Lua API已有參數。原生API不帶generation，故ID回收期間的過期操作必須在發布層阻擋。

## 2. 身分與資源：已證來源及未綁定值

原Table/_ActorList.xml在OBJCATEGORY=0下的ACTOR1，PRE=1、FILE=`soma`、SCALE=120，提供一個有來源的角色模型候選。同表category3也有ID1，FILE=`S_Item-Money01`；這是不同域，不能拿「ID1存在」就認定角色資源。FILE仍保留stem，不猜副檔名或實際avatar part列表。

**這不提供當次world EntityId。** 實際worldId應來自Server已發布的actor快照；model1不能推導成0x0100，更不能從local counter猜一個ID。測試程式裡的0x0100只標為合成資料，不進部署profile。

本輪未取得指定model的原始avatar descriptor／可視化資產，因此part、新variant、舊variant與release hash全部未填。已知loader支援某類資源，不能證明任意part/variant真的存在。

## 3. 新補證：metadata寫入比render gate早

正常綁定來源沿用既有121項surface；本輪重新看完整native `4A0B80..4A0C45`及`7A6EA0..7A6FA3`。

`4A0B80`用傳入world key查FAB138；actor不存在／空指標則返回，不生成新actor。命中後：

| 原件 | 動作 | 對狀態的影響 |
|---|---|---|
| 4A0C0B | 取actor+15C的CDoll | 先取得pointer，尚未驗證可用 |
| 4A0C14 | 將variant low WORD寫actor+388 | 即使後面render gate失敗，metadata也可能已變 |
| 4A0C1B附近 | 測CDoll與actor+370 | 不成立直接返回，沒有視覺成功保證 |
| 4A0C2E | 呼7A6EA0 | 只有此後才處理CDoll avatar選擇 |

`7A6EA0`按CDoll model key查catalog；既有descriptor有指定限制時直接返回。它以low WORD part找map，若現存variant相同可直接返回；不同才更新或移除選擇，最後設dirty。variant0代表移除override，不必然等同Server認定的原樣外觀。

因此內容需分開記：**尚未呼叫／已派發未確認／metadata可能已改／模型apply未觀察／恢復已要求未確認**。不能把原生void、Lua action的結果槽數或003F當顯示成功。

## 4. 後續非同步鏈直接復用，不重算為新發現

R11 world-npc report已閉合：dirty且load state不是2/3→7A8E70複製model/avatar/attachment到0x74工作→FC0E90佇列→worker descriptor lookup／model materialize→7A90F0 apply→7A63C0 draw。有效結果state1，無效結果可清模型並設state3。此後續不是本輪全面重驗；精確引用見source-manifest。

正常Q End沒有把這個世界CDoll變成Q actor或給每次外觀請求新的Lua ACK。也不能在native工作未完成時僅憑送出End就刪除／回收該worldId，再把完成假定套到新生命週期。

## 5. 最小建置／執行契約

建置時固定worldId、part、variant及release version；0047本身不攜帶這三參數。必須以真實可達內容選取與合法資源發布方式供應，不能把Server內部JSON當作Client會自動讀到的參數通道。若採A1式quest0單次鍵策略，apply與restore使用各自配置且未消耗的鍵；本輪不私自佔用32760去改寫已完成A1切點內容。

正式callback只做所需一次avatar操作，然後End並立即return。不得在prepass、formal chunk頂層提前End；不得以Q.EnableInput偽稱B不中斷操控。還原操作使用Server保存的舊variant；不能靠沒有公開getter的Client欄位猜舊值，也不能把variant0一律當還原。

Server若需要對多玩家同步，必須為每個Client同一世界實體選定一致資料。此本地操作本身不授予裝備、不更新背包、不決定強化或交易。權威資產與持久化另由Server實作。

## 6. Attach／Detach為什麼不作本輪第一個可部署案例

本輪讀完4A0C50與4A0D10的world lookup／gate。R11既有下游證明Attach用appearanceItem及model查descriptor，真正attachmentKey在descriptor+20；Detach參數是該key且會處理key+0x10。**itemID不能原樣當Detach key。**

在尚未取得指定descriptor前，硬填一組attach/detach數字會掩蓋資源缺口。因此先交avatar的條件式操作契約，附件保留同一資源綁定門檻，不用任意常數造出「清理成功」。

## 7. 完成狀態及解除條件

已完成同身分的查找、setter、metadata/render差異、既有非同步consumer、有限入口與退出／還原契約。**一個真實可見外觀變更案例尚未完成**：缺當次Server world快照與指定model/part/variant descriptor、資源版本及正常畫面驗收。這些明列於`actor-operation-profile.json`，deployable=false。

下一步應取得`OBJCATEGORY0/model1/PRE1/FILE=soma`實際descriptor的reader輸入及源member，挑其確實支援的一個part/variant，連同原variant與資源SHA交S00綁定。不必重做世界CreateObjectEx配號，也不用把普通AI和死亡判定加入本地外觀切片的前置。
