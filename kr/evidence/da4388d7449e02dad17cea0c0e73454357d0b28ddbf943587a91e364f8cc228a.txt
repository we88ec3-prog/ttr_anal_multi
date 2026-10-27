# T10-64 — 一般／特殊索引查詢的預設結果與 gate

- 研究時間：2026-10-28T02:22:16+08:00（Asia/Taipei）
- 研究對象：KR `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 原始 PE：`.text` VA `0x401000`，raw `0x400`；本檔 VA 與 raw 使用 `raw=VA−0x400C00`（限 `.text`）
- 版本／方法：x86 objdump 從本機原始 BIN 離線只讀重解碼；已有 T10-1～60、T01整合為歷史線索而非本批 native 證明
- 主責限制：T10 普攻、輸入與連段；T11技能裁決、T12傷害公式僅引用；未執行/附加客戶端
- 本段是否完整還原原生功能：**否**。局部組合與資料流保留未閉合點。

## 摘要：可由本次原始 BIN 核對的有限事實

`0x6D4CE0` 在 `0x6D4D05` 做 `esi-0x2711` 的範圍檢查。屬特殊區間會查 `0xFDF630` 索引樹，以 sentinel `0xFDF634` 判斷是否找到，讀取 `node+0x10` 的 byte；另一支必須 `esi <= 0x27` 才讀 `0xFB9004+esi`，其他情況在 `0x6D4DAE` 返回零。因此「回傳零」不能單獨判定遊戲未收到按鍵，也可能是索引非法／查無鍵。

## 第一手 x86 證據

### VA `0x006D4CE0` ～ `0x006D4DBF`／raw start `0x002D40E0`

```asm
  6d4ce0:	55                   	push   ebp
  6d4ce1:	8b ec                	mov    ebp,esp
  6d4ce3:	6a ff                	push   0xffffffff
  6d4ce5:	68 5c 68 92 00       	push   0x92685c
  6d4cea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4cf0:	50                   	push   eax
  6d4cf1:	83 ec 08             	sub    esp,0x8
  6d4cf4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4cf9:	33 c5                	xor    eax,ebp
  6d4cfb:	50                   	push   eax
  6d4cfc:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4cff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4d05:	8d 86 ef d8 ff ff    	lea    eax,[esi-0x2711]
  6d4d0b:	3d 0e 27 00 00       	cmp    eax,0x270e
  6d4d10:	b8 01 00 00 00       	mov    eax,0x1
  6d4d15:	77 59                	ja     0x6d4d70
  6d4d17:	84 05 ec f3 fd 00    	test   BYTE PTR ds:0xfdf3ec,al
  6d4d1d:	75 1f                	jne    0x6d4d3e
  6d4d1f:	09 05 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,eax
  6d4d25:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4d2c:	e8 6f d0 ff ff       	call   0x6d1da0
  6d4d31:	68 30 e3 bc 00       	push   0xbce330
  6d4d36:	e8 df d5 1b 00       	call   0x89231a
  6d4d3b:	83 c4 04             	add    esp,0x4
  6d4d3e:	8d 4d f0             	lea    ecx,[ebp-0x10]
  6d4d41:	51                   	push   ecx
  6d4d42:	8d 45 ec             	lea    eax,[ebp-0x14]
  6d4d45:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4d4a:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  6d4d4d:	e8 ae a1 15 00       	call   0x82ef00
  6d4d52:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  6d4d55:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4d5b:	74 51                	je     0x6d4dae
  6d4d5d:	0f b6 40 10          	movzx  eax,BYTE PTR [eax+0x10]
  6d4d61:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4d64:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4d6b:	59                   	pop    ecx
  6d4d6c:	8b e5                	mov    esp,ebp
  6d4d6e:	5d                   	pop    ebp
  6d4d6f:	c3                   	ret
  6d4d70:	84 05 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,al
  6d4d76:	75 1b                	jne    0x6d4d93
  6d4d78:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  6d4d7e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d4d81:	e8 ca b9 ff ff       	call   0x6d0750
  6d4d86:	68 30 d5 bc 00       	push   0xbcd530
  6d4d8b:	e8 8a d5 1b 00       	call   0x89231a
  6d4d90:	83 c4 04             	add    esp,0x4
  6d4d93:	83 fe 27             	cmp    esi,0x27
  6d4d96:	77 16                	ja     0x6d4dae
  6d4d98:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  6d4d9f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4da2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4da9:	59                   	pop    ecx
  6d4daa:	8b e5                	mov    esp,ebp
  6d4dac:	5d                   	pop    ebp
  6d4dad:	c3                   	ret
  6d4dae:	33 c0                	xor    eax,eax
  6d4db0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4db3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4dba:	59                   	pop    ecx
  6d4dbb:	8b e5                	mov    esp,ebp
  6d4dbd:	5d                   	pop    ebp
  6d4dbe:	c3                   	ret
  6d4dbf:	cc                   	int3
```

## 直接 caller 檢索（僅 E8 near call，不含虛擬／間接）

- `0x6D4A30` 的 .text 直接 `call` 候選 `2` 處：`0x490DFC`, `0x58A607`
- `0x6D4CE0` 的 .text 直接 `call` 候選 `2` 處：`0x59624E`, `0x59643F`
- `0x6D4DC0` 的 .text 直接 `call` 候選 `29` 處：`0x594672`, `0x5946CB`, `0x59471B`, `0x5947FD`, `0x59484D`, `0x59492F`, `0x59497F`, `0x594CD4`, `0x594DC4`, `0x594EB4`, `0x594FA4`, `0x595094`, `0x595184`, `0x595274`, `0x595364`, `0x595454`, `0x595544`, `0x595634`, `0x595724`, `0x595814`, `0x595901`, `0x5959F4`, `0x5CD68A`, `0x5CE5BA`, `0x62B5BA` …

## 可檢驗偽碼（只描述局部控制流）

```cpp
// 研究用示意，非原始符號／函式原型
// state_read(index): index 域首先決定容器，查無或超出時可回傳 0；
// reset(context): 按 mode / gate 清零一般 array 或特殊樹中對應 node；
// event_candidate: state_byte == 1 時可觸發有限命令構造／virtual callback。
// 尚缺：OS event writer -> action mapping -> player receiver -> motion writer。
```

## 證據分級與反證邊界

- **已確認（局部）**：上列 x86 指令及已列明直接控制分支與資料讀寫；逐段原始 bytes 已由 hash 符合的 BIN 反組譯。
- **部分確認**：來源索引／回傳 byte 與多態 callback 存在聯繫；型別、物件生命週期及上游來源尚未封閉。
- **僅合理假設**：此資料可能參與玩家可自訂鍵位及攻擊輸入；缺完整 player receiver 身分與事件來源證據。
- **尚待驗證**：非零 phase writer、V tap/held、Z press/hold、普攻／技能隊列、動畫完成／取消、client-server authority。
- **明確排除推論**：`0x547240` 的 `>500ms` 不是原版連段窗口；SubAI >60 次不是 V held 秒數；`CHAIN_WINDOW=0.65` 為 AI 替代；命令索引數不等普攻段數。

## 可接續工作

未閉合：`0x5961C0` 的 esi 如何產生、狀態 byte 的 phase 值何時由事件寫入、以及函式內 gate 呼叫是否會有副作用。尤其 phase==1 只能視為被消費的 byte 值。

## 與歷史原稿的關係

- 以 T10-45～60（原始 `kr-temp-roy/`）作交叉參考；這份是本輪**新補定向 BIN 原始證據與條件細分**，不是宣布舊報告全函式獲正式接受。
- 未改動 owner/catalog、T11/T12 或其他研究者產物。須由 T01 後續整合者另行審核才可提正式 claim。