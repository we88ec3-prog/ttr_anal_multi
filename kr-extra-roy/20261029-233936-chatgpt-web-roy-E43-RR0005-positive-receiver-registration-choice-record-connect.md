# E43 — RR-0005 / KR T02：runtime callback 非零 writer、選服 record→Connect、first wire 證據邊界（目標導向 10 子段）

**研究者**：chatgpt-web roy；**本地記錄時間**：2026-10-29T23:39:36+08:00 (Asia/Taipei)。**正式段號**：E43；E43.1–E43.10 全屬同一正式段號，**不是**十個連續正式段號。**本次停止：B — 第十子段研究完畢，目標未完全閉合**；從 E42 的 B 停止接續。即使 E43.1 找到重大新 writer，也按使用者當次實驗規則繼續至第十子段。

**唯一研究目標**：把原本條件式的 `FC10D0 pop → Client callback` 精確註冊生命週期接到實際客戶端主循環，並從選服資料的原生查找一路到 `4957C0` 的 key0/key2 Connect、首筆應用送出／收到及特定 native command handler，最終以原生端到端、可供相容 Server 使用的選服後收發時序為完成門檻。這同時檢驗 E42 遺留的 `manager+4` 正向 writer、`F94294` gate、兩個記錄 resolver、首次 wire 及失敗分支；**不把局部閉合冒充完整登入遊戲流程**。

**版本/方法**：僅讀取本地原件 `Tartaros.bin` (12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`)，PE32 machine 0x14c、四 sections。`.text` VA `0x401000` raw `0x400` (raw = VA − 0x400C00)；`.rdata` VA `0xBD2000` raw `0x7D0600` (raw = VA − 0x401A00)；`.data` VA `0xD61000` raw `0x95E800`。下列 Assembly 直接由原始 BIN 在實際地址重新解碼，既有 E40–E42 用來指向函式/校正舊結論；非執行、非 pcap、非官方 Server 驗證。`objdump -b binary` 的顯示 section 名稱不能代替真正 PE section。

**GitHub 基準/授權**：同一對話沿用首次核對的 `main=43c51f579cada3aa6257eb8467f65af281c3585b`、`extra/roy1=34d1a55b21df78ac1c025872e641fe23dfe52645`，遵循當時 `AGENTS.md` 只在新對話首次開工讀完整 Task/RR；**E43 沒再抓最新 GitHub main，不聲稱當下最新**。最後一次已讀 RR-0005 為 `PENDING / QUEUED`、claim=null、submission=null。使用者本次沒有要求 Commit/Push，**未認領、未 Commit、未 Push、未修改遠端 RR/Task/T01/S00**。

**分級**：`N` = 此段可從 BIN 驗證的指令/控制流程；`C` = 可在明列實際動態前提下串接；`H` = 有跡可循的假說；`U` = 未證實（不得對 Server 產生強制協定值）。本原稿不是 T01 FULL-PASS，也不是 RR ACCEPTED／規格 STABLE／可玩驗收。

## 摘要：E43 真正新增的兩個整鏈關鍵

1. **E42 正向 writer 缺口已被縮小而非完全消失。** `0x6E65A0` 會在原生流程中把一個來源指標保存於 `[ebp−0xFC]`，並在 `0x6E6871` 真正寫到 `[FBA7CC]+4`；其直接呼叫者為 `0x6E5530`，上游 `0x6E4F90` 把傳入第二個參數保存為 `[ebp−0x208]`。**這是明確的非零候選正向 writer**（外部傳入 ECX 非零時經 AddRef + 儲存）；但 `0x6E4F90` 的所有 caller 尚無逐一證明該參數必為 `C+8`，也有帶零或局部物件的路徑，不可直接升格為「此欄位永遠是 Client+8」。
2. **E42 選服判斷有真正的結構化解釋。** `0x5078C0` 在兩重以 `0x60` 為 stride 的資料查找中返回匹配記錄的 **DWORD `[record+4]`**，`0x507750` 返回匹配 **`record+0xC` 的地址**。`0x66C090` 把前者存 EBX 當 gate，後者存 ESI，兩個 `push ESI → call 0x4957C0` 會把**來自選服資料記錄的地址**交給 key0/key2 Connect。這不是「EBX/ESI 都是函式結果碼」；E42 相關措辭在本段修正為資料欄位／資料指標。無 wire 來源和 record 實際字元編碼，不能把它稱為原版 Server 實際下發的端點 authority。

**目前條件式收包 path**：`[FBA7CC]+4` 非零且等於實際 `Client C+8` 時，`6DFA50→vptr+0x30 (490FE0)→804740→80486D→4930E0→48AAD0→494360→4FDA30` 才有機會抵達已註冊 handler；除了 writer 的存在，還必須逐一成立 receiver identity、lane、table override、解包完整性。**first wire／first S2C 仍為 U**。

## E43.1 — 第一手找到 `[FBA7CC]+4` 的正向 writer（重大新發現，不因此提前停止）

**研究問題**：E42 只發現 `0x6E9F9C` 的清零；對 manager 的 `+4` 是否真有非零 pointer store，具體 writer、鎖及來源為何？

**N — 指令級結論**：在 `6E6821` 以 lazy manager `[FBA7CC]` 取得/必要時配置 `0x1380` 物件；`6E6849` 之後以 `EDI=manager`；`6E6850` 讀 stack `[ebp−0xFC]` 作 `ESI`；若全域 `D63D09` 為真，先鎖 `FBA4C8`，到 `0x6E6871 mov [edi+4],esi`，然後在 `6E687C` 釋鎖。這與 E42 的 `0x6E9F9C mov [esi+4],ebx=0` 為**同一 manager 欄位**而非 offset 相同的不同型別。此 writer 的存入值可為非零，也可能為零，不能無前提稱 always nonnull。

**可證資料流**：`local_output([EBP−0xFC]) → ESI → manager_ptr(EDI) + 4`；不是 `manager_ptr + 0x398`、不是 `Client + 0x148`。`6E6865` 在鎖後再讀全域 manager 到 EAX，但寫入使用 6E6856 保存的 EDI；本次不宣稱這構成跨執行緒完全原子安全，亦未測測試程式/競態。

**剩餘缺口**：此 stack output 的所有 positive producer 與 Client+8 對應尚需 E43.2/E43.3；由此地址不能直接確定原版登入界面有成功切換。

**Native Assembly — 取得 manager、local output 及持鎖寫入 (`VA 0x6e6813–0x6e6883`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e6813:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6e6815:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  6e6818:	57                   	push   edi
  6e6819:	ff d2                	call   edx
  6e681b:	89 bd 04 ff ff ff    	mov    DWORD PTR [ebp-0xfc],edi
  6e6821:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6826:	85 c0                	test   eax,eax
  6e6828:	75 1f                	jne    0x6e6849
  6e682a:	68 80 13 00 00       	push   0x1380
  6e682f:	e8 34 aa 1a 00       	call   0x891268
  6e6834:	83 c4 04             	add    esp,0x4
  6e6837:	85 c0                	test   eax,eax
  6e6839:	74 07                	je     0x6e6842
  6e683b:	e8 90 8b ff ff       	call   0x6df3d0
  6e6840:	eb 02                	jmp    0x6e6844
  6e6842:	33 c0                	xor    eax,eax
  6e6844:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e6849:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6850:	8b b5 04 ff ff ff    	mov    esi,DWORD PTR [ebp-0xfc]
  6e6856:	8b f8                	mov    edi,eax
  6e6858:	74 10                	je     0x6e686a
  6e685a:	68 c8 a4 fb 00       	push   0xfba4c8
  6e685f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6865:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e686a:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6871:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  6e6874:	8b 3d 48 22 bd 00    	mov    edi,DWORD PTR ds:0xbd2248
  6e687a:	74 0c                	je     0x6e6888
  6e687c:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6881:	ff d7                	call   edi
```

## E43.2 — `6E65A0` 的雙路輸入：外部傳入物件與內部 callback 取回的指標

**研究問題**：寫入 manager+4 的 `[EBP−FC]` 到底由哪裏來？有無成功/錯誤路徑？

**N**：入口 `0x6E65A0` 以 **ECX**（不是 stack 第1參）保存在 EDI（`6E65BB`），先把 `[EBP−FC]` 清零（`6E65BD`）。`6E6617 test edi`; 若非零，**直接** `jne 6E6813`，對 `[EDI].vptr+4` 執行呼叫，`6E681B` 把原 EDI 保存至 `[EBP−FC]`。即 `ecx!=0` 路徑精確為 `this-like pointer → virtual+4 → local_output → manager+4`；virtual+4 的具體實作/是否 AddRef 要依該型別的 vtable，**AddRef 只是 COM 風格合理推測**。

**N — `ECX==0` 另一條路**：`6E661F` getter `6DFB80`，`6E662D` 保存 `[EBX+40]`，執行一組前置狀態/初始化後，在 `6E6732..6E6760` 對從 getter 取得之 interface（取 vptr+0x40）進行虛擬呼叫；在呼叫參數中傳入 `&[EBP−FC]`，讓被呼叫者可能寫出該指標。`6E6765` 的特殊 return 常數 `0x88760868` 會**立即走返回**，負 HRESULT 路徑回 `0x80040905`；只有不符合特殊值、非負返回的 `6E6808` 路徑才繼續寫 manager+4。因此 `ecx==0` 不等於一定寫入 NULL。完整 virtual target/輸出值來源 **U**。

**實際 CFG 精簡**：`ECX!=0 -> virtual+4 -> [local]=ECX -> writer`；`ECX==0 -> preflight/optional init -> virtual+0x40(&local) -> if special early return / if negative fail / else writer`。這些都是同一 `0x6E65A0` 函式，非把鄰接函式錯拼。

**剩餘缺口**：虛擬+0x40 實作與其輸出物件型別，及傳入 ECX 是哪個具體 Client subobject。

**Native Assembly — 6E65A0 入口與 ECX 分支（完整條件） (`VA 0x6e65a0–0x6e664f`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e65a0:	55                   	push   ebp
  6e65a1:	8b ec                	mov    ebp,esp
  6e65a3:	81 ec 0c 01 00 00    	sub    esp,0x10c
  6e65a9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6e65ae:	33 c5                	xor    eax,ebp
  6e65b0:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6e65b3:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e65b8:	53                   	push   ebx
  6e65b9:	56                   	push   esi
  6e65ba:	57                   	push   edi
  6e65bb:	8b f9                	mov    edi,ecx
  6e65bd:	c7 85 04 ff ff ff 00 	mov    DWORD PTR [ebp-0xfc],0x0
  6e65c4:	00 00 00 
  6e65c7:	85 c0                	test   eax,eax
  6e65c9:	75 1f                	jne    0x6e65ea
  6e65cb:	68 80 13 00 00       	push   0x1380
  6e65d0:	e8 93 ac 1a 00       	call   0x891268
  6e65d5:	83 c4 04             	add    esp,0x4
  6e65d8:	85 c0                	test   eax,eax
  6e65da:	74 07                	je     0x6e65e3
  6e65dc:	e8 ef 8d ff ff       	call   0x6df3d0
  6e65e1:	eb 02                	jmp    0x6e65e5
  6e65e3:	33 c0                	xor    eax,eax
  6e65e5:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e65ea:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e65f1:	8b f0                	mov    esi,eax
  6e65f3:	74 0b                	je     0x6e6600
  6e65f5:	68 c8 a4 fb 00       	push   0xfba4c8
  6e65fa:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6600:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6607:	8b 5e 0c             	mov    ebx,DWORD PTR [esi+0xc]
  6e660a:	74 0b                	je     0x6e6617
  6e660c:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6611:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e6617:	85 ff                	test   edi,edi
  6e6619:	0f 85 f4 01 00 00    	jne    0x6e6813
  6e661f:	e8 5c 95 ff ff       	call   0x6dfb80
  6e6624:	8b 73 30             	mov    esi,DWORD PTR [ebx+0x30]
  6e6627:	89 85 fc fe ff ff    	mov    DWORD PTR [ebp-0x104],eax
  6e662d:	8b 43 40             	mov    eax,DWORD PTR [ebx+0x40]
  6e6630:	89 b5 f8 fe ff ff    	mov    DWORD PTR [ebp-0x108],esi
  6e6636:	89 85 00 ff ff ff    	mov    DWORD PTR [ebp-0x100],eax
  6e663c:	85 f6                	test   esi,esi
  6e663e:	0f 85 ee 00 00 00    	jne    0x6e6732
  6e6644:	e8 b7 9b ff ff       	call   0x6e0200
  6e6649:	84 c0                	test   al,al
  6e664b:	0f 84 e1 00      	je     0x6e6732
```

**Native Assembly — interface callback 提供 &local_output / 特殊 code 分岔 (`VA 0x6e6732–0x6e681e`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e6732:	8b 95 fc fe ff ff    	mov    edx,DWORD PTR [ebp-0x104]
  6e6738:	8b 3a                	mov    edi,DWORD PTR [edx]
  6e673a:	8b 53 0c             	mov    edx,DWORD PTR [ebx+0xc]
  6e673d:	8d 85 04 ff ff ff    	lea    eax,[ebp-0xfc]
  6e6743:	50                   	push   eax
  6e6744:	8d 4b 10             	lea    ecx,[ebx+0x10]
  6e6747:	51                   	push   ecx
  6e6748:	52                   	push   edx
  6e6749:	e8 c2 96 ff ff       	call   0x6dfe10
  6e674e:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  6e6750:	8b 95 fc fe ff ff    	mov    edx,DWORD PTR [ebp-0x104]
  6e6756:	50                   	push   eax
  6e6757:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  6e675a:	50                   	push   eax
  6e675b:	8b 47 40             	mov    eax,DWORD PTR [edi+0x40]
  6e675e:	51                   	push   ecx
  6e675f:	52                   	push   edx
  6e6760:	ff d0                	call   eax
  6e6762:	89 73 30             	mov    DWORD PTR [ebx+0x30],esi
  6e6765:	3d 68 08 76 88       	cmp    eax,0x88760868
  6e676a:	75 79                	jne    0x6e67e5
  6e676c:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6771:	8b 8d 00 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x100]
  6e6777:	89 4b 40             	mov    DWORD PTR [ebx+0x40],ecx
  6e677a:	85 c0                	test   eax,eax
  6e677c:	75 1f                	jne    0x6e679d
  6e677e:	68 80 13 00 00       	push   0x1380
  6e6783:	e8 e0 aa 1a 00       	call   0x891268
  6e6788:	83 c4 04             	add    esp,0x4
  6e678b:	85 c0                	test   eax,eax
  6e678d:	74 07                	je     0x6e6796
  6e678f:	e8 3c 8c ff ff       	call   0x6df3d0
  6e6794:	eb 02                	jmp    0x6e6798
  6e6796:	33 c0                	xor    eax,eax
  6e6798:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e679d:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e67a4:	8b f0                	mov    esi,eax
  6e67a6:	74 0b                	je     0x6e67b3
  6e67a8:	68 c8 a4 fb 00       	push   0xfba4c8
  6e67ad:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e67b3:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e67ba:	c6 86 28 03 00 00 01 	mov    BYTE PTR [esi+0x328],0x1
  6e67c1:	0f 84 3f 04 00 00    	je     0x6e6c06
  6e67c7:	68 c8 a4 fb 00       	push   0xfba4c8
  6e67cc:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e67d2:	33 c0                	xor    eax,eax
  6e67d4:	5f                   	pop    edi
  6e67d5:	5e                   	pop    esi
  6e67d6:	5b                   	pop    ebx
  6e67d7:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6e67da:	33 cd                	xor    ecx,ebp
  6e67dc:	e8 20 a8 1a 00       	call   0x891001
  6e67e1:	8b e5                	mov    esp,ebp
  6e67e3:	5d                   	pop    ebp
  6e67e4:	c3                   	ret
  6e67e5:	85 c0                	test   eax,eax
  6e67e7:	79 1f                	jns    0x6e6808
  6e67e9:	8b 95 00 ff ff ff    	mov    edx,DWORD PTR [ebp-0x100]
  6e67ef:	89 53 40             	mov    DWORD PTR [ebx+0x40],edx
  6e67f2:	b8 05 09 04 80       	mov    eax,0x80040905
  6e67f7:	5f                   	pop    edi
  6e67f8:	5e                   	pop    esi
  6e67f9:	5b                   	pop    ebx
  6e67fa:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6e67fd:	33 cd                	xor    ecx,ebp
  6e67ff:	e8 fd a7 1a 00       	call   0x891001
  6e6804:	8b e5                	mov    esp,ebp
  6e6806:	5d                   	pop    ebp
  6e6807:	c3                   	ret
  6e6808:	8b 85 00 ff ff ff    	mov    eax,DWORD PTR [ebp-0x100]
  6e680e:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  6e6811:	eb 0e                	jmp    0x6e6821
  6e6813:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6e6815:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  6e6818:	57                   	push   edi
  6e6819:	ff d2                	call   edx
  6e681b:	89 bd 04       	mov    DWORD PTR [ebp-0xfc],edi
```

## E43.3 — `6E4F90 → 6E5530 → 6E65A0` 的 caller／參數來源（不得越證）

**研究問題**：有沒有對外部傳入指標來源的 caller 證據，能證明 manager 取得的就是 Client `C+8`？

**N**：`6E4F90` (`6E4FA3`) 將 **第二個 stack 參數 `[EBP+0xC]`** 存入 `[EBP−0x208]`；`6E552A` 從此 local `mov ecx,[ebp−0x208]`，`6E5530` 是唯一確認的 `call 6E65A0` (以原件 direct E8 rel32 掃描 `.text`：只有此命中，仍以已解碼指令為準)。這把 `0x6E6871` 的資料來源追至**通用初始化函式的具體參數**，大幅收斂 E42 的「未知 alias」。

**caller 遍歷去重**：對 `6E4F90` 的 direct CALL 候選有十二處：

`0x6e2dfc`, `0x6e31cc`, `0x6e326e`, `0x6e359d`, `0x6e3637`, `0x6e5457`, `0x6e5a55`, `0x6e76a6`, `0x6e7c2e`, `0x6e7e72`, `0x6e7ee0`, `0x6eabc3`。其中 `6E2DFC/6E31CC/6E326E/6E359D/6E3637` 等有傳入零作第二參數的路徑；`6E5457` 會傳自身 `[ebp−0x208]` 繼續 delegate；`6E5A55` 則傳局部 `[ebp−0x64]` 的 address。**不能把這一組全部視為 C+8 caller。** 若有其他透過 vtable/外部模組的呼叫也未完整索引；不能因 12 個 direct E8 就宣稱窮盡全部動態 caller。

**E42 訂正／界線**：過去「正向 manager+4 writer 完全找不到」現在已否定；更精確的新缺口是 **writer 的 source identity 未證實為 C+8**。有 writer ≠ 證實 gameplay 中實際選擇該 Client callback。

**剩餘缺口**：`0x6DEB40`、Client `C+8` 的註冊 API 如何把精確 `C+8` 值放入通用 `6E4F90` 第二參數；以及某些分支由 `vptr+0x40` 返回而非外部傳入的型別。

**Native Assembly — 6E4F90 接收 p2、儲存與準備 (`VA 0x6e4f90–0x6e502d`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e4f90:	55                   	push   ebp
  6e4f91:	8b ec                	mov    ebp,esp
  6e4f93:	81 ec 18 02 00 00    	sub    esp,0x218
  6e4f99:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6e4f9e:	33 c5                	xor    eax,ebp
  6e4fa0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  6e4fa3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6e4fa6:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  6e4fa9:	53                   	push   ebx
  6e4faa:	89 85 f8 fd ff ff    	mov    DWORD PTR [ebp-0x208],eax
  6e4fb0:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e4fb5:	56                   	push   esi
  6e4fb6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6e4fb9:	57                   	push   edi
  6e4fba:	89 8d f4 fd ff ff    	mov    DWORD PTR [ebp-0x20c],ecx
  6e4fc0:	85 c0                	test   eax,eax
  6e4fc2:	75 1f                	jne    0x6e4fe3
  6e4fc4:	68 80 13 00 00       	push   0x1380
  6e4fc9:	e8 9a c2 1a 00       	call   0x891268
  6e4fce:	83 c4 04             	add    esp,0x4
  6e4fd1:	85 c0                	test   eax,eax
  6e4fd3:	74 07                	je     0x6e4fdc
  6e4fd5:	e8 f6 a3 ff ff       	call   0x6df3d0
  6e4fda:	eb 02                	jmp    0x6e4fde
  6e4fdc:	33 c0                	xor    eax,eax
  6e4fde:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e4fe3:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e4fea:	8b f8                	mov    edi,eax
  6e4fec:	74 0b                	je     0x6e4ff9
  6e4fee:	68 c8 a4 fb 00       	push   0xfba4c8
  6e4ff3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e4ff9:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e5000:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  6e5003:	89 95 f0 fd ff ff    	mov    DWORD PTR [ebp-0x210],edx
  6e5009:	74 0b                	je     0x6e5016
  6e500b:	68 c8 a4 fb 00       	push   0xfba4c8
  6e5010:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e5016:	c7 85 fc fd ff ff 00 	mov    DWORD PTR [ebp-0x204],0x0
  6e501d:	00 00 00 
  6e5020:	e8 5b ab ff ff       	call   0x6dfb80
  6e5025:	85 c0                	test   eax,eax
  6e5027:	0f 84 e9 00 00 00    	je     0x6e5116
```

**Native Assembly — 6E4F90 中條件式取 p2 / 呼叫 6E65A0 (`VA 0x6e5388–0x6e5567`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e5388:	80 7d 10 00          	cmp    BYTE PTR [ebp+0x10],0x0
  6e538c:	0f 85 8a 01 00 00    	jne    0x6e551c
  6e5392:	8b b5 f8 fd ff ff    	mov    esi,DWORD PTR [ebp-0x208]
  6e5398:	85 f6                	test   esi,esi
  6e539a:	74 0d                	je     0x6e53a9
  6e539c:	e8 3f a8 ff ff       	call   0x6dfbe0
  6e53a1:	3b f0                	cmp    esi,eax
  6e53a3:	0f 85 73 01 00 00    	jne    0x6e551c
  6e53a9:	e8 32 a8 ff ff       	call   0x6dfbe0
  6e53ae:	85 c0                	test   eax,eax
  6e53b0:	0f 84 66 01 00 00    	je     0x6e551c
  6e53b6:	85 ff                	test   edi,edi
  6e53b8:	0f 84 6c 01 00 00    	je     0x6e552a
  6e53be:	8b 17                	mov    edx,DWORD PTR [edi]
  6e53c0:	3b 13                	cmp    edx,DWORD PTR [ebx]
  6e53c2:	0f 85 54 01 00 00    	jne    0x6e551c
  6e53c8:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  6e53cb:	3b 43 04             	cmp    eax,DWORD PTR [ebx+0x4]
  6e53ce:	0f 85 48 01 00 00    	jne    0x6e551c
  6e53d4:	8b 4f 0c             	mov    ecx,DWORD PTR [edi+0xc]
  6e53d7:	3b 4b 0c             	cmp    ecx,DWORD PTR [ebx+0xc]
  6e53da:	0f 85 3c 01 00 00    	jne    0x6e551c
  6e53e0:	57                   	push   edi
  6e53e1:	e8 3a 18 00 00       	call   0x6e6c20
  6e53e6:	8b f0                	mov    esi,eax
  6e53e8:	83 c4 04             	add    esp,0x4
  6e53eb:	85 f6                	test   esi,esi
  6e53ed:	79 15                	jns    0x6e5404
  6e53ef:	81 fe 68 08 76 88    	cmp    esi,0x88760868
  6e53f5:	75 27                	jne    0x6e541e
  6e53f7:	6a 01                	push   0x1
  6e53f9:	e8 d2 a2 ff ff       	call   0x6df6d0
  6e53fe:	50                   	push   eax
  6e53ff:	e8 9c bc ff ff       	call   0x6e10a0
  6e5404:	83 7b 30 00          	cmp    DWORD PTR [ebx+0x30],0x0
  6e5408:	0f 84 96 01 00 00    	je     0x6e55a4
  6e540e:	e8 bd a2 ff ff       	call   0x6df6d0
  6e5413:	50                   	push   eax
  6e5414:	e8 f7 b6 ff ff       	call   0x6e0b10
  6e5419:	e9 91 01 00 00       	jmp    0x6e55af
  6e541e:	81 fe 08 09 04 80    	cmp    esi,0x80040908
  6e5424:	0f 84 af 00 00 00    	je     0x6e54d9
  6e542a:	81 fe 03 09 04 80    	cmp    esi,0x80040903
  6e5430:	0f 84 a3 00 00 00    	je     0x6e54d9
  6e5436:	57                   	push   edi
  6e5437:	e8 94 a2 ff ff       	call   0x6df6d0
  6e543c:	50                   	push   eax
  6e543d:	e8 3e af ff ff       	call   0x6e0380
  6e5442:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  6e5445:	8b 8d f8 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x208]
  6e544b:	8d 95 fc fd ff ff    	lea    edx,[ebp-0x204]
  6e5451:	52                   	push   edx
  6e5452:	50                   	push   eax
  6e5453:	6a 01                	push   0x1
  6e5455:	51                   	push   ecx
  6e5456:	53                   	push   ebx
  6e5457:	e8 34 fb ff ff       	call   0x6e4f90
  6e545c:	83 c4 14             	add    esp,0x14
  6e545f:	85 c0                	test   eax,eax
  6e5461:	79 3d                	jns    0x6e54a0
  6e5463:	83 bd fc fd ff ff 00 	cmp    DWORD PTR [ebp-0x204],0x0
  6e546a:	75 19                	jne    0x6e5485
  6e546c:	8b 85 f4 fd ff ff    	mov    eax,DWORD PTR [ebp-0x20c]
  6e5472:	85 c0                	test   eax,eax
  6e5474:	74 06                	je     0x6e547c
  6e5476:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  6e547c:	57                   	push   edi
  6e547d:	e8 8a bd 1a 00       	call   0x89120c
  6e5482:	83 c4 04             	add    esp,0x4
  6e5485:	e8 56 46 00 00       	call   0x6e9ae0
  6e548a:	b8 05 09 04 80       	mov    eax,0x80040905
  6e548f:	5f                   	pop    edi
  6e5490:	5e                   	pop    esi
  6e5491:	5b                   	pop    ebx
  6e5492:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  6e5495:	33 cd                	xor    ecx,ebp
  6e5497:	e8 65 bb 1a 00       	call   0x891001
  6e549c:	8b e5                	mov    esp,ebp
  6e549e:	5d                   	pop    ebp
  6e549f:	c3                   	ret
  6e54a0:	83 bd fc fd ff ff 00 	cmp    DWORD PTR [ebp-0x204],0x0
  6e54a7:	0f 85 bb 06 00 00    	jne    0x6e5b68
  6e54ad:	8b 85 f4 fd ff ff    	mov    eax,DWORD PTR [ebp-0x20c]
  6e54b3:	85 c0                	test   eax,eax
  6e54b5:	74 06                	je     0x6e54bd
  6e54b7:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  6e54bd:	57                   	push   edi
  6e54be:	e8 49 bd 1a 00       	call   0x89120c
  6e54c3:	83 c4 04             	add    esp,0x4
  6e54c6:	33 c0                	xor    eax,eax
  6e54c8:	5f                   	pop    edi
  6e54c9:	5e                   	pop    esi
  6e54ca:	5b                   	pop    ebx
  6e54cb:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  6e54ce:	33 cd                	xor    ecx,ebp
  6e54d0:	e8 2c bb 1a 00       	call   0x891001
  6e54d5:	8b e5                	mov    esp,ebp
  6e54d7:	5d                   	pop    ebp
  6e54d8:	c3                   	ret
  6e54d9:	83 bd fc fd ff ff 00 	cmp    DWORD PTR [ebp-0x204],0x0
  6e54e0:	75 19                	jne    0x6e54fb
  6e54e2:	8b 85 f4 fd ff ff    	mov    eax,DWORD PTR [ebp-0x20c]
  6e54e8:	85 c0                	test   eax,eax
  6e54ea:	74 06                	je     0x6e54f2
  6e54ec:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  6e54f2:	57                   	push   edi
  6e54f3:	e8 14 bd 1a 00       	call   0x89120c
  6e54f8:	83 c4 04             	add    esp,0x4
  6e54fb:	56                   	push   esi
  6e54fc:	e8 6f 50 00 00       	call   0x6ea570
  6e5501:	83 c4 04             	add    esp,0x4
  6e5504:	e8 d7 45 00 00       	call   0x6e9ae0
  6e5509:	8b c6                	mov    eax,esi
  6e550b:	5f                   	pop    edi
  6e550c:	5e                   	pop    esi
  6e550d:	5b                   	pop    ebx
  6e550e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  6e5511:	33 cd                	xor    ecx,ebp
  6e5513:	e8 e9 ba 1a 00       	call   0x891001
  6e5518:	8b e5                	mov    esp,ebp
  6e551a:	5d                   	pop    ebp
  6e551b:	c3                   	ret
  6e551c:	85 ff                	test   edi,edi
  6e551e:	74 0a                	je     0x6e552a
  6e5520:	6a 00                	push   0x0
  6e5522:	e8 29 47 00 00       	call   0x6e9c50
  6e5527:	83 c4 04             	add    esp,0x4
  6e552a:	8b 8d f8 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x208]
  6e5530:	e8 6b 10 00 00       	call   0x6e65a0
  6e5535:	8b f0                	mov    esi,eax
  6e5537:	85 f6                	test   esi,esi
  6e5539:	0f 89 c5 fe ff ff    	jns    0x6e5404
  6e553f:	83 bd fc fd ff ff 00 	cmp    DWORD PTR [ebp-0x204],0x0
  6e5546:	75 1d                	jne    0x6e5565
  6e5548:	8b 85 f4 fd ff ff    	mov    eax,DWORD PTR [ebp-0x20c]
  6e554e:	85 c0                	test   eax,eax
  6e5550:	74 06                	je     0x6e5558
  6e5552:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  6e5558:	85 ff                	test   edi,edi
  6e555a:	74 09                	je     0x6e5565
  6e555c:	57                   	push   edi
  6e555d:	e8 aa bc 1a 00       	call   0x89120c
  6e5562:	83 c4 04             	add    esp,0x4
  6e5565:	6a 01                	push   0x1
```

**Native Assembly — 6E5457 接續傳遞 p2（此函式內 callback 路徑） (`VA 0x6e5442–0x6e5462`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e5442:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  6e5445:	8b 8d f8 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x208]
  6e544b:	8d 95 fc fd ff ff    	lea    edx,[ebp-0x204]
  6e5451:	52                   	push   edx
  6e5452:	50                   	push   eax
  6e5453:	6a 01                	push   0x1
  6e5455:	51                   	push   ecx
  6e5456:	53                   	push   ebx
  6e5457:	e8 34 fb ff ff       	call   0x6e4f90
  6e545c:	83 c4 14             	add    esp,0x14
  6e545f:	85 c0                	test   eax,eax
  6e5461:	79                 	jns    0x6e54a0
```

## E43.4 — 真正的 writer 後續呼叫 mainloop pump、失敗碼與 conditional reachability

**研究問題**：`6E6871` 設定指標後，是否在**同一 native 流程**再觸發 E42 的 `6DFA50`？需何種狀態？

**N**：在 `6E6871` 之後，同一 `0x6E65A0` 正常分支於 `6E6888` 檢查 `[EBX+4]==2`，可在 manager `[+30C]==0` 相關條件下調另一輔助 `6E0CE0`；`6E68EF` 另測 `[EBX+4]==1`、`6DF5E0(... )==0xB`。不論這些分支的部分被跳過，在落到 `6E6930` 的正常 CFG 上會先 `6EA1A0`，後於 **`6E6935` 直接 CALL `6DFA50`**。E42 只從 `6DFA50` 反查兩個 direct xrefs，本次已完整找到它與正向 writer 共屬一個 caller；這是 writer→consumer 的實質連結。

**C**：`6DFA50` 有 `6DFBE0` getter、`6EA3D0` guard、`ESI!=0` guard，成功時經 receiver vptr+0x30 接入 `490FE0`（當 vptr 是 C05AA4 且 receiver=C+8）。`6E6935` **並非保證當次有 packet／可觸發回呼**；queue 沒有 packet、ESI 不對、或另外 gate 阻止時仍不走相同 handler。

**剩餘缺口**：特定 vptr+0x40 實作是否輸出 C+8、`6E6935` 在具體版本初始化時的 tick/事件頻率，以及此 route 對每個 socket 的實際第一個收到 packet 的時序。

**Native Assembly — 6E65A0 writer 後的條件分支與直接 6DFA50 (`VA 0x6e6883–0x6e699a`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e6883:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6888:	83 7b 04 02          	cmp    DWORD PTR [ebx+0x4],0x2
  6e688c:	75 61                	jne    0x6e68ef
  6e688e:	85 c0                	test   eax,eax
  6e6890:	75 1f                	jne    0x6e68b1
  6e6892:	68 80 13 00 00       	push   0x1380
  6e6897:	e8 cc a9 1a 00       	call   0x891268
  6e689c:	83 c4 04             	add    esp,0x4
  6e689f:	85 c0                	test   eax,eax
  6e68a1:	74 07                	je     0x6e68aa
  6e68a3:	e8 28 8b ff ff       	call   0x6df3d0
  6e68a8:	eb 02                	jmp    0x6e68ac
  6e68aa:	33 c0                	xor    eax,eax
  6e68ac:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e68b1:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e68b8:	8b f0                	mov    esi,eax
  6e68ba:	74 10                	je     0x6e68cc
  6e68bc:	68 c8 a4 fb 00       	push   0xfba4c8
  6e68c1:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e68c7:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e68cc:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e68d3:	8b b6 0c 03 00 00    	mov    esi,DWORD PTR [esi+0x30c]
  6e68d9:	74 0c                	je     0x6e68e7
  6e68db:	68 c8 a4 fb 00       	push   0xfba4c8
  6e68e0:	ff d7                	call   edi
  6e68e2:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e68e7:	85 f6                	test   esi,esi
  6e68e9:	75 04                	jne    0x6e68ef
  6e68eb:	6a 0b                	push   0xb
  6e68ed:	eb 36                	jmp    0x6e6925
  6e68ef:	83 7b 04 01          	cmp    DWORD PTR [ebx+0x4],0x1
  6e68f3:	75 3b                	jne    0x6e6930
  6e68f5:	85 c0                	test   eax,eax
  6e68f7:	75 1f                	jne    0x6e6918
  6e68f9:	68 80 13 00 00       	push   0x1380
  6e68fe:	e8 65 a9 1a 00       	call   0x891268
  6e6903:	83 c4 04             	add    esp,0x4
  6e6906:	85 c0                	test   eax,eax
  6e6908:	74 07                	je     0x6e6911
  6e690a:	e8 c1 8a ff ff       	call   0x6df3d0
  6e690f:	eb 02                	jmp    0x6e6913
  6e6911:	33 c0                	xor    eax,eax
  6e6913:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e6918:	50                   	push   eax
  6e6919:	e8 c2 8c ff ff       	call   0x6df5e0
  6e691e:	83 f8 0b             	cmp    eax,0xb
  6e6921:	75 0d                	jne    0x6e6930
  6e6923:	6a 00                	push   0x0
  6e6925:	e8 a6 8d ff ff       	call   0x6df6d0
  6e692a:	50                   	push   eax
  6e692b:	e8 b0 a3 ff ff       	call   0x6e0ce0
  6e6930:	e8 6b 38 00 00       	call   0x6ea1a0
  6e6935:	e8 16 91 ff ff       	call   0x6dfa50
  6e693a:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e693f:	85 c0                	test   eax,eax
  6e6941:	75 1f                	jne    0x6e6962
  6e6943:	68 80 13 00 00       	push   0x1380
  6e6948:	e8 1b a9 1a 00       	call   0x891268
  6e694d:	83 c4 04             	add    esp,0x4
  6e6950:	85 c0                	test   eax,eax
  6e6952:	74 07                	je     0x6e695b
  6e6954:	e8 77 8a ff ff       	call   0x6df3d0
  6e6959:	eb 02                	jmp    0x6e695d
  6e695b:	33 c0                	xor    eax,eax
  6e695d:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e6962:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6969:	8b f0                	mov    esi,eax
  6e696b:	74 0b                	je     0x6e6978
  6e696d:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6972:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6978:	83 c6 30             	add    esi,0x30
  6e697b:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6982:	74 07                	je     0x6e698b
  6e6984:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6989:	ff d7                	call   edi
  6e698b:	e8 50 92 ff ff       	call   0x6dfbe0
  6e6990:	8b 08                	mov    ecx,DWORD PTR [eax]
  6e6992:	8b 51 1c             	mov    edx,DWORD PTR [ecx+0x1c]
  6e6995:	56                   	push   esi
  6e6996:	50                   	push   eax
  6e6997:	ff d2                	call   edx
  6e6999:	6a                 	push   0x0
```

**Native Assembly — 6DFA50 呼叫 dispatch 的 getter / gate (`VA 0x6dfa60–0x6dfae7`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6dfa60:	53                   	push   ebx
  6dfa61:	56                   	push   esi
  6dfa62:	e8 79 01 00 00       	call   0x6dfbe0
  6dfa67:	8b f0                	mov    esi,eax
  6dfa69:	e8 62 a9 00 00       	call   0x6ea3d0
  6dfa6e:	84 c0                	test   al,al
  6dfa70:	75 75                	jne    0x6dfae7
  6dfa72:	85 f6                	test   esi,esi
  6dfa74:	74 71                	je     0x6dfae7
  6dfa76:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6dfa7b:	85 c0                	test   eax,eax
  6dfa7d:	75 1f                	jne    0x6dfa9e
  6dfa7f:	68 80 13 00 00       	push   0x1380
  6dfa84:	e8 df 17 1b 00       	call   0x891268
  6dfa89:	83 c4 04             	add    esp,0x4
  6dfa8c:	85 c0                	test   eax,eax
  6dfa8e:	74 07                	je     0x6dfa97
  6dfa90:	e8 3b f9 ff ff       	call   0x6df3d0
  6dfa95:	eb 02                	jmp    0x6dfa99
  6dfa97:	33 c0                	xor    eax,eax
  6dfa99:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6dfa9e:	50                   	push   eax
  6dfa9f:	e8 bc fa ff ff       	call   0x6df560
  6dfaa4:	6a 00                	push   0x0
  6dfaa6:	84 c0                	test   al,al
  6dfaa8:	74 28                	je     0x6dfad2
  6dfaaa:	ff 15 d4 24 bd 00    	call   DWORD PTR ds:0xbd24d4
  6dfab0:	6a f4                	push   0xfffffff4
  6dfab2:	e8 b9 03 00 00       	call   0x6dfe70
  6dfab7:	50                   	push   eax
  6dfab8:	ff 15 d0 24 bd 00    	call   DWORD PTR ds:0xbd24d0
  6dfabe:	56                   	push   esi
  6dfabf:	8b c8                	mov    ecx,eax
  6dfac1:	e8 3a fc ff ff       	call   0x6df700
  6dfac6:	83 c4 04             	add    esp,0x4
  6dfac9:	e8 12 01 00 00       	call   0x6dfbe0
  6dface:	6a 01                	push   0x1
  6dfad0:	eb 0d                	jmp    0x6dfadf
  6dfad2:	ff 15 d4 24 bd 00    	call   DWORD PTR ds:0xbd24d4
  6dfad8:	e8 03 01 00 00       	call   0x6dfbe0
  6dfadd:	6a 00                	push   0x0
  6dfadf:	8b 08                	mov    ecx,DWORD PTR [eax]
  6dfae1:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  6dfae4:	50                   	push   eax
  6dfae5:	ff d2                	call   edx
```

## E43.5 — writer / getter / 清零的生命週期與拒絕條件矩陣

**研究問題**：為避免「註冊後永遠可回呼」的錯誤，pointer 可用性何時成立/失效？

**N**：`6DF3D0→6DF660` 將新 manager 的前 `0x1350` bytes 清零（包含 +4）；`6DFBE0` 讀 manager+4 會在 `D63D09` gate 下加鎖；`6E6871` 是正向候選 setter，`6E9F9C` 把同欄位置零，`6DECBA…6DECDD` 釋放整個 manager 並把全域 `[FBA7CC]=0`。`6E65A0` 有 HRESULT-like 失敗，後續 `6E4F90` 檢查 `js/negative`；這些失敗**不能**等同 Client 已連線或登入失敗的 wire 結果。

| 事件 | manager+4 | 已證限制 |
|---|---|---|
| lazy allocation / ctor | zero by init | 不能直接執行 receiver.vptr |
| `6E65A0→6E6871` 正常 path | local_output（可能非零） | source object 尚未精確對 C+8 |
| `6DFBE0` getter | 讀同欄位 | 有受鎖讀，未證全生命周期同步 |
| `6E9F9C` teardown | 0 | 不能聲稱所有 outstanding IO 已 drained |
| framework `6DEC90` shutdown | manager free/global 0 | 不等於每次選服切線都會重建 manager |

**剩餘缺口**：已排隊的 packet 對 Conn* 和 Client subobject 的完整生命週期保障、close/retry 是否必經同一 manager reset；runtime race/UAF 均不能從靜態列表直接宣稱已發生。

**Native Assembly — manager+4 明確清零與 teardown 條件 (`VA 0x6e9f81–0x6e9fb8`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6e9f81:	8b 35 cc a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7cc
  6e9f87:	8b 3d 4c 22 bd 00    	mov    edi,DWORD PTR ds:0xbd224c
  6e9f8d:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9f93:	74 07                	je     0x6e9f9c
  6e9f95:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9f9a:	ff d7                	call   edi
  6e9f9c:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  6e9f9f:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9fa5:	74 0b                	je     0x6e9fb2
  6e9fa7:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9fac:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e9fb2:	38 5d 08             	cmp    BYTE PTR [ebp+0x8],bl
  6e9fb5:	0f 84 b1       	je     0x6ea06c
```

**Native Assembly — framework shutdown 包含 global manager 清理 (`VA 0x6dec90–0x6decef`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6dec90:	83 7f 2c 00          	cmp    DWORD PTR [edi+0x2c],0x0
  6dec94:	56                   	push   esi
  6dec95:	74 07                	je     0x6dec9e
  6dec97:	b8 05 40 00 80       	mov    eax,0x80004005
  6dec9c:	5e                   	pop    esi
  6dec9d:	c3                   	ret
  6dec9e:	e8 fd 14 00 00       	call   0x6e01a0
  6deca3:	85 c0                	test   eax,eax
  6deca5:	74 13                	je     0x6decba
  6deca7:	83 f8 01             	cmp    eax,0x1
  6decaa:	74 0e                	je     0x6decba
  6decac:	50                   	push   eax
  6decad:	68 04 12 c4 00       	push   0xc41204
  6decb2:	e8 06 44 1b 00       	call   0x8930bd
  6decb7:	83 c4 08             	add    esp,0x8
  6decba:	8b 35 cc a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7cc
  6decc0:	85 f6                	test   esi,esi
  6decc2:	74 23                	je     0x6dece7
  6decc4:	e8 17 ae 00 00       	call   0x6e9ae0
  6decc9:	68 c8 a4 fb 00       	push   0xfba4c8
  6decce:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  6decd4:	56                   	push   esi
  6decd5:	e8 32 25 1b 00       	call   0x89120c
  6decda:	83 c4 04             	add    esp,0x4
  6decdd:	c7 05 cc a7 fb 00 00 	mov    DWORD PTR ds:0xfba7cc,0x0
  6dece4:	00 00 00 
  6dece7:	8b 07                	mov    eax,DWORD PTR [edi]
  6dece9:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  6decec:	57                   	push   edi
  6deced:	ff d1                	call   ecx
```

## E43.6 — 以實際 Client subobject 地址檢查 callback receiver（與 manager writer 的相接條件）

**研究問題**：manager+4 若被傳入一個 pointer，如何辨識「剛好是 Client C+8」；差 8 bytes 問題是否已完成獨立復核？

**N**：`4A3041 lea C=[esp+2C]`，`4A3046 call 48AB70` ctor；`4A304B lea [esp+34]` 是 `C+8`，`4A305A` 把 ESI=C+8 提交 `6DEB40`。原生 `.rdata [C05AA4+0x30] = 0x490FE0`，`[C05AEC+0]=0x4930E0`；E41 已核 `C+0x148` 安裝 `0xC05AEC` secondary vptr。`490FE0` 的 `lea ebx,[edi+0x140]` 以 `EDI=C+8` 計算即 `C+0x148`，並 `push ebx; call 804740`。因此當 `manager+4=C+8` 時，所需 receiver address 及 vtable identity **可以直接算出**，不必靠「差8相似」猜測。

**C**：`0x6E6871` 能儲存不特定 pointer；只有證明 `6E4F90 p2 == C+8`，才把此強條件變成 runtime 已確認。E43 找到 manager writer 的存在，**並未取得這個等式**。

**剩餘缺口**：不同時刻 secondary vptr 動態覆寫及確實被選中的個體、`6DEB40` 傳遞 C+8 到 `6E4F90` 的完整橋接。

**Native Assembly — 原始 Client+8 傳入 framework (`VA 0x4a3041–0x4a3065`，只以原件解碼；端點遵循指令邊界)：**

```asm
  4a3041:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  4a3045:	51                   	push   ecx
  4a3046:	e8 25 7b fe ff       	call   0x48ab70
  4a304b:	8d 74 24 34          	lea    esi,[esp+0x34]
  4a304f:	c7 84 24 c0 c0 00 00 	mov    DWORD PTR [esp+0xc0c0],0x1
  4a3056:	01 00 00 00 
  4a305a:	e8 e1 ba 23 00       	call   0x6deb40
  4a305f:	e8 dc bb 23 00       	call   0x6dec40
  4a3064:	8b                 	mov    edi,esi
```

**Native Assembly — framework 的 vptr+0x28 callback 與 6E2850 (`VA 0x6dec10–0x6dec3f`，只以原件解碼；端點遵循指令邊界)：**

```asm
  6dec10:	e8 4b 11 00 00       	call   0x6dfd60
  6dec15:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  6dec18:	8b 06                	mov    eax,DWORD PTR [esi]
  6dec1a:	8b 48 28             	mov    ecx,DWORD PTR [eax+0x28]
  6dec1d:	56                   	push   esi
  6dec1e:	ff d1                	call   ecx
  6dec20:	8b 46 3c             	mov    eax,DWORD PTR [esi+0x3c]
  6dec23:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  6dec26:	56                   	push   esi
  6dec27:	68 50 ae 6e 00       	push   0x6eae50
  6dec2c:	68 10 ae 6e 00       	push   0x6eae10
  6dec31:	50                   	push   eax
  6dec32:	51                   	push   ecx
  6dec33:	e8 18 3c 00 00       	call   0x6e2850
  6dec38:	83 c4 14             	add    esp,0x14
  6dec3b:	33 c0                	xor    eax,eax
  6dec3d:	5f                   	pop    edi
  6dec3e:	c3                   	ret
```

**Native Assembly — mainloop 中 holder=(C+8)+0x140 (`VA 0x49197f–0x491990`，只以原件解碼；端點遵循指令邊界)：**

```asm
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6       	test   BYTE PTR ds:0xfc10cc,0x1
```

**`.rdata` vtable 直接原件 LE32 解碼**（不可套用 `.text` raw bias）：`[0xC05AA4+0x30]=0x490FE0`；`[0xC05AEC]=0x4930E0`；`[0xC05AEC+0x1C]=0x48AAD0`。這是相鄰但不同的 secondary subobject vtable/slot，不代表所有物件 vptr 在 runtime 都相同。

## E43.7 — 收包 FIFO 到兩層 dispatch：header/lane/override 不能跳過

**研究問題**：E43 正向 writer 可證後，是否能直接宣稱 `index2/0xBD2` 一定到達？

**N + C（保留 E40/E41 的必要前提，並由本 BIN 重新核實核心點）**：`0x807D8B` 把 Conn* 存 packet+0，`0x807D83` 先判斷 packet+4 nonzero，`0x807D9E` 讀 Conn+A080 為 app lane；`0x807DAD` 入 FC10D0。`0x80486D` 以 holder.vptr[0] 回呼時仍保留 packet source、payload、length、lane，並非先把 Conn* 轉成 transport key。`0x4930E0` 解析 payload WORD，並針對 lane 的條件選擇 delegate；前端 `48AAD0` 使用 stride16 callback 表、預設 `494360`，後端 `4FDA30` 是另一個 stride8 表，signed 16-bit command。這些是**有條件可達的局部原生鏈**。

**重要安全/相容界線**：`4FDA30` 的 `movsx edi,cx` 使用 signed command，對負值 index 的 upstream validation 尚未證明；`0x4930E0` 讀 WORD 的有效長度 guard 必須按 caller 層一起審核；不據此宣稱攻擊可利用。`index2→4B7F00`、`0xBD2→4B8DC0` 為 handler 註冊後具對應索引的候選，必須檢查 16-byte first-tier override 和上游實際 command/destination，不能當選服 S2C first reply。

**剩餘缺口**：當次 inbound packet transport key、完整 first framing、first S2C、所有 top-tier override writer 及它們的 lifetime，皆未因找到 `6E6871` 而自動解決。

**Native Assembly — producer payload->FC10D0 app bucket (`VA 0x807d7f–0x807db2`，只以原件解碼；端點遵循指令邊界)：**

```asm
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
```

**Native Assembly — callback holder 的 virtual call 及参数 (`VA 0x804837–0x804873`，只以原件解碼；端點遵循指令邊界)：**

```asm
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff                 	call   edi
```

**Native Assembly — 4930E0 讀 command 與 delegate (`VA 0x4930e0–0x49315b`，只以原件解碼；端點遵循指令邊界)：**

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
```

**Native Assembly — 48AAD0 前段 callback 路由（使用 stride16） (`VA 0x48aad0–0x48ab64`，只以原件解碼；端點遵循指令邊界)：**

```asm
  48aad0:	55                   	push   ebp
  48aad1:	8b ec                	mov    ebp,esp
  48aad3:	83 ec 08             	sub    esp,0x8
  48aad6:	53                   	push   ebx
  48aad7:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  48aada:	0f bf c3             	movsx  eax,bx
  48aadd:	56                   	push   esi
  48aade:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  48aae1:	03 c0                	add    eax,eax
  48aae3:	57                   	push   edi
  48aae4:	8b f9                	mov    edi,ecx
  48aae6:	8b 4c c7 0c          	mov    ecx,DWORD PTR [edi+eax*8+0xc]
  48aaea:	8d 34 c7             	lea    esi,[edi+eax*8]
  48aaed:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  48aaf0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  48aaf3:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  48aaf6:	85 c0                	test   eax,eax
  48aaf8:	75 1b                	jne    0x48ab15
  48aafa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  48aafd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48ab00:	8b 17                	mov    edx,DWORD PTR [edi]
  48ab02:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  48ab05:	53                   	push   ebx
  48ab06:	50                   	push   eax
  48ab07:	51                   	push   ecx
  48ab08:	8b cf                	mov    ecx,edi
  48ab0a:	ff d2                	call   edx
  48ab0c:	5f                   	pop    edi
  48ab0d:	5e                   	pop    esi
  48ab0e:	5b                   	pop    ebx
  48ab0f:	8b e5                	mov    esp,ebp
  48ab11:	5d                   	pop    ebp
  48ab12:	c2 0c 00             	ret    0xc
  48ab15:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  48ab18:	6a 06                	push   0x6
  48ab1a:	68 6c 6c bf 00       	push   0xbf6c6c
  48ab1f:	50                   	push   eax
  48ab20:	e8 99 7d 40 00       	call   0x8928be
  48ab25:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  48ab28:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  48ab2b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  48ab2e:	83 c4 0c             	add    esp,0xc
  48ab31:	53                   	push   ebx
  48ab32:	51                   	push   ecx
  48ab33:	52                   	push   edx
  48ab34:	8d 8c 38 00 fe ff ff 	lea    ecx,[eax+edi*1-0x200]
  48ab3b:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  48ab3e:	8b f8                	mov    edi,eax
  48ab40:	81 ff 05 40 00 80    	cmp    edi,0x80004005
  48ab46:	75 15                	jne    0x48ab5d
  48ab48:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  48ab4b:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  48ab4e:	51                   	push   ecx
  48ab4f:	52                   	push   edx
  48ab50:	68 74 6c bf 00       	push   0xbf6c74
  48ab55:	e8 06 30 26 00       	call   0x6edb60
  48ab5a:	83 c4 0c             	add    esp,0xc
  48ab5d:	8b c7                	mov    eax,edi
  48ab5f:	5f                   	pop    edi
  48ab60:	5e                   	pop    esi
  48ab61:	5b                   	pop    ebx
  48ab62:	8b e5                	mov    esp,ebp
```

**Native Assembly — 4FDA30 signed index / fallback (`VA 0x4fda30–0x4fda8c`，只以原件解碼；端點遵循指令邊界)：**

```asm
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55              	call   DWORD PTR [ebp-0x4]
```

## E43.8 — 原生兩層選服記錄 resolver：`5078C0` 回傳值、`507750` 回傳地址（本輪重大新增）

**研究問題**：E42 叫 `EBX/ESI local result`，這兩個值到底來自 Client 的何種資料？究竟是 wire result code、記錄欄位還是字串地址？

**N**：兩函式都由 `EAX` 為 base，`[EAX+0x18]` 為最外層群組數，`EAX+8` 為 group collection，呼叫 `542210` 取 group 迭代元素，再 `50B4B0` 轉成 group object；與第一個 key（`[EBP+8]`）相等才進入第二層。group 內 `[+0x40]` 起始、`[+0x44]` 結尾，差值由 magic division 轉成 `0x60` bytes record 計數，對 record `[+0]` 與第二個 key（`[EBP+0x0C]`）比較；每步 `add [EBP+8],0x60`（此處它已復用為 record offset）。兩層任一找不到回 EAX=0。

**精確不同返回值**：`0x5078C0` 命中時在 `0x507A12 mov eax,[ecx+offset+4]` **回傳 record+4 內的 32-bit 值**；`0x507750` 命中時在 `0x5078A3 lea eax,[ecx+offset+0x0C]` **回傳 record+0x0C 的地址**。因此 `0x66C090` 的 EBX 不是任意 HRESULT，而是記錄中一個 DWORD；ESI 是另一個**指向記錄內資料**的指標。

**實質更正 E42.9**：`EBX==4/5` 的分支不等於登入 result code=4/5，它可能是 record 的 role/flag/type，語義暫稱 field4；`ESI!=0` 意味有匹配 record，不能稱 resultB success。`record+0x0C` 內容可能被 Connect 視為 host 地址，但字元編碼與來源（S2C? 內建資源? UI 選項快取?）仍未證。未發現 matching record 時不走該 Connect 入口。

**資料 layout 暫定**：`Group { field0=lookup key; begin(+0x40), end(+0x44), ... }`；`Record[0x60] { key@0, field4@4, endpoint_data@0x0C, ... }`。此結構僅對目前 iterator 使用位置成立；不擅自決定其他欄位的正式名稱。

**剩餘缺口**：outer group / inner record 的實際 writer 和 wire source、record 是否 UTF-16 / ANSI/UTF-8、畫面上 row 指派與選服操作的唯一對應。

**Native Assembly — 507750 group+record 比對與 0x60 stride (`VA 0x507750–0x5077ba`，只以原件解碼；端點遵循指令邊界)：**

```asm
  507750:	55                   	push   ebp
  507751:	8b ec                	mov    ebp,esp
  507753:	83 ec 24             	sub    esp,0x24
  507756:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  507759:	57                   	push   edi
  50775a:	33 c9                	xor    ecx,ecx
  50775c:	33 ff                	xor    edi,edi
  50775e:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  507761:	85 d2                	test   edx,edx
  507763:	0f 84 45 01 00 00    	je     0x5078ae
  507769:	53                   	push   ebx
  50776a:	8d 58 08             	lea    ebx,[eax+0x8]
  50776d:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  507770:	56                   	push   esi
  507771:	57                   	push   edi
  507772:	8d 45 e8             	lea    eax,[ebp-0x18]
  507775:	8b cb                	mov    ecx,ebx
  507777:	e8 94 aa 03 00       	call   0x542210
  50777c:	8b f0                	mov    esi,eax
  50777e:	8d 45 dc             	lea    eax,[ebp-0x24]
  507781:	e8 2a 3d 00 00       	call   0x50b4b0
  507786:	8b 08                	mov    ecx,DWORD PTR [eax]
  507788:	85 c9                	test   ecx,ecx
  50778a:	74 02                	je     0x50778e
  50778c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  50778e:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507791:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  507794:	3b d0                	cmp    edx,eax
  507796:	77 02                	ja     0x50779a
  507798:	2b c2                	sub    eax,edx
  50779a:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  50779d:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  5077a0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5077a3:	39 02                	cmp    DWORD PTR [edx],eax
  5077a5:	74 11                	je     0x5077b8
  5077a7:	47                   	inc    edi
  5077a8:	3b 7d f4             	cmp    edi,DWORD PTR [ebp-0xc]
  5077ab:	72 c4                	jb     0x507771
  5077ad:	5e                   	pop    esi
  5077ae:	5b                   	pop    ebx
  5077af:	33 c0                	xor    eax,eax
  5077b1:	5f                   	pop    edi
  5077b2:	8b e5                	mov    esp,ebp
  5077b4:	5d                   	pop    ebp
  5077b5:	c2 08 00             	ret    0x8
  5077b8:	57                   	push   edi
  5077b9:	8d               	lea    eax,[ebp-0x24]
```

**Native Assembly — 507750 returns record+0x0C address (`VA 0x507810–0x5078b5`，只以原件解碼；端點遵循指令邊界)：**

```asm
  507810:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  507813:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  507816:	52                   	push   edx
  507817:	8d 45 dc             	lea    eax,[ebp-0x24]
  50781a:	e8 f1 a9 03 00       	call   0x542210
  50781f:	8b f0                	mov    esi,eax
  507821:	8d 45 e8             	lea    eax,[ebp-0x18]
  507824:	e8 87 3c 00 00       	call   0x50b4b0
  507829:	8b 08                	mov    ecx,DWORD PTR [eax]
  50782b:	85 c9                	test   ecx,ecx
  50782d:	74 02                	je     0x507831
  50782f:	8b 09                	mov    ecx,DWORD PTR [ecx]
  507831:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507834:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  507837:	3b d0                	cmp    edx,eax
  507839:	77 02                	ja     0x50783d
  50783b:	2b c2                	sub    eax,edx
  50783d:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507840:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507843:	8b 42 40             	mov    eax,DWORD PTR [edx+0x40]
  507846:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  507849:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  50784c:	39 0c 02             	cmp    DWORD PTR [edx+eax*1],ecx
  50784f:	74 14                	je     0x507865
  507851:	83 45 08 60          	add    DWORD PTR [ebp+0x8],0x60
  507855:	43                   	inc    ebx
  507856:	3b df                	cmp    ebx,edi
  507858:	72 b6                	jb     0x507810
  50785a:	5e                   	pop    esi
  50785b:	5b                   	pop    ebx
  50785c:	33 c0                	xor    eax,eax
  50785e:	5f                   	pop    edi
  50785f:	8b e5                	mov    esp,ebp
  507861:	5d                   	pop    ebp
  507862:	c2 08 00             	ret    0x8
  507865:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  507868:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  50786b:	50                   	push   eax
  50786c:	8d 45 dc             	lea    eax,[ebp-0x24]
  50786f:	e8 9c a9 03 00       	call   0x542210
  507874:	8b f0                	mov    esi,eax
  507876:	8d 45 e8             	lea    eax,[ebp-0x18]
  507879:	e8 32 3c 00 00       	call   0x50b4b0
  50787e:	8b 08                	mov    ecx,DWORD PTR [eax]
  507880:	85 c9                	test   ecx,ecx
  507882:	74 02                	je     0x507886
  507884:	8b 09                	mov    ecx,DWORD PTR [ecx]
  507886:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507889:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  50788c:	3b d0                	cmp    edx,eax
  50788e:	77 02                	ja     0x507892
  507890:	2b c2                	sub    eax,edx
  507892:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507895:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507898:	8b 4a 40             	mov    ecx,DWORD PTR [edx+0x40]
  50789b:	8d 04 5b             	lea    eax,[ebx+ebx*2]
  50789e:	5e                   	pop    esi
  50789f:	c1 e0 05             	shl    eax,0x5
  5078a2:	5b                   	pop    ebx
  5078a3:	8d 44 01 0c          	lea    eax,[ecx+eax*1+0xc]
  5078a7:	5f                   	pop    edi
  5078a8:	8b e5                	mov    esp,ebp
  5078aa:	5d                   	pop    ebp
  5078ab:	c2 08 00             	ret    0x8
  5078ae:	8b c1                	mov    eax,ecx
  5078b0:	5f                   	pop    edi
  5078b1:	8b e5                	mov    esp,ebp
  5078b3:	5d                   	pop    ebp
  5078b4:	c2               	ret    0x8
```

**Native Assembly — 5078C0 group entry (`VA 0x5078c0–0x507912`，只以原件解碼；端點遵循指令邊界)：**

```asm
  5078c0:	55                   	push   ebp
  5078c1:	8b ec                	mov    ebp,esp
  5078c3:	83 ec 24             	sub    esp,0x24
  5078c6:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  5078c9:	57                   	push   edi
  5078ca:	33 c9                	xor    ecx,ecx
  5078cc:	33 ff                	xor    edi,edi
  5078ce:	89 55 f4             	mov    DWORD PTR [ebp-0xc],edx
  5078d1:	85 d2                	test   edx,edx
  5078d3:	0f 84 45 01 00 00    	je     0x507a1e
  5078d9:	53                   	push   ebx
  5078da:	8d 58 08             	lea    ebx,[eax+0x8]
  5078dd:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  5078e0:	56                   	push   esi
  5078e1:	57                   	push   edi
  5078e2:	8d 45 e8             	lea    eax,[ebp-0x18]
  5078e5:	8b cb                	mov    ecx,ebx
  5078e7:	e8 24 a9 03 00       	call   0x542210
  5078ec:	8b f0                	mov    esi,eax
  5078ee:	8d 45 dc             	lea    eax,[ebp-0x24]
  5078f1:	e8 ba 3b 00 00       	call   0x50b4b0
  5078f6:	8b 08                	mov    ecx,DWORD PTR [eax]
  5078f8:	85 c9                	test   ecx,ecx
  5078fa:	74 02                	je     0x5078fe
  5078fc:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5078fe:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  507901:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  507904:	3b d0                	cmp    edx,eax
  507906:	77 02                	ja     0x50790a
  507908:	2b c2                	sub    eax,edx
  50790a:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  50790d:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507910:	8b 45              	mov    eax,DWORD PTR [ebp+0x8]
```

**Native Assembly — 5078C0 returns DWORD at record+0x04 (`VA 0x5079d5–0x507a24`，只以原件解碼；端點遵循指令邊界)：**

```asm
  5079d5:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  5079d8:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  5079db:	50                   	push   eax
  5079dc:	8d 45 dc             	lea    eax,[ebp-0x24]
  5079df:	e8 2c a8 03 00       	call   0x542210
  5079e4:	8b f0                	mov    esi,eax
  5079e6:	8d 45 e8             	lea    eax,[ebp-0x18]
  5079e9:	e8 c2 3a 00 00       	call   0x50b4b0
  5079ee:	8b 08                	mov    ecx,DWORD PTR [eax]
  5079f0:	85 c9                	test   ecx,ecx
  5079f2:	74 02                	je     0x5079f6
  5079f4:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5079f6:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5079f9:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  5079fc:	3b d0                	cmp    edx,eax
  5079fe:	77 02                	ja     0x507a02
  507a00:	2b c2                	sub    eax,edx
  507a02:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  507a05:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  507a08:	8b 4a 40             	mov    ecx,DWORD PTR [edx+0x40]
  507a0b:	8d 04 5b             	lea    eax,[ebx+ebx*2]
  507a0e:	5e                   	pop    esi
  507a0f:	c1 e0 05             	shl    eax,0x5
  507a12:	8b 44 01 04          	mov    eax,DWORD PTR [ecx+eax*1+0x4]
  507a16:	5b                   	pop    ebx
  507a17:	5f                   	pop    edi
  507a18:	8b e5                	mov    esp,ebp
  507a1a:	5d                   	pop    ebp
  507a1b:	c2 08 00             	ret    0x8
  507a1e:	8b c1                	mov    eax,ecx
  507a20:	5f                   	pop    edi
  507a21:	8b e5                	mov    esp,ebp
  507a23:	5d                   	pop    ebp
```

## E43.9 — 選服 record 真正流入 `0x4957C0`，並追初始 `F94294` gate

**研究問題**：有無原生跨函式連續 evidence 證明 selected record 真的決定 Connect 的指標參數？前置 `F94294` 來源如何？

**N**：`66C0BC` 從業務 UI-like object `[EBP+8]+0xF0/0xF4` 的二級指標 `+0xCC → +0xDC → +0x20` 取得兩個 match keys（缺值設 `-1`）；`66C124` 讀 `[FE1B54]` 這份選服資料容器。`66C12E` push keys、`66C132` call `5078C0` 得 `EBX=record.field4`；`66C13B…66C141` call `507750` 得 `ESI=&record[0x0C]`。當 `F94294!=0, EBX!=0, ESI!=0`，`66C1A0 push ESI; 66C1A7 call 4957C0`；第二個 branch `66C21D` 排除 EBX `4/0/5` 及 `ESI==0` 後，`66C240 push ESI; 66C247 call 4957C0`。因此已閉合 **client local selection keys → record matching → endpoint_data pointer → 4957C0 Connect** 的前半段，無須把它說成直接來自 S2C 0x13。

**新 guard 反查**：`.text` 原生唯一直接 `mov ds:0xF94294` 命中為 `0x4E16BF`，當時 `EBX=0` (0x4E15BF `xor ebx,ebx`)；它是初始化/重設成0，而非「證明此值永遠0」。在這次限定 direct-write 檢查沒有發現其他明確 `A3/89 1D/C7 05` 形式的正向 nonzero writer；**alias、memcpy、外部 module、vtable side effects 均未窮盡**。因此 `F94294!=0` 的 branch 在當次 native 發現之前仍需來源證明，不能假設它總會正常進入。第二個不依賴 `F94294` 的分支依 EBX field4 仍可能進 Connect。

**否證**：E42 將 EBX/ESI 稱為「本地判斷碼/結果A/結果B」屬不夠精確；現在可確定它們是資料表的值與地址而非兩筆相同 domain 的狀態碼。也不能保證 0x507750 地址可在並行更新中長期有效，還需 owner/lifetime 研究。

**剩餘缺口**：T03 `0x13` handler 對 `FE1B54` 或 record 的完整寫入鏈、F94294 非零 writer、精確 UI item selection 和 feedback/error branch、Server authoritative endpoint 源頭。

**Native Assembly — 66C090 選取兩個 key / 呼叫兩 resolver (`VA 0x66c0bc–0x66c14f`，只以原件解碼；端點遵循指令邊界)：**

```asm
  66c0bc:	8b f9                	mov    edi,ecx
  66c0be:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  66c0c1:	8b 81 f0 00 00 00    	mov    eax,DWORD PTR [ecx+0xf0]
  66c0c7:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c0cd:	85 c0                	test   eax,eax
  66c0cf:	74 1c                	je     0x66c0ed
  66c0d1:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c0d7:	85 c0                	test   eax,eax
  66c0d9:	75 09                	jne    0x66c0e4
  66c0db:	83 c8 ff             	or     eax,0xffffffff
  66c0de:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0e2:	eb 11                	jmp    0x66c0f5
  66c0e4:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c0e7:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0eb:	eb 08                	jmp    0x66c0f5
  66c0ed:	c7 44 24 10 ff ff ff 	mov    DWORD PTR [esp+0x10],0xffffffff
  66c0f4:	ff 
  66c0f5:	85 ff                	test   edi,edi
  66c0f7:	75 2b                	jne    0x66c124
  66c0f9:	8b 81 f4 00 00 00    	mov    eax,DWORD PTR [ecx+0xf4]
  66c0ff:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c105:	85 c0                	test   eax,eax
  66c107:	74 18                	je     0x66c121
  66c109:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c10f:	85 c0                	test   eax,eax
  66c111:	75 07                	jne    0x66c11a
  66c113:	83 c8 ff             	or     eax,0xffffffff
  66c116:	8b f8                	mov    edi,eax
  66c118:	eb 0a                	jmp    0x66c124
  66c11a:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c11d:	8b f8                	mov    edi,eax
  66c11f:	eb 03                	jmp    0x66c124
  66c121:	83 cf ff             	or     edi,0xffffffff
  66c124:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  66c128:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  66c12e:	57                   	push   edi
  66c12f:	50                   	push   eax
  66c130:	8b c6                	mov    eax,esi
  66c132:	e8 89 b7 e9 ff       	call   0x5078c0
  66c137:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  66c13b:	57                   	push   edi
  66c13c:	8b d8                	mov    ebx,eax
  66c13e:	51                   	push   ecx
  66c13f:	8b c6                	mov    eax,esi
  66c141:	e8 0a b6 e9 ff       	call   0x507750
  66c146:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  66c14d:	8b f0                	mov    esi,eax
```

**Native Assembly — 66C090 first conditional Connect path (`VA 0x66c17b–0x66c1ae`，只以原件解碼；端點遵循指令邊界)：**

```asm
  66c17b:	83 cf ff             	or     edi,0xffffffff
  66c17e:	83 3d 94 42 f9 00 00 	cmp    DWORD PTR ds:0xf94294,0x0
  66c185:	0f 84 92 00 00 00    	je     0x66c21d
  66c18b:	85 db                	test   ebx,ebx
  66c18d:	0f 84 8a 00 00 00    	je     0x66c21d
  66c193:	85 f6                	test   esi,esi
  66c195:	0f 84 1e 03 00 00    	je     0x66c4b9
  66c19b:	e8 e0 84 da ff       	call   0x414680
  66c1a0:	56                   	push   esi
  66c1a1:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c1a7:	e8 14 96 e2 ff       	call   0x4957c0
  66c1ac:	8b 55              	mov    edx,DWORD PTR [ebp+0x8]
```

**Native Assembly — 66C090 alternate Connect path / EBX=4/5 特例 (`VA 0x66c21d–0x66c272`，只以原件解碼；端點遵循指令邊界)：**

```asm
  66c21d:	83 fb 04             	cmp    ebx,0x4
  66c220:	74 52                	je     0x66c274
  66c222:	85 db                	test   ebx,ebx
  66c224:	0f 84 bc 01 00 00    	je     0x66c3e6
  66c22a:	83 fb 05             	cmp    ebx,0x5
  66c22d:	0f 84 bc 01 00 00    	je     0x66c3ef
  66c233:	85 f6                	test   esi,esi
  66c235:	0f 84 7e 02 00 00    	je     0x66c4b9
  66c23b:	e8 40 84 da ff       	call   0x414680
  66c240:	56                   	push   esi
  66c241:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c247:	e8 74 95 e2 ff       	call   0x4957c0
  66c24c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c24f:	8b 80 f0 00 00 00    	mov    eax,DWORD PTR [eax+0xf0]
  66c255:	e8 d6 02 dc ff       	call   0x42c530
  66c25a:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c25f:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c263:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c26a:	59                   	pop    ecx
  66c26b:	5f                   	pop    edi
  66c26c:	5e                   	pop    esi
  66c26d:	5b                   	pop    ebx
  66c26e:	8b e5                	mov    esp,ebp
  66c270:	5d                   	pop    ebp
  66c271:	c2               	ret    0x4
```

**Native Assembly — F94294 確認唯一 direct initializer=0 (`VA 0x4e16b3–0x4e16d5`，只以原件解碼；端點遵循指令邊界)：**

```asm
  4e16b3:	89 1d 8c 42 f9 00    	mov    DWORD PTR ds:0xf9428c,ebx
  4e16b9:	88 1d 90 42 f9 00    	mov    BYTE PTR ds:0xf94290,bl
  4e16bf:	89 1d 94 42 f9 00    	mov    DWORD PTR ds:0xf94294,ebx
  4e16c5:	89 1d 98 42 f9 00    	mov    DWORD PTR ds:0xf94298,ebx
  4e16cb:	c7 05 9c 42 f9 00 ff 	mov    DWORD PTR ds:0xf9429c,0xffff
  4e16d2:	ff 00 00 
```

## E43.10 — 傳輸的實際連線角色、first send/first receive 與本段強制停止

**研究問題**：在新的 local selected record→Connect 鏈已確立後，能否再把它向下閉合到**首筆 wire/首個 S2C 及選服 UI 反應**？

**N**：`0x4957C0` 以 `[EBP+8]` 取 caller `push ESI` 傳來的指標，對 network manager vptr+0x18 先傳 `port=0x20E0,key0,lane2`，再傳 `port=0x20DE,key2,lane2`；兩條的 host/input 指標完全相同。兩條 connect 都回 nonzero 才走下段老 key1 local `WORD 007E/2B` 與新 key0 local `WORD 0001` 起始、長 0x39 的 payload enqueue，key0/key2 分別會在 success path 有不同欄位保存。任一 Connect 返回 NULL 都有其 cleanup path，不應把 `4957C0` 完成當 socket 已寫出第一筆 wire。

**C**：`0x806CF0 → 0x807B40` 完成解碼後，`0x807D9E/0x807DAD` 按 Conn+A080 入 FC10D0；主循環 `0x804740` 可 pop 回呼。在條件 manager+4=C+8、vptr 匹配、lane=2、command index/override 匹配之下，`4930E0→48AAD0→494360→4FDA30` 可讓 handler 消費應用 payload。**沒有實際 wire trace**，沒法從 native local enqueue 推出「選服後第一筆一定是 key0 0001」或「0x0002 handler 必然第一個到達」。此外舊 key1 local `007E` 可能仍 pending，WSASend thread 排程與 I/O completion 非同步；跨 socket 全序不可由函式內行序代替。

**尚未閉合四層**：

- **Client 待逆向**：`6E4F90 p2` 是否等於 Client C+8；`F94294` alias positive writer；`FE1B54` 及 0x60 record 的 producer/wire 來源；Connect 成功後 per-key real first frame/first response、callback first command、close/retry 的全條件；T03 login `0x13`/實際 UI 對此 lookup 的 upstream writer。
- **Server 待開發**：根據**已確認**的 record/封包/回覆資料向 S00 提出可實作契約；原版 Server 的選服政策/驗證演算法未知，不應由 Client 猜補；原版 port literal `20DF/20E0/20DE` 不等於部署建議。
- **跨功能待整合**：T02 往下提供 socket/framing/兩層 handler 的限定證據；T03 提供登入結果、選服資料如何入表、畫面效果，T01/S00 對 RR5 之有限 claim 審查另行處理；本稿不能越權把 RR 設已認領或 accepted。
- **待遊玩驗證**：未執行原 Client、無官方 Server pcap、無實際 Socket first-send/first-recv 記錄和 UI 轉場 trace；static only。

**停止條件 B**：已完成全部十個有深度的單元，雖有重大新的 writer + choice record chain，**端到端 RR5 尚未達 A**；按當次要求必須停於 E43，不再續開第11單元。可在 E44 繼續追 `6E4F90 p2` 的精確 C+8 producer 與 `FE1B54` record writer/first S2C；建議先把兩個可證整鏈接成一個，再定向驗 wire，不重列 E40 packet FIFO 原稿。

**Native Assembly — 4957C0 兩條 network manager Connect 含 key/port/lane (`VA 0x4957c0–0x495817`，只以原件解碼；端點遵循指令邊界)：**

```asm
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
```

**Native Assembly — 舊 key1 local queued 007E / release flag (`VA 0x495817–0x495872`，只以原件解碼；端點遵循指令邊界)：**

```asm
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
```

**Native Assembly — 新 key0 local payload 起始欄位 (`VA 0x49587d–0x4958e9`，只以原件解碼；端點遵循指令邊界)：**

```asm
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00 00       	mov    ecx,0x1
  495884:	66 89 4d c0          	mov    WORD PTR [ebp-0x40],cx
  495888:	89 45 c6             	mov    DWORD PTR [ebp-0x3a],eax
  49588b:	89 45 ca             	mov    DWORD PTR [ebp-0x36],eax
  49588e:	89 45 ce             	mov    DWORD PTR [ebp-0x32],eax
  495891:	89 45 d2             	mov    DWORD PTR [ebp-0x2e],eax
  495894:	89 45 d6             	mov    DWORD PTR [ebp-0x2a],eax
  495897:	66 89 4d da          	mov    WORD PTR [ebp-0x26],cx
  49589b:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  49589e:	88 45 e0             	mov    BYTE PTR [ebp-0x20],al
  4958a1:	89 45 e1             	mov    DWORD PTR [ebp-0x1f],eax
  4958a4:	89 45 e5             	mov    DWORD PTR [ebp-0x1b],eax
  4958a7:	89 45 e9             	mov    DWORD PTR [ebp-0x17],eax
  4958aa:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  4958ad:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  4958b0:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  4958b3:	e8 e8 f2 f6 ff       	call   0x404ba0
  4958b8:	8b 90 e0 67 00 00    	mov    edx,DWORD PTR [eax+0x67e0]
  4958be:	89 55 c2             	mov    DWORD PTR [ebp-0x3e],edx
  4958c1:	e8 da f2 f6 ff       	call   0x404ba0
  4958c6:	6a 0a                	push   0xa
  4958c8:	05 e4 67 00 00       	add    eax,0x67e4
  4958cd:	50                   	push   eax
  4958ce:	8d 45 c6             	lea    eax,[ebp-0x3a]
  4958d1:	6a 0a                	push   0xa
  4958d3:	50                   	push   eax
  4958d4:	e8 25 e7 3f 00       	call   0x893ffe
  4958d9:	e8 c2 f2 f6 ff       	call   0x404ba0
  4958de:	6a 0a                	push   0xa
  4958e0:	05 fa 67 00 00       	add    eax,0x67fa
  4958e5:	50                   	push   eax
  4958e6:	8d 4d e5             	lea    ecx,[ebp-0x1b]
```

**Native Assembly — IOCP application queue 再次核對收件 (`VA 0x807d7f–0x807db2`，只以原件解碼；端點遵循指令邊界)：**

```asm
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
```

## 完整端到端狀態矩陣（嚴格分離已證和前置）

| 子流程 | 已證原生關係 | 尚缺的必要連結 | 不能對外宣稱 |
|---|---|---|---|
| Manager positive writer | 6E65A0→6E6871 寫 `[FBA7CC]+4`，6E6935 後調 6DFA50 | 寫入物件必然是 C+8、當次 dispatch gate | 「runtime callback 無條件已註冊」 |
| Client subobject receiver | C+8 vptr+30→490FE0，holder=C+148→4930E0 | manager source identity/動態覆寫 | 「每包必經 handler」 |
| Application inbound | IOCP→807B40→FC10D0→804740 pop | 正確 Conn key、first inbound、命令表覆寫 | 「handler index 就是第一個 S2C」 |
| Choice record | 兩 key→5078C0 field4、507750 record+0C address→66C090 ESI→4957C0 | table writer、T03 0x13 input、編碼 | 「原版 S2C 0x13 直接攜帶 host/port」 |
| Socket handoff | 4957C0 提交 key0/key2 + local queue，舊 key1 007E | 實際 WSASend 順序、成功/close ack、first reply | 「socket 已依程式順序完成 wire I/O」 |
| UI/遊玩 | 有結構化 Client gating/selection 資料 | UI 畫面事件、角色 roster/選角結果、真實測試 | 「已可遊玩」 |

## E42 勘誤與進度說明（不覆寫前段 blob）

1. E42 記錄 manager+4「正向 writer 尚未知」當時為**受搜尋模式限制的局部狀態**，不是已證全原件不存在。E43 從 `6E6871` 已找實際 writer；但存入指標「就是 C+8」仍是 U。
2. E42 將 `5078C0` / `507750` 回傳值概述成兩個 local result/code，且以 `EBX=4/5` 暫時對應判斷碼；E43 用原始 `507A12` / `5078A3` 證明更精確的 **record field4 / record+0C address**。它們分別是資料值與資料指標，並不能直接命名為登入結果碼。
3. E42 的 `F94294` positive gate 仍未找到初始以外的 direct writer；此處再附 direct initializer=0 的原件限制，不進行「永遠0」的非法全域否證。
4. 兩個新研究增量都**尚非 T01 FULL-PASS**；本地原稿不擅改 GitHub main/`extra/roy1`/RR claim，不產生 Git blob SHA。

## 證據重現方式與未覆蓋負面搜尋

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6e65a0 --stop-address=0x6e69a0 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6e4f90 --stop-address=0x6e5568 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x507750 --stop-address=0x507a24 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x66c090 --stop-address=0x66c274 Tartaros.bin
```

**工具/否證限制**：直接 `E8 rel32` 全 `.text` 來源候選不包括間接/vtable calls，雖每個本稿引用處均在原生有效指令邊界重新核對，仍不能由「只見一處 direct CALL」斷言無其他動態呼叫。`.text` 裡對 `F94294` 的 direct `mov ds:` 搜尋不排除 alias、memcpy 或外部 writer。`0x507750` 的 record+0x0C 地址沒有證明字串編碼或網路權威；first wire / first response 缺實際完整序列與 pcap 時維持 Unknown。原版 Client/Server 沒有執行／patch／附加。

---

**E43 交付**：本地一份完整研究原稿（本檔，十子段）；**未 Commit/Push**。若將來授權提交，僅能提交 `kr-extra-roy/` 完整原稿至 `extra/roy1`，提交前核對目標分支與遠端競爭修改；RR-0005 暫不認領。

