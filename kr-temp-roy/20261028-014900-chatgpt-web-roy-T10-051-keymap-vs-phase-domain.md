# T10-51 — keymap-vs-phase-domain

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：key mapping 結果與 phase 消費不是同型別

- `.text` 直接 `E8`→`0x6D4DC0` 有 **29** 處候選呼叫：集中 `0x5946xx..0x5959xx`，另在 `0x5CD68A / 0x5CE5BA / 0x62B5BA / 0x650E96..0x6510A4`；**caller 數不等於 action row 數**。
- `0x5CD91F` 直接呼叫 `0x594610`；`0x5CD90A` 先從全域指標表 `[ebx*4+0xF832F0]` 取得參數；緊接 `0x5CD924` 檢查局部 byte 與 `0x5CD930` 的 `al<0x0B` 守衛。`0x5CD937: imul ecx,ecx,0xB`，`0x5CD943: add ecx,edx`，`0x5CD943` 後採 `[eax+ecx*2+4]` 讀 WORD；這是矩陣式索引的正向局部證據，不能直接命名成技能/普攻 tier。
- `0x596390..0x5964C0` 可見特殊鍵域迭代讀取鍵碼、呼叫 `0x6D4CE0` 與多型 `+0xEC/+0xF0` predicate。這個流程**沒有因同樣使用鍵碼**而自動等於 `0x5CD91F` 的映射矩陣或玩家 controller。
- `0x6D4C7C` 對特殊鍵樹節點 `+0x10` 寫零；這和 `0x5CD943` 取 WORD 是不同容器/單位。

## 交叉模組界線

T10 管輸入與 combo/cancel；T11 主責 cooldown/cost/cast。若 `0x5CD9xx` 屬技能資料生產鏈，這裡只記錄輸入到資料表示的介面，並不擅自併入 T10 主責。

## 後續最小閉合試驗

需要相同版本的 `KeyMapping.xml`/fallback row、實際 action id 與 `0x6D4DC0` 回傳項值，才可建立 Z/X/C/V 的映射表。目前無此原始資料直接連接，保持缺口。

## 第一手反組譯片段

### VA `0x00594610` / raw `0x00193a10` (920 bytes)

```asm
00594610 <.data>:
  594610:	55                   	push   ebp
  594611:	8b ec                	mov    ebp,esp
  594613:	83 e4 f8             	and    esp,0xfffffff8
  594616:	6a ff                	push   0xffffffff
  594618:	68 00 70 92 00       	push   0x927000
  59461d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  594623:	50                   	push   eax
  594624:	83 ec 60             	sub    esp,0x60
  594627:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59462c:	33 c4                	xor    eax,esp
  59462e:	89 44 24 58          	mov    DWORD PTR [esp+0x58],eax
  594632:	53                   	push   ebx
  594633:	56                   	push   esi
  594634:	57                   	push   edi
  594635:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59463a:	33 c4                	xor    eax,esp
  59463c:	50                   	push   eax
  59463d:	8d 44 24 70          	lea    eax,[esp+0x70]
  594641:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  594647:	8b f9                	mov    edi,ecx
  594649:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  59464c:	33 db                	xor    ebx,ebx
  59464e:	8b f2                	mov    esi,edx
  594650:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  594654:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  594658:	89 5c 24 3c          	mov    DWORD PTR [esp+0x3c],ebx
  59465c:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  594660:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
  594690:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  594694:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  594698:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  59469c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5946a0:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5946a4:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5946a8:	33 c9                	xor    ecx,ecx
  5946aa:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5946b1:	00 
  5946b2:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5946b6:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5946bb:	6a 02                	push   0x2
  5946bd:	6a 0d                	push   0xd
  5946bf:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5946c3:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x3
  5946ca:	03 
  5946cb:	e8 f0 06 14 00       	call   0x6d4dc0
  5946d0:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5946d4:	83 c4 08             	add    esp,0x8
  5946d7:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  5946db:	74 27                	je     0x594704
  5946dd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  5946e1:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  5946e4:	74 12                	je     0x5946f8
  5946e6:	8b 10                	mov    edx,DWORD PTR [eax]
  5946e8:	52                   	push   edx
  5946e9:	8d 74 24 50          	lea    esi,[esp+0x50]
  5946ed:	e8 8e 03 00 00       	call   0x594a80
  5946f2:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5946f6:	eb 0c                	jmp    0x594704
  5946f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5946fa:	50                   	push   eax
  5946fb:	8d 44 24 50          	lea    eax,[esp+0x50]
  5946ff:	e8 6c fe ff ff       	call   0x594570
  594704:	6a ff                	push   0xffffffff
  594706:	53                   	push   ebx
  594707:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59470b:	51                   	push   ecx
  59470c:	8b ce                	mov    ecx,esi
  59470e:	e8 dd fa e6 ff       	call   0x4041f0
  594713:	6a 02                	push   0x2
  594715:	6a 0e                	push   0xe
  594717:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  59471b:	e8 a0 06 14 00       	call   0x6d4dc0
  594720:	8b 7c 24 24          	mov    edi,DWORD PTR [esp+0x24]
  594724:	83 c4 08             	add    esp,0x8
  594727:	3b 7c 24 20          	cmp    edi,DWORD PTR [esp+0x20]
  59472b:	74 2f                	je     0x59475c
  59472d:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594730:	74 16                	je     0x594748
  594732:	8b 17                	mov    edx,DWORD PTR [edi]
  594734:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  594738:	52                   	push   edx
  594739:	8d 74 24 50          	lea    esi,[esp+0x50]
  59473d:	e8 3e 03 00 00       	call   0x594a80
  594742:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  594746:	eb 10                	jmp    0x594758
  594748:	8b 07                	mov    eax,DWORD PTR [edi]
  59474a:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  59474e:	50                   	push   eax
  59474f:	8d 44 24 50          	lea    eax,[esp+0x50]
  594753:	e8 18 fe ff ff       	call   0x594570
  594758:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  59475c:	6a ff                	push   0xffffffff
  59475e:	53                   	push   ebx
  59475f:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  594763:	51                   	push   ecx
  594764:	8b ce                	mov    ecx,esi
  594766:	e8 85 fa e6 ff       	call   0x4041f0
  59476b:	83 7c 24 60 08       	cmp    DWORD PTR [esp+0x60],0x8
  594770:	72 0d                	jb     0x59477f
  594772:	8b 54 24 4c          	mov    edx,DWORD PTR [esp+0x4c]
  594776:	52                   	push   edx
  594777:	e8 90 ca 2f 00       	call   0x89120c
  59477c:	83 c4 04             	add    esp,0x4
  59477f:	33 c0                	xor    eax,eax
  594781:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  594788:	00 
  594789:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  59478d:	66 89 44 24 4c       	mov    WORD PTR [esp+0x4c],ax
  594792:	3b fb                	cmp    edi,ebx
  594794:	74 09                	je     0x59479f
  594796:	57                   	push   edi
  594797:	e8 70 ca 2f 00       	call   0x89120c
  59479c:	83 c4 04             	add    esp,0x4
  59479f:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  5947a3:	3b c3                	cmp    eax,ebx
  5947a5:	0f 84 9f 02 00 00    	je     0x594a4a
  5947ab:	50                   	push   eax
  5947ac:	e8 5b ca 2f 00       	call   0x89120c
  5947b1:	83 c4 04             	add    esp,0x4
  5947b4:	e9 91 02 00 00       	jmp    0x594a4a
  5947b9:	83 ff 19             	cmp    edi,0x19
  5947bc:	0f 85 29 01 00 00    	jne    0x5948eb
  5947c2:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  5947c6:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  5947ca:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  5947ce:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5947d2:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5947d6:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5947da:	33 c9                	xor    ecx,ecx
  5947dc:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5947e3:	00 
  5947e4:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5947e8:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5947ed:	6a 02                	push   0x2
  5947ef:	6a 0e                	push   0xe
  5947f1:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5947f5:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x6
  5947fc:	06 
  5947fd:	e8 be 05 14 00       	call   0x6d4dc0
  594802:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  594806:	83 c4 08             	add    esp,0x8
  594809:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  59480d:	74 27                	je     0x594836
  59480f:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  594813:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594816:	74 12                	je     0x59482a
  594818:	8b 10                	mov    edx,DWORD PTR [eax]
  59481a:	52                   	push   edx
  59481b:	8d 74 24 50          	lea    esi,[esp+0x50]
  59481f:	e8 5c 02 00 00       	call   0x594a80
  594824:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  594828:	eb 0c                	jmp    0x594836
  59482a:	8b 00                	mov    eax,DWORD PTR [eax]
  59482c:	50                   	push   eax
  59482d:	8d 44 24 50          	lea    eax,[esp+0x50]
  594831:	e8 3a fd ff ff       	call   0x594570
  594836:	6a ff                	push   0xffffffff
  594838:	53                   	push   ebx
  594839:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59483d:	51                   	push   ecx
  59483e:	8b ce                	mov    ecx,esi
  594840:	e8 ab f9 e6 ff       	call   0x4041f0
  594845:	6a 02                	push   0x2
  594847:	6a 0f                	push   0xf
  594849:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  59484d:	e8 6e 05 14 00       	call   0x6d4dc0
  594852:	8b 7c 24 24          	mov    edi,DWORD PTR [esp+0x24]
  594856:	83 c4 08             	add    esp,0x8
  594859:	3b 7c 24 20          	cmp    edi,DWORD PTR [esp+0x20]
  59485d:	74 2f                	je     0x59488e
  59485f:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594862:	74 16                	je     0x59487a
  594864:	8b 17                	mov    edx,DWORD PTR [edi]
  594866:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  59486a:	52                   	push   edx
  59486b:	8d 74 24 50          	lea    esi,[esp+0x50]
  59486f:	e8 0c 02 00 00       	call   0x594a80
  594874:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  594878:	eb 10                	jmp    0x59488a
  59487a:	8b 07                	mov    eax,DWORD PTR [edi]
  59487c:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  594880:	50                   	push   eax
  594881:	8d 44 24 50          	lea    eax,[esp+0x50]
  594885:	e8 e6 fc ff ff       	call   0x594570
  59488a:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  59488e:	6a ff                	push   0xffffffff
  594890:	53                   	push   ebx
  594891:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  594895:	51                   	push   ecx
  594896:	8b ce                	mov    ecx,esi
  594898:	e8 53 f9 e6 ff       	call   0x4041f0
  59489d:	83 7c 24 60 08       	cmp    DWORD PTR [esp+0x60],0x8
  5948a2:	72 0d                	jb     0x5948b1
  5948a4:	8b 54 24 4c          	mov    edx,DWORD PTR [esp+0x4c]
  5948a8:	52                   	push   edx
  5948a9:	e8 5e c9 2f 00       	call   0x89120c
  5948ae:	83 c4 04             	add    esp,0x4
  5948b1:	33 c0                	xor    eax,eax
  5948b3:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5948ba:	00 
  5948bb:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5948bf:	66 89 44 24 4c       	mov    WORD PTR [esp+0x4c],ax
  5948c4:	3b fb                	cmp    edi,ebx
  5948c6:	74 09                	je     0x5948d1
  5948c8:	57                   	push   edi
  5948c9:	e8 3e c9 2f 00       	call   0x89120c
  5948ce:	83 c4 04             	add    esp,0x4
  5948d1:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  5948d5:	3b c3                	cmp    eax,ebx
  5948d7:	0f 84 6d 01 00 00    	je     0x594a4a
  5948dd:	50                   	push   eax
  5948de:	e8 29 c9 2f 00       	call   0x89120c
  5948e3:	83 c4 04             	add    esp,0x4
  5948e6:	e9 5f 01 00 00       	jmp    0x594a4a
  5948eb:	83 ff 1a             	cmp    edi,0x1a
  5948ee:	0f 85 22 01 00 00    	jne    0x594a16
  5948f4:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  5948f8:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  5948fc:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  594900:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  594904:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  594908:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  59490c:	33 c9                	xor    ecx,ecx
  59490e:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  594915:	00 
  594916:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  59491a:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  59491f:	6a 02                	push   0x2
  594921:	6a 0d                	push   0xd
  594923:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  594927:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x9
  59492e:	09 
  59492f:	e8 8c 04 14 00       	call   0x6d4dc0
  594934:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  594938:	83 c4 08             	add    esp,0x8
  59493b:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  59493f:	74 27                	je     0x594968
  594941:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  594945:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594948:	74 12                	je     0x59495c
  59494a:	8b 10                	mov    edx,DWORD PTR [eax]
  59494c:	52                   	push   edx
  59494d:	8d 74 24 50          	lea    esi,[esp+0x50]
  594951:	e8 2a 01 00 00       	call   0x594a80
  594956:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  59495a:	eb 0c                	jmp    0x594968
  59495c:	8b 00                	mov    eax,DWORD PTR [eax]
  59495e:	50                   	push   eax
  59495f:	8d 44 24 50          	lea    eax,[esp+0x50]
  594963:	e8 08 fc ff ff       	call   0x594570
  594968:	6a ff                	push   0xffffffff
  59496a:	53                   	push   ebx
  59496b:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59496f:	51                   	push   ecx
  594970:	8b ce                	mov    ecx,esi
  594972:	e8 79 f8 e6 ff       	call   0x4041f0
  594977:	6a 02                	push   0x2
  594979:	6a 0f                	push   0xf
  59497b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  59497f:	e8 3c 04 14 00       	call   0x6d4dc0
  594984:	8b 7c 24 24          	mov    edi,DWORD PTR [esp+0x24]
  594988:	83 c4 08             	add    esp,0x8
  59498b:	3b 7c 24 20          	cmp    edi,DWORD PTR [esp+0x20]
  59498f:	74 2f                	je     0x5949c0
  594991:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594994:	74 16                	je     0x5949ac
  594996:	8b 17                	mov    edx,DWORD PTR [edi]
  594998:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  59499c:	52                   	push   edx
  59499d:	8d 74 24 50          	lea    esi,[esp+0x50]
  5949a1:	e8 da 00 00 00       	call   0x594a80
  5949a6:	8b                   	.byte 0x8b
  5949a7:	74                   	.byte 0x74
```
### VA `0x005cd8b0` / raw `0x001cccb0` (320 bytes)

```asm
005cd8b0 <.data>:
  5cd8b0:	33 d2                	xor    edx,edx
  5cd8b2:	c7 84 24 bc 00 00 00 	mov    DWORD PTR [esp+0xbc],0x7
  5cd8b9:	07 00 00 00 
  5cd8bd:	c7 84 24 b8 00 00 00 	mov    DWORD PTR [esp+0xb8],0x0
  5cd8c4:	00 00 00 00 
  5cd8c8:	66 89 94 24 a8 00 00 	mov    WORD PTR [esp+0xa8],dx
  5cd8cf:	00 
  5cd8d0:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xd
  5cd8d7:	0d 
  5cd8d8:	f6 05 10 fb fd 00 01 	test   BYTE PTR ds:0xfdfb10,0x1
  5cd8df:	75 29                	jne    0x5cd90a
  5cd8e1:	83 0d 10 fb fd 00 01 	or     DWORD PTR ds:0xfdfb10,0x1
  5cd8e8:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xe
  5cd8ef:	0e 
  5cd8f0:	e8 6b 2e fc ff       	call   0x590760
  5cd8f5:	68 60 e7 bc 00       	push   0xbce760
  5cd8fa:	e8 1b 4a 2c 00       	call   0x89231a
  5cd8ff:	83 c4 04             	add    esp,0x4
  5cd902:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xd
  5cd909:	0d 
  5cd90a:	8b 0c 9d f0 32 f8 00 	mov    ecx,DWORD PTR [ebx*4+0xf832f0]
  5cd911:	6a 01                	push   0x1
  5cd913:	68 18 fb fd 00       	push   0xfdfb18
  5cd918:	8d 94 24 b0 00 00 00 	lea    edx,[esp+0xb0]
  5cd91f:	e8 ec 6c fc ff       	call   0x594610
  5cd924:	8a 4c 24 14          	mov    cl,BYTE PTR [esp+0x14]
  5cd928:	8d 43 01             	lea    eax,[ebx+0x1]
  5cd92b:	80 f9 04             	cmp    cl,0x4
  5cd92e:	73 1a                	jae    0x5cd94a
  5cd930:	3c 0b                	cmp    al,0xb
  5cd932:	73 16                	jae    0x5cd94a
  5cd934:	0f b6 c9             	movzx  ecx,cl
  5cd937:	6b c9 0b             	imul   ecx,ecx,0xb
  5cd93a:	0f b6 d0             	movzx  edx,al
  5cd93d:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5cd941:	03 ca                	add    ecx,edx
  5cd943:	0f b7 44 48 04       	movzx  eax,WORD PTR [eax+ecx*2+0x4]
  5cd948:	eb 02                	jmp    0x5cd94c
  5cd94a:	33 c0                	xor    eax,eax
  5cd94c:	0f b7 c8             	movzx  ecx,ax
  5cd94f:	8d 54 24 44          	lea    edx,[esp+0x44]
  5cd953:	89 4c 24 44          	mov    DWORD PTR [esp+0x44],ecx
  5cd957:	52                   	push   edx
  5cd958:	8d 84 24 a4 00 00 00 	lea    eax,[esp+0xa4]
  5cd95f:	8b cf                	mov    ecx,edi
  5cd961:	e8 1a 89 25 00       	call   0x826280
  5cd966:	8b 8c 24 a0 00 00 00 	mov    ecx,DWORD PTR [esp+0xa0]
  5cd96d:	3b 4f 04             	cmp    ecx,DWORD PTR [edi+0x4]
  5cd970:	0f 84 fe 02 00 00    	je     0x5cdc74
  5cd976:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  5cd979:	85 c0                	test   eax,eax
  5cd97b:	0f 84 f3 02 00 00    	je     0x5cdc74
  5cd981:	0f b7 48 04          	movzx  ecx,WORD PTR [eax+0x4]
  5cd985:	66 85 c9             	test   cx,cx
  5cd988:	0f 84 e6 02 00 00    	je     0x5cdc74
  5cd98e:	8b 38                	mov    edi,DWORD PTR [eax]
  5cd990:	8b f1                	mov    esi,ecx
  5cd992:	89 74 24 44          	mov    DWORD PTR [esp+0x44],esi
  5cd996:	e8 15 75 eb ff       	call   0x484eb0
  5cd99b:	50                   	push   eax
  5cd99c:	8b c6                	mov    eax,esi
  5cd99e:	8b cf                	mov    ecx,edi
  5cd9a0:	e8 8b 2b f6 ff       	call   0x530530
  5cd9a5:	8b d8                	mov    ebx,eax
  5cd9a7:	e8 04 75 eb ff       	call   0x484eb0
  5cd9ac:	50                   	push   eax
  5cd9ad:	8b c6                	mov    eax,esi
  5cd9af:	8b cf                	mov    ecx,edi
  5cd9b1:	e8 0a 2c f6 ff       	call   0x5305c0
  5cd9b6:	89 44 24 6c          	mov    DWORD PTR [esp+0x6c],eax
  5cd9ba:	e8 f1 74 eb ff       	call   0x484eb0
  5cd9bf:	50                   	push   eax
  5cd9c0:	8b c6                	mov    eax,esi
  5cd9c2:	8b cf                	mov    ecx,edi
  5cd9c4:	e8 87 2c f6 ff       	call   0x530650
  5cd9c9:	8d 74 24 70          	lea    esi,[esp+0x70]
  5cd9cd:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  5cd9d1:	e8 3a 34 26 00       	call   0x830e10
  5cd9d6:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0xf
  5cd9dd:	0f 
  5cd9de:	0f 57 c0             	xorps  xmm0,xmm0
  5cd9e1:	33 c0                	xor    eax,eax
  5cd9e3:	89 44 24 70          	mov    DWORD PTR [esp+0x70],eax
  5cd9e7:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  5cd9ee:	57                   	push   edi
  5cd9ef:	8b                   	.byte 0x8b
```
### VA `0x00596390` / raw `0x00195790` (570 bytes)

```asm
00596390 <.data>:
  596390:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  596397:	bf 01 00 00 00       	mov    edi,0x1
  59639c:	75 22                	jne    0x5963c0
  59639e:	09 3d ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,edi
  5963a4:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5963a7:	e8 f4 b9 13 00       	call   0x6d1da0
  5963ac:	68 30 e3 bc 00       	push   0xbce330
  5963b1:	e8 64 bf 2f 00       	call   0x89231a
  5963b6:	83 c4 04             	add    esp,0x4
  5963b9:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5963c0:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  5963c7:	a1 24 f6 fd 00       	mov    eax,ds:0xfdf624
  5963cc:	8b 30                	mov    esi,DWORD PTR [eax]
  5963ce:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  5963d1:	75 26                	jne    0x5963f9
  5963d3:	09 3d ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,edi
  5963d9:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  5963e0:	e8 bb b9 13 00       	call   0x6d1da0
  5963e5:	68 30 e3 bc 00       	push   0xbce330
  5963ea:	e8 2b bf 2f 00       	call   0x89231a
  5963ef:	83 c4 04             	add    esp,0x4
  5963f2:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5963f9:	8b 0d 24 f6 fd 00    	mov    ecx,DWORD PTR ds:0xfdf624
  5963ff:	89 4d d0             	mov    DWORD PTR [ebp-0x30],ecx
  596402:	3b f1                	cmp    esi,ecx
  596404:	0f 84 ac 01 00 00    	je     0x5965b6
  59640a:	80 7d f1 00          	cmp    BYTE PTR [ebp-0xf],0x0
  59640e:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  596411:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  596414:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  596417:	74 24                	je     0x59643d
  596419:	81 fe f9 2a 00 00    	cmp    esi,0x2af9
  59641f:	72 08                	jb     0x596429
  596421:	81 fe fa 2a 00 00    	cmp    esi,0x2afa
  596427:	76 14                	jbe    0x59643d
  596429:	8b 10                	mov    edx,DWORD PTR [eax]
  59642b:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  59642e:	e9 7a 01 00 00       	jmp    0x5965ad
  596433:	68 34 20 bf 00       	push   0xbf2034
  596438:	e8 f3 76 2e 00       	call   0x87db30
  59643d:	32 db                	xor    bl,bl
  59643f:	e8 9c e8 13 00       	call   0x6d4ce0
  596444:	83 f8 01             	cmp    eax,0x1
  596447:	0f 85 96 00 00 00    	jne    0x5964e3
  59644d:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  596450:	85 c9                	test   ecx,ecx
  596452:	74 11                	je     0x596465
  596454:	8b 01                	mov    eax,DWORD PTR [ecx]
  596456:	8b 90 ec 00 00 00    	mov    edx,DWORD PTR [eax+0xec]
  59645c:	56                   	push   esi
  59645d:	ff d2                	call   edx
  59645f:	84 c0                	test   al,al
  596461:	74 02                	je     0x596465
  596463:	b3 01                	mov    bl,0x1
  596465:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  596469:	0f 85 fd 00 00 00    	jne    0x59656c
  59646f:	84 db                	test   bl,bl
  596471:	0f 85 f9 00 00 00    	jne    0x596570
  596477:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  59647a:	8d 45 dc             	lea    eax,[ebp-0x24]
  59647d:	50                   	push   eax
  59647e:	8d 8f 80 00 00 00    	lea    ecx,[edi+0x80]
  596484:	8d 45 e0             	lea    eax,[ebp-0x20]
  596487:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  59648a:	e8 71 8a 29 00       	call   0x82ef00
  59648f:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  596492:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  596498:	74 35                	je     0x5964cf
  59649a:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  59649d:	8b 59 04             	mov    ebx,DWORD PTR [ecx+0x4]
  5964a0:	8b 3b                	mov    edi,DWORD PTR [ebx]
  5964a2:	3b fb                	cmp    edi,ebx
  5964a4:	74 26                	je     0x5964cc
  5964a6:	eb 08                	jmp    0x5964b0
  5964a8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5964af:	90                   	nop
  5964b0:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  5964b3:	8b 11                	mov    edx,DWORD PTR [ecx]
  5964b5:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5964bb:	56                   	push   esi
  5964bc:	ff d0                	call   eax
  5964be:	84 c0                	test   al,al
  5964c0:	0f 85 aa 00 00 00    	jne    0x596570
  5964c6:	8b 3f                	mov    edi,DWORD PTR [edi]
  5964c8:	3b fb                	cmp    edi,ebx
  5964ca:	75 e4                	jne    0x5964b0
  5964cc:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  5964cf:	8b 17                	mov    edx,DWORD PTR [edi]
  5964d1:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  5964d7:	56                   	push   esi
  5964d8:	8b cf                	mov    ecx,edi
  5964da:	ff d0                	call   eax
  5964dc:	84 c0                	test   al,al
  5964de:	e9 8b 00 00 00       	jmp    0x59656e
  5964e3:	83 f8 03             	cmp    eax,0x3
  5964e6:	0f 85 b6 00 00 00    	jne    0x5965a2
  5964ec:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  5964ef:	85 c9                	test   ecx,ecx
  5964f1:	74 11                	je     0x596504
  5964f3:	8b 11                	mov    edx,DWORD PTR [ecx]
  5964f5:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5964fb:	56                   	push   esi
  5964fc:	ff d0                	call   eax
  5964fe:	84 c0                	test   al,al
  596500:	74 02                	je     0x596504
  596502:	b3 01                	mov    bl,0x1
  596504:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  596508:	75 62                	jne    0x59656c
  59650a:	84 db                	test   bl,bl
  59650c:	75 62                	jne    0x596570
  59650e:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  596511:	8d 4d dc             	lea    ecx,[ebp-0x24]
  596514:	51                   	push   ecx
  596515:	8d 8f 80 00 00 00    	lea    ecx,[edi+0x80]
  59651b:	8d 45 d8             	lea    eax,[ebp-0x28]
  59651e:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  596521:	e8 da 89 29 00       	call   0x82ef00
  596526:	8b 45 d8             	mov    eax,DWORD PTR [ebp-0x28]
  596529:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  59652f:	74 2a                	je     0x59655b
  596531:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  596534:	8b 5a 04             	mov    ebx,DWORD PTR [edx+0x4]
  596537:	8b 3b                	mov    edi,DWORD PTR [ebx]
  596539:	3b fb                	cmp    edi,ebx
  59653b:	74 1b                	je     0x596558
  59653d:	8d 49 00             	lea    ecx,[ecx+0x0]
  596540:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  596543:	8b 01                	mov    eax,DWORD PTR [ecx]
  596545:	8b 90 f0 00 00 00    	mov    edx,DWORD PTR [eax+0xf0]
  59654b:	56                   	push   esi
  59654c:	ff d2                	call   edx
  59654e:	84 c0                	test   al,al
  596550:	75 1e                	jne    0x596570
  596552:	8b 3f                	mov    edi,DWORD PTR [edi]
  596554:	3b fb                	cmp    edi,ebx
  596556:	75 e8                	jne    0x596540
  596558:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  59655b:	8b 07                	mov    eax,DWORD PTR [edi]
  59655d:	8b 90 f0 00 00 00    	mov    edx,DWORD PTR [eax+0xf0]
  596563:	56                   	push   esi
  596564:	8b cf                	mov    ecx,edi
  596566:	ff d2                	call   edx
  596568:	84 c0                	test   al,al
  59656a:	eb 02                	jmp    0x59656e
  59656c:	84 db                	test   bl,bl
  59656e:	74 32                	je     0x5965a2
  596570:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  596573:	8b 37                	mov    esi,DWORD PTR [edi]
  596575:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  596578:	8d 45 d4             	lea    eax,[ebp-0x2c]
  59657b:	50                   	push   eax
  59657c:	51                   	push   ecx
  59657d:	56                   	push   esi
  59657e:	e8 7d 71 1b 00       	call   0x74d700
  596583:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  596586:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  59658b:	2b d1                	sub    edx,ecx
  59658d:	83 fa 01             	cmp    edx,0x1
  596590:	0f 82 9d fe ff ff    	jb     0x596433
  596596:	41                   	inc    ecx
  596597:	89 4f 04             	mov    DWORD PTR [edi+0x4],ecx
  59659a:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  59659d:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  5965a0:	89 01                	mov    DWORD PTR [ecx],eax
  5965a2:	8b 55 e8             	mov    edx,DWORD PTR [ebp-0x18]
  5965a5:	8b 02                	mov    eax,DWORD PTR [edx]
  5965a7:	8b 4d d0             	mov    ecx,DWORD PTR [ebp-0x30]
  5965aa:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5965ad:	39 4d e8             	cmp    DWORD PTR [ebp-0x18],ecx
  5965b0:	0f 85 54 fe ff ff    	jne    0x59640a
  5965b6:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5965b9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5965c0:	59                   	pop    ecx
  5965c1:	5f                   	pop    edi
  5965c2:	5e                   	pop    esi
  5965c3:	5b                   	pop    ebx
  5965c4:	8b e5                	mov    esp,ebp
  5965c6:	5d                   	pop    ebp
  5965c7:	c2 04 00             	ret    0x4
```
### VA `0x006d4c06` / raw `0x002d4006` (200 bytes)

```asm
006d4c06 <.data>:
  6d4c06:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6d4c09:	8b 00                	mov    eax,DWORD PTR [eax]
  6d4c0b:	8b 38                	mov    edi,DWORD PTR [eax]
  6d4c0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  6d4c10:	3b f8                	cmp    edi,eax
  6d4c12:	0f 84 a8 00 00 00    	je     0x6d4cc0
  6d4c18:	eb 06                	jmp    0x6d4c20
  6d4c1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  6d4c20:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6d4c23:	8d 8e ef d8 ff ff    	lea    ecx,[esi-0x2711]
  6d4c29:	81 f9 0e 27 00 00    	cmp    ecx,0x270e
  6d4c2f:	77 51                	ja     0x6d4c82
  6d4c31:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4c38:	75 23                	jne    0x6d4c5d
  6d4c3a:	83 0d ec f3 fd 00 01 	or     DWORD PTR ds:0xfdf3ec,0x1
  6d4c41:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  6d4c48:	e8 53 d1 ff ff       	call   0x6d1da0
  6d4c4d:	68 30 e3 bc 00       	push   0xbce330
  6d4c52:	e8 c3 d6 1b 00       	call   0x89231a
  6d4c57:	83 c4 04             	add    esp,0x4
  6d4c5a:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4c5d:	8d 55 08             	lea    edx,[ebp+0x8]
  6d4c60:	52                   	push   edx
  6d4c61:	8d 45 f0             	lea    eax,[ebp-0x10]
  6d4c64:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4c69:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  6d4c6c:	e8 8f a2 15 00       	call   0x82ef00
  6d4c71:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  6d4c74:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4c7a:	74 39                	je     0x6d4cb5
  6d4c7c:	c6 40 10 00          	mov    BYTE PTR [eax+0x10],0x0
  6d4c80:	eb 33                	jmp    0x6d4cb5
  6d4c82:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4c89:	75 23                	jne    0x6d4cae
  6d4c8b:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  6d4c92:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  6d4c99:	e8 b2 ba ff ff       	call   0x6d0750
  6d4c9e:	68 30 d5 bc 00       	push   0xbcd530
  6d4ca3:	e8 72 d6 1b 00       	call   0x89231a
  6d4ca8:	83 c4 04             	add    esp,0x4
  6d4cab:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4cae:	c6 86 04 90 fb 00 00 	mov    BYTE PTR [esi+0xfb9004],0x0
  6d4cb5:	8b 3f                	mov    edi,DWORD PTR [edi]
  6d4cb7:	3b 7d ec             	cmp    edi,DWORD PTR [ebp-0x14]
  6d4cba:	0f 85 60 ff ff ff    	jne    0x6d4c20
  6d4cc0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4cc3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4cca:	59                   	pop    ecx
  6d4ccb:	5f                   	pop    edi
  6d4ccc:	5e                   	pop    esi
  6d4ccd:	5b                   	pop    ebx
```

## 可重現的呼叫掃描（原始 BIN）

- Direct E8 target `0x6d4ce0`：0x59624e, 0x59643f。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x6d4dc0`：0x594672, 0x5946cb, 0x59471b, 0x5947fd, 0x59484d, 0x59492f, 0x59497f, 0x594cd4, 0x594dc4, 0x594eb4, 0x594fa4, 0x595094, 0x595184, 0x595274, 0x595364, 0x595454, 0x595544, 0x595634, 0x595724, 0x595814, 0x595901, 0x5959f4, 0x5cd68a, 0x5ce5ba, 0x62b5ba, 0x650e96, 0x650f48, 0x650ff6, 0x6510a4。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x594610`：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x546780`：0x546263。注意僅是 bytes 命中，不是全部可達路徑。

## 明確未解

- 自訂 action mapping 的實際 XML 資料與儲存 writer 尚未連上。
- 玩家 V 短按／長按、Z 長按自動續段、普通攻擊與技能前後銜接的 queue、cancel window 均尚無直接跨函式證據。
- 間接函式、物件類型與多執行緒事件來源應繼續按實例校驗，不可單憑相同 offset 或名稱視為相等。