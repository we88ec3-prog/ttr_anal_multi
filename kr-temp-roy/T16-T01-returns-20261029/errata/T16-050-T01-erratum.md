# T16-050 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md`
- **舊原稿 Git blob SHA**：`bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564`
- T01 通知：`T01-RETURN-T16-050-c26518b1`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容


### 討論附錄指令起點錯誤 — 修正提案

T01 marked the supplemental assembly windows below as having **instruction-boundary risk or incorrect decoding**. One `0x4AEDAF→0x4AEDB0` pair additionally overlaps a possible distinct function-entry prologue and must not be judged by naive linear scanning of preceding data. A linear `objdump --start-address` from the bad address will invent instructions; remove affected rows, branch lists and any conclusions that depend on them. For each address below, preserve the source historical appendix unchanged; the listed **candidate preceding instruction anchor** is only a local decode location, not proof of a reachable root or that the original entry is invalid. In particular, the `0x4AEDB0` case needs function-start proof. Full function-root/control-flow re-decoding and independent T01 re-review are still required for a `READY_FOR_REVIEW` claim; this is explicitly **not** a fabricated full rooted CFG.


|原錯誤起點|候選前置 decode 起點（T01 建議／本次局部重解）|實檔 raw 摘要|
|---|---|---|
|`0x6F4E83`|`0x6F4E81`|`VA 0x006F4E81, .text raw 0x002F4281: e8 ea 98 00 00 83 c4 0c 83 fb ff 75`|

#### 原始 bytes 上 anchored decode（只是候選局部窗口，非全 CFG）

`原錯誤窗口起點 0x6F4E83`，從先前指令 `0x6F4E81` 解碼：

```asm
  6f4e81:	e8 ea 98 00 00       	call   0x6fe770
  6f4e86:	83 c4 0c             	add    esp,0xc
  6f4e89:	83 fb ff             	cmp    ebx,0xffffffff
  6f4e8c:	75 0e                	jne    0x6f4e9c
  6f4e8e:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4e91:	8b 76              	mov    esi,DWORD PTR [esi+0x8]
```

**需 T01 下一步：** 找到完整 containing function entry，從 root 和可到達 edges 重新解碼，重做原報告附錄與由該附錄推導的所有 call/branch list；未修完前不要標 `READY_FOR_REVIEW`。

## 本次第一手 BIN 反組譯（指定入口）

注意：下面以函式入口開始連續解碼，**不自動等於完整可達 CFG**；不追逐 SEH/thunk 外部段、不可把無控制流根據的線性尾端當必然執行。

### 入口 `0x6F4DD0` 到 `0x6F4F10`

```asm
  6f4dd0:	55                   	push   ebp
  6f4dd1:	8b ec                	mov    ebp,esp
  6f4dd3:	83 e4 f8             	and    esp,0xfffffff8
  6f4dd6:	83 ec 14             	sub    esp,0x14
  6f4dd9:	53                   	push   ebx
  6f4dda:	56                   	push   esi
  6f4ddb:	57                   	push   edi
  6f4ddc:	8b f8                	mov    edi,eax
  6f4dde:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4de0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4de3:	8d 5e 48             	lea    ebx,[esi+0x48]
  6f4de6:	8d 48 01             	lea    ecx,[eax+0x1]
  6f4de9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  6f4df0:	8a 10                	mov    dl,BYTE PTR [eax]
  6f4df2:	40                   	inc    eax
  6f4df3:	84 d2                	test   dl,dl
  6f4df5:	75 f9                	jne    0x6f4df0
  6f4df7:	2b c1                	sub    eax,ecx
  6f4df9:	50                   	push   eax
  6f4dfa:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4dfd:	50                   	push   eax
  6f4dfe:	56                   	push   esi
  6f4dff:	e8 6c 9e 00 00       	call   0x6fec70
  6f4e04:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6f4e07:	83 c4 0c             	add    esp,0xc
  6f4e0a:	51                   	push   ecx
  6f4e0b:	8d 54 24 14          	lea    edx,[esp+0x14]
  6f4e0f:	52                   	push   edx
  6f4e10:	53                   	push   ebx
  6f4e11:	56                   	push   esi
  6f4e12:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4e16:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  6f4e1d:	00 
  6f4e1e:	e8 2d 6a 00 00       	call   0x6fb850
  6f4e23:	bb 10 00 00 00       	mov    ebx,0x10
  6f4e28:	01 5e 08             	add    DWORD PTR [esi+0x8],ebx
  6f4e2b:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4e2d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  6f4e30:	2b c3                	sub    eax,ebx
  6f4e32:	83 c4 10             	add    esp,0x10
  6f4e35:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  6f4e3a:	0f 84 b5 00 00 00    	je     0x6f4ef5
  6f4e40:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
  6f4e44:	0f 85 ab 00 00 00    	jne    0x6f4ef5
  6f4e4a:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  6f4e4d:	8d 45 14             	lea    eax,[ebp+0x14]
  6f4e50:	50                   	push   eax
  6f4e51:	57                   	push   edi
  6f4e52:	e8 79 fe ff ff       	call   0x6f4cd0
  6f4e57:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4e59:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  6f4e5c:	8d 48 01             	lea    ecx,[eax+0x1]
  6f4e5f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4e62:	c1 e1 04             	shl    ecx,0x4
  6f4e65:	2b c1                	sub    eax,ecx
  6f4e67:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4e6b:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4e6e:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4e72:	50                   	push   eax
  6f4e73:	52                   	push   edx
  6f4e74:	68 50 5a 6f 00       	push   0x6f5a50
  6f4e79:	33 d2                	xor    edx,edx
  6f4e7b:	8b c6                	mov    eax,esi
  6f4e7d:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  6f4e81:	e8 ea 98 00 00       	call   0x6fe770
  6f4e86:	83 c4 0c             	add    esp,0xc
  6f4e89:	83 fb ff             	cmp    ebx,0xffffffff
  6f4e8c:	75 0e                	jne    0x6f4e9c
  6f4e8e:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4e91:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4e94:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4e97:	72 03                	jb     0x6f4e9c
  6f4e99:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4e9c:	85 c0                	test   eax,eax
  6f4e9e:	0f 84 87 00 00 00    	je     0x6f4f2b
  6f4ea4:	8b 3f                	mov    edi,DWORD PTR [edi]
  6f4ea6:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f4ea9:	83 ee 10             	sub    esi,0x10
  6f4eac:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  6f4eb0:	74 25                	je     0x6f4ed7
  6f4eb2:	e8 19 67 00 00       	call   0x6fb5d0
  6f4eb7:	85 c0                	test   eax,eax
  6f4eb9:	75 04                	jne    0x6f4ebf
  6f4ebb:	33 f6                	xor    esi,esi
  6f4ebd:	eb 1d                	jmp    0x6f4edc
  6f4ebf:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6f4ec2:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6f4ec5:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6f4ec8:	72 07                	jb     0x6f4ed1
  6f4eca:	8b c7                	mov    eax,edi
  6f4ecc:	e8 cf 64 00 00       	call   0x6fb3a0
  6f4ed1:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f4ed4:	83 ee 10             	sub    esi,0x10
  6f4ed7:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4ed9:	83 c6 10             	add    esi,0x10
  6f4edc:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  6f4edf:	56                   	push   esi
  6f4ee0:	52                   	push   edx
  6f4ee1:	68 78 26 c4 00       	push   0xc42678
  6f4ee6:	e8 d2 e1 19 00       	call   0x8930bd
  6f4eeb:	83 c4 0c             	add    esp,0xc
  6f4eee:	5f                   	pop    edi
  6f4eef:	5e                   	pop    esi
  6f4ef0:	5b                   	pop    ebx
  6f4ef1:	8b e5                	mov    esp,ebp
  6f4ef3:	5d                   	pop    ebp
  6f4ef4:	c3                   	ret
  6f4ef5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4ef8:	50                   	push   eax
  6f4ef9:	68 10 26 c4 00       	push   0xc42610
  6f4efe:	e8 ba e1 19 00       	call   0x8930bd
  6f4f03:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4f05:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6f4f08:	83 c4 08             	add    esp,0x8
  6f4f0b:	3b 48 0c             	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f0e:	73 15                	jae    0x6f4f25
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
