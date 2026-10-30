# E03 — KR Event.stp SceneList.xml EX 解碼器核查（未閉合）

日期 2026-10-29。原件唯讀；未執行遊戲或 Lua。承接 extra/roy1:kr-extra-roy E01/E02。

## 一手驗證

原始 Event.stp 11,241,597 bytes，STPD magic。對原始 STP 逐 byte XOR 0xFF 後，候選 SceneList 資料區為 raw 0xA23810..0xA26FFF，共 14320 bytes，SHA256 `ca445c6ee80cfe984c16561ac2124e6a892b5782af45bc3a79825f07ba8c581b`。

前 16 bytes：`45 58 01 00 A0 36 00 00 3D 6A 02 00 10 00 00 00`。其 LE32 值為 `0x15845,0x36A0,0x26A3D,0x10`；其中 `EX 01 00` 標識可由原 bytes 直接確認，**長度、版本、flag 的欄位身分仍待 STP 原生 reader 對照**。候選資料開頭（header 後）為 `48 7B FF B9 3C 0B D7 8F 64 06 66 0B BA D8 51 0B`，不是直接可讀 XML。

E02 已獲目錄 ordinal: qbase.lua 7378、SceneList.xml 7379、TutorialBase.lua 7380、TutorialMain.lua 7381；E01 已從同一檔案確定三個 Lua chunk SHA。上述資料和本輪 EX 區塊為跨步來源定位，**尚未用 BIN 實際 reader 證明 EX metadata 到 SceneList 名稱的完整映射**。

## 解碼測試與其界線

以 XOR 後候選資料的 offsets `0,16,20,24,32`，對 zlib wrapper (`wbits=15`)、raw deflate (`-15`) 及 gzip (`31`) 進行直接解壓嘗試，全部失敗。這只表示所測起點的直接解壓不適用，不足以排除自訂 codec、加密或其他 buffer 排列。

T01 來源稽核可確認某些靜態資源出處，但既有 E01/E02 及本輪尚未取得可輸出 SceneList.xml、驗證 XML 原文 SHA 的可用 `EX` XML 解碼器。因此**答案是目前沒有已驗證的解碼器**，不得將 EX metadata 直接替換成 XML schema。

## 再現指令

```python
from pathlib import Path
import hashlib, struct, zlib
p=Path("Event.stp").read_bytes()
assert p[:4]==b"STPD"
x=bytes(c^255 for c in p[0xA23810:0xA27000])
assert hashlib.sha256(x).hexdigest()=="ca445c6ee80cfe984c16561ac2124e6a892b5782af45bc3a79825f07ba8c581b"
assert x[:4]==b"EX\x01\x00"
print(struct.unpack("<4I",x[:16]))
for off in (0,16,20,24,32):
 for wbits in (15,-15,31):
  try: print(off,wbits,len(zlib.decompress(x[off:],wbits)))
  except zlib.error: pass
```

## 下一段必須補證

1. 從 KR BIN 追 STPD/EX reader、解壓或解密調用，證明四個 header 欄位與 input/output buffer 的實際語意。
2. 解出完整 SceneList.xml 後記錄 bytes SHA、編碼、root、逐場景 row。
3. 把教程 Lua 與 T07 controller、T03 select-response 上下游連接，避免誤用測試修補 005F type6。
4. E03 是「格式確認及失敗假設排除」，**不是 XML codec 完成或完整教學分流完成**。只寫 extra/roy1 的 kr-extra-roy/；正式整合與驗證完成後再清理研究暫存資料夾；不得預先刪掉尚未整合的原稿。
