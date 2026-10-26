# T08 第七十段：主物件元件表的 25 個槽位與析構迴圈

- 作者：chatgpt-web roy
- 時間：2026-10-27 01:47:50 Asia/Taipei (+08:00)
- 樣本：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
- 依據：原始 PE 的 objdump -d -Mintel，非推測的反編譯輸出。

## 已確認的新發現

在 0x004C7D6B–0x004C7D90，析構清理流程逐一走訪 owner+0xF4 的元件指標表：

```asm
004C7D6B  lea esi,[ebx+0xF4]
004C7D71  mov edi,0x19
004C7D76  mov ecx,[esi]
004C7D78  test ecx,ecx
004C7D7A  je 0x004C7D8A
004C7D7C  mov eax,[ecx]
004C7D7E  mov edx,[eax]
004C7D80  push 1
004C7D82  call edx
004C7D84  mov DWORD PTR [esi],0
004C7D8A  add esi,4
004C7D8D  dec edi
004C7D8E  jne 0x004C7D76
004C7D90  mov [ebx+0x158],edi
```

- 25 個槽位，索引 0..24，指標跨度 4 bytes；位置為 owner+0xF4 至 owner+0x154。
- +0x158 在表外；迴圈結束時 EDI=0，該欄位被清空。
- 非空元件呼叫其 vtable+0x00，傳入 1，然後將槽位清零。
- 這是釋放元件，不是呼叫 vtable+0x04 的事件入口；不可據此聲稱事件 7、8 在此觸發。

## 建構端交叉驗證

0x004C7306–0x004C7314：呼叫 0x004CB230 初始化 Type 4，再設定 vtable=0x00C077E4；後續根據 component+0x08 類型索引存入 owner+0xF4+4*type。
0x004CB850 是 Type 4 vtable+0x04，設定事件 8；0x004CB590 是 Type 3 vtable+0x04，設定事件 7。這些方法的實際調度者仍未直接定位。
0x004C7DF0 的事件重播使用的是 owner vtable+0x68 並取 owner+0x38C，而非元件 vtable+0x04。

## 尚未確認

- 誰在何種條件下間接呼叫 component vtable+0x04。
- 命令 26 是否曾在元件析構之前觸發 Type 4 事件 8。
- 事件 7、8 的遊戲語意（不能直接命名為死亡事件）。
- 主物件析構與某個具體網路命令之間的所有中間呼叫路徑。

## 後續

搜尋 component+0x08 的索引讀取和間接 vtable+0x04 的調度者；必要時在執行期對 0x004CB850 與 0x004CB590 設斷點，記錄呼叫堆疊及 owner+0x04、owner+0x38C 值。
