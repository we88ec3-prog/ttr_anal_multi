# T10-085 — 輸入 phase 清零與事件容器：非零 writer 證據界線

## 原始來源與方法
KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，已於本輪本機重新核對。PE32 .text VA 0x401000，raw 0x400。GNU objdump -D -Mintel，靜態唯讀。延續 T10-081～084，保持原生／部分確認／未知分級。

## 逐指令證據

```asm
006d4a93 xor eax,eax
006d4a95 test BYTE PTR ds:0xfdf3ec,0x1
006d4a9c mov ds:0xfb9004,eax
006d4aa1 mov ds:0xfb9008,eax
006d4aa6 mov ds:0xfb900c,eax
006d4aab mov ds:0xfb9010,eax
006d4ab0 mov ds:0xfb9014,eax
006d4ab5 mov ds:0xfb9018,eax
006d4aba mov ds:0xfb901c,eax
006d4abf mov ds:0xfb9020,eax
006d4ac4 mov ds:0xfb9024,eax
006d4ac9 mov ds:0xfb9028,eax
006d4b69 xor eax,eax
006d4b6b mov ds:0xfb9004,eax
006d4b70 mov ds:0xfb9008,eax
006d4b75 mov ds:0xfb900c,eax
006d4b7a mov ds:0xfb9010,eax
006d4b7f mov ds:0xfb9014,eax
006d4b84 mov ds:0xfb9018,eax
006d4b89 mov ds:0xfb901c,eax
006d4b8e mov ds:0xfb9020,eax
006d4b93 mov ds:0xfb9024,eax
006d4b98 mov ds:0xfb9028,eax
006d4c20 mov esi,DWORD PTR [edi+0x8]
006d4c23 lea ecx,[esi-0x2711]
006d4c29 cmp ecx,0x270e
006d4c2f ja 0x6d4c82
006d4c64 mov ecx,0xfdf630
006d4c69 mov [ebp+0x8],esi
006d4c6c call 0x82ef00
006d4c7c mov BYTE PTR [eax+0x10],0
006d4cae mov BYTE PTR [esi+0xfb9004],0
006d4d05 lea eax,[esi-0x2711]
006d4d0b cmp eax,0x270e
006d4d42 lea eax,[ebp-0x14]
006d4d45 mov ecx,0xfdf630
006d4d4d call 0x82ef00
006d4d5d movzx eax,BYTE PTR [eax+0x10]
006d4d93 cmp esi,0x27
006d4d98 movzx eax,BYTE PTR [esi+0xfb9004]
```

## 分析
1. 0x6D4A30 的兩條初始化分支將 0xFB9004 起 40 bytes 全部清零；所見 DWORD writes 的來源 eax 已由 xor eax,eax 直接確認為 0，非 phase=1/3 writer。
2. 0x6D4C06 起迭代事件容器節點，從 node+8 取 ID，特殊 ID 10001..19999 以 0x82EF00 在 0xFDF630 關聯結構定位後清除 node+0x10；一般 ID 使用 0xFB9004+ID 清零。這兩種記憶體模型不可混為同一 array。
3. 0x6D4CE0 同時支援 10001..19999 節點型 reader 和普通 0..39 phase-byte reader。對應 KeyMappingExtra 的高 MapButton ID 是待查線索，不能在無 producer 證據時宣稱已完全連接兩張 XML。
4. 本段沒有找到非零 phase writer；初始化／reset 不能被當成 keydown/keyup producer。事件容器 callsite 0x490DFC、0x58A607 應向前追產生者。對於指標別名、base+offset、虛擬 callback，負面 literal xref 掃描不具排除能力。

## 研究邊界
已確認：原始指令、ID 數值範圍、明確清零、reader 分流。尚待驗證：高 ID 具體語義、掃描碼 producer、phase=1/3 非零 writer、動作 consumer、連段／取消。沒有執行遊戲或修改其他 Task。