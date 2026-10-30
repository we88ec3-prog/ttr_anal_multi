# T16-98 — KR 同一 channel 的 queued frame → virtual WSASend 直接 callsite 閉合（BIN-first）

研究者 `chatgpt-web roy`；時間 20261028-225623 Asia/Taipei。正式 T16-98，僅 KR client 靜態逆向；此原稿按本次明確授權推送至 `t16/roy/chatgpt-web`。**重大新發現：首次在原始機器碼中找到把先前 queue-drain/frame-buffer 消費的同一 `ESI` channel 指標，經由 `[FBA854]` vtable+0x0C 呼叫到已確認 WSASend wrapper 的直接送出 callsite。這是通用 channel 的原生出站鏈閉合，不是 Quest 專屬 wire opcode 的確認。**

## 0. 來源、版本與 Git 門檻

- `/mnt/data/Tartaros.bin`：實測 12472320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `/mnt/data/Tartaros.exe`：實測 2594816 bytes；SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE32 `.text` VA `0x00401000`, raw `0x400` ⇒ raw=VA−`0x00400C00`；`.rdata` VA `0x00BD2000`, raw `0x007D0600` ⇒ raw=VA−`0x00401A00`。以原始 PE section header 與 objdump 核實。
- 當輪開工查 GitHub 遠端 compare：main HEAD `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355`，`t16/roy/chatgpt-web` 相對 main ahead 7、behind 0，merge-base=main；無待合併提交。本輪只在已同步分支之後開工。
- 導航用 T16-93～97 完整原稿；下列 assembly 是對 SHA 匹配的 KR BIN 直接 `objdump -D -M intel`，不是反編譯臆測。只作唯讀；不執行、修改或提交 EXE／BIN。未修改 T02 或其他 Task。

## 1. 第一輪 T16-98：發現 0x804B5A 傳送呼叫點，證實 channel pointer 身分

T16-95 已定位 `0x804AD6` 與 `0x805228` 直接呼叫 `0x8061A0`，傳入的通道指標為 `ESI`。本輪由 `0x804AC8` 原生 assembly 觀察到同一 `ESI+0xA0AC` gate；`0x804AD5 push ESI; call 0x8061A0`，其 downstream `0x80621E`/`0x80623A` 實際依模式走 `0x807830`/`0x807A70` frame builder，目標 frame 在 `ESI+0x501C`、待送 len 在 `ESI+0x500C`。

最重要的新呼叫點從 `0x804B21` 起：

```asm
804b21: 83 be 28 a0 00 00 00  cmp DWORD PTR [esi+0xa028],0
804b28: 0f 84 1d 01 00 00     je ...
804b2e: 8b 86 b8 a0 00 00     mov eax,[esi+0xa0b8]
804b34: 85 c0                 test eax,eax
804b36: 0f 8f 0f 01 00 00     jg ...
804b3c: 8b 86 28 a0 00 00     mov eax,[esi+0xa028]
804b42: 8b 0d 54 a8 fb 00     mov ecx,[0xfba854]
804b48: 8b 11                 mov edx,[ecx]
804b4a: 8b 52 0c              mov edx,[edx+0xc]
804b4d: 8d 7d ec              lea edi,[ebp-0x14]
804b50: 57                    push edi
804b51: 50                    push eax
804b52: 8d 86 20 50 00 00     lea eax,[esi+0x5020]
804b58: 50                    push eax
804b59: 56                    push esi
804b5a: ff d2                 call edx
804b5c: 85 c0                 test eax,eax
804b5e: 75 1c                 jne 0x804b7c
```

依 x86 thiscall／stdcall 參數順序，`this=[0xFBA854]`，四個 stack arguments 依序為：`channel=ESI`, `dataPtr=ESI+0x5020`, `len=[ESI+0xA028]`, `outPtr=&[EBP-0x14]`。`0x8068B0` 入口讀 `arg0=[EBP+8]` 作 channel、`arg1=[EBP+0xC]` 作 buffer pointer、`arg2=[EBP+0x10]` 作 length，且 `arg3=[EBP+0x14]` 為 bytes-sent 輸出 pointer；**stack register/ABI 對應直接吻合**。`0x8068DE` 使用 `channel+0xA050` OVERLAPPED，`0x806912` 透過 PE import WSASend IAT 呼叫。

這裡是**同一個 channel `ESI`** 從 queue-drain（`0x804AD6`）延續到 WSASend callsite（`0x804B5A`），不再僅是相鄰 helper 或同一類別的推測。但 `0x8061A0` 是否真的插入 frame、是否走 `0x804B21`、socket API 是否成功皆受條件與結果支配；不是每次觸發都保證送出。

## 2. 第二輪 T16-98-2：vtable 正式對照，建立 producer 和 sender 的相同 owner

`.rdata` `0x00C51748` (= raw `0x0084FD48`) 的原始 little-endian slots（由 BIN raw 直接讀）：

| slot | `.rdata` VA | raw | little-endian target | 作用／限制 |
|---|---|---|---|---|
| +0x00 | 0x00C51748 | 0x0084FD48 | 0x00806670 | 未完全確認生命週期語意 |
| +0x04 | 0x00C5174C | 0x0084FD4C | 0x00806CF0 | completion dispatcher（T16-97） |
| +0x08 | 0x00C51750 | 0x0084FD50 | 0x00806850 | 初始化相關方法 |
| **+0x0C** | **0x00C51754** | **0x0084FD54** | **0x008068B0** | **本輪發送 callsite `0x804B5A` 的 target，內含 WSASend** |
| **+0x10** | **0x00C51758** | **0x0084FD58** | **0x008069A0** | **T16-94 的訊息 producer/queue method** |
| +0x14 | 0x00C5175C | 0x0084FD5C | 0x00806A00 | receive-side native method 候選 |

T16-94 已由 native `0x8046F7` 建立 `[0xFBA854]` object 的 vptr= `0xC51748`，而 `0x596FBA` 以相同 global `vtable+0x10` 投入 4-byte 候選資料。現在有第二條 native callsite `0x804B42–0x804B5A`，以 **同一 `[FBA854]` global** 取 `vtable+0x0C` 進 `0x8068B0`。因此可證實**同一個多型 sender owner 可供 producer 入列及後段 sender API 呼叫**；具體是哪個 channel 實例由 `ESI` 指定並延續至 send wrapper。

注意：同一 global owner 不代表原始 4 bytes 必然繞過 lookup gate、尺寸 gate、queue 排程、frame builder 變換、buffer 發送條件；**0x00010049 不可逕稱 Quest wire opcode，也不能把 `49 00 01 00` 直接等同 socket 完整 bytes**。正常成功的 `[ESI+0xA028]` 長度可能由 buffer preparation/其他路徑更新，不能假定始終等於當初 4-byte user payload。

## 3. 條件與反證、對 T16-95/96/97 的修訂

- `0x804AC8` 確認 `[channel+0xA0AC] != 0` 方會 call `0x8061A0`；`0x804AD6` 使用的 channel 與 `0x804B5A` 參數 `ESI` 相同。`0x804B21` 需 `[channel+0xA028] != 0`，並於 `0x804B2E–0x804B36` 篩除 `[channel+0xA0B8] > 0`；成功條件必須追 source writer 才能說明何時實際發送。
- `0x804B5C` return 0 則走 `0x804B60 → 0x8063E0` 等失敗分支；非零也不必然代表 Server 已處理 request。`0x8068B0` 仍可能回傳 1 同步、2 pending、0 失敗、-1 參數/狀態錯誤，按 T16-96 原生 return 分支限制。
- `0x806E7D` completion 與 `channel+0xA050` identity 及 `0x806EA1 → 0x8077B0` 回收仍依 T16-97。有了本輪 `0x804B5A` direct source 後，這套機制現在可與 frame builder 識別為同一個 channel object 的典型 outbox lifecycle，**但不能宣稱全部事件一定依相同時序發生**。
- 更正前段的嚴格缺口：T16-96/97 說「尚未證明 frame builder→WSASend 的同一 channel 實例」；本輪已以 `ESI` 的 caller 傳遞閉合該點。**未閉合邊界改為 Quest 業務 opcode、正常實例中 key0 可否查找成功、frame bytes 與 Server 回應內容**。

## 4. 第三輪門檻

- T16-98 第一輪：找出 `0x804B5A` 的真實 indirect callsite，第一手組語確認 `ESI` channel、`ESI+0x5020` data、`ESI+0xA028` length 與 `0x8068B0` ABI 全部對應；是消除前段重大未知的有界完整功能鏈進展。
- T16-98-2 第二輪：獨立由 `.rdata` raw vtable slot、`[FBA854]` 初始化和 `0x596FBA` 的 producer 交叉驗證，確認 producer/sender 在同一 owner 而非單純位址類比；補查 gate 與 failure。
- T16-98-3：**未啟動**。前兩輪已達共用 02 三輪深入門檻的重大新發現標準，明示未做而不是捏造。

## 5. 玩家情境 × Client↔Server matrix

| 玩家操作／事件 | Client gate | C→S | S→C | Client 本地結果 | 待開發 Server／未知 |
|---|---|---|---|---|---|
| NPC/Quest 候選 user callback（T16-93） | `0x596FBA` gate + `[FBA854] vtable+0x10` map key0 lookup；queue/buffer gate | 在已證條件滿足時 4 bytes 可以進 native queue，後續同 channel 網路發送通路已知；**此訊息實際 wire 的 opcode/bytes 仍 unknown** | **unknown** | 一般 outbox scheduler/framers 可以消費待送節點 | Client 業務 request/response、角色／Quest 變更未知 |
| 任意已入列 channel frame | `[A0AC]`、`[A028]`、`[A0B8]` 與全域 scheduler | 通道沿 `0x804AD6 → 0x8061A0 → frame buffer → 0x804B5A vcall → 0x8068B0 → WSASend`；**有條件的原生呼叫鏈確認** | 非業務 S→C | WSASend 結果可能同步、pending、失敗 | 同筆 frame 是否被 Server 接收／處理需 wire capture |
| 非同步 send completion | `channel+0xA050` OVERLAPPED 身分 | T16-97 已證 `0x806EA1 → 0x8077B0` | 非 Quest 回包 | 發送已完成位元組的 pending buffer 消費 | 不等於 Quest 已成功 |
| Quest16 完成→Quest15 可接取 | QuestInfo XML static read-side 存在 | **unknown** | **unknown** | quest state writer 與 NPC update 仍未證 | 需 native Quest handler/reply 與 QuestInfo actual content |

## 6. 偽碼（非原始 class/function 名稱）

```cpp
void generic_channel_tick(SenderOwner* owner, Channel* channel) {
    if (channel->field_A0AC != 0) {
        bool drained = drain_queue(channel); // 0x804AD6 → 0x8061A0, may build frame
        if (!drained) { /* conditional scheduling/backoff */ }
    }
    if (channel->field_A028 != 0 && channel->field_A0B8 <= 0) {
        uint32_t sent_or_pending_out = 0;
        int result = owner->vtable_slot_0C(channel, channel->base + 0x5020,
                                            channel->field_A028, &sent_or_pending_out);
        // default owner vptr 0xC51748, slot+0x0C = 0x8068B0 → WSASend
        if (!result) { /* 0x8063E0 and other recovery operations */ }
    }
}
```

虛擬呼叫僅在已見 owner vptr 的具體路徑解析；有 runtime vptr 改寫或不同 instance 時需另驗。此偽碼刻意略去詳細 scheduler/加密 helper，不能以此取代下列 raw dump。

## 7. 未解事項與 T16-99 研究入口

1. 從 `0x804B5A` 的 send 前資料走到 `0x8061A0` 的 mode framing bytes，核定原始 outbox `0x00010049` 最終 wire 在何種模式下出現（如有）與 framing；但先檢查 `0x8438C0` key0 lookup 的真實表 writer，否則不可聲稱必然發送。
2. T16 P0 優先恢復 Quest 相關 **S→C opcode dispatcher → dynamic quest writer → NPC/UI**；以 `[FB114C]` read-side 之外的動態狀態、Server snapshot、handler 尋址，跨 T02 只引用其已證接收骨架。
3. Quest16→Quest15 必須同時取得接取 C→S 與確認/拒絕 S→C，否則不得稱 Client 雙向互動已完成；原版 Server 規則列相容待開發。

## 8. 附錄：同版原始 BIN x86 組語與 VA/raw 證據

`0x00C51748` raw DWORD list：`00806670 00806cf0 00806850 008068b0 008069a0 00806a00 00806ad0 00806f60 00806f80 00806fc0 00807090`；截取範圍以 section header 與指令邊界驗證。下方是 objdump 真實輸出。

### I. channel scheduler reads queued/pending flags; VA 0x804ac3–0x804b1a; `.text` raw 0x403ec3–0x403f1a

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00804ac3 <.text+0x403ac3>:
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

```

### II. decisive vtable +0x0C send callsite; VA 0x804b1a–0x804b9b; `.text` raw 0x403f1a–0x403f9b

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00804b1a <.text+0x403b1a>:
  804b1a:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  804b21:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  804b28:	0f 84 1d 01 00 00    	je     0x804c4b
  804b2e:	8b 86 b8 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0b8]
  804b34:	85 c0                	test   eax,eax
  804b36:	0f 8f 0f 01 00 00    	jg     0x804c4b
  804b3c:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  804b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b48:	8b 11                	mov    edx,DWORD PTR [ecx]
  804b4a:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  804b4d:	8d 7d ec             	lea    edi,[ebp-0x14]
  804b50:	57                   	push   edi
  804b51:	50                   	push   eax
  804b52:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  804b58:	50                   	push   eax
  804b59:	56                   	push   esi
  804b5a:	ff d2                	call   edx
  804b5c:	85 c0                	test   eax,eax
  804b5e:	75 1c                	jne    0x804b7c
  804b60:	56                   	push   esi
  804b61:	e8 7a 18 00 00       	call   0x8063e0
  804b66:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b6c:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b6e:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b71:	6a 00                	push   0x0
  804b73:	56                   	push   esi
  804b74:	ff d2                	call   edx
  804b76:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  804b7c:	83 be b0 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0b0],0x0
  804b83:	74 16                	je     0x804b9b
  804b85:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  804b8d:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  804b90:	6a 00                	push   0x0
  804b92:	56                   	push   esi
  804b93:	ff d2                	call   edx
  804b95:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx

```

### III. post-send branch and backpressure; VA 0x804b9b–0x804c48; `.text` raw 0x403f9b–0x404048

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00804b9b <.text+0x403b9b>:
  804b9b:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  804ba2:	01 00 00 
  804ba5:	0f 8e 9d 00 00 00    	jle    0x804c48
  804bab:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  804bb2:	0f 85 90 00 00 00    	jne    0x804c48
  804bb8:	56                   	push   esi
  804bb9:	e8 22 18 00 00       	call   0x8063e0
  804bbe:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  804bc1:	8b b8 8c 00 00 00    	mov    edi,DWORD PTR [eax+0x8c]
  804bc7:	85 ff                	test   edi,edi
  804bc9:	74 51                	je     0x804c1c
  804bcb:	8b 8e a0 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0a0]
  804bd1:	8b 96 90 a0 00 00    	mov    edx,DWORD PTR [esi+0xa090]
  804bd7:	8b 86 9c a0 00 00    	mov    eax,DWORD PTR [esi+0xa09c]
  804bdd:	51                   	push   ecx
  804bde:	8b 8e 8c a0 00 00    	mov    ecx,DWORD PTR [esi+0xa08c]
  804be4:	52                   	push   edx
  804be5:	8b 96 98 a0 00 00    	mov    edx,DWORD PTR [esi+0xa098]
  804beb:	50                   	push   eax
  804bec:	8b 86 88 a0 00 00    	mov    eax,DWORD PTR [esi+0xa088]
  804bf2:	51                   	push   ecx
  804bf3:	8b 8e 94 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa094]
  804bf9:	52                   	push   edx
  804bfa:	8b 96 84 a0 00 00    	mov    edx,DWORD PTR [esi+0xa084]
  804c00:	50                   	push   eax
  804c01:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804c07:	51                   	push   ecx
  804c08:	8b 0e                	mov    ecx,DWORD PTR [esi]
  804c0a:	52                   	push   edx
  804c0b:	50                   	push   eax
  804c0c:	51                   	push   ecx
  804c0d:	68 38 14 c5 00       	push   0xc51438
  804c12:	6a 02                	push   0x2
  804c14:	e8 e7 b7 ee ff       	call   0x6f0400
  804c19:	83 c4 30             	add    esp,0x30
  804c1c:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  804c23:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  804c29:	8b 11                	mov    edx,DWORD PTR [ecx]
  804c2b:	75 0d                	jne    0x804c3a
  804c2d:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  804c30:	56                   	push   esi
  804c31:	ff d0                	call   eax
  804c33:	e8 d8 13 00 00       	call   0x806010
  804c38:	eb 08                	jmp    0x804c42
  804c3a:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  804c3d:	6a 00                	push   0x0
  804c3f:	56                   	push   esi
  804c40:	ff d0                	call   eax
  804c42:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx

```

### IV. vtable target WSASend; VA 0x8068b0–0x806998; `.text` raw 0x405cb0–0x405d98

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008068b0 <.text+0x4058b0>:
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff

```

### V. queue drain same channel instance; VA 0x8061c8–0x80627b; `.text` raw 0x4055c8–0x40567b

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008061c8 <.text+0x4051c8>:
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]

```

### VI. buffer framing path mode switch; VA 0x807a70–0x807b3b; `.text` raw 0x406e70–0x406f3b

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00807a70 <.text+0x406a70>:
  807a70:	55                   	push   ebp
  807a71:	8b ec                	mov    ebp,esp
  807a73:	83 ec 08             	sub    esp,0x8
  807a76:	53                   	push   ebx
  807a77:	56                   	push   esi
  807a78:	8b 37                	mov    esi,DWORD PTR [edi]
  807a7a:	56                   	push   esi
  807a7b:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  807a7e:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2 08 00             	ret    0x8
  807b19:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  807b1c:	52                   	push   edx
  807b1d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b23:	5e                   	pop    esi
  807b24:	33 c0                	xor    eax,eax
  807b26:	5b                   	pop    ebx
  807b27:	8b e5                	mov    esp,ebp
  807b29:	5d                   	pop    ebp
  807b2a:	c2 08 00             	ret    0x8
  807b2d:	56                   	push   esi
  807b2e:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b34:	5e                   	pop    esi
  807b35:	33 c0                	xor    eax,eax
  807b37:	5b                   	pop    ebx
  807b38:	8b e5                	mov    esp,ebp
  807b3a:	5d                   	pop    ebp

```

### VII. slot +0x10 producer -> queue; VA 0x8069a0–0x8069f6; `.text` raw 0x405da0–0x405df6

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008069a0 <.text+0x4059a0>:
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2 0c 00             	ret    0xc

```

### VIII. completion channel identity; VA 0x806e65–0x806ed0; `.text` raw 0x406265–0x4062d0

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00806e65 <.text+0x405e65>:
  806e65:	95                   	xchg   ebp,eax
  806e66:	ee                   	out    dx,al
  806e67:	ff 8b 45 e4 83 c4    	dec    DWORD PTR [ebx-0x3b7c1bbb]
  806e6d:	20 c7                	and    bh,al
  806e6f:	80 b0 a0 00 00 01 00 	xor    BYTE PTR [eax+0x10000a0],0x0
  806e76:	00 00                	add    BYTE PTR [eax],al
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b               	mov    ecx,DWORD PTR [ebp-0x20]

```