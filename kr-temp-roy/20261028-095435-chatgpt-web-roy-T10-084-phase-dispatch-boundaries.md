# T10-084 — KR 即時鍵狀態 reader、事件派送條件與 phase writer 缺口

- 研究日期：2026-10-28 Asia/Taipei，KR T10，唯讀靜態分析。
- 原始 BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- .text VA 0x401000 / raw 0x400；反組譯整個 BIN 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。

## 1. reader 的 ID 寄存器已補證

T10-82 遺留 `0x5961C0` 的 esi/edi 關係未定。本段在原始 x86 確認：

```asm
005961ed mov eax,ebx
005961ef call 0x761010
005961f4 xor edi,edi
00596245 mov esi,edi
00596247 mov byte ptr [ebp-0xe],0
0059624b mov [ebp-0x24],edi
0059624e call 0x6d4ce0
00596253 cmp byte ptr [ebp-0xf],0
00596257 je 0x596267
00596259 cmp edi,0xd
0059625c je 0x596267
0059625e cmp edi,0xe
00596261 jne 0x596386
00596267 cmp eax,1
0059626a jne 0x5962bc
00596275 mov eax,[edx+0xec]
0059627b push edi
0059627c call eax
005962bc cmp eax,3
005962ce mov eax,[edx+0xf0]
005962d4 push edi
005962d5 call eax
```

`0x6D4CE0` 普通 ID 0..39 讀取 `byte[0xFB9004 + esi]`；`0x5961C0` loop 先 `esi=edi`，故 ID 13..16 都在 reader 所掃區間。狀態值 1/3 分別引導不同虛擬槽位 `+0xEC/+0xF0`。不含符號證據時不能為其命名 AttackPress/Release。

## 2. 嚴格限定的事件派送抑制

`0x59623B cmp [0xFB73E8],edi; setne [ebp-0xf]`，當此全域欄位非零時，`0x596259..0x596261` 允許 ID 13、14 經此函式的分派檢查，其他 ID 跳向本輪尾 `0x596386`。**只可說明這條函式內的當前條件分支**；尚不能聲稱 ID15/16 全遊戲停用，或此全域變數是戰鬥姿態／連段限制。

`0x596201..0x59620B` 另將 `0x761010` 所得物件 `[+0x28]` bit13 轉為局部旗標 `[ebp-0xd]`。phase1 先呼叫可得子物件 vtable+0xEC，再依返回值與條件 fallback 到 this vtable+0xEC；phase3 對應子物件 vtable+0xF0 與後續 fallback/傳播；未還原 vtable 的實際 owning class 或其 motion consumer。

## 3. 全 .text 原始碼地址 literal 掃描

經 `objdump` 全 KR BIN 搜尋位址直值：
- `0x548957`：`movzx eax,byte ptr [esi+0xfb9004]` — reader。
- `0x6D4D98`：`movzx eax,byte ptr [esi+0xfb9004]` — 普通 ID reader。
- `0x6D0875`, `0x6D1B02`, `0x6D4A9C`, `0x6D4B6B`：直接寫 `0xFB9004` 起點 DWORD，須結合上游 eax 證明實際值；先前清零路徑不等於非零 writer。
- `0x6D4CAE`：`mov byte ptr [esi+0xfb9004],0`，明確清零。
- `0x6D07A2`, `0x6D1AAA` 更新 `0xFB902C`；`0x6D07A8`, `0x6D1AB4` 更新 `0xFB9030`。

本輪沒有透過 literal xref 找到把 phase byte 直接寫 1 或 3 的原生非零 writer。**負面搜尋不能證明不存在**：writer 可能使用 base+offset、指標別名、callback、block copy、另一輸入子系統。掃描只涵蓋可解析的絕對常量引用，非所有寫入路徑。

## 4. 可用的連接鏈與未閉合處

確認鏈：Type0/1 XML 或外部資料→bank0/1→bank2→`0x6D4DC0` 查鍵列表；runtime `[0xFB9004+ID]`→`0x6D4CE0`→`0x5961C0`→vtable+0xEC/+0xF0。**這兩段鏈在 scan code→phase writer 處尚未閉合**，且第二段亦未被證明到角色 motion／queue／cancel。

T10-85 定向目標：
1. `0x6D4A30/0x6D4B00` 附近找 phase alias writer 與 DIK/GetDeviceState producer；核對掃描碼 Key44..47 的原始解讀。
2. `0xFB73E8` 非零 writer 與語意及 ID13/14 特例的上下游。
3. `0x761010` 所返物件和 vtable+0xEC/+0xF0 的實際實作，再跨角色 controller/motion。
4. 原生 Z 連按/持按、V tap/hold 及 queue/cancel 時窗一律未定，不使用 AI `CHAIN_WINDOW=.65`、SubAI >60、>500ms 等代替。

證據分類：已確認寄存器與分支；部分確認事件分派界面；未確認非零 phase writer／原生動作與取消規則。未改其他任務資料，未新增原始遊戲檔。
