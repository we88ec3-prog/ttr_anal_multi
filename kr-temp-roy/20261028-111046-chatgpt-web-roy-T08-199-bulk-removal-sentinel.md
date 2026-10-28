# T08-199 — 整表移除與條件移除之 iterator／sentinel 契約

- 日期：2026-10-28（Asia/Taipei），研究者：`chatgpt-web roy`
- 原始 KR `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際重新計算）。
- PE `.text` VA `0x00401000`, raw `0x400`; `objdump -d -Mintel` 針對原始 BIN 以 VA 指定範圍。
- 參照：T08-193～196 本地完整版、GitHub `main` T08-192；源碼來源與研究推論分開。
- Task 範圍：正式 T08 0007 的實體建立、登記、移除資料介面；不推定伺服器波次、生成時間或 AI。

## 一、T08-199 第一輪新證據

1. `0x004DFE94` 取主樹的 sentinel `[owner+0x0C]`，從 `[sentinel]` 起迭代；`0x004DFF02` 比對 iterator 與 sentinel。
2. `0x004DFEA2` 取 `node+0x10` 的 actor；非空先呼叫 `vptr+0x14` 再 `vptr+0x00(1)`，後由 `0x00823850` 整體清樹。
3. `0x004DFF0F` 的全域 callback 虛擬槽 `+0x14` 是整表路徑附加動作；不能當作 actor 的 +0x14。
4. `0x004DFC90` 是走查期間單節點 erase，呼叫 `0x007B6890` 後使用回傳 iterator 重置；與整表 `0x00823850` 有不同迭代安全策略。

## 二、函式／欄位與控制流程

本批只對原始 BIN 視窗中具體指令、參數、條件及跳躍地址作直接結論。`node+0x10` 指標的真實型別須沿構造路徑核對；相同 offset 不代表不同 owner 具有同一語意。虛擬呼叫 `FF /2` 的靜態槽位已知但動態目標不一定唯一，不得把 CMonster 的主表套至其他實體。

## 三、三輪深入規則

**第一輪已達重大進展：** 重大進展：確定批量清空與有條件刪除使用不同的 iterator-erase 契約。

依 02 共用規範，T08-199-2、T08-199-3 **未啟動**。完整報告記錄了實際第一輪，未虛構進一步研究。

## 四、可驗證等級

- **已確認：** 本檔附錄原始 PE `.text` bytes 的有界解碼、分支條件、對象存取偏移及 direct E8 / indirect vtable 區分。
- **部分確認：** 樹 payload 動態類別、兩套樹是否共享同一物件、全路徑析構防重覆策略。
- **未確認：** runtime 觸發順序、所有異常分支及 server 權威決策；沒有導入 AI 遊戲規則或保證所有個案相同。

## 五、後續函式及交接

後續應由插入者追索 `node+0x10` 的 allocation provenance；對 `+0x15C` 子物件追 vptr 寫入；對兩棵樹相同 actor pointer 的所有權與同步刪除做有界 alias 交叉驗證。不得把本檔局部 CFG 視為整個遊戲生命週期全閉合。

## 六、完整原始 BIN 反組譯節錄

### 視窗 1: `0x004DFE90..0x004DFF24`

```asm
004dfe90 <.text+0xdee90>:
  4dfe90:	55                   	push   ebp
  4dfe91:	8b ec                	mov    ebp,esp
  4dfe93:	53                   	push   ebx
  4dfe94:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dfe97:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  4dfe9a:	56                   	push   esi
  4dfe9b:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe9d:	57                   	push   edi
  4dfe9e:	3b f0                	cmp    esi,eax
  4dfea0:	74 65                	je     0x4dff07
  4dfea2:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  4dfea5:	85 ff                	test   edi,edi
  4dfea7:	74 13                	je     0x4dfebc
  4dfea9:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeab:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfeae:	8b cf                	mov    ecx,edi
  4dfeb0:	ff d2                	call   edx
  4dfeb2:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeb4:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfeb6:	6a 01                	push   0x1
  4dfeb8:	8b cf                	mov    ecx,edi
  4dfeba:	ff d2                	call   edx
  4dfebc:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfec0:	75 40                	jne    0x4dff02
  4dfec2:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfec5:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfec9:	75 16                	jne    0x4dfee1
  4dfecb:	8b f0                	mov    esi,eax
  4dfecd:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfecf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfed3:	75 2d                	jne    0x4dff02
  4dfed5:	8b f0                	mov    esi,eax
  4dfed7:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfed9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfedd:	74 f6                	je     0x4dfed5
  4dfedf:	eb 21                	jmp    0x4dff02
  4dfee1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfee4:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfee8:	75 16                	jne    0x4dff00
  4dfeea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4dfef0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfef3:	75 0b                	jne    0x4dff00
  4dfef5:	8b f0                	mov    esi,eax
  4dfef7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfefa:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfefe:	74 f0                	je     0x4dfef0
  4dff00:	8b f0                	mov    esi,eax
  4dff02:	3b 73 0c             	cmp    esi,DWORD PTR [ebx+0xc]
  4dff05:	75 9b                	jne    0x4dfea2
  4dff07:	8d 7b 08             	lea    edi,[ebx+0x8]
  4dff0a:	e8 41 39 34 00       	call   0x823850
  4dff0f:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dff15:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dff17:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dff1a:	ff d2                	call   edx
  4dff1c:	5f                   	pop    edi
  4dff1d:	5e                   	pop    esi
  4dff1e:	5b                   	pop    ebx
  4dff1f:	5d                   	pop    ebp
  4dff20:	c2 04 00             	ret    0x4
  4dff23:	cc                   	int3
```
### 視窗 2: `0x004DFC90..0x004DFD38`

```asm
004dfc90 <.text+0xdec90>:
  4dfc90:	55                   	push   ebp
  4dfc91:	8b ec                	mov    ebp,esp
  4dfc93:	51                   	push   ecx
  4dfc94:	56                   	push   esi
  4dfc95:	57                   	push   edi
  4dfc96:	8d 78 08             	lea    edi,[eax+0x8]
  4dfc99:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4dfc9c:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfc9e:	3b f0                	cmp    esi,eax
  4dfca0:	0f 84 89 00 00 00    	je     0x4dfd2f
  4dfca6:	eb 08                	jmp    0x4dfcb0
  4dfca8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfcaf:	90                   	nop
  4dfcb0:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dfcb6:	39 81 88 00 00 00    	cmp    DWORD PTR [ecx+0x88],eax
  4dfcbc:	75 2c                	jne    0x4dfcea
  4dfcbe:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcc0:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfcc3:	ff d0                	call   eax
  4dfcc5:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcc8:	85 c9                	test   ecx,ecx
  4dfcca:	74 0f                	je     0x4dfcdb
  4dfccc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcce:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfcd0:	6a 01                	push   0x1
  4dfcd2:	ff d0                	call   eax
  4dfcd4:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfcdb:	56                   	push   esi
  4dfcdc:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4dfcdf:	51                   	push   ecx
  4dfce0:	57                   	push   edi
  4dfce1:	e8 aa 6b 2d 00       	call   0x7b6890
  4dfce6:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfce8:	eb 40                	jmp    0x4dfd2a
  4dfcea:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfcee:	75 3a                	jne    0x4dfd2a
  4dfcf0:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfcf3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfcf7:	75 16                	jne    0x4dfd0f
  4dfcf9:	8b f0                	mov    esi,eax
  4dfcfb:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfcfd:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd01:	75 27                	jne    0x4dfd2a
  4dfd03:	8b f0                	mov    esi,eax
  4dfd05:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfd07:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd0b:	74 f6                	je     0x4dfd03
  4dfd0d:	eb 1b                	jmp    0x4dfd2a
  4dfd0f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfd12:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd16:	75 10                	jne    0x4dfd28
  4dfd18:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfd1b:	75 0b                	jne    0x4dfd28
  4dfd1d:	8b f0                	mov    esi,eax
  4dfd1f:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfd22:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd26:	74 f0                	je     0x4dfd18
  4dfd28:	8b f0                	mov    esi,eax
  4dfd2a:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  4dfd2d:	75 81                	jne    0x4dfcb0
  4dfd2f:	5f                   	pop    edi
  4dfd30:	5e                   	pop    esi
  4dfd31:	8b e5                	mov    esp,ebp
  4dfd33:	5d                   	pop    ebp
  4dfd34:	c2 04 00             	ret    0x4
  4dfd37:	cc                   	int3
```
### 視窗 3: `0x004DFBC0..0x004DFC2C`

```asm
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
```