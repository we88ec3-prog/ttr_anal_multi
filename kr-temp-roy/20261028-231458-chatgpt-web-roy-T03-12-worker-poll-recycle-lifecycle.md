# T03-12 — KR receive worker 多 bucket 輪詢、虛擬 callback 與接收記錄回收生命週期

- 研究者 `chatgpt-web roy`；實際生成時間 `2026-10-28T23:16:13+08:00`；Task T03，正式段號 T03-12。
- 一手樣本 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE i386 `.text` RVA/VA `0x401000`、raw `0x400`，因此 `.text` raw offset = VA − `0x400C00`；`.rdata` VA `0xBD2000`, raw `0x7D0600`。
- 本研究僅靜態讀取原版 KR BIN；不執行、不 patch、不連線、不偽造封包擷取。`objdump -D -M intel -b pei-i386 -m i386` 直接讀 PE 原始指令，截取來源地址如下。
- GitHub 基線研究 `T03-9` / `T03-10` / `T03-11`；本次研究前 `main` 是 T03 分支祖先，未落後主線。T03 權責只到登入/選角；T02 transport、T05 世界切換照舊。

## 1. 關鍵結論（新於 T03-11）

1. 原生 `0x804740` 是包含 **6 個 bucket/類別 index `0..5`** 的 worker 迴圈，而非僅一次虛擬回呼：在 `0x804816` 清零 ESI 後 `0x804823` 保存 index，`0x8049DA` 自增、`0x8049DE` 比較 `6`、`0x8049E1` 反跳 `0x804826`。每個 index 對 `0xFC10D0` reader `0x804100` 發起查詢，在特定結果下回到 `0x804850` 繼續讀取。
2. 成功讀取後，`0x804858..0x80486D` 以 worker (`EBX`，來源 `[ebp+8]`) 的 `vtable[0]` 呼叫暫無法解析的 callback。其返回值保存 `[ebp-0x1C]`，並影響 `0x80499F` 是否同 index 再讀取。**不能視為 Server 成功/拒絕選角碼**。
3. 原生 `0x804872..0x8048A1` 以計時結果，呼叫 worker vtable `+0xC`，超過 `0x28` 時額外呼叫 `+0x8`。計時／統計是由呼叫 `ds:[0xBD25A0]` 前後相減而見，實際虛擬方法副作用需具體 target 才能命名。
4. **新確證的資料生命週期：** callback 完成後 `0x8048D3/0x8048D9` 清空 record `+0`/`+4`，鎖定 `FE33B0`，使用 `FE3398`/`FE339C`/`FE33A0`/`FE33A4` 管理的槽位，把 record 指標存入空槽；`0x804980` 增加 `FE33A4`、`0x804986` 減少 `FE33AC`，`0x80498D` 釋放鎖。這提供 T03-8/9 的中繼記錄下游**消費後回收**原生證據，並非一般的 wire dispatcher。
5. `0x804993` 增加 worker `+0x50` 的處理計數；index `==2` 另增 `+0x54`；全批次完成 `0x8049E7/0x8049F8` 更新 `+0x3C`、依 `+0x84` 運算的時間額度設置 byte `+0x59`。不能由此推導 T03 選角解鎖門檻。

## 2. 函式與資料流、呼叫者

| VA | 一手行為／界線 |
|---|---|
| `0x49198A` | 傳入 `parent+0x140` 作為 worker；直接 `call 0x804740`，T03-10/11 已驗 |
| `0x804740` | 本次擴充至完整 CFG；6 個 bucket / queue index 處理迴圈 |
| `0x804841`, `0x8049B2` | 兩處 `call 0x804100`；指向 `0xFC10D0` 分桶 reader |
| `0x80486D` | `call edx`，其中 `edx = *( *(worker+0) + 0 )`，需要 worker vtable writer 才能解出實際 target |
| `0x804886` | `vtable+0xC` 回呼，傳入 index / record / duration |
| `0x8048A1` | 若 elapsed > `0x28`，`vtable+0x8` 回呼 |
| `0x8048D3..0x80498D` | 釋放資料內容後，record 指標回收入 `FE3398` 的分頁槽位；包含互斥控制與計數 |
| `0x8049E1` | `index < 6` 時跳回 `0x804826`；是迴圈，不可將單筆成功誤稱結束 |
| `0x48C0E6 → 0x804650` | 傳入 `parent+0x140` 進初始化；`0x804650` 目前未見 `*[worker] = vtable`，不能誤用其內新建 transport object `0xC51748` vtable |

### Pseudocode (bounded; native branch-derived)

```cpp
void worker_cycle(Worker* w) {  // 原生類型未證實
    init_global_lane_if_needed();
    wait_on_shared_gate();
    copy_and_clear_timing_state(w); // +0x30 .. +0x58
    int i = 0;
    for (; i < 6; ++i) { // 0x8049DA/0x8049DE
        Record* rec = nullptr;
        while (read_FC10D0_bucket(&rec, i)) { // 0x804841, 0x8049B2
            if (!rec) { /* 無進一步語意可證 */ }
            auto retval = w->vfunc_0(rec->field0, &rec->payload8, rec->field4, i);
            elapsed = tick_after() - tick_before();
            w->vfunc_C(i, rec, elapsed);
            if (elapsed > 0x28) w->vfunc_8(w->field8c, i, rec, elapsed);
            recycle_record_to_FE33_slot(rec); // 同步、slot、counter；可能有不可達與錯誤分支
            ++w->field50;
            if (i == 2) ++w->field54;
            if (retval != 0) break; // 原生 0x80499F/0x8049C7 的 bounded interpretation
        }
    }
    w->field59 = exceeded_cycle_budget();
}
```

注意：偽碼為高階閱讀用、不能代替原始 Assembly，且異常/資源耗盡路徑未全部作來源完整性證明。`retval` 是 worker callback 的結果，**不是**已確認的角色選角 S→C 結果碼。

## 3. 原始 x86 Assembly（KR BIN 直接擷取）

### worker entry/init

```asm
  804740:	55                   	push   ebp
  804741:	8b ec                	mov    ebp,esp
  804743:	6a ff                	push   0xffffffff
  804745:	68 9c 9a 90 00       	push   0x909a9c
  80474a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  804750:	50                   	push   eax
  804751:	83 ec 4c             	sub    esp,0x4c
  804754:	53                   	push   ebx
  804755:	56                   	push   esi
  804756:	57                   	push   edi
  804757:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80475c:	33 c5                	xor    eax,ebp
  80475e:	50                   	push   eax
  80475f:	8d 45 f4             	lea    eax,[ebp-0xc]
  804762:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
```

### reader and virtual callbacks

```asm
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

### recycle to FE3358 shared storage

```asm
  8048a3:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  8048aa:	75 27                	jne    0x8048d3
  8048ac:	b8 01 00 00 00       	mov    eax,0x1
  8048b1:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  8048b7:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  8048ba:	e8 61 28 00 00       	call   0x807120
  8048bf:	68 90 0b bd 00       	push   0xbd0b90
  8048c4:	e8 51 da 08 00       	call   0x89231a
  8048c9:	83 c4 04             	add    esp,0x4
  8048cc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
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
  804993:	01 73 50             	add    DWORD PTR [ebx+0x50],esi
  804996:	83 7d 08 02          	cmp    DWORD PTR [ebp+0x8],0x2
  80499a:	75 03                	jne    0x80499f
  80499c:	01 73 54             	add    DWORD PTR [ebx+0x54],esi
```

### retry and poll counters

```asm
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
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
  804a09:	c2 04 00             	ret    0x4
```

## 4. vtable 未解出的具體否證與下一入口

- 反查 `0x804650` 實際原生指令：`0x8046D7` 配置 `0x5C` bytes、`0x8046F7` `mov [esi],0xC51748`，但 `ESI` 是**剛配置的 transport object**，`0x80470F` 寫入全域 `0xFBA854`。並非將 vtable 寫入 `EDI=worker`。`0x804650` 在這一段對 worker 的明確寫入主要是 `worker+0x8C`、`worker+0x60`、`worker+0x34`。因此不得把 `0xC51748` vtable+0 當作 `0x80486D` callback。
- `0x48C0E0: lea edi,[ebx+0x140]` → `0x48C0E6: call 0x804650` 已直接驗證。但這只是 worker init；需往父物件本身的建構、copy/aggregation、間接配置追 `*[parent+0x140]` 的真正 writer。
- 已在全 `.text` 掃描三種常見 `C7 [EBX/EDI/ESI+0x140],imm32` 的原始 bytes；`EBX`/`EDI` 零候選，`ESI` 九處其他函式位址，**這不能排除 `mov reg → [mem]`、`mov [worker],reg`、別名或外部初始化。** 下一段應使用資料流和 `0x48C0E6` 上層建構者，不應只憑絕對地址 xref 武斷下結論。

## 5. 玩家情境與證據分級

| 情境 | C→S | S→C/transport | reader → callback | Client 作用 | Server 原版行為 |
|---|---|---|---|---|---|
| 選角確認已通過角色可用 gate | `0x42` / 4-byte buffer T03-3，傳輸 T03-4..6 有共用原生鏈 | T03-7..8 一般解框 / 中繼，**未與 0x42 一對一配對** | 本段一般 `FC10D0` 6-index worker 消費機制，非已定位 42-reply handler | 消費後回收 record；未見確認轉場 | 批准／拒絕仍 unknown |
| 收到 FC10D0 lane 之一般資料 | 與 C→S 不一定相關 | `record+4 != 0` 進入 FC10D0 lane | `0x804100` success → worker vtable+0；其後 callback+0xC/+0x8 | record 被鎖定回收入 FE33 槽位 | 不需假設 Server policy |
| callback 返回非零 | 不適用 | record 已被取出 | 改變同 bucket 重試條件 | worker metrics 更新 | 不得當選角批准 |
| callback 返回零 | 不適用 | reader 可提供更多記錄 | `0x8049B2` 可繼續同 bucket 讀取 | record 回收及計數 | 不得當選角拒絕 |

- **原生已確認：** 6 bucket 迴圈、虛擬 callback 調度、多條記錄回收與計數更新、全域槽位使用互斥鎖。
- **部分確認：** 此共用中繼資料是否實際包含選角回包；worker vtable+0 具體實作；重試/時間額度對遊戲 UI 何時更新的作用。
- **未知：** command 42 對應原版 Server opcode / payload / 成功與失敗 handler、T05 scene handoff、原始 Server 規則。
- **AI 測試替代非證據：** fixture `42→43/69`，不得當成官方協定。

## 6. 三輪門檻與下一段

- **第 1 輪 T03-12 已完成**：從完整 `0x804740..0x804A0B` 原始 CFG 建立 `bucket 0..5 → reader → vfunc+0 / +C / +8 → record recycling → metrics` 有界功能鏈；相較 T03-11 已有重要的原生完整生命週期增量，因此符合第 1 輪重大發現停止標準。
- 第 2 輪 `T03-12-2`：未啟動；第一輪已達標。
- 第 3 輪 `T03-12-3`：未啟動；第一輪已達標。
- **T03-13 首要入口：** 逆向 `parent+0x140` 的分派表寫入（父類 constructor / aggregate builder / 通道註冊）；把 worker vtable+0 實際目標釘死後，才向 T03 選角業務回包 opcode／UI gate 展開。
- T02 owns generic transport、T04 roster/character initial state、T05 world scene、T06 UI identities。沒有修改它們；沒有執行遊戲或修改 BIN。