# KR T16-54 — 教學入口與 Lua loader/call site 的 E8 直接呼叫交叉參照

- 研究時間：20261028-103816 Asia/Taipei；`chatgpt-web roy`；**KR only**。
- GitHub：https://github.com/we88ec3-prog/ttr_anal_multi，目標 `main`，此份僅專屬研究原稿，不更改 catalog/owner。

## 原始來源與證據級別
- 原始檔 `/mnt/data/Tartaros.bin`，實際本輪重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；唯讀。
- `Tartaros.exe` 不執行；不使用 TC。
- GitHub 已提交原稿 T16-45～52 與 T01-20261028-06 的來源稽核為交叉脈絡，不把曾有的推測列為新證據。
- 此處 direct CALL 搜尋是 `.text` raw 位元組掃描 `E8 rel32`，可能有 embedded data／非指令邊界假陽性，需 CFG 進一步確認。

## 本批新建靜態 direct-E8 CALL xref 集合

| 目標 VA | 來源 callsites（VA） | 數量 |
|---|---|---|
| `0x004A89C0` | `0x0047BACE`, `0x004C1FFC` | 2 |
| `0x004A8A60` | `0x004C4D3F` | 1 |
| `0x004A8B90` | `0x0047CA45`, `0x004C19AE`, `0x004C4E8A` | 3 |
| `0x006F4A50` | `0x0048B11D`, `0x0048B12C`, `0x0048B13B`, `0x0048CA11`, `0x0048CA4D`, `0x004A89B6`, `0x004A8A36`, `0x004A8B64`, `0x0055D7C2`, `0x00560796`, `0x005607A2`, `0x005607AE`, `0x005607BA`, `0x00561C7D`, `0x005659D9` | 15 |
| `0x006F4DD0` | `0x004A8A46`, `0x004A8B74`, `0x005615D8` | 3 |

## 局部來源函式的機器碼片段（BIN off 經 PE section 推算）

### caller `0x0047BACE` → `0x004A89C0`，raw `0x7aece`
```asm

```

### caller `0x004C1FFC` → `0x004A89C0`，raw `0xc13fc`
```asm

```

### caller `0x004C4D3F` → `0x004A8A60`，raw `0xc413f`
```asm

```

### caller `0x0047CA45` → `0x004A8B90`，raw `0x7be45`
```asm

```

### caller `0x004C19AE` → `0x004A8B90`，raw `0xc0dae`
```asm

```

### caller `0x004C4E8A` → `0x004A8B90`，raw `0xc428a`
```asm

```

### caller `0x0048B11D` → `0x006F4A50`，raw `0x8a51d`
```asm

```

### caller `0x0048B12C` → `0x006F4A50`，raw `0x8a52c`
```asm

```

### caller `0x0048B13B` → `0x006F4A50`，raw `0x8a53b`
```asm

```

### caller `0x004A8A46` → `0x006F4DD0`，raw `0xa7e46`
```asm

```

### caller `0x004A8B74` → `0x006F4DD0`，raw `0xa7f74`
```asm

```

### caller `0x005615D8` → `0x006F4DD0`，raw `0x1609d8`
```asm

```

## 控制流解釋（限定）
- 在 opcode `E8` 及相對位移符合的情況下，可推得 direct call destination；本輪未重建上述全部 caller 的完整函式入口與控制流，故不宣稱每個命中均已被 CFG 驗證。
- `0x004A89C0`, `0x004A8A60`, `0x004A8B90` 均有不同 caller；不因距離接近而合併為同一 API。
- `0x006F4A50` 的多個 direct caller 與 `0x006F4DD0` 的少量 direct caller，是值得追 Lua script-load 與具名 dispatch 的獨立入口；是否載入 TutorialBase、TutorialMain 特定腳本需 caller 參數與字串繼續追蹤。
- `Event/TutorialBase.lua` SHA `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` 的 chunk 內容仍缺乏直接可審讀的函式指令；不可虛構 callback 或把 client coroutine 等同 server success。
