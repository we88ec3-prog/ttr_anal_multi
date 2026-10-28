# T10-088 — 輸入 producer／動作 consumer 缺口審核與可驗證接續矩陣

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 整體結果與嚴格驗收

* 已確認：KR `KeyMapping.xml` Type0 `MapButton=13..16` 對 `Key=44..47`；type1 MapButton 13..16 另指向 Key36..39。映射 ID ≠ action opcode。
* 已確認：bank0/1 的 0x280-byte 欄位可複製至 bank2；外部設定也可逐 slot 回填 bank2（T10-083）。但不能證明玩家現用的配置模式／Type1 Key45 fallback。
* 已確認：phase reader 普通 0..39 使用 `0xFB9004+ID`，特殊 10001..19999 的查詢使用 `0xFDF630` 節點，`0x6D4A30` 可對兩類執行清零。
* 已確認：phase1/3 進入 `0x5961C0` 的多態 slot；`0xFB73E8` 非零情況在該函式限制輸入 ID 13/14；`0x5A46xx` 使用同一全域旗標控制 `[esi+0x154]` 變化並以 `0x5A55E0` 進入 mode 1/2。
* 未確認：本機輸入 producer 是否採 DirectInput DIK 掃描碼及其翻譯機制、phase=1/3 的任何**非零** writer、vtable `+0xEC/+0xF0` 所屬 class／具體虛擬覆寫、動作 motion consumer、Z 持按與連擊／V tap-hold／queue/cancel 規則與時窗。這些不能以 AI `CHAIN_WINDOW=.65` 或 `>500ms` 假設填補。

## 對下一段 T10-089 的精確實驗路線

1. 以 `0x490DFC`、`0x58A607` 追 `0x6D4A30` 的事件容器參數，定位究竟是「設備輪詢→事件節點」或清除出口，查 node 的構造和非零 writer。
2. 以 `[0xFB73E8]` 真實物件所屬 `0xFB73C0` 及其鄰接容器追 alias writer；絕對位址 xref 已僅見初始化清零 `0x560239`，其他常數讀取不代表缺少 runtime 修改。
3. 從 `0x5961C0` dispatch target 追虛擬表具體指標與 override，避免將 vtable **byte offsets** 與 object member offset 混同；只有證實實例來源後才能跨 T08/T09/T11 引用。
4. 抽樣檢查 `0x5CD68A`/`0x5CE5BA`/`0x62B5BA`/`0x650E96` 的 `0x6D4DC0` 返回值用途，標註 UI 配置消費者與真正 runtime 消費者。
5. 需在實際原始證據確認 writer、motion、連段／取消分支，才能把任何 T10 功能列 native_complete；現在只屬 bounded native review。

## 額外 BIN xref 片段

### VA 0x00490DE0..0x00490E15

```asm
  490de0:	e8 35 15 40 00       	call   0x89231a
  490de5:	83 c4 04             	add    esp,0x4
  490de8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  490def:	0f b6 05 fa ad fa 00 	movzx  eax,BYTE PTR ds:0xfaadfa
  490df6:	68 d8 5c f9 00       	push   0xf95cd8
  490dfb:	50                   	push   eax
  490dfc:	e8 2f 3c 24 00       	call   0x6d4a30
  490e01:	83 c4 08             	add    esp,0x8
  490e04:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  490e07:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  490e0e:	59                   	pop    ecx
  490e0f:	5b                   	pop    ebx
  490e10:	8b e5                	mov    esp,ebp
  490e12:	5d                   	pop    ebp
  490e13:	c3                   	ret
  490e14:	cc                   	int3
```

### VA 0x0058A5ED..0x0058A620

```asm
  58a5ef:	89 36                	mov    DWORD PTR [esi],esi
  58a5f1:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  58a5f5:	89 76 04             	mov    DWORD PTR [esi+0x4],esi
  58a5f8:	8d 44 24 14          	lea    eax,[esp+0x14]
  58a5fc:	50                   	push   eax
  58a5fd:	6a 01                	push   0x1
  58a5ff:	c7 44 24 50 03 00 00 	mov    DWORD PTR [esp+0x50],0x3
  58a606:	00 
  58a607:	e8 24 a4 14 00       	call   0x6d4a30
  58a60c:	89 bb 3c 01 00 00    	mov    DWORD PTR [ebx+0x13c],edi
  58a612:	89 bb 40 01 00 00    	mov    DWORD PTR [ebx+0x140],edi
  58a618:	89 bb 44 01 00 00    	mov    DWORD PTR [ebx+0x144],edi
  58a61e:	66 89 bb 48 01 00 00 	mov    WORD PTR [ebx+0x148],di
```

### VA 0x005A4614..0x005A4671

```asm
  5a4614:	39 1d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,ebx
  5a461a:	8a 86 54 01 00 00    	mov    al,BYTE PTR [esi+0x154]
  5a4620:	0f 95 c3             	setne  bl
  5a4623:	84 c0                	test   al,al
  5a4625:	75 35                	jne    0x5a465c
  5a4627:	84 db                	test   bl,bl
  5a4629:	74 2d                	je     0x5a4658
  5a462b:	6a 02                	push   0x2
  5a462d:	32 c9                	xor    cl,cl
  5a462f:	8b d6                	mov    edx,esi
  5a4631:	e8 aa 0f 00 00       	call   0x5a55e0
  5a4636:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  5a4639:	81 ea 3b 01 00 00    	sub    edx,0x13b
  5a463f:	56                   	push   esi
  5a4640:	b8 05 00 00 00       	mov    eax,0x5
  5a4645:	e8 16 11 00 00       	call   0x5a5760
  5a464a:	ba 66 00 00 00       	mov    edx,0x66
  5a464f:	8b ce                	mov    ecx,esi
  5a4651:	e8 4a 11 00 00       	call   0x5a57a0
  5a4656:	eb 13                	jmp    0x5a466b
  5a4658:	84 c0                	test   al,al
  5a465a:	74 0f                	je     0x5a466b
  5a465c:	84 db                	test   bl,bl
  5a465e:	75 0b                	jne    0x5a466b
  5a4660:	6a 01                	push   0x1
  5a4662:	32 c9                	xor    cl,cl
  5a4664:	8b d6                	mov    edx,esi
  5a4666:	e8 75 0f 00 00       	call   0x5a55e0
  5a466b:	88 9e 54 01 00 00    	mov    BYTE PTR [esi+0x154],bl
```

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。