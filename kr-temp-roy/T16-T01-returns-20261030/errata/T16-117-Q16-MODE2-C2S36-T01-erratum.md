# T16-117 — T01 正式退回勘誤：Quest16 mode2、F4402、C→S 0x36 與 TalkBox 欄位（KR BIN-first）

> **作者端修復／`READY_FOR_REVIEW` 候選，非 T01 正式 `RESOLVED`、非全文 `FULL-PASS`。** 舊 T16-117 完整原稿保留不覆寫；僅針對 T01 確認的主張逐點更正，並明列受影響後續引用。

## 0. 退回身分、來源與權限邊界

- 固定退回：`T01-RETURN-T16-117-Q16-MODE2-C2S36-001`。`main` 核對時：T16 README 共 **43 個 `RESOLVED`、1 個 `NEEDS_FIX`**；本稿只修復唯一尚需作者補件的退回，不重開 43 個舊項。
- 原稿：`kr-temp-roy/20261030-034517-chatgpt-web-roy-T16-117-KR-Quest14-study5-Quest16-type2-unlock-UI-C2S-S2C.md`，Git blob `388b9100362ed43ec65ba1f7504f73518dce5d44`，**保留原樣**。
- 後續第一手修正文件：T16-121 blob `e5d48e09ac8604ac39ce0dc584bb20308d927b54`；T16-122 blob `d056bb2d0ff4ee136e13f2ff8c034434a61b2d87`。T01 審核來源 `research/handoffs/t01-20261030-quest16-r0-r2/README.md`，其 `CLM-QUEST-0007=REFUTED`、`CLM-QUEST-0006=PARTIAL`；這不是本稿自行授予 FULL-PASS。
- 本次原件：`/mnt/data/Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，唯讀。PE `.text` 的 `raw offset = VA - 0x400C00`；objdump: `-D -b binary -m i386 -M intel --adjust-vma=0x400c00`。
- 檢查基準最新 `main` 查得 `97cd5a2eb961a6052ff6682ae586e21764f6b921`、T16 工作分支當時 `c9f1219d835af81e238079d41e1b121103d77125` (`ahead=6, behind=147`)；本對話依 T16 固定規則不再自動 main→T16 Merge。README 在工作分支比 `main` 只少本固定 ID 通知，其他內容（含 43 個 `RESOLVED`）相同。
- `S00` RR 收件箱無 T16 指派；本稿不是 RR 申報。提交僅到 `t16/roy/chatgpt-web`，不合併 `main`。

## 1. 精確問題、反證與替換結論

| 原稿位置 | 舊主張（必須撤回的部分） | BIN 已證的替代結論 |
|---|---|---|
| A 開頭流程（原約第38行） | `0x105B9` 任一 mode 選 QuestInfo → `TalkBox+0x88` → F4402/`0x636E10` → `36 00 10 00` | 事件 **action** 決定 UI handler；`F438A→mode1`、`F438B→mode2`；mode2 一般流程**不能**推出 F4402 或 C2S `0x36`。 |
| **D.1**（原107–116行） | mode1／mode2／mode3 都從選擇的 QuestInfo 直接觸發 F4402，且 `0x36` 的 WORD = QuestID16 | `0x636B70`: 只有 `TalkBox+0x90==1` 且前置 gate 通過才建 F4402；`0x636DE0` 要求 action `0xF4402` 才呼叫 `0x636E10`。`0x636E82` 讀的是 `WORD*([TalkBox+0x88])`。 |
| D.2 末句（原128行） | 把 `0x36 00 10 00` 當 Quest16 type2 TalkBox 已證的「真正請求」來對比 `0x1C` | `0x1C` 確實不是直接的 QuestID payload；然而 `0x36 00 10 00` 仍**未證是 Quest16 mode2 點選請求**，不得將不等價反例提升為確定 request。 |
| **D.3**（原130–136行） | 把 `0x40` 項目與 mode1..3 `0x36` 假設相鄰寫成候選因果 | `S→C 0x40(state0,QID16)` 可建立 `F438B→mode2 TalkBox`；**不能配對原版 Server 的 `0x36↔0x40` 因果**，舊稿在「未證配對」的警告仍正確，必須更正其依賴的前述 `0x36` 先驗。 |
| D.4（原141行） | 簡化成「Q16 `0x36` 在正確 TalkBox mode/action 下發出」 | 必須具體指明 **mode1 F4402 分支**，不是一切「正確 mode」。 |
| E 表中「玩家在 TalkBox 選擇 Q16」（原148–151行附近） | `mode1/2/3 + action6A7` 都可直接建 `36 00 10 00`，`dialog+0x88` 是 QuestInfo16 | 改成兩種獨立事件：`F438B→mode2` 僅確認 UI；`mode1+F4402 + outer 0x105BD/6A7 + TalkBox+88!=null + sender gate` 才可能建四 byte `36 00 [WORD*QuestTalk]`。是否為16要另證資料值。 |
| F `SPEC-Q16-REQUEST-DRAFT`、`G` 已確認摘要、`H` 第三輪（原160、172、191行附近） | 將 mode1..3 的 `0x36(QID16)` 作成可供 Server 實作的肯定規格／完成證據 | **撤回 `SPEC-Q16-REQUEST-DRAFT` 中的該款以及相同肯定摘要**；改依本稿受限 schema，Quest16 mode2 submit 的實際送出來源列 `Client 待逆向`。不得僅憑舊稿生成 Server accept 封包。 |

### 1.1 重新限定的正確 Client 流程（不可拼出原版 Server 決策）

```text
NPC10027 / Quest type2 candidate16 (依 Demand14、town、level、exclusion gate)
  → controller branch (可能送 C→S 0x1C 或條件式 0x3F；各有不同欄位來源)
  [此處不能假設原版 Server 如何回覆]
S→C application 0x40, state0, QID16
  → 0x502270 產生 action F438B、event+0x14=16
  → 0x5B7F80 dispatch → 0x5B6D20 → 0x636520(mode2)
  → TalkBox+0x80=16；TalkBox+0x84=giver selector；TalkBox+0x88=QuestTalk record pointer
  [mode2 UI 本身不等於 F4402、也不證明發出 0x36]

不同的 mode1 UI 路徑：
  TalkBox+0x90==1 / +0xAC gate → 0x636BFF 建 action F4402
  → 0x636DF8 action gate → 0x636E10
  → outer event type0x105BD / action 0x6A7；+0x88 非零；[0xFBA798]==0
  → C→S app payload u16(0x36), u16(WORD*([TalkBox+0x88]))；傳送佇列

另一個與 TalkBox 不同的 producer：
  0x4B3510 → u16(0x36), u16(WORD[input_msg+2]) → same gated sender
  [table slot 0x4D 的業務／wire 分派尚未完整閉合，不得假稱 mode2 正常 submit]
```

### 1.2 邏輯反例與保留主張

- **反例 A — mode2：** `+0x90==2`，且 `+0xAC<=1`，在 `0x636BD6 !=1` 且 `0x636C84 !=3`，直接落到 `0x636CFA`；此函式路徑**不建立 F4402**。這是否涵蓋所有其他 UI 元件及事件 producer，仍待確認；不是對所有 mode2 送包路徑的全稱否定。
- **反例 B — QuestID 與對話指標不等值：** `0x63655D` 把入參存 `TalkBox+0x80`；`0x6365A5` 先清 `+0x88`，`0x6366A3` 將 `0x500F90` 返回指標存 `+0x88`；`0x636E82` 從其指向記錄取 WORD，與 `+0x80` 不同基底。即使數值偶然同為 16，也不足以推定「id16 的 mode2 接取封包」。
- **反例 C — 相同 bytes 不代表相同原因：** 若 mode1 QuestTalk 首個 WORD=16，或 `0x4B3510` 的 input+2 WORD=16，均可有 `36 00 10 00`，但根源與 mode2 QuestInfo 選取不同。
- 保留不撤回：`Demand14`、`0x74 key14→0x500240`、`0x500A00` 的 type2 篩選、`0x1C` 的巢狀事件 WORD、`S→C 0x40` state0/state1 **有界 handler**、以及「0x36 與 0x40 未證唯一配對」的原有警告。這些不因單一 T01 錯誤被全篇否決。

## 2. 第一手 KR BIN 指令與可重現原件切片

下列所有切片直接自指定 SHA 的 KR BIN 按 PE VA→raw 映射擷取，非從反編譯稿推導。截斷尾端若出現部分指令，**只採證完整的前綴指令**。給出每段 `[start,end)`、SHA256 與直接 objdump disassembly。

### S01 mode1 gate / F4402 writer

- VA `[0x00636BBE,0x00636C08)`; raw `[0x00235FBE,0x00236008)`; 74 bytes; SHA256 `de0f854fa7efe3e49b8b3cc4580748b2f8cca0bb780afb1153ad9697dc9fcee1`.

```asm
00636bbe <.data+0x235fbe>:
  636bbe:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636bc4:	33 db                	xor    ebx,ebx
  636bc6:	3b c3                	cmp    eax,ebx
  636bc8:	75 0c                	jne    0x636bd6
  636bca:	8b f7                	mov    esi,edi
  636bcc:	e8 4f 01 00 00       	call   0x636d20
  636bd1:	e9 24 01 00 00       	jmp    0x636cfa
  636bd6:	83 f8 01             	cmp    eax,0x1
  636bd9:	0f 85 a5 00 00 00    	jne    0x636c84
  636bdf:	6a 14                	push   0x14
  636be1:	e8 82 a6 25 00       	call   0x891268
  636be6:	83 c4 04             	add    esp,0x4
  636be9:	3b c3                	cmp    eax,ebx
  636beb:	74 1b                	je     0x636c08
  636bed:	83 c9 ff             	or     ecx,0xffffffff
  636bf0:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636bf3:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  636bf9:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636bfc:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636bff:	c7 40 10 02 44 0f 00 	mov    DWORD PTR [eax+0x10],0xf4402
  636c06:	8b d8                	mov    ebx,eax
```

### S02 mode3 writer and mode2 fallthrough

- VA `[0x00636C84,0x00636CFA)`; raw `[0x00236084,0x002360FA)`; 118 bytes; SHA256 `3099070a534bbe39f8a0239dea9968031f3be268fcf9163a577c36de611f0e66`.

```asm
00636c84 <.data+0x236084>:
  636c84:	83 f8 03             	cmp    eax,0x3
  636c87:	75 71                	jne    0x636cfa
  636c89:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c8f:	3b c3                	cmp    eax,ebx
  636c91:	74 67                	je     0x636cfa
  636c93:	8b 10                	mov    edx,DWORD PTR [eax]
  636c95:	52                   	push   edx
  636c96:	51                   	push   ecx
  636c97:	e8 94 8c dd ff       	call   0x40f930
  636c9c:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  636ca2:	83 c4 04             	add    esp,0x4
  636ca5:	8b d0                	mov    edx,eax
  636ca7:	e8 24 9b ec ff       	call   0x5007d0
  636cac:	0f b7 f0             	movzx  esi,ax
  636caf:	85 f6                	test   esi,esi
  636cb1:	74 47                	je     0x636cfa
  636cb3:	6a 18                	push   0x18
  636cb5:	e8 ae a5 25 00       	call   0x891268
  636cba:	83 c4 04             	add    esp,0x4
  636cbd:	85 c0                	test   eax,eax
  636cbf:	74 1e                	je     0x636cdf
  636cc1:	83 c9 ff             	or     ecx,0xffffffff
  636cc4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636cc7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636cca:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636ccd:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  636cd4:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  636cda:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  636cdd:	eb 02                	jmp    0x636ce1
  636cdf:	33 c0                	xor    eax,eax
  636ce1:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  636ce5:	e8 b6 dd dc ff       	call   0x404aa0
  636cea:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  636cee:	51                   	push   ecx
  636cef:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  636cf5:	e8 66 d5 1c 00       	call   0x804260
```

### S03 local callback F4402 gate

- VA `[0x00636DF8,0x00636E06)`; raw `[0x002361F8,0x00236206)`; 14 bytes; SHA256 `0684c2080a73774ed3775d0db06007be298203ca6f076ba3538f076d9caa2b40`.

```asm
00636df8 <.data+0x2361f8>:
  636df8:	81 7e 10 02 44 0f 00 	cmp    DWORD PTR [esi+0x10],0xf4402
  636dff:	75 05                	jne    0x636e06
  636e01:	e8 0a 00 00 00       	call   0x636e10
```

### S04 actual 0x36 producer / pointer source / sender

- VA `[0x00636E42,0x00636EB9)`; raw `[0x00236242,0x002362B9)`; 119 bytes; SHA256 `0cda34dd348d278422c5a6adb64da226307f643cbff0c0342c5f1b6ad43d95e6`.

```asm
00636e42 <.data+0x236242>:
  636e42:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636e45:	3d a7 06 00 00       	cmp    eax,0x6a7
  636e4a:	75 6d                	jne    0x636eb9
  636e4c:	83 bf 88 00 00 00 00 	cmp    DWORD PTR [edi+0x88],0x0
  636e53:	74 77                	je     0x636ecc
  636e55:	b8 01 00 00 00       	mov    eax,0x1
  636e5a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  636e60:	75 13                	jne    0x636e75
  636e62:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  636e68:	68 10 cf bc 00       	push   0xbccf10
  636e6d:	e8 a8 b4 25 00       	call   0x89231a
  636e72:	83 c4 04             	add    esp,0x4
  636e75:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  636e7c:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  636e82:	66 8b 11             	mov    dx,WORD PTR [ecx]
  636e85:	b8 36 00 00 00       	mov    eax,0x36
  636e8a:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  636e8e:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  636e92:	75 2c                	jne    0x636ec0
  636e94:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  636e9a:	8b 01                	mov    eax,DWORD PTR [ecx]
  636e9c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  636e9f:	6a 04                	push   0x4
  636ea1:	8d 55 fc             	lea    edx,[ebp-0x4]
  636ea4:	52                   	push   edx
  636ea5:	6a 00                	push   0x0
  636ea7:	ff d0                	call   eax
  636ea9:	8b 17                	mov    edx,DWORD PTR [edi]
  636eab:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636eb1:	8b cf                	mov    ecx,edi
  636eb3:	ff d0                	call   eax
  636eb5:	8b e5                	mov    esp,ebp
  636eb7:	5d                   	pop    ebp
  636eb8:	c3                   	ret
```

### S05 independent 0x36 producer

- VA `[0x004B3510,0x004B356C)`; raw `[0x000B2910,0x000B296C)`; 92 bytes; SHA256 `71b378cac33808dc4419240471935b14535edabd107b8ca1bad0664f8b14793c`.

```asm
004b3510 <.data+0xb2910>:
  4b3510:	55                   	push   ebp
  4b3511:	8b ec                	mov    ebp,esp
  4b3513:	51                   	push   ecx
  4b3514:	b8 01 00 00 00       	mov    eax,0x1
  4b3519:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  4b351f:	75 13                	jne    0x4b3534
  4b3521:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  4b3527:	68 10 cf bc 00       	push   0xbccf10
  4b352c:	e8 e9 ed 3d 00       	call   0x89231a
  4b3531:	83 c4 04             	add    esp,0x4
  4b3534:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b353b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b353e:	66 8b 51 02          	mov    dx,WORD PTR [ecx+0x2]
  4b3542:	b8 36 00 00 00       	mov    eax,0x36
  4b3547:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4b354b:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  4b354f:	75 15                	jne    0x4b3566
  4b3551:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b3557:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b3559:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b355c:	6a 04                	push   0x4
  4b355e:	8d 55 fc             	lea    edx,[ebp-0x4]
  4b3561:	52                   	push   edx
  4b3562:	6a 00                	push   0x0
  4b3564:	ff d0                	call   eax
  4b3566:	33 c0                	xor    eax,eax
  4b3568:	8b e5                	mov    esp,ebp
  4b356a:	5d                   	pop    ebp
  4b356b:	c2               	ret    0xc
```

### S06 TalkBox QuestID +0x80 / mode +0x90 / pointer init

- VA `[0x0063654E,0x006365AB)`; raw `[0x0023594E,0x002359AB)`; 93 bytes; SHA256 `839b88b1592adce784a18729c6a94a987e22e21b5e6ac85233cd25f02becb511`.

```asm
0063654e <.data+0x23594e>:
  63654e:	8b fa                	mov    edi,edx
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
```

### S07 mode2 QuestTalk pointer writer

- VA `[0x00636687,0x006366B8)`; raw `[0x00235A87,0x00235AB8)`; 49 bytes; SHA256 `162e0536de27bebb43565a850e73ff5ea8701db587c6663327873fbece7eb0e9`.

```asm
00636687 <.data+0x235a87>:
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
```

### S08 F438B mode2 event consumer

- VA `[0x005B6DAE,0x005B6E30)`; raw `[0x001B61AE,0x001B6230)`; 130 bytes; SHA256 `89dabd3a9353d095083c6d10d3c5911ae76e8da1b187ac8110688ee45a133533`.

```asm
005b6dae <.data+0x1b61ae>:
  5b6dae:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6db1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6db7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6dbb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6dbf:	51                   	push   ecx
  5b6dc0:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6dc4:	8b ce                	mov    ecx,esi
  5b6dc6:	e8 55 cf f4 ff       	call   0x503d20
  5b6dcb:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6dce:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6dd2:	3b c6                	cmp    eax,esi
  5b6dd4:	74 6c                	je     0x5b6e42
  5b6dd6:	8d 70 10             	lea    esi,[eax+0x10]
  5b6dd9:	85 f6                	test   esi,esi
  5b6ddb:	74 65                	je     0x5b6e42
  5b6ddd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6de4:	75 29                	jne    0x5b6e0f
  5b6de6:	b8 01 00 00 00       	mov    eax,0x1
  5b6deb:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6df1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6df5:	e8 96 7e f2 ff       	call   0x4dec90
  5b6dfa:	68 30 ce bc 00       	push   0xbcce30
  5b6dff:	e8 16 b5 2d 00       	call   0x89231a
  5b6e04:	83 c4 04             	add    esp,0x4
  5b6e07:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6e0e:	ff 
  5b6e0f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6e12:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6e17:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6e1a:	52                   	push   edx
  5b6e1b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e21:	6a 02                	push   0x2
  5b6e23:	50                   	push   eax
  5b6e24:	e8 f7 f6 07 00       	call   0x636520
  5b6e29:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6e2f:	51                   	push   ecx
```
## 3. 下游引用逐項審核（原稿保留，不靜默覆寫）

| 來源 | 查核結論與處理 |
|---|---|
| **T16-117 本文** | A 概覽、D.1、D.2 末句、D.3 依賴、D.4、E、F、G、H 的舊 mode1..3→0x36(QID16) 肯定句**由本勘誤正式取代**；原始 blob 為歷史證據，讀者必須同時閱讀本稿。 |
| **T16-121** `e5d48...` | 已原生區分 `F438A→mode1` 和 `F438B→mode2`，並證明 `0x40,state0,QID16→mode2 TalkBox` 的受限路徑；其「下一段追 mode2 0x36」是研究方向，不得當完成證據。 |
| **T16-122** `d056bb...` | 已明確否定 mode2 直接 F4402，記載獨立 `0x4B3510` 與 TalkBox `+0x80/+0x88`；作為本修正的主要相互印證，而不是取代獨立勘誤。 |
| **T16-118～120、123～131** | 對本次可取得的 T16-118～131 本地完整 Markdown 逐檔搜尋 `F4402`／`0x36 00 10 00`／`TalkBox+0x88`／`mode2` 等敏感敘述，未見另外一篇繼續肯定 **「Quest16 mode2 一定走 F4402 送 0x36,QID16」**；T16-125、126、127、130、131 反而明示 T16-117 待修正。這僅限列出的本地檔案，不聲稱全 GitHub 所有文字均已覆核。 |
| **T16-114 早期 ID14 0x36** | 不因 QID16 mode2 的反證就否定另一任務／mode 的所有產生條件；若未來用於 S00，必須依其自身 producer 逐項審核，不能由本稿自動保證。 |
| **T01 `CLM-QUEST-0007`** | 原本被反駁的廣泛 mode1..3 主張繼續保持 `REFUTED` 歷史；本勘誤不自行修改 T01 claim、`research/intake` 或 `shared/verified-knowledge` 索引。 |
| **S00 / Server SPEC / TEST** | 取消依賴舊 `SPEC-Q16-REQUEST-DRAFT` 的「Quest16 mode2 confirm 必送 0x36」假設；改用已證的 Client producer schema 與 `GAP-Q16-MODE2-REAL-SUBMIT`，封包因果與 server policy 另行驗證。 |

### 3.1 可提交給後續整合的最小正確契約

1. **Quest16 本地候選**：key14 必須滿足 `Demand14`，type2 giver NPC10027 選取需通過其餘 gate；本身不代表已發包或成功接取。
2. **NPC 交互 C→S**：`0x1C` 使用巢狀事件兩個 WORD；控制器 `0x3F` 要求其他 gate，payload 欄位不與 `0x36` 混用。
3. **S→C state0 UI**：`0x40` 的 QuestID WORD / status DWORD 經 `F438B→mode2` 打開受限 TalkBox；不宣稱原版 Server 因哪個請求回覆。
4. **`0x36`**：TalkBox mode1、F4402、outer type/action gate，或另一獨立 handler `0x4B3510` 的各自 producer，均只可稱 **application payload**；不得宣稱封包完成 wire framing、Server ACK、Quest16 接取／交付。
5. **Open**：mode2 真正 submit producer、`0x4B3510` 的完整 inbound namespace、`0x3F↔0x40` 原版配對、接受／拒絕／完成業務語意、獎勵及保存，仍未確定。

## 4. 提交與 T01 驗收動作

- 本勘誤寫作完成後，將完整 `.md` 作為**新的獨立 Git blob** 提交到 `t16/roy/chatgpt-web`；**不能覆寫 T16-117**。
- 在 **T16 工作分支**的 `kr/tasks/T16/README.md` **新增相同固定退回 ID** 並更新作者端狀態 `READY_FOR_REVIEW`，引用本勘誤精確 repo 路徑、Git blob SHA、原件 SHA 與原始反證。既有 43 個 `RESOLVED` 不改。
- 因主線目前仍保留 `NEEDS_FIX`、此對話禁止自行重新 main→T16 Merge 或合回 main，本次工作分支 `READY_FOR_REVIEW` **不是已在 `main` 發布的正式驗收狀態**；待依既有協作流程納入 main，T01 才能據以獨立複驗。不能自行把任何項目標成 `RESOLVED`。
- **Client 待逆向**：Quest16 mode2 真正按鍵送出的全部 producer、正負回覆配對。**Server 待開發**：任務接取、完成、拒絕、進度持久化與獎勵。**跨功能待整合**：T02 framing、UI 事件與 NPC/Quest 讀端；是否分派其他 Task 由 S00 決定。**待遊玩驗證**：原版 Client 與相容 Server 聯機操作、封包到達時序、UI 和狀態結果。

**結論：此為 T16 作者端退回定向修復材料，可申請 T01 `READY_FOR_REVIEW`，不宣稱 `RESOLVED`、全文 FULL-PASS 或可玩。**
