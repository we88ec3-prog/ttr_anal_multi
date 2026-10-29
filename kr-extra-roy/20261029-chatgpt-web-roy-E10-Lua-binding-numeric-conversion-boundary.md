# E10 — KR Scene Lua C++ binding registration and numeric conversion callback (BIN-first)

日期 2026-10-29 Asia/Taipei。原始 Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本段 E10 承接 E09；只讀靜態 disassembly，沒有執行、修改 Client、Lua 或 Server。工作分支 `extra/roy1`；專屬目錄 `kr-extra-roy/`。

## 研究範圍與前段邊界

E09 證實 `Event.stp` 內 `tutorial_start.seq` 及 XML `(questIdx=1001,sceneIdx=1) → tutorial_start` 靜態對應，但 **尚未證明** Lua `Register` 的 C++ 對應、`*.seq` 的 runtime loader、選角 `0x42` 回覆或首次登入分流。本段嘗試從相關本機 Lua/C++ bridge 與場景索引周邊追查；重要校正：相近位址不代表相同業務語意。

## 第一輪：Lua binding registration 的具體原生呼叫鏈

`0x560600` 是長串本機 Lua/C++ callback registration 的初始化路徑，而不是 `0x568680` 場景雙鍵 tree 的直接 reader。以下原生指令可見：

```asm
0x560606 lea ecx,[ebp-4]
0x56060B mov [eax],esi
0x56060D call 0x565E40
0x560616 call 0x565F20
0x56061C call 0x565FC0
0x560622 call 0x566060
; 後續依序呼叫 0x566100, 0x5661A0, ... ,0x5685E0
0x56078F push 0xC055C8
0x560796 call 0x6F4A50
0x56079B push 0xC055B0
0x5607A2 call 0x6F4A50
0x5607A7 push 0xC055BC
0x5607AE call 0x6F4A50
0x5607B3 push 0xC10658
0x5607BA call 0x6F4A50
```

`0x565E40` 證實登記本機函式：

```asm
0x565E88 mov edi,0xC10604
0x565E8D mov eax,0xFFFFD8EE
0x565E92 call 0x6F5790
0x565EA3 mov eax,[ebx]
0x565EA5 mov eax,[eax+8]
0x565EB7 cmp [eax+8],5
0x565ED6 push 0xC06224
0x565EDB call 0x6F5510
0x565EE5 push 0
0x565EE7 push 0x568790
0x565EEC call 0x6F55B0
0x565EF4 mov eax,0xFFFFFFFD
0x565EF9 call 0x6F57F0
```

關鍵是 `0x565EE7 push 0x568790` 和 `0x565EEC call 0x6F55B0`：可明確證明 **Lua/native binding callback function pointer 的註冊操作**。字串 VA `0xC10604` 原始 bytes 為 `51 00 ...`，即 `Q`，其他字串/namespace 需分開查對；不能把這段註冊自動稱為 Tutorial_EntryPoint 的 callback。

## 第二輪：callback 實際下游，是 Lua integer reader 而非 seq executor

```asm
0x568790 mov eax,[0xFE2774]
0x568795 call 0x4A2BB0
0x56879A mov [0xFE2778],eax
0x56879F xor eax,eax
0x5687A1 ret
```

其下游 `0x4A2BB0` 可證為 stack/value → number → integer 轉換：

```asm
0x4A2BB3 mov ecx,[eax]
0x4A2BBA or eax,0xFFFFFFFF
0x4A2BBD call 0x6F50F0
0x4A2BC2 mov ecx,[eax+8]
0x4A2BC5 cmp ecx,3
0x4A2BCA cmp ecx,4
0x4A2BD7 call 0x6F7760
0x4A2BE0 fld qword [ebp-8]
0x4A2BF0 fld qword [eax]
0x4A2BF8 fistp dword [ebp-4]
0x4A2BFB mov eax,[ebp-4]
; failure at 0x4A2C04 returns zero
```

它辨認 Lua 類型 3/4，必要時嘗試數字轉換，經 x87 `fistp` 得到 signed dword；若型別不符走 0。此處不呼叫 `*.seq` loader、SceneList key lookup 或 scene controller。因此 **`0x568790` 不能當作 `tutorial_start` executor**。這是本段重要可證語意界線，而非位址清單。

## 第三輪：相鄰場景相關程式並非 scene key dispatch

`0x560AA0` 讀 `[arg+0x1c]` 所在的獨立有序容器、逐節點遍歷，依 `[arg+0x70]` 條件和 `[0xFC0E90]` lookup 尋找本地物件，並多次對物件 vtable `+0x8`、`+0x24`、`+0x10` 間接調用。它的指標來源、比較的 16-bit 欄位、容器不是 E09 的 `0xFB73C8` key table 的直接已證 reader；不可僅因 `0x560AA0` 與 `0x5607D0` 位址相近，就把它推定為 `questIdx,sceneIdx` runtime dispatcher。

原生證據錨：
```asm
0x560ACC mov eax,[ebp+8]
0x560ACF mov eax,[eax+0x1c]
0x560AD2 mov esi,[eax]
0x560AE7 cmp [edx+0x70],0
0x560B47 mov ecx,0xFC0E90
0x560B4C call 0x515790
0x560B9E mov eax,[ecx]
0x560BA0 mov edx,[eax+8]
0x560BA3 call edx
0x560BE1 mov eax,[edx+8]
0x560BE4 call eax
0x560C0F call 0x826280
0x560C44 movzx ebx,word [esi+0xc]
0x560C5B call 0x82EF00
0x560CDE mov eax,[edx+0x10]
0x560CE3 call eax
```

其迴圈位址 `0x560C86–0x560D42` 展現兩層有序節點前進，但不是已證的 XML scene-map reader。未將其上升為 Server wire 或 tutorial trigger。

## 下一段高優先順序與範圍

1. 追 `0x565F20` 到 `0x5685E0` 其餘註冊回呼，定位是否有 `RequestStartScenario`、`LoadMap`、`Register`、scene dispatch 的 native gateway，且必須逐個保留 Lua exposed name 的真實來源。
2. 追 `0xFB73C8` SceneList 結構的實際讀取 API（指標流、雙鍵查找），再連 `funcName` 到 `*.seq` 的檔名生成與載入流程。
3. 以原版 `tutorial_start.seq`、`TutorialMain.lua`、T03/T07 已有研究追 S→C／first-login gate；本輪仍未閉合，不能用 fixture 補空白。

證據狀態：**Lua/native binding callback → Lua number/int conversion** 已有重大新的有界功能鏈；`funcName→seq→Lua execution`、`0x42 response→tutorial` 仍未知。E10 第一輪即取得可驗證 callback 和 numeric conversion 語意重大增量，第二／第三輪為額外交叉反證。不能將報告視為 Tutorial 完整驗收或 T01 FULL-PASS。

## 重現

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x560600 --stop-address=0x5607c3 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x565e40 --stop-address=0x565f20 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x568790 --stop-address=0x5687a2 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4a2bb0 --stop-address=0x4a2c0c Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x560aa0 --stop-address=0x560d48 Tartaros.bin
```

整合規則：E01–E10 原稿暫留 `extra/roy1:kr-extra-roy/`；僅 T01 完成來源稽核、正式吸收後按使用者約定清理，不能預先刪除。Main 不改。
