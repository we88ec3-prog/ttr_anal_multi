# S2C 005F 換場景：安裝順序與取消協程的實際邊界

## 1. 結論

**S2C `005F` 不能當作「舊 qco 已取消」的確認點。** 本輪已把它從 packet callback、scene manager receiver、舊 scene 的 virtual exit／delete，到新 scene 安裝與 ordinary init 閉合。共同替換函式的固定順序是：

1. `005F` handler `4B99C0` 先更新 GameInfo mode，並建立新 field。
2. `4B7D50` 呼舊 scene `vtable+14` exit。
3. 舊 scene 仍存在時，呼其 `vtable+0` deleting destructor，清舊指標。
4. `4B7DA7` **安裝新 scene pointer**。
5. `4B7DBC` 才呼新 scene `vtable+10` init；controller 的 reuse／replacement 與 UI 處理在這之後。

**`4B99C0` 才是這個 packet handler；`4B7D50` 是共同 scene replacement helper。** 這兩個角色不可合併。

對普通 `CScenarioField`／`CMissionField`，本輪新增的關鍵證據是：兩者的 deleting destructor **都指向 `4C5940`**，而原件只改成 `CPacketProcessor` vtable，再按 delete flag 釋放 field 本體。它沒有清 qco／關閉共用 Lua VM。Scenario exit 本身是空函式；Mission exit 則清另一個集合 owner，其中尚有動態物件 callback，不能反過來稱為所有間接行為皆已排除。

已初始化的正常 ordinary 替換中，**舊 Scenario → 新 subtype 2 或 4，在新 field 安裝前沒有這條固定流程要求的 Q Stop／End／qco remove 呼叫**。這支持「005F 自身不保證先取消」，不表示其他已處理的 packet、Lua 任務或 UI 事件不可能先做過取消。

## 2. 原件、版本與可重驗資料

| 項目 | Pin |
|---|---|
| 原件 | `02-Tartaros.bin`，12,472,320 bytes，i386 PE32，ImageBase `00400000` |
| SHA-256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 導航偽碼 | main `909754f28bd2e54c8ede00e3a56021cf59facd14`，32 個 exact path／blob／SHA-256 |
| 復用已發布資料 | extra/roy1 `67021e609f56e45981aecf45533bdad084039a47` 的 `entry.md`、`lifecycle.md`、其原件窗及 `executor.md` |

偽碼只導航。本文 key instructions、完整選定函式窗、vtable、RTTI 都在 [native-windows.json](native-windows.json)，含 VA、raw、hex、SHA-256 與 native decode；[tables.json](tables.json) 列 owner、vtable 及 slot；[bounded-call-sites.json](bounded-call-sites.json) 列**只在選定 35 個 code windows 內**的直接與間接 CALL。來源 pin 見 [source-manifest.json](source-manifest.json)。

此分題不掃整個 disconnect 系統，不重建其他 mode 的全部 init／exit，也不把有限窗中的零 direct stop 擴張成所有動態 callback 的陰性。

## 3. Packet 如何進到真正的 scene owner

### 3.1 `005F` 註冊與 indirect dispatch

| 原件位置 | 已核行為 |
|---|---|
| `494376` | `[FD2CF8]=C06EB4`，建立 `CSceneManager` 的 vtable |
| `494380` | `[FD8BA4]=0`，初始化 current scene |
| `49438A` | 呼 `4B7DC0` 初始化 packet callback 表 |
| `4B7EAF` | `[FD2FF4]=4B99C0`；表基址 `FD2CFC + 005F*8 = FD2FF4` |
| `49439C` | ECX 明確設成 `&FD2CF8`；從 vtable `+4=4FDA30` 尾跳 dispatch |
| `4FDA3E` | 讀 `[receiver + signextended_command*8 + 4]` |
| `4FDA88–4FDA8A` | ECX 恢復同一 receiver，再呼選出的 callback |
| `4B99EC`、`4B9B34` | handler 將原 ECX 留於 EBX，進 `4B7D50` 前放到 ESI |

因此 `4B7D50` 的 `[ESI+5EAC]` 是 **`CSceneManager @FD2CF8` 的 current scene `@FD8BA4`**。這不是 GameInfo `F8D9E0` 的同一欄位。GameInfo mode 另為 `F8D9E0+5F4C=F9392C`；`4B9A32` 寫的是後者。〔原件 `N01–N03`、`N33–N35`、SceneManager vtable／RTTI〕

此 owner 區分很重要：mode 在舊 field exit 與新 pointer install **之前**就已更新，不可因此把新 mode 與當時仍存在的舊 field 類別視為永遠一致。

### 3.2 factory 與本輪涵蓋範圍

`005F` BYTE+2 是 subtype。原件 switch 接受 2、4、6、9、`19h`、`1Ah`、`1Ch`；本輪詳細追普通 2／4：

| subtype | constructor | field vtable | `+10` init | `+14` exit | `+0` delete |
|---|---|---|---|---|---|
| 2 | `4C46F0` | `C073B4`，CScenarioField | `4C4750` | `8DC2F0` | `4C5940` |
| 4 | `4BC6A0` | `C0705C`，CMissionField | `4BC750` | `4BBF10` | `4C5940` |

兩個 constructor 先用 `4ADD50` 填共用 packet callback 表，再設 field vtable；其餘動作是欄位初始化／清本 field 的 callback table。Mission `4BC6E0` 註冊的 `0031→4BCA90` 是**日後收到該命令才使用的函式指標**，constructor 沒有因此立即執行該 stop handler。`4ADD50` 也只是登記 `0038→4B1BF0`，不是建立新 field 時先處理一次 0038。〔`N04–N07`〕

unsupported subtype 的 factory 不執行共同換場景；本稿不把它當作一般成功轉場。配置失敗或 fatal path 也不是「正常取消完成」。

## 4. 舊 field 的 exit 與 destructor 到底清什麼

### 4.1 共同 helper 保證的是順序

| 時點 | 原件 | 行為 |
|---|---|---|
| 舊 pointer 非零 | `4B7D6B–4B7D6E` | 舊 field `v+14` exit |
| exit 後重新讀舊 pointer，仍非零 | `4B7D7C–4B7D80` | `v+0(1)` deleting destructor |
| delete 後 | `4B7D82` | current scene 清 0 |
| 安裝 | `4B7DA7` | `[CSceneManager+5EAC]=newField` |
| 安裝後 | `4B7DB4–4B7DBC` | 新 field `v+10` init |

helper 會在 exit 後重讀 pointer，故不能把 exit 前後一定是同一非空物件當成一般保證。正常 ordinary hooks 的本輪路徑則沒有改寫 manager current scene 的動作。原件 `N03`。

### 4.2 Scenario：空 exit、單純刪 field 本體

`C073B4+14=8DC2F0`，原件僅 `xor eax,eax; ret`。`C073B4+0=4C5940`，該函式將物件 vtable 設為 `C05B38`（RTTI 為 CPacketProcessor），若 delete flag bit0 非零便呼 `89120C` 釋放本體，再返回物件值。沒有接到 Lua wrapper、Q Stop／End 或 coroutine table。

同一 delete target 也屬 Mission。這把前稿的「析構不等於取消」補成**實際 vtable slot 與 native destructor 本體**，而不只是因 Q manager 是 global 的推論。〔`N08–N09` 及兩個 field／PacketProcessor RTTI〕

### 4.3 Mission：另一個集合 owner，動態 callback 保留型別界線

`4BBF10` 先依 `FB7354 & 1` 做一次初始化，然後明確 `EAX=&FB7358`，在 `4BBF6A` 呼 `553740`。`5533D0` 建 4 個 stride `10h` 的容器；這個 owner **不是 Q manager `FB73C0`**。〔`N10–N12`〕

`553740` 遍歷各樹的物件：先呼物件 `v+28` 判斷；若回 0，呼同物件 `v+10`，再 `v+0(1)` 刪除並移除樹節點；其他情形移到下一節點。這是確定的 native collection cleanup。

**本輪沒有把每個 collection element 的 runtime class 都定出來。** 因而只能說 Mission exit／此 collection loop 沒有明確呼 Q Stop／End／已知 removeAll 命名 wrapper，不能說它的所有物件析構與 callback 都不可能間接碰 Lua。這是具體的物件型別邊界；不以「沒看到 direct call」掩蓋間接呼叫。

## 5. 新 field 安裝後：controller 與 UI 分支

### 5.1 init 的 controller owner 與 gate

兩種 field init 都操作 `[FBA7A4]` controller，種類欄為 `FBA7AC`：

| 新 field | 要求 kind | 同 kind 且 pointer 非零 | 不同 kind 或無 controller |
|---|---:|---|---|
| Scenario `4C4750` | 3 | `4C47C1→544F50` reuse reset | 舊 `v+28`／`v+0`，建 `547390`，安裝後呼新 `v+24` |
| Mission `4BC750` | 2 | `4BC823→544F50` reuse reset | 舊 `v+28`／`v+0`，建 `548540`，安裝後呼新 `v+24` |

`547390`／`548540` 分別把 kind 寫成 3／2，且由原件 constructor 與 RTTI 可定出 Formation／Single controller vtable。**這些分支全在 field pointer 安裝之後**，不能當作必定先於 `4B7DA7` 的取消程序。〔`N13–N18`〕

### 5.2 可定出的 controller virtual targets

| controller | vtable | `+1C` slot getter | `+24` enter | `+28` exit | `+0` delete |
|---|---|---|---|---|---|
| Single | `C0FAC4` | `545290` | `4443B0` | `5486E0` | `548600→548630` |
| Formation | `C0FA14` | `545290` | `547C40` | `547C80` | `5475D0→547600` |

同 kind 的 `544F50` 重設 controller 的 `+40/+44/+5C/+60` 等欄位、時間、三個 slot 記錄；`v+1C=545290` 是 index<3 的 controller 欄位 getter。若取得現有 slot 物件，後續會釋放其引用並有物件 virtual destructor 呼叫。其狀態 owner 是 controller，沒有理由把這些欄位改名為 qco 的 `coTasks`。〔`N15–N16`〕

不同 kind 的 exit／destructor 處理 controller 擁有的 rendering／helper 物件，包含 `+A0`、`+B4/+B8/+BC/+C0/+C4` 等指標；共同 `544E80` 清自己的容器與配置。enter 則準備這些 helper。相關 body 已保存以覆核其直接呼叫與 dynamic member callbacks；沒有把所有 member 的析構器展開為全世界的取消分析。〔`N19–N27`、`N32`〕

本輪因此可以具體說明「新 init 並非沒有 cleanup，而是在安裝後處理另一組 owner」，仍不能將 controller 成功重建等同 `qco:removeAllCoroutines()` 已發生。

### 5.3 UI 狀態與 event 不是同步取消完成

Scenario init 要求 UI state 7，Mission 要求 5。`4C4855`／`4BC8EC` 比較目前 UI state `0x00FAADEC`；若不同，寫 pending `0x00FAADF0`；若已相同，呼 `58A9A0`。

`58A9A0` 建立 event，`58A9EB` 寫 event `+10=000F4355`；`58AA2E` 選 queue owner `F95C6C`，呼 `804260`。後者只把 pointer 放入 queue block、增加 count，沒有當場 invoke event consumer。**`F4355` 是內部 UI event，並非 wire opcode，也不是取消 ACK。**〔`N28–N29`〕

Mission init 額外 `53B7E0` 清某 presentation 物件的 flags，並送既有 UI event；`4E0FC0(FB72B8)` 清另一個資料樹。這些 owner 與 M／qco 不同，已保存 `N30–N31`，沒有把它們誤標成 Lua coroutine removeAll。

## 6. 對取消契約可以說到哪裡

| 範圍 | 可以確認 | 不能擴張成 |
|---|---|---|
| `005F` handler 與共同 helper | mode 更新、new constructor、old exit/delete、new install、new init 的明確順序 | 「005F 成功返回＝舊 coroutine 已取消」 |
| 舊 Scenario → 新 type2／type4，已初始化的正常替換 | 新 constructor 只做 field 初始化；舊 exit 為空；刪 field 本體後就安裝新 field | 「之前一定已跑過 Q Stop」；是否先處理別的 packet 必須另證 |
| 舊 Mission exit | 呼另一個四容器 owner 的 virtual cleanup loop | 全部 runtime element 型別都已證，或所有間接 cancel 都不存在 |
| ordinary 新 init | 安裝後做 controller reuse／replacement、UI state／queue | 對 qco 的同步清空保證 |
| 前稿 `0038` | `4B1D0E→5624B0` 發生在該 handler 自己的後續 preload 之前 | 該 stop 必定早於另一封 `005F` 的 install |
| 前稿 Tutorial／Synopsis exit | 各自有明確 tco remove／tracking cleanup | 所有 ordinary field 同樣清 tco，或 qco 與 tco 是同一 owner |

本輪 35 個選定 native code windows 共 125 個直接 CALL、34 個間接 CALL；其中對 `5624B0`、`561DB0`、`4AD0A0/6F4DD0/6F4F40/6F5A70` 的直接呼叫為 0。這個數字只是附帶可重驗的**選定窗內事實**；真正的取消判斷依據是上面的 receiver、vtable 與實際順序，且保留 dynamic object／queue consumer 邊界。

Server 開發／整合需求是把「舊任務停止、舊資源清理、新場景安裝、新任務啟動」定義成有具體原生事件依據的順序。現成 `0038` 的 handler 內先 stop 再 preload 可復用，但**不能只為了想要取消就任意重排現成 packet**；先須符合 mode、資源與既有 selector 的前置條件。本稿沒有新增 opcode，也沒有宣稱 Client 會回未曾證明存在的 cancel／完成 ACK。

## 7. 交付、重驗與未擴展範圍

提交的最小包是 `report.md`、`native-windows.json`、`native-disassembly.txt`、`bounded-call-sites.json`、`tables.json`、`source-manifest.json`、`reproduce.py`、`validation.json`、`deliverables-manifest.json`。本地 `sources/`、導航 JSON 與 builder 僅為 scratch，不需發布。

```sh
python reproduce.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

verifier 不執行 Client／Lua、不下載、不寫原件或 Git。它核對 60 個 records、8,049 bytes、35 個 code windows／2,147 instructions、6 個 vtable／RTTI、packet receiver 與 install 的明確 instruction anchors、窗內 call 分類，以及 36 個固定來源 path／blob。完整 instruction 邊界用 `end+15` decode 後只收 `VA<end`，避免 objdump 在截斷窗尾誤呈現完整 mnemonic。

尚未擴展的是 collection／controller member 的全部 runtime class、排隊 UI event 的所有 consumer、其餘五個 subtype 的完整 init／exit，以及 disconnect／重試／packet scheduling；這些不納入本稿「所有路徑已取消」的承諾。既有 parser package 及其 hashes 未因新增此子題而修改。
