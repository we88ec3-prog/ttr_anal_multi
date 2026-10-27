# T10-66 — 自訂鍵位映射查詢與數值轉換仍屬分離資料鏈

- 研究時間：2026-10-28T02:22:16+08:00（Asia/Taipei）
- 研究對象：KR `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 原始 PE：`.text` VA `0x401000`，raw `0x400`；本檔 VA 與 raw 使用 `raw=VA−0x400C00`（限 `.text`）
- 版本／方法：x86 objdump 從本機原始 BIN 離線只讀重解碼；已有 T10-1～60、T01整合為歷史線索而非本批 native 證明
- 主責限制：T10 普攻、輸入與連段；T11技能裁決、T12傷害公式僅引用；未執行/附加客戶端
- 本段是否完整還原原生功能：**否**。局部組合與資料流保留未閉合點。

## 摘要：可由本次原始 BIN 核對的有限事實

先前 T10-45／47 證明 `0x6D4DC0` 屬 mapping 查詢與結果集合，`0x594610` 為其中一個 consumer。此處以新的 BIN 鄰域反組譯核對 caller 對輸出集合、局部索引與後續 helper 的使用，不將 `0xFB8834` mapping bank 和 `0xFB9004` phase array 合成同一儲存實體。輸入實際 action 綁定仍要靠 `KeyMapping.xml` row、設定檔 fallback 與來源 writer 才能閉合。

## 第一手 x86 證據

### VA `0x005945E0` ～ `0x005946E0`／raw start `0x001939E0`

```asm
  5945e1:	2b c8                	sub    ecx,eax
  5945e3:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  5945e7:	6a 00                	push   0x0
  5945e9:	52                   	push   edx
  5945ea:	8b ce                	mov    ecx,esi
  5945ec:	e8 ef e0 e6 ff       	call   0x4026e0
  5945f1:	5e                   	pop    esi
  5945f2:	5b                   	pop    ebx
  5945f3:	5d                   	pop    ebp
  5945f4:	c2 04 00             	ret    0x4
  5945f7:	6a 00                	push   0x0
  5945f9:	68 fc d1 be 00       	push   0xbed1fc
  5945fe:	8b ce                	mov    ecx,esi
  594600:	e8 5b db e6 ff       	call   0x402160
  594605:	5e                   	pop    esi
  594606:	5b                   	pop    ebx
  594607:	5d                   	pop    ebp
  594608:	c2 04 00             	ret    0x4
  59460b:	cc                   	int3
  59460c:	cc                   	int3
  59460d:	cc                   	int3
  59460e:	cc                   	int3
  59460f:	cc                   	int3
  594610:	55                   	push   ebp
  594611:	8b ec                	mov    ebp,esp
  594613:	83 e4 f8             	and    esp,0xfffffff8
  594616:	6a ff                	push   0xffffffff
  594618:	68 00 70 92 00       	push   0x927000
  59461d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  594623:	50                   	push   eax
  594624:	83 ec 60             	sub    esp,0x60
  594627:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59462c:	33 c4                	xor    eax,esp
  59462e:	89 44 24 58          	mov    DWORD PTR [esp+0x58],eax
  594632:	53                   	push   ebx
  594633:	56                   	push   esi
  594634:	57                   	push   edi
  594635:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59463a:	33 c4                	xor    eax,esp
  59463c:	50                   	push   eax
  59463d:	8d 44 24 70          	lea    eax,[esp+0x70]
  594641:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  594647:	8b f9                	mov    edi,ecx
  594649:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  59464c:	33 db                	xor    ebx,ebx
  59464e:	8b f2                	mov    esi,edx
  594650:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  594654:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  594658:	89 5c 24 3c          	mov    DWORD PTR [esp+0x3c],ebx
  59465c:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  594660:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
  594690:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  594694:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  594698:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  59469c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5946a0:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5946a4:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5946a8:	33 c9                	xor    ecx,ecx
  5946aa:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5946b1:	00 
  5946b2:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5946b6:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5946bb:	6a 02                	push   0x2
  5946bd:	6a 0d                	push   0xd
  5946bf:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5946c3:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x3
  5946ca:	03 
  5946cb:	e8 f0 06 14 00       	call   0x6d4dc0
  5946d0:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5946d4:	83 c4 08             	add    esp,0x8
  5946d7:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  5946db:	74 27                	je     0x594704
  5946dd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
```

### VA `0x00594A60` ～ `0x00594B00`／raw start `0x00193E60`

```asm
  594a66:	59                   	pop    ecx
  594a67:	5f                   	pop    edi
  594a68:	5e                   	pop    esi
  594a69:	5b                   	pop    ebx
  594a6a:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  594a6e:	33 cc                	xor    ecx,esp
  594a70:	e8 8c c5 2f 00       	call   0x891001
  594a75:	8b e5                	mov    esp,ebp
  594a77:	5d                   	pop    ebp
  594a78:	c2 08 00             	ret    0x8
  594a7b:	cc                   	int3
  594a7c:	cc                   	int3
  594a7d:	cc                   	int3
  594a7e:	cc                   	int3
  594a7f:	cc                   	int3
  594a80:	55                   	push   ebp
  594a81:	8b ec                	mov    ebp,esp
  594a83:	53                   	push   ebx
  594a84:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  594a87:	8b c3                	mov    eax,ebx
  594a89:	c1 e8 10             	shr    eax,0x10
  594a8c:	84 c0                	test   al,al
  594a8e:	74 41                	je     0x594ad1
  594a90:	0f b6 c0             	movzx  eax,al
  594a93:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594a9a:	6a ff                	push   0xffffffff
  594a9c:	2b c8                	sub    ecx,eax
  594a9e:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594aa2:	6a 00                	push   0x0
  594aa4:	52                   	push   edx
  594aa5:	8b ce                	mov    ecx,esi
  594aa7:	e8 34 dc e6 ff       	call   0x4026e0
  594aac:	84 db                	test   bl,bl
  594aae:	74 54                	je     0x594b04
  594ab0:	0f b6 c3             	movzx  eax,bl
  594ab3:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594aba:	6a ff                	push   0xffffffff
  594abc:	2b c8                	sub    ecx,eax
  594abe:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594ac2:	6a 00                	push   0x0
  594ac4:	52                   	push   edx
  594ac5:	8b ce                	mov    ecx,esi
  594ac7:	e8 24 f7 e6 ff       	call   0x4041f0
  594acc:	5b                   	pop    ebx
  594acd:	5d                   	pop    ebp
  594ace:	c2 04 00             	ret    0x4
  594ad1:	84 db                	test   bl,bl
  594ad3:	74 21                	je     0x594af6
  594ad5:	0f b6 c3             	movzx  eax,bl
  594ad8:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594adf:	6a ff                	push   0xffffffff
  594ae1:	2b c8                	sub    ecx,eax
  594ae3:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594ae7:	6a 00                	push   0x0
  594ae9:	52                   	push   edx
  594aea:	8b ce                	mov    ecx,esi
  594aec:	e8 ef db e6 ff       	call   0x4026e0
  594af1:	5b                   	pop    ebx
  594af2:	5d                   	pop    ebp
  594af3:	c2 04 00             	ret    0x4
  594af6:	6a 00                	push   0x0
  594af8:	68 fc d1 be 00       	push   0xbed1fc
  594afd:	8b ce                	mov    ecx,esi
  594aff:	e8 5c d6 e6 ff       	call   0x402160
```

## 直接 caller 檢索（僅 E8 near call，不含虛擬／間接）

- `0x5945E0` 的 .text 直接 `call` 候選 `0` 處：
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

下一步需要配置與檔案載入 call graph，並建立每個鍵位 action row、映射結果、使用點的三欄矩陣；否則 Z 可自訂的遊戲事實不能反推 `VK_Z` 是 native action constant。

## 與歷史原稿的關係

- 以 T10-45～60（原始 `kr-temp-roy/`）作交叉參考；這份是本輪**新補定向 BIN 原始證據與條件細分**，不是宣布舊報告全函式獲正式接受。
- 未改動 owner/catalog、T11/T12 或其他研究者產物。須由 T01 後續整合者另行審核才可提正式 claim。