# E54 — RR-0005／KR T02：選服首個送出嘗試、全域 send pump、framing/dispatch、失敗 slot／Conn 所有權（持續目標導向 BIN-first）

- **正式段號**：E54；E54.1～E54.20 為一份原稿的連續研究單元，**不是**因某個重大發現而提前停止。
- **原稿產生時間（Asia/Taipei）**：`2026-10-30T04:20:00+08:00`，研究標記 `chatgpt-web roy`。
- **原件**：KR `Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；不執行，不 patch，不附加 process，不生成偽造 pcap。
- **區段**：PE32 i386 `.text` VA `0x401000`、raw `0x400`，raw=VA−`0x400C00`；`.rdata` VA `0xBD2000`、raw `0x7D0600`，raw=VA−`0x401A00`；函式解碼使用該區段的真實 raw slice `/mnt/data/e51-text.bin`，其位元組已和原件比對一致。
- **GitHub 開工檢查（此段）**：`main=eadabf33f31da542db32ddf1d10cabea5a020ea4`，`extra/roy1=8cf7693d26d813aa87d5aed19a90af4b148149dd`；`research/requests/index.json` 中 RR-0005 是 `ACTIVE/CLAIMED`、`claim.actor=chatgpt-web roy`、`claim.branch=extra/roy1`，`submission=null`；T02 README 未有現行 T01 NEEDS_FIX 專節，T02 共用已驗證知識無完整 RR-0005 端到端 FULL-PASS。正式研究上段 E53 只有本地原稿，**尚未上 Git**；E51/E52 已於 `extra/roy1` 存在。此次未授權 Commit/Push，不變更 Git/RR 台帳。
- **研究層級**：`N` 原生 machine code／PE IAT／已知入口基本塊；`C` 具體前提下的 CFG 與功能鏈推導；`U` 未閉合的 writer/caller、runtime 順序、所有權、socket/wire 或需要跨 Task 核對。`Client`、`Manager`、`Conn`、`Pool` 為暫稱；+offset 皆必須附 base。
- **重要停止規則更新**：使用者明確要求**不得以重大新發現為停止點**。本段沿 RR 目標持續串接 S→C 角色清單/UI→C→S 選服 Connect→本地排入→定時 send pump→WSASend→IOCP→frame parser/dispatch→close/retry；本次在 15 單元後繼續擴展上層 handler，最後只有獲取特定 Server 回覆／動態同 session 記錄等需外部一手證據的阻塞才能列作未閉合，並非因本段出現新發現而停止。下一段須持續追查，RR-0005 未達成結案條件。

## 摘要：此次直接證據增加了什麼

**N**：`0x4957C0` 在兩個 Connect 成功後，key0 的 57 bytes 被 `Manager+0x10` method `0x8069A0` 送進 `Conn+sendQueue`，`0x806060` 設 `Conn+A024=1`；定時更新路徑 `0x491FDD→0x804A40` 遍歷 Pool **+0/4 全部配置的 Conn 陣列**，以 `A0AC≠0` lease flag、`A0B8<=0` 與 `A028>0` 等條件決定 `Manager vtable+0x0C` SEND post；後者為 `0x8068B0→WSASend(Conn+A050 OVERLAPPED)`。**這是 send attempt 的有界條件鏈，不是已觀測 first wire**。

**N**：`0x807B40` 對 S2C framing 有 `WORD payloadLength ∈ [1,0x1000]`、第二個 WORD 區分 `0x2633/0x0BBB/0x1A68/0x22D7`，在長度與累積 buffer 上檢查界線後，`0x807E50` 準備上層 payload；`0x807D8F/0x807D9E` 依解碼 packet length 分成 **零長度返回 FE3358 free pool** 的 `0x804310→0x8076F0`、以及 **正長度排入 FC10D0 應用分組佇列**的 `0x489920→0x8040A0`。另證 `0x49198A→0x804740` 逐 lane 出佇列再呼叫動態 handler，這才是上層分派入口；既有 E44/E45 的 `0x4930E0→...→0x4C37A0/0x4C3C10` 提供附條件路徑，仍不代表某次實際 S2C 回覆。

**N**：`0x66C1A7` / `0x66C247` 是兩處由選服 UI 轉入 `0x4957C0` 的 direct callers；`0x4957C0` 除了 `arg=server IPv4` 外，**還依賴進入時的 `ESI=Client-like*`**（該兩個 callers 在 call 前 `mov esi,[FB1318]`）。這使 `BF60/BF64/BF68` 的 base 和 `BF58` 的方法 argument 更能限界，不可把 `BF58` 認定為已證的新 Conn slot。

---

## E54.1 — 重新盤點 RR-0005 驗收目標與 E50–E53 的已知/未證界線

RR 文義需回答：Join T03 0x13 response / choice UI with KR 0x495610/0x4957C0 Connect call sites；derive actual conditions/order、close/retry、slot ownership、initial frame per connection；把 legacy static port constants 與 Server deployment decision 分開。最後驗收涉及正式 S00/T01 workflow，**不是本文自行 DECLARE ACCEPTED**。

沿用但不偷換 E53 有界結論：`0x490FE0` 是 Client subobject `0xC05AA4+0x30` vtable，能從 Pool+28 追蹤移動 leased Conn 到 Pool+48，之後 `0x805B40` 按 `A0B8==0` reset/reuse；`0x805720` 最多預熱 3 個 Conn；Pool+38/+3C/+40 cold init 為零。這不是 OS handle 全域證明，也不表示 source→sink 已完整達 runtime。E51/E52 的 key-map erase 與 Conn teardown 仍非同動作。

新檢查方法：重新從 `.text` 取得 `0x495610` / `0x4957C0` / `0x8069A0` / `0x8060D0` / `0x806060` / `0x804A40` / `0x8061A0` / `0x8068B0` / `0x806CF0` / `0x807B40`，再以 binary `E8 rel32` 候選定位呼叫者；所有候選按真正起點反組譯，虛呼叫只認已知 vtable，不用掃不到 E8 來證明不會執行。

## E54.2 — key1 前置 `0x495610`：舊 key0/key2 shutdown 與 `BF60` 寫入的條件排序

**N**：`0x4956B8` 檢查第三實參是否為零；非零時 `0x4956F2..0x49570B` 分別對 Manager vtable+0x20 以 `key=0` 與 `key=2`、`how=1` 呼叫 shutdown-by-key；若原 Client-like `BF60≠0` 再對 key1 做同類 shutdown，並清零 `BF60`。`0x495743..0x49575B` 在允許條件分支下呼叫 vtable+0x18 Connect，`port=0x20DF, key=1, pipeline=2`；成功 `0x495789` 使用 vtable+0x14 post WSARecv，`0x495794` 寫 `BF60=returned Conn*`。非零 BF60 且第三引數為 0 時可直接 return success，不強制重新連線。

**C/U**：vtable+0x20 已在 E51 辨明只做 socket `shutdown` 而不保證 `closesocket`、map erase 或 Pool release。`0x495763` 失敗支路呼叫 `_?` external import 並返回 0，但不能在此推得完整 retry policy。`BF60` 只可稱 Client 持有的 key1 Conn alias（以本函式和後續成功路徑為前提），不證全域唯一 owner。

**原生證據：** `.text` VA `0x004956B8–0x004957B8`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2               	ret    0xc
```

## E54.3 — UI 選擇向 `0x4957C0` 傳入 host 的兩個直接入口及隱式 ESI

**N**：`0x66C090` 在角色/選項物件的 `+0xF0/+0xF4` 鏈讀候選整數，經 `0x5078C0`、`0x507750` 取出 `EBX/ESI`，在 global `0xF94294`、非零指標分支下 `0x66C1A7 call 0x4957C0`；另一條 case 在 `0x66C233..247` 重入相同 connect routine。

在 `0x66C19B` 與 `0x66C23B` 都先 `call 0x414680`，以 `push esi` 帶入 host 字串/指標，並 `mov esi,[0xFB1318]` 後 `call 0x4957C0`。**因此** caller 明確同時交付 stack host argument 與 hidden register `ESI` Client-like*；不能誤認被覆蓋後的 ESI 仍為先前 choice record。T03 的精確 UI index/角色語意仍由其來源負責，本段只確認 T02 的衝接入口和 CFG guard。

**原生證據：** `.text` VA `0x0066C090–0x0066C1B0`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  66c090:	55                   	push   ebp
  66c091:	8b ec                	mov    ebp,esp
  66c093:	83 e4 f8             	and    esp,0xfffffff8
  66c096:	6a ff                	push   0xffffffff
  66c098:	68 7a 61 94 00       	push   0x94617a
  66c09d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  66c0a3:	50                   	push   eax
  66c0a4:	83 ec 10             	sub    esp,0x10
  66c0a7:	53                   	push   ebx
  66c0a8:	56                   	push   esi
  66c0a9:	57                   	push   edi
  66c0aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  66c0af:	33 c4                	xor    eax,esp
  66c0b1:	50                   	push   eax
  66c0b2:	8d 44 24 20          	lea    eax,[esp+0x20]
  66c0b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  66c0bc:	8b f9                	mov    edi,ecx
  66c0be:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  66c0c1:	8b 81 f0 00 00 00    	mov    eax,DWORD PTR [ecx+0xf0]
  66c0c7:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c0cd:	85 c0                	test   eax,eax
  66c0cf:	74 1c                	je     0x66c0ed
  66c0d1:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c0d7:	85 c0                	test   eax,eax
  66c0d9:	75 09                	jne    0x66c0e4
  66c0db:	83 c8 ff             	or     eax,0xffffffff
  66c0de:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0e2:	eb 11                	jmp    0x66c0f5
  66c0e4:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c0e7:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  66c0eb:	eb 08                	jmp    0x66c0f5
  66c0ed:	c7 44 24 10 ff ff ff 	mov    DWORD PTR [esp+0x10],0xffffffff
  66c0f4:	ff 
  66c0f5:	85 ff                	test   edi,edi
  66c0f7:	75 2b                	jne    0x66c124
  66c0f9:	8b 81 f4 00 00 00    	mov    eax,DWORD PTR [ecx+0xf4]
  66c0ff:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  66c105:	85 c0                	test   eax,eax
  66c107:	74 18                	je     0x66c121
  66c109:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  66c10f:	85 c0                	test   eax,eax
  66c111:	75 07                	jne    0x66c11a
  66c113:	83 c8 ff             	or     eax,0xffffffff
  66c116:	8b f8                	mov    edi,eax
  66c118:	eb 0a                	jmp    0x66c124
  66c11a:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  66c11d:	8b f8                	mov    edi,eax
  66c11f:	eb 03                	jmp    0x66c124
  66c121:	83 cf ff             	or     edi,0xffffffff
  66c124:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  66c128:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  66c12e:	57                   	push   edi
  66c12f:	50                   	push   eax
  66c130:	8b c6                	mov    eax,esi
  66c132:	e8 89 b7 e9 ff       	call   0x5078c0
  66c137:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  66c13b:	57                   	push   edi
  66c13c:	8b d8                	mov    ebx,eax
  66c13e:	51                   	push   ecx
  66c13f:	8b c6                	mov    eax,esi
  66c141:	e8 0a b6 e9 ff       	call   0x507750
  66c146:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  66c14d:	8b f0                	mov    esi,eax
  66c14f:	75 2a                	jne    0x66c17b
  66c151:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  66c158:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  66c15f:	00 
  66c160:	e8 2b 54 e7 ff       	call   0x4e1590
  66c165:	68 80 cc bc 00       	push   0xbccc80
  66c16a:	e8 ab 61 22 00       	call   0x89231a
  66c16f:	83 c4 04             	add    esp,0x4
  66c172:	83 cf ff             	or     edi,0xffffffff
  66c175:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  66c179:	eb 03                	jmp    0x66c17e
  66c17b:	83 cf ff             	or     edi,0xffffffff
  66c17e:	83 3d 94 42 f9 00 00 	cmp    DWORD PTR ds:0xf94294,0x0
  66c185:	0f 84 92 00 00 00    	je     0x66c21d
  66c18b:	85 db                	test   ebx,ebx
  66c18d:	0f 84 8a 00 00 00    	je     0x66c21d
  66c193:	85 f6                	test   esi,esi
  66c195:	0f 84 1e 03 00 00    	je     0x66c4b9
  66c19b:	e8 e0 84 da ff       	call   0x414680
  66c1a0:	56                   	push   esi
  66c1a1:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c1a7:	e8 14 96 e2 ff       	call   0x4957c0
  66c1ac:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  66c1af:	8b         	mov    eax,DWORD PTR [edx+0xf0]
```

**原生證據：** `.text` VA `0x0066C21D–0x0066C25A`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  66c21d:	83 fb 04             	cmp    ebx,0x4
  66c220:	74 52                	je     0x66c274
  66c222:	85 db                	test   ebx,ebx
  66c224:	0f 84 bc 01 00 00    	je     0x66c3e6
  66c22a:	83 fb 05             	cmp    ebx,0x5
  66c22d:	0f 84 bc 01 00 00    	je     0x66c3ef
  66c233:	85 f6                	test   esi,esi
  66c235:	0f 84 7e 02 00 00    	je     0x66c4b9
  66c23b:	e8 40 84 da ff       	call   0x414680
  66c240:	56                   	push   esi
  66c241:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c247:	e8 74 95 e2 ff       	call   0x4957c0
  66c24c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c24f:	8b 80 f0 00 00 00    	mov    eax,DWORD PTR [eax+0xf0]
  66c255:	e8 d6 02 dc ff       	call   0x42c530
```

## E54.4 — `0x4957C0` 先建立兩條 socket，部分成功及兩個失敗支路均不具完整 Conn release

**N**：`0x4957DF..4957EC` 與 `0x4957F2..495805` 同 host 呼叫 vtable+0x18 Connect，第一次 `key=0,port=0x20E0,pipeline=2` 存 `EDI`，第二次 `key=2,port=0x20DE,pipeline=2` 存 `EBX`。二者都非零才繼續 old BF60 cleanup、`0x39` 本地 queue、兩條 post-recv。第一成功而第二失敗時 `0x49597E..49598D` 對 key0 呼叫 vtable+0x20 shutdown-by-key，記錄/返回 0；第一失敗而第二成功 `0x4959B0..4959D0` 對 key2 shutdown-by-key；兩者失敗則沒有可 shutdown 的成功 key。

此控制流**沒有直接**在失敗分支呼叫 `0x806FC0`，亦沒有在 `0x4957C0` 中明確 `Pool+28` producer 或完整 `A0B8` drain 等待。Manager Connect 若本身失敗可先進 Pool+48（E51/E52），但「另一個成功 Conn 是否真正 close/recycle」不能直接由 vtable+0x20 等同證明。兩個成功時也不能當作 handshake 已完成。

**原生證據：** `.text` VA `0x004957C0–0x00495872`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
```

**原生證據：** `.text` VA `0x0049597E–0x004959E4`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
  4959e0:	8b e5                	mov    esp,ebp
  4959e2:	5d                   	pop    ebp
  4959e3:	c2               	ret    0x4
```

## E54.5 — old `Client+BF60` 由 queue drain / `0x007E` 排入 / A0B0 flag 清除 alias 的確切位置

**N**：兩條新 Conn 均成功才在 `0x495817` 檢查 `Client-like+BF60`。若不為零，依序 `0x495839 call 0x8063E0(oldConn)`、`0x49583E..853` 在 oldConn 的 queue 排入 2 bytes `WORD 0x007E`、`0x49585E mov oldConn+A0B0,1`、`0x495868..86F Client+BF60=0`。前面有 logger callback `0x44D680`，其結果不可冒稱 owner/free 確認。這裡的 `0x8063E0` 依 E52 是 queue drain/全域 buffer pool resource cleanup，不是 `closesocket`。

**C**：`0x007E` 是**本地待送**的 control payload；仍須後續 send pump、socket alive、send buffer encoding、WSASend completion 才能推到實際 socket bytes。設 A0B0 與清 BF60 並不等於 OS close；且沒有保證舊 Conn 仍可接收到對端 ACK。這能避免相容 Server 誤把「已呼叫選服」直接等同舊 session fully disconnected。

**原生證據：** `.text` VA `0x00495817–0x00495872`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
```

## E54.6 — key0 `0x39`=57 bytes 第一次本地排入：欄位寫入位置與資料來源

**N**：`0x49587F..4958B0` 建構 57-byte stack payload，`[EBP-0x40]` 開頭 WORD `0x0001`，`[EBP-0x26]` 另有 WORD 初始化但在 `0x4958F1` 將其低 BYTE 覆寫為 `1`。後續 `0x404BA0` 取得 runtime account-like buffer 來源：`+0x67E0` DWORD、`+0x67E4` 10 bytes、`+0x67FA` 10 bytes、`+0x6898` 1 byte、`+0x6899` 5 bytes、`+0x68A0` DWORD；兩個 memcpy-like helper `0x893FFE` 依指令有 `push 0xA` 長度，另 `0x893B59` 有 `push 5`。`0x495935..93D` 呼叫 `Manager vtable+0x10(key=0,ptr=&[EBP-0x40],len=0x39)`。

**需嚴守**：`0x0001` 是**尚未 framed/encoded 的 57-byte payload 的開頭 WORD**，不能當成真正 TCP stream 的第一兩 bytes。任何未在本段靜態碼實證的帳密欄位語義只能暫稱 `runtime source`；`Client+BF64/+BF68` 於 `0x49595B/962` 分別存 EDI/EBX，和 `BF60` key1 alias 不相同。

**原生證據：** `.text` VA `0x00495872–0x0049597B`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  495872:	68 90 01 00 00       	push   0x190
  495877:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00 00       	mov    ecx,0x1
  495884:	66 89 4d c0          	mov    WORD PTR [ebp-0x40],cx
  495888:	89 45 c6             	mov    DWORD PTR [ebp-0x3a],eax
  49588b:	89 45 ca             	mov    DWORD PTR [ebp-0x36],eax
  49588e:	89 45 ce             	mov    DWORD PTR [ebp-0x32],eax
  495891:	89 45 d2             	mov    DWORD PTR [ebp-0x2e],eax
  495894:	89 45 d6             	mov    DWORD PTR [ebp-0x2a],eax
  495897:	66 89 4d da          	mov    WORD PTR [ebp-0x26],cx
  49589b:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  49589e:	88 45 e0             	mov    BYTE PTR [ebp-0x20],al
  4958a1:	89 45 e1             	mov    DWORD PTR [ebp-0x1f],eax
  4958a4:	89 45 e5             	mov    DWORD PTR [ebp-0x1b],eax
  4958a7:	89 45 e9             	mov    DWORD PTR [ebp-0x17],eax
  4958aa:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  4958ad:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  4958b0:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  4958b3:	e8 e8 f2 f6 ff       	call   0x404ba0
  4958b8:	8b 90 e0 67 00 00    	mov    edx,DWORD PTR [eax+0x67e0]
  4958be:	89 55 c2             	mov    DWORD PTR [ebp-0x3e],edx
  4958c1:	e8 da f2 f6 ff       	call   0x404ba0
  4958c6:	6a 0a                	push   0xa
  4958c8:	05 e4 67 00 00       	add    eax,0x67e4
  4958cd:	50                   	push   eax
  4958ce:	8d 45 c6             	lea    eax,[ebp-0x3a]
  4958d1:	6a 0a                	push   0xa
  4958d3:	50                   	push   eax
  4958d4:	e8 25 e7 3f 00       	call   0x893ffe
  4958d9:	e8 c2 f2 f6 ff       	call   0x404ba0
  4958de:	6a 0a                	push   0xa
  4958e0:	05 fa 67 00 00       	add    eax,0x67fa
  4958e5:	50                   	push   eax
  4958e6:	8d 4d e5             	lea    ecx,[ebp-0x1b]
  4958e9:	6a 0a                	push   0xa
  4958eb:	51                   	push   ecx
  4958ec:	e8 0d e7 3f 00       	call   0x893ffe
  4958f1:	c6 45 da 01          	mov    BYTE PTR [ebp-0x26],0x1
  4958f5:	e8 a6 f2 f6 ff       	call   0x404ba0
  4958fa:	8a 90 98 68 00 00    	mov    dl,BYTE PTR [eax+0x6898]
  495900:	88 55 db             	mov    BYTE PTR [ebp-0x25],dl
  495903:	e8 98 f2 f6 ff       	call   0x404ba0
  495908:	05 99 68 00 00       	add    eax,0x6899
  49590d:	50                   	push   eax
  49590e:	8d 45 dc             	lea    eax,[ebp-0x24]
  495911:	6a 05                	push   0x5
  495913:	50                   	push   eax
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
```

## E54.7 — `Manager key0 send` 找 active-map，無鍵/零指標/空長度的 bounded return

**N**：`0x8069A0` 以 `Manager+0x18` map tree 的 key argument 查 `0x8438C0`，若返回 end sentinel 或 node+0x10 Conn* 為 0，`0x8069CC` 回傳 0；若輸入長度==0 則回 1（不必真的入列），否則 `0x8069E6–0x8069EB` 取 data ptr/len，以 `ECX=Conn*` 呼叫 `0x8060D0`。

同 key replace：E50 的 `0x806CB3..CD2` 移除舊 **map node** 再插入新 Conn，因而 `0x8069A0` 只基於**當下映射**投遞資料；不能由傳入 key=0 就推稱一定投遞在第一次 Connect 的 EDI 上（並發或重連可能改映射）。本段選服函式同一控制流不直接重連，但這仍是 map ownership 需要隔離的概念。

**原生證據：** `.text` VA `0x008069A0–0x008069F6`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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

## E54.8 — `Conn+queue` allocation、負載大小限制與 A024 wake-up flag

**N**：`0x8060D0` 先比較 `Conn+A0A4 > 0x12C (=300)`，滿足時立即 return 0；否則從全域 `0x807470` 取得 0x1000 類 buffer object、`0x806163` 檢查 len<=0x1000 再複製到 buffer+8，`0x806177` 呼叫 `0x806060`。需區分這是 payload enqueue 的判斷，**不是** TCP framing 的全局限制。`0x806060` 以 `Conn+A0D4` mutex 序列化操作，將 node 插入 `Conn+A074` 雙向 list、增加 `Conn+A078`，unlock 後設 `Conn+A024=1`，return 1。

**有界資料流**：`0x39` 和 `0x007E` 等都先入此 queue，並沒有在 `0x8069A0/8060D0/806060` 內直接呼叫 WSASend。當 len>0x1000 時 `0x8060D0` 只在可見分支不複製 payload，但路徑會繼續呼叫 `0x806060`；所以不能概括寫「大於 0x1000 一律拒絕」而未查下游 queue 的 buffer 預設值。此處不宣稱完整 encoder 內容。

**原生證據：** `.text` VA `0x008060D0–0x00806190`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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
  80618e:	c2 08              	ret    0x8
```

**原生證據：** `.text` VA `0x00806060–0x008060CC`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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

## E54.9 — 主循環 `0x491FDD→0x804A40` 真正串起 enqueue 後的 send pump

**N**：在已知主循環邊界 `0x491FD3..491FEB`，`[EBX+0x90] == 0` 分支明確 `push EBX; call 0x804A40`；另一分支呼叫 `0x804C70`。`0x491FEC` 再調 `0x804FC0` 統計。因而傳統 E8 掃描可定位 `0x804A40` 的主循環直接 caller `0x491FDD`；`0x490FE0` 則仍須由 Client vtable 虛呼叫追查。

`0x804A40` 先 `GetTickCount`（IAT `0xBD25A0`）和 Pool singleton `[0xFBA858]`；`0x804AA2..AAF` 由 `Pool+0 / Pool+4` 差值計算元素數，`0x804AC3` 讀取 `Pool+0` 的 Conn* 陣列，`0x804AC8` gate `Conn+A0AC!=0`，`0x804AD6 call 0x8061A0`。**注意：此遍歷的是 Pool+0/4 的所有 allocated slots，不是 Pool+0x10 的可重用 vector**；不可由 E53 prewarm free vector 直接推送必然發生。

**原生證據：** `.text` VA `0x00491FC7–0x00492018`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  491fc7:	e8 64 33 f9 ff       	call   0x425330
  491fcc:	8b f0                	mov    esi,eax
  491fce:	e8 ad 4b 06 00       	call   0x4f6b80
  491fd3:	80 bb 90 00 00 00 00 	cmp    BYTE PTR [ebx+0x90],0x0
  491fda:	75 08                	jne    0x491fe4
  491fdc:	53                   	push   ebx
  491fdd:	e8 5e 2a 37 00       	call   0x804a40
  491fe2:	eb 07                	jmp    0x491feb
  491fe4:	8b f3                	mov    esi,ebx
  491fe6:	e8 85 2c 37 00       	call   0x804c70
  491feb:	53                   	push   ebx
  491fec:	e8 cf 2f 37 00       	call   0x804fc0
  491ff1:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  491ff5:	8b 8c 24 50 03 00 00 	mov    ecx,DWORD PTR [esp+0x350]
  491ffc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  492003:	59                   	pop    ecx
  492004:	5f                   	pop    edi
  492005:	5e                   	pop    esi
  492006:	5b                   	pop    ebx
  492007:	8b 8c 24 38 03 00 00 	mov    ecx,DWORD PTR [esp+0x338]
  49200e:	33 cc                	xor    ecx,esp
  492010:	e8 ec ef 3f 00       	call   0x891001
  492015:	8b e5                	mov    esp,ebp
  492017:	5d                   	pop    ebp
```

**原生證據：** `.text` VA `0x00804A40–0x00804B22`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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
  804b1a:	c7 45 ec 00 00 00 00 	mov    DWORD PTR [ebp-0x14],0x0
  804b21:	83       	cmp    DWORD PTR [esi+0xa028],0x0
```

## E54.10 — send pump 的 in-flight gate → Manager vtable +0x0C → WSASend

**N**：`0x804B21` 若 `Conn+A028==0`（沒有待提交 encoded bytes）直接跳過；若 `Conn+A0B8>0`（已有 send I/O）則跳過本輪 post；否則 `0x804B3C..B5A` 將 `Conn+0x5020`、長度 `Conn+A028`、`Conn*` 等傳給 `Manager vtable+0x0C`。該 slot 在 `.rdata` `Manager vtable 0xC51748+0x0C` 是 `0x8068B0`，其 `0x806912` 透過 PE IAT `0xBD25B8` 呼叫 WSASend 並用 `Conn+A050` OVERLAPPED；立即成功或 `WSA_IO_PENDING` 使 `InterlockedIncrement(A0B8)`，其他錯誤不加。

**C**：`0x4957C0` 成功+已排 `0x39`，且 Conn lease 仍有效、queue parser 成功、主循環執行、send buffer 長度 > 0、沒有正在 pending 的 send 時，Client 有原生 WSASend 投遞路徑。這是比『本地 enqueue』更具體的可重現鏈，仍不是觀察 wire transmission 的證據。

**原生證據：** `.text` VA `0x00804B21–0x00804B9B`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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

**原生證據：** `.text` VA `0x008068B0–0x0080699B`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2               	ret    0x10
```

## E54.11 — 第二種 send pump 與後續 encoded queue 消耗，不是唯一 timer 路徑

**N**：另一函式 `0x8051C0..0x8053B9` 由 `Pool+0/4` 取得 Conn*，按索引迭代；同樣 `0x805228 call 0x8061A0`，`0x805273` 檢查 `Conn+A028`，`0x805280` 檢查 `Conn+A0B8`，`0x80529F..AC` 用 Manager vtable+0x0C 發送。這是與 `0x804A40` **不同的 pump variant**，取樣索引與週期條件不同。`0x8061A0` 不是直接 WSASend，會讀 `Conn+A074` 的 raw outgoing list、依 `Conn+A02C` 選取 `0x807830` 等 encode 路徑，再用 `0x807A70` 構造待發送資料；完成時移除已消費 list node、記帳，且透過 mutex/全域 free pool 歸還 packet buffer。

此處即使連上 encoding stage，也不能將 `0x49587F` 建的 57 bytes 寫成固定 wire bytes；encoding 不同 mode 可能增添 header、checksum、transform、fragment。關於 `Conn+A02C=2` 的預設及 reuse 未必重設，沿用 E46/E52 的有界結論，沒有從本段推定 first packet encoder 所選 mode 已 runtime 證實。

**原生證據：** `.text` VA `0x008051D0–0x008052D2`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  8051d0:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  8051d7:	75 15                	jne    0x8051ee
  8051d9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8051e0:	74 07                	je     0x8051e9
  8051e2:	e8 79 5d c9 ff       	call   0x49af60
  8051e7:	eb 05                	jmp    0x8051ee
  8051e9:	e8 12 5e c9 ff       	call   0x49b000
  8051ee:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  8051f4:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  8051f7:	2b 01                	sub    eax,DWORD PTR [ecx]
  8051f9:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  8051fc:	c1 f8 02             	sar    eax,0x2
  8051ff:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  805202:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805205:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  805208:	3b f8                	cmp    edi,eax
  80520a:	0f 83 a9 01 00 00    	jae    0x8053b9
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
  80526c:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [ebp-0xc],0x0
  805273:	83 be 28 a0 00 00 00 	cmp    DWORD PTR [esi+0xa028],0x0
  80527a:	0f 84 29 01 00 00    	je     0x8053a9
  805280:	8b 96 b8 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0b8]
  805286:	85 d2                	test   edx,edx
  805288:	0f 8f 1b 01 00 00    	jg     0x8053a9
  80528e:	8b 86 28 a0 00 00    	mov    eax,DWORD PTR [esi+0xa028]
  805294:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  80529a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80529c:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  80529f:	8d 7d f4             	lea    edi,[ebp-0xc]
  8052a2:	57                   	push   edi
  8052a3:	50                   	push   eax
  8052a4:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  8052aa:	50                   	push   eax
  8052ab:	56                   	push   esi
  8052ac:	ff d2                	call   edx
  8052ae:	85 c0                	test   eax,eax
  8052b0:	75 20                	jne    0x8052d2
  8052b2:	56                   	push   esi
  8052b3:	e8 28 11 00 00       	call   0x8063e0
  8052b8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  8052be:	8b 01                	mov    eax,DWORD PTR [ecx]
  8052c0:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  8052c3:	6a 00                	push   0x0
  8052c5:	56                   	push   esi
  8052c6:	ff d2                	call   edx
  8052c8:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  8052cf:	00 00 00 
```

**原生證據：** `.text` VA `0x008061A0–0x0080627B`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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
```

## E54.12 — SEND／RECV 的 IOCP completion、計數與下游 dispatch 不能合稱為一個 pending barrier

**N**：IOCP worker `0x806CF0` 中 `GetQueuedCompletionStatus` 出參分為 bytes、completion key（Conn* 或 key=1 stop sentinel）及 OVERLAPPED*。成功且 recv OVERLAPPED `Conn+A030`：`0x806DE4..0x806E08` 計 bytes 與 recv completions、`0x807B40` 解 framing，返回非零時呼叫 Manager vtable+0x14 `0x806A00` 再 post recv；失敗且非 send OVERLAPPED 不增減 `Conn+A0B8`。成功 send OVERLAPPED `Conn+A050`：`0x806E91..0x806EC4` 可能清理 send buffer `0x8077B0`，依 `Conn+A028` 更新 `A024`，然後 `InterlockedDecrement(A0B8)`；失敗 send OVERLAPPED 也在 `0x806EF1` decrement，再按 `A0B8==0` 觸發 close-by-Conn。

**安全限制**：`0x806A00` 中 WSARecv 不對 `A0B8` increment，`0x805B40` recycle 只查 A0B8==0；這不構成 recv outstanding 全域安全保證。completion result/EOF 及 runtime ordering 仍須獨立實證；不能從 atomic zero 推得 OS socket 一定不存在。

**原生證據：** `.text` VA `0x00806D6F–0x00806E2F`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
  806d9e:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  806da1:	3b d6                	cmp    edx,esi
  806da3:	75 1b                	jne    0x806dc0
  806da5:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806da8:	3b fe                	cmp    edi,esi
  806daa:	74 84                	je     0x806d30
  806dac:	68 04 17 c5 00       	push   0xc51704
  806db1:	6a 02                	push   0x2
  806db3:	e8 48 96 ee ff       	call   0x6f0400
  806db8:	83 c4 08             	add    esp,0x8
  806dbb:	e9 70 ff ff ff       	jmp    0x806d30
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
```

**原生證據：** `.text` VA `0x00806E7D–0x00806F2E`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
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
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7 80 a8 a0 00 00 01 	mov    DWORD PTR [eax+0xa0a8],0x1
  806f26:	00 00 00 
  806f29:	e9 02 fe ff ff       	jmp    0x806d30
```

## E54.13 — S2C framing 的合法長度、mode header、選擇解碼與雙佇列分岔

**N**：`0x807B40` 從 `Conn+0x18` 接收累積區讀`WORD [EBX]`，`0x807BB5` 排除 `0`，`0x807BC3` 排除 `>0x1000`；`WORD [EBX+2]` 再依 `0x2633`（header 8 bytes／特殊 flag）、`0x0BBB`（header 6 bytes／另 flag）、`0x1A68`、`0x22D7`（header 4 bytes）與預設 4 bytes 區分。`0x807C34` 比對累積 bytes ≥ length+header，否則跳到緩衝折疊。`0x807C7C..807D75` 有 XOR/完整性與可能解壓／還原；`0x807D7A call 0x807E50` 將 <=0x1000 bytes 放入 packet buffer+8。

有條件分派 `0x807D83`：`[packet+4]==0` 時 `0x804310→0x8076F0`；否則 `0x489920→0x8040A0`。之後 `0x807DB2` 跳下一個 framed item，`0x807DDA` 移除已消費 bytes 並整理 `Conn+0x18/0x5000` 累積狀態。其中 `packet+4 == 0` 是將空 packet 結構清零後交回 FE3358 的回收分支，**不是**業務 callback；正長度才以 `Conn+A080` 交 FC10D0 的 `0x8040A0` lane queue，仍須主循環 `0x804740` 才會進 handler。這些是通用 wire framing 與分組佇列交付，不足以證明某個特定 `0x0013`/`0x007A` 已真的從 Server 回來，更不能把 2-byte first WORD `0x0001` 混同 outer framing 長度。

**原生證據：** `.text` VA `0x00807B85–0x00807C44`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  807b85:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807b88:	8b fa                	mov    edi,edx
  807b8a:	01 8f 00 50 00 00    	add    DWORD PTR [edi+0x5000],ecx
  807b90:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807b94:	8b 87 00 50 00 00    	mov    eax,DWORD PTR [edi+0x5000]
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
```

**原生證據：** `.text` VA `0x00807C7C–0x00807D2C`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  807c7c:	bf 58 33 fe 00       	mov    edi,0xfe3358
  807c81:	e8 2a f9 ff ff       	call   0x8075b0
  807c86:	8d 3c 1e             	lea    edi,[esi+ebx*1]
  807c89:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807c8c:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  807c90:	8d 0c 3e             	lea    ecx,[esi+edi*1]
  807c93:	3b 7c 24 14          	cmp    edi,DWORD PTR [esp+0x14]
  807c97:	0f 82 39 01 00 00    	jb     0x807dd6
  807c9d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807ca1:	81 c2 00 50 00 00    	add    edx,0x5000
  807ca7:	3b fa                	cmp    edi,edx
  807ca9:	0f 83 27 01 00 00    	jae    0x807dd6
  807caf:	3b 4c 24 14          	cmp    ecx,DWORD PTR [esp+0x14]
  807cb3:	0f 82 1d 01 00 00    	jb     0x807dd6
  807cb9:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807cbd:	81 c2 00 50 00 00    	add    edx,0x5000
  807cc3:	3b ca                	cmp    ecx,edx
  807cc5:	0f 83 0b 01 00 00    	jae    0x807dd6
  807ccb:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  807cd0:	74 5a                	je     0x807d2c
  807cd2:	8a 17                	mov    dl,BYTE PTR [edi]
  807cd4:	80 f2 7c             	xor    dl,0x7c
  807cd7:	b8 01 00 00 00       	mov    eax,0x1
  807cdc:	88 54 24 2c          	mov    BYTE PTR [esp+0x2c],dl
  807ce0:	3b f0                	cmp    esi,eax
  807ce2:	76 10                	jbe    0x807cf4
  807ce4:	8a 0c 07             	mov    cl,BYTE PTR [edi+eax*1]
  807ce7:	32 4c 04 2b          	xor    cl,BYTE PTR [esp+eax*1+0x2b]
  807ceb:	40                   	inc    eax
  807cec:	88 4c 04 2b          	mov    BYTE PTR [esp+eax*1+0x2b],cl
  807cf0:	3b c6                	cmp    eax,esi
  807cf2:	72 f0                	jb     0x807ce4
  807cf4:	8d 94 24 2c 10 00 00 	lea    edx,[esp+0x102c]
  807cfb:	52                   	push   edx
  807cfc:	8b ce                	mov    ecx,esi
  807cfe:	8d 44 24 30          	lea    eax,[esp+0x30]
  807d02:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  807d06:	c7 44 24 1c 00 10 00 	mov    DWORD PTR [esp+0x1c],0x1000
  807d0d:	00 
  807d0e:	e8 7d f4 f1 ff       	call   0x727190
  807d13:	83 c4 04             	add    esp,0x4
  807d16:	85 c0                	test   eax,eax
  807d18:	75 65                	jne    0x807d7f
  807d1a:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  807d1e:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d22:	8d 84 24 2c 10 00 00 	lea    eax,[esp+0x102c]
  807d29:	50                   	push   eax
  807d2a:	eb 4e                	jmp    0x807d7a
```

**原生證據：** `.text` VA `0x00807D77–0x00807E43`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  807d77:	57                   	push   edi
  807d78:	8b f8                	mov    edi,eax
  807d7a:	e8 d1 00 00 00       	call   0x807e50
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
  807db2:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  807db5:	03 54 24 20          	add    edx,DWORD PTR [esp+0x20]
  807db9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  807dbd:	8b 80 00 50 00 00    	mov    eax,DWORD PTR [eax+0x5000]
  807dc3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dc7:	03 da                	add    ebx,edx
  807dc9:	2b c3                	sub    eax,ebx
  807dcb:	83 f8 04             	cmp    eax,0x4
  807dce:	0f 83 dc fd ff ff    	jae    0x807bb0
  807dd4:	eb 04                	jmp    0x807dda
  807dd6:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dda:	8b b7 00 50 00 00    	mov    esi,DWORD PTR [edi+0x5000]
  807de0:	8d 87 00 50 00 00    	lea    eax,[edi+0x5000]
  807de6:	2b f3                	sub    esi,ebx
  807de8:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807dec:	8d 0c 1e             	lea    ecx,[esi+ebx*1]
  807def:	3b df                	cmp    ebx,edi
  807df1:	72 2a                	jb     0x807e1d
  807df3:	3b d8                	cmp    ebx,eax
  807df5:	73 26                	jae    0x807e1d
  807df7:	3b cf                	cmp    ecx,edi
  807df9:	72 22                	jb     0x807e1d
  807dfb:	3b c8                	cmp    ecx,eax
  807dfd:	73 1e                	jae    0x807e1d
  807dff:	85 f6                	test   esi,esi
  807e01:	78 1a                	js     0x807e1d
  807e03:	56                   	push   esi
  807e04:	53                   	push   ebx
  807e05:	57                   	push   edi
  807e06:	e8 e5 94 08 00       	call   0x8912f0
  807e0b:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  807e0f:	83 c4 0c             	add    esp,0xc
  807e12:	03 fe                	add    edi,esi
  807e14:	89 38                	mov    DWORD PTR [eax],edi
  807e16:	b8 01 00 00 00       	mov    eax,0x1
  807e1b:	eb 02                	jmp    0x807e1f
  807e1d:	33 c0                	xor    eax,eax
  807e1f:	8b 8c 24 38 20 00 00 	mov    ecx,DWORD PTR [esp+0x2038]
  807e26:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  807e2d:	59                   	pop    ecx
  807e2e:	5f                   	pop    edi
  807e2f:	5e                   	pop    esi
  807e30:	5b                   	pop    ebx
  807e31:	8b 8c 24 20 20 00 00 	mov    ecx,DWORD PTR [esp+0x2020]
  807e38:	33 cc                	xor    ecx,esp
  807e3a:	e8 c2 91 08 00       	call   0x891001
  807e3f:	8b e5                	mov    esp,ebp
  807e41:	5d                   	pop    ebp
  807e42:	c2               	ret    0x4
```

**原生證據：** `.text` VA `0x00807E50–0x00807E79`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  807e50:	55                   	push   ebp
  807e51:	8b ec                	mov    ebp,esp
  807e53:	81 fe 00 10 00 00    	cmp    esi,0x1000
  807e59:	76 06                	jbe    0x807e61
  807e5b:	32 c0                	xor    al,al
  807e5d:	5d                   	pop    ebp
  807e5e:	c2 04 00             	ret    0x4
  807e61:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807e64:	56                   	push   esi
  807e65:	50                   	push   eax
  807e66:	8d 4f 08             	lea    ecx,[edi+0x8]
  807e69:	51                   	push   ecx
  807e6a:	e8 61 5d 09 00       	call   0x89dbd0
  807e6f:	83 c4 0c             	add    esp,0xc
  807e72:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  807e75:	b0 01                	mov    al,0x1
  807e77:	5d                   	pop    ebp
  807e78:	c2               	ret    0x4
```

## E54.14 — close/retry 與 `Client+BF58` writer 反證的有界結果

**N**：`0x806A00` 收包失敗非 `WSA_IO_PENDING` 時調 vtable+0x24 close-by-Conn `0x806FC0`，設 `Conn+A0A8=1` 並 return 0；成功/WSA_IO_PENDING 時調 `0x8065B0` 節流 gate（如為 1，仍 close）。close-by-Conn `0x806FC0` 的有效 socket、A0A8==0 分支呼叫 socket shutdown/close 及 `0x805A80` Pool+28 tracking，然後 E53 的 Client+8 virtual +0x30 才可能轉 Pool+48。不是呼叫一次 recv 就必然 ACK。

**有限 pattern scope**：在完整 `.text` raw slice 找 literal little-endian `58 bf 00 00`（`BF58` disp32）只命中一處，正是 `0x4910C5 cmp [arg+BF58],Conn*` 的 displacement；沒有命中任何使用**相同 disp32 編碼**的直接 writer。這不是 runtime 或所有編碼型態的 writer 全集；任何基址預偏移、memcpy、disp8、別名/跨模組都可能繞過 pattern。`0x490FE0` 在 `C05AA4+0x30` vtable，而不是 direct E8 caller；即使搜索 0x490FE0 direct CALL 無結果，不能說這條清理方法不會被調用。

**same-key reconnect 邊界**：E50 active map 的 erase 插入不 free old Conn；E53 Pool+28→+48 是另一個**可用但需先 close**的 producer。若 old Conn 未進 Pool+28、在其他別名存在、或 pending recv 尚未解，現有證據不能判定 old Conn 最終 owner。失敗 connect 的 key0/2 只是 key-shutdown，不等於 guaranteed close/retry。

**原生證據：** `.text` VA `0x00806A4C–0x00806ACE`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  806a4c:	ff 15 bc 25 bd 00    	call   DWORD PTR ds:0xbd25bc
  806a52:	83 f8 ff             	cmp    eax,0xffffffff
  806a55:	75 54                	jne    0x806aab
  806a57:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806a5d:	8b d8                	mov    ebx,eax
  806a5f:	81 fb e5 03 00 00    	cmp    ebx,0x3e5
  806a65:	74 44                	je     0x806aab
  806a67:	8b 17                	mov    edx,DWORD PTR [edi]
  806a69:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806a6c:	6a 00                	push   0x0
  806a6e:	56                   	push   esi
  806a6f:	8b cf                	mov    ecx,edi
  806a71:	ff d0                	call   eax
  806a73:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	00 00 00 
  806a7d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806a81:	74 1d                	je     0x806aa0
  806a83:	8b 36                	mov    esi,DWORD PTR [esi]
  806a85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806a8b:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806a8e:	50                   	push   eax
  806a8f:	53                   	push   ebx
  806a90:	56                   	push   esi
  806a91:	68 58 16 c5 00       	push   0xc51658
  806a96:	6a 02                	push   0x2
  806a98:	e8 63 99 ee ff       	call   0x6f0400
  806a9d:	83 c4 14             	add    esp,0x14
  806aa0:	5f                   	pop    edi
  806aa1:	5e                   	pop    esi
  806aa2:	33 c0                	xor    eax,eax
  806aa4:	5b                   	pop    ebx
  806aa5:	8b e5                	mov    esp,ebp
  806aa7:	5d                   	pop    ebp
  806aa8:	c2 04 00             	ret    0x4
  806aab:	e8 00 fb ff ff       	call   0x8065b0
  806ab0:	83 f8 01             	cmp    eax,0x1
  806ab3:	75 0c                	jne    0x806ac1
  806ab5:	8b 17                	mov    edx,DWORD PTR [edi]
  806ab7:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806aba:	6a 00                	push   0x0
  806abc:	56                   	push   esi
  806abd:	8b cf                	mov    ecx,edi
  806abf:	ff d0                	call   eax
  806ac1:	5f                   	pop    edi
  806ac2:	5e                   	pop    esi
  806ac3:	b8 01 00 00 00       	mov    eax,0x1
  806ac8:	5b                   	pop    ebx
  806ac9:	8b e5                	mov    esp,ebp
  806acb:	5d                   	pop    ebp
  806acc:	c2 04              	ret    0x4
```

**原生證據：** `.text` VA `0x00806FF2–0x0080704A`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  806ff2:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  806ff5:	83 bf a8 a0 00 00 00 	cmp    DWORD PTR [edi+0xa0a8],0x0
  806ffc:	8b 37                	mov    esi,DWORD PTR [edi]
  806ffe:	75 4a                	jne    0x80704a
  807000:	85 f6                	test   esi,esi
  807002:	74 46                	je     0x80704a
  807004:	83 fe ff             	cmp    esi,0xffffffff
  807007:	74 41                	je     0x80704a
  807009:	80 7d 0c 00          	cmp    BYTE PTR [ebp+0xc],0x0
  80700d:	75 1e                	jne    0x80702d
  80700f:	6a 04                	push   0x4
  807011:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  807014:	51                   	push   ecx
  807015:	68 80 00 00 00       	push   0x80
  80701a:	68 ff ff 00 00       	push   0xffff
  80701f:	56                   	push   esi
  807020:	c7 45 0c 01 00 00 00 	mov    DWORD PTR [ebp+0xc],0x1
  807027:	ff 15 ac 25 bd 00    	call   DWORD PTR ds:0xbd25ac
  80702d:	6a 02                	push   0x2
  80702f:	56                   	push   esi
  807030:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  807036:	56                   	push   esi
  807037:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  80703d:	57                   	push   edi
  80703e:	e8 2d 40 c9 ff       	call   0x49b070
  807043:	8b f8                	mov    edi,eax
  807045:	e8 36 ea ff ff       	call   0x805a80
```

**原生證據：** `.text` VA `0x00490FE0–0x004910D0`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  490fe0:	55                   	push   ebp
  490fe1:	8b ec                	mov    ebp,esp
  490fe3:	83 e4 f8             	and    esp,0xfffffff8
  490fe6:	6a ff                	push   0xffffffff
  490fe8:	68 d0 98 94 00       	push   0x9498d0
  490fed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  490ff3:	50                   	push   eax
  490ff4:	81 ec 40 03 00 00    	sub    esp,0x340
  490ffa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  490fff:	33 c4                	xor    eax,esp
  491001:	89 84 24 38 03 00 00 	mov    DWORD PTR [esp+0x338],eax
  491008:	53                   	push   ebx
  491009:	56                   	push   esi
  49100a:	57                   	push   edi
  49100b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  491010:	33 c4                	xor    eax,esp
  491012:	50                   	push   eax
  491013:	8d 84 24 50 03 00 00 	lea    eax,[esp+0x350]
  49101a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  491020:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  491023:	33 f6                	xor    esi,esi
  491025:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  491029:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49102f:	75 14                	jne    0x491045
  491031:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491037:	74 07                	je     0x491040
  491039:	e8 22 9f 00 00       	call   0x49af60
  49103e:	eb 05                	jmp    0x491045
  491040:	e8 bb 9f 00 00       	call   0x49b000
  491045:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  49104b:	8b 41 34             	mov    eax,DWORD PTR [ecx+0x34]
  49104e:	50                   	push   eax
  49104f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  491055:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49105b:	75 14                	jne    0x491071
  49105d:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491063:	74 07                	je     0x49106c
  491065:	e8 f6 9e 00 00       	call   0x49af60
  49106a:	eb 05                	jmp    0x491071
  49106c:	e8 8f 9f 00 00       	call   0x49b000
  491071:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491077:	8b 4a 28             	mov    ecx,DWORD PTR [edx+0x28]
  49107a:	8b 01                	mov    eax,DWORD PTR [ecx]
  49107c:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  491080:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  491084:	3b c1                	cmp    eax,ecx
  491086:	0f 84 4a 01 00 00    	je     0x4911d6
  49108c:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  49108f:	39 b3 ac a0 00 00    	cmp    DWORD PTR [ebx+0xa0ac],esi
  491095:	75 0b                	jne    0x4910a2
  491097:	8b 00                	mov    eax,DWORD PTR [eax]
  491099:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  49109d:	e9 2c 01 00 00       	jmp    0x4911ce
  4910a2:	a1 04 f7 fd 00       	mov    eax,ds:0xfdf704
  4910a7:	bf 01 00 00 00       	mov    edi,0x1
  4910ac:	03 c7                	add    eax,edi
  4910ae:	50                   	push   eax
  4910af:	68 68 58 c0 00       	push   0xc05868
  4910b4:	a3 04 f7 fd 00       	mov    ds:0xfdf704,eax
  4910b9:	e8 a6 20 40 00       	call   0x893164
  4910be:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4910c2:	83 c4 08             	add    esp,0x8
  4910c5:	39 98 58 bf 00 00    	cmp    DWORD PTR [eax+0xbf58],ebx
  4910cb:	75 50                	jne    0x49111d
  4910cd:	f6 05 d0     	test   BYTE PTR ds:0xfbacd0,0x1
```

## E54.15 — RR-0005 端到端核對矩陣、缺口分類、下一段入口與停止判據

| RR-0005 要求 | 此次最遠可證的連結 | 尚缺證據／不能升格 |
|---|---|---|
| T03 login result `0x0013` / choice roster `0x007A` → 選服 UI | 前稿 E44/E45 由 T03 引述；本段核對 `0x66C090` 兩條直呼 `0x4957C0` 與 hidden Client ESI | 未重新完整複驗 T03 packet handler 與一次 runtime session；跨 Task 原稿待 T03/T01 整合 |
| Connect slot/port | key1=`0x20DF/1`，key0=`0x20E0/0`，key2=`0x20DE/2`；皆 pipeline=2；`0x495610`,`0x4957C0` | 是 KR legacy constants，**不是**相容 Server 必須保留的部署 ports；部署政策需另行決定 |
| Client Conn alias | BF60=key1 alias；BF64=key0 alias；BF68=key2 alias，僅在各函式成功路徑 | BF58 writer/ownership、map replacement old Conn 最後 owner 未證 |
| key0 first C2S | 57 bytes raw payload，`WORD 0x0001`，`Manager send-by-key → enqueue → main/update pump → Manager WSASend` | 未證特定 session first real wire 與確切外封裝 bytes；WSASend 成功/partial/IOCP 時序未實測 |
| key2 first C2S | 成功後 post `WSARecv`，未見同函式排入獨立 initial payload | 不能推 `key2` 永遠不發首包；其他 post-send callers 未全部列舉 |
| first S2C response | `WSARecv→IOCP→0x807B40→0x807E50→0x8040A0(正長度)→0x804740(app queue pop)→0x4930E0(條件式)`；零長度走 `0x8076F0` free pool | 第一筆對端封包 ID、payload、和選服 UI 之間嚴格 session correlation 未證 |
| failure/retry | key0/key2 部分成功時，成功者 key-shutdown、return 0；key1 可因既有 BF60 走不重連分支 | 實際 retry schedule／舊 socket close／Pool ownership/IOCP race 未閉合 |

**Client 待逆向**：選服 key0 0x0001 payload 的上層 consumer/response ID 配對；`0x66C1A7/247` 之先前 T03 紀錄索引及 UI 條件精確規則；`0x490FE0` vtable 的實際 caller/time order；same-key replacement old Conn final owner、`BF58` writer、其他 send producers / key2 initial payload；`0x8076F0` 和 `0x8040A0` 如何導入選服/角色清單處理器。

**跨功能待整合**：T03 來源在 E44/E45/T03 交接有登入與 UI，T02 本段新連到 send pump 和 generic receive framing；需以共同收發 ID、handler 及同一角色選擇時序接成一段可核對 contract。

**Server 待開發**：選擇相容部署 host/ports、提供對 Client 有依據的合法應答；Server 內部資料庫、角色清單策略未知不是 Client 逆向的藉口，但不能猜 Client parser 所需的內容欄位。

**待遊玩驗證**：若要斷定真正 first wire bytes、socket lifetime 和異步競態，需合法隔離環境、記錄建立/connect/shutdown/closesocket 時序、outstanding WSASend/WSARecv/IOCP completion、實際 encode mode 及 frame hash／pcap；以 opaque handle + Conn pointer + map key 對照，避免把 socket number 當穩定 object ID。

**明確未達成 RR-0005 完整目標**：這一段**不因重大新發現停止**。在重讀可用原始碼並繼續至第20個研究單元後，已在第16～20單元重新連上既有 E44/E45 二級 callback 鏈；但仍未取得同一 session 的 first S2C response、全函式 `BF58` writer 及 old Conn 最終持有者；是**有具體解除條件的實質證據缺口**，不是『已達標』。後續 E55 應針對已建立的 `0x8040A0→0x804740→0x4930E0→0x4C4670` 條件鏈，做與初始 `0x0001` 相同 Session 的實際 first-response correlation；並並從 `0x491Fxx`、`0x490FE0` 的虛呼叫源驗證 Client 每 tick clean-up 時序；沿 `0x806AD0` map replacement 追 old Conn final close-by-Conn；必要時與 T03 比對 native payload parser。RR-0005 保持 `ACTIVE/CLAIMED`，無交付提交、S00 ACCEPTED、T01 FULL-PASS、SPEC STABLE 或實際可玩宣稱。

**原生證據：** `.text` VA `0x00806CF0–0x00806D99`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f         	je     0x806f2e
```

**原生證據：** `.text` VA `0x00805B40–0x00805BC0`；區段 raw offset = VA−`0x400C00`。下列從既知 entry/basic-block 邊界開始；遇省略時不得把 disassembly 起點落在指令中間。

```asm
  805b40:	55                   	push   ebp
  805b41:	8b ec                	mov    ebp,esp
  805b43:	83 ec 18             	sub    esp,0x18
  805b46:	53                   	push   ebx
  805b47:	56                   	push   esi
  805b48:	57                   	push   edi
  805b49:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  805b4c:	8b 5f 28             	mov    ebx,DWORD PTR [edi+0x28]
  805b4f:	8b 03                	mov    eax,DWORD PTR [ebx]
  805b51:	3b c3                	cmp    eax,ebx
  805b53:	74 33                	je     0x805b88
  805b55:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  805b58:	83 79 14 00          	cmp    DWORD PTR [ecx+0x14],0x0
  805b5c:	75 24                	jne    0x805b82
  805b5e:	8b 30                	mov    esi,DWORD PTR [eax]
  805b60:	3b 47 28             	cmp    eax,DWORD PTR [edi+0x28]
  805b63:	74 19                	je     0x805b7e
  805b65:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805b68:	89 32                	mov    DWORD PTR [edx],esi
  805b6a:	8b 08                	mov    ecx,DWORD PTR [eax]
  805b6c:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805b6f:	50                   	push   eax
  805b70:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  805b73:	e8 94 b6 08 00       	call   0x89120c
  805b78:	83 c4 04             	add    esp,0x4
  805b7b:	ff 4f 2c             	dec    DWORD PTR [edi+0x2c]
  805b7e:	8b c6                	mov    eax,esi
  805b80:	eb 02                	jmp    0x805b84
  805b82:	8b 00                	mov    eax,DWORD PTR [eax]
  805b84:	3b c3                	cmp    eax,ebx
  805b86:	75 cd                	jne    0x805b55
  805b88:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  805b8b:	8b 01                	mov    eax,DWORD PTR [ecx]
  805b8d:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805b90:	3b c1                	cmp    eax,ecx
  805b92:	75 0f                	jne    0x805ba3
  805b94:	5f                   	pop    edi
  805b95:	5e                   	pop    esi
  805b96:	5b                   	pop    ebx
  805b97:	8b e5                	mov    esp,ebp
  805b99:	5d                   	pop    ebp
  805b9a:	c2 04 00             	ret    0x4
  805b9d:	8d 49 00             	lea    ecx,[ecx+0x0]
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
  805bbc:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  805bbf:	8b               	mov    edx,DWORD PTR [edi+0x1c]
```

## 附錄 A — 原件重現方法、反證搜尋範圍與受限解釋

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -h /mnt/data/Tartaros.bin
objdump -p /mnt/data/Tartaros.bin
# 提取 `.text` 後從已知入口 disassemble，而非任意檔案 byte offset
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4957c0 --stop-address=0x4959e4 /mnt/data/e51-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x804a40 --stop-address=0x804c5b /mnt/data/e51-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x807b40 --stop-address=0x807e43 /mnt/data/e51-text.bin
```

- 本段對 `Client+BF58` 的搜尋僅是 `.text` 內 `58 bf 00 00` disp32 pattern 的大小端精確命中，不等於 dynamic alias xref 全集。`0x490FE0` 無 direct E8 候選是 code encoding 層的觀察，vtable `0xC05AA4+0x30` 是直接 `.rdata` 指標證據。
- `.text` binary `E8 rel32` target= `0x495610` 的 6 個原始候選起點是 `0x6D6377、0x6D6424、0x6D6508、0x6D65C8、0x6D670C、0x6D696C`；`0x4957C0` 是 `0x66C1A7、0x66C247`；`0x8061A0` 是 `0x804AD6、0x805228`；`0x804A40` 是 `0x491FDD`；`0x807B40` 是 `0x806E08`。各地址仍需從前後基本塊確認，目前已核對其所列關鍵呼叫。
- S2C framing 中所有非 0x2633/0x0BBB/0x1A68/0x22D7 外封裝均不可推斷為已完全處理；dispatch target 是 packet callback 機制，不直接推論 raw bytes、handler ID 或 Server 內部。
- 任何 `SetEvent` 以前被混稱 `Conn+A0B8` 均以 E50/E51 的原生 IAT `InterlockedIncrement/Decrement` 更正。

## 附錄 B — 條件式協定導覽（非可直接實作的 mock Server）

```text
T03 S2C login/choice record (historical E44/E45, cross-task verification pending)
  -> choice UI selection 0x66C090 / 0x66C1A7 or 0x66C247
  -> 0x4957C0(host, ESI=Client-like)
       Connect host:0x20E0/key0/mode2 -> C0
       Connect host:0x20DE/key2/mode2 -> C2
       if (!C0 || !C2): shutdown successful key; return false
       if (Client.BF60): drain old queue; enqueue 2B 0x007E; A0B0=1; BF60=0
       build raw payload 57B starting WORD 0x0001; key0 send-by-key
       post recv on both C0 & C2; Client.BF64=C0; Client.BF68=C2
  -> 0x8069A0 lookup map[key0] -> 0x8060D0 -> 0x806060: queue++, A024=1
  -> scheduler 0x491FDD (if EBX+90==0) -> 0x804A40 scans Pool+0 vector
       leased Conn + queued raw bytes -> 0x8061A0 (mode encode)
       if Conn.A028>0 && Conn.A0B8<=0 -> Manager+0x0C -> 0x8068B0 WSASend
  -> IOCP 0x806CF0: SEND completion decrements A0B8; RECV completion 0x807B40
  -> framing validate length/header -> 0x807E50 -> 0x8076F0 or 0x8040A0
  -> actual S2C response ID & T03 next state: STILL UNKNOWN
  -> close/recycle: 0x806FC0 -> Pool+28; conditional 0x490FE0 -> Pool+48 -> 0x805B40; same-key oldConn owner STILL UNKNOWN
```

此為**有嚴格前提的靜態導覽，不是 runtime trace**。


---

# E54 進階延伸：不以第 15 單元重大發現作停止點（E54.16～E54.20）


## E54.16 — 分清 `0x807D83` 的零長度回收與有效封包入 FC10D0

**N**：`0x807D83 cmp DWORD [packet+4],0` 判斷的是 `0x807E50` 寫入的解碼有效 payload length；`0x807D8D jne 0x807D9E` 僅非零長度抵達 `0x489920→0x8040A0`。`0x807D8F` 先 `push packet`，透過 `0x804310` 拿 `[FE3358]`，`0x8076F0` **把 [packet]、[packet+4] 清零，再在 lock/critical section 下呼叫 `0x804260` 加入 `[FE3358]+0x3C` 重用佇列，並減 `[FE3358]+0x54`**。故先前將 `0x8076F0` 稱作「第一層上層 dispatcher」是錯誤：它是空 buffer 歸還，不是登入/選角封包 handler。`0x8040A0` 分支才會將有效 decoded record 放入不同的 queue。這一修正同時確認接收 IOCP callback **不等同**第一個業務 callback。

**C/U**：這個非零 length 判斷只約束「若 decoded len>0 才 queue」。若解碼失敗、驗證失敗或 TCP 分段不足，**不可**據此斷言 callback 一定運行；free pool index/lease 等別名需要存取控制競態證據。

**原始 BIN 指令（parser branch，VA 0x807d7f–0x807db2，`.text` raw = VA−0x400C00）**

```asm
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
```

**原始 BIN 指令（zero-length recycling，VA 0x8076f0–0x80772a，`.text` raw = VA−0x400C00）**

```asm
  8076f0:	55                   	push   ebp
  8076f1:	8b ec                	mov    ebp,esp
  8076f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8076f6:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  8076fc:	c7 40 04 00 00 00 00 	mov    DWORD PTR [eax+0x4],0x0
  807703:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  807706:	56                   	push   esi
  807707:	50                   	push   eax
  807708:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80770e:	8d 4d 08             	lea    ecx,[ebp+0x8]
  807711:	51                   	push   ecx
  807712:	8d 77 3c             	lea    esi,[edi+0x3c]
  807715:	e8 46 cb ff ff       	call   0x804260
  80771a:	8b 57 58             	mov    edx,DWORD PTR [edi+0x58]
  80771d:	ff 4f 54             	dec    DWORD PTR [edi+0x54]
  807720:	52                   	push   edx
  807721:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807727:	5e                   	pop    esi
  807728:	5d                   	pop    ebp
  807729:	c2               	ret    0x4
```


## E54.17 — 正長度封包的 Conn lane → FC10D0 雙 buffer → 0x804740 6 類 pop

**N**：`0x807D9E` 以 `[Conn+A080]` 作 `0x8040A0` 第2個實參（而不是 packet ID）；本體在 global `FC10D0+0x124` lock 下，根據該 lane index 和其翻面標記 `[FC10D0+0x128+lane]`，寫入 `[FC10D0+lane*0x30 + activeSlot*0x18]` 等價的分組 ring `0x804260`，`lane==2` 額外透過 handle 觸發事件。`0x804100` 對同一 global 和 lane 做 pop；當優先面空且另一面有資料時會翻面，不可稱成單一無鎖 FIFO。`0x804740` 的 `0x804826` 從 lane0 逐一迴圈至 `lane5` (`0x8049DE cmp esi,6`)；`0x80483C` `mov eax,0xFC10D0; call 0x804100`，成功時取得 `record*`，在 `0x80486D` 透過 `[object-vtable+0x00]` 回呼。這是 user-code 進一步處理的入口，並非 `0x8076F0`。

**C/U**：`Conn+A080` 來自建立 Conn 的 lane=2，是 Connect call 的程式參數，不是命令 WORD，也不是 socket key0/2；沒有完整所有 writers 掃描不代表 lane 永遠固定。frame queue 成功不保證主循環當 tick 即 pop；callback 是否 return false 會改變同 lane 的 burst drain。

**原始 BIN 指令（queue producer，VA 0x8040a0–0x8040f6，`.text` raw = VA−0x400C00）**

```asm
  8040a0:	55                   	push   ebp
  8040a1:	8b ec                	mov    ebp,esp
  8040a3:	8b 87 24 01 00 00    	mov    eax,DWORD PTR [edi+0x124]
  8040a9:	53                   	push   ebx
  8040aa:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8040ad:	56                   	push   esi
  8040ae:	50                   	push   eax
  8040af:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8040b5:	33 d2                	xor    edx,edx
  8040b7:	38 94 3b 28 01 00 00 	cmp    BYTE PTR [ebx+edi*1+0x128],dl
  8040be:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8040c1:	0f 94 c2             	sete   dl
  8040c4:	51                   	push   ecx
  8040c5:	8d 04 5a             	lea    eax,[edx+ebx*2]
  8040c8:	8d 04 40             	lea    eax,[eax+eax*2]
  8040cb:	8d 34 c7             	lea    esi,[edi+eax*8]
  8040ce:	e8 8d 01 00 00       	call   0x804260
  8040d3:	8b 8f 24 01 00 00    	mov    ecx,DWORD PTR [edi+0x124]
  8040d9:	51                   	push   ecx
  8040da:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8040e0:	5e                   	pop    esi
  8040e1:	83 fb 02             	cmp    ebx,0x2
  8040e4:	5b                   	pop    ebx
  8040e5:	75 0d                	jne    0x8040f4
  8040e7:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [edi+0x120]
  8040ed:	52                   	push   edx
  8040ee:	ff 15 d0 20 bd 00    	call   DWORD PTR ds:0xbd20d0
  8040f4:	5d                   	pop    ebp
  8040f5:	c2               	ret    0x8
```

**原始 BIN 指令（consumer lane pop，VA 0x804826–0x8048a3，`.text` raw = VA−0x400C00）**

```asm
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

**原始 BIN 指令（consumer loop tail，VA 0x8049a5–0x804a0a，`.text` raw = VA−0x400C00）**

```asm
  8049a5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8049a8:	50                   	push   eax
  8049a9:	8d 4d f0             	lea    ecx,[ebp-0x10]
  8049ac:	51                   	push   ecx
  8049ad:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  8049b2:	e8 49 f7 ff ff       	call   0x804100
  8049b7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049bd:	84 c0                	test   al,al
  8049bf:	0f 85 8b fe ff ff    	jne    0x804850
  8049c5:	eb 06                	jmp    0x8049cd
  8049c7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049cd:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8049d0:	83 fe 02             	cmp    esi,0x2
  8049d3:	75 05                	jne    0x8049da
  8049d5:	ff d7                	call   edi
  8049d7:	89 43 44             	mov    DWORD PTR [ebx+0x44],eax
  8049da:	46                   	inc    esi
  8049db:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  8049de:	83 fe 06             	cmp    esi,0x6
  8049e1:	0f 8c 3f fe ff ff    	jl     0x804826
  8049e7:	ff d7                	call   edi
  8049e9:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  8049ec:	2b 43 38             	sub    eax,DWORD PTR [ebx+0x38]
  8049ef:	3b 45 ec             	cmp    eax,DWORD PTR [ebp-0x14]
  8049f2:	0f 97 c1             	seta   cl
  8049f5:	88 4b 59             	mov    BYTE PTR [ebx+0x59],cl
  8049f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8049fb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804a02:	59                   	pop    ecx
  804a03:	5f                   	pop    edi
  804a04:	5e                   	pop    esi
  804a05:	5b                   	pop    ebx
  804a06:	8b e5                	mov    esp,ebp
  804a08:	5d                   	pop    ebp
  804a09:	c2               	ret    0x4
```


## E54.18 — Client 主循環 `0x49198A` consumer caller 與 callback 的時限/回收

**N**：`0x49197F` 從 `[esp+0x20]` 取得當前 holder、以 `lea ebx,[edi+0x140]` 傳入 `0x804740`；與同函式其餘場景/物件判定並列，不是 socket IOCP worker 直接調 `0x804740`。`0x804858..0x80486D` 將 `record+0`、`record+8`、`record+4` 與 lane 依次推入 callback (`this=ebx`, `[vptr+0]`)，`0x804872` 呼叫計時 API 算耗時，固定呼叫 vtable+0x0C 以及在耗時 `>0x28` 時調 vtable+0x08，之後 `0x8048D3..804993` 將 record 歸還 FE3358 free pool。回呼返回零時同 lane 續 pop（`0x8049A5→0x804100`）；返回非零時跳 lane tail。故「pop 和業務 handler」是獨立階段，且處理次序可因 callback result 和 loop 而變。

**C/U**：`[esp+0x20]` 的物件別名跨整個 `0x491xxx` 函式需守住實際控制流／stack slot；不能只因 offset +0x140 就假定所有分支都必定對同一 Client instance 呼叫。既有 E45 的 Client C+0x148 是**有型別/路徑前提**的識別。主循環有呼叫不等於網路回覆一定已在此 tick 處理。

**原始 BIN 指令（main caller，VA 0x49196e–0x49198f，`.text` raw = VA−0x400C00）**

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
```

**原始 BIN 指令（callback vtable + duration，VA 0x804850–0x8048a3，`.text` raw = VA−0x400C00）**

```asm
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

**原始 BIN 指令（return-to-free-pool，VA 0x8048d3–0x804993，`.text` raw = VA−0x400C00）**

```asm
  8048d3:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  8048d9:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  8048e0:	8b 0d b0 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b0
  8048e6:	51                   	push   ecx
  8048e7:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8048ed:	a1 a4 33 fe 00       	mov    eax,ds:0xfe33a4
  8048f2:	8b 15 a0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33a0
  8048f8:	03 d0                	add    edx,eax
  8048fa:	f6 c2 03             	test   dl,0x3
  8048fd:	75 18                	jne    0x804917
  8048ff:	83 c0 04             	add    eax,0x4
  804902:	c1 e8 02             	shr    eax,0x2
  804905:	39 05 9c 33 fe 00    	cmp    DWORD PTR ds:0xfe339c,eax
  80490b:	77 0a                	ja     0x804917
  80490d:	68 94 33 fe 00       	push   0xfe3394
  804912:	e8 59 26 e3 ff       	call   0x636f70
  804917:	a1 a0 33 fe 00       	mov    eax,ds:0xfe33a0
  80491c:	03 05 a4 33 fe 00    	add    eax,DWORD PTR ds:0xfe33a4
  804922:	8b 0d 9c 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe339c
  804928:	8b f8                	mov    edi,eax
  80492a:	c1 ef 02             	shr    edi,0x2
  80492d:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  804930:	3b cf                	cmp    ecx,edi
  804932:	77 02                	ja     0x804936
  804934:	2b f9                	sub    edi,ecx
  804936:	8b 15 98 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3398
  80493c:	83 3c ba 00          	cmp    DWORD PTR [edx+edi*4],0x0
  804940:	75 1e                	jne    0x804960
  804942:	6a 10                	push   0x10
  804944:	e8 1f c9 08 00       	call   0x891268
  804949:	83 c4 04             	add    esp,0x4
  80494c:	85 c0                	test   eax,eax
  80494e:	0f 84 b8 00 00 00    	je     0x804a0c
  804954:	8b 0d 98 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3398
  80495a:	89 04 b9             	mov    DWORD PTR [ecx+edi*4],eax
  80495d:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  804960:	8b 15 98 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3398
  804966:	8b 0c ba             	mov    ecx,DWORD PTR [edx+edi*4]
  804969:	83 e0 03             	and    eax,0x3
  80496c:	8d 04 81             	lea    eax,[ecx+eax*4]
  80496f:	85 c0                	test   eax,eax
  804971:	74 02                	je     0x804975
  804973:	89 30                	mov    DWORD PTR [eax],esi
  804975:	8b 15 b0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33b0
  80497b:	be 01 00 00 00       	mov    esi,0x1
  804980:	01 35 a4 33 fe 00    	add    DWORD PTR ds:0xfe33a4,esi
  804986:	29 35 ac 33 fe 00    	sub    DWORD PTR ds:0xfe33ac,esi
  80498c:	52                   	push   edx
  80498d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
```


## E54.19 — 與 E44/E45 已有 native 證據接軌：Client +148 vtable→0x4930E0→次級 0x0013/0x007A

**前稿原件重新核對**：E44/E45 不是單純「引用 T03 摘要」；在 `extra/roy1` 的 `E44-RR0005-native-0013-007A-choice-table-to-connect.md` 及 `E45-RR0005-native-endpoint-schema-initial-message-boundaries.md` 已保留原生證據。這次獨立從 `.rdata` VA `0xC05AEC`（raw `0x8040EC`）讀到 vtable+0 = **`0x4930E0`**；Client class 的 `0x48AC87` 將 `Client+0x148` 經 `0x804380` 建構，`0x48AC9A` 與 `0x48B1C5` 安裝／恢復 vptr `0xC05AEC`。`0x4930E0` 把 payload 前 WORD 讀成命令碼（`0x4930ED movzx edi,WORD PTR [eax]`），在 length 非零且 lane=`0x2` 時進內部 vtable+4。E45 既有逐段 chain 為 `0x4930E0→0x48AAD0→0x494360→0x4FDA30→0x4B7EC0→0x4C4670`；`0x4C3220` 裝設第二級 index `0x13`→`0x4C37A0`，index `0x7A`→`0x4C3C10`（`0x4C467E` 的 `signed WORD *8 + 0x5EAC`）。`0x4C37A0` 在 mode0+非空 UTF-16 下呼叫 `0x4C3080`；`0x4C3C10` 亦能呼叫同 list parser；寫入 `FE1B54`→ UI `0x66C090`→ Connect `0x4957C0`。這是**靜態、帶分支與 vtable identity 條件的鏈**，不是本次觀測到 packet。

**型別/誤判防護**：`0x804740` 只是通用 callback invocation，無論 holder 的 vtable 是否為 `C05AEC` 均可呼叫；只有 `Client+0x148` 的 subclass 路徑才把 `vptr+0` 確認為 `0x4930E0`。不得把其他 holder 的 callback 直接指定此函式；沒有 live socket→packet session correlation 時不能把第1筆 S2C reply 指定為 `0x0013`。`C05AA4` 是 **Client+8** 的 vtable，`C05AEC` 是 **Client+0x148** 的 vtable，兩者亦不能混用。

**原始 BIN 指令（constructor vptr installation，VA 0x48ac76–0x48acc8，`.text` raw = VA−0x400C00）**

```asm
  48ac76:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  48ac79:	8d 77 08             	lea    esi,[edi+0x8]
  48ac7c:	e8 1f 3e 25 00       	call   0x6deaa0
  48ac81:	8d 87 48 01 00 00    	lea    eax,[edi+0x148]
  48ac87:	e8 f4 96 37 00       	call   0x804380
  48ac8c:	c7 87 00 02 00 00 38 	mov    DWORD PTR [edi+0x200],0xc05b38
  48ac93:	5b c0 00 
  48ac96:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	5b c0 00 
  48acb6:	89 9f 60 bf 00 00    	mov    DWORD PTR [edi+0xbf60],ebx
  48acbc:	89 9f 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],ebx
  48acc2:	89 9f 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],ebx
```

**原始 BIN 指令（callback entry and lane gate，VA 0x4930e0–0x493160，`.text` raw = VA−0x400C00）**

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10              	ret    0x10
```

**原始 BIN 指令（second-level indexed dispatch，VA 0x4c4670–0x4c46f0，`.text` raw = VA−0x400C00）**

```asm
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2 0c 00             	ret    0xc
```


## E54.20 — RR-0005 證據阻塞的精確邊界、可重現驗證與前稿範圍修正

**達到 RR-0005 目標的必要端到端條件**：

1. **靜態已知 N/C**：`0x0013`（有條件）→`0x4C3080` 的 group/subentry 解析→`FE1B54`→選擇 UI→`0x66C090`→`0x4957C0`→key0/port0x20E0 + key2/port0x20DE→本地 key0 `WORD 0x0001,len0x39` queue→`0x804A40` pump→`0x8068B0` WSASend attempt；另有 key1/port0x20DF 的 `0x495610` 路徑。這只在驗證對應 caller/handler gates、Conn 成功及 scheduled pump 條件下成立。
2. **新補 N/C**：receive `WSARecv→IOCP 0x806CF0→0x807B40→0x807E50` 正長度→FC10D0 lane queue→main caller `0x49198A→0x804740`→經 Client+148 vptr+0=`0x4930E0`、lane=2、length>0→first/second-level dispatch `0x4C4670`。零長度 packet 經 `0x8076F0` 歸還 free pool，不進業務。
3. **無法從目前純靜態 bytes 得知的 U**：某一次 key0 `0x0001` 是否真的送達 wire，是否為該 connection 第一筆 frame、實際 header/壓縮/加密旗標、該 connection 最先進來的 S2C command 是何者、Server 是否在特定時間閉鎖/拒絕、重連時 OS handle/IOCP completions 的時序。這些需 client/server runtime trace 或實際封包；不允許根據同一可達 CFG 憑空給肯定值。
4. **待閉合的 Client 靜態分析 U**：old same-key Conn 被 map erase 後哪個物件持有、所有 `Client+BF58` 等價寫入者、失敗/重試排程和 key2 其他送包入口；後續可做更廣跨模組別名/指令索引與現存 EA 反證，不能把單一立即數搜索的未命中提升為「沒有 writer」。
5. **RR 狀態及任務權限**：`research/requests/index.json` 仍 `ACTIVE/CLAIMED`；沒有 `SUBMITTED`、審查完成或 `S00 ACCEPTED`。本次沒有 commit/push；E53 亦只有本地稿。固定 `0x20DE/DF/E0` 是 KR legacy 原生值，並非 Server 必須採用的部署配置。

**停止理由不是重大進展**：完整二級 handler 靜態路徑已沿 E44/E45 重新核對，但發生於同一會話中的首個 wire/回覆及 Close/IOCP race 僅有純靜態 binary，無合法 runtime 目標/Server 輸出/pcap。此為**證據模態阻塞**，明確區分缺少可供證偽的觀測與未完的靜態 ownership index。後續應向 T03 整合既有二級 handler 的 payload schema，而不能另造協定欄位或「Server 第一筆必然回 0x0013」結論。

**原始 BIN 指令（frame to queue，VA 0x807d7f–0x807db2，`.text` raw = VA−0x400C00）**

```asm
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
```

**原始 BIN 指令（main callback，VA 0x804850–0x804888，`.text` raw = VA−0x400C00）**

```asm
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
```

**原始 BIN 指令（lane2 conditional，VA 0x4930ed–0x493137，`.text` raw = VA−0x400C00）**

```asm
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
```


---

## E54 全段最終狀態（20 單元／原稿末次校核）

`N` 直接原始機器碼，`C` 有條件 CFG，可達不代表 runtime，`U` 未知。**E54 未證實 first-wire/first-reply；RR-0005 仍 `ACTIVE/CLAIMED`。** 這份 Markdown 是保留原稿並後加延伸的完整研究證據；任何舊 E54.15 的「下一段由 `0x8076F0` 追 handler」應以 E54.16～.20 的更正為準，因 `0x8076F0` 實為零長度 buffer 回收。原稿未獲使用者 Git 提交授權，保持本地未 push。
