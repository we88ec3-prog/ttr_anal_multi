# T10-W04 — KR S→C 戰鬥關聯角色資料：IOCP→應用分派→000B／000C／000D／0000→本地/其他 actor、動作資源與 C2S 回授

> **研究及交付日期**：2026-10-31 17:25 Asia/Taipei；研究者標記 chatgpt-web roy。**W04 是接收端 Client 靜態研究，普通攻擊視為 SkillAction 是使用者的 Server 設計抽象，不宣稱原版 Client C++ 類型。** 完成了本篇列明的 S2C 角色更新與上/下游結構性鏈；**尚不能將 000A 的任意一筆與某 S2C 000B／000C／000D／0000 綁為原版攻擊 ACK 或拒絕，無法把整體「普攻反應的完整因果及動畫播放時機」標完成**。此交付保留可續查的 Client 機器碼入口及 Server-only 未知，不拿無原版 Server 程式當停止尚可靜態研究的藉口。
>
> 唯讀 KR **Tartaros.bin**：12,472,320 bytes，**SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；EXE **03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f**。原件每次先確認 checksum；PE32 \`.text\` VA \`0x401000\`、raw \`0x400\`（raw=VA−\`0x400C00\`）；\`.rdata\` VA \`0xBD2000\`、raw \`0x7D0600\`（raw=VA−\`0x401A00\`）。使用 GNU objdump -D -Mintel、原始 bytes、struct/hashlib；未執行、附加、修改 Client，不抓取原版 server/wire 封包，不把 fixture 模擬當原生。檢查檔另附 raw/code hash 及虛表指標；**原件離線校驗為 18/18 程式視窗 SHA256、162/162 byte anchors、9/9 vtable pointers、浮點常數4.0**。這是來源/範圍自動一致性而不是函式全文 T01 FULL-PASS。

## 0. 權威流程與前段更正

- 開工 GitHub \`main=f6eeef02dfa3704aabb45349718cc9da4b35fbe0\`、T10 工作分支 \`c047d5c3bc77dca972e41907c3c55d90a9422eac\`；依 03 規定先完成**真實雙 parent Git merge** \`e477086a522838d8133c462e4259770f9cfc6a9e\`（parent=T10、main），保留 W00-W03 21個 branch-only artifacts；**未將 T10 合回 main**、未創新 branch。
- 已查 \`AGENTS.md\`、\`kr/tasks/T10/README.md\` 的七件 T01 退回、\`task.json\`、\`research/dispatch/README.md\`、\`research/dispatch/inbox/T10.md\`、唯一 \`research/requests/index.json\`、\`shared/verified-knowledge/README.md\` 與 Client 修改政策。當時 **T10 inbox 無已派 RR**。T01 退回依 W00 已有勘誤版本引用；有 \`NEEDS_FIX\` 的項目不由本研究逕改 RESOLVED/FULL-PASS。使用者指定 W04，優先本次範圍而非重新審 T01 退回。
- W03 已證 C2S 000A 以 6+5N、N>0才呼叫 selector0 傳輸；雙鍵 Z+X/Z+C/X+C 在 Type0 先合成 bit masks 0x03/05/06→SkillMatrix columns4/5/6；**Row A/B 是兩種物件 producer，不等於雙鍵各送一 row**。本篇逆向應用接收，不把 opcode 000A、S2C 000B/000D、socket frame prefix、connection selector0 當成同一 ID。
- 已有相關有界原稿（本輪回到原生 BIN 對關鍵邊界重驗）：\`T10-105\` 屬性、\`T10-106\` queue，\`T10-108\` framed receive，\`T10-110\` IOCP，\`T10-119\` 000D 9-byte rows，\`T10-120\` actor vtable。舊稿被 T01 勘誤的錯誤不能自動轉引為原生。

## 1. 已閉合的條件式 Client 網路接收→應用分派層（不是伺服器確認）

~~~text
WinSock WSARecv submitted on connection
 → Windows IOCP GetQueuedCompletionStatus（806D84, recv overlapped +A030）
   └─ worker 806E08 -> 807B40(frame input EDX=connection+0x18, ECX=completed bytes)
      ├─ 807BB0 首 WORD framed-length；0或>0x1000 invalid exit
      ├─ 807BD4 次 WORD frame signature；一般4 byte prefix、特例6/8
      ├─ 有界 unpack / checksum 或不同前處理
      └─ 807E50 copying into record+8（record+4=len，限制<=0x1000）
            → 807DAD call 8040A0（connection+0xA080 queue category）
            → 804100/804740（雙 bucket drain，可能替代 bucket，不能假設單 FIFO）
                 → 80486D virtual callback
                 → C05AEC vtable+0x00 = 4930E0（相符接收 manager 實例）
                    → 4930ED reads P[0:2] app key
                    → 493105 category==2/ P nonzero → 493135 [state+0xB8] vfunc+4
                    → active state 48AAD0（8-byte entry：key13 之類）
                       ├─ app key0→4AFAF0 ParamUpdate
                       ├─ app key11→4AFE60
                       ├─ app key12→4B0130
                       └─ app key13→4B01C0
~~~

實際 BIN 片段：

~~~asm
806DE4 lea eax,[eax+0xA030]  ; completed receive-overlapped equality
806E04 lea edx,[eax+0x18]
806E08 call 807B40           ; receive framing parse (不是 807B60)
807B85 mov eax,[ebp+8]
807B88 mov edi,edx
807B8A add [edi+0x5000],ecx
807BB0 movzx esi,word [ebx]
807BD4 movzx ecx,word [ebx+2]
807DAD call 8040A0          ; queue append
804841 call 804100          ; category/toggle queue pop
804862 push ecx             ; category
804863 push eax             ; record+4 length
804867 push eax             ; &record+8 payload
80486A push eax             ; record+0 extra arg
80486D call edx             ; receiver vtable slot 0
4930ED movzx edi,word [eax] ; application key from P; category2 gated
493105 mov eax,[ebp+14h]   ; queue category (2 if dispatch)
493135 call edx             ; active state virtual+4
48AAD0 ... 8-byte handler table lookup via key as signed short
~~~

**必要條件**：IOCP 回傳成功／overlapped identity 必須是 recv 分支且 connection+0xA0AC gate 成立；frame 完整、長度/校驗、decode、queue category=2、receiving manager 的 vptr/active state table 正確、key 在有效範圍。WSARecv callback 的成功只表示 OS receiving completion；\`4930E0\` 的 \`EAX\` 或 \`48AAD0\` 的 HRESULT 也不是普通攻擊 Server accept。由於分桶切換與多 completion，**本輪不能由 static path 推論與前一個 000A 建包同一 tick 或嚴格 wire order**。

**handler 表四個實際位置**：\`4ADD50\` 初始化 \`8-byte/slot\`，索引 \`key k\` pointer \`base+4+8*k\`。\`4ADDAC mov [eax+4],4AFAF0\` key0；\`4ADDBC mov [eax+5C],4AFE60\` key11；\`4ADDC6 mov [eax+64],4B0130\` key12；\`4ADDD0 mov [eax+6C],4B01C0\` key13。**這是指定 active-state table 的實作，不保證所有 client mode 使用它**；其他 key/狀態另有 handler。

## 2. NEW：S2C key11 / 0x000B 是 8-byte actor state + 坐標候選，不是 C2S 000A 的 ACK 定義

\`4AFE60\` 收到 application buffer \`P\` 及 length \`L\` 後：
\`4AFE8C\` 讀 L；\`4AFE98 add eax,-2\`、\`4AFE9B shr eax,3\`，得 **N=floor((L−2)/8)**（若 L<2 則 N=0）。\`4AFEA6 mov ebx,P+6\`、\`4B00FA add ebx,8\` 固定 stride8。完整 row（從 P+2 開始）：

| Offset P+2+8i | 寬 | 直接原生讀者 | 有界用途 |
|---:|---:|---|---|
| +0 | u16 | \`4AFEE6 movzx edi,word[ebx−4]\` | \`FAB138\` actor tree key，查不到跳過這 row |
| +2 | u8 | \`4AFF31 mov cl,[ebx−2]\` | 放進 actor+0xE4，且經 actor virtual+0x58 |
| +3 | u8 | \`4AFF28 movsx ax,byte[ebx−1];4AFF34 shl ax,0xF;4AFF46 and ax,0x8000\` | **只取該 byte 的 bit0 映成 local bit15**；不等於施法成敗 |
| +4 | u16 | \`4AFF4E movzx eax,word[ebx]\` | 座標類整數候選 A，可在條件下轉 float |
| +6 | u16 | \`4AFF65 movzx ecx,word[ebx+2]\` | 座標類整數候選 B，可在條件下轉 float |

actor 查找為 \`FAB138/82EF00\`、\`FAB13C\` sentinel，node+0x10=actor。若沒有有效 actor，\`4AFF16\` 記錄 missing 並從 \`4B00FA\` 下一 row；其它角色仍能被處理。

**重要新增 def-use：**

~~~asm
4AFF28 movsx ax,byte [ebx-1]
4AFF34 shl ax,0xF
4AFF46 and ax,0x8000
4AFF49 mov word [esp+2Eh],ax   ; packed local high word = bit15 or 0
4AFF51 mov word [esp+2Ch],di   ; packed local low word = actor row ID
4AFF58 mov byte [esp+30h],cl   ; local state byte
...
4B00E5 mov [esi+0xE0],eax      ; eax = DWORD [esp+2Ch]
4B00EF mov [esi+0xE4],cl       ; cl = [esp+30h]
4B00F5 push eax
4B00F8 call edx               ; actor vtable +0x58
~~~

所以 **對已核實通常成功的這個 branch**，收到的第3個 row byte bit0 變成 \`WORD(actor+0xE2)\` 的 0x8000 旗標，低 WORD 用 actor row ID；state byte 寫 \`actor+0xE4\`，另呼叫 actor+0x58 事件 setter。此 bit15 **不證是攻擊命中、技能取消或 ACK**。

### 2.1 000B 在 actor 位置上的條件式處理：距離平方門檻是 4.0

如果 bit15 !=0、兩個 row WORD 座標值非零，\`4AFF72..4AFF9A\` 把 u16 轉為 float 並存入 \`actor+0xE8/+0xEC\`（候選目標位置），計算 delta=(E8−A0, EC−A4)。\`4AFFD0..4AFFE0\` 計算平方距離，\`4AFFE4 fld float [C55A64]\`，原始 .rdata C55A64 bytes \`00 00 80 40\` = **4.0**。\`4AFFEE fcomip st,st(1); 4AFFF2 jbe 4B0020\`：當 \`dist²<=4.0\` 就跳過下面的 delta writer，當 ordered \`dist²>4.0\` 才執行：

~~~asm
4B0014 mov [esi+0xD8],ecx
4B001A mov [esi+0xDC],edx
~~~

這是**有條件設定 actor 後續位置差量**，不是證明 Server 做了一次合法移動、實際角色立刻傳送、或攻擊距離／Combo 判定是2.0。超界浮點/NaN edge 未全審，常數只可稱此段 squared-delta gate，不移植為 Server 時窗。

### 2.2 000B 的本地受控 actor 特殊分支 vs 其它 actor

每 row 在位置處理後，\`4B0020 mov ecx,[FBA7A4];4B0028 call [vptr+20]\` 取得 owner 的 current actor-like pointer，\`4B0033 cmp esi,eax\`。**相等時才**進 \`4B003B..4B00CB\` 的 local-controlled-candidate 特殊控制：

- \`owner+0x6A &0x8000\`、該 row bit15 是否有設置、\`actor+0x158 ->+0x8 != 0xD\` 等控制會改 \`owner+0x74\`（\`4B0058\` 設1；\`4B00BB\` 清理可設0），以及 \`actor+0x3A8\`（\`4B00AF\` 設1；\`4B00CB\` 清零）；同時可重存 actor+0x3A4 與附屬效果。
- **不相等的 actor** 跳 \`4B00D1\`，不走這個 owner+74/actor+3A8 特殊分支，但仍進 \`4B00E5..\` 的 E0/E4 更新及 vptr+58，除非其前置 lookup 敗。
- 此處的「本地」是**manager virtual+0x20 回傳 pointer identity** 的有界判斷；其 class/instance 與顯示於畫面的玩家 avatar 的完全同一性還需 constructor/owner provenance，故僅稱 local-controlled-candidate，不稱 runtime 已確認本地角色。**原生確定有依 identity 分流**，不能套用到所有遠端 actor。

### 2.3 關鍵的新跨方向鏈：000B → actor+E0/E4 → W03 000A Row B

這是 W04 與 W03 之間最重要可交付的原生增量之一：

~~~text
S2C key11 4AFE60 8-byte row
  ├─ state byte P+4 → 4B00EF actor+E4
  └─ flag byte P+5 bit0 → 4AFF49 packed highWORD bit15
     → 4B00E5 actor+E0 DWORD
                    ↓ (same actor instance, later Row B lookup by owner vector)
C2S key10 000A builder 5452C0, Row B path
  ├─ 545A54 mov eax,[R+E0] → local[+2C] (includes previous bit15)
  ├─ 545A67 mov cl,[R+E4] → local[+30] (initial fifth byte)
  ├─ 545A97 owner::virtual+44(out, actor, index)
  ├─ 545AC8 may overwrite fifth byte with sampled R+B0
  ├─ 545AEB / 545AF4 overwrite output low WORD with R+4
  └─ 545B0E..B13 append 4+1 bytes → 000A buffer if gates pass
~~~

因此 **在 Row B 實際命中同一 R、virtual/gates 未覆寫相應欄位的條件下，S2C 000B 的 bit0/byte 與 C2S 000A Row B 欄位存在真正記憶體來源關係**。但 \`545AC8\`、\`546EF0\` virtual+44 的 \`547044/547077/5470BF\` 等，可能改 bit15 和 fifthByte；0x000A 也不是被 000B 自動觸發的回 ACK，這是**跨時間資料/狀態回授的條件式可達性**，非一發一回的 protocol handshake。

## 3. NEW：S2C key12 / 0x000C 是 3-byte 子物件事件，和 000D 共用同一個 vtable slot

\`4B0130\`：
\`4B0133 L<2→0\`，\`4B0142 magic 0xAAAAAAAB; 4B0149 shr EDX,1\` ⇒ **N=floor((L−2)/3)**；\`4B0155 ESI=P+2\`，\`4B01B0 add ESI,3\`。

| row offset | 寬 | Source | 下游 |
|---|---|---|---|
| +0 | u16 | \`4B0160 movzx EDX,word[ESI]\` | \`40F060\` actor group→tree lookup \`82EF00\`；miss 跳過 |
| +2 | signed byte | \`4B01A9 movsx EAX,byte[ESI+2]\` | \`4B019A\` actor+F0 子物件的 \`vtable+0x8\`，stack push signed value |

\`\`\`asm
4B019A mov edx,[eax+0xF0]
4B01A0 mov edx,[edx+0x8]
4B01A3 lea ecx,[eax+0xF0]
4B01A9 movsx eax,byte [esi+2]
4B01AE call edx
\`\`\`

**直接可比對的第二條來源**：在 000D \`4C8B58..4C8B69\`：

~~~asm
4C8B58 mov eax,[esi+F0h]
4C8B5E mov edx,[eax+8]
4C8B61 lea ecx,[esi+F0h]
4C8B67 push 0Dh
4C8B69 call edx
~~~

所以 **000C row 帶可變 signed event，000D 為已確認的固定值 \`0x0D\`，兩者在 actor+F0 的同一 vtable+8 接口匯合**。這提供了 Server 可能影響動作/事件狀態的具體接口，但**尚未將這個 vtable 方法完整確認為播放某個動畫 clip**。不能把 000C row byte -1、0、1、... 無證命名為「技能成功/失敗」或把固定13當 Z 普攻編號。

## 4. S2C key13 / 0x000D 是 9-byte 多 actor 更新列：actor status + motion-adjacent lookup

再次由 original .text \`4ADD D0\` pointer 和 \`4B01C0\` 函式直接驗證：
\`4B01F8..4B0202\` 使用 \`0x38E38E39\` magic 且 high DWORD>>1 實現 **N=floor((L−2)/9)**；
\`4B0211 EDI=P+5\`；\`4B039E add EDI,9\`；
\`4B0206\` count0 直接到函式正常返回0。

| P+2+9i row | bytes | 真實 native 指令 | 適用語意 |
|---:|---:|---|---|
| +0 | u16 | \`4B0250 movzx edx,word [edi−3]\` | FAB138/82EF00 actor tree key |
| +2 | u8 | \`4B0290 movzx eax,byte [edi−1]\` | actor vtable+58 寫/處理的 state byte |
| +3 | u16 | \`4B0313 movzx ecx,word [edi]\` | \`4C8A90\` 下游 vtable+68 的 signed WORD |
| +5 | f32 | \`4B030F fld dword [edi+2]\` | \`4C8A90\` 下游帶入 float |

找不到 actor 或 node+0x10 空的 row \`4B027E..4B028B\` 記錄 missing 並繼續下一 row，不會把同批所有 actor 都當成成功。有效 actor：

~~~asm
4B0294 mov edx,[esi]
4B0296 mov edx,[edx+58h]
4B0299 push stateByte
4B029C call edx                       ; actor virtual+58
4B02A6 mov [esi+3A8h],0               ; local state reset
4B02C2 mov [esi+3A4h],bl              ; conditional state copy
4B030F fld dword [edi+2]
4B0313 movzx ecx,word [edi]
4B031A call 4C8A90                    ; ESI live actor pointer
~~~

已確認的若干候選 actor vtable：
\`C07554+58→4C8C30\`, \`C07B44+58→4C8C30\`, \`C076AC+58→4C8C30\`（另有 T10-120 列出其餘四張候選表）。\`4C8C30: mov al,[ebp+8]; mov [ecx+0xB0],al; ret4\`，**是 status byte 的直接寫入，不是可叫「播放普攻 animation」的函式**。不同 actor subtype 不能未驗證 constructor/vptr lifetime 就全部合併。

\`4C8A90\` 除了 actor+0xB0/+0x3A4 附屬效果，也會看 actor+0xD8/+0xDC 兩個浮點 delta；若其中有效，\`4C8ABD..4C8B10\` 加到 actor+0xA0/A4 候選位置，將 delta 清0，再呼叫 actor vtable+0x44 處理 position。之後固定向 actor+0xF0 vtable+8 提交0xD事件，然後：

~~~asm
4C8B6B fld dword [ebp+0Ch]           ; S2C row float
4C8B6E mov eax,[esi]
4C8B70 mov edx,[eax+68h]
4C8B74 movsx ecx,word [ebp+8]        ; S2C row WORD as signed
4C8B7E call edx                      ; actor+68 WORD,float
~~~

\`C07554+68\`、\`C07B44+68\` 等候選表＝\`4C8DA0\`；此實作：

~~~asm
4C8DA3 mov eax,[ebp+8]
4C8DA7 mov edi,[ecx+15Ch]
4C8DAD mov [ecx+38Ch],eax          ; received WORD -> actor persistent DWORD
4C8DB3 test edi,edi
4C8DB7 cmp dword [ecx+370h],0
4C8DC0 fld dword [ebp+0Ch]
4C8DC8 call 7A6970                ; guarded attached object effect
~~~

**新增深入下游** \`7A6970\` 及 \`7A7800\` 透過 \`EDI=actor+15C\` 指向的附屬物件（需 \(+370\) 與 \(+15C\) 均有效）：
- \`7A697F fstp [edi+104h]\`：將 row float 存 attached+0x104。
- \`7A698D mov [edi+0xA8],eax\`：將 row WORD/ID 來源寫 attached+0xA8；\`7A6995\` 會依當前有無舊項目/狀態作分支，可能先清/重置。
- \`7A6A17 call 7A7800\`：按 ID 做附屬資源/條目 lookup。實際 \`7A780D lea ecx,[esi+7Ch]\` / \`7A7813 call 82EF00\`，又可能 \`47C290→515790→[sub+0xD4] tree lookup\`，\`7A787C\` 無資料可返回 null；這是**有條件的動作/效果資源候選查找**，不是所有情境必找到資源。
- 找到資源 \`7A6A2A..7A6A31\` 使用回傳物件 vtable+0x40，然後 \`7A6A89 call 7A6D80\`、多個資源/vtable 查詢，可能進一步設定附屬效果/時間。
- **不能宣稱 \`7A6970\` 必啟動單一特定 animation clip、必播放角色 attack、等同 Server 授權**：仍需解出資源實際型別／表值/clip start 的最後 callee，對多型及失敗分支分別驗。

### 4.1 key13 的另一種「本地身分」比較，不得和 key11 混為一個來源

\`4B0326 mov esi,[esi+0x9C]\` 後，\`4B0357 cmp esi,[F93930]\`。若相等且當筆 WORD \`[edi]==0x12\`，\`4B0397 push 0Ah;4B0399 call 501650\`，有一次性 lazy-init \`4FFE60\` 相關副路徑。這是**actor+0x9C vs 全域 F93930 的 identity 特例**，不等於 \`key11: FBA7A4->vfunc20\` 的 actor-pointer 對比；\`F93930\` 在 \`4E15D4\` 只見清零 writer，後續 assignment/provenance 另需追。即使此值後來確為 local avatar ID，也不能因這裡 valueWORD==0x12 便稱為普攻或某技能編號。注意字面 \`0x12\` 是 **000D row 內 WORD**，非 app opcode 0x12。

### 4.2 一筆 000D 可能同時影響多個 actor；不宣稱這就是技能命中廣播

000D handler 的迴圈按 \`(L−2)//9\` 逐 actor lookup、處理、推進，並對缺少的 actor 略過。相容 Server 若要顯示多人角色動作/位置，必須先參照這種原生收包介面，但**從有多筆 actor rows 不能推論它就是普攻命中多目標廣播**。傷害結果是否用別的 handler、何時 Server 做 ACK、遠端玩家是否僅收這個欄位，尚待其他 opcode/Server 契約證據。

## 5. S2C key0 / 0x0000 屬性更新可改下一輪技能可用性（獨立回包作用）

同 active table \`+4=4AFAF0\` 的 key0 handler：
\`4AFAF3\` 長度不足2→0 row；\`4AFB02\` magic0xAAAAAAAB且 \`4AFB09 shr EDX,2\` → **N=floor((L−2)/6)**；每行 \`{u16 actorID,u16 property,u16 value}\`，\`40F060/82EF00\` 查 actor 後 \`4AFB61 mov edx,[ecx]\`, \`4AFB64 mov edx,[edx+2Ch]\`，呼叫該 actor virtual+0x2C(property,value)。

在**候選派生 actor vtable C07B44+0x2C=4CE7F0**（別的表如基底 C07554 可只 log）：
\`4CE81D movsx ecx,word[ebp+8]\` 對 property 數值跳表。當 property==4 到 \`4CE90A\`：
\`\`\`asm
4CE90A movsx ecx,word[ebp+0Ch]   ; received value
4CE914 mov [ebx+0x3E8],ecx       ; actor state, not universal all vtables
...\`\`\`

這個狀態對下次戰鬥輸入有明確跨時間讀者：W03 \`546100\` 的 \`5462B4 mov ecx,[edi+0x3E8]\` 把它傳入 \`54F270\` local matrix/timing availability predicate；若部分條件查不到可用列，\`5462ED cmp [edi+0x3E8],0\` 決定是否保留局部判斷結果；\`546302 and word[out+2],0x8000\` 清低15位發生在更嚴格失敗條件。

**真正可以說**：分類2收到 app-key0 的 property4、actor subtype 支援時，Client 能修改其後 \`546100→54F270\` 的技能輸入 gate；**不能說 property4 的值就是官方冷卻、MP、施法狀態、Server 授權，亦不一定是該次000A的成功/拒絕回覆**。這是 Server 相容性要保留的「收到屬性可改後續 Client 判斷」介面，不可只實作 damage packet 而忽略 actor property 同步。

## 6. 重要負證與反例（限定 handler，不做全遊戲否證）

1. **不是一按 000A 就收一個 000D**：\`000A\` 長度 \`6+5N\`、有 header \`F93944\`；這些 S2C app 的已核對 rows 分別 \`000B=2+8N\`、\`000C=2+3N\`、\`000D=2+9N\`、\`0000=2+6N\`，沒有在這幾個 handler 的 row read 中辨識出「回傳原始 \`F93944\` 的對應 nonce/serial」。**不排除其他 Server key、actor state 或外部時序存在 ACK**，只是不把物件更新硬當 ACK。
2. **000B 的本地控制 branch 不等於收到了拒絕**：當 actor == owner virtual+0x20 pointer 時才更改 owner+0x74/actor+0x3A8；其他 actor 仍可收到 E0/E4/callback。條件分流在 Client 內部，既不包含 Server accept flag 已證語意，也沒有辨識 reject message。
3. **000C 和 000D 指向同一 actor+F0 vtable+8**，但傳入不同值/目的；event callback 不能單憑名稱就推成動畫起手。這也是「Server 回包→動畫」的明確未閉合介面。
4. **actor 沒有查到**：000B／000D／000C／0000 按各自 handler 跳過相應 row 或 log，不能把 socket 收到當所有玩家都套用。
5. **錯誤/超短/尾端截斷**：各 handler 對 \`L<2\` 不生成 row，對 \`L>=2\` 採 floor 除 stride 截斷不足完整 row 的餘數。這不等於有上游 packet 明確合法性驗證；\`4930ED\` 在分派前讀 WORD，仍有 length0/short buffer 的局部安全前提；Server 應按經證的完整長度產生合約資料而非惡意測極值。
6. **000D 的 \`4C8C30\` vfunc58 不會自行播放 clip**，只寫 actor+B0；附屬物件 \`7A6970\` 才導向 resource lookup，仍不保證 clip start。T10-120 的 \`C076AC+0x68→4CC0D0\` 是 destructor-like 疑點，不可視為與其他 six vtable 相同的 action callback；本輪 vtable bytes 核對其存在，**runtime instance 和真實 address-point 需後續 constructor 查證**。
7. **Client local preview**：W03 的技能輸入收集與 S2C actor callback 確是獨立 code sources。沒有找到能證明本地「先播」、必「等回包才播」、或被 Server 拒絕時一定回滾 animation 的同一 actor/action sequence。這是 Client 尚待更具體的連續 state/clip producer 逆向，而不是缺原版 Server source 的可略過問題。

## 7. 玩家情境 × Client gate × C→S × S→C × 動作 × 責任

| 玩家情境 | Client 判斷 | C→S | S→C | 本地/其他 actor 效果 | 證據級別/責任 |
|---|---|---|---|---|---|
| Type0 Z 普攻、重複按/持按 | W02 phase1/2 同 bit0；actor+3E8/SkillMatrix、000A Row gates | 000A 6+5N，N>0、selector0/queue/send gates 才可到 WSASend | **未證哪個 opcode 直接 ACK** | 當地是否先播/要等回包未知 | Client input/send 有界；Server accept/cancel unknown |
| Type0 Z+X/Z+C/X+C | W03 masks 0x03/05/06→matrix col4/5/6，有 callback clear/flag | 可能同一 000A Row A 的 highWORD，未保證實際 row | 同上 | 000B/000C/000D 不因按組合鍵而確定收 | 不能把雙鍵拆成兩次施法 |
| 收到 app 000B、某 actor 存在 | category2+active table、8-byte row | 不由此 handler 必然發新 C2S | 000B 更新 E0/E4、vfunc58；有條件位置 delta | 所有查到 actor 都可基本更新；pointer-identity match 才額外 owner+74/actor+3A8 | 新驗證 receive/actor state |
| 收到 000B 且 Row B 後續使用同 actor R | 有 R+E0/E4 被寫 | 後來 000A Row B 可能讀先前資料作 highWORD/byte | 000B 本身不是 000A ACK | output callback 可修改/清 bit15 | Client 跨時間資料流，非固定 handshake |
| 收到 000C 某 actor | actor group查找，3-byte row | 不是本 handler 的直接送出 | signed byte→actor+F0 vtable+8 | 事件效果實作未完整；未證 attack animation | 有界 Client subobject event |
| 收到 000D 某 actor | FAB138 查找、9-byte row | 不是本 handler 的直接送出 | state BYTE、signed WORD、float→actor | 候選 table B0 writer、position delta/attached resource lookup；不同 actor type 可分叉 | 原生已確認局部；motion clip仍待證 |
| 000D 的 actor+9C 比對 F93930 相等且 row WORD=0x12 | 雙重 identity/value branch | 無由這一條直接構成 attack C2S | 觸發 4FFE60/501650(0xA) 特例 | side-effect用途 unknown | 不把 0x12 叫 attack ID |
| 收到 0000 property=4、相符 actor subclass | 40F060 tree + vfunc2C→4CE914 | 可影響**未來** 000A Row A gate | actor+3E8 更新 | SkillMatrix predicate 再讀+3E8 | 已確認 Client state耦合；Server需可提供相容同步 |
| 任意 S2C row actor missing | 查找 failure/空 payload | 本 handler無新增 C2S | 本 row skip，後續 row繼續 | 不對 absent actor call | 限定 Client 已證 |
| 收到「官方技能拒絕」 | 尚無該原版 app key/value match | 不等於 WSASend failure | **未知** | 回滾/停播/重置 unknown | Client 待逆向＋Server裁決不能硬猜 |
| 施放中鍵盤/滑鼠移動 | W03 尚無完整 move producer/互取消 | opcode/先後仍 unknown | 000B 可有位置 delta，但不證與玩家此操作對應 | actor+44 position path有界；取消動作 unknown | T09/T02/T11 交界 |

## 8. 精確的待續 Client 路徑、Server 交接與停止界線

### Client 已確認、部分確認

- 000B、000C、000D、0000 的 **active table conditional S2C parser**／stride／offset／actor lookup／missing branch、常數4.0平方距離比較、key11 local-owner identity、key12/13 同 actor+F0 vtable+8、key13 state+B0/position/attached resource、key0 prop4→actor+3E8→下一輪 action gate；network OS completion/queue 的有界入口。
- W03 000A Row B 的 highWORD/byte 可以從 000B 寫過的 E0/E4 取得；**必須保留 virtual callback 可修改、不同 subtype、跨時間條件**。
- 未證 runtime 000A→S2C 直接對應，沒有擷取原版 play trace，不把 app payload KEY 直接當最終 wire framing。程式碼檢查通過不代表 T01 FULL-PASS。

### Client 尚待逆向（明確入口，不以「缺原版 Server」結束）

1. **actor+F0 的真實 vtable+8**：由 \`4B01A0\`（000C）與 \`4C8B5E\`（000D）反查 actor construction 與此子物件 concrete class，再追被呼叫者是否真正寫 motion/animation queue。需排除 \`C076AC+68→4CC0D0\` destructor/address-point false match。
2. **attached action/clip**：跟 \`4C8DA0→7A6970→7A7800→7A6D80\` 的非零資源、實際 class/動作資源檔、具體 clip play caller；要分本地/遠端 subtype。這條 Client 仍可從 static data 深挖，**不能只以 Server 未知停止**。
3. **Client local preview**：從 W03 \`546100\` 和 actor motion queue 的真實 writer、owner+0x74/+0x3A8、actor+0x158 狀態，建立同一角色操作在網路 callback **之前** 是否播放/更改 motion 的 exact order；不能由兩個獨立函式的存在推斷同步先後。
4. **ACK/refusal/correction**：在 category2 handler 表的其它鍵與 subtype 尋找能讀 \`F93944\`（C2S 000A header u32）或具名 skill/actor action correlation 的實質欄位，追是否有明確 success/error opcode/branch。**本輪已覆核 0000/000B/000C/000D，不是全部 3029 keys**；沒有找到 ACK 是有限搜尋結果，不是全局不存在證明。
5. **F93930/本地身份**：已找到 \`4E15D4\` 清 global F93930 為0，\`4B0357\` 讀 actor+9C 與之比；還需找到成功創角/選角→值寫入與 actor constructor，及 key11 的 FBA7A4 vfunc+20 所取 actor 是否同一物件。兩種 local identity 不可互代。
6. **真實 C2S move與接收互動**：keyboard/mouse 分開追輸入→封包→000B position writer，同 W03 的施放中取消與 ordering 連續比對；不能猜 000B 是 move ACK。
7. **T02 wire**：從 WSARecv raw bytes、0x807B40 frame mode/0x807E50 packed records 到 category2 的最後 transform field，整理正式 on-wire payload；本 W04 已有 memory-level schema，但不能冒充完整 TCP frame 契約。

### Server 待開發（由 S00 審核納入規格，不宣稱原版邏輯）

- 相容 Server 依玩家情境提供**符合 Client 當前狀態與 actor registry**的角色屬性/狀態回覆；至少在需要同步時理解 \`key0/11/12/13\` 的本地格式與 row 長度，保護不存在 actor 的情境。**未能證實它們必定是每次普通攻擊的回應**，因此不能直接要求 Server 每 000A 送 000D 或每 Z+X 送兩筆。
- 以既有 S00 REQ/SPEC/GAP/TEST（去重）明列仍需的 action/cast accept/refuse、動作/他人廣播、失敗修正、cooldown/資源/連段；如果採 Server 自行策略必標 ADR，**不能宣稱原版 Server 已採某個反應時窗或 ACK 格式**。
- 跨 Task：T02 framing，T09 motion，T11 skill cost/cooldown，T12 damage，S00 架構；不在本 T10 改它們的 owner、task.json、全局 verified knowledge 或 RR。

### 待遊玩驗證

- 未執行原版 Client、沒有 Server replay/抓包/角色動畫比較：**NOT_RUN**。
- W04 已完成**本輪明確列出的 S2C key0/11/12/13 與 actor state 的原生靜態功能鏈**，但**W04 原計畫「哪個包代表 000A 攻擊結果／本地是否先播／服務端拒絕如何反應」仍未解**，狀態為「有界階段交付／整體 W04 未全閉合」而非完全達標。這是需要後續 Client 靜態深挖的具體缺口；不能以已提交、抽樣驗證或重大發現當停止條件。

## 9. 完整原生稽核與引用

同目錄附 \`W04-native-audit.json\`（**18 個原件 VA 視窗的 SHA256、byte anchors、actor vtable 與 float 4.0**），以及只讀的 \`verify-native.py\`。可執行 \`python verify-native.py Tartaros.bin W04-native-audit.json\`（僅驗證 bytes；不執行目標）；詳細 VA、raw、read/write/branch 和反證均在本文，而非僅用 SHA 判讀 gameplay。

- 上游 W03：\`kr-temp-roy/T10/W03-20261031/20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md\` Git blob \`0d17362eb300ab8ea002c3d6380d5a41039665bc\`；W03 primary \`20261031-165757-chatgpt-web-roy-T10-W03-action-transport-native.md\` blob \`62d31e8b3d8a450e644362092fd04e7ae696c729\`。
- T10-105 \`kr-temp-roy/20261028-1919-chatgpt-web-roy-T10-105-paramupdate-handler-and-property-dispatch.md\`, blob \`9b12f6f3572a1f15540fa9a874a21bb8056aee52\`（本輪 key0/4CE914/5462B4 原件重驗）。
- T10-106 \`kr-temp-roy/20261028-1942-chatgpt-web-roy-T10-106-queue-header-key-and-dispatch-bases.md\`, blob \`b9873d454eca75147c3251b85aed7f54929ecb5f\`。
- T10-108 \`kr-temp-roy/20261028-201546-chatgpt-web-roy-T10-108-KR-framed-receive-to-queue-producer.md\`, blob \`804572ab576259cc82162f56d68379b4f0f7d940\`。
- T10-110 \`kr-temp-roy/20261028-203129-chatgpt-web-roy-T10-110-KR-IOCP-completion-to-frame-consumer.md\`, blob \`c63e65b5c3270ec3bb1b5339960668bae106ade3\`。
- T10-119 \`kr-temp-roy/20261028-225025-chatgpt-web-roy-T10-119-KR-S2C-key13-nine-byte-actor-motion-consumer.md\`, blob \`d44df2cf097e112ff98a78ebd918fbf9910b8952\`。
- T10-120 \`kr-temp-roy/20261028-225505-chatgpt-web-roy-T10-120-KR-actor-vtable58-state-writer-and-vtable68-effects.md\`, blob \`d0efddc90c9943bbad3bc121ad9898304f11d8ea\`。
- W00 更正 \`kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md\`，blob \`bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804\`，原生第5byte/alias 以此優先。上述原稿是導航/來源；本輪只對本稿列出的地址/本輪驗證檔承擔第一手主張。

**不可由本報告推論**：某一 Z／Z+X 送出後必收到 000D、000B 是移動 ACK、000C 是技能取消、000D+F0 slot 是原版 animation start、所有 client actor 類型一致、官方 Server 規則或遊戲可玩已驗收。
