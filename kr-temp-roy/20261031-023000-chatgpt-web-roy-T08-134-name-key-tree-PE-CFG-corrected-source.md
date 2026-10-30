# T08-134 — Name-key tree find-or-create 原生 PE 入口／CFG 勘誤（完整有界新來源）

- 作者：chatgpt-web roy；日期 2026-10-31 Asia/Taipei。原件：KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 新稿針對舊源 `kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-134-two-caller-record-name-routing.md`（原始Git blob `e00a3e06649983687ef227f550a756fee78a6128`，T01 legacy mapping FAILED）。不改舊源、不宣稱整篇修訂通過 T01 FULL-PASS。
- **本次獨立從原件解碼**：PE `.text` VA `0x401000`、file offset `0x400`，`raw=VA-0x400C00`。區分舊版把整個PE raw0當code開始的 `VA-0x401000`，是舊抽碼顯示坐標錯誤，並非原PE header 錯誤；`.rdata` VA `0xBD2000`、raw `0x7D0600` 另行處理。

## 1. 舊源稱 `0x7E8AE0` 的函式真正入口 `0x7E86E0`

```asm
7E86E0 55                    push ebp
7E86E1 8B EC                 mov ebp,esp
7E86E3 6A FF                 push -1
7E86E5 68 13 48 91 00       push 0x914813
7E86F1 81 EC 90 00 00 00    sub esp,0x90
7E870E 8B 5D 08             mov ebx,[ebp+8]          ; supplied key object
7E8711 8B F9                mov edi,ecx              ; target container
7E8713 53                   push ebx
7E8714 8B C7                mov eax,edi
7E871C E8 DF 02 00 00       call 0x7E8A00           ; search
7E8721 8B F0                mov esi,eax              ; returned node
7E8723 3B 77 04             cmp esi,[edi+4]         ; head/sentinel
7E8726 74 12                je 0x7E873A            ; no candidate node
7E8728 8D 46 0C             lea eax,[esi+0xC]      ; candidate node key
7E872B 8B D3                mov edx,ebx             ; caller key
7E872D E8 FE 26 CB FF       call 0x49AE30           ; key comparator
7E8732 84 C0                test al,al
7E8734 0F 84 8C 00 00 00    je 0x7E87C6            ; existing-match route
7E873A 33 DB                xor ebx,ebx
7E8755 8D 45 BC             lea eax,[ebp-0x44]     ; local string temp
7E8761 50                   push eax
7E8762 51                   push ecx
7E8763 8D 95 6C FF FF FF    lea edx,[ebp-0x94]
7E8769 52                   push edx
7E876A E8 11 0C 00 00       call 0x7E9380
7E877C E8 2F 0B 00 00       call 0x7E92B0
7E8789 E8 02 07 00 00       call 0x7E8E90
7E879A E8 A1 00 00 00       call 0x7E8840
```

此程式入口型式與直接E8由KR原件 `VA-0x400C00`解碼。重算：`0x7E871C+5+0x2DF=0x7E8A00`、`0x7E872D+5+signed(0xFFCB26FE)=0x49AE30`。舊原稿引用 `0x7E8E00 / 0x49B230` 是把舊位置和相對目標一起錯位所致。既有數個 `.rdata` 絕對vtable指標不在本函式 `E8` 更正範圍。

## 2. 真 `0x7E8A00` 是以字串樣式鍵值做樹 traversal，不是 priority B queue

```asm
7E8A00 55 8B EC                push ebp ; mov ebp,esp
7E8A06 8B 40 04                mov eax,[eax+4]      ; container head
7E8A0A 8B 78 04                mov edi,[eax+4]      ; initial node
7E8A0D 80 7F 59 00             cmp byte [edi+0x59],0 ; nil flag
7E8A16 8B 4D 08                mov ecx,[ebp+8]     ; key
7E8A19 8B 51 14                mov edx,[ecx+0x14] ; key length/capacity
7E8A1D 8B 59 10                mov ebx,[ecx+0x10] ; key size
7E8A29 83 7D F8 10             cmp dword [ebp-8],0x10
7E8A2D 8D 47 0C                lea eax,[edi+0xC] ; node key
7E8A30 72 02                   jb 0x7E8A34
7E8A32 8B 09                   mov ecx,[ecx]      ; heap-string branch
7E8A45 83 78 14 10             cmp dword [eax+0x14],0x10
7E8A4B 8B 00                   mov eax,[eax]
7E8A4D 52                      push edx          ; comparison length
7E8A50 E8 1B F4 C1 FF          call 0x407E70
7E8A58 85 C0                   test eax,eax
7E8A69 8B 7F 08                mov edi,[edi+8] ; one tree arm
7E8A6E 89 7D FC                mov [ebp-4],edi ; candidate
7E8A71 8B 3F                   mov edi,[edi]   ; other tree arm
7E8A73 80 7F 59 00             cmp byte [edi+0x59],0
7E8A77 74 AD                   je 0x7E8A26    ; repeat
7E8A79 8B 45 FC                mov eax,[ebp-4]
7E8A82 C2 04 00                ret 4
```

**已確認**：`[edi+0x59]` 用作nil標記，child links位於 `node+0/+8`，實際比較的是字串樣式的長度與 buffer；於正常成功路回傳候選node。`0x407E70` 的完整比較語義（長度相等、大小順序、二進位等價）仍需下游核對，不能因為有樹查找就命名為原始 `std::map` 或確定所有異常分支。

## 3. 函式身分與上下游現狀

1. `0x7E8240`（T08-133-R2）在名字來源不同的分支使用 container+4 / +14 去導入 `0x7E86E0`，但兩臂實際字串來源的全CFG仍須分別確認；不能把 `manager+8C` 的record值、`A-entry+34` 的handle與B-entry指標等同。
2. 查找命中與找不到候選的兩條路以 `7E8723/26`和`7E8732/34`分流；找不到才建立的候選路徑 `7E873A..7E879A` 涉及多個臨時buffer/allocator helper，**沒有逐callee證明整個記錄建立/釋放鏈**。對它只可主張有建構/插入候選，不可宣稱全路線無洩漏。
3. 舊源數次重複貼同一段ASM是排版重列，不等於執行多次。直接 `E8` 記號必依**真正PE caller VA**重算（已在此列明），而非僅將函式標頭更正。

## 4. 功能介面及後續驗收

|玩家情境|Client有界事實|推定可見效果|Server未證決策|下一個本地查點|
|---|---|---|---|---|
|名稱/記錄關聯|`7E8240→7E86E0→7E8A00`，依key查找/條件建立|不由這條helper單獨推定畫面有變化|何時何種封包造成新記錄不可證|`7E87C6`命中路、`7E8840`實際記錄配置、`7E8A00`完整搜尋樹與caller型別|

**目前狀態**：T01 `LEGACY-MAPPING-001` 仍NEEDS_FIX；本稿是134的第一手 **部分來源勘誤**，尚未完成全部原稿真PE函式/記錄所有權的全文驗證。Client待逆向：record所有者與writer、上游handler；Server待開發：相容資料來源；跨Task：T02 framing；待遊玩驗證：實際觸發時序。
