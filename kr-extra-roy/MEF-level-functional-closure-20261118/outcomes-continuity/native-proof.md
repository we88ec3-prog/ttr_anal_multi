# Scenario 結果之後的招募視窗：限定原生閉合

**新閉合的是 `CEmployNewCharacter` 自己的指定按鈕與 `C2S 0033` 返回意圖。** 一般結果按鈕先送 `F431F`；非零參數才切入這個招募視窗。不能把兩個按鈕當成同一個，也不能由此宣稱角色授予、任意關窗／取消或整場獎勵交易完成。

固定原件為 `02-Tartaros.bin`，12,472,320 bytes，PE32/I386、ImageBase `0x400000`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原件只讀。原有 decompilation 固定於 `09799b117f01e577be56dee3e909e1cde25b855f`，B01–B14 在 [source-manifest.json](source-manifest.json)。所有關鍵指令／資料再次落回原 BIN，並保存 [native-evidence.json](native-evidence.json) 的 bounded windows、file raw offset、SHA 和可重驗斷言。

## 1. 來源與頁面 owner

| 接點 | 原件觀察 | 證據 |
|---|---|---|
| 結果 payload | `4C45E0` 讀 message `+8` DWORD，`4C45E3` 寫 result manager `+0x28`；所以原 `+9` byte 位在 manager `+0x29` | N01／A13；B01 |
| 一般結果按鈕 | `6BA2C0` 的既有 click 分支將 manager `+0x29` 作為 `F431F` 參數 | N02；B02 |
| 分開的視窗欄位 | `5AACA0` 使用 page `+0x164` 作結果視窗、`+0x168` 作第二視窗；`5AAD11→5AB020` 是第二個 cache factory | N03／A01；B03 |
| cache→object | `5AB06D→5AB280`；cache ID `0x11B`，新物件 vtable 寫 `C3F024` | N04–N05／A02、A14；B04–B05 |
| 非零選擇 | `5AAEB2` 檢 `F431F` 的參數；非零時關結果窗，`5AAECE` 將參數載入 ECX，`5AAED2→6BF310` 填第二視窗，`5AAEDF→596E00` 開窗 | N06／A03–A04、A15；B06–B07 |
| 零值直接返回 | 同函式 `5AAF11` 建 `0x33`，以長度 2 呼 sender，前提為 network state `FBA798==0` | N06；B06 |

`6BF310` 不是接收任意字串或任意 MEF payload：它把 selector 與 9 作 unsigned 比較，越界離開；以 selector×`0x210` 選既有角色資料，該 record `+0x5C` 非零才填畫面。這是本輪對非零參數的額外限定，不將每個非零 byte 都視為可用角色。[N07；B10]

## 2. 原 RTTI 與事件槽

| 原件資料 | 值 |
|---|---|
| `C3F024[-4]` | `C7AD44`（Complete Object Locator） |
| `C7AD44+0x0C` | `F87EF0`（Type Descriptor） |
| `F87EF0+8` | `.?AVCEmployNewCharacter@FUI@@` |
| vtable `C3F024+0x114` | `6BF140`，初始化控制項 |
| vtable `C3F024+0x15C` | `6BF2A0`，事件 handler |

這些值由原件資料讀出，並非只採用 Ghidra 類別名稱。證據為 N13–N17、A09–A12、A20。

`6BF140` 在 `6BF1D8` 令輸出欄位指向視窗 `+0xD0`，`6BF1E0→6BF900` 查控制項；`6BF900` 的固定 lookup 值為 `0x5654`（22100）。後續 `6BF2A0` 只接受 event `+0x10=0x578` 且 event `+8` 等於這個已綁控制項 `+0x20` 的分支。[N08–N10；B08–B09、B11]

## 3. 兩個互斥的按鈕分支

| 條件 | 已證動作 | 不能外推的內容 |
|---|---|---|
| `context+0x5F4C != 1` | `6BF2F5→414680` 準備 sender；`6BF2FA→4A38D0`；後者寫 WORD `0033`，長度 2，在 network state 允許時發送 | 沒有 Quest、Town、Map 或「招募已保存」欄位 |
| `context+0x5F4C == 1` | `6BF2D5→6BFAE0` 把 number 1 寫進 `g_TutoEmployCharQuery`，後接本機通知及視窗 close virtual `+0xD4` | 這條教學例外沒有經上述 `0033` sender；不能強迫它走普通返回 |
| 其他事件／其他 control | `6BF2A0` 在所選條件之外返回 | 未證有取消／關閉時自動返回，也不是整個 UI 系統的全域陰性結論 |

原 sender `4A38D0` 的 `4A38DB` 寫 EAX=`0x33`，`4A38E0` 寫 WORD，`4A38F1` push 2；動態網路送出前提仍保留。特殊 branch 的 global 名稱直接位於 `C3F008`；沒有執行 Lua。[N10–N12、N18；A06–A08、A16、A18–A21]

## 4. 對 MEF 關卡開發的影響

結果 profile 可以明確描述「普通結果直接返回」或「顯示已初始化新角色介紹後返回」，依目前 accepted phase 接同一 `0033` 意圖。Server 仍由本場 state 決定目的地、返回劇情與提交規則；封包不帶任何可直接採信的目的地。

此證據不自行授予角色，也不把招募 UI 的名字當持久化能力。若自有 MEF 要在某任務解鎖角色，應接既有角色／帳號服務或列出其真實接線差額；判定、顯示、授予與返回四件事各有明確狀態。這次關卡主線 Q119 的直接結果流程不因此被改成必出招募視窗。

## 5. 重驗

與主報告相同的 [verify.py](verify.py) 核對固定 Git source identity、原件完整 SHA、18 個 windows 的 PE→raw 映射與 bytes，以及 20 項 rel32／pointer／cstring／instruction 斷言。PASS 僅代表這些限定靜態證據成立；指定 v2 的視窗與操作仍沒有在本輪執行。
