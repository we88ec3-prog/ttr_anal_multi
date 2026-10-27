# T08-134 — Keyed record lookup and two upstream paths

來源：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，原始 BIN x86 objdump 靜態驗證，未動態執行。

0x007E8640 由 source+0x3EB0 字串轉入 table+4 或 table+0x14 的子容器。0x007E8AE0 中 0x007E8B1C call 0x007E8E00 查找；0x007E8B2D call 0x0049B230 比較候選鍵。

原始 ASM：

    007E8B0E mov ebx,[ebp+8]

    007E8B11 mov edi,ecx

    007E8B13 push ebx

    007E8B1C call 007E8E00h

    007E8B23 cmp esi,[edi+4]

    007E8B28 lea eax,[esi+0Ch]

    007E8B2D call 0049B230h

上游 A：0x007A89CE cmp [ebx+150h],0；不存在時 0x007A89F6 call 0x007BAE80，0x007A89FB mov [ebx+150h],eax；0x007A8A01 mov ebx,[ebx+150h]，0x007A8A18 call 0x007E8640。

上游 B：0x007BABBE mov edi,[esi+0A8h]；0x007BABC4 sub edi,[esi+0A4h]；0x007BABCC sar edi,2；0x007BABD3 mov ecx,[esi+0A4h]；0x007BABD9 mov edx,[ecx+ebx*4]；0x007BABDC mov eax,[edx+34h]；0x007BABED call 0x007E8640。

資料流：object+150 (可能由 7BAE80 建立) -> 7A8A18 -> 7E8640；或 owner A-array entry+34 -> 7BABED -> 7E8640；接著 +4/+14 child -> 7E8AE0 -> record+20 append。

已確認：兩個 source 導向同一按字串分組記錄表。合理推測：記錄採名稱索引；尚未證實其實際業務語義。這個子容器+4 不是 priority entry vtable+4，亦不能將 +14 誤當 owner B array。
