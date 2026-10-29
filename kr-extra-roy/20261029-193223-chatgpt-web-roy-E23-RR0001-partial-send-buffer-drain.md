# E23 — RR-0001/0004：IOCP 送出完成後部分資料消費、緩衝移動與 next-send gate

時間：2026-10-29T19:32:23+08:00
原始 KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，已重新校驗。反組譯 raw/VA 偏移 `VA=raw+0x400C00`；沒有執行或修改 Client。以 extra/roy1 E22 為上游，T02 RR-0001、0004 的跨 Task 補證，不宣稱已認領/提交 S00。

## 第一輪：0x8077B0 為「消耗已完成 byte count」的 in-place 緩衝前移，含重要 bool 反例

此函式使用非標準寄存器 ABI：`ESI=&connection+0x501C`、`EDI=completedBytes`，所以結構內 `+0x500C` 對應 connection `+0xA028`，`+0x5004` 對應 connection `+0xA020`。起點 `0x8077B0` 取 `lock=*ESI`。

* `0x8077BA`：`EDI < 0` 拒絕。
* `0x8077BE..0x8077C6`：讀 buffered count `ESI+0x500C`；`count < completedBytes` 拒絕。
* `0x8077C8..0x8077CA`：更新 remaining=`count-completedBytes`，寫回。
* remaining非零：`0x8077D2..0x8077ED` 將 write/end pointer 回退 completedBytes，檢查範圍 `ESI+4 <= newTail < ESI+0x5004`；`0x8077EF` 更新尾指標；`0x8077F1..0x8077FD` 計算剩餘有效 bytes，呼叫 `0x89DBD0` 從 `ESI+4+completedBytes` 移至 `ESI+4`（在 `0x89DBD0` 未反編譯前暫稱 memmove-like）；非零剩餘且合法時 `AL=1`。
* remaining 等於 0：`0x807810` 只將 tail 重設為 `ESI+4`，**落至 `0x807819`，`AL=0`**。所以 `AL=0` 不能直接代表「不合法或傳送失敗」，也可能代表正常消耗全數 bytes！同時，invalid/negative/too many bytes 也可能在 AL=0 路徑。原呼叫者 `0x806EA1` 不檢查此 AL，而重新讀剩餘 `connection+A028`。

## 第二輪：完成分支重讀剩餘長度，調節后續排程

`0x806E7D..0x806EC4` 先要求 completion `OVERLAPPED==connection+A050`，再以傳回完成 bytes `ECX` 當 `EDI` 呼叫 `0x8077B0`；但若 `connection+A0AC==0`，則跳過緩衝消耗直接重新評估 `A028`。`0x806EAB..0x806EB4` 將 `(A028>0)` 布林寫入 `byte connection+A024`；`0x806EC4` 再呼叫對 `connection+A0B8` 的計數操作；return 到 completion loop。**這段沒有證明 IOCP worker 立即再呼叫 WSASend。**

`0x804B21` 是另一個送出排程 gate：需 buffered len `A028>0` 且 pending `A0B8<=0`，才呼叫 virtual WSASend。故確實有「完成更新 A024 / A0B8、後續發送排程另處理」的設計；需要追 dispatch caller 如何再次到 `0x804B21`，不能宣稱所有部分送出都立即重試。

### Pseudocode (bounded)

```cpp
// ESI=pointer to staging struct at connection+0x501C, EDI=IOCP completedBytes
bool consume_completed(Staging* s, int transferred) {
  lock(s->mutex);
  if (transferred < 0 || s->count < transferred) { unlock(); return false; }
  s->count -= transferred;
  if (s->count == 0) {
    s->tail = &s->data[0];
    unlock();
    return false; // NOTE: false on normal complete drain!
  }
  // validate tail boundaries, move remaining data to start
  s->tail -= transferred;
  if (!tail_valid) { unlock(); return false; }
  move_like_memmove(s->data, s->data + transferred, s->tail-s->data);
  unlock(); return true;
}
// Parent caller ignores boolean, instead uses (conn->A028 > 0) for conn->A024.
```

**限制**：此偽碼用抽象 `move_like_memmove` 代表 call `0x89DBD0`，不宣稱已證函式使用標準 libc `memmove`。`s->tail` 的合法性和個別地址必以組語為權威。

## 第三輪：連線生命週期的限定結論

`0x804B5C` 發生 virtual send wrapper 返回 0 時，會呼叫 `0x8063E0` flush pending list 並 vtable `+0x24` 執行連線處理；`0x804B7C` 還檢查 `A0B0`，以及 `A0A4 > 0x12C` 等條件呼叫 flush。這些是同一連線局部 send scheduler 的錯誤/節流處理；與 `0x806Dxx` IOCP callback 的效果應分別記錄。

相較 E22，本輪**真正補足** 0x8077B0 的完成 byte count 對應、partial buffer shift、合法範圍、完整耗盡回傳值陷阱；不是重複既有 send-vtable 證據。剩下較難的 RR-0001 首封包及 0xFE3368 consumer 尚未找到；不能標正式完成。

## 各類缺口

- Client 待逆向：`0x89DBD0` 真實搬移實作；後續 scheduler 何時再進 `0x804B21`；各 connection 首筆送出 frame、receive/dispatch；`0xFE3368` consumer。
- Server 待開發：依 Client framing 與實際收包 handler 設計兼容返回，不能以本地 buffer 據點臆測 Server 策略。
- 跨功能待整合：T02 RR-0001/0004/0005；T03 auth/selection；E01–E22 scene path。
- 待遊玩驗證：無 pcap / runtime acceptance；IOCP completion 不等於 Server 收到。

## 一手原始組語視窗

### VA 0x8077B0–0x807824 (raw 0x406BB0–0x406C24)

```asm
  8077b0:	53                   	push   ebx
  8077b1:	8b 1e                	mov    ebx,DWORD PTR [esi]
  8077b3:	53                   	push   ebx
  8077b4:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8077ba:	85 ff                	test   edi,edi
  8077bc:	78 5b                	js     0x807819
  8077be:	8b 86 0c 50 00 00    	mov    eax,DWORD PTR [esi+0x500c]
  8077c4:	3b c7                	cmp    eax,edi
  8077c6:	72 51                	jb     0x807819
  8077c8:	2b c7                	sub    eax,edi
  8077ca:	89 86 0c 50 00 00    	mov    DWORD PTR [esi+0x500c],eax
  8077d0:	74 3e                	je     0x807810
  8077d2:	8b 86 04 50 00 00    	mov    eax,DWORD PTR [esi+0x5004]
  8077d8:	8d 8e 04 50 00 00    	lea    ecx,[esi+0x5004]
  8077de:	8d 56 04             	lea    edx,[esi+0x4]
  8077e1:	2b c7                	sub    eax,edi
  8077e3:	3b d1                	cmp    edx,ecx
  8077e5:	73 32                	jae    0x807819
  8077e7:	3b c2                	cmp    eax,edx
  8077e9:	72 2e                	jb     0x807819
  8077eb:	3b c1                	cmp    eax,ecx
  8077ed:	73 2a                	jae    0x807819
  8077ef:	89 01                	mov    DWORD PTR [ecx],eax
  8077f1:	2b c6                	sub    eax,esi
  8077f3:	83 e8 04             	sub    eax,0x4
  8077f6:	50                   	push   eax
  8077f7:	8d 44 37 04          	lea    eax,[edi+esi*1+0x4]
  8077fb:	50                   	push   eax
  8077fc:	52                   	push   edx
  8077fd:	e8 ce 63 09 00       	call   0x89dbd0
  807802:	83 c4 0c             	add    esp,0xc
  807805:	53                   	push   ebx
  807806:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80780c:	b0 01                	mov    al,0x1
  80780e:	5b                   	pop    ebx
  80780f:	c3                   	ret
  807810:	8d 4e 04             	lea    ecx,[esi+0x4]
  807813:	89 8e 04 50 00 00    	mov    DWORD PTR [esi+0x5004],ecx
  807819:	53                   	push   ebx
  80781a:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807820:	32 c0                	xor    al,al
  807822:	5b                   	pop    ebx
  807823:	c3                   	ret
```

### VA 0x806E7D–0x806ECD (raw 0x40627D–0x4062CD)

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
  806eca:	e9 61 fe         	jmp    0x806d30
```

### VA 0x804B1A–0x804BC0 (raw 0x403F1A–0x403FC0)

```asm
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
  804b9b:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  804ba2:	01 00 00 
  804ba5:	0f 8e 9d 00 00 00    	jle    0x804c48
  804bab:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  804bb2:	0f 85 90 00 00 00    	jne    0x804c48
  804bb8:	56                   	push   esi
  804bb9:	e8 22 18 00 00       	call   0x8063e0
  804bbe:	8b 45              	mov    eax,DWORD PTR [ebp+0x8]
```

## 停止與下段

第一輪已取得原生緩衝消耗和 bool 反例重大新發現，第二輪驗證 completion 使用及下次送出 gate，第三輪確認失敗與排程界線。下一段 E24：從 `0x804B21` 的包含函式及 callers 找排程週期，從首送作業追到 RR-0001 first frame。main RR 狀態未更動；提交僅 extra/roy1。