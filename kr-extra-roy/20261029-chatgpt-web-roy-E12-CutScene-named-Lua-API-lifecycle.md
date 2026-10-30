# E12 — Lua binding 實名校正、CutScene 狀態機與 Sequence 路徑錨點（BIN-first）

日期：2026-10-29（Asia/Taipei）。原始 `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，原件唯讀；未執行／修改 Client。本段 E12 承接 `extra/roy1:kr-extra-roy/` E11，並核對 `02-PROJECT-SHARED-INSTRUCTIONS.md`。原生反組譯使用 `.text VA = raw + 0x400C00`，資料指標另外依 PE section 對應，不混用映射。

## 第 1 輪：E11 重大校正——註冊資料真實名稱

**E11 誤判／限制需正式修正**：`0xD6A250`、`0xD6A260`、`0xD6A26C` 並不是不可讀、不可命名的 binary registration array。這些位置在 PE `.data`，對應原 BIN raw `0x967A50`、`0x967A60`、`0x967A6C`，原始 bytes 以 NUL 結尾的 ASCII：

| native VA | raw | 名稱 | E11 已確認 callback | native target |
|---|---:|---|---|---|
| `0xD6A250` | `0x967A50` | `StartCutScene` | `0x568A30` | `0x561760` |
| `0xD6A260` | `0x967A60` | `EndCutScene` | `0x568A90` | `0x561DB0` |
| `0xD6A26C` | `0x967A6C` | `IsCutSceneRunning` | `0x568AF0` | `0x489CF0` |

此為一手 BIN ASCII × E11 原生 registration xref 的雙證據，不再把三者誤稱為待辨識的未命名 Lua API。註冊 `0x6F5510` 本身接受 NUL 結尾字串：`0x6F5530–0x6F553C` 掃描 `byte[eax]` 到 NUL，`0x6F5559 call 0x6FEC70` 建立 Lua 字串，並將 type `4` 寫至 Lua slot `[edi+8]`。因此 `0x6F5510` 是實際 Lua 字串常數/名稱入棧者（更完整 register 作用取決於周邊 `0x6F55B0`），而不是資料列解析器。

## 第 2 輪：0x561760 StartCutScene gate/副作用，超越單純兩整數 callback

E11 已證 `StartCutScene` wrapper `0x568A30→0x56A220→0x561760`，由 Lua stack 讀取兩個 number/int 後作 C++ method 參數。本輪新增 native：

```asm
561797 cmp dword ptr [0xFBAB18],0
5617A2 xorps xmm0,xmm0
5617A5 movss [0xFBAB24],xmm0
5617AD call 0x40F060
5617BA movss [eax+0xAC],xmm0
5617C2 cmp dword ptr [ebx+0x28],0
5617C6 mov byte ptr [ebx+0x89],0
5617CF mov eax,[ebp+0xC]
5617D2 mov ecx,[ebp+8]
5617D7 push 0xC106AC
5617DC call 0x6EDB60
5617E4 jmp 0x561D86
5617E9 test byte ptr [0xFB8828],1
5617FD mov dword ptr [esp+0x68],0
561805 call 0x54F850
561823 cmp byte ptr [0xFB92F1],0
561830 cmp dword ptr [ebp+8],0
56183A call 0x404BA0
56183F cmp dword ptr [eax+0x5F4C],9
561848 call 0x404BA0
56184D cmp dword ptr [eax+0x5F4C],4
561856 call 0x404BA0
56185B cmp dword ptr [eax+0x5F4C],0x19
561864 mov esi,[ebx+0x78]
56186B lea ecx,[ebx+0x74]
561872 call 0x4364C0
56187D push 0xF
56187D..5618C2 call 0x5855B0/0x585330/0x402250/0x40F8C0/0x4D6B30/0x4FA440/0x414680
```

關鍵：
- `[this+0x28] != 0` 時會進入錯誤/中斷分支，並在 `0x5617C6` 清除 `this+0x89`。這支持「切場景開始前不可重入」的有限 gate，但不可將錯誤 helper `0x6EDB60` 自行視為完整 runtime exception。
- 若 `[0xFBAB18] !=0`，清零 `[0xFBAB24]` 並更新某單例 `+0xAC` 浮點欄位；目前僅能描述寫入效果，不冠名 camera/transition speed。
- `[0xFB92F1]`、first arg=0、`[0x404BA0()+0x5F4C]` 為 9/4/25 形成有界特殊分支，並將 `[this+0x78]`、`this+0x74` 送入另一路 helper。不能由這幾個值直接認定 tutorial scene type。
- `0x561760` 是 **StartCutScene 的本機 CutScene 狀態操作**，不是 T03 選角 `0x42` response builder；需再追其較後方 `0x5618C2..0x561D90` 完整 CFG 才能稱 CutScene 完整 lifecycle。

## 第 3 輪：EndCutScene 與 IsCutSceneRunning 實際欄位對接

```asm
489CF0 mov eax,[ecx+0x28]
489CF3 ret
```
`IsCutSceneRunning` 直接返回 `this+0x28`；而 `StartCutScene` `0x5617C2` 以此欄位為非零 gate，`EndCutScene` `0x561DF0` 檢查相同 `[edi+0x28]`，非零時 `0x561DF6` 清零。由此首次獲得三個已具真實 Lua 名稱的 **共享同一 this+0x28 狀態欄位** 的有界啟動、查詢與結束語意閉環。

```asm
561DE0 cmp byte ptr [edi+0x89],0
561DE7 je 0x561F60
561DED cmp dword ptr [edi+0x28],esi  ; esi=0
561DF6 mov dword ptr [edi+0x28],esi
561DF9 call 0x434250
561E03 mov [eax+0x14],ebx           ; ebx=1
561E36 push 0xC106EC               ; f_removeAllCoroutines
561E3D push 0xFDF3C8
561E42 call 0x4AD0A0
561E70 fld dword ptr [edi+0x84]
561E88 call 0x589A20
561E8D mov bl,[edi+0x88]
561E93 call 0x404BA0
561E98 mov [eax+0x68C4],bl
561ED1 mov eax,[edi+0x3C]
561ED4 mov ecx,[edi+0x38]
561EDE call 0x47E640
561EE5 mov [edi+0x3C],eax
561EF3 call 0x565720
561F39 mov eax,[edi+0x34]
561F42 call 0x6D9430
561F47 mov [edi+0x38],ebx
561F4A mov [edi+0x3C],ebx
```

`EndCutScene` 除了清理 running flag，還有協程管理字串 `f_removeAllCoroutines`、浮點狀態傳給 `0x589A20`、另一 manager `+0x68C4` byte writer，以及後續 scene/camera-like resources 的狀態交接。只證實呼叫/寫入，**不對這些子系統猜原名**。此路徑說明 `EndCutScene` 是多階段 lifecycle，不是單一布林 toggle。

## 新增的 seq locator 原件錨（不同於 XML row）

原始 BIN `.rdata`：
- `Event/Sequences/` at raw `0x80ECD0` → VA `0xC106D0`
- `.seq` at raw `0x80ECE4` → VA `0xC106E4`
- 同一區另有 `f_removeAllCoroutines` 及任務索引／`funcName` 字串。

這些為拼接出 `Event/Sequences/<name>.seq` 的**候選構件**，但本輪尚未沿 caller 證明完整 string assembly；不應將 locator 猜想提升為真正的 runtime seq loader。

## 重現（BIN-first）

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x561760 --stop-address=0x5619a0 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x561db0 --stop-address=0x561f60 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x489cf0 --stop-address=0x489cf4 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6f5510 --stop-address=0x6f5573 Tartaros.bin
```

```python
from pathlib import Path
from hashlib import sha256
b=Path("Tartaros.bin").read_bytes()
assert sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
data_va_to_raw=lambda va: va-0xD61000+0x95E800
rdata_va_to_raw=lambda va: va-0xBD2000+0x7D0600
for va,s in [(0xD6A250,b"StartCutScene"),(0xD6A260,b"EndCutScene"),(0xD6A26C,b"IsCutSceneRunning")]:
    assert b[data_va_to_raw(va):].startswith(s+b"\0")
for va,s in [(0xC106D0,b"Event/Sequences/"),(0xC106E4,b".seq")]:
    assert b[rdata_va_to_raw(va):].startswith(s+b"\0")
```

## 對研究目標的界線與下一段

- **Client native 已確認**：具名 Lua callback `StartCutScene`／`EndCutScene`／`IsCutSceneRunning` 與共享 `this+0x28` lifecycle；本地有完整 seq 字串構件。
- **Client 待逆向**：`Event/Sequences/` 實際使用者、`funcName→seq path→Lua Execute/Register`、`Tutorial_EntryPoint` 到此 CutScene 的真實調用、T03 `0x42` response 到首登 decision。
- **Server 待開發**：待前述 Client wire/handler 已確認後實作相容的首登 state/scene decision；不要把 XML `1001/1` 當已證 S→C 格式。
- **跨 Task 待整合**：T03/T07/T16 原稿與此次 E12 的 CutScene API 應分離來源；不自行提升 T01 FULL-PASS。
- **待遊玩驗證**：本次沒有跑原 Client，沒有 claim tutorial 可玩。
- **下一段 E13**：優先追 `0xC106D0`、`0xC106E4` 的具體 xref 與路徑字串建立者（可連 `0x561760` 後半段、`0x561DB0` 的 `0x561F60..`），再追 Lua runtime script loader。
- E12 第一輪已取得與 E11 不同的**正式 Lua 名稱與共享 cutscene lifecycle** 大幅新證，第二、三輪另外做雙向 CFG；不宣稱全函式驗證。E01～E12 原稿均留 `extra/roy1:kr-extra-roy/`，待 T01 正式整合且可稽核後才依使用者指示清理。Main 不改。
