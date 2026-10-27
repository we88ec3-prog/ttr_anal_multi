# KR T08-162 — 兩類 Actor slot+14 共享預清理及 128 槽解除引用

- 研究時間：20261028-020933 Asia/Taipei；研究者：`chatgpt-web roy`。
- 第一手來源：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；靜態唯讀 GNU objdump（PE32 i386），禁止執行或附加。
- GitHub 研究基準：`main` 於研究起始查得 `3fb7b8f6da6fd670cd2fb1e1db739e4f9dc2045b`（其他任務可能同時更新，提交時必須重新確認）；正式 T08 = `0007` 實體建立／登記／移除，網路 dispatch 僅提供 T02 引用邊界。
- 文件類型：新的完整分析原稿，非正式 catalog native semantic acceptance。證據分級：[BYTE] 原始機器碼、[FLOW] 可由指令支持的局部資料流、[INFER] 推論、[OPEN] 未解。
- 地址統一採 PE VA；`.text` VA 0x401000 對 file raw 0x400；禁止使用 flat `VA-0x401000` 混充 PE raw。
- 先前 T08-153～160 及 T01-20261027-05 限定審核仍有效。

## 分析目標與主要確認

從 T08-161 的兩張 vtable 追 slot+0x14 的實際執行鏈。

[BYTE] 在 `0x4D1F80`，CMonster slot+14 包裝器只呼叫 `0x4C8360`，並固定 `eax=0` 返回；在 CEventActor，slot+14 直接指向 `0x4C8360`。因此 **虛擬預清理與 slot+0(1) 的物件記憶體釋放是明確分開的兩階段**。

[BYTE] `0x4C8360` 針對 `receiver+0x15C` 若非零，取 `pointer+8` 的 vptr+8，做間接清理；再查看 `receiver+0x364` 的 `+0x24`，非空時呼叫 `0x7BE5F0`；最後從 `receiver+0x164` 起進行 `0x80`（128）次 DWORD stride=4 檢查，對非零指標及其 `+0x24` 仍有值者呼叫 `0x7BE5F0`。

[FLOW] 這是**關聯／binding/resource 解除引用**的具體生產端，而非角色 AI 停止；其 offset 必須依 receiver 型別解釋，不能直接混同前面 `0x4CA860` 控制區塊或 `owner+0x15C` 推論的其他 receiver。

[OPEN] `0x7BE5F0` 的完整資源所有權與執行期引用次序仍需更深函式分析；迴圈後沒有看到清掉 128 個 slots 的顯式 store，不應說所有欄位被清零。

## 直接位址與 data-flow 表

| VA | data-flow / branch | 等級 |
|---|---|---|
| `4D1F80` | `E8 DB 63 FF FF` -> 4C8360，再 eax=0 | BYTE |
| `4C8365` | 讀 receiver+0x15C | BYTE |
| `4C8372..77` | 取嵌套介面 vptr+0x08 間接呼叫 | BYTE |
| `4C8379` | 讀 receiver+0x364 | BYTE |
| `4C838C` | call 7BE5F0 | BYTE |
| `4C8391` | pointer = receiver+0x164 | BYTE |
| `4C8397` | count=0x80 | BYTE |
| `4C83A0..B8` | 迴圈逐項檢查 +0x24，再 7BE5F0 | BYTE |
| `4C83BA..BF` | eax=0；ret | BYTE |

## 保守偽碼

```cpp
int actorPreRemove(ActorLike *self) {
    if (auto *nested = *(void**)((char*)self+0x15C))
        callVirtual8((char*)nested+8);
    maybeReleaseBinding(*(void**)((char*)self+0x364));
    for (int i=0;i<128;i++)
        maybeReleaseBinding(*(void**)((char*)self+0x164+4*i));
    return 0;
}
```

此偽碼中的 `maybeReleaseBinding` 代表**僅在 +0x24 非零時進入 7BE5F0**；沒有透過偽碼推定執行後 pointer 會自動清空。

## 跨階段結論

正式 T08 需要建立／移除所帶來的指標所有權邊界，此段在移除前的資源解除路徑有可驗證進展，但沒有獲得一個可據此複製的全域 Actor memory layout；下一段追網路入口和資料鍵形成。


## 原始反組譯：共享預清理與 wrapper

### 4D1F80
```asm
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
```

### 4C8360–4C83C0
```asm
  4c8360:	53                   	push   ebx
  4c8361:	56                   	push   esi
  4c8362:	57                   	push   edi
  4c8363:	8b f9                	mov    edi,ecx
  4c8365:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4c836b:	85 c0                	test   eax,eax
  4c836d:	74 0a                	je     0x4c8379
  4c836f:	8d 48 08             	lea    ecx,[eax+0x8]
  4c8372:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c8374:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c8377:	ff d2                	call   edx
  4c8379:	8b 87 64 03 00 00    	mov    eax,DWORD PTR [edi+0x364]
  4c837f:	85 c0                	test   eax,eax
  4c8381:	74 0e                	je     0x4c8391
  4c8383:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c8387:	8d 70 24             	lea    esi,[eax+0x24]
  4c838a:	74 05                	je     0x4c8391
  4c838c:	e8 5f 62 2f 00       	call   0x7be5f0
  4c8391:	81 c7 64 01 00 00    	add    edi,0x164
  4c8397:	bb 80 00 00 00       	mov    ebx,0x80
  4c839c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4c83a0:	8b 07                	mov    eax,DWORD PTR [edi]
  4c83a2:	85 c0                	test   eax,eax
  4c83a4:	74 0e                	je     0x4c83b4
  4c83a6:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c83aa:	8d 70 24             	lea    esi,[eax+0x24]
  4c83ad:	74 05                	je     0x4c83b4
  4c83af:	e8 3c 62 2f 00       	call   0x7be5f0
  4c83b4:	83 c7 04             	add    edi,0x4
  4c83b7:	4b                   	dec    ebx
  4c83b8:	75 e6                	jne    0x4c83a0
  4c83ba:	5f                   	pop    edi
  4c83bb:	5e                   	pop    esi
  4c83bc:	33 c0                	xor    eax,eax
  4c83be:	5b                   	pop    ebx
  4c83bf:	c3                   	ret
```

### 4DFBC0 間接呼叫點
```asm
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
```

## 證據與不變限制

- 使用者要求本段保留完整 trace，而非強行將 caller 確定為封包 opcode；只在 PE 映射及 opcode 所支援範圍下說話。
- 對於歷史已判定有不同內容的 flat dump，採用 PE 頭與具體位置實際 bytes，不跨視角複製反組譯結論。
- 靜態反組譯未含執行時各派生類別的所有實際 vptr；不得推論全域 exhaustive caller 或 runtime 時序。
- 不修改 `kr/tasks/T08/task.json`、`shared/catalog.json`、別人任務文件；commit 僅研究者個人 `kr-temp-roy/`。