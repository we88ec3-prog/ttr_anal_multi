# T10-61 — 一般鍵狀態初始化 gate 與兩類資源起始點

- 研究時間：2026-10-28T02:22:16+08:00（Asia/Taipei）
- 研究對象：KR `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 原始 PE：`.text` VA `0x401000`，raw `0x400`；本檔 VA 與 raw 使用 `raw=VA−0x400C00`（限 `.text`）
- 版本／方法：x86 objdump 從本機原始 BIN 離線只讀重解碼；已有 T10-1～60、T01整合為歷史線索而非本批 native 證明
- 主責限制：T10 普攻、輸入與連段；T11技能裁決、T12傷害公式僅引用；未執行/附加客戶端
- 本段是否完整還原原生功能：**否**。局部組合與資料流保留未閉合點。

## 摘要：可由本次原始 BIN 核對的有限事實

`0x6D0750` 的初始化入口安排了 global `0xFB8830` 與 `0xFB8834` 為核心的配置，並在 `0x6D0794` 寫入初值。`0x6D07A2` 起先清數個與一般按鍵欄位相鄰的 DWORD；`0x6D0811..0x6D08A2` 接續把長區段逐 DWORD 清零。其間 `0x6D07CE` 呼叫 `0x6D08F0`，再以 `0xFB8828` 的 bit gate 控制延遲初始化分支。`0x6D07FA` 比較狀態 byte 是否為 2，並按條件呼叫 `0x6D0D10`；後接 `0x6D1A70`。因此重設數值不可理解為每個輸入 frame 的一般按鍵事件。

## 第一手 x86 證據

### VA `0x006D0750` ～ `0x006D07FF`／raw start `0x002CFB50`

```asm
  6d0750:	55                   	push   ebp
  6d0751:	8b ec                	mov    ebp,esp
  6d0753:	6a ff                	push   0xffffffff
  6d0755:	68 e5 28 92 00       	push   0x9228e5
  6d075a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d0760:	50                   	push   eax
  6d0761:	51                   	push   ecx
  6d0762:	53                   	push   ebx
  6d0763:	56                   	push   esi
  6d0764:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d0769:	33 c5                	xor    eax,ebp
  6d076b:	50                   	push   eax
  6d076c:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d076f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d0775:	68 e0 08 6d 00       	push   0x6d08e0
  6d077a:	68 c0 08 6d 00       	push   0x6d08c0
  6d077f:	6a 03                	push   0x3
  6d0781:	68 80 02 00 00       	push   0x280
  6d0786:	33 f6                	xor    esi,esi
  6d0788:	68 34 88 fb 00       	push   0xfb8834
  6d078d:	c7 45 f0 30 88 fb 00 	mov    DWORD PTR [ebp-0x10],0xfb8830
  6d0794:	89 35 30 88 fb 00    	mov    DWORD PTR ds:0xfb8830,esi
  6d079a:	e8 64 18 1c 00       	call   0x892003
  6d079f:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d07a2:	89 35 2c 90 fb 00    	mov    DWORD PTR ds:0xfb902c,esi
  6d07a8:	89 35 30 90 fb 00    	mov    DWORD PTR ds:0xfb9030,esi
  6d07ae:	89 35 34 90 fb 00    	mov    DWORD PTR ds:0xfb9034,esi
  6d07b4:	89 35 3c 90 fb 00    	mov    DWORD PTR ds:0xfb903c,esi
  6d07ba:	89 35 40 90 fb 00    	mov    DWORD PTR ds:0xfb9040,esi
  6d07c0:	89 35 44 90 fb 00    	mov    DWORD PTR ds:0xfb9044,esi
  6d07c6:	bb 01 00 00 00       	mov    ebx,0x1
  6d07cb:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  6d07ce:	e8 1d 01 00 00       	call   0x6d08f0
  6d07d3:	84 1d 28 88 fb 00    	test   BYTE PTR ds:0xfb8828,bl
  6d07d9:	75 1f                	jne    0x6d07fa
  6d07db:	09 1d 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,ebx
  6d07e1:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6d07e5:	e8 66 f0 e7 ff       	call   0x54f850
  6d07ea:	68 80 d5 bc 00       	push   0xbcd580
  6d07ef:	e8 26 1b 1c 00       	call   0x89231a
  6d07f4:	83 c4 04             	add    esp,0x4
  6d07f7:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  6d07fa:	80 3d e9 91 fb 00 02 	cmp    BYTE PTR ds:0xfb91e9,0x2
```

### VA `0x006D0808` ～ `0x006D08BC`／raw start `0x002CFC08`

```asm
  6d0808:	6a 02                	push   0x2
  6d080a:	e8 61 12 00 00       	call   0x6d1a70
  6d080f:	33 c0                	xor    eax,eax
  6d0811:	a3 b4 8f fb 00       	mov    ds:0xfb8fb4,eax
  6d0816:	a3 b8 8f fb 00       	mov    ds:0xfb8fb8,eax
  6d081b:	a3 bc 8f fb 00       	mov    ds:0xfb8fbc,eax
  6d0820:	a3 c0 8f fb 00       	mov    ds:0xfb8fc0,eax
  6d0825:	a3 c4 8f fb 00       	mov    ds:0xfb8fc4,eax
  6d082a:	a3 c8 8f fb 00       	mov    ds:0xfb8fc8,eax
  6d082f:	a3 cc 8f fb 00       	mov    ds:0xfb8fcc,eax
  6d0834:	a3 d0 8f fb 00       	mov    ds:0xfb8fd0,eax
  6d0839:	a3 d4 8f fb 00       	mov    ds:0xfb8fd4,eax
  6d083e:	a3 d8 8f fb 00       	mov    ds:0xfb8fd8,eax
  6d0843:	a3 dc 8f fb 00       	mov    ds:0xfb8fdc,eax
  6d0848:	a3 e0 8f fb 00       	mov    ds:0xfb8fe0,eax
  6d084d:	a3 e4 8f fb 00       	mov    ds:0xfb8fe4,eax
  6d0852:	a3 e8 8f fb 00       	mov    ds:0xfb8fe8,eax
  6d0857:	a3 ec 8f fb 00       	mov    ds:0xfb8fec,eax
  6d085c:	a3 f0 8f fb 00       	mov    ds:0xfb8ff0,eax
  6d0861:	a3 f4 8f fb 00       	mov    ds:0xfb8ff4,eax
  6d0866:	a3 f8 8f fb 00       	mov    ds:0xfb8ff8,eax
  6d086b:	a3 fc 8f fb 00       	mov    ds:0xfb8ffc,eax
  6d0870:	a3 00 90 fb 00       	mov    ds:0xfb9000,eax
  6d0875:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d087a:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d087f:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d0884:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d0889:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d088e:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d0893:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d0898:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d089d:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d08a2:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d08a7:	b8 30 88 fb 00       	mov    eax,0xfb8830
  6d08ac:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d08af:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d08b6:	59                   	pop    ecx
  6d08b7:	5e                   	pop    esi
  6d08b8:	5b                   	pop    ebx
  6d08b9:	8b e5                	mov    esp,ebp
  6d08bb:	5d                   	pop    ebp
  6d08bc:	c3                   	ret
```

## 直接 caller 檢索（僅 E8 near call，不含虛擬／間接）

- `0x6D0750` 的 .text 直接 `call` 候選 `67` 處：`0x444753`, `0x44489C`, `0x44499C`, `0x48CE92`, `0x491493`, `0x49C732`, `0x49D1CF`, `0x49D2E3`, `0x4A11FC`, `0x4A147A`, `0x4A9503`, `0x4A953E`, `0x4B25E8`, `0x4BB818`, `0x4BBEC9`, `0x4BDE69`, `0x545422`, `0x54545D`, `0x54549E`, `0x5454DA`, `0x54551A`, `0x545555`, `0x545594`, `0x5455CF`, `0x54560F` …
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

主要未閉合：`0x892003` 配置之物件的實際型別、初始化在玩家生命週期的呼叫頻率，以及 mapping row 是否在初始化完成後才載入。應由 `0x6D0750` caller 與 `0x6D08F0` 的真正語義追查，不能把 global state 清零當成玩家 keyup。

## 與歷史原稿的關係

- 以 T10-45～60（原始 `kr-temp-roy/`）作交叉參考；這份是本輪**新補定向 BIN 原始證據與條件細分**，不是宣布舊報告全函式獲正式接受。
- 未改動 owner/catalog、T11/T12 或其他研究者產物。須由 T01 後續整合者另行審核才可提正式 claim。