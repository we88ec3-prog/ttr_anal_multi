# T08-119 — Six half-space plane construction and math

研究者：chatgpt-web roy；2026-10-27 Asia/Taipei。
一級來源：原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，本輪重新核對。ASM 直接取自該 BIN 的 x86 反組譯。本 GitHub 筆記為完整研究結論與關鍵證據版本，本機另有較長的逐行 ASM 附錄。

## 前置矩陣組合
0x00799D20 從 [0x00FB76A8] 核心物件+0x54 與+0x98 複製 17 DWORD/13 DWORD 到 stack，0x00838210 執行 float multiply/add 的矩陣結合，結果傳入 0x00838430；前述 rep movsd 的目的地是 stack，不能視為寫入六平面 heap。

~~~asm
00799D7E mov eax,[0xfb76a8]
00799D83 lea esi,[eax+0x54]
00799D86 mov ecx,0x11
00799D91 rep movsd
00799D93 lea esi,[eax+0x98]
00799D99 mov ecx,0xd
00799DA4 rep movsd
00799E8F call 0x838210
00799E94 mov esi,[ebx+8]
00799E98 call 0x838430
~~~

## 三點生成平面 0x00862C00
0x00838430 準備多個幾何點/向量，反覆呼叫 0x00862C00，再把計算出的四浮點值寫回 ESI 各段。0x00862C00 用 3D 向量相減、叉積形式的 x87 運算建立法線，並把常數項寫入 output+0x0C。

~~~asm
00862C18 fld DWORD PTR [ecx]
00862C1D fsub DWORD PTR [edi]
00862C22 fld DWORD PTR [ecx+4]
00862C25 fsub DWORD PTR [edi+4]
00862C2B fld DWORD PTR [ecx+8]
00862C2E fsub DWORD PTR [edi+8]
00862C34 fld DWORD PTR [eax]
00862C36 fsub DWORD PTR [edi]
00862C3B fld DWORD PTR [eax+4]
00862C3E fsub DWORD PTR [edi+4]
00862C44 fld DWORD PTR [eax+8]
00862C47 fsub DWORD PTR [edi+8]
00862CA2 fst DWORD PTR [ebx]
00862CA7 fst DWORD PTR [ebx+4]
00862CAD fst DWORD PTR [ebx+8]
00862CCF fstp DWORD PTR [ebx+0xc]
~~~

後段以點座標和法線係數乘加、fchs 變號，符合 D=-dot(n,point) 的平面方程。0x838860 與 0x838800 按六個 16-byte 紀錄測試 A*x+B*y+C*z+D 的符號或閾值。

~~~asm
00838874 fld DWORD PTR [edx-8]
00838877 fmul st,st(1)
00838879 fld DWORD PTR [edx-4]
0083887C fmul st,st(3)
00838880 fld DWORD PTR [edx]
00838882 fmul st,st(4)
0083888C fadd DWORD PTR [edx+4]
0083889E inc ecx
0083889F add edx,0x10
008388A2 cmp ecx,0x6
~~~

### 保守偽碼
~~~cpp
Plane from3(Vec3 p0,Vec3 p1,Vec3 p2) {
  Vec3 n=cross(p1-p0,p2-p0);
  return {n.x,n.y,n.z,-dot(n,p0)};
}
void buildSix(Plane dst[6], Matrix m) {
  // source points produced by transformation; 6 calls to from3
}
~~~

已確認：6 plane vectors、數學公式及存放。推測：六平面界定相機視錐，但沒有 camera owner/RTTI 證據；法線是否單位長尚須詳查 0x791180 和 x87 stack。