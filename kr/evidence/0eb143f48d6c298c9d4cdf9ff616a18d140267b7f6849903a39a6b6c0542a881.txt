# T10-37 — 型別驅動工廠與新物件初始化、註冊邊界（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 新確認的證據與具體資料流
1. 【確認】`0x4AE5D4` 限制 index <=7，`0x4AE5DD` 使用 `0x4AED90` 跳轉表。只有落在 `0x4AE5E4` 分支時，配置 `0x444` 並呼叫 `0x4CD6F0`；不能將所有 0..7 類型一律判定為此 actor 類。
2. 【確認】`0x4AE604–0x4AE609` 從輸入記錄 `[ebx+0x0E]` 讀 32-bit 值、與配置指標一併傳給 ctor；`0x4AE610` 的 `esi` 保存 ctor 返回值，供之後分支共用。這是新物件指標從建立到初始化的可直接追溯段。
3. 【確認】`0x4AE917` 檢查 `esi!=0`，之後依 `[ebx]` 的 WORD 值，透過 `0x515790` 查全域 `0xFC0E90` 的資料樹；`0x4AE98A` 還透過 `[0xFBA7A4]` 的 vtable+0x20 取得外部物件。這些是建立後的依賴查找，不得未經證明命名為 entity registry 寫入。
4. 【確認】`0x4AEAA4` 以 `[ebx]` WORD 呼叫 `0x541610`；`0x4AEAE5` 透過 `0x4F7A70` 取得索引結果並取 result+0x61，存入新物件 `+0x41C`。此欄位的資料來源與控制器 `+0x3E8` 不同。
5. 【確認】`0x4AEB0A..0x4AEB30`：新物件 `+0x9C←[ebx+0x0E]`、`+0x90←BYTE[ebx+0x14]`、`+0x04←WORD[ebx-0x04]`。隨後對同一 `esi` receiver 連續呼叫 vtable `+0x3C/+0x44/+0x58/+0x5C/+0x30`（`0x4AEB34..0x4AEB7D`）。**這是從 factory 到初始化虛擬方法的同一物件身分鏈**，但沒有 +0x2C setter 的呼叫。
6. 【確認】`0x4AE9xx` 的檢索檢查與 `0x4AEBxx` 欄位填充在同一函式中；【未知】此記錄由封包、場景檔還是其他來源產生。不能將其當成玩家攻擊按鍵輸入。
## 局部偽碼（按目前已追出的分支）
```cpp
if (type <= 7) switch(type) {
 case /* jump-table arm at 0x4AE5E4 */:
    p = allocate(0x444);
    actor = p ? ctor_4CD6F0(p, record->field_0E) : nullptr;
    break;
 // other arms allocate different types
}
if (!actor) goto exit;
// global lookups and conditional dependencies
actor->field_41C = lookup(...)->byte_61;
actor->field_9C = record->field_0E;
actor->field_90 = record->byte_14;
actor->field_04 = record->word_minus_04;
actor->vfunc_3C(...);
actor->vfunc_44(...);
actor->vfunc_58(record->byte_12);
actor->vfunc_5C(record->float_0A);
actor->vfunc_30();
```
## 排除與待查
- 不能把出現在這個 constructor 尾端的虛擬方法序列直接當作 `vfunc_2C(selector=5)`。
- 下一研究入口：`0x4DFF30` 和 `0x4AEC4A` 後續的對象歸屬、`0x4AE5C0` 輸入 record 的生產者，另找導致 `+0x2C` virtual call 的具體 receiver 資料流。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x4ae5d0–0x4ae66d
```asm
004ae5d0 <.text+0xad5d0>:
  4ae5d0:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  4ae5d4:	83 f8 07             	cmp    eax,0x7
  4ae5d7:	0f 87 a6 07 00 00    	ja     0x4aed83
  4ae5dd:	ff 24 85 90 ed 4a 00 	jmp    DWORD PTR [eax*4+0x4aed90]
  4ae5e4:	68 44 04 00 00       	push   0x444
  4ae5e9:	e8 7a 2c 3e 00       	call   0x891268
  4ae5ee:	83 c4 04             	add    esp,0x4
  4ae5f1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae5f5:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x1
  4ae5fc:	01 00 00 00 
  4ae600:	85 c0                	test   eax,eax
  4ae602:	74 0e                	je     0x4ae612
  4ae604:	8b 53 0e             	mov    edx,DWORD PTR [ebx+0xe]
  4ae607:	52                   	push   edx
  4ae608:	50                   	push   eax
  4ae609:	e8 e2 f0 01 00       	call   0x4cd6f0
  4ae60e:	8b f0                	mov    esi,eax
  4ae610:	eb 02                	jmp    0x4ae614
  4ae612:	33 f6                	xor    esi,esi
  4ae614:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae61b:	ff ff ff ff 
  4ae61f:	e8 7c 65 f5 ff       	call   0x404ba0
  4ae624:	8b 80 50 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f50]
  4ae62a:	39 43 0e             	cmp    DWORD PTR [ebx+0xe],eax
  4ae62d:	0f 85 e4 02 00 00    	jne    0x4ae917
  4ae633:	e8 68 65 f5 ff       	call   0x404ba0
  4ae638:	8b 90 24 69 00 00    	mov    edx,DWORD PTR [eax+0x6924]
  4ae63e:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  4ae641:	83 f8 09             	cmp    eax,0x9
  4ae644:	0f 87 cd 02 00 00    	ja     0x4ae917
  4ae64a:	8b c8                	mov    ecx,eax
  4ae64c:	69 c9 10 02 00 00    	imul   ecx,ecx,0x210
  4ae652:	03 ca                	add    ecx,edx
  4ae654:	0f 84 bd 02 00 00    	je     0x4ae917
  4ae65a:	83 79 5c 00          	cmp    DWORD PTR [ecx+0x5c],0x0
  4ae65e:	0f 85 b3 02 00 00    	jne    0x4ae917
  4ae664:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ae666:	50                   	push   eax
  4ae667:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4ae66a:	ff d0                	call   eax
  4ae66c:	e9                   	.byte 0xe9
```

### VA 0x4ae917–0x4aea10
```asm
004ae917 <.text+0xad917>:
  4ae917:	85 f6                	test   esi,esi
  4ae919:	0f 84 64 04 00 00    	je     0x4aed83
  4ae91f:	f6 05 60 0f fc 00 01 	test   BYTE PTR ds:0xfc0f60,0x1
  4ae926:	75 2f                	jne    0x4ae957
  4ae928:	83 0d 60 0f fc 00 01 	or     DWORD PTR ds:0xfc0f60,0x1
  4ae92f:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x8
  4ae936:	08 00 00 00 
  4ae93a:	e8 01 e6 2e 00       	call   0x79cf40
  4ae93f:	68 80 db bc 00       	push   0xbcdb80
  4ae944:	e8 d1 39 3e 00       	call   0x89231a
  4ae949:	83 c4 04             	add    esp,0x4
  4ae94c:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae953:	ff ff ff ff 
  4ae957:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  4ae95a:	8d 44 24 14          	lea    eax,[esp+0x14]
  4ae95e:	50                   	push   eax
  4ae95f:	8d 44 24 30          	lea    eax,[esp+0x30]
  4ae963:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  4ae968:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4ae96c:	e8 1f 6e 06 00       	call   0x515790
  4ae971:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  4ae975:	3b 05 94 0e fc 00    	cmp    eax,DWORD PTR ds:0xfc0e94
  4ae97b:	74 0d                	je     0x4ae98a
  4ae97d:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4ae980:	83 78 54 00          	cmp    DWORD PTR [eax+0x54],0x0
  4ae984:	0f 85 23 01 00 00    	jne    0x4aeaad
  4ae98a:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4ae990:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ae992:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  4ae995:	ff d0                	call   eax
  4ae997:	85 c0                	test   eax,eax
  4ae999:	0f 84 cd 00 00 00    	je     0x4aea6c
  4ae99f:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4ae9a6:	8b 88 9c 00 00 00    	mov    ecx,DWORD PTR [eax+0x9c]
  4ae9ac:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4ae9b0:	75 2f                	jne    0x4ae9e1
  4ae9b2:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4ae9b9:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x9
  4ae9c0:	09 00 00 00 
  4ae9c4:	e8 c7 02 03 00       	call   0x4dec90
  4ae9c9:	68 30 ce bc 00       	push   0xbcce30
  4ae9ce:	e8 47 39 3e 00       	call   0x89231a
  4ae9d3:	83 c4 04             	add    esp,0x4
  4ae9d6:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae9dd:	ff ff ff ff 
  4ae9e1:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4ae9e5:	8d 44 24 14          	lea    eax,[esp+0x14]
  4ae9e9:	50                   	push   eax
  4ae9ea:	8d 44 24 38          	lea    eax,[esp+0x38]
  4ae9ee:	b9 48 b1 fa 00       	mov    ecx,0xfab148
  4ae9f3:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4ae9f7:	e8 c4 4e 39 00       	call   0x8438c0
  4ae9fc:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  4aea00:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
  4aea06:	74 64                	je     0x4aea6c
  4aea08:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4aea0b:	85 c0                	test   eax,eax
  4aea0d:	74 5d                	je     0x4aea6c
  4aea0f:	80                   	.byte 0x80
```

### VA 0x4aeaa0–0x4aeb80
```asm
004aeaa0 <.text+0xadaa0>:
  4aeaa0:	ff                   	(bad)
  4aeaa1:	ff                   	(bad)
  4aeaa2:	ff                   	(bad)
  4aeaa3:	ff 0f                	dec    DWORD PTR [edi]
  4aeaa5:	b7 0b                	mov    bh,0xb
  4aeaa7:	51                   	push   ecx
  4aeaa8:	e8 63 2b 09 00       	call   0x541610
  4aeaad:	f6 05 b0 75 fb 00 01 	test   BYTE PTR ds:0xfb75b0,0x1
  4aeab4:	75 2f                	jne    0x4aeae5
  4aeab6:	83 0d b0 75 fb 00 01 	or     DWORD PTR ds:0xfb75b0,0x1
  4aeabd:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xc
  4aeac4:	0c 00 00 00 
  4aeac8:	e8 b3 52 04 00       	call   0x4f3d80
  4aeacd:	68 e0 d1 bc 00       	push   0xbcd1e0
  4aead2:	e8 43 38 3e 00       	call   0x89231a
  4aead7:	83 c4 04             	add    esp,0x4
  4aeada:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4aeae1:	ff ff ff ff 
  4aeae5:	8d 54 24 14          	lea    edx,[esp+0x14]
  4aeae9:	b9 70 74 fb 00       	mov    ecx,0xfb7470
  4aeaee:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4aeaf2:	e8 79 8f 04 00       	call   0x4f7a70
  4aeaf7:	0f b6 50 61          	movzx  edx,BYTE PTR [eax+0x61]
  4aeafb:	8b 86 f0 00 00 00    	mov    eax,DWORD PTR [esi+0xf0]
  4aeb01:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aeb04:	89 96 1c 04 00 00    	mov    DWORD PTR [esi+0x41c],edx
  4aeb0a:	0f b6 53 15          	movzx  edx,BYTE PTR [ebx+0x15]
  4aeb0e:	8d 8e f0 00 00 00    	lea    ecx,[esi+0xf0]
  4aeb14:	52                   	push   edx
  4aeb15:	ff d0                	call   eax
  4aeb17:	8b 43 0e             	mov    eax,DWORD PTR [ebx+0xe]
  4aeb1a:	8b 16                	mov    edx,DWORD PTR [esi]
  4aeb1c:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  4aeb22:	0f b6 43 14          	movzx  eax,BYTE PTR [ebx+0x14]
  4aeb26:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  4aeb2c:	66 8b 43 fc          	mov    ax,WORD PTR [ebx-0x4]
  4aeb30:	66 89 46 04          	mov    WORD PTR [esi+0x4],ax
  4aeb34:	8b 42 3c             	mov    eax,DWORD PTR [edx+0x3c]
  4aeb37:	57                   	push   edi
  4aeb38:	8b ce                	mov    ecx,esi
  4aeb3a:	ff d0                	call   eax
  4aeb3c:	8b 16                	mov    edx,DWORD PTR [esi]
  4aeb3e:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4aeb41:	6a 01                	push   0x1
  4aeb43:	8d 43 02             	lea    eax,[ebx+0x2]
  4aeb46:	50                   	push   eax
  4aeb47:	8b ce                	mov    ecx,esi
  4aeb49:	ff d2                	call   edx
  4aeb4b:	0f b6 4b 12          	movzx  ecx,BYTE PTR [ebx+0x12]
  4aeb4f:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb51:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4aeb54:	51                   	push   ecx
  4aeb55:	8b ce                	mov    ecx,esi
  4aeb57:	ff d2                	call   edx
  4aeb59:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb5b:	d9 43 0a             	fld    DWORD PTR [ebx+0xa]
  4aeb5e:	8b 50 5c             	mov    edx,DWORD PTR [eax+0x5c]
  4aeb61:	51                   	push   ecx
  4aeb62:	8b ce                	mov    ecx,esi
  4aeb64:	d9 1c 24             	fstp   DWORD PTR [esp]
  4aeb67:	ff d2                	call   edx
  4aeb69:	80 7b 15 18          	cmp    BYTE PTR [ebx+0x15],0x18
  4aeb6d:	75 07                	jne    0x4aeb76
  4aeb6f:	c6 86 bc 00 00 00 01 	mov    BYTE PTR [esi+0xbc],0x1
  4aeb76:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb78:	8b 50 30             	mov    edx,DWORD PTR [eax+0x30]
  4aeb7b:	8b ce                	mov    ecx,esi
  4aeb7d:	ff d2                	call   edx
  4aeb7f:	8a                   	.byte 0x8a
```