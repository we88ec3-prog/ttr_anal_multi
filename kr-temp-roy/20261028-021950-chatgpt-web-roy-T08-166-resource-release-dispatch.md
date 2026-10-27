# KR T08-166 — 7BE5F0 的 Resource／Binding 分支與指標槽所有權

- 研究者：`chatgpt-web roy`；本輪產檔時間：`20261028-021950` (Asia/Taipei)
- 基準：GitHub `main` 在本輪查核 commit `567e3ec82b826fafede56e2ee5e054a0b3ad798d`（提交前再查 HEAD）
- 原始來源：`Tartaros.bin` `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386 `.text` VA 0x401000/raw 0x400；完全唯讀
- 方法：GNU objdump 指定位址視窗；未啟動、附加或修改客戶端。`BYTE` 是目標 BIN 中直接的指令，`INFERENCE` 表示由機器碼推得的功能邊界
- 跨批次參考：`T08-153..164` 與 T01 整合來源審核，歷史報告是索引，不獨立替代原生 bytes

## 研究目的

7BE5F0 的 Resource／Binding 分支與指標槽所有權。此工作包聚焦正式 KR T08 的「物件建立／登記／移除資料介面」；不自行擴大成 AI 生成時機或遊戲規則。

## 主結論及推導
- `[BYTE]` `7BE5F0` 接受 `ESI` 指向的可寫 `DWORD* slot`。先檢查 `[ESI]`，零則立即 return。
- `[BYTE]` `[slot]` 指向 resource，取 `[resource]` 後把相應 `+60` 計數減一。具體 resource/owner 型別、counter 原生名稱仍未知。
- `[BYTE]` 當 resource `+74` 非零且 `+78` 非零時，推入 resource 與其 `*resource` 呼叫 `7DD1A0`；設 `EAX=1` 並將 `*slot=0`，提前返回。這一路沒有在本函式直接呼叫 `89120C`，不等於記憶體洩漏或不釋放。
- `[BYTE]` 其他分支若 `+74 >= 1`，呼叫 `7BE0F0`（需追其被呼叫者具體解除行為）；之後 `7BD850`、`89120C` 可能釋放 resource，最後將 `*slot=0`。這裡 `ECX`/`ESI`/`EDI` 存在非標準參數慣例，不能按典型 cdecl 假設。
- `[BYTE]` 兩種成功處理路徑都將 `*slot=0` 且回傳 `EAX=1`；零入參時直接 return，並未在此路徑初始化 EAX，因此不能承諾零入參也回傳 1。
- 本函式只清被傳入的 `+24` 欄位所在指標槽，不代表清 outer Actor 的 `+164` 陣列項。

## 限制
- `+60/+74/+78` 意義不得直接稱動畫時間、生命值、引用計數或完整 resource 種類；本輪只界定分支與 callsite。


## 可重現的機器碼摘錄

### VA `0x007be5f0..0x007be654`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007be5f0 <.text+0x3bd5f0>:
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
  7be647:	b8 01 00 00 00       	mov    eax,0x1
  7be64c:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be652:	c3                   	ret
  7be653:	cc                   	int3
```

### VA `0x007be0f0..0x007be160`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007be0f0 <.text+0x3bd0f0>:
  7be0f0:	55                   	push   ebp
  7be0f1:	8b ec                	mov    ebp,esp
  7be0f3:	51                   	push   ecx
  7be0f4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be0f7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7be0fa:	57                   	push   edi
  7be0fb:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  7be0fe:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  7be101:	3b f9                	cmp    edi,ecx
  7be103:	74 33                	je     0x7be138
  7be105:	56                   	push   esi
  7be106:	8b 37                	mov    esi,DWORD PTR [edi]
  7be108:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be10b:	85 c9                	test   ecx,ecx
  7be10d:	74 1d                	je     0x7be12c
  7be10f:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be111:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7be114:	ff d2                	call   edx
  7be116:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be119:	85 c9                	test   ecx,ecx
  7be11b:	74 0f                	je     0x7be12c
  7be11d:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be11f:	8b 10                	mov    edx,DWORD PTR [eax]
  7be121:	6a 01                	push   0x1
  7be123:	ff d2                	call   edx
  7be125:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  7be12c:	83 c7 04             	add    edi,0x4
  7be12f:	3b 7d fc             	cmp    edi,DWORD PTR [ebp-0x4]
  7be132:	75 d2                	jne    0x7be106
  7be134:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be137:	5e                   	pop    esi
  7be138:	c7 40 74 00 00 00 00 	mov    DWORD PTR [eax+0x74],0x0
  7be13f:	5f                   	pop    edi
  7be140:	8b e5                	mov    esp,ebp
  7be142:	5d                   	pop    ebp
  7be143:	c2 04 00             	ret    0x4
  7be146:	cc                   	int3
  7be147:	cc                   	int3
  7be148:	cc                   	int3
  7be149:	cc                   	int3
  7be14a:	cc                   	int3
  7be14b:	cc                   	int3
  7be14c:	cc                   	int3
  7be14d:	cc                   	int3
  7be14e:	cc                   	int3
  7be14f:	cc                   	int3
  7be150:	55                   	push   ebp
  7be151:	8b ec                	mov    ebp,esp
  7be153:	83 e4 f8             	and    esp,0xfffffff8
  7be156:	81 ec 04 01 00 00    	sub    esp,0x104
  7be15c:	d9 ee                	fldz
  7be15e:	53                   	push   ebx
  7be15f:	8b                   	.byte 0x8b
```

## 工作流程偽碼（受限版本）

```cpp
// 非原生原始碼，僅表達本輪已核對的條件與未知；不直接部署。
void T08_166_bounded_study() {
    // See machine-code windows and branch conditions above.
    // No claim of full execution, all callers, or server authority.
}
```

## 證據等級與未解條件

- 直接原始證據：上列 VA 視窗 machine code，由指定 SHA 的 PE bytes 產生。
- 有條件推論：call 前後欄位訪問所推之 ownership/cleanup 次序；虛擬函式未解析為固定 callee。
- 未驗證：執行期頻率、實體是否存在其他 owner、全部 caller 集、TCP/P2P authority、場景與 AI 決策、失敗回滾。
- 不修改 repo `task.json`、catalog、其他 Agent 筆記；新稿僅擬放 `kr-temp-roy/`。