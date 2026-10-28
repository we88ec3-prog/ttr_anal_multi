# T01-011 — KR T08 主索引登記→查找→移除：主張級 CFG 審核

- 審核時間：20261028-120507 Asia/Taipei；T01 整合者獨立審核，不修改 T08 owner 原始研究稿。
- 原始 KR BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- BIN 12,472,320 bytes；PE32 / x86；`.text` VA 0x00401000 / raw 0x400，VA→raw `raw=VA-0x00400C00`（僅限 `.text`）。
- 來源：`shared/integrations/T01-20261028-07/README.md`、`T01-20261028-10/README.md` 與 T08-184/188/192/193/196/200 等對應原稿；本次以原始 BIN 重新完整反組譯**以下四個限定函式／視窗**，而非只比對入口 prologue。
- 未執行／附加遊戲，不修改目標，沒有取得原版 Server 行為。驗收不是遊戲可玩性證明。

## 結論／證據分級

| 編號 | 主張 | 可直接追溯的原生證據 | 本輪狀態 |
|---|---|---|---|
| R1 | `0x004DFF30` 從 actor-like 指標 `[edi+4]` **只讀 unsigned 16-bit key** | `0x4DFF3C mov edi,eax; 0x4DFF4C movzx eax,WORD PTR [edi+4]` | **PASS（局部指令與資料流）** |
| R2 | 登記路徑從 owner `[ebp+8]` 的 `owner+8` tree header 呼叫 `0x82EF00` 找候選，與 `owner+0xC` sentinel 比較 | `0x4DFF37`, `0x4DFF56`, `0x4DFF5F`, `0x4DFF67` | **PASS（局部資料流）** |
| R3 | 未命中 sentinel 比對時 `je`? **實際是 `jne 0x4DFF90`：候選不等 sentinel 表示已找到 key，走 message handler**；候選等 sentinel 才進 insert | `0x4DFF6A jne`, `0x4DFF82 call 0x82F200`, `0x4DFF99 call 0x6EDB60` | **PASS（分支互斥與直接 call）** |
| R4 | `0x82EF00` 為有界樹 key 搜尋：以 `node+0x0C` DWORD key 作 unsigned 比較，沿 `node+0x00`、`node+0x08` links；哨兵 `node+0x15`；回傳候選或 header sentinel 到 `[eax]` | `0x82EF0B..0x82EF64` | **PASS（候選查找 CFG）；樹具體 C++ 型別 UNKNOWN** |
| R5 | `0x82F200` insertion 也以 `node+0x0C` 比較決定左/右分支；委派 `0x44BD00` 完成結構插入，回傳 result 指標／標誌 | `0x82F21F..0x82F2C3`，注意原始函式入口 `0x82F200` 到 `0x82F2C3` | **PASS（局部分支/callee），不推論所有節點配置/例外** |
| R6 | `0x004DFBC0` 依同一 helper 查找；當回傳與 `[owner+0x0C]` sentinel 相等直接 return，非相等才依序進三次虛擬呼叫、payload 兩次虛擬處理、`0x7B6890` unlink | `0x4DFBD5`, `0x4DFBDD..0x4DFBE0`, `0x4DFBE4..0x4DFC1E` | **PASS（這個函式的可見呼叫順序）；動態方法目標 UNKNOWN** |
| R7 | 登記 duplicate 分支立即釋放新 actor | 在 `0x4DFF90..0x4DFFA7` **沒有直接 delete/free** | **NOT PROVEN（只可否定此視窗直接 free；handler 間接行為未追）** |
| R8 | 樹與 actor 由同一 owner 唯一擁有 | 可見 `node+0x10` payload 與虛擬 release，但無完整 allocation/caller 證據 | **DEFERRED / UNVERIFIED** |

## 精確分支及資料流

- `0x004DFF30` 非典型 calling convention：`eax` 傳入 actor-like 指標，`[ebp+8]` 作 owner。先 test actor-like ptr；若零則 call `0x6EDC70`，**函式內沒有直接 return**，後續仍存取 `[edi+4]`。該 call 是 fatal/assert 還是可能返回，需另核對，不能直接認為 null-safe。
- key：`movzx eax,word ptr [edi+4]` → `[ebp+8]` stack slot 變成 lookup key；owner 原指標已先複製進 ebx。`owner+8` 作 tree view；`owner+0xC` 是供此函式比較的 sentinel pointer。**這裡不能用相同 offset 套到其他 owner 類型**。
- `0x82EF00` 使用 unsigned 比較：`node.key < requested` 時往 `node+8`（右），否則維持候選並走 `node+0`（左），結束後比對最後候選是否 `candidate.key >= request`；若不足則回 sentinel。此為 lower_bound 風格（型別名為推測）；**並非找到任意近似 key 就直接回命中**。
- 等 sentinel → call `0x57EF20` 產生插入參數 → call `0x82F200` 插入。非 sentinel → call `0x6EDB60`，傳入 `0xC0CEF0` 和 key。此處沒有新 actor 替換舊 actor 的直接指令。
- 移除入口 `0x4DFBC0` 的 owner 由 eax 而非登記函式的 `[ebp+8]` 傳入，key 由 `[ebp+8]`。先 call 同一 `0x82EF00`；命中才跑 `esi=0..2` 對 `[0xFBA7A4]` 物件的 vtable `+0x1C`；隨後 `node+0x10` payload vtable `+0x14`；如果 payload pointer 非零，再呼叫其 vtable `+0x00` 並將 `node+0x10` 清零；最後 call `0x7B6890` 刪除樹節點。
- **邊界/疑點**：在 `0x4DFBF8` 首次使用 `[edi+0x10]` 之前沒有可見的 null guard。除非前面的 vcall 會確保有效，否則這個分支依賴其非零，不能宣稱函式可處理空 payload。`0x4DFC02` 後才有 null check。

## bounded pseudocode（保留指標/生命週期未知）

```cpp
void register_key(ActorLike* actor /* EAX */, Owner* owner /* stack arg */) {
  if (!actor) unknown_handler_6edc70(0xC0CED0);  // 未證實不返回
  uint32_t key = uint16_t(actor->field_04);
  Node* candidate = tree_lower_bound(owner->tree_08, key); // 82EF00
  if (candidate == owner->sentinel_0C) {
    // helper 57EF20 creates insertion auxiliary; exact type pending
    tree_insert_82f200(/* register path */);
  } else {
    unknown_message_6edb60(0xC0CEF0, key);
  }
}
void remove_key(Owner* owner /* EAX */, uint32_t key /* stack */) {
  Node* n = tree_lower_bound(owner->tree_08, key);
  if (n == owner->sentinel_0C) return;
  for (int i=0;i<3;i++) global_fba7a4->vcall_1c(i);
  n->payload_10->vcall_14(); // 可見路徑沒有事先 null check
  if (n->payload_10) { n->payload_10->vcall_00(1); n->payload_10=nullptr; }
  tree_unlink_7b6890(owner->tree_08, key, n);
}
```

## 本階段驗收決策

- **局部 native confirmed**：R1–R6 的精確 CFG／資料流／callee 相關主張。這是 T01 可獨立重現的實際增加驗收範圍。
- **原稿未升級為全篇 confirmed**：T08-184/188/192/193/196/200 尚有大量不在本次視窗的動態 dispatch、所有權、雙樹 alias 與初始化問題；其原作者原文保留不改。
- **缺件／待補**：`0x44BD00` 和 `0x7B6890` 的完整樹修補／回收；`0x57EF20` 配置回傳型別；`0x6EDB60` 是否可能改動/釋放 actor；payload 動態 vtable；跨 T02/T07 的遊玩時序。這些**沒有因此判錯或完成**。
- **三輪深入**：第 1 輪從 register/remove 延伸至 lower_bound 與 insert helper，已將先前只驗證入口 byte 的證據提升至有限完整查找/插入控制流，達到本階段可用且有界的功能鏈進展；第 2/3 輪**未啟動**，不捏造。
- **Git**：使用者本輪說「繼續下一個 T01 階段」，未明確要求 commit/push；因此只建立本地可下載原稿，**未修改 GitHub**。

## 第一手 BIN 反組譯附錄

### Registration / duplicate — 0x4dff30..0x4dffaa

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dff30 <.text+0xdef30>:
  4dff30:	55                   	push   ebp
  4dff31:	8b ec                	mov    ebp,esp
  4dff33:	83 ec 10             	sub    esp,0x10
  4dff36:	53                   	push   ebx
  4dff37:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dff3a:	56                   	push   esi
  4dff3b:	57                   	push   edi
  4dff3c:	8b f8                	mov    edi,eax
  4dff3e:	85 ff                	test   edi,edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dff50:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dff53:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4dff56:	8d 73 08             	lea    esi,[ebx+0x8]
  4dff59:	51                   	push   ecx
  4dff5a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dff5d:	8b ce                	mov    ecx,esi
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4dff67:	3b 53 0c             	cmp    edx,DWORD PTR [ebx+0xc]
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dff6f:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4dff72:	8d 7d f4             	lea    edi,[ebp-0xc]
  4dff75:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   eax
  4dff7e:	56                   	push   esi
  4dff7f:	8d 75 f4             	lea    esi,[ebp-0xc]
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    edi
  4dff88:	5e                   	pop    esi
  4dff89:	5b                   	pop    ebx
  4dff8a:	8b e5                	mov    esp,ebp
  4dff8c:	5d                   	pop    ebp
  4dff8d:	c2 04 00             	ret    0x4
  4dff90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4dff93:	51                   	push   ecx
  4dff94:	68 f0 ce c0 00       	push   0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    esp,0x8
  4dffa1:	5f                   	pop    edi
  4dffa2:	5e                   	pop    esi
  4dffa3:	5b                   	pop    ebx
  4dffa4:	8b e5                	mov    esp,ebp
  4dffa6:	5d                   	pop    ebp
  4dffa7:	c2 04 00             	ret    0x4

```

### Tree lower-bound lookup — 0x82ef00..0x82ef67

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0082ef00 <.text+0x42df00>:
  82ef00:	55                   	push   ebp
  82ef01:	8b ec                	mov    ebp,esp
  82ef03:	51                   	push   ecx
  82ef04:	53                   	push   ebx
  82ef05:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  82ef08:	56                   	push   esi
  82ef09:	8b f1                	mov    esi,ecx
  82ef0b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  82ef0e:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  82ef11:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  82ef15:	75 1e                	jne    0x82ef35
  82ef17:	57                   	push   edi
  82ef18:	8b 3b                	mov    edi,DWORD PTR [ebx]
  82ef1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  82ef20:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  82ef23:	73 05                	jae    0x82ef2a
  82ef25:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  82ef28:	eb 04                	jmp    0x82ef2e
  82ef2a:	8b d1                	mov    edx,ecx
  82ef2c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  82ef2e:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  82ef32:	74 ec                	je     0x82ef20
  82ef34:	5f                   	pop    edi
  82ef35:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  82ef38:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  82ef3b:	3b d1                	cmp    edx,ecx
  82ef3d:	74 16                	je     0x82ef55
  82ef3f:	8b 33                	mov    esi,DWORD PTR [ebx]
  82ef41:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  82ef44:	72 0f                	jb     0x82ef55
  82ef46:	8d 4d 08             	lea    ecx,[ebp+0x8]
  82ef49:	8b 09                	mov    ecx,DWORD PTR [ecx]
  82ef4b:	5e                   	pop    esi
  82ef4c:	89 08                	mov    DWORD PTR [eax],ecx
  82ef4e:	5b                   	pop    ebx
  82ef4f:	8b e5                	mov    esp,ebp
  82ef51:	5d                   	pop    ebp
  82ef52:	c2 04 00             	ret    0x4
  82ef55:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  82ef58:	8d 4d fc             	lea    ecx,[ebp-0x4]
  82ef5b:	8b 09                	mov    ecx,DWORD PTR [ecx]
  82ef5d:	5e                   	pop    esi
  82ef5e:	89 08                	mov    DWORD PTR [eax],ecx
  82ef60:	5b                   	pop    ebx
  82ef61:	8b e5                	mov    esp,ebp
  82ef63:	5d                   	pop    ebp
  82ef64:	c2 04 00             	ret    0x4

```

### Tree insert path — 0x82f200..0x82f2c6

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0082f200 <.text+0x42e200>:
  82f200:	55                   	push   ebp
  82f201:	8b ec                	mov    ebp,esp
  82f203:	83 ec 08             	sub    esp,0x8
  82f206:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  82f209:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  82f20c:	53                   	push   ebx
  82f20d:	57                   	push   edi
  82f20e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  82f211:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  82f214:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  82f218:	b1 01                	mov    cl,0x1
  82f21a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  82f21d:	75 1f                	jne    0x82f23e
  82f21f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  82f222:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  82f225:	8b f8                	mov    edi,eax
  82f227:	0f 92 c1             	setb   cl
  82f22a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  82f22d:	84 c9                	test   cl,cl
  82f22f:	74 04                	je     0x82f235
  82f231:	8b 00                	mov    eax,DWORD PTR [eax]
  82f233:	eb 03                	jmp    0x82f238
  82f235:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  82f238:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  82f23c:	74 e4                	je     0x82f222
  82f23e:	8b df                	mov    ebx,edi
  82f240:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  82f243:	84 c9                	test   cl,cl
  82f245:	74 3a                	je     0x82f281
  82f247:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  82f24a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  82f24d:	3b 38                	cmp    edi,DWORD PTR [eax]
  82f24f:	75 22                	jne    0x82f273
  82f251:	52                   	push   edx
  82f252:	6a 01                	push   0x1
  82f254:	8d 55 0c             	lea    edx,[ebp+0xc]
  82f257:	8b c7                	mov    eax,edi
  82f259:	52                   	push   edx
  82f25a:	8b f9                	mov    edi,ecx
  82f25c:	e8 9f ca c1 ff       	call   0x44bd00
  82f261:	8b 00                	mov    eax,DWORD PTR [eax]
  82f263:	5f                   	pop    edi
  82f264:	89 06                	mov    DWORD PTR [esi],eax
  82f266:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  82f26a:	8b c6                	mov    eax,esi
  82f26c:	5b                   	pop    ebx
  82f26d:	8b e5                	mov    esp,ebp
  82f26f:	5d                   	pop    ebp
  82f270:	c2 08 00             	ret    0x8
  82f273:	8d 45 fc             	lea    eax,[ebp-0x4]
  82f276:	e8 25 06 d1 ff       	call   0x53f8a0
  82f27b:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  82f27e:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  82f281:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  82f284:	52                   	push   edx
  82f285:	3b 4a 0c             	cmp    ecx,DWORD PTR [edx+0xc]
  82f288:	73 24                	jae    0x82f2ae
  82f28a:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  82f28d:	52                   	push   edx
  82f28e:	8d 45 0c             	lea    eax,[ebp+0xc]
  82f291:	50                   	push   eax
  82f292:	8b c7                	mov    eax,edi
  82f294:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  82f297:	e8 64 ca c1 ff       	call   0x44bd00
  82f29c:	8b 08                	mov    ecx,DWORD PTR [eax]
  82f29e:	5f                   	pop    edi
  82f29f:	89 0e                	mov    DWORD PTR [esi],ecx
  82f2a1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  82f2a5:	8b c6                	mov    eax,esi
  82f2a7:	5b                   	pop    ebx
  82f2a8:	8b e5                	mov    esp,ebp
  82f2aa:	5d                   	pop    ebp
  82f2ab:	c2 08 00             	ret    0x8
  82f2ae:	e8 59 1f 06 00       	call   0x89120c
  82f2b3:	83 c4 04             	add    esp,0x4
  82f2b6:	5f                   	pop    edi
  82f2b7:	89 1e                	mov    DWORD PTR [esi],ebx
  82f2b9:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  82f2bd:	8b c6                	mov    eax,esi
  82f2bf:	5b                   	pop    ebx
  82f2c0:	8b e5                	mov    esp,ebp
  82f2c2:	5d                   	pop    ebp
  82f2c3:	c2 08 00             	ret    0x8

```

### Removal callback / node unlink — 0x4dfbc0..0x4dfc2c

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4

```