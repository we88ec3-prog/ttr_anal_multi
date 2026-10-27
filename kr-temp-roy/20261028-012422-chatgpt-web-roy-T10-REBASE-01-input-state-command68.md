# T10 REBASE-01 — 整合證據基準與輸入狀態／命令 0x68 BIN-first 定向驗證

- 記錄時間：2026-10-28T01:24:22+08:00
- 研究標的：KR Tartaros.bin，純靜態只讀分析；無遊戲執行、無 Hook、無修改。
- repo：we88ec3-prog/ttr_anal_multi；已經從 GitHub connector 讀取正式 T10/T11、AGENTS、HANDOFF 和 T01-20261027-05 的 README / accepted-claims / resolutions / pending；近期 commit 列表首項 `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`，**未透過分支 ref API 證實就是 main HEAD**；不以此宣稱 HEAD 完成校準。
- GitHub 無寫入；本筆記為本機新成果。既有 1–44 原稿尚未全部逐份讀回比對，不宣稱已完成全量 rebase。

## 來源與 PE 映射

- BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- 原始 BIN PE header 由 GNU objdump 實際讀出：.text VA=0x401000 raw=0x400，.rdata VA=0xBD2000 raw=0x7D0600，.data VA=0xD61000 raw=0x95E800；下述 VA 全在 BIN .text。注意 T08 過去 PE/flat 映射差異需對每個來源核實；此處以原始 PE section header + objdump 直接證據。
- `0x547240` raw：`0x547240 - 0x401000 + 0x400 = 0x146640`。
- `0x548918` raw `0x548918 - 0x401000 + 0x400 = 0x147D18`。

## 整合後可採信範圍

| 議題 | 現階段分類 | 精確限制 |
|---|---|---|
| `0x547240` 狀態機與 `>500ms` | 本段 BIN 局部分支確認 | 僅時間差比較；不等於普攻 combo / cancel window |
| `0x548918` `28..37` | 本段 BIN 控制流確認 | 為特殊命令索引迴圈；不等於十段連擊 |
| 自訂 Z/X/C/V | 玩家行為觀察、尚缺直接映射鏈 | Z 只是預設，不可硬映為 VK_Z |
| 一般/擴展鍵 phase 1/3 | T01 限定原稿 | 不稱 keydown/keyup，尚缺非零 writer |
| 3 路輸入 OR 與 byte 優先選擇 | T01 限定原稿 | 不可合併成一種語義 |
| controller index 5 / SubAI >60 | T01 有界來源線索 | 不等於玩家 V 或蓄氣秒數 |
| actor +0x3E8, skill predicate `0x54F270` | 33–44 交接線索 | 同 offset 不同類型須分；predicate 非 cast/cancel writer |
| 普攻連段、動畫完成、動作排隊 | 缺口 | 不可套用自製 `CHAIN_WINDOW=0.65` |

## 原始 bytes 證據 A：0x547240

`esi` 指向至少兩個 DWORD 的狀態記錄（本段僅推論欄位佈局，未證明類別所有權）。`[esi]` 為狀態 0–3 dispatch，`[esi+4]` 保存 timeGetTime 返回的 tick，global byte `[0xFB9014]` 被讀取。`[0xBD25A0]` 是 IAT 間接呼叫，歷史來源標記 timeGetTime；尚需從 PE imports 獨立確認符號。

- 0x5472A7/0x5472B5：若讀到 byte 1 或 2，呼叫 IAT，將 EAX 寫入 `[esi+4]`，`[esi]=2`，返回 1。
- 0x5472F6 起：byte 既不是 3、也不是 0 時，取新 tick 減去 `[esi+4]`；在 `cmp eax,0x1F4` 之後採用 **`jbe`**，意味著只有無符號差值嚴格大於 500 才走狀態 3、返回 3 的路徑。
- 另一條 phase/狀態路徑將 `[esi]` 與 `[esi+4]` 清零並返回 2 或 4；**未證其對應 V 的點放/長按，亦未證定時輪詢頻率**。
- 完整函式的跳表四個入口尚需要以 .text data 及函式入口邊界交叉確認；不能依本段推測全函式完整 CFG。

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00547240 <.text+0x146240>:
  547240:	55                   	push   ebp
  547241:	8b ec                	mov    ebp,esp
  547243:	6a ff                	push   0xffffffff
  547245:	68 1e 74 92 00       	push   0x92741e
  54724a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  547250:	50                   	push   eax
  547251:	51                   	push   ecx
  547252:	57                   	push   edi
  547253:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  547258:	33 c5                	xor    eax,ebp
  54725a:	50                   	push   eax
  54725b:	8d 45 f4             	lea    eax,[ebp-0xc]
  54725e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  547264:	b8 01 00 00 00       	mov    eax,0x1
  547269:	33 ff                	xor    edi,edi
  54726b:	84 05 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,al
  547271:	75 1b                	jne    0x54728e
  547273:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  547279:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  54727c:	e8 cf 94 18 00       	call   0x6d0750
  547281:	68 30 d5 bc 00       	push   0xbcd530
  547286:	e8 8f b0 34 00       	call   0x89231a
  54728b:	83 c4 04             	add    esp,0x4
  54728e:	8b 0e                	mov    ecx,DWORD PTR [esi]
  547290:	0f b6 05 14 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9014
  547297:	83 f9 03             	cmp    ecx,0x3
  54729a:	0f 87 be 00 00 00    	ja     0x54735e
  5472a0:	ff 24 8d 70 73 54 00 	jmp    DWORD PTR [ecx*4+0x547370]
  5472a7:	83 f8 01             	cmp    eax,0x1
  5472aa:	74 09                	je     0x5472b5
  5472ac:	83 f8 02             	cmp    eax,0x2
  5472af:	0f 85 a9 00 00 00    	jne    0x54735e
  5472b5:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  5472bb:	bf 01 00 00 00       	mov    edi,0x1
  5472c0:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  5472c3:	c7 06 02 00 00 00    	mov    DWORD PTR [esi],0x2
  5472c9:	8b c7                	mov    eax,edi
  5472cb:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5472ce:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5472d5:	59                   	pop    ecx
  5472d6:	5f                   	pop    edi
  5472d7:	8b e5                	mov    esp,ebp
  5472d9:	5d                   	pop    ebp
  5472da:	c3                   	ret
  5472db:	3b c7                	cmp    eax,edi
  5472dd:	74 7f                	je     0x54735e
  5472df:	89 3e                	mov    DWORD PTR [esi],edi
  5472e1:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  5472e4:	8b c7                	mov    eax,edi
  5472e6:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5472e9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5472f0:	59                   	pop    ecx
  5472f1:	5f                   	pop    edi
  5472f2:	8b e5                	mov    esp,ebp
  5472f4:	5d                   	pop    ebp
  5472f5:	c3                   	ret
  5472f6:	83 f8 03             	cmp    eax,0x3
  5472f9:	74 34                	je     0x54732f
  5472fb:	3b c7                	cmp    eax,edi
  5472fd:	74 30                	je     0x54732f
  5472ff:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  547305:	2b 46 04             	sub    eax,DWORD PTR [esi+0x4]
  547308:	3d f4 01 00 00       	cmp    eax,0x1f4
  54730d:	76 4f                	jbe    0x54735e
  54730f:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547312:	bf 03 00 00 00       	mov    edi,0x3
  547317:	c7 06 03 00 00 00    	mov    DWORD PTR [esi],0x3
  54731d:	8b c7                	mov    eax,edi
  54731f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  547322:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547329:	59                   	pop    ecx
  54732a:	5f                   	pop    edi
  54732b:	8b e5                	mov    esp,ebp
  54732d:	5d                   	pop    ebp
  54732e:	c3                   	ret
  54732f:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547332:	89 3e                	mov    DWORD PTR [esi],edi
  547334:	bf 02 00 00 00       	mov    edi,0x2
  547339:	8b c7                	mov    eax,edi
  54733b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  54733e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547345:	59                   	pop    ecx
  547346:	5f                   	pop    edi
  547347:	8b e5                	mov    esp,ebp
  547349:	5d                   	pop    ebp
  54734a:	c3                   	ret
  54734b:	83 f8 03             	cmp    eax,0x3
  54734e:	74 04                	je     0x547354
  547350:	3b c7                	cmp    eax,edi
  547352:	75 0a                	jne    0x54735e
  547354:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547357:	89 3e                	mov    DWORD PTR [esi],edi
  547359:	bf 04 00 00 00       	mov    edi,0x4
  54735e:	8b c7                	mov    eax,edi
  547360:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  547363:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  54736a:	59                   	pop    ecx
  54736b:	5f                   	pop    edi
  54736c:	8b e5                	mov    esp,ebp
  54736e:	5d                   	pop    ebp
  54736f:	c3                   	ret

```

## 原始 bytes 證據 B：0x548918

- 0x548918 `xor ebx,ebx`，0x54891A `lea esi,[ebx+0x1c]`；迴圈 0x548952 上限比較 `esi,0x27` 並在 0x5489B0 比較 `esi,0x26` 循環，實際處理 index **28,29,...,37**（10 筆）；index38 跳出。
- 0x548957 從 `[esi+0xFB9004]` 讀 phase byte，0x54895E 僅接受值 1；此為 *consumer*，**不是非零 phase producer**。
- 0x548985 將 WORD `0x68` 寫 stack 命令結構 `[esp+0x14]`；0x548992 設事件 byte 1；若 `[0xFBA798]==0`，以 `[0xFBA854]` 指向物件的 virtual+0x10 送出（參數順序為 push 3 / ptr / 0，實際 ABI 及接收端需驗）。
- 0x5489C1 後另有 WORD 7 與先前 stack byte 分支；這不是把 0x68 直接命名普通攻擊或技能。
- 本段顯示 `0xFB9004 + index` 參與命令候選；仍需沿 writer → controller → actor 實例鏈確認是否是玩家自訂按鍵所生的 state。

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00548918 <.text+0x147918>:
  548918:	33 db                	xor    ebx,ebx
  54891a:	8d 73 1c             	lea    esi,[ebx+0x1c]
  54891d:	8d 49 00             	lea    ecx,[ecx+0x0]
  548920:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  548927:	75 29                	jne    0x548952
  548929:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  548930:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  548937:	00 
  548938:	e8 13 7e 18 00       	call   0x6d0750
  54893d:	68 30 d5 bc 00       	push   0xbcd530
  548942:	e8 d3 99 34 00       	call   0x89231a
  548947:	83 c4 04             	add    esp,0x4
  54894a:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  548951:	ff 
  548952:	83 fe 27             	cmp    esi,0x27
  548955:	77 57                	ja     0x5489ae
  548957:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  54895e:	83 f8 01             	cmp    eax,0x1
  548961:	75 4b                	jne    0x5489ae
  548963:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  548969:	75 13                	jne    0x54897e
  54896b:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  548971:	68 10 cf bc 00       	push   0xbccf10
  548976:	e8 9f 99 34 00       	call   0x89231a
  54897b:	83 c4 04             	add    esp,0x4
  54897e:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  548985:	b9 68 00 00 00       	mov    ecx,0x68
  54898a:	8d 53 01             	lea    edx,[ebx+0x1]
  54898d:	66 89 4c 24 14       	mov    WORD PTR [esp+0x14],cx
  548992:	88 54 24 16          	mov    BYTE PTR [esp+0x16],dl
  548996:	75 16                	jne    0x5489ae
  548998:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  54899e:	8b 01                	mov    eax,DWORD PTR [ecx]
  5489a0:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5489a3:	6a 03                	push   0x3
  5489a5:	8d 54 24 18          	lea    edx,[esp+0x18]
  5489a9:	52                   	push   edx
  5489aa:	6a 00                	push   0x0
  5489ac:	ff d0                	call   eax
  5489ae:	46                   	inc    esi
  5489af:	43                   	inc    ebx
  5489b0:	83 fe 26             	cmp    esi,0x26
  5489b3:	0f 8c 67 ff ff ff    	jl     0x548920
  5489b9:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
  5489bd:	84 c0                	test   al,al
  5489bf:	74 42                	je     0x548a03
  5489c1:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5489c8:	b9 07 00 00 00       	mov    ecx,0x7
  5489cd:	66 89 4c 24 18       	mov    WORD PTR [esp+0x18],cx
  5489d2:	88 44 24 1a          	mov    BYTE PTR [esp+0x1a],al
  5489d6:	75 16                	jne    0x5489ee
  5489d8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5489de:	8b 11                	mov    edx,DWORD PTR [ecx]
  5489e0:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  5489e3:	6a 03                	push   0x3
  5489e5:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5489e9:	50                   	push   eax
  5489ea:	6a 00                	push   0x0
  5489ec:	ff d2                	call   edx
  5489ee:	b0 01                	mov    al,0x1
  5489f0:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5489f4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5489fb:	59                   	pop    ecx
  5489fc:	5f                   	pop    edi
  5489fd:	5e                   	pop    esi
  5489fe:	5b                   	pop    ebx
  5489ff:	8b e5                	mov    esp,ebp
  548a01:	5d                   	pop    ebp
  548a02:	c3                   	ret
  548a03:	32 c0                	xor    al,al
  548a05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  548a09:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  548a10:	59                   	pop    ecx
  548a11:	5f                   	pop    edi
  548a12:	5e                   	pop    esi
  548a13:	5b                   	pop    ebx
  548a14:	8b e5                	mov    esp,ebp
  548a16:	5d                   	pop    ebp
  548a17:	c3                   	ret

```

## 最小資料流及未閉合上下游

1. 尚缺 `KeyMapping.xml` 真正 action row、fallback 與載入函式到玩家輸入 state 的實參鏈。
2. `FB9004+index` phase **reader** 已有原始 bytes；要找寫入非零值的 writer（含間接寫、memcpy、物件換 bank）及鍵位釋放時的改寫。
3. `0x547240` state/tick consumer 跟 index 28–37 間尚未證同一 action；不用 500ms 推 V 蓄氣或 Z 續段。
4. `0x548918` 送 command 0x68 至 virtual+0x10 的 receiver 實體尚未證 actor cast/attack 的目的地，須辨認 packet dispatch 與 motion queue owner。
5. 待證普攻續段觸發為 Z 重按或 Z held、技能互銜接 queue/cancel 與 motion completion 回報；不得假設固定取消窗口。

## 新段號策略與後續

- 使用 `T10-REBASE-01` 獨立標記整合基準後的新研究，避免將未完成重核誤記為舊 T10-45；舊 1–44 不改寫。
- 待逐一讀回 `kr-temp-roy` 舊原稿與 `source-review-status.json`，依來源 SHA 連結相應 accepted-claims / resolutions 才能完成全量 rebase 矩陣。
- 先從 input nonzero writer 與 command 0x68 receiver 追到 controller、actor/action transition；完成之後再調整研究優先順序至 V tap/held 與連段排隊。

## 版本與權限

本筆記只建立本機副本；沒有 Commit、Push、改 owner、改 catalog、修改其他 Task。正式 main HEAD 與 1–44 全量核對仍待補證。