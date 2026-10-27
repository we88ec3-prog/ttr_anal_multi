# T08-093 — 底層資源進度、子項變換更新、完成旗標與回收鏈

- 研究者：`chatgpt-web roy`
- 時間：2026-10-27T10:38:53.958911+08:00
- Repository：`we88ec3-prog/ttr_anal_multi`（本筆記僅本地產生，未提交）
- BIN：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，與交接指定值一致。
- 證據層級：下列含地址之觀察依據原始 PE `.text` 使用 `objdump -d -Mintel` 直接分析；偽程式碼是暫定抽象，不是遊戲原始碼。
- 第 1–92 段由使用者提供交接，僅作已知脈絡。此處著重 T08-093 新證據。

## 1. 本段新增的完整功能鏈

```text
0x007BD7E0 初始化資源
  +0x1C=0 ; +0x24=入參 ; +0x68=0 ; +0x6C=0
       │
       ├─ 0x007FF8B0 (wrapper+0x2C → resource) 更新
       │         └─ 0x007BD8D0 (delta)
       │                ├─ foreach resource->[+0x04,+0x08) 子項指標
       │                │    ├─ item+0x04 指向參數塊
       │                │    ├─ item+0x08 指向 polymorphic binding
       │                │    ├─ binding vtable+0x1C (float) → bool-like result
       │                │    ├─ 0x0077E910 變換合成
       │                │    ├─ 0x0077EA00 Transform 0x2C bytes 複製
       │                │    ├─ binding vtable+0x14 (float,float)
       │                │    └─ binding vtable+0x28 ()
       │                └─ condition → resource+0x6C=1
       │                        └─ 0x007FF8B0 → 0x007BE5B0 重設
       │
       └─ 0x007A86B0 自有 active-list 節點迴圈
                  └─ 0x007BD8D0
                        └─ +0x6C 非零 → manager+0x60--
                                     → 0x007DD1A0 池回收
                                       或 0x007BE0F0 + 0x007BD850 + 釋放
```

## 2. `0x007BD8D0`：更新函式逐段證據與意義

### 2.1 時間相位或累積參數

```asm
007BD8DC fld  dword ptr [ebp+08h]  ; delta
007BD8E0 fmul dword ptr [edi+24h]  ; global multiplier
007BD8EB fadd dword ptr [edi+1Ch]
007BD8FE fstp dword ptr [edi+1Ch]
```

確證 `resource+0x1C += delta * resource+0x24`。由後述「相對偏移、分段、循環」的消費形式，`+0x1C` 應暫稱 `phase` / 時間型位置，`+0x24` 應暫稱 `phaseRate`；是否代表真正秒數、動畫時間不可定論。

### 2.2 兩組變換建立及融合

開頭從 `resource+0x18`、`+0x28..+0x30`、`+0x34..+0x3C`、`+0x40`、`+0x44..+0x4C`、`+0x50..+0x58` 建立暫存變換。`0x00790DC0`、`0x00790E90`、`0x00790F60`（可能是軸向變換工具）與 `0x00780890` 被使用兩輪；`0x0089E860` 初始化暫存變換構造物件。此處不能直接把各欄稱為旋轉角/偏移座標，待細查 helper 的引數與輸出。

### 2.3 子項遍歷及虛擬方法

```asm
007BDB5A mov eax, [edi+08h]
007BDB61 sub eax, [edi+04h]
007BDB68 sar eax, 2
007BDB8B mov esi, [edx+eax*4]   ; item ptr
007BDB8E mov ebx, [esi+04h]    ; parameter block
007BDB94 mov ecx, [esi+08h]    ; polymorphic binding
007BDB99 mov eax, [edx+1Ch]    ; vtable slot
007BDB9C fmul dword ptr [ebx+64h]
007BDBB3 call eax
007BDBB8 and dword ptr [esp+40h], eax
```

`item+0x04` 是參數塊，`item+0x08` 是 binding。傳入 binding 虛擬槽 `+0x1C` 的資料為 `(resource.phase - block+0x40) * block+0x64`；回傳值採 AND 聚合，用於函式結尾是否允許設完成。`binding` 記憶體 `+0x70`, `+0x74`, `+0x78` 另用於變換合成/寫入。不能僅憑槽位給出原始函式名稱。

### 2.4 子項 transform output

```asm
007BDBDD mov eax, [ecx+78h]
007BDBF1 call 0x0077E910
007BDBF9 mov ecx, [[esi+08h]+74h]
007BDC07 mov edx, [eax]
 ...
007BDC50 mov eax, [eax+28h]
007BDC50..007BDC52 mov [ecx+28h], eax
```

當 `block+0x60 != 0` 時可直接寫入 binding+0x74 所指之 transform；另一分支經 `0x0077EA00` 完成拷貝。`0x0077EA00` 已於本段直接反組譯，搬移 `0x00..0x28` 共 `0x2C` byte，並在來源與目標相同時跳過。

`block+0x60 == 0` 時依 `block+0x40` 與 `resource+0x1C` 比較，會在相位達標後處理 `resource+0x5C/+0x60/+0x64`，且視 `resource+0x68==0` 首次以 `0x0077E910 → 0x0077EA00` 更新變換，隨後將 `resource+0x68` 遞增。一般分支合成 `resource+0x44..+0x4C` 與變換並輸出。

### 2.5 循環/分段與子項 tick

```asm
007BDDBF cmp byte ptr [ebx+61h], 0
007BDDD3 call 0x008FED10
007BDDE0 cmp eax, ecx
007BDDE4 lea eax, [ecx-1]
...
007BDE36 fmul st, st(2)
007BDE3C call 0x008FED10
...
007BDE71 mov ecx, [esi+08h]
007BDE79 mov eax, [edx+14h]
007BDE7C call eax
007BDE83 mov eax, [edx+28h]
007BDE88 call eax
```

`block+0x61` 控制有界的整數段索引，`binding+0x70` 參與 reciprocal / normalization，`0x008FED10` 返回整數。另一分支亦以相同函式形成環狀/分段的餘量，故有明確 **phase 分段或環繞** 的機制；尚未確立這一定是動畫 loop 或資源重播。呼叫 `binding vtable+0x14` 使用兩個浮點引數，隨後呼叫 `+0x28`。

### 2.6 完成條件及狀態

```asm
007BDEA5 fld [edi+1Ch]
007BDEA8 fld [edi+20h]
007BDEAB fcompp
007BDEB4 cmp dword ptr [esp+40h], 0
007BDEBB cmp dword ptr [edi+14h], 0
007BDEC5 mov dword ptr [edi+6Ch], 1
007BDEF1 mov dword ptr [edi+68h], 0
```

當 `resource+0x20` 與進度 `+0x1C` 比較達到指定序關係、所有子項的虛擬 `+0x1C` 回傳值聚合非零、以及 `resource+0x14==0` 時，設 `+0x6C=1`，回寫 `+0x5C/+0x60/+0x64`，並重設 `+0x68=0`。注意 x87 flags / NaN 路徑有例外：應寫成「有序比較及條件」而非先假設純粹的 `>=`。此證據也給先前聚合 `resource+0x20` 一個**確證讀取者**：`0x007BD8D0` 自身！但尚不能稱該值為動畫長度。

## 3. 其他函式與新資料流

| 函式 VA | 本段 BIN 觀察 | 信心 |
|---|---|---|
| `0x007BD7E0` | resource 初始化：`+0x1C=0`, `+0x24=輸入 float`, `+0x68=0`, `+0x6C=0`, `+0x70=1` | 確認 |
| `0x007BD8D0` | 相位累加、遍歷子項、變換、完成條件 | 確認 |
| `0x0077EA00` | `0x2C` bytes Transform 複製 helper | 確認 |
| `0x007BDF00` | 遍歷資源子項呼叫各 binding vtable `+0x20`，傳入第二引數 | 確認 |
| `0x007BDF40` | 三重 gate `binding != NULL`, `item.firstbyte==0`, `binding+0x80==0` 才呼叫 binding vtable `+0x18` | 確認 |
| `0x007A86B0` | 遍歷 `manager+0x10C` 哨兵雙向串列，更新 resource，根據 `+0x6C` 清理節點/回收 | 確認 |
| `0x007A87D0` | 透過 `manager+0x108` 更新單一 resource，之後以 `0x007BDF00` 派送子項，連入更廣更新管線 | 確認 |
| `0x007FF8B0` | wrapper+0x2C → resource，呼叫更新，若 resource+0x6C 非零則 `0x007BE5B0` | 確認 |
| `0x007FF8E0` | wrapper+0x2C → resource，呼叫 `0x007BDF40` | 確認 |
| `0x007BE0F0` | 清理子項 binding、令 `item+0x08=NULL` 並使 resource+0x74=0 | 確認 |

### 3.1 首次確認 `0x007A86B0` 的完成資源移除路徑

```asm
007A86DF mov edi, [esi+08h]           ; active node → resource
007A871C call 0x007BD8D0
007A8721 cmp dword ptr [edi+6Ch],0
007A872B mov eax,[edi]
007A872D dec dword ptr [eax+60h]      ; manager active count
007A8741 call 0x007DD1A0              ; conditional pool path
007A874E call 0x007BE0F0              ; alternate subitem detach
007A8753 call 0x007BD850              ; subitem array cleanup
007A8759 call 0x0089120C              ; allocator free
007A8793 push esi
007A8797 call 0x0089120C               ; linked-list node free
007A87A2 dec dword ptr [edi+110h]     ; active-list count
```

**補強資源生命週期認知**：`+0x6C` 是某路徑會消費的「可結束、可回收」訊號，並非單純只供渲染檢查的欄位。鏈上存在池回收與直接釋放兩路；後者還會先清理 binding。

### 3.2 全部直接 call reference（以 E8 rel32 解碼後確認）

- `0x007BD8D0`：`0x004C881A`, `0x004C8846`, `0x004CB03E`, `0x004CC561`, `0x004CC5B5`, `0x004CE0AC`, `0x004D0692`, `0x004D166D`, `0x004D2A4C`, `0x00550FA7`, `0x007A871C`, `0x007A8927`, `0x007FF8C1`。
- `0x007BDF40`：`0x00492C0B`, `0x004C8929`, `0x004C894E`, `0x004CB062`, `0x004CC705`, `0x004CC71D`, `0x004CE2CE`, `0x004D0863`, `0x004D1242`, `0x004D2C82`, `0x007A6694`, `0x007A66A9`, `0x007FF8E4`。
- `0x007BDF00`：`0x007A8937`。
- 這是從 `.text` 直接掃描 `E8` + 相對位移得到的**候選直接 call 網址**並透過重點反組譯確認；極端情況會包含偶然對齊，不代表間接呼叫已遍歷。

## 4. 暫定 C++ 高階偽程式碼

```cpp
// Illustrative only. Registers/ABI are not C++ proof.
void update_resource(Resource* r, float delta) {
    r->phase_1C += delta * r->phaseRate_24;
    Transform composedBase = build_transform_1(r); // helpers not fully mapped
    Transform composedOther = build_transform_2(r);
    bool allChildrenDone = true;
    for (Item* it : r->items_04_to_08) {
        Block* p = it->params_04;
        Binding* b = it->binding_08; // important: no universal nonnull proof
        float local = (r->phase_1C - p->field_40) * p->field_64;
        allChildrenDone &= b->vfunc_1C(local);
        // Flag p+0x60 changes output behavior.
        // p+0x61 changes segment/loop-like interpolation behavior.
        // Compose output into b->transform_74 via source b->transform_78.
        // b->vfunc_14(adjustedDelta, localPhase);
        // b->vfunc_28();
    }
    if (ordered_threshold_met(r->field_20, r->phase_1C)
        && allChildrenDone && r->field_14 == 0) {
        r->flag_6C = 1;
        r->field_5C = /* locally computed */;
        r->field_60 = /* locally computed */;
        r->field_64 = /* locally computed */;
        r->field_68 = 0;
    }
}
```

偽程式碼省略 x87 stack 細節與 NaN 例外，也未解出所有 helper，切忌拿來直接重寫或視為精確實作。

## 5. 待釐清、限制及下一段任務

1. 尚未確認所有 `binding vtable+0x18` 實作與具體職責。需以建立 binding 的 allocation 與 vtable 常數回推，避免僅按偏移猜測。
2. `binding+0x80` 的寫入者仍需追蹤。三重 gate 只證明何時允許子項虛擬更新。
3. `resource+0x20` 的**第一個可靠讀取者**已定位到 `0x007BD8D0`；要繼續回追聚合來源是否量綱一致，不應僅憑比較命名成「動畫總長」。
4. `0x007A86B0` 是 active-list 資源回收迴圈，但**不是** `scene object vtable+0x20` 的主場景更新迴圈；後者仍未定位。
5. `0x007A87D0` 的較大層更新流程需要接續解析，它已同時串入更新資源與 `0x007BDF00` 虛擬派送。
6. `0x007BE5B0` 在 wrapper 更新完成後可被直接呼叫，但它代表重設而非必然釋放；所有權需分別推理。
7. `0x008FED10` 應確認確切浮點→整數模式，避免把整數段索引誤稱為帧數。
8. 須從 `0x007DCFB0` 起沿配置源追蹤 `Resource` 對象到 `+0x20` 的每個讀取者，包含 vtable 導致的間接路徑。

## 6. GitHub 狀態

本段僅建立本地完整 Markdown，**未建立 GitHub Commit**，未修改 `kr/` 或他人目錄。交接給定先前最新 commit：`088abbd338e95d85bc3beb4c979249f798aba153`，未在本段重新宣稱遠端 HEAD 不變。

## 附錄 A：`0x007BD8D0` 至 `0x007BDF40` BIN 反組譯節錄（含完整 0x7BD8D0 函式）

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bd8d0 <.text+0x3bc8d0>:
  7bd8d0:	55                   	push   ebp
  7bd8d1:	8b ec                	mov    ebp,esp
  7bd8d3:	83 e4 f8             	and    esp,0xfffffff8
  7bd8d6:	81 ec 28 01 00 00    	sub    esp,0x128
  7bd8dc:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7bd8df:	53                   	push   ebx
  7bd8e0:	d8 4f 24             	fmul   DWORD PTR [edi+0x24]
  7bd8e3:	56                   	push   esi
  7bd8e4:	6a 34                	push   0x34
  7bd8e6:	bb 01 00 00 00       	mov    ebx,0x1
  7bd8eb:	d8 47 1c             	fadd   DWORD PTR [edi+0x1c]
  7bd8ee:	6a 00                	push   0x0
  7bd8f0:	89 9c 24 34 01 00 00 	mov    DWORD PTR [esp+0x134],ebx
  7bd8f7:	89 9c 24 a4 00 00 00 	mov    DWORD PTR [esp+0xa4],ebx
  7bd8fe:	d9 5f 1c             	fstp   DWORD PTR [edi+0x1c]
  7bd901:	d9 ee                	fldz
  7bd903:	d9 54 24 7c          	fst    DWORD PTR [esp+0x7c]
  7bd907:	d9 94 24 80 00 00 00 	fst    DWORD PTR [esp+0x80]
  7bd90e:	d9 94 24 84 00 00 00 	fst    DWORD PTR [esp+0x84]
  7bd915:	d9 94 24 88 00 00 00 	fst    DWORD PTR [esp+0x88]
  7bd91c:	d9 94 24 8c 00 00 00 	fst    DWORD PTR [esp+0x8c]
  7bd923:	d9 94 24 90 00 00 00 	fst    DWORD PTR [esp+0x90]
  7bd92a:	d9 e8                	fld1
  7bd92c:	d9 94 24 94 00 00 00 	fst    DWORD PTR [esp+0x94]
  7bd933:	d9 94 24 98 00 00 00 	fst    DWORD PTR [esp+0x98]
  7bd93a:	d9 94 24 9c 00 00 00 	fst    DWORD PTR [esp+0x9c]
  7bd941:	d9 94 24 a0 00 00 00 	fst    DWORD PTR [esp+0xa0]
  7bd948:	d9 47 18             	fld    DWORD PTR [edi+0x18]
  7bd94b:	d9 5c 24 60          	fstp   DWORD PTR [esp+0x60]
  7bd94f:	d9 47 18             	fld    DWORD PTR [edi+0x18]
  7bd952:	8b 44 24 60          	mov    eax,DWORD PTR [esp+0x60]
  7bd956:	d9 5c 24 64          	fstp   DWORD PTR [esp+0x64]
  7bd95a:	d9 47 18             	fld    DWORD PTR [edi+0x18]
  7bd95d:	89 84 24 28 01 00 00 	mov    DWORD PTR [esp+0x128],eax
  7bd964:	8b 4c 24 64          	mov    ecx,DWORD PTR [esp+0x64]
  7bd968:	d9 5c 24 68          	fstp   DWORD PTR [esp+0x68]
  7bd96c:	d9 c9                	fxch   st(1)
  7bd96e:	8d 84 24 ac 00 00 00 	lea    eax,[esp+0xac]
  7bd975:	8b 54 24 68          	mov    edx,DWORD PTR [esp+0x68]
  7bd979:	d9 54 24 50          	fst    DWORD PTR [esp+0x50]
  7bd97d:	d9 54 24 54          	fst    DWORD PTR [esp+0x54]
  7bd981:	50                   	push   eax
  7bd982:	d9 5c 24 5c          	fstp   DWORD PTR [esp+0x5c]
  7bd986:	89 8c 24 30 01 00 00 	mov    DWORD PTR [esp+0x130],ecx
  7bd98d:	89 94 24 34 01 00 00 	mov    DWORD PTR [esp+0x134],edx
  7bd994:	d9 5c 24 60          	fstp   DWORD PTR [esp+0x60]
  7bd998:	e8 c3 0e 0e 00       	call   0x89e860
  7bd99d:	d9 e8                	fld1
  7bd99f:	83 c4 08             	add    esp,0x8
  7bd9a2:	d9 94 24 c8 00 00 00 	fst    DWORD PTR [esp+0xc8]
  7bd9a9:	8d b4 24 a8 00 00 00 	lea    esi,[esp+0xa8]
  7bd9b0:	d9 94 24 b8 00 00 00 	fst    DWORD PTR [esp+0xb8]
  7bd9b7:	d9 9c 24 a8 00 00 00 	fstp   DWORD PTR [esp+0xa8]
  7bd9be:	d9 47 34             	fld    DWORD PTR [edi+0x34]
  7bd9c1:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bd9c4:	e8 f7 33 fd ff       	call   0x790dc0
  7bd9c9:	d9 47 38             	fld    DWORD PTR [edi+0x38]
  7bd9cc:	51                   	push   ecx
  7bd9cd:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bd9d0:	e8 bb 34 fd ff       	call   0x790e90
  7bd9d5:	d9 47 3c             	fld    DWORD PTR [edi+0x3c]
  7bd9d8:	51                   	push   ecx
  7bd9d9:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bd9dc:	e8 7f 35 fd ff       	call   0x790f60
  7bd9e1:	8d 4c 24 48          	lea    ecx,[esp+0x48]
  7bd9e5:	e8 a6 2e fc ff       	call   0x780890
  7bd9ea:	d9 44 24 54          	fld    DWORD PTR [esp+0x54]
  7bd9ee:	d9 9c 24 1c 01 00 00 	fstp   DWORD PTR [esp+0x11c]
  7bd9f5:	d9 44 24 48          	fld    DWORD PTR [esp+0x48]
  7bd9f9:	d9 9c 24 10 01 00 00 	fstp   DWORD PTR [esp+0x110]
  7bda00:	d9 44 24 4c          	fld    DWORD PTR [esp+0x4c]
  7bda04:	d9 9c 24 14 01 00 00 	fstp   DWORD PTR [esp+0x114]
  7bda0b:	d9 44 24 50          	fld    DWORD PTR [esp+0x50]
  7bda0f:	d9 9c 24 18 01 00 00 	fstp   DWORD PTR [esp+0x118]
  7bda16:	d9 47 28             	fld    DWORD PTR [edi+0x28]
  7bda19:	d9 5c 24 64          	fstp   DWORD PTR [esp+0x64]
  7bda1d:	8b 4c 24 64          	mov    ecx,DWORD PTR [esp+0x64]
  7bda21:	d9 47 2c             	fld    DWORD PTR [edi+0x2c]
  7bda24:	89 8c 24 04 01 00 00 	mov    DWORD PTR [esp+0x104],ecx
  7bda2b:	d9 5c 24 68          	fstp   DWORD PTR [esp+0x68]
  7bda2f:	8b 54 24 68          	mov    edx,DWORD PTR [esp+0x68]
  7bda33:	d9 47 30             	fld    DWORD PTR [edi+0x30]
  7bda36:	89 94 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],edx
  7bda3d:	d9 5c 24 6c          	fstp   DWORD PTR [esp+0x6c]
  7bda41:	8b 44 24 6c          	mov    eax,DWORD PTR [esp+0x6c]
  7bda45:	d9 47 40             	fld    DWORD PTR [edi+0x40]
  7bda48:	6a 34                	push   0x34
  7bda4a:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  7bda4e:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  7bda52:	d9 47 40             	fld    DWORD PTR [edi+0x40]
  7bda55:	89 8c 24 f8 00 00 00 	mov    DWORD PTR [esp+0xf8],ecx
  7bda5c:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  7bda60:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  7bda64:	d9 47 40             	fld    DWORD PTR [edi+0x40]
  7bda67:	89 84 24 10 01 00 00 	mov    DWORD PTR [esp+0x110],eax
  7bda6e:	d9 5c 24 30          	fstp   DWORD PTR [esp+0x30]
  7bda72:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  7bda76:	d9 ee                	fldz
  7bda78:	8d 8c 24 a8 00 00 00 	lea    ecx,[esp+0xa8]
  7bda7f:	d9 54 24 18          	fst    DWORD PTR [esp+0x18]
  7bda83:	6a 00                	push   0x0
  7bda85:	d9 54 24 20          	fst    DWORD PTR [esp+0x20]
  7bda89:	51                   	push   ecx
  7bda8a:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  7bda8e:	89 9c 24 0c 01 00 00 	mov    DWORD PTR [esp+0x10c],ebx
  7bda95:	d9 e8                	fld1
  7bda97:	89 94 24 04 01 00 00 	mov    DWORD PTR [esp+0x104],edx
  7bda9e:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  7bdaa2:	89 84 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],eax
  7bdaa9:	e8 b2 0d 0e 00       	call   0x89e860
  7bdaae:	d9 e8                	fld1
  7bdab0:	d9 94 24 d0 00 00 00 	fst    DWORD PTR [esp+0xd0]
  7bdab7:	83 c4 08             	add    esp,0x8
  7bdaba:	d9 94 24 b8 00 00 00 	fst    DWORD PTR [esp+0xb8]
  7bdac1:	8d b4 24 a8 00 00 00 	lea    esi,[esp+0xa8]
  7bdac8:	d9 9c 24 a8 00 00 00 	fstp   DWORD PTR [esp+0xa8]
  7bdacf:	d9 47 50             	fld    DWORD PTR [edi+0x50]
  7bdad2:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bdad5:	e8 e6 32 fd ff       	call   0x790dc0
  7bdada:	d9 47 54             	fld    DWORD PTR [edi+0x54]
  7bdadd:	51                   	push   ecx
  7bdade:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bdae1:	e8 aa 33 fd ff       	call   0x790e90
  7bdae6:	d9 47 58             	fld    DWORD PTR [edi+0x58]
  7bdae9:	51                   	push   ecx
  7bdaea:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bdaed:	e8 6e 34 fd ff       	call   0x790f60
  7bdaf2:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  7bdaf6:	e8 95 2d fc ff       	call   0x780890
  7bdafb:	d9 44 24 20          	fld    DWORD PTR [esp+0x20]
  7bdaff:	d9 9c 24 f0 00 00 00 	fstp   DWORD PTR [esp+0xf0]
  7bdb06:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  7bdb0a:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  7bdb0e:	c7 44 24 3c 00 00 00 	mov    DWORD PTR [esp+0x3c],0x0
  7bdb15:	00 
  7bdb16:	d9 9c 24 e4 00 00 00 	fstp   DWORD PTR [esp+0xe4]
  7bdb1d:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  7bdb21:	d9 9c 24 e8 00 00 00 	fstp   DWORD PTR [esp+0xe8]
  7bdb28:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  7bdb2c:	d9 9c 24 ec 00 00 00 	fstp   DWORD PTR [esp+0xec]
  7bdb33:	d9 47 44             	fld    DWORD PTR [edi+0x44]
  7bdb36:	d9 5c 24 30          	fstp   DWORD PTR [esp+0x30]
  7bdb3a:	8b 54 24 30          	mov    edx,DWORD PTR [esp+0x30]
  7bdb3e:	d9 47 48             	fld    DWORD PTR [edi+0x48]
  7bdb41:	89 94 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],edx
  7bdb48:	d9 5c 24 34          	fstp   DWORD PTR [esp+0x34]
  7bdb4c:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  7bdb50:	d9 47 4c             	fld    DWORD PTR [edi+0x4c]
  7bdb53:	89 84 24 dc 00 00 00 	mov    DWORD PTR [esp+0xdc],eax
  7bdb5a:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  7bdb5d:	d9 5c 24 38          	fstp   DWORD PTR [esp+0x38]
  7bdb61:	2b 47 04             	sub    eax,DWORD PTR [edi+0x4]
  7bdb64:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  7bdb68:	c1 f8 02             	sar    eax,0x2
  7bdb6b:	89 8c 24 e0 00 00 00 	mov    DWORD PTR [esp+0xe0],ecx
  7bdb72:	89 84 24 a0 00 00 00 	mov    DWORD PTR [esp+0xa0],eax
  7bdb79:	85 c0                	test   eax,eax
  7bdb7b:	0f 84 24 03 00 00    	je     0x7bdea5
  7bdb81:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  7bdb84:	d9 47 1c             	fld    DWORD PTR [edi+0x1c]
  7bdb87:	8b 44 24 3c          	mov    eax,DWORD PTR [esp+0x3c]
  7bdb8b:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  7bdb8e:	8b 5e 04             	mov    ebx,DWORD PTR [esi+0x4]
  7bdb91:	d8 63 40             	fsub   DWORD PTR [ebx+0x40]
  7bdb94:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7bdb97:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bdb99:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  7bdb9c:	d8 4b 64             	fmul   DWORD PTR [ebx+0x64]
  7bdb9f:	51                   	push   ecx
  7bdba0:	89 5c 24 0c          	mov    DWORD PTR [esp+0xc],ebx
  7bdba4:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  7bdba8:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  7bdbac:	d9 54 24 14          	fst    DWORD PTR [esp+0x14]
  7bdbb0:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bdbb3:	ff d0                	call   eax
  7bdbb5:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7bdbb8:	21 44 24 40          	and    DWORD PTR [esp+0x40],eax
  7bdbbc:	85 c9                	test   ecx,ecx
  7bdbbe:	0f 84 c6 02 00 00    	je     0x7bde8a
  7bdbc4:	80 7b 60 00          	cmp    BYTE PTR [ebx+0x60],0x0
  7bdbc8:	d9 41 70             	fld    DWORD PTR [ecx+0x70]
  7bdbcb:	d9 5c 24 44          	fstp   DWORD PTR [esp+0x44]
  7bdbcf:	d9 44 24 44          	fld    DWORD PTR [esp+0x44]
  7bdbd3:	d9 e8                	fld1
  7bdbd5:	de f1                	fdivrp st(1),st
  7bdbd7:	d9 5c 24 70          	fstp   DWORD PTR [esp+0x70]
  7bdbdb:	74 7b                	je     0x7bdc58
  7bdbdd:	8b 41 78             	mov    eax,DWORD PTR [ecx+0x78]
  7bdbe0:	8d 94 24 04 01 00 00 	lea    edx,[esp+0x104]
  7bdbe7:	52                   	push   edx
  7bdbe8:	50                   	push   eax
  7bdbe9:	8d 8c 24 ac 00 00 00 	lea    ecx,[esp+0xac]
  7bdbf0:	51                   	push   ecx
  7bdbf1:	e8 1a 0d fc ff       	call   0x77e910
  7bdbf6:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7bdbf9:	8b 49 74             	mov    ecx,DWORD PTR [ecx+0x74]
  7bdbfc:	83 c4 0c             	add    esp,0xc
  7bdbff:	3b c8                	cmp    ecx,eax
  7bdc01:	0f 84 b8 01 00 00    	je     0x7bddbf
  7bdc07:	8b 10                	mov    edx,DWORD PTR [eax]
  7bdc09:	89 11                	mov    DWORD PTR [ecx],edx
  7bdc0b:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7bdc0e:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  7bdc11:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7bdc14:	89 51 08             	mov    DWORD PTR [ecx+0x8],edx
  7bdc17:	8d 50 0c             	lea    edx,[eax+0xc]
  7bdc1a:	8d 59 0c             	lea    ebx,[ecx+0xc]
  7bdc1d:	3b da                	cmp    ebx,edx
  7bdc1f:	74 16                	je     0x7bdc37
  7bdc21:	d9 42 0c             	fld    DWORD PTR [edx+0xc]
  7bdc24:	d9 5b 0c             	fstp   DWORD PTR [ebx+0xc]
  7bdc27:	d9 02                	fld    DWORD PTR [edx]
  7bdc29:	d9 1b                	fstp   DWORD PTR [ebx]
  7bdc2b:	d9 42 04             	fld    DWORD PTR [edx+0x4]
  7bdc2e:	d9 5b 04             	fstp   DWORD PTR [ebx+0x4]
  7bdc31:	d9 42 08             	fld    DWORD PTR [edx+0x8]
  7bdc34:	d9 5b 08             	fstp   DWORD PTR [ebx+0x8]
  7bdc37:	8b 50 1c             	mov    edx,DWORD PTR [eax+0x1c]
  7bdc3a:	8b 5c 24 08          	mov    ebx,DWORD PTR [esp+0x8]
  7bdc3e:	89 51 1c             	mov    DWORD PTR [ecx+0x1c],edx
  7bdc41:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  7bdc44:	89 51 20             	mov    DWORD PTR [ecx+0x20],edx
  7bdc47:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  7bdc4a:	89 51 24             	mov    DWORD PTR [ecx+0x24],edx
  7bdc4d:	8b 40 28             	mov    eax,DWORD PTR [eax+0x28]
  7bdc50:	89 41 28             	mov    DWORD PTR [ecx+0x28],eax
  7bdc53:	e9 67 01 00 00       	jmp    0x7bddbf
  7bdc58:	d9 43 40             	fld    DWORD PTR [ebx+0x40]
  7bdc5b:	d9 47 1c             	fld    DWORD PTR [edi+0x1c]
  7bdc5e:	de d9                	fcompp
  7bdc60:	df e0                	fnstsw ax
  7bdc62:	f6 c4 41             	test   ah,0x41
  7bdc65:	0f 85 2b 01 00 00    	jne    0x7bdd96
  7bdc6b:	d9 44 24 64          	fld    DWORD PTR [esp+0x64]
  7bdc6f:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  7bdc73:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  7bdc77:	d9 44 24 68          	fld    DWORD PTR [esp+0x68]
  7bdc7b:	89 4f 5c             	mov    DWORD PTR [edi+0x5c],ecx
  7bdc7e:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  7bdc82:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  7bdc86:	d9 44 24 6c          	fld    DWORD PTR [esp+0x6c]
  7bdc8a:	89 57 60             	mov    DWORD PTR [edi+0x60],edx
  7bdc8d:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  7bdc91:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  7bdc95:	89 47 64             	mov    DWORD PTR [edi+0x64],eax
  7bdc98:	d9 47 5c             	fld    DWORD PTR [edi+0x5c]
  7bdc9b:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  7bdc9f:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  7bdca3:	d9 47 60             	fld    DWORD PTR [edi+0x60]
  7bdca6:	89 4c 24 74          	mov    DWORD PTR [esp+0x74],ecx
  7bdcaa:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  7bdcae:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  7bdcb2:	d9 47 64             	fld    DWORD PTR [edi+0x64]
  7bdcb5:	89 54 24 78          	mov    DWORD PTR [esp+0x78],edx
  7bdcb9:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  7bdcbd:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  7bdcc1:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  7bdcc5:	89 44 24 7c          	mov    DWORD PTR [esp+0x7c],eax
  7bdcc9:	d9 44 24 30          	fld    DWORD PTR [esp+0x30]
  7bdccd:	da e9                	fucompp
  7bdccf:	df e0                	fnstsw ax
  7bdcd1:	f6 c4 44             	test   ah,0x44
  7bdcd4:	7a 26                	jp     0x7bdcfc
  7bdcd6:	d9 44 24 28          	fld    DWORD PTR [esp+0x28]
  7bdcda:	d9 44 24 34          	fld    DWORD PTR [esp+0x34]
  7bdcde:	da e9                	fucompp
  7bdce0:	df e0                	fnstsw ax
  7bdce2:	f6 c4 44             	test   ah,0x44
  7bdce5:	7a 15                	jp     0x7bdcfc
  7bdce7:	d9 44 24 2c          	fld    DWORD PTR [esp+0x2c]
  7bdceb:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  7bdcef:	da e9                	fucompp
  7bdcf1:	df e0                	fnstsw ax
  7bdcf3:	f6 c4 44             	test   ah,0x44
  7bdcf6:	0f 8b 81 00 00 00    	jnp    0x7bdd7d
  7bdcfc:	83 7f 68 00          	cmp    DWORD PTR [edi+0x68],0x0
  7bdd00:	75 7b                	jne    0x7bdd7d
  7bdd02:	d9 44 24 54          	fld    DWORD PTR [esp+0x54]
  7bdd06:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  7bdd0a:	8b 44 24 60          	mov    eax,DWORD PTR [esp+0x60]
  7bdd0e:	d9 9c 24 8c 00 00 00 	fstp   DWORD PTR [esp+0x8c]
  7bdd15:	8b 54 24 5c          	mov    edx,DWORD PTR [esp+0x5c]
  7bdd19:	d9 44 24 48          	fld    DWORD PTR [esp+0x48]
  7bdd1d:	d9 9c 24 80 00 00 00 	fstp   DWORD PTR [esp+0x80]
  7bdd24:	89 84 24 98 00 00 00 	mov    DWORD PTR [esp+0x98],eax
  7bdd2b:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7bdd2e:	d9 44 24 4c          	fld    DWORD PTR [esp+0x4c]
  7bdd32:	89 8c 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],ecx
  7bdd39:	d9 9c 24 84 00 00 00 	fstp   DWORD PTR [esp+0x84]
  7bdd40:	d9 44 24 50          	fld    DWORD PTR [esp+0x50]
  7bdd44:	8d 4c 24 74          	lea    ecx,[esp+0x74]
  7bdd48:	89 94 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],edx
  7bdd4f:	d9 9c 24 88 00 00 00 	fstp   DWORD PTR [esp+0x88]
  7bdd56:	8b 50 78             	mov    edx,DWORD PTR [eax+0x78]
  7bdd59:	51                   	push   ecx
  7bdd5a:	52                   	push   edx
  7bdd5b:	8d 84 24 ac 00 00 00 	lea    eax,[esp+0xac]
  7bdd62:	50                   	push   eax
  7bdd63:	e8 a8 0b fc ff       	call   0x77e910
  7bdd68:	8b c8                	mov    ecx,eax
  7bdd6a:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7bdd6d:	8b 40 74             	mov    eax,DWORD PTR [eax+0x74]
  7bdd70:	83 c4 0c             	add    esp,0xc
  7bdd73:	e8 88 0c fc ff       	call   0x77ea00
  7bdd78:	ff 47 68             	inc    DWORD PTR [edi+0x68]
  7bdd7b:	eb 42                	jmp    0x7bddbf
  7bdd7d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7bdd80:	8b 50 78             	mov    edx,DWORD PTR [eax+0x78]
  7bdd83:	8d 8c 24 d8 00 00 00 	lea    ecx,[esp+0xd8]
  7bdd8a:	51                   	push   ecx
  7bdd8b:	52                   	push   edx
  7bdd8c:	8d 84 24 ac 00 00 00 	lea    eax,[esp+0xac]
  7bdd93:	50                   	push   eax
  7bdd94:	eb 14                	jmp    0x7bddaa
  7bdd96:	8b 41 78             	mov    eax,DWORD PTR [ecx+0x78]
  7bdd99:	8d 94 24 d8 00 00 00 	lea    edx,[esp+0xd8]
  7bdda0:	52                   	push   edx
  7bdda1:	50                   	push   eax
  7bdda2:	8d 8c 24 ac 00 00 00 	lea    ecx,[esp+0xac]
  7bdda9:	51                   	push   ecx
  7bddaa:	e8 61 0b fc ff       	call   0x77e910
  7bddaf:	8b c8                	mov    ecx,eax
  7bddb1:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7bddb4:	8b 40 74             	mov    eax,DWORD PTR [eax+0x74]
  7bddb7:	83 c4 0c             	add    esp,0xc
  7bddba:	e8 41 0c fc ff       	call   0x77ea00
  7bddbf:	80 7b 61 00          	cmp    BYTE PTR [ebx+0x61],0x0
  7bddc3:	74 60                	je     0x7bde25
  7bddc5:	d9 44 24 70          	fld    DWORD PTR [esp+0x70]
  7bddc9:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  7bddcd:	d9 c0                	fld    st(0)
  7bddcf:	de ca                	fmulp  st(2),st
  7bddd1:	d9 c9                	fxch   st(1)
  7bddd3:	e8 38 0f 14 00       	call   0x8fed10
  7bddd8:	0f b6 4b 61          	movzx  ecx,BYTE PTR [ebx+0x61]
  7bdddc:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  7bdde0:	3b c1                	cmp    eax,ecx
  7bdde2:	7c 07                	jl     0x7bddeb
  7bdde4:	8d 41 ff             	lea    eax,[ecx-0x1]
  7bdde7:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  7bddeb:	db 44 24 0c          	fild   DWORD PTR [esp+0xc]
  7bddef:	d8 4c 24 44          	fmul   DWORD PTR [esp+0x44]
  7bddf3:	de e9                	fsubp  st(1),st
  7bddf5:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  7bddf9:	85 c0                	test   eax,eax
  7bddfb:	79 0a                	jns    0x7bde07
  7bddfd:	d9 05 68 56 c5 00    	fld    DWORD PTR ds:0xc55668
  7bde03:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  7bde07:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  7bde0b:	83 ec 08             	sub    esp,0x8
  7bde0e:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7bde12:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7bde15:	d8 4f 24             	fmul   DWORD PTR [edi+0x24]
  7bde18:	d8 4b 64             	fmul   DWORD PTR [ebx+0x64]
  7bde1b:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  7bde1f:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  7bde23:	eb 4c                	jmp    0x7bde71
  7bde25:	d9 44 24 0c          	fld    DWORD PTR [esp+0xc]
  7bde29:	d9 44 24 44          	fld    DWORD PTR [esp+0x44]
  7bde2d:	d8 d1                	fcom   st(1)
  7bde2f:	df e0                	fnstsw ax
  7bde31:	f6 c4 41             	test   ah,0x41
  7bde34:	7a 1b                	jp     0x7bde51
  7bde36:	d9 44 24 70          	fld    DWORD PTR [esp+0x70]
  7bde3a:	d8 ca                	fmul   st,st(2)
  7bde3c:	e8 cf 0e 14 00       	call   0x8fed10
  7bde41:	89 44 24 08          	mov    DWORD PTR [esp+0x8],eax
  7bde45:	da 4c 24 08          	fimul  DWORD PTR [esp+0x8]
  7bde49:	de e9                	fsubp  st(1),st
  7bde4b:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  7bde4f:	eb 04                	jmp    0x7bde55
  7bde51:	dd d9                	fstp   st(1)
  7bde53:	dd d8                	fstp   st(0)
  7bde55:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  7bde59:	83 ec 08             	sub    esp,0x8
  7bde5c:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7bde60:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7bde63:	d8 4f 24             	fmul   DWORD PTR [edi+0x24]
  7bde66:	d8 4b 64             	fmul   DWORD PTR [ebx+0x64]
  7bde69:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  7bde6d:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  7bde71:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7bde74:	d9 1c 24             	fstp   DWORD PTR [esp]
  7bde77:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bde79:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  7bde7c:	ff d0                	call   eax
  7bde7e:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  7bde81:	8b 16                	mov    edx,DWORD PTR [esi]
  7bde83:	8b 42 28             	mov    eax,DWORD PTR [edx+0x28]
  7bde86:	8b ce                	mov    ecx,esi
  7bde88:	ff d0                	call   eax
  7bde8a:	8b 44 24 3c          	mov    eax,DWORD PTR [esp+0x3c]
  7bde8e:	40                   	inc    eax
  7bde8f:	89 44 24 3c          	mov    DWORD PTR [esp+0x3c],eax
  7bde93:	3b 84 24 a0 00 00 00 	cmp    eax,DWORD PTR [esp+0xa0]
  7bde9a:	0f 82 e1 fc ff ff    	jb     0x7bdb81
  7bdea0:	bb 01 00 00 00       	mov    ebx,0x1
  7bdea5:	d9 47 1c             	fld    DWORD PTR [edi+0x1c]
  7bdea8:	d9 47 20             	fld    DWORD PTR [edi+0x20]
  7bdeab:	de d9                	fcompp
  7bdead:	df e0                	fnstsw ax
  7bdeaf:	f6 c4 41             	test   ah,0x41
  7bdeb2:	7a 44                	jp     0x7bdef8
  7bdeb4:	83 7c 24 40 00       	cmp    DWORD PTR [esp+0x40],0x0
  7bdeb9:	74 3d                	je     0x7bdef8
  7bdebb:	83 7f 14 00          	cmp    DWORD PTR [edi+0x14],0x0
  7bdebf:	75 37                	jne    0x7bdef8
  7bdec1:	d9 44 24 30          	fld    DWORD PTR [esp+0x30]
  7bdec5:	89 5f 6c             	mov    DWORD PTR [edi+0x6c],ebx
  7bdec8:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  7bdecc:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  7bded0:	d9 44 24 34          	fld    DWORD PTR [esp+0x34]
  7bded4:	89 4f 5c             	mov    DWORD PTR [edi+0x5c],ecx
  7bded7:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  7bdedb:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  7bdedf:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  7bdee3:	89 57 60             	mov    DWORD PTR [edi+0x60],edx
  7bdee6:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  7bdeea:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  7bdeee:	89 47 64             	mov    DWORD PTR [edi+0x64],eax
  7bdef1:	c7 47 68 00 00 00 00 	mov    DWORD PTR [edi+0x68],0x0
  7bdef8:	5e                   	pop    esi
  7bdef9:	5b                   	pop    ebx
  7bdefa:	8b e5                	mov    esp,ebp
  7bdefc:	5d                   	pop    ebp
  7bdefd:	c2 04 00             	ret    0x4
  7bdf00:	55                   	push   ebp
  7bdf01:	8b ec                	mov    ebp,esp
  7bdf03:	53                   	push   ebx
  7bdf04:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf07:	56                   	push   esi
  7bdf08:	57                   	push   edi
  7bdf09:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf0c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf0f:	33 f6                	xor    esi,esi
  7bdf11:	c1 ff 02             	sar    edi,0x2
  7bdf14:	85 ff                	test   edi,edi
  7bdf16:	74 21                	je     0x7bdf39
  7bdf18:	eb 06                	jmp    0x7bdf20
  7bdf1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf20:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf23:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf26:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf29:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bdf2b:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7bdf2e:	8b 52 20             	mov    edx,DWORD PTR [edx+0x20]
  7bdf31:	50                   	push   eax
  7bdf32:	ff d2                	call   edx
  7bdf34:	46                   	inc    esi
  7bdf35:	3b f7                	cmp    esi,edi
  7bdf37:	72 e7                	jb     0x7bdf20
  7bdf39:	5f                   	pop    edi
  7bdf3a:	5e                   	pop    esi
  7bdf3b:	5b                   	pop    ebx
  7bdf3c:	5d                   	pop    ebp
  7bdf3d:	c2 08 00             	ret    0x8
  7bdf40:	55                   	push   ebp
  7bdf41:	8b ec                	mov    ebp,esp
  7bdf43:	53                   	push   ebx
  7bdf44:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf47:	56                   	push   esi
  7bdf48:	57                   	push   edi
  7bdf49:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf4c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf4f:	33                   	.byte 0x33
```

## 附錄 B：`0x007A86B0` active-list 資源生命週期反組譯

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a86a0 <.text+0x3a76a0>:
  7a86a0:	c7                   	(bad)
  7a86a1:	8b e5                	mov    esp,ebp
  7a86a3:	5d                   	pop    ebp
  7a86a4:	c2 04 00             	ret    0x4
  7a86a7:	cc                   	int3
  7a86a8:	cc                   	int3
  7a86a9:	cc                   	int3
  7a86aa:	cc                   	int3
  7a86ab:	cc                   	int3
  7a86ac:	cc                   	int3
  7a86ad:	cc                   	int3
  7a86ae:	cc                   	int3
  7a86af:	cc                   	int3
  7a86b0:	55                   	push   ebp
  7a86b1:	8b ec                	mov    ebp,esp
  7a86b3:	83 ec 18             	sub    esp,0x18
  7a86b6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a86bb:	33 c5                	xor    eax,ebp
  7a86bd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7a86c0:	53                   	push   ebx
  7a86c1:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7a86c4:	8b 83 0c 01 00 00    	mov    eax,DWORD PTR [ebx+0x10c]
  7a86ca:	56                   	push   esi
  7a86cb:	8b 30                	mov    esi,DWORD PTR [eax]
  7a86cd:	57                   	push   edi
  7a86ce:	3b f0                	cmp    esi,eax
  7a86d0:	0f 84 e6 00 00 00    	je     0x7a87bc
  7a86d6:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7a86d9:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7a86dc:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  7a86df:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7a86e2:	ff d2                	call   edx
  7a86e4:	d9 5f 3c             	fstp   DWORD PTR [edi+0x3c]
  7a86e7:	c7 47 70 01 00 00 00 	mov    DWORD PTR [edi+0x70],0x1
  7a86ee:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7a86f1:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7a86f4:	8d 4d f0             	lea    ecx,[ebp-0x10]
  7a86f7:	51                   	push   ecx
  7a86f8:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7a86fb:	ff d2                	call   edx
  7a86fd:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  7a8700:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a8702:	89 4f 28             	mov    DWORD PTR [edi+0x28],ecx
  7a8705:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a8708:	89 57 2c             	mov    DWORD PTR [edi+0x2c],edx
  7a870b:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  7a870e:	51                   	push   ecx
  7a870f:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a8712:	89 47 30             	mov    DWORD PTR [edi+0x30],eax
  7a8715:	c7 47 70 01 00 00 00 	mov    DWORD PTR [edi+0x70],0x1
  7a871c:	e8 af 51 01 00       	call   0x7bd8d0
  7a8721:	83 7f 6c 00          	cmp    DWORD PTR [edi+0x6c],0x0
  7a8725:	0f 84 81 00 00 00    	je     0x7a87ac
  7a872b:	8b 07                	mov    eax,DWORD PTR [edi]
  7a872d:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7a8730:	8b 47 74             	mov    eax,DWORD PTR [edi+0x74]
  7a8733:	85 c0                	test   eax,eax
  7a8735:	74 11                	je     0x7a8748
  7a8737:	83 7f 78 00          	cmp    DWORD PTR [edi+0x78],0x0
  7a873b:	74 0b                	je     0x7a8748
  7a873d:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7a873f:	57                   	push   edi
  7a8740:	51                   	push   ecx
  7a8741:	e8 5a 4a 03 00       	call   0x7dd1a0
  7a8746:	eb 19                	jmp    0x7a8761
  7a8748:	83 f8 01             	cmp    eax,0x1
  7a874b:	7c 06                	jl     0x7a8753
  7a874d:	57                   	push   edi
  7a874e:	e8 9d 59 01 00       	call   0x7be0f0
  7a8753:	e8 f8 50 01 00       	call   0x7bd850
  7a8758:	57                   	push   edi
  7a8759:	e8 ae 8a 0e 00       	call   0x89120c
  7a875e:	83 c4 04             	add    esp,0x4
  7a8761:	8b 7e 0c             	mov    edi,DWORD PTR [esi+0xc]
  7a8764:	85 ff                	test   edi,edi
  7a8766:	74 12                	je     0x7a877a
  7a8768:	8b 17                	mov    edx,DWORD PTR [edi]
  7a876a:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  7a876d:	8b cf                	mov    ecx,edi
  7a876f:	ff d0                	call   eax
  7a8771:	8b 17                	mov    edx,DWORD PTR [edi]
  7a8773:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  7a8776:	8b cf                	mov    ecx,edi
  7a8778:	ff d0                	call   eax
  7a877a:	8b 06                	mov    eax,DWORD PTR [esi]
  7a877c:	8b fb                	mov    edi,ebx
  7a877e:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  7a8781:	3b b7 0c 01 00 00    	cmp    esi,DWORD PTR [edi+0x10c]
  7a8787:	74 1f                	je     0x7a87a8
  7a8789:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  7a878c:	89 01                	mov    DWORD PTR [ecx],eax
  7a878e:	8b 16                	mov    edx,DWORD PTR [esi]
  7a8790:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7a8793:	56                   	push   esi
  7a8794:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  7a8797:	e8 70 8a 0e 00       	call   0x89120c
  7a879c:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  7a879f:	83 c4 04             	add    esp,0x4
  7a87a2:	ff 8f 10 01 00 00    	dec    DWORD PTR [edi+0x110]
  7a87a8:	8b f0                	mov    esi,eax
  7a87aa:	eb 04                	jmp    0x7a87b0
  7a87ac:	8b 36                	mov    esi,DWORD PTR [esi]
  7a87ae:	8b fb                	mov    edi,ebx
  7a87b0:	3b b7 0c 01 00 00    	cmp    esi,DWORD PTR [edi+0x10c]
  7a87b6:	0f 85 1a ff ff ff    	jne    0x7a86d6
  7a87bc:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  7a87bf:	5f                   	pop    edi
  7a87c0:	5e                   	pop    esi
  7a87c1:	33 cd                	xor    ecx,ebp
  7a87c3:	5b                   	pop    ebx
  7a87c4:	e8 38 88 0e 00       	call   0x891001
  7a87c9:	8b e5                	mov    esp,ebp
  7a87cb:	5d                   	pop    ebp
  7a87cc:	c2 08 00             	ret    0x8
  7a87cf:	cc                   	int3
  7a87d0:	55                   	push   ebp
  7a87d1:	8b ec                	mov    ebp,esp
  7a87d3:	83 ec 28             	sub    esp,0x28
  7a87d6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a87db:	33 c5                	xor    eax,ebp
  7a87dd:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  7a87e0:	53                   	push   ebx
  7a87e1:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7a87e4:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a87ea:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a87ec:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  7a87ef:	56                   	push   esi
  7a87f0:	57                   	push   edi
  7a87f1:	ff d2                	call   edx
  7a87f3:	85 c0                	test   eax,eax
  7a87f5:	74 7b                	je     0x7a8872
  7a87f7:	83 bb b0 00 00 00 00 	cmp    DWORD PTR [ebx+0xb0],0x0
  7a87fe:	75 72                	jne    0x7a8872
  7a8800:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8806:	c7 83 b0 00 00 00 01 	mov    DWORD PTR [ebx+0xb0],0x1
  7a880d:	00 00 00 
  7a8810:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a8812:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7a8815:	ff d2                	call   edx
  7a8817:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a881a:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a881d:	d9 93 b8 00 00 00    	fst    DWORD PTR [ebx+0xb8]
  7a8823:	d9 83 c0 00 00 00    	fld    DWORD PTR [ebx+0xc0]
  7a8829:	d8 d9                	fcomp  st(1)
  7a882b:	df e0                	fnstsw ax
  7a882d:	f6 c4 41             	test   ah,0x41
  7a8830:	75 10                	jne    0x7a8842
  7a8832:	d9 93 c0 00 00 00    	fst    DWORD PTR [ebx+0xc0]
  7a8838:	c7 83 c4 00 00 00 00 	mov    DWORD PTR [ebx+0xc4],0x0
  7a883f:	00 00 00 
  7a8842:	d9 83 bc 00 00 00    	fld    DWORD PTR [ebx+0xbc]
  7a8848:	de d9                	fcompp
  7a884a:	df e0                	fnstsw ax
  7a884c:	f6 c4 41             	test   ah,0x41
  7a884f:	75 08                	jne    0x7a8859
  7a8851:	d9 ee                	fldz
  7a8853:	d9 9b bc 00 00 00    	fstp   DWORD PTR [ebx+0xbc]
  7a8859:	d9 ee                	fldz
  7a885b:	51                   	push   ecx
  7a885c:	8b f3                	mov    esi,ebx
  7a885e:	d9                   	.byte 0xd9
  7a885f:	1c                   	.byte 0x1c
```