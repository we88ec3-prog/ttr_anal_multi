# KR T08-167 — 4C8360 預清理與 4C7B90 終結清理的跨函式對照

- 研究者：`chatgpt-web roy`；本輪產檔時間：`20261028-021950` (Asia/Taipei)
- 基準：GitHub `main` 在本輪查核 commit `567e3ec82b826fafede56e2ee5e054a0b3ad798d`（提交前再查 HEAD）
- 原始來源：`Tartaros.bin` `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386 `.text` VA 0x401000/raw 0x400；完全唯讀
- 方法：GNU objdump 指定位址視窗；未啟動、附加或修改客戶端。`BYTE` 是目標 BIN 中直接的指令，`INFERENCE` 表示由機器碼推得的功能邊界
- 跨批次參考：`T08-153..164` 與 T01 整合來源審核，歷史報告是索引，不獨立替代原生 bytes

## 研究目的

4C8360 預清理與 4C7B90 終結清理的跨函式對照。此工作包聚焦正式 KR T08 的「物件建立／登記／移除資料介面」；不自行擴大成 AI 生成時機或遊戲規則。

## 主結論及推導
- `[BYTE]` `4C8360` 先檢查 `actor+15C`，對非零控制塊的 `+8` 取 vptr，再呼叫其虛擬 +8；後面對 actor+364 和 128 項 `+164` 陣列只在 nested `+24 != 0` 時呼叫 `7BE5F0`。
- `[BYTE]` `4C8360` 的迴圈總共 128 次、每次 actor slot 增量 4；沒有直接清空 actor array slot，因此只是 nested resource release，而非刪除 actor 本體。
- `[BYTE]` `4C7B90` 的對應 array cleanup 無論 nested+24 是否為空，都將每個非零 item 送 `89120C`，把 actor slot 清為零；還檢查 item+28 並進行虛擬 +10/+8。此差異支援**兩層清理**，不直接證實必定按先後各執行一次。
- `[BYTE]` `4C7DB0` 被 `4C7B90` 的 actor+364 branch 使用，對 nested+24 不需事先判空；`7BE5F0` 自己有空槽提前返回，避免把該路徑說成 double free。
- 推測：移除路徑 virtual +14 可能實施預清理，而 virtual +0(flag1) 進入派生 deleting destructor，再到 base `4C7B90`。**實際派生 vtable/對應 slot 以 T08-161 原始指標為限，不外推其他類別。**

## 待驗
- 是否有重入與執行緒競爭？`resource` 及 `actor` 是否有外部持有者？ `4DFBC0` 之外的清理入口何時經過預清理？此輪只用靜態 bytes 無法一概證明。


## 可重現的機器碼摘錄

### VA `0x004c8360..0x004c83c0`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8360 <.text+0xc7360>:
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

### VA `0x004c7c73..0x004c7cd2`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c7c73 <.text+0xc6c73>:
  4c7c73:	8d 83 64 01 00 00    	lea    eax,[ebx+0x164]
  4c7c79:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c7c7c:	c7 45 ec 80 00 00 00 	mov    DWORD PTR [ebp-0x14],0x80
  4c7c83:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c7c86:	8b 39                	mov    edi,DWORD PTR [ecx]
  4c7c88:	85 ff                	test   edi,edi
  4c7c8a:	74 3d                	je     0x4c7cc9
  4c7c8c:	8d 77 24             	lea    esi,[edi+0x24]
  4c7c8f:	e8 5c 69 2f 00       	call   0x7be5f0
  4c7c94:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7c97:	85 c9                	test   ecx,ecx
  4c7c99:	74 1c                	je     0x4c7cb7
  4c7c9b:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c7c9d:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  4c7ca0:	ff d0                	call   eax
  4c7ca2:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7ca5:	85 c9                	test   ecx,ecx
  4c7ca7:	74 0e                	je     0x4c7cb7
  4c7ca9:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c7cab:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  4c7cae:	ff d0                	call   eax
  4c7cb0:	c7 47 28 00 00 00 00 	mov    DWORD PTR [edi+0x28],0x0
  4c7cb7:	57                   	push   edi
  4c7cb8:	e8 4f 95 3c 00       	call   0x89120c
  4c7cbd:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c7cc0:	83 c4 04             	add    esp,0x4
  4c7cc3:	c7 01 00 00 00 00    	mov    DWORD PTR [ecx],0x0
  4c7cc9:	83 45 f0 04          	add    DWORD PTR [ebp-0x10],0x4
  4c7ccd:	ff 4d ec             	dec    DWORD PTR [ebp-0x14]
  4c7cd0:	75 b1                	jne    0x4c7c83
```

### VA `0x004c7db0..0x004c7de9`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c7db0 <.text+0xc6db0>:
  4c7db0:	56                   	push   esi
  4c7db1:	8d 77 24             	lea    esi,[edi+0x24]
  4c7db4:	e8 37 68 2f 00       	call   0x7be5f0
  4c7db9:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7dbc:	5e                   	pop    esi
  4c7dbd:	85 c9                	test   ecx,ecx
  4c7dbf:	74 1c                	je     0x4c7ddd
  4c7dc1:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c7dc3:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4c7dc6:	ff d2                	call   edx
  4c7dc8:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7dcb:	85 c9                	test   ecx,ecx
  4c7dcd:	74 0e                	je     0x4c7ddd
  4c7dcf:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c7dd1:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c7dd4:	ff d2                	call   edx
  4c7dd6:	c7 47 28 00 00 00 00 	mov    DWORD PTR [edi+0x28],0x0
  4c7ddd:	57                   	push   edi
  4c7dde:	e8 29 94 3c 00       	call   0x89120c
  4c7de3:	83 c4 04             	add    esp,0x4
  4c7de6:	8b c7                	mov    eax,edi
  4c7de8:	c3                   	ret
```

## 工作流程偽碼（受限版本）

```cpp
// 非原生原始碼，僅表達本輪已核對的條件與未知；不直接部署。
void T08_167_bounded_study() {
    // See machine-code windows and branch conditions above.
    // No claim of full execution, all callers, or server authority.
}
```

## 證據等級與未解條件

- 直接原始證據：上列 VA 視窗 machine code，由指定 SHA 的 PE bytes 產生。
- 有條件推論：call 前後欄位訪問所推之 ownership/cleanup 次序；虛擬函式未解析為固定 callee。
- 未驗證：執行期頻率、實體是否存在其他 owner、全部 caller 集、TCP/P2P authority、場景與 AI 決策、失敗回滾。
- 不修改 repo `task.json`、catalog、其他 Agent 筆記；新稿僅擬放 `kr-temp-roy/`。