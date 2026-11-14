# `lb` 本地建立物件的回傳契約與世界 ID consumer

## 結論與證據邊界

本節只補查「Lua 建立的世界物件，能否由建立函式回傳 ID，再交給其他 API 或 Server 對帳」。`lb.CreateObjectEx` 確實走世界 actor 建立／索引路徑；但本原件的 Lua 包裝層沒有把新 actor 的 ID 推回 Lua。`return 1` 是 C 函式交還 Lua 的結果個數，不是物件 ID、成功碼或建立數量。`lb.CreateObject` 同樣如此。

另一方面，`SetActorAvatar`、`AttachActorItem`、`DetachActorItem` 的第一參數確實查世界 ID 樹。這三者不是靠 Q 的劇情物件 slot、model ID 或建立順序查找。因而不能直接採用 `id = lb.CreateObjectEx(...); lb.SetActorAvatar(id, ...)` 作為已確認的可靠契約。

這是上述 binding／marshaller／native target 的有界結論。它不表示整個 Client 或所有可能載入的 Lua 都沒有其他 ID 查詢工具；也沒有執行 Client／Lua 來觀察實際殘留 stack 值。

## 1. 從註冊到原生 target，而非只看名稱

原件 `4A0950` 初始化 `lb`，`4A09AB` 傳入 `&FDF3C8`，`4A09B1 → 4A14D0` 建立 namespace，然後依序呼叫下表 14 個註冊器。`Rebind` 在 `4A14D0` 另行註冊。本次保存全部 14 個有限註冊器的原始 bytes、字串與指標，目的是限定這個原生 API 集合的查詢能力，不把它當作重新發現全部 Lua API。

| Lua 名稱 | 註冊器 | native target | Lua wrapper |
|---|---|---|---|
| SetDebugLevel | `4A15B0` | `4A0AA0` | `4A1E90` |
| GetObjectCount | `4A1650` | `4A0A30` | `4A1EF0` |
| ChangeMap | `4A16F0` | `4A0AC0` | `4A1F50` |
| CreateObject | `4A1790` | `4A0B40` | `4A1FB0` |
| CreateObjectEx | `4A1830` | `4A0F70` | `4A2010` |
| SetActorAvatar | `4A18D0` | `4A0B80` | `4A2070` |
| AttachActorItem | `4A1970` | `4A0C50` | `4A20D0` |
| DetachActorItem | `4A1A10` | `4A0D10` | `4A2130` |
| GetTime | `4A1AB0` | `4A0B70` | `4A2190` |
| DoFile | `4A1B50` | `4A1230` | `4A2200` |
| PrintCurrSceneID | `4A1BF0` | `5F5D10` | `4A2260` |
| ChangeResolution | `4A1C90` | `4A1330` | `4A22C0` |
| LoadMinimap | `4A1D30` | `4A1400` | `4A2320` |
| ChangeKeymapType | `4A1DD0` | `4A1440` | `4A2380` |

每個註冊器的 `+18` 為 `C7 05 <slot> <target>`，`+58` 推入名稱，`+69` 推入 Lua wrapper。JSON 逐項保存實際名稱 VA、slot、target、wrapper，驗證器重新從原件解碼對照。此集合沒有獨立的 `GetObjectId`／列舉世界 actor 的註冊項。既有 `GetObjectCount` 空 target 的結論沿用前一稿，不作本輪新發現，也不能藉它補出有效 ID。

## 2. `CreateObjectEx` 完整回傳路徑

呼叫鏈：

`4A1830` 註冊 → `4A2010` Lua C wrapper → `4A25F0` 參數轉換 → `[FE178C] = 4A0F70` 世界物件建立。

原件關鍵指令：

```asm
004A1848  mov dword ptr [00FE178C],004A0F70
004A204A  call 004A25F0
004A2052  mov eax,1                  ; Lua 結果個數

004A25F6  mov eax,[00FE178C]
004A2606  mov [ebp-24h],eax
004A2806  call dword ptr [ebp-24h]    ; native target
004A2809  pop edi
004A280A  pop esi
004A280B  xor eax,eax
004A280D  pop ebx
004A280E  mov esp,ebp
004A2810  pop ebp
004A2811  ret
```

`4A25F0..4A2848` 的所有正常／轉型失敗分支完整保存。它讀取六個 stack 參數，轉成四個整數與兩個 float 後呼叫 native；native 返回後沒有 pushnumber、pushinteger、userdata 或其他 Lua 結果建立操作。外層 `4A2010..4A2066` 也沒有這些操作。

這個 binding 的參數型別也有實作意義：最後一個 attach 參數在 `4A2617..4A265B` 只接受 Lua number（type 3）或可轉數值的 string（type 4），其他型別走 `4A2812` 的數值 0 fallback。因此不能用 Lua `true` 代替已證的數字 `1` 來掛接 controller。其餘參數亦按 numeric conversion 處理；轉型失敗歸零不是完整的內容驗證。若開發產生器，必須驗固定 arity、數值範圍與 context，不能依賴 native 對錯誤內容提供明確錯誤碼。

native `4A0F70` 的既有主體可重述為：

1. 依 model 範圍建 actor 類型，設定位置、外觀等資料。
2. `4A104F` 讀 `[F7DE04]` 的低 16 bits；`4A105F` 寫 actor `+4`。
3. `4A11B6 → 4DFF30` 插入世界 ID 索引。
4. `4A11BB` 將 `[F7DE04]` 的 DWORD 加一。
5. 若第六參數非零，走當前 controller 的 `v+4` 與 `v+10`；這些 controller 的 AI 能力邊界沿用 2026-11-13 S00 原稿。
6. `4A1218..4A122D` 回收函式 frame，沒有把 actor ID 放入 Lua stack，也沒有約定 ID 返回值。

Lua C 呼叫回收邏輯沿用前稿並保存對照窗口：`6FE375` 將 C 回傳 EAX 左移 4，`6FE37A..37D` 用 `L->top - nresults*16` 決定結果起點，`6FE380 → 6FE4C0` 搬回結果。故 EAX=1 不能解讀為 ID=1；在本包裝層沒有新 push 的情況下，不能把 stack 尾端既存值當成新 actor 身分。本稿不將未實測的殘留值寫成公開 API 保證。

## 3. `CreateObject` 也不提供另一條 ID 返回捷徑

`4A1790 → 4A1FB0 → 4A2460 → [FE1788]=4A0B40`。marshaller 在 `4A25C0` 間接呼叫 target 後，`4A25C5` 清 EAX 並返回；外層 `4A1FF2` 同樣只設定結果個數 1。

`4A0B40` 接四參數，轉呼 `4A0F70`，把額外兩個整數參數固定為 `12` 與 `0`。它不是另一個會回傳 EntityId 的建立器，也不接受 Server 指定的 EntityId。

## 4. 其他 `lb` actor API 消費的是世界 ID

Lua 到 native 的橋接也已閉合：`4A2070` 在 `4A20A6` 取 `[FE1790]` 並交 `4A2850`，由 `4A295C` 呼三整數 target；`4A20D0`／`4A2130` 分別取 `[FE1794]`／`[FE1798]` 交 `4A2990`，由 `4A2A41`（或第一參數轉換失敗的 `4A2A60`）呼二整數 target。三個 native target 都把第一參數複製為 DWORD key，設 `ECX=&FAB138`，呼叫 `82EF00` 查樹，再以結果節點 `+10` 取得 actor；若是 `[FAB13C]` 哨兵或 actor 空指標即返回。

| 函式 | 查找 call | actor 取出 | 命中後的作用 |
|---|---|---|---|
| SetActorAvatar `4A0B80` | `4A0BF3 → 82EF00` | `4A0C04` | `4A0C14` 寫 actor `+388`，有效 render owner 時呼 `7A6EA0` |
| AttachActorItem `4A0C50` | `4A0CC3 → 82EF00` | `4A0CD4` | render owner 有效時 `4A0CF8 → 7A7240` |
| DetachActorItem `4A0D10` | `4A0D83 → 82EF00` | `4A0D94` | render owner 有效時 `4A0DB3 → 7A7620` |

`82EF00` 用無號 DWORD 比較樹節點 `+C` 與 key（`82EF20`、`82EF41`），傳回符合節點或哨兵；沒有把 model ID 轉成 actor ID、沒有用 Q slot 作橋接，也不自行建立 actor。這裡的字典 key 寬度是 DWORD；本地建立時 actor `+4` 只寫 WORD，不能把兩處資料寬度混寫。

## 5. 本地 ID 計數器只能提供有限靜態資訊

`F7DE04` 位於 raw-backed `.data`，檔案初值 DWORD=`1001`。對這個**單一位址**作 `.text` 的絕對 literal operand 定向查找，僅找到兩處且都已解碼：

| operand VA | instruction | 用途 |
|---|---|---|
| `4A1051` | `4A104F: mov ax,[F7DE04]` | 取低 WORD 配置 actor ID |
| `4A11BD` | `4A11BB: add dword ptr [F7DE04],edi` | 此路徑 `EDI=1`，建立後遞增 |

這不是全程 counter writer proof：計算位址、間接 alias 或其他記憶體操作不在 literal 搜尋的保證內。不能由初值 1001 推定每張地圖重設、每個 Client 建立順序一致，或 Server 可以單憑次數安全推算 ID。也沒有證據讓 Server 接收「本地 ID 配置完成」的新協定。

## 6. 開發影響與尚缺證據

已證正向能力是「既有 Lua context 可呼叫 native 建立本機世界 actor，並可在已知世界 ID 時操作其外觀／附掛」。未閉合的是新 actor 的可靠身分暴露與跨端對應；它影響死亡群組判定、Server 傷害／掉落／移除指向、重入場及多 Client 一致性。

- **Client 待逆向**：是否存在別的已可達 API／事件帶回本地 actor ID，或可用原生 context 明確維持 actor handle；新候選必須給 binding、writer、consumer，不能改以猜測 counter 值補齊。
- **Server 開發需求候選**：若採本地建立替代 Server spawn，先定義 group membership、身分對應、重複建立／重連去重與權威結果處理。其實作以已證 Client 身分介面為前置；這不是要求猜填新 opcode。
- **跨功能待整合**：將已可達入口、實際 runner、world actor ID 與死亡／清組 observer 串成同一條功能鏈，才可停送對應 Server 操作。
- **待遊玩驗證**：未在本輪執行 Client／Lua。未宣稱 `CreateObjectEx` 實際回傳值、多人 ID 一致性或普通怪物 AI 已通過。

完整原件窗口在本節同目錄 `native-windows.json`／`.asm`；`lb-bindings.json` 保存註冊 operand，`local-counter-literal-refs.json` 保存有界掃描結果。反編譯檔僅作導航，固定最新檢查 main `552e05a024505a3773095f951c285216051ce2a1`，來源 blob／SHA-256 見 `source-manifest.json`。
