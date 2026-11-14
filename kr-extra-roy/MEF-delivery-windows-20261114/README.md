# MEF 可交付時機：原件證據

主稿：[20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md](../20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md)。

本目錄保存使用者指定 `extra/roy1` 研究的有界靜態證據。它回答「相容 Server 可使用的交付／收包／啟用時機」，不要求復原官方 MEF 發送歷史，也不將普通檔案落地等同於原生 MEF 執行。

## 檔案

| 檔案 | 用途 |
|---|---|
| `native-windows.json` | 91 個定址視窗：遊戲 BIN 31、launcher EXE 60；共 27,895 bytes。保存 VA、PE raw offset、hex、SHA-256，另有 28 個精確 anchors。 |
| `native-windows.asm` | 上述視窗的 objdump 指令或 data hex；每段標記來源及名稱。 |
| `verify_native_windows.py` | 唯讀重驗兩份原件的完整 SHA-256、各自 PE section 映射及所有視窗／anchors。 |
| `verification-result.json` | 本輪重驗結果：91/91 視窗、28/28 anchors 相符。 |
| `source-manifest.json` | 原件身分、研究基準、89 筆精確 repository path／commit／Git blob 來源；包含復用報告及只作導航的偽碼。 |

## 重現命令

需要 Python 3 標準函式庫。以自己的原件位置取代以下兩個參數；不要執行遊戲或更新器。

```bash
python verify_native_windows.py \
  --bin /path/to/Tartaros.bin \
  --exe /path/to/Tartaros.exe \
  --out /tmp/mef-window-verification.json
```

若要重新匯出 assembly，另加 `--asm /tmp/mef-window-evidence.asm`，並安裝 GNU objdump。objdump 只反組譯已驗證的暫存 bytes，不啟動目標程序。程式先驗完整來源 hash；來源不同會拒絕套用地址。

兩份來源都是 PE32 i386，但 code／data 與 BIN／EXE 的 VA→raw 映射不可混用。視窗 end 為 exclusive；有界截取尾端未完整的後繼指令不屬被主張的語義證據，完整指令與上下游關係見主稿附錄。

## 結果的適用範圍

本輪新證據包括 manifest 新檔名經新增計畫、provider、HTTP、gzip 至普通 writer；正常更新完成與 BIN 啟動順序；loading 的接收 pump 位置；場景鍵與快取的交付截止點。完整出處及反證保留在主稿。

精確 bytes 相符是來源與局部指令核對；不代表真實網路／更新已成功、原生 `.mef` parser 已找到、T01 FULL-PASS、S00 需求已採納或 Server 已開發。原件未執行、未修改。使用者在分析完成後明確授權推送，提交目標為既有 `extra/roy1`；實際提交結果以 Git 歷史為準。
