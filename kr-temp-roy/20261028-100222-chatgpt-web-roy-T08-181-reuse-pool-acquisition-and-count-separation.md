# T08-181 — 復用佇列取出／新配置雙路徑及持有計數獨立性

- Task：T08；作者：`chatgpt-web roy`；研究時間：`2026-10-28T10:02:22.096809+08:00`（Asia/Taipei）。
- 第一手來源：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算）；唯讀分析、不啟動遊戲。
- PE `.text` 映射：VA `0x00401000` / raw `0x400`；本批對 `.text` 使用 `raw = VA - 0x401000 + 0x400`，**不對其他節區或歷史 flat 位址套公式**。
- 承接：T08-177～180；正式 T08 Scope `0007` 的實體建立、登記、移除資料介面。資源層屬上／下游證據，不推論伺服器波次、生成規則與 AI。
- 界線：純靜態指令證據；未執行 runtime、未證實所有間接邊、異常安全性或 thread interleaving。下列未具原始符號的名稱均為暫稱。

## 範圍、方法與證據等級

本段只以原始 PE `.text` bytes 獨立抽樣核對；舊 Markdown 只提供地址候選。**已確認**限於本節錄機器碼與有界資料流；**合理推測**須明列前提；**尚待驗證**包括間接呼叫、物件類型和 runtime。

## 新確認的位元組證據及結論

1. `0x007DCFB7 mov ebx,[ebp+8]` 取得 owner 參數；`0x007DCFBA inc dword ptr [ebx+0x60]` 在進入鎖前增加 `owner+0x60`。此 `+0x60` 與前段 `owner+0x5C` 並非同一 DWORD；不應把二者混成單一引用計數。
2. `0x007DCFBF lea edi,[ebx+0x64]`、`0x007DCFC2 push edi`、`0x007DCFC3 call [0x00BD224C]` 對 owner 的鎖欄位進入同步流程；取出和修改的指標範圍是 `owner+0x7C` 至 `owner+0x80`。
3. 非空分支 `0x007DCFD4 mov eax,[ebx+0x80]`、`0x007DCFDA mov esi,[eax-4]` 取出**尾端 DWORD**，`0x007DCFDF call 0x007BE5B0`，接著 `0x007DCFF2 mov [ebx+0x80],eax` 將 end 減4。此為容器取出／復用，**不能稱為已執行 free**。是否由 `0x007BE5B0` 完成全量重新初始化，須沿函式確認。
4. 空分支 `0x007DD011 push 0x7C`、`0x007DD013 call 0x00891268` 配置新資源；若非空指標，`0x007DD02A call 0x007BD7E0` 初始化，並以 `owner+0x48` 浮點參數傳遞。
5. `owner+0x4C/+0x50` 的指標差以4位元組為元素計數；每項配置 `0x0C` bytes 次級項目並寫入 `item+0x04`。`0x007DD0E4 cmp [ebx+0x44],1` 決定要不要呼叫 `0x007BDF90` 做名稱／Provider binding 處理，這是**復用/配置完成後的模式條件**。
6. `0x007DD0F9 ret 4` 對外按 stack 清理一個參數；函式內又取 `[ebp+8]` owner。只是 ABI 有界觀察，不足以自動套成通用 C++ thiscall。

## 有界 C++ 偽碼（示意，非原始程式）

```cpp
Resource* acquire_resource(Manager* owner /* [ebp+8] */) {
    ++owner->field60;             // increment outside +64 lock: ordering verified
    lock(&owner->field64);
    if (owner->end80 != owner->begin7C) {
        Resource* r = *(owner->end80 - 1);
        reset_or_prepare_7BE5B0(r); // semantics of callee not fully named
        owner->end80 -= 1;
        unlock(&owner->field64);
        return r;
    }
    unlock(&owner->field64);
    Resource* r = allocate_0x7C_and_initialize(owner->field48);
    if (r) {
        for (auto q : owner->range4C_50) attach_0x0C_item(r, q);
        if (owner->mode44 >= 1) bind_names_7BDF90(r);
    }
    return r;
}
```

**重要限制：** `allocate_0x7C` 若失敗及次級 `0x0C` 分配失敗的分支需個別審計；上述偽碼只總結有界主資料流，不保證原版錯誤處理、重入、計數回滾完整。`+0x60` pre-increment 與 return-null 是否可能失配仍待追查。

## 對前段結論的精確增量

T08-177～180 以 `0x007DD1A0` 生產端和 `0x007DD1F0` 消費端為主。本段直接證明**同一 `+0x7C/+0x80` 容器還存在 reverse pop 的 `0x007DCFB0` consumer**，故「所有佇列項目必等待 drain 到最後才 free」不能成立；有些物件可在 drain 前從池中再利用。這仍不能斷言 runtime 有跨 frame 的復用時序。

## 全 `.text` E8 rel32 位移核對

掃描 `.text` raw bytes 中每一個 `E8 xx xx xx xx`，目標依 `callsite VA + 5 + sign_extend(rel32)` 計算；屬**候選 byte 命中**，部分可能是資料/非指令邊界。若未逐一走 CFG，不能聲稱完整 caller 集合，更不能排除 `FF /2` 或虛表間接呼叫。

- **0x007DCFB0** — 2 個候選：`0x007B8275` (`e8364d0200`), `0x007F6FDC` (`e8cf5ffeff`)
- **0x007BE5B0** — 7 個候選：`0x007A681D` (`e88e7d0100`), `0x007A68FA` (`e8b17c0100`), `0x007A6923` (`e8887c0100`), `0x007A8D1B` (`e890580100`), `0x007DCFDF` (`e8cc15feff`), `0x007FF899` (`e812edfbff`), `0x007FF8D1` (`e8daecfbff`)
- **0x007BD7E0** — 1 個候選：`0x007DD02A` (`e8b107feff`)
- **0x007BDF90** — 1 個候選：`0x007DD0EC` (`e89f0efeff`)
- **0x007DD1A0** — 2 個候選：`0x007A8741` (`e85a4a0300`), `0x007BE60F` (`e88ceb0100`)

## 未解問題及下一步

1. 在 Ghidra 的真實函式邊界與完整 CFG 驗證 byte-scan E8 候選。
2. 逐一追蹤 owner/node payload 的配置來源、具體型別、vptr、直接／間接 caller 與可能的不同實例。
3. 核對 `+0x44/+0x5C/+0x60/+0x64/+0x7C/+0x80` 的各種引用，嚴禁跨型別 offsets 混合。
4. 未經 runtime 不宣稱跨 frame 消費頻率或 lock-free 安全性。

## 附錄：原始 BIN 指令節錄

### Raw BIN disassembly: `0x007DCFB0..0x007DD100`

```asm
007dcfb0 <.text+0x3dbfb0>:
  7dcfb0:	55                   	push   %ebp
  7dcfb1:	8b ec                	mov    %esp,%ebp
  7dcfb3:	83 ec 10             	sub    $0x10,%esp
  7dcfb6:	53                   	push   %ebx
  7dcfb7:	8b 5d 08             	mov    0x8(%ebp),%ebx
  7dcfba:	ff 43 60             	incl   0x60(%ebx)
  7dcfbd:	56                   	push   %esi
  7dcfbe:	57                   	push   %edi
  7dcfbf:	8d 7b 64             	lea    0x64(%ebx),%edi
  7dcfc2:	57                   	push   %edi
  7dcfc3:	ff 15 4c 22 bd 00    	call   *0xbd224c
  7dcfc9:	8b 43 7c             	mov    0x7c(%ebx),%eax
  7dcfcc:	3b 83 80 00 00 00    	cmp    0x80(%ebx),%eax
  7dcfd2:	74 36                	je     0x7dd00a
  7dcfd4:	8b 83 80 00 00 00    	mov    0x80(%ebx),%eax
  7dcfda:	8b 70 fc             	mov    -0x4(%eax),%esi
  7dcfdd:	8b c6                	mov    %esi,%eax
  7dcfdf:	e8 cc 15 fe ff       	call   0x7be5b0
  7dcfe4:	8b 83 80 00 00 00    	mov    0x80(%ebx),%eax
  7dcfea:	39 43 7c             	cmp    %eax,0x7c(%ebx)
  7dcfed:	74 09                	je     0x7dcff8
  7dcfef:	83 c0 fc             	add    $0xfffffffc,%eax
  7dcff2:	89 83 80 00 00 00    	mov    %eax,0x80(%ebx)
  7dcff8:	57                   	push   %edi
  7dcff9:	ff 15 48 22 bd 00    	call   *0xbd2248
  7dcfff:	8b c6                	mov    %esi,%eax
  7dd001:	5f                   	pop    %edi
  7dd002:	5e                   	pop    %esi
  7dd003:	5b                   	pop    %ebx
  7dd004:	8b e5                	mov    %ebp,%esp
  7dd006:	5d                   	pop    %ebp
  7dd007:	c2 04 00             	ret    $0x4
  7dd00a:	57                   	push   %edi
  7dd00b:	ff 15 48 22 bd 00    	call   *0xbd2248
  7dd011:	6a 7c                	push   $0x7c
  7dd013:	e8 50 42 0b 00       	call   0x891268
  7dd018:	33 ff                	xor    %edi,%edi
  7dd01a:	83 c4 04             	add    $0x4,%esp
  7dd01d:	3b c7                	cmp    %edi,%eax
  7dd01f:	74 15                	je     0x7dd036
  7dd021:	d9 43 48             	flds   0x48(%ebx)
  7dd024:	51                   	push   %ecx
  7dd025:	8b cb                	mov    %ebx,%ecx
  7dd027:	d9 1c 24             	fstps  (%esp)
  7dd02a:	e8 b1 07 fe ff       	call   0x7bd7e0
  7dd02f:	8b f0                	mov    %eax,%esi
  7dd031:	89 75 f8             	mov    %esi,-0x8(%ebp)
  7dd034:	eb 05                	jmp    0x7dd03b
  7dd036:	89 7d f8             	mov    %edi,-0x8(%ebp)
  7dd039:	8b f7                	mov    %edi,%esi
  7dd03b:	8b 43 50             	mov    0x50(%ebx),%eax
  7dd03e:	2b 43 4c             	sub    0x4c(%ebx),%eax
  7dd041:	89 7d fc             	mov    %edi,-0x4(%ebp)
  7dd044:	c1 f8 02             	sar    $0x2,%eax
  7dd047:	89 45 f4             	mov    %eax,-0xc(%ebp)
  7dd04a:	3b c7                	cmp    %edi,%eax
  7dd04c:	0f 86 92 00 00 00    	jbe    0x7dd0e4
  7dd052:	eb 02                	jmp    0x7dd056
  7dd054:	33 ff                	xor    %edi,%edi
  7dd056:	6a 0c                	push   $0xc
  7dd058:	e8 0b 42 0b 00       	call   0x891268
  7dd05d:	83 c4 04             	add    $0x4,%esp
  7dd060:	3b c7                	cmp    %edi,%eax
  7dd062:	74 0b                	je     0x7dd06f
  7dd064:	89 78 04             	mov    %edi,0x4(%eax)
  7dd067:	89 78 08             	mov    %edi,0x8(%eax)
  7dd06a:	c6 00 00             	movb   $0x0,(%eax)
  7dd06d:	8b f8                	mov    %eax,%edi
  7dd06f:	8b 4b 4c             	mov    0x4c(%ebx),%ecx
  7dd072:	8b 55 fc             	mov    -0x4(%ebp),%edx
  7dd075:	8b 04 91             	mov    (%ecx,%edx,4),%eax
  7dd078:	89 47 04             	mov    %eax,0x4(%edi)
  7dd07b:	8b 46 08             	mov    0x8(%esi),%eax
  7dd07e:	8d 4d 08             	lea    0x8(%ebp),%ecx
  7dd081:	89 7d 08             	mov    %edi,0x8(%ebp)
  7dd084:	3b c8                	cmp    %eax,%ecx
  7dd086:	73 2f                	jae    0x7dd0b7
  7dd088:	8b 4e 04             	mov    0x4(%esi),%ecx
  7dd08b:	8d 55 08             	lea    0x8(%ebp),%edx
  7dd08e:	3b ca                	cmp    %edx,%ecx
  7dd090:	77 25                	ja     0x7dd0b7
  7dd092:	8b fa                	mov    %edx,%edi
  7dd094:	2b f9                	sub    %ecx,%edi
  7dd096:	c1 ff 02             	sar    $0x2,%edi
  7dd099:	3b 46 0c             	cmp    0xc(%esi),%eax
  7dd09c:	75 08                	jne    0x7dd0a6
  7dd09e:	8d 46 04             	lea    0x4(%esi),%eax
  7dd0a1:	e8 8a a8 fb ff       	call   0x797930
  7dd0a6:	8b 46 08             	mov    0x8(%esi),%eax
  7dd0a9:	85 c0                	test   %eax,%eax
  7dd0ab:	74 20                	je     0x7dd0cd
  7dd0ad:	8b 4e 04             	mov    0x4(%esi),%ecx
  7dd0b0:	8b 14 b9             	mov    (%ecx,%edi,4),%edx
  7dd0b3:	89 10                	mov    %edx,(%eax)
  7dd0b5:	eb 16                	jmp    0x7dd0cd
  7dd0b7:	3b 46 0c             	cmp    0xc(%esi),%eax
  7dd0ba:	75 08                	jne    0x7dd0c4
  7dd0bc:	8d 46 04             	lea    0x4(%esi),%eax
  7dd0bf:	e8 6c a8 fb ff       	call   0x797930
  7dd0c4:	8b 46 08             	mov    0x8(%esi),%eax
  7dd0c7:	85 c0                	test   %eax,%eax
  7dd0c9:	74 02                	je     0x7dd0cd
  7dd0cb:	89 38                	mov    %edi,(%eax)
  7dd0cd:	8b 45 fc             	mov    -0x4(%ebp),%eax
  7dd0d0:	83 46 08 04          	addl   $0x4,0x8(%esi)
  7dd0d4:	40                   	inc    %eax
  7dd0d5:	89 45 fc             	mov    %eax,-0x4(%ebp)
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

### Raw BIN disassembly: `0x007DD1A0..0x007DD1EC`

```asm
007dd1a0 <.text+0x3dc1a0>:
  7dd1a0:	55                   	push   %ebp
  7dd1a1:	8b ec                	mov    %esp,%ebp
  7dd1a3:	53                   	push   %ebx
  7dd1a4:	8b 5d 08             	mov    0x8(%ebp),%ebx
  7dd1a7:	83 7b 44 01          	cmpl   $0x1,0x44(%ebx)
  7dd1ab:	57                   	push   %edi
  7dd1ac:	8b 7d 0c             	mov    0xc(%ebp),%edi
  7dd1af:	7c 24                	jl     0x7dd1d5
  7dd1b1:	56                   	push   %esi
  7dd1b2:	8d 73 64             	lea    0x64(%ebx),%esi
  7dd1b5:	56                   	push   %esi
  7dd1b6:	ff 15 4c 22 bd 00    	call   *0xbd224c
  7dd1bc:	8d 7b 7c             	lea    0x7c(%ebx),%edi
  7dd1bf:	8d 45 0c             	lea    0xc(%ebp),%eax
  7dd1c2:	e8 89 e1 fd ff       	call   0x7bb350
  7dd1c7:	56                   	push   %esi
  7dd1c8:	ff 15 48 22 bd 00    	call   *0xbd2248
  7dd1ce:	5e                   	pop    %esi
  7dd1cf:	5f                   	pop    %edi
  7dd1d0:	5b                   	pop    %ebx
  7dd1d1:	5d                   	pop    %ebp
  7dd1d2:	c2 08 00             	ret    $0x8
  7dd1d5:	85 ff                	test   %edi,%edi
  7dd1d7:	74 0e                	je     0x7dd1e7
  7dd1d9:	e8 72 06 fe ff       	call   0x7bd850
  7dd1de:	57                   	push   %edi
  7dd1df:	e8 28 40 0b 00       	call   0x89120c
  7dd1e4:	83 c4 04             	add    $0x4,%esp
  7dd1e7:	5f                   	pop    %edi
  7dd1e8:	5b                   	pop    %ebx
  7dd1e9:	5d                   	pop    %ebp
  7dd1ea:	c2 08              	ret    $0x8
```

### Raw BIN disassembly: `0x007DD1F0..0x007DD29B`

```asm
007dd1f0 <.text+0x3dc1f0>:
  7dd1f0:	55                   	push   %ebp
  7dd1f1:	8b ec                	mov    %esp,%ebp
  7dd1f3:	51                   	push   %ecx
  7dd1f4:	53                   	push   %ebx
  7dd1f5:	8d 46 64             	lea    0x64(%esi),%eax
  7dd1f8:	57                   	push   %edi
  7dd1f9:	50                   	push   %eax
  7dd1fa:	89 45 fc             	mov    %eax,-0x4(%ebp)
  7dd1fd:	ff 15 4c 22 bd 00    	call   *0xbd224c
  7dd203:	8b 46 7c             	mov    0x7c(%esi),%eax
  7dd206:	8b 8e 80 00 00 00    	mov    0x80(%esi),%ecx
  7dd20c:	2b c8                	sub    %eax,%ecx
  7dd20e:	c1 f9 02             	sar    $0x2,%ecx
  7dd211:	33 db                	xor    %ebx,%ebx
  7dd213:	85 c9                	test   %ecx,%ecx
  7dd215:	74 46                	je     0x7dd25d
  7dd217:	8b 14 98             	mov    (%eax,%ebx,4),%edx
  7dd21a:	52                   	push   %edx
  7dd21b:	e8 d0 0e fe ff       	call   0x7be0f0
  7dd220:	8b 46 7c             	mov    0x7c(%esi),%eax
  7dd223:	83 3c 98 00          	cmpl   $0x0,(%eax,%ebx,4)
  7dd227:	8d 04 98             	lea    (%eax,%ebx,4),%eax
  7dd22a:	74 1e                	je     0x7dd24a
  7dd22c:	8b 38                	mov    (%eax),%edi
  7dd22e:	85 ff                	test   %edi,%edi
  7dd230:	74 0e                	je     0x7dd240
  7dd232:	e8 19 06 fe ff       	call   0x7bd850
  7dd237:	57                   	push   %edi
  7dd238:	e8 cf 3f 0b 00       	call   0x89120c
  7dd23d:	83 c4 04             	add    $0x4,%esp
  7dd240:	8b 4e 7c             	mov    0x7c(%esi),%ecx
  7dd243:	c7 04 99 00 00 00 00 	movl   $0x0,(%ecx,%ebx,4)
  7dd24a:	8b 46 7c             	mov    0x7c(%esi),%eax
  7dd24d:	8b 96 80 00 00 00    	mov    0x80(%esi),%edx
  7dd253:	2b d0                	sub    %eax,%edx
  7dd255:	43                   	inc    %ebx
  7dd256:	c1 fa 02             	sar    $0x2,%edx
  7dd259:	3b da                	cmp    %edx,%ebx
  7dd25b:	72 ba                	jb     0x7dd217
  7dd25d:	8b 8e 80 00 00 00    	mov    0x80(%esi),%ecx
  7dd263:	8b 7e 7c             	mov    0x7c(%esi),%edi
  7dd266:	3b f9                	cmp    %ecx,%edi
  7dd268:	74 21                	je     0x7dd28b
  7dd26a:	8b c1                	mov    %ecx,%eax
  7dd26c:	2b c1                	sub    %ecx,%eax
  7dd26e:	c1 f8 02             	sar    $0x2,%eax
  7dd271:	8d 1c 85 00 00 00 00 	lea    0x0(,%eax,4),%ebx
  7dd278:	53                   	push   %ebx
  7dd279:	51                   	push   %ecx
  7dd27a:	57                   	push   %edi
  7dd27b:	e8 70 40 0b 00       	call   0x8912f0
  7dd280:	83 c4 0c             	add    $0xc,%esp
  7dd283:	03 df                	add    %edi,%ebx
  7dd285:	89 9e 80 00 00 00    	mov    %ebx,0x80(%esi)
  7dd28b:	8b 45 fc             	mov    -0x4(%ebp),%eax
  7dd28e:	50                   	push   %eax
  7dd28f:	ff 15 48 22 bd 00    	call   *0xbd2248
  7dd295:	5f                   	pop    %edi
  7dd296:	5b                   	pop    %ebx
  7dd297:	8b e5                	mov    %ebp,%esp
  7dd299:	5d                   	pop    %ebp
  7dd29a:	c3                   	ret
```