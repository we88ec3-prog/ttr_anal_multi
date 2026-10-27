# KR T10-11 — 0x546B50 次級輸入 gate、邊沿旗標與位置角度
日期：2026-10-27 Asia/Taipei；KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。只讀原始 x86 BIN，函式命名暫定。
## 問題與驗證
0x546780 的第二路 0x546B50 是否是真正的 Z 連按？本段完整展開該 helper 的狀態源、控制器欄位與輸出，避免把每個 edge gate 誤認為攻擊連擊。
## 第一手 evidence
```asm
546B5E mov eax,ds:[0xFBA80C]
546B69 push 0x57C
546B6E call 0x891268
546B7C call 0x6F1370
546B85 mov ds:[0xFBA80C],eax
546B8A mov edx,ds:[0xFB1318]
546BA0 mov ecx,[edx+0xC01C]
546BA6 shr ecx,1
546BAD test BYTE PTR [edx+0xC01C],0x1
546BB6 mov DWORD PTR [edi+0x7C],0x1
546BBD mov DWORD PTR [edi+0x80],ebx
546BC3 cmp DWORD PTR [ebp+0x10],ebx
546BC8 mov DWORD PTR [edi+0x7C],ebx
546BCB mov DWORD PTR [edi+0x80],ebx
546BFB cmp DWORD PTR ds:[0xFE1E20],ebx
546C03 mov ecx,0x1
546C08 mov ds:[0xFE1E20],ecx
546C19 mov [edi+0x80],ecx
546C1F mov [edi+0x7C],edx
546C24 mov ds:[0xFE1E20],ebx
546C79 mov ecx,[ebp+0x8]
546C7E mov edx,[eax+0x4C]
546C81 call edx
546C85 call 0x434740
546C92 call 0x79A6B0
546CD0 call DWORD PTR ds:[0xBD25F8]
546CDE call 0x8FEDCA
546D0B call 0x4BB450
546D2C call 0x4BB450
546D39 mov BYTE PTR [ecx],al
```
FBA80C 懶初始化於 0x57C 配置，FB1318+0xC01C bit gate 有時阻止更新；第三參數非零立即清 controller+0x7C/+0x80 並返 0。FE1E20 維持一次性觸發、清零流程，配合 +0x7C/+0x80 狀態。後段使用 vtable +0x4C、座標差、三角函式和角度 byte，屬指標／方向輸入候選而非確定攻擊。
## C++ 暫定模型
```cpp
bool inputSecondary(Controller* c, Actor* a, uint8_t* angle, bool block) {
 if (block) { c->flag7C=0; c->state80=0; return false; }
 if (!passesDeviceAndGlobalGate()) return false;
 if (needsDirection()) *angle=quantizePositionDerivedAngle();
 return true; // 僅流程草圖，非所有分支重建
}
```
## 限制與待查
已確認：指標配置、旗標測試、全域與 controller 寫入、資料位置衍生角度。推測：指標／滑鼠類取向。未確認：Z 的 keydown、普攻連段 index、0xFE1E20 是否是按鍵 debounce、actor motion 綁定。下一段核第三路 0x546D50。完整長版組語在本地 T10-11 Markdown。