# T08-100 — heap 名稱索引的 Provider 建構、vtable+0x10 與 Binding 複製路徑

- 研究者：`chatgpt-web roy`
- 時間 Asia/Taipei：`2026-10-27T13:43:25+08:00`
- 主體：`Tartaros.bin` / SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方法：BIN 上 `objdump -d -Mintel` 與 `.rdata` DWORD 靜態讀取，沒有動態測試，所有 C++ 名稱僅為暫定。

## 一、主要發現（直接可證）

1. `[0x00FE173C]` 所指的 0x2C heap 索引，其**插入函式是 `0x007DC660`**。`0x007DC660` 以 `esi` 持有索引物件，先呼叫 `0x007DCA10` 查重，再呼叫 `0x00719B90` 生成 0x28 bytes 名稱節點。`[esp+0x10]` 是要存入節點的 payload；`0x00719B90` 把傳入暫存 entry 的 payload 複製到 `node+0x24`（參見 T08-097）。在查重已存在時，`0x007DC7B0` 取回舊節點 payload，`0x007DC7B7` 對其 `+0x08` 增加引用計數，之後以 vtable+0x00 釋放新的候選物件。
2. `0x007DC660` 在此 BIN 中的**直接 `CALL rel32`** 呼叫點為 `0x007D6EC4` 和 `0x007D6F51`。兩條路徑先從 `[0x00FE173C]` 取得 heap index，於 `esi`，在 `ecx` 提供名稱指標、stack 傳候選物件指標。
3. `0x007D6EC9` 配置 `0xB4` bytes，`0x007D6EF5` 呼叫 `0x007F15B0`；`0x007D6E55/0x007D6E6A` 另經 `0x007F1650` 建立同類型物件，之後將結果傳入 `0x007DC660`。因此**真正的 heap-index provider payload 屬於具有 vtable 的 `0xB4` bytes 物件家族**，而非內嵌樹的 `0x8C` bytes 順序 ID 管理器。這修正 T08-098 的衝突且補足 T08-099 未定位的插入者。
4. `0x007F15D7 / 0x007F1673` 均寫 `*(uint32_t*)(obj+0)=0x00C50A8C`；`obj+0x84=0x00C50ABC` 是**第二個子物件的 vptr**，不可混同主 vptr。`0x007F16B9` 額外將 `obj+0x04` 設為 1。
5. BIN `.rdata` 讀取 `0x00C50A8C+0x10` 的 DWORD 為 **`0x007F21A0`**。此函式 `0x007F21CE` 配置 `0xB4` bytes，`0x007F21F0` 呼叫 `0x007F15B0` 初始化後再拷貝/複製父物件資源與關聯資料，`0x007F230A` 回傳新物件。因此 `0x007BDF90` 呼叫的 `provider->vtable[4]` 對此 vptr **確定是建立/複製 0xB4 bytes binding 型物件**，而不是回傳 0x8C bytes manager。
6. `binding+0x80` 在 `0x007BDF40` 以 DWORD 比較 0 (`0x007BDF72`)，只有為 0 才呼叫 `binding->vtable+0x18`。本段不能證實所有 `+0x80` 寫入者，亦未證實其語義（鎖定/停用/完成等都只是猜想）。

## 二、vtable 原始 DWORD 映射（從 `.rdata` 取得）

| vtable | offset | 入口 VA | 已可描述行為 |
| --- | --- | --- | --- |
| `0x00C50A8C` | `+0x00` | `0x007F1620` | 析構包裝，按旗標可能釋放記憶體 |
| 同上 | `+0x04` | `0x007F1770` | 待深入 |
| 同上 | `+0x08` | `0x007F2110` | 釋放關聯物件/更新內部狀態 |
| 同上 | `+0x0C` | `0x007F20E0` | `+0x08` 計數遞減及歸零後處理 |
| 同上 | `+0x10` | `0x007F21A0` | 建立 0xB4 bytes 複本並回傳 |
| 同上 | `+0x14` | `0x007F2320` | 待深入 |
| 同上 | `+0x18` | `0x007F23B0` | 對應第79～95段 binding 虛擬調度 |
| 同上 | `+0x1C` | `0x007F24F0` | 待深入 |
| `0x00C50ABC` | `+0x00` | `0x007F2600` | 次級子物件 vtable，需分開還原 |

vtable 表值從原始 BIN 的 section mapping `file_offset = VA - 0x00BD2000 + 0x007D0600` 讀取，屬於靜態證據；沒有宣稱 RTTI 確認的原始 class 名稱。

## 三、生命週期／資料流

```cpp
// 皆暫定型別、略去例外/分配失敗/名稱字串 SSO
struct ProviderLikeB4 {
    void **vptr;              // +0x00 = 0x00C50A8C
    uint32_t field_04;        // +0x04; 某建構器寫 1
    uint32_t refs_or_count;   // +0x08; vtable+0x0C 遞減
    uint8_t opaque[0x78];    // 直至 +0x84
    void **secondary_vptr;    // +0x84 = 0x00C50ABC
    void *related;            // +0x88; 複製時特殊處理
    // ... 直到 +0xB4
};

// heap 索引（0x00FE173C 解參照後）
ProviderLikeB4 *candidate = create_provider_like_b4(...);
insert_name_heap_index(heap_index, name, candidate); // 0x007DC660
// 找到已登記名稱時，復用舊 payload，增加 +8 持有數並清理候選；
// 未命中時配置 0x28 bytes name node、設 node+0x24 為 payload。

// 子項資源綁定（T08-095 + T08-100）
auto *provider = name_tree_find(heap_index, item->name)->payload;
item->binding = provider->vtable_slot_10(); // 0x007F21A0 產生 B4 複本
// 更新時 item->binding->vtable_slot_18();
```

## 四、尚未解決與下一段

- 完整建立 `0x007F21A0` 後半部複製內容、`+0x88` 的關聯物件和 `0x007C7DD0`、`0x007CBB00` 的用途；原始 provider 與 clone 之間的引用計數及 ownership 邊界。
- 定位 **`binding+0x80`** 的所有靜態寫入者及條件傳播；確認它與虛擬 `+0x18` 行為的關係。
- 進一步還原 `0x007F23B0`、`0x007F24F0`、`vtable+0x20`（主物件 `0x007F2320` 與此前 wrapper/scene vtable 不得混淆）。
- 場景物件 `vtable+0x20` 的主更新迴圈依舊未確認。

## 五、原始 BIN 反組譯附錄（完整選定函式範圍）

`0x00C50A8C` → `0x007F1620`
`0x00C50A90` → `0x007F1770`
`0x00C50A94` → `0x007F2110`
`0x00C50A98` → `0x007F20E0`
`0x00C50A9C` → `0x007F21A0`
`0x00C50AA0` → `0x007F2320`
`0x00C50AA4` → `0x007F23B0`
`0x00C50AA8` → `0x007F24F0`

`0x00C50ABC` → `0x007F2600`
`0x00C50AC0` → `0x007F15A0`
`0x00C50AC4` → `0x007F25F0`
`0x00C50AC8` → `0x007BEDA0`
`0x00C50ACC` → `0x00C8084C`
`0x00C50AD0` → `0x007F2610`
`0x00C50AD4` → `0x00891FB2`
`0x00C50AD8` → `0x007F28E0`

### heap 索引插入 `0x007DC660–0x007DC7F6`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dc660 <.text+0x3db660>:
  7dc660:	55                   	push   ebp
  7dc661:	8b ec                	mov    ebp,esp
  7dc663:	83 e4 f8             	and    esp,0xfffffff8
  7dc666:	6a ff                	push   0xffffffff
  7dc668:	68 70 49 91 00       	push   0x914970
  7dc66d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dc673:	50                   	push   eax
  7dc674:	83 ec 54             	sub    esp,0x54
  7dc677:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc67c:	33 c4                	xor    eax,esp
  7dc67e:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  7dc682:	53                   	push   ebx
  7dc683:	57                   	push   edi
  7dc684:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc689:	33 c4                	xor    eax,esp
  7dc68b:	50                   	push   eax
  7dc68c:	8d 44 24 60          	lea    eax,[esp+0x60]
  7dc690:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dc696:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7dc699:	8b d6                	mov    edx,esi
  7dc69b:	8b f9                	mov    edi,ecx
  7dc69d:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7dc6a1:	e8 6a 03 00 00       	call   0x7dca10
  7dc6a6:	33 db                	xor    ebx,ebx
  7dc6a8:	85 c0                	test   eax,eax
  7dc6aa:	8b c7                	mov    eax,edi
  7dc6ac:	8d 50 01             	lea    edx,[eax+0x1]
  7dc6af:	0f 85 9d 00 00 00    	jne    0x7dc752
  7dc6b5:	c7 44 24 4c 0f 00 00 	mov    DWORD PTR [esp+0x4c],0xf
  7dc6bc:	00 
  7dc6bd:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  7dc6c1:	88 5c 24 38          	mov    BYTE PTR [esp+0x38],bl
  7dc6c5:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc6c7:	40                   	inc    eax
  7dc6c8:	3a cb                	cmp    cl,bl
  7dc6ca:	75 f9                	jne    0x7dc6c5
  7dc6cc:	2b c2                	sub    eax,edx
  7dc6ce:	50                   	push   eax
  7dc6cf:	57                   	push   edi
  7dc6d0:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  7dc6d4:	e8 97 63 c2 ff       	call   0x402a70
  7dc6d9:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  7dc6dd:	89 4c 24 54          	mov    DWORD PTR [esp+0x54],ecx
  7dc6e1:	89 5c 24 68          	mov    DWORD PTR [esp+0x68],ebx
  7dc6e5:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7dc6e8:	8b 3a                	mov    edi,DWORD PTR [edx]
  7dc6ea:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  7dc6ed:	8d 44 24 38          	lea    eax,[esp+0x38]
  7dc6f1:	50                   	push   eax
  7dc6f2:	51                   	push   ecx
  7dc6f3:	57                   	push   edi
  7dc6f4:	e8 97 d4 f3 ff       	call   0x719b90
  7dc6f9:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7dc6fc:	ba fe ff ff 07       	mov    edx,0x7fffffe
  7dc701:	2b d1                	sub    edx,ecx
  7dc703:	83 fa 01             	cmp    edx,0x1
  7dc706:	73 0a                	jae    0x7dc712
  7dc708:	68 34 20 bf 00       	push   0xbf2034
  7dc70d:	e8 1e 14 0a 00       	call   0x87db30
  7dc712:	41                   	inc    ecx
  7dc713:	89 4e 08             	mov    DWORD PTR [esi+0x8],ecx
  7dc716:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  7dc719:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  7dc71c:	89 01                	mov    DWORD PTR [ecx],eax
  7dc71e:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7dc721:	8b 02                	mov    eax,DWORD PTR [edx]
  7dc723:	50                   	push   eax
  7dc724:	83 c0 08             	add    eax,0x8
  7dc727:	50                   	push   eax
  7dc728:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  7dc72c:	50                   	push   eax
  7dc72d:	8b ce                	mov    ecx,esi
  7dc72f:	e8 4c 49 ff ff       	call   0x7d1080
  7dc734:	83 7c 24 4c 10       	cmp    DWORD PTR [esp+0x4c],0x10
  7dc739:	72 0d                	jb     0x7dc748
  7dc73b:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  7dc73f:	51                   	push   ecx
  7dc740:	e8 c7 4a 0b 00       	call   0x89120c
  7dc745:	83 c4 04             	add    esp,0x4
  7dc748:	b8 01 00 00 00       	mov    eax,0x1
  7dc74d:	e9 85 00 00 00       	jmp    0x7dc7d7
  7dc752:	c7 44 24 30 0f 00 00 	mov    DWORD PTR [esp+0x30],0xf
  7dc759:	00 
  7dc75a:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  7dc75e:	88 5c 24 1c          	mov    BYTE PTR [esp+0x1c],bl
  7dc762:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc764:	40                   	inc    eax
  7dc765:	3a cb                	cmp    cl,bl
  7dc767:	75 f9                	jne    0x7dc762
  7dc769:	2b c2                	sub    eax,edx
  7dc76b:	50                   	push   eax
  7dc76c:	57                   	push   edi
  7dc76d:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  7dc771:	e8 fa 62 c2 ff       	call   0x402a70
  7dc776:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  7dc77a:	52                   	push   edx
  7dc77b:	8d 44 24 18          	lea    eax,[esp+0x18]
  7dc77f:	50                   	push   eax
  7dc780:	bf 01 00 00 00       	mov    edi,0x1
  7dc785:	8b c6                	mov    eax,esi
  7dc787:	89 7c 24 70          	mov    DWORD PTR [esp+0x70],edi
  7dc78b:	e8 60 bf fd ff       	call   0x7b86f0
  7dc790:	c7 44 24 68 ff ff ff 	mov    DWORD PTR [esp+0x68],0xffffffff
  7dc797:	ff 
  7dc798:	83 7c 24 30 10       	cmp    DWORD PTR [esp+0x30],0x10
  7dc79d:	72 0d                	jb     0x7dc7ac
  7dc79f:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  7dc7a3:	51                   	push   ecx
  7dc7a4:	e8 63 4a 0b 00       	call   0x89120c
  7dc7a9:	83 c4 04             	add    esp,0x4
  7dc7ac:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  7dc7b0:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  7dc7b3:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  7dc7b7:	01 78 08             	add    DWORD PTR [eax+0x8],edi
  7dc7ba:	c7 44 24 30 0f 00 00 	mov    DWORD PTR [esp+0x30],0xf
  7dc7c1:	00 
  7dc7c2:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  7dc7c6:	88 5c 24 1c          	mov    BYTE PTR [esp+0x1c],bl
  7dc7ca:	3b cb                	cmp    ecx,ebx
  7dc7cc:	74 07                	je     0x7dc7d5
  7dc7ce:	8b 01                	mov    eax,DWORD PTR [ecx]
  7dc7d0:	8b 10                	mov    edx,DWORD PTR [eax]
  7dc7d2:	57                   	push   edi
  7dc7d3:	ff d2                	call   edx
  7dc7d5:	33 c0                	xor    eax,eax
  7dc7d7:	8b 4c 24 60          	mov    ecx,DWORD PTR [esp+0x60]
  7dc7db:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dc7e2:	59                   	pop    ecx
  7dc7e3:	5f                   	pop    edi
  7dc7e4:	5b                   	pop    ebx
  7dc7e5:	8b 4c 24 4c          	mov    ecx,DWORD PTR [esp+0x4c]
  7dc7e9:	33 cc                	xor    ecx,esp
  7dc7eb:	e8 11 48 0b 00       	call   0x891001
  7dc7f0:	8b e5                	mov    esp,ebp
  7dc7f2:	5d                   	pop    ebp
  7dc7f3:	c2 04 00             	ret    0x4

```

### 第一與第二登記呼叫點 `0x007D6E80–0x007D6F9A`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d6e80 <.text+0x3d5e80>:
  7d6e80:	10 72 04             	adc    BYTE PTR [edx+0x4],dh
  7d6e83:	8b 33                	mov    esi,DWORD PTR [ebx]
  7d6e85:	eb 02                	jmp    0x7d6e89
  7d6e87:	8b f3                	mov    esi,ebx
  7d6e89:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7d6e90:	75 29                	jne    0x7d6ebb
  7d6e92:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7d6e99:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x6
  7d6ea0:	06 
  7d6ea1:	e8 fa 0e fe ff       	call   0x7b7da0
  7d6ea6:	68 90 e7 bc 00       	push   0xbce790
  7d6eab:	e8 6a b4 0b 00       	call   0x89231a
  7d6eb0:	83 c4 04             	add    esp,0x4
  7d6eb3:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d6eba:	04 
  7d6ebb:	8b ce                	mov    ecx,esi
  7d6ebd:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7d6ec3:	57                   	push   edi
  7d6ec4:	e8 97 57 00 00       	call   0x7dc660
  7d6ec9:	68 b4 00 00 00       	push   0xb4
  7d6ece:	e8 95 a3 0b 00       	call   0x891268
  7d6ed3:	8b c8                	mov    ecx,eax
  7d6ed5:	83 c4 04             	add    esp,0x4
  7d6ed8:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  7d6edc:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x7
  7d6ee3:	07 
  7d6ee4:	85 c9                	test   ecx,ecx
  7d6ee6:	74 16                	je     0x7d6efe
  7d6ee8:	83 7b 4c 10          	cmp    DWORD PTR [ebx+0x4c],0x10
  7d6eec:	8d 43 38             	lea    eax,[ebx+0x38]
  7d6eef:	72 02                	jb     0x7d6ef3
  7d6ef1:	8b 00                	mov    eax,DWORD PTR [eax]
  7d6ef3:	6a 00                	push   0x0
  7d6ef5:	e8 b6 a6 01 00       	call   0x7f15b0
  7d6efa:	8b f8                	mov    edi,eax
  7d6efc:	eb 02                	jmp    0x7d6f00
  7d6efe:	33 ff                	xor    edi,edi
  7d6f00:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d6f07:	04 
  7d6f08:	83 7b 4c 10          	cmp    DWORD PTR [ebx+0x4c],0x10
  7d6f0c:	72 05                	jb     0x7d6f13
  7d6f0e:	8b 73 38             	mov    esi,DWORD PTR [ebx+0x38]
  7d6f11:	eb 03                	jmp    0x7d6f16
  7d6f13:	8d 73 38             	lea    esi,[ebx+0x38]
  7d6f16:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7d6f1d:	75 29                	jne    0x7d6f48
  7d6f1f:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7d6f26:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x8
  7d6f2d:	08 
  7d6f2e:	e8 6d 0e fe ff       	call   0x7b7da0
  7d6f33:	68 90 e7 bc 00       	push   0xbce790
  7d6f38:	e8 dd b3 0b 00       	call   0x89231a
  7d6f3d:	83 c4 04             	add    esp,0x4
  7d6f40:	c6 84 24 c0 00 00 00 	mov    BYTE PTR [esp+0xc0],0x4
  7d6f47:	04 
  7d6f48:	8b ce                	mov    ecx,esi
  7d6f4a:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7d6f50:	57                   	push   edi
  7d6f51:	e8 0a 57 00 00       	call   0x7dc660
  7d6f56:	68 8c 00 00 00       	push   0x8c
  7d6f5b:	e8 08 a3 0b 00       	call   0x891268
  7d6f60:	83 c4 04             	add    esp,0x4
  7d6f63:	85 c0                	test   eax,eax
  7d6f65:	74 1c                	je     0x7d6f83
  7d6f67:	83 7c 24 54 10       	cmp    DWORD PTR [esp+0x54],0x10
  7d6f6c:	8b 7c 24 40          	mov    edi,DWORD PTR [esp+0x40]
  7d6f70:	73 04                	jae    0x7d6f76
  7d6f72:	8d 7c 24 40          	lea    edi,[esp+0x40]
  7d6f76:	8b f0                	mov    esi,eax
  7d6f78:	e8 63 5f 00 00       	call   0x7dcee0
  7d6f7d:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  7d6f81:	eb 08                	jmp    0x7d6f8b
  7d6f83:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  7d6f8a:	00 
  7d6f8b:	6a 68                	push   0x68
  7d6f8d:	e8 d6 a2 0b 00       	call   0x891268
  7d6f92:	83 c4 04             	add    esp,0x4
  7d6f95:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d6f99:	c6                   	.byte 0xc6

```

### Provider 建構 A `0x007F15B0–0x007F161E`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f15b0 <.text+0x3f05b0>:
  7f15b0:	55                   	push   ebp
  7f15b1:	8b ec                	mov    ebp,esp
  7f15b3:	56                   	push   esi
  7f15b4:	50                   	push   eax
  7f15b5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7f15b8:	8b f1                	mov    esi,ecx
  7f15ba:	e8 31 86 ff ff       	call   0x7e9bf0
  7f15bf:	d9 05 18 7d c0 00    	fld    DWORD PTR ds:0xc07d18
  7f15c5:	c7 86 84 00 00 00 68 	mov    DWORD PTR [esi+0x84],0xc4f468
  7f15cc:	f4 c4 00 
  7f15cf:	33 c0                	xor    eax,eax
  7f15d1:	89 86 88 00 00 00    	mov    DWORD PTR [esi+0x88],eax
  7f15d7:	c7 06 8c 0a c5 00    	mov    DWORD PTR [esi],0xc50a8c
  7f15dd:	c7 86 84 00 00 00 bc 	mov    DWORD PTR [esi+0x84],0xc50abc
  7f15e4:	0a c5 00 
  7f15e7:	89 86 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],eax
  7f15ed:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  7f15f3:	89 86 94 00 00 00    	mov    DWORD PTR [esi+0x94],eax
  7f15f9:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  7f15ff:	89 86 a0 00 00 00    	mov    DWORD PTR [esi+0xa0],eax
  7f1605:	89 86 a4 00 00 00    	mov    DWORD PTR [esi+0xa4],eax
  7f160b:	d9 9e b0 00 00 00    	fstp   DWORD PTR [esi+0xb0]
  7f1611:	89 86 ac 00 00 00    	mov    DWORD PTR [esi+0xac],eax
  7f1617:	8b c6                	mov    eax,esi
  7f1619:	5e                   	pop    esi
  7f161a:	5d                   	pop    ebp
  7f161b:	c2 04 00             	ret    0x4

```

### Provider 建構 B `0x007F1650–0x007F16C7`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f1650 <.text+0x3f0650>:
  7f1650:	55                   	push   ebp
  7f1651:	8b ec                	mov    ebp,esp
  7f1653:	56                   	push   esi
  7f1654:	50                   	push   eax
  7f1655:	8b f1                	mov    esi,ecx
  7f1657:	33 c0                	xor    eax,eax
  7f1659:	e8 92 85 ff ff       	call   0x7e9bf0
  7f165e:	d9 05 18 7d c0 00    	fld    DWORD PTR ds:0xc07d18
  7f1664:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7f1667:	c7 86 84 00 00 00 68 	mov    DWORD PTR [esi+0x84],0xc4f468
  7f166e:	f4 c4 00 
  7f1671:	33 c0                	xor    eax,eax
  7f1673:	c7 06 8c 0a c5 00    	mov    DWORD PTR [esi],0xc50a8c
  7f1679:	c7 86 84 00 00 00 bc 	mov    DWORD PTR [esi+0x84],0xc50abc
  7f1680:	0a c5 00 
  7f1683:	89 8e 88 00 00 00    	mov    DWORD PTR [esi+0x88],ecx
  7f1689:	89 86 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],eax
  7f168f:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  7f1695:	89 86 94 00 00 00    	mov    DWORD PTR [esi+0x94],eax
  7f169b:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  7f16a1:	89 86 a0 00 00 00    	mov    DWORD PTR [esi+0xa0],eax
  7f16a7:	89 86 a4 00 00 00    	mov    DWORD PTR [esi+0xa4],eax
  7f16ad:	d9 9e b0 00 00 00    	fstp   DWORD PTR [esi+0xb0]
  7f16b3:	89 86 ac 00 00 00    	mov    DWORD PTR [esi+0xac],eax
  7f16b9:	c7 46 04 01 00 00 00 	mov    DWORD PTR [esi+0x4],0x1
  7f16c0:	8b c6                	mov    eax,esi
  7f16c2:	5e                   	pop    esi
  7f16c3:	5d                   	pop    ebp
  7f16c4:	c2 04 00             	ret    0x4

```

### Provider vtable+0x10 `0x007F21A0–0x007F2320`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f21a0 <.text+0x3f11a0>:
  7f21a0:	55                   	push   ebp
  7f21a1:	8b ec                	mov    ebp,esp
  7f21a3:	83 e4 f8             	and    esp,0xfffffff8
  7f21a6:	6a ff                	push   0xffffffff
  7f21a8:	68 d3 9b 90 00       	push   0x909bd3
  7f21ad:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f21b3:	50                   	push   eax
  7f21b4:	83 ec 30             	sub    esp,0x30
  7f21b7:	53                   	push   ebx
  7f21b8:	56                   	push   esi
  7f21b9:	57                   	push   edi
  7f21ba:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f21bf:	33 c4                	xor    eax,esp
  7f21c1:	50                   	push   eax
  7f21c2:	8d 44 24 40          	lea    eax,[esp+0x40]
  7f21c6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f21cc:	8b f9                	mov    edi,ecx
  7f21ce:	68 b4 00 00 00       	push   0xb4
  7f21d3:	e8 90 f0 09 00       	call   0x891268
  7f21d8:	8b c8                	mov    ecx,eax
  7f21da:	83 c4 04             	add    esp,0x4
  7f21dd:	89 4c 24 28          	mov    DWORD PTR [esp+0x28],ecx
  7f21e1:	33 db                	xor    ebx,ebx
  7f21e3:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  7f21e7:	3b cb                	cmp    ecx,ebx
  7f21e9:	74 12                	je     0x7f21fd
  7f21eb:	6a 01                	push   0x1
  7f21ed:	8d 47 30             	lea    eax,[edi+0x30]
  7f21f0:	e8 bb f3 ff ff       	call   0x7f15b0
  7f21f5:	8b f0                	mov    esi,eax
  7f21f7:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  7f21fb:	eb 06                	jmp    0x7f2203
  7f21fd:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  7f2201:	8b f3                	mov    esi,ebx
  7f2203:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  7f220a:	ff 
  7f220b:	d9 47 70             	fld    DWORD PTR [edi+0x70]
  7f220e:	d9 5e 70             	fstp   DWORD PTR [esi+0x70]
  7f2211:	d9 87 b0 00 00 00    	fld    DWORD PTR [edi+0xb0]
  7f2217:	d9 9e b0 00 00 00    	fstp   DWORD PTR [esi+0xb0]
  7f221d:	8b 87 ac 00 00 00    	mov    eax,DWORD PTR [edi+0xac]
  7f2223:	89 86 ac 00 00 00    	mov    DWORD PTR [esi+0xac],eax
  7f2229:	39 9f 88 00 00 00    	cmp    DWORD PTR [edi+0x88],ebx
  7f222f:	0f 84 d5 00 00 00    	je     0x7f230a
  7f2235:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  7f223b:	8b 11                	mov    edx,DWORD PTR [ecx]
  7f223d:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  7f2240:	ff d0                	call   eax
  7f2242:	89 86 88 00 00 00    	mov    DWORD PTR [esi+0x88],eax
  7f2248:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  7f224c:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  7f2250:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  7f2254:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  7f2258:	51                   	push   ecx
  7f2259:	50                   	push   eax
  7f225a:	c7 44 24 50 01 00 00 	mov    DWORD PTR [esp+0x50],0x1
  7f2261:	00 
  7f2262:	e8 69 5b fd ff       	call   0x7c7dd0
  7f2267:	8b 54 24 38          	mov    edx,DWORD PTR [esp+0x38]
  7f226b:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  7f226f:	2b d0                	sub    edx,eax
  7f2271:	c1 fa 02             	sar    edx,0x2
  7f2274:	83 c4 08             	add    esp,0x8
  7f2277:	85 d2                	test   edx,edx
  7f2279:	74 62                	je     0x7f22dd
  7f227b:	d9 05 f0 5a c5 00    	fld    DWORD PTR ds:0xc55af0
  7f2281:	d9 54 24 14          	fst    DWORD PTR [esp+0x14]
  7f2285:	d9 54 24 18          	fst    DWORD PTR [esp+0x18]
  7f2289:	d9 54 24 1c          	fst    DWORD PTR [esp+0x1c]
  7f228d:	d9 54 24 20          	fst    DWORD PTR [esp+0x20]
  7f2291:	d9 54 24 24          	fst    DWORD PTR [esp+0x24]
  7f2295:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  7f2299:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  7f22a0:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7f22a3:	8d 7c 24 14          	lea    edi,[esp+0x14]
  7f22a7:	8d 74 24 18          	lea    esi,[esp+0x18]
  7f22ab:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  7f22af:	e8 1c 2f 06 00       	call   0x8551d0
  7f22b4:	8d 7c 24 20          	lea    edi,[esp+0x20]
  7f22b8:	8d 74 24 24          	lea    esi,[esp+0x24]
  7f22bc:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  7f22c0:	e8 4b 2e 06 00       	call   0x855110
  7f22c5:	8b 4c 24 30          	mov    ecx,DWORD PTR [esp+0x30]
  7f22c9:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  7f22cd:	2b c8                	sub    ecx,eax
  7f22cf:	43                   	inc    ebx
  7f22d0:	c1 f9 02             	sar    ecx,0x2
  7f22d3:	3b d9                	cmp    ebx,ecx
  7f22d5:	72 c9                	jb     0x7f22a0
  7f22d7:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  7f22db:	33 db                	xor    ebx,ebx
  7f22dd:	56                   	push   esi
  7f22de:	e8 cd fb ff ff       	call   0x7f1eb0
  7f22e3:	8b 86 88 00 00 00    	mov    eax,DWORD PTR [esi+0x88]
  7f22e9:	8d 96 9c 00 00 00    	lea    edx,[esi+0x9c]
  7f22ef:	52                   	push   edx
  7f22f0:	50                   	push   eax
  7f22f1:	e8 0a 98 fd ff       	call   0x7cbb00
  7f22f6:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  7f22fa:	83 c4 08             	add    esp,0x8
  7f22fd:	3b c3                	cmp    eax,ebx
  7f22ff:	74 09                	je     0x7f230a
  7f2301:	50                   	push   eax
  7f2302:	e8 05 ef 09 00       	call   0x89120c
  7f2307:	83 c4 04             	add    esp,0x4
  7f230a:	8b c6                	mov    eax,esi
  7f230c:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  7f2310:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f2317:	59                   	pop    ecx
  7f2318:	5f                   	pop    edi
  7f2319:	5e                   	pop    esi
  7f231a:	5b                   	pop    ebx
  7f231b:	8b e5                	mov    esp,ebp
  7f231d:	5d                   	pop    ebp
  7f231e:	c3                   	ret
  7f231f:	cc                   	int3

```

### binding 虛擬呼叫 `0x007BDF40–0x007BE095`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf40 <.text+0x3bcf40>:
  7bdf40:	55                   	push   ebp
  7bdf41:	8b ec                	mov    ebp,esp
  7bdf43:	53                   	push   ebx
  7bdf44:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf47:	56                   	push   esi
  7bdf48:	57                   	push   edi
  7bdf49:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf4c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf4f:	33 f6                	xor    esi,esi
  7bdf51:	c1 ff 02             	sar    edi,0x2
  7bdf54:	85 ff                	test   edi,edi
  7bdf56:	74 31                	je     0x7bdf89
  7bdf58:	eb 06                	jmp    0x7bdf60
  7bdf5a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf60:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf63:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf66:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf69:	85 c9                	test   ecx,ecx
  7bdf6b:	74 17                	je     0x7bdf84
  7bdf6d:	80 38 00             	cmp    BYTE PTR [eax],0x0
  7bdf70:	75 12                	jne    0x7bdf84
  7bdf72:	83 b9 80 00 00 00 00 	cmp    DWORD PTR [ecx+0x80],0x0
  7bdf79:	75 09                	jne    0x7bdf84
  7bdf7b:	8b c1                	mov    eax,ecx
  7bdf7d:	8b 10                	mov    edx,DWORD PTR [eax]
  7bdf7f:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  7bdf82:	ff d0                	call   eax
  7bdf84:	46                   	inc    esi
  7bdf85:	3b f7                	cmp    esi,edi
  7bdf87:	72 d7                	jb     0x7bdf60
  7bdf89:	5f                   	pop    edi
  7bdf8a:	5e                   	pop    esi
  7bdf8b:	5b                   	pop    ebx
  7bdf8c:	5d                   	pop    ebp
  7bdf8d:	c2 04 00             	ret    0x4
  7bdf90:	55                   	push   ebp
  7bdf91:	8b ec                	mov    ebp,esp
  7bdf93:	6a ff                	push   0xffffffff
  7bdf95:	68 b6 8a 91 00       	push   0x918ab6
  7bdf9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7bdfa0:	50                   	push   eax
  7bdfa1:	83 ec 2c             	sub    esp,0x2c
  7bdfa4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7bdfa9:	33 c5                	xor    eax,ebp
  7bdfab:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7bdfae:	53                   	push   ebx
  7bdfaf:	56                   	push   esi
  7bdfb0:	57                   	push   edi
  7bdfb1:	50                   	push   eax
  7bdfb2:	8d 45 f4             	lea    eax,[ebp-0xc]
  7bdfb5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7bdfbb:	8b f1                	mov    esi,ecx
  7bdfbd:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7bdfc0:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  7bdfc3:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  7bdfc6:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7bdfc9:	0f 84 f4 00 00 00    	je     0x7be0c3
  7bdfcf:	eb 03                	jmp    0x7bdfd4
  7bdfd1:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7bdfd4:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7bdfdb:	8b 18                	mov    ebx,DWORD PTR [eax]
  7bdfdd:	75 27                	jne    0x7be006
  7bdfdf:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7bdfe6:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bdfed:	e8 ae 9d ff ff       	call   0x7b7da0
  7bdff2:	68 90 e7 bc 00       	push   0xbce790
  7bdff7:	e8 1e 43 0d 00       	call   0x89231a
  7bdffc:	83 c4 04             	add    esp,0x4
  7bdfff:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be006:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7be009:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7be00f:	8b c1                	mov    eax,ecx
  7be011:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be018:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be01f:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be023:	8d 78 01             	lea    edi,[eax+0x1]
  7be026:	8a 10                	mov    dl,BYTE PTR [eax]
  7be028:	40                   	inc    eax
  7be029:	84 d2                	test   dl,dl
  7be02b:	75 f9                	jne    0x7be026
  7be02d:	2b c7                	sub    eax,edi
  7be02f:	50                   	push   eax
  7be030:	51                   	push   ecx
  7be031:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7be034:	e8 37 4a c4 ff       	call   0x402a70
  7be039:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7be03c:	50                   	push   eax
  7be03d:	8d 4d c8             	lea    ecx,[ebp-0x38]
  7be040:	51                   	push   ecx
  7be041:	8b c6                	mov    eax,esi
  7be043:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7be04a:	e8 a1 a6 ff ff       	call   0x7b86f0
  7be04f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be056:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  7be05a:	72 0c                	jb     0x7be068
  7be05c:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7be05f:	52                   	push   edx
  7be060:	e8 a7 31 0d 00       	call   0x89120c
  7be065:	83 c4 04             	add    esp,0x4
  7be068:	8b 45 c8             	mov    eax,DWORD PTR [ebp-0x38]
  7be06b:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be072:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be079:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be07d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7be080:	74 11                	je     0x7be093
  7be082:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  7be085:	85 c9                	test   ecx,ecx
  7be087:	74 0a                	je     0x7be093
  7be089:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be08b:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7be08e:	ff d2                	call   edx
  7be090:	89 43 08             	mov    DWORD PTR [ebx+0x8],eax
  7be093:	83                   	.byte 0x83
  7be094:	7b                   	.byte 0x7b

```

### Provider vtable+0x0c `0x007F20E0–0x007F2104`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f20e0 <.text+0x3f10e0>:
  7f20e0:	56                   	push   esi
  7f20e1:	8b f1                	mov    esi,ecx
  7f20e3:	ff 4e 08             	dec    DWORD PTR [esi+0x8]
  7f20e6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7f20e9:	75 17                	jne    0x7f2102
  7f20eb:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  7f20ef:	74 0e                	je     0x7f20ff
  7f20f1:	e8 8a fb ff ff       	call   0x7f1c80
  7f20f6:	8b 06                	mov    eax,DWORD PTR [esi]
  7f20f8:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7f20fb:	8b ce                	mov    ecx,esi
  7f20fd:	ff d2                	call   edx
  7f20ff:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7f2102:	5e                   	pop    esi
  7f2103:	c3                   	ret

```

### Provider cleanup `0x007F16D0–0x007F1769`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f16d0 <.text+0x3f06d0>:
  7f16d0:	56                   	push   esi
  7f16d1:	8b f1                	mov    esi,ecx
  7f16d3:	57                   	push   edi
  7f16d4:	c7 06 8c 0a c5 00    	mov    DWORD PTR [esi],0xc50a8c
  7f16da:	c7 86 84 00 00 00 bc 	mov    DWORD PTR [esi+0x84],0xc50abc
  7f16e1:	0a c5 00 
  7f16e4:	8b 86 9c 00 00 00    	mov    eax,DWORD PTR [esi+0x9c]
  7f16ea:	33 ff                	xor    edi,edi
  7f16ec:	3b c7                	cmp    eax,edi
  7f16ee:	74 09                	je     0x7f16f9
  7f16f0:	50                   	push   eax
  7f16f1:	e8 16 fb 09 00       	call   0x89120c
  7f16f6:	83 c4 04             	add    esp,0x4
  7f16f9:	89 be 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],edi
  7f16ff:	89 be a0 00 00 00    	mov    DWORD PTR [esi+0xa0],edi
  7f1705:	89 be a4 00 00 00    	mov    DWORD PTR [esi+0xa4],edi
  7f170b:	8b 86 8c 00 00 00    	mov    eax,DWORD PTR [esi+0x8c]
  7f1711:	3b c7                	cmp    eax,edi
  7f1713:	74 09                	je     0x7f171e
  7f1715:	50                   	push   eax
  7f1716:	e8 f1 fa 09 00       	call   0x89120c
  7f171b:	83 c4 04             	add    esp,0x4
  7f171e:	89 be 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],edi
  7f1724:	89 be 90 00 00 00    	mov    DWORD PTR [esi+0x90],edi
  7f172a:	89 be 94 00 00 00    	mov    DWORD PTR [esi+0x94],edi
  7f1730:	8b 46 74             	mov    eax,DWORD PTR [esi+0x74]
  7f1733:	c7 86 84 00 00 00 68 	mov    DWORD PTR [esi+0x84],0xc4f468
  7f173a:	f4 c4 00 
  7f173d:	c7 06 18 06 c5 00    	mov    DWORD PTR [esi],0xc50618
  7f1743:	3b c7                	cmp    eax,edi
  7f1745:	74 0c                	je     0x7f1753
  7f1747:	50                   	push   eax
  7f1748:	e8 bf fa 09 00       	call   0x89120c
  7f174d:	83 c4 04             	add    esp,0x4
  7f1750:	89 7e 74             	mov    DWORD PTR [esi+0x74],edi
  7f1753:	8b 46 78             	mov    eax,DWORD PTR [esi+0x78]
  7f1756:	3b c7                	cmp    eax,edi
  7f1758:	74 0c                	je     0x7f1766
  7f175a:	50                   	push   eax
  7f175b:	e8 ac fa 09 00       	call   0x89120c
  7f1760:	83 c4 04             	add    esp,0x4
  7f1763:	89 7e 78             	mov    DWORD PTR [esi+0x78],edi
  7f1766:	5f                   	pop    edi
  7f1767:	5e                   	pop    esi
  7f1768:	c3                   	ret

```

### Heap 索引初始化 `0x007DC3D0–0x007DC475`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dc3d0 <.text+0x3db3d0>:
  7dc3d0:	55                   	push   ebp
  7dc3d1:	8b ec                	mov    ebp,esp
  7dc3d3:	6a ff                	push   0xffffffff
  7dc3d5:	68 a6 9d 90 00       	push   0x909da6
  7dc3da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dc3e0:	50                   	push   eax
  7dc3e1:	83 ec 10             	sub    esp,0x10
  7dc3e4:	56                   	push   esi
  7dc3e5:	57                   	push   edi
  7dc3e6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc3eb:	33 c5                	xor    eax,ebp
  7dc3ed:	50                   	push   eax
  7dc3ee:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dc3f1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dc3f7:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  7dc3fa:	8a 45 0b             	mov    al,BYTE PTR [ebp+0xb]
  7dc3fd:	88 07                	mov    BYTE PTR [edi],al
  7dc3ff:	33 f6                	xor    esi,esi
  7dc401:	6a 28                	push   0x28
  7dc403:	89 77 08             	mov    DWORD PTR [edi+0x8],esi
  7dc406:	e8 5d 4e 0b 00       	call   0x891268
  7dc40b:	83 c4 04             	add    esp,0x4
  7dc40e:	3b c6                	cmp    eax,esi
  7dc410:	74 3c                	je     0x7dc44e
  7dc412:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  7dc415:	89 00                	mov    DWORD PTR [eax],eax
  7dc417:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7dc41a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  7dc41d:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  7dc420:	89 77 10             	mov    DWORD PTR [edi+0x10],esi
  7dc423:	89 77 14             	mov    DWORD PTR [edi+0x14],esi
  7dc426:	89 77 18             	mov    DWORD PTR [edi+0x18],esi
  7dc429:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  7dc42d:	d9 e8                	fld1
  7dc42f:	6a 08                	push   0x8
  7dc431:	d9 5f 28             	fstp   DWORD PTR [edi+0x28]
  7dc434:	e8 f7 07 00 00       	call   0x7dcc30
  7dc439:	8b c7                	mov    eax,edi
  7dc43b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dc43e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dc445:	59                   	pop    ecx
  7dc446:	5f                   	pop    edi
  7dc447:	5e                   	pop    esi
  7dc448:	8b e5                	mov    esp,ebp
  7dc44a:	5d                   	pop    ebp
  7dc44b:	c2 04 00             	ret    0x4
  7dc44e:	8d 4d f0             	lea    ecx,[ebp-0x10]
  7dc451:	51                   	push   ecx
  7dc452:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  7dc455:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7dc458:	e8 4c 4c 0b 00       	call   0x8910a9
  7dc45d:	68 a8 57 c8 00       	push   0xc857a8
  7dc462:	8d 55 e4             	lea    edx,[ebp-0x1c]
  7dc465:	52                   	push   edx
  7dc466:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  7dc46d:	e8 7e 05 0c 00       	call   0x89c9f0
  7dc472:	cc                   	int3
  7dc473:	cc                   	int3
  7dc474:	cc                   	int3

```
