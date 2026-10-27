# T08-135 — Pointer-vector append ABI, three verified owners

來源：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；objdump 直接反組譯。

0x007BB750 是通用 DWORD vector append：EDI 指向 begin/end/capacity 三指標容器，EAX 指向待加入的 DWORD 槽，end=capacity 時經 0x00797D30 擴容。正常複製寫入 [end]，接著 [EDI+4]+=4。

原始 ASM：

    007BB750 push esi

    007BB751 mov esi,eax

    007BB753 mov eax,[edi+4]

    007BB765 cmp eax,[edi+8]

    007BB76C call 00797D30h

    007BB771 mov eax,[edi+4]

    007BB77D mov [eax],edx

    007BB77F add dword ptr [edi+4],4

    007BB785 cmp eax,[edi+8]

    007BB78C call 00797D30h

    007BB798 mov ecx,[esi]

    007BB79A mov [eax],ecx

    007BB79C add dword ptr [edi+4],4

已核實三個容器身份：0x007BB61A add edi,0A4h -> 0x007BB623 call 0x007BB750 寫 A array；0x007E87F7 lea edi,[esi+20h] -> 0x007E87FA call 0x007BB750 寫分組記錄 vector；0x007B96CB lea edi,[ebx+7Ch] -> 0x007B96D1 call 0x007BB750 寫 group array。

注意：不同類型物件的相同欄位偏移不能互換。於近端 0x007B8E00..0x007BCF00 所見 B end 的 0x007B8F7C 初始化清零、0x007B91E8 析構清零和 0x007BB730 consumer reset，並非非初始化增長 writer。

已確認：以上三條不是 B queue producer。未證實：完整程序的 owner+B4 append writer；通用 helper 的其餘 call site 需要逐一核實實參 EDI 來源；單純 offset +B4 搜尋不足以證實身分鏈。
