# T08-182 — 模式旗標對復用物件與新物件 Binding 的分歧

- Task：T08；作者：`chatgpt-web roy`；研究時間：`2026-10-28T10:02:22.096809+08:00`（Asia/Taipei）。
- 第一手來源：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算）；唯讀分析、不啟動遊戲。
- PE `.text` 映射：VA `0x00401000` / raw `0x400`；本批對 `.text` 使用 `raw = VA - 0x401000 + 0x400`，**不對其他節區或歷史 flat 位址套公式**。
- 承接：T08-177～180；正式 T08 Scope `0007` 的實體建立、登記、移除資料介面。資源層屬上／下游證據，不推論伺服器波次、生成規則與 AI。
- 界線：純靜態指令證據；未執行 runtime、未證實所有間接邊、異常安全性或 thread interleaving。下列未具原始符號的名稱均為暫稱。

## 範圍、方法與證據等級

本段只以原始 PE `.text` bytes 獨立抽樣核對；舊 Markdown 只提供地址候選。**已確認**限於本節錄機器碼與有界資料流；**合理推測**須明列前提；**尚待驗證**包括間接呼叫、物件類型和 runtime。

## 關鍵新對照

1. `0x007B7FD0` 啟用函式經樹節點 `node+0x24` payload 將多個物件 `+0x44` 寫成常數1；`0x007B8030` 停用時先呼叫 `0x007DD1F0` 再清零。在同一 owner 上應區分「物件模式」與「管理器模式」；名字相似不代表相同結構。
2. `0x007DD0E4` 於**新配置分支**測試 `manager+0x44 >= 1`，為真才呼叫 `0x007BDF90`；`0x007DCFDF` 於**復用分支**則呼叫 `0x007BE5B0`。這兩個分支的 binding 重新建立是否等價尚無完整證據，不能把它們合併成同一 cleanup/reinit 動作。
3. `0x007BDF90` 是依名稱解析 Provider 並取得 Binding 的已知路徑；`0x007BE0F0` 則是 Binding 解除，兩者不同於配置 `0x7C` bytes 資源本體。`binding+0x80` 與 `manager+0x80` 也不可混淆。
4. `0x007B8030` 的 `0x007DD1F0` 消費發生於清零前；`0x007DD1A0` 延遲／立即判斷參考 manager `+0x44`，但不保證 mode stop 後不存在跨執行緒的新 producer。這需要鎖序與 call graph 全面審核。

## 暫定狀態模型（不保證 runtime 排程）

```text
Manager mode+44 >= 1
  -> create new: optionally bind via 0x7BDF90
  -> release via 0x7DD1A0: append under +64 lock to +7C/+80
  -> acquire via 0x7DCFB0: pop from +7C/+80 and reset via 0x7BE5B0
  -> close via 0x7B8030: drain via 0x7DD1F0 then mode+44=0
Manager mode+44 < 1
  -> release via 0x7DD1A0: immediate conditional cleanup/free branch
```

以上模式由局部 CFG 推得，**未追齊所有 mode+44 writers、callers 與同時性**；尤其前述樹節點 payload 種類需從構造者確認。

## 全 `.text` E8 rel32 位移核對

掃描 `.text` raw bytes 中每一個 `E8 xx xx xx xx`，目標依 `callsite VA + 5 + sign_extend(rel32)` 計算；屬**候選 byte 命中**，部分可能是資料/非指令邊界。若未逐一走 CFG，不能聲稱完整 caller 集合，更不能排除 `FF /2` 或虛表間接呼叫。

- **0x007B7FD0** — 1 個候選：`0x007AAF1F` (`e8acd00000`)
- **0x007B8030** — 1 個候選：`0x007AB155` (`e8d6ce0000`)
- **0x007BDF90** — 1 個候選：`0x007DD0EC` (`e89f0efeff`)
- **0x007BE0F0** — 7 個候選：`0x007A53F4` (`e8f78c0100`), `0x007A5A0C` (`e8df860100`), `0x007A5AE8` (`e803860100`), `0x007A7914` (`e8d7670100`), `0x007A874E` (`e89d590100`), `0x007BE626` (`e8c5faffff`), `0x007DD21B` (`e8d00efeff`)

## 未解問題及下一步

1. 在 Ghidra 的真實函式邊界與完整 CFG 驗證 byte-scan E8 候選。
2. 逐一追蹤 owner/node payload 的配置來源、具體型別、vptr、直接／間接 caller 與可能的不同實例。
3. 核對 `+0x44/+0x5C/+0x60/+0x64/+0x7C/+0x80` 的各種引用，嚴禁跨型別 offsets 混合。
4. 未經 runtime 不宣稱跨 frame 消費頻率或 lock-free 安全性。

## 附錄：原始 BIN 指令節錄

### Raw BIN disassembly: `0x007B7FD0..0x007B8027`

```asm
007b7fd0 <.text+0x3b6fd0>:
  7b7fd0:	55                   	push   %ebp
  7b7fd1:	8b ec                	mov    %esp,%ebp
  7b7fd3:	53                   	push   %ebx
  7b7fd4:	8b 5d 08             	mov    0x8(%ebp),%ebx
  7b7fd7:	56                   	push   %esi
  7b7fd8:	57                   	push   %edi
  7b7fd9:	8b 3b                	mov    (%ebx),%edi
  7b7fdb:	8b 47 04             	mov    0x4(%edi),%eax
  7b7fde:	8b 30                	mov    (%eax),%esi
  7b7fe0:	3b f0                	cmp    %eax,%esi
  7b7fe2:	74 11                	je     0x7b7ff5
  7b7fe4:	8b 4e 24             	mov    0x24(%esi),%ecx
  7b7fe7:	8b 01                	mov    (%ecx),%eax
  7b7fe9:	8b 50 04             	mov    0x4(%eax),%edx
  7b7fec:	ff d2                	call   *%edx
  7b7fee:	8b 36                	mov    (%esi),%esi
  7b7ff0:	3b 77 04             	cmp    0x4(%edi),%esi
  7b7ff3:	75 ef                	jne    0x7b7fe4
  7b7ff5:	8b 4b 08             	mov    0x8(%ebx),%ecx
  7b7ff8:	8b 01                	mov    (%ecx),%eax
  7b7ffa:	3b c1                	cmp    %ecx,%eax
  7b7ffc:	74 1c                	je     0x7b801a
  7b7ffe:	b9 01 00 00 00       	mov    $0x1,%ecx
  7b8003:	8b 50 24             	mov    0x24(%eax),%edx
  7b8006:	89 4a 44             	mov    %ecx,0x44(%edx)
  7b8009:	8b 00                	mov    (%eax),%eax
  7b800b:	3b 43 08             	cmp    0x8(%ebx),%eax
  7b800e:	75 f3                	jne    0x7b8003
  7b8010:	5f                   	pop    %edi
  7b8011:	5e                   	pop    %esi
  7b8012:	89 4b 30             	mov    %ecx,0x30(%ebx)
  7b8015:	5b                   	pop    %ebx
  7b8016:	5d                   	pop    %ebp
  7b8017:	c2 04 00             	ret    $0x4
  7b801a:	5f                   	pop    %edi
  7b801b:	5e                   	pop    %esi
  7b801c:	c7 43 30 01 00 00 00 	movl   $0x1,0x30(%ebx)
  7b8023:	5b                   	pop    %ebx
  7b8024:	5d                   	pop    %ebp
  7b8025:	c2 04              	ret    $0x4
```

### Raw BIN disassembly: `0x007B8030..0x007B8081`

```asm
007b8030 <.text+0x3b7030>:
  7b8030:	55                   	push   %ebp
  7b8031:	8b ec                	mov    %esp,%ebp
  7b8033:	53                   	push   %ebx
  7b8034:	8b 5d 08             	mov    0x8(%ebp),%ebx
  7b8037:	8b 43 08             	mov    0x8(%ebx),%eax
  7b803a:	56                   	push   %esi
  7b803b:	57                   	push   %edi
  7b803c:	8b 38                	mov    (%eax),%edi
  7b803e:	3b f8                	cmp    %eax,%edi
  7b8040:	74 16                	je     0x7b8058
  7b8042:	8b 77 24             	mov    0x24(%edi),%esi
  7b8045:	e8 a6 51 02 00       	call   0x7dd1f0
  7b804a:	c7 46 44 00 00 00 00 	movl   $0x0,0x44(%esi)
  7b8051:	8b 3f                	mov    (%edi),%edi
  7b8053:	3b 7b 08             	cmp    0x8(%ebx),%edi
  7b8056:	75 ea                	jne    0x7b8042
  7b8058:	8b 3b                	mov    (%ebx),%edi
  7b805a:	8b 47 04             	mov    0x4(%edi),%eax
  7b805d:	8b 30                	mov    (%eax),%esi
  7b805f:	3b f0                	cmp    %eax,%esi
  7b8061:	74 11                	je     0x7b8074
  7b8063:	8b 4e 24             	mov    0x24(%esi),%ecx
  7b8066:	8b 01                	mov    (%ecx),%eax
  7b8068:	8b 50 08             	mov    0x8(%eax),%edx
  7b806b:	ff d2                	call   *%edx
  7b806d:	8b 36                	mov    (%esi),%esi
  7b806f:	3b 77 04             	cmp    0x4(%edi),%esi
  7b8072:	75 ef                	jne    0x7b8063
  7b8074:	5f                   	pop    %edi
  7b8075:	5e                   	pop    %esi
  7b8076:	c7 43 30 00 00 00 00 	movl   $0x0,0x30(%ebx)
  7b807d:	5b                   	pop    %ebx
  7b807e:	5d                   	pop    %ebp
  7b807f:	c2 04              	ret    $0x4
```

### Raw BIN disassembly: `0x007DD0D8..0x007DD100`

```asm
007dd0d8 <.text+0x3dc0d8>:
  7dd0d8:	3b 45 f4             	cmp    -0xc(%ebp),%eax
  7dd0db:	0f 82 73 ff ff ff    	jb     0x7dd054
  7dd0e1:	8b 75 f8             	mov    -0x8(%ebp),%esi
  7dd0e4:	83 7b 44 01          	cmpl   $0x1,0x44(%ebx)
  7dd0e8:	7c 07                	jl     0x7dd0f1
  7dd0ea:	8b ce                	mov    %esi,%ecx
  7dd0ec:	e8 9f 0e fe ff       	call   0x7bdf90
  7dd0f1:	5f                   	pop    %edi
  7dd0f2:	8b c6                	mov    %esi,%eax
  7dd0f4:	5e                   	pop    %esi
  7dd0f5:	5b                   	pop    %ebx
  7dd0f6:	8b e5                	mov    %ebp,%esp
  7dd0f8:	5d                   	pop    %ebp
  7dd0f9:	c2 04 00             	ret    $0x4
  7dd0fc:	cc                   	int3
  7dd0fd:	cc                   	int3
  7dd0fe:	cc                   	int3
  7dd0ff:	cc                   	int3
```

### Raw BIN disassembly: `0x007BDF90..0x007BE0F0`

```asm
007bdf90 <.text+0x3bcf90>:
  7bdf90:	55                   	push   %ebp
  7bdf91:	8b ec                	mov    %esp,%ebp
  7bdf93:	6a ff                	push   $0xffffffff
  7bdf95:	68 b6 8a 91 00       	push   $0x918ab6
  7bdf9a:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  7bdfa0:	50                   	push   %eax
  7bdfa1:	83 ec 2c             	sub    $0x2c,%esp
  7bdfa4:	a1 20 1f d6 00       	mov    0xd61f20,%eax
  7bdfa9:	33 c5                	xor    %ebp,%eax
  7bdfab:	89 45 f0             	mov    %eax,-0x10(%ebp)
  7bdfae:	53                   	push   %ebx
  7bdfaf:	56                   	push   %esi
  7bdfb0:	57                   	push   %edi
  7bdfb1:	50                   	push   %eax
  7bdfb2:	8d 45 f4             	lea    -0xc(%ebp),%eax
  7bdfb5:	64 a3 00 00 00 00    	mov    %eax,%fs:0x0
  7bdfbb:	8b f1                	mov    %ecx,%esi
  7bdfbd:	8b 46 04             	mov    0x4(%esi),%eax
  7bdfc0:	89 75 cc             	mov    %esi,-0x34(%ebp)
  7bdfc3:	89 45 d0             	mov    %eax,-0x30(%ebp)
  7bdfc6:	3b 46 08             	cmp    0x8(%esi),%eax
  7bdfc9:	0f 84 f4 00 00 00    	je     0x7be0c3
  7bdfcf:	eb 03                	jmp    0x7bdfd4
  7bdfd1:	8b 45 d0             	mov    -0x30(%ebp),%eax
  7bdfd4:	f6 05 70 17 fe 00 01 	testb  $0x1,0xfe1770
  7bdfdb:	8b 18                	mov    (%eax),%ebx
  7bdfdd:	75 27                	jne    0x7be006
  7bdfdf:	83 0d 70 17 fe 00 01 	orl    $0x1,0xfe1770
  7bdfe6:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
  7bdfed:	e8 ae 9d ff ff       	call   0x7b7da0
  7bdff2:	68 90 e7 bc 00       	push   $0xbce790
  7bdff7:	e8 1e 43 0d 00       	call   0x89231a
  7bdffc:	83 c4 04             	add    $0x4,%esp
  7bdfff:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%ebp)
  7be006:	8b 4b 04             	mov    0x4(%ebx),%ecx
  7be009:	8b 35 3c 17 fe 00    	mov    0xfe173c,%esi
  7be00f:	8b c1                	mov    %ecx,%eax
  7be011:	c7 45 e8 0f 00 00 00 	movl   $0xf,-0x18(%ebp)
  7be018:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
  7be01f:	c6 45 d4 00          	movb   $0x0,-0x2c(%ebp)
  7be023:	8d 78 01             	lea    0x1(%eax),%edi
  7be026:	8a 10                	mov    (%eax),%dl
  7be028:	40                   	inc    %eax
  7be029:	84 d2                	test   %dl,%dl
  7be02b:	75 f9                	jne    0x7be026
  7be02d:	2b c7                	sub    %edi,%eax
  7be02f:	50                   	push   %eax
  7be030:	51                   	push   %ecx
  7be031:	8d 4d d4             	lea    -0x2c(%ebp),%ecx
  7be034:	e8 37 4a c4 ff       	call   0x402a70
  7be039:	8d 45 d4             	lea    -0x2c(%ebp),%eax
  7be03c:	50                   	push   %eax
  7be03d:	8d 4d c8             	lea    -0x38(%ebp),%ecx
  7be040:	51                   	push   %ecx
  7be041:	8b c6                	mov    %esi,%eax
  7be043:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%ebp)
  7be04a:	e8 a1 a6 ff ff       	call   0x7b86f0
  7be04f:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%ebp)
  7be056:	83 7d e8 10          	cmpl   $0x10,-0x18(%ebp)
  7be05a:	72 0c                	jb     0x7be068
  7be05c:	8b 55 d4             	mov    -0x2c(%ebp),%edx
  7be05f:	52                   	push   %edx
  7be060:	e8 a7 31 0d 00       	call   0x89120c
  7be065:	83 c4 04             	add    $0x4,%esp
  7be068:	8b 45 c8             	mov    -0x38(%ebp),%eax
  7be06b:	c7 45 e8 0f 00 00 00 	movl   $0xf,-0x18(%ebp)
  7be072:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
  7be079:	c6 45 d4 00          	movb   $0x0,-0x2c(%ebp)
  7be07d:	3b 46 04             	cmp    0x4(%esi),%eax
  7be080:	74 11                	je     0x7be093
  7be082:	8b 48 24             	mov    0x24(%eax),%ecx
  7be085:	85 c9                	test   %ecx,%ecx
  7be087:	74 0a                	je     0x7be093
  7be089:	8b 01                	mov    (%ecx),%eax
  7be08b:	8b 50 10             	mov    0x10(%eax),%edx
  7be08e:	ff d2                	call   *%edx
  7be090:	89 43 08             	mov    %eax,0x8(%ebx)
  7be093:	83 7b 08 00          	cmpl   $0x0,0x8(%ebx)
  7be097:	75 13                	jne    0x7be0ac
  7be099:	8b 43 04             	mov    0x4(%ebx),%eax
  7be09c:	6a 00                	push   $0x0
  7be09e:	50                   	push   %eax
  7be09f:	68 ec fc c4 00       	push   $0xc4fcec
  7be0a4:	6a 00                	push   $0x0
  7be0a6:	ff 15 90 24 bd 00    	call   *0xbd2490
  7be0ac:	8b 45 d0             	mov    -0x30(%ebp),%eax
  7be0af:	8b 4d cc             	mov    -0x34(%ebp),%ecx
  7be0b2:	83 c0 04             	add    $0x4,%eax
  7be0b5:	89 45 d0             	mov    %eax,-0x30(%ebp)
  7be0b8:	3b 41 08             	cmp    0x8(%ecx),%eax
  7be0bb:	0f 85 10 ff ff ff    	jne    0x7bdfd1
  7be0c1:	8b f1                	mov    %ecx,%esi
  7be0c3:	56                   	push   %esi
  7be0c4:	e8 87 00 00 00       	call   0x7be150
  7be0c9:	c7 46 74 01 00 00 00 	movl   $0x1,0x74(%esi)
  7be0d0:	8b 4d f4             	mov    -0xc(%ebp),%ecx
  7be0d3:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  7be0da:	59                   	pop    %ecx
  7be0db:	5f                   	pop    %edi
  7be0dc:	5e                   	pop    %esi
  7be0dd:	5b                   	pop    %ebx
  7be0de:	8b 4d f0             	mov    -0x10(%ebp),%ecx
  7be0e1:	33 cd                	xor    %ebp,%ecx
  7be0e3:	e8 19 2f 0d 00       	call   0x891001
  7be0e8:	8b e5                	mov    %ebp,%esp
  7be0ea:	5d                   	pop    %ebp
  7be0eb:	c3                   	ret
  7be0ec:	cc                   	int3
  7be0ed:	cc                   	int3
  7be0ee:	cc                   	int3
  7be0ef:	cc                   	int3
```