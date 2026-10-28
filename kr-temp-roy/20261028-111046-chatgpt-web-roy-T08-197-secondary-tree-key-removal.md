# T08-197 — 次級樹 key 查找、刪除及 payload 所有權

- 日期：2026-10-28（Asia/Taipei），研究者：`chatgpt-web roy`
- 原始 KR `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際重新計算）。
- PE `.text` VA `0x00401000`, raw `0x400`; `objdump -d -Mintel` 針對原始 BIN 以 VA 指定範圍。
- 參照：T08-193～196 本地完整版、GitHub `main` T08-192；源碼來源與研究推論分開。
- Task 範圍：正式 T08 0007 的實體建立、登記、移除資料介面；不推定伺服器波次、生成時間或 AI。

## 一、T08-197 第一輪新證據

1. `0x004DFC30` 將查找基底設為 `[ESI+0x18]`，以 `0x008438C0` 查找，和主樹 `0x0082EF00` 不同。
2. `0x004DFC4F` 讀取 `[ESI+0xF8]`，只有其指向值等於傳入 key 時才清空該快取指標。
3. `0x004DFC6A` 對 `node+0x10` payload 直接傳 `0x0089120C`，此路徑**沒有** actor vtable +0x14 / +0x00 分派。
4. `0x004DFC90` 遍歷 `[EAX+0x08]` 的樹，條件以 `payload+0x88 == [EBP+0x08]` 過濾；匹配才虛擬預清理及刪除。

## 二、函式／欄位與控制流程

本批只對原始 BIN 視窗中具體指令、參數、條件及跳躍地址作直接結論。`node+0x10` 指標的真實型別須沿構造路徑核對；相同 offset 不代表不同 owner 具有同一語意。虛擬呼叫 `FF /2` 的靜態槽位已知但動態目標不一定唯一，不得把 CMonster 的主表套至其他實體。

## 三、三輪深入規則

**第一輪已達重大進展：** 重大進展：明確區分兩種樹 payload 的不同釋放 ABI，排除跨樹同一析構式的假設。

依 02 共用規範，T08-197-2、T08-197-3 **未啟動**。完整報告記錄了實際第一輪，未虛構進一步研究。

## 四、可驗證等級

- **已確認：** 本檔附錄原始 PE `.text` bytes 的有界解碼、分支條件、對象存取偏移及 direct E8 / indirect vtable 區分。
- **部分確認：** 樹 payload 動態類別、兩套樹是否共享同一物件、全路徑析構防重覆策略。
- **未確認：** runtime 觸發順序、所有異常分支及 server 權威決策；沒有導入 AI 遊戲規則或保證所有個案相同。

## 五、後續函式及交接

後續應由插入者追索 `node+0x10` 的 allocation provenance；對 `+0x15C` 子物件追 vptr 寫入；對兩棵樹相同 actor pointer 的所有權與同步刪除做有界 alias 交叉驗證。不得把本檔局部 CFG 視為整個遊戲生命週期全閉合。

## 六、完整原始 BIN 反組譯節錄

### 視窗 1: `0x004DFC30..0x004DFC90`

```asm
004dfc30 <.text+0xdec30>:
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