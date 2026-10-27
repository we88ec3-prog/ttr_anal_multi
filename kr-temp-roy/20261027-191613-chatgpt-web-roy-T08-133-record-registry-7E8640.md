# T08-133 — 0x007E8640 record registry and owner identity

來源：Tartaros.bin，12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；使用 objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 直接分析，未做動態驗證。

新確認：0x007E8640 的 E8 直接 caller 為 0x007A8A18 與 0x007BABED。兩處都 push source，再 push [0x00FBA838]+0x8C。callee [EBP+8] 指向 table， [EBP+0xC] 指向 source。0x007E867A 對 source+0x3ECC 做 inc；0x007E8689 使用 source+0x3EB0 字串，依 source+0x0 分支，用 table+4 或 table+0x14 呼叫 0x007E8AE0。

原始 ASM：

    007E8677 mov eax,[ebp+0Ch]

    007E867A inc dword ptr [eax+3ECCh]

    007E8680 mov ebx,[ebp+8]

    007E8689 lea edi,[eax+3EB0h]

    007E86D1 lea ecx,[ebx+4]

    007E86DC call 007E8AE0h

    007E877D lea ecx,[ebx+14h]

    007E8788 call 007E8AE0h

    007E87F7 lea edi,[esi+20h]

    007E87FA call 007BB750h

    007E881C ret 8

原始 caller：0x007A8A0B mov eax,[0x00FBA838]；0x007A8A10 mov ecx,[eax+8Ch]；0x007A8A16 push ebx；0x007A8A17 push ecx；0x007A8A18 call 0x007E8640。另一條 0x007BABDC mov eax,[edx+34h]，0x007BABDF mov ecx,[0x00FBA838]，0x007BABE5 mov edx,[ecx+8Ch]，0x007BABEB push eax，0x007BABEC push edx，0x007BABED call 0x007E8640。

抽象偽碼：register_record(Table* table, Source* source) { ++source->field_3ECC; Record* r=lookup_by_source_string(table, source->string_3EB0); if(!r->field_0) r->field_0=1; append_pointer(&r->vector_20,source); }

已確認：最終 append 容器是 record+0x20，不是已知 owner+0xB4。未證實：計數含義、記錄後續是否產生 B queue entry；不得將本函式稱為 B queue 直接 producer。
