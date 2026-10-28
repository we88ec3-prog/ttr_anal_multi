# T08-184 — 正式 0007 實體登記／移除與復用池所有權邊界

- Task：T08；作者：`chatgpt-web roy`；研究時間：`2026-10-28T10:02:22.096809+08:00`（Asia/Taipei）。
- 第一手來源：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算）；唯讀分析、不啟動遊戲。
- PE `.text` 映射：VA `0x00401000` / raw `0x400`；本批對 `.text` 使用 `raw = VA - 0x401000 + 0x400`，**不對其他節區或歷史 flat 位址套公式**。
- 承接：T08-177～180；正式 T08 Scope `0007` 的實體建立、登記、移除資料介面。資源層屬上／下游證據，不推論伺服器波次、生成規則與 AI。
- 界線：純靜態指令證據；未執行 runtime、未證實所有間接邊、異常安全性或 thread interleaving。下列未具原始符號的名稱均為暫稱。

## 範圍、方法與證據等級

本段只以原始 PE `.text` bytes 獨立抽樣核對；舊 Markdown 只提供地址候選。**已確認**限於本節錄機器碼與有界資料流；**合理推測**須明列前提；**尚待驗證**包括間接呼叫、物件類型和 runtime。

## 本段介面判定

1. `0x004DFF30` 是 actor registration，`0x004DFBC0` 為 key-based removal，`0x004DFE90` 是多項清理；其原始直接呼叫位址與 `0x007DD1F0` drain 不同（前段 T08-180 列表）。本段再把 `0x007DCFB0` resource acquire 納入**間接生命週期**，仍未定位一條由 actor tree owner 直接傳到 manager pool owner 的完整多跳資料流。
2. 與 actor/元件相關的 `0x004C7DB4`、`0x004C838C` 等已觀測 `call 0x007BE5F0`，資源 release 經 `0x007BE60F` 到 `0x007DD1A0`，屬**具局部 caller/callee 支援的接口連接**。不能把 `0x007BE5F0` 的 `resource+0x20` 與場景 `actor+0x20` 視為同欄位。
3. 新增 `0x007DCFB0` 復用路徑，建立「release-> enqueue-> reuse 或 drain」的雙出口模型。不能因此推定每次 actor remove 都會立即 delete resource、亦不能推定資源永不 free。
4. `0x007DD100` 僅對 manager payload 的計數歸零處置；與場景 entity `0x004DFBC0` 的索引刪除不等價。尚缺 actor component 持有者 -> resource -> manager owner 的原始型別和參照錨點。

## 正式介面矩陣

| 介面 | 已知主責 | 與 pool 的已確認關係 | 未解 |
|---|---|---|---|
| `0x004DFF30` | Actor registry add | 尚未見直接 `E8` 至 `0x007DD1F0` | 確切 component resource writer |
| `0x004DFBC0` | Actor key removal | 可經 component teardown 間接涉及 `0x007BE5F0`（需逐實例定型） | 單次移除覆蓋哪些資源 |
| `0x004DFE90` | Registry-wide cleanup | 無直接 drain 呼叫點 | 是否同時觸及所有 resource owner |
| `0x007BE5F0` | Resource release facade | `0x007DD1A0` 延遲／立即釋放生產者 | owner 來源／多型執行 |
| `0x007DCFB0` | Resource acquire/reuse | pop `+7C/+80`, empty -> allocate `0x7C` | 跨 frame 存活、鎖競態 |
| `0x007DD1F0` | Manager drain | release or cleanup pending pointer slots | runtime 頻率與其它 consumer |

## 未可升級為原生結論的項目

- 玩家／怪物生成的 server 時點、位置、波次、AI 及死亡語義，仍屬 T02/T06/T07/T16 等跨 Task 範圍，不可由本段的 allocator 斷言。
- 未有 runtime heap trace、全部 vtable target 解碼、或完整 error/unwind CFG。本文件不宣稱 C++ 完整原碼還原。

## 全 `.text` E8 rel32 位移核對

掃描 `.text` raw bytes 中每一個 `E8 xx xx xx xx`，目標依 `callsite VA + 5 + sign_extend(rel32)` 計算；屬**候選 byte 命中**，部分可能是資料/非指令邊界。若未逐一走 CFG，不能聲稱完整 caller 集合，更不能排除 `FF /2` 或虛表間接呼叫。

- **0x004DFF30** — 5 個候選：`0x004A11B6` (`e875ed0300`), `0x004AA222` (`e8095d0300`), `0x004AEC03` (`e828130300`), `0x004AF4F7` (`e8340a0300`), `0x004B2F83` (`e8a8cf0200`)
- **0x004DFBC0** — 2 個候選：`0x004AA057` (`e8645b0300`), `0x004B2AC2` (`e8f9d00200`)
- **0x004DFE90** — 11 個候選：`0x00424448` (`e843ba0b00`), `0x004BA9C9` (`e8c2540200`), `0x004BB62A` (`e861480200`), `0x004BBCF0` (`e89b410200`), `0x004BC423` (`e8683a0200`), `0x004BCCDA` (`e8b1310200`), `0x004BE5AF` (`e8dc180200`), `0x004C1706` (`e885e70100`), `0x004C33E6` (`e8a5ca0100`), `0x004C4BE3` (`e8a8b20100`), `0x004C5AA8` (`e8e3a30100`)
- **0x007BE5F0** — 42 個候選：`0x004C7C8F` (`e85c692f00`), `0x004C7DB4` (`e837682f00`), `0x004C838C` (`e85f622f00`), `0x004C83AF` (`e83c622f00`), `0x004C8411` (`e8da612f00`), `0x004C902C` (`e8bf552f00`), `0x004C9066` (`e885552f00`), `0x004C9074` (`e877552f00`), `0x004CAFF4` (`e8f7352f00`), `0x004CC867` (`e8841d2f00`), `0x004CC89A` (`e8511d2f00`), `0x004CDDF1` (`e8fa072f00`), `0x004CE927` (`e8c4fc2e00`), `0x004CEC2C` (`e8bff92e00`), `0x004CECA7` (`e844f92e00`), `0x004D0330` (`e8bbe22e00`), `0x004D1333` (`e8b8d22e00`), `0x004D16B8` (`e833cf2e00`), `0x004D2449` (`e8a2c12e00`), `0x004D2497` (`e854c12e00`), `0x004D2522` (`e8c9c02e00`), `0x004D25A6` (`e845c02e00`), `0x004D2632` (`e8b9bf2e00`), `0x004D26BE` (`e82dbf2e00`), `0x004D2772` (`e879be2e00`), `0x004D287D` (`e86ebd2e00`), `0x00543B98` (`e853aa2700`), `0x00543FDF` (`e80ca62700`), `0x0054480B` (`e8e09d2700`), `0x00550B7D` (`e86eda2600`), `0x00550DAE` (`e83dd82600`), `0x00550EF9` (`e8f2d62600`), `0x00550EFE` (`e8edd62600`), `0x00550FB5` (`e836d62600`), `0x00552380` (`e86bc22600`), `0x007A5361` (`e88a920100`), `0x007A69A9` (`e8427c0100`), `0x007A78AA` (`e8416d0100`), `0x007A7A79` (`e8726b0100`), `0x007A7ACE` (`e81d6b0100`), `0x007A8DAC` (`e83f580100`), `0x007FF79A` (`e851eefbff`)
- **0x007DD1A0** — 2 個候選：`0x007A8741` (`e85a4a0300`), `0x007BE60F` (`e88ceb0100`)
- **0x007DCFB0** — 2 個候選：`0x007B8275` (`e8364d0200`), `0x007F6FDC` (`e8cf5ffeff`)

## 未解問題及下一步

1. 在 Ghidra 的真實函式邊界與完整 CFG 驗證 byte-scan E8 候選。
2. 逐一追蹤 owner/node payload 的配置來源、具體型別、vptr、直接／間接 caller 與可能的不同實例。
3. 核對 `+0x44/+0x5C/+0x60/+0x64/+0x7C/+0x80` 的各種引用，嚴禁跨型別 offsets 混合。
4. 未經 runtime 不宣稱跨 frame 消費頻率或 lock-free 安全性。

## 附錄：原始 BIN 指令節錄

### Raw BIN disassembly: `0x004DFF30..0x004E0030`

```asm
004dff30 <.text+0xdef30>:
  4dff30:	55                   	push   %ebp
  4dff31:	8b ec                	mov    %esp,%ebp
  4dff33:	83 ec 10             	sub    $0x10,%esp
  4dff36:	53                   	push   %ebx
  4dff37:	8b 5d 08             	mov    0x8(%ebp),%ebx
  4dff3a:	56                   	push   %esi
  4dff3b:	57                   	push   %edi
  4dff3c:	8b f8                	mov    %eax,%edi
  4dff3e:	85 ff                	test   %edi,%edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   $0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzwl 0x4(%edi),%eax
  4dff50:	8d 4d 08             	lea    0x8(%ebp),%ecx
  4dff53:	89 45 08             	mov    %eax,0x8(%ebp)
  4dff56:	8d 73 08             	lea    0x8(%ebx),%esi
  4dff59:	51                   	push   %ecx
  4dff5a:	8d 45 f8             	lea    -0x8(%ebp),%eax
  4dff5d:	8b ce                	mov    %esi,%ecx
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    -0x8(%ebp),%edx
  4dff67:	3b 53 0c             	cmp    0xc(%ebx),%edx
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    0x8(%ebp),%eax
  4dff6f:	89 7d f8             	mov    %edi,-0x8(%ebp)
  4dff72:	8d 7d f4             	lea    -0xc(%ebp),%edi
  4dff75:	89 45 f4             	mov    %eax,-0xc(%ebp)
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   %eax
  4dff7e:	56                   	push   %esi
  4dff7f:	8d 75 f4             	lea    -0xc(%ebp),%esi
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    %edi
  4dff88:	5e                   	pop    %esi
  4dff89:	5b                   	pop    %ebx
  4dff8a:	8b e5                	mov    %ebp,%esp
  4dff8c:	5d                   	pop    %ebp
  4dff8d:	c2 04 00             	ret    $0x4
  4dff90:	8b 4d 08             	mov    0x8(%ebp),%ecx
  4dff93:	51                   	push   %ecx
  4dff94:	68 f0 ce c0 00       	push   $0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    $0x8,%esp
  4dffa1:	5f                   	pop    %edi
  4dffa2:	5e                   	pop    %esi
  4dffa3:	5b                   	pop    %ebx
  4dffa4:	8b e5                	mov    %ebp,%esp
  4dffa6:	5d                   	pop    %ebp
  4dffa7:	c2 04 00             	ret    $0x4
  4dffaa:	cc                   	int3
  4dffab:	cc                   	int3
  4dffac:	cc                   	int3
  4dffad:	cc                   	int3
  4dffae:	cc                   	int3
  4dffaf:	cc                   	int3
  4dffb0:	55                   	push   %ebp
  4dffb1:	8b ec                	mov    %esp,%ebp
  4dffb3:	83 e4 f8             	and    $0xfffffff8,%esp
  4dffb6:	6a ff                	push   $0xffffffff
  4dffb8:	68 de ed 93 00       	push   $0x93edde
  4dffbd:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  4dffc3:	50                   	push   %eax
  4dffc4:	83 ec 10             	sub    $0x10,%esp
  4dffc7:	53                   	push   %ebx
  4dffc8:	56                   	push   %esi
  4dffc9:	57                   	push   %edi
  4dffca:	a1 20 1f d6 00       	mov    0xd61f20,%eax
  4dffcf:	33 c4                	xor    %esp,%eax
  4dffd1:	50                   	push   %eax
  4dffd2:	8d 44 24 20          	lea    0x20(%esp),%eax
  4dffd6:	64 a3 00 00 00 00    	mov    %eax,%fs:0x0
  4dffdc:	8b f1                	mov    %ecx,%esi
  4dffde:	8b 5d 08             	mov    0x8(%ebp),%ebx
  4dffe1:	8b 3e                	mov    (%esi),%edi
  4dffe3:	b8 01 00 00 00       	mov    $0x1,%eax
  4dffe8:	84 05 90 43 f9 00    	test   %al,0xf94390
  4dffee:	75 28                	jne    0x4e0018
  4dfff0:	09 05 90 43 f9 00    	or     %eax,0xf94390
  4dfff6:	c7 44 24 28 00 00 00 	movl   $0x0,0x28(%esp)
  4dfffd:	00 
  4dfffe:	e8 8d 15 00 00       	call   0x4e1590
  4e0003:	68 80 cc bc 00       	push   $0xbccc80
  4e0008:	e8 0d 23 3b 00       	call   0x89231a
  4e000d:	83 c4 04             	add    $0x4,%esp
  4e0010:	c7 44 24 28 ff ff ff 	movl   $0xffffffff,0x28(%esp)
  4e0017:	ff 
  4e0018:	3b 3d 30 39 f9 00    	cmp    0xf93930,%edi
  4e001e:	75 06                	jne    0x4e0026
  4e0020:	89 b3 f8 00 00 00    	mov    %esi,0xf8(%ebx)
  4e0026:	8b 06                	mov    (%esi),%eax
  4e0028:	89 74 24 18          	mov    %esi,0x18(%esp)
  4e002c:	8d 73 18             	lea    0x18(%ebx),%esi
  4e002f:	8d             	lea    0x14(%esp),%edi
```

### Raw BIN disassembly: `0x004DFBC0..0x004DFCB0`

```asm
004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   %ebp
  4dfbc1:	8b ec                	mov    %esp,%ebp
  4dfbc3:	51                   	push   %ecx
  4dfbc4:	53                   	push   %ebx
  4dfbc5:	56                   	push   %esi
  4dfbc6:	8b f0                	mov    %eax,%esi
  4dfbc8:	57                   	push   %edi
  4dfbc9:	8d 45 08             	lea    0x8(%ebp),%eax
  4dfbcc:	8d 5e 08             	lea    0x8(%esi),%ebx
  4dfbcf:	50                   	push   %eax
  4dfbd0:	8d 45 fc             	lea    -0x4(%ebp),%eax
  4dfbd3:	8b cb                	mov    %ebx,%ecx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    -0x4(%ebp),%edi
  4dfbdd:	3b 7e 0c             	cmp    0xc(%esi),%edi
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    %esi,%esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    0xfba7a4,%ecx
  4dfbea:	8b 11                	mov    (%ecx),%edx
  4dfbec:	8b 42 1c             	mov    0x1c(%edx),%eax
  4dfbef:	56                   	push   %esi
  4dfbf0:	ff d0                	call   *%eax
  4dfbf2:	46                   	inc    %esi
  4dfbf3:	83 fe 03             	cmp    $0x3,%esi
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    0x10(%edi),%ecx
  4dfbfb:	8b 11                	mov    (%ecx),%edx
  4dfbfd:	8b 42 14             	mov    0x14(%edx),%eax
  4dfc00:	ff d0                	call   *%eax
  4dfc02:	8b 4f 10             	mov    0x10(%edi),%ecx
  4dfc05:	85 c9                	test   %ecx,%ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    (%ecx),%edx
  4dfc0b:	8b 02                	mov    (%edx),%eax
  4dfc0d:	6a 01                	push   $0x1
  4dfc0f:	ff d0                	call   *%eax
  4dfc11:	c7 47 10 00 00 00 00 	movl   $0x0,0x10(%edi)
  4dfc18:	57                   	push   %edi
  4dfc19:	8d 4d 08             	lea    0x8(%ebp),%ecx
  4dfc1c:	51                   	push   %ecx
  4dfc1d:	53                   	push   %ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    %edi
  4dfc24:	5e                   	pop    %esi
  4dfc25:	5b                   	pop    %ebx
  4dfc26:	8b e5                	mov    %ebp,%esp
  4dfc28:	5d                   	pop    %ebp
  4dfc29:	c2 04 00             	ret    $0x4
  4dfc2c:	cc                   	int3
  4dfc2d:	cc                   	int3
  4dfc2e:	cc                   	int3
  4dfc2f:	cc                   	int3
  4dfc30:	55                   	push   %ebp
  4dfc31:	8b ec                	mov    %esp,%ebp
  4dfc33:	51                   	push   %ecx
  4dfc34:	53                   	push   %ebx
  4dfc35:	57                   	push   %edi
  4dfc36:	8d 45 08             	lea    0x8(%ebp),%eax
  4dfc39:	8d 5e 18             	lea    0x18(%esi),%ebx
  4dfc3c:	50                   	push   %eax
  4dfc3d:	8d 45 fc             	lea    -0x4(%ebp),%eax
  4dfc40:	8b cb                	mov    %ebx,%ecx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    -0x4(%ebp),%edi
  4dfc4a:	3b 7e 1c             	cmp    0x1c(%esi),%edi
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b 86 f8 00 00 00    	mov    0xf8(%esi),%eax
  4dfc55:	85 c0                	test   %eax,%eax
  4dfc57:	74 11                	je     0x4dfc6a
  4dfc59:	8b 08                	mov    (%eax),%ecx
  4dfc5b:	3b 4d 08             	cmp    0x8(%ebp),%ecx
  4dfc5e:	75 0a                	jne    0x4dfc6a
  4dfc60:	c7 86 f8 00 00 00 00 	movl   $0x0,0xf8(%esi)
  4dfc67:	00 00 00 
  4dfc6a:	8b 47 10             	mov    0x10(%edi),%eax
  4dfc6d:	85 c0                	test   %eax,%eax
  4dfc6f:	74 09                	je     0x4dfc7a
  4dfc71:	50                   	push   %eax
  4dfc72:	e8 95 15 3b 00       	call   0x89120c
  4dfc77:	83 c4 04             	add    $0x4,%esp
  4dfc7a:	57                   	push   %edi
  4dfc7b:	8d 55 08             	lea    0x8(%ebp),%edx
  4dfc7e:	52                   	push   %edx
  4dfc7f:	53                   	push   %ebx
  4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
  4dfc85:	5f                   	pop    %edi
  4dfc86:	5b                   	pop    %ebx
  4dfc87:	8b e5                	mov    %ebp,%esp
  4dfc89:	5d                   	pop    %ebp
  4dfc8a:	c2 04 00             	ret    $0x4
  4dfc8d:	cc                   	int3
  4dfc8e:	cc                   	int3
  4dfc8f:	cc                   	int3
  4dfc90:	55                   	push   %ebp
  4dfc91:	8b ec                	mov    %esp,%ebp
  4dfc93:	51                   	push   %ecx
  4dfc94:	56                   	push   %esi
  4dfc95:	57                   	push   %edi
  4dfc96:	8d 78 08             	lea    0x8(%eax),%edi
  4dfc99:	8b 47 04             	mov    0x4(%edi),%eax
  4dfc9c:	8b 30                	mov    (%eax),%esi
  4dfc9e:	3b f0                	cmp    %eax,%esi
  4dfca0:	0f 84 89 00 00 00    	je     0x4dfd2f
  4dfca6:	eb 08                	jmp    0x4dfcb0
  4dfca8:	8d a4 24 00 00 00 00 	lea    0x0(%esp),%esp
  4dfcaf:	90                   	nop
```

### Raw BIN disassembly: `0x004DFE90..0x004DFF70`

```asm
004dfe90 <.text+0xdee90>:
  4dfe90:	55                   	push   %ebp
  4dfe91:	8b ec                	mov    %esp,%ebp
  4dfe93:	53                   	push   %ebx
  4dfe94:	8b 5d 08             	mov    0x8(%ebp),%ebx
  4dfe97:	8b 43 0c             	mov    0xc(%ebx),%eax
  4dfe9a:	56                   	push   %esi
  4dfe9b:	8b 30                	mov    (%eax),%esi
  4dfe9d:	57                   	push   %edi
  4dfe9e:	3b f0                	cmp    %eax,%esi
  4dfea0:	74 65                	je     0x4dff07
  4dfea2:	8b 7e 10             	mov    0x10(%esi),%edi
  4dfea5:	85 ff                	test   %edi,%edi
  4dfea7:	74 13                	je     0x4dfebc
  4dfea9:	8b 07                	mov    (%edi),%eax
  4dfeab:	8b 50 14             	mov    0x14(%eax),%edx
  4dfeae:	8b cf                	mov    %edi,%ecx
  4dfeb0:	ff d2                	call   *%edx
  4dfeb2:	8b 07                	mov    (%edi),%eax
  4dfeb4:	8b 10                	mov    (%eax),%edx
  4dfeb6:	6a 01                	push   $0x1
  4dfeb8:	8b cf                	mov    %edi,%ecx
  4dfeba:	ff d2                	call   *%edx
  4dfebc:	80 7e 15 00          	cmpb   $0x0,0x15(%esi)
  4dfec0:	75 40                	jne    0x4dff02
  4dfec2:	8b 46 08             	mov    0x8(%esi),%eax
  4dfec5:	80 78 15 00          	cmpb   $0x0,0x15(%eax)
  4dfec9:	75 16                	jne    0x4dfee1
  4dfecb:	8b f0                	mov    %eax,%esi
  4dfecd:	8b 06                	mov    (%esi),%eax
  4dfecf:	80 78 15 00          	cmpb   $0x0,0x15(%eax)
  4dfed3:	75 2d                	jne    0x4dff02
  4dfed5:	8b f0                	mov    %eax,%esi
  4dfed7:	8b 06                	mov    (%esi),%eax
  4dfed9:	80 78 15 00          	cmpb   $0x0,0x15(%eax)
  4dfedd:	74 f6                	je     0x4dfed5
  4dfedf:	eb 21                	jmp    0x4dff02
  4dfee1:	8b 46 04             	mov    0x4(%esi),%eax
  4dfee4:	80 78 15 00          	cmpb   $0x0,0x15(%eax)
  4dfee8:	75 16                	jne    0x4dff00
  4dfeea:	8d 9b 00 00 00 00    	lea    0x0(%ebx),%ebx
  4dfef0:	3b 70 08             	cmp    0x8(%eax),%esi
  4dfef3:	75 0b                	jne    0x4dff00
  4dfef5:	8b f0                	mov    %eax,%esi
  4dfef7:	8b 40 04             	mov    0x4(%eax),%eax
  4dfefa:	80 78 15 00          	cmpb   $0x0,0x15(%eax)
  4dfefe:	74 f0                	je     0x4dfef0
  4dff00:	8b f0                	mov    %eax,%esi
  4dff02:	3b 73 0c             	cmp    0xc(%ebx),%esi
  4dff05:	75 9b                	jne    0x4dfea2
  4dff07:	8d 7b 08             	lea    0x8(%ebx),%edi
  4dff0a:	e8 41 39 34 00       	call   0x823850
  4dff0f:	8b 0d a4 a7 fb 00    	mov    0xfba7a4,%ecx
  4dff15:	8b 01                	mov    (%ecx),%eax
  4dff17:	8b 50 14             	mov    0x14(%eax),%edx
  4dff1a:	ff d2                	call   *%edx
  4dff1c:	5f                   	pop    %edi
  4dff1d:	5e                   	pop    %esi
  4dff1e:	5b                   	pop    %ebx
  4dff1f:	5d                   	pop    %ebp
  4dff20:	c2 04 00             	ret    $0x4
  4dff23:	cc                   	int3
  4dff24:	cc                   	int3
  4dff25:	cc                   	int3
  4dff26:	cc                   	int3
  4dff27:	cc                   	int3
  4dff28:	cc                   	int3
  4dff29:	cc                   	int3
  4dff2a:	cc                   	int3
  4dff2b:	cc                   	int3
  4dff2c:	cc                   	int3
  4dff2d:	cc                   	int3
  4dff2e:	cc                   	int3
  4dff2f:	cc                   	int3
  4dff30:	55                   	push   %ebp
  4dff31:	8b ec                	mov    %esp,%ebp
  4dff33:	83 ec 10             	sub    $0x10,%esp
  4dff36:	53                   	push   %ebx
  4dff37:	8b 5d 08             	mov    0x8(%ebp),%ebx
  4dff3a:	56                   	push   %esi
  4dff3b:	57                   	push   %edi
  4dff3c:	8b f8                	mov    %eax,%edi
  4dff3e:	85 ff                	test   %edi,%edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   $0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzwl 0x4(%edi),%eax
  4dff50:	8d 4d 08             	lea    0x8(%ebp),%ecx
  4dff53:	89 45 08             	mov    %eax,0x8(%ebp)
  4dff56:	8d 73 08             	lea    0x8(%ebx),%esi
  4dff59:	51                   	push   %ecx
  4dff5a:	8d 45 f8             	lea    -0x8(%ebp),%eax
  4dff5d:	8b ce                	mov    %esi,%ecx
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    -0x8(%ebp),%edx
  4dff67:	3b 53 0c             	cmp    0xc(%ebx),%edx
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    0x8(%ebp),%eax
  4dff6f:	89               	mov    %edi,-0x8(%ebp)
```

### Raw BIN disassembly: `0x004C7D90..0x004C7DC5`

```asm
004c7d90 <.text+0xc6d90>:
  4c7d90:	89 bb 58 01 00 00    	mov    %edi,0x158(%ebx)
  4c7d96:	c7 03 ac 76 c0 00    	movl   $0xc076ac,(%ebx)
  4c7d9c:	8b 4d f4             	mov    -0xc(%ebp),%ecx
  4c7d9f:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  4c7da6:	59                   	pop    %ecx
  4c7da7:	5f                   	pop    %edi
  4c7da8:	5e                   	pop    %esi
  4c7da9:	5b                   	pop    %ebx
  4c7daa:	8b e5                	mov    %ebp,%esp
  4c7dac:	5d                   	pop    %ebp
  4c7dad:	c3                   	ret
  4c7dae:	cc                   	int3
  4c7daf:	cc                   	int3
  4c7db0:	56                   	push   %esi
  4c7db1:	8d 77 24             	lea    0x24(%edi),%esi
  4c7db4:	e8 37 68 2f 00       	call   0x7be5f0
  4c7db9:	8b 4f 28             	mov    0x28(%edi),%ecx
  4c7dbc:	5e                   	pop    %esi
  4c7dbd:	85 c9                	test   %ecx,%ecx
  4c7dbf:	74 1c                	je     0x4c7ddd
  4c7dc1:	8b 01                	mov    (%ecx),%eax
  4c7dc3:	8b 50              	mov    0x10(%eax),%edx
```

### Raw BIN disassembly: `0x007BE5F0..0x007BE648`

```asm
007be5f0 <.text+0x3bd5f0>:
  7be5f0:	8b 06                	mov    (%esi),%eax
  7be5f2:	85 c0                	test   %eax,%eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    (%eax),%eax
  7be5f9:	ff 48 60             	decl   0x60(%eax)
  7be5fc:	8b 06                	mov    (%esi),%eax
  7be5fe:	8b 48 74             	mov    0x74(%eax),%ecx
  7be601:	85 c9                	test   %ecx,%ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmpl   $0x0,0x78(%eax)
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   %eax
  7be60c:	8b 00                	mov    (%eax),%eax
  7be60e:	50                   	push   %eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    $0x1,%eax
  7be619:	c7 06 00 00 00 00    	movl   $0x0,(%esi)
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    $0x1,%ecx
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   %eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   %edi
  7be62c:	8b 3e                	mov    (%esi),%edi
  7be62e:	85 ff                	test   %edi,%edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   %edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    $0x4,%esp
  7be640:	c7 06 00 00 00 00    	movl   $0x0,(%esi)
  7be646:	5f                   	pop    %edi
  7be647:	b8           	mov    $0x1,%eax
```