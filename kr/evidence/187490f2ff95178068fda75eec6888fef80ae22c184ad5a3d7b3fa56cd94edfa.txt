# T08-111：內嵌分桶逐筆 consumer 與指標來源

研究者：chatgpt-web roy。2026-10-27 Asia/Taipei。BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91（本輪已用 sha256sum 驗證）；原始 x86 objdump 機器碼一級證據，函式名稱暫定。

## 確認的桶資料流

0x007D1310：EBX 來自函式參數 [EBP+8]，不是由函式直接載入全域 [0x00FB7740]。每桶 0x2004 bytes，包含2048筆 4-byte entries 和最後一個 count。已觀察 bucket index 1、2、4、15 分別使用 count +0x4004、+0x6008、+0xA010、+0x2003C。以 entry 的 vtable+0x0C 派送 stage，再把 count 清零。

~~~asm
007D13C4 mov ebx,[ebp+8]
007D13DC mov ecx,[ebx+edx*4+0x2004]
007D13E5 mov edx,[eax+0xc]
007D13E8 push 1
007D13EA push esi
007D13EB call edx
007D1405 mov DWORD PTR [ebx+0x4004],0
007D1452 mov ecx,[ebx+edx*4+0x4008]
007D1476 mov DWORD PTR [ebx+0x6008],0
007D14E0 mov ecx,[ebx+edi*4+0x8010]
007D14FC mov DWORD PTR [ebx+0xa010],edi
007D1510 mov ecx,[ebx+edi*4+0x1e03c]
007D152C mov DWORD PTR [ebx+0x2003c],0
~~~

此處 count 歸零不表示 entries 每個槽都被設0，也不能由此推斷 entry object 已釋放。桶 layout 符合全域22桶，但參數 EBX 實際 base 尚無直接證據確定指向 [0x00FB7740]。先前 T08-107 已確認另一條 0x007D3601 -> 0x0079A3C0 是全域桶 producer，不能套用到本 consumer。

~~~cpp
void drain(BucketOwner* owner, int stage, Manager* manager) {
 auto& bucket=owner->buckets[stage];
 for(int i=0;i<bucket.count;i++) bucket.entries[i]->virtual0C(manager,stage);
 bucket.count=0;
}
~~~

已確認：stride、迴圈、stage、清零。未知：caller 的 EBX 實參、全域 consumer 身分、各 entry 具體 vtable 實作。下一段112追六係數。