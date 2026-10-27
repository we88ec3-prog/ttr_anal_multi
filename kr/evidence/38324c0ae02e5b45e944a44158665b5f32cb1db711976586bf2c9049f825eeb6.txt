# KR T10-10 — 0x546850 四個輸入位元組與方向／角度合成

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 範圍
T10-7 確認 `0x546780` 會呼叫 `0x546850`，但這一分支是否屬於普攻需要查看它自己的輸入與輸出。完整檢查 `0x546850..0x546B45` 的方向狀態運算，定位 `0xFB9005..0xFB9008` 及其角度 byte 的意義邊界。

## 關鍵原生證據
`0x5468AA,0x5468E5` 取 `FB9005` 並與 1 或 2 比較，符合時 `sub [ebp-0x18],1`；`FB9006` 相同模式，符合時 `add [ebp-0x18],1`；`FB9007` 對 EDI 做 `sub 1`；`FB9008` 對 EDI 做 `add 1`。輸入值 1、2 在此**具有相同的啟動效果**，但二者在其他消費者可仍有不同語義。

方向分支在 `0x546A54..0x546A91` 將軸向符號轉換成離散 byte `0x00/0x20/0x40/0x60/0x80/0xA0/0xC0/0xE0`，再以 `0xFB8824 * ([0xFB76E8]+0x20)` 的 float 調整量（經 x87 float-to-int）加到輸出 byte。兩軸都為 0 時返回 0；否則寫出 angle byte 並返回 1。未確認輸出單位、浮點欄位正式命名。

### 原始 BIN：四向來源
```asm
5468aa:	0f b6 05 05 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9005
  5468b1:	b9 01 00 00 00       	mov    ecx,0x1
  5468b6:	3b c1                	cmp    eax,ecx
  5468b8:	74 34                	je     0x5468ee
  5468ba:	84 0d 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,cl
  5468c0:	75 23                	jne    0x5468e5
  5468c2:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  5468c8:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  5468cb:	e8 80 9e 18 00       	call   0x6d0750
  5468d0:	68 30 d5 bc 00       	push   0xbcd530
  5468d5:	e8 40 ba 34 00       	call   0x89231a
  5468da:	83 c4 04             	add    esp,0x4
  5468dd:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5468e0:	b9 01 00 00 00       	mov    ecx,0x1
  5468e5:	80 3d 05 90 fb 00 02 	cmp    BYTE PTR ds:0xfb9005,0x2
  5468ec:	75 03                	jne    0x5468f1
  5468ee:	29 4d e8             	sub    DWORD PTR [ebp-0x18],ecx
```
```asm
546921:	0f b6 05 06 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9006
  546928:	3b c1                	cmp    eax,ecx
  54692a:	74 39                	je     0x546965
  54692c:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  546933:	75 27                	jne    0x54695c
  546935:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  54693b:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  546942:	e8 09 9e 18 00       	call   0x6d0750
  546947:	68 30 d5 bc 00       	push   0xbcd530
  54694c:	e8 c9 b9 34 00       	call   0x89231a
  546951:	83 c4 04             	add    esp,0x4
  546954:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  546957:	b9 01 00 00 00       	mov    ecx,0x1
  54695c:	80 3d 06 90 fb 00 02 	cmp    BYTE PTR ds:0xfb9006,0x2
  546963:	75 03                	jne    0x546968
  546965:	01 4d e8             	add    DWORD PTR [ebp-0x18],ecx
```
```asm
546998:	0f b6 05 07 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9007
  54699f:	3b c1                	cmp    eax,ecx
  5469a1:	74 39                	je     0x5469dc
  5469a3:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  5469aa:	75 27                	jne    0x5469d3
  5469ac:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  5469b2:	c7 45 fc 05 00 00 00 	mov    DWORD PTR [ebp-0x4],0x5
  5469b9:	e8 92 9d 18 00       	call   0x6d0750
  5469be:	68 30 d5 bc 00       	push   0xbcd530
  5469c3:	e8 52 b9 34 00       	call   0x89231a
  5469c8:	83 c4 04             	add    esp,0x4
  5469cb:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5469ce:	b9 01 00 00 00       	mov    ecx,0x1
  5469d3:	80 3d 07 90 fb 00 02 	cmp    BYTE PTR ds:0xfb9007,0x2
  5469da:	75 02                	jne    0x5469de
  5469dc:	2b f9                	sub    edi,ecx
```
```asm
546a0e:	0f b6 05 08 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9008
  546a15:	3b c1                	cmp    eax,ecx
  546a17:	74 39                	je     0x546a52
  546a19:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  546a20:	75 27                	jne    0x546a49
  546a22:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  546a28:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  546a2f:	e8 1c 9d 18 00       	call   0x6d0750
  546a34:	68 30 d5 bc 00       	push   0xbcd530
  546a39:	e8 dc b8 34 00       	call   0x89231a
  546a3e:	83 c4 04             	add    esp,0x4
  546a41:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  546a44:	b9 01 00 00 00       	mov    ecx,0x1
  546a49:	80 3d 08 90 fb 00 02 	cmp    BYTE PTR ds:0xfb9008,0x2
  546a50:	75 02                	jne    0x546a54
  546a52:	03 f9                	add    edi,ecx
```

### 原始 BIN：離散角度與輸出
```asm
546a54:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  546a57:	3b c6                	cmp    eax,esi
  546a59:	75 12                	jne    0x546a6d
  546a5b:	b3 80                	mov    bl,0x80
  546a5d:	3b fe                	cmp    edi,esi
  546a5f:	75 04                	jne    0x546a65
  546a61:	b3 a0                	mov    bl,0xa0
  546a63:	eb 2c                	jmp    0x546a91
  546a65:	3b f9                	cmp    edi,ecx
  546a67:	75 28                	jne    0x546a91
  546a69:	b3 60                	mov    bl,0x60
  546a6b:	eb 24                	jmp    0x546a91
  546a6d:	3b c1                	cmp    eax,ecx
  546a6f:	75 12                	jne    0x546a83
  546a71:	32 db                	xor    bl,bl
  546a73:	3b fe                	cmp    edi,esi
  546a75:	75 04                	jne    0x546a7b
  546a77:	b3 e0                	mov    bl,0xe0
  546a79:	eb 16                	jmp    0x546a91
  546a7b:	3b f9                	cmp    edi,ecx
  546a7d:	75 12                	jne    0x546a91
  546a7f:	b3 20                	mov    bl,0x20
  546a81:	eb 0e                	jmp    0x546a91
  546a83:	3b fe                	cmp    edi,esi
  546a85:	75 04                	jne    0x546a8b
  546a87:	b3 c0                	mov    bl,0xc0
  546a89:	eb 06                	jmp    0x546a91
  546a8b:	3b f9                	cmp    edi,ecx
  546a8d:	75 02                	jne    0x546a91
  546a8f:	b3 40                	mov    bl,0x40
```
```asm
546b0c:	85 ff                	test   edi,edi
  546b0e:	75 1b                	jne    0x546b2b
  546b10:	39 7d e8             	cmp    DWORD PTR [ebp-0x18],edi
  546b13:	75 16                	jne    0x546b2b
  546b15:	33 c0                	xor    eax,eax
  546b17:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  546b1a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  546b21:	59                   	pop    ecx
  546b22:	5f                   	pop    edi
  546b23:	5e                   	pop    esi
  546b24:	5b                   	pop    ebx
  546b25:	8b e5                	mov    esp,ebp
  546b27:	5d                   	pop    ebp
  546b28:	c2 04 00             	ret    0x4
  546b2b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  546b2e:	88 18                	mov    BYTE PTR [eax],bl
  546b30:	8b c1                	mov    eax,ecx
  546b32:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  546b35:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  546b3c:	59                   	pop    ecx
  546b3d:	5f                   	pop    edi
  546b3e:	5e                   	pop    esi
  546b3f:	5b                   	pop    ebx
  546b40:	8b e5                	mov    esp,ebp
  546b42:	5d                   	pop    ebp
  546b43:	c2                   	.byte 0xc2
  546b44:	04                   	.byte 0x4
```

## 結論
這條分支讀四個連續的輸入狀態 byte，合成類似二維方向資料及 byte 角度。在輸出合流 `0x546780` 中它對某個 byte 輸出具有優先權；**但沒有看到可把四個 byte 命名為 Z、普攻段數或取消窗口的依據**。

暫定偽碼：
```cpp
int x = enabled(FB9006) - enabled(FB9005);
int y = enabled(FB9008) - enabled(FB9007);
if (x==0 && y==0) return 0;
uint8_t angle = directional_octant(x,y) + quantized_adjustment;
*outAngle = angle;
return 1;
```
`enabled` 在此只指 ==1 或 ==2；浮點調整的正式語義未確定。下一段 T10-11 轉向 `0x546B50` 中的另一裝置狀態與按下邊沿條件。