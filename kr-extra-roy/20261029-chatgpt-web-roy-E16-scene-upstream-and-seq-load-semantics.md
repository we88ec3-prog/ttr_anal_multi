# E16 — 場景雙鍵讀取者的兩條實際上游、Script 載入時序與首登證據邊界

研究日期：2026-10-29 Asia/Taipei。研究來源：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；上一段 E15 原稿（`extra/roy1:kr-extra-roy/20261029-chatgpt-web-roy-E15-Lua-protected-call-dual-seq-loader.md`）。本輪僅使用原始 BIN 靜態反組譯；不執行或修改 Client。段號 E16，無合併 `main` 操作。

## 一、本輪真正新的 caller：0x47B5C0 → 0x565720

`0x565720` 是第二條場景查表／啟動流程的函式入口（不同於函式內部迴圈標籤 `0x5658D0`）。對整段 `.text` 原始 bytes 搜尋直接 E8 rel32，`0x565720` 的直接 caller 有兩處：`0x47B64A`、`0x561EF3`。這把此前只有內部查表細節的路徑，延伸到了明確的外部狀態來源。

```asm
47B5C0 push ebp                      ; containing function start
47B5E9 mov edi,ecx
47B5EB cmp dword ptr [edi+0x248],0xEA61
47B5F5 jne 0x47B608
47B5F7 cmp byte ptr [edi+0x26C],0
47B5FE jne 0x47B64F
47B600 push edi
47B601 call 0x47B850               ; special case branch
47B608 test byte ptr [0xFB73B8],1   ; one-time initialization flag
47B620 call 0x560170               ; conditional scene-owner init
47B63A mov eax,[ebp+8]
47B63D mov ecx,[edi+0x248]
47B643 push eax
47B644 push ecx
47B645 mov esi,0xFB73C0
47B64A call 0x565720               ; (object+248, arg1)
```

這裡 `0xEA61` 是**物件欄位比較常數**，且命中時須看 `[object+0x26C]` 決定是否呼叫 `0x47B850`，不能直接叫它 S→C opcode、教學 ID 或 questIdx。其他分支以 `[object+0x248]` 與外部 `arg1` 作雙參數轉交，`ESI=0xFB73C0` 是場景 manager/global owner（名稱暫稱）。`0x47B5C0` 的 caller 及 `[object+0x248]` 的 writer 尚待追。

## 二、第二個 caller：EndCutScene 的復原路徑

E12 已確認 `EndCutScene` 的 native 入口 `0x561DB0`；本輪直接查得它後續透過 `0x47E640` 取回某個 32-bit 值並在非零時調用相同的 `0x565720`：

```asm
561EDE call 0x47E640
561EE3 xor ebx,ebx
561EE5 mov [edi+0x3C],eax
561EE8 cmp eax,ebx
561EEA je 0x561F0B
561EEC mov edx,[edi+0x38]
561EEF push eax
561EF0 push edx
561EF1 mov esi,edi
561EF3 call 0x565720
```

所以 `0x565720` **並非只服務第一次進入場景**；它也能在 CutScene 結束時被再次調用。原生輸入分別來自 `this+0x38`、`0x47E640` 的結果，不能與上段 `object+0x248` 誤標成同一欄位。這也反證「任何進入 `0x565720` 的行為都是首次登入」的猜法。

## 三、兩條 .seq 載入行為的精確比較（修正 E15 的不確定點）

E15 已確認 `0x55D6A0` 在 `0x55D7C2` 內部呼叫 `0x6F4A50`。本輪查對兩條使用者：

- `0x561AF3` 先呼叫 `0x55D6A0`；其 `arg2` 是當前利用 `funcName` 組成的 `Event/Sequences/<name>.seq` 路徑。之後第一條路徑還在 `0x561C7D` 對先前建立的局部路徑呼叫 `0x6F4A50`。故第一條也有**獨立額外讀入路徑**；E15 若只突出第二條有再次呼叫，範圍不足，須在整合時修正。
- `0x5659B5 push edi; 0x5659B6 push 0xFE1EEC; 0x5659BB call 0x55D6A0` 後，`0x5659C5 mov [esi+0x70],eax`，隨後 `0x5659C8..0x5659D6` 從同一個局部 `std::string` 的 SSO／heap 表示重新取得路徑 pointer，`0x5659D9 call 0x6F4A50`。因此就**可見路徑字串來源**而言，第二條內外兩次呼叫採同一個字串物件；不應先猜「載入不同的兩份 .seq」。但 `0x55D7C2` 和 `0x5659D9` 的 Lua VM context／副作用不同，不能稱為完全重複執行或 Bug。

原生證據：

```asm
55D7BB mov eax,[ebp+0xC]       ; caller-supplied path
55D7BE mov ecx,[ebx+4]
55D7C1 push eax
55D7C2 call 0x6F4A50
5659B5 push edi                 ; selected scene .seq path
5659B6 push 0xFE1EEC
5659BB call 0x55D6A0
5659C5 mov [esi+0x70],eax
5659C8 mov eax,[esp+0x1C]     ; same local string object
5659CC cmp [esp+0x30],0x10
5659D0 jae 0x5659D6
5659D2 lea eax,[esp+0x1C]     ; SSO inline path
5659D6 push eax
5659D9 call 0x6F4A50
561C67 mov eax,[esp+0x20]
561C70 cmp [esp+0x34],0x10
561C76 lea eax,[esp+0x20]     ; SSO inline path
561C7C push eax
561C7D call 0x6F4A50
```

**現有證據只閉合靜態 call edge；未抓取 runtime stack，因此不宣稱成功呼叫兩次 Lua function 或二次場景重啟。** `0x6F4A50` 的錯誤回傳仍須檢查。

## 四、對首次登入 → Tutorial 的真正阻塞

已確認原始 BIN 的兩個 C++ entry point 可以從 XML 索引查 `(questIdx,sceneIdx)`，組 `Event/Sequences/<funcName>.seq`，並到 Lua 載入／protected-call 層；E06/E08 對應 XML `1001/1 → tutorial_start` 及 STP 中 `.seq` 文字已證。**然而未找到任何一條原生關係證明**：`command 0x42` 選角回覆派送了 `(1001,1)`；也未確定 `0x47B5C0` 的 `[object+0x248]` 是任務、地圖、cutscene 或別種 scene identifier。這些仍屬 Client 待逆向，而非 Server 自行填值。

原生 `005F type6` 在 T07 中曾有「建立 CDuelField、fixture 修補成 Tutorial」的反證，不能用測試可玩結論替代。前述 `0xEA61` 與 `1001` 更沒有可直接等號連接的證據。

## 五、三輪深入與後續具體入口

- 第一輪：兩個 `0x565720` 直接 E8 caller、`0x47B5C0` `0xEA61` gate、`EndCutScene` 重入 caller。**達成重要新上游證據**，不同於舊 callsite 清單。
- 第二輪：比較 `0x55D6A0`、`0x5659D9`、`0x561C7D`，修正「只有第二條額外載入」的舊界線。**有額外確證**。
- 第三輪：未啟動；前兩輪已達重大證據門檻，依 02 共用規則停止 E16。

E17 建議：`0x47B5C0` 的直接/虛擬 caller 與 `[object+0x248]` writer；`0x47E640` 的回傳語意、EndCutScene 的 key/state；第一條 `0x561C7D` 呼叫時的 VM context；最後配對 T03 `0x42` S→C handler。另從 `0x565720` 的錯誤/查表 miss 分支驗證資源不存在時是否保持原場景。

## 六、可重現證據

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x47b5c0 --stop-address=0x47b690 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x561ed8 --stop-address=0x561f0c Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5659b5 --stop-address=0x5659e5 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x561c65 --stop-address=0x561c87 Tartaros.bin
```

```python
from pathlib import Path
from hashlib import sha256
import struct
b=Path('Tartaros.bin').read_bytes()
assert sha256(b).hexdigest()=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
base=0x400c00
for target in [0x565720,0x55d6a0,0x6f4a50]:
 callers=[i+base for i in range(0x400,0x7d0600-5) if b[i]==0xe8 and i+base+5+struct.unpack_from('<i',b,i+1)[0]==target]
 print(hex(target),[hex(c) for c in callers])
```

分類：Client 待逆向＝選角回覆、場景 key writer 及實際首次登入 gate；Server 待開發＝僅在 Client wire 確定後實作相容場景/帳號狀態；跨 Task 待整合＝E06/E08/E13～E16 與 T03/T07/T16；待遊玩驗證＝尚無原版 Client runtime 驗收。E01–E16 保留於 `extra/roy1:kr-extra-roy/`，T01 完整吸收後才清理，不修改 `main`。