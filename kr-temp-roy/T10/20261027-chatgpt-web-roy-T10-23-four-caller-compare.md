# KR T10-23 — 技能 availability 四處呼叫者交叉比對

研究日期：2026-10-27 Asia/Taipei。KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；BIN 唯讀、PE .text VA 0x401000/raw 0x400。T10 普攻／T11 技能施放共用邊界，未執行目標，符號名稱暫定。本 GitHub 版是有證據摘錄的研究筆記；完整且更長的 objdump 連續節錄保存在另附本地長版原稿，兩者不是逐字一致。

## 直接呼叫者（已有 T11 audit；本批逐址核對）
```asm
5462DD call 54F270
54827F call 54F270
549C0E call 54F270
549D54 call 54F270
```
這僅是 direct E8 callsites，不覆蓋間接 callback。

- 0x5462DD：前方 0x546263 聚合輸入；回傳非零設定 local byte，否則還檢查 actor+0x3E8 並可能將輸出 word 低15 bits 清掉。T10 控制器→T11 gate。
- 0x54827F：另一控制器路徑，先檢查 actor +0x158、0x4C9ED0；依 output word 的低位組合 flags；回傳非零也置 local flag。**不是同一個攻擊鏈的第二階段**。
- 0x549C0E：SubAI condition 相關路徑，前面檢查 actor+0x3C8/+0x3CC/+0x3D0；後續還檢查 [ebp+14h] 與 actor+0x3E8。
- 0x549D54：回傳非零後寫 object+0x72 及 object+((object+0x108)*16)+0xAC 為 DWORD 4。

```asm
549C0E call 54F270
549C13 test eax,eax
549C25 mov edx,[esi+50h]
549C28 cmp [edx+3E8h],edi
549D54 call 54F270
549D59 test eax,eax
549D5D mov ax,[esi+72h]
549D7D mov dword ptr [esi+edx*8+0ACh],4
```

0x549D7D 確定寫入狀態常數 4，但不得未驗證就叫做冷卻計時、連段段數或取消成功；其中 edx 來自 [esi+0x108] *2。T11 可接續追 reader/initializer/reset。