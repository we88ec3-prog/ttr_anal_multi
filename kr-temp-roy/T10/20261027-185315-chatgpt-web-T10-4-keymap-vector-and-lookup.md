# KR T10-4 — KeyMapping vector append、映射來源分流（BIN-first）

任務：KR T10 普通攻擊與連段；前段 T10-1、T10-2、T10-3；此文件為 T10-4。  
日期：2026-10-27 Asia/Taipei。  
原始檔：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本段僅唯讀。  
反組譯方法：Python 讀取 BIN `.text` 的 VA/raw 對映（VA `0x401000`、raw `0x400`），以 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma` 解碼相關地址；未啟動遊戲。

## 1. 已確認：`0x4A8680..0x4A86DB` 是 DWORD vector 的 append-copy helper

輸入：`EDI` 指向三欄 `begin/end/capacity` 動態 DWORD 陣列；`EAX` 是**來源 DWORD 的地址**，不是欲寫入的 DWORD 常數。結果：必要時擴容，複製 4 bytes 至 end，end 增 4。函式包含來源指標位於自身 buffer 時的特殊分支，以保護向量 reallocate 後的引用。

```asm
4A8681 mov esi,eax
4A8683 mov eax,[edi+4]       ; end
4A8686 cmp esi,eax
4A868A mov ecx,[edi]         ; begin
4A8690 sub esi,ecx
4A8692 sar esi,2             ; self-reference index
4A8695 cmp eax,[edi+8]       ; capacity
4A86A1 call 6D6240          ; grow if full
4A86AD mov ecx,[edi]
4A86AF mov edx,[ecx+esi*4]  ; source after reallocation
4A86B2 mov [eax],edx
4A86B4 add dword [edi+4],4
...                         ; non-self-reference branch
4A86BF mov ecx,1
4A86C6 call 6D6240          ; grow if full
4A86D2 mov edx,[esi]
4A86D4 mov [eax],ecx
4A86D6 add dword [edi+4],4
4A86DB ret
```

**更正 T10-3：** `0x6D0EB0` 中的 `mov [ebp-4],0x48` 配 `call 0x4A8680`，是讓 `EAX` 指向本地 DWORD，再向 `EDI` 指定的 vector push 該值。不可將 `0x48` 直接理解為 MapButton 編號、角色技能或 Z 的 Windows VK，除非同時追出 caller 與對應表。

**暫定偽碼（不代表已證實 C++ 原型）**：
```cpp
void appendDword(Vector32* v, const uint32_t* source) {
    // source in v's own storage requires index preservation across expansion
    size_t sourceIndex = 0;
    bool selfRef = source >= v->begin && source < v->end;
    if (selfRef) sourceIndex = source - v->begin;
    if (v->end == v->capacity) grow(v, 1);  // 0x6D6240
    *v->end++ = selfRef ? v->begin[sourceIndex] : *source;
}
```

## 2. 已確認：`0x6D4DC0` 至少包含兩條映射查取分支

此函式 prologue 在 `0x6D4DC0`；對 `arg0` 與常數 `0x2711` 相減後與 `0x270E` 比較，依區間跳往 `0x6D4EE6` 或落至 `0x6D4E02`。第二參數在前半經 `<<4` 用於選擇全域 `0xFDF3F4+index*16`，在另一分支參與 `0xFB8834` Bank row 的索引計算。**這是兩種不同來源的映射查取，無證據表示它就是 physical keyboard keydown callback。**

```asm
6D4DE8 mov eax,[ebp+0xC]
6D4DEB mov ebx,[ebp+0x8]
6D4DF0 lea ecx,[ebx-0x2711]
6D4DF6 cmp ecx,0x270E
6D4DFC ja 6D4EE6
6D4E02 shl eax,4
6D4E0F lea esi,[eax+0xFDF3F4]
6D4E49 call 6D43F0        ; retrieval helper, source still unresolved
6D4E4E mov edx,[eax+4]
6D4E51 sub edx,[eax]
6D4E53 sar edx,2
6D4E56 cmp [ebp+8],edx
6D4E59 jae 6D4FFA
6D4EB2 call 4A8680       ; missing entry -> append 0 candidate
6D4ED9 call 4A8680       ; existing row -> append fetched DWORD
6D4EE6 lea edx,[eax+eax*4]
6D4EE9 lea ebx,[ebx+edx*8]
6D4EEE shl ebx,4
6D4EF4 lea ebx,[ebx+0xFB8834]
6D4F30 mov eax,[ebx+4]
6D4F33 sub eax,[ebx]
6D4F35 sar eax,2
6D4F38 cmp esi,eax
6D4F7D xor esi,esi        ; empty vector fallback
6D4F81 mov edx,[ebx]
6D4F83 mov esi,[edx+esi*4]
```

地址計算 `0x6D4EE6..0x6D4EF4` 對應 `((arg1*40) + arg0) * 16 + 0xFB8834`（以實際暫存器資料流推導，需再確認兩參數各自上游的語義與界線）。`0x6D4E15`、`0x6D4F00` 的靜態初始化 guard 會呼叫 `0x6D1DA0` 或 `0x6D0750`，因此在這條查取流程中可能觸發懶初始化。不可誤認其為每次實體按鍵按下時都重載 XML。

## 3. 與 T10-1～T10-3 的接續、證據分級

| 命題 | 狀態 | 證據／限制 |
|---|---|---|
| `4A8680` 是 append-copy DWORD vector helper | 已確認 | `4A8680..4A86DB` 完整短函式機器碼 |
| `6D4DC0` 依數值範圍走至少兩個映射來源 | 已確認 | `6D4DF0..6D4E02`、`6D4EE6..6D4EF4` |
| 選定 Bank 中的 row 存有 DWORD vector | 已確認 | `6D4EF4`、`6D4F30..6D4F83` |
| default key value `0x48/0xC8/0x4C...` 可直接讀成攻擊鍵 Z | 未確認 | 其實是回退設定的 vector 資料；未證實實際 XML 或 mapped action |
| `6D4DC0` 是 Z keydown／keyup 事件 dispatcher | 未確認 | 尚未完成 caller / input device callback 追查 |
| Z 連按與 Z 持續按住的合流點 | 未確認 | 本段限於映射容器與查取，沒有攻擊狀態的證據 |
| `0x547240` 的 500ms 就是 Z 普攻續段窗口 | 未確認 | timeGetTime 計時確定，控制來源仍不確定 |

使用者提供原版普攻兩種操作：Z 連按與 Z 持續按住。這是研究需求，不能倒推某個函式必然對應它們。

## 4. 下一段 T10-5 建議

1. 查 `0x6D4DC0` caller 與其第一參數產生者，確認 `0x2711..` 特殊範圍與 Bank row 的資料語義。
2. 追 `0x6D43F0`、`0x6D1DA0` 的來源容器，將 `0x6D4DC0` 回傳資料與輸入 bit 實際消費者連起來。
3. 取得實際 `Table/KeyMapping.xml` 作為獨立來源，核對原始鍵碼／MapButton 對應；不以 BIN fallback 當使用者配置。
4. 在確定 Z action 後分離 pressed edge、held state、release 與自動續段，進一步追到普攻 motion 的 gate / cancel 條件。

## 5. GitHub／協作界線

T10 正式範圍見 `kr/tasks/T10/README.md`；除普通攻擊、連段、取消之外不跨入 T12 傷害公式。所有原始檔均唯讀。GitHub `AGENTS.md` 的 owner / catalog 共用責任仍待整合者分派；本次只新增個人 T10 原稿，不修改 task.json、catalog 或其他 Agent 目錄。原稿與 T10-1～T10-3 提交情況依遠端回讀為準。