# T16-42 — Quest XML：原始資料來源、版本差異與 ID 驗證界線

- 分析時間：20261028-095118（Asia/Taipei）
- KR 原始 BIN：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 證據來源：https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/integrations/T01-20261028-06/README.md、resource-source-audit.json、NEXT-QUERIES.md；本機 KR BIN 以 objdump -D -Mintel 靜態反組譯
- 分類：**有限範圍已確認／來源內容未讀取的項目待驗證**。這份筆記不是教學流程完成證書。

## 1. 原生來源與內容分級
T01 稽核：KR QuestInfo.xml SHA256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`，`QuestInfo` root 下 4,798 children；KR QuestTalk.xml SHA256 `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`，`QuestTalk` root 下 4,322 children。TC 同名兩檔分別 4,723 與 4,235 children，SHA 各異。這是 XML root/數量/來源差異的證據，**不是 Quest ID 15/16 的定義或任務順序證據**。

## 2. 本次直接 BIN 證據（PE VA）

### `0x00504740–0x00504830`
```asm
  504740:	55                   	push   ebp
  504741:	8b ec                	mov    ebp,esp
  504743:	83 e4 f8             	and    esp,0xfffffff8
  504746:	6a ff                	push   0xffffffff
  504748:	68 3d 42 92 00       	push   0x92423d
  50474d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504753:	50                   	push   eax
  504754:	81 ec 48 02 00 00    	sub    esp,0x248
  50475a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50475f:	33 c4                	xor    eax,esp
  504761:	89 84 24 40 02 00 00 	mov    DWORD PTR [esp+0x240],eax
  504768:	53                   	push   ebx
  504769:	56                   	push   esi
  50476a:	57                   	push   edi
  50476b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  504770:	33 c4                	xor    eax,esp
  504772:	50                   	push   eax
  504773:	8d 84 24 58 02 00 00 	lea    eax,[esp+0x258]
  50477a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00        	jmp    0x5054d8
```

### `0x00505570–0x00505630`
```asm
  505570:	55                   	push   ebp
  505571:	8b ec                	mov    ebp,esp
  505573:	83 e4 f8             	and    esp,0xfffffff8
  505576:	6a ff                	push   0xffffffff
  505578:	68 7b 28 92 00       	push   0x92287b
  50557d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505583:	50                   	push   eax
  505584:	81 ec 98 00 00 00    	sub    esp,0x98
  50558a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50558f:	33 c4                	xor    eax,esp
  505591:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  505598:	53                   	push   ebx
  505599:	56                   	push   esi
  50559a:	57                   	push   edi
  50559b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5055a0:	33 c4                	xor    eax,esp
  5055a2:	50                   	push   eax
  5055a3:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  5055aa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00  	mov    DWORD PTR [esp+0x80],ebx
```

## 3. 功能分析／偽碼邊界
XML 載入器 `0x00504740`、`0x00505570` 的函式與原版 BIN 相關；不能因檔名相同假定 parser 確認「某 Quest ID 是教學主線」。本批未讀取 XML 逐個元素內容，因此 ID/依賴欄位仍標 unknown。

```cpp
// 證據分級式流程模型；未知值不臆造
resource = find_source_by_version_and_sha();
if (!resource.full_bytes_read) mark("DEFERRED-LOCAL-RESOURCE");
native_entry = verify_machine_code_boundaries();
// Quest16/Quest15 server authority & persistence: unknown
```

## 4. 與既有 T16 分段的關係
- T16-1～T16-40 原稿位於 `kr-temp-roy/`，提供 Lua 入口、XML 載入、quest parser 與分派路徑的歷史分析。這份筆記保留新來源稽核和原生組合語言，**不把舊推論提升成已驗收業務規則**。
- 原版 BIN 的 PE VA 與 TC 不可共用。

## 5. 尚缺證據與本地補證工作
1. `DEFERRED-LOCAL-RESOURCE`：從已核對 SHA 的 KR Event.stp 解出並交付 `Event/TutorialMain.lua`、`Event/TutorialBase.lua` 的完整 bytes 與 Lua proto/constant/branch 解碼。
2. `DEFERRED-LOCAL-RESOURCE`：KR Table.stp 中 `QuestInfo.xml`／`QuestTalk.xml` 完整元素，單獨列 Quest15、Quest16 及相關前置和 ID namespace。
3. 確認 scenario14/TUTO 交界、正式 opcode/payload、伺服器任務 writer，並以重登恢復抓包或伺服器碼交叉驗證。
4. 只有來源 hash 或 XML root children count 時，quest step、完成條件、獎勵與權威仍填 `unknown`。

## 6. 最小測試矩陣
| 問題 | 目前狀態 | 下一個驗收證據 |
|---|---|---|
| 是否能確認 KR 腳本/表來源 | 已確認來源稽核，尚未讀全文 | 提供 hash 對應原始位元組 |
| Tutorial 入口可定位 | 原生程式入口部分確認 | 腳本 function/branch 對應 |
| 教學逐節點順序 | 未確認 | Lua proto/constant/CFG 與 XML 對照 |
| Quest16 完成／Quest15 接取 | 未確認 | XML rule + server notification/write |
| 重登／保存 | 未確認 | T15 提供 writer 與 snapshot |

## 7. 版本與提交注意
- KR/TC 嚴格隔離，無 TC BIN 的本次直接反組譯。
- 未啟動或修改遊戲程序。
- 本稿作為獨立分析來源提交，不變更 catalog、owner、其他 Task。