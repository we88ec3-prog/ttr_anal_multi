# E27 — RR-0001／RR-0005：雙連線切換的上游呼叫者、57-byte 結構與 key=0 查找
研究時間：2026-10-29 19:49:35 Asia/Taipei；原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91（本輪重驗）。raw offset = VA−0x400C00。main 基準 610a822b15346c9e0b69edd4e104c2076f2b59ac，RR-0001 / 0005 QUEUED。本研究僅支持跨 Task，未改 owner/RR/main。
## 第一輪：0x4957C0 兩個真正的直接 E8 callers
完整 .text E8 rel32 搜尋僅匹配 0x66C1A7、0x66C247；兩者均位於原生函式 0x66C090。不是兩個不同登入功能已被證實，只是同函式不同條件分支：
```asm
66C090 push ebp
66C0BE mov ecx,[ebp+8]
66C0C1 mov eax,[ecx+0xF0]
66C0C7 mov eax,[eax+0xCC]
66C124 mov eax,[esp+0x10]
66C128 mov esi,[0xFE1B54]
66C12E push edi
66C12F push eax
66C132 call 0x5078C0
66C13B push edi
66C13E push ecx
66C141 call 0x507750
66C17E cmp dword [0xF94294],0
66C185 je 0x66C21D
66C18B test ebx,ebx
66C18D je 0x66C21D
66C193 test esi,esi
66C195 je 0x66C4B9
66C19B call 0x414680
66C1A0 push esi
66C1A1 mov esi,[0xFB1318]
66C1A7 call 0x4957C0
66C21D cmp ebx,4
66C220 je 0x66C274
66C222 test ebx,ebx
66C224 je 0x66C3E6
66C22A cmp ebx,5
66C22D je 0x66C3EF
66C233 test esi,esi
66C235 je 0x66C4B9
66C23B call 0x414680
66C240 push esi
66C241 mov esi,[0xFB1318]
66C247 call 0x4957C0
```
上下文存在 ebx=0/4/5 的 gate；還不能把它們命名成 0x13 auth status 或選服成功碼，必須追 0x66C090 的註冊/dispatch 来源。兩個 callsite 的 stack arg 均來自上一個 esi 值，而全域 [0xFB1318] 載入 esi 為 0x4957C0 隱含 context。
## 第二輪：0x39 本地 payload 的 source-offset 對照
| 相對 buffer 起點 | stack 目標 | 原生來源 | 證據邊界 |
|---:|---|---|---|
| +0 | [ebp-0x40] word | literal 1, 495884 | confirmed |
| +2 | [ebp-0x3E] dword | 404BA0() + 0x67E0 | confirmed |
| +6 | [ebp-0x3A] region | 404BA0() + 0x67E4 via 893FFE | 呼叫前 push 0xA，copy semantics not yet proved |
| +26 | [ebp-0x26] byte | literal 1 at 4958F1 | confirmed |
| +27 | [ebp-0x25] byte | 404BA0() + 0x6898 | confirmed |
| +28 | [ebp-0x24] region | 404BA0() + 0x6899 via 893B59, push 5 | precise copy semantics pending |
| +33 | [ebp-0x1F] dword | 404BA0() + 0x68A0 | confirmed |
| +37 | [ebp-0x1B] region | 404BA0() + 0x67FA via 893FFE, push 0xA | confirmed callsite |
```asm
495884 mov word [ebp-0x40],cx
4958B3 call 0x404BA0
4958B8 mov edx,[eax+0x67E0]
4958BE mov [ebp-0x3E],edx
4958C1 call 0x404BA0
4958C6 push 0xA
4958C8 add eax,0x67E4
4958D4 call 0x893FFE
4958D9 call 0x404BA0
4958E0 add eax,0x67FA
4958EC call 0x893FFE
4958F1 mov byte [ebp-0x26],1
4958F5 call 0x404BA0
4958FA mov dl,[eax+0x6898]
495900 mov [ebp-0x25],dl
495908 add eax,0x6899
495914 call 0x893B59
49591C call 0x404BA0
495921 mov ecx,[eax+0x68A0]
495927 mov [ebp-0x1F],ecx
495932 mov edx,[edx+0x10]
495935 push 0x39
495937 lea eax,[ebp-0x40]
49593A push eax
49593B push 0
49593D call edx
```
不能把 0x39 宣告為最終 wire frame 長度；vtable +0x10 的 payload 入列後還會由 807830 或 807A70 framed。十位元組 callsite 未追 callee 前亦不能宣稱必定原封十位元組。
## 第三輪：connection key 0 是 tree lookup，不等於第一個 socket
```asm
8069A4 mov eax,[ebp+8]
8069AA lea ecx,[ebp+8]
8069B0 push ecx
8069B1 lea ecx,[esi+0x18]
8069B4 lea eax,[ebp-4]
8069B7 call 0x8438C0
8069BC mov eax,[ebp-4]
8069BF cmp eax,[esi+0x1C]
8069C3 je 0x8069CC
8069C5 mov ecx,[eax+0x10]
8069C8 test ecx,ecx
8069CA jne 0x8069D4
8069CC xor eax,eax
8069D4 mov eax,[ebp+0x10]
8069D7 test eax,eax
8069D9 jne 0x8069E6
8069DB mov eax,1
8069E6 mov edx,[ebp+0xC]
8069E9 push eax
8069EA push edx
8069EB call 0x8060D0
```
因此 49593B push 0 是 transport tree key，不是 payload opcode；0x4957EA 建立 selector 0x20E0 的 connection、0x495803 建立 0x20DE，兩者與 key0 之間尚無索引 insertion 證據。0x495853 向舊 connection+0xBF60 直接 enqueue 0x007E 兩位元組是另一個路徑，不應與 key0 的 0x39 bytes 混同。
## RR 與後續
已確認：0x4957C0 direct callers exact two；0x66C090 的 branch gates；部分 0x39 stack-field sources；0x8069A0 keyed tree lookup and failure path。尚待確認：0x66C090 upstream receiver/0x13 affiliation、0x8438C0 map key0 insertion/actual socket、每 socket 首筆 wire data、807830/807A70 framing 是否真走該 payload、非同步時序。
Client 待逆向：上述來源/鍵/網路首包；Server 待開發：僅實作已核實格式及自行 policy；跨功能待整合：T02 RR-0001/0005 × T03 RR-0003 auth handoff；待遊玩驗證：原 Client + 相容 Server 的 socket pcap、接收/失敗情境。
三輪研究：第一輪兩個 caller，第二輪 payload field provenance，第三輪 key0 consumer/failure；取得實質 bounded upstream/field findings，但 RR 尚未正式完成。下一 E28 追 0x66C090 的 callback/dispatch 和 0x805950 的 key insertion。
重驗：objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x66c090 --stop-address=0x66c275 Tartaros.bin；同法分析 0x49587d..0x49595b、0x8069a0..0x8069f5。