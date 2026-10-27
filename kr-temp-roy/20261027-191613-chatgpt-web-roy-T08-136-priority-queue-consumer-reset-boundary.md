# T08-136 — Priority queue consumer and reset-zero-length evidence

來源：Tartaros.bin 12,472,320 bytes SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；原始機器碼靜態分析，沒有動態驗證。

兩個直接 caller：0x0079A394 和 0x007BAC79。0x007BB640 使用 [ESI+B4/B8] begin/end 和 [ESI+C4] 限制 min(cap,count)。呼叫 0x007BB7B0 first=begin,middle=begin+4*n,last=end；對前 n 個 entry 間接呼叫 entry->vtable+4。其在全域22桶 dispatcher 之前執行，並不構成直接產生22桶 entry 的證據。

原始 ASM：

    007BB664 mov eax,[esi+0B8h]

    007BB66A sub eax,[esi+0B4h]

    007BB670 mov ebx,[esi+0C4h]

    007BB676 sar eax,2

    007BB679 cmp ebx,eax

    007BB6D7 lea eax,[edx+ebx*4]

    007BB6DC call 007BB7B0h

    007BB6F0 mov ecx,[esi+0B4h]

    007BB6F6 mov ecx,[ecx+edi*4]

    007BB6FB mov eax,[edx+4]

    007BB6FE call eax

新稽核：在 begin != end 路徑，0x007BB715 mov eax,ecx，緊接 0x007BB717 sub eax,ecx，故 eax=0，0x007BB719 sar eax,2 和 0x007BB71C lea ebx,[eax*4] 也為0。0x007BB723 push ebx、0x007BB724 push ecx、0x007BB725 push edi、0x007BB726 call 0x008916F0 的長度參數因此為0；0x007BB72E add ebx,edi，0x007BB730 mov [esi+0B8h],ebx，等同 end=begin。不能據此聲稱每個 entry 都被釋放。

偽碼：n=min((end-begin)/4, owner->limit_C4); selection_sort_like(begin, begin+n, end, comparison_context); for(i=0;i<n;i++) begin[i]->vtable_04(); if(begin!=end){call_helper_8916F0(begin,end,0); end=begin;}

未解：owner+B4 writer、entry vptr 的 +4/+8 實體地址、與全域22桶 producer 的直接呼叫鏈。T08-137 應監視 owner+B8 的非初始化寫入並記錄當時 entry vptr；動態方案本輪未執行。T08-133～136 分段靜態分析完成，但不聲稱完成整條 B producer 身分鏈。
