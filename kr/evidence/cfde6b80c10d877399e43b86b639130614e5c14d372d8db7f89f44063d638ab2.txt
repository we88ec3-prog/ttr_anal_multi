# KR T08-165 — 基底 Actor 析構與欄位清理

- 研究者：`chatgpt-web roy`；本輪產檔時間：`20261028-021950` (Asia/Taipei)
- 基準：GitHub `main` 在本輪查核 commit `567e3ec82b826fafede56e2ee5e054a0b3ad798d`（提交前再查 HEAD）
- 原始來源：`Tartaros.bin` `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386 `.text` VA 0x401000/raw 0x400；完全唯讀
- 方法：GNU objdump 指定位址視窗；未啟動、附加或修改客戶端。`BYTE` 是目標 BIN 中直接的指令，`INFERENCE` 表示由機器碼推得的功能邊界
- 跨批次參考：`T08-153..164` 與 T01 整合來源審核，歷史報告是索引，不獨立替代原生 bytes

## 研究目的

基底 Actor 析構與欄位清理。此工作包聚焦正式 KR T08 的「物件建立／登記／移除資料介面」；不自行擴大成 AI 生成時機或遊戲規則。

## 主結論及推導
- `[BYTE]` `4C7BBD` 寫主 vptr `C07554`，`4C7BC3` 寫次 vptr `C075DC`；不是只釋放 heap 的小函式，而是覆寫 vtable 後的多步析構。
- `[BYTE]` `+368` 非零時呼叫 `833AD0` 清理內部容器，隨後 `89120C` 釋放兩個相關塊，且 `+368=0`。這只能證實本支路釋放次序，不保證所有 alias 不再引用。
- `[BYTE]` `+160` 取出後把 `+160/+15C` 清零，`lock xadd` 對兩個不同 +4/+8 引用計數進行遞減，僅特定零值分支派送 vptr+0/vptr+4；不可改稱固定 operator delete。
- `[BYTE]` `+364` 非零進入 `4C7DB0` helper，helper 對 `+24` 呼叫 `7BE5F0`，對 `+28` 非零順序派送虛擬 `+10`、重取後 `+8`，清 +28 並釋放外層。
- `[BYTE]` `+164` 起 128 槽，針對每個非零 item 呼叫 `7BE5F0`，對 item+28 的外掛对象兩階段解除，再釋放 item 本身，實際將 actor 的槽清零。
- `[BYTE]` 另銷毀 `+3F0`、`+378` 的嵌入式容器，及 `+F4` 起 25 個指標 slot 的 virtual slot0(flag1)，最後 `+158=0` 並改 vptr `C076AC`。**最後一步是 base 子物件結尾，而非已證整個 Actor 記憶體 free。**
- 此路徑和 `4C8360` 預清理不同：前者釋放 item+記憶體、清 actor slots；後者局部解除 binding 但並不清外層 actor slots。

## 限制
- 未動態確認 exception-unwind、`833AD0` 內部語意、`89120C` allocator identity；物件跨執行緒安全不可從 lock xadd 單獨推論。


## 可重現的機器碼摘錄

### VA `0x004c7b90..0x004c7db0`
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
  4c7c5a:	8b bb 64 03 00 00    	mov    edi,DWORD PTR [ebx+0x364]
  4c7c60:	85 ff                	test   edi,edi
  4c7c62:	74 0f                	je     0x4c7c73
  4c7c64:	e8 47 01 00 00       	call   0x4c7db0
  4c7c69:	c7 83 64 03 00 00 00 	mov    DWORD PTR [ebx+0x364],0x0
  4c7c70:	00 00 00 
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
  4c7cd2:	8d bb f0 03 00 00    	lea    edi,[ebx+0x3f0]
  4c7cd8:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7cdb:	c6 45 fc 06          	mov    BYTE PTR [ebp-0x4],0x6
  4c7cdf:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7ce2:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7ce4:	50                   	push   eax
  4c7ce5:	51                   	push   ecx
  4c7ce6:	8d 75 f0             	lea    esi,[ebp-0x10]
  4c7ce9:	8b c7                	mov    eax,edi
  4c7ceb:	e8 d0 c3 08 00       	call   0x5540c0
  4c7cf0:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  4c7cf3:	57                   	push   edi
  4c7cf4:	e8 13 95 3c 00       	call   0x89120c
  4c7cf9:	8d bb 78 03 00 00    	lea    edi,[ebx+0x378]
  4c7cff:	83 c4 04             	add    esp,0x4
  4c7d02:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  4c7d05:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  4c7d09:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4c7d0c:	8b 08                	mov    ecx,DWORD PTR [eax]
  4c7d0e:	50                   	push   eax
  4c7d0f:	51                   	push   ecx
  4c7d10:	8d 75 f0             	lea    esi,[ebp-0x10]
  4c7d13:	8b c7                	mov    eax,edi
  4c7d15:	e8 46 24 00 00       	call   0x4ca160
  4c7d1a:	8b 7f 04             	mov    edi,DWORD PTR [edi+0x4]
  4c7d1d:	57                   	push   edi
  4c7d1e:	e8 e9 94 3c 00       	call   0x89120c
  4c7d23:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4c7d27:	8b b3 60 01 00 00    	mov    esi,DWORD PTR [ebx+0x160]
  4c7d2d:	83 c4 04             	add    esp,0x4
  4c7d30:	85 f6                	test   esi,esi
  4c7d32:	74 29                	je     0x4c7d5d
  4c7d34:	8d 56 04             	lea    edx,[esi+0x4]
  4c7d37:	83 c8 ff             	or     eax,0xffffffff
  4c7d3a:	f0 0f c1 02          	lock xadd DWORD PTR [edx],eax
  4c7d3e:	75 1d                	jne    0x4c7d5d
  4c7d40:	8b 16                	mov    edx,DWORD PTR [esi]
  4c7d42:	8b 02                	mov    eax,DWORD PTR [edx]
  4c7d44:	8b ce                	mov    ecx,esi
  4c7d46:	ff d0                	call   eax
  4c7d48:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c7d4b:	83 ca ff             	or     edx,0xffffffff
  4c7d4e:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c7d52:	75 09                	jne    0x4c7d5d
  4c7d54:	8b 06                	mov    eax,DWORD PTR [esi]
  4c7d56:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c7d59:	8b ce                	mov    ecx,esi
  4c7d5b:	ff d2                	call   edx
  4c7d5d:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  4c7d61:	c7 83 f0 00 00 00 fc 	mov    DWORD PTR [ebx+0xf0],0xc075fc
  4c7d68:	75 c0 00 
  4c7d6b:	8d b3 f4 00 00 00    	lea    esi,[ebx+0xf4]
  4c7d71:	bf 19 00 00 00       	mov    edi,0x19
  4c7d76:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4c7d78:	85 c9                	test   ecx,ecx
  4c7d7a:	74 0e                	je     0x4c7d8a
  4c7d7c:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c7d7e:	8b 10                	mov    edx,DWORD PTR [eax]
  4c7d80:	6a 01                	push   0x1
  4c7d82:	ff d2                	call   edx
  4c7d84:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  4c7d8a:	83 c6 04             	add    esi,0x4
  4c7d8d:	4f                   	dec    edi
  4c7d8e:	75 e6                	jne    0x4c7d76
  4c7d90:	89 bb 58 01 00 00    	mov    DWORD PTR [ebx+0x158],edi
  4c7d96:	c7 03 ac 76 c0 00    	mov    DWORD PTR [ebx],0xc076ac
  4c7d9c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c7d9f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c7da6:	59                   	pop    ecx
  4c7da7:	5f                   	pop    edi
  4c7da8:	5e                   	pop    esi
  4c7da9:	5b                   	pop    ebx
  4c7daa:	8b e5                	mov    esp,ebp
  4c7dac:	5d                   	pop    ebp
  4c7dad:	c3                   	ret
  4c7dae:	cc                   	int3
  4c7daf:	cc                   	int3
```

## 工作流程偽碼（受限版本）

```cpp
// 非原生原始碼，僅表達本輪已核對的條件與未知；不直接部署。
void T08_165_bounded_study() {
    // See machine-code windows and branch conditions above.
    // No claim of full execution, all callers, or server authority.
}
```

## 證據等級與未解條件

- 直接原始證據：上列 VA 視窗 machine code，由指定 SHA 的 PE bytes 產生。
- 有條件推論：call 前後欄位訪問所推之 ownership/cleanup 次序；虛擬函式未解析為固定 callee。
- 未驗證：執行期頻率、實體是否存在其他 owner、全部 caller 集、TCP/P2P authority、場景與 AI 決策、失敗回滾。
- 不修改 repo `task.json`、catalog、其他 Agent 筆記；新稿僅擬放 `kr-temp-roy/`。