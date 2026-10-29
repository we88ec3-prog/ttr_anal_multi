# T16-013 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-020402-chatgpt-web-roy-T16-13-KR-tree-lookup-ABI.md`
- **舊原稿 Git blob SHA**：`b5ea5e5ed5312c287f2051b1db6ed3326c44be9c`
- T01 通知：`T01-RETURN-T16-013-36353f64`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容

`0x8438C0` uses **signed** comparison. 0x843901 `cmp esi,[edx+0xC]`, 0x843904 `jl 0x843915` excludes key smaller than best candidate (even if lower-bound produced best≥key). Correct conceptual final gate:
```cpp
// signed key comparison; best==head is not found.
if (best == head || key < best->key_0C) return head;
return best;
```
EAX output pointer and `ret 4` ABI remain as in source. A key=5 with best=7 must fail exact lookup, not return candidate7.

## 本次第一手 BIN 反組譯（指定入口）

注意：下面以函式入口開始連續解碼，**不自動等於完整可達 CFG**；不追逐 SEH/thunk 外部段、不可把無控制流根據的線性尾端當必然執行。

### 入口 `0x8438C0` 到 `0x843925`

```asm
  8438c0:	55                   	push   ebp
  8438c1:	8b ec                	mov    ebp,esp
  8438c3:	51                   	push   ecx
  8438c4:	53                   	push   ebx
  8438c5:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  8438c8:	56                   	push   esi
  8438c9:	8b f1                	mov    esi,ecx
  8438cb:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  8438ce:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  8438d1:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438d5:	75 1e                	jne    0x8438f5
  8438d7:	57                   	push   edi
  8438d8:	8b 3b                	mov    edi,DWORD PTR [ebx]
  8438da:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  8438e0:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  8438e3:	7d 05                	jge    0x8438ea
  8438e5:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  8438e8:	eb 04                	jmp    0x8438ee
  8438ea:	8b d1                	mov    edx,ecx
  8438ec:	8b 09                	mov    ecx,DWORD PTR [ecx]
  8438ee:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  8438f2:	74 ec                	je     0x8438e0
  8438f4:	5f                   	pop    edi
  8438f5:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  8438f8:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  8438fb:	3b d1                	cmp    edx,ecx
  8438fd:	74 16                	je     0x843915
  8438ff:	8b 33                	mov    esi,DWORD PTR [ebx]
  843901:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  843904:	7c 0f                	jl     0x843915
  843906:	8d 4d 08             	lea    ecx,[ebp+0x8]
  843909:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84390b:	5e                   	pop    esi
  84390c:	89 08                	mov    DWORD PTR [eax],ecx
  84390e:	5b                   	pop    ebx
  84390f:	8b e5                	mov    esp,ebp
  843911:	5d                   	pop    ebp
  843912:	c2 04 00             	ret    0x4
  843915:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  843918:	8d 4d fc             	lea    ecx,[ebp-0x4]
  84391b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  84391d:	5e                   	pop    esi
  84391e:	89 08                	mov    DWORD PTR [eax],ecx
  843920:	5b                   	pop    ebx
  843921:	8b e5                	mov    esp,ebp
  843923:	5d                   	pop    ebp
  843924:	c2               	ret    0x4
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
