# T08-200 — 主索引登記 key、重複分支與生命週期邊界

- 日期：2026-10-28（Asia/Taipei），研究者：`chatgpt-web roy`
- 原始 KR `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際重新計算）。
- PE `.text` VA `0x00401000`, raw `0x400`; `objdump -d -Mintel` 針對原始 BIN 以 VA 指定範圍。
- 參照：T08-193～196 本地完整版、GitHub `main` T08-192；源碼來源與研究推論分開。
- Task 範圍：正式 T08 0007 的實體建立、登記、移除資料介面；不推定伺服器波次、生成時間或 AI。

## 一、T08-200 第一輪新證據

1. `0x004DFF4C` 使用 `movzx eax,WORD PTR [actor+4]`，將 16 位 key 放入查找引數；此欄位與 actor+0x88 複合 ID 比對不是同一索引。
2. `0x004DFF5F` 用 `0x0082EF00` 查找主樹，僅在結果等於 `[owner+0x0C]` sentinel 時執行 `0x0082F200` 插入。
3. 若 key 已存在，`0x004DFF90` 走 `0x006EDB60` 訊息處理分支；**沒有**在此分支建立替換 actor 或釋放新 actor 的直接呼叫。
4. 對照 `0x004DFBC0` 查找、清理、刪節點，可建立相同 key 協定，但不能推定重複登記時新 actor 的上游記憶體責任。

## 二、函式／欄位與控制流程

本批只對原始 BIN 視窗中具體指令、參數、條件及跳躍地址作直接結論。`node+0x10` 指標的真實型別須沿構造路徑核對；相同 offset 不代表不同 owner 具有同一語意。虛擬呼叫 `FF /2` 的靜態槽位已知但動態目標不一定唯一，不得把 CMonster 的主表套至其他實體。

## 三、三輪深入規則

**第一輪已達重大進展：** 重大進展：主樹 key 的 16-bit 正規化、duplicate branch 與 actor ownership 未解邊界同步確認。

依 02 共用規範，T08-200-2、T08-200-3 **未啟動**。完整報告記錄了實際第一輪，未虛構進一步研究。

## 四、可驗證等級

- **已確認：** 本檔附錄原始 PE `.text` bytes 的有界解碼、分支條件、對象存取偏移及 direct E8 / indirect vtable 區分。
- **部分確認：** 樹 payload 動態類別、兩套樹是否共享同一物件、全路徑析構防重覆策略。
- **未確認：** runtime 觸發順序、所有異常分支及 server 權威決策；沒有導入 AI 遊戲規則或保證所有個案相同。

## 五、後續函式及交接

後續應由插入者追索 `node+0x10` 的 allocation provenance；對 `+0x15C` 子物件追 vptr 寫入；對兩棵樹相同 actor pointer 的所有權與同步刪除做有界 alias 交叉驗證。不得把本檔局部 CFG 視為整個遊戲生命週期全閉合。

## 六、完整原始 BIN 反組譯節錄

### 視窗 1: `0x004DFF30..0x004DFFA9`

```asm
004dff30 <.text+0xdef30>:
  4dff30:	55                   	push   ebp
  4dff31:	8b ec                	mov    ebp,esp
  4dff33:	83 ec 10             	sub    esp,0x10
  4dff36:	53                   	push   ebx
  4dff37:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dff3a:	56                   	push   esi
  4dff3b:	57                   	push   edi
  4dff3c:	8b f8                	mov    edi,eax
  4dff3e:	85 ff                	test   edi,edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dff50:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dff53:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4dff56:	8d 73 08             	lea    esi,[ebx+0x8]
  4dff59:	51                   	push   ecx
  4dff5a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dff5d:	8b ce                	mov    ecx,esi
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4dff67:	3b 53 0c             	cmp    edx,DWORD PTR [ebx+0xc]
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dff6f:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4dff72:	8d 7d f4             	lea    edi,[ebp-0xc]
  4dff75:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   eax
  4dff7e:	56                   	push   esi
  4dff7f:	8d 75 f4             	lea    esi,[ebp-0xc]
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    edi
  4dff88:	5e                   	pop    esi
  4dff89:	5b                   	pop    ebx
  4dff8a:	8b e5                	mov    esp,ebp
  4dff8c:	5d                   	pop    ebp
  4dff8d:	c2 04 00             	ret    0x4
  4dff90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4dff93:	51                   	push   ecx
  4dff94:	68 f0 ce c0 00       	push   0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    esp,0x8
  4dffa1:	5f                   	pop    edi
  4dffa2:	5e                   	pop    esi
  4dffa3:	5b                   	pop    ebx
  4dffa4:	8b e5                	mov    esp,ebp
  4dffa6:	5d                   	pop    ebp
  4dffa7:	c2                   	.byte 0xc2
  4dffa8:	04                   	.byte 0x4
```
### 視窗 2: `0x004DFBC0..0x004DFC2C`

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
### 視窗 3: `0x004DFC30..0x004DFC90`

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