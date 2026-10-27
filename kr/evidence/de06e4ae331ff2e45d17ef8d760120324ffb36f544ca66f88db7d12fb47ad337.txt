# T10-47 — 映射查詢結果至字串／顯示格式轉換的多路分支

- 產生時間：2026-10-28T01:40:26+08:00（Asia/Taipei）
- BIN：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE：`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- BIN PE `.text` 解碼採 VA = `0x401000 + (file_offset - 0x400)`；以下 raw offset = VA − 0x401000 + 0x400，僅適用 `.text`。
- 只做唯讀靜態分析；沒有啟動／附加／修改遊戲，也沒有把 AI fixture 視為原生結論。
- T10-45 後續連號；REBASE-01/02 不佔正式段號；過去筆記的主張須與 T01 限定整合及 BIN 直接核對分開。

## 本段原生核對與限定結論

### 已確認資料流
- `0x594610` 入參從 ECX 收 EDI，EDX 收 ESI，`[ebp+8]`另存；`0x594664/0x594666` 推入參數 2 與 EDI 呼叫 `0x6D4DC0`，回傳一個映射結果集合。
- 僅在 EDI==`0x18` 時，`0x5946CB`、`0x59471B` 另外查 `0x0D`/`0x0E`；當資料集合非空且 `[ebp+0xC] != 0` 時優先走 `0x594A80`，否則走 `0x594570`。原報告也有 EDI==`0x19` 時另一組查詢，這裡不能直接命名 combo 或特定按鍵。
- `0x594A80` 抽取 DWORD 裡不同 byte 字段，以 `0x4026E0`、`0x4041F0`、`0x402160` 操作目的緩衝，表現為格式化／組裝用的下游；不是已證明會將玩家按下 event 寫入 `FB9004`。
### 反證與缺口
- `0x594610` 的存在可證多組映射結果被查詢、合併／格式化，**不能證明輸出的字串一定是設定 UI、可編輯綁定存檔，或含實時事件路徑**。
- `0x18`/`0x19` 是選擇器值而非已證 Z+X/Z+C 或 24/25 段普攻。
- 要確認是否影響實時行為，必須追 `0x6D4DC0` 返回資料的 **producer** 與 `0x594610` 的 **caller**，不能只追 formatter 的 byte 結構。
### 後續可接續的追查
1. 逐個按 direct E8 caller 位置選讀，追 `0x594610` 上游 ECX/EDX 與 flag byte。
2. 找容器 `0xFB8834`/`0xFDF3F4` 的非零元素寫入者與配置器、XML 解析器，確認來源欄位。
3. 以 exact instance 辨識 `0x594570` 和 `0x594A80` 的接收資料格式，避免和實時 phase 混淆。


## 目標位址與原始 PE bytes 證據

### VA `0x00594610` / raw `0x00193A10` / window `832` bytes

```asm
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
  59494d:	8d                   	.byte 0x8d
  59494e:	74 24                	je     0x594974
```

### VA `0x00594A80` / raw `0x00193E80` / window `144` bytes

```asm
  594a80:	55                   	push   ebp
  594a81:	8b ec                	mov    ebp,esp
  594a83:	53                   	push   ebx
  594a84:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  594a87:	8b c3                	mov    eax,ebx
  594a89:	c1 e8 10             	shr    eax,0x10
  594a8c:	84 c0                	test   al,al
  594a8e:	74 41                	je     0x594ad1
  594a90:	0f b6 c0             	movzx  eax,al
  594a93:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594a9a:	6a ff                	push   0xffffffff
  594a9c:	2b c8                	sub    ecx,eax
  594a9e:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594aa2:	6a 00                	push   0x0
  594aa4:	52                   	push   edx
  594aa5:	8b ce                	mov    ecx,esi
  594aa7:	e8 34 dc e6 ff       	call   0x4026e0
  594aac:	84 db                	test   bl,bl
  594aae:	74 54                	je     0x594b04
  594ab0:	0f b6 c3             	movzx  eax,bl
  594ab3:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594aba:	6a ff                	push   0xffffffff
  594abc:	2b c8                	sub    ecx,eax
  594abe:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594ac2:	6a 00                	push   0x0
  594ac4:	52                   	push   edx
  594ac5:	8b ce                	mov    ecx,esi
  594ac7:	e8 24 f7 e6 ff       	call   0x4041f0
  594acc:	5b                   	pop    ebx
  594acd:	5d                   	pop    ebp
  594ace:	c2 04 00             	ret    0x4
  594ad1:	84 db                	test   bl,bl
  594ad3:	74 21                	je     0x594af6
  594ad5:	0f b6 c3             	movzx  eax,bl
  594ad8:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594adf:	6a ff                	push   0xffffffff
  594ae1:	2b c8                	sub    ecx,eax
  594ae3:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594ae7:	6a 00                	push   0x0
  594ae9:	52                   	push   edx
  594aea:	8b ce                	mov    ecx,esi
  594aec:	e8 ef db e6 ff       	call   0x4026e0
  594af1:	5b                   	pop    ebx
  594af2:	5d                   	pop    ebp
  594af3:	c2 04 00             	ret    0x4
  594af6:	6a 00                	push   0x0
  594af8:	68 fc d1 be 00       	push   0xbed1fc
  594afd:	8b ce                	mov    ecx,esi
  594aff:	e8 5c d6 e6 ff       	call   0x402160
  594b04:	5b                   	pop    ebx
  594b05:	5d                   	pop    ebp
  594b06:	c2 04 00             	ret    0x4
  594b09:	cc                   	int3
  594b0a:	cc                   	int3
  594b0b:	cc                   	int3
  594b0c:	cc                   	int3
  594b0d:	cc                   	int3
  594b0e:	cc                   	int3
  594b0f:	cc                   	int3
```

### VA `0x00594570` / raw `0x00193970` / window `272` bytes

```asm
  594570:	55                   	push   ebp
  594571:	8b ec                	mov    ebp,esp
  594573:	53                   	push   ebx
  594574:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  594577:	56                   	push   esi
  594578:	8b f0                	mov    esi,eax
  59457a:	8b c3                	mov    eax,ebx
  59457c:	c1 e8 10             	shr    eax,0x10
  59457f:	84 c0                	test   al,al
  594581:	74 4e                	je     0x5945d1
  594583:	0f b6 c0             	movzx  eax,al
  594586:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  59458d:	6a ff                	push   0xffffffff
  59458f:	2b c8                	sub    ecx,eax
  594591:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594595:	6a 00                	push   0x0
  594597:	52                   	push   edx
  594598:	8b ce                	mov    ecx,esi
  59459a:	e8 41 e1 e6 ff       	call   0x4026e0
  59459f:	84 db                	test   bl,bl
  5945a1:	74 62                	je     0x594605
  5945a3:	6a 03                	push   0x3
  5945a5:	68 54 b3 c1 00       	push   0xc1b354
  5945aa:	e8 51 fd e6 ff       	call   0x404300
  5945af:	0f b6 c3             	movzx  eax,bl
  5945b2:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  5945b9:	6a ff                	push   0xffffffff
  5945bb:	2b c8                	sub    ecx,eax
  5945bd:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  5945c1:	6a 00                	push   0x0
  5945c3:	52                   	push   edx
  5945c4:	8b ce                	mov    ecx,esi
  5945c6:	e8 25 fc e6 ff       	call   0x4041f0
  5945cb:	5e                   	pop    esi
  5945cc:	5b                   	pop    ebx
  5945cd:	5d                   	pop    ebp
  5945ce:	c2 04 00             	ret    0x4
  5945d1:	84 db                	test   bl,bl
  5945d3:	74 22                	je     0x5945f7
  5945d5:	0f b6 c3             	movzx  eax,bl
  5945d8:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  5945df:	6a ff                	push   0xffffffff
  5945e1:	2b c8                	sub    ecx,eax
  5945e3:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  5945e7:	6a 00                	push   0x0
  5945e9:	52                   	push   edx
  5945ea:	8b ce                	mov    ecx,esi
  5945ec:	e8 ef e0 e6 ff       	call   0x4026e0
  5945f1:	5e                   	pop    esi
  5945f2:	5b                   	pop    ebx
  5945f3:	5d                   	pop    ebp
  5945f4:	c2 04 00             	ret    0x4
  5945f7:	6a 00                	push   0x0
  5945f9:	68 fc d1 be 00       	push   0xbed1fc
  5945fe:	8b ce                	mov    ecx,esi
  594600:	e8 5b db e6 ff       	call   0x402160
  594605:	5e                   	pop    esi
  594606:	5b                   	pop    ebx
  594607:	5d                   	pop    ebp
  594608:	c2 04 00             	ret    0x4
  59460b:	cc                   	int3
  59460c:	cc                   	int3
  59460d:	cc                   	int3
  59460e:	cc                   	int3
  59460f:	cc                   	int3
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
```

## Direct E8 relative call 候選（機械搜尋，不等同完整 CFG）

- `0x00594610`：9 個候選指令位址：`0x005CD91F`, `0x005D1B75`, `0x005D2DD5`, `0x005D4045`, `0x0060E06B`, `0x00651122`, `0x0065117E`, `0x006511DA`, `0x0065120A`

- `0x00594A80`：9 個候選指令位址：`0x005946ED`, `0x0059473D`, `0x0059481F`, `0x0059486F`, `0x00594951`, `0x005949A1`, `0x00594A2C`, `0x005CD6BF`, `0x005CE5E7`

- `0x00594570`：28 個候選指令位址：`0x005946FF`, `0x00594753`, `0x00594831`, `0x00594885`, `0x00594963`, `0x005949B7`, `0x00594A38`, `0x00594CFD`, `0x00594DED`, `0x00594EDD`, `0x00594FCD`, `0x005950BD`, `0x005951AD`, `0x0059529D`, `0x0059538D`, `0x0059547D`, `0x0059556D`, `0x0059565D`, `0x0059574D`, `0x0059583D`, `0x0059592A`, `0x00595A1D`, `0x00628EF6`, `0x006294A6`, `0x00650EC3`, `0x00650F75`, `0x00651023`, `0x006510D1`

## 記錄品質／驗收界線
- 本段第一手原始 bytes 是上述每段 BIN window，由 GNU objdump i386 解析；窗口起點選自既有函式入口，遇內部跳轉目標超出窗口時需另定位反組譯，不能把未列入的分支稱不存在。
- E8 搜尋依 direct rel32 靜態匹配（可能偽陽性），只屬候選來源，不包含 indirect/vtable/tailcall。
- PE raw vs flat 位址混淆應每次由原始 PE section header 檢查，絕不把本報告的局部核對推廣為整個反編譯索引皆正確。
- 本段不宣稱 Z/X/C/V 特定綁定、V 蓄氣、Z held 自動續段、queue/cancel 已閉合；亦不新增動作／伺服器規則或修改程式。
- GitHub 送交狀態以實際遠端 Commit+讀回為準；本檔在本機完成不等於已提交。