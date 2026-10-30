# T16-95 — KR outgoing queue drain、兩模式 frame writer、尚未閉合的 socket 邊界（BIN-first）

研究者：chatgpt-web roy；生成時間：20261028-224525 Asia/Taipei。原始主程式唯讀，未執行、附加、修改或上傳原始 EXE/BIN。

## 0. Git 協作與證據身份

- Repository `we88ec3-prog/ttr_anal_multi`；目標分支 `t16/roy/chatgpt-web`。開工前 GitHub compare `main...t16/roy/chatgpt-web`：`ahead_by=4`, `behind_by=0`，main base `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355`，本次不須新增 Merge Commit。上一段 T16-94 已提交。
- `Tartaros.bin`: 12,472,320 bytes; SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `.text` VA `0x401000`, raw `0x400`；raw = VA - `0x400C00`。以下每段以原始 BIN 的 `objdump -D -Mintel` 指令核驗；xref 為原始 `.text` E8 rel32 候選，使用 objdump 核實具體 caller。
- 本段只對 KR 本地 queue、frame/serialization 證明到達的位置作原生斷言。原版 Server decision、Quest wire opcode、socket 實際 send、Quest16→Quest15 皆尚未證實。

## 1. 第一輪 T16-95：由前段 queue 找到真正 drain 消費者（重大新進展）

T16-94 已確認 `0x596FBA → vtable[+0x10]=0x8069A0 → 0x8060D0 → 0x806060`：成功時複製 4-byte `49 00 01 00` 入 node，插入 owner 的 `[+0xA074]` linked queue，`[+0xA078]` count+1、`[+0xA024]=1`。本段不重算前段既有 producer，而以相同 queue offset 從消費端反證其生命週期。

### 1.1 `0x8061A0` queue drain：首次定位 caller 與成功／拒絕門檻

- `0x8061CB` 由函式參數 `[EBP+8]` 得到 owner，`[owner+0xA0D4]` 保護同步。
- `0x8061E6` 取得 `[owner+0xA074]` 鏈表 sentinel；`0x8061EC` 讀 sentinel.next 到 EBX；相等時無資料，跳到 `0x8063BA` 釋放同步並返回。
- 有節點時 `[EBX+8]` 指向 payload node EDI，`[EDI+4]` 取資料長度，`EDI+8` 取 bytes 地址。和 T16-94 的資料寫入 offset `[node+4]` / `[node+8]` 同構，**確認 drain 消費剛入列的類型**。
- `0x806202` 讀 `[owner+0xA02C]` 模式：零走 `0x807A70`，非零先走 `0x807830`（成功時 `0x80624F`），未成功則 fallback `0x807A70`。這兩者都是封裝 writer，不能直接叫 socket。
- writer 成功則 `0x80624F…0x806275` 解除 linked node、呼叫 `0x89120C` 釋放 linked node，對 `[owner+0xA078]` **count--**；因此 T16-94 count++ 有成對 consumer。
- `0x8062B9` 開始清 payload 物件前兩個 DWORD，`0x8062C6…0x80635D` 將資料指標存入另一個全域環狀/分塊暫存佇列（`[0xFE3368]` 等），後續消費/生命週期仍待查；不把這段誤稱 socket。
- `0x8063A4` 檢查 `[owner+0xA0B4]==1` 與本輪有效處理旗標，決定本次 return；無法由本段證明網路端的送達保證。

### 1.2 Drain 的已確認上游排程

透過 `.text` 中 E8 rel32 target scan，`0x8061A0` 直接呼叫候選兩處，實際 objdump 指令邊界均成立：

| call site VA | raw | 原始呼叫上下文 | 結果欄位 |
|---|---|---|---|
| `0x804AD6` | `0x403ED6` | 從活躍連線/通道向量取 ESI；`[ESI+0xA0AC]!=0` 才 push ESI call drain | 成功增加 `[ESI+0xA094]` 並降低 `[ESI+0xA0A4]`，無結果分支可增加 retry-related 欄位 |
| `0x805228` | `0x404628` | 另一個迴圈同樣在 `[ESI+0xA0AC]!=0` 下呼叫 | 相同類型的 success/failure accounting |

這裡的「通道」、「排程」是**結構用途的暫名**。尚未確定是哪個 thread/callback、也未確定其中一條一定屬 Quest 業務。

### 1.3 第一輪找到 frame serialization（新原生證據）

`0x807A70` 在 `0x807A8A` 建立 word `0x1A68`，`0x807A93` 寫入 DWORD/word 長度相關值；`EBX=len+4`，需 `len !=0`、`len+4 <= 0x1000`，buffer accumulated + payload <= `0x4000`。成功時 `0x807AE9` 把 payload length 放進 write cursor，`0x807AF2` 呼叫 `0x89DBD0` 複製 bytes，並更新 `[EDI+0x500C]` pending size、`[ESI]` cursor。由於 `0x1A68` 的組裝落在 local stack 且沒有在這段完整證明被寫入 buffer，**不可直接宣稱其為 wire opcode**；更準確是 frame writer 內部常數或標記。

`0x807830` 是另一種模式 writer，起始具 payload+6 gate、`0x1000`/`0x4000` 容量界線，在 `0x8078FD` 起使用 `xor 0xB6` 的位元組轉換，後續長路徑須核對其輸出長度與校驗。不能將 xor B6 單獨叫完整網路加密。

## 2. 第二輪 T16-95-2：返回值、邊界與外圍線索

- `0x8061A0` 選用兩個 writer 皆有明確 return status；若 `0x807A70` 失敗，跳 `0x8063A4`，不做 Linked node remove/count--。故無法把 queue 入列等同 frame 已寫成，frame 成功也尚不能等同 socket sent。
- `0x8063E0` 為另一個與同一 queue 相關的 drain/搬運路徑，原始 E8 候選 xrefs 多處（`0x495839`, `0x804B61`, `0x804BB9`, `0x8052B3`, `0x805313`, `0x805FDA`, `0x806021`）。它從 `[owner+0xA074]` 摘第一節點，把 `[node+8]` 的資料指標轉存至全域 `[0xFE33xx]` 一組容器；**與 `0x8061A0` 的 framed writer 分流不同**，不可誤將它視為 queue 的唯一 consumer。
- 反證邊界：兩條 drain 都不是 `send/WSASend` 呼叫所在的直接指令，`0x807A70` 只寫內存 buffer。`WS2_32.dll` import table 有 `WSASend`，但其存在不等於本鏈已到達該 import。需後續從 `[owner+0x5004] / [+0x500C]` 的 flush / sender xref 追到 socket output，再比對 wire 位元組與 Quest request source。
- `0x00010049` 的前段 4-byte 並非自帶完整 frame。本段可以從 caller 到 writer 建立**條件可達路徑**，而非保證發送、封包與 Quest 之間等同。沒有 S→C 的 Quest accept/complete handler 或動態 writer 新閉環證據。

## 3. 三輪規則決策

T16-95 第一輪已新確認以前未知的「enqueue → 同一 linked queue drain → 按模式 frame writer → 另一暫存隊列」實際生產/消費鏈，明確 xref 與反向 count 配對；屬具可回溯原生證據的重大功能鏈進展。為增加嚴謹性又執行第二輪的錯誤/分流與呼叫者核對。`T16-95-3` **未啟動**：已於第一／第二輪達重大進展門檻，非假裝完成第三輪。

## 4. 玩家情境與 C→S/S→C 證據矩陣

| 玩家情境 | Client local gate | C→S | S→C | Client 效果 | 相容 Server/未解 |
|---|---|---|---|---|---|
| 特定 NPC/Quest 候選互動 | T16-93 `[ESI+5]!=0`、`[FBA798]==0` 下產生 `49 00 01 00` | 已確證入本地佇列，並**有條件地**交 frame writer；wire opcode/packet bytes/發送時機仍 unknown | unknown | 本地 consumer/control state 更新已有前段證據 | 不能設定官方 Quest accept 封包 |
| 隊列由排程處理 | `[ESI+0xA0AC] !=0` 且 linked queue 非空 | `0x8061A0` 分模式封裝；下游 socket 尚 unknown | unknown | queue 成功 remove/count--；pending buffer size++ | flush / socket xref 必追 |
| Quest16 完成→Quest15 可接 | unknown | unknown | unknown | unknown | 原版 Server 內部規則未知；須定位實際 Client handler |
| NPC 接取／交付及確認／拒絕 | XML 靜態 consumer 已證，動態 gate unknown | unknown | unknown | unknown | 先找 S→C packet handler，不用本地 XML key 猜協定 |

## 5. C++-like bounded pseudocode

```cpp
bool drain_one_or_more(Channel* ch) { // 0x8061A0, simplified, unverified types
  lock(ch->lockA0D4);
  for (auto* link = ch->queueA074->next; link != ch->queueA074;) {
    auto* data = link->payloadAt8;
    bool ok = false;
    if (ch->modeA02C != 0) ok = mode_writer_807830(ch->frameAt501c, data->bytesAt8, data->lengthAt4);
    if (!ok) ok = append_writer_807A70(ch->frameAt501c, data->bytesAt8, data->lengthAt4);
    if (!ok) break;
    unlink_free_link(link);
    --ch->queuedCountA078;
    transfer_payload_to_other_container(data);  // destination FE3368 family
    link = next;
  }
  unlock(ch->lockA0D4);
  return local_status;
}
```

上述偽碼不等同可編譯原版還原；`mode` 分支與 fallback、資料容器/長度、責任已核，錯誤處理與 payload 所有權應回到附錄指令核對。

## 6. 後續 T16-96

1. 由 `[owner+0x5004]`、`[owner+0x500C]` frame buffer cursor/size 的 writer、consumer xref，追到 WSASend/socket 直接呼叫，建立 frame boundary→wire bytes；留意 `0x807A70` 表面 `0x1A68` 的實際輸出語意。
2. 精查 `0x8063E0` 全域 `[0xFE3368]` consumer、`0x807830` 完整轉換/成功條件，區分不同 outgoing modes。
3. 回到 NPC/Quest native producer，核對是否確實選中該通信通道；由原生 S→C handler 的分派域追 Quest status writer／UI 消費；明示 no original Server evidence。

## 7. BIN 原始組語附錄（地址、bytes 和 CFG）

每段出自校驗後 BIN，`raw` 根據 `.text` 段映射（VA−`0x400C00`）；周邊非指令邊界的 objdump 解讀不作肯定主張。

### producer queue insertion — VA `0x806060–0x8060CC`, raw `0x405460–0x4054CC`

```asm
00806060 <.text+0x405060>:
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
  8060cb:	c2               	ret    0x4
```

### queue drain and frame dispatch — VA `0x8061A0–0x80627D`, raw `0x4055A0–0x40567D`

```asm
008061a0 <.text+0x4051a0>:
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  80627b:	f6 05      	test   BYTE PTR ds:0xfe3354,0x1
```

### drain completion / transfer — VA `0x8062AD–0x8063DC`, raw `0x4056AD–0x4057DC`

```asm
008062ad <.text+0x4052ad>:
  8062ad:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  8062b2:	50                   	push   eax
  8062b3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8062b9:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  8062bf:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  8062c6:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  8062cb:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  8062d1:	03 c8                	add    ecx,eax
  8062d3:	f6 c1 03             	test   cl,0x3
  8062d6:	75 18                	jne    0x8062f0
  8062d8:	83 c0 04             	add    eax,0x4
  8062db:	c1 e8 02             	shr    eax,0x2
  8062de:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  8062e4:	77 0a                	ja     0x8062f0
  8062e6:	68 64 33 fe 00       	push   0xfe3364
  8062eb:	e8 80 0c e3 ff       	call   0x636f70
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
  80637f:	50                   	push   eax
  806380:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806383:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  80638a:	e8 1a ad 08 00       	call   0x8910a9
  80638f:	68 a8 57 c8 00       	push   0xc857a8
  806394:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806397:	51                   	push   ecx
  806398:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  80639f:	e8 4c 66 09 00       	call   0x89c9f0
  8063a4:	83 be b4 a0 00 00 01 	cmp    DWORD PTR [esi+0xa0b4],0x1
  8063ab:	75 0d                	jne    0x8063ba
  8063ad:	83 7d e8 00          	cmp    DWORD PTR [ebp-0x18],0x0
  8063b1:	75 07                	jne    0x8063ba
  8063b3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  8063ba:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8063c0:	52                   	push   edx
  8063c1:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8063c7:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  8063ca:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8063cd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  8063d4:	59                   	pop    ecx
  8063d5:	5f                   	pop    edi
  8063d6:	5e                   	pop    esi
  8063d7:	5b                   	pop    ebx
  8063d8:	8b e5                	mov    esp,ebp
  8063da:	5d                   	pop    ebp
  8063db:	c2               	ret    0x4
```

### second drain — VA `0x8063E0–0x80652A`, raw `0x4057E0–0x40592A`

```asm
008063e0 <.text+0x4053e0>:
  8063e0:	55                   	push   ebp
  8063e1:	8b ec                	mov    ebp,esp
  8063e3:	6a ff                	push   0xffffffff
  8063e5:	68 fe 98 90 00       	push   0x9098fe
  8063ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8063f0:	50                   	push   eax
  8063f1:	83 ec 18             	sub    esp,0x18
  8063f4:	53                   	push   ebx
  8063f5:	56                   	push   esi
  8063f6:	57                   	push   edi
  8063f7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8063fc:	33 c5                	xor    eax,ebp
  8063fe:	50                   	push   eax
  8063ff:	8d 45 f4             	lea    eax,[ebp-0xc]
  806402:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  806408:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  80640b:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806411:	50                   	push   eax
  806412:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806418:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  80641e:	8b 18                	mov    ebx,DWORD PTR [eax]
  806420:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  806423:	3b d8                	cmp    ebx,eax
  806425:	0f 84 fe 00 00 00    	je     0x806529
  80642b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806432:	75 27                	jne    0x80645b
  806434:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80643b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806442:	e8 d9 0c 00 00       	call   0x807120
  806447:	68 90 0b bd 00       	push   0xbd0b90
  80644c:	e8 c9 be 08 00       	call   0x89231a
  806451:	83 c4 04             	add    esp,0x4
  806454:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80645b:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806460:	8b 73 08             	mov    esi,DWORD PTR [ebx+0x8]
  806463:	50                   	push   eax
  806464:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  806467:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80646d:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  806473:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  80647a:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  80647f:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  806485:	03 c8                	add    ecx,eax
  806487:	f6 c1 03             	test   cl,0x3
  80648a:	75 18                	jne    0x8064a4
  80648c:	83 c0 04             	add    eax,0x4
  80648f:	c1 e8 02             	shr    eax,0x2
  806492:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  806498:	77 0a                	ja     0x8064a4
  80649a:	68 64 33 fe 00       	push   0xfe3364
  80649f:	e8 cc 0a e3 ff       	call   0x636f70
  8064a4:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8064aa:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8064b0:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  8064b5:	8b f7                	mov    esi,edi
  8064b7:	c1 ee 02             	shr    esi,0x2
  8064ba:	3b c6                	cmp    eax,esi
  8064bc:	77 02                	ja     0x8064c0
  8064be:	2b f0                	sub    esi,eax
  8064c0:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  8064c6:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  8064ca:	75 1b                	jne    0x8064e7
  8064cc:	6a 10                	push   0x10
  8064ce:	e8 95 ad 08 00       	call   0x891268
  8064d3:	83 c4 04             	add    esp,0x4
  8064d6:	85 c0                	test   eax,eax
  8064d8:	0f 84 a8 00 00 00    	je     0x806586
  8064de:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  8064e4:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  8064e7:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  8064ec:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  8064ef:	83 e7 03             	and    edi,0x3
  8064f2:	8d 04 b9             	lea    eax,[ecx+edi*4]
  8064f5:	85 c0                	test   eax,eax
  8064f7:	74 05                	je     0x8064fe
  8064f9:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  8064fc:	89 10                	mov    DWORD PTR [eax],edx
  8064fe:	b8 01 00 00 00       	mov    eax,0x1
  806503:	01 05 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,eax
  806509:	29 05 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,eax
  80650f:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  806514:	50                   	push   eax
  806515:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80651b:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  80651d:	3b 5d ec             	cmp    ebx,DWORD PTR [ebp-0x14]
  806520:	0f 85 05 ff ff ff    	jne    0x80642b
  806526:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806529:	8b         	mov    ecx,DWORD PTR [esi+0xa074]
```

### first upstream periodic caller — VA `0x804AC0–0x804B1A`, raw `0x403EC0–0x403F1A`

```asm
00804ac0 <.text+0x403ac0>:
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
```

### second upstream caller — VA `0x805210–0x805270`, raw `0x404610–0x404670`

```asm
00805210 <.text+0x404210>:
  805210:	eb 03                	jmp    0x805215
  805212:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805215:	8b 09                	mov    ecx,DWORD PTR [ecx]
  805217:	8b 34 b9             	mov    esi,DWORD PTR [ecx+edi*4]
  80521a:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  805221:	0f 84 85 01 00 00    	je     0x8053ac
  805227:	56                   	push   esi
  805228:	e8 73 0f 00 00       	call   0x8061a0
  80522d:	85 c0                	test   eax,eax
  80522f:	74 28                	je     0x805259
  805231:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  805237:	ff 86 94 a0 00 00    	inc    DWORD PTR [esi+0xa094]
  80523d:	83 f8 05             	cmp    eax,0x5
  805240:	73 0c                	jae    0x80524e
  805242:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  805249:	00 00 00 
  80524c:	eb 1e                	jmp    0x80526c
  80524e:	83 c0 fb             	add    eax,0xfffffffb
  805251:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  805257:	eb 13                	jmp    0x80526c
  805259:	80 7b 10 00          	cmp    BYTE PTR [ebx+0x10],0x0
  80525d:	74 0d                	je     0x80526c
  80525f:	ff 86 84 a0 00 00    	inc    DWORD PTR [esi+0xa084]
  805265:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  80526c:	c7 45 f4 00    	mov    DWORD PTR [ebp-0xc],0x0
```

### frame writer default — VA `0x807A70–0x807B3E`, raw `0x406E70–0x406F3E`

```asm
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
  807b3b:	c2 08 00             	ret    0x8
```

### frame writer alternate mode — VA `0x807830–0x807923`, raw `0x406C30–0x406D23`

```asm
00807830 <.text+0x406830>:
  807830:	55                   	push   ebp
  807831:	8b ec                	mov    ebp,esp
  807833:	b8 38 10 00 00       	mov    eax,0x1038
  807838:	e8 33 8e 0a 00       	call   0x8b0670
  80783d:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807842:	33 c5                	xor    eax,ebp
  807844:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  807847:	53                   	push   ebx
  807848:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80784b:	56                   	push   esi
  80784c:	8b f1                	mov    esi,ecx
  80784e:	8b 06                	mov    eax,DWORD PTR [esi]
  807850:	57                   	push   edi
  807851:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  807854:	50                   	push   eax
  807855:	89 b5 cc ef ff ff    	mov    DWORD PTR [ebp-0x1034],esi
  80785b:	89 9d d4 ef ff ff    	mov    DWORD PTR [ebp-0x102c],ebx
  807861:	89 85 f0 ef ff ff    	mov    DWORD PTR [ebp-0x1010],eax
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
  8078ef:	33 c0                	xor    eax,eax
  8078f1:	89 85 ec ef ff ff    	mov    DWORD PTR [ebp-0x1014],eax
  8078f7:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078fd:	8a 03                	mov    al,BYTE PTR [ebx]
  8078ff:	8a d0                	mov    dl,al
  807901:	80 f2 b6             	xor    dl,0xb6
  807904:	88 95 fc ef ff ff    	mov    BYTE PTR [ebp-0x1004],dl
  80790a:	0f b6 d0             	movzx  edx,al
  80790d:	b8 01 00 00 00       	mov    eax,0x1
  807912:	89 95 f8 ef ff ff    	mov    DWORD PTR [ebp-0x1008],edx
  807918:	3b f8                	cmp    edi,eax
  80791a:	0f 86 c9 00 00 00    	jbe    0x8079e9
  807920:	8d 57 ff             	lea    edx,[edi-0x1]
```