# T16-005 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-014323-chatgpt-web-roy-T16-5-KR-child-parser-vector.md`
- **舊原稿 Git blob SHA**：`ae3dec4d3e612e2b20e31db54b6425602786c615`
- T01 通知：`T01-RETURN-T16-005-82389c1b`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容

`0x53FEB0` pseudo iterator must advance the **original Shout node** preserved in `ESI`, not the virtual callback conversion `EAX`. `virtual +0x14` may produce null and null skips appending; the next original node is `[ESI+0x40]`. Corrected bounded pseudocode:
```cpp
for (Node* original = initial; original != nullptr; original = original->next_at_0x40) {
    auto converted = call_virtual_plus_0x14(original); // result in EAX; actual ABI remains bounded
    if (!converted) continue;
    // key conversion / append only if required guards pass
}
```
The sketch is not a proven C++ class declaration. Do not reassign `original = converted`.

## 本次第一手 BIN 反組譯（指定入口）

注意：下面以函式入口開始連續解碼，**不自動等於完整可達 CFG**；不追逐 SEH/thunk 外部段、不可把無控制流根據的線性尾端當必然執行。

### 入口 `0x53FEB0` 到 `0x53FF25`

```asm
  53feb0:	55                   	push   ebp
  53feb1:	8b ec                	mov    ebp,esp
  53feb3:	51                   	push   ecx
  53feb4:	56                   	push   esi
  53feb5:	68 a0 f4 c0 00       	push   0xc0f4a0
  53feba:	e8 21 e4 1e 00       	call   0x72e2e0
  53febf:	8b f0                	mov    esi,eax
  53fec1:	85 f6                	test   esi,esi
  53fec3:	74 51                	je     0x53ff16
  53fec5:	57                   	push   edi
  53fec6:	8b 06                	mov    eax,DWORD PTR [esi]
  53fec8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  53fecb:	8b ce                	mov    ecx,esi
  53fecd:	ff d2                	call   edx
  53fecf:	85 c0                	test   eax,eax
  53fed1:	74 3b                	je     0x53ff0e
  53fed3:	68 a8 f4 c0 00       	push   0xc0f4a8
  53fed8:	8d 78 44             	lea    edi,[eax+0x44]
  53fedb:	e8 c0 01 1f 00       	call   0x7300a0
  53fee0:	85 c0                	test   eax,eax
  53fee2:	74 1a                	je     0x53fefe
  53fee4:	83 c0 30             	add    eax,0x30
  53fee7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53feeb:	72 02                	jb     0x53feef
  53feed:	8b 00                	mov    eax,DWORD PTR [eax]
  53feef:	85 c0                	test   eax,eax
  53fef1:	74 0b                	je     0x53fefe
  53fef3:	50                   	push   eax
  53fef4:	e8 bb 18 35 00       	call   0x8917b4
  53fef9:	83 c4 04             	add    esp,0x4
  53fefc:	eb 02                	jmp    0x53ff00
  53fefe:	33 c0                	xor    eax,eax
  53ff00:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53ff03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53ff06:	8d 45 fc             	lea    eax,[ebp-0x4]
  53ff09:	e8 72 87 f6 ff       	call   0x4a8680
  53ff0e:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  53ff11:	85 f6                	test   esi,esi
  53ff13:	75 b1                	jne    0x53fec6
  53ff15:	5f                   	pop    edi
  53ff16:	5e                   	pop    esi
  53ff17:	8b e5                	mov    esp,ebp
  53ff19:	5d                   	pop    ebp
  53ff1a:	c2 04 00             	ret    0x4
  53ff1d:	cc                   	int3
  53ff1e:	cc                   	int3
  53ff1f:	cc                   	int3
  53ff20:	55                   	push   ebp
  53ff21:	8b ec                	mov    ebp,esp
  53ff23:	51                   	push   ecx
  53ff24:	e8           	call   0x89289d
```


## 修正影響／驗收門檻

- **Client 待逆向**：此勘誤沒有證成任何新的 Quest S→C wire opcode 或 Quest16→15 接取 UI 閉環。
- **Server 待開發**：相容 Server 的任務前置、解鎖、持久化由 S00 SPEC/ADR 獨立設計，不可由局部 ASM 冒稱官方判斷。
- **跨功能待整合**：如涉及 T02 framing/網路、T06 UI 等，由相關 Task 的原始證據及 T01 claim-level review 處理。
- **待遊玩驗證**：未執行原 Client 或動態封包測試。
- **T01 狀態**：GitHub 仍為 `NEEDS_FIX`/`NEEDS_QUALIFICATION`；待來源 Task 將此勘誤審核／提交後，才能提出 `READY_FOR_REVIEW`，且 T01 通過才可 `RESOLVED`。

## 原始來源／交叉引用

- `kr/tasks/T16/README.md` 上固定退回 ID 和精確 blob SHA。
- `shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json`；`shared/integrations/T01-20261029-continuation-02/t16/README.md`。
- `shared/verified-knowledge/README.md` 的有界條目不等於本篇 FULL-PASS。
