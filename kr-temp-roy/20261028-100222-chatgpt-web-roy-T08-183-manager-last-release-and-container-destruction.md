# T08-183 — 管理器最後引用、回收槽與析構界線

- Task：T08；作者：`chatgpt-web roy`；研究時間：`2026-10-28T10:02:22.096809+08:00`（Asia/Taipei）。
- 第一手來源：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算）；唯讀分析、不啟動遊戲。
- PE `.text` 映射：VA `0x00401000` / raw `0x400`；本批對 `.text` 使用 `raw = VA - 0x401000 + 0x400`，**不對其他節區或歷史 flat 位址套公式**。
- 承接：T08-177～180；正式 T08 Scope `0007` 的實體建立、登記、移除資料介面。資源層屬上／下游證據，不推論伺服器波次、生成規則與 AI。
- 界線：純靜態指令證據；未執行 runtime、未證實所有間接邊、異常安全性或 thread interleaving。下列未具原始符號的名稱均為暫稱。

## 範圍、方法與證據等級

本段只以原始 PE `.text` bytes 獨立抽樣核對；舊 Markdown 只提供地址候選。**已確認**限於本節錄機器碼與有界資料流；**合理推測**須明列前提；**尚待驗證**包括間接呼叫、物件類型和 runtime。

## 新增限定證據

1. `0x007B8124 mov edi,[eax+0x24]` 先從樹節點取 payload，再 `0x007B8129 call 0x007DD100`。`0x007B812E test eax,eax` 的結果決定是否進入 `0x007DCF40` 後 `0x0089120C` 的釋放路徑；因此此 callsite **不能只憑 `0x007DD100` 便稱物件立即刪除**。
2. `0x007B8144` 之後的 `0x007B8680` 用於樹節點移除／調整，其呼叫發生在最後引用導致物件釋放的分支。樹節點清理、payload 管理器析構、資源池 drain 三者須分別表達。
3. 由前段 T08-179 已見 `0x007DD100` 終止引用時進入 `0x007DD1F0`，並在其後處理另一條 `0x007DC510` 登記表；本段再以 `0x007B8124` 上游字串索引刪除點固定 *manager payload* 的生命週期入口。
4. `0x007DCF40` 是 payload manager 層級清理入口，但尚無完整證據證明所有 callback / vtable 清理鏈均已覆蓋，尤其各種 `0x0C` item 的所有權需單獨核對。

## 有界順序圖

```text
0x7B8124 node+24 -> manager payload
  -> 0x7DD100 decrease manager+5C
     -> if still held: keep payload alive
     -> if reaches terminal: 0x7DD1F0 drain +7C/+80
        -> 0x7DC510 registry cleanup (as found in T08-179)
  -> only terminal zero result leads to 0x7DCF40 then 0x89120C
  -> 0x7B8680 removes index node
```

**不能由此導出**沒有其它 heap/owner 引用、registry item callback 具體類型、或 server 角色移除通知等價於管理器 delete。`0x7B8124` 取到的 `node+24` 只能沿其原始索引來源定型。

## 全 `.text` E8 rel32 位移核對

掃描 `.text` raw bytes 中每一個 `E8 xx xx xx xx`，目標依 `callsite VA + 5 + sign_extend(rel32)` 計算；屬**候選 byte 命中**，部分可能是資料/非指令邊界。若未逐一走 CFG，不能聲稱完整 caller 集合，更不能排除 `FF /2` 或虛表間接呼叫。

- **0x007DD100** — 1 個候選：`0x007B8129` (`e8d24f0200`)
- **0x007DC510** — 1 個候選：`0x007DD17D` (`e88ef3ffff`)
- **0x007DCF40** — 2 個候選：`0x007B7F49` (`e8f24f0200`), `0x007B8136` (`e8054e0200`)
- **0x007B8680** — 3 個候選：`0x007B814C` (`e82f050000`), `0x007D0EDC` (`e89f77feff`), `0x007DC5C2` (`e8b9c0fdff`)

## 未解問題及下一步

1. 在 Ghidra 的真實函式邊界與完整 CFG 驗證 byte-scan E8 候選。
2. 逐一追蹤 owner/node payload 的配置來源、具體型別、vptr、直接／間接 caller 與可能的不同實例。
3. 核對 `+0x44/+0x5C/+0x60/+0x64/+0x7C/+0x80` 的各種引用，嚴禁跨型別 offsets 混合。
4. 未經 runtime 不宣稱跨 frame 消費頻率或 lock-free 安全性。

## 附錄：原始 BIN 指令節錄

### Raw BIN disassembly: `0x007DD100..0x007DD19D`

```asm
007dd100 <.text+0x3dc100>:
  7dd100:	55                   	push   %ebp
  7dd101:	8b ec                	mov    %esp,%ebp
  7dd103:	6a ff                	push   $0xffffffff
  7dd105:	68 2e 88 91 00       	push   $0x91882e
  7dd10a:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  7dd110:	50                   	push   %eax
  7dd111:	53                   	push   %ebx
  7dd112:	56                   	push   %esi
  7dd113:	57                   	push   %edi
  7dd114:	a1 20 1f d6 00       	mov    0xd61f20,%eax
  7dd119:	33 c5                	xor    %ebp,%eax
  7dd11b:	50                   	push   %eax
  7dd11c:	8d 45 f4             	lea    -0xc(%ebp),%eax
  7dd11f:	64 a3 00 00 00 00    	mov    %eax,%fs:0x0
  7dd125:	8b f1                	mov    %ecx,%esi
  7dd127:	83 cf ff             	or     $0xffffffff,%edi
  7dd12a:	01 7e 5c             	add    %edi,0x5c(%esi)
  7dd12d:	8b 46 5c             	mov    0x5c(%esi),%eax
  7dd130:	75 58                	jne    0x7dd18a
  7dd132:	e8 b9 00 00 00       	call   0x7dd1f0
  7dd137:	33 db                	xor    %ebx,%ebx
  7dd139:	f6 05 70 17 fe 00 01 	testb  $0x1,0xfe1770
  7dd140:	89 5e 44             	mov    %ebx,0x44(%esi)
  7dd143:	75 1f                	jne    0x7dd164
  7dd145:	83 0d 70 17 fe 00 01 	orl    $0x1,0xfe1770
  7dd14c:	89 5d fc             	mov    %ebx,-0x4(%ebp)
  7dd14f:	e8 4c ac fd ff       	call   0x7b7da0
  7dd154:	68 90 e7 bc 00       	push   $0xbce790
  7dd159:	e8 bc 51 0b 00       	call   0x89231a
  7dd15e:	83 c4 04             	add    $0x4,%esp
  7dd161:	89 7d fc             	mov    %edi,-0x4(%ebp)
  7dd164:	8b 7e 50             	mov    0x50(%esi),%edi
  7dd167:	2b 7e 4c             	sub    0x4c(%esi),%edi
  7dd16a:	c1 ff 02             	sar    $0x2,%edi
  7dd16d:	3b fb                	cmp    %ebx,%edi
  7dd16f:	76 16                	jbe    0x7dd187
  7dd171:	8b 46 4c             	mov    0x4c(%esi),%eax
  7dd174:	8b 14 98             	mov    (%eax,%ebx,4),%edx
  7dd177:	8b 0d 3c 17 fe 00    	mov    0xfe173c,%ecx
  7dd17d:	e8 8e f3 ff ff       	call   0x7dc510
  7dd182:	43                   	inc    %ebx
  7dd183:	3b df                	cmp    %edi,%ebx
  7dd185:	72 ea                	jb     0x7dd171
  7dd187:	8b 46 5c             	mov    0x5c(%esi),%eax
  7dd18a:	8b 4d f4             	mov    -0xc(%ebp),%ecx
  7dd18d:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  7dd194:	59                   	pop    %ecx
  7dd195:	5f                   	pop    %edi
  7dd196:	5e                   	pop    %esi
  7dd197:	5b                   	pop    %ebx
  7dd198:	8b e5                	mov    %ebp,%esp
  7dd19a:	5d                   	pop    %ebp
  7dd19b:	c3                   	ret
  7dd19c:	cc                   	int3
```

### Raw BIN disassembly: `0x007DC510..0x007DC5A1`

```asm
007dc510 <.text+0x3db510>:
  7dc510:	55                   	push   %ebp
  7dc511:	8b ec                	mov    %esp,%ebp
  7dc513:	6a ff                	push   $0xffffffff
  7dc515:	68 b0 49 91 00       	push   $0x9149b0
  7dc51a:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  7dc520:	50                   	push   %eax
  7dc521:	83 ec 44             	sub    $0x44,%esp
  7dc524:	a1 20 1f d6 00       	mov    0xd61f20,%eax
  7dc529:	33 c5                	xor    %ebp,%eax
  7dc52b:	89 45 f0             	mov    %eax,-0x10(%ebp)
  7dc52e:	53                   	push   %ebx
  7dc52f:	56                   	push   %esi
  7dc530:	57                   	push   %edi
  7dc531:	50                   	push   %eax
  7dc532:	8d 45 f4             	lea    -0xc(%ebp),%eax
  7dc535:	64 a3 00 00 00 00    	mov    %eax,%fs:0x0
  7dc53b:	8b fa                	mov    %edx,%edi
  7dc53d:	33 db                	xor    %ebx,%ebx
  7dc53f:	8b c7                	mov    %edi,%eax
  7dc541:	8b f1                	mov    %ecx,%esi
  7dc543:	c7 45 cc 0f 00 00 00 	movl   $0xf,-0x34(%ebp)
  7dc54a:	89 5d c8             	mov    %ebx,-0x38(%ebp)
  7dc54d:	88 5d b8             	mov    %bl,-0x48(%ebp)
  7dc550:	8d 50 01             	lea    0x1(%eax),%edx
  7dc553:	8a 08                	mov    (%eax),%cl
  7dc555:	40                   	inc    %eax
  7dc556:	3a cb                	cmp    %bl,%cl
  7dc558:	75 f9                	jne    0x7dc553
  7dc55a:	2b c2                	sub    %edx,%eax
  7dc55c:	50                   	push   %eax
  7dc55d:	57                   	push   %edi
  7dc55e:	8d 4d b8             	lea    -0x48(%ebp),%ecx
  7dc561:	e8 0a 65 c2 ff       	call   0x402a70
  7dc566:	8d 45 b8             	lea    -0x48(%ebp),%eax
  7dc569:	50                   	push   %eax
  7dc56a:	8d 4d b4             	lea    -0x4c(%ebp),%ecx
  7dc56d:	51                   	push   %ecx
  7dc56e:	8b c6                	mov    %esi,%eax
  7dc570:	89 5d fc             	mov    %ebx,-0x4(%ebp)
  7dc573:	e8 78 c1 fd ff       	call   0x7b86f0
  7dc578:	c7 45 fc ff ff ff ff 	movl   $0xffffffff,-0x4(%ebp)
  7dc57f:	83 7d cc 10          	cmpl   $0x10,-0x34(%ebp)
  7dc583:	72 0c                	jb     0x7dc591
  7dc585:	8b 55 b8             	mov    -0x48(%ebp),%edx
  7dc588:	52                   	push   %edx
  7dc589:	e8 7e 4c 0b 00       	call   0x89120c
  7dc58e:	83 c4 04             	add    $0x4,%esp
  7dc591:	8b 45 b4             	mov    -0x4c(%ebp),%eax
  7dc594:	3b 46 04             	cmp    0x4(%esi),%eax
  7dc597:	74 33                	je     0x7dc5cc
  7dc599:	8b 78 24             	mov    0x24(%eax),%edi
  7dc59c:	8b 07                	mov    (%edi),%eax
  7dc59e:	8b 50 0c             	mov    0xc(%eax),%edx
```

### Raw BIN disassembly: `0x007DCF40..0x007DCFB0`

```asm
007dcf40 <.text+0x3dbf40>:
  7dcf40:	53                   	push   %ebx
  7dcf41:	56                   	push   %esi
  7dcf42:	8b 77 4c             	mov    0x4c(%edi),%esi
  7dcf45:	33 db                	xor    %ebx,%ebx
  7dcf47:	3b 77 50             	cmp    0x50(%edi),%esi
  7dcf4a:	74 1d                	je     0x7dcf69
  7dcf4c:	8d 64 24 00          	lea    0x0(%esp),%esp
  7dcf50:	8b 06                	mov    (%esi),%eax
  7dcf52:	3b c3                	cmp    %ebx,%eax
  7dcf54:	74 0b                	je     0x7dcf61
  7dcf56:	50                   	push   %eax
  7dcf57:	e8 b0 42 0b 00       	call   0x89120c
  7dcf5c:	83 c4 04             	add    $0x4,%esp
  7dcf5f:	89 1e                	mov    %ebx,(%esi)
  7dcf61:	83 c6 04             	add    $0x4,%esi
  7dcf64:	3b 77 50             	cmp    0x50(%edi),%esi
  7dcf67:	75 e7                	jne    0x7dcf50
  7dcf69:	8b 47 7c             	mov    0x7c(%edi),%eax
  7dcf6c:	3b c3                	cmp    %ebx,%eax
  7dcf6e:	74 09                	je     0x7dcf79
  7dcf70:	50                   	push   %eax
  7dcf71:	e8 96 42 0b 00       	call   0x89120c
  7dcf76:	83 c4 04             	add    $0x4,%esp
  7dcf79:	8d 47 64             	lea    0x64(%edi),%eax
  7dcf7c:	50                   	push   %eax
  7dcf7d:	89 5f 7c             	mov    %ebx,0x7c(%edi)
  7dcf80:	89 9f 80 00 00 00    	mov    %ebx,0x80(%edi)
  7dcf86:	89 9f 84 00 00 00    	mov    %ebx,0x84(%edi)
  7dcf8c:	ff 15 28 22 bd 00    	call   *0xbd2228
  7dcf92:	8b 47 4c             	mov    0x4c(%edi),%eax
  7dcf95:	3b c3                	cmp    %ebx,%eax
  7dcf97:	74 09                	je     0x7dcfa2
  7dcf99:	50                   	push   %eax
  7dcf9a:	e8 6d 42 0b 00       	call   0x89120c
  7dcf9f:	83 c4 04             	add    $0x4,%esp
  7dcfa2:	5e                   	pop    %esi
  7dcfa3:	89 5f 4c             	mov    %ebx,0x4c(%edi)
  7dcfa6:	89 5f 50             	mov    %ebx,0x50(%edi)
  7dcfa9:	89 5f 54             	mov    %ebx,0x54(%edi)
  7dcfac:	5b                   	pop    %ebx
  7dcfad:	c3                   	ret
  7dcfae:	cc                   	int3
  7dcfaf:	cc                   	int3
```

### Raw BIN disassembly: `0x007B8118..0x007B8171`

```asm
007b8118 <.text+0x3b7118>:
  7b8118:	8b 45 d0             	mov    -0x30(%ebp),%eax
  7b811b:	3b 47 08             	cmp    0x8(%edi),%eax
  7b811e:	75 04                	jne    0x7b8124
  7b8120:	33 c0                	xor    %eax,%eax
  7b8122:	eb 32                	jmp    0x7b8156
  7b8124:	8b 78 24             	mov    0x24(%eax),%edi
  7b8127:	8b cf                	mov    %edi,%ecx
  7b8129:	e8 d2 4f 02 00       	call   0x7dd100
  7b812e:	85 c0                	test   %eax,%eax
  7b8130:	75 1f                	jne    0x7b8151
  7b8132:	85 ff                	test   %edi,%edi
  7b8134:	74 0e                	je     0x7b8144
  7b8136:	e8 05 4e 02 00       	call   0x7dcf40
  7b813b:	57                   	push   %edi
  7b813c:	e8 cb 90 0d 00       	call   0x89120c
  7b8141:	83 c4 04             	add    $0x4,%esp
  7b8144:	8b 45 d0             	mov    -0x30(%ebp),%eax
  7b8147:	50                   	push   %eax
  7b8148:	8d 4d d0             	lea    -0x30(%ebp),%ecx
  7b814b:	51                   	push   %ecx
  7b814c:	e8 2f 05 00 00       	call   0x7b8680
  7b8151:	b8 01 00 00 00       	mov    $0x1,%eax
  7b8156:	8b 4d f4             	mov    -0xc(%ebp),%ecx
  7b8159:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  7b8160:	59                   	pop    %ecx
  7b8161:	5f                   	pop    %edi
  7b8162:	5e                   	pop    %esi
  7b8163:	8b 4d f0             	mov    -0x10(%ebp),%ecx
  7b8166:	33 cd                	xor    %ebp,%ecx
  7b8168:	e8 94 8e 0d 00       	call   0x891001
  7b816d:	8b e5                	mov    %ebp,%esp
  7b816f:	5d                   	pop    %ebp
  7b8170:	c3                   	ret
```