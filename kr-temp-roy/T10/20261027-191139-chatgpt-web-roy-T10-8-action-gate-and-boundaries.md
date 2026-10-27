# KR T10-8 — Controller gate and evidence boundaries

KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91, PE32 x86, static source read only.

The output of T10-7 0x546780 is saved by caller 0x546100 at 0x546268. At 0x54628F..0x5462A2 a WORD from actor/control data is combined with a new WORD using XOR and AND instructions. 0x5462A2 can branch on [0xFBA7AC]==1. 0x5462B0 reads [EDI+0x3E8] for a subsequent branch; 0x5462DD calls 0x54F270 with an action-dependent data pointer. 0x5462E2 tests the result and one branch 0x5462FD..0x546302 clears the low fifteen bits by AND WORD with 0x8000. This is a confirmed conditional input-mask clear, not a confirmed combo cancel mechanism.

    546263 call 0x546780
    546268 mov [esp+0x28],eax
    54628f mov cx,WORD PTR [ebx+0x2]
    546293 xor cx,ax
    54629b and cx,dx
    54629e xor WORD PTR [ebx+0x2],cx
    5462a2 cmp DWORD PTR [0xfba7ac],0x1
    5462b4 mov ecx,[edi+0x3e8]
    5462dd call 0x54f270
    5462e2 test eax,eax
    5462fd mov edx,0x8000
    546302 and WORD PTR [ebx+0x2],dx

0x546306..0x546330 includes a once-initializer calling 0x6D0750. 0x546345 reads a state component at actor+0x158 and 0x546353 checks that component's +0x30 field; 0x54635F calls 0x4C9ED0. These are native conditional actor/action gates, but their authoritative game names and relationship to basic attacks are not demonstrated.

The verified boundaries now divide into a static setting path KeyMapping.xml -> 0x6D08F0/0x6D0EB0 -> 0x6D4DC0 -> 0x6D43F0; and a runtime path 0x547240 -> 0x546780 -> 0x546100 -> 0x54F270 -> existing 0x5452C0 action input send. The link identifying actual physical Z key pressed/held/released, an action mapping row, and an attack motion/chain consumer between these two is STILL UNVERIFIED.

Evidence grades: confirmed input state conversion, call graph pieces, conditionals and masking; inferred actor action eligibility; not confirmed Z automatic continuation, number of hits, cancel timing or official chain window. The locally implemented CHAIN_WINDOW=0.65 must not be reported as an original rule.

T10-9 direction: obtain actual Table/KeyMapping.xml, locate direct/indirect normal writer for global 0xFB9014, trace original attack motion consumers and reconcile client vs server-authoritative continuation. Exclude T12 damage formula. Original files unchanged; work confined to T10 researcher notes.