# KR T16-57 — HasQuest 條件名稱解析、節點配置與後續消費者

- 日期：2026-10-28T10:58:06.857560+08:00；研究者：`chatgpt-web roy`，KR T16 only。
- 唯讀來源：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32/i386 `.text` VA `0x401000`，raw `0x400`；`.rdata` VA `0xBD2000`，raw `0x7D0600`；`.data` VA `0xD61000`，raw `0x95E800`。
- GitHub repo：https://github.com/we88ec3-prog/ttr_anal_multi，前段 T16-53～56 已提交；此批不修改其他 Task／catalog／owner，不研究 TC；不啟動程式。
- disassembly：`objdump -D -Mintel --start-address=... --stop-address=... Tartaros.bin`；局部片段不保證全函式 CFG，但已按已知入口與連續指令核對。

## 新確認的原生資料流
- 字串 `HasQuest`、`HasCompletableQuest`、`HasScenario` 的 *push imm32* 確認分別位於 `0x53FD84`、`0x53FD92`、`0x53FDA2`，接續均 `mov eax,ebx; call 0x72E2E0`。三次回傳值依序保存到 `ESI`、`[esp+0x20]`、`[esp+0x1c]`，前面另有第四個名稱 `0xC0F4E4`。
- `0x72E2E0` 以 `eax` 當容器來源，從 `[eax+0x18]` 起逐一遍歷節點的 `+0x40` 鏈；字串/小字串判定使用 `[esi+0x34] >= 0x10`，比較在 `0x893CB1`，遇同名節點回傳其指標，否則零。這是**本地名稱查找**，不是存檔 API。
- 若查找成功，分別以 `lea edx,[edi+0x10]`、`lea ecx,[edi+0x20]`、`lea edx,[edi+0x30]` 提供不同輸出槽給 `0x53FEB0`；早一個節點的輸出槽在 `[esp+0x14]`。槽距 0x10。
- `0x53FEB0` 進一步讀取 `[esi]` vtable `+0x14` 的節點方法，查 `0xC0F4A8` 屬性並從字串取數值，交 `0x4A8680`。只確認解析／欄位寫入，**不能命名為 HasQuest 檢查玩家任務狀態**。

## 可重現原碼

VA 0x0053FD76 raw 0x13F176 bytes: 68 e4 f4 c0 00 8b c3 e8 5e e5 1e 00 8b f8 68 ec f4 c0 00 8b c3 e8 50 e5 1e 00 8b f0 68 f8 f4 c0
```asm
0053fd76 <.text+0x13ed76>:
  53fd76:	68 e4 f4 c0 00       	push   0xc0f4e4
  53fd7b:	8b c3                	mov    eax,ebx
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd82:	8b f8                	mov    edi,eax
  53fd84:	68 ec f4 c0 00       	push   0xc0f4ec
  53fd89:	8b c3                	mov    eax,ebx
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd90:	8b f0                	mov    esi,eax
  53fd92:	68 f8 f4 c0 00       	push   0xc0f4f8
  53fd97:	8b c3                	mov    eax,ebx
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fd9e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  53fda2:	68 0c f5 c0 00       	push   0xc0f50c
  53fda7:	8b c3                	mov    eax,ebx
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdae:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe      	jne    0x53fcf5
```

VA 0x0072E2E0 raw 0x32D6E0 bytes: 55 8b ec 53 8b 5d 08 56 8b 70 18 85 f6 74 21 90 83 7e 34 10 8d 46 20 72 02 8b 00 53 50 e8 af 59
```asm
0072e2e0 <.text+0x32d2e0>:
  72e2e0:	55                   	push   ebp
  72e2e1:	8b ec                	mov    ebp,esp
  72e2e3:	53                   	push   ebx
  72e2e4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  72e2e7:	56                   	push   esi
  72e2e8:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  72e2eb:	85 f6                	test   esi,esi
  72e2ed:	74 21                	je     0x72e310
  72e2ef:	90                   	nop
  72e2f0:	83 7e 34 10          	cmp    DWORD PTR [esi+0x34],0x10
  72e2f4:	8d 46 20             	lea    eax,[esi+0x20]
  72e2f7:	72 02                	jb     0x72e2fb
  72e2f9:	8b 00                	mov    eax,DWORD PTR [eax]
  72e2fb:	53                   	push   ebx
  72e2fc:	50                   	push   eax
  72e2fd:	e8 af 59 16 00       	call   0x893cb1
  72e302:	83 c4 08             	add    esp,0x8
  72e305:	85 c0                	test   eax,eax
  72e307:	74 0f                	je     0x72e318
  72e309:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  72e30c:	85 f6                	test   esi,esi
  72e30e:	75 e0                	jne    0x72e2f0
  72e310:	5e                   	pop    esi
  72e311:	33 c0                	xor    eax,eax
  72e313:	5b                   	pop    ebx
  72e314:	5d                   	pop    ebp
  72e315:	c2 04 00             	ret    0x4
  72e318:	8b c6                	mov    eax,esi
  72e31a:	5e                   	pop    esi
  72e31b:	5b                   	pop    ebx
  72e31c:	5d                   	pop    ebp
  72e31d:	c2 04 00             	ret    0x4
```

## 出參／回傳推測偽碼（僅根據已見片段）
```cpp
Node* findNamedNode(Container* c, const char* s) {
    for (Node* n=c->first_at_0x18; n; n=n->next_at_0x40)
        if (compare(node_name(n), s)==0) return n;
    return nullptr;
}
// parser: optional named nodes HasQuest / HasCompletableQuest / HasScenario
// each invokes 0x53FEB0 with its own 0x10-spaced output slot.
```

## 尚待證明
- 此容器的具體 XML／腳本來源、`0x53FEB0` 對 `0x4A8680` 的確切參數型別、輸出槽的後續 consumer，不能從名稱推演 server 任務條件。
- 下一段查輸出結構的構建者與使用者；與 T16-58 的 Lua 介面做**名稱域隔離**。
