# T01-012 — KR actor tree 插入／摘除與旋轉修復的主張級驗收

- 分析日期：2026-10-28 Asia/Taipei；執行者：chatgpt-web roy（T01 整合審核），僅新增 T01 自有原稿，不覆寫 T08 技術筆記或 owner。
- 原始檔：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本輪重新執行 `sha256sum` 比對成功。
- PE32 x86，`.text` VA 0x00401000、raw 0x400；以下 raw = VA - 0x00400C00 僅限 `.text`。
- 前段完整原稿：`shared/integrations/T01-20261028-11/20261028-120507-chatgpt-web-roy-T01-011-registered-actor-index-CFG-audit.md`。本輪從其 R5/R6 直接接續 `0x44BD00`、`0x7B6890`，延伸 `0x43E670`、`0x763F60`、`0x49E6A0`。
- 操作：唯讀 `objdump -D -Mintel --start-address=... --stop-address=...`；不啟動、修改或附加遊戲。通過僅代表本地 CFG 與指令資料流，不是遊戲功能驗收。

## 本輪重要發現與分級

| ID | 有界原生主張 | 直接 BIN 證據 | 狀態與邊界 |
|---|---|---|---|
| N1 | `0x44BD00` 接收待插入節點並增加容器 `[edi+8]` 數量，依 root／左／右分支更新 parent/child/header，完成後輸出節點指標。 | `0x44BD03..0x44BD66`、`0x44BE56..0x44BE60`；`[edi+8]++`、`[edx+4]=eax`、header root/min/max 三類連線、`[return-slot]=edx`。 | **NATIVE-PASS（局部結構插入）**；`edi` 的動態 C++ 型別未明。 |
| N2 | 插入後不是只有掛鏈：若 parent `+0x14` 狀態為 0，就進入多輪修復，透過 `0x763F60`／`0x43E670` 旋轉並修改 `+0x14`。 | `0x44BD69..0x44BE53`、`0x44BD9D call 0x763F60`、`0x44BDB9 call 0x43E670`、`0x44BDE9 call 0x43E670`、`0x44BE43 je 0x44BD80`。 | **NATIVE-PASS（有界修復 CFG）**；`+0x14` 是平衡標記/顏色的高度可信解讀，但單以位元組不確立 MSVC STL 具名實作。 |
| N3 | `0x43E670` 對指定節點執行「左子節點上移」方向的結構旋轉，更新子節點、parent，並處理 header root 或 parent 左右鏈。 | `0x43E673..0x43E6C2`：`eax=[ecx]`、`[ecx]=[eax+8]`、`[eax+8]=ecx`、`[ecx+4]=eax`；分支依 header/parent 左右位置變動。 | **NATIVE-PASS（樹旋轉結構）**；不假設其他容器共享此同一型別。 |
| N4 | `0x763F60` 為相對方向旋轉：右子節點上移，`[ecx+8]=[right+0]`、`[right+0]=ecx`、並接回 parent/header。 | `0x763F63..0x763FAE`，尤其 `0x763F66..0x763F8C`。 | **NATIVE-PASS（樹旋轉結構）**。 |
| N5 | `0x7B6890` 為節點摘除/erase 的結構函式：先選 successor/replacement，更新 tree header 根、左端、右端；多分支調整 `+0x14` 並透過上述旋轉輔助修復；最後釋放一個節點及遞減計數。 | `0x7B68B4 call 0x49E6A0`、`0x7B68B9..0x7B69B6`、`0x7B69BB..0x7B6AC3`、`0x7B6AC7 call 0x89120C`、`0x7B6AD8..0x7B6ADD`。 | **NATIVE-PASS（本函式可見樹刪除及平衡 CFG）**；節點和 actor payload 不是同一件事。 |
| N6 | `0x49E6A0` 是查找相鄰樹節點的迭代 helper，依 `+0x15` sentinel 沿 child/parent 更新 `[eax]`；該 helper 不直接釋放。 | `0x49E6A0..0x49E6EA`。 | **NATIVE-PASS（局部 iterator/adjacent node 搜索）**；更細的 iterator API 名稱保留暫定。 |
| N7 | `0x7B6890` 尾端一律執行 `0x89120C` 的節點解配置調用，並在計數非零時 `[tree+8]--`、將 `[result-slot]` 設為輸入節點參數。 | `0x7B6AC3..0x7B6AEB`，`0x7B6AC6 push edx` `0x7B6AC7 call 0x89120C`。 | **NATIVE-PASS（直接 call/計數/回傳）**；`0x89120C` 實作內容與 heap ownership 的其他客體尚需另驗。 |
| N8 | 將 `0x4DFBC0` 說成「依傳入 key 精確匹配並刪除 actor」仍不成立：其上游 `0x82EF00` 為 lower_bound 風格，移除入口只檢查 `candidate != sentinel`。 | T01-011 R4/R6，`0x82EF20 cmp node+0xC, request; jae`、`0x4DFBDD cmp ... sentinel; je`；`0x7B6890` 只依傳入 iterator/node 刪除。 | **NEGATIVE / BOUNDARY CONFIRMED**：缺少 callsite 上游「key 必存在」不變式；`key != candidate.key` 的可能性仍須調查。 |
| N9 | `0x44BD00` 與 `0x7B6890` 的修復模式共同高度符合紅黑樹的插入／erase 修復，而不是 gameplay-specific scheduler。 | `+0x14` byte 調整、父/兄/叔節點、鏡像旋轉、root 顏色強制賦值；雙向的 `0x43E670`／`0x763F60`。 | **STRUCTURAL-INTERPRETATION（高度支持，但非符號類型驗證）**。 |

## 直接 ASM 證據：不可用「只有函式頭」取代

```asm
; 插入 count、parent 與 header
0044bd03  8b 4f 08              mov ecx,[edi+0x8]
0044bd24  8b 55 10              mov edx,[ebp+0x10]
0044bd27  41                    inc ecx
0044bd28  89 4f 08              mov [edi+0x8],ecx
0044bd2b  89 42 04              mov [edx+0x4],eax
0044bd35  89 51 04              mov [ecx+0x4],edx
0044bd3b  89 11                 mov [ecx],edx
0044bd40  89 50 08              mov [eax+0x8],edx

; 插入後修復/旋轉與返回
0044bd9d  e8 be 81 31 00        call 0x763F60
0044bdb9  e8 b2 28 ff ff        call 0x43E670
0044bde9  e8 82 28 ff ff        call 0x43E670
0044be43  80 78 14 00           cmp byte [eax+0x14],0
0044be47  0f 84 33 ff ff ff     je 0x44BD80
0044be56  8b 45 08              mov eax,[ebp+8]
0044be5a  89 10                 mov [eax],edx

; erase 前進迭代與替換/兩側 child 修補
007b68b4  e8 e7 7d ce ff        call 0x49E6A0
007b68b9  8b 0b                 mov ecx,[ebx]
007b68c6  8b 43 08              mov eax,[ebx+8]
007b68f4  89 78 04              mov [eax+4],edi
007b6959  89 41 04              mov [ecx+4],eax
007b6960  3b 43 08              cmp eax,[ebx+8]
007b69a7  8a 53 14              mov dl,[ebx+0x14]
007b69ad  88 50 14              mov [eax+0x14],dl
007b69b3  88 4b 14              mov [ebx+0x14],cl

; erase fixup includes rotations
007b69f2  e8 69 d5 fa ff        call 0x763F60
007b6a24  e8 47 7c c8 ff        call 0x43E670
007b6a41  e8 1a d5 fa ff        call 0x763F60
007b6a58  e8 13 7c c8 ff        call 0x43E670
007b6aa0  e8 bb d4 fa ff        call 0x763F60
007b6abb  e8 b0 7b c8 ff        call 0x43E670

; erase free/count/result
007b6ac7  e8 40 a7 0d 00        call 0x89120C
007b6ad8  85 c0                 test eax,eax
007b6ada  74 04                 je 0x7B6AE0
007b6adc  48                    dec eax
007b6add  89 41 08              mov [ecx+8],eax
007b6ae6  89 08                 mov [eax],ecx
```

## 主要結構欄位（以本組樹例程為限）

- `node+0x00` / `node+0x08`：左／右 child 指標；`node+0x04`：parent 指標。
- `node+0x0C`：在本組 lookup/insert 上以 DWORD key 參與 unsigned 比較，**不把同一位移套到 payload 或其他 tree owner**。
- `node+0x14`：修復狀態（顏色標誌的解讀高度合理）；`node+0x15`：sentinel/header 判斷標記。
- `node+0x10`：上游 T01-011 見到的 actor-like payload 指標；本輪 `0x7B6890` 不將 payload 的深度解構自動視為自身責任。
- `tree+0x04`：header 指標；`tree+0x08`：大小計數。此處 `tree` 是這組工具內的視圖，不自動推定所有 manager 的型別。

## 有界偽碼（本輪從機器碼歸納）

```cpp
Node* structural_insert(TreeView* tree, Node* parent, Node* fresh, bool left,
                        Node** result) {
  // 0x44BD00: count++, set fresh->parent, attach to root/left/right
  // Update header min/max as appropriate.
  // While parent fixup state requires, rotate and adjust +0x14 flags.
  // Mark root repair flag; *result = fresh.
  // Allocation itself happens BEFORE this helper (not proven here).
}
Node* structural_erase(TreeView* tree, Node* candidate, Node** result) {
  // 0x7B6890: use 0x49E6A0 to compute related iterator,
  // choose replacement/transplant, adjust header root/min/max,
  // perform fixup through 0x43E670 / 0x763F60,
  // deallocate one tree node via 0x89120C,
  // decrement tree count if nonzero, set *result to iterator.
  // No proof here of exact-key precondition or actor payload semantics.
}
```

## 缺口與衝突仲裁

1. **精確 key 問題（核心）：** `0x82EF00` 返回的是候選 `>= request`。上層 `0x4DFBC0` 只做非 sentinel 判斷，直接進入 payload 虛擬呼叫與刪節點；此視窗看不到 `candidate.key == request`。若呼叫者保證 key 必存在，仍可能安全；但此保證必須以 callsite/資料流證明。不能再將「非 sentinel」直接稱作 exact match 或 duplicate。
2. **動態類型：** `0x44BD00/0x7B6890` 只能證明樹節點層操作；未驗證 `node+0x10` 所指 payload 實際 vtable 與所有實體 owner。
3. **配置與回收：** `0x89120C` 對樹節點的解配置 callsite 可見；未確認所有別名/多樹共享物件是否同時持有 payload，不可宣稱 actor 所有權問題全解。
4. **封包→場景效果：** T02 framing、T08 actor 場景效果、T07/T14 場景/結算與原版 Server 決策仍未形成完整 client-visible 端到端鏈；本段不重複猜測。
5. **第二／第三輪門檻：** 第一輪取得實質新增的結構插入、刪除、雙向旋轉與修復鏈原生證據，已達明確可重驗的控制流程增量，故本段第二／第三輪未啟動。
6. **原稿管理：** 本次只新增 T01 檔案，不覆寫 T08-184/188/192/193/196/200 的技術原稿，不調整 catalog、owner、`shared/source-review-status.json`。

## 後續最優先的可驗證入口

- `0x004DFBC0` **所有呼叫者** 的 key provenance / 精確匹配不變式；檢查傳入 key 不存在時是否存在破壞性刪除風險（僅靜態推導，不執行目標）。
- `0x0082EF00` 其餘 callsites 是把它用於 lower_bound、精確查找還是 range consumer；與 `0x0082F200` insert failure branch 比對。
- `0x0057EF20` 節點配置/初始化及 `0x0089120C` 解配置 ABI；區分 tree node / payload / wrapper。
- 配合 T08 已知 S2C 0007／000A 客戶端入口，建立封包 handler→actor index mutation 的限定上游鏈，不跨 Task 宣稱 server 觸發規則。

## 再現命令

```sh
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -D -Mintel --start-address=0x44bd00 --stop-address=0x44be61 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x7b6890 --stop-address=0x7b6aee /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x43e670 --stop-address=0x43e6c5 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x763f60 --stop-address=0x763fb1 /mnt/data/Tartaros.bin
objdump -D -Mintel --start-address=0x49e6a0 --stop-address=0x49e6eb /mnt/data/Tartaros.bin
```
