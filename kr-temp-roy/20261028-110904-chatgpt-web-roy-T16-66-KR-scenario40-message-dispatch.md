# KR T16-66 — 0x004AA4D0 的 4-byte 訊息封送與虛呼叫

- 研究日期：20261028-110904 Asia/Taipei；分析者 `chatgpt-web roy`；**僅 KR T16**。
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。實際讀取 `/mnt/data/Tartaros.bin`（唯讀）；未啟動遊戲或呼叫任何原版 API。
- PE `.text` 有效映射：VA `0x00401000`, raw `0x400`；下列 `.text` 函式轉檔案位移使用 `raw = VA - 0x00400C00`，跨 section 必須重算。
- 證據術語：原生已確認=本次直接 BIN 原始位元組與逐指令反組譯；部分確認=指標來源／語意尚未對齊；unknown=缺少原始資料。

## 1. 已確認 native data flow

函式入參 `[ebp+8]` 低 16 bits 轉入 `[ebp-2]`，另將立即數 `0x0040` 寫入 `[ebp-4]`，組成記憶體 4 bytes（little endian）`40 00 XX XX`。經 `cmp dword [0xFBA798],0`，**只有該全域為零**時，從 `[0xFBA854]` 取得指標，以物件首個 pointer 的 vtable + `0x10` 虛方法呼叫，參數順序 `push 4; lea eax,[ebp-4]; push eax; push 0; call edx`。返回 `ret 4`。

- `0x004AA4D0` raw=`0xA98D0`；已確認指令 raw 與 VA。
- 目前最嚴謹的命名為「本地送出／分派**候選**，四位元組 buffer」，並非已確認 TCP/UDP socket 寫入。
- `0x40` 是此本機 4-byte message 的 16-bit 首欄位；**不能未經 T02/封包分派證據就命名官方 opcode 或 scenario14 結果**。
- `0x4ACB70` 轉整數再給本 callback，低 16 bit 被採用，因此如 `id > 65535` 會截斷；是否允許這種輸入、runtime 真值未知。

```asm
  4aa4d0:	55                   	push   ebp
  4aa4d1:	8b ec                	mov    ebp,esp
  4aa4d3:	51                   	push   ecx
  4aa4d4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4aa4db:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4aa4df:	b8 40 00 00 00       	mov    eax,0x40
  4aa4e4:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4aa4e8:	66 89 4d fe          	mov    WORD PTR [ebp-0x2],cx
  4aa4ec:	75 15                	jne    0x4aa503
  4aa4ee:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4aa4f4:	8b 11                	mov    edx,DWORD PTR [ecx]
  4aa4f6:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4aa4f9:	6a 04                	push   0x4
  4aa4fb:	8d 45 fc             	lea    eax,[ebp-0x4]
  4aa4fe:	50                   	push   eax
  4aa4ff:	6a 00                	push   0x0
  4aa501:	ff d2                	call   edx
  4aa503:	8b e5                	mov    esp,ebp
  4aa505:	5d                   	pop    ebp
  4aa506:	c2 04 00             	ret    0x4
  4aa509:	cc                   	int3
  4aa50a:	cc                   	int3
  4aa50b:	cc                   	int3
  4aa50c:	cc                   	int3
  4aa50d:	cc                   	int3
  4aa50e:	cc                   	int3
  4aa50f:	cc                   	int3
  4aa510:	55                   	push   ebp
```

## 2. 精確偽碼（限定）

```cpp
void candidate_handler(uint32_t value) {
    struct { uint16_t tag, value; } msg = {0x0040, (uint16_t)value};
    if (*(uint32_t*)0x00FBA798 == 0) {
        auto obj = *(void**)0x00FBA854;
        // exact virtual method semantics unknown
        obj->vtable[4](0, &msg, 4);
    }
}
```

> vtable[4] 根據 x86 32-bit byte offset `0x10`；此處 C++ 介面**示意**，未證明型別名稱或 thiscall 參數清除方式。

## 3. 後續要查的 xref

`0x00FBA798` refs（binary byte hits）：0x405955, 0x406466, 0x4133A2, 0x413616, 0x4190D0, 0x421286, 0x422AD7, 0x422C6D, 0x4230B7, 0x42373D, 0x42618C, 0x42BE01, 0x42C4EB, 0x434652, 0x435FD5, 0x43644E, 0x439E67, 0x439FD1, 0x439FFD, 0x43A0C0, 0x441FAD, 0x4448CA, 0x452CF5, 0x454112, 0x455F3D, 0x4579D9, 0x458118, 0x47755C, 0x480FB9, 0x48308E, 0x4912A9, 0x491C6A, 0x4A35C6, 0x4A35F6, 0x4A3626；`0x00FBA854`: 0x405978, 0x406484, 0x40A190, 0x40CBA4, 0x411CA7, 0x4133B5, 0x41362C, 0x4190E3, 0x421298, 0x422AEA, 0x422C84, 0x4230C7, 0x42374F, 0x4261AB, 0x42BE2C, 0x42C501, 0x434664, 0x435FF6, 0x43648F, 0x439E82, 0x439FE8, 0x43A00F, 0x43A0D5, 0x441FF2, 0x4448D3, 0x452CFD, 0x454124, 0x455F49, 0x4579E5, 0x458133, 0x45C361, 0x47757D, 0x477652, 0x47F17B, 0x47F7BB。這些只是 raw 4-byte pattern 命中，應逐一確認指令界線和 owner；不可把每一命中等價於寫入。

## 4. 尚待驗證

- `0xFBA854` vtable `+0x10` 實際 dispatcher、是否連線送出／本機排程。
- `0x0040` message 是否對應 scenario start，仍需 T02 封包／接收端對照。
- 伺服器合法結算、Quest16 完成／Quest15 可接、重登仍是 unknown。
