# T03-11 — KR 接收 worker 身份界限、父物件 +0x140 初始化及實際發送 scheduler → 0x8061A0

日期：2026-10-28T23:11:21.591076+08:00（Asia/Taipei），研究者 chatgpt-web roy，研究分支 `t03/roy/chatgpt-web`。

## 來源、證據等級和本次增量

- 原件 `/mnt/data/Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，**本次實際重新讀取**；沒有執行或修改目標。
- PE `.text` VMA `0x401000`, raw `0x400`，`.rdata` VMA `0xBD2000`, raw `0x7D0600`；`.text` 地址映射 `raw = VA − 0x400C00`。
- 證據工具：GNU objdump 對本次實際 BIN 的原生 x86 反組譯，以及全 `.text` direct E8 rel32 掃描。掃描僅覆蓋 direct call opcode，不能排除 vtable、jump thunk、function pointer。
- 前段 T03-9/10 已確定 `0x804740 → 0x804841 → 0x804100 → worker vtable +0/+8/+C`；曾建議將 `0x804A40` 視為尚待確認之相鄰傳輸路徑。
- **本輪新證實：** `0x804A40` 在來源連線容器的逐通道迴圈中，於 `0x804AD6` **直接呼叫先前 T03-5 的 `0x8061A0`**；它依返回值與計時 gate 更新 `channel+0xA094`、`+0xA0A4`、`+0xA084`。這把已知 42 queue drain 的排程上層補齊了一部分，並更明確把 `0x804A40` 與接收業務回覆 worker `0x804740` 分開。

## 第 1 輪：從父物件及 worker 接收迴圈還原實際傳遞

1. `0x48C0E0 lea edi,[ebx+0x140]`、`0x48C0E6 call 0x804650`：**EBX 是父物件指標，EDI 為內嵌 worker 基址**。`0x804650` 使用 EDI，初始化時間欄位及全域傳輸物件；這不等於已找到該 worker 的 vtable 寫入。
2. `0x491983 lea ebx,[edi+0x140]`、`0x491989 push ebx`、`0x49198A call 0x804740`：worker 確實以指標作 stack 引數傳入接收迴圈。`0x804768 mov ebx,[ebp+8]` 再取回。
3. `0x8047B2 lea edi,[ebx+4]`、`0x8047BA lea esi,[ebx+0x30]`、`ECX=0xB`、`rep movsd`：先將 worker+0x30..+0x5B 的 **44 bytes** 複製回 worker+0x04..+0x2F。隨後把 11 dword 清零後複製至 worker+0x30..+0x5B，再使用 `worker+0x84`、`+0x10`、`+0x58` 做週期/狀態操作。欄位是 worker 的，不是角色紀錄、也不是 socket bytes。
4. `0x804858..0x80486D` 對 `worker[0]` 讀虛擬表，以 record[0], &record[8], record[4], worker selector 作入參呼叫 vtable+0，後續有 vtable+0xC、超過 0x28 threshold 時 vtable+0x8。**沒有本次原始證據能指出 worker[0] 的最終靜態表值**，因此不能把 `vtable+0` 硬對到選角批准 handler。
5. `0x804650` 實際 `0x8046F1..0x8046F7` 配置的是 **0x5C-byte 另一獨立物件**，並寫 `0xC51748` 到該物件的首欄位，再於 `0x80470F` 存入 `FBA854`。**這是共用發送介面物件的 vtable，不是 parent+0x140 worker vtable**；否證上一段可能混淆的方向。

## 第 2 輪：交叉追回 0x804A40 的真正發送排程

1. `0x491FDD` 是 `0x804A40` 唯一直接 E8 caller（掃描界限見下），與 `0x49198A → 0x804740` 分居上層不同區塊。
2. `0x804A40` 先呼叫計時方法並使用 `FBA858`；`0x804AA2..0x804AAF` 從 `[[FBA858]+0]` 到 `[[FBA858]+4]` 求 4-byte pointer stride 的數量，再以 `0x804AC3 mov esi,[edx+eax*4]` 逐一取出通道物件。
3. `0x804AC8 cmp [esi+0xA0AC],0` gate 不成立時略過；成立則 `0x804AD5 push esi`、`0x804AD6 call 0x8061A0`。直接把上層排程與此前已證實的 dequeue/frame-builder 接上。
4. 成功返回：`0x804AE5 add [esi+0xA094],1`；`[esi+0xA0A4] >= 5` 會扣 5，否則清 0。失敗返回：僅在 `[ebp-4]` 非零的計時 gate，`0x804B0D` 累計 `[esi+0xA084]` 並於 `0x804B13` 給 `[esi+0xA0A4]` 加 5。**目前不得將計數器直接命名為 network retry 或擁塞控制實際語義**；只確認數學更新與 gating。
5. `0x804A40` 是實質 transport send scheduler，而不是 S→C opcode dispatcher；因此不能從這個分支反推出原版 command 42 的回覆 ID。

## 第 3 輪：direct xref 範圍、vtable 缺口及反證

針對本次 `.text` 每一個 raw `E8 rel32` 計算 target；結果：

| target | 直接呼叫來源（`.text`） | 界線 |
|---|---|---|
| `0x804650` | `0x48c0e6` | 僅 direct E8，非完整所有間接 caller |
| `0x804740` | `0x49198a` | 僅 direct E8，非完整所有間接 caller |
| `0x804A40` | `0x491fdd` | 僅 direct E8，非完整所有間接 caller |
| `0x8061A0` | `0x804ad6, 0x805228` | 僅 direct E8，非完整所有間接 caller |

- `0x804650` 的唯一可見直接呼叫 `0x48C0E6` 並**未寫入 parent+0x140 首 dword 的 vtable**；不能因找不到而推論它從未被初始化。必須延伸至父物件完整建構鏈、複製／指標指派與可能的間接初始化。
- `0x804740` 的唯一直接 E8 caller 在 `0x49198A`；`0x804A40` 的唯一直接 E8 caller 在 `0x491FDD`，後者屬傳送 scheduler 而不是業務 callback。
- 此次新證據是發送排程與接收 worker 所屬關係及欄位拷貝；**真正 worker vtable 目標仍未核定**。接收資料進入特定 Server 回覆 handler 尚未閉合。
- 三輪均有實際第一手位址、交叉驗證與反證；第 2 輪提供可回溯的重大新排程鏈，已達研究單位停止門檻，第 3 輪僅進行 xref 校對，不擴稱完成選角。

## 玩家情境、雙向契約矩陣

| 場景 | 本地條件 | C→S | 發送/接收傳輸 | 原始 S→C | UI / 世界效果 | 等級 |
|---|---|---|---|---|---|---|
| 玩家確認選角 | `record+0x5C` 可用、T03-3 之全域 sender gate | `42 00 XX YY` 本地 builder；T03-4 enqueue | 本段 `0x804A40` 在通道啟用後定期 `0x8061A0`，與 T03-5 排程補鏈 | 尚未配對，不能用測試 `43/69` 當真 | 不明；T05 轉場未證明 | 原生部分確認 |
| 通道已啟用且 queue 有資料 | `channel+0xA0AC != 0` | 可能從 queue 取出 | `0x8061A0` 成功則更新數值旗標及計數 | 不適用 | 不適用 | 原生已確認（有界） |
| 收到解框後 record | T03-8/9 reader 有資料 | 不適用 | `0x804740` 呼叫 worker vtable+0 | opcode / payload / handler 未知 | 未知 | 原生部分確認 |
| 發送排程沒有資料或失敗 | `0x8061A0` 返回 0；計時 gate 可控制統計 | 不可證實有本次 socket 寫出 | 本段只確認計數器更新 | 不適用 | 不代表 Server 拒絕 | 原生已確認（有界） |

## 待解決與下段 T03-12 入口

1. 真正確認父物件建構起點、`parent+0x140` 首欄位如何被指定 vtable（或是否為多態/外部 callback 表）；一個 ctor 的初始化不足以斷言不存在。
2. 從 `0x80486D` 的動態目標回查對應 callback 的程式碼，找到消息 ID 的解析與分派；注意接收 `record[0]` 是否為原始 opcode 仍未證明。
3. 補齊 `0x804A40→0x8061A0→WSASend` 特定 channel 對應，確認選角 command42 是否實際排程至哪一條 socket，及回覆／T05 過渡結果。T02 管 transport 主責，T03 只引用並歸屬業務。
4. 不猜原版 Server 認證、拒絕碼、人物資料或切換場景；不更新 T02/T04/T05/T06 或 main；所有物件類名為暫稱。

## 原始機器碼（摘錄）

### Parent embedded-worker initialization `0x48C0E0..0x48C10A`

```asm
0048c0e0 <.text+0x8b0e0>:
  48c0e0:	8d bb 40 01 00 00    	lea    edi,[ebx+0x140]
  48c0e6:	e8 65 85 37 00       	call   0x804650
  48c0eb:	6a 34                	push   0x34
  48c0ed:	6a 01                	push   0x1
  48c0ef:	6a 01                	push   0x1
  48c0f1:	68 24 57 c0 00       	push   0xc05724
  48c0f6:	8d 94 24 54 01 00 00 	lea    edx,[esp+0x154]
  48c0fd:	e8 ae cd 00 00       	call   0x498eb0
  48c102:	83 c4 10             	add    esp,0x10
  48c105:	e8 76 15 fc ff       	call   0x44d680
```

### Initializer and global sender object `0x804674..0x804727`

```asm
00804674 <.text+0x403674>:
  804674:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  80467b:	c7 87 8c 00 00 00 00 	mov    DWORD PTR [edi+0x8c],0x0
  804682:	00 00 00 
  804685:	75 27                	jne    0x8046ae
  804687:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80468e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804695:	e8 86 2a 00 00       	call   0x807120
  80469a:	68 90 0b bd 00       	push   0xbd0b90
  80469f:	e8 76 dc 08 00       	call   0x89231a
  8046a4:	83 c4 04             	add    esp,0x4
  8046a7:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8046ae:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  8046b5:	75 15                	jne    0x8046cc
  8046b7:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8046be:	74 07                	je     0x8046c7
  8046c0:	e8 9b 68 c9 ff       	call   0x49af60
  8046c5:	eb 05                	jmp    0x8046cc
  8046c7:	e8 34 69 c9 ff       	call   0x49b000
  8046cc:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  8046d1:	50                   	push   eax
  8046d2:	e8 49 10 00 00       	call   0x805720
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
  804724:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
```

### Worker receiver call `0x49197F..0x49198F`

```asm
0049197f <.text+0x9097f>:
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
```

### Worker reader setup and field copy `0x804768..0x804826`

```asm
00804768 <.text+0x403768>:
  804768:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80476b:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  804772:	75 27                	jne    0x80479b
  804774:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  80477b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804782:	e8 69 f8 ff ff       	call   0x803ff0
  804787:	68 90 dc bc 00       	push   0xbcdc90
  80478c:	e8 89 db 08 00       	call   0x89231a
  804791:	83 c4 04             	add    esp,0x4
  804794:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80479b:	a1 f0 11 fc 00       	mov    eax,ds:0xfc11f0
  8047a0:	6a 01                	push   0x1
  8047a2:	50                   	push   eax
  8047a3:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  8047aa:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  8047b0:	33 c0                	xor    eax,eax
  8047b2:	8d 7b 04             	lea    edi,[ebx+0x4]
  8047b5:	b9 0b 00 00 00       	mov    ecx,0xb
  8047ba:	8d 73 30             	lea    esi,[ebx+0x30]
  8047bd:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047bf:	89 45 a8             	mov    DWORD PTR [ebp-0x58],eax
  8047c2:	89 45 ac             	mov    DWORD PTR [ebp-0x54],eax
  8047c5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  8047c8:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  8047cb:	89 45 b8             	mov    DWORD PTR [ebp-0x48],eax
  8047ce:	89 45 bc             	mov    DWORD PTR [ebp-0x44],eax
  8047d1:	89 45 c0             	mov    DWORD PTR [ebp-0x40],eax
  8047d4:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  8047d7:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  8047da:	66 89 45 d0          	mov    WORD PTR [ebp-0x30],ax
  8047de:	b9 0b 00 00 00       	mov    ecx,0xb
  8047e3:	8d 75 a8             	lea    esi,[ebp-0x58]
  8047e6:	8d 7b 30             	lea    edi,[ebx+0x30]
  8047e9:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047eb:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8047f1:	ff d7                	call   edi
  8047f3:	8b 8b 84 00 00 00    	mov    ecx,DWORD PTR [ebx+0x84]
  8047f9:	89 43 30             	mov    DWORD PTR [ebx+0x30],eax
  8047fc:	2b 43 10             	sub    eax,DWORD PTR [ebx+0x10]
  8047ff:	8d 51 fc             	lea    edx,[ecx-0x4]
  804802:	3b c2                	cmp    eax,edx
  804804:	76 0d                	jbe    0x804813
  804806:	c7 45 ec 04 00 00 00 	mov    DWORD PTR [ebp-0x14],0x4
  80480d:	c6 43 58 01          	mov    BYTE PTR [ebx+0x58],0x1
  804811:	eb 03                	jmp    0x804816
  804813:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  804816:	33 f6                	xor    esi,esi
  804818:	89 73 50             	mov    DWORD PTR [ebx+0x50],esi
  80481b:	89 73 54             	mov    DWORD PTR [ebx+0x54],esi
  80481e:	ff d7                	call   edi
  804820:	89 43 38             	mov    DWORD PTR [ebx+0x38],eax
  804823:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
```

### Worker virtual callback `0x804837..0x8048A3`

```asm
00804837 <.text+0x403837>:
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
  80488b:	76 16                	jbe    0x8048a3
  80488d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804890:	8b 03                	mov    eax,DWORD PTR [ebx]
  804892:	8b 93 8c 00 00 00    	mov    edx,DWORD PTR [ebx+0x8c]
  804898:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  80489b:	57                   	push   edi
  80489c:	56                   	push   esi
  80489d:	51                   	push   ecx
  80489e:	52                   	push   edx
  80489f:	8b cb                	mov    ecx,ebx
  8048a1:	ff d0                	call   eax
```

### Scheduler connected channels / queue drain `0x804A40..0x804B20`

```asm
00804a40 <.text+0x403a40>:
  804a40:	55                   	push   ebp
  804a41:	8b ec                	mov    ebp,esp
  804a43:	83 ec 18             	sub    esp,0x18
  804a46:	53                   	push   ebx
  804a47:	8b 1d a0 25 bd 00    	mov    ebx,DWORD PTR ds:0xbd25a0
  804a4d:	56                   	push   esi
  804a4e:	57                   	push   edi
  804a4f:	ff d3                	call   ebx
  804a51:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  804a58:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  804a5b:	89 47 48             	mov    DWORD PTR [edi+0x48],eax
  804a5e:	75 15                	jne    0x804a75
  804a60:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  804a67:	74 07                	je     0x804a70
  804a69:	e8 f2 64 c9 ff       	call   0x49af60
  804a6e:	eb 05                	jmp    0x804a75
  804a70:	e8 8b 65 c9 ff       	call   0x49b000
  804a75:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  804a7b:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  804a7e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804a85:	ff d3                	call   ebx
  804a87:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  804a8d:	2b c8                	sub    ecx,eax
  804a8f:	bb 01 00 00 00       	mov    ebx,0x1
  804a94:	83 f9 21             	cmp    ecx,0x21
  804a97:	76 09                	jbe    0x804aa2
  804a99:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  804a9f:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  804aa2:	8b 7e 04             	mov    edi,DWORD PTR [esi+0x4]
  804aa5:	2b 3e                	sub    edi,DWORD PTR [esi]
  804aa7:	33 c0                	xor    eax,eax
  804aa9:	c1 ff 02             	sar    edi,0x2
  804aac:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  804aaf:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  804ab2:	85 ff                	test   edi,edi
  804ab4:	0f 84 a1 01 00 00    	je     0x804c5b
  804aba:	eb 07                	jmp    0x804ac3
  804abc:	8d 64 24 00          	lea    esp,[esp+0x0]
  804ac0:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  804b1a:	c7 45 ec 00 00 00  	mov    DWORD PTR [ebp-0x14],0x0
```
