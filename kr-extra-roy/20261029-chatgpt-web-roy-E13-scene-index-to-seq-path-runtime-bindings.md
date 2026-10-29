# E13 — KR Event/Sequences/<funcName>.seq 雙鍵讀取與 Lua 環境初始化（BIN-first）

研究日期 2026-10-29（Asia/Taipei），原始 BIN 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Event.stp SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。原件唯讀；沒有啟動、修補或呼叫遊戲程式。承接 E12。

## 一、重大新證：兩個原生雙鍵 SceneList reader，均實際建構 .seq 路徑

完整原始 BIN 直接尋找 `0xC106D0`（`Event/Sequences/`）和 `0xC106E4`（`.seq`）的 little-endian VA 指標：
- Prefix 的直接 caller 僅 `0x561A8D`、`0x56592E`。
- Suffix 的直接 caller 僅 `0x561ACB`、`0x56596D`。
這是 bounded immediate xref，不排除間接引用。

`0x561A1C–0x561A85` 取自 `[this+0x0C]` 的 RB-tree-like node，依 `[arg+8]`、`[arg+0xC]` 兩個整數依次比較 `node+0xC` 和 `node+0x10`。只有命中且不是 sentinel 才進後面的路徑構建；miss 跳到 `0x561D7F`。這是 E08 的 writer `0x568950→0x568680` 以外，首次找到具體 two-key consumer。

```asm
561A30 mov ecx,[eax+0xC]
561A33 mov edi,[ebp+8]
561A36 cmp edi,ecx
561A3C mov ecx,[ebp+0xC]
561A3F cmp [eax+0x10],ecx
561A5E mov eax,[edx+0xC]
561A64 cmp eax,ecx
561A6A mov eax,[ebp+0xC]
561A6D cmp eax,[edx+0x10]
561A82 cmp esi,[ebx+0xC]
561A85 je 0x561D7F
561A8B push 0x10
561A8D push 0xC106D0         ; "Event/Sequences/"
561AAB call 0x402A70         ; initialize prefix string
561AB0 lea eax,[esi+0x14]     ; matching scene node funcName string
561AC4 call 0x401ED0         ; append funcName
561AC9 push 0x4
561ACB push 0xC106E4         ; ".seq"
561AD4 call 0x401FC0         ; append suffix
561AEA call 0x55C5A0         ; note: singleton access, NOT file read itself
561AF3 call 0x55D6A0         ; script environment setup
561AFA mov [ebx+0x70],eax
```

因此，可將 `(questIdx,sceneIdx)` → `funcName` → `Event/Sequences/` + `funcName` + `.seq` 視為已證的**Client 原生路徑產生鏈**；尚不能宣告 Lua 檔已成功執行。

## 二、另一個 reader（0x5658D0–0x565A21）：不同下游效果

第二條也按 `[arg+8]`、`[arg+0xC]` 比較 `node+0xC/+0x10`，從 `node+0x14` 拿 funcName，組成完整 path：

```asm
5658D0 mov edx,[eax+0xC]
5658D3 mov edi,[ebp+8]
5658D6 cmp edi,edx
5658DC mov edx,[ebp+0xC]
5658DF cmp [eax+0x10],edx
565924 cmp edi,[esi+0xC]
565926 je 0x565A65          ; miss
56592C push 0x10
56592E push 0xC106D0       ; prefix
56594C call 0x402A70
565951 push -1
565953 lea eax,[edi+0x14]
565966 call 0x401ED0       ; append selected funcName
56596B push 4
56596D push 0xC106E4       ; ".seq"
565976 call 0x401FC0
5659B5 push edi             ; path
5659B6 push 0xFE1EEC       ; Lua environment owner
5659BB call 0x55D6A0
5659C5 mov [esi+0x70],eax
5659D9 call 0x6F4A50       ; separate Lua source/context interface
5659DE call 0x434250       ; state side-effect
565A15 push 2
565A17 push 0xFC0E90
565A1C call 0x79D9C0
```

兩者同樣使用 XML 雙鍵 index、prefix + funcName + suffix，但第二條**追加 Lua interface 和 scene state side effects**，不是第一條的同義 wrapper。原生 `0x5659D9` 的實際 Lua 執行語意需從 callee 和 loop 追查，不能單憑 `0x6F4A50` 便宣稱 `tutorial_start` 已被 invoke。

## 三、0x55C5A0 和 0x55D6A0 的真正作用（修正簡化命名）

`0x55C5A0` 不是直接檔案 reader：它檢查 `[0xFE1EE8]` one-time init bit，必要時 `call 0x55C610`（這條分配、初始化 singleton/容器），最後 `mov eax,0xFE1EEC` 返回該 owner。這個 callee 在 `0x561AEA` 只取得 owner 指標。

`0x55D6A0` 接收 script/runtime owner 與路徑，`0x55D6B1 call 0x55E2E0`，後續建立 Lua/C++ native callback 表：

```asm
55D6B1 call 0x55E2E0
55D6CF push 0x55C940
55D6D7 call 0x6F55B0
55D6E1 mov edi,0xC10230    ; "CreateObject"
55D6EB call 0x6F5790
55D6F7 push 0x55CCE0
55D6FF call 0x6F55B0
55D709 mov edi,0xC10240    ; "AniObject"
55D713 call 0x6F5790
55D71F push 0x55CED0
55D727 call 0x6F55B0
55D731 mov edi,0xC1024C    ; "WalkObject"
55D73B call 0x6F5790
55D747 push 0x55D220
55D74F call 0x6F55B0
55D759 mov edi,0xC10258    ; "WarpObject"
55D763 call 0x6F5790
```

`CreateObject`、`AniObject`、`WalkObject`、`WarpObject` 由原 BIN RDATA 真正 bytes 驗證，並非臆測。這是 **腳本環境原生 binding registration** 的新下游證據。必須繼續追 `0x55E2E0` 與 `0x6F4A50` 才可確認 compile/load/run。

## 四、可重現的 BIN 驗證

```python
from pathlib import Path
from hashlib import sha256
b=Path("Tartaros.bin").read_bytes()
assert sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
for va,pat in [
 (0xC106D0,b"Event/Sequences/"),
 (0xC106E4,b".seq"),
 (0xC10230,b"CreateObject"),
 (0xC10240,b"AniObject"),
 (0xC1024C,b"WalkObject"),
 (0xC10258,b"WarpObject"),
]:
 raw=va-0x401A00
 assert b[raw:raw+len(pat)]==pat
 needle=va.to_bytes(4,"little")
 print(hex(va),[hex(i+0x400c00) for i in range(len(b)) if b.startswith(needle,i)][:20])
```
```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x561a1c --stop-address=0x561b10 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5658d0 --stop-address=0x565a22 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x55c5a0 --stop-address=0x55c665 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x55d6a0 --stop-address=0x55d780 Tartaros.bin
```

## 五、玩家情境與未解界線

- **已確認**：Client native `(questIdx,sceneIdx)` 雙鍵 reader → 命中場景節點 `funcName` → `Event/Sequences/<funcName>.seq` path → runtime object setup, plus Lua native bindings。
- **Client 待逆向**：`0x55E2E0` 真正 file/source reader 及 `0x6F4A50` 是否會執行；`0x561D7F` miss branch、二條 reader 的上游 caller、Lua `Register(tutorial_start)` 實際消費者、選角 `0x42` 之 S→C result → scene pair。
- **Server 待開發**：首登教學決策與相容 state，但尚無經核實之正式 scene switch wire packet，不能將 `1001/1` 視為每個新帳號的必然下發值。
- **跨 Task 待整合**：T03/T06/T07/T16 舊成果和 E06/E08/E13 场景/腳本鏈；保持 hash/blob provenance，不冒認 T01 FULL-PASS。
- **待遊玩驗證**：本段僅 Client 原始 BIN 和 Event.stp 靜態還原；未做 runtime 玩家驗收。

**三輪門檻**：E13 第一輪已真正關閉之前缺失的場景雙鍵 read → 原生 .seq 字串建構 → Lua runtime setup 有界鏈，為重大新證；第二／第三輪未啟動，原因是本段重大新發現已達門檻，不是表示執行/遊玩已完成。

**整合清理**：只更新 `extra/roy1:kr-extra-roy/`；在 T01 全量吸收並核驗之前不可刪除資料夾，也不改 main。
