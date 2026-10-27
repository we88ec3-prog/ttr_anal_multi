# KR T08-163 — 移除接收器長度／資料鍵對齊及 dispatch 負證據邊界

- 研究時間：20261028-020933 Asia/Taipei；研究者：`chatgpt-web roy`。
- 第一手來源：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；靜態唯讀 GNU objdump（PE32 i386），禁止執行或附加。
- GitHub 研究基準：`main` 於研究起始查得 `3fb7b8f6da6fd670cd2fb1e1db739e4f9dc2045b`（其他任務可能同時更新，提交時必須重新確認）；正式 T08 = `0007` 實體建立／登記／移除，網路 dispatch 僅提供 T02 引用邊界。
- 文件類型：新的完整分析原稿，非正式 catalog native semantic acceptance。證據分級：[BYTE] 原始機器碼、[FLOW] 可由指令支持的局部資料流、[INFER] 推論、[OPEN] 未解。
- 地址統一採 PE VA；`.text` VA 0x401000 對 file raw 0x400；禁止使用 flat `VA-0x401000` 混充 PE raw。
- 先前 T08-153～160 及 T01-20261027-05 限定審核仍有效。

## 問題：封包接收與移除函式如何可靠對齊？

[BYTE] `0x4B28D0` 首部對 `[ebp+0x0C]` 長度作最少 4 bytes 檢查，其餘筆數以 `(length-4)>>1` 計算，從 `packet+4` 開始用 WORD 步長處理。這不是 `S2C0007` 的 26-byte 建立 row；二者資料格式不同。

[BYTE] `0x4B3710` 用最少 2 bytes，筆數 `(length-2)>>1`，從 `packet+2` 取得 WORD，`or eax,0x06000000`，先 push 該鍵，再 call `0x40F060` 取得 GameInfo-like receiver，隨後 call `0x4DFC90`，該函式 `ret 0x04` 負責取走推入的鍵。這修正 154/156 曾把 getter 視作 key converter 的錯誤。

[FLOW] `0x4B28D0` 與 `0x4B3710` 都是符合接收器型態的函式，能確認從原始 bytes 讀取行為，但 **不能光憑 code 入口與 payload 形狀指定 S2C opcode**。函式指標表可能註冊中間 thunk／持有者，direct DWORD pointer 搜尋為零不代表沒註冊。

## 兩條 payload 不能混用

| 入口 | 門檻 | count | 每筆偏移 | 操作 | 語意限制 |
|---|---:|---|---|---|---|
| `4B28D0` | 4 bytes | `(n-4)>>1` | +4,+6,... | 單 Actor ID 查找及移除候選 | 上游封包 opcode 尚未定位 |
| `4B3710` | 2 bytes | `(n-2)>>1` | +2,+4,... | 組 `0x06000000|WORD`，批次條件刪 | 6 的 domain 意義未知 |
| `4AE4D0` | 建立封包 2 bytes + 26-byte rows | `(n-2)/26` | +2 起，26-byte | 新建 Actor 並 `4DFF30` 插表 | 和前兩個移除格式不同 |

## 反證：不應由缺少直接引用擴大結論

本輪進行**限定 `.rdata` 直接 DWORD 比對**：對 `0x4B28D0`、`0x4B3710`、`0x4AE4D0` 在 PE `.rdata` 單獨搜尋 4-byte little endian 直接指標，結果皆為零。這只能表示指定這塊 file raw bytes 內沒有原樣 DWORD 值；不能推成網路命令沒登錄、來源不可能經 wrapper、或不存在以計算位址間接分派。

同檢查用 CMonster `0x4D18D0` 與 CEventActor `0x4D0CA0` 的 vtable slots 各得直接命中，作為正控制，證明搜尋方法能找到已知 PE .rdata 指標。仍不代表前面負掃描具全域性。

## C++ 保守型態

```cpp
int candidateConditionalPacket(const uint8_t *data, size_t n) {
    size_t count = n < 2 ? 0 : (n-2)/2;
    for (size_t i=0; i<count; i++) {
        uint16_t item = load_le16(data+2+2*i);
        uint32_t key = 0x06000000 | item;
        auto *gameInfo = lazyGameInfoGetter();
        gameInfo->eraseByActorField88(key);
    }
    return 0;
}
```

`load_le16` 是語義上避免非對齊存取問題的示意，不聲稱編譯器原碼如此；此函式未自證 packet 是哪一個正式命令、服務端權威或移除 timing。


## 原始反組譯錨點

### 4B28D0 初始長度／筆數
```asm
  4b28fc:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b28ff:	83 f8 04             	cmp    eax,0x4
  4b2902:	73 04                	jae    0x4b2908
  4b2904:	33 c0                	xor    eax,eax
  4b2906:	eb 05                	jmp    0x4b290d
  4b2908:	83 c0 fc             	add    eax,0xfffffffc
  4b290b:	d1 e8                	shr    eax,1
  4b290d:	85 c0                	test   eax,eax
  4b290f:	0f 84 c1 01 00 00    	je     0x4b2ad6
  4b2915:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b2918:	83 c1 04             	add    ecx,0x4
  4b291b:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4b291f:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4b2923:	bb                   	.byte 0xbb
  4b2924:	01                   	.byte 0x1
```

### 4B3710 完整短函式
```asm
  4b3710:	55                   	push   ebp
  4b3711:	8b ec                	mov    ebp,esp
  4b3713:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b3716:	57                   	push   edi
  4b3717:	83 f8 02             	cmp    eax,0x2
  4b371a:	73 04                	jae    0x4b3720
  4b371c:	33 ff                	xor    edi,edi
  4b371e:	eb 05                	jmp    0x4b3725
  4b3720:	8d 78 fe             	lea    edi,[eax-0x2]
  4b3723:	d1 ef                	shr    edi,1
  4b3725:	85 ff                	test   edi,edi
  4b3727:	74 21                	je     0x4b374a
  4b3729:	56                   	push   esi
  4b372a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b372d:	83 c6 02             	add    esi,0x2
  4b3730:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4b3733:	0d 00 00 00 06       	or     eax,0x6000000
  4b3738:	50                   	push   eax
  4b3739:	e8 22 b9 f5 ff       	call   0x40f060
  4b373e:	e8 4d c5 02 00       	call   0x4dfc90
  4b3743:	83 c6 02             	add    esi,0x2
  4b3746:	4f                   	dec    edi
  4b3747:	75 e7                	jne    0x4b3730
  4b3749:	5e                   	pop    esi
  4b374a:	33 c0                	xor    eax,eax
  4b374c:	5f                   	pop    edi
  4b374d:	5d                   	pop    ebp
  4b374e:	c2                   	.byte 0xc2
  4b374f:	0c                   	.byte 0xc
```

### GameInfo getter（完整返回前關鍵區域）
```asm
  40f09c:	24 10                	and    al,0x10
  40f09e:	00 00                	add    BYTE PTR [eax],al
  40f0a0:	00 00                	add    BYTE PTR [eax],al
  40f0a2:	e8 e9 fb 0c 00       	call   0x4dec90
  40f0a7:	68 30 ce bc 00       	push   0xbcce30
  40f0ac:	e8 69 32 48 00       	call   0x89231a
  40f0b1:	83 c4 04             	add    esp,0x4
  40f0b4:	b8                   	.byte 0xb8
  40f0b5:	30                   	.byte 0x30
  40f0b6:	b1 fa                	mov    cl,0xfa
```

## 證據與不變限制

- 使用者要求本段保留完整 trace，而非強行將 caller 確定為封包 opcode；只在 PE 映射及 opcode 所支援範圍下說話。
- 對於歷史已判定有不同內容的 flat dump，採用 PE 頭與具體位置實際 bytes，不跨視角複製反組譯結論。
- 靜態反組譯未含執行時各派生類別的所有實際 vptr；不得推論全域 exhaustive caller 或 runtime 時序。
- 不修改 `kr/tasks/T08/task.json`、`shared/catalog.json`、別人任務文件；commit 僅研究者個人 `kr-temp-roy/`。