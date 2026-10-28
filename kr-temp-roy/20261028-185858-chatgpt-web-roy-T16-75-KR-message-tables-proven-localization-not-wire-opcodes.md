# KR T16-75 — Quest 名稱 ID 反證：三組 XML 本地化訊息註冊表與原生初始化鏈

- 分析時間：2026-10-28 18:58:58 Asia/Taipei（以執行環境 `TZ=Asia/Taipei date` 核對）。研究者：chatgpt-web roy。僅 KR T16。
- 原始 KR `/mnt/data/Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。唯讀反組譯和 bytes 比對；未啟動／修改 Client。
- PE32 sections 由本輪 `objdump -h` 核對：`.text` VMA `0x00401000`, raw `0x400`, size `0x7D01F0`；`.rdata` VMA `0x00BD2000`, raw `0x7D0600`; `.data` VMA `0x00D61000`, raw `0x95E800`。`.data` 映射 `VA=raw+0x402800`。

## 1. 本段重大發現：前段的「Quest command / notification enum」不成立

T16-74 提出的 A/B 表含 `kRequestAcceptQuest`、`kAcceptedQuest`、`kAcceptQuestFailed`、`kCompletedQuest`，當時**只確認為名稱／整數資料表**，沒有確立 wire opcode。本輪藉由整張表的原生 xref，確認這些名稱數字屬於與三個 **Table/Messages/*.xml** XML 相連的本地訊息名稱索引／註冊機制。**不是已證實的 Quest C→S、S→C 業務 opcode**；原先把 A/B 叫作「Quest request/result 命令表」的方向需正式勘誤。表內 `0x1F`、`0x11`、`0x12`、`0x13` 等不得據此實作網路封包。

### 1.1 三個資料表的實際邊界和索引重置

使用 BIN 的 `struct.unpack_from('<III', ...)`，按每 12-byte 紀錄取 `{integer,name_pointer,common_pointer}`，以第三欄 `0x00C11778`、名稱指標落於 `.rdata`、連續編號復核：

| 區域 | raw 開始 | raw 最後一筆 | 末筆 ID | 紀錄數 | 對應初始化呼叫及 XML |
|---|---:|---:|---:|---:|---|
| A | `0x963420` | `0x964AD0` | `0x1E4` | 485 | `Table/Messages/CommonMessages.xml` |
| B1 | `0x964AF0` | `0x96509C` | `0x79` | 122 | `Table/Messages/SystemMessages.xml` |
| B2 | `0x9650A8` | `0x9678C8` | `0x358` | 857 | `Table/Messages/UIText.xml` |

B1 結尾 `0x79` 下一筆在 `0x9650A8` 從 `0` 重起，故**不能**將 B1/B2 合稱一張無中斷的 979 筆同域 enum 表。前段 T16-74 的兩組 A/B 名稱只是同一類訊息資源的不同紀錄位置，不是可靠的 C2S／S2C 區分。

表段起點換算：A VA `0x00D65C20`；B1 VA `0x00D672F0`；B2 VA `0x00D678A8`。

### 1.2 關鍵第一手反證：三個表頭都被同一段原生初始化程式引用

`0x005853F1` raw `0x1847F1`：

```asm
5853ec: push 0x1e5             ; count=485
5853f1: push 0x00d65c20        ; A table base
5853f6: mov edx,0x00c191a4     ; "Table/Messages/CommonMessages.xml"
5853fb: mov ecx,0x00fe5b0c     ; registry/owner object
585400: call 0x00584d40
```

`0x00585434`：

```asm
585434: push 0x7a              ; count=122
585436: push 0x00d672f0        ; B1 table base
58543b: mov edx,0x00c191c8     ; "Table/Messages/SystemMessages.xml"
585440: mov ecx,0x00fe5ae8
585445: call 0x00584d40
```

`0x0058547D`：

```asm
58547d: push 0x359             ; count=857
585482: push 0x00d678a8        ; B2 table base
585487: mov edx,0x00c191ec     ; "Table/Messages/UIText.xml"
58548c: mov ecx,0x00fe5ac4
585491: call 0x00584d40
```

三個 `.rdata` UTF-8/ASCII path 的原始文字在 VA `0x00C191A4`, `0x00C191C8`, `0x00C191EC`，以 `.rdata VA-raw = 0x402A00` 得 raw `0x8177A4`, `0x8177C8`, `0x8177EC`。本輪實際直接讀取 bytes 確認上述三條路徑。

以上 **原生已確認**：三組 12-byte 表、三個數量、三條 XML 路徑與共享呼叫目標；較高層「本地化文字／訊息載入」是由 `Table/Messages` 路徑與處理字串步驟支持的高度可靠語意分類，並非已還原完整 XML parser 機制。沒有讀取到三份 XML 原件，不推斷其內容。

## 2. `0x00584D40` 共用載入／登記流程的直接組語證據

本輪 `objdump -D -Mintel --start-address=0x584d40 --stop-address=0x584eac` 核對：

```asm
584d6b: mov eax,[ebp+0xc]      ; count
584d73: mov ecx,[ebp+0x8]      ; raw table base
584d79: cmp eax,ebx            ; count <= 0 branch to 584e85
584d81: lea edi,[ecx+0x4]      ; pointer into record
584d93: mov eax,[edi-0x4]      ; record integer ID
584d96: mov edx,[edi+0x4]      ; record common_ptr (UTF-16 string pointer)
584dae: lea esi,[eax+0x2]
584db1: mov cx,[eax]            ; UTF-16 length scan, +2 each iteration
584db7: cmp cx,bx
584dba: jne 584db1
584dc5: call 0x00402160       ; string construction helper candidate
584dd6: call 0x005063f0       ; registration/lookup helper candidate
584de0: call 0x00506030       ; container mutation candidate
584dfe: mov ecx,[edi]         ; name_ptr (single-byte string)
584e15: lea edi,[eax+0x1]
584e18: mov dl,[eax]           ; byte string length scan
584e1b: cmp dl,bl
584e1d: jne 584e18
584e26: call 0x00402a70       ; string construction helper candidate
584e42: call 0x0077e100       ; name lookup/registration helper candidate
584e4d: call 0x00552980       ; container mutation candidate
584e6b: add DWORD PTR [ebp-0x58],0xc  ; next record
584e6f: sub DWORD PTR [ebp-0x5c],edi  ; decrement count (edi=1)
584e7f: jne 0x00584d90        ; next record
584e88: push ecx              ; registry
584e8c: call 0x00584eb0       ; load/parse phase, exact semantics not proven
584eac: ret 8
```

`0x584D40` 對每個元素從 record+0 取 ID、record+4 取單位元組名稱、record+8 取 UTF-16 指標，並建立／插入兩套關聯容器，最後調用 `0x584EB0`；以 XML 檔名及資料流看似訊息目錄登記及後續資源載入，細節需進一步核驗。此處 **不處理 WSASend/WSARecv，也未證明含有封包 dispatcher**。

上游 `0x5853C7`、`0x585413`、`0x585458` 在各表載入前使用一次性 guard 與 `0x584C40` 初始化三個全域 registry 的內部結構；`0x584C40` 在 `0x584C6D` 對第一樹配置 0x30-byte 節點，於 `0x584CA4` 對第二樹配置 0x30-byte 節點（部分已直接驗證）。不將此自行命名為 protocol registry。

### 有界偽碼

```cpp
struct MessageNameRecord {
    uint32_t local_message_id;
    const char* symbolic_name;         // raw record +4; byte-terminated
    const wchar_t* common_wide_name;   // raw record +8; same pointer 0xC11778 here
};

void initialize_message_catalogs() {
    register_messages(registryA, "Table/Messages/CommonMessages.xml",
                      (MessageNameRecord*)0xD65C20, 485);
    register_messages(registryB, "Table/Messages/SystemMessages.xml",
                      (MessageNameRecord*)0xD672F0, 122);
    register_messages(registryC, "Table/Messages/UIText.xml",
                      (MessageNameRecord*)0xD678A8, 857);
}
```

注意：`register_messages` 是研究者暫名而非官方符號；`0x584D40` 參數來自 `ECX` registry、`EDX` XML path、stack[+8] records、stack[+12] count。每記錄 `common_wide_name` 是否語意為預設值仍未經 XML 原件驗證。

## 3. 三輪門檻與範圍

T16-75 **第 1 輪已達重大新發現**：成功由單筆表記錄擴展至完整三組表、原生初始化者、三條 XML 檔案路徑、共用 helper 與迴圈記錄格式。此重大發現同時**否證舊研究方向**，防止將訊息編號誤當封包 opcode。因此依全 Task 規範，第 2／3 輪未啟動（不是已執行），可進入下一正式段。

本段未找到 NPC 操作 → C→S Quest packet builder，亦未找到 S→C Quest 接受／拒絕／完成 handler；原版 wire opcode、欄位、回覆格式、Quest16→Quest15 仍 unknown。通用 Winsock 路徑沿用已提交 T16-69～72，不用本地訊息 registry 取代其封包分派證據。絕不由此推論 Server 如何完成 Quest。

| 玩家情境 | 本地 gate | C→S | S→C | Client UI | Server 待開發 |
|---|---|---|---|---|---|
| 玩家接受 NPC 任務 | unknown | unknown；`kRequestAcceptQuest` 只是 CommonMessages 名稱 ID | unknown | 本地文字目錄有相關名稱，行為未知 | 等真實封包格式確認 |
| Quest 接受／失敗 | unknown | unknown | unknown；`kAcceptedQuest`、`kAcceptQuestFailed` 只是 UIText 文字 ID | 本地有對應文字名稱，何時顯示未知 | 等 S→C handler 確認 |
| Quest 完成 | unknown | unknown | unknown；`kCompletedQuest` 是 UIText 文字 ID | unknown | 等 Quest cache writer 確認 |
| Quest16→Quest15 | unknown | unknown | unknown | unknown | 不猜原版 Server 任務前置 |

## 4. 下一段 T16-76 / 遺留疑問

1. 從真正的 NPC Quest accept UI callback、Quest cache 狀態 writer 或網路 payload 變更 handler 追 C→S/S→C；**不要再將 `Table/Messages/*.xml` 表作為 opcode 搜尋入口**。
2. 如需研究具體 UI 字串，從 `0x584EB0` 追入本地化文字載入，再找其消費者；不將其當作網路封包主線。
3. 從 T02 已確認的 packet domain 與 T16-72 worker 實際 vtable 查業務 handler；保留未證時序／封包欄位。
4. `QuestInfo.xml`、`TutorialBase.lua` 尚未取得原件。缺失不阻塞 Client 網路追查。

## 5. 原稿提交及隔離

本稿僅屬 KR T16 `kr-temp-roy/`，原件唯讀。不得修改 T02/T07/T14/T15 task、owner、catalog 或上傳遊戲二進位檔。GitHub Commit 與 read-back 另以提交動作驗證，不能以本稿自稱完成推送。