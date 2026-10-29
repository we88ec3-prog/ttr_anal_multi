# T16-002 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-012719-chatgpt-web-roy-T16-2-KR-Lua-dispatch-and-quest-fields.md`
- **舊原稿 Git blob SHA**：`c3c7a7efc3b1aed44d9bb3187e652ba3638ae595`
- T01 通知：`T01-RETURN-T16-002-9c70bd9f`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容

In the hypothetical C++ for `0x6F4A50`, `if (!file) return false;` is semantically wrong when presented as raw native status. Native code initializes `ESI=1` at 0x6F4A94; missing file reaches 0x6F4BCF and returns that nonzero status, while successful parse sets ESI=0. Correct pseudocode:
```cpp
// Raw status only, not a bool API wrapper.
int load_script_raw_status(...) {
    int status = 1; // failure by default
    if (!resource) return status; // nonzero error
    // ... parse only on valid source; success path explicitly stores 0
    if (parse_succeeded) status = 0;
    return status;
}
```
A separate bool wrapper could be `return load_script_raw_status(...) == 0;`, but such a wrapper is **illustrative only**; no evidence that original Client uses it.

## 本次第一手 BIN 反組譯（指定入口）

注意：下面以函式入口開始連續解碼，**不自動等於完整可達 CFG**；不追逐 SEH/thunk 外部段、不可把無控制流根據的線性尾端當必然執行。

### 入口 `0x6F4A50` 到 `0x6F4C10`

```asm
  6f4a50:	55                   	push   ebp
  6f4a51:	8b ec                	mov    ebp,esp
  6f4a53:	83 e4 f8             	and    esp,0xfffffff8
  6f4a56:	81 ec 2c 02 00 00    	sub    esp,0x22c
  6f4a5c:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6f4a61:	33 c4                	xor    eax,esp
  6f4a63:	89 84 24 28 02 00 00 	mov    DWORD PTR [esp+0x228],eax
  6f4a6a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4a6d:	53                   	push   ebx
  6f4a6e:	56                   	push   esi
  6f4a6f:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  6f4a73:	57                   	push   edi
  6f4a74:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  6f4a78:	2b d0                	sub    edx,eax
  6f4a7a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  6f4a80:	8a 08                	mov    cl,BYTE PTR [eax]
  6f4a82:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  6f4a85:	40                   	inc    eax
  6f4a86:	84 c9                	test   cl,cl
  6f4a88:	75 f6                	jne    0x6f4a80
  6f4a8a:	8d 54 24 30          	lea    edx,[esp+0x30]
  6f4a8e:	68 e0 d1 be 00       	push   0xbed1e0
  6f4a93:	52                   	push   edx
  6f4a94:	be 01 00 00 00       	mov    esi,0x1
  6f4a99:	e8 d2 fc 01 00       	call   0x714770
  6f4a9e:	8b f8                	mov    edi,eax
  6f4aa0:	83 c4 08             	add    esp,0x8
  6f4aa3:	85 ff                	test   edi,edi
  6f4aa5:	0f 84 24 01 00 00    	je     0x6f4bcf
  6f4aab:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4aad:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  6f4ab0:	8b cf                	mov    ecx,edi
  6f4ab2:	ff d2                	call   edx
  6f4ab4:	8b f0                	mov    esi,eax
  6f4ab6:	8d 46 01             	lea    eax,[esi+0x1]
  6f4ab9:	50                   	push   eax
  6f4aba:	e8 7e 91 18 00       	call   0x87dc3d
  6f4abf:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4ac1:	83 c4 04             	add    esp,0x4
  6f4ac4:	8b d8                	mov    ebx,eax
  6f4ac6:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  6f4ac9:	56                   	push   esi
  6f4aca:	8b cf                	mov    ecx,edi
  6f4acc:	ff d0                	call   eax
  6f4ace:	50                   	push   eax
  6f4acf:	53                   	push   ebx
  6f4ad0:	e8 fb 90 1a 00       	call   0x89dbd0
  6f4ad5:	c6 04 1e 00          	mov    BYTE PTR [esi+ebx*1],0x0
  6f4ad9:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4adb:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  6f4ade:	83 c4 0c             	add    esp,0xc
  6f4ae1:	8b cf                	mov    ecx,edi
  6f4ae3:	ff d0                	call   eax
  6f4ae5:	83 f8 03             	cmp    eax,0x3
  6f4ae8:	72 48                	jb     0x6f4b32
  6f4aea:	80 3b ef             	cmp    BYTE PTR [ebx],0xef
  6f4aed:	75 43                	jne    0x6f4b32
  6f4aef:	80 7b 01 bb          	cmp    BYTE PTR [ebx+0x1],0xbb
  6f4af3:	75 3d                	jne    0x6f4b32
  6f4af5:	80 7b 02 bf          	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4af9:	75 37                	jne    0x6f4b32
  6f4afb:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4aff:	8b 16                	mov    edx,DWORD PTR [esi]
  6f4b01:	83 c0 fd             	add    eax,0xfffffffd
  6f4b04:	50                   	push   eax
  6f4b05:	8d 4b 03             	lea    ecx,[ebx+0x3]
  6f4b08:	51                   	push   ecx
  6f4b09:	33 c0                	xor    eax,eax
  6f4b0b:	e8 00 26 00 00       	call   0x6f7110
  6f4b10:	83 c4 08             	add    esp,0x8
  6f4b13:	85 c0                	test   eax,eax
  6f4b15:	0f 85 9d 00 00 00    	jne    0x6f4bb8
  6f4b1b:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b1d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b20:	83 e8 10             	sub    eax,0x10
  6f4b23:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b27:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b2a:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4b2e:	50                   	push   eax
  6f4b2f:	52                   	push   edx
  6f4b30:	eb 57                	jmp    0x6f4b89
  6f4b32:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4b36:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6f4b38:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f4b3c:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f4b40:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6f4b44:	33 c0                	xor    eax,eax
  6f4b46:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  6f4b4a:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  6f4b4e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4b52:	51                   	push   ecx
  6f4b53:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f4b58:	8d 44 24 20          	lea    eax,[esp+0x20]
  6f4b5c:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  6f4b60:	c7 44 24 28 e0 70 6f 	mov    DWORD PTR [esp+0x28],0x6f70e0
  6f4b67:	00 
  6f4b68:	e8 23 9e 00 00       	call   0x6fe990
  6f4b6d:	83 c4 04             	add    esp,0x4
  6f4b70:	85 c0                	test   eax,eax
  6f4b72:	75 44                	jne    0x6f4bb8
  6f4b74:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b76:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b79:	83 e8 10             	sub    eax,0x10
  6f4b7c:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b80:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b83:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  6f4b87:	50                   	push   eax
  6f4b88:	51                   	push   ecx
  6f4b89:	68 50 5a 6f 00       	push   0x6f5a50
  6f4b8e:	33 d2                	xor    edx,edx
  6f4b90:	8b c6                	mov    eax,esi
  6f4b92:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  6f4b99:	ff 
  6f4b9a:	e8 d1 9b 00 00       	call   0x6fe770
  6f4b9f:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4ba2:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4ba5:	83 c4 0c             	add    esp,0xc
  6f4ba8:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4bab:	72 03                	jb     0x6f4bb0
  6f4bad:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4bb0:	85 c0                	test   eax,eax
  6f4bb2:	75 04                	jne    0x6f4bb8
  6f4bb4:	33 f6                	xor    esi,esi
  6f4bb6:	eb 05                	jmp    0x6f4bbd
  6f4bb8:	be 01 00 00 00       	mov    esi,0x1
  6f4bbd:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4bbf:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6f4bc2:	8b cf                	mov    ecx,edi
  6f4bc4:	ff d0                	call   eax
  6f4bc6:	53                   	push   ebx
  6f4bc7:	e8 71 d1 19 00       	call   0x891d3d
  6f4bcc:	83 c4 04             	add    esp,0x4
  6f4bcf:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  6f4bd3:	51                   	push   ecx
  6f4bd4:	8d 94 24 34 01 00 00 	lea    edx,[esp+0x134]
  6f4bdb:	68 9c 26 c4 00       	push   0xc4269c
  6f4be0:	52                   	push   edx
  6f4be1:	e8 49 df 19 00       	call   0x892b2f
  6f4be6:	83 c4 0c             	add    esp,0xc
  6f4be9:	85 f6                	test   esi,esi
  6f4beb:	74 12                	je     0x6f4bff
  6f4bed:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  6f4bf1:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  6f4bf8:	50                   	push   eax
  6f4bf9:	51                   	push   ecx
  6f4bfa:	e8 a1 fb ff ff       	call   0x6f47a0
  6f4bff:	8b 8c 24 34 02 00 00 	mov    ecx,DWORD PTR [esp+0x234]
  6f4c06:	5f                   	pop    edi
  6f4c07:	8b c6                	mov    eax,esi
  6f4c09:	5e                   	pop    esi
  6f4c0a:	5b                   	pop    ebx
  6f4c0b:	33 cc                	xor    ecx,esp
  6f4c0d:	e8 ef c3         	call   0x891001
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
