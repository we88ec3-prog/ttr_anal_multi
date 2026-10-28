# E11 — KR Lua 雙參數 callback 註冊、委派與場景語意邊界

2026-10-29 03:19 Asia/Taipei；原始 BIN 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新核驗）。唯讀 BIN-first 分析，不執行／修改 Client；本稿在 `extra/roy1:kr-extra-roy/`，承接 E10。反組譯 `.text` 以 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。

## 1. 第一輪：實際 callback registration 與 target pointer

| 註冊函式 | callback | 註冊 call | 被保存的原生目標 |
|---|---|---|---|
| 0x565F20 | 0x568A30 | 0x565F8E → 0x6F55B0 | `[0xFE277C]=0x561760` |
| 0x565FC0 | 0x568A90 | 0x56602E → 0x6F55B0 | `[0xFE2780]=0x561DB0` |
| 0x566060 | 0x568AF0 | 0x5660CE → 0x6F55B0 | `[0xFE2784]=0x489CF0` |

直接組語：
```asm
565F38 mov dword ptr [0xFE277C],0x561760
565F78 push 0xD6A250
565F7D call 0x6F5510
565F89 push 0x568A30
565F8E call 0x6F55B0
565FD8 mov dword ptr [0xFE2780],0x561DB0
566018 push 0xD6A260
56601D call 0x6F5510
566029 push 0x568A90
56602E call 0x6F55B0
566078 mov dword ptr [0xFE2784],0x489CF0
5660B8 push 0xD6A26C
5660BD call 0x6F5510
5660C9 push 0x568AF0
5660CE call 0x6F55B0
```
資料 `0xD6A250/260/26C` 在 PE `.data` 中為 binary registration array：`0xD6A250` 前 16 bytes 為 `ce020000b423c1007817c100cf020000`；它**不是普通的單一 Lua API 零結尾字串**，須追 `0x6F5510` 的 metadata 實際使用者後才能命名 exposed method。

## 2. 第二輪：0x568A30 → 0x56A220 → 0x561760，兩個 Lua 數值實參

```asm
568A66 mov ecx,[0xFE277C]
568A6D lea edx,[ebp-0x18]
568A70 push edx
568A71 call 0x56A220
56A226 mov eax,[0xFE2778]
56A239 call 0x6F50F0      ; Lua stack -1
56A241 cmp ecx,3
56A246 cmp ecx,4
56A278 fistp dword ptr [ebp+8]
56A283 mov eax,0xFFFFFFFE
56A288 call 0x6F50F0      ; Lua stack -2
56A290 cmp ecx,3
56A295 cmp ecx,4
56A2C3 fistp dword ptr [ebp-4]
56A2CF push edx
56A2D0 push eax
56A2D1 call dword ptr [ebp+0xC]
```

`0x56A220` 把 Lua stack 上兩個 number（或可轉成 number 的資料）轉成 signed dword，若不符條件則走傳 0 分支；以 `ECX=[0xFE2778]` 呼叫函式指標。指標來自 `0x565F20` 對 `0xFE277C` 的初始化，因此**已閉合一段真實 Lua 兩整數 → C++ 0x561760 call chain**。但數量與型別不等同證明兩個整數就是 questIdx、sceneIdx。

`0x561760` 入口可見 `[0xFBAB18]` gate、`[0xFBAB24]` 清零、receiver `[EBX+0x28]` 非零時報錯 `0x6EDB60`，完整效果尚未還原；不能由此推成 scene start 或 T03 選角回覆。

## 3. 第二輪：其他兩個 callback 的 ABI 不同

```asm
568AC6 mov ecx,[0xFE2778]
568ACC call dword ptr [0xFE2780]  ; 0x561DB0
568AD2 mov eax,1

568B27 mov ecx,[0xFE2778]
568B2D call dword ptr [0xFE2784]  ; 0x489CF0
568B33 mov [ebp+8],eax
568B36 mov eax,[esi+8]
568B39 fild dword ptr [ebp+8]
568B3C mov dword ptr [eax+8],3
568B43 fstp qword ptr [eax]
568B45 add dword ptr [esi+8],0x10
```

`0x568A90` 無明確兩整數解碼，而是轉發 C++ method `0x561DB0`；`0x568AF0` 把 `0x489CF0` 的整數回傳值寫回 Lua stack 的 number slot。不能把同一註冊家族的不同 callback 一律歸為 scene request。

## 4. 第三輪：對 E09 場景索引的反證界線

E06/E08/E09 已證原始 Event XML 中 `1001/1 → tutorial_start`，STP 中存在 `tutorial_start.seq`、`Register(tutorial_start)`，Client 有 `(questIdx,sceneIdx)` 有序索引。**本段沒有**證據把這三個 Lua callback 接到場景索引 consumer，亦沒有確認 exposed API name 是 `Register`、`LoadMap`、`RequestStartScenario` 或 `RestoreMap`。因此仍不能證明「選角 `0x42` 回覆→首次登入→1001/1→Lua」原生閉環。E11 重大新證是 Lua ABI → 兩數值 → 具體 C++ target，非首登入場景可玩驗收。

### 下一段

- 逆向 `0x561760` 完整 CFG、`0x561DB0`、`0x489CF0` 的副作用。
- 解析 `0x6F5510` registration metadata，分辨每個 Lua API 實際名稱。
- 搜 `0xFB73C8` scene index indirect reader，串接 `funcName→*.seq→Lua execute`，最後與 T03 response、T07 scene controller 交叉補證。

## 再現與 Server 界線

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x565f20 --stop-address=0x566110 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x568a30 --stop-address=0x568b60 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x56a220 --stop-address=0x56a300 Tartaros.bin
```

Client 待逆向：callback exposed name、scene index reader、first-login gate、wire response；Server 待開發：相容場景／任務規則（必須等 Client wire 確認）；跨功能待整合：T03/T07/T16；待遊玩驗證：原版 Client 實際流程。T01 FULL-PASS 尚未升級。E11 本段有三輪界線核對，保留 E01–E11 原稿至 T01 正式吸收後才清理 `kr-extra-roy/`；不修改 main。
