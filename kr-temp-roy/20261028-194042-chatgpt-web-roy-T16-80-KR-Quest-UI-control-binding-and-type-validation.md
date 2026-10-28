# KR T16-80 — Quest UI 控件 ID 綁定與型別驗證的原生鏈

- 研究者：chatgpt-web roy；日期：20261028-194042 Asia/Taipei；KR only。
- 原始 BIN：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- BIN PE32 x86 `.text` VA `0x401000` raw `0x400`，該節內 raw = VA - `0x400C00`；不同節須重新映射。
- 原件唯讀，未執行、附加、修補 Client；沒有真實 Quest 封包流量。分別標示原生已確認、部分確認及 unknown。

## 0. 研究目標與上一段關係

T16-79 已確認內部物件 vtable `0xC2DA0C`，其 +`0x114` 指向 `0x62E380`；本段從該方法延伸 UI 控件查找、runtime 型別驗證、指標回填、錯誤分支；不將 UI ID 或 widget 類型碼誤作網路 opcode。

## 1. 第一輪 T16-80：完整 UI binding 鏈（重大實質新進展）

`0x62E380` 先 `mov esi,ecx; call 0x755E50`；再按控制項數值呼叫 `0x43C570`、`0x615FC0`、`0x6AE700`，用 **EDI** 指向物件內的目的欄位。這些 helper 搜尋指定 ID 的控制物件，呼叫取得物件型別碼的 vtable +`0x04`，如吻合則將找到的 pointer 寫入 `[edi]`。

| Lookup number | object destination | invoked helper | expected control-type code | evidence |
|---|---|---|---|---|
| `0x2710` | `+0x108` | `0x43C570` | `0xC8` | native confirmed |
| `0x2AF8` | `+0x10C` | `0x615FC0` | `0x12D` | native confirmed |
| `0x4E20` (in helper) | `+0x110` | `0x6AE700` | `0x514` | native confirmed |
| `0x7530` | `+0xFC` | `0x615FC0` | `0x12D` | native confirmed |
| `0x9C40` | `+0x104` | `0x615FC0` | `0x12D` | native confirmed |
| `0xC350` | `+0x100` | `0x615FC0` | `0x12D` | native confirmed |
| `0x1ADB0` | `+0x12C` | `0x43C570` | `0xC8` | native confirmed |

注意：`0x62E380` 的 call site 將 ID 以 `push` 傳遞（`0x6AE700` 則內部固定 `push 0x4E20`）；**呼叫後 `0x62E403` 一次 `add esp,0x18`**，代表以上部分 helper 尚有堆疊呼叫慣例需處理；不得用一般 cdecl 推定所有 helper 的 ABI。所有欄位表示保存 widget pointer 的候選，已見指標回填而非 Quest 狀態寫入。

### 重要後置欄位寫入

`0x62E403`: `mov eax,[esi+0x110]`；`0x62E40E`: `mov dword [eax+0xD4],0`，**只在控制指標有效時安全**。若 helper 未找到或型別不符的錯誤路徑仍可返回，動態錯誤處理可能中斷執行；無執行觀察，不可聲稱所有失敗路徑安全。

## 2. 第二輪 T16-80-2：helper data flow、成功／失敗條件

`0x43C570` / `0x615FC0` 的共享形態：

```cpp
// ABI schematic only: ECX contains parent; EDI points to destination slot.
auto found = lookup_child(parent, numeric_id); // native call 0x746940
if (found != nullptr) {
    auto code = found->vtable[1](found); // byte offset +0x04
    if (code == expected_code) *destination = found;
    else diagnostics(); // native diagnostic path; details unconfirmed
} else diagnostics();
```

- `0x43C570`: `call 0x746940` → nonnull → vtable+`0x04` → `cmp eax,0xC8` → `[edi]=esi`。
- `0x615FC0`: same lookup + type check, `cmp eax,0x12D`。
- `0x6AE700`: `push 0x4E20` → `call 0x746940` → `cmp eax,0x514` → `[edi]=esi`。
- mismatch / lookup failure branches use diagnostic formatting and indirect imported call at `[0xBD2580]` (import identity not confirmed here). Their behavior is **not** demonstrated to submit a network message.
- `0x755E50`: uses embedded key-index `parent+0x4C` with `0x82EF00`, compares against `[parent+0x50]`, writes key 11 found payload to `parent+0x80` and key 10 found payload to `parent+0xEC`; this is distinct from the numerical widget lookup above.

## 3. 第三輪 T16-80-3：已知 event 與上述 lookup domain 的否證邊界

`0x62E360`: checks event `0x4E22` and calls `0x6306F0` with an address of stack args. `0x62E380` looks up child **ID `0x4E20`** via `0x6AE700`. These are nearby numeric values, yet **no observed call establishes `0x4E22` as click of child `0x4E20`**. Event number and child numeric lookup are different namespaces until callback registry is proven. The `0x6306F0` condition `0x12D` is independent of widget return-code check without further state provenance.

This round's bounded investigation covers the above 3 helper bodies, `0x755E50`, `0x62E360`, and `0x62E380` and their local immediate callees. It does *not* establish the owner of Quest click/accept network producer, Quest-cache writer or S→C handler; it also does not establish negative behavior beyond this bounded CFG. Since the first round already yielded a substantial directly verified multi-function widget binding chain, latter rounds are optional per shared rules; **T16-80-2 and T16-80-3 here are additional focused verification**, not invented large callgraph closure.

## 4. BIN 原生 Assembly 摘錄（raw bytes 由 objdump 原件即時反組譯）

### UI binding 0x62E380 (VA 0x62e380..0x62e41a)

```asm
0062e380 <.text+0x22d380>:
  62e380:	53                   	push   ebx
  62e381:	56                   	push   esi
  62e382:	57                   	push   edi
  62e383:	8b f1                	mov    esi,ecx
  62e385:	e8 c6 7a 12 00       	call   0x755e50
  62e38a:	68 10 27 00 00       	push   0x2710
  62e38f:	8d be 08 01 00 00    	lea    edi,[esi+0x108]
  62e395:	8b ce                	mov    ecx,esi
  62e397:	e8 d4 e1 e0 ff       	call   0x43c570
  62e39c:	68 f8 2a 00 00       	push   0x2af8
  62e3a1:	8d be 0c 01 00 00    	lea    edi,[esi+0x10c]
  62e3a7:	8b ce                	mov    ecx,esi
  62e3a9:	e8 12 7c fe ff       	call   0x615fc0
  62e3ae:	8d be 10 01 00 00    	lea    edi,[esi+0x110]
  62e3b4:	8b ce                	mov    ecx,esi
  62e3b6:	e8 45 03 08 00       	call   0x6ae700
  62e3bb:	68 30 75 00 00       	push   0x7530
  62e3c0:	8d be fc 00 00 00    	lea    edi,[esi+0xfc]
  62e3c6:	8b ce                	mov    ecx,esi
  62e3c8:	e8 f3 7b fe ff       	call   0x615fc0
  62e3cd:	68 40 9c 00 00       	push   0x9c40
  62e3d2:	8d be 04 01 00 00    	lea    edi,[esi+0x104]
  62e3d8:	8b ce                	mov    ecx,esi
  62e3da:	e8 e1 7b fe ff       	call   0x615fc0
  62e3df:	68 50 c3 00 00       	push   0xc350
  62e3e4:	8d be 00 01 00 00    	lea    edi,[esi+0x100]
  62e3ea:	8b ce                	mov    ecx,esi
  62e3ec:	e8 cf 7b fe ff       	call   0x615fc0
  62e3f1:	68 b0 ad 01 00       	push   0x1adb0
  62e3f6:	8d be 2c 01 00 00    	lea    edi,[esi+0x12c]
  62e3fc:	8b ce                	mov    ecx,esi
  62e3fe:	e8 6d e1 e0 ff       	call   0x43c570
  62e403:	8b 86 10 01 00 00    	mov    eax,DWORD PTR [esi+0x110]
  62e409:	83 c4 18             	add    esp,0x18
  62e40c:	5f                   	pop    edi
  62e40d:	5e                   	pop    esi
  62e40e:	c7 80 d4 00 00 00 00 	mov    DWORD PTR [eax+0xd4],0x0
  62e415:	00 00 00 
  62e418:	5b                   	pop    ebx
  62e419:	c3                   	ret
```
### generic control type 0xC8 0x43C570 (VA 0x43c580..0x43c5f4)

```asm
0043c580 <.text+0x3b580>:
  43c580:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  43c583:	56                   	push   esi
  43c584:	8b f1                	mov    esi,ecx
  43c586:	50                   	push   eax
  43c587:	e8 b4 a3 30 00       	call   0x746940
  43c58c:	8b f0                	mov    esi,eax
  43c58e:	85 f6                	test   esi,esi
  43c590:	75 52                	jne    0x43c5e4
  43c592:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  43c597:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  43c59c:	8d 75 e0             	lea    esi,[ebp-0x20]
  43c59f:	e8 dc 84 fc ff       	call   0x404a80
  43c5a4:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  43c5a7:	be 08 00 00 00       	mov    esi,0x8
  43c5ac:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  43c5af:	73 03                	jae    0x43c5b4
  43c5b1:	8d 45 e0             	lea    eax,[ebp-0x20]
  43c5b4:	6a 00                	push   0x0
  43c5b6:	68 c0 1f bf 00       	push   0xbf1fc0
  43c5bb:	50                   	push   eax
  43c5bc:	6a 00                	push   0x0
  43c5be:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  43c5c4:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  43c5c7:	72 7f                	jb     0x43c648
  43c5c9:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  43c5cc:	50                   	push   eax
  43c5cd:	e8 3a 4c 45 00       	call   0x89120c
  43c5d2:	83 c4 04             	add    esp,0x4
  43c5d5:	5e                   	pop    esi
  43c5d6:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  43c5d9:	33 cd                	xor    ecx,ebp
  43c5db:	e8 21 4a 45 00       	call   0x891001
  43c5e0:	8b e5                	mov    esp,ebp
  43c5e2:	5d                   	pop    ebp
  43c5e3:	c3                   	ret
  43c5e4:	8b 16                	mov    edx,DWORD PTR [esi]
  43c5e6:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  43c5e9:	8b ce                	mov    ecx,esi
  43c5eb:	ff d0                	call   eax
  43c5ed:	3d c8 00 00 00       	cmp    eax,0xc8
  43c5f2:	74 52                	je     0x43c646
```
### generic control type 0x12D 0x615FC0 (VA 0x615fd0..0x616044)

```asm
00615fd0 <.text+0x214fd0>:
  615fd0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  615fd3:	56                   	push   esi
  615fd4:	8b f1                	mov    esi,ecx
  615fd6:	50                   	push   eax
  615fd7:	e8 64 09 13 00       	call   0x746940
  615fdc:	8b f0                	mov    esi,eax
  615fde:	85 f6                	test   esi,esi
  615fe0:	75 52                	jne    0x616034
  615fe2:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  615fe7:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  615fec:	8d 75 e0             	lea    esi,[ebp-0x20]
  615fef:	e8 8c ea de ff       	call   0x404a80
  615ff4:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  615ff7:	be 08 00 00 00       	mov    esi,0x8
  615ffc:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  615fff:	73 03                	jae    0x616004
  616001:	8d 45 e0             	lea    eax,[ebp-0x20]
  616004:	6a 00                	push   0x0
  616006:	68 c0 1f bf 00       	push   0xbf1fc0
  61600b:	50                   	push   eax
  61600c:	6a 00                	push   0x0
  61600e:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  616014:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  616017:	72 7f                	jb     0x616098
  616019:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  61601c:	50                   	push   eax
  61601d:	e8 ea b1 27 00       	call   0x89120c
  616022:	83 c4 04             	add    esp,0x4
  616025:	5e                   	pop    esi
  616026:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  616029:	33 cd                	xor    ecx,ebp
  61602b:	e8 d1 af 27 00       	call   0x891001
  616030:	8b e5                	mov    esp,ebp
  616032:	5d                   	pop    ebp
  616033:	c3                   	ret
  616034:	8b 16                	mov    edx,DWORD PTR [esi]
  616036:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  616039:	8b ce                	mov    ecx,esi
  61603b:	ff d0                	call   eax
  61603d:	3d 2d 01 00 00       	cmp    eax,0x12d
  616042:	74 52                	je     0x616096
```
### control 0x4E20 type 0x514 0x6AE700 (VA 0x6ae710..0x6ae785)

```asm
006ae710 <.text+0x2ad710>:
  6ae710:	56                   	push   esi
  6ae711:	8b f1                	mov    esi,ecx
  6ae713:	68 20 4e 00 00       	push   0x4e20
  6ae718:	e8 23 82 09 00       	call   0x746940
  6ae71d:	8b f0                	mov    esi,eax
  6ae71f:	85 f6                	test   esi,esi
  6ae721:	75 52                	jne    0x6ae775
  6ae723:	b9 5c 1f bf 00       	mov    ecx,0xbf1f5c
  6ae728:	b8 68 1f bf 00       	mov    eax,0xbf1f68
  6ae72d:	8d 75 e0             	lea    esi,[ebp-0x20]
  6ae730:	e8 4b 63 d5 ff       	call   0x404a80
  6ae735:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  6ae738:	be 08 00 00 00       	mov    esi,0x8
  6ae73d:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  6ae740:	73 03                	jae    0x6ae745
  6ae742:	8d 45 e0             	lea    eax,[ebp-0x20]
  6ae745:	6a 00                	push   0x0
  6ae747:	68 c0 1f bf 00       	push   0xbf1fc0
  6ae74c:	50                   	push   eax
  6ae74d:	6a 00                	push   0x0
  6ae74f:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  6ae755:	39 75 f4             	cmp    DWORD PTR [ebp-0xc],esi
  6ae758:	72 7f                	jb     0x6ae7d9
  6ae75a:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  6ae75d:	50                   	push   eax
  6ae75e:	e8 a9 2a 1e 00       	call   0x89120c
  6ae763:	83 c4 04             	add    esp,0x4
  6ae766:	5e                   	pop    esi
  6ae767:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6ae76a:	33 cd                	xor    ecx,ebp
  6ae76c:	e8 90 28 1e 00       	call   0x891001
  6ae771:	8b e5                	mov    esp,ebp
  6ae773:	5d                   	pop    ebp
  6ae774:	c3                   	ret
  6ae775:	8b 16                	mov    edx,DWORD PTR [esi]
  6ae777:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6ae77a:	8b ce                	mov    ecx,esi
  6ae77c:	ff d0                	call   eax
  6ae77e:	3d 14 05 00 00       	cmp    eax,0x514
  6ae783:	74 52                	je     0x6ae7d7
```
### nested UI lookup 0x755E50 (VA 0x755e59..0x755ec4)

```asm
00755e59 <.text+0x354e59>:
  755e59:	8d 45 fc             	lea    eax,[ebp-0x4]
  755e5c:	8b f1                	mov    esi,ecx
  755e5e:	50                   	push   eax
  755e5f:	8d 45 f8             	lea    eax,[ebp-0x8]
  755e62:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  755e65:	c7 45 fc 0b 00 00 00 	mov    DWORD PTR [ebp-0x4],0xb
  755e6c:	e8 8f 90 0d 00       	call   0x82ef00
  755e71:	8b 5e 50             	mov    ebx,DWORD PTR [esi+0x50]
  755e74:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  755e77:	3b c3                	cmp    eax,ebx
  755e79:	74 05                	je     0x755e80
  755e7b:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  755e7e:	eb 02                	jmp    0x755e82
  755e80:	33 c0                	xor    eax,eax
  755e82:	8d 4d f8             	lea    ecx,[ebp-0x8]
  755e85:	89 86 80 00 00 00    	mov    DWORD PTR [esi+0x80],eax
  755e8b:	51                   	push   ecx
  755e8c:	8d 45 fc             	lea    eax,[ebp-0x4]
  755e8f:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  755e92:	c7 45 f8 0a 00 00 00 	mov    DWORD PTR [ebp-0x8],0xa
  755e99:	e8 62 90 0d 00       	call   0x82ef00
  755e9e:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  755ea1:	3b c3                	cmp    eax,ebx
  755ea3:	74 10                	je     0x755eb5
  755ea5:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  755ea8:	5f                   	pop    edi
  755ea9:	89 86 ec 00 00 00    	mov    DWORD PTR [esi+0xec],eax
  755eaf:	5e                   	pop    esi
  755eb0:	5b                   	pop    ebx
  755eb1:	8b e5                	mov    esp,ebp
  755eb3:	5d                   	pop    ebp
  755eb4:	c3                   	ret
  755eb5:	33 c0                	xor    eax,eax
  755eb7:	5f                   	pop    edi
  755eb8:	89 86 ec 00 00 00    	mov    DWORD PTR [esi+0xec],eax
  755ebe:	5e                   	pop    esi
  755ebf:	5b                   	pop    ebx
  755ec0:	8b e5                	mov    esp,ebp
  755ec2:	5d                   	pop    ebp
  755ec3:	c3                   	ret
```
### event 0x4E22 (VA 0x62e360..0x62e379)

```asm
0062e360 <.text+0x22d360>:
  62e360:	55                   	push   ebp
  62e361:	8b ec                	mov    ebp,esp
  62e363:	81 7d 08 22 4e 00 00 	cmp    DWORD PTR [ebp+0x8],0x4e22
  62e36a:	75 0a                	jne    0x62e376
  62e36c:	56                   	push   esi
  62e36d:	8d 75 08             	lea    esi,[ebp+0x8]
  62e370:	e8 7b 23 00 00       	call   0x6306f0
  62e375:	5e                   	pop    esi
  62e376:	5d                   	pop    ebp
  62e377:	c2 0c              	ret    0xc
```


## 5. Quest player scenario / network evidence matrix

| Player scenario | Local gate | C→S wire | S→C wire | Client outcome | Server interface / evidence |
|---|---|---|---|---|---|
| Quest UI initialization | child lookup + vtable+4 type check; widget ID above | unknown / no observed producer in bounded paths | unknown | widget pointer fields populated | not required to interpret local setup (native-confirmed local only) |
| Quest button click | event handler not yet mapped | unknown | unknown | unknown | must trace actual UI event source and state writer |
| Accept Quest16 or Quest15 | unknown | unknown | unknown | unknown | compatibility design deferred until wire proof |
| Complete Quest16 → Quest15 available | unknown | unknown | unknown | unknown | compatibility design deferred; official Server algorithm not claimed |

## 6. Distinct data namespaces and remaining gaps

- Widget lookup IDs `0x2710`, `0x2AF8`, `0x4E20`, etc. are **not** Quest IDs or wire opcodes.
- Widget runtime type codes `0xC8`, `0x12D`, `0x514` are **not** Quest IDs or wire opcodes.
- Event selector `0x4E22` is not proven to correspond to `0x4E20` child control.
- `kRequestAcceptQuest` text ID from T16-75 is confirmed localization, and is **not** native wire opcode.
- Need: native handler for actual accept-button click → packet serializer → Queue/WSASend, and receive Quest handler → state cache/UI update; same T02 network layer can be referenced without editing its scope.

## 7. Next T16-81 and Git isolation

Pivot to child-control pointer fields `+0x108/+0x10C/+0x110/+0xFC/+0x104/+0x100/+0x12C` **readers** after initialization to determine registration/click producers. Trace control event dispatch and Quest-state writer from real consumers rather than another class inventory. Keep KR-only and original binary read-only. Researcher notes only under `kr-temp-roy/`, no changes to other task/owner/catalog.