# T08-094 — 上層資源調度、完成狀態消費與持有權轉移

- 研究者：`chatgpt-web roy`；台灣時間：`2026-10-27T10:42:42.995183+08:00`
- BIN：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（與交接一致）；`objdump -d -Mintel` 直接解 Windows PE32 `.text`，非推測編造反組譯。
- 基於 T08-093 已確認 `0x007BD8D0`、`resource+0x6C`、`0x007A86B0`，本段延伸至**其實際上游及持有者資源轉移**。
- 本筆記為完整本機原始技術記錄，未 commit，名稱/物件用途均屬暫定（除明確機器碼事實）。

## 一、最大的新證據：兩階段上層調度

`0x007A5DBA` 和 `0x007A5DD9` 是同一上層程式區塊內相鄰的直接呼叫：

```asm
007A5DA4 fld dword ptr [ebx+104h]
007A5DAB fmul dword ptr [ebp+0Ch]
007A5DB9 push ebx
007A5DBA call 007A86B0       ; active list 更新及完成資源回收
007A5DBF cmp dword ptr [ebx+0ACh], esi
007A5DC5 je 007A5DDE        ; 缺少 +AC 關聯時跳過下一階段
007A5DD8 push ebx
007A5DD9 call 007A87D0       ; 另一階段更新（有三個堆疊引數）
```

- **已確認**：`0x007A86B0` 和 `0x007A87D0` 並非相互呼叫，而是由**共同上游**依序調度。前者輸入的浮點數是 `manager+0x104 * [ebp+0x0C]`；後者另以 `[ebp+0x0C]` 及上游暫存的 float 傳入。`0x007A87D0` 函式末尾 `ret 0x0C`，符合三參數。
- **已確認**：這是資源管理系統的更新調度；尚無證據直接認定為場景 `object vtable+0x20` 主迴圈。
- 上游 `manager+0x124`、`+0x140` 被用來控制節流/更新分支：`+0x124` 為 0 且 `+0x140 <= 10` 時 `0x007A87D0` 可略過 `manager+0xAC vtable+0x20`，否則呼叫。

### 直接 E8 呼叫來源（BIN 逐 bytes 檢查）

| 目標 | 直接呼叫位址 | 意義 |
|---|---|---|
| `0x007A86B0` | `0x007A5DBA` | 更新活躍連結串列 |
| `0x007A87D0` | `0x007A5DD9` | 更新 manager 所屬 `+0x108`、上層狀態 |
| `0x007BDF00` | `0x007A8937` | 第二階段派送全部子項 `vtable+0x20` |
| `0x0075A6F0` | `0x007590DD`, `0x007A8DDA` | 指標對存入鏈表（見下） |

掃描採 `.text` FileOffset 0x400 / VA 0x00401000 的 E8 rel32 映射，存在落在資料/指令中間的理論上誤判可能，但上列均另經連續反組譯驗證。

## 二、`0x007A87D0` 詳細流程和新物件欄位

### 2.1 關聯物件 gate 與初次啟動

```asm
007A87E4 mov ecx,[ebx+0ACh]
007A87EC mov edx,[eax+2Ch]
007A87F1 call edx
007A87F3 test eax,eax
007A87F5 je 007A8872
007A87F7 cmp dword ptr [ebx+0B0h],0
007A8806 mov dword ptr [ebx+0B0h],1
007A8812 mov edx,[eax+0Ch]
007A8815 call edx
007A881D fst dword ptr [ebx+0B8h]
007A8861 call 007A6830
007A886D call 007A6830
```

- `manager+0xAC` 是**含 vtable 的關聯物件**，不等同前段 `resource` 或 `binding`。`vtable+0x2C` 的非零結果與 `manager+0xB0==0` 共同控制一次性初始化。
- 初次啟動時讀取 `+0xAC vtable+0x0C` 返回的浮點數寫入 `manager+0xB8`，依條件更新 `+0xC0/+0xC4/+0xBC`，用 `0x007A6830` 呼叫兩次，分別傳入 `0.0` 和第三個形參 float。`manager+0xB0=1` 是首次執行 guard；具體行為未命名為播放。

### 2.2 控制外部 +AC 關聯更新及 +108 resource

```asm
007A8872 cmp dword ptr [ebx+11Ch],0
007A8883 mov edx,[eax+38h] ; vtable gate
007A8890 cmp dword ptr [ebx+124h],0
007A8899 cmp dword ptr [ebx+140h],0Ah
007A88B0 mov eax,[eax+20h]
007A88B8 call eax           ; [manager+AC] vtable+20, NOT scene vtable+20
007A88BA cmp dword ptr [ebx+108h],0
007A88D7 fld dword ptr [ebp-24h]
007A88DA fstp dword ptr [eax+3Ch]
007A88E2 mov dword ptr [eax+70h],1
007A88F2 call edx          ; manager+04 vtable+08
007A88FC mov [ecx+28h],edx
007A8905 mov [ecx+30h],eax
007A890E fld dword ptr [ebx+104h]
007A8914 fmul dword ptr [ebp+0Ch]
007A8917 mov edi,[ebx+108h]
007A8927 call 007BD8D0
007A8937 call 007BDF00
```

- 這裡的 `+0x20` 虛擬方法來自 **manager+0xAC**，與場景 `object vtable+0x20` 是不同指標來源；不能因偏移相同而視為主場景迴圈！
- 若 `manager+0x108 != NULL`，就透過 manager 內嵌於 `+0x04` 的多型介面寫入 resource 的 `+0x3C`、`+0x28/+0x2C/+0x30` 並將 `+0x70=1`；再以 `+0x104 * 第二形參` 呼叫 `0x007BD8D0`，然後 `0x007BDF00(resource, manager+0x1C)` 派送全部子項 `binding vtable+0x20`。
- `resource+0x70=1` 的確切語意未確認，可能代表寫入結果有效/dirty；兩次相同立即寫入不代表具體動畫概念。

### 2.3 完成狀態被更高層**實際消費**：三條處理路徑

```asm
007A8CC9 mov [ebx+11Ch],esi
007A8CCF cmp dword ptr [ebx+11Ch],0
007A8D07 call [manager+AC vtable+38h]
007A8D11 mov eax,[ebx+108h]
007A8D1B call 007BE5B0         ; reset path
007A8D96 mov eax,[ebx+108h]
007A8DA6 cmp dword ptr [eax+6Ch],0
007A8DAC call 007BE5F0         ; completion path: resource detach/release
007A8DC4 mov [ebp-10h],eax    ; non-complete path
007A8DC7 mov eax,[ebx+120h]
007A8DDA call 0075A6F0         ; add pair to manager+10C list
007A8DDF mov dword ptr [ebx+108h],0
007A8DE9 mov dword ptr [ebx+120h],0
```

依 branch 可確認：

1. 在 `+0x11C` 設定且關聯物件 vtable `+0x38` 通過時，若 `+0x108` 非空，可能先呼叫 `0x007BE5B0` 重設它（另有 `manager+0x120` 的分支處理）。
2. `vtable+0x38` 未通過走到 `0x007A8D96`：若 `resource+0x6C != 0`，呼叫 `0x007BE5F0`，將完成的資源交還底層生命週期；**此處本函式不直接寫空 `+0x108`，`0x007BE5F0` 的指標副作用須另查**。
3. 若 `resource+0x6C == 0`，把 `(manager+0x108, manager+0x120)` 這對 DWORD 作為局部 pair，呼叫 `0x0075A6F0` 加入 `manager+0x10C` 串列，隨後把 `+0x108/+0x120` 明確置 NULL。**這是未完成資源由單一持有槽轉交 active list 的確證**。

`0x0075A6F0` 讀入局部 pair，呼叫 `0x00404FD0` 配置/插入鏈結節點，遞增 list 計數並連接 next/prev；不是資料庫操作也不是釋放 helper。`manager+0x10C` 在此為雙向串列基底，而前段 `0x007A86B0` 會走訪同一串列，形成**一個插入者＋一個消費者**的閉環。

### 2.4 累進的浮點狀態與 gate

- `manager+0xB4` 是在 `0x007A87D0` 分支中會浮點累進的值；`+0xB8`、`+0xBC`、`+0xC0` 是比較/界限來源。
- `+0xCC` 控制另一條混合式累進分支，使用 `+0xD0/+0xD4` 查表 `0x00FBAB8C`，更新 `+0xDC/+0xE0/+0xB4`，並在和 `+0xD8` 比較後清零 `+0xCC`。
- 在 `+0xCC==0` 分支，對 `+0xE0` 使用靜態浮點常數 `0x00C55848` 做分段運算；結果和 `+0xE4/+0xB4` 合成。可說**存在循環或分段累加**，但尚不能命名為動畫 duration/frame-rate。
- 條件比較會設定 `manager+0x11C`，影響前段的完成/重設/轉移處理。原函式內有兩塊類似累進流程（大致 `0x7A8959～0x7A8AE4` 與 `0x7A8B21～0x7A8CC9`），各 gate 不同，不能簡化成單一完全相同條件。

## 三、`0x007A6830` 新確認的 phase 歸零/重設路徑

```asm
007A685D fld dword ptr [ebp+08h]
007A6877 fld dword ptr [esi+0B8h]
007A6892 fstp dword ptr [esi+0B4h]
007A68EF mov eax,[esi+108h]
007A68F5 fldz
007A68F7 fstp dword ptr [eax+1Ch]   ; phase=0
007A68FA call 007BE5B0              ; resource reset
007A690D mov ecx,[esi+108h]
007A6913 fst dword ptr [ecx+1Ch]    ; phase=入參的經判斷版本
007A6923 call 007BE5B0              ; 特定分支 reset
```

- `0x007A6830` 在有 `manager+0x1C` 控制對象且 `manager+0x108` 資源存在時，能將資源 `+0x1C` 設為 0 或指定相位，必要時透過 `0x007BE5B0` 重設子項。
- `0x007D3BD0` 被用來處理 `manager+0x1C` 關聯，不應直接稱為資源重置本體；精確實作另待驗證。
- 這補強 `resource+0x1C` 是**可被 seek/歸零的 phase-like 欄位**，而非唯獨由 `0x007BD8D0` 累加。

## 四、目前仍未確認的 binding vtable 實作

- `0x007BDF00` 會依 `resource+0x04..+0x08` 遍歷子項，對 `item+0x08` binding 呼叫其 vtable `+0x20`，傳入 `manager+0x1C`；**該虛擬方法與 `0x007BDF40` 的 `+0x18` 是不同槽**。
- `0x007BDF40` gate `binding != NULL`、`item[0]==0`、`binding+0x80==0` 維持不變。尚未建立 binding 建構器 -> 常數 vtable -> `+0x18` 實際方法的可信完整鏈，不能杜撰 RVA 或名稱。
- `manager+0xAC` vtable `+0x20` 的存在也**不等於** `scene object vtable+0x20`，本段特別留意區分。

## 五、資料結構增量（暫定偏移表）

| 結構來源 | Offset | 已確認操作 | 保守解讀 |
|---|---:|---|---|
| manager（`ebx`） | `+0x04` | 獨立 vtable 實作，提供浮點與 3-vector | 管理器內嵌多型介面 |
| manager | `+0x1C` | 傳入 `0x007BDF00` / `+0xAC` 方法 | 外部關聯資料／控制物件，所有權未定 |
| manager | `+0x104` | float * delta | 局部更新倍率 |
| manager | `+0x108` | 資源指標，更新、重設、完成消費、轉移後清零 | 活動主資源單槽 |
| manager | `+0x10C` | `0x0075A6F0` 插入 pair | active 雙向串列管理頭 |
| manager | `+0x11C` | 條件式完成/轉移 gate | 操作階段旗標 |
| manager | `+0x120` | 與 `+0x108` 組成一對，轉入串列後清零 | 關聯指標 |
| manager | `+0x124/+0x140` | 更新頻率 gate | 調度節流/條件計數 |
| manager | `+0xAC` | 多型指標 `+0x04/+0x0C/+0x20/+0x2C/+0x38/+0x40` | 尚未定位型別 |
| manager | `+0xB4..+0xE4` | 多條浮點比較、查表、積分及設旗標路徑 | 相位/條件暫存；不猜名稱 |
| resource | `+0x1C` | 累加、顯式歸零/寫值 | phase-like |
| resource | `+0x6C` | 由 `0x007BD8D0` 設旗標、由 `0x007A8DA6` 消費 | 可結束資源狀態 |
| resource | `+0x70` | 更新前寫 1 | dirty/有效性候選，未確認 |

## 六、偽程式碼（非原始符號，簡化分支）

```cpp
void Manager::upper_tick(float delta, float param) {
  tick_active_list(this, this->rate_104 * delta);  // 0x7A86B0
  if (this->polymorphic_AC)
    tick_attached(this, delta, param);              // 0x7A87D0
}

void Manager::tick_attached(float delta, float other) {
  // initial gate: polymorphic_AC vfunc_2C() && !flag_B0
  // gated event/phase update and optional polymorphic_AC vfunc_20()
  if (this->resource_108) {
    this->resource_108->field_3C = this->interface_04.vfunc_10();
    this->interface_04.vfunc_08(&xyz);
    this->resource_108->field_28_30 = xyz;
    this->resource_108->field_70 = 1;
    update_resource(this->resource_108, this->rate_104 * delta);
    dispatch_children(this->resource_108, this->linked_1C);  // 0x7BDF00
  }
  // complex alternate branch: compare B4/B8/BC/C0; lookup and accumulate;
  // gate next action via +11C and polymorphic_AC vfunc_38.
  if (completion_handling_branch) {
    if (this->resource_108 && this->resource_108->flag_6C)
      detach_resource(this->resource_108);          // 0x7BE5F0
    else if (this->resource_108) {
      active_list_10C.push_back({resource_108, linked_120}); // 0x75A6F0
      this->resource_108 = nullptr;
      this->linked_120 = nullptr;
    }
  }
}
```

偽程式碼只保留已見到的資料流與分支類型；尤其 `completion_handling_branch` 包含 vtable `+0x38`、 `+0x11C` 的複數條件，不能簡化成所有完成資源必然直接釋放。

## 七、重要未知及 T08-095 建議

1. **binding vtable 實體仍未成功定位**；先由 `item+0x08` 的寫入與產生位置入手，再追 constructor 中常數 vtable 指標，最後才命名 `+0x18/+0x20`。
2. `binding+0x80` 寫入者仍未知，不可套用 `manager+0x80` 或其他結構同偏移。
3. `0x007A5DBA/0x007A5DD9` 共同上游所在函式的最外層呼叫者，與 `manager+0x04/+0xAC` 具體多型實作需繼續確認。
4. `0x007A8DDA` 插入 active list 的 `(resource, linked)` pair 可與 `0x007A86B0` 取節點 +0x08 的完整 layout 交叉還原，追查第二指標清理及所有權。
5. 真正場景管理器更新物件 `object vtable+0x20` 的調度者尚未定位，不能把本段 `manager+0xAC vtable+0x20` 誤認場景主迴圈。
6. `0x007A87D0` 的浮點查表 `0x00FBAB8C` 及 `0x00C55848` 常數語意未驗證；下一段可確認該表實際結構及界限。

## 八、Commit 狀態

本段僅產生本地 Markdown，**沒有執行 GitHub Commit**；前段交接所知 commit `088abbd338e95d85bc3beb4c979249f798aba153`，未聲稱即時查證遠端 HEAD。

## 附錄：上層呼叫點及近旁調度 (`0x007A5D70..0x007A5E30`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a5d70 <.text+0x3a4d70>:
  7a5d70:	24 e8                	and    al,0xe8
  7a5d72:	ea 2a 09 00 33 f6 eb 	jmp    0xebf6:0x3300092a
  7a5d79:	07                   	pop    es
  7a5d7a:	b8 01 00 00 00       	mov    eax,0x1
  7a5d7f:	8b f8                	mov    edi,eax
  7a5d81:	89 83 24 01 00 00    	mov    DWORD PTR [ebx+0x124],eax
  7a5d87:	3b c6                	cmp    eax,esi
  7a5d89:	74 08                	je     0x7a5d93
  7a5d8b:	89 b3 40 01 00 00    	mov    DWORD PTR [ebx+0x140],esi
  7a5d91:	eb 06                	jmp    0x7a5d99
  7a5d93:	01 bb 40 01 00 00    	add    DWORD PTR [ebx+0x140],edi
  7a5d99:	39 75 10             	cmp    DWORD PTR [ebp+0x10],esi
  7a5d9c:	74 06                	je     0x7a5da4
  7a5d9e:	89 bb 24 01 00 00    	mov    DWORD PTR [ebx+0x124],edi
  7a5da4:	d9 83 04 01 00 00    	fld    DWORD PTR [ebx+0x104]
  7a5daa:	51                   	push   ecx
  7a5dab:	d8 4d 0c             	fmul   DWORD PTR [ebp+0xc]
  7a5dae:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  7a5db2:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  7a5db6:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a5db9:	53                   	push   ebx
  7a5dba:	e8 f1 28 00 00       	call   0x7a86b0
  7a5dbf:	39 b3 ac 00 00 00    	cmp    DWORD PTR [ebx+0xac],esi
  7a5dc5:	74 17                	je     0x7a5dde
  7a5dc7:	d9 44 24 2c          	fld    DWORD PTR [esp+0x2c]
  7a5dcb:	83 ec 08             	sub    esp,0x8
  7a5dce:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7a5dd2:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  7a5dd5:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a5dd8:	53                   	push   ebx
  7a5dd9:	e8 f2 29 00 00       	call   0x7a87d0
  7a5dde:	d9 ee                	fldz
  7a5de0:	39 b3 24 01 00 00    	cmp    DWORD PTR [ebx+0x124],esi
  7a5de6:	75 0d                	jne    0x7a5df5
  7a5de8:	83 bb 40 01 00 00 0a 	cmp    DWORD PTR [ebx+0x140],0xa
  7a5def:	0f 86 b6 00 00 00    	jbe    0x7a5eab
  7a5df5:	39 b3 00 01 00 00    	cmp    DWORD PTR [ebx+0x100],esi
  7a5dfb:	0f 84 97 00 00 00    	je     0x7a5e98
  7a5e01:	8b 43 1c             	mov    eax,DWORD PTR [ebx+0x1c]
  7a5e04:	8b 93 ec 00 00 00    	mov    edx,DWORD PTR [ebx+0xec]
  7a5e0a:	89 50 28             	mov    DWORD PTR [eax+0x28],edx
  7a5e0d:	8b 8b f0 00 00 00    	mov    ecx,DWORD PTR [ebx+0xf0]
  7a5e13:	89 48 2c             	mov    DWORD PTR [eax+0x2c],ecx
  7a5e16:	8b 93 f4 00 00 00    	mov    edx,DWORD PTR [ebx+0xf4]
  7a5e1c:	89 50 30             	mov    DWORD PTR [eax+0x30],edx
  7a5e1f:	8b 8b ec 00 00 00    	mov    ecx,DWORD PTR [ebx+0xec]
  7a5e25:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  7a5e28:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx
  7a5e2b:	8b                   	.byte 0x8b
  7a5e2c:	93                   	xchg   ebx,eax
  7a5e2d:	f0 00 00             	lock add BYTE PTR [eax],al

```

## 附錄：活躍更新的第二階段 (`0x007A87D0..0x007A8E06`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a87d0 <.text+0x3a77d0>:
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
  7a885e:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a8861:	e8 ca df ff ff       	call   0x7a6830
  7a8866:	d9 45 10             	fld    DWORD PTR [ebp+0x10]
  7a8869:	51                   	push   ecx
  7a886a:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a886d:	e8 be df ff ff       	call   0x7a6830
  7a8872:	83 bb 1c 01 00 00 00 	cmp    DWORD PTR [ebx+0x11c],0x0
  7a8879:	74 15                	je     0x7a8890
  7a887b:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8881:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a8883:	8b 50 38             	mov    edx,DWORD PTR [eax+0x38]
  7a8886:	ff d2                	call   edx
  7a8888:	85 c0                	test   eax,eax
  7a888a:	0f 84 63 05 00 00    	je     0x7a8df3
  7a8890:	83 bb 24 01 00 00 00 	cmp    DWORD PTR [ebx+0x124],0x0
  7a8897:	75 09                	jne    0x7a88a2
  7a8899:	83 bb 40 01 00 00 0a 	cmp    DWORD PTR [ebx+0x140],0xa
  7a88a0:	76 18                	jbe    0x7a88ba
  7a88a2:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a88a8:	d9 45 10             	fld    DWORD PTR [ebp+0x10]
  7a88ab:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a88ad:	8b 53 1c             	mov    edx,DWORD PTR [ebx+0x1c]
  7a88b0:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  7a88b3:	51                   	push   ecx
  7a88b4:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a88b7:	52                   	push   edx
  7a88b8:	ff d0                	call   eax
  7a88ba:	83 bb 08 01 00 00 00 	cmp    DWORD PTR [ebx+0x108],0x0
  7a88c1:	74 79                	je     0x7a893c
  7a88c3:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7a88c6:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  7a88c9:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7a88cc:	ff d0                	call   eax
  7a88ce:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a88d1:	8b 83 08 01 00 00    	mov    eax,DWORD PTR [ebx+0x108]
  7a88d7:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a88da:	d9 58 3c             	fstp   DWORD PTR [eax+0x3c]
  7a88dd:	be 01 00 00 00       	mov    esi,0x1
  7a88e2:	89 70 70             	mov    DWORD PTR [eax+0x70],esi
  7a88e5:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7a88e8:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  7a88eb:	8d 45 ec             	lea    eax,[ebp-0x14]
  7a88ee:	50                   	push   eax
  7a88ef:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7a88f2:	ff d2                	call   edx
  7a88f4:	8b 10                	mov    edx,DWORD PTR [eax]
  7a88f6:	8b 8b 08 01 00 00    	mov    ecx,DWORD PTR [ebx+0x108]
  7a88fc:	89 51 28             	mov    DWORD PTR [ecx+0x28],edx
  7a88ff:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a8902:	89 51 2c             	mov    DWORD PTR [ecx+0x2c],edx
  7a8905:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  7a8908:	89 41 30             	mov    DWORD PTR [ecx+0x30],eax
  7a890b:	89 71 70             	mov    DWORD PTR [ecx+0x70],esi
  7a890e:	d9 83 04 01 00 00    	fld    DWORD PTR [ebx+0x104]
  7a8914:	d8 4d 0c             	fmul   DWORD PTR [ebp+0xc]
  7a8917:	8b bb 08 01 00 00    	mov    edi,DWORD PTR [ebx+0x108]
  7a891d:	51                   	push   ecx
  7a891e:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a8921:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a8924:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a8927:	e8 a4 4f 01 00       	call   0x7bd8d0
  7a892c:	8b 4b 1c             	mov    ecx,DWORD PTR [ebx+0x1c]
  7a892f:	8b 93 08 01 00 00    	mov    edx,DWORD PTR [ebx+0x108]
  7a8935:	51                   	push   ecx
  7a8936:	52                   	push   edx
  7a8937:	e8 c4 55 01 00       	call   0x7bdf00
  7a893c:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8942:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a8944:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a8947:	ff d2                	call   edx
  7a8949:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a894f:	85 c0                	test   eax,eax
  7a8951:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a8953:	0f 85 90 01 00 00    	jne    0x7a8ae9
  7a8959:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7a895c:	ff d2                	call   edx
  7a895e:	d9 83 04 01 00 00    	fld    DWORD PTR [ebx+0x104]
  7a8964:	d8 4d 0c             	fmul   DWORD PTR [ebp+0xc]
  7a8967:	de c9                	fmulp  st(1),st
  7a8969:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a896c:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8972:	d9 83 c0 00 00 00    	fld    DWORD PTR [ebx+0xc0]
  7a8978:	de d9                	fcompp
  7a897a:	df e0                	fnstsw ax
  7a897c:	f6 c4 41             	test   ah,0x41
  7a897f:	75 07                	jne    0x7a8988
  7a8981:	b9 01 00 00 00       	mov    ecx,0x1
  7a8986:	eb 02                	jmp    0x7a898a
  7a8988:	33 c9                	xor    ecx,ecx
  7a898a:	33 ff                	xor    edi,edi
  7a898c:	33 f6                	xor    esi,esi
  7a898e:	c7 83 e8 00 00 00 01 	mov    DWORD PTR [ebx+0xe8],0x1
  7a8995:	00 00 00 
  7a8998:	39 bb cc 00 00 00    	cmp    DWORD PTR [ebx+0xcc],edi
  7a899e:	0f 84 80 00 00 00    	je     0x7a8a24
  7a89a4:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a89a7:	8b 83 d0 00 00 00    	mov    eax,DWORD PTR [ebx+0xd0]
  7a89ad:	8b 93 d4 00 00 00    	mov    edx,DWORD PTR [ebx+0xd4]
  7a89b3:	d9 c0                	fld    st(0)
  7a89b5:	d8 83 dc 00 00 00    	fadd   DWORD PTR [ebx+0xdc]
  7a89bb:	8d 04 40             	lea    eax,[eax+eax*2]
  7a89be:	8d 04 42             	lea    eax,[edx+eax*2]
  7a89c1:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a89c4:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a89c7:	d9 93 dc 00 00 00    	fst    DWORD PTR [ebx+0xdc]
  7a89cd:	d9 04 85 8c ab fb 00 	fld    DWORD PTR [eax*4+0xfbab8c]
  7a89d4:	d9 e8                	fld1
  7a89d6:	de e1                	fsubrp st(1),st
  7a89d8:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a89db:	d9 c1                	fld    st(1)
  7a89dd:	d8 0c 85 8c ab fb 00 	fmul   DWORD PTR [eax*4+0xfbab8c]
  7a89e4:	d8 83 e0 00 00 00    	fadd   DWORD PTR [ebx+0xe0]
  7a89ea:	d9 9b e0 00 00 00    	fstp   DWORD PTR [ebx+0xe0]
  7a89f0:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a89f3:	de ca                	fmulp  st(2),st
  7a89f5:	d9 83 e4 00 00 00    	fld    DWORD PTR [ebx+0xe4]
  7a89fb:	de ca                	fmulp  st(2),st
  7a89fd:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8a03:	de c2                	faddp  st(2),st
  7a8a05:	d9 c9                	fxch   st(1)
  7a8a07:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8a0d:	d9 83 d8 00 00 00    	fld    DWORD PTR [ebx+0xd8]
  7a8a13:	de d9                	fcompp
  7a8a15:	df e0                	fnstsw ax
  7a8a17:	f6 c4 41             	test   ah,0x41
  7a8a1a:	7a 41                	jp     0x7a8a5d
  7a8a1c:	89 bb cc 00 00 00    	mov    DWORD PTR [ebx+0xcc],edi
  7a8a22:	eb 39                	jmp    0x7a8a5d
  7a8a24:	d9 83 e0 00 00 00    	fld    DWORD PTR [ebx+0xe0]
  7a8a2a:	dc 35 48 58 c5 00    	fdiv   QWORD PTR ds:0xc55848
  7a8a30:	d9 5d f4             	fstp   DWORD PTR [ebp-0xc]
  7a8a33:	d9 83 e0 00 00 00    	fld    DWORD PTR [ebx+0xe0]
  7a8a39:	d9 45 f4             	fld    DWORD PTR [ebp-0xc]
  7a8a3c:	d9 c0                	fld    st(0)
  7a8a3e:	de ea                	fsubp  st(2),st
  7a8a40:	d9 c9                	fxch   st(1)
  7a8a42:	d9 9b e0 00 00 00    	fstp   DWORD PTR [ebx+0xe0]
  7a8a48:	d8 45 dc             	fadd   DWORD PTR [ebp-0x24]
  7a8a4b:	d8 8b e4 00 00 00    	fmul   DWORD PTR [ebx+0xe4]
  7a8a51:	d8 83 b4 00 00 00    	fadd   DWORD PTR [ebx+0xb4]
  7a8a57:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8a5d:	39 bb c4 00 00 00    	cmp    DWORD PTR [ebx+0xc4],edi
  7a8a63:	74 2b                	je     0x7a8a90
  7a8a65:	3b cf                	cmp    ecx,edi
  7a8a67:	74 27                	je     0x7a8a90
  7a8a69:	d9 83 c0 00 00 00    	fld    DWORD PTR [ebx+0xc0]
  7a8a6f:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8a75:	de d9                	fcompp
  7a8a77:	df e0                	fnstsw ax
  7a8a79:	f6 c4 41             	test   ah,0x41
  7a8a7c:	7a 12                	jp     0x7a8a90
  7a8a7e:	e8 1a 9e 0e 00       	call   0x89289d
  7a8a83:	39 83 c4 00 00 00    	cmp    DWORD PTR [ebx+0xc4],eax
  7a8a89:	7d 05                	jge    0x7a8a90
  7a8a8b:	be 01 00 00 00       	mov    esi,0x1
  7a8a90:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8a96:	d9 83 b8 00 00 00    	fld    DWORD PTR [ebx+0xb8]
  7a8a9c:	de d9                	fcompp
  7a8a9e:	df e0                	fnstsw ax
  7a8aa0:	d9 ee                	fldz
  7a8aa2:	f6 c4 05             	test   ah,0x5
  7a8aa5:	7a 07                	jp     0x7a8aae
  7a8aa7:	be 01 00 00 00       	mov    esi,0x1
  7a8aac:	eb 1c                	jmp    0x7a8aca
  7a8aae:	d8 93 b4 00 00 00    	fcom   DWORD PTR [ebx+0xb4]
  7a8ab4:	df e0                	fnstsw ax
  7a8ab6:	f6 c4 41             	test   ah,0x41
  7a8ab9:	75 07                	jne    0x7a8ac2
  7a8abb:	be 01 00 00 00       	mov    esi,0x1
  7a8ac0:	eb 08                	jmp    0x7a8aca
  7a8ac2:	3b f7                	cmp    esi,edi
  7a8ac4:	0f 84 fd 01 00 00    	je     0x7a8cc7
  7a8aca:	39 bb c8 00 00 00    	cmp    DWORD PTR [ebx+0xc8],edi
  7a8ad0:	0f 85 bb 01 00 00    	jne    0x7a8c91
  7a8ad6:	dd d8                	fstp   st(0)
  7a8ad8:	d9 83 b8 00 00 00    	fld    DWORD PTR [ebx+0xb8]
  7a8ade:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8ae4:	e9 e0 01 00 00       	jmp    0x7a8cc9
  7a8ae9:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a8aec:	ff d2                	call   edx
  7a8aee:	83 f8 01             	cmp    eax,0x1
  7a8af1:	0f 85 d8 01 00 00    	jne    0x7a8ccf
  7a8af7:	8b bb ac 00 00 00    	mov    edi,DWORD PTR [ebx+0xac]
  7a8afd:	8b 07                	mov    eax,DWORD PTR [edi]
  7a8aff:	8b 50 40             	mov    edx,DWORD PTR [eax+0x40]
  7a8b02:	8b cf                	mov    ecx,edi
  7a8b04:	ff d2                	call   edx
  7a8b06:	8b 88 a8 00 00 00    	mov    ecx,DWORD PTR [eax+0xa8]
  7a8b0c:	3b 88 ac 00 00 00    	cmp    ecx,DWORD PTR [eax+0xac]
  7a8b12:	0f 84 b7 01 00 00    	je     0x7a8ccf
  7a8b18:	8b 17                	mov    edx,DWORD PTR [edi]
  7a8b1a:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  7a8b1d:	8b cf                	mov    ecx,edi
  7a8b1f:	ff d0                	call   eax
  7a8b21:	d9 83 04 01 00 00    	fld    DWORD PTR [ebx+0x104]
  7a8b27:	d8 4d 0c             	fmul   DWORD PTR [ebp+0xc]
  7a8b2a:	de c9                	fmulp  st(1),st
  7a8b2c:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
  7a8b2f:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8b35:	d9 83 c0 00 00 00    	fld    DWORD PTR [ebx+0xc0]
  7a8b3b:	de d9                	fcompp
  7a8b3d:	df e0                	fnstsw ax
  7a8b3f:	f6 c4 41             	test   ah,0x41
  7a8b42:	75 07                	jne    0x7a8b4b
  7a8b44:	b9 01 00 00 00       	mov    ecx,0x1
  7a8b49:	eb 02                	jmp    0x7a8b4d
  7a8b4b:	33 c9                	xor    ecx,ecx
  7a8b4d:	33 ff                	xor    edi,edi
  7a8b4f:	33 f6                	xor    esi,esi
  7a8b51:	c7 83 e8 00 00 00 01 	mov    DWORD PTR [ebx+0xe8],0x1
  7a8b58:	00 00 00 
  7a8b5b:	39 bb cc 00 00 00    	cmp    DWORD PTR [ebx+0xcc],edi
  7a8b61:	0f 84 80 00 00 00    	je     0x7a8be7
  7a8b67:	d9 45 dc             	fld    DWORD PTR [ebp-0x24]
  7a8b6a:	8b 83 d0 00 00 00    	mov    eax,DWORD PTR [ebx+0xd0]
  7a8b70:	d9 c0                	fld    st(0)
  7a8b72:	8d 14 40             	lea    edx,[eax+eax*2]
  7a8b75:	d8 83 dc 00 00 00    	fadd   DWORD PTR [ebx+0xdc]
  7a8b7b:	8b 83 d4 00 00 00    	mov    eax,DWORD PTR [ebx+0xd4]
  7a8b81:	8d 04 50             	lea    eax,[eax+edx*2]
  7a8b84:	d9 5d f4             	fstp   DWORD PTR [ebp-0xc]
  7a8b87:	d9 45 f4             	fld    DWORD PTR [ebp-0xc]
  7a8b8a:	d9 93 dc 00 00 00    	fst    DWORD PTR [ebx+0xdc]
  7a8b90:	d9 04 85 8c ab fb 00 	fld    DWORD PTR [eax*4+0xfbab8c]
  7a8b97:	d9 e8                	fld1
  7a8b99:	de e1                	fsubrp st(1),st
  7a8b9b:	d9 5d f4             	fstp   DWORD PTR [ebp-0xc]
  7a8b9e:	d9 04 85 8c ab fb 00 	fld    DWORD PTR [eax*4+0xfbab8c]
  7a8ba5:	d8 ca                	fmul   st,st(2)
  7a8ba7:	d8 83 e0 00 00 00    	fadd   DWORD PTR [ebx+0xe0]
  7a8bad:	d9 9b e0 00 00 00    	fstp   DWORD PTR [ebx+0xe0]
  7a8bb3:	d9 45 f4             	fld    DWORD PTR [ebp-0xc]
  7a8bb6:	de ca                	fmulp  st(2),st
  7a8bb8:	d9 83 e4 00 00 00    	fld    DWORD PTR [ebx+0xe4]
  7a8bbe:	de ca                	fmulp  st(2),st
  7a8bc0:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8bc6:	de c2                	faddp  st(2),st
  7a8bc8:	d9 c9                	fxch   st(1)
  7a8bca:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8bd0:	d9 83 d8 00 00 00    	fld    DWORD PTR [ebx+0xd8]
  7a8bd6:	de d9                	fcompp
  7a8bd8:	df e0                	fnstsw ax
  7a8bda:	f6 c4 41             	test   ah,0x41
  7a8bdd:	7a 41                	jp     0x7a8c20
  7a8bdf:	89 bb cc 00 00 00    	mov    DWORD PTR [ebx+0xcc],edi
  7a8be5:	eb 39                	jmp    0x7a8c20
  7a8be7:	d9 83 e0 00 00 00    	fld    DWORD PTR [ebx+0xe0]
  7a8bed:	dc 35 48 58 c5 00    	fdiv   QWORD PTR ds:0xc55848
  7a8bf3:	d9 5d f4             	fstp   DWORD PTR [ebp-0xc]
  7a8bf6:	d9 83 e0 00 00 00    	fld    DWORD PTR [ebx+0xe0]
  7a8bfc:	d9 45 f4             	fld    DWORD PTR [ebp-0xc]
  7a8bff:	d9 c0                	fld    st(0)
  7a8c01:	de ea                	fsubp  st(2),st
  7a8c03:	d9 c9                	fxch   st(1)
  7a8c05:	d9 9b e0 00 00 00    	fstp   DWORD PTR [ebx+0xe0]
  7a8c0b:	d8 45 dc             	fadd   DWORD PTR [ebp-0x24]
  7a8c0e:	d8 8b e4 00 00 00    	fmul   DWORD PTR [ebx+0xe4]
  7a8c14:	d8 83 b4 00 00 00    	fadd   DWORD PTR [ebx+0xb4]
  7a8c1a:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8c20:	39 bb c4 00 00 00    	cmp    DWORD PTR [ebx+0xc4],edi
  7a8c26:	74 2b                	je     0x7a8c53
  7a8c28:	3b cf                	cmp    ecx,edi
  7a8c2a:	74 27                	je     0x7a8c53
  7a8c2c:	d9 83 c0 00 00 00    	fld    DWORD PTR [ebx+0xc0]
  7a8c32:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8c38:	de d9                	fcompp
  7a8c3a:	df e0                	fnstsw ax
  7a8c3c:	f6 c4 41             	test   ah,0x41
  7a8c3f:	7a 12                	jp     0x7a8c53
  7a8c41:	e8 57 9c 0e 00       	call   0x89289d
  7a8c46:	39 83 c4 00 00 00    	cmp    DWORD PTR [ebx+0xc4],eax
  7a8c4c:	7d 05                	jge    0x7a8c53
  7a8c4e:	be 01 00 00 00       	mov    esi,0x1
  7a8c53:	d9 83 b4 00 00 00    	fld    DWORD PTR [ebx+0xb4]
  7a8c59:	d9 83 b8 00 00 00    	fld    DWORD PTR [ebx+0xb8]
  7a8c5f:	de d9                	fcompp
  7a8c61:	df e0                	fnstsw ax
  7a8c63:	d9 ee                	fldz
  7a8c65:	f6 c4 05             	test   ah,0x5
  7a8c68:	7a 07                	jp     0x7a8c71
  7a8c6a:	be 01 00 00 00       	mov    esi,0x1
  7a8c6f:	eb 18                	jmp    0x7a8c89
  7a8c71:	d8 93 b4 00 00 00    	fcom   DWORD PTR [ebx+0xb4]
  7a8c77:	df e0                	fnstsw ax
  7a8c79:	f6 c4 41             	test   ah,0x41
  7a8c7c:	75 07                	jne    0x7a8c85
  7a8c7e:	be 01 00 00 00       	mov    esi,0x1
  7a8c83:	eb 04                	jmp    0x7a8c89
  7a8c85:	3b f7                	cmp    esi,edi
  7a8c87:	74 3e                	je     0x7a8cc7
  7a8c89:	39 bb c8 00 00 00    	cmp    DWORD PTR [ebx+0xc8],edi
  7a8c8f:	74 26                	je     0x7a8cb7
  7a8c91:	89 bb cc 00 00 00    	mov    DWORD PTR [ebx+0xcc],edi
  7a8c97:	d9 93 e0 00 00 00    	fst    DWORD PTR [ebx+0xe0]
  7a8c9d:	d9 93 d8 00 00 00    	fst    DWORD PTR [ebx+0xd8]
  7a8ca3:	d9 9b dc 00 00 00    	fstp   DWORD PTR [ebx+0xdc]
  7a8ca9:	d9 83 bc 00 00 00    	fld    DWORD PTR [ebx+0xbc]
  7a8caf:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8cb5:	eb 12                	jmp    0x7a8cc9
  7a8cb7:	dd d8                	fstp   st(0)
  7a8cb9:	d9 83 b8 00 00 00    	fld    DWORD PTR [ebx+0xb8]
  7a8cbf:	d9 9b b4 00 00 00    	fstp   DWORD PTR [ebx+0xb4]
  7a8cc5:	eb 02                	jmp    0x7a8cc9
  7a8cc7:	dd d8                	fstp   st(0)
  7a8cc9:	89 b3 1c 01 00 00    	mov    DWORD PTR [ebx+0x11c],esi
  7a8ccf:	83 bb 1c 01 00 00 00 	cmp    DWORD PTR [ebx+0x11c],0x0
  7a8cd6:	0f 84 17 01 00 00    	je     0x7a8df3
  7a8cdc:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8ce2:	8b 39                	mov    edi,DWORD PTR [ecx]
  7a8ce4:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  7a8ce7:	ff d2                	call   edx
  7a8ce9:	8b 43 1c             	mov    eax,DWORD PTR [ebx+0x1c]
  7a8cec:	8b 57 20             	mov    edx,DWORD PTR [edi+0x20]
  7a8cef:	51                   	push   ecx
  7a8cf0:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8cf6:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a8cf9:	50                   	push   eax
  7a8cfa:	ff d2                	call   edx
  7a8cfc:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8d02:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a8d04:	8b 50 38             	mov    edx,DWORD PTR [eax+0x38]
  7a8d07:	ff d2                	call   edx
  7a8d09:	85 c0                	test   eax,eax
  7a8d0b:	0f 84 85 00 00 00    	je     0x7a8d96
  7a8d11:	8b 83 08 01 00 00    	mov    eax,DWORD PTR [ebx+0x108]
  7a8d17:	85 c0                	test   eax,eax
  7a8d19:	74 05                	je     0x7a8d20
  7a8d1b:	e8 90 58 01 00       	call   0x7be5b0
  7a8d20:	83 bb 20 01 00 00 00 	cmp    DWORD PTR [ebx+0x120],0x0
  7a8d27:	0f 84 c6 00 00 00    	je     0x7a8df3
  7a8d2d:	8b 8b ac 00 00 00    	mov    ecx,DWORD PTR [ebx+0xac]
  7a8d33:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a8d35:	8b 50 1c             	mov    edx,DWORD PTR [eax+0x1c]
  7a8d38:	ff d2                	call   edx
  7a8d3a:	85 c0                	test   eax,eax
  7a8d3c:	0f 85 b1 00 00 00    	jne    0x7a8df3
  7a8d42:	50                   	push   eax
  7a8d43:	8d 45 ec             	lea    eax,[ebp-0x14]
  7a8d46:	50                   	push   eax
  7a8d47:	8b fb                	mov    edi,ebx
  7a8d49:	e8 e2 ed ff ff       	call   0x7a7b30
  7a8d4e:	85 c0                	test   eax,eax
  7a8d50:	75 20                	jne    0x7a8d72
  7a8d52:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7a8d55:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  7a8d58:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7a8d5b:	8d 45 e0             	lea    eax,[ebp-0x20]
  7a8d5e:	50                   	push   eax
  7a8d5f:	ff d2                	call   edx
  7a8d61:	8b 08                	mov    ecx,DWORD PTR [eax]
  7a8d63:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  7a8d66:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a8d69:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  7a8d6c:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  7a8d6f:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  7a8d72:	8b 8b 20 01 00 00    	mov    ecx,DWORD PTR [ebx+0x120]
  7a8d78:	8b 11                	mov    edx,DWORD PTR [ecx]
  7a8d7a:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  7a8d7d:	8d 45 ec             	lea    eax,[ebp-0x14]
  7a8d80:	50                   	push   eax
  7a8d81:	ff d2                	call   edx
  7a8d83:	5f                   	pop    edi
  7a8d84:	5e                   	pop    esi
  7a8d85:	5b                   	pop    ebx
  7a8d86:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7a8d89:	33 cd                	xor    ecx,ebp
  7a8d8b:	e8 71 82 0e 00       	call   0x891001
  7a8d90:	8b e5                	mov    esp,ebp
  7a8d92:	5d                   	pop    ebp
  7a8d93:	c2 0c 00             	ret    0xc
  7a8d96:	8b 83 08 01 00 00    	mov    eax,DWORD PTR [ebx+0x108]
  7a8d9c:	8d b3 08 01 00 00    	lea    esi,[ebx+0x108]
  7a8da2:	85 c0                	test   eax,eax
  7a8da4:	74 4d                	je     0x7a8df3
  7a8da6:	83 78 6c 00          	cmp    DWORD PTR [eax+0x6c],0x0
  7a8daa:	74 18                	je     0x7a8dc4
  7a8dac:	e8 3f 58 01 00       	call   0x7be5f0
  7a8db1:	5f                   	pop    edi
  7a8db2:	5e                   	pop    esi
  7a8db3:	5b                   	pop    ebx
  7a8db4:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7a8db7:	33 cd                	xor    ecx,ebp
  7a8db9:	e8 43 82 0e 00       	call   0x891001
  7a8dbe:	8b e5                	mov    esp,ebp
  7a8dc0:	5d                   	pop    ebp
  7a8dc1:	c2 0c 00             	ret    0xc
  7a8dc4:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7a8dc7:	8b 83 20 01 00 00    	mov    eax,DWORD PTR [ebx+0x120]
  7a8dcd:	8d 8b 0c 01 00 00    	lea    ecx,[ebx+0x10c]
  7a8dd3:	51                   	push   ecx
  7a8dd4:	8d 75 f0             	lea    esi,[ebp-0x10]
  7a8dd7:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  7a8dda:	e8 11 19 fb ff       	call   0x75a6f0
  7a8ddf:	c7 83 08 01 00 00 00 	mov    DWORD PTR [ebx+0x108],0x0
  7a8de6:	00 00 00 
  7a8de9:	c7 83 20 01 00 00 00 	mov    DWORD PTR [ebx+0x120],0x0
  7a8df0:	00 00 00 
  7a8df3:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7a8df6:	5f                   	pop    edi
  7a8df7:	5e                   	pop    esi
  7a8df8:	33 cd                	xor    ecx,ebp
  7a8dfa:	5b                   	pop    ebx
  7a8dfb:	e8 01 82 0e 00       	call   0x891001
  7a8e00:	8b e5                	mov    esp,ebp
  7a8e02:	5d                   	pop    ebp
  7a8e03:	c2 0c 00             	ret    0xc

```

## 附錄：重設與 phase 寫入 (`0x007A6830..0x007A6960`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a6830 <.text+0x3a5830>:
  7a6830:	55                   	push   ebp
  7a6831:	8b ec                	mov    ebp,esp
  7a6833:	6a ff                	push   0xffffffff
  7a6835:	68 55 a1 90 00       	push   0x90a155
  7a683a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7a6840:	50                   	push   eax
  7a6841:	51                   	push   ecx
  7a6842:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a6847:	33 c5                	xor    eax,ebp
  7a6849:	50                   	push   eax
  7a684a:	8d 45 f4             	lea    eax,[ebp-0xc]
  7a684d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7a6853:	b8 0c f6 c4 00       	mov    eax,0xc4f60c
  7a6858:	e8 53 18 09 00       	call   0x8380b0
  7a685d:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7a6860:	d9 55 f0             	fst    DWORD PTR [ebp-0x10]
  7a6863:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7a686a:	d9 ee                	fldz
  7a686c:	d8 d1                	fcom   st(1)
  7a686e:	df e0                	fnstsw ax
  7a6870:	f6 c4 41             	test   ah,0x41
  7a6873:	74 17                	je     0x7a688c
  7a6875:	dd d8                	fstp   st(0)
  7a6877:	d9 86 b8 00 00 00    	fld    DWORD PTR [esi+0xb8]
  7a687d:	d8 d9                	fcomp  st(1)
  7a687f:	df e0                	fnstsw ax
  7a6881:	f6 c4 05             	test   ah,0x5
  7a6884:	7a 09                	jp     0x7a688f
  7a6886:	d9 86 b8 00 00 00    	fld    DWORD PTR [esi+0xb8]
  7a688c:	d9 5d f0             	fstp   DWORD PTR [ebp-0x10]
  7a688f:	d9 45 f0             	fld    DWORD PTR [ebp-0x10]
  7a6892:	d9 9e b4 00 00 00    	fstp   DWORD PTR [esi+0xb4]
  7a6898:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  7a689b:	85 c0                	test   eax,eax
  7a689d:	0f 84 9d 00 00 00    	je     0x7a6940
  7a68a3:	83 be ac 00 00 00 00 	cmp    DWORD PTR [esi+0xac],0x0
  7a68aa:	74 1d                	je     0x7a68c9
  7a68ac:	8b 8e ac 00 00 00    	mov    ecx,DWORD PTR [esi+0xac]
  7a68b2:	dd d8                	fstp   st(0)
  7a68b4:	d9 86 b4 00 00 00    	fld    DWORD PTR [esi+0xb4]
  7a68ba:	8b 11                	mov    edx,DWORD PTR [ecx]
  7a68bc:	51                   	push   ecx
  7a68bd:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a68c0:	50                   	push   eax
  7a68c1:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  7a68c4:	ff d0                	call   eax
  7a68c6:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7a68c9:	83 be 08 01 00 00 00 	cmp    DWORD PTR [esi+0x108],0x0
  7a68d0:	74 61                	je     0x7a6933
  7a68d2:	83 be ac 00 00 00 00 	cmp    DWORD PTR [esi+0xac],0x0
  7a68d9:	74 32                	je     0x7a690d
  7a68db:	8b 8e ac 00 00 00    	mov    ecx,DWORD PTR [esi+0xac]
  7a68e1:	dd d8                	fstp   st(0)
  7a68e3:	8b 11                	mov    edx,DWORD PTR [ecx]
  7a68e5:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7a68e8:	ff d0                	call   eax
  7a68ea:	83 f8 01             	cmp    eax,0x1
  7a68ed:	75 1b                	jne    0x7a690a
  7a68ef:	8b 86 08 01 00 00    	mov    eax,DWORD PTR [esi+0x108]
  7a68f5:	d9 ee                	fldz
  7a68f7:	d9 58 1c             	fstp   DWORD PTR [eax+0x1c]
  7a68fa:	e8 b1 7c 01 00       	call   0x7be5b0
  7a68ff:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
  7a6902:	51                   	push   ecx
  7a6903:	e8 c8 d2 02 00       	call   0x7d3bd0
  7a6908:	eb 38                	jmp    0x7a6942
  7a690a:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7a690d:	8b 8e 08 01 00 00    	mov    ecx,DWORD PTR [esi+0x108]
  7a6913:	d9 51 1c             	fst    DWORD PTR [ecx+0x1c]
  7a6916:	d9 ee                	fldz
  7a6918:	da e9                	fucompp
  7a691a:	df e0                	fnstsw ax
  7a691c:	f6 c4 44             	test   ah,0x44
  7a691f:	7a 14                	jp     0x7a6935
  7a6921:	8b c1                	mov    eax,ecx
  7a6923:	e8 88 7c 01 00       	call   0x7be5b0
  7a6928:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
  7a692b:	51                   	push   ecx
  7a692c:	e8 9f d2 02 00       	call   0x7d3bd0
  7a6931:	eb 0f                	jmp    0x7a6942
  7a6933:	dd d8                	fstp   st(0)
  7a6935:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
  7a6938:	51                   	push   ecx
  7a6939:	e8 92 d2 02 00       	call   0x7d3bd0
  7a693e:	eb 02                	jmp    0x7a6942
  7a6940:	dd d8                	fstp   st(0)
  7a6942:	e8 89 16 09 00       	call   0x837fd0
  7a6947:	8b 15 fc 39 d6 00    	mov    edx,DWORD PTR ds:0xd639fc
  7a694d:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7a6950:	a3 fc 39 d6 00       	mov    ds:0xd639fc,eax
  7a6955:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7a6958:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7a695f:	59                   	pop    ecx

```

## 附錄：資源子項派送 (`0x007BDF00..0x007BDF90`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf00 <.text+0x3bcf00>:
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

```

## 附錄：延後清單 push helper (`0x0075A6F0..0x0075A730`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0075a6f0 <.text+0x3596f0>:
  75a6f0:	55                   	push   ebp
  75a6f1:	8b ec                	mov    ebp,esp
  75a6f3:	53                   	push   ebx
  75a6f4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  75a6f7:	57                   	push   edi
  75a6f8:	8b 3b                	mov    edi,DWORD PTR [ebx]
  75a6fa:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  75a6fd:	50                   	push   eax
  75a6fe:	57                   	push   edi
  75a6ff:	e8 cc a8 ca ff       	call   0x404fd0
  75a704:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  75a707:	ba fe ff ff 1f       	mov    edx,0x1ffffffe
  75a70c:	2b d1                	sub    edx,ecx
  75a70e:	83 fa 01             	cmp    edx,0x1
  75a711:	73 0a                	jae    0x75a71d
  75a713:	68 34 20 bf 00       	push   0xbf2034
  75a718:	e8 13 34 12 00       	call   0x87db30
  75a71d:	41                   	inc    ecx
  75a71e:	89 4b 04             	mov    DWORD PTR [ebx+0x4],ecx
  75a721:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  75a724:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  75a727:	5f                   	pop    edi
  75a728:	89 01                	mov    DWORD PTR [ecx],eax
  75a72a:	5b                   	pop    ebx
  75a72b:	5d                   	pop    ebp
  75a72c:	c2 04 00             	ret    0x4
  75a72f:	cc                   	int3

```

## 附錄：資源完成釋放端 (`0x007A86B0..0x007A87D0`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007a86b0 <.text+0x3a76b0>:
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

```