# T10-098 — 0x761010 條件 selector 與 0x596140 listener 優先序

## 來源
KR PE32 x86 Tartaros.bin; SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91; EXE SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f. Both re-hashed locally. BIN .text VA 0x401000/raw 0x400, .rdata VA 0xBD2000/raw 0x7D0600, .data VA 0xD61000/raw 0x95E800 (verified via objdump -h). Static read-only disassembly, no program execution.

## 函式窗口
[code block separately checked in preflight]

## 結論
選取器使用輸入 owner 的 +0x64/+0x68 指向容器，走訪節點取 +8 子物件，再檢查子物件 +0x28 中 bit19 必須為 0、bit8 必須為 1、bit12 必須為 0 的條件。三個位元判斷是位元級直接證據，位元業務名稱未知。無符合者返回 NULL；符合者返回節點 +8 所指向物件。+0x64/+0x68 是 owner 的 offset，+0x28 是被篩選物件欄位，二者不得與 0x5A55E0 的不同物件 +0x28 混用。

0x596140 從 owner+0x80 關聯容器尋找以 EDI 作鍵的 listener bucket，依 phase 1/3 分別調用 vtable +0xEC/+0xF0；收到非零布林便提前成功返回，全部失敗則返回 0。它是 fallback 中「詢問其他 listener」的具體實作，不能將 helper 命名為攻擊命中或動作成功。

## 仍缺
vtable 具體表址與 override 沒有直接確定，尚未找到從 listener 回調進入角色 motion 的原生機器碼鏈。T10-99 追 phase flags，T10-100 統整分歧及後續入口。
