# KR T16-73 補充輪次（-2 / -3）— Worker callback 參數修正與 `outer+0x140` 寫入查找

- 研究時間：20261028-185148 Asia/Taipei；分析者 `chatgpt-web roy`；**僅 KR**。
- 原生 BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes。
- 原生 EXE SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，2,594,816 bytes。
- 原始檔唯讀；不執行、不 patch、不附加 Client；此次未請求 GitHub commit/push。
- 本補充記錄與既有 `20261028-184700-chatgpt-web-roy-T16-73-KR-inbound-worker-owner-and-callback-boundary.md` **共同構成 T16-73 工作原稿**；不覆寫已推送舊檔。

## 1. 原始 PE 映射與核對

BIN DOS `MZ`、PE `PE\0\0` 正常，`e_lfanew=0x120`。section header 從原始位元組解析：

| section | RVA | VirtualSize | raw start | raw size |
|---|---:|---:|---:|---:|
| `.text` | `0x1000` | `0x7D01F0` | `0x400` | `0x7D0200` |
| `.rdata` | `0x7D2000` | `0x18E07C` | `0x7D0600` | `0x18E200` |
| `.data` | `0x961000` | `0x2873D8` | `0x95E800` | `0x22B800` |

ImageBase `0x00400000`；本次 `.text` 的 `raw=VA-0x00400C00`。跨 section 不可直接延用此差值。

## 2. 第 2 輪：參數 / register 生命週期直接驗證（新勘誤）

核心證據（原始 BIN `.text`, raw `0x403B68` 起）：

```asm
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
  804826:	83 fe 02             	cmp    esi,0x2
  804829:	75 0c                	jne    0x804837
  80482b:	ff d7                	call   edi
  80482d:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  804830:	c7 43 54 00 00 00 00 	mov    DWORD PTR [ebx+0x54],0x0
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
```

**新確認（對上一份 T16-73 的修正）：**

1. `0x804768: mov ebx,[ebp+8]` 取 caller 提供的 `inner=outer+0x140`。
2. `0x804823: mov [ebp+8],esi` 此處 `esi=0`，函式內**覆寫了 stack argument slot**；後續 `0x804855: mov ecx,[ebp+8]` 不得再視為原始 inner pointer。該位置隨後可能由迴圈更新；要追完整迴圈才能確立 lane 值域。
3. `0x804858..0x80486D` 的 vtable[0] 消費的是 `ebx` 代表的 inner 實體：`mov edx,[ebx]`; `mov edx,[edx]`; 依序 `push [ebp+8]`, `push [frame+4]`, `push &frame+8`, `push [frame]`; `mov ecx,ebx`; `call edx`。因此只有 ABI 層的 *this* 來源明確，其他四參數的業務語意尚未證實。
4. `0x80487C..0x804886` 另呼叫 vtable `+0x0C`，超出時間門檻 `0x28` 時 `0x80488D..0x8048A1` 呼叫 `+0x08`；這些可能是診斷、監測或次級處理，但不可猜為 Quest accept/ACK。
5. `0x8047B2..0x8047E9` 的 11 DWORD 複製與清零屬 inner 私有狀態的時間／統計處理；與 wire 封包格式尚未建立直接關係。

**堆疊參數修正**：上次把 `push ecx` 稱為 lane 是合理候選、**不是已確認 lane enum**；本次至少證明它讀自已被修改的 `[ebp+8]`，而非固定沿用 caller 原始入參。`[ebp+8]` 後續改寫的作用範圍需完整檢查以釐清實際 lane。

## 3. 第 3 輪：追 `outer+0x140` 建構／vptr writer 的限界搜索

### 已確認的直接 caller

```asm
49196e:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491974:	3b cb                	cmp    ecx,ebx
  491976:	74 07                	je     0x49197f
  491978:	8b 11                	mov    edx,DWORD PTR [ecx]
  49197a:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49197d:	ff d0                	call   eax
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  491996:	75 2f                	jne    0x4919c7
  491998:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
```

- `0x49197F` 讀取 `[esp+0x20]` 至 `edi`；`0x491983 lea ebx,[edi+0x140]`；`0x491989 push ebx`；`0x49198A call 0x804740`。
- 本片段只確認 `outer` 來自**呼叫者的當前 stack 內容**，尚未確認 allocator／outer C++ 類型，也未確認 `outer+0x140` vptr 在何處初始化。

### 靜態位元組篩選的覆蓋界線

在 `.text` raw `0x400..0x7D0600` 內搜尋 little-endian displacement `40 01 00 00`，共得到 **408 個原始位元組命中**。包括各類 `mov`/`lea`、其他類別同偏移、stack size 立即數，以及可能落在非指令邊界的碰巧命中；**這些不是 408 個已驗證的 `outer+0x140` xref，更不是 vptr 寫入數量**。

必須先確認 owner 身份與指令邊界，再從類別建構器/呼叫圖判斷 `[reg+0x140]` 是否為本例 inner vptr。此次沒有任何候選同時滿足「證明 reg=本例 outer」且「寫入合法 vtable 常數」兩條件；**不能把全程搜尋未命中推論為不存在 vtable writer**。可能還有 helper 裡的 `lea inner` 後 `mov [inner],imm` 或基底類初始化、memcpy、constructor inlining，不會被單純 displacement 搜尋涵蓋。

## 4. 資料流、暫定偽碼、證據等級

```cpp
// ABI/flow sketch only; speculative names intentionally avoided.
void periodic_callback(OuterUnknown *p) {
    void *inner = (char*)p + 0x140; // 0x491983
    process_queue_worker(inner);   // 0x49198A
}
void process_queue_worker(void *originalInner) {
    void *thisptr = originalInner; // ebx = [ebp+8] at 0x804768
    // compiler reuses the original stack arg slot as an internal local
    // [ebp+8] = 0 at 0x804823; later contents unknown without complete loop proof
    for (/* internal scheduling not yet proved */) {
        Frame *frame = nullptr;
        if (dequeue_queueB(/* queue */, &frame, /* register parameter */)) {
            auto vt = *(void ***)thisptr;
            vt[0](/* frame[0] */, /* frame+8 */, /* frame+4 */, /* reused stack slot */);
            vt[3](/* further parameters */);
        }
    }
}
```

- **原生已確認：** 函式原始機器碼、`outer+0x140` 傳遞、worker 的 `this=ebx`、回呼 slot `+0/+0x0C/+0x08`、`[ebp+8]` 重用。
- **部分確認：** callback 四個 stack 參數的資料來源與佇列 frame 欄位；未確認它們的網路業務語意及 dynamic class。
- **unknown：** 實際 vtable 常數、method target、Quest opcode、Quest16/15 producer/consumer、回覆欄位、NPC UI 結果、官方 Server 決策。

## 5. 玩家情境 × Client↔Server 矩陣

| 玩家情境 | Client gate | C→S | S→C | Client 寫入/UI | 待開發 Server |
|---|---|---|---|---|---|
| Lua `RequestStartScenario(id)` | 前段已證 `[FBA798]==0` | 前段 4-byte 本地 message `40 00 lo hi`，通往發送網路 API 的靜態可能鏈；wire opcode 未核實 | unknown | unknown | 依實際 Client 協定提供回應，具體格式未知 |
| 教學完成、Quest16 更新 | unknown | unknown | 通用 Queue B → callback slot `+0` 已證；Quest handler unknown | unknown | 完成／拒絕通知待從 Client 反推 |
| Quest15 開放 | unknown | unknown | 相關 opcode unknown | NPC/UI writer unknown | 條件及下發格式待確認 |
| 點 NPC 接下一任務 | unknown | Quest accept builder/opcode unknown | ACK/拒絕 handler unknown | unknown | 依證據設計相容介面 |

## 6. 三輪門檻與停止理由

- **T16-73 第 1 輪：** 已於先前完整原稿確認 `0x49198A` direct caller 與 `outer+0x140`。
- **T16-73-2 第 2 輪（本次）：** 明確證明 `[ebp+8]` 在 worker 內被覆寫，修正 callback 的寄存器／參數註解；這是有效勘誤，但**不足以宣稱 Quest 業務鏈有重大進展**。
- **T16-73-3 第 3 輪（本次）：** 於 `.text` 搜尋 `+0x140` displacement 及檢驗 caller 附近；尚無可證明的 vtable writer／callback target。**三輪未達重大發現門檻**，依 `02` 可結束正式 T16-73 並於下一正式段 T16-74 改採其他入口（例如 NPC 接取 producer、Quest S→C 狀態 writer），不宜再無限反覆猜測同一指標。

## 7. 下一正式段 T16-74 的可交付阻塞清單

1. 在 `0x49197F` 上游定位 `[esp+0x20]` 賦值及 outer object 的初始化／動態型別；建立帶 BIN 位元組的證據鏈。
2. 從 Quest state/cache writer 或 NPC accept UI 反向追指定業務 C→S/S→C message；從這些已知 semantic entry 回接 Queue B callback，避免盲掃大量同偏移欄位。
3. 若取得具體 constructor/subobject vptr 的第一手 writer，驗證有效 vtable 常數與 `+0/+8/+0x0C` method targets；對照 T02 封包層，但不得修改 T02。
4. `Event/TutorialBase.lua` 與 `Table/QuestInfo.xml` 有助 mapping，但不是 network handler 研究前提。

## 8. GitHub

此文件為本地完整補充原稿，**未在本次要求 Commit／Push**；本次不修改 repo；前一輪已提交的 T16-69～73 仍保持原貌。