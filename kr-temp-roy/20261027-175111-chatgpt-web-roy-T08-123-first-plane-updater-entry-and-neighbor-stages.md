# T08-123 — First geometry update caller at 0x00492567 and neighboring subsystems

- Task: T08｜researcher: chatgpt-web roy｜time: 2026-10-27 17:51 Asia/Taipei
- Original: Tartaros.bin｜SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪本地計算確認）
- Source: 本輪以 `objdump -d -Mintel /mnt/data/Tartaros.bin` 反組譯直接對照 ASM；無 Ghidra 推論冒充原始機器碼。
- Evidence grading: **已確認** = machine code supports; **推測** = interpretation; **未知** = no proof.
- Repository target: `kr-temp-roy/`，不更動其他 Agent 內容。

## 1. 研究問題
T08-118 已證實 `0x00492567 -> 0x00799D20 -> 0x00838430` 寫回 `[0x00FB76B0]`。本段向外觀察 `0x00492567` 所在函式連續執行的其他系統，區分真實順序與語義推測。

## 2. 上游同函式多階段實證
```asm
004923D0 cmp dword ptr ds:0xfbab34,0
004923D9 push 0xfbaaf8
004923DE call 0x54d420
00492410 mov ecx,ds:0xfb7620
0049241A mov eax,[ecx]
0049241F mov edx,[eax+0x10]
00492426 call edx
0049245D mov ecx,ds:0xfd8ba4
00492467 mov eax,[ecx]
0049246C mov edx,[eax+0x1c]
00492473 call edx
004924A2 mov edi,ds:0xfb76e8
004924A8 call 0x797ec0
004924DF fld dword ptr [ebp+0xc]
004924EB call 0x561680
0049251D fld dword ptr [ebp+0xc]
00492529 call 0x5544b0
0049252E test byte ptr ds:0xfb79e8,1
00492545 call 0x798de0
0049255B fld dword ptr [ebp+0xc]
00492562 push 0xfb76a8
00492567 call 0x799d20
0049256C test byte ptr ds:0xfab22c,1
00492583 call 0x4dec90
```

分支條件：`[0xFB7620]` 與 `[0xFD8BA4]` 非零才會分派對應虛方法；global once flags 控制個別初始化。因而 0x492xxx 同函式段不是所有列舉的步驟都無條件執行。

## 3. 為何不能硬命名
`[EBP+0x0C]` 在這些步驟中被當 float 傳給多個子系統，符合週期性 tick 形式，但只靠傳入 float 不能證明固定 FPS / 每幀執行。此路徑是否呼叫場景 `0x00C07554+0x20` 仍無直接證據。

## 4. 保守偽碼
```cpp
void multiStageUpdate(/* unknown ctx */, float value) {
  if (globalA) globalA->virtual10(value);
  if (globalB) globalB->virtual1C(value);
  step_797ec0(...);
  step_561680(value);
  step_5544b0(value);
  if (!initialized) init_798de0();
  geometry_799d20(&globalManagerHandle,value);
  // subsequent independent stage(s)
}
```
保留虛方法實際類型未知、初始化有條件的限制。

## 5. 下一段
確認另一條 `0x007BA56E` 更新入口的額外迭代及條件，避免將兩個不同場景直接合併成同一個主更新。