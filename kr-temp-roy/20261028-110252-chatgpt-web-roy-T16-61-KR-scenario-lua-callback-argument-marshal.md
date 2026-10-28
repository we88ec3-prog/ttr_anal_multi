# T16-61 — KR Lua `RequestStartScenario` 回呼、參數型別與間接呼叫驗證

- 對象：**KR T16 only**，《星空幻想 Online》任務與劇情流程；分析日期 `20261028-110252`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 唯讀原件：`/mnt/data/Tartaros.bin`；大小 `12,472,320` bytes；本次 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `.text` 核驗 VA `0x00401000` / raw `0x400`，在本段地址使用 `raw = VA - 0x00400C00`；實際取 `Tartaros.bin` 機器碼，再由 GNU objdump `-m i386 -M intel` 靜態解碼，不執行客戶端。
- GitHub 先前基準為 main `ce87b59efc2712535d04f0cd212ebe0323df23d7`（查詢時），延續 T16-57～60；不改 catalog、owner、其他任務；**不檢查 TC**。
- 分級：`原生已確認` = 這次可核驗的位元組／直線組語；`部分確認` = caller 和 callee 意義尚有條件；`合理推測` = 待證；`資訊缺失` = 沒有原件證據。線性反組譯在跳轉／函式邊界外可能混入非程式位元組，不自稱完成 CFG。

## 核心新確認

- `0x004AC9E0` 以 `[ebp+8]` 的 Lua 來源指標建立 stack local，讀取 `[0x00FE187C]` 並呼叫 `0x004ACB70`。`0x004ACA28` 將 `EAX=1` 返回，代表包裝器本身返回值，而**非**關卡成功旗標。
- `0x004ACB70` 從 Lua 上游參數執行 `0x006F50F0` 型別處理；`[eax+8]==3` 或可轉數字型別 `4` 才進入 FPU 整數化，透過 `push eax; mov ecx,[0x00FE1804]; call dword ptr [ebp+8]` 把 **一個整數** 交給注入的 callback。其他型別／轉換失敗改為 `push 0` 後同樣間接呼叫。
- callback 來源由上層 `[0x00FE187C]` 讀入，不能直接將 `0x004ACB70` 標為 scenario server send。真正被呼叫函式需要追該全域指標的寫入者、初始化、vtable 及其下游。
- `0x004ACA40` 的近似包裝器改用 `[0x00FE1880]`，並呼叫另一個 `0x004ACF90`，**不能**與上面的單參數介面直接合併。

## 回呼 ABI 與控制流摘錄

- VA 0x004ACA16 / raw 0x000ABE16: 8b 0d 7c 18 fe 00 51 8d 45 e8 e8 4b 01 00 00 83 c4 04 b8 01
- VA 0x004ACBC1 / raw 0x000ABFC1: db 5d fc 8b 45 fc 50 8b cb ff 55 08 33 c0 5b 8b e5 5d c3 33 c0 50 8b cb
- VA 0x004ACBD4 / raw 0x000ABFD4: 33 c0 50 8b cb ff 55 08 33 c0 5b 8b e5 5d c3 cc cc cc cc cc

```asm
004ac9e0 <.data+0xabde0>:
  4ac9e0:	55                   	push   ebp
  4ac9e1:	8b ec                	mov    ebp,esp
  4ac9e3:	6a ff                	push   0xffffffff
  4ac9e5:	68 c8 83 93 00       	push   0x9383c8
  4ac9ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac9f0:	50                   	push   eax
  4ac9f1:	83 ec 0c             	sub    esp,0xc
  4ac9f4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac9f9:	33 c5                	xor    eax,ebp
  4ac9fb:	50                   	push   eax
  4ac9fc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac9ff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aca05:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aca08:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4aca0b:	33 c0                	xor    eax,eax
  4aca0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4aca10:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4aca13:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4aca16:	8b 0d 7c 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe187c
  4aca1c:	51                   	push   ecx
  4aca1d:	8d 45 e8             	lea    eax,[ebp-0x18]
  4aca20:	e8 4b 01 00 00       	call   0x4acb70
  4aca25:	83 c4 04             	add    esp,0x4
  4aca28:	b8 01 00 00 00       	mov    eax,0x1
  4aca2d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4aca30:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aca37:	59                   	pop    ecx
  4aca38:	8b e5                	mov    esp,ebp
  4aca3a:	5d                   	pop    ebp
  4aca3b:	c3                   	ret
```

```asm
004acb70 <.data+0xabf70>:
  4acb70:	55                   	push   ebp
  4acb71:	8b ec                	mov    ebp,esp
  4acb73:	8b 08                	mov    ecx,DWORD PTR [eax]
  4acb75:	83 ec 18             	sub    esp,0x18
  4acb78:	53                   	push   ebx
  4acb79:	8b 1d 04 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1804
  4acb7f:	83 c8 ff             	or     eax,0xffffffff
  4acb82:	e8 69 85 24 00       	call   0x6f50f0
  4acb87:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acb8a:	83 f9 03             	cmp    ecx,0x3
  4acb8d:	74 2a                	je     0x4acbb9
  4acb8f:	83 f9 04             	cmp    ecx,0x4
  4acb92:	75 40                	jne    0x4acbd4
  4acb94:	56                   	push   esi
  4acb95:	8b 30                	mov    esi,DWORD PTR [eax]
  4acb97:	57                   	push   edi
  4acb98:	83 c6 10             	add    esi,0x10
  4acb9b:	8d 7d f8             	lea    edi,[ebp-0x8]
  4acb9e:	e8 bd ab 24 00       	call   0x6f7760
  4acba3:	5f                   	pop    edi
  4acba4:	5e                   	pop    esi
  4acba5:	85 c0                	test   eax,eax
  4acba7:	74 2b                	je     0x4acbd4
  4acba9:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4acbac:	c7 45 f0 03 00 00 00 	mov    DWORD PTR [ebp-0x10],0x3
  4acbb3:	dd 5d e8             	fstp   QWORD PTR [ebp-0x18]
  4acbb6:	8d 45 e8             	lea    eax,[ebp-0x18]
  4acbb9:	dd 00                	fld    QWORD PTR [eax]
  4acbbb:	dd 5d f0             	fstp   QWORD PTR [ebp-0x10]
  4acbbe:	dd 45 f0             	fld    QWORD PTR [ebp-0x10]
  4acbc1:	db 5d fc             	fistp  DWORD PTR [ebp-0x4]
  4acbc4:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4acbc7:	50                   	push   eax
  4acbc8:	8b cb                	mov    ecx,ebx
  4acbca:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  4acbcd:	33 c0                	xor    eax,eax
  4acbcf:	5b                   	pop    ebx
  4acbd0:	8b e5                	mov    esp,ebp
  4acbd2:	5d                   	pop    ebp
  4acbd3:	c3                   	ret
  4acbd4:	33 c0                	xor    eax,eax
  4acbd6:	50                   	push   eax
  4acbd7:	8b cb                	mov    ecx,ebx
  4acbd9:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  4acbdc:	33 c0                	xor    eax,eax
  4acbde:	5b                   	pop    ebx
  4acbdf:	8b e5                	mov    esp,ebp
  4acbe1:	5d                   	pop    ebp
  4acbe2:	c3                   	ret
```

## 限定的偽碼

```cpp
// 型別分支與 ABI 為組語直接支持；Lua state/argument 的正式 C++ 型別未確認。
int lua_one_integer_callback(LuaValueLike* src, void (__thiscall *cb)(void*, int)) {
    int parameter = 0;
    auto value = obtain_lua_value(src, /* index=-1 */);
    if (type(value)==3 || (type(value)==4 && convert_numeric_string(value)))
        parameter = fpu_convert_to_int(value);
    cb(global_00FE1804, parameter);
    return 0;
}
int wrapper(LuaValueLike* input) {
    callback = *(void**)0x00FE187C;
    lua_one_integer_callback(input, callback);
    return 1;
}
```

## 下一條需要驗證的邊

1. 查 `[0x00FE187C]` 全部**寫入**（而非僅 xref）；核對是否為 scenario start handler。
2. 查 `0x004ACB70` 的其他呼叫者，區分共用 Lua argument-conversion thunk。
3. 對 `TutorialMain.lua` 中 `RequestStartScenario` 的具體 integer constant 及它如何傳入 native 層逐指令重建；這份僅證明這條 binder 允許 int/0。
4. 對網路封包方向需關閉「API→actual callback→packet enqueue/send→server reply」鏈，尚未完成；**不能**宣稱 `scenario14` 已成功開始或完成。

## 目前仍缺的原件（DEFERRED-LOCAL-RESOURCE）

| 來源 | 來源 SHA256 | 目前不足的內容及影響 |
|---|---|---|
| `Event/TutorialBase.lua` | `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744` | 缺具體 function bodies，無法確證全教學回呼 |
| `Table/QuestInfo.xml` | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 尚無 Quest15、Quest16 元素原文及前置規則 |
| Quest16 server 狀態 writer／原生 ACK、角色持久化來源 | unknown | 不能證明 Quest16 已完成、Quest15 可接或重登續接 |

不可把 T01 的來源稽核、QuestTalk 缺少兩筆的局部切片、或歷史 fixture 視為上述缺口已解。

