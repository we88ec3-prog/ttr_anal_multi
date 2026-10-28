# T10-088 — T10-85～88 完整研究階段證據矩陣、未閉合區段與下一段定向計畫

KR 原始證據：Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，Tartaros.exe SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f（均本機重新驗證）。PE32 .text VA 0x401000/raw 0x400；靜態唯讀，不執行、不修改目標，亦不新增原檔至 repo。

## 已驗證原始鍵位資料

KR 原 KeyMapping.xml 於 kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt 保存：Type0 MapButton13..16 對 Key44..47，ModKey0。Type1 MapButton13..16 分配 Key36..39；Type1 Key45 基本 XML 無顯式列出，Extra Type1 Key45+ModKey29 對高 ID10509 不屬同一 domain。DIK Z/X/C/V 只能先稱掃描碼候選；玩家配置與 fallback 未知。0x6D1A70 選 bank，0x6D4DC0 查 bank；0x4A1440 複製 Type0/1 至 bank2；0x6D0D10 將外部配對回填 bank2。使用者持久化配置 writer 仍缺。

## 原始 x86 所支持的執行時半鏈

* 0x6D4CE0 對 ID0..39 讀 byte[0xFB9004+ID]，對特殊 ID10001..19999 查 0xFDF630 容器 node+0x10。
* 0x6D4A30 的 0x6D4A93/0x6D4B69 先 xor eax,eax，再寫零到 0xFB9004..0xFB9028；0x6D4CAE 清零 byte[0xFB9004+esi]，0x6D4C7C 清零特殊 node+0x10。上述都是 reset，不是 phase1/3 producer。
* 0x5961C0 將 EDI ID 傳到 ESI reader，phase1 與3 經子物件/this 的 +0xEC/+0xF0 虛擬槽派送。0xFB73E8 非零時這條派送分支保留 ID13/14。
* 0x560197 xor ebx,ebx；0x560239 mov [0xFB73E8],ebx 是已發現的 **初始化清零**，不是非零狀態 writer。
* 0x5A4614 讀全域旗標，與物件 [esi+0x154] 前次布林比較，呼叫 0x5A55E0(mode=1/2)，並更新 [esi+0x154]；0x5A55E0 寫 [esi+0x158]、[esi+0x15c]，觸及 [esi+0x140/0x148] 的多態 +0xD0/+0xD4、子物件 +0x28 的 0x80000 mask。這是模式轉換的直接證據，不是已確認攻擊取消。

## 缺口與否定性證據邊界

A. scan-code→working bank→phase 1/3 的非零 writer：**尚未定位**。全 .text 直接絕對位址 xref 為負面，不能排除 base+offset、alias、callback、間接寫入。
B. vtable +0xEC/+0xF0 所屬 class/override→角色 motion/queue/cancel：尚未定位。
C. 全域 0xFB73E8 非零 writer/語義：尚未定位。
D. 原生 Z 連打／長按、V tap/hold、queue/cancel 窗口：未確認。CHAIN_WINDOW=.65、SubAI>60、>500ms 等不得頂替原生依據。
E. 0x5CD68A、0x5CE5BA、0x62B5BA、0x650E96 的 MapButton 查詢用途待逐條核實，不可視為所有 caller 都是 UI 或所有都是 gameplay。

## T10-089 優先順序

1. 逆追 0x490DFC、0x58A607 的 0x6D4A30 事件容器來源、元素新增與清除時序。
2. 沿 0xFB73C0 鄰近物件和指標別名，找 [0xFB73E8] 非零寫入與 flags 的業務來源。
3. 以 0x761010 物件取得函式查 vptr，定位 +0xEC/+0xF0 override 實際地址，跨 controller/motion 用一手指令證實。
4. 逐個審核未分類 0x6D4DC0 caller，區分配置 UI/設定與原生 runtime consumer。
5. 未閉合前標 bounded native review，不標 native_complete、不改其他 Task owner/catalog。