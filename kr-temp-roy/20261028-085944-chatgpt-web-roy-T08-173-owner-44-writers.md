# T08-173 — owner+0x44 寫入者及延遲清理入口

- 原始客戶端：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀 GNU objdump x86 PE VA 解碼。
- 日期：2026-10-28T08:59:44+08:00; 研究者 `chatgpt-web roy`。
- GitHub 整合基準：`T01-20261028-06`；正式 T08 Scope 為 0007 的建立/登記/移除資料介面。
- 地址僅按 `.text VA 0x401000 / raw 0x400`，不將歷史 flat 地址無條件平移。
- E8 呼叫掃描只代表候選直接指令相對位址，不等完整 CFG / runtime。

## 主結論
這批獨立找到兩條 owner+44 = 0 寫入路徑：`0x7B804A` 位於迭代容器解除關聯之後；`0x7DD140` 位於 `0x7DD100` 引用計數/終止處理中，且在呼叫 `0x7DD1F0` 之後。`0x7B8006` 也會從樹節點 payload 的 `+0x24` 取出物件，將另一個受控 `ecx` 寫入 `object+0x44`；這是已定位的非零/可變值生產者候選，應按 caller 驗證傳入 `ecx`，不能稱唯一寫入者。

## 控制流程
- `0x7B8030`：遍歷 `arg0+8` sentinel 指向的樹節點，從 node+24 載入 `esi=owner`，執行 `call 7DD1F0`，然後 `mov dword ptr [esi+44],0`。樹中另一個關聯列表呼叫 vtable `+8`，最後 `arg0+30=0`。
- `0x7DD100`：`this+5C -= 1`，非零直接跳返；等於零時 `call 7DD1F0`、`this+44=0`，後續清理 `this+4C/50` 之間指標陣列。
- `0x7DD1A0` 入口依 `owner+44 >=1` 走延遲路徑，否則立即清理。這是呼叫當下的 gate，**不是全域延遲釋放政策**。

## 已確認與未知
- 確認：同一 owner+44 被兩條清理路徑清零，且存在容器迭代時指派值的另一條路徑。
- 未知：`0x7B7FA0` 上層驅動者、`ecx` 的具體生命週期含義、所有寫入者全集。
- 不可把不同結構的任意 `+44` 字節寫入直接視為相同 owner。

## 原始 BIN 反組譯（原樣節錄）

### 0x7B7FA0

```asm
007b7fa0 <.text+0x3b6fa0>:
  7b7fa0:	00 00                	add    %al,(%eax)
  7b7fa2:	00 e8                	add    %ch,%al
  7b7fa4:	e8 4c 02 00 c7       	call   0xc77b81f5
  7b7fa9:	43                   	inc    %ebx
  7b7faa:	24 07                	and    $0x7,%al
  7b7fac:	00 00                	add    %al,(%eax)
  7b7fae:	00 c7                	add    %al,%bh
  7b7fb0:	43                   	inc    %ebx
  7b7fb1:	28 08                	sub    %cl,(%eax)
  7b7fb3:	00 00                	add    %al,(%eax)
  7b7fb5:	00 8b 13 52 e8 c2    	add    %cl,-0x3d17aded(%ebx)
  7b7fbb:	44                   	inc    %esp
  7b7fbc:	02 00                	add    (%eax),%al
  7b7fbe:	5f                   	pop    %edi
  7b7fbf:	5e                   	pop    %esi
  7b7fc0:	5b                   	pop    %ebx
  7b7fc1:	5d                   	pop    %ebp
  7b7fc2:	c2 04 00             	ret    $0x4
  7b7fc5:	cc                   	int3
  7b7fc6:	cc                   	int3
  7b7fc7:	cc                   	int3
  7b7fc8:	cc                   	int3
  7b7fc9:	cc                   	int3
  7b7fca:	cc                   	int3
  7b7fcb:	cc                   	int3
  7b7fcc:	cc                   	int3
  7b7fcd:	cc                   	int3
  7b7fce:	cc                   	int3
  7b7fcf:	cc                   	int3
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
  7b8025:	c2 04 00             	ret    $0x4
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

## 證據標籤
- `BIN-direct`: 上述原始位元組對應的靜態指令與局部 branch/dataflow。
- `callsite-candidate`: 直接 E8 位址，尚不能代表全部動態 caller。
- `unresolved`: 真正遊戲執行/跨執行緒/後端語意未確認。

未修改遊戲執行檔或其他任務文件。