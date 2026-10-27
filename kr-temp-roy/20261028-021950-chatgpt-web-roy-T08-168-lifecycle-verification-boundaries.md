# KR T08-168 — 正式 T08 生命周期閉合矩陣與跨 Task 邊界

- 研究者：`chatgpt-web roy`；本輪產檔時間：`20261028-021950` (Asia/Taipei)
- 基準：GitHub `main` 在本輪查核 commit `567e3ec82b826fafede56e2ee5e054a0b3ad798d`（提交前再查 HEAD）
- 原始來源：`Tartaros.bin` `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386 `.text` VA 0x401000/raw 0x400；完全唯讀
- 方法：GNU objdump 指定位址視窗；未啟動、附加或修改客戶端。`BYTE` 是目標 BIN 中直接的指令，`INFERENCE` 表示由機器碼推得的功能邊界
- 跨批次參考：`T08-153..164` 與 T01 整合來源審核，歷史報告是索引，不獨立替代原生 bytes

## 研究目的

正式 T08 生命周期閉合矩陣與跨 Task 邊界。此工作包聚焦正式 KR T08 的「物件建立／登記／移除資料介面」；不自行擴大成 AI 生成時機或遊戲規則。

## 統合證據表
| 功能 | 直接來源 | 已確立 | 尚未確立 |
|---|---|---|---|
| 建立與登記 | T08-153/157 追的 `4AE4D0→4D1710→4DFF30` | 有具體生成、登記呼叫候選及 BIN 位址 | 全部生成來源、伺服器決策／時機 |
| 單 ID 移除 | T08-153/154/159 `4DFBC0` | 根據 key 找 actor、虛擬解除後 map erase 的局部流程 | 所有 upstream opcode 與例外處理 |
| 預清理 | `4C8360` + vtable slots | `+15C/+364/+164` 處理 nested binding | 任意 actor 的所有清理入口 |
| 基底析構 | `4C7B90` | 內部容器、控制塊、128 槽、25 槽釋放順序 | 無外部 alias／完全 free 與執行緒語意 |
| nested release | `7BE5F0` | `+74/+78` 分支、可寫 slot 清零 | 分支具體業務含意，`7DD1A0` 後續所有權 |
| Tree erase | T08-155 `7B6890` | 有樹節點移除／數量更新來源 | 不等於 actor 物件析構成功或 free 全程保證 |

## 與舊分析互動／防誤判
- `S2C0007` row=26 bytes 是建立接收資料介面，不能以此反推出生成時間、波次規則或原版後端選怪方式。
- Lua `Q.DeleteObject` 註冊的空操作不可視為 GameInfo actor 移除；`Q.DeleteAllObject` 清理的是腳本容器，並非必定同一種 Actor 擁有權。
- T02 主責 dispatch 框架、T06/T07 主責場景進退；本 T08 只記錄對 actor 表的影響，不擅改任務歸屬。
- 已有一個歷史 BIN 映射衝突；本輪各地址以 `objdump -d` 標準 PE VMA 展示，並非以 flat `VA-401000` 直接讀 bytes。
- 靜態機器碼只證實條件分支與 callsites，不等於動態測試、遊戲可玩驗收或任何原版 server 規則。

## 後續最值得驗證
1. `7DD1A0` 到 deferred lifecycle／owner transfer 的真正資料關聯。
2. `89120C` 實際分配器配對與 exception path。
3. 不同 Actor 派生類別 deleting destructor 的覆蓋率與重入防護。


## 可重現的機器碼摘錄

### VA `0x004dfbc0..0x004dfc90`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
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
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4
  4dfc2c:	cc                   	int3
  4dfc2d:	cc                   	int3
  4dfc2e:	cc                   	int3
  4dfc2f:	cc                   	int3
  4dfc30:	55                   	push   ebp
  4dfc31:	8b ec                	mov    ebp,esp
  4dfc33:	51                   	push   ecx
  4dfc34:	53                   	push   ebx
  4dfc35:	57                   	push   edi
  4dfc36:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfc39:	8d 5e 18             	lea    ebx,[esi+0x18]
  4dfc3c:	50                   	push   eax
  4dfc3d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfc40:	8b cb                	mov    ecx,ebx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfc4a:	3b 7e 1c             	cmp    edi,DWORD PTR [esi+0x1c]
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b 86 f8 00 00 00    	mov    eax,DWORD PTR [esi+0xf8]
  4dfc55:	85 c0                	test   eax,eax
  4dfc57:	74 11                	je     0x4dfc6a
  4dfc59:	8b 08                	mov    ecx,DWORD PTR [eax]
  4dfc5b:	3b 4d 08             	cmp    ecx,DWORD PTR [ebp+0x8]
  4dfc5e:	75 0a                	jne    0x4dfc6a
  4dfc60:	c7 86 f8 00 00 00 00 	mov    DWORD PTR [esi+0xf8],0x0
  4dfc67:	00 00 00 
  4dfc6a:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4dfc6d:	85 c0                	test   eax,eax
  4dfc6f:	74 09                	je     0x4dfc7a
  4dfc71:	50                   	push   eax
  4dfc72:	e8 95 15 3b 00       	call   0x89120c
  4dfc77:	83 c4 04             	add    esp,0x4
  4dfc7a:	57                   	push   edi
  4dfc7b:	8d 55 08             	lea    edx,[ebp+0x8]
  4dfc7e:	52                   	push   edx
  4dfc7f:	53                   	push   ebx
  4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
  4dfc85:	5f                   	pop    edi
  4dfc86:	5b                   	pop    ebx
  4dfc87:	8b e5                	mov    esp,ebp
  4dfc89:	5d                   	pop    ebp
  4dfc8a:	c2 04 00             	ret    0x4
  4dfc8d:	cc                   	int3
  4dfc8e:	cc                   	int3
  4dfc8f:	cc                   	int3
```

### VA `0x004c7b90..0x004c7c5a`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c7b90 <.text+0xc6b90>:
  4c7b90:	55                   	push   ebp
  4c7b91:	8b ec                	mov    ebp,esp
  4c7b93:	6a ff                	push   0xffffffff
  4c7b95:	68 b9 d9 90 00       	push   0x90d9b9
  4c7b9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c7ba0:	50                   	push   eax
  4c7ba1:	83 ec 0c             	sub    esp,0xc
  4c7ba4:	53                   	push   ebx
  4c7ba5:	56                   	push   esi
  4c7ba6:	57                   	push   edi
  4c7ba7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c7bac:	33 c5                	xor    eax,ebp
  4c7bae:	50                   	push   eax
  4c7baf:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c7bb2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c7bb8:	8b d9                	mov    ebx,ecx
  4c7bba:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  4c7bbd:	c7 03 54 75 c0 00    	mov    DWORD PTR [ebx],0xc07554
  4c7bc3:	c7 83 f0 00 00 00 dc 	mov    DWORD PTR [ebx+0xf0],0xc075dc
  4c7bca:	75 c0 00 
  4c7bcd:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  4c7bd4:	8b bb 68 03 00 00    	mov    edi,DWORD PTR [ebx+0x368]
  4c7bda:	85 ff                	test   edi,edi
  4c7bdc:	74 3b                	je     0x4c7c19
  4c7bde:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7be1:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  4c7be5:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7be8:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7bea:	50                   	push   eax
  4c7beb:	51                   	push   ecx
  4c7bec:	8d 75 f0             	lea    esi,[ebp-0x10]
  4c7bef:	8b c7                	mov    eax,edi
  4c7bf1:	e8 da be 36 00       	call   0x833ad0
  4c7bf6:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  4c7bfa:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7bfd:	50                   	push   eax
  4c7bfe:	e8 09 96 3c 00       	call   0x89120c
  4c7c03:	83 c4 04             	add    esp,0x4
  4c7c06:	57                   	push   edi
  4c7c07:	e8 00 96 3c 00       	call   0x89120c
  4c7c0c:	83 c4 04             	add    esp,0x4
  4c7c0f:	c7 83 68 03 00 00 00 	mov    DWORD PTR [ebx+0x368],0x0
  4c7c16:	00 00 00 
  4c7c19:	8b b3 60 01 00 00    	mov    esi,DWORD PTR [ebx+0x160]
  4c7c1f:	33 c0                	xor    eax,eax
  4c7c21:	89 83 60 01 00 00    	mov    DWORD PTR [ebx+0x160],eax
  4c7c27:	89 83 5c 01 00 00    	mov    DWORD PTR [ebx+0x15c],eax
  4c7c2d:	3b f0                	cmp    esi,eax
  4c7c2f:	74 29                	je     0x4c7c5a
  4c7c31:	8d 46 04             	lea    eax,[esi+0x4]
  4c7c34:	83 c9 ff             	or     ecx,0xffffffff
  4c7c37:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4c7c3b:	75 1d                	jne    0x4c7c5a
  4c7c3d:	8b 16                	mov    edx,DWORD PTR [esi]
  4c7c3f:	8b 02                	mov    eax,DWORD PTR [edx]
  4c7c41:	8b ce                	mov    ecx,esi
  4c7c43:	ff d0                	call   eax
  4c7c45:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c7c48:	83 ca ff             	or     edx,0xffffffff
  4c7c4b:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c7c4f:	75 09                	jne    0x4c7c5a
  4c7c51:	8b 06                	mov    eax,DWORD PTR [esi]
  4c7c53:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c7c56:	8b ce                	mov    ecx,esi
  4c7c58:	ff d2                	call   edx
```

### VA `0x007be5f0..0x007be653`
```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007be5f0 <.text+0x3bd5f0>:
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
  7be647:	b8 01 00 00 00       	mov    eax,0x1
  7be64c:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be652:	c3                   	ret
```

## 工作流程偽碼（受限版本）

```cpp
// 非原生原始碼，僅表達本輪已核對的條件與未知；不直接部署。
void T08_168_bounded_study() {
    // See machine-code windows and branch conditions above.
    // No claim of full execution, all callers, or server authority.
}
```

## 證據等級與未解條件

- 直接原始證據：上列 VA 視窗 machine code，由指定 SHA 的 PE bytes 產生。
- 有條件推論：call 前後欄位訪問所推之 ownership/cleanup 次序；虛擬函式未解析為固定 callee。
- 未驗證：執行期頻率、實體是否存在其他 owner、全部 caller 集、TCP/P2P authority、場景與 AI 決策、失敗回滾。
- 不修改 repo `task.json`、catalog、其他 Agent 筆記；新稿僅擬放 `kr-temp-roy/`。