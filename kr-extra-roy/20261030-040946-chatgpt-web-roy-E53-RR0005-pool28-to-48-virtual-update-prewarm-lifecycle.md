# E53 — RR-0005／KR T02：Pool+28→+48 關閉追蹤轉移、Client vtable callback、3 個預建 Conn 與接收 gate 初始值（大型 BIN-first）

- **原稿建立時間（Asia/Taipei）**：`2026-10-30T04:09:46+08:00`；作者 `chatgpt-web roy`；**正式段號 E53**，下列 E53.x 只是同份報告的問題單元。
- **原件**：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE32 i386。原始檔唯讀，未執行、附加、patch、封包擷取。
- **Git 開工基準**：main=`eadabf33f31da542db32ddf1d10cabea5a020ea4`、extra/roy1=`8cf7693d26d813aa87d5aed19a90af4b148149dd`。GitHub `compare main...extra` ahead=1/behind=0；**main 已為 extra 的祖先，沒有需新增的 merge commit**。當次使用者明確授權 main→extra merge，未授權本段 E53 原稿自動 Push。
- **RR-0005**：main `ACTIVE/CLAIMED`，actor=`chatgpt-web roy`，branch=`extra/roy1`，submission=null；本次沒有改 RR 台帳或其他 Task。
- **來源層級**：N=原生 PE/bytes/正確基本塊指令直接證據；C=指定前提的靜態資料流推導；U=尚未證明/動態並發或真正 wire unknown。`Pool/Conn/Client/Manager` 都是暫名，`+offset` 必須標記 base。
- **既有依據**：extra/roy1 E50（map replacement/Pool/atomic）；E51（Conn close/Pool/WSASend-WSARecv）；E52（queue flush/reuse throttle/IOCP）；main T02 README, RR inbox/registry, verified-knowledge。E50–E52 **是來源筆記，不等同 T01 FULL-PASS**。

## 當段主要突破及批次規則

**N：找到 E50–E52 都未閉合的第三條 `Pool+0x48` producer**：`0x490FE0` 是 Client subobject vtable `0xC05AA4+0x30` 指向的入口。它在持有 Pool mutex 時掃 Pool+28；對條件成立的 Conn 執行 `Pool+44--`、`Pool+48` 插入、`Pool+4C++`、`Conn+14=0`，**再**調用 `0x805B40`，令 Pool+28 追蹤節點移除、Pool+48 按 `A0B8==0` 回到 reuse vector。前段僅觀察到 close→Pool+28 與 fail/teardown→Pool+48，這次補上了有界的正常 close 後 downstream。

**N：Pool 冷建構先把 +38/+3C/+40 全設零，`0x8046D2` 在 network manager 建立前調 `0x805720` 預建三個 Conn**，每一個都從 Pool 的同一三欄複製零，放入 reuse vector。這收窄 E52 對 fresh vs reused gate 不對稱的推論：結構 CFG 不對稱是事實，但**預設 Pool 設定為零**，實際是否出現非零 gate 需找其它 writer 或執行期證據。

**研究限制**：本次未取得 live trace，不能宣稱同 key reconnect 必然正確閉合、socket 不會 leak、連線能玩、Server 已回覆，亦不推升 RR/S00/T01 狀態。

## E53.1 — PE/section/hash/既有主張的對照與必要勘誤

**研究問題**：E52 對 Pool+28 清理是消極觀察，是否漏了 Client 主循環到 Pool+48 的明確正向 producer？

原件 `.text` raw=VA−`0x400C00`；`.rdata` raw=VA−`0x401A00`，兩個 section 不能混用。針對 `0x490FE0` / `0x805B40` / `0x805720` / `0x805460` 都重讀原件並核對 caller 指令。E50 E51 E52 對 Pool+48 的兩條 producer（Connect fail、Manager 析構）**仍成立但非全集**；新增第三條 `0x49117C–0x4911B7`。E51 對 Conn+14 清零的三種來源亦須追加此第四種。

方法：從已知函式進入；裸 `0xE8` displacement 掃描僅列候選，對 `0x490FE0` **沒有 direct E8** 並非其未被呼叫。原件 `.rdata` vtable 指標能給出間接入口。符合證據分級 N；實際 runtime call frequency U。

## E53.2 — Pool singleton 的確切 base 與冷建構 +38/+3C/+40=0

**N**：`0x49B070` 從 `[FBA858]` 取 Pool 單例，不存在時由 `0x49AF60`／`0x49B000` 建構 `0xFC1208`；`0x49AF9F`、`0x49B041` 呼叫 `0x805460`。在 `0x805460` 中，傳入的 `ESI=Pool*`：`0x805515..51B` 三個連續 store 清 `Pool+38/+3C/+40`；`0x805512` 設 Pool+34 mutex；Pool+28/+48 各建 sentinel list。

這是這三個參數的**原生初始值零**，不是從外部預設值猜測。`0x805720` 和 fresh allocation 只讀這三欄並 copy。此次沒有驗證**全部時間與別名**無其它 writer，所以不得宣稱系統永遠不會啟用 throttle；要將 `default=0` 與 `never changes` 區分。

**原生 `.text` 組譯**：VA `0x0049AF83–0x0049AFEA`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  49af83:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  49af8a:	75 25                	jne    0x49afb1
  49af8c:	83 0d 00 12 fc 00 01 	or     DWORD PTR ds:0xfc1200,0x1
  49af93:	68 08 12 fc 00       	push   0xfc1208
  49af98:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  49af9f:	e8 bc a4 36 00       	call   0x805460
  49afa4:	68 70 e6 bc 00       	push   0xbce670
  49afa9:	e8 6c 73 3f 00       	call   0x89231a
  49afae:	83 c4 04             	add    esp,0x4
  49afb1:	c7 05 58 a8 fb 00 08 	mov    DWORD PTR ds:0xfba858,0xfc1208
  49afb8:	12 fc 00 
  49afbb:	c7 45 f0 08 12 fc 00 	mov    DWORD PTR [ebp-0x10],0xfc1208
  49afc2:	68 08 12 fc 00       	push   0xfc1208
  49afc7:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  49afce:	e8 8d a4 36 00       	call   0x805460
  49afd3:	68 50 af 49 00       	push   0x49af50
  49afd8:	e8 3d 73 3f 00       	call   0x89231a
  49afdd:	83 c4 04             	add    esp,0x4
  49afe0:	c7 05 5c a8 fb 00 00 	mov    DWORD PTR ds:0xfba85c,0x0
  49afe7:	00 00 00 
```

**原生 `.text` 組譯**：VA `0x0049B022–0x0049B063`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  49b022:	b8 01 00 00 00       	mov    eax,0x1
  49b027:	84 05 00 12 fc 00    	test   BYTE PTR ds:0xfc1200,al
  49b02d:	75 24                	jne    0x49b053
  49b02f:	09 05 00 12 fc 00    	or     DWORD PTR ds:0xfc1200,eax
  49b035:	68 08 12 fc 00       	push   0xfc1208
  49b03a:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  49b041:	e8 1a a4 36 00       	call   0x805460
  49b046:	68 70 e6 bc 00       	push   0xbce670
  49b04b:	e8 ca 72 3f 00       	call   0x89231a
  49b050:	83 c4 04             	add    esp,0x4
  49b053:	c7 05 58 a8 fb 00 08 	mov    DWORD PTR ds:0xfba858,0xfc1208
  49b05a:	12 fc 00 
  49b05d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  49b060:	64 89 0d     	mov    DWORD PTR fs:0x0,ecx
```

**原生 `.text` 組譯**：VA `0x008054CE–0x00805546`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  8054ce:	6a 0c                	push   0xc
  8054d0:	89 5e 2c             	mov    DWORD PTR [esi+0x2c],ebx
  8054d3:	e8 90 bd 08 00       	call   0x891268
  8054d8:	83 c4 04             	add    esp,0x4
  8054db:	3b c3                	cmp    eax,ebx
  8054dd:	0f 84 94 00 00 00    	je     0x805577
  8054e3:	89 46 28             	mov    DWORD PTR [esi+0x28],eax
  8054e6:	89 00                	mov    DWORD PTR [eax],eax
  8054e8:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  8054eb:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  8054ee:	6a 18                	push   0x18
  8054f0:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  8054f4:	e8 6f bd 08 00       	call   0x891268
  8054f9:	8b f8                	mov    edi,eax
  8054fb:	83 c4 04             	add    esp,0x4
  8054fe:	3b fb                	cmp    edi,ebx
  805500:	74 0e                	je     0x805510
  805502:	68 a0 0f 00 00       	push   0xfa0
  805507:	57                   	push   edi
  805508:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  80550e:	eb 02                	jmp    0x805512
  805510:	33 ff                	xor    edi,edi
  805512:	89 7e 34             	mov    DWORD PTR [esi+0x34],edi
  805515:	89 5e 38             	mov    DWORD PTR [esi+0x38],ebx
  805518:	89 5e 3c             	mov    DWORD PTR [esi+0x3c],ebx
  80551b:	89 5e 40             	mov    DWORD PTR [esi+0x40],ebx
  80551e:	89 5e 44             	mov    DWORD PTR [esi+0x44],ebx
  805521:	6a 0c                	push   0xc
  805523:	89 5e 4c             	mov    DWORD PTR [esi+0x4c],ebx
  805526:	e8 3d bd 08 00       	call   0x891268
  80552b:	83 c4 04             	add    esp,0x4
  80552e:	3b c3                	cmp    eax,ebx
  805530:	74 21                	je     0x805553
  805532:	89 46 48             	mov    DWORD PTR [esi+0x48],eax
  805535:	89 00                	mov    DWORD PTR [eax],eax
  805537:	8b 46 48             	mov    eax,DWORD PTR [esi+0x48]
  80553a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  80553d:	8b c6                	mov    eax,esi
  80553f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805542:	64 89 0d 00    	mov    DWORD PTR fs:0x0,ecx
```

## E53.3 — 0x8046D2 啟動前預建 Conn：來源、數量與先後順序

**N**：`0x8046AE..CC` 確保 FBA858 Pool 存在；`0x8046D1 push eax; 0x8046D2 call 0x805720` 在 `0x8046D7` network manager `0x5C` 配置及 `0x8046F7` 設 vtable 之前。`0x805720` 在 `0x805755` 將計數初值 0，`0x805762` 配置 `0xA0D8` byte Conn，`0x80577A` constructor，`0x805792/79B/7A4` copy Pool 三欄到 Conn 的 A0C8/CC/D0，存入 Pool+10 容器，`0x80581E` 增 Pool+20，再 `0x8058E1–EEC` 計數到 3 停止。後續 `0x8058F2` unlock mutex。

**C**：建構成功且沒有異常時，此池在 manager 啟動時已有三個**預先配置、尚無 TCP socket 的 Conn 物件**。這既不是「三個成功連線」，也不是三個角色選擇槽；初始化只是 memory pool。

**反證／界線**：E52 把 `0x805950` 的路徑叫 fresh / reused 是程式分支分類；然而第一次真正 Connect 很可能先消耗這三個 prewarm items，不能把預熱 items 歸到 `fresh allocation branch`。配置失敗／早期例外未證永遠能達三個。

**原生 `.text` 組譯**：VA `0x008046AE–0x0080471F`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
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
```

**原生 `.text` 組譯**：VA `0x00805748–0x008057B0`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805748:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80574b:	8b 43 34             	mov    eax,DWORD PTR [ebx+0x34]
  80574e:	50                   	push   eax
  80574f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805755:	33 f6                	xor    esi,esi
  805757:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  80575a:	eb 06                	jmp    0x805762
  80575c:	8d 64 24 00          	lea    esp,[esp+0x0]
  805760:	33 f6                	xor    esi,esi
  805762:	68 d8 a0 00 00       	push   0xa0d8
  805767:	e8 fc ba 08 00       	call   0x891268
  80576c:	83 c4 04             	add    esp,0x4
  80576f:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805772:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805775:	3b c6                	cmp    eax,esi
  805777:	74 0d                	je     0x805786
  805779:	50                   	push   eax
  80577a:	e8 21 05 00 00       	call   0x805ca0
  80577f:	8b d0                	mov    edx,eax
  805781:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  805784:	eb 05                	jmp    0x80578b
  805786:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  805789:	8b d6                	mov    edx,esi
  80578b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805792:	8b 43 38             	mov    eax,DWORD PTR [ebx+0x38]
  805795:	89 82 c8 a0 00 00    	mov    DWORD PTR [edx+0xa0c8],eax
  80579b:	8b 4b 3c             	mov    ecx,DWORD PTR [ebx+0x3c]
  80579e:	89 8a cc a0 00 00    	mov    DWORD PTR [edx+0xa0cc],ecx
  8057a4:	8b 43 40             	mov    eax,DWORD PTR [ebx+0x40]
  8057a7:	8d 7b 10             	lea    edi,[ebx+0x10]
  8057aa:	89 82 d0 a0 00 00    	mov    DWORD PTR [edx+0xa0d0],eax
```

**原生 `.text` 組譯**：VA `0x008057F1–0x00805829`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  8057f1:	6a 10                	push   0x10
  8057f3:	e8 70 ba 08 00       	call   0x891268
  8057f8:	83 c4 04             	add    esp,0x4
  8057fb:	85 c0                	test   eax,eax
  8057fd:	0f 84 12 01 00 00    	je     0x805915
  805803:	8b 4b 14             	mov    ecx,DWORD PTR [ebx+0x14]
  805806:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  805809:	89 04 b9             	mov    DWORD PTR [ecx+edi*4],eax
  80580c:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  80580f:	8b 0c b8             	mov    ecx,DWORD PTR [eax+edi*4]
  805812:	83 e6 03             	and    esi,0x3
  805815:	8d 34 b1             	lea    esi,[ecx+esi*4]
  805818:	85 f6                	test   esi,esi
  80581a:	74 02                	je     0x80581e
  80581c:	89 16                	mov    DWORD PTR [esi],edx
  80581e:	ff 43 20             	inc    DWORD PTR [ebx+0x20]
  805821:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  805824:	8d 4d f0             	lea    ecx,[ebp-0x10]
  805827:	3b c8                	cmp    ecx,eax
```

**原生 `.text` 組譯**：VA `0x008058DE–0x00805912`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  8058de:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  8058e1:	83 43 04 04          	add    DWORD PTR [ebx+0x4],0x4
  8058e5:	40                   	inc    eax
  8058e6:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  8058e9:	83 f8 03             	cmp    eax,0x3
  8058ec:	0f 8c 6e fe ff ff    	jl     0x805760
  8058f2:	8b 4b 34             	mov    ecx,DWORD PTR [ebx+0x34]
  8058f5:	51                   	push   ecx
  8058f6:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8058fc:	b8 01 00 00 00       	mov    eax,0x1
  805901:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  805904:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  80590b:	59                   	pop    ecx
  80590c:	5f                   	pop    edi
  80590d:	5e                   	pop    esi
  80590e:	5b                   	pop    ebx
  80590f:	8b e5                	mov    esp,ebp
  805911:	5d                   	pop    ebp
```

## E53.4 — 正式建立 E51/E52 缺失的 Client vtable 入口 `0x490FE0`

**原始 `.rdata` 結構 N**：檔案 raw `0x8040A4`（`.rdata` VA = raw + `0x401A00`）包含指標 `0x0049ADE0`，由指令 `0x48ACA6 mov [ESI],0xC05AA4` / `0x48B1BE mov [ESI+8],0xC05AA4` 可把此表連到 Client 相應子物件。raw `0x8040D4` = VA `0xC05AD4` 內容值 `0x00490FE0`，相對 vtable base `+0x30`。

可證**方法身分**：在 Client 子物件（例如 `Client+8` 對應 vptr `0xC05AA4`）的 vtable `+0x30` 方法指向 `0x490FE0`。這是 native pointer content，不靠 E8 掃描；該函式的上游 virtual caller 與實際 tick frequency 仍 U。

注意 `Client+8` vptr 和 `Manager` vptr `0xC51748` 完全不同，不能因都是網路關聯就混用 `+0x30` 或 `+0x24`。

**原生 `.text` 組譯**：VA `0x0048AC9A–0x0048ACCB`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	5b c0 00 
  48acb6:	89 9f 60 bf 00 00    	mov    DWORD PTR [edi+0xbf60],ebx
  48acbc:	89 9f 64 bf 00 00    	mov    DWORD PTR [edi+0xbf64],ebx
  48acc2:	89 9f 68 bf 00 00    	mov    DWORD PTR [edi+0xbf68],ebx
  48acc8:	89 9f 6c       	mov    DWORD PTR [edi+0xbf6c],ebx
```

**原生 `.text` 組譯**：VA `0x0048B1B8–0x0048B1DA`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  48b1b8:	c7 06 9c 5a c0 00    	mov    DWORD PTR [esi],0xc05a9c
  48b1be:	c7 46 08 a4 5a c0 00 	mov    DWORD PTR [esi+0x8],0xc05aa4
  48b1c5:	c7 86 48 01 00 00 ec 	mov    DWORD PTR [esi+0x148],0xc05aec
  48b1cc:	5a c0 00 
  48b1cf:	c7 86 00 02 00 00 04 	mov    DWORD PTR [esi+0x200],0xc05b04
  48b1d6:	5b c0 00 
  48b1d9:	c7       	mov    DWORD PTR [ebp-0x4],0x6
```

**原生 `.text` 組譯**：VA `0x00490FE0–0x00491029`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

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
```

## E53.5 — Pool+28 traversal 的 gate：`Conn+A0AC` 非零才加入轉移

**N**：`0x491045` 以 `[Pool+34]` lock；`0x491071` 取 Pool+28 list sentinel；從 `[node+8]` 取 `Conn*` `EBX`；`0x49108F` 比較 `Conn+A0AC` 與零。`==0` 時透過 `0x491097` 直接迭代下一節點；`!=0` 才走 `0x4910A2` 可選 callback 與 `0x49117C` producer。

`0x805950` reuse branch 在 `0x8059F3` 設 Conn+A0AC=1；fresh `0x805A54` 亦寫 1；`0x805F50` reset 在 `0x805F5B` 寫零。故 A0AC 的**有界角色**是 lease/in-use 旗標，不能直接說是 `Conn+14` 的 refcount。

**C**：正常 close 只入 Pool+28 並不代表所有其中 Conn 都會移入 Pool+48；本輪還取決於 A0AC 是否非零、虛方法是否被執行。不能將 Pool+28 list 的每個元素無條件轉移。

**原生 `.text` 組譯**：VA `0x00491020–0x004910A2`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
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
```

**原生 `.text` 組譯**：VA `0x008059E9–0x008059FC`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
```

**原生 `.text` 組譯**：VA `0x00805A49–0x00805A5E`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
```

**原生 `.text` 組譯**：VA `0x00805F50–0x00805F70`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
```

## E53.6 — `Client+BF58` match 只控制回呼，不控制 Pool+48 轉移

**N**：`0x491020` 將 `[EBP+8]` 保存為方法的 caller argument；`0x4910BE` 取它、`0x4910C5` 將 `[arg+0xBF58]` 和掃到的 `EBX=Conn*` 比較。`!=` 直接跳到 `0x49111D`；若相等，依 `0xFBACD0` lazy-init `0xFBACD4`，`0x491111` 取其 vtable `+0x10` 並以 `push 1` 呼叫。兩種情況之後**都流向 `0x49111D`**，繼續重新載入 Pool 並進行轉移。

**結論 N**：Client/arg 上的 BF58 比對是額外通知的條件，**不是**「是否從 Pool+28 進 Pool+48」的唯一 gate。實際回呼對 UI/業務的作用、`arg+BF58` 的完整 writer/source 仍 U；`+BF58` 不等於已知的 `Client+BF60`。

**C**：以這個 guard 並不能推稱 Server 已看到 disconnect、callback 已轉換 UI，或連線角色必然是 key0/key2。

**原生 `.text` 組譯**：VA `0x004910A2–0x0049111D`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
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
  4910cd:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4910d4:	75 35                	jne    0x49110b
  4910d6:	09 3d d0 ac fb 00    	or     DWORD PTR ds:0xfbacd0,edi
  4910dc:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4910e3:	89 35 d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,esi
  4910e9:	e8 12 52 24 00       	call   0x6d6300
  4910ee:	68 70 d6 bc 00       	push   0xbcd670
  4910f3:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4910f8:	e8 1d 12 40 00       	call   0x89231a
  4910fd:	83 c4 04             	add    esp,0x4
  491100:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491107:	ff ff ff ff 
  49110b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491111:	3b ce                	cmp    ecx,esi
  491113:	74 08                	je     0x49111d
  491115:	8b 11                	mov    edx,DWORD PTR [ecx]
  491117:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  49111a:	57                   	push   edi
  49111b:	ff d0                	call   eax
```

## E53.7 — 第三條 Pool+48 producer：`0x49117C` 的原生寫入者全鏈

**N／主突破**：在 Pool+28 遍歷到 A0AC!=0 的 Conn 後，`0x49117C` `dec [Pool+44]`，`0x49117F` 取 `Pool+48` list sentinel，`0x491193 call 0x74D700` 插新節點，`0x4911A7` 增 `Pool+4C`、`0x4911AB..B1` 完成雙向 list insertion，`0x4911B7 mov [Conn+14],0`，`0x4911BE..CE` 選取下一個 Pool+28 node。**本片段沒有 `shutdown` 或 `closesocket` 呼叫**。

E50/E51 的 producer 已有：`0x805AF0`（connect/setsockopt fail）；`0x8066A0`（manager destructor inline）。第三條**不是**其中兩條的 direct caller，而是 Client 子物件虛方法內聯的 Pool+28→+48 promotion。

**更正**：E51 的 Conn+14 clear-writer inventory 缺少 `0x4911B7`，不能再將 `0x805F6D`、`0x805B30`、`0x806778` 寫成已知全部。所有 writer/別名仍未保證完全窮盡。

**原生 `.text` 組譯**：VA `0x0049111D–0x004911D6`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  49111d:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491122:	3b c6                	cmp    eax,esi
  491124:	75 56                	jne    0x49117c
  491126:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  49112c:	74 0c                	je     0x49113a
  49112e:	e8 2d 9e 00 00       	call   0x49af60
  491133:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491138:	eb 42                	jmp    0x49117c
  49113a:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  491141:	75 2f                	jne    0x491172
  491143:	09 3d 00 12 fc 00    	or     DWORD PTR ds:0xfc1200,edi
  491149:	68 08 12 fc 00       	push   0xfc1208
  49114e:	89 bc 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],edi
  491155:	e8 06 43 37 00       	call   0x805460
  49115a:	68 70 e6 bc 00       	push   0xbce670
  49115f:	e8 b6 11 40 00       	call   0x89231a
  491164:	83 c4 04             	add    esp,0x4
  491167:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49116e:	ff ff ff ff 
  491172:	b8 08 12 fc 00       	mov    eax,0xfc1208
  491177:	a3 58 a8 fb 00       	mov    ds:0xfba858,eax
  49117c:	ff 48 44             	dec    DWORD PTR [eax+0x44]
  49117f:	8b 78 48             	mov    edi,DWORD PTR [eax+0x48]
  491182:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  491185:	8d 70 48             	lea    esi,[eax+0x48]
  491188:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  49118c:	51                   	push   ecx
  49118d:	52                   	push   edx
  49118e:	57                   	push   edi
  49118f:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  491193:	e8 68 c5 2b 00       	call   0x74d700
  491198:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  49119b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  4911a0:	2b d1                	sub    edx,ecx
  4911a2:	83 fa 01             	cmp    edx,0x1
  4911a5:	72 46                	jb     0x4911ed
  4911a7:	41                   	inc    ecx
  4911a8:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  4911ab:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4911ae:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4911b1:	89 01                	mov    DWORD PTR [ecx],eax
  4911b3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911b7:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  4911be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4911c0:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4911c4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4911c8:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911cc:	33 f6                	xor    esi,esi
  4911ce:	3b c1                	cmp    eax,ecx
  4911d0:	0f 85 b6 fe ff ff    	jne    0x49108c
```

## E53.8 — `0x4911D6→0x805B40` 解開兩 list 的直接循環

**N**：`0x4911D6` 在 Pool+28 迴圈完畢才檢查單例，`0x4911FC` 把 Pool* push，`0x491203 call 0x805B40`。接著 `0x491224..232` unlock Pool+34。

`0x805B40` **第一輪**看 `Pool+28` 所有 node+8 Conn 的 `Conn+14==0`，刪除 Pool+28 追蹤 node 並 Pool+2C--；**第二輪**遍歷 Pool+48，只有 `Conn+A0B8==0` 時才 `0x805F50` reset，向 `Pool+10` free/reuse vector 加入 Conn，移除 Pool+48 node，Pool+4C--。

由此形成有界順序：
```
close-by-Conn → Pool+28 tracking
(Client sub-vtable+30 method 0x490FE0 被呼叫時)
  [Conn+A0AC!=0] → Pool+48 enqueue + Conn+14=0
  → 0x805B40:
       Pool+28 node cleanup if Conn+14==0
       Pool+48 recycle if Conn+A0B8==0 → 0x805F50 → Pool+10 reuse
```

**重要限制 U**：這不是 running UI/game session 時序保證；如果 method 不被呼叫、Pool+28 沒有 A0AC!=0 的 Conn、`A0B8` 非零或存在其他 owner，則不能推出已真正回收/關 socket。

**原生 `.text` 組譯**：VA `0x004911B3–0x0049123A`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  4911b3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911b7:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  4911be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4911c0:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4911c4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4911c8:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911cc:	33 f6                	xor    esi,esi
  4911ce:	3b c1                	cmp    eax,ecx
  4911d0:	0f 85 b6 fe ff ff    	jne    0x49108c
  4911d6:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  4911dc:	75 1e                	jne    0x4911fc
  4911de:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  4911e4:	74 11                	je     0x4911f7
  4911e6:	e8 75 9d 00 00       	call   0x49af60
  4911eb:	eb 0f                	jmp    0x4911fc
  4911ed:	68 34 20 bf 00       	push   0xbf2034
  4911f2:	e8 39 c9 3e 00       	call   0x87db30
  4911f7:	e8 04 9e 00 00       	call   0x49b000
  4911fc:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491202:	52                   	push   edx
  491203:	e8 38 49 37 00       	call   0x805b40
  491208:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49120e:	75 14                	jne    0x491224
  491210:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491216:	74 07                	je     0x49121f
  491218:	e8 43 9d 00 00       	call   0x49af60
  49121d:	eb 05                	jmp    0x491224
  49121f:	e8 dc 9d 00 00       	call   0x49b000
  491224:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491229:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  49122c:	50                   	push   eax
  49122d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  491233:	bf 01 00 00 00       	mov    edi,0x1
  491238:	29 3d        	sub    DWORD PTR ds:0xf7dd78,edi
```

**原生 `.text` 組譯**：VA `0x00805B49–0x00805B90`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
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
```

**原生 `.text` 組譯**：VA `0x00805BA0–0x00805BD0`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
  805bbc:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  805bbf:	8b 57 1c             	mov    edx,DWORD PTR [edi+0x1c]
  805bc2:	83 c7 10             	add    edi,0x10
  805bc5:	03 d0                	add    edx,eax
  805bc7:	f6 c2 03             	test   dl,0x3
  805bca:	75 11                	jne    0x805bdd
  805bcc:	83 c0 04             	add    eax,0x4
  805bcf:	c1               	shr    eax,0x2
```

**原生 `.text` 組譯**：VA `0x00805C1E–0x00805C62`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805c1e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805c21:	89 0b                	mov    DWORD PTR [ebx],ecx
  805c23:	ff 47 10             	inc    DWORD PTR [edi+0x10]
  805c26:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805c29:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  805c2c:	8b 30                	mov    esi,DWORD PTR [eax]
  805c2e:	3b 47 48             	cmp    eax,DWORD PTR [edi+0x48]
  805c31:	74 19                	je     0x805c4c
  805c33:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805c36:	89 32                	mov    DWORD PTR [edx],esi
  805c38:	8b 08                	mov    ecx,DWORD PTR [eax]
  805c3a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  805c3d:	50                   	push   eax
  805c3e:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  805c41:	e8 c6 b5 08 00       	call   0x89120c
  805c46:	83 c4 04             	add    esp,0x4
  805c49:	ff 4f 4c             	dec    DWORD PTR [edi+0x4c]
  805c4c:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805c4f:	eb 05                	jmp    0x805c56
  805c51:	8b 00                	mov    eax,DWORD PTR [eax]
  805c53:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  805c56:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  805c59:	3b 4f 48             	cmp    ecx,DWORD PTR [edi+0x48]
  805c5c:	0f 85 3e ff ff ff    	jne    0x805ba0
```

## E53.9 — 互斥鎖、清理節點與 `A0B8` 並發界線

`0x49104B` 在讀 Pool+28 前鎖 `Pool+34`；掃描、Pool+48 producer 和 `0x805B40` 均落在持鎖範圍，`0x49122D` 釋放。`0x805A80` 被 `0x806FC0` 呼叫時，外層也鎖 Pool+34。此提供 **Pool list 操作順序的一個有界互斥證據**；不能將它當成 Conn/socket/IOCP 的全域 happens-before。

`Conn+A0B8` 的 WSASend InterlockedIncrement/Decrement 前段 E50/E51 已有原生證據，這次透過 consumer `0x805BA6 cmp A0B8,0` 接回 Pool+48。**WSARecv 沒有對 A0B8 增加**，故 A0B8=0 不保證沒有 pending receive 或已取消所有 overlapped I/O。

**明確的安全邊界**：回收重用的 `0x805F50` 會把 Conn socket 欄位寫為 INVALID_SOCKET、清 queue；這不是對所有仍有效 OS socket 自動呼叫 `closesocket` 的證據。若原本 close-by-Conn 已經確實 closesocket，此路徑是正常延後 reuse；同 key replace 舊 Conn 是否走過此路徑未證。

**原生 `.text` 組譯**：VA `0x00491045–0x00491055`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  491045:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  49104b:	8b 41 34             	mov    eax,DWORD PTR [ecx+0x34]
  49104e:	50                   	push   eax
  49104f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
```

**原生 `.text` 組譯**：VA `0x004911FC–0x00491233`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  4911fc:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491202:	52                   	push   edx
  491203:	e8 38 49 37 00       	call   0x805b40
  491208:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49120e:	75 14                	jne    0x491224
  491210:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491216:	74 07                	je     0x49121f
  491218:	e8 43 9d 00 00       	call   0x49af60
  49121d:	eb 05                	jmp    0x491224
  49121f:	e8 dc 9d 00 00       	call   0x49b000
  491224:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491229:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  49122c:	50                   	push   eax
  49122d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
```

**原生 `.text` 組譯**：VA `0x00805BA0–0x00805BBC`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805ba0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  805ba3:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  805ba6:	8b 8e b8 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa0b8]
  805bac:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  805baf:	85 c9                	test   ecx,ecx
  805bb1:	0f 85 9a 00 00 00    	jne    0x805c51
  805bb7:	e8 94 03 00 00       	call   0x805f50
```

**原生 `.text` 組譯**：VA `0x00806FF2–0x0080704A`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

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

## E53.10 — 預設 recv throttle 與 fresh/reuse 差異的嚴格收窄

**N**：`Pool+38/3C/40` 在 cold constructor 三個都為零；預建 `0x805720` 和新建 `0x805950` 各把三個值複製到 `Conn+A0C8/+A0CC/+A0D0`；重用 `0x8059E9→0x805F50` 清零，不 copy。`0x806010` 額外 decoder-fail reset 也清零。`0x8065B0` 在 `Conn+A0C8==0` 時直接返回零，後續 threshold/clock 路徑不走。

**因此**：E52 的『fresh/reuse 具不同 copy 路徑』是 N；『一般連線因而有不同 throttle 生效』不是 N，冷啟動預設條件兩者均為零。只有額外 `Pool+38` 非零 writer 或 Conn 別名直接變更後，才可能顯現異常；目前沒有定位該 writer。

原件 `.text` 針對直接 `Conn+A0C8` 使用之 `DWORD displacement c8 a0 00 00` 只有 `0x805792`、`0x805A2B`、`0x805FEB`、`0x806034`、`0x8065B0` 五個型態候選（列址為指令起點附近，見原生 dump），是**byte pattern 範圍內**的有界觀察；不能排除別名／大塊複製、不同編碼及執行期補丁，亦不以此宣稱零設定永遠不變。

**原生 `.text` 組譯**：VA `0x00805A24–0x00805A5E`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
```

**原生 `.text` 組譯**：VA `0x00805FD0–0x00806050`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
  805fdf:	89 9e c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],ebx
  805fe5:	89 9e c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],ebx
  805feb:	89 9e c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],ebx
  805ff1:	89 9e cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],ebx
  805ff7:	89 9e d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],ebx
  805ffd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  806003:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80600a:	00 00 00 
  80600d:	5b                   	pop    ebx
  80600e:	c3                   	ret
  80600f:	cc                   	int3
  806010:	56                   	push   esi
  806011:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  806017:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  80601e:	00 00 00 
  806021:	e8 ba 03 00 00       	call   0x8063e0
  806026:	33 c0                	xor    eax,eax
  806028:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  80602e:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  806034:	89 86 c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],eax
  80603a:	89 86 cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],eax
  806040:	89 86 d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],eax
  806046:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80604d:	00 00 00 
```

**原生 `.text` 組譯**：VA `0x008065B0–0x0080661C`；raw offset `VA−0x400C00`（此切片使用 section raw 0x400 / VA 0x401000 檢驗）。

```asm
  8065b0:	83 be c8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0c8],0x0
  8065b7:	75 03                	jne    0x8065bc
  8065b9:	33 c0                	xor    eax,eax
  8065bb:	c3                   	ret
  8065bc:	83 be b4 a0 00 00 02 	cmp    DWORD PTR [esi+0xa0b4],0x2
  8065c3:	74 f4                	je     0x8065b9
  8065c5:	8b 86 bc a0 00 00    	mov    eax,DWORD PTR [esi+0xa0bc]
  8065cb:	53                   	push   ebx
  8065cc:	8b 1d d4 22 bd 00    	mov    ebx,DWORD PTR ds:0xbd22d4
  8065d2:	57                   	push   edi
  8065d3:	8d be bc a0 00 00    	lea    edi,[esi+0xa0bc]
  8065d9:	85 c0                	test   eax,eax
  8065db:	75 08                	jne    0x8065e5
  8065dd:	ff d3                	call   ebx
  8065df:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  8065e5:	8b 0f                	mov    ecx,DWORD PTR [edi]
  8065e7:	3b 8e cc a0 00 00    	cmp    ecx,DWORD PTR [esi+0xa0cc]
  8065ed:	7e 21                	jle    0x806610
  8065ef:	6a 00                	push   0x0
  8065f1:	57                   	push   edi
  8065f2:	ff 15 80 22 bd 00    	call   DWORD PTR ds:0xbd2280
  8065f8:	ff d3                	call   ebx
  8065fa:	2b 86 c4 a0 00 00    	sub    eax,DWORD PTR [esi+0xa0c4]
  806600:	3b 86 d0 a0 00 00    	cmp    eax,DWORD PTR [esi+0xa0d0]
  806606:	73 0f                	jae    0x806617
  806608:	5f                   	pop    edi
  806609:	b8 01 00 00 00       	mov    eax,0x1
  80660e:	5b                   	pop    ebx
  80660f:	c3                   	ret
  806610:	57                   	push   edi
  806611:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806617:	5f                   	pop    edi
  806618:	33 c0                	xor    eax,eax
  80661a:	5b                   	pop    ebx
  80661b:	c3                   	ret
```

## E53.11 — E50/E51/E52 修正對照、反證與未證事項

| 前段描述／疑點 | E53 第一手修正 | 等級 |
|---|---|---|
| Pool+48 正向 producer 只有 failure + destructor 能定位 | 新增 `0x49117C..B7` 正常 close-tracking → delayed recycle；前段兩類仍成立，**非全集** | N，限定該虛方法 | 
| 正常 close `Pool+28` 不知道如何進 `Pool+48` | 先由 490FE0 讀 A0AC gate，經 inline insertion，呼叫 805B40 移除 Pool+28 node；回收仍需 A0B8=0 | N/C |
| Conn+14 已知清零 writer 三條 | 新增 `0x4911B7` 清零，且是 remove tracking 的條件來源 | N |
| fresh/reused Conn 因 copy/reset 不對稱所以 receive gate 必然不同 | constructor Pool 三欄 cold=0，預熱 items 也 copy 零；非零 writer U，不能推必然差異 | N＋限制 |
| Pool 首次取得必定為 fresh new | network manager setup 前執行 `0x805720` 建最多 3 筆 reuse candidates | N/C |
| 490FE0 必須有 E8 direct caller 才可視為執行路徑 | `.rdata` `0xC05AD4` 是 Client+8 vtable +0x30 pointer；上游動態頻率 U | N/U |
| Pending SEND counter 為零必然 IOCP 全 drained | `WSARecv` 未見 A0B8+1；這不是 recv completion safety barrier | 反證 N、並發 U |

任何單一路徑未找到 explicit socket close 不能證明全域 socket 泄漏；另外同 key replacement 的 map-node erase 不等於 old Conn close，仍要沿 higher layer caller/owner 補證。

## E53.12 — Client 邊界與 RR-0005 連線、回應階段之有界矩陣

| 情境 | active map / Conn / Pool | 已證原生效果 | 未證與解除條件 |
|---|---|---|---|
| key0/2 新 Connect | Manager map node 映射新的 Conn | `0x806AD0` 成功後 replace map node | 舊 Conn 是否先 close，何時失去最後 owner U |
| key 失敗或 setsockopt fail | 沒插成功 node 的 Conn | `0x805AF0` 加入 Pool+48 | 失敗時 OS socket 是否全部 close，需 socket trace |
| close-by-Conn | Conn may remain in active map | `0x806FC0 → 0x805A80`；socket close (有 gate)，Pool+28 timestamp node | 若 socket 無效或 `A0A8` gate 命中，是否進 Pool+28 需分支化 |
| Client virtual method+30 執行 | Pool+28 扫 leased Conn | `A0AC!=0` → Pool+48 inline + Conn+14=0 | App/Client 實際調用頻率，及 key 身分與時序 U |
| scan pool | Pool+28/48 | `0x805B40` 清 +28 node；A0B8==0 才 reset/reuse +48 | pending recv 是否完成 U |
| key1 轉換／選服 UI | T03 業務與 T02 transport 相接 | E44/E45/E52 條件式鏈 | 同一 session pcap、實際首筆 write/回覆 U |

**Client 待逆向**：`0x490FE0` 虛呼叫者與 tick 輪次，`Client+BF58` 實際 writer、同 key reconnect 舊 Conn last owner、Pool+38/3C/40 非零 writer、Conn+14 非零 writer、失敗 socket close、IOCP與 receive outstanding 安全同步。

**跨功能待整合**：T03 登入 0x0013/0x007A → UI 選服 → key0/1/2 真正產生的封包 → T03 roster/selection 回應同一 session。引用 T03，不能轉移其主責。

**待遊玩驗證**：只有合法 runtime environment 與 packet capture／Socket handle trace 才能確定 OS socket 數、first wire/first Server response、Pool reuse 並發競態。

**Server 待開發**：依已證的 Client framing、host/slot 等契約實作 Server 的相容回應；legacy `0x20E0/0x20DE/0x20DF` 是舊 KR Client 常數，非新部署決策。

## E53.13 — 以 bytes/ABI 可重現的精確覆蓋與 xref 限定

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -h /mnt/data/Tartaros.bin
objdump -p /mnt/data/Tartaros.bin
# below needs .text extracted by PE header instead of applying section bias to IAT
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x490fe0 --stop-address=0x491234 /mnt/data/e51-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x805460 --stop-address=0x805555 /mnt/data/e51-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x805720 --stop-address=0x805913 /mnt/data/e51-text.bin
```

**Direct E8 candidates from full `.text`**：`0x805720` 目前唯一 `0x8046D2`；`0x805460` 相關候選 `0x491155`、`0x49AF9F`、`0x49AFCE`、`0x49B041`、`0x80671B`，但每個要按 caller 起始核對（立即數假陽性可能存在）；`0x805B40` 唯一已見 `0x491203`；`0x490FE0` **0 個 direct E8**，但原件 vtable pointer 完整驗證。這不是間接/虛擬 caller 全集。

**`.rdata` vtable raw pointer**：file raw `0x8040D4`, native little-endian `e0 0f 49 00`，其 VA=`0xC05AD4`，相對已證 `0xC05AA4` vptr +0x30；不可錯用 `.text` VA/raw bias。

## E53.14 — 端到端清理時序 C++ 偽碼（條件式而非原版 source）

```cpp
// 符號只供研究，並非真正 C++ source 或動態時序。
Pool* p = singleton_FBA858();  // static object around FC1208
// p constructor 805460: p->gateEnable=0; p->gateThreshold=0; p->gateWindow=0;
// 8046D2: prewarm(3) allocations of 0xA0D8, each constructor+copy gate defaults.

void ClientSubobjectVirtual30_method_490FE0(ClientArg* arg) {
    lock(p->mutex_34);
    for (Node* n : p->closeTrack_28) {
        Conn* c = n->valueAt8;
        if (c->flagA0AC == 0) continue;
        if (arg->connAtBF58 == c) {
            maybeNotifyLazyObjectVfunc10(/*1*/); // side effect not fully identified
        }
        --p->counter44;
        p->delayedRecycle48.push(c); ++p->count4C;
        c->field14 = 0;
        // n is still in closeTrack_28 until poolSweep called below.
    }
    poolSweep_805B40(p); // +28 remove if field14 == 0;
                        // +48 only reset/reuse when c->pendingSendA0B8 == 0
    unlock(p->mutex_34);
}
```

**約束**：這份 code 壓縮了 vector/list allocator、exception、其他 branch；它僅模擬已核的主路徑，不等於程序必定每 frame 呼叫，也不證明 pool sweep 可以安全解決未計入 A0B8 的 recv I/O。所有 callback/輸入狀態仍需核對。

## E53.15 — 停止、剩餘缺口與 E54 指定入口

**本次重大新發現已符合共用 02 的單段結束門檻**：原始 BIN 與 vtable 證據閉合了先前未見的 Pool+28→+48 正向 producer 與 `0x805B40` 消費者關係；另取得 Pool 預建三筆、預設 gate 全零的直接證據。此處結束的是**正式 E53**，不是停止 RR 研究或聲稱 Client 完全驗收。

E54 優先：1) 動態 vtable `0xC05AA4+0x30` 的 owner/callers 及 `[arg+BF58]` 寫入者與 client state；2) 原生 close→shutdown→Pool 的所有分支，判定 same-key 替換舊 Conn 如何進 `Pool+28` 以及 key-map 身分；3) Pool+38/3C/40 在此版本是否有其它非零 setter 或配置導入；4) 針對 abort/WSARecv pending rearm 與 `A0B8==0` recycle 的 alias race 建立具體測試契約；5) 真正 C2S 首包／S2C 首回覆必須由合法原生封包佐證，不造包猜測。

**Git 狀態**：本輪只做 main→extra ancestor/merge 判定（已同步）；**E53 原稿僅在本地，無使用者本輪明確指示，不 Commit/Push、不變更 RR 唯一台帳**。E51、E52 均已在 extra/roy1 完整保留。
