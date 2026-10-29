# E28 — RR-0001／RR-0005：connection key=0/2、tree register 與上游事件
時間：2026-10-29 19:53:58 Asia/Taipei。KR 原始 Tartaros.bin 12,472,320 bytes、SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91（當次重算）。機器碼 raw=VA−0x400C00；只讀未執行。開工 main 610a822b15346c9e0b69edd4e104c2076f2b59ac；RR-0001/0005 QUEUED。研究分支 extra/roy1，非正式領取 RR。
## Round 1：key 0/2 的第一手參數來源及索引註冊 — 重大新發現
在 0x4957C0，第一個 transport vtable+0x18 create call 0x4957EA，stack 從右向左 push host、0x20E0、0、2；第二個 0x495803 則為 host、0x20DE、2、2。vtable 0xC51748+0x18 = 0x806AD0。0x806AD0 的 [ebp+0x10] 恰是第三參數 connection key；[ebp+0xC] 是第二參數 port numeric，[ebp+0x14] 用於 connection+0xA080。
```asm
4957E0 push 2
4957E2 push 0
4957E4 push 0x20E0
4957E9 push ebx
4957EA call edx
4957F2 push 2
4957F4 push 2
4957FD push 0x20DE
495802 push ebx
495803 call edx
806B0E mov ecx,[0xFBA858]
806B14 push 1
806B16 call 0x805950
806B29 mov [ebx+0xA0B4],2
806B33 mov [ebx+0xA080],eax
806B54 mov eax,[ebp+0xC]
806B65 call dword [0xBD25A8]
806B8A mov [ebx],eax
806B8C call dword [0xBD25C4]
806B95 jne 0x806C16
806C91 lea eax,[ebp+0x10] ; address of connection key
806C94 lea esi,[edi+0x18] ; transport tree
806C97 push eax
806C9E call 0x8438C0      ; lookup
806CA7 cmp eax,[edi+0x1C]
806CB3 call 0x7B6890      ; existing-key handling
806CB8 mov edx,[ebp+0x10]
806CBF mov [esp+0x14],edx
806CC3 mov [esp+0x18],ebx ; newly connected Conn*
806CC7 call 0x57EF20
806CD2 call 0x57E850      ; insert/update candidate
```
故在兩次連線成功且索引插入完成、未遭重設的條件下，0x8069A0 由同一 transport+0x18 tree 查 key 0 的結果應為第一條（0x20E0）連線。E27 對 key0 目標未知的保守結論得到實質補證。不能推定 0x20E0 是何部署政策或 first wire opcode。
## Round 2：0x805950 是獨立的連線 pool，不是 transport keyed map
```asm
80597A mov eax,[edi+0x34]
805980 call dword [0xBD224C]
805986 cmp dword [edi+0x20],0
805989 je 0x8059FE
8059E9 call 0x805F50
8059F3 mov [esi+0xA0AC],eax
8059FE cmp [ebp+8],esi
805A03 push 0xA0D8
805A08 call 0x891268
805A1B call 0x805CA0
805A2B mov ecx,[edi+0x38]
805A2E mov [eax+0xA0C8],ecx
805A54 mov [esi+0xA0AC],1
805A62 call dword [0xBD2248]
805A68 mov eax,esi
```
該函式在既有 pool 中取 Conn 或新配置大小 0xA0D8 的 Conn；pool+0x20 count 不能混同 transport+0x18 key tree。socket connect 失敗使用 0x805AF0 回收；因此 key0 對象的條件性質還包括 socket 是否成功。
## Round 3：找到 0x66C090 的真正高層 E8 呼叫者
原始 .text E8 rel32 掃描 + objdump 指令邊界：0x66C090 direct callers 只有 0x66C6B9 和 0x66C713。前者在外層物件+0x20 比對成功後 reset 多個 vtable+0x90 狀態，接著 push esi，call 0x66C090；後者以 ECX=0 呼叫同函式，其 gate 包括 0x578 比較。
```asm
66C675 mov edx,[eax+8]
66C678 cmp edx,[ecx+0x20]
66C67B jne 0x66C718
66C687 mov edx,[eax+0x90]
66C68D push 0
66C68F call edx
66C6B5 mov ecx,[edi+0x20]
66C6B8 push esi
66C6B9 call 0x66C090
66C6C4 cmp ecx,0x578
66C6CA jne 0x66C718
66C6D2 mov edx,[eax+8]
66C6D5 cmp edx,[ecx+0x20]
66C6D8 jne 0x66C718
66C710 push esi
66C711 xor ecx,ecx
66C713 call 0x66C090
```
這是事件／上層物件到 0x4957C0 的上游證據；但 0x578 的原生事件型別、0x66C090 是否 T03 0x13 認證回覆 consumer，尚未證明。不得自稱登入成功已完整串線。
## 有界資料流
0x66C6B9 / 0x66C713 → 0x66C090 → 0x66C1A7/0x66C247 → 0x4957C0 → vtable+0x18 / 0x806AD0（key0, key2）→ keyed transport tree → vtable+0x10 / 0x8069A0 (key0) → 0x8060D0（0x39 local payload enqueue）。後續 E19–E25 的 frame→WSASend/IOCP 鏈已另有實證，但無 runtime 可證該 payload 即第一筆 wire frame。
Client 待逆向：0x57EF20/0x57E850 tree insertion precise duplicate-key rules、0x66C090 事件註冊源、每 socket 首包/首收、0x13 上游真正對應。Server 待開發：已確認原生 Client interface 的相容策略，未知官方 Server policy 不能自行假設。跨功能待整合：T02 RR-0001/0005 與 T03 RR-0003。待遊玩驗證：Client/new Server pcap 和成功/失敗 connect。正式 RR 仍待 owner/S00 acceptance，亦非 T01 FULL-PASS。
重現：objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4957d0 --stop-address=0x495812 Tartaros.bin；同法 0x806ad0..0x806cd8、0x805950..0x805a7c、0x66c675..0x66c718。