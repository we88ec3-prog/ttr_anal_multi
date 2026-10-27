# KR T10-22 — T11 技能矩陣與狀態可用性檢查

研究日期：2026-10-27 Asia/Taipei。KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；BIN 唯讀、PE .text VA 0x401000/raw 0x400。T10 普攻／T11 技能施放共用邊界，未執行目標，符號名稱暫定。本 GitHub 版是有證據摘錄的研究筆記；完整且更長的 objdump 連續節錄保存在另附本地長版原稿，兩者不是逐字一致。

## 函式邊界
0x54F270..0x54F32F 是獨立有界 predicate。開頭 `test al,0xC0` 成功直接跳返回 1 的分支。其它 flags 對應 key：bit1/2/4 各別對 1/2/3；組合 3/5/6 對 4/5/6；0x08 ->7；0x10->10。

```asm
54F277 test al,0C0h
54F279 jne 54F325
54F28A mov bl,4
54F297 mov bl,5
54F2A6 mov bl,6
54F2C8 mov bl,7
54F2D0 mov bl,0Ah
54F2D5 movzx ecx,word ptr [esi+2]
54F2DB call 40F7F0
54F2E0 call 819220
54F2F7 call 81A8E0
54F2FF test ax,ax
54F310 call 54F4E0
54F317 cmp dword ptr [eax+4],0
54F31A sete cl
54F325 mov eax,1
```

矩陣 lookup 非施放決策；tree entry 的 +4==0 是此次可見的是否可用條件。T10-2 已證明 0x54F4E0 可能配置／插入節點，故雖然 predicate 的遊戲語義是查詢，不能宣稱毫無寫入副作用。沒有看到此處開始冷卻或扣資源。

## T11 標記
0x54F270：技能可用性檢查（確立）。0x819220/81A8E0：矩陣 lookup（確立）。0x54F4E0：可能變更樹的 entry lookup（確立）；實際 cooldown writer 未找到。不可拿 500ms input state 或 CHAIN_WINDOW=.65 代替原生取消門檻。

## 下一段
比對四個直接 callsite 的 caller-specific 前置 gate 與回傳值消費。