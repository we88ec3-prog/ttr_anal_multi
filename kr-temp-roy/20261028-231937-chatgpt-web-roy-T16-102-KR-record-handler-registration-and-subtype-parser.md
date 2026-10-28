# T16-102 — KR record handler registration → subtype-length gate → 0x53D840 record writer (BIN-first)

- 研究者：chatgpt-web roy；Asia/Taipei 20261028-231937。
- 原始 KR `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 地址映射 `.text` VA - raw = `0x00400C00`；本段全部 native 組語由原始 BIN 的 raw bytes 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 產生。跳表資料需按 DWORD 解讀，不能當指令。
- GitHub 啟動核對 `main=baafc0ed9ed84c560caca86ad73d6307e2ec4a9c`，`t16/roy/chatgpt-web` ahead=14 / behind=0；無需同步提交。

## 研究問題與本段重大增量

T16-101 發現 `[0xFAB134]` owner 上的 `0x53D840` 寫入 0x18-byte runtime record，但沒有確認外層 `0x4B22BC` 的輸入。**本段原生直接確認 `0x4B2190` 是外層含長度 gate 與 subtype 跳表的 handler，且被 `0x4ADF3D` 註冊至分派表 `handlerTable+0x214`；資料輸入取自 `[EBP+8]` 指標，第二參數 `[EBP+0xC]` 是可用長度候選。** 這是先前未知的 producer/handler-registration 實質關係，並非只盤點相同 helper。分派表是否是 T02 network receive wire opcode table、slot 索引與完整協定 framing **尚未證實**。

## 第一輪：handler registration 與函式參數

- `0x4ADF3D: mov dword ptr [eax+0x214],0x4B2190` 並且 `0x4ADF47: mov [eax+0x218],ecx`；同片段 `+0x20C` 為 `0x4B2310`，`+0x1C4` 為 `0x4B1BF0`。因此 0x4B2190 並非沒有上游；它被寫入 callback/handler table。`eax` 的完整 allocation、分派索引與真正接收入口需另證。
- 精確 4-byte little-endian `0x004B2190` 在 BIN 全域有 1 個命中：0xad343；其唯一命中落在 immediate 指令 `0x4ADF43`，故用 direct `E8` call 掃描找不到並不能否定註冊。
- `0x4B2190` 標準 prologue、結尾 `ret 0xC`，三參數 handler 形式（尚未為各參數冠名）；`0x4B21C3 mov esi,[ebp+8]`，再 `lea eax,[esi+4]`，先保存 input+4。`0x4B21FD movsx esi,word [esi+2]` 並傳到 `0x500110`，用另一個輸入 16-bit key 作前置處理。
- `0x4B220B mov edi,[ebp+0xC]`，`cmp edi,4; jbe 0x4B22C6`；輸入長度<=4 的路徑退出。這僅為本地 handler gate，尚不能當作 wire packet 的最小幀長。
- `0x4B2218` 取暫存 input+4；`0x4B221C movzx ecx,byte [eax+1]`，`dec ecx; cmp ecx,10; ja 0x4B22C6`，然後 `jmp [ecx*4+0x4B22E0]`。subtype 的數值範圍依此為 1..11；未知/不合範圍走結束分支。

## 第二輪：11-entry 跳表實際變長與 writer 資料來源

`0x4B22E0` raw `0x000B16E0` 是 11 個 DWORD 目標：

| subtype `[input+5]` | jump target | 附加長度（在當次基礎 4 之上） | 類別界線 |
|---:|---|---|---|
| 1 | `0x004B2238` | 15 | 本地格式分支，非已知 Quest state |
| 2 | `0x004B2258` | 11 | 本地格式分支，非已知 Quest state |
| 3 | `0x004B2238` | 15 | 本地格式分支，非已知 Quest state |
| 4 | `0x004B2240` | 13 | 本地格式分支，非已知 Quest state |
| 5 | `0x004B2258` | 11 | 本地格式分支，非已知 Quest state |
| 6 | `0x004B2240` | 13 | 本地格式分支，非已知 Quest state |
| 7 | `0x004B2248` | 10 | 本地格式分支，非已知 Quest state |
| 8 | `0x004B2248` | 10 | 本地格式分支，非已知 Quest state |
| 9 | `0x004B2250` | 9 | 本地格式分支，非已知 Quest state |
| 10 | `0x004B22C6` | 直接退出（不進入 writer） | 本地格式分支，非已知 Quest state |
| 11 | `0x004B2258` | 11 | 本地格式分支，非已知 Quest state |

**關鍵數據路徑**：branch `add eax,N; add ebx,N` → `0x4B225E` 暫存下一筆 cursor → `0x4B2262 cmp ebx,edi` 檢查累計長度，超出則 `0x6EDB60` 通報/處理（不假定例外可返回或仍安全）；`0x4B2273 cmp byte [esi],9` 命中特定標誌時回到 `0x4B2210`；其他情況在 `0x4B22AA` 取得 `[ebp+8]+2` 的 signed 16-bit key 與 `[FAB134]` owner，最後 `0x4B22B6 mov esi,[esp+14]` 恢復本筆輸入指標，`0x4B22BC call 0x53D840`。因此 writer ESI 來自本筆 handler input 切片而非 QuestInfo 靜態表。

`0x53D840` 以 `word [esi+4]` 查找 record key，找不到就擴增 0x18-byte 陣列，更新 `record+0x14`（外層 key）、`+0x04`（subtype byte）、`+0x00`、`+0x02`、`+0x0A`、`+0x10`、`+0x0B`。`input[0]==2` 有 `record+0=0xFF` 的覆蓋分支；其子類型 jump table `0x53DA48` 尚需後續完全追查。不能由此直接命名 quest accept/finish。

### 有界偽碼（不代表線上協定）

```cpp
void Handler_4B2190(const uint8_t* data, unsigned available, void* arg3) {
    // 附帶 lazy initialization 和 0x500110(data[2:4]) 前置；省略與本問題無關細節
    if (available <= 4) return;
    unsigned consumed = 4;
    const uint8_t* cursor = data + 4;
    for (;;) {
        unsigned subtype = cursor[1];
        if (subtype < 1 || subtype > 11) return;
        int extra = subtype_extra[subtype];
        if (extra < 0) return;
        const uint8_t* entry = cursor;
        cursor += extra;
        consumed += extra;
        if (consumed > available) { report_error_6EDB60(); /* termination unknown */ }
        if (entry[1] == 9) continue; // ESI = entry+1 from 0x4B2220
        UpdateRecord_53D840(global_FAB134, (int16_t)read_u16(data+2), entry);
    }
}
```

**偽碼限制**：編譯器真實迴圈條件在 `0x4B2273` 使用 `ESI`（本項 `entry+1`），故比較的是 `entry[1]==9`；不能用這段推導合法 payload 長度或安全性。嚴格採用下方原生組語，且 `0x6EDB60` 的效果未完整解析。外部呼叫者是否含某種已解碼 header unknown。

## 三輪門檻紀錄

- `T16-102` 第 1 輪：原生 BIN 找到 `0x4ADF3D` 的具體 handler-table registration；證明 0x4B2190 上游與 input gate，已取得重大新證據。
- `T16-102-2` 第 2 輪：沿 `0x4B2190` jump table 實際 raw 11 entries、各分支長度、forward input pointer 到 `0x53D840`；形成比前段更完整的有界功能鏈。
- `T16-102-3`：未啟動，原因是前兩輪已達 02 共用的重大新發現門檻；並非聲稱 Quest S→C 已閉合。

## 玩家情境 × C→S × S→C × Client state/UI × Server 待開發

| 情境 | Client gate | C→S | S→C | 已證本地影響 | 待開發／unknown |
|---|---|---|---|---|---|
| 某處將 callback 表配置並登記 | `+0x214 = 0x4B2190` | unknown | handler domain 尚未證明 | handler 入口已註冊 | 完整 dispatcher 語意待驗 |
| 任一三參數資料回呼 | `available > 4`、subtype 1..11 | unknown | **wire opcode/長度 unknown** | 由 `0x53D840` 寫 `[FAB134]` 下的 runtime 記錄 | 缺 receive→decode→handler 註冊槽的線路 |
| NPC 任務可接列表過濾 | `0x500E00` 檢查 runtime record | unknown | 尚未證明該記錄來自 wire | 靜態資料與 runtime 記錄比較（已證） | UI/Quest 15/16 映射待證 |
| Quest16 完成 → Quest15 顯示／接取 | unknown | unknown | unknown | 未閉合 | 原版 Server 裁決為相容開發責任 |

## 反證與分工

1. `0x4ADF3D` 確認 callback registration，**不等於已確認真正的 S→C wire opcode**。需找到使用表 `+0x214` 的 dispatcher，驗證其索引／參數來自 socket frame；callback table slot 偏移不直接等於協定數值。
2. `0x4B2190` 三參數與 `ret 0xC` 不保證有可回復的 wire length；不能拿本地 `0x4B22E0` subtype table 作原版 Server 規則。
3. 此 `[FAB134]` owner 與 Quest XML global `[FB114C]` **不同**；只驗證了本地過濾依賴，不證明任務進度資料唯一來源。
4. 保留 T02 封包框架及 T16 分工界線；未變更其他 Task、owner/catalog。原始 Client 唯讀，無執行／patch。

## T16-103 建議

優先追 `0x4ADF3D` 所寫的 handler table owner 與 `+0x214` 的實際使用者，嚴格驗證 dispatcher 索引是否來自 S→C framing；將已知 `0x4B2190` runtime record writer 連到真正 network source，再追 `0x500E00` 更新 NPC/UI 的時序。若有其他 handler type 可能表示 Quest 項目，不可從分支編號猜。

## 可重現的原始 BIN Assembly

每個片段以 `objdump` 對實際 `Tartaros.bin` raw（VA offset=`0x400C00`）輸出，**注意**從函式中間切片可能存在失配指令；以下從精確已定位指令邊界開始。

### handler registration VA `0x004ADECD` raw `0x000AD2CD`

```asm
  4adecd:	c7 80 0c 01 00 00 d0 	mov    DWORD PTR [eax+0x10c],0x4b2cd0
  4aded4:	2c 4b 00 
  4aded7:	89 88 10 01 00 00    	mov    DWORD PTR [eax+0x110],ecx
  4adedd:	c7 80 14 01 00 00 40 	mov    DWORD PTR [eax+0x114],0x4b3040
  4adee4:	30 4b 00 
  4adee7:	89 88 18 01 00 00    	mov    DWORD PTR [eax+0x118],ecx
  4adeed:	c7 80 34 01 00 00 60 	mov    DWORD PTR [eax+0x134],0x4b3060
  4adef4:	30 4b 00 
  4adef7:	89 88 38 01 00 00    	mov    DWORD PTR [eax+0x138],ecx
  4adefd:	c7 80 ec 08 00 00 60 	mov    DWORD PTR [eax+0x8ec],0x4b3060
  4adf04:	30 4b 00 
  4adf07:	89 88 f0 08 00 00    	mov    DWORD PTR [eax+0x8f0],ecx
  4adf0d:	c7 80 44 01 00 00 d0 	mov    DWORD PTR [eax+0x144],0x4b1bd0
  4adf14:	1b 4b 00 
  4adf17:	89 88 48 01 00 00    	mov    DWORD PTR [eax+0x148],ecx
  4adf1d:	c7 80 a4 01 00 00 90 	mov    DWORD PTR [eax+0x1a4],0x4b3090
  4adf24:	30 4b 00 
  4adf27:	89 88 a8 01 00 00    	mov    DWORD PTR [eax+0x1a8],ecx
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00     	mov    DWORD PTR [eax+0x210],ecx
```

### handler prologue + bounds + subtype VA `0x004B2190` raw `0x000B1590`

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
```

### handler writer call + epilogue VA `0x004B2278` raw `0x000B1678`

```asm
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
  4b22d6:	5b                   	pop    ebx
  4b22d7:	8b e5                	mov    esp,ebp
  4b22d9:	5d                   	pop    ebp
  4b22da:	c2 0c 00             	ret    0xc
```

### record writer key and fields VA `0x0053D840` raw `0x0013CC40`

```asm
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff       	jmp    DWORD PTR [ecx*4+0x53da48]
```

### Jump table raw DWORD

```
004B2238 004B2258 004B2238 004B2240 004B2258 004B2240 004B2248 004B2248 004B2250 004B22C6 004B2258
```