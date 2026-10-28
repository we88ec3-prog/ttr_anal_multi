# T16-100 — KR Quest 三模式列表與 runtime record gate（BIN-first）

研究者：chatgpt-web roy。2026-10-28 23:09:20 Asia/Taipei。僅靜態讀取 KR 原始 BIN。正式段號承接 T16-99；不將靜態查表解讀為 Quest C→S/S→C 封包。

## 0. 來源與 Git

- 原始 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。已重新 hash。
- `.text` VA `0x401000` raw `0x400`，raw = VA − `0x400C00`。實際 x86 指令由 `objdump -b binary -m i386 -M intel -D --adjust-vma=0x400c00` 讀取（該顯示標籤 `.data` 為 raw binary 的虛擬節名，非 PE `.data` 分節）。
- 新對話開工前 GitHub compare：`main=baafc0ed9ed84c560caca86ad73d6307e2ec4a9c`，T16 分支 ahead 12 / behind 0。未改 main、T02 或其他 Task。
- 先前 T16-99 研究指出 0x62F640、0x62F4C0、0x62F580 依 mode 建立 pointer-vector；本段新增中間 helper 的精確 gate，並修正容易混淆的兩個全域 owner。

## 1. 第一輪：`0x500950` 不是無條件讀取全部 Quest

呼叫現場 `0x62F552..0x62F566`：

```asm
62f552: 8b 83 f8 00 00 00    mov eax,[ebx+0xf8]
62f558: 57                   push edi
62f559: 50                   push eax
62f55a: 68 a0 b2 fa 00       push 0xfab2a0
62f55f: e8 ec 13 ed ff       call 0x500950
62f564: 8b cb                mov ecx,ebx
62f566: e8 25 05 00 00       call 0x62fa90
```

`0x500950` 前置：目標 vector `[arg3]+0/+4` 相等性檢查後，從 `[arg1+0x5EC0]..[arg1+0x5EC4]` 逐個 16-bit key 讀取；查 `[arg1+0x5EAC]` map，而非直接假設全域 `[0xFB114C]`。其中 `arg1=0xFAB2A0` 是全域物件地址，並非隱含的指標解參照。

```asm
500983: 8b 7d 08             mov edi,[ebp+8]
500986: 8b 87 c4 5e 00 00    mov eax,[edi+0x5ec4]
50098c: 8b 9f c0 5e 00 00    mov ebx,[edi+0x5ec0]
5009a0: 0f b7 03             movzx eax,word [ebx]
5009a3: 8b b7 ac 5e 00 00    mov esi,[edi+0x5eac]
5009b5: e8 66 33 00 00       call 0x503d20
5009bd: 3b 46 04             cmp eax,[esi+4]
5009c0: 74 05                je 0x5009c7
5009c2: 83 c0 10             add eax,0x10
5009c7: 33 c0                xor eax,eax
5009d3: 39 50 28             cmp [eax+0x28],edx
5009d8: 83 78 04 01          cmp dword [eax+4],1
5009e4: e8 27 33 f4 ff       call 0x443d10
5009ec: 83 c3 02             add ebx,2
```

這條路徑需要 map 有效節點、`record+0x28 == arg2` 且 `record+4 == 1`，才把 `record` 指標加入 `arg3` vector。`0x5009c7` 是 miss branch，不能理解成所有結果無條件清零；在 hit branch `0x5009c5 jmp 0x5009c9` 跳過。

注意 `0x500965..0x500980` 清列表時的 `sub eax,ecx` 原始確實是「end-end」，疑似最佳化的空長度區域處理，不能以直覺改成 `end-begin` 作為原始反組譯。須以更完整 vector 生命週期檢查。

## 2. 第二輪：`0x500E00` 具備跨資料源的條件 gate

Mode 2 呼叫現場 `0x62F612..0x62F626`：

```asm
62f612: 8b 83 f8 00 00 00   mov eax,[ebx+0xf8]
62f618: 57                  push edi
62f619: 50                  push eax
62f61a: 68 a0 b2 fa 00      push 0xfab2a0
62f61f: e8 dc 17 ed ff      call 0x500e00
62f624: 8b cb               mov ecx,ebx
62f626: e8 65 04 00 00      call 0x62fa90
```

注意在共同 consumer `0x62FA90` 內亦存在另一直接 `0x500E00` 呼叫，傳入 `record+0x2C`，不是所有呼叫都以 `[EBX+0xF8]` 當選擇值。

```asm
500e56: 8b 45 08             mov eax,[ebp+8]
500e59: 05 d0 5e 00 00       add eax,0x5ed0
500e62: c7 44 24 14 14 00 00 00  mov [esp+0x14],0x14
500e6e: 0f b7 39             movzx edi,word [ecx]
500e71: 66 85 ff             test di,di
500e74: 0f 84 e4 00 00 00    je 0x500f5e
500e7d: 8b b2 ac 5e 00 00    mov esi,[edx+0x5eac]
500e95: e8 86 2e 00 00       call 0x503d20
500eb5: 39 48 2c             cmp [eax+0x2c],ecx
500eb8: 0f 85 a0 00 00 00    jne 0x500f5e
500ef0: a1 34 b1 fa 00       mov eax,[0xfab134]
500ef5: 8b 48 14             mov ecx,[eax+0x14]
500ef8: 8b 40 10             mov eax,[eax+0x10]
500f00: 66 39 78 14          cmp word [eax+0x14],di
500f06: 66 8b 50 08          mov dx,word [eax+8]
500f0a: 66 3b 50 06          cmp dx,word [eax+6]
500f0e: 7c 4e                jl 0x500f5e
500f10: 83 c0 18             add eax,0x18
500f4c: 83 78 04 02          cmp dword [eax+4],2
500f50: 74 0c                je 0x500f5e
500f59: e8 b2 2d f4 ff       call 0x443d10
500f5e: 83 44 24 10 02       add dword [esp+0x10],2
500f63: ff 4c 24 14          dec dword [esp+0x14]
```

`0x500E00` 明確遍歷 `arg1+0x5ED0` 起始的 20 個 16-bit key（而非 `0x500950` 的 begin/end 指標範圍）。先以 `[arg1+0x5EAC]` map 查 ID，需 `record+0x2C == arg2`。然後遍歷 `[0xFAB134]` 指向物件之 `[+0x10,+0x14)` 區段，每 0x18 bytes 一個 entry：若 entry `+0x14` 的 word 等於 key 且 entry `+8` 的 word 小於 entry `+6` 的 word，直接跳過；否則再查 map，當 `record+4 != 2` 時將 record 指標加入 vector。當 key=0、map miss、`record+0x2C` mismatch，同樣跳過。這個結論不包含 `[0xFAB134]` 的建構者與資料傳輸來源。

關鍵差別：`0x500950` 過濾 `record+4 == 1` 與 `record+0x28`；`0x500E00` 過濾 `record+4 != 2` 與 `record+0x2C`，且額外檢查 `[0xFAB134]` 的 0x18-byte entries。**兩個 helper 的入口、選擇欄位、集合來源不可混成相同任務清單。**

## 3. 第三輪門檻與局限

第一輪已取得 T16-99 所缺的 `0x500950` 欄位 gate，第二輪又新增 `0x500E00` 和獨立 `[0xFAB134]` 0x18-byte 動態記錄的條件讀取鏈，屬具重要上下游與新欄位的原生發現；依 02 規則第三輪**未啟動**，並非聲稱無需再追動態 writer。

### 暫定偽碼（僅描述已觀察分支）

```cpp
void select_mode1(Owner* owner, int selector, Vector<Record*>& out) {
    clear_end_pointer(out);
    for (uint16_t id : owner->range_5EC0_5EC4) {
        Record* r = lookup(owner->map_5EAC, id);
        if (r && r->field_28 == selector && r->field_04 == 1) out.push_back(r);
    }
}
void select_mode2(Owner* owner, int selector, Vector<Record*>& out) {
    clear_end_pointer(out);
    for (int i=0; i<20; ++i) {
        uint16_t id = owner->keys_5ED0[i];
        if (!id) continue;
        Record* r = lookup(owner->map_5EAC,id);
        if (!r || r->field_2C != selector) continue;
        bool skipped = false;
        for (auto* e=global_FAB134->begin; e != global_FAB134->end; e+=0x18) {
            if (e->id_14 == id && e->u16_08 < e->u16_06) { skipped=true; break; }
        }
        if (skipped) continue;
        r=lookup(owner->map_5EAC,id);
        if (r && r->field_04 != 2) out.push_back(r);
    }
}
```

### 玩家情境矩陣

| 玩家情境 | Client 本地 gate | C→S | S→C | 本地結果 | 原版 Server/待驗 |
|---|---|---|---|---|---|
| mode1 列表重新建立 | key range、record+28==selector、record+4==1 | unknown | unknown | pointer-vector 新增符合項 | 未確認原版 Quest 業務語意 |
| mode2 列表重新建立 | 20 key、record+2C==selector、global 0x18-byte record gate、record+4!=2 | unknown | unknown | pointer-vector 新增符合項 | `[FAB134]` 的 writer 與來源未知 |
| 指定 Quest 的列表再次過濾 | `0x62FA90` 將 `record+0x2C` 傳 `0x500E00` | unknown | unknown | 過濾結果與原始 record 指標比對 | NPC/UI 最終效果 unknown |
| Quest16→Quest15 解鎖與接取 | unknown | unknown | unknown | unknown | 需原版客戶端封包證據 |

### 下一正式段 T16-101

優先從 `[0xFAB134]` 的初始化／writer（尤其 0x18-byte entry 欄位 +6,+8,+0x14）追其是否為 S→C 資料影響；同時由 T02 receive dispatcher 尋找 Quest 狀態 cache 實際 writer，追 `0x62FA90` 之後的畫面更新。此段目前只能證實 Quest-local reader/gate；未找到封包不代表原版沒有封包，亦不可把 XML 內 ID 當 wire opcode。