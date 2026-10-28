# T08-175 — 延遲與立即分支的同一物件釋放協定

- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀 GNU objdump x86 PE VA 解碼。
- 日期：2026-10-28T08:59:44+08:00; 研究者 `chatgpt-web roy`。
- GitHub 整合基準：`T01-20261028-06`；正式 T08 Scope 為 0007 的建立/登記/移除資料介面。
- 地址僅按 `.text VA 0x401000 / raw 0x400`，不將歷史 flat 地址無條件平移。
- E8 呼叫掃描只代表候選直接指令相對位址，不等完整 CFG / runtime。

## 生產與消費鏈交叉核對

1. `0x7BE5F0` 從 pointer slot 拿到 resource，讀 resource+74/+78；二者均非零時將 resource 的 owner 與 resource 指標傳給 `0x7DD1A0`，然後清零原 slot。
2. `0x7DD1A0` 依 `owner+44` 決定進入 0x7BB350 队列插入（持有 `owner+64` 同一把臨界區）或立即 `0x7BD850`／`0x89120C`。
3. `0x7DD1F0` 在釋放端對 owner+7C/+80 範圍逐項清理。
4. `0x7A8741` 提供另一條 owner→resource 使用同一 0x7DD1A0 的 callsite，但源對象類型不同，不可把所有此函式 caller 都當 0007 actor。

## ABI及順序風險
- `0x7DD1A0` `ret 8`，第一個 stack 參數是 owner、第二個是要清理的指標；callsite `0x7BE60F` 與 `0x7A8741` 的 push 順序與之吻合。
- `0x7DD1F0` 的迭代先呼叫 `0x7BE0F0`，再視槽是否為零決定是否補直接 free。此二階段清理與外部早前 `0x7BE5F0` 的 slot 清零不是同一個操作。
- **未證明** cleanup 與 free 並發安全；沒有追完整 `0x7BE0F0`、`0x7BD850` 的再入行為。

## 其他界線
本結論只是 resource owner 生命週期；T08 原始 actor 建立/刪除的 GameInfo 樹、腳本 CEventActor 樹與此 owner 結構必須依來源分開。

## 原始 BIN 反組譯（原樣節錄）

### 0x7BE5F0

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
  7be647:	b8 01 00 00 00       	mov    $0x1,%eax
  7be64c:	c7 06 00 00 00 00    	movl   $0x0,(%esi)
  7be652:	c3                   	ret
```

### 0x7DD1A0

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
  7dd1ea:	c2 08 00             	ret    $0x8
```

### 0x7DD1F0

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

### 0x7A870F

```asm
007a8712 <.text+0x3a7712>:
  7a8712:	89 47 30             	mov    %eax,0x30(%edi)
  7a8715:	c7 47 70 01 00 00 00 	movl   $0x1,0x70(%edi)
  7a871c:	e8 af 51 01 00       	call   0x7bd8d0
  7a8721:	83 7f 6c 00          	cmpl   $0x0,0x6c(%edi)
  7a8725:	0f 84 81 00 00 00    	je     0x7a87ac
  7a872b:	8b 07                	mov    (%edi),%eax
  7a872d:	ff 48 60             	decl   0x60(%eax)
  7a8730:	8b 47 74             	mov    0x74(%edi),%eax
  7a8733:	85 c0                	test   %eax,%eax
  7a8735:	74 11                	je     0x7a8748
  7a8737:	83 7f 78 00          	cmpl   $0x0,0x78(%edi)
  7a873b:	74 0b                	je     0x7a8748
  7a873d:	8b 0f                	mov    (%edi),%ecx
  7a873f:	57                   	push   %edi
  7a8740:	51                   	push   %ecx
  7a8741:	e8 5a 4a 03 00       	call   0x7dd1a0
  7a8746:	eb 19                	jmp    0x7a8761
  7a8748:	83 f8 01             	cmp    $0x1,%eax
  7a874b:	7c 06                	jl     0x7a8753
  7a874d:	57                   	push   %edi
  7a874e:	e8 9d 59 01 00       	call   0x7be0f0
  7a8753:	e8 f8 50 01 00       	call   0x7bd850
  7a8758:	57                   	push   %edi
  7a8759:	e8 ae 8a 0e 00       	call   0x89120c
  7a875e:	83 c4 04             	add    $0x4,%esp
  7a8761:	8b 7e 0c             	mov    0xc(%esi),%edi
  7a8764:	85 ff                	test   %edi,%edi
  7a8766:	74 12                	je     0x7a877a
  7a8768:	8b 17                	mov    (%edi),%edx
  7a876a:	8b 42 10             	mov    0x10(%edx),%eax
  7a876d:	8b cf                	mov    %edi,%ecx
  7a876f:	ff d0                	call   *%eax
  7a8771:	8b 17                	mov    (%edi),%edx
  7a8773:	8b 42 08             	mov    0x8(%edx),%eax
  7a8776:	8b cf                	mov    %edi,%ecx
  7a8778:	ff d0                	call   *%eax
  7a877a:	8b                 	mov    (%esi),%eax
```

## 證據標籤
- `BIN-direct`: 上述原始位元組對應的靜態指令與局部 branch/dataflow。
- `callsite-candidate`: 直接 E8 位址，尚不能代表全部動態 caller。
- `unresolved`: 真正遊戲執行/跨執行緒/後端語意未確認。

未修改遊戲執行檔或其他任務文件。