# KR T10 — 分段研究：動作條件二層查詢與輸入資料塊布局

日期：2026-10-27（Asia/Taipei）；研究方式：對原始 PE32/x86 BIN 唯讀反組譯。這是一段新的技術研究原稿，不宣稱已完成原版 Z 連段機制復原。

## 1. 範圍與完整性

- 主題：接續上一段的 `0xFB902C` 與 `0x81A8E0 → 0x54F4E0`，定位輸入資料來源與條件查表的**具體布局及返回條件**。
- 檔案 `/mnt/data/Tartaros.bin`，SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**，`file` 識別為 PE32 Intel i386，並使用 `objdump -Mintel -d` 由第一手機器碼解析。
- 任務限於 KR T10「普通攻擊與連段」；T12 傷害、T02 通訊框架、T09 移動等既有分工不重作。`kr/tasks/T10/task.json` 仍為 unclaimed，未更動 owner、catalog、遊戲程式或 GitHub。
- 操作背景由使用者確認：**Z 連按與 Z 長按均能進行普通攻擊連擊**。以下並無任何 Z 映射已查明的聲明。

## 2. 新確認：`0x81A8E0` 是嚴格上限的 4×11 WORD 矩陣查詢

完整函式範圍約 `0x81A8E0–0x81A906`：

```asm
81A8E3 cmp al,0x4
81A8E5 jae 81A903              ; AL >=4 => 0
81A8E7 cmp cl,0xB
81A8EA jae 81A903              ; CL >=11 => 0
81A8EC mov edx,[ebp+8]        ; table/object pointer
81A8EF movzx eax,al
81A8F2 imul eax,eax,0xB
81A8F5 movzx ecx,cl
81A8F8 add eax,ecx
81A8FA mov ax,[edx+eax*2+4]   ; 2-byte entry, +4 header
81A900 ret 4
81A903 xor eax,eax
81A906 ret 4
```

直接確定：AL 索引 **0–3**；CL 索引 **0–10**；`table+4 + 2*(AL*11 + CL)` 的 16-bit unsigned 條目；任何索引超界回 0。**「4×11」是表形狀，不是四套攻擊、十一段連擊的遊戲語義。**

## 3. 新確認：`0x54F270` 的 gate 實際有三層條件

由原始 `0x54F270–0x54F32D` 組語確認：

1. **位元分類**：AL 若 bit6/7 非零，直接返回 1。否則依優先序把 bit0+1、bit0+2、bit1+2、bit0、bit1、bit2、bit3、bit4 分類為 CL=`4/5/6/1/2/3/7/10`；其餘直接返回 1。
2. **資料來源查找**：從 `[esi+2]` 的 WORD 和 caller 的 `[ebp+8]` 進行 `0x40F7F0 → 0x819220`。如 `0x819220` 返回 NULL，**返回 0**。
3. **矩陣及樹**：將 caller `[ebp+0xC]` 低位 BYTE 放入 AL，分類碼放入 CL，以第 2 步的指標作為矩陣基底，呼叫 `0x81A8E0`。若 WORD 結果 0，**返回 0**。若非零，結果被當成後續樹查詢 key，`0x54F4E0` 在 `[esi+4]` 指向的有序樹查詢 key；最終 `cmp dword [eax+4],0`，以 `sete` 轉為布林返回。

關鍵原文摘錄：

```asm
54F2D2 mov eax,[ebp+8]
54F2D5 movzx ecx,word [esi+2]
54F2D9 push eax
54F2DA push ecx
54F2DB call 40F7F0
54F2E0 call 819220
54F2E5 test eax,eax
54F2E7 jne 54F2F1
54F2E9 xor eax,eax             ; zero from lookup failure
...
54F2F1 push eax
54F2F2 mov al,[ebp+0xC]
54F2F5 mov cl,bl
54F2F7 call 81A8E0             ; AL<4, CL<11, table+4+2*(AL*11+CL)
54F2FC movzx eax,ax
54F2FF test ax,ax
54F302 je 54F2E9
54F304 mov edx,eax
54F306 add esi,4
54F309 push esi
54F30A lea eax,[ebp+8]
54F30D mov [ebp+8],edx
54F310 call 54F4E0             ; tree query, key storage at &ebp+8
54F315 xor ecx,ecx
54F317 cmp dword [eax+4],ecx
54F31A sete cl
54F31D mov eax,ecx
...
54F325 mov eax,1             ; bypass for bit6/7 or no candidate bits
```

**重新釐清**：`0x54F4E0` 不是直接讀取動作允許布林值的單層 array，而是**按 key 搜尋有序樹並返回 iterator/payload 指標**。最後 `[eax+4]==0` 的結構語義仍未證實，尤其不能把 `0` 直譯為「攻擊可取消」。不能把 `0x54F270` 的 1/0 直接命名為連段判定。

## 4. 新確認：`0x54F4E0` 的樹尋找過程

```asm
54F4E7 mov ebx,[ebp+8]        ; container argument
54F4EA mov ecx,[ebx+4]        ; tree header
54F4F1 mov eax,[ecx+4]        ; initial node
54F4F4 cmp byte [eax+0x21],0  ; terminal/sentinel marker candidate
54F4FC mov ecx,[edi]          ; key
54F500 cmp [eax+0xC],ecx
54F505 mov eax,[eax+8]        ; one tree branch
54F50A mov esi,eax
54F50C mov eax,[eax]            ; other branch
54F514 cmp esi,[ebx+4]
54F519 mov eax,[edi]
54F51B cmp eax,[esi+0xC]
54F520 mov edi,[edi]
54F542 call 54F7D0            ; insertion/helper on no exact bound
54F54E call 54F6A0            ; tree helper
54F553 mov eax,[ebp+8]
54F556 add eax,0x10           ; pointer into found/inserted element
54F562 ...
54F563 lea eax,[esi+0x10]    ; pointer into existing node
```

可核定有序節點比較 key、分支走訪、可能的插入／配套 helper，且返回節點內部 `+0x10` 指標。**仍不能證明「只查不寫」**：由 `0x54F542` / `0x54F54E` 可見另一分支呼叫容器 helper；須查 `0x54F7D0`、`0x54F6A0` 是否修改樹。這是目前比「攻擊允許表」命名更嚴謹的結論。

## 5. 新確認：`0xFB902C` 選擇 3 個 0x280-byte 輸入資料塊

初始化 `0x6D0750`：

```asm
6D0775 push 6D08E0
6D077A push 6D08C0
6D077F push 3
6D0781 push 0x280
6D0788 push 0xFB8834
6D079A call 892003
6D07A2 mov [0xFB902C],0
```

切換 `0x6D1A70`：

```asm
6D1A93 mov ebx,[ebp+8]
6D1A96 cmp ebx,3
6D1A99 jge 6D1B34
6D1A9F lea eax,[ebx+ebx*4]
6D1AA2 shl eax,7
6D1AA5 add eax,0xFB8834    ; +index*640 = +index*0x280
6D1AAA mov [0xFB902C],eax
6D1AB4 mov [0xFB9030],ebx
6D1B00 xor eax,eax
6D1B02 mov [0xFB9004],eax
...
6D1B16 mov [0xFB9014],eax
...
6D1B2F mov [0xFB9028],eax
```

三個塊的基底由計算直接得出：`0xFB8834`、`0xFB8AB4`、`0xFB8D34`，各間距 `0x280`。`0x6D0781` 實參 `0x280` 與索引公式互相印證。

**新增修正**：`0xFB902C` 僅有兩個 `.text` 中的精確直接引用（初始化清零、選擇指標），並非等於「只有兩個使用者」；存取選定 bank 的邏輯可能經各 bank 基底、指標別名或輸入聚合函式。`0x6D0B19` 確實出現 `0xFB8834 + (索引 <<4)` 的 indexed 元件存取，且 `0x6D4EF4` 亦為動態計算的 bank+row 索引，提供了**無須直接引用 `0xFB902C` 也會操作資料塊**的第一手例子。

> 注意 `cmp ebx,3; jge` 只是 signed 上界，負數值未在該函式明確檢查。三個有效 bank 的推導依 `0x6D0750` 初始化的三元素範圍及預期 caller 合法輸入；不應宣稱該函式自身對所有非法索引安全。

## 6. 新確認：資料塊中有 16-byte 元件的向量狀結構

`0x6D0B00–0x6D0B6C`：

```asm
6D0B0B lea esi,[esi+eax]
6D0B11 shl esi,4
6D0B19 add esi,0xFB8834
6D0B1F mov eax,[esi+4]
6D0B32 mov ecx,[esi]
6D0B47 cmp eax,[esi+8]
6D0B53 call 6D6240
6D0B58 mov eax,[esi]
6D0B5A lea ecx,[eax+edi*4]
6D0B68 mov ecx,[ecx]
6D0B6A mov [eax],ecx
```

這與 C++ `begin/end/capacity` 類型的三指標容器相容，尤其 `+0/+4/+8` 及四位元組元素追加／搬移。**但 `0x6D0Bxx` 所操作的是 bank 內的 row 結構，不等同已確認 `0xFB9014` 的 Z key writer。**

## 7. 綜合流程與偽碼

```cpp
// 確認位址計算，名稱僅為暫定
struct InputBankSelection {
    void* selectedBank; // global [0xFB902C]
    int selection;      // global [0xFB9030]
};

void SelectBank_candidate(int index) {
    // 注意：原生只有 signed index>=3 的上界分支。
    if (index < 3) {
        *(uintptr_t*)0xFB902C = 0xFB8834 + index*0x280;
        *(int*)0xFB9030 = index;
        // reset 0xFB9004..0xFB9028 in 4-byte steps
    }
}

uint16_t Matrix81A8E0(void* table, uint8_t type, uint8_t category) {
    if (type >= 4 || category >= 11) return 0;
    return read_u16((uint8_t*)table + 4 + 2*(type*11 + category));
}

// 不補猜角色語義、樹插入 side effects 或「允許取消」的 bool 名稱。
int Gate54F270_candidate(uint8_t bits, ...);
```

## 8. Z 連按／Z 按住的證據分級

| 待解項目 | 本段可確定 | 本段仍未知 |
|---|---|---|
| Z 連按 | 輸入機制具有多狀態、可能有不同事件位元 | Z 實際映射、重複按壓事件如何作用於動作節點 |
| Z 按住 | `0x547240` 有 500ms 時間分支（前段結果） | 該 byte 是否由 Z 所寫、是否達時間即續段 |
| 輸入資料來源 | 三個 `0x280` bank，含 16-byte row 的容器使用 | bank 代表角色/裝置/映射種類的哪一種；`0xFB9014` 非零 writer |
| 動作判定 | `0x54F270` 完整分類與查詢到 4×11 WORD 表／有序樹 | 4 與 11 的業務含義、表內容來源、樹返回指標的布林意義 |
| 普攻連段段數／取消 | 尚無可直接證實的段號與取消窗口 | 原版規則、服務端輸入接受與回覆配對 |

## 9. 下一段優先

1. 選 `0x6D0B00/0x6D4EF4` 的 bank 內 row，針對 **資料塊內 key code 到 `0xFB9004–0xFB9028` 聚合 bit** 查找完整讀／寫關係。按鍵 Z 的 scancode 候選僅做匹配，不直接指派。
2. 展開 `0x54F7D0`、`0x54F6A0`，確認 `0x54F4E0` 的查找是否有插入副作用，避免誤判 gate 語義。
3. 證明 `[esi+2]` 的實際來源及 `0x40F7F0 → 0x819220` 的物件類型，再透過具證據的 caller 接至普攻動作而不是單純的控制器一般輸入。
4. 額外核對是否存在 Z 按住時跨 frame 新指令生成，和 Z 連按時不同 input transition，以及兩者的合流點；查到實際資訊才推導取消窗口。

## 10. Git / 紀錄

本段是完整的指定地址靜態機器碼研究，不是整個 T10 Z 連擊機制的完整閉環。本地 Markdown 原稿已建立；未 Commit / Push，未變更其他 Task 的 owner、catalog 或技術筆記。研究結果中的所有函式名均為地址化暫名。