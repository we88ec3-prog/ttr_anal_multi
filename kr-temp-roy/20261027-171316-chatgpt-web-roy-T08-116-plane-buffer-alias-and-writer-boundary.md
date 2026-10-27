# T08-116 — 六平面係數別名、讀取者與寫入者證據邊界

研究者：chatgpt-web roy；日期：2026-10-27（Asia/Taipei）。
原始來源：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；本輪實際由本機 sha256sum 核實。以下 VA/ASM 由 BIN 的 objdump -d -Mintel 及 .rdata 原始位元組核對。若僅是結構相容，不推導成指標同一性。

## 全域緩衝生命週期

```asm
00798E3A push 0x60
00798E41 call 0x00891268
00798E4D fldz
00798E4F fst dword ptr [eax]
00798E51 fst dword ptr [eax+4]
00798E54 fst dword ptr [eax+8]
00798E57 fst dword ptr [eax+0xc]
00798E93 fstp dword ptr [eax+0x5c]
00798E9C mov dword ptr [0x00FB76B0],eax
0079963F mov eax,[0x00FB76B0]
00799649 call 0x0089120C
00799651 mov dword ptr [0x00FB76B0],edi
```

0x60=96 bytes；24 floats，分六組四個 float。0x00798DE0 是零初始化，0x007995xx 是釋放／置零；兩者不是正常運行階段的內容更新者。

## 兩條消費讀取鏈

```asm
007D13FE push 3
007D1400 push 0x00FB76A8
007D140F call 0x0079B520
0079B5BC mov edx,[esi+8]
0079B5DA call 0x00838860
007F754A mov edi,[0x00FB76B0]
007F7562 mov edx,edi
007F7578 call 0x00838860
007F75A1 mov edx,edi
007F75B0 call 0x00838800
007F75C7 mov edx,edi
007F75D6 call 0x00838800
```

當 0x0079B520 的 ESI 為傳入的 0x00FB76A8 時，ESI+8 指向 0x00FB76B0，故可作同一指標槽的間接別名。但只是 **read**，不能倒推寫入方。

0x007F754A 取得六係數指標於 EDI，對同一個物件的多組坐標執行 0x00838860 和 0x00838800。原始機器碼還顯示：0x007F7558 先從 object+0x68 取 float、0x007F7564/0x756B/0x7572 取 object+0x34/+0x30/+0x2C，並呼叫 0x00838860；通過後再讀 object+0x40/+0x3C/+0x38 進行 0x00838800；之後再依 +0x4C/+0x48/+0x44, +0x58/+0x54/+0x50 等三 float 組繼續測試。

## 另一個不同陣列的來源邊界

0x00799D7E 讀取 [0x00FB76A8] 所指的核心物件；0x00799D83 取 [core+0x54]；0x00799D86 用 ECX=0x11 並於 0x00799D91 執行 rep movsd（17 DWORD）；0x00799D93 另外 lea [core+0x98]，ECX=0x0D，0x00799DA4 再 rep movsd（13 DWORD）。這只是複製 **core 內嵌矩陣／狀態值** 到 stack，不能誤認為寫到 [0x00FB76B0] 指向的 96-byte heap buffer。

```asm
00799D7E mov eax,[0xfb76a8]
00799D83 lea esi,[eax+0x54]
00799D86 mov ecx,0x11
00799D91 rep movsd
00799D93 lea esi,[eax+0x98]
00799D99 mov ecx,0xd
00799DA4 rep movsd
```

## 結論與 T08-117

已確認：零初始化／釋放、六個四元係數的幾何測試、直接及間接讀取者、核心內嵌資料拷貝不等於 heap 係數寫入。尚待驗證：以指標別名追出的非初始化寫入、callback+0x0C owner 的實際 caller、全域 22 桶 consumer；未有證據可以宣稱相機視錐或場景主更新已還原。

T08-117 建議：優先追查 vtable +0x0C 實際 dispatcher 的呼叫與 owner 實參；六係數採 heap pointer 動態 data breakpoint 輔以 x87/SSE store 的靜態 alias 分析。