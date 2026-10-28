# T08-174 — 7DD1F0 延遲佇列消費與臨界區

- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀 GNU objdump x86 PE VA 解碼。
- 日期：2026-10-28T08:59:44+08:00; 研究者 `chatgpt-web roy`。
- GitHub 整合基準：`T01-20261028-06`；正式 T08 Scope 為 0007 的建立/登記/移除資料介面。
- 地址僅按 `.text VA 0x401000 / raw 0x400`，不將歷史 flat 地址無條件平移。
- E8 呼叫掃描只代表候選直接指令相對位址，不等完整 CFG / runtime。

## 主結論
**找到明確的 `owner+0x7C` 延遲佇列消費端 `0x7DD1F0`。** 它不是純粹的容器清空：取得 `owner+0x64` 臨界區後，計算 `(owner+0x80 - owner+0x7C)/4` 的 DWORD 指標數量；逐一先呼叫 `0x7BE0F0`，若指標仍非零，呼叫 `0x7BD850` 與 `0x89120C` 釋放，並將每個槽清零。最後把 end 指標設回 begin，退出臨界區。

## 重要精確邊界
- `0x7DD1F0` 使用 `esi` 作為 owner 基底；非一般標準 `ecx this` ABI，確切調用契約需要 caller 驗證。
- `0x7DD1A0` 在 owner+44 >=1 分支把傳入指標交 `0x7BB350`，而 `0x7DD1F0` 從相同 owner+7C 起始的陣列逐項消費。**因此已建立生產者→消費者的靜態呼叫/欄位匹配。**
- `0x7DD1F0` 路徑中的 `0x8912F0` 傳入相同 end/start 作清除，需注意具體函式的 ABI 尚未確認；觀察到 end 最後寫回 `owner+80`。
- `0x7DD100` 在 this+5C 遞減結果為零時呼叫此消費者；`0x7B8030` 在迭代解除關聯時亦呼叫。

## 保留未知
是否所有 owner 最終都走這兩條路徑；owner+5C 的所有增量來源與併發語意；資源/綁定派生型的真正解構與跨模組持有。

## 原始 BIN 反組譯（原樣節錄）

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

### 0x7DD100

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
```

### 0x7B8030

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
  7b807f:	c2 04 00             	ret    $0x4
```

## 證據標籤
- `BIN-direct`: 上述原始位元組對應的靜態指令與局部 branch/dataflow。
- `callsite-candidate`: 直接 E8 位址，尚不能代表全部動態 caller。
- `unresolved`: 真正遊戲執行/跨執行緒/後端語意未確認。

未修改遊戲執行檔或其他任務文件。