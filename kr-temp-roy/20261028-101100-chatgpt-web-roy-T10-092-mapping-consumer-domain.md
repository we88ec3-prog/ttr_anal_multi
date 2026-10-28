# T10-092 — 基本與 Extra MapButton 消費者的原生 domain 分界

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0x6D4DC0 的不同 ID-domain consumer，分清 UI 文字和 action runtime

### 低 ID：0x5CD68A 明確請求 MapButton=16

```asm
  5cd661:	68 60 e7 bc 00       	push   0xbce760
  5cd666:	e8 af 4c 2c 00       	call   0x89231a
  5cd66b:	83 c4 04             	add    esp,0x4
  5cd66e:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5cd672:	89 7c 24 4c          	mov    DWORD PTR [esp+0x4c],edi
  5cd676:	89 7c 24 50          	mov    DWORD PTR [esp+0x50],edi
  5cd67a:	6a 02                	push   0x2
  5cd67c:	6a 10                	push   0x10
  5cd67e:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  5cd682:	c6 84 24 f8 00 00 00 	mov    BYTE PTR [esp+0xf8],0x3
  5cd689:	03 
  5cd68a:	e8 31 77 10 00       	call   0x6d4dc0
  5cd68f:	83 c4 08             	add    esp,0x8
  5cd692:	57                   	push   edi
  5cd693:	68 fc d1 be 00       	push   0xbed1fc
  5cd698:	8d 8c 24 cc 00 00 00 	lea    ecx,[esp+0xcc]
  5cd69f:	e8 bc 4a e3 ff       	call   0x402160
  5cd6a4:	8b 74 24 48          	mov    esi,DWORD PTR [esp+0x48]
  5cd6a8:	3b 74 24 4c          	cmp    esi,DWORD PTR [esp+0x4c]
  5cd6ac:	74 1e                	je     0x5cd6cc
  5cd6ae:	8b d6                	mov    edx,esi
  5cd6b0:	8b 02                	mov    eax,DWORD PTR [edx]
  5cd6b2:	50                   	push   eax
  5cd6b3:	8d b4 24 c8 00 00 00 	lea    esi,[esp+0xc8]
  5cd6ba:	bf 18 fb fd 00       	mov    edi,0xfdfb18
  5cd6bf:	e8 bc 73 fc ff       	call   0x594a80
```

Stack vector `[esp+0x48]..[esp+0x50]` 初始化為 0，呼叫前 `push 2` / `push 0x10`，對應配置查詢的 mode / MapButton=16；返回 vector 指標後，會呼叫 `0x402160`，若有資料則 `0x594A80` 消費值並形成字串。這支持**配置／文字展現候選**，沒有證明 motion 或攻擊指令。

### 高 ID：0x650E96 明確請求 MapButton=0x2904 (10500)

```asm
  650e6d:	68 60 e7 bc 00       	push   0xbce760
  650e72:	e8 a3 14 24 00       	call   0x89231a
  650e77:	83 c4 04             	add    esp,0x4
  650e7a:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  650e7e:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  650e82:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  650e86:	6a 02                	push   0x2
  650e88:	68 04 29 00 00       	push   0x2904
  650e8d:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  650e91:	c6 44 24 58 02       	mov    BYTE PTR [esp+0x58],0x2
  650e96:	e8 25 3f 08 00       	call   0x6d4dc0
  650e9b:	83 c4 08             	add    esp,0x8
  650e9e:	57                   	push   edi
  650e9f:	68 fc d1 be 00       	push   0xbed1fc
  650ea4:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  650ea8:	e8 b3 12 db ff       	call   0x402160
  650ead:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  650eb1:	3b 74 24 18          	cmp    esi,DWORD PTR [esp+0x18]
  650eb5:	74 15                	je     0x650ecc
  650eb7:	8b 0e                	mov    ecx,DWORD PTR [esi]
  650eb9:	51                   	push   ecx
  650eba:	8d 44 24 28          	lea    eax,[esp+0x28]
  650ebe:	bf 18 fb fd 00       	mov    edi,0xfdfb18
  650ec3:	e8 a8 36 f4 ff       	call   0x594570
  650ec8:	33 ff                	xor    edi,edi
  650eca:	eb 0f                	jmp    0x650edb
  650ecc:	8d 54 24 24          	lea    edx,[esp+0x24]
  650ed0:	52                   	push   edx
```

`0x2904` 十進位 10500，屬 `KeyMappingExtra.xml` 的高 ID 範圍；同樣採 vector result 與 `0x402160`/`0x594570` 字串處理。此證據反向證明不能把 0x6D4DC0 的所有 caller 都當作基本 MapButton 1..39 或戰鬥控制者。

### 兩個 callsite 的共同點及差異

| 面向 | 0x5CD68A | 0x650E96 |
|---|---|---|
| ID | 0x10 / 16 | 0x2904 / 10500 |
| XML domain | 基本候選 | Extra 候選 |
| 查詢模式參數 | push 2 | push 2 |
| 結果 | 三個 DWORD vector 的輸出區 | 三個 DWORD vector 的輸出區 |
| 後處理 | 0x402160、0x594A80 | 0x402160、0x594570 |
| 嚴格證據 | 查詢 + 字串結構處理 | 查詢 + 字串結構處理 |
| 未成立 | gameplay keydown / attack | Extra runtime action |

### 上一階段輸入／動作完整鏈狀態

```text
KR XML: MapButton13..16 ─→ Key44..47 （只有 Type0 字面配置證據）
        bank0/1 → working bank2 → 0x6D4DC0（配置查詢）
                                   ?（設備 scan-code producer + 轉換）
phase [0xFB9004+ID] ─→ 0x6D4CE0 ─→ 0x5961C0 ─→ vptr+0xEC/+0xF0
                                   ?（真正 target function → motion / queue / cancel）
```

## T10-093 有限可執行研究目標

1. 從 `0x6D4CE0` 非零 phase producer 反追 pointer aliases / `memcpy` / callback，避免只尋 literal `FB9004`。
2. 從 `0x5961C0` 的 this vptr 或 `0x761010` 的 node+8 物件擷取具體 vtable，在只讀靜態下枚舉 `+0xEC/+0xF0` overrides。
3. 逆追 `0xF95CD8` event container 原始插入者與 `0xFAADFA` 的值域。
4. 找 `0xFB73E8` 的非零寫入者；未證明前保留未知。

## 嚴格驗收／禁止推論

目前沒有官方 Z 普攻/V 蓄氣或其他動作的完整 write→dispatch→motion 證據。`CHAIN_WINDOW=.65`、server SubAI>60、`0x547240 >500ms` 不能作原版連段窗口。四段均只讀；未變動其他 Task 的 owner/catalog/notes，也未上傳遊戲原件。