# KR T10-21 — 控制器輸入接入技能 availability gate

研究日期：2026-10-27 Asia/Taipei。KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；BIN 唯讀、PE .text VA 0x401000/raw 0x400。T10 普攻／T11 技能施放共用邊界，未執行目標，符號名稱暫定。本 GitHub 版是有證據摘錄的研究筆記；完整且更長的 objdump 連續節錄保存在另附本地長版原稿，兩者不是逐字一致。

## 本段新確認
同一條控制器處理鏈出現 `0x546263 call 0x546780`（聚合輸入）和 `0x5462DD call 0x54F270`（技能旗標可用性 predicate）。actor +0x3E8、矩陣索引、狀態 bytes 一同影響輸出 gate。

```asm
546263 call 546780
5462B4 mov ecx,[edi+3E8h]
5462D2 lea edx,[ecx+ecx*2]
5462DD call 54F270
5462E2 test eax,eax
5462E6 mov byte ptr [esp+17h],1
5462ED cmp dword ptr [edi+3E8h],0
5462FD mov edx,8000h
546302 and word ptr [ebx+2],dx
```

可確認輸入**受到技能可用性檢查**；不可直接推出普攻 Z、技能開始、連擊取消窗口或施放結果。actor+0x3E8 的正式語義未確認。與 T11 的交界是 **0x54F270 的消費者**，T10 不獨佔 T11 的 timer/cost writer。

## 下一段
展開 0x54F270 的 flag->key 映射、矩陣及冷卻記錄檢查；追 gate 返回值的相反分支。