# E05 — KR SceneList 雙來源載入函式與共用資源介面原生閉環（BIN-first）

2026-10-29；原件 Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Event.stp SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。僅離線讀取原始 BIN；沒有執行／修改 Client。研究分支 extra/roy1，暫存 kr-extra-roy。

## 1. E04 的欠缺已補：完整路徑有實際機器碼引用

對原始 BIN 原生位址計算 `.rdata` VA=raw+0x401A00，並搜尋各字串 VA 的 LE32 直接引用：

| 資源 | 字串 raw | 字串 VA | 機器碼引用 VA |
|---|---:|---:|---:|
| Event/SceneList.xml | 0x80EC68 | 0xC10668 | 0x560816 |
| Table/SceneList.xml | 0x8018C8 | 0xC032C8 | 0x47DE86 |

**重要修正**：E04 稱未找到直接指標命中的說法不正確；本段對完整 BIN 實際搜尋精確 LE32 指標，兩處各找到一個命中。上一段的 negative pointer 結論應撤回，以 E05 為準。

## 2. Event/SceneList.xml：0x5607D0 載入鏈

BIN 指令（地址為 PE VA）：

```asm
0x560810 lea eax,[esp+0x64]
0x560814 push eax
0x560815 mov ecx,0xC10668      ; "Event/SceneList.xml"
0x56081A call 0x72EE30         ; 初始化帶檔名的工作物件
0x560830 mov ecx,[esp+0x84]
0x560839 lea ecx,[esp+0x84]     ; SSO 長度分支
0x560840 push ebx              ; 0
0x560841 lea esi,[esp+0x68]
0x560845 call 0x72F110         ; 以路徑讀取／建立資源物件
0x56084A test al,al
0x56084C je 0x560A26           ; 失敗分支
0x56087D push 0xC1067C
0x56088A call 0x72E2E0         ; 後續查找/節點操作，語意待確認
```

0x5607D0 函式另有 `SCENESET`、`questIdx`、`funcName` 相關解析候選；本段只證其資源載入入口與 failure gate，不宣稱完整 XML row 已解碼。

## 3. Table/SceneList.xml：0x47DE40 共用載入鏈

```asm
0x47DE80 lea eax,[esp+0x7C]
0x47DE84 push eax
0x47DE85 mov ecx,0xC032C8     ; "Table/SceneList.xml"
0x47DE8A call 0x72EE30
0x47DEAD lea ecx,[esp+0x9C]
0x47DEB4 push ebx             ; 0
0x47DEB5 lea esi,[esp+0x80]
0x47DEBC call 0x72F110
0x47DEC1 cmp byte [esp+0xC0],bl
0x47DEC8 je 0x47DF1F
```

兩個原生入口共用 `0x72EE30` 和 `0x72F110`，並非 E04 的孤立字串命中。

## 4. 0x72F110 下游：路徑組裝、資源節點查找、具體委派

```asm
0x72F150 mov dl,[eax]       ; NUL 結尾路徑長度
0x72F157 sub eax,edi
0x72F15E call 0x402A70    ; 小字串／長度管理
0x72F172 call 0x403040    ; 路徑字串操作
0x72F183 push 0xBED1E0
0x72F188 push eax
0x72F189 call 0x714770    ; 查找資源節點（功能暫稱）
0x72F193 test ebx,ebx
0x72F195 je 0x72F1C7     ; 查找失敗回退
0x72F197 push [ebp+8]
0x72F19F call 0x72F260    ; 下一個有證 reader 入口
0x72F1A4 mov edx,[ebx]
0x72F1A9 mov eax,[edx+4]
0x72F1AE call eax         ; 資源節點 virtual method
```

`0x72F110` 是 **共用檔案資源分派與委派入口**；此段未證明 `0x72F260` 或 vtable `+4` 正是 `EX` decompressor。當 `0x714770` 不返回節點時會走另一 fallback，必須繼續分析，不得只取成功分支。

## 5. 可重現的 read-only xref 檢查

```python
from pathlib import Path
import hashlib,struct
b=Path("Tartaros.bin").read_bytes()
assert hashlib.sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
for s,raw,callraw in [
("Event/SceneList.xml",0x80EC68,0x15FC16),
("Table/SceneList.xml",0x8018C8,0x7D286),
]:
    va=raw+0x401A00
    assert b[raw:raw+len(s)]==s.encode()
    assert b[callraw:callraw+4]==struct.pack("<I",va)
    print(s,hex(va),hex(callraw+0x400C00))
```

## 6. 玩家情境、Server 規格與界線

- 已確認原生 Client 使用 `Event/SceneList.xml` 載入呼叫、成功才走後續解析；`Table/SceneList.xml` 是另一來源，不能混合 row/schema。
- 原始 STP `EX` 區塊仍未還原，沒有可驗證 XML 解碼輸出、XML SHA 或解壓器。不得宣稱先前 E03 直接 zlib 失敗意味沒有解碼器。
- 需要從 `0x72F260`、`0x714770` 和虛擬槽 `+4` 回溯實際 raw data source，才可能碰到 STP `EX` codec。這可能跨模組或多層緩衝，不能把 `0x72F110` 直接命名為 EX codec。
- 原版選角 `0x42`、first-login Tutorial 分支和 Server SV-04～SV-07 仍未閉合，本段不可捏造 wire format。
- E05 已得兩個明確 native caller+shared loader 的實質證據，依共用三輪門檻本段停止，E05-2/3 未做；不是 XML 解碼完成。
- 等 T01 正式吸收並驗證原稿 provenance 後才按使用者規則清理整合目標 `kr-extra-roy/`；本段不觸碰 main。
