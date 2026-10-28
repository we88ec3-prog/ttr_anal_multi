# T16-87 — KR 原生 action factory 上游解析、27 種索引映射與 .rdata 地址勘誤

> T16 Quest & Story Progression 相關線索；研究者 chatgpt-web roy；2026-10-28 (Asia/Taipei)。原始 Client 唯讀、未執行。接續 T16-86；依專案三輪規範。

## 0. 來源與重大勘誤

- `/mnt/data/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `/mnt/data/Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE `.text` VMA `0x00401000` / raw `0x00000400`，換算 **VA−`0x00400C00`**。
- PE `.rdata` VMA `0x00BD2000` / raw `0x007D0600`，換算 **VA−`0x00401A00`**。**此前 T16-69～86 交接背景裡記載的 rdata `0x00402A00` 是錯誤映射，不可再引用；此勘誤僅針對 rdata 轉換，不推翻其它獨立原生驗證。**
- 由正確 rdata mapping 對原生字串指標解碼：`0x00C069A8`→ASCII `action`；`0x00C0EAD8`→ASCII `ACTION`。這個證據表示現階段函式鏈處理的是**通用 action XML/物件**；其是否屬 QuestInfo、QuestTalk 業務資料仍需要其它 Client caller/resource 證明。不能因 T16-86 的 Quest 欄位出現在同 BIN 而直接關聯兩條流程。
- 使用 `objdump -D -M intel` 和 Python 直接讀取原始 bytes、
  `struct.unpack_from('<10I', ...)` 交叉核對；不包含任何假造封包錄製或 Server 行為。

## 1. 第 1 輪 T16-87 — 唯一直接 caller 與通用 action 字串

從 `.text` 全段掃描 E8 rel32（僅視作**候選**，objdump 覆核指令邊界）：`0x00523260` 的 direct call 僅在 `0x00522D20`；`0x00523230` 的相同方法類 helper 候選呼叫九處。`0x005233A8` 是**跳表目標**，故找不到 E8 call 是正常的，不能據此宣稱無人使用。

`0x00522CB2` 先從樹 node 的 `+0x10` 取 payload，走 `0x72E360` + `0x72E3C0` 迭代 `ACTION` 節點（語義由字串支持，具體 XML 結構層級 unknown）。

**關鍵原生反組譯：**

```asm
/mnt/data/Tartaros.bin:     file format pei-i386
00522cf0 <.text+0x121cf0>:
  522cf0:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  522cf4:	8d 46 14             	lea    eax,[esi+0x14]
  522cf7:	72 02                	jb     0x522cfb
  522cf9:	8b 00                	mov    eax,DWORD PTR [eax]
  522cfb:	68 a8 69 c0 00       	push   0xc069a8
  522d00:	50                   	push   eax
  522d01:	e8 ab 0f 37 00       	call   0x893cb1
  522d06:	83 c4 08             	add    esp,0x8
  522d09:	85 c0                	test   eax,eax
  522d0b:	74 1c                	je     0x522d29
  522d0d:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  522d10:	3b f7                	cmp    esi,edi
  522d12:	75 dc                	jne    0x522cf0
  522d14:	33 c0                	xor    eax,eax
  522d16:	8d 48 ff             	lea    ecx,[eax-0x1]
  522d19:	83 f9 1a             	cmp    ecx,0x1a
  522d1c:	77 29                	ja     0x522d47
  522d1e:	33 c0                	xor    eax,eax
  522d20:	e8 3b 05 00 00       	call   0x523260
  522d25:	8b f8                	mov    edi,eax
  522d27:	eb 20                	jmp    0x522d49
  522d29:	85 f6                	test   esi,esi
  522d2b:	74 e7                	je     0x522d14
  522d2d:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  522d31:	8d 46 30             	lea    eax,[esi+0x30]
  522d34:	72 02                	jb     0x522d38
  522d36:	8b 00                	mov    eax,DWORD PTR [eax]
  522d38:	85 c0                	test   eax,eax
  522d3a:	74 d8                	je     0x522d14
  522d3c:	50                   	push   eax
  522d3d:	e8 72 ea 36 00       	call   0x8917b4
  522d42:	83 c4 04             	add    esp,0x4
  522d45:	eb cf                	jmp    0x522d16
  522d47:	33 ff                	xor    edi,edi
  522d49:	89 bd 70 ff ff ff    	mov    DWORD PTR [ebp-0x90],edi
  522d4f:	85 ff                	test   edi,edi
  522d51:	0f 84 87 00 00 00    	je     0x522dde
  522d57:	57                   	push   edi
  522d58:	8b c3                	mov    eax,ebx
  522d5a:	e8 91 d8 ff ff       	call   0x5205f0
  522d5f:	8b b5 64 ff ff ff    	mov    esi,DWORD PTR [ebp-0x9c]
  522d65:	8b 86        	mov    eax,DWORD PTR [esi+0x14c]
```

細節：

1. 指令 `0x522CFB: push 0xC069A8` 之字串為 `action`，接著 `0x893CB1` 讀屬性/對比（該 helper 全語義待查），命中後 `0x522D2D` 從 node `+0x30` 的 string 緩衝取字串。
2. `0x522D3D: call 0x8917B4` 產生 EAX 整數（有力證據為數字字串轉換，但尚未逐指令確認 CRT 名稱）；`0x522D16: lea ecx,[eax-1]` 把整數轉零基索引。
3. `0x522D19: cmp ecx,0x1A` 和 `0x522D1C: ja 0x522D47`：無號範圍 `0..26` 才走 `0x522D20: call 0x523260`。若缺少或找不到有效屬性，`0x522D14 xor eax,eax` → `ecx=FFFFFFFF` → range fail、`edi=0`，**不會**直接依 `0x523260` 中的 byte table 失控下標。
4. `0x522D57: push edi` + `0x522D5A: call 0x5205F0`，把 factory result 傳入後續方法，是否會改 Quest cache 未證。

## 2. 第 1 輪延伸：二段跳表的 27 個 XML action code → 10 個建構器

原生 

```asm
523260: movzx edx,BYTE PTR [ecx+0x52342c]
523267: jmp DWORD PTR [edx*4+0x523404]
```

查表索引 `ecx` 為**解析的原始數字減一**，有效索引 0..26；第一個 byte map 位於 `.text` VA `0x52342C`，第二個 dword target table 位於同 `.text` VA `0x523404`（都不是 rdata）。

#### 2.1 10 項 native jump target

| map value | jump target | raw offset |
|---:|---:|---:|
| 0 | `0x0052326E` | `0x0012266E` |
| 1 | `0x005232A1` | `0x001226A1` |
| 2 | `0x005233A8` | `0x001227A8` |
| 3 | `0x00523323` | `0x00122723` |
| 4 | `0x005232D0` | `0x001226D0` |
| 5 | `0x005232F9` | `0x001226F9` |
| 6 | `0x00523387` | `0x00122787` |
| 7 | `0x00523352` | `0x00122752` |
| 8 | `0x005233CD` | `0x001227CD` |
| 9 | `0x00523403` | `0x00122803` |

#### 2.2 完整 27 項映射（原始「文字數值」與內部 factory value 不可混同）

| 原始數值 | zero-based ECX | byte map | 最終 jump VA |
|---:|---:|---:|---:|
| 1 | `0` | `0` | `0x0052326E` |
| 2 | `1` | `1` | `0x005232A1` |
| 3 | `2` | `2` | `0x005233A8` |
| 4 | `3` | `3` | `0x00523323` |
| 5 | `4` | `2` | `0x005233A8` |
| 6 | `5` | `4` | `0x005232D0` |
| 7 | `6` | `5` | `0x005232F9` |
| 8 | `7` | `2` | `0x005233A8` |
| 9 | `8` | `6` | `0x00523387` |
| 10 | `9` | `6` | `0x00523387` |
| 11 | `10` | `2` | `0x005233A8` |
| 12 | `11` | `2` | `0x005233A8` |
| 13 | `12` | `2` | `0x005233A8` |
| 14 | `13` | `2` | `0x005233A8` |
| 15 | `14` | `6` | `0x00523387` |
| 16 | `15` | `6` | `0x00523387` |
| 17 | `16` | `6` | `0x00523387` |
| 18 | `17` | `7` | `0x00523352` |
| 19 | `18` | `6` | `0x00523387` |
| 20 | `19` | `6` | `0x00523387` |
| 21 | `20` | `6` | `0x00523387` |
| 22 | `21` | `2` | `0x005233A8` |
| 23 | `22` | `9` | `0x00523403` |
| 24 | `23` | `8` | `0x005233CD` |
| 25 | `24` | `6` | `0x00523387` |
| 26 | `25` | `6` | `0x00523387` |
| 27 | `26` | `6` | `0x00523387` |


原始 27 bytes：`00 01 02 03 02 04 05 02 06 06 02 02 02 02 06 06 06 07 06 06 06 02 09 08 06 06 06`。原始 10 dwords little-endian：`0052326E 005232A1 005233A8 00523323 005232D0 005232F9 00523387 00523352 005233CD 00523403`。range gate 所以只用到 27 bytes；之後到 `0x52344F` 的 `CC` 是 padding，不能算有效 value。

**特別注意：** 實體 factory 內寫 `object+4 = 1..9` 等 type 值，但相同內部建構分支會被多個外部 action 數字使用，例如 `byte map=2` 對應 `0x5233A8`，有多個來源代碼。**這證明 27 個文字值與少數物件型別之間不是一對一。它們不是 Quest ID 或 wire opcode。**

## 3. 第 2 輪 T16-87-2 — factory 成功與下游容器

下方是 factory 及前段 caller 的真實資料轉移（非執行時觀察）：

```asm
/mnt/data/Tartaros.bin:     file format pei-i386
00522d49 <.text+0x121d49>:
  522d49:	89 bd 70 ff ff ff    	mov    DWORD PTR [ebp-0x90],edi
  522d4f:	85 ff                	test   edi,edi
  522d51:	0f 84 87 00 00 00    	je     0x522dde
  522d57:	57                   	push   edi
  522d58:	8b c3                	mov    eax,ebx
  522d5a:	e8 91 d8 ff ff       	call   0x5205f0
  522d5f:	8b b5 64 ff ff ff    	mov    esi,DWORD PTR [ebp-0x9c]
  522d65:	8b 86 4c 01 00 00    	mov    eax,DWORD PTR [esi+0x14c]
  522d6b:	8d 8d 70 ff ff ff    	lea    ecx,[ebp-0x90]
  522d71:	3b c8                	cmp    ecx,eax
  522d73:	73 43                	jae    0x522db8
  522d75:	8b 8e 48 01 00 00    	mov    ecx,DWORD PTR [esi+0x148]
  522d7b:	8d 95 70 ff ff ff    	lea    edx,[ebp-0x90]
  522d81:	3b ca                	cmp    ecx,edx
  522d83:	77 33                	ja     0x522db8
  522d85:	8b fa                	mov    edi,edx
  522d87:	2b f9                	sub    edi,ecx
  522d89:	c1 ff 02             	sar    edi,0x2
  522d8c:	3b 86 50 01 00 00    	cmp    eax,DWORD PTR [esi+0x150]
  522d92:	75 0b                	jne    0x522d9f
  522d94:	8d 86 48 01 00 00    	lea    eax,[esi+0x148]
  522d9a:	e8 11 bd fb ff       	call   0x4deab0
  522d9f:	8b 86 48 01 00 00    	mov    eax,DWORD PTR [esi+0x148]
  522da5:	8d 0c b8             	lea    ecx,[eax+edi*4]
  522da8:	8b 86 4c 01 00 00    	mov    eax,DWORD PTR [esi+0x14c]
  522dae:	85 c0                	test   eax,eax
  522db0:	74 25                	je     0x522dd7
  522db2:	8b 09                	mov    ecx,DWORD PTR [ecx]
  522db4:	89 08                	mov    DWORD PTR [eax],ecx
  522db6:	eb 1f                	jmp    0x522dd7
  522db8:	3b 86 50 01 00 00    	cmp    eax,DWORD PTR [esi+0x150]
  522dbe:	75 0b                	jne    0x522dcb
  522dc0:	8d 86 48 01 00 00    	lea    eax,[esi+0x148]
  522dc6:	e8 e5 bc fb ff       	call   0x4deab0
  522dcb:	8b 86 4c 01 00 00    	mov    eax,DWORD PTR [esi+0x14c]
  522dd1:	85 c0                	test   eax,eax
  522dd3:	74 02                	je     0x522dd7
  522dd5:	89 38                	mov    DWORD PTR [eax],edi
  522dd7:	83 86 4c 01 00 00 04 	add    DWORD PTR [esi+0x14c],0x4
  522dde:	bf d8 ea c0        	mov    edi,0xc0ead8
```

- `0x522D4F` 若 `edi=0` 則跳過 `0x5205F0` 與容器填入；若非零，呼叫 `0x5205F0`，然後讀 `esi+0x148/+0x14C/+0x150`，這是一組**三指標類動態陣列邊界**，在填入前檢查目前位置與 capacity；不足時 `0x4DEAB0` 擴展。
- `0x522DD5 mov [eax],edi`、`0x522DD7 add [esi+0x14C],4`：在部分分支向動態陣列寫入 factory 回傳 object pointer 並推進 end 4 bytes。**`0x522DB4 mov [eax],ecx` 在另一分支寫入的來源不同，必須保留分支條件，不可將兩分支都抽象成簡單 push_back。**
- `0x5205F0` 的一手參數（`eax=ebx`, `push edi`）及 native 機器碼：

```asm
/mnt/data/Tartaros.bin:     file format pei-i386
005205f0 <.text+0x11f5f0>:
  5205f0:	55                   	push   ebp
  5205f1:	8b ec                	mov    ebp,esp
  5205f3:	53                   	push   ebx
  5205f4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5205f7:	56                   	push   esi
  5205f8:	57                   	push   edi
  5205f9:	8b f0                	mov    esi,eax
  5205fb:	8d 7e 44             	lea    edi,[esi+0x44]
  5205fe:	68 a8 69 c0 00       	push   0xc069a8
  520603:	e8 98 fa 20 00       	call   0x7300a0
  520608:	85 c0                	test   eax,eax
  52060a:	74 1a                	je     0x520626
  52060c:	83 c0 30             	add    eax,0x30
  52060f:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  520613:	72 02                	jb     0x520617
  520615:	8b 00                	mov    eax,DWORD PTR [eax]
  520617:	85 c0                	test   eax,eax
  520619:	74 0b                	je     0x520626
  52061b:	50                   	push   eax
  52061c:	e8 93 11 37 00       	call   0x8917b4
  520621:	83 c4 04             	add    esp,0x4
  520624:	eb 02                	jmp    0x520628
  520626:	33 c0                	xor    eax,eax
  520628:	68 30 e8 c0 00       	push   0xc0e830
  52062d:	66 89 43 08          	mov    WORD PTR [ebx+0x8],ax
  520631:	e8 6a fa 20 00       	call   0x7300a0
  520636:	85 c0                	test   eax,eax
  520638:	74 1a                	je     0x520654
  52063a:	83 c0 30             	add    eax,0x30
  52063d:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  520641:	72 02                	jb     0x520645
  520643:	8b 00                	mov    eax,DWORD PTR [eax]
  520645:	85 c0                	test   eax,eax
  520647:	74 0b                	je     0x520654
  520649:	50                   	push   eax
  52064a:	e8 65 11 37 00       	call   0x8917b4
  52064f:	83 c4 04             	add    esp,0x4
  520652:	eb 02                	jmp    0x520656
  520654:	33 c0                	xor    eax,eax
  520656:	66 89 43 0a          	mov    WORD PTR [ebx+0xa],ax
  52065a:	8b 76 18             	mov    esi,DWORD PTR [esi+0x18]
  52065d:	85 f6                	test   esi,esi
  52065f:	74 14                	je     0x520675
  520661:	8b 06                	mov    eax,DWORD PTR [esi]
  520663:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  520666:	8b ce                	mov    ecx,esi
  520668:	ff d2                	call   edx
  52066a:	85 c0                	test   eax,eax
  52066c:	75 1a                	jne    0x520688
  52066e:	8b               	mov    esi,DWORD PTR [esi+0x40]
```

`0x5205F0` 在字串鍵 `action` 下取得值、經 `0x8917B4` 數字轉換後，將低 16 bits 寫入**新物件** `+0x8`；再查第二鍵 `0xC0E830`（此鍵需獨立原生資料解碼）寫 `+0xA`，並可能以 virtual `+0x18` 驗證下一層狀態。這是**XML 物件初始化／屬性填充**的具體下游，不是傳輸層封包打包。
- 由 `0x522D20` 新建物件 → `0x5205F0` 属性初始化 → `esi+0x148/+0x14C/+0x150` 陣列儲存，建立有上下游的新 **action XML instance materialization chain**，足以區分前段錯誤地把 `0x523260` 單獨稱作「QuestInfo factory」的風險。

## 4. 第 2 輪門檻與第 3 輪

此段第二輪已確認：「文字 \"action\" → 範圍檢查 → 27-to-10 二級 jump table → 原生物件配置 → XML 屬性初始化 → 指標陣列寫入」，是一條具體且可驗證的功能鏈，**符合重大新進展門檻**。所以 `T16-87-3` **未啟動**，並非跳過必須的第三輪。此發現更正 T16-86 可能從 Quest 字串附近導出的過度關聯，後續應先確認此 action 框架與任務資料 loader 的實際 caller，再決定是否屬於 T16，不能預先歸入 Quest handler。

## 5. 玩家互動／Server 相容矩陣

| 情境 | Client gate | C→S opcode/len/fields | S→C handler/len | Client 狀態／UI | Server 待開發 |
|---|---|---|---|---|---|
| 啟動/載入 action XML | action 值 1..27 才有 factory object（已證 static branch） | unknown；無此路徑的送包證據 | unknown | 物件 `+0x8/+0xA` 欄位，動態陣列 append（已證）；與 Quest 業務是否關聯 unknown | 沒有足夠 wire 規格可實作 |
| NPC 點擊接受任務 | 原生 click callback unknown | unknown | unknown | Quest cache writer unknown | 待確認協定 |
| Quest 完成、下一任務開放 | unknown | unknown | unknown | unknown | 原版 Server 判定不可由 XML factory 推論 |
| Tutorial RequestStartScenario | `[FBA798]==0`（前段 T16-65~68） | 本地 buffer `40 00 xx xx`；正式 wire opcode 未證 | unknown | unknown | 需實測或進一步 native framing 對照 |

## 6. 後續 T16-88

優先從已驗證 XML action object 的 caller/consumer 接到 QuestInfo／QuestTalk 的**具體**原生 loader（需要相同實例或實際參數資料流）；若資料域不同，停止深追通用框架，改由 NPC accept UI callback 和 Quest cache writer 並以 T02 inbound business dispatcher 逆追。不可套用誤寫的 rdata 位移；所有先前標記為 Quest factory 的型別解釋應重新分級，而非直接改 Server protocol。

## 7. 方法與限制

全程 static BIN-first；E8 rel32 純位元組候選僅在 objdump 證實位置後認作 call，jump table 使用原始 `.text` 索引和 dword 解析；原始 Server、網路 trace、QuestInfo.xml / QuestTalk.xml 檔案仍無從核對；只提交 T16 個人筆記、不得更動其它 Task 或上傳原始執行檔。