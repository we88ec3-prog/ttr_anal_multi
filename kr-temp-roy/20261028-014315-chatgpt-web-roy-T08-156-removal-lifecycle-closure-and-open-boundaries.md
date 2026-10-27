# KR T08-156 — removal lifecycle closure and open boundaries

- 研究時間：2026-10-28T01:43:15+08:00 Asia/Taipei；研究者：`chatgpt-web roy`。
- KR 原始檔：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本地實際重新核對）；唯讀靜態分析，未啟動或修改程式。
- 原始碼來源：本次使用 GNU objdump 對 PE32 `.text` 的 VA 反組譯及 E8 相對目的地直接核查。**完整 `.text` 線性反組譯掃描只建立 direct-call 候選集合，不等同完整 CFG，亦可能包括誤解碼區。**
- GitHub 整合：前次查核 main HEAD `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；最新 HEAD 需於提交前複核。正式 T08 為 0007 建立／登記／移除資料介面；不替代 T02/T06/T07 分工。
- 歷史來源：T08-153 及整合重審-01/02；保留本次覆核與舊報告證據等級差異。

## 工作包結論（154–156）

本批已把正式 T08 的**建立／登記／移除資料介面**從原先的「移除地址未知」推進到「多條原始移除函式、直接上游 caller 及共享 tree erase 可靜態重現」。但**尚未**完成任意封包 opcode 的完整 dispatch 身分核對、actor vtable 真正 destructor 身分、所有間接 caller，以及官方伺服器何時發送何種移除。以下只聲稱一手驗證範圍。

### 1. 完整可重現功能鏈矩陣

| 路徑 | 調度／生產 | 操作 | 主鍵／條件 | 內部清理與限制 |
|---|---|---|---|---|
| 0007 創建 | `4AE4D0` | `4D1710`→`4DFF30` | `WORD actor+4` | 2 byte prelude, 26-byte rows；前批驗證，創建時機未證 |
| 單鍵移除 A | `4B2A...` | `4DFBC0` | 從 buffer 每 2 bytes 讀 WORD | 先控制器三槽，再 actor 虛擬清理，最後 `7B6890` |
| 單鍵移除 B | `4A9FE0` | `4DFBC0` | 低 BYTE 擴成 WORD | 不可視同涵蓋全部 16-bit ID |
| 條件式批次 | `4B3710` | `4DFC90` | actor+88 vs 候選複合 DWORD | `40F060` 轉換語意需驗；不能直接叫 owner |
| 類型式批次 | `4B1A...` | `4DFD40` | BYTE actor+4 vs WORD 輸入 | 類型0/1/6/7的 `+15C/+370` 路徑未完整解 |
| 全 actor 清理 | `424448,4BA9C9,4BB62A` 等 | `4DFE90` | receiver 的 +8 tree | 多個 caller，非單一封包場景；先 actor 再整樹 |
| 腳本物件 | `Q.CreateObject` | `563A70` 等 | script this+18，DWORD key | 另一套 CEventActor，不能與 GameInfo map 合併 |
| 節點 erase | `4DFC1E` 等 | `7B6890` | tree node | 修補樹平衡、free node、size--，**不是 actor free** |

### 2. 強證據锚點

- `0x4B2AB9 movzx ecx,word [eax]` → `0x4B2AC2 E8 ... call 4DFBC0`；`+0x2` 推進來源 cursor。完整直接分支見 T08-154。
- `0x4B371E` 形成 `(len-2)>>1`，`0x4B3733 OR eax,0x06000000` → `0x4B3739 call 0x40F060` → `0x4B373E call 0x4DFC90`。這和刪除完整 WORD actor ID 不等價。
- `0x7B6AC7 call 0x89120C`，`0x7B6ADA` 判定 count 非零，`0x7B6ADD` 把 count 減 1；函式於 `0x7B6AEB ret 0xC`。原始 bytes/上下文見 T08-155。
- `0x4DFF0A call 0x823850` 是全表清除節點；單鍵移除 `0x4DFC1E` 則 call `0x7B6890`。兩個容器操作的副作用與控制順序不能互換。
- 多個 `4DFE90` caller 直接將 `0xFAB130` push 進去；不代表所有 caller 都在執行同一場景切換。

### 3. 部分語意的安全 C++ 模型

```cpp
struct ActorNode {
    ActorNode* left;  // +0
    ActorNode* parent;// +4
    ActorNode* right; // +8
    // +C key / +10 payload；+14 color, +15 nil 用於通用樹 layout
};

void createPath(Packet p) {
    // 0007: 前2 bytes + N*26 bytes；更高層發送與時機未驗證。
    for (auto row : parseBoundedRows(p, 2, 26)) {
        Actor* a = nativeFactoryCandidate(row);
        if (a) insertUniqueActorId(gameInfoTree, a->actorId);
    }
}
void eraseByIdPath(uint16_t id) {
    // 三槽清理 / v14 / v0(1) 只屬 4DFBC0 路徑。
    auto* n = findActorNode(gameInfoTree, id);
    if (!n) return;
    removeControllerSlotsCandidate();
    callActorVirtual14Then0(n->value);
    eraseBalancedTreeNode(gameInfoTree, n);
}
```

**模型只用來表達資料流與條件限制，不是忠實的可直接部署原版實作**。控制器 slot 清理在實際 `4DFBC0` 只有查中 key 後才執行；上例依該順序表達，但省略虛擬方法細節。亦不能假設每個 virtual +0 都一定對應 delete this。

### 4. 最新證據分級

| 要點 | 分級 | 不可擴大到 |
|---|---|---|
| PE BIN 完整 SHA 與直接 E8 call | 已確認／本地原始 bytes | 某 opcode 對應無外部註冊證據時不能命名 |
| `4B2A...` 逐 WORD 刪除、`4B3710` 逐 WORD 分支 | 已確認局部指令 | 不證所有 buffer 長度分支都有完整防護 |
| `7B6890` linked tree erase + free node + size-- | 已確認 | 不證 actor 類別 destructor 已驗證 |
| 封包的官方來源、房主/P2P 分工 | 尚未驗證 | 不可當伺服器規則 |
| `actor+88` 的型別及 `+15C/+370` 的資源語意 | 尚未驗證 | 不可混用 `+9C owner` |
| T01 catalog 正式完整 native 受理 | 未宣稱 | 本批原稿尚待整合者逐 SHA 審核 |

### 5. 下一段工作方向（如有需要）

T08-157 最值得追 `0x4B2928` 的接收器入口、命令表註冊，`0x40F060` 的鍵值映射；另向 `actor vtable+0/+14` 回溯具體 class 與 sidecar 解構，逐條解決未證實的完整釋放。更廣泛的場景排程 T06/T07 和 opcode 框架 T02 僅引用不接管。

### 6. 提交原則

使用者在本輪明確授權完成 T08-156 後提交**可取得但尚未推送的自己完整分析**；預計同時包括中間整合重審-01、02、T08-153 和 154–156，各檔不得以 summary 冒充原稿。提交後逐 SHA 比對遠端內容；如權限／檔案傳輸受阻，應誠實標示而保留本地全部原稿。