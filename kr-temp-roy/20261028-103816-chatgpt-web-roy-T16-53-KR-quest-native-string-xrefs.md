# KR T16-53 — Quest/Tutorial native strings 與 xref 邊界攻堅

- 研究時間：20261028-103816 Asia/Taipei；`chatgpt-web roy`；**KR only**。
- GitHub：https://github.com/we88ec3-prog/ttr_anal_multi，目標 `main`，此份僅專屬研究原稿，不更改 catalog/owner。

## 原始來源與證據級別
- 原始檔 `/mnt/data/Tartaros.bin`，實際本輪重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；唯讀。
- `Tartaros.exe` 不執行；不使用 TC。
- GitHub 已提交原稿 T16-45～52 與 T01-20261028-06 的來源稽核為交叉脈絡，不把曾有的推測列為新證據。
- 此處 direct CALL 搜尋是 `.text` raw 位元組掃描 `E8 rel32`，可能有 embedded data／非指令邊界假陽性，需 CFG 進一步確認。

## PE 映射（本輪直接解析 DOS/NT header）
- .text: VA `401000`, RVA span 0x7d01f0, raw `0x400` span 0x7d0200
- .rdata: VA `bd2000`, RVA span 0x18e07c, raw `0x7d0600` span 0x18e200
- .data: VA `d61000`, RVA span 0x2873d8, raw `0x95e800` span 0x22b800
- .rsrc: VA `fe9000`, RVA span 0x5af58, raw `0xb8a000` span 0x5b000

## 直接字串與引用證據

| 字串 | raw / VA | .text 內 VA 位元組引用 | 可確認程度 |
|---|---|---|---|
| `TutoQuest` | `0x80d7a4` / `0xc0f1a4` | `0x532248` | 僅 byte-reference；待指令邊界及 operand 核實 |
| `HasQuest` | `0x80daec` / `0xc0f4ec` | `0x53fd85` | 僅 byte-reference；待指令邊界及 operand 核實 |
| `HasCompletableQuest` | `0x80daf8` / `0xc0f4f8` | `0x53fd93` | 僅 byte-reference；待指令邊界及 operand 核實 |
| `HasScenario` | `0x80db0c` / `0xc0f50c` | `0x53fda3` | 僅 byte-reference；待指令邊界及 operand 核實 |
| `RequestStartScenario` | `0x968568` / `0xd6ad68` | `0x4ab8f9` | 僅 byte-reference；待指令邊界及 operand 核實 |

## 字串引用附近實際反組譯

### `TutoQuest` @ `0x532248`
```asm

```

### `HasQuest` @ `0x53fd85`
```asm

```

### `HasCompletableQuest` @ `0x53fd93`
```asm

```

### `HasScenario` @ `0x53fda3`
```asm

```

### `RequestStartScenario` @ `0x4ab8f9`
```asm

```

## 語意邊界與反證
- `HasQuest` 與 `HasCompletableQuest` 這些字串是 client/native 掛接線索，尚不表示 server persistence writer。
- `.rdata` 原件字串偏移與 `.text` literal 參照是獨立可重現位址；沒有 caller CFG 就不能把附近整個函式命名為 Quest state 寫入器。
- 目前 Quest16／Quest15 的權威條件仍是 `DEFERRED-LOCAL-RESOURCE`：`Table/QuestInfo.xml` SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`，需原始 id 15/16 element、欄位與完整上下文。
