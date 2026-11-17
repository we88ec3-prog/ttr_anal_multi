# P1 UI 載入鏈更正與適用範圍

日期：2026-11-18（Asia/Taipei）。基準：`15d9501c203c6f656461b64f578a50c96e38a5ff`，工作分支 `extra/roy1`。保留舊原稿，不覆寫歷史成果。原件為 SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 的 KR BIN。

## E1：`talk+18` 不能斷言必定是另一個物件

**需更正的舊句**位於 [前稿 entry-b/report.md §5.1](../../MEF-P0-P1-master-continuation-20261117/entry-b/report.md)：

> `749019` 的 `+110` 呼叫來自 talk `+18` 的 resource owner；它不是 talk 自己的 `+110`。

前半句描述了正確的欄位間接讀取。後半句排除了 `talk+18==talk`，超出當時尚未定型的 owner 證據。舊 [candidate-contracts.json](../../MEF-P0-P1-master-continuation-20261117/entry-b/candidate-contracts.json) 的同一未定型邊應依下述新證據解讀。

**本輪更正**：在實際 resource 212 的正常首載鏈上，`44E120 → 764520` 於 **`7645D1 mov [ebx+18],ebx`** 設定 root 的 owner 為自身，再於 `7645D4` 進 `776C60`；ClassID 相等時，才以同一 root 呼 `v+14=748C40`。對具體 `CScenarioTalkBox`，因此 `749019` 的實際 receiver 就是 root talk 本身。其 `v+110` 為 `C3EC54 → 49AE10`，原件只有 **`RET 0xC`**。呼叫前 out-child 在 `748FF4` 已清 0，hook 不寫它，所以此路徑轉往通用 child factory。〔本輪 U09、U12–U14、D04–D05；復用 B09〕

這是**此已識別載入鏈的正向 pointer provenance**，不是宣稱所有 UI 物件或任意另一個 caller 的 `+18` 都必然指向自己。後代的 `+18` 在 `749044` 繼承 root owner；其他載入方式仍須各自追來源。

此更正關閉前稿未定型的 custom-child hook 候選；不把它提升為普通腳本入口。`ordinary_B=false` 維持不變。

## E2：`5A3840` 的 owner 是 binder；page 是另一個 destination owner

[前稿 §3.1](../../MEF-P0-P1-master-continuation-20261117/entry-b/report.md) 已正確列出 `page+B4` 是 destination，以及 supplied window 在 `5A3888` 寫入。前稿沒有定型後續 manager 的完整 receiver。本輪補齊時必須分開以下三物件：

| 位置／暫存器 | 真正身分 | 原件證據 |
|---|---|---|
| `596010` 的原 ECX、後續 ESI | 普通 page；`+B4` 是 window pointer slot | `596038`、`596066` |
| `[ebp-20]`、傳入 `5A9F40` 的 EDI | 棧上 `FUI::CFXUIBinder`，vptr `C1920C` | `596045`、`59606F`、RTTI_BINDER |
| binder `v+14` 的返回值 | 固定 `FAAFD8` 的 `FUI::FXUICachingMgrCmdTarget`，vptr `BFC9D8` | `585690`、`44DFB0`、RTTI_CACHE |

`5A9F7A` 將 EDI binder 放入 ECX，然後呼 `5A3840`。因此後者 `v+14/v+18/v+1C` 是 **binder 的虛擬方法**。不能將它們叫成普通 page 的方法；普通 page 的 `v+14` 實際是繼承 XML reader。這是本輪探索中 provisional receiver 說法的修正，並非改寫前稿已證的 `page+B4` destination。〔U01–U06；D01–D02〕

## E3：補件來源現在可以精確到 FTC；Field 不是這條 UI 子圖的前置

前稿把未提供的 UI child/resource 子圖保留為邊界。現在原 BIN 的 `AD2991 → E577E8` 與 resource-ID getter 已把來源定名為 **`UI/Component/TalkBox_Scenario_Panel.FTC`**。Master 又把該虛擬目錄接到 **`UI/Component.stp`**。

接續這條 UI 子圖所需的是該版本的 FTC 或其 carrier，不能再概括成只缺 `Field.stp`，也不能把 UI/Component 與 UI/LUA 混成相同 provider。FTC 的 actual ClassID/child rows、額外節點、文字／圖片屬性仍未提供，不能從四個固定 lookup ID 反造整份檔案。〔U06–U13、D12–D14、M01–M02〕

完整鏈、cache／取消條件與剩餘 B 缺邊見 [report.md](report.md)；機讀更正後契約見 [candidate-contracts.json](candidate-contracts.json)。本輪不變更 T01 FULL-PASS、RR、Task owner 或正式可玩狀態。
