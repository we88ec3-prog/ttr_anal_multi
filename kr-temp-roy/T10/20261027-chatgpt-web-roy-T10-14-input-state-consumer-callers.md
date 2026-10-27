# KR T10-14 — 狀態 Getter 的呼叫者與分流

來源：KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；.text VA 0x401000/raw 0x400；2026-10-27 Asia/Taipei。BIN 唯讀靜態反組譯，不執行遊戲。函式語義與 C++ 名稱均暫定。以下為可獨立理解的技術筆記；更長的逐址組語另在同名本地原稿。

## CALL rel32 交叉參照與新結果
限定 KR BIN .text 直接 E8 relative call 掃描，`0x6D4CE0` 的兩個直接 caller 為 `0x59624E` 與 `0x59643F`（不涵蓋間接/虛呼叫）。第一呼叫者將查詢結果與 1、3 比較，分別通往不同的 controller/object gate；第二呼叫者把結果與 1 比較並進入額外的 gate。可證實有多相位分流，未證明 state==1 是 keydown、state==3 是 keyup。

### 精確錨點
```asm
59624E call 0x6D4CE0
596267 cmp eax,1
596275 mov eax,[edx+0xEC]
59627C call eax
5962BC cmp eax,3
5962CE mov eax,[edx+0xF0]
5962D5 call eax
596299 push 1
59629D call 0x596140
5962FB call 0x82EF00
59643F call 0x6D4CE0
596444 cmp eax,1
596456 mov edx,[eax+0xEC]
59645D call edx
```

### 暫定流程
```cpp
auto phase = QueryState(key);
if (phase==1) { /* virtual +EC checks; owner filter; optional dispatch */ }
else if(phase==3) { /* virtual +F0 checks; owner +0x80 mapping */ }
```
為避免符號誤導，以上只表示 CFG，不能稱為原版 Z 攻擊，亦不能把 1/3 等同 pressed/released。待追 0x5961C0 與 0x5963xx 的上游輸入循環與真正的非零值 writer。

## 提交來源和可重現性
BIN 使用原本 PE .text section 映射；每個地址均為 VA。上述組語是逐址節錄；完整連續片段保留在該段獨立本地原稿，遠端版不是逐字的本地長版替身。