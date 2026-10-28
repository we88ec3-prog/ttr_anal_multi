# E06 — 原生 EX v1 解碼器閉合及 Event/SceneList.xml 完整還原

日期：2026-10-29；分支 `extra/roy1`；原件唯讀、未執行或修改 Tartaros 客戶端。原始 KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Event.stp SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。

## 結論：E03–E05 遺留 XML codec 缺口已成功關閉

從原生 BIN `0x72F260` 向下讀取後，確實找到 `EX` format check、版本 `1` 判斷、1024-byte 循環 XOR key、`0x727190` 解壓處理；將這個演算法套用於使用者提供的原版 Event.stp，完整還原 `Event/SceneList.xml`，長度 **158269 bytes**，SHA256 **`8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`**。輸出為 euc-kr XML，根為 `SCENESET`、**1687 個 `SCENE`**。這是直接原始 bytes 的解碼實證，不再是 EX 壓縮方式猜測。

## Native BIN 三段證據與 header

1. `0x72F3E9..0x72F3F2`：對 resource object vtable `+0x10` 讀取 `EBX` raw data buffer，length `[ebp-0x418]`；成功需 `EAX == 1`。
2. `0x72F42E` 對 output buffer 第一 byte 比較 `0x45('E')`；`0x72F437` 比較第二 byte `0x58('X')`；`0x72F45B` 比較第三 byte `1`。原生函式直接證明 EX v1。
3. `0x72F441 mov edi,[ebx+0xC]; 0x72F444 mov eax,[ebx+8]; 0x72F447 add edi,ebx`：壓縮 data offset 存於 header+0xC，output size 於 header+8；後續 `0x72F513 cmp [ebx+4],eax` 與 `0x72F528...` 說明 XOR payload長度 `header+4`。因此 E03 所謂四個未知值本段正式釐清：`EX 01 00`、compressed length `13984`、uncompressed length `158269`、payload offset `16`。
4. `0x72F47F mov word [ebp-0x40c],0xE730` 建立 1024-byte key；`0x72F4B6..0x72F509` 根據上兩個 key bytes 和 `+0x13` 產生下一 byte、特殊 `i==0x17c` 減去 `0x56`；`0x72F520 and ecx,0x3ff; 0x72F528 mov dl,[key+ecx]; 0x72F52F xor [eax+edi],dl` 是循環 XOR。
5. `0x72F54A call 0x727190` 以解密後 bytes、compressed len `[ebx+4]` 和 output buffer 呼叫解壓（本段 Python zlib 交叉證明與該接口對應；`0x727190` 的後續 `0x7274B0` 是 decompression family）。結果成功產生 XML 並符合 header 宣告 output length。

**校正容易誤判的一點**：`0x72F4EF cmp edi,0x17c` 時 `EDI=EAX+1`，而迴圈 `EAX` 從 2 每次加 2，所以該第二特殊分支不可達；只有 `key[0x17c]` 減去 `0x56`。如果錯誤地也調整 `key[0x17d]`，zlib 將報 `invalid distance too far back`。此校正用成功解壓及 XML size/hash 驗證，不是猜測。

## 原始 Event.stp 可復現 Python (不需遊戲 runtime)

```python
from pathlib import Path
from hashlib import sha256
from struct import unpack_from
from zlib import decompress
import xml.etree.ElementTree as ET

stp=Path("Event.stp").read_bytes()
assert stp[:4]==b"STPD"
block=bytes(v^255 for v in stp[0xA23810:0xA27000])
assert block[:2]==b"EX" and block[2]==1
compressed_len=unpack_from("<I",block,4)[0]
original_len=unpack_from("<I",block,8)[0]
payload_offset=unpack_from("<I",block,12)[0]
assert (compressed_len,original_len,payload_offset)==(13984,158269,16)
key=bytearray(1024)
key[:2]=bytes.fromhex("30e7")
for i in range(2,1024,2):
    key[i]=(key[i-2]+key[i-1]+0x13)&255
    if i==0x17c: key[i]=(key[i]-0x56)&255
    key[i+1]=(key[i-1]+key[i]+0x13)&255
encrypted=block[payload_offset:payload_offset+compressed_len]
compressed=bytes(b^key[j&1023] for j,b in enumerate(encrypted))
assert compressed[:2]==b"\x78\x9c"
xml=decompress(compressed)
assert len(xml)==original_len
assert sha256(xml).hexdigest()=="8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25"
root=ET.fromstring(xml.decode("cp949").replace('encoding="euc-kr"','encoding="utf-8"').encode())
assert root.tag=="SCENESET" and len(root)==1687
print("SCENESET",len(root),"SCENE rows")
Path("SceneList.xml").write_bytes(xml)
```

## 原版場景資料新證

完整 XML 共 1687 個 `SCENE` children、498 種 questIdx，典型欄位：`questIdx`, `sceneIdx`, `funcName`, `endBehavior`。以下為完整還原 XML 的實際 row：

| questIdx | sceneIdx | funcName | endBehavior |
|---|---|---|---|
| 1000 | 9 | tutorial5_1 | 0 |
| 1001 | 1 | tutorial_start | 0 |
| 15 | 1 | Square_Tutorial01 | 0 |
| 15 | 2 | scenario_tuto1_1 | 0 |
| 15 | 4 | scenario_tuto2_1 | 0 |

這些只證明 **Event/SceneList.xml 靜態場景對應**，不直接證實首次登入一定進入 questIdx 1001，亦不能混入 `Table/SceneList.xml`，更不能當作 S→C wire opcode。

## 跨 Task、Server 與範圍

- T06/T16：原始教學場景 XML 已復原，T16 Lua Part1/Part2 的 RequestStartScenario 可沿 `funcName`、questIdx/sceneIdx 做靜態交叉；正式觸發條件待查。
- T03/T07：選角 `0x42` response→world state→首次教學 decision 仍未 closure；T07 原生 `005F type6` CDuelField 的已知反證仍有效。
- SV-05~SV-07：可引用場景表、不可自原始 row 推導 Server reply/acceptance。
- 只有 `Event/SceneList.xml` 這個 confirmed EX v1 sample 已成功解碼；不宣稱所有 EX version、所有 STP 內容都是同一 codec。所有 extracted commercial resources 保留在本地，不將 XML 全文直接提交 GitHub。
- T01 正式整合且確認原稿及 hash 已吸收後，才清理 `kr-extra-roy/`；本輪只建立 E06 原稿，不動 main。
