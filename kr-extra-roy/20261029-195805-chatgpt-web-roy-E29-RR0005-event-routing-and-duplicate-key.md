# E29 — RR-0005／RR-0001：0x66C620 事件路由與 connection 重複鍵的邊界
研究時間：2026-10-29T19:58:05+08:00。原始 Tartaros.bin (12,472,320 bytes) SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，當次重驗。只讀反組譯；VA=raw+0x400C00。GitHub main 開工版本 610a822b15346c9e0b69edd4e104c2076f2b59ac；RR-0001/0005 仍 QUEUED，cross-task 支援不正式認領、不修改台帳。
## 第一輪：0x66C090 上游不是已證的 0x13 收包分派
E28 的 0x66C6B9、0x66C713 兩個直接呼叫點都位於函式入口 0x66C620；它從 [event+0x10] 讀出事件碼。branch 0x709 比較 event+8 與 object+0xF0/+0xF4 對應 object+0x20，分別導向 0x66BBD0/0x66C510；0x70A 綁 object+0xF4 指向的 object+0x20 並清三個 +0x90 virtual state 之後 call 0x66C090；0x578 則綁 object+0xF8 的 object+0x20 並清三項 +0x90 state，再以 ECX=0 call 0x66C090。這是具名事件識別值的本地 UI/事件轉派跡象，*不能*把 0x709/0x70A/0x578 直接叫 0x13 packet status 或 wire opcode。
## 第二輪：key=0 已存在時的 delete/insert 本地樹操作
0x806C91 取 [ebp+0x10] connection key address，針對 transport+0x18 tree 呼叫 0x8438C0；若結果不是 end sentinel (transport+0x1C)，先以舊 iterator 呼叫 0x7B6890，然後將 key 與新連線指標放在 stack 暫存，再由 0x57EF20 配置包含 key+Conn* 的節點，交給 0x57E850。0x57EF20 配置 0x18-byte 節點並在 +0x0C 寫 key、+0x10 寫 connection pointer、+0x14 清零。0x57E850 是帶 ordered comparison 的 node insertion search，會比較 node+0x0C key 和待插入 key；實際可能存在重複 key 以及資源回收/替換的更細節，應以 0x7B6890 精確刪除語意與插入返回值再驗收。
## 第三輪：資料流結論及未閉合
已確認由 0x66C620 本地事件 branches 可達 0x66C090→0x4957C0→key0/key2 connect→tree registration；本次補強 duplicate-key 先處理既有 mapping 再插入 newly allocated node 的程式碼。沒有找到 0x13 receive packet handler 到 0x66C620 的已證直接鏈；若需證明仍要從 T03 0x13 consumer 的原生 handler 比對事件如何轉到 0x66C620，不能反方向由 UI 常數猜測。
Client 待逆向：0x66C620 caller/事件生命週期與 T03 auth 0x13 consumer 匹配、0x7B6890 erase semantics、key0/2 error/reconnect。Server 待開發：只依可驗證 client requirements 提出 framed/connection contract。跨功能待整合：T02 RR-0005 與 T03 RR-0003。待遊玩驗證：first socket per key、packet wire/order/pcap。
## 可回放原始 BIN 機器碼（完整有界區段）
### VA 0x66C620–0x66C71B，raw 0x26BA20–0x26BB1B
```asm
  66c620:	55                   	push   ebp
  66c621:	8b ec                	mov    ebp,esp
  66c623:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c626:	56                   	push   esi
  66c627:	8b f1                	mov    esi,ecx
  66c629:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  66c62c:	81 f9 09 07 00 00    	cmp    ecx,0x709
  66c632:	75 33                	jne    0x66c667
  66c634:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  66c637:	8b 8e f0 00 00 00    	mov    ecx,DWORD PTR [esi+0xf0]
  66c63d:	3b 41 20             	cmp    eax,DWORD PTR [ecx+0x20]
  66c640:	75 0b                	jne    0x66c64d
  66c642:	56                   	push   esi
  66c643:	e8 88 f5 ff ff       	call   0x66bbd0
  66c648:	5e                   	pop    esi
  66c649:	5d                   	pop    ebp
  66c64a:	c2 04 00             	ret    0x4
  66c64d:	8b 96 f4 00 00 00    	mov    edx,DWORD PTR [esi+0xf4]
  66c653:	3b 42 20             	cmp    eax,DWORD PTR [edx+0x20]
  66c656:	0f 85 bc 00 00 00    	jne    0x66c718
  66c65c:	56                   	push   esi
  66c65d:	e8 ae fe ff ff       	call   0x66c510
  66c662:	5e                   	pop    esi
  66c663:	5d                   	pop    ebp
  66c664:	c2 04 00             	ret    0x4
  66c667:	81 f9 0a 07 00 00    	cmp    ecx,0x70a
  66c66d:	75 55                	jne    0x66c6c4
  66c66f:	8b 8e f4 00 00 00    	mov    ecx,DWORD PTR [esi+0xf4]
  66c675:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  66c678:	3b 51 20             	cmp    edx,DWORD PTR [ecx+0x20]
  66c67b:	0f 85 97 00 00 00    	jne    0x66c718
  66c681:	57                   	push   edi
  66c682:	8b 78 18             	mov    edi,DWORD PTR [eax+0x18]
  66c685:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c687:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c68d:	6a 00                	push   0x0
  66c68f:	ff d2                	call   edx
  66c691:	8b 8e f0 00 00 00    	mov    ecx,DWORD PTR [esi+0xf0]
  66c697:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c699:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c69f:	6a 00                	push   0x0
  66c6a1:	ff d2                	call   edx
  66c6a3:	8b 8e f8 00 00 00    	mov    ecx,DWORD PTR [esi+0xf8]
  66c6a9:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c6ab:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c6b1:	6a 00                	push   0x0
  66c6b3:	ff d2                	call   edx
  66c6b5:	8b 4f 20             	mov    ecx,DWORD PTR [edi+0x20]
  66c6b8:	56                   	push   esi
  66c6b9:	e8 d2 f9 ff ff       	call   0x66c090
  66c6be:	5f                   	pop    edi
  66c6bf:	5e                   	pop    esi
  66c6c0:	5d                   	pop    ebp
  66c6c1:	c2 04 00             	ret    0x4
  66c6c4:	81 f9 78 05 00 00    	cmp    ecx,0x578
  66c6ca:	75 4c                	jne    0x66c718
  66c6cc:	8b 8e f8 00 00 00    	mov    ecx,DWORD PTR [esi+0xf8]
  66c6d2:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  66c6d5:	3b 51 20             	cmp    edx,DWORD PTR [ecx+0x20]
  66c6d8:	75 3e                	jne    0x66c718
  66c6da:	8b 8e f4 00 00 00    	mov    ecx,DWORD PTR [esi+0xf4]
  66c6e0:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c6e2:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c6e8:	6a 00                	push   0x0
  66c6ea:	ff d2                	call   edx
  66c6ec:	8b 8e f0 00 00 00    	mov    ecx,DWORD PTR [esi+0xf0]
  66c6f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c6f4:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c6fa:	6a 00                	push   0x0
  66c6fc:	ff d2                	call   edx
  66c6fe:	8b 8e f8 00 00 00    	mov    ecx,DWORD PTR [esi+0xf8]
  66c704:	8b 01                	mov    eax,DWORD PTR [ecx]
  66c706:	8b 90 90 00 00 00    	mov    edx,DWORD PTR [eax+0x90]
  66c70c:	6a 00                	push   0x0
  66c70e:	ff d2                	call   edx
  66c710:	56                   	push   esi
  66c711:	33 c9                	xor    ecx,ecx
  66c713:	e8 78 f9 ff ff       	call   0x66c090
  66c718:	5e                   	pop    esi
  66c719:	5d                   	pop    ebp
  66c71a:	c2               	ret    0x4
```
### VA 0x806C91–0x806CD7，raw 0x406091–0x4060D7
```asm
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
```
### VA 0x57EF20–0x57EF61，raw 0x17E320–0x17E361
```asm
  57ef20:	55                   	push   ebp
  57ef21:	8b ec                	mov    ebp,esp
  57ef23:	83 ec 10             	sub    esp,0x10
  57ef26:	6a 18                	push   0x18
  57ef28:	e8 3b 23 31 00       	call   0x891268
  57ef2d:	33 d2                	xor    edx,edx
  57ef2f:	83 c4 04             	add    esp,0x4
  57ef32:	3b c2                	cmp    eax,edx
  57ef34:	74 2a                	je     0x57ef60
  57ef36:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef39:	89 08                	mov    DWORD PTR [eax],ecx
  57ef3b:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef3e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  57ef41:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef44:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  57ef47:	8d 48 0c             	lea    ecx,[eax+0xc]
  57ef4a:	66 89 50 14          	mov    WORD PTR [eax+0x14],dx
  57ef4e:	3b ca                	cmp    ecx,edx
  57ef50:	74 0a                	je     0x57ef5c
  57ef52:	8b 17                	mov    edx,DWORD PTR [edi]
  57ef54:	89 11                	mov    DWORD PTR [ecx],edx
  57ef56:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  57ef59:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  57ef5c:	8b e5                	mov    esp,ebp
  57ef5e:	5d                   	pop    ebp
  57ef5f:	c3                   	ret
  57ef60:	8d               	lea    eax,[ebp-0x4]
```
### VA 0x57E850–0x57E916，raw 0x17DC50–0x17DD16
```asm
  57e850:	55                   	push   ebp
  57e851:	8b ec                	mov    ebp,esp
  57e853:	83 ec 08             	sub    esp,0x8
  57e856:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  57e859:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e85c:	53                   	push   ebx
  57e85d:	57                   	push   edi
  57e85e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  57e861:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  57e864:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e868:	b1 01                	mov    cl,0x1
  57e86a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e86d:	75 1f                	jne    0x57e88e
  57e86f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  57e872:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  57e875:	8b f8                	mov    edi,eax
  57e877:	0f 9c c1             	setl   cl
  57e87a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e87d:	84 c9                	test   cl,cl
  57e87f:	74 04                	je     0x57e885
  57e881:	8b 00                	mov    eax,DWORD PTR [eax]
  57e883:	eb 03                	jmp    0x57e888
  57e885:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  57e888:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e88c:	74 e4                	je     0x57e872
  57e88e:	8b df                	mov    ebx,edi
  57e890:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  57e893:	84 c9                	test   cl,cl
  57e895:	74 3a                	je     0x57e8d1
  57e897:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  57e89a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  57e89d:	3b 38                	cmp    edi,DWORD PTR [eax]
  57e89f:	75 22                	jne    0x57e8c3
  57e8a1:	52                   	push   edx
  57e8a2:	6a 01                	push   0x1
  57e8a4:	8d 55 0c             	lea    edx,[ebp+0xc]
  57e8a7:	8b c7                	mov    eax,edi
  57e8a9:	52                   	push   edx
  57e8aa:	8b f9                	mov    edi,ecx
  57e8ac:	e8 4f d4 ec ff       	call   0x44bd00
  57e8b1:	8b 00                	mov    eax,DWORD PTR [eax]
  57e8b3:	5f                   	pop    edi
  57e8b4:	89 06                	mov    DWORD PTR [esi],eax
  57e8b6:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8ba:	8b c6                	mov    eax,esi
  57e8bc:	5b                   	pop    ebx
  57e8bd:	8b e5                	mov    esp,ebp
  57e8bf:	5d                   	pop    ebp
  57e8c0:	c2 08 00             	ret    0x8
  57e8c3:	8d 45 fc             	lea    eax,[ebp-0x4]
  57e8c6:	e8 d5 0f fc ff       	call   0x53f8a0
  57e8cb:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  57e8ce:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e8d1:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  57e8d4:	52                   	push   edx
  57e8d5:	3b 4a 0c             	cmp    ecx,DWORD PTR [edx+0xc]
  57e8d8:	7d 24                	jge    0x57e8fe
  57e8da:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  57e8dd:	52                   	push   edx
  57e8de:	8d 45 0c             	lea    eax,[ebp+0xc]
  57e8e1:	50                   	push   eax
  57e8e2:	8b c7                	mov    eax,edi
  57e8e4:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  57e8e7:	e8 14 d4 ec ff       	call   0x44bd00
  57e8ec:	8b 08                	mov    ecx,DWORD PTR [eax]
  57e8ee:	5f                   	pop    edi
  57e8ef:	89 0e                	mov    DWORD PTR [esi],ecx
  57e8f1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8f5:	8b c6                	mov    eax,esi
  57e8f7:	5b                   	pop    ebx
  57e8f8:	8b e5                	mov    esp,ebp
  57e8fa:	5d                   	pop    ebp
  57e8fb:	c2 08 00             	ret    0x8
  57e8fe:	e8 09 29 31 00       	call   0x89120c
  57e903:	83 c4 04             	add    esp,0x4
  57e906:	5f                   	pop    edi
  57e907:	89 1e                	mov    DWORD PTR [esi],ebx
  57e909:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  57e90d:	8b c6                	mov    eax,esi
  57e90f:	5b                   	pop    ebx
  57e910:	8b e5                	mov    esp,ebp
  57e912:	5d                   	pop    ebp
  57e913:	c2 08 00             	ret    0x8
```
## 研究輪次與停止理由
第一輪對事件碼 0x709/0x70A/0x578 做直接 opcode 來源判斷；第二輪閉合 0x57EF20 node layout（0x18 bytes、+0x0C key、+0x10 Conn*）與 0x57E850 有序插入；第三輪完整限定非等價和下一步。重大有界新增是 exact tree node memory layout + matching consumer，以及 UI event-to-connect handler 的分支條件。RR 未達正式完成條件，不聲稱 T01 FULL-PASS。
## E30 首要追蹤
(1) 0x66C620 所在 vtable/註冊和直接/間接 caller；(2) T03 0x13 native consumer 到 UI event bridge；(3) 0x7B6890 對重複連線 key 節點的 erase / close；(4) connection-specific first frame。
(1) 0x66C620 所在 vtable/註冊和直接/間接 caller；(2) T03 0x13 native consumer 到 UI event bridge；(3) 0x7B6890 對重複連線 key 節點的 erase / close；(4) connection-specific first frame。