# E70 — RR-0009 / T03：空角色名單至建角 GUI 的原生候選、反例與可解除證據缺口

> 2026-10-31 / chatgpt-web roy / KR BIN-first / 唯一研究分支 `extra/roy1`。原始 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；原始 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；資源 `Table.stp`：5,248,784 bytes，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。均已從本輪實檔重新核對。未執行或修改 Client，沒有原版 Server 封包擷取。

## 0. 決議摘要與 RR 驗收條件

RR-0009 正式要求從 KR `S→C command2` 的 `65+53*N`、`0x4D4150` 角色資料 writer，正向追到 N=0/create-button GUI branch、resource ID、scene prerequisite、control producer、event consumer、create dialog。還須檢驗 N=0、N>0、缺資源、資料已填而 UI 未 ready，且不可從 `F42EF/F4246/F4247/F4278` 或 `0x665150` 的 list-hit 直接推 UI 可用。此 RR 限 UI；`RR-0010` 的建角 C2S/S2C 交易保持 QUEUED，`RR-0002` 選角回覆仍 BLOCKED，`RR-0007` T02 下游分派不重做。

**原生 Client 有界結論**：空 roster 的迴圈跳轉、非空 roster 53-byte row、之後資料更新、`CEmployNewCharacter@FUI@@` RTTI、cache 建立與 UI-owner 登記、候選 local event 均找到了。**沒有正向證據能證明 N=0 會啟用可點擊的建角按鈕或開啟建角 dialog。** 這不是說它不存在，而是資料／事件連結在所核對範圍內不閉合。RR 驗收第 5 條明定若無 positive entry，應提交 precise blocker + 解除條件；本稿據此完成有界研究交付，**不宣稱玩家建角畫面已開、T01 FULL-PASS 或 S00 ACCEPTED**。

已完成使用者指定 Git Merge：`main→extra/roy1` 的 PR #58 合併 Commit `f764b88b77a9e10f1b5ec43f247637b873b6b874`，父 SHA 分別為原 extra 與 main。正式 RR 先在 main CLAIMED，claim branch = extra/roy1；沒有建立新研究 branch。另 T03 T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX 是獨立待修，不能當作已驗收。

## 1. 原生來源與可重現驗證

KR PE32 x86：`.text` VA `0x401000` raw `0x400`（此段 raw=VA-`0x400C00`），`.rdata` VA `0xBD2000` raw `0x7D0600`，`.data` VA `0xD61000` raw `0x95E800`。由 PE section headers 證實，RTTI 不得誤用 .text 轉址差額。定向反組譯來源為 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=VA --stop-address=VA2 Tartaros.bin`，直接 E8 rel32 遍掃整段 .text 的匹配還需驗證指令邊界。

已執行 30 項嚴格的 PE 原生 bytes、函式分支、RTTI、call-sites 與 STPD 資源檢查，全部 PASS。交付 `E70-RR0009-verify.py`。測試是 static self-audit，不是執行 Client、GUI screenshot、Server trace，也不是 T01 全文正確的審核判決。

## 2. cmd2 長度與 N=0 vs N>0

`0x4B8923` 讀 length 並檢查最低 65 bytes。`0x4B892F..0x4B893F` 以 `(length−65)/53` 取得 row 迴圈數 N。原始 machine bytes 由驗證腳本精確比對。主要指令：

- `0x4B894A test ECX,ECX`，`0x4B894C je 0x4B8A20`。N=0 只**跳過 row loop**，不等於開建角視窗。
- N>0：`0x4B8952 mov EDI,[ESP+0x28]`，`0x4B8956 add EDI,0x6F`，`0x4B8992 movzx EAX,[EDI]`，`0x4B8995 cmp EAX,9`，`0x4B899A imul EAX,EAX,0x210`，`0x4B89AD call 0x4D4150`，`0x4B8A0E add EDI,0x35`，`0x4B8A16 dec count`。不要把 EDI 指標來源與 app payload absolute offset 混淆。
- `0x4D4154 mov [ESI+0x5C],1`：證實角色 record 被初始化/允許本地顯示候選，不等於 GUI ready、角色已進入世界或 Server 已授權選角。
- **兩路匯合** `0x4B8A20`，`0x4B8A60 mov word [0xF94240],AX` 存本地 mask，`0x4B8A9C call 0x4E5FB0`，後續有條件發本地 C2S 應用命令 `0x24`（`0x4B8AC4`），也可能排 `0x1F/0x25/0x15`。這些是網路應用命令，不是建立角色 GUI event。
- `0x4E5FB0` 讀 Client +`0x6924` 角色記錄 array，`0x4E5FEB call 0x4D4590`，`0x4E5FF5/0x4E5FF7` 依回傳為 0 跳後繼 `0x4E6121`；其它路徑比較 cached `+0x68CC/+0x5F4C`。已核的 direct E8 callers `0x4B8A9C`、`0x4E2794`。它只是**N0/N>0 共用的狀態處理**，未找到它對建角視窗的正向直接開啟。

## 3. CEmployNewCharacter 是真實 RTTI，但功能不能單憑命名

MSVC RTTI 原生 `.?AVCEmployNewCharacter@FUI@@`：vptr `0xC3F024`，COL `0xC7AD44`，TypeDescriptor `0xF87EF0`。不保證名稱裡的「NewCharacter」必然指新帳號創角；也可能是遊戲內聘用/招募角色的 UI。

`0x5AB280` cache constructor 在 `0x5AB2E4` 寫 vptr `0xC3F024`，`0x5AB2EE` 將物件寫 entry+`0xC`，`0x5AB2F1` 設內部 cache type 索引 `0x11B`。**0x11B 不得擅自命名為 GUI XML / controlID**。`0x5AB020` lazy cache 入口以全域 `FE2D9C` 保存/取得 entry，`0x5AB06D` 在必要時 call `0x5AB280`；記憶體/資源失敗不保證成功。

獨立 UI owner 建構：
```text
0x5C3040 GUI owner setup
 → 0x5C30F7 LEA ESI,[EBX+0x230]
 → 0x5C30FD CALL 0x5AB020
 → 0x5C3105 CALL 0x5A9F40
 → 0x5C3156 MOV EAX,[EBX+0x230]
 → 0x5C316A CALL 0x596D70 (UI registration/manager)
```
這是 **cached object→UI-owner registration 有界鏈**，不是已證該 dialog 顯示、可點、已載入 layout、位於 character select scene，也未證由 roster N=0 觸發。

本地事件 `0x65D550` 讀 `event+0x10` 是否為 `0x387`，成立時 `0x65D585` 建 `F4350` 事件並由 `0x65D592 call 0x4072A0` 投遞。`F4350` 還有多個其他產生者（`0x5F7F8B/0x604892/0x63688F/0x6A1841/0x6BBFFF/0x6C0D24`），不是 exclusive 建角事件。未證明真正 consumer 最後開 dialog，更未證與 N0 branch 相連。

## 4. 舊 UI 事件的正確資料鏈及反證

- `F42EF`：local producers `0x6602F0` 與 `0x673E13`，consumer `0x5A69E8` 再於 `0x5A6A28 call 0x665150`。後者利用 `FE1DF4` 8-byte stride 表、ID<=9、`F94304 + ID*0x210` 的 `record+0x5C`，可更新詳細 dialog+`0x110`、控件指標 `+0xF4..+0x108`。`0x665150` 回傳1 可能只表示本地列表 hit，即使 record 未 ready 仍不能證 UI 已顯示。
- `0x59A520` caller 在 `0x665150` 回傳0時不呼叫 dialog virtual +D0；`0x5A6A28` F42EF consumer 在本地事件前提成立後無條件呼叫 virtual +D0。這兩種通知行為不可混用。
- `F4246` 由 `0x5F4760` 等選角 UI branch 產生，`F4247` 與 `0x673DA0` 的其他事件有關；`F4278` 有 `0x4B5E27` 等來源。它們是 UI 本地事件域，不是 Server wire command，不是建角視窗可見性的正向證明。
- `0x665150` 是 **已存在角色的 detail dialog** 的資料填入，不能拿來補缺失的「沒有角色→按建立角色→開編輯視窗」。

## 5. GUI 資源及 T06 諮詢的界線

已核 `kr/tasks/T06/README.md` 和 task.json，主責是地圖/場景資源與版本，不代表已有此版角色建立 layout/control 的原生映射。本輪 `Table.stp` 的 SHA 與 `STPD` 封裝均確認，能看到 Table 類 XML 目錄、AI/Matrix 類資料，**沒有可驗證的 GUI controlID、layout、button identity、texture 和建立視窗資源索引**。不能把 Table.stp 或 UI cache type `0x11B` 自動當作建角 GUI pack。若相同版本 GUI pack 未提供，resource-missing branch 無法以原版 Client 遊玩結果驗證。

## 6. 四種必考情境的可測矩陣

| 情境 | 已證 N（Client 有界） | 尚欠／反例 |
|---|---|---|
| N=0，65-byte 前置資訊 | 於 `0x4B894C` 跳過 row 迴圈，仍執行 `0x4B8A20` 共用後處理 | **無正向 N0→建角按鈕/視窗**，不能宣稱自動開 |
| N>0，合法索引 0..9 | `0x4D4150` 初始化 record+0x5C，後續 UI 要另過 ID/資源/scene gate | 有角色不能推無 create-button；需要 GUI 限額與 visibility setter |
| 缺 GUI 資源 | cache/GUI owner 函式本身存在，配置與註冊有條件 | cache 生成不等於 layout 解出、控件存在、視窗可用；缺資源為推定故障風險，不是實機已觀測錯誤 |
| data written, UI not-ready | roster mask/record set、local F42EF 與 GUI record data 可以存在 | list hit / record+0x5C / UI notify 不能替代 current scene、control enabled+visible、subscription、dialog open |

## 7. 全段 .text 直接 E8 掃描：有限陰性而非不可達

從原件 .text 搜尋 `E8 rel32` 的直接目標並在命中處回看機器碼：
- target `0x5AB280` → `0x5AB06D`；
- target `0x5AB020` → `0x5AAD11`、`0x5C30FD`；
- target `0x4D4150` → `0x4B89AD`、`0x4E2782`；
- target `0x4E5FB0` → `0x4B8A9C`、`0x4E2794`。
在 `0x4B7F00..0x4B8F40` 的命令2處理器內沒有直接 E8 到 `0x5AB020`；N=0 是跳到同函式 `0x4B8A20`。**不能排除** virtual/event/alias/thread UI/反射/回呼／狀態輪詢，所以這是一個帶證據範圍的陰性主張，不是宣稱遊戲不會建立角色介面。

## 8. 解除阻塞的具體工作

未閉合鏈：

```text
S2C0x0002 → (N=0) roster post-processing
    → UNKNOWN: N0-specific state/event writer
    → UNKNOWN: active login/character-select scene and UI callback listener
    → UNKNOWN: create-button control lookup, id, visible/enabled gate
    → UNKNOWN: actual create-dialog open / owner lifetime
```

**解除 A（優先 BIN-first）**：對 `0x4B8A20` 後續 writer、`0x4E5FB0` 所寫全域 state 做所有 read-xref（含 indirect alias）；從 UI scene 事件註冊反追到有 N0 gate 的 listener；閉合 callback→control→modal creation 并正向驗證失敗路徑。
**解除 B（GUI 資源）**：提供同版 KR 原始 GUI layout/texture pack 的實檔與 SHA，查實 `0x11B` 是否 resource/index、建立按鈕 ID、window/modal layout、載入失敗分支；不可用 Table.stp 憑空補出。
**解除 C（Client runtime）**：在獲明確允許的環境用 *標明合成* 相容 Server 發 N0/N1，對照 UI event breakpoint、control visibility、dialog lifecycle、資源 lookup，不能把合成結果稱官方 Server 常規。
**解除 D（原版正向證據）**：可信的相同 KR build 網路 capture + 畫面/事件紀錄，同步確定正向流程；記錄分 Conn、事件時序和失敗狀態。

`GAP-CHAR-0002` 保持 OPEN；`SPEC-CHAR-0001`、`SPEC-FLOW-0001` 不可標 STABLE；提議測試 N0-N1-ROSTER、DATA-WRITTEN-NOT-READY、MISSING-GUI-RESOURCE、CREATE-CONTROL-CLICK 等（**尚不是正式已存在 TEST ID**）。`RR-0010` 保持 QUEUED，無原版 create C2S/S2C 假設。這是第5條允許的「精確 blocker 報告」，不能誤稱創角 GUI 已證。

## 9. 原生 assembly 附錄與歷史交叉來源

附錄沿用 GitHub E61、T03-LOGIN-01/02 中實際 objdump 指令節錄，供 T01 核對；本輪新位址 `0x5AB020/0x5AB280/0x5C30xx/0x65D550` 透過附帶 30 項 bytes verification script 覆驗。先前原稿不刪除／改名。E61 角色網路段仍以 T02 lane2 為前提；不將 `F4350` 當 Server response。

### 新函式定位，原始指令摘要

```asm
4B894A test ecx,ecx
4B894C je 0x4B8A20
4B8A60 mov word ptr ds:[0xF94240],ax
4B8A9C call 0x4E5FB0
4D4154 mov dword ptr [esi+0x5c],1
5AB06D call 0x5AB280
5AB2E4 mov dword ptr [edi],0xC3F024
5AB2EE mov [esi+0xc],edi
5AB2F1 mov dword ptr [esi+4],0x11B
5C30F7 lea esi,[ebx+0x230]
5C30FD call 0x5AB020
5C3105 call 0x5A9F40
5C3156 mov eax,[ebx+0x230]
5C316A call 0x596D70
65D556 cmp dword ptr [eax+0x10],0x387
65D585 mov dword ptr [eax+0x10],0xF4350
65D592 call 0x4072A0
```

本檔附錄保留 E61 的 cmd2/record/cache 前置和 LOGIN-01/02 的局部證據，合計三輪來源，並在接收對象不同的地方註明分層界線。


---

### A.4 `0x4B8920` cmd2 length/row cursor/record copy/26 sender

- `.text` VA `0x004B8920..0x004B8AA2`；raw `0x000B7D20..0x000B7EA2`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4b8920:	83 ce ff             	or     esi,0xffffffff
  4b8923:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b8926:	83 f9 41             	cmp    ecx,0x41
  4b8929:	73 04                	jae    0x4b892f
  4b892b:	33 c9                	xor    ecx,ecx
  4b892d:	eb 13                	jmp    0x4b8942
  4b892f:	83 c1 bf             	add    ecx,0xffffffbf
  4b8932:	b8 b3 cf 21 35       	mov    eax,0x3521cfb3
  4b8937:	f7 e1                	mul    ecx
  4b8939:	2b ca                	sub    ecx,edx
  4b893b:	d1 e9                	shr    ecx,1
  4b893d:	03 ca                	add    ecx,edx
  4b893f:	c1 e9 05             	shr    ecx,0x5
  4b8942:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  4b8949:	00 
  4b894a:	85 c9                	test   ecx,ecx
  4b894c:	0f 84 ce 00 00 00    	je     0x4b8a20
  4b8952:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  4b8956:	83 c7 6f             	add    edi,0x6f
  4b8959:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4b895d:	bb 1d 00 00 00       	mov    ebx,0x1d
  4b8962:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8969:	75 27                	jne    0x4b8992
  4b896b:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8972:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b8979:	e8 12 8c 02 00       	call   0x4e1590
  4b897e:	68 80 cc bc 00       	push   0xbccc80
  4b8983:	e8 92 99 3d 00       	call   0x89231a
  4b8988:	83 c4 04             	add    esp,0x4
  4b898b:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8992:	0f b6 07             	movzx  eax,BYTE PTR [edi]
  4b8995:	83 f8 09             	cmp    eax,0x9
  4b8998:	77 1b                	ja     0x4b89b5
  4b899a:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  4b89a0:	03 05 04 43 f9 00    	add    eax,DWORD PTR ds:0xf94304
  4b89a6:	74 0d                	je     0x4b89b5
  4b89a8:	8d 57 d2             	lea    edx,[edi-0x2e]
  4b89ab:	8b f0                	mov    esi,eax
  4b89ad:	e8 9e b7 01 00       	call   0x4d4150
  4b89b2:	83 ce ff             	or     esi,0xffffffff
  4b89b5:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b89bc:	75 14                	jne    0x4b89d2
  4b89be:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  4b89c5:	68 10 cf bc 00       	push   0xbccf10
  4b89ca:	e8 4b 99 3d 00       	call   0x89231a
  4b89cf:	83 c4 04             	add    esp,0x4
  4b89d2:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b89d9:	0f b6 07             	movzx  eax,BYTE PTR [edi]
  4b89dc:	ba 26 00 00 00       	mov    edx,0x26
  4b89e1:	66 89 54 24 18       	mov    WORD PTR [esp+0x18],dx
  4b89e6:	88 44 24 1a          	mov    BYTE PTR [esp+0x1a],al
  4b89ea:	75 16                	jne    0x4b8a02
  4b89ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b89f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b89f4:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b89f7:	6a 03                	push   0x3
  4b89f9:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  4b89fd:	52                   	push   edx
  4b89fe:	6a 00                	push   0x0
  4b8a00:	ff d0                	call   eax
  4b8a02:	0f b6 0f             	movzx  ecx,BYTE PTR [edi]
  4b8a05:	49                   	dec    ecx
  4b8a06:	ba 01 00 00 00       	mov    edx,0x1
  4b8a0b:	66 d3 e2             	shl    dx,cl
  4b8a0e:	83 c7 35             	add    edi,0x35
  4b8a11:	66 09 54 24 14       	or     WORD PTR [esp+0x14],dx
  4b8a16:	ff 4c 24 10          	dec    DWORD PTR [esp+0x10]
  4b8a1a:	0f 85 42 ff ff ff    	jne    0x4b8962
  4b8a20:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8a27:	75 2b                	jne    0x4b8a54
  4b8a29:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8a30:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x1e
  4b8a37:	1e 00 00 00 
  4b8a3b:	e8 50 8b 02 00       	call   0x4e1590
  4b8a40:	68 80 cc bc 00       	push   0xbccc80
  4b8a45:	e8 d0 98 3d 00       	call   0x89231a
  4b8a4a:	83 c4 04             	add    esp,0x4
  4b8a4d:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8a54:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8a5b:	66 8b 44 24 14       	mov    ax,WORD PTR [esp+0x14]
  4b8a60:	66 a3 40 42 f9 00    	mov    ds:0xf94240,ax
  4b8a66:	bf 01 00 00 00       	mov    edi,0x1
  4b8a6b:	75 2a                	jne    0x4b8a97
  4b8a6d:	09 3d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,edi
  4b8a73:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x1f
  4b8a7a:	1f 00 00 00 
  4b8a7e:	e8 0d 8b 02 00       	call   0x4e1590
  4b8a83:	68 80 cc bc 00       	push   0xbccc80
  4b8a88:	e8 8d 98 3d 00       	call   0x89231a
  4b8a8d:	83 c4 04             	add    esp,0x4
  4b8a90:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8a97:	b9 e0 d9 f8 00       	mov    ecx,0xf8d9e0
  4b8a9c:	e8 0f d5 02 00       	call   0x4e5fb0
  4b8aa1:	f6 05      	test   BYTE PTR ds:0xfb1314,0x1
```


---

### A.5 `0x4D4150` 單筆 53B 角色來源→角色 record 映射

- `.text` VA `0x004D4150..0x004D419C`；raw `0x000D3550..0x000D359C`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4d4150:	57                   	push   edi
  4d4151:	8d 7e 0c             	lea    edi,[esi+0xc]
  4d4154:	c7 46 5c 01 00 00 00 	mov    DWORD PTR [esi+0x5c],0x1
  4d415b:	8b c2                	mov    eax,edx
  4d415d:	2b fa                	sub    edi,edx
  4d415f:	90                   	nop
  4d4160:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4d4163:	66 89 0c 07          	mov    WORD PTR [edi+eax*1],cx
  4d4167:	83 c0 02             	add    eax,0x2
  4d416a:	66 85 c9             	test   cx,cx
  4d416d:	75 f1                	jne    0x4d4160
  4d416f:	0f b6 42 2e          	movzx  eax,BYTE PTR [edx+0x2e]
  4d4173:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  4d4176:	0f b6 4a 2f          	movzx  ecx,BYTE PTR [edx+0x2f]
  4d417a:	89 8e d4 00 00 00    	mov    DWORD PTR [esi+0xd4],ecx
  4d4180:	0f b6 42 30          	movzx  eax,BYTE PTR [edx+0x30]
  4d4184:	89 86 dc 00 00 00    	mov    DWORD PTR [esi+0xdc],eax
  4d418a:	8b 4a 31             	mov    ecx,DWORD PTR [edx+0x31]
  4d418d:	89 4e 50             	mov    DWORD PTR [esi+0x50],ecx
  4d4190:	8b 52 2a             	mov    edx,DWORD PTR [edx+0x2a]
  4d4193:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  4d4196:	b8 01 00 00 00       	mov    eax,0x1
  4d419b:	5f                   	pop    edi
  4d419c:	c3                   	ret
```


---

### A.13 `0x4E5FB0` 可用清單之後 rank UI effects/limits

- `.text` VA `0x004E5FB0..0x004E613C`；raw `0x000E53B0..0x000E553C`（對 code section 有效）。此處是可重現的入口切片，不保證覆蓋完整函式。

```asm
  4e5fb0:	55                   	push   ebp
  4e5fb1:	8b ec                	mov    ebp,esp
  4e5fb3:	6a ff                	push   0xffffffff
  4e5fb5:	68 44 e3 91 00       	push   0x91e344
  4e5fba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4e5fc0:	50                   	push   eax
  4e5fc1:	83 ec 30             	sub    esp,0x30
  4e5fc4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4e5fc9:	33 c5                	xor    eax,ebp
  4e5fcb:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4e5fce:	53                   	push   ebx
  4e5fcf:	56                   	push   esi
  4e5fd0:	57                   	push   edi
  4e5fd1:	50                   	push   eax
  4e5fd2:	8d 45 f4             	lea    eax,[ebp-0xc]
  4e5fd5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4e5fdb:	8b f9                	mov    edi,ecx
  4e5fdd:	33 f6                	xor    esi,esi
  4e5fdf:	89 75 d0             	mov    DWORD PTR [ebp-0x30],esi
  4e5fe2:	8b 8f 24 69 00 00    	mov    ecx,DWORD PTR [edi+0x6924]
  4e5fe8:	89 7d c8             	mov    DWORD PTR [ebp-0x38],edi
  4e5feb:	e8 a0 e5 fe ff       	call   0x4d4590
  4e5ff0:	8b d8                	mov    ebx,eax
  4e5ff2:	89 5d cc             	mov    DWORD PTR [ebp-0x34],ebx
  4e5ff5:	3b de                	cmp    ebx,esi
  4e5ff7:	0f 84 24 01 00 00    	je     0x4e6121
  4e5ffd:	f6 05 a8 1c fc 00 01 	test   BYTE PTR ds:0xfc1ca8,0x1
  4e6004:	75 26                	jne    0x4e602c
  4e6006:	83 0d a8 1c fc 00 01 	or     DWORD PTR ds:0xfc1ca8,0x1
  4e600d:	68 a0 e5 bc 00       	push   0xbce5a0
  4e6012:	89 35 ac 1c fc 00    	mov    DWORD PTR ds:0xfc1cac,esi
  4e6018:	89 35 b0 1c fc 00    	mov    DWORD PTR ds:0xfc1cb0,esi
  4e601e:	89 35 b4 1c fc 00    	mov    DWORD PTR ds:0xfc1cb4,esi
  4e6024:	e8 f1 c2 3a 00       	call   0x89231a
  4e6029:	83 c4 04             	add    esp,0x4
  4e602c:	8b 35 ac 1c fc 00    	mov    esi,DWORD PTR ds:0xfc1cac
  4e6032:	8b 0d b0 1c fc 00    	mov    ecx,DWORD PTR ds:0xfc1cb0
  4e6038:	2b ce                	sub    ecx,esi
  4e603a:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  4e603f:	f7 e9                	imul   ecx
  4e6041:	c1 fa 03             	sar    edx,0x3
  4e6044:	8b c2                	mov    eax,edx
  4e6046:	c1 e8 1f             	shr    eax,0x1f
  4e6049:	03 c2                	add    eax,edx
  4e604b:	48                   	dec    eax
  4e604c:	8d 0c c0             	lea    ecx,[eax+eax*8]
  4e604f:	8d 4c 8e 04          	lea    ecx,[esi+ecx*4+0x4]
  4e6053:	39 19                	cmp    DWORD PTR [ecx],ebx
  4e6055:	76 06                	jbe    0x4e605d
  4e6057:	48                   	dec    eax
  4e6058:	83 e9 24             	sub    ecx,0x24
  4e605b:	eb f6                	jmp    0x4e6053
  4e605d:	8d 14 c0             	lea    edx,[eax+eax*8]
  4e6060:	0f b6 1c 96          	movzx  ebx,BYTE PTR [esi+edx*4]
  4e6064:	39 9f cc 68 00 00    	cmp    DWORD PTR [edi+0x68cc],ebx
  4e606a:	0f 84 a2 00 00 00    	je     0x4e6112
  4e6070:	e8 2b eb f1 ff       	call   0x404ba0
  4e6075:	83 b8 4c 5f 00 00 00 	cmp    DWORD PTR [eax+0x5f4c],0x0
  4e607c:	0f 84 90 00 00 00    	je     0x4e6112
  4e6082:	6a 6c                	push   0x6c
  4e6084:	e8 df b1 3a 00       	call   0x891268
  4e6089:	8b f0                	mov    esi,eax
  4e608b:	83 c4 04             	add    esp,0x4
  4e608e:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  4e6091:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4e6098:	85 f6                	test   esi,esi
  4e609a:	74 4b                	je     0x4e60e7
  4e609c:	e8 8f 6f fe ff       	call   0x4cd030
  4e60a1:	68 48 cf c0 00       	push   0xc0cf48
  4e60a6:	8d 7d d4             	lea    edi,[ebp-0x2c]
  4e60a9:	e8 92 94 f9 ff       	call   0x47f540
  4e60ae:	83 c4 04             	add    esp,0x4
  4e60b1:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4e60b5:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  4e60b9:	c7 45 d0 01 00 00 00 	mov    DWORD PTR [ebp-0x30],0x1
  4e60c0:	72 04                	jb     0x4e60c6
  4e60c2:	8b 10                	mov    edx,DWORD PTR [eax]
  4e60c4:	eb 02                	jmp    0x4e60c8
  4e60c6:	8b d0                	mov    edx,eax
  4e60c8:	6a 00                	push   0x0
  4e60ca:	6a 19                	push   0x19
  4e60cc:	6a 64                	push   0x64
  4e60ce:	56                   	push   esi
  4e60cf:	b9 19 00 00 00       	mov    ecx,0x19
  4e60d4:	e8 b7 dd 06 00       	call   0x553e90
  4e60d9:	8b 7d c8             	mov    edi,DWORD PTR [ebp-0x38]
  4e60dc:	c7 06 70 d1 c0 00    	mov    DWORD PTR [esi],0xc0d170
  4e60e2:	89 5e 68             	mov    DWORD PTR [esi+0x68],ebx
  4e60e5:	eb 02                	jmp    0x4e60e9
  4e60e7:	33 f6                	xor    esi,esi
  4e60e9:	6a 00                	push   0x0
  4e60eb:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4e60f2:	e8 d9 cd f3 ff       	call   0x422ed0
  4e60f7:	50                   	push   eax
  4e60f8:	b8 02 00 00 00       	mov    eax,0x2
  4e60fd:	8b ce                	mov    ecx,esi
  4e60ff:	e8 dc d5 06 00       	call   0x5536e0
  4e6104:	f6 45 d0 01          	test   BYTE PTR [ebp-0x30],0x1
  4e6108:	74 08                	je     0x4e6112
  4e610a:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4e610d:	e8 3e cb f1 ff       	call   0x402c50
  4e6112:	8b 45 cc             	mov    eax,DWORD PTR [ebp-0x34]
  4e6115:	89 87 d0 68 00 00    	mov    DWORD PTR [edi+0x68d0],eax
  4e611b:	89 9f cc 68 00 00    	mov    DWORD PTR [edi+0x68cc],ebx
  4e6121:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4e6124:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4e612b:	59                   	pop    ecx
  4e612c:	5f                   	pop    edi
  4e612d:	5e                   	pop    esi
  4e612e:	5b                   	pop    ebx
  4e612f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4e6132:	33 cd                	xor    ecx,ebp
  4e6134:	e8 c8 ae 3a 00       	call   0x891001
  4e6139:	8b e5                	mov    esp,ebp
  4e613b:	5d                   	pop    ebp
  4e613c:	c3                   	ret
```


---

### 1.1 F42EF consumer — 0x5A69E0

```asm
5a69e0: 55                    push ebp
5a69e1: 8b ec                 mov ebp,esp
5a69e5: 8b 75 08              mov esi,[ebp+0x8]
5a69e8: 81 7e 10 ef 42 0f 00  cmp DWORD PTR [esi+0x10],0xf42ef
5a69f1: 75 4b                 jne 0x5a6a3e
5a69f3: 8b 06                 mov eax,[esi]
5a69f5: 8b 50 04              mov edx,[eax+0x4]
5a69f8: 8b ce                 mov ecx,esi
5a69fa: ff d2                 call edx
5a69fc: 3d b9 05 01 00        cmp eax,0x105b9
5a6a01: 75 04                 jne 0x5a6a07
5a6a1d: 8b 40 14              mov eax,[eax+0x14]
5a6a21: 8b bb 3c 01 00 00     mov edi,[ebx+0x13c]
5a6a27: 50                    push eax
5a6a28: e8 23 e7 0b 00        call 0x665150
5a6a2d: 8b 8b 3c 01 00 00     mov ecx,[ebx+0x13c]
5a6a33: 8b 11                 mov edx,[ecx]
5a6a35: 8b 82 d0 00 00 00     mov eax,[edx+0xd0]
5a6a3b: ff d0                 call eax
```

`0x5A6A07` 在虛擬方法回傳值非 `0x105B9` 時經由 `ds:[0xBD2580]` 呼叫診斷路徑，接著 EAX 設零；立即在 `0x5A6A1D` 解參考 `EAX+0x14`。**沒有動態證據**判斷診斷函式是否必定不返回，故不得把此當成可正常恢復的錯誤路徑。成功時事件 `+0x14` 傳給 `0x665150`，隨後 `receiver+0x13C` dialog 的 virtual `+0xD0` 被呼叫。這構成具體 F42EF UI 消費入口，但不等於證明 dialog 已訂閱此事件或原始 wire opcode。


---

### 1.4 F42EF 下游 — 0x665150 角色記錄 gate

```asm
665186: 8b 15 f4 1d fe 00     mov edx,ds:[0xfe1df4]
66518c: 8b 42 0c              mov eax,[edx+0xc]
66518f: 2b 42 08              sub eax,[edx+0x8]
665194: c1 f8 03              sar eax,0x3
66519b: 8b 5a 08              mov ebx,[edx+0x8]
6651a0: 0f b6 32              movzx esi,BYTE PTR [edx]
6651a3: 3b 75 08              cmp esi,[ebp+0x8]
6651a9: 83 c2 08              add edx,0x8
6651e4: 8b 55 08              mov edx,[ebp+0x8]
6651e7: 83 fa 09              cmp edx,0x9
6651ec: 8b 0d 04 43 f9 00     mov ecx,ds:[0xf94304]
6651f4: 69 c0 10 02 00 00     imul eax,eax,0x210
6651fc: 8b 41 5c              mov eax,[ecx+0x5c]
66520e: 85 db                 test ebx,ebx
665210: 0f 84 9e 01 00 00     je 0x6653b4
665216: 85 c0                 test eax,eax
665218: 0f 84 96 01 00 00     je 0x6653b4
66521e: 89 97 10 01 00 00     mov [edi+0x110],edx
66522b: e8 70 f9 d9 ff        call 0x404ba0
```

此段是重大新進展：F42EF 不只存在 producer/consumer，還將 `event+0x14` 值傳入 `0x665150`，與先前由 command2 清單寫入的 `F94304+ID*0x210`／`record+0x5C` **可用條件**接合。`0x665150` 另外要求 `FE1DF4` 的 8-byte stride 結構能找到相同低位元組 ID，及後續 `+5C` 有效，兩者皆滿足時寫 `dialog+0x110` 並進入更深操作。這是原生 Client UI 狀態選擇 gate 的重要證據，**不是**官方 Server 已批准角色登入的證據。尚未核對 `0x665150` 整函式結尾的全部發包與 vtable，也未證實 full UI lifecycle。


---

## 1. 第 1 輪：665150 成功與失敗 CFG（原始 x86）

函式體 `0x665150..0x6653D9`，返 `ret 4`，參數 `[ebp+8]` 為候選 ID；`EDI` 在呼叫前由 caller 設為 UI dialog 物件。直接 caller `0x5A6A28` / `0x59A520` 均已獨立反組譯核對。

```asm
665186  mov edx, [0xfe1df4]
66518c  mov eax, [edx+0xc]
66518f  sub eax, [edx+0x8]
665194  sar eax, 3
66519b  mov ebx, [edx+0x8]
6651a0  movzx esi, byte ptr [edx]
6651a3  cmp esi, [ebp+8]
6651a6  je 665207
6651a9  add edx, 8
6651b2  test byte ptr [0xf94390],1
6651bb  or dword ptr [0xf94390],1
6651ca  call 0x4e1590
6651e4  mov edx,[ebp+8]
6651e7  cmp edx,9
6651ea  ja 66520c
6651ec  mov ecx,[0xf94304]
6651f4  imul eax,eax,0x210
6651fa  add ecx,eax
6651fc  mov eax,[ecx+0x5c]
6651ff  neg eax
665201  sbb eax,eax
665203  and eax,ecx
66520e  test ebx,ebx
665210  je 6653b4
665216  test eax,eax
665218  je 6653b4
66521e  mov [edi+0x110],edx
```

**確認**：需候選 ID 在 `FE1DF4` 的 8-byte stride 表中匹配，且 `ID<=9` 並能從 `F94304+ID*0x210` 找到 `+0x5C!=0`；否則跳過 UI 資料填入，走 `0x6653B4`。特別注意 `0x6651B2` 的 lazy initialization (`F94390` bit0、call 4E1590) 使「空表」與「未初始化」不可直接混同。若找到列表 ID，但 record 尚未可用，函式末端仍回 1；返回值代表 list 命中，而非完整 UI 資料填入成功。

### 1.1 通過 gate 之後：UI 多欄位填入

```asm
66521e  mov [edi+0x110],edx
665224  mov edx,[ebx+4]
665227  mov [esp+0x10],edx
66522b  call 0x404ba0
665230  mov edx,[edi+0xf4]
665236  mov eax,[eax+0x6864]
66523c  movzx ecx,byte ptr [ebx+1]
66524c  call 0x7597b0
665251  mov cl,byte ptr [ebx+1]
665258  call 0x662800
665265  mov esi,[edi+0xf8]
665272  call 0x757800
665293  mov cx,word ptr [ebx+2]
66529b  call 0x665560
6652a8  mov esi,[edi+0xfc]
6652b5  call 0x757800
6652d6  mov ecx,[esp+0x10]
6652de  call 0x412df0
6652f7  mov esi,[edi+0x100]
665303  call 0x757710
665324  mov ecx,[esp+0x14]
66532c  call 0x412df0
665345  mov esi,[edi+0x104]
665351  call 0x757710
665372  mov ecx,[edi+0x108]
66537a  mov eax,[eax+0x90]
66538b  cmp [esp+0x10],edx
665397  setle dl
66539d  push edx
6653a6  call eax
6653a8  mov edx,[edi]
6653aa  mov eax,[edx+0xc8]
6653b2  call eax
6653b4  xor eax,eax
6653b6  test ebx,ebx
6653b8  setne al
6653d7  ret 4
```

**新增有界結論**：`0x665150` 是選角 detail dialog 的**本地多控件資料填入函式**，不是已驗證的選角 C→S producer。來自 `FE1DF4` 表項的 `+1 byte`、`+2 word`、`+4 dword` 分別進 UI 資料顯示轉換；`dialog+0xF4`、`+0xF8`、`+0xFC`、`+0x100`、`+0x104`、`+0x108` 是控件/相關物件指標的使用位置，不得未查 T06 資源便直接命名具體 UI 控件。最後 `dialog virtual+0xC8` 被呼叫。`0x665372..0x6653A6` 使用 `[esp+0x10] <= [esp+0x14]` 形成布林值傳給 `dialog+0x108` 指向物件的 `virtual+0x90`；該比較的業務含義未知。

### 1.2 直接 caller 的重要差異

```asm
59a515 mov eax,[eax+0x14]
59a519 mov edi,[ebx+0x1d4]
59a520 call 665150
59a526 test eax,eax
59a528 je 59a53a
59a52a mov ecx,[ebx+0x1d4]
59a532 mov eax,[edx+0xd0]
59a538 call eax

5a6a1d mov eax,[eax+0x14]
5a6a21 mov edi,[ebx+0x13c]
5a6a28 call 665150
5a6a2d mov ecx,[ebx+0x13c]
5a6a35 mov eax,[edx+0xd0]
5a6a3b call eax
```

**新差異**：`0x59A520` 的 caller **以 665150 非零 return gate** 控制後續 UI virtual +D0；`0x5A6A28` 的 caller **無條件**呼叫 dialog virtual +D0（在 F42EF type check 通過後）。因此即使未找到角色 ID，兩條 GUI 更新路徑在通知觸發條件上不同。該差異不等於 Server 拒絕或成功；需要 GUI listener 與 T06 的控件資料補證。

### 1.3 `0x665560` 不是網路建包

```asm
665570 push 0xa
665572 push 0x7
665577 movzx ecx,cx
66557c mov dword ptr [ebp-0x18],0
665583 call 0x89243a
66558d mov dword ptr [esi+0x14],7
665594 mov dword ptr [esi+0x10],0
66559e mov word ptr [esi],dx
6655aa test cx,cx
6655b3 push eax
6655ba call 0x402160
6655ce ret
```

此 helper 將 `CX` 的無符號整數經 formatting helper `0x89243A` 轉成文字並寫入 `ESI` 所指 string-like 物件；它在 `0x665293` 取 `word [ebx+2]` 後被呼叫，因此只是 UI 字串格式化證據。不能把 `0x7/0xA` 當作 packet opcode 或資料長度。


**E70 結尾**：有界研究已交付、正向 GUI entry 未證，待 T01/S00 決定是否接受 exact-blocker submission；不得宣稱原版 Client 已進入建角畫面。
