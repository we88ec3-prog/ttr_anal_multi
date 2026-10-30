# T01 — RR-0007 / E60 KR Client S2C 命令→場景限定驗收與來源修復（2026-10-30）

**審查身份**：T01 / chatgpt-web roy；審查日期 2026-10-30（Asia/Taipei）。開工主線 `5f323ddaaecaf1b3f78e24c5a4f0927d9469445a`。
**原始原件**：KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。兩份使用當次已上傳的本機唯讀原件實際重新計算 SHA256；沒有執行／patch／attach／連線 Client。原始 BIN PE .text VA 0x401000/raw 0x400（.text VA−0x400C00）；.rdata VA−0x401A00。

## 1. R0：處理 RR-0007 source path 不在 main 的整合錯誤

- GitHub `main` 的 `research/requests/index.json` 已公開 RR-0007 `SUBMITTED`，`dispatch.submission.report_path` 指向 E60，但 **E60 路徑尚未存在於當次 main**。不能把 PR #41 合併 RR 台帳誤稱為原稿也已合入。
- 原稿在作者 `rr/t02/roy/rr-0007` 分支完整存在：`kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md`，Git blob **`2ca02f3870d79d3217abf39b8651c43226eb77d6`**，UTF-8 原文 SHA256 **`c98a600c84773609de82050f8e71231d450d2e8f52ad5f8920e35b99996665ee`**。本批以**相同既有 blob**加入主線同名路徑，未修正、重排、精簡任何原稿內容；來源 SRC-0472。
- R0 存檔與此 T01 R2 記錄分開；來源全篇仍非 FULL-PASS。留存 RR 原作者的事件、分支與提交歷史，不改其 task owner、task.json 或 catalog。

## 2. 獨立 KR BIN-first R2：具條件的指令、table 與本機路由

以下由本次實際 `Tartaros.bin` 依原始 PE 映射讀取定界 bytes、SHA256 並以 x86 objdump 反組譯；與 E60 原稿的相應肯定主張逐項比對。**精確取樣與指定 rooted 分支核對不等於對 E60 1,318 行全文、所有 indirect writer、所有動態場景做完整語意驗收。**

| 原生區段 VA [start,end) | 長度 | SHA256(raw bytes) | 有界結論 |
|---|---:|---|---|
| `4930E0..493160` | 128 | `5c7e1b4f2e3b2d473c67ec77dec8065f878ea7b70cd20af90cdae11b45ad89ab` | Client callback: length 非零、lane==2，轉 [Client+B8]+4；return==0x100 後檢查 BE8C |
| `494360..4943AB` | 75 | `86cada79ad3ea7a956ce3e78cecb8d85dac75086470ded01201f67eb5a6b65ee` | 初始化／轉入 FD2CF8+4 table |
| `4FDA30..4FDAB3` | 131 | `f972c684f3955a1d49c1e56eef445bb5f60fd3e4e16da15c654a51ef21054f88` | signed WORD index，`[owner+index*8+4]`，不存在時 virtual fallback |
| `4B7EC0..4B7F30` | 112 | `61a8ca73487a1ff2fab6c2f8fb73feaf36791c2cf8a3d3e379051e756a309a83` | generic fallback 檢查 `[owner+5EAC]` active scene，非所有命令共用 gate |
| `4C4670..4C46A0` | 48 | `9ff7fea80b2ecdf60e4115fcfb0bfeab6c7387893dcb6710435dfb8a3be2ca41` | scene 第二層 index*8 +5EAC，missing 轉 base virtual |
| `4A3B80..4A3C00` | 128 | `bf0e31c3abce72142a66792a04c6a7c82d63df8478ecb7996b4b5f0458d06811` | C2S buffer WORD42、byte index、byte mode；FBA798 gate 與 manager virtual+10 |
| `4B7DC0..4B7EC0` | 256 | `fa48613974a308ddf6c2eb90bea82195fc9d77023c4c918585f5e6dc6bcb7f32` | 第一層 `FD2D0C = 4B7F00`，`FD2CF8+4+2*8` |
| `4ADD50..4AE650` | 2304 | `d0036130fd648b01ed1c1f2dcdb5cc12d4e5a32800436a0e259415f81424229e` | base table `+214→4B2190` cmd42、`+21C→4B1A90` cmd43；該 hash 僅覆蓋 +0x900 |
| `4C3220..4C33E0` | 448 | `6f2cefdf7eb263cd9b348e6b9b0912cfb103cdcacaef11f9a728027d8b3333e3` | login scene `5F44→4C37A0` cmd13、`627C→4C3C10` cmd7A |
| `4B2190..4B22C0` | 304 | `159d0443cd8ee8d4629b61df123c2d691d692ad0aa1c15cab91f18dd00ea8f6a` | S2C42 handler 讀入並呼叫 0x500110，**不能證明選角成功** |
| `C05AEC..C05AF4` (.rdata) | 8 | `6e192f182419ba912c38b5c179b1409e9485dcd1ebe990585e2c57da9c99e655` | little-endian vptr[0]→4930E0 |
| `C072FC..C07304` (.rdata) | 8 | `0cd2a95ab655abf460d7ce879f41b54a19545208f82a870dedbd4b673d401225` | vptr+4→4C4670 |
| `C06EB4..C06EBC` (.rdata) | 8 | `67a528b740a71a433aafa6af6937dcccc3fb64a00f4bc7cd4e512c0a3bdff763` | vptr+4→4FDA30 |

**原始指令/表片段（T01 再讀）**：

```asm
4930ED 0F B7 38                  movzx edi, word ptr [eax]    ; before lane/len check
4930F6 85 DB                     test ebx,ebx
493105 8B 45 14                  mov eax,[ebp+14h]
493108 83 E8 02                  sub eax,2
493120 8B 96 B8 00 00 00         mov edx,[esi+0B8h]
493129 8B 52 04                  mov edx,[edx+4]
493135 FF D2                     call edx
49313F 81 FF 00 01 00 00         cmp edi,100h
493147 83 BE 8C BE 00 00 00      cmp dword ptr [esi+0BE8Ch],0
4FDA3B 0F BF F9                  movsx edi,cx
4FDA3E 8B 44 FE 04               mov eax,[esi+edi*8+4]
4B7EC3 83 B9 AC 5E 00 00 00      cmp dword ptr [ecx+5EACh],0
4C467E 8B 9C FE AC 5E 00 00      mov ebx,[esi+edi*8+5EACh]
4B7DDF C7 05 0C 2D FD 00 ...     mov dword ptr [FD2D0C],4B7F00h
4C323B C7 86 44 5F 00 00 ...     mov dword ptr [esi+5F44h],4C37A0h
4C325B C7 86 7C 62 00 00 ...     mov dword ptr [esi+627Ch],4C3C10h
4ADF3D C7 80 14 02 00 00 ...     mov dword ptr [eax+214h],4B2190h
4ADE31 C7 80 1C 02 00 00 ...     mov dword ptr [eax+21Ch],4B1A90h
4A3B91 B8 42 00 00 00            mov eax,42h
4A3B96 66 89 45 FC               mov word ptr [ebp-4],ax
4A3B9A 88 4D FE                  mov [ebp-2],cl
4A3B9D 88 55 FF                  mov [ebp-1],dl
```

注意：以上為**局部覆核**，其中 `0x4B7DC0`／`0x4ADD50`／`0x4C3220` 大區段 hash 以明示長度為準。全域 FIFO/IOCP、scene instance writer、全部 indirect caller 並未因 sample 取得而自動閉合。

## 3. R1 有界主張與反證

| 主張 | T01 判定 | 特別防止的錯誤 |
|---|---|---|
| CLM-NET-0029 | PARTIAL / bounded native R2 | callback **return-true** 需要 BE8C，不能錯當所有 handler 的 pre-dispatch gate；payload WORD 先讀取未見本地 2-byte guard |
| CLM-NET-0030 | PARTIAL / bounded native R2 | command2 第一層 override 不需要先通過 scene-null fallback；cmd13/7A 才在 active LOGIN scene 第二層 |
| CLM-NET-0031 | PARTIAL / bounded native R2 | C2S 42 建構與 S2C 42/43 有本地 handler 是**兩件不同方向事件**；沒有證據能把 S2C 42/43 提升成選角成功／拒絕或切場景 |

- 由 E59 / SRC-0471 / CLM-NET-0026..0028 提供 `0x2633/0x22D7` 解壓失敗、checksum、0x807E50/pool 的前置；**不在本份 E60 R2 認領 RR-0006 的全部語意**。
- `0x4C37A0` 的 body+0x16 分支、`0x4B7F00→0x4D4150` roster 副作用、`0x804740` app lane 的全域容器身份，主要沿 E60 作者的明示證據與既有 R2 規格作有界導航；本次**未完整獨立覆核所有函式每條執行路徑**。
- T03 RR-0002/0003/0008 仍由原 owner 補角色選擇回覆、登入 UI 和場景轉入 writer；不變更 T03 原稿或 T01 既有退回。
- 既有 E57/E58 的 RR-0001/0004 有獨立 T01 R0–R2 [限定審核](../t01-20261030-rr0001-rr0004-bounded-r2/README.md)，E59 RR-0006 已有 [多來源有限審核](../t01-20261030-multi-branch-merge-r0-r2/README.md)。本批讓四筆仍 SUBMITTED 的正式 RR 經 T01 進入 **IN_REVIEW**；不是 T01 替 S00 ACCEPTED。

## 4. 決議、狀態與需要的後續研究

- **T01 結果**：E60 的本次根源與限定指令主張可用於 R1/R2 有界引用，無直接原生反證須由原作者更正；仍是 **PARTIAL、未達 FULL-PASS**。維持原稿，未寫他人 Task README 退回通知（因不是已確認錯誤）。
- **Client 待逆向**：S2C 42/43 與 C2S 選角的真實配對；登入 UI status、scene transition writer、callback 實例穩定身份、邊緣 payload bounds；另保留 compressed frame/unknown marker 的未閉合範圍。
- **Server 待開發**：不同連線時序、業務回覆與拒絕策略、角色/任務資料的相容 Server 介面；不可依某個相同 command 值自創 Server 成功封包。
- **跨功能待整合**：RR-0006/E59 的 framing 邊界、T02 的命令表 → T03 auth/roster/選角 → T05 場景 writer。
- **待遊玩驗證**：未執行原版 Client，沒有原始 Server pcap，不宣稱真正登入/選角可玩。
- S00 將根據各 RR acceptance criteria 獨立決定 ACCEPTED 或 NEEDS_REVISION；SPEC 仍 DRAFT/PARTIAL，GAP 仍 OPEN，TEST 未升級，沒有新增 `shared/verified-knowledge/` FULL-PASS 或改 `native_complete`。

