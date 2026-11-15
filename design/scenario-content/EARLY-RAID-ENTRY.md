# 一般挑戰 RAID 1～3 的入場交握與關卡來源

廣場 NPC 10069 開窗的事件 9 用於 Q2851。選關、開始以及進戰鬥場各有自己的請求和場景。 [Q2851 開窗證據](TOWN-SERVICE-TUTORIAL-EVENTS.md#q2851-挑戰入場教學)

| RAID | 最低等級 | Stage／Case | NodeLink 的地圖順序 | 結算表獎勵 |
|---:|---:|---|---|---|
| 1 | 7 | 50／88 | 932 → 934 → 936 → 937 → 938 | Product 2274 ×1 |
| 2 | 12 | 51／89 | 942 → 944 → 948 → 950 → 951 | Product 2275 ×1 |
| 3 | 17 | 52／90 | 952 → 954 → 957 → 960 → 961 | Product 2276 ×1 |

三筆皆為可見的一般挑戰。原表要求列 CP_TOTAL=700。Stage 各列 TOTAL_CP=700、BOSS_COUNT=3、FAIL_CP=140、START_CP=0，使用時機須再核對。三份 CHART 均為五節點單線，首節點 type 0，末節點 type 3。索引列出 CLUST、15 張圖的原版 BND 雜湊及 _MapList 的 TRIGGER 引用。怪群分配、頭目及波次仍待取證。 [來源索引](early-raid-kr-source.json)

```powershell
python -B <分析庫>/design/scenario-content/extract_early_raid_sources.py <KR目錄> <輸出>/early-raid-kr-source.json --bounds <輸出>/raid-bounds
dotnet <本機檢查器DLL> --early-raid-sources <輸出>/early-raid-kr-source.json 3209d0afff692a7636d8945c96ec4e26b5046ecb0ba39a65bebf1e5489352053 <輸出>/raid-bounds
```

本機 Release 檢查器已逐一載入 15 份 BND，核對清單雜湊、每圖 BND 雜湊、版本與靜態碰撞層格式。九份為版本 2，六份為版本 0。收據 SHA-256 為 `907fa767bf2fc0328d8c3d0305258fafa54ced385f759661568c49cc7b101578`。MEF 讀取、動態碰撞、實際走位及戰鬥仍待驗。

## Client 選關、建隊與開始

| 操作 | 封包 | 原版路徑 |
|---|---|---|
| 開啟挑戰配對清單 | C2S `52 00 <page> 09 03 <raidId> <waitingOnly>` | `6910B0` 設定列表類型 3，經 `6904B0 → 53B890` 發送。 |
| 選定挑戰 | C2S `57 00 <raidId> 01` 或 `7B 00 <raidId> 01` | `68C790` 的挑戰分支可在 `0053` 建隊後產生本機事件 `F4396`。 `5B7F80 → 5B68C0` 檢查選中關卡等級，從配對面板 `+20Ch` 取選擇。當前模式 7、23、24 由 `4DDA10` 發 `0057`。其他模式由 `4DDA70` 發 `007B`。 |
| 安裝挑戰大廳 | S2C `00A6`／mode 8 | `4B7DC0` 在 `FD322C` 登錄 `4B9410`。該函式檢查 `+2` 等於 8，建立 `CRaidRoom` 並寫入模式。 |
| 大廳開始 | C2S `08 00 00 00` | `F439E → 5B1230 → 5B1380`。比較已選 RAID 的門檻與 `CGameInfo+5EB4h` 的 CP，符合隊長條件的分支由 `5B15C6 → 4A35F0` 發送。封包沒有 RAID 或 Stage 欄。 |
| 安裝挑戰戰鬥場 | S2C `005F`／mode 9 | `4B7DC0` 在 `FD2FF4` 登錄 `4B99C0`。mode 9 分支經 `4C54E0` 建立 `CRaidField`。首圖載入及戰鬥初始化仍待核對。 |

另一個選項視窗的 `426060` 比較目前選擇與 `CGameInfo+5EACh`，變更時發 C2S `01 01 <row+258h> <row+260h>`。S2C `00A7` 經 `4DD8F0` 登錄到 `4DDBF0`，把 offset 3／4 的 byte 寫入 `+5EACh/+5EB0h`。offset 2 為零時處理 offset 5 起的 DWORD 陣列並顯示提示。回覆狀態與發布時機仍待確認。

挑戰 UI 讀取的 CP 由兩個已定位的入口更新。帳號資料 S2C `002A` 經 `4E1E9F → 4E2B30` 讀取 `+39h` 的 WORD，寫入 `CGameInfo+5EB4h`。場景 S2C `00ED` 由 `4AE0ED → 4B5C10` 讀取 `+2` 的 WORD，與現值比較後寫入同一位置。更新函式也依差額顯示提示。這兩處確定了 Client 顯示的餘額欄位。起始值、取得來源、上限和扣除時機仍需原版規則證據。

下列原版 KR BIN 和指定 v2 視窗依個別 PE section 映射後一致。長度以十六進位計。

| VA＋長度 | SHA-256 |
|---|---|
| `5B6AE6+60` | `4ff1a45301f8460982407f272f3addae21a8c7d3cb4f481d47643ad669454fcf` |
| `4DDA10+60` | `e73830a0036412c95449a569429983e5a29f0ea1939e481b6215f9d406c2f121` |
| `4DDA70+60` | `f7ede665be0d2a2273bb98a4bde03f8182efa6fca9af5e4a0e71dec1fdce5e60` |
| `4B7E3F+A` | `c7f6632306d928379472971b0cdc89a7512dc6a4a6685cc21559df5f85a8d858` |
| `4B9441+59` | `baa65e8d9941aada916407e1053aafa5cd6fbf70167e8b2d8b3719b6944c9657` |
| `5B1480+7` | `eb4477e727b83b7349acacddd89ad1b900a1ff5933e904747f726a182e86d4c1` |
| `5B15C1+A` | `203f580044041fc2fc577a26d4e92153fb0faa203e996ffb00569a0a13f14dea` |
| `4A35F0+2B` | `d777b9726046f5ee65935216aa73cca27a2179b49f06c652789e3ee9df790482` |
| `4B7EAF+A` | `342e3f034373d37878b84ca62ae2e573afd6bacdfe6d70dbe2d470d09da4ed9a` |
| `4B99C0+1D0` | `31c4678af808f8a5c84c78e398a9cff725f7cb75bb4b873353ff22a1b909dbff` |
| `426154+6B` | `f00fbb090799c30e80c87cb1a354892d77434688d41f716b64b2a65e632799af` |
| `4DD94F+A` | `d15da530a33207fc48f7bc256051b4e972f91c5d1511dc8407aa0d847aca3f86` |
| `4DDC35+30` | `a2f88b2ecebed686c8bbf634c84909e83a2c67b74962b13719b37748c9cfcb30` |
| `4AE0ED+A` | `58f4d9f2008046234cf2bf1b8236d28341b00fa11410b3265f43c14d99f9051c` |
| `4B5C44+31` | `96b2354f345d3b11c22f86933be839f3023ef14cbed7985ebb296d0beb1fd7f7` |
| `4E1E9F+A` | `7b3dae489f600fc22f96f4804a8a152ad631eccc16d0d11345985e3c36ce8c3e` |
| `4E2BE4+D` | `b4b000367819b51ef10706d866cc4f47da95ea626093e8575b1ed7177baadd7b` |

## Server 開發順序

1. 確認選定 RAID 後的挑戰大廳初始化，補齊 RAID 與 CP 快照。核對 CP 來源及隊伍人數，保留模式 8 大廳和模式 9 戰鬥場。
2. 由有效連線及隊長提交開場，以房間所選 RAID 查出 Stage／Case。逐步核對首圖載入、就緒和離場握手。
3. 先為 Case 88 建立可驗證的出生點、遭遇與出口。結算使用核對過的 CP 與獎勵規則，再回廣場恢復主線。尚無挑戰副本實機通過紀錄。
