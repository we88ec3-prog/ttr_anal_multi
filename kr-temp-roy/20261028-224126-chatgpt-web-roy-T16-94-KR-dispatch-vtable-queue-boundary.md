# T16-94 — KR 0xFBA854 vtable 實體、0x00010049 條件性本地出站佇列（BIN-first）

研究者 `chatgpt-web roy`；2026-10-28 Asia/Taipei。此檔是本輪完整證據原稿；本次使用者授權提交 T16-93 與 T16-94，**只可推 t16/roy/chatgpt-web**。

## 0. Git 同步

GitHub `main` 於啟動時 HEAD `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355`，T16 分支 `20aec864564996c14462cc968a5b36e0bfbb1199`，落後 4 commits。真正雙 parent merge commit `23dcab55d4ef30cd54dd7b77a2c1f2bdbd9b59be` 建立並更新 T16 分支；compare `main...t16/roy/chatgpt-web` 顯示 `behind_by=0`, `ahead_by=2`, merge base 即 main HEAD。同步後才研究。未改 main。

## 1. 原始來源與方法

- 原始 `/mnt/data/Tartaros.bin`，size 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `/mnt/data/Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 只使用 KR 原始 BIN x86 靜態反組譯 `objdump -D -b binary -m i386 -M intel --adjust-vma=<VA>`；反組譯前從 raw `VA-0x00400C00` 直接抽取 bytes。`.rdata` raw=`VA-0x00401A00`。沒有執行／修改／上傳原始遊戲程式。
- 先核對 T16-93 上一段 `0x596FBA` virtual call；本段不把 local 4-byte `0x00010049` 推定成 wire Quest opcode；未取得 Server / runtime 封包捕獲。

## 2. 第一輪 T16-94：global owner 建構與虛擬函式的具體 target（重大新發現）

### 2.1 `[0x00FBA854]` 的直接實際 writer

`0x8046D7` 分配 `0x5C` bytes，`0x8046F2` 呼叫 `0x803D60` 建構，`0x8046F7` 明確設定 `[ESI]=0x00C51748`；`0x80470F` 將 ECX 物件存入 `[0x00FBA854]`，隨後呼叫其 vtable+8。此資料流能交叉驗證 local producer 使用的是某具體多型物件實例而非假設類別。*只聲稱此已證路徑，不聲稱所有可能 runtime 替換情境皆固定此 vtable。*

`.rdata` vtable 指標於 `0x00C51748`：

| slot | `.rdata` VA/raw | 原生 little-endian target | 判定 |
|---|---|---|---|
| +0x00 | 0x00C51748 / 0x0084FD48 | 0x00806670 | 可能是生命週期 method，尚未語意全驗 |
| +0x08 | 0x00C51750 / 0x0084FD50 | 0x00806850 | 初始化相關 virtual call |
| **+0x10** | **0x00C51758 / 0x0084FD58** | **0x008069A0** | **此次已定位的原生 virtual target** |
| +0x14 | 0x00C5175C / 0x0084FD5C | 0x00806A00 | 非本段主題 |

### 2.2 `0x596FBA` → `0x8069A0` 條件與資料引數

原 caller 只在 `[ESI+5]!=0` 且 `[0xFBA798]==0` 時，建立 DWORD `0x00010049`；依序 `push 4`、`push &local`、`push 0`，經 `[0xFBA854]` vtable+0x10 呼叫。對 target `0x8069A0`：`arg0=[ebp+8]=0`、`arg1=[ebp+0xC]=&DWORD`、`arg2=[ebp+0x10]=4`； target 使用 arg0 對 `this+0x18` 執行 `0x8438C0` lookup，與 `[this+0x1C]` sentinel 比較，查找成功且 `[node+0x10] != 0` 才繼續；否則返回 0。若 arg2=0 返回 1 而未轉給 0x8060D0；本 caller arg2=4，故可走 `0x8060D0`，不等於每次均保證成功入列。

**首要結論：** `0x8069E6 → 0x8060D0` 使用 `push length` 再 `push bytesPtr`；與 caller 的 4 bytes 一致。這是已確認的原生**訊息本地隊列**入口，不是孤立的 vtable 猜測。

## 3. 第二輪 T16-94-2：下游 buffer/queue 與鎖/旗標的實證

`0x8060D0` 先以 `[ESI+0xA0A4] > 0x12C` 作 gate，若大於則返回 0。呼叫 `0x807470` 取得資料節點；當 `len <= 0x1000` 時，通過 `0x89DBD0` 將指定指標的 `len` bytes 複製到 `node+8`，再寫入 `node+4=len`。接著 `push node; call 0x806060`。

`0x806060` 在已見 `ESI` owner 下對 `[ESI+0xA0D4]` 做同步原語呼叫，然後 `0x74D700` 修改 `[ESI+0xA074]` 指向的 linked queue、遞增 `[ESI+0xA078]`，釋放同步原語，並使 `[ESI+0xA024]=1`，回傳 1。這是**原生編碼資料進入 Client 內部佇列並設待處理旗標**的實質功能鏈進展。同步呼叫的 Win32 API 實名和 queue 消費者尚待 IAT/下游核實，不能因此說已送到 socket。

對原先 `0x00010049`，在成功通過 lookup 和 size gate 時，queue node 的 `+4` 代表 `4`、`+8..+0xB` 保留四個 little-endian bytes `49 00 01 00`。這是佇列中的原生內存內容，**尚未證實 wire framing byte order**。

## 4. 第三輪門檻與未證事項

- `T16-94` 第一輪確認 0xFBA854 具體物件 vtable、實際 +0x10 target，屬前段未知的重大新 native target。
- `T16-94-2` 第二輪深入到資料複製、佇列節點、同步、待處理 flag，更構成明確有界的 producer→queue 鏈。
- `T16-94-3` **未啟動**：前兩輪已達共用規範的重大原生新發現門檻，非必須機械式補跑第三輪。

**仍待證明**：`0x806060` queue 的取出 consumer→encryption/framing→socket、`0x00010049` 是否進入真正 wire、Quest 相關 UI 事件是否為實際任務接取、S→C Quest 回覆 handler、動態 Quest cache writer、Quest16→Quest15 轉移。不得把已證 queue 當作 Socket send，更不得把舊 fixture 編號當成原版協定。

## 5. 玩家情境 × C→S/S→C 證據矩陣

| 玩家情境 | Client 本地條件 | C→S | S→C | Client 可見/內部效果 | Server / 未解 |
|---|---|---|---|---|---|
| 上一段 Quest 靜態 key 成功分支 | `0x5B6C86 → 0x636520 → 0x596E00 → 0x596EC0` | 候選 local `0x00010049`，wire unknown | unknown | 只在 flag gate 通過才觸發 +0x10 | 此操作是否為 Quest accept 未確認 |
| 4-byte local message 派送 | `[ESI+5]!=0`、`[FBA798]==0`、map lookup成功、size gate可通過 | **`49 00 01 00` 可寫入內部佇列**；wire opcode/實際 socket unknown | unknown | `node+4=4`、`node+8=bytes`、queue 插入、pending flag `+0xA024=1` | 待追 queue consumer→socket |
| NPC 接取／交付 | 尚未定位真實 UI gate | unknown | unknown | state writer unknown | 相容 Server 按實際封包補開發 |
| Quest16→Quest15 | 靜態 XML reader 已知 | unknown | unknown | NPC 可接下一任務仍 unknown | 原版 Server 規則不推測 |

## 6. 偽碼（只表示已核原生範圍）

```cpp
// names are analytical placeholders, not original C++ symbols
int VirtualSlot10(Dispatcher* self, int key, const void* data, unsigned len) {
  auto node = lookup(self->tree_at_18, key); // native 0x8438C0
  if (node == self->sentinel_at_1C || node->field_10 == 0) return 0;
  if (!len) return 1;
  return enqueue_buffer(self, data, len); // native 0x8060D0
}
int enqueue_buffer(Dispatcher* self, const void* bytes, unsigned len) {
  if (self->field_A0A4 > 300) return 0;
  auto item = acquire_node();
  if (len <= 4096) { copy(item + 8, bytes, len); item->length_at_4 = len; }
  return append_queue_and_mark_pending(self, item); // 0x806060
}
```

Note: `0x8060D0` still enqueues node when `len > 0x1000`; data copy is conditioned. Do not present pseudocode as proven memory-safe or complete error handling.

## 7. 後續 T16-95

1. `0x806060` 修改的 `[owner+0xA074]` queue：追 `0x8061A0` 及其 users → encoding/framing/socket；實際 outgoing bytes/length/opcode domain 原生核定。
2. `0x8438C0` 查找 key `0` 的 tree writer，確認是否可能在正常路徑命中，與初始化 vtable 的替代型別分支。
3. Quest S→C dispatcher→writer→UI，及 Quest16→Quest15 真正 Quest accept C→S。跨 T02 只引用不覆寫。

## 8. 原始 BIN 組語附錄（逐段真實 dump）

### Global owner setup — VA 0x8046c7…0x804737, raw 0x403ac7…0x403b37

```asm


008046c7 <.data>:
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
  804727:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80472a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804731:	59                   	pop    ecx
  804732:	5e                   	pop    esi
  804733:	8b e5                	mov    esp,ebp
  804735:	5d                   	pop    ebp
  804736:	c3                   	ret

```

### Conditional caller — VA 0x596f7c…0x596fc4, raw 0x19637c…0x1963c4

```asm


00596f7c <.data>:
  596f7c:	80 7e 05 00          	cmp    BYTE PTR [esi+0x5],0x0
  596f80:	74 42                	je     0x596fc4
  596f82:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  596f89:	75 14                	jne    0x596f9f
  596f8b:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  596f92:	68 10 cf bc 00       	push   0xbccf10
  596f97:	e8 7e b3 2f 00       	call   0x89231a
  596f9c:	83 c4 04             	add    esp,0x4
  596f9f:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  596fa6:	c7 45 08 49 00 01 00 	mov    DWORD PTR [ebp+0x8],0x10049
  596fad:	75 15                	jne    0x596fc4
  596faf:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  596fb5:	8b 11                	mov    edx,DWORD PTR [ecx]
  596fb7:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  596fba:	6a 04                	push   0x4
  596fbc:	8d 45 08             	lea    eax,[ebp+0x8]
  596fbf:	50                   	push   eax
  596fc0:	6a 00                	push   0x0
  596fc2:	ff d2                	call   edx

```

### Vtable target — VA 0x8069a0…0x8069f6, raw 0x405da0…0x405df6

```asm


008069a0 <.data>:
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

### Queue entry — VA 0x8060d0…0x806191, raw 0x4054d0…0x405591

```asm


008060d0 <.data>:
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
  80618e:	c2 08 00             	ret    0x8

```

### Enqueue / notification — VA 0x806060…0x8060ce, raw 0x405460…0x4054ce

```asm


00806060 <.data>:
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806071:	8b be 74 a0 00 00    	mov    edi,DWORD PTR [esi+0xa074]
  806077:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  80607a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  80607d:	51                   	push   ecx
  80607e:	52                   	push   edx
  80607f:	57                   	push   edi
  806080:	e8 7b 76 f4 ff       	call   0x74d700
  806085:	8b 8e 78 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa078]
  80608b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  806090:	2b d1                	sub    edx,ecx
  806092:	83 fa 01             	cmp    edx,0x1
  806095:	73 0a                	jae    0x8060a1
  806097:	68 34 20 bf 00       	push   0xbf2034
  80609c:	e8 8f 7a 07 00       	call   0x87db30
  8060a1:	41                   	inc    ecx
  8060a2:	89 8e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ecx
  8060a8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  8060ab:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8060ae:	89 01                	mov    DWORD PTR [ecx],eax
  8060b0:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8060b6:	52                   	push   edx
  8060b7:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8060bd:	c6 86 24 a0 00 00 01 	mov    BYTE PTR [esi+0xa024],0x1
  8060c4:	b8 01 00 00 00       	mov    eax,0x1
  8060c9:	5f                   	pop    edi
  8060ca:	5d                   	pop    ebp
  8060cb:	c2 04 00             	ret    0x4

```

### Global teardown — VA 0x8045da…0x804607, raw 0x4039da…0x403a07

```asm


008045da <.data>:
  8045da:	33 db                	xor    ebx,ebx
  8045dc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8045e2:	3b cb                	cmp    ecx,ebx
  8045e4:	74 0e                	je     0x8045f4
  8045e6:	8b 11                	mov    edx,DWORD PTR [ecx]
  8045e8:	8b 02                	mov    eax,DWORD PTR [edx]
  8045ea:	6a 01                	push   0x1
  8045ec:	ff d0                	call   eax
  8045ee:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
  8045f4:	8b 86 a8 00 00 00    	mov    eax,DWORD PTR [esi+0xa8]
  8045fa:	3b c3                	cmp    eax,ebx
  8045fc:	74 09                	je     0x804607
  8045fe:	50                   	push   eax
  8045ff:	e8 08 cc 08 00       	call   0x89120c
  804604:	83 c4 04             	add    esp,0x4

```