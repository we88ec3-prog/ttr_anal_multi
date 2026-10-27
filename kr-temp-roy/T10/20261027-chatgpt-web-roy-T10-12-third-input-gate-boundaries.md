# KR T10-12 — 0x546D50 第三路裝置取向與 Z 連段證據邊界

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 範圍
從 `0x546780` 第三路 `0x546D50` 展開，判定此分支取值、門檻、輸出和狀態依賴，並與 T10-10/T10-11 整合。這是本次連續研究的第四段；原生 Z 連段完整閉環仍未找到，不因預定四段就虛構成功。

## 原始觀察
- 入口 `0x546D50`（未有正式函式符號），一次性檢查 `0xFB7C14`，需要時呼叫 `0x6D0750`。
- `[0xFB8830] != 0` 直接跳向返回 0；否則將 `[0xFB1318+0x10]` 與呼叫 `IAT 0xBD245C` 的結果比較，不一致也返回 0。IAT 的正式 API 身份本段未直接核對，不能稱為特定 window API。
- 在允許分支，呼叫 `0x6F3350` 將兩個整數座標填入局部變數，轉 float，平方相加，呼叫 `0x8FF870`（形式類似取得向量大小）與 `0xC55CAC` float 常數比較；門檻未跨越返回 0。
- 超過門檻才利用 `0xBD25F8`、`0x8FEDCA` 及 `0x4BB450` 換算兩個來源角度，將兩結果合成 byte 輸出，返回 1。函式在 `0x546EEC` 結束；其後 `0x546EF0` 是下一個函式入口，不能混入本函式。

### 原始 BIN：前置 gate
```asm
546dad:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  546db4:	0f 85 1f 01 00 00    	jne    0x546ed9
  546dba:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  546dbf:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  546dc2:	ff 15 5c 24 bd 00    	call   DWORD PTR ds:0xbd245c
  546dc8:	3b c7                	cmp    eax,edi
  546dca:	0f 85 09 01 00 00    	jne    0x546ed9
  546dd0:	f6 05 6c 1a fc 00 01 	test   BYTE PTR ds:0xfc1a6c,0x1
  546dd7:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  546dde:	00 
  546ddf:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  546de6:	00 
  546de7:	75 14                	jne    0x546dfd
  546de9:	83 0d 6c 1a fc 00 01 	or     DWORD PTR ds:0xfc1a6c,0x1
  546df0:	68 b0 e3 bc 00       	push   0xbce3b0
  546df5:	e8 20 b5 34 00       	call   0x89231a
  546dfa:	83 c4 04             	add    esp,0x4
```

### 原始 BIN：座標閾值與角度計算
```asm
546dfd:	6a 00                	push   0x0
  546dff:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  546e03:	e8 48 c5 1a 00       	call   0x6f3350
  546e08:	db 44 24 18          	fild   DWORD PTR [esp+0x18]
  546e0c:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  546e10:	db 44 24 1c          	fild   DWORD PTR [esp+0x1c]
  546e14:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  546e18:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  546e1c:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546e20:	dc c8                	fmul   st(0),st
  546e22:	d9 c1                	fld    st(1)
  546e24:	de ca                	fmulp  st(2),st
  546e26:	de c1                	faddp  st(1),st
  546e28:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  546e2c:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  546e30:	e8 3b 8a 3b 00       	call   0x8ff870
  546e35:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  546e39:	d9 05 ac 5c c5 00    	fld    DWORD PTR ds:0xc55cac
  546e3f:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  546e43:	df f1                	fcomip st,st(1)
  546e45:	dd d8                	fstp   st(0)
  546e47:	0f 86 8c 00 00 00    	jbe    0x546ed9
```
```asm
546e4d:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  546e51:	51                   	push   ecx
  546e52:	8b d1                	mov    edx,ecx
  546e54:	52                   	push   edx
  546e55:	ff 15 f8 25 bd 00    	call   DWORD PTR ds:0xbd25f8
  546e5b:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  546e5f:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546e63:	e8 62 7f 3b 00       	call   0x8fedca
  546e68:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  546e6c:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  546e70:	51                   	push   ecx
  546e71:	dc 05 28 58 c5 00    	fadd   QWORD PTR ds:0xc55828
  546e77:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  546e7b:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546e7f:	dc 2d d8 5a c5 00    	fsubr  QWORD PTR ds:0xc55ad8
  546e85:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  546e89:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546e8d:	d9 1c 24             	fstp   DWORD PTR [esp]
  546e90:	e8 bb 45 f7 ff       	call   0x4bb450
  546e95:	83 c4 04             	add    esp,0x4
  546e98:	8a d8                	mov    bl,al
  546e9a:	e8 a1 d8 ee ff       	call   0x434740
  546e9f:	8b 40 40             	mov    eax,DWORD PTR [eax+0x40]
  546ea2:	d9 40 20             	fld    DWORD PTR [eax+0x20]
  546ea5:	51                   	push   ecx
  546ea6:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  546eaa:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  546eae:	d9 1c 24             	fstp   DWORD PTR [esp]
  546eb1:	e8 9a 45 f7 ff       	call   0x4bb450
  546eb6:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  546eb9:	83 c4 04             	add    esp,0x4
  546ebc:	02 c3                	add    al,bl
  546ebe:	88 01                	mov    BYTE PTR [ecx],al
  546ec0:	b8 01 00 00 00       	mov    eax,0x1
```

### 原始 BIN：返回邊界
```asm
546ec0:	b8 01 00 00 00       	mov    eax,0x1
  546ec5:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  546ec9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  546ed0:	59                   	pop    ecx
  546ed1:	5f                   	pop    edi
  546ed2:	5b                   	pop    ebx
  546ed3:	8b e5                	mov    esp,ebp
  546ed5:	5d                   	pop    ebp
  546ed6:	c2 04 00             	ret    0x4
  546ed9:	33 c0                	xor    eax,eax
  546edb:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  546edf:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  546ee6:	59                   	pop    ecx
  546ee7:	5f                   	pop    edi
  546ee8:	5b                   	pop    ebx
  546ee9:	8b e5                	mov    esp,ebp
  546eeb:	5d                   	pop    ebp
  546eec:	c2 04 00             	ret    0x4
  546eef:	cc                   	int3
```

## T10-9～T10-12 合併後的可驗證資料流
```text
0x6D4A93 / 0x6D4B69 -> 清 FB9004..FB9028
                                 |
                    [正常事件 writer 尚未找到]
                                 v
0x547240 讀 FB9014 -> 相位結果 -> 0x546780 組 mask
0x546850 讀 FB9005..08 -> 四向合成離散角度 byte -+
0x546B50 讀裝置與指標 gate -> 第二個角度候選 -----+-> 0x546780 選擇 byte 輸出
0x546D50 讀裝置／座標閾值 -> 第三個角度候選 -----+
                                 |
                        0x546100 下游 controller 限制
```

## 嚴格區分
已確認＝清零位置、四向狀態取樣、部分 gate、位元組輸出及幾何處理。推測＝第二與第三路屬於指標／滑鼠輸入相關處理。未確認＝Z 對應行為碼、Z 按住連打的重複續段來源、不同普通攻擊段數、原生取消窗口、實際 `Table/KeyMapping.xml` 内容、伺服器權威規則。之前 `0x1F4` 即便為 500ms，也仍不可稱為 combo window。

## T10-13 後續追查
1. 優先由正常運作的鍵盤事件管理器定位 `0xFB9004` 基底的**間接寫入者**，確認 `FB9014` 實際值域。
2. 查同版本 `Table/KeyMapping.xml` 及 actor/action 入口，具備來源證據後映射 Z 行為。
3. 倒查攻擊 motion/animation 的「下一段完成回呼」、連按 pressed-edge 和 held 同時是否各自有條件分支。
4. 不跨越 T12 傷害公式，不將伺服器自製 `CHAIN_WINDOW=0.65` 冒稱原生。
5. 本批原始檔唯讀；按使用者明確授權，在 T10-12 完成後提交四份 T10 個人原稿；不改 AGENTS、task.json 或其他 Agent 目錄。