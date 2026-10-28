# T08-198 — 類型條件篩選與 actor 次級介面移除

- 日期：2026-10-28（Asia/Taipei），研究者：`chatgpt-web roy`
- 原始 KR `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際重新計算）。
- PE `.text` VA `0x00401000`, raw `0x400`; `objdump -d -Mintel` 針對原始 BIN 以 VA 指定範圍。
- 參照：T08-193～196 本地完整版、GitHub `main` T08-192；源碼來源與研究推論分開。
- Task 範圍：正式 T08 0007 的實體建立、登記、移除資料介面；不推定伺服器波次、生成時間或 AI。

## 一、T08-198 第一輪新證據

1. `0x004DFD73` 從 payload+0x04 讀 byte，和參數中的 16-bit 值比較；比較寬度本身不同，不能無條件視為同一 uint16 欄位。
2. `0x004DFD87～0x004DFD99` 只接受低 byte 值 `1/6/0/7` 的一組分支；仍不可命名為官方職業、怪物或權限分類。
3. `0x004DFD9B` 讀 actor+0x15C，後續再評估其子結構；可連接 T08-195 的次級介面疑點，但仍須識別 vtable。
4. 匹配路徑清理 actor 後呼叫 `0x007B6890` 刪除樹節點；未匹配路徑是紅黑樹巡訪，沒有立即刪除。

## 二、函式／欄位與控制流程

本批只對原始 BIN 視窗中具體指令、參數、條件及跳躍地址作直接結論。`node+0x10` 指標的真實型別須沿構造路徑核對；相同 offset 不代表不同 owner 具有同一語意。虛擬呼叫 `FF /2` 的靜態槽位已知但動態目標不一定唯一，不得把 CMonster 的主表套至其他實體。

## 三、三輪深入規則

**第一輪已達重大進展：** 重大進展：定出明確的條件式 actor 移除前置 predicate，並分離篩選與清理。

依 02 共用規範，T08-198-2、T08-198-3 **未啟動**。完整報告記錄了實際第一輪，未虛構進一步研究。

## 四、可驗證等級

- **已確認：** 本檔附錄原始 PE `.text` bytes 的有界解碼、分支條件、對象存取偏移及 direct E8 / indirect vtable 區分。
- **部分確認：** 樹 payload 動態類別、兩套樹是否共享同一物件、全路徑析構防重覆策略。
- **未確認：** runtime 觸發順序、所有異常分支及 server 權威決策；沒有導入 AI 遊戲規則或保證所有個案相同。

## 五、後續函式及交接

後續應由插入者追索 `node+0x10` 的 allocation provenance；對 `+0x15C` 子物件追 vptr 寫入；對兩棵樹相同 actor pointer 的所有權與同步刪除做有界 alias 交叉驗證。不得把本檔局部 CFG 視為整個遊戲生命週期全閉合。

## 六、完整原始 BIN 反組譯節錄

### 視窗 1: `0x004DFD40..0x004DFE00`

```asm
004dfd40 <.text+0xded40>:
  4dfd40:	55                   	push   ebp
  4dfd41:	8b ec                	mov    ebp,esp
  4dfd43:	83 e4 f8             	and    esp,0xfffffff8
  4dfd46:	83 ec 18             	sub    esp,0x18
  4dfd49:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4dfd4c:	83 c1 08             	add    ecx,0x8
  4dfd4f:	56                   	push   esi
  4dfd50:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfd52:	57                   	push   edi
  4dfd53:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  4dfd57:	3b f0                	cmp    esi,eax
  4dfd59:	0f 84 23 01 00 00    	je     0x4dfe82
  4dfd5f:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfd66:	00 
  4dfd67:	eb 07                	jmp    0x4dfd70
  4dfd69:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfd70:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4dfd73:	0f b6 50 04          	movzx  edx,BYTE PTR [eax+0x4]
  4dfd77:	66 3b 55 08          	cmp    dx,WORD PTR [ebp+0x8]
  4dfd7b:	0f 85 b8 00 00 00    	jne    0x4dfe39
  4dfd81:	8b f8                	mov    edi,eax
  4dfd83:	85 ff                	test   edi,edi
  4dfd85:	74 72                	je     0x4dfdf9
  4dfd87:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dfd8b:	3c 01                	cmp    al,0x1
  4dfd8d:	74 0c                	je     0x4dfd9b
  4dfd8f:	3c 06                	cmp    al,0x6
  4dfd91:	74 08                	je     0x4dfd9b
  4dfd93:	84 c0                	test   al,al
  4dfd95:	74 04                	je     0x4dfd9b
  4dfd97:	3c 07                	cmp    al,0x7
  4dfd99:	75 5e                	jne    0x4dfdf9
  4dfd9b:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfda1:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4dfda7:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4dfdad:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4dfdb3:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4dfdb9:	85 c0                	test   eax,eax
  4dfdbb:	74 3c                	je     0x4dfdf9
  4dfdbd:	83 bf 70 03 00 00 00 	cmp    DWORD PTR [edi+0x370],0x0
  4dfdc4:	74 33                	je     0x4dfdf9
  4dfdc6:	6a 00                	push   0x0
  4dfdc8:	50                   	push   eax
  4dfdc9:	e8 f2 7e 2c 00       	call   0x7a7cc0
  4dfdce:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4dfdd2:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4dfdd6:	83 ec 10             	sub    esp,0x10
  4dfdd9:	8b c4                	mov    eax,esp
  4dfddb:	89 08                	mov    DWORD PTR [eax],ecx
  4dfddd:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4dfde1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4dfde4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4dfde8:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4dfdeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dfdee:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfdf4:	e8 f7 7d 2c 00       	call   0x7a7bf0
  4dfdf9:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfdfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfdfe:	8b                   	.byte 0x8b
  4dfdff:	50                   	push   eax
```
### 視窗 2: `0x004DFE00..0x004DFE90`

```asm
004dfe00 <.text+0xdee00>:
  4dfe00:	14 ff                	adc    al,0xff
  4dfe02:	d2 8b 4e 10 85 c9    	ror    BYTE PTR [ebx-0x367aefb2],cl
  4dfe08:	74 0f                	je     0x4dfe19
  4dfe0a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfe0c:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfe0e:	6a 01                	push   0x1
  4dfe10:	ff d2                	call   edx
  4dfe12:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfe19:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe1d:	56                   	push   esi
  4dfe1e:	8d 44 24 10          	lea    eax,[esp+0x10]
  4dfe22:	50                   	push   eax
  4dfe23:	51                   	push   ecx
  4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
  4dfe29:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe2b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfe32:	00 
  4dfe33:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe37:	eb 40                	jmp    0x4dfe79
  4dfe39:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfe3d:	75 3a                	jne    0x4dfe79
  4dfe3f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfe42:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe46:	75 16                	jne    0x4dfe5e
  4dfe48:	8b f0                	mov    esi,eax
  4dfe4a:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe4c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe50:	75 27                	jne    0x4dfe79
  4dfe52:	8b f0                	mov    esi,eax
  4dfe54:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe56:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe5a:	74 f6                	je     0x4dfe52
  4dfe5c:	eb 1b                	jmp    0x4dfe79
  4dfe5e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfe61:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe65:	75 10                	jne    0x4dfe77
  4dfe67:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfe6a:	75 0b                	jne    0x4dfe77
  4dfe6c:	8b f0                	mov    esi,eax
  4dfe6e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfe71:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe75:	74 f0                	je     0x4dfe67
  4dfe77:	8b f0                	mov    esi,eax
  4dfe79:	3b 71 04             	cmp    esi,DWORD PTR [ecx+0x4]
  4dfe7c:	0f 85 ee fe ff ff    	jne    0x4dfd70
  4dfe82:	5f                   	pop    edi
  4dfe83:	5e                   	pop    esi
  4dfe84:	8b e5                	mov    esp,ebp
  4dfe86:	5d                   	pop    ebp
  4dfe87:	c2 04 00             	ret    0x4
  4dfe8a:	cc                   	int3
  4dfe8b:	cc                   	int3
  4dfe8c:	cc                   	int3
  4dfe8d:	cc                   	int3
  4dfe8e:	cc                   	int3
  4dfe8f:	cc                   	int3
```