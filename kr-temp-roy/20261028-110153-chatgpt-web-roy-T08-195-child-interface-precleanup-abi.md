# T08-195 — actor+0x15C 多型子物件前置清理的 ABI 與型別界線

- 研究時間：`2026-10-28T11:01:53.006713+08:00`（Asia/Taipei）；研究者 `chatgpt-web roy`。
- 第一手：韓版 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪已重算），檔案唯讀。
- PE `.text`：VA `0x00401000`、file raw `0x400`；`.rdata`：VA `0x00BD2000`、raw `0x007D0600`。只在節區內用 `raw=0x400+(VA-0x401000)`。
- 接續 T08-193；`CMonster` 名稱承襲先前研究，缺原始 class symbol 的其他欄位/呼叫一律暫稱。所有結論限靜態路徑，不能推定 runtime 全部型別。

## 三輪研究紀錄及決策

### 195 第一輪：識別清理順序

`0x004C8360` 先讀 `actor+0x15C`。如果非零，**並非**直接以子物件起點呼叫 method：`mov ecx,[actor+0x15C]` 後 `lea ecx,[eax+0x08]`，再 `mov eax,[ecx]`、`mov edx,[eax+0x08]`、`call edx`。可確認為 **子物件地址 +8 的次級介面虛擬方法 +8**。它發生於 `actor+0x364` 與 128 個 `+0x164` 槽的 `0x007BE5F0` 前。這比僅說「有 vcall」多了具體 base adjust/次級 interface 證據，但尚不足以確認 target 身分。

### 195-2：反證直讀 actor 自身 vtable 的錯誤推論

以原始指令追 `0x004C8365–0x004C8377`：`eax=[edi+15C]` → `ecx=eax+8` → `eax=[ecx]` → `edx=[eax+8]`。因此 vptr 並非 `[actor]`、也不是 `[child]`，而是 `[child+8]`。不可以用 CMonster 主 vtable `0x00C0C9DC` 直接推這個 callback；亦不能把 `actor+0x15C` 與先前 `object+0xF0` 次級 vptr 當同一地址。

### 195-3：有界型別界線與下一研究入口

同窗再次核對，沒有 `actor+0x15C` 子物件建構的 literal vptr 或可靠間接 calltarget，故三輪後**仍沒有完成此 callback 的確切目標解析**。本段停止於已確認的 ABI 與執行順序，不冒充已確定 vtable 目標；按跨 Task 規則可轉 196。這三輪是同一正式段號，完整合併於本檔。

## 有界資料流及偏移圖

| 指標 | 真正來源 | 已確認操作 | 避免誤解 |
|---|---|---|---|
| `actor` | `ECX` 入函式，保存在 `EDI` | 取 `+0x15C`、`+0x364`、`+0x164` | 不等於 resource owner |
| `child` | `[actor+0x15C]` | 非零才進入 | 未知配置類型 |
| `iface` | `child+0x08` | `ECX=iface` | 非主 vptr |
| `iface_vptr` | `[iface]` | 取 slot `+0x08` | 需子物件建構追溯 |
| `resource slot` | `[actor+0x364]`／`[actor+0x164+4*i]` | `[slot+0x24] != 0` 時傳 `&slot->+0x24` 至 `0x007BE5F0` | 128 槽之外另有 +0x364 |

## 偽碼（證據限制）

```cpp
void precleanup_actor(Actor* actor) {
    auto* child = actor->field_15C;
    if (child) {
        auto* iface = reinterpret_cast<uint8_t*>(child) + 8;
        iface->vtable[2](iface);  // slot +8；目標尚未確認
    }
    auto release_if_present = [](auto* item) {
        if (item && item->field24) release_reference_7BE5F0(&item->field24);
    };
    release_if_present(actor->field364);
    for (int i=0; i<128; ++i) release_if_present(actor->slot164[i]);
}
```

## 未解

必須沿 `actor+0x15C` 所存指標的 writer，追到 `child+8` 初始化 vptr（含配置大小），才可具體解析虛擬 callback；目前僅具 AB​​I、順序及間接槽位置一級證據，不能上升為已完成所有權釋放。

## 原始組語

### VA `0x004C8360–0x004C83C0`

```asm
004c8360 <.text+0xc7360>:
  4c8360:	53                   	push   ebx
  4c8361:	56                   	push   esi
  4c8362:	57                   	push   edi
  4c8363:	8b f9                	mov    edi,ecx
  4c8365:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4c836b:	85 c0                	test   eax,eax
  4c836d:	74 0a                	je     0x4c8379
  4c836f:	8d 48 08             	lea    ecx,[eax+0x8]
  4c8372:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c8374:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c8377:	ff d2                	call   edx
  4c8379:	8b 87 64 03 00 00    	mov    eax,DWORD PTR [edi+0x364]
  4c837f:	85 c0                	test   eax,eax
  4c8381:	74 0e                	je     0x4c8391
  4c8383:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c8387:	8d 70 24             	lea    esi,[eax+0x24]
  4c838a:	74 05                	je     0x4c8391
  4c838c:	e8 5f 62 2f 00       	call   0x7be5f0
  4c8391:	81 c7 64 01 00 00    	add    edi,0x164
  4c8397:	bb 80 00 00 00       	mov    ebx,0x80
  4c839c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4c83a0:	8b 07                	mov    eax,DWORD PTR [edi]
  4c83a2:	85 c0                	test   eax,eax
  4c83a4:	74 0e                	je     0x4c83b4
  4c83a6:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c83aa:	8d 70 24             	lea    esi,[eax+0x24]
  4c83ad:	74 05                	je     0x4c83b4
  4c83af:	e8 3c 62 2f 00       	call   0x7be5f0
  4c83b4:	83 c7 04             	add    edi,0x4
  4c83b7:	4b                   	dec    ebx
  4c83b8:	75 e6                	jne    0x4c83a0
  4c83ba:	5f                   	pop    edi
  4c83bb:	5e                   	pop    esi
  4c83bc:	33 c0                	xor    eax,eax
  4c83be:	5b                   	pop    ebx
  4c83bf:	c3                   	ret
```
### VA `0x004D1F80–0x004D1F88`

```asm
004d1f80 <.text+0xd0f80>:
  4d1f80:	e8 db 63 ff ff       	call   0x4c8360
  4d1f85:	33 c0                	xor    eax,eax
  4d1f87:	c3                   	ret
```