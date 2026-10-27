# KR T08-164 — 建立—移除—預清理—刪除—樹節點回收的限定閉合

- 研究時間：20261028-020933 Asia/Taipei；研究者：`chatgpt-web roy`。
- 第一手來源：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；靜態唯讀 GNU objdump（PE32 i386），禁止執行或附加。
- GitHub 研究基準：`main` 於研究起始查得 `3fb7b8f6da6fd670cd2fb1e1db739e4f9dc2045b`（其他任務可能同時更新，提交時必須重新確認）；正式 T08 = `0007` 實體建立／登記／移除，網路 dispatch 僅提供 T02 引用邊界。
- 文件類型：新的完整分析原稿，非正式 catalog native semantic acceptance。證據分級：[BYTE] 原始機器碼、[FLOW] 可由指令支持的局部資料流、[INFER] 推論、[OPEN] 未解。
- 地址統一採 PE VA；`.text` VA 0x401000 對 file raw 0x400；禁止使用 flat `VA-0x401000` 混充 PE raw。
- 先前 T08-153～160 及 T01-20261027-05 限定審核仍有效。

## 本輪總結

T08-161..163 對 T08-160 尚未具體定位的 actor 派生清理作原生 bytes 驗證。已能從建構來源追到 CMonster、CEventActor 兩個 vtable 的 `+0x00` / `+0x14`，且區分刪除前資源解除、實際釋放及樹 node erase 三個階段。新分析沒有修改正式 GitHub catalog，也沒有將其他 Task 的封包 dispatch 登記占為 T08 主責。

## 新增精確對照表

| 階段 | VA/資料 | 已證前提與出口 | 不可升級的語意 |
|---|---|---|---|
| 建構 CMonster | `4D1710` `vptr=C0C9DC` | 原始物件建構 bytes | 不能推出所有 Actor 同 vtable |
| 建構 CEventActor | `4D0B80` `vptr=C0C824` | 腳本物件路徑 | 不能以外觀等同 CMonster |
| CMonster pre-remove | slot+14 `4D1F80` -> `4C8360` | call 後 eax=0 | 不能稱為單步 final free |
| CEventActor pre-remove | slot+14 `4C8360` | 直接共享 cleanup | 不能斷言經 4D1F80 |
| CMonster virtual+0(flag=1) | `4D18D0` | base cleanup，flag bit1 才 call 89120C | 其他派生型別未知 |
| EventActor virtual+0(flag=1) | `4D0CA0` | 同型式但派生 vptr 不同 | 不等於同一析構函式位址 |
| 主樹查找/移除 | `4DFBC0` | `node+10` 非空 invariant、pre-remove、delete、erase | null actor 的安全性不可假設 |
| 樹節點 erase | `7B6890` | 節點操作由 caller 決定 payload 責任 | 不會自動替代 actor delete |
| 條件移除接收 | `4B3710` | key=`0x06000000|WORD` | opcode/domain 6 含義未確認 |
| ID 移除接收 | `4B28D0` | packet length >=4，WORD rows | 不能推成 0007 26-byte payload |

## 修正舊結論與證據權限

- 154/156 將 `40F060` 暫認為 key converter 已由 T08-158 更正；本輪同指令確認該 getter 取得 GameInfo receiver，`or` 在 `4B3733`。
- 159 提到 slot+0/slot+14 分派未定位；新兩個 vtable 的具體 callee 補入 161，並在 162 深入共享 cleanup。
- `4DFBC0` 呼叫順序是 **controller 三槽處理 → actor slot+14 → actor slot+0(1) → node erase**，並非簡單 map.erase()。這只成立於該單 ID helper，不能覆蓋條件／全表清理。
- 163 針對 `.rdata` 負掃描的聲明僅限定該區，符合整合者之前對 negative-xrefs 的保留，不因此推斷沒有 opcode 註冊。

## 下一個值得研究的完整功能鏈（T08-165 候選）

1. 對 `0x4C7B90` 基底 destructor 與 `0x7BE5F0` 釋放 helper 建立 bounded CFG、例外分支及資源引用證據，確認最後所有權。
2. 對 T02 提供 `4B28D0`、`4B3710` 的 registration callsite 及準確 dispatcher opcode；若需修改 T02 catalog，交由 T02/整合者。
3. 以 4DFD40 與 4DFE90 追不同 bulk/full clear caller 是否正確 pre-remove 所有類別；特別需避免兩種 virtual cleanup 順序的推論互相替代。
4. `actor+0x88` 的真正 writer/schema 仍未知；不要用 `0x06000000` 直接推成伺服器實體種類。

## 交付方式

完整原始 Markdown 每個段號各一份，包含機器碼片段、函式表、有限偽碼、已更正的歷史說法及可重現驗證。GitHub path `kr-temp-roy/`，送交 T01 integrator 時應以具體 SHA 和限定 claim 為對象，不宣稱 native whole-function audited。


## 本批核查的代表性原生錨點

### 4DFBC0 整體單鍵清理序列
```asm
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2                   	.byte 0xc2
```

### 4D1F80、4D18D0 派生槽
```asm
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
  4d18d0:	55                   	push   ebp
  4d18d1:	8b ec                	mov    ebp,esp
  4d18d3:	56                   	push   esi
  4d18d4:	8b f1                	mov    esi,ecx
  4d18d6:	c7 06 dc c9 c0 00    	mov    DWORD PTR [esi],0xc0c9dc
  4d18dc:	c7 86 f0 00 00 00 64 	mov    DWORD PTR [esi+0xf0],0xc0ca64
  4d18e3:	ca c0 00 
  4d18e6:	e8 a5 62 ff ff       	call   0x4c7b90
  4d18eb:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4d18ef:	74 09                	je     0x4d18fa
  4d18f1:	56                   	push   esi
  4d18f2:	e8 15 f9 3b 00       	call   0x89120c
  4d18f7:	83 c4 04             	add    esp,0x4
  4d18fa:	8b c6                	mov    eax,esi
  4d18fc:	5e                   	pop    esi
  4d18fd:	5d                   	pop    ebp
  4d18fe:	c2                   	.byte 0xc2
```

## 證據與不變限制

- 使用者要求本段保留完整 trace，而非強行將 caller 確定為封包 opcode；只在 PE 映射及 opcode 所支援範圍下說話。
- 對於歷史已判定有不同內容的 flat dump，採用 PE 頭與具體位置實際 bytes，不跨視角複製反組譯結論。
- 靜態反組譯未含執行時各派生類別的所有實際 vptr；不得推論全域 exhaustive caller 或 runtime 時序。
- 不修改 `kr/tasks/T08/task.json`、`shared/catalog.json`、別人任務文件；commit 僅研究者個人 `kr-temp-roy/`。