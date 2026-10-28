# KR T16-82 — 0xC2DBAC 子對話框 vtable、物件配置與事件路徑證據邊界

- 研究者：chatgpt-web roy；日期：2026-10-28 Asia/Taipei（文件名時間為本次觀察時間 19:46 UTC+8 近似標記，非精確秒數；後續請使用 git commit 紀錄作正式時間）。
- 研究範圍：**KR T16 Quest & Story Progression**。本段以原始 `/mnt/data/Tartaros.bin` 靜態唯讀核對，沒有啟動、修改或附加遊戲。
- BIN 大小 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE32 x86 `.text` VA=0x00401000、raw=0x400，這一節的 raw=VA-0x00400C00；`.rdata` VA=0x00BD2000、raw=0x007D0600，**此節不能套用 .text 的換算**。
- 導航來源：前段 T16-81 原稿；本輪對以下機器碼由 `objdump -D -M intel` 及直接 BIN dword 重新驗證。原始 Server 與實際封包流量仍無來源。

## 1. T16-82 第 1 輪：vtable 實際內容及可辨認的分配方法

前段 T16-81 已從 `0x6309D0` 的 `mov dword [esi],0xC2DBAC` 確認物件 final vptr。由 KR .rdata 原始 dword 解出：

| vtable offset | 目標 VA | 原生證據及可證範圍 |
|---:|---:|---|
| +0x00 | 0x466DE0 | 函式指標存在；語意尚未追證 |
| +0x04 | 0x403DF0 | 指標存在 |
| +0x08 | 0x403DF0 | 指標存在 |
| +0x0C | 0x414670 | 指標存在 |
| +0x10 | 0x403DE0 | 指標存在 |
| +0x14 | 0x744C00 | 指標存在 |
| +0x18 | 0x744C50 | 指標存在 |
| +0x1C | 0x4619F0 | 指標存在 |
| **+0x20** | **0x630860** | 直接包含 0x254-byte 單物件配置 + vptr 初始化 |
| **+0x24** | **0x6307B0** | 陣列配置、overflow 守護及逐元素建構 |
| **+0x28** | **0x630910** | 指標存在；須續查釋放語意 |
| +0x50 | 0x749890 | 指標存在，不能由事件候選自行認定 |
| +0x54 | 0x7498E0 | 指標存在，不能由事件候選自行認定 |

表內 `0x630C20` / `0x630D50` **不屬上述 +0x00..+0x74 已驗證 vtable slots**；不能未有另一份 vtable/instance xref 證據就稱它們是該子對話框的虛擬事件方法。

### 1.1 0x630860 — 單物件配置路徑

```asm
630885: push 0x254
63088a: call 0x892068
63089c: cmp esi,edi
63089e: je  0x6308ef
6308a2: call 0x754880
6308a7: lea eax,[esi+0x15c]
6308b2: mov DWORD PTR [esi],0xC467DC
6308b8: call 0x77b520
6308bd: mov BYTE PTR [esi+0x158],0x1
6308c4: mov DWORD PTR [esi],0xC2DBAC
6308ca: mov DWORD PTR [esi+0x248],edi
6308d0: mov DWORD PTR [esi+0x24c],edi
6308d6: mov DWORD PTR [esi+0x250],edi
```

原生已確認：`new` 相當分配候選大小 0x254，成功時內嵌初始化並寫 final vptr，失敗返回 null。注意 `0x630860` 將 `0x6309D0` 內聯式初始化工作重做一遍，可能是 compiler-generated scalar-creating constructor；無符號不可認定正式名稱。

### 1.2 0x6307B0 — 陣列配置與逐元素初始化

```asm
6307d4: mov edi,[ebp+0x8]
6307d9: mov eax,edi
6307db: mov edx,0x254
6307e0: mul edx
6307e2: seto cl
6307e5: neg ecx
6307e7: or ecx,eax
6307eb: add ecx,0x4
6307ee: setb al
6307f1: neg eax
6307f3: or eax,ecx
6307f5: push eax
6307f6: call 0x87dc3d
630808: test eax,eax
63080a: je 0x63083c
63080c: push 0x450400
630811: push 0x6309d0
630816: push edi
630817: lea esi,[eax+0x4]
63081a: push 0x254
630820: mov DWORD PTR [eax],edi
630822: call 0x892003
```

獨立證明 element size=0x254；配置總長含 +4-byte count header；配置溢位保護；元素初始化入口 `0x6309D0`；`0x892003` 類似 CRT vector-constructor iterator，但具體 ABI/exception 行為留給跨模組審查。

### 1.3 原始記憶體與 VA/raw 校核

上述函式 `0x630860` .text raw `0x22FC60`，`0x6307B0` raw `0x22FBB0`，`0x6309D0` raw `0x22FDD0`，`0x630C20` raw `0x230020`，`0x630D50` raw `0x230150`。

```text
vtable=0x00C2DBAC (.rdata)
+0x20 → 0x00630860
+0x24 → 0x006307B0
+0x28 → 0x00630910
+0x50 → 0x00749890
+0x54 → 0x007498E0
```

## 2. T16-82 第 1 輪延伸：附近事件例程的有限證據（與 vtable 關係尚未建立）

### 2.1 0x630C20 — 傳入事件物件 +0x10 比對 0xCB/0xCC

```asm
630c25: mov edi,[ebp+0x8]
630c29: mov esi,ecx
630c2b: call 0x7445d0
630c30: mov eax,[edi+0x10]
630c33: cmp eax,0xcb
630c38: jne 0x630c95
630c3a: mov eax,[esi]
630c3c: mov edx,[eax+0x54]
630c41: call edx
630c48: test BYTE PTR [0xfe2c70],al
630c50: or DWORD PTR [0xfe2c70],eax
630c6d: mov dx,WORD PTR [esi+0x158]
630c7a: call 0x4a6900
630c85: mov eax,[esi]
630c87: mov edx,[eax+0x50]
630c8d: call edx
630c95: cmp eax,0xcc
630c9e: mov edx,[eax+0x54]
630ca3: call edx
```

此處 `+0x54/+0x50` 是**動態取得的 [esi] vtable**，不能逕自套用 `0xC2DBAC`；本例程的 actual instance type 未解析。已驗證事件碼 `0xCB` / `0xCC` 在 `[event+0x10]` 而非直接網路封包頭。條件分支會改全域 `0xFE2C70` / `0xFE2C74`，並將 16-bit `[esi+0x158]` 值交給 `0x4A6900`；此資料流**未追到 Quest packet handler**。注意 `0x630C20` 的函式邊界與此模組類別歸屬尚未閉合。

### 2.2 0x630D50 — 兩個事件值

```asm
630d53: cmp DWORD PTR [ebp+0x8],0xc352
630d5c: lea eax,[ebp+0x8]
630d60: call 0x45efe0
630d68: cmp DWORD PTR [ebp+0x8],0x61a8
630d75: call 0x632d70
630d7c: ret 0x0c
```

`0xC352` 與 `0x61A8` 是此事件介面比較的數值，尚未確認為 Quest 接取按鈕或官方 wire opcode。為追後續語意應從這兩個 callee 及 UI 資源查，而非先命名 AcceptQuest。

## 3. 目前停止理由與後續輪次

第 1 輪已形成**具兩種物件配置模式與實際 vtable slots、元素建構者、錯誤路徑的完整本機功能鏈**，為前段僅查得子物件建構器以外的新技術進展，按 `02` 的重大進展門檻可結束本正式段。第 2 輪 T16-82-2 與第 3 輪 T16-82-3 **未啟動**，不得捏造搜尋紀錄。

本段尚未證明 Quest 業務 opcode，不能說玩家點擊後有發包，也不能證實接任務需要或不需要伺服器。下一段 T16-83：以 `0x630D50` → `0x632D70` / `0x45EFE0` 為一線，另由真正的 Quest cache state writer 或 NPC Accept UI callback 反向追到發送佇列；不要僅因相鄰函式就假設共享類別。

## 4. 玩家情境矩陣

| 玩家情境 | Client gate | C→S 發送 | S→C 回覆 | Client UI/state | Server 待開發 |
|---|---|---|---|---|---|
| 選擇 NPC 任務 | unknown | unknown | unknown | 子視窗配置流程已確認，但與 NPC 選任務的直接關聯 unknown | 待先確定 Client 實際封包格式 |
| 接受任務 | unknown | unknown | unknown | `0xCB/0xCC` 為本地事件比較，是否接受任務 unknown | 接受／拒絕條件僅列待開發 |
| 完成任務與下一任務開放 | unknown | unknown | unknown | Quest cache writer 未定位 | 任務完成／解鎖 Server 邏輯尚不屬 Client 證據 |

## 5. 分工、完整性、修正

僅更動 T16 個人技術原稿；T02 framing/socket、T07 關卡、T14 結算、T15 保存均維持主責。舊 `T16-81` GitHub 稿比本地完整原稿短，本輪另行補交**逐字相同**的 T16-81 正本，修正研究存檔完整性。無修改／執行遊戲，無把 UI 數值映射到 wire opcode。
