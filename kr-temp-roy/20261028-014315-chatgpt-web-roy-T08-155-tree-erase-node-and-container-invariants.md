# KR T08-155 — tree erase node and container invariants

- 研究時間：2026-10-28T01:43:15+08:00 Asia/Taipei；研究者：`chatgpt-web roy`。
- KR 原始檔：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本地實際重新核對）；唯讀靜態分析，未啟動或修改程式。
- 原始碼來源：本次使用 GNU objdump 對 PE32 `.text` 的 VA 反組譯及 E8 相對目的地直接核查。**完整 `.text` 線性反組譯掃描只建立 direct-call 候選集合，不等同完整 CFG，亦可能包括誤解碼區。**
- GitHub 整合：前次查核 main HEAD `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；最新 HEAD 需於提交前複核。正式 T08 為 0007 建立／登記／移除資料介面；不替代 T02/T06/T07 分工。
- 歷史來源：T08-153 及整合重審-01/02；保留本次覆核與舊報告證據等級差異。

## 首要結論

`0x007B6890..0x007B6AEB` 不負責 actor vtable 清理；其執行的是**通用紅黑樹樣式（顏色 byte +0x14；nil flag +0x15）的結構移除**，最後呼叫 `0x89120C` 釋放節點，計數若非 0 則減 1，並在 iterator 輸出寫回後 `ret 0x0C`。確定其可被多種非 actor 容器共用，不能將呼叫此 helper 解讀為原生實體銷毀。

### 1. 入口、實參及標記

- `0x7B6893 mov eax,[ebp+0x10]`：第三個 stack 參數是待 erase 節點；`[node+0x15]` 作為 nil sentinel 檢查。
- `0x7B68AB mov ebx,eax`、`0x7B68B4 call 0x49E6A0`：先建立返回 iterator／暫存資訊；`0x49E6A0` 語意需另行核對。
- `node+0x00/+0x08`：child links，`node+0x04` parent，`node+0x14` 顏色／平衡旗標，`+0x15` nil flag。這套 layout 由多個分支直接讀寫支持。
- 依據 `0x7B68DD..0x7B69B6` 可見移除節點對父子鏈與容器 head 邊界做修補；`0x7B69D0..0x7B6AC0` 執行顏色／旋轉等平衡處置，轉動交 `0x43E670`、`0x763F60`。
- 終端 `0x7B6AC3..0x7B6AEB` free old node，計數安全減 1，回填輸出 iterator。

### 2. 一手關鍵原始指令：入口至 unlink

```asm
  7b6890:	55                   	push   ebp
  7b6891:	8b ec                	mov    ebp,esp
  7b6893:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b6896:	83 ec 08             	sub    esp,0x8
  7b6899:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b689d:	74 0a                	je     0x7b68a9
  7b689f:	68 28 d2 be 00       	push   0xbed228
  7b68a4:	e8 d4 72 0c 00       	call   0x87db7d
  7b68a9:	53                   	push   ebx
  7b68aa:	56                   	push   esi
  7b68ab:	8b d8                	mov    ebx,eax
  7b68ad:	57                   	push   edi
  7b68ae:	8d 45 10             	lea    eax,[ebp+0x10]
  7b68b1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7b68b4:	e8 e7 7d ce ff       	call   0x49e6a0
  7b68b9:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b68bb:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b68bf:	74 05                	je     0x7b68c6
  7b68c1:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7b68c4:	eb 17                	jmp    0x7b68dd
  7b68c6:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b68c9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b68cd:	74 04                	je     0x7b68d3
  7b68cf:	8b f9                	mov    edi,ecx
  7b68d1:	eb 0a                	jmp    0x7b68dd
  7b68d3:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b68d6:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  7b68d9:	3b c3                	cmp    eax,ebx
  7b68db:	75 7c                	jne    0x7b6959
  7b68dd:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b68e1:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  7b68e4:	75 03                	jne    0x7b68e9
  7b68e6:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b68e9:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b68ec:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b68ef:	39 58 04             	cmp    DWORD PTR [eax+0x4],ebx
  7b68f2:	75 05                	jne    0x7b68f9
  7b68f4:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  7b68f7:	eb 0b                	jmp    0x7b6904
  7b68f9:	39 1e                	cmp    DWORD PTR [esi],ebx
  7b68fb:	75 04                	jne    0x7b6901
  7b68fd:	89 3e                	mov    DWORD PTR [esi],edi
  7b68ff:	eb 03                	jmp    0x7b6904
  7b6901:	89 7e 08             	mov    DWORD PTR [esi+0x8],edi
  7b6904:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b6907:	39 18                	cmp    DWORD PTR [eax],ebx
  7b6909:	75 24                	jne    0x7b692f
  7b690b:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b690f:	74 04                	je     0x7b6915
  7b6911:	8b ce                	mov    ecx,esi
  7b6913:	eb 15                	jmp    0x7b692a
  7b6915:	8b 07                	mov    eax,DWORD PTR [edi]
  7b6917:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b691b:	8b cf                	mov    ecx,edi
  7b691d:	75 0b                	jne    0x7b692a
  7b691f:	90                   	nop
  7b6920:	8b c8                	mov    ecx,eax
  7b6922:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6924:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b6928:	74 f6                	je     0x7b6920
  7b692a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b692d:	89 08                	mov    DWORD PTR [eax],ecx
  7b692f:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6932:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  7b6935:	39 59 08             	cmp    DWORD PTR [ecx+0x8],ebx
  7b6938:	75 7c                	jne    0x7b69b6
  7b693a:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b693e:	74 07                	je     0x7b6947
  7b6940:	8b c6                	mov    eax,esi
  7b6942:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6945:	eb 6f                	jmp    0x7b69b6
  7b6947:	8b c7                	mov    eax,edi
  7b6949:	e8 32 d2 06 00       	call   0x823b80
  7b694e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7b6951:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6954:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6957:	eb 5d                	jmp    0x7b69b6
  7b6959:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b695c:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b695e:	89 08                	mov    DWORD PTR [eax],ecx
  7b6960:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b6963:	75 04                	jne    0x7b6969
  7b6965:	8b f0                	mov    esi,eax
  7b6967:	eb 1a                	jmp    0x7b6983
  7b6969:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b696d:	8b 70 04             	mov    esi,DWORD PTR [eax+0x4]
  7b6970:	75 03                	jne    0x7b6975
  7b6972:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b6975:	89 3e                	mov    DWORD PTR [esi],edi
  7b6977:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b697a:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  7b697d:	8b 53 08             	mov    edx,DWORD PTR [ebx+0x8]
  7b6980:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  7b6983:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6986:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  7b6989:	39 59 04             	cmp    DWORD PTR [ecx+0x4],ebx
  7b698c:	75 05                	jne    0x7b6993
  7b698e:	89               	mov    DWORD PTR [ecx+0x4],eax
```

### 3. 一手指令：再平衡與 terminal

```asm
  7b698f:	41                   	inc    ecx
  7b6990:	04 eb                	add    al,0xeb
  7b6992:	0e                   	push   cs
  7b6993:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7b6996:	39 19                	cmp    DWORD PTR [ecx],ebx
  7b6998:	75 04                	jne    0x7b699e
  7b699a:	89 01                	mov    DWORD PTR [ecx],eax
  7b699c:	eb 03                	jmp    0x7b69a1
  7b699e:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b69a1:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7b69a4:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  7b69a7:	8a 53 14             	mov    dl,BYTE PTR [ebx+0x14]
  7b69aa:	8a 48 14             	mov    cl,BYTE PTR [eax+0x14]
  7b69ad:	88 50 14             	mov    BYTE PTR [eax+0x14],dl
  7b69b0:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69b3:	88 4b 14             	mov    BYTE PTR [ebx+0x14],cl
  7b69b6:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7b69b9:	b3 01                	mov    bl,0x1
  7b69bb:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b69be:	0f 85 ff 00 00 00    	jne    0x7b6ac3
  7b69c4:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b69c7:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b69ca:	0f 84 f0 00 00 00    	je     0x7b6ac0
  7b69d0:	38 5f 14             	cmp    BYTE PTR [edi+0x14],bl
  7b69d3:	0f 85 e7 00 00 00    	jne    0x7b6ac0
  7b69d9:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b69db:	3b f9                	cmp    edi,ecx
  7b69dd:	75 69                	jne    0x7b6a48
  7b69df:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69e2:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b69e6:	75 15                	jne    0x7b69fd
  7b69e8:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b69eb:	52                   	push   edx
  7b69ec:	8b ce                	mov    ecx,esi
  7b69ee:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b69f2:	e8 69 d5 fa ff       	call   0x763f60
  7b69f7:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69fa:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69fd:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a01:	75 78                	jne    0x7b6a7b
  7b6a03:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a05:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a08:	75 08                	jne    0x7b6a12
  7b6a0a:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a0d:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a10:	74 65                	je     0x7b6a77
  7b6a12:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a15:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a18:	75 15                	jne    0x7b6a2f
  7b6a1a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a1c:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a1f:	52                   	push   edx
  7b6a20:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a24:	e8 47 7c c8 ff       	call   0x43e670
  7b6a29:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b6a2c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a2f:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6a32:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6a35:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6a38:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  7b6a3b:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a3e:	52                   	push   edx
  7b6a3f:	8b ce                	mov    ecx,esi
  7b6a41:	e8 1a d5 fa ff       	call   0x763f60
  7b6a46:	eb 78                	jmp    0x7b6ac0
  7b6a48:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b6a4c:	75 14                	jne    0x7b6a62
  7b6a4e:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a51:	52                   	push   edx
  7b6a52:	8b ce                	mov    ecx,esi
  7b6a54:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b6a58:	e8 13 7c c8 ff       	call   0x43e670
  7b6a5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6a5f:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a62:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a66:	75 13                	jne    0x7b6a7b
  7b6a68:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a6b:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a6e:	75 1e                	jne    0x7b6a8e
  7b6a70:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a72:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a75:	75 17                	jne    0x7b6a8e
  7b6a77:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a7b:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6a7e:	8b fe                	mov    edi,esi
  7b6a80:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  7b6a83:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b6a86:	0f 85 44 ff ff ff    	jne    0x7b69d0
  7b6a8c:	eb 32                	jmp    0x7b6ac0
  7b6a8e:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a90:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a93:	75 15                	jne    0x7b6aaa
  7b6a95:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a98:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a9b:	52                   	push   edx
  7b6a9c:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6aa0:	e8 bb d4 fa ff       	call   0x763f60
  7b6aa5:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6aa7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6aaa:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6aad:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6ab0:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6ab3:	8b 09                	mov    ecx,DWORD PTR [ecx]
  7b6ab5:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6ab8:	52                   	push   edx
  7b6ab9:	8b ce                	mov    ecx,esi
  7b6abb:	e8 b0 7b c8 ff       	call   0x43e670
  7b6ac0:	88 5f 14             	mov    BYTE PTR [edi+0x14],bl
  7b6ac3:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b6ac6:	52                   	push   edx
  7b6ac7:	e8 40 a7 0d 00       	call   0x89120c
  7b6acc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6acf:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6ad2:	83 c4 04             	add    esp,0x4
  7b6ad5:	5f                   	pop    edi
  7b6ad6:	5e                   	pop    esi
  7b6ad7:	5b                   	pop    ebx
  7b6ad8:	85 c0                	test   eax,eax
  7b6ada:	74 04                	je     0x7b6ae0
  7b6adc:	48                   	dec    eax
  7b6add:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6ae0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7b6ae3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b6ae6:	89 08                	mov    DWORD PTR [eax],ecx
  7b6ae8:	8b e5                	mov    esp,ebp
  7b6aea:	5d                   	pop    ebp
  7b6aeb:	c2               	ret    0xc
```

### 4. 呼叫端對照與 receiver 注意事項

以下為**全 `.text` 線性掃描的直接 E8 候選**；不同 caller 的 receiver 不能因使用同一 helper 就混為 GameInfo。

```text
40ae7f:	e8 0c ba 3a 00       	call   0x7b6890
40ae93:	e8 f8 b9 3a 00       	call   0x7b6890
410e79:	e8 12 5a 3a 00       	call   0x7b6890
411c8e:	e8 fd 4b 3a 00       	call   0x7b6890
44e468:	e8 23 84 36 00       	call   0x7b6890
4b65eb:	e8 a0 02 30 00       	call   0x7b6890
4b681a:	e8 71 00 30 00       	call   0x7b6890
4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
4dfce1:	e8 aa 6b 2d 00       	call   0x7b6890
4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
53c2e0:	e8 ab a5 27 00       	call   0x7b6890
553793:	e8 f8 30 26 00       	call   0x7b6890
5538a7:	e8 e4 2f 26 00       	call   0x7b6890
554144:	e8 47 27 26 00       	call   0x7b6890
5ca7a1:	e8 ea c0 1e 00       	call   0x7b6890
5e55fe:	e8 8d 12 1d 00       	call   0x7b6890
61d059:	e8 32 98 19 00       	call   0x7b6890
61d4ce:	e8 bd 93 19 00       	call   0x7b6890
73f8c9:	e8 c2 6f 07 00       	call   0x7b6890
748652:	e8 39 e2 06 00       	call   0x7b6890
749e31:	e8 5a ca 06 00       	call   0x7b6890
7644ff:	e8 8c 23 05 00       	call   0x7b6890
7b6071:	e8 1a 08 00 00       	call   0x7b6890
7b612f:	e8 5c 07 00 00       	call   0x7b6890
7b64e9:	e8 a2 03 00 00       	call   0x7b6890
7b6527:	e8 64 03 00 00       	call   0x7b6890
7b6e68:	e8 23 fa ff ff       	call   0x7b6890
806cb3:	e8 d8 fb fa ff       	call   0x7b6890
82e1fc:	e8 8f 86 f8 ff       	call   0x7b6890
```

GameInfo 單 key 刪除 `0x4DFC1E`、另樹關聯清除 `0x4DFC80`、按 `actor+0x88` 批次 `0x4DFCE1`、型別條件移除 `0x4DFE24` 均進入同一通用 helper。這證明**erase 的容器實現共享**，而非證明物件被同一管線管理。前端各自釋放 `node+0x10` 指向的物件、或先清 reference，再讓 helper 只處理節點。

### 5. 限定偽碼與可測不變量

```cpp
// 粗粒度重構；不是可編譯版，也不保證 red-black 演算法細節。
Iterator eraseNode(Tree* t, Node* requested) {
    assert(!requested->isNil);             // 原版走診斷分支，不是 C++ assert 證據
    Iterator next = successor(requested);  // 0x49E6A0 間接關聯待核
    Node* doomed = detachAndRebalance(t, requested);
    rawFree(doomed);                      // call 0x89120C
    if (t->size != 0) --t->size;
    return next;
}
```

**需保留的差異與安全邊界**：`0x7B6890` 不認識 actor+0x04、+0x88、+0x9C；不呼叫 actor vtable+0、+0x14。節點在 erase 後不能再沿其指標走訪。`0x4DFC90` 與 `0x4DFD40` 均使用 erase 回傳／另行 successor 的做法避免遞迴跳過節點。即使在本檔存在很多 `call 7B6890`，也不代表同一場景。下一段 T08-156 要把 full clear 與 ID/domain 分離後做生命週期交叉檢查。