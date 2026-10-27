# T08-085 資源模板名稱綁定與數值初始化
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
研究者 chatgpt-web roy；以 objdump 直接對原始 BIN 分析。

## 已確認的新路徑
0x007BDF90 遍歷 [resource+0x04,resource+0x08) 指標陣列，逐項讀 entry+0x04 名稱，轉為臨時字串，使用全域名稱集合 0x00FE173C 和函式 0x007B86F0 查找。查找命中且 node+0x24 有對象，呼叫該對象 vtable+0x10 並寫回 entry+0x08。空關聯觸發報告路徑。完成後呼叫 0x007BE150 並設 resource+0x74=1。

```asm
007BDFBB mov esi,ecx
007BDFBD mov eax,[esi+04h]
007BDFC6 cmp eax,[esi+08h]
007BDFDB mov ebx,[eax]
007BE006 mov ecx,[ebx+04h]
007BE009 mov esi,[0FE173Ch]
007BE034 call 00402A70
007BE04A call 007B86F0
007BE07D cmp eax,[esi+04h]
007BE082 mov ecx,[eax+24h]
007BE08B mov edx,[eax+10h]
007BE08E call edx
007BE090 mov [ebx+08h],eax
007BE093 cmp dword ptr [ebx+08h],0
007BE0C4 call 007BE150
007BE0C9 mov dword ptr [esi+74h],1
```

### 0x007BE150 證據
```asm
007BE166 fld dword ptr [ebx+18h]
007BE1E6 fld dword ptr [ebx+34h]
007BE1EC call 00790DC0
007BE1F1 fld dword ptr [ebx+38h]
007BE1F8 call 00790E90
007BE1FD fld dword ptr [ebx+3Ch]
007BE204 call 00790F60
007BE20D call 00780890
```
這是一套讀取多個 float、透過下游轉換函式建立數值狀態的流程；尚不能直接命名為渲染或世界座標更新。

### 0x007DC510 移除路徑驗證
```asm
007DC573 call 007B86F0
007DC594 cmp eax,[esi+04h]
007DC599 mov edi,[eax+24h]
007DC59E mov edx,[eax+0Ch]
007DC5A3 call edx
007DC5A8 cmp eax,ebx
007DC5B8 call edx
007DC5C2 call 007B8680
```
上述 vtable+0x0C 回傳零時才執行析構與樹節點刪除；具體回傳數值語意未知。

### 行為偽碼
```cpp
for(auto* e : resource->children){
  Node* n = lookupName(e->name);
  if(n != registry.sentinel && n->object)
    e->binding = n->object->vfunc10();
  if (!e->binding) reportUnbound(e->name);
}
applyNumericResourceState(resource); // 0x007BE150
resource->field_74=1;
```

## 與前段的關係
0x007BD7E0 建立新物件→0x007BDF90 名稱關聯→0x007BE150 數值初始化→設定 +0x74，對接 0x007DCFB0 復用池新建分支。尚未找到場景物件 vtable+0x20 主迴圈間接調度者。

## 下一段
追查 0x00FE173C 名稱集合的建立和移除、0x007BE150 後半段矩陣/數值運算、0x007DC510 vtable+0x0C 真正實作。
