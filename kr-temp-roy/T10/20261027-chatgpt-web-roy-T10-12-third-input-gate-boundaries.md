# KR T10-12 — 0x546D50 第三路裝置方向與連段證據邊界
日期：2026-10-27 Asia/Taipei。原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，原檔唯讀，PE .text VA 0x401000 / raw 0x400。以下位址為 VA，非正式符號名稱均暫定。
## 獨立追查
T10-7 的輸入合流第三路呼叫 0x546D50。本段展開 0x546D50..0x546EEC（後續 0x546EF0 是**新函式入口**，不可混入）。
## 核心 BIN 證據
```asm
546D7B test BYTE PTR ds:[0xFB7C14],0x1
546D93 call 0x6D0750
546DAD cmp DWORD PTR ds:[0xFB8830],0x0
546DB4 jne 0x546ED9
546DBA mov eax,ds:[0xFB1318]
546DBF mov edi,[eax+0x10]
546DC2 call DWORD PTR ds:[0xBD245C]
546DC8 cmp eax,edi
546DCA jne 0x546ED9
546DFD push 0x0
546E03 call 0x6F3350
546E08 fild DWORD PTR [esp+0x18]
546E10 fild DWORD PTR [esp+0x1C]
546E20 fmul st(0),st
546E24 fmulp st(2),st
546E26 faddp st(1),st
546E30 call 0x8FF870
546E39 fld DWORD PTR ds:[0xC55CAC]
546E43 fcomip st,st(1)
546E47 jbe 0x546ED9
546E55 call DWORD PTR ds:[0xBD25F8]
546E63 call 0x8FEDCA
546E90 call 0x4BB450
546E9A call 0x434740
546EB1 call 0x4BB450
546EBE mov BYTE PTR [ecx],al
546EC0 mov eax,0x1
546ED9 xor eax,eax
546EEC ret 0x4
546EF0 push ebp     ; 下一獨立函式
```
前置 guard 涉及 FB8830、全域物件 FB1318+0x10 與 IAT 0xBD245C 返回值比對。其 IAT 函式名稱本輪**未直接驗證**。0x6F3350 取得的二個整數值經 float 平方加總與 0x8FF870，再和常數 0xC55CAC 比較。越過門檻才使用三角計算與另一角度來源合成 byte 並返回 1，否則返回 0。座標系和角度單位未確認。
## T10-9～12 可驗證的整體邊界
```text
0x6D4A93 / 0x6D4B69 -> FB9004..FB9028 清零
 [正常鍵盤事件 writer 尚未定位] -> FB9014 -> 0x547240 -> 0x546780 mask
FB9005..FB9008 -> 0x546850 四向 -> byte angle ────┐
裝置與位置狀態 -> 0x546B50 次級 byte angle ──────┼-> 0x546780 byte 選擇
裝置與座標門檻 -> 0x546D50 第三路 byte angle ───┘
                  -> 0x546100 控制器下游限制
```
## 已確認 / 推測 / 未解
已確認：上述讀取、批次清零、三條 helper 的明確分工、部分 guard 與 angle byte。推測：第二／第三路具指標方向特徵。未解：Z 的實際 KeyMapping.xml row、按下 edge 與 held 差異、連段 next-motion 消費者、取消窗口、服務端權威。前段 500ms 與本機自製 CHAIN_WINDOW=0.65 不可直接當原版 combo 規則。
## 下一段 T10-13
沿 FB9004 基底的**間接寫入**、實際 Table/KeyMapping.xml、普攻 animation 完成與續段入口追查，不重複已有方向裝置支線。排除 T12 傷害公式；原始遊戲不執行、不修改。
長版完整組語證據保存在本地 T10-12 獨立 Markdown 原稿。