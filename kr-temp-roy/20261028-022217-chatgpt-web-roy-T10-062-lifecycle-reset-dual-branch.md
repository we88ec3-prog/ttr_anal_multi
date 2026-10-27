# T10-62 — `0x6D4A30` 雙模式清理與資源 gate

- 研究時間：2026-10-28T02:22:16+08:00（Asia/Taipei）
- 研究對象：KR `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 原始 PE：`.text` VA `0x401000`，raw `0x400`；本檔 VA 與 raw 使用 `raw=VA−0x400C00`（限 `.text`）
- 版本／方法：x86 objdump 從本機原始 BIN 離線只讀重解碼；已有 T10-1～60、T01整合為歷史線索而非本批 native 證明
- 主責限制：T10 普攻、輸入與連段；T11技能裁決、T12傷害公式僅引用；未執行/附加客戶端
- 本段是否完整還原原生功能：**否**。局部組合與資料流保留未閉合點。

## 摘要：可由本次原始 BIN 核對的有限事實

`0x6D4A5B` 依 `[ebp+8]` 的低 byte 導向兩支流程。第一支透過 `0xFB7C14` 與 `0xFDF3EC` gate 決定呼叫 `0x6D0750` 或 `0x6D1DA0`；然後於 `0x6D4A9C..0x6D4AC9` 清除 0xFB9004..0xFB9028 的 DWORD。另一支先檢查 `0xFB8830`，在條件成立時於 `0x6D4B6B..0x6D4B98` 清相同區域，並且對 `0xFDF630` 走 `0x823850`。可見 reset 與特殊鍵樹資源處理存在控制相依，尚不能把布林選擇器命名為按下或放開。

## 第一手 x86 證據

### VA `0x006D4A30` ～ `0x006D4AFB`／raw start `0x002D3E30`

```asm
  6d4a30:	55                   	push   ebp
  6d4a31:	8b ec                	mov    ebp,esp
  6d4a33:	6a ff                	push   0xffffffff
  6d4a35:	68 f0 68 92 00       	push   0x9268f0
  6d4a3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4a40:	50                   	push   eax
  6d4a41:	83 ec 0c             	sub    esp,0xc
  6d4a44:	53                   	push   ebx
  6d4a45:	56                   	push   esi
  6d4a46:	57                   	push   edi
  6d4a47:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4a4c:	33 c5                	xor    eax,ebp
  6d4a4e:	50                   	push   eax
  6d4a4f:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4a52:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4a58:	83 cb ff             	or     ebx,0xffffffff
  6d4a5b:	80 7d 08 00          	cmp    BYTE PTR [ebp+0x8],0x0
  6d4a5f:	8d 73 02             	lea    esi,[ebx+0x2]
  6d4a62:	0f 84 a2 00 00 00    	je     0x6d4b0a
  6d4a68:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4a6f:	75 22                	jne    0x6d4a93
  6d4a71:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4a77:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4a7e:	e8 cd bc ff ff       	call   0x6d0750
  6d4a83:	68 30 d5 bc 00       	push   0xbcd530
  6d4a88:	e8 8d d8 1b 00       	call   0x89231a
  6d4a8d:	83 c4 04             	add    esp,0x4
  6d4a90:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4a93:	33 c0                	xor    eax,eax
  6d4a95:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4a9c:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4aa1:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4aa6:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4aab:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4ab0:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4ab5:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4aba:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4abf:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4ac4:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4ac9:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4ace:	75 1e                	jne    0x6d4aee
  6d4ad0:	09 35 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,esi
  6d4ad6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d4ad9:	e8 c2 d2 ff ff       	call   0x6d1da0
  6d4ade:	68 30 e3 bc 00       	push   0xbce330
  6d4ae3:	e8 32 d8 1b 00       	call   0x89231a
  6d4ae8:	83 c4 04             	add    esp,0x4
  6d4aeb:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4aee:	bf 30 f6 fd 00       	mov    edi,0xfdf630
  6d4af3:	e8 58 ed 14 00       	call   0x823850
  6d4af8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4afb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
```

### VA `0x006D4B0A` ～ `0x006D4C1A`／raw start `0x002D3F0A`

```asm
  6d4b0a:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4b11:	75 22                	jne    0x6d4b35
  6d4b13:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4b19:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  6d4b20:	e8 2b bc ff ff       	call   0x6d0750
  6d4b25:	68 30 d5 bc 00       	push   0xbcd530
  6d4b2a:	e8 eb d7 1b 00       	call   0x89231a
  6d4b2f:	83 c4 04             	add    esp,0x4
  6d4b32:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4b35:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  6d4b3c:	74 5f                	je     0x6d4b9d
  6d4b3e:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4b45:	75 22                	jne    0x6d4b69
  6d4b47:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4b4d:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  6d4b54:	e8 f7 bb ff ff       	call   0x6d0750
  6d4b59:	68 30 d5 bc 00       	push   0xbcd530
  6d4b5e:	e8 b7 d7 1b 00       	call   0x89231a
  6d4b63:	83 c4 04             	add    esp,0x4
  6d4b66:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4b69:	33 c0                	xor    eax,eax
  6d4b6b:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4b70:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4b75:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4b7a:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4b7f:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4b84:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4b89:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4b8e:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4b93:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4b98:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4b9d:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4ba4:	75 22                	jne    0x6d4bc8
  6d4ba6:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4bac:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  6d4bb3:	e8 98 bb ff ff       	call   0x6d0750
  6d4bb8:	68 30 d5 bc 00       	push   0xbcd530
  6d4bbd:	e8 58 d7 1b 00       	call   0x89231a
  6d4bc2:	83 c4 04             	add    esp,0x4
  6d4bc5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4bc8:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  6d4bcf:	74 35                	je     0x6d4c06
  6d4bd1:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4bd8:	75 22                	jne    0x6d4bfc
  6d4bda:	09 35 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,esi
  6d4be0:	c7 45 fc 05 00 00 00 	mov    DWORD PTR [ebp-0x4],0x5
  6d4be7:	e8 b4 d1 ff ff       	call   0x6d1da0
  6d4bec:	68 30 e3 bc 00       	push   0xbce330
  6d4bf1:	e8 24 d7 1b 00       	call   0x89231a
  6d4bf6:	83 c4 04             	add    esp,0x4
  6d4bf9:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4bfc:	bf 30 f6 fd 00       	mov    edi,0xfdf630
  6d4c01:	e8 4a ec 14 00       	call   0x823850
  6d4c06:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6d4c09:	8b 00                	mov    eax,DWORD PTR [eax]
  6d4c0b:	8b 38                	mov    edi,DWORD PTR [eax]
  6d4c0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  6d4c10:	3b f8                	cmp    edi,eax
  6d4c12:	0f 84 a8 00 00 00    	je     0x6d4cc0
  6d4c18:	eb 06                	jmp    0x6d4c20
  6d4c1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
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

後續應追上游 `call 0x6D4A30` 的實參來源及兩路 mode 的進入時機，並確定 `0x823850` 是否只清 tree、還有其他持有者。應避免「兩個模式 = V tap/hold」的跳躍。

## 與歷史原稿的關係

- 以 T10-45～60（原始 `kr-temp-roy/`）作交叉參考；這份是本輪**新補定向 BIN 原始證據與條件細分**，不是宣布舊報告全函式獲正式接受。
- 未改動 owner/catalog、T11/T12 或其他研究者產物。須由 T01 後續整合者另行審核才可提正式 claim。