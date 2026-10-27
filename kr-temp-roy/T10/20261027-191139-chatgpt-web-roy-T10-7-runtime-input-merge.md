# KR T10-7 — Runtime input merge

Source: KR BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91. Machine-code-only check; PE .text VA 0x401000 / raw 0x400.

0x546263 directly calls 0x546780. This function reads WORD [controller+0x5C] at 0x546791 and copies an input byte into three temporary bytes. At 0x5467A4 it calls the time/state-machine 0x547240. Returned phase 2 causes OR 0x0008, phase 3 causes OR 0x0080, phase 4 causes OR 0x0040 into the result WORD. This is a factual phase-to-bit conversion, not identification of Z.

    546791 movzx ebx,WORD PTR [edi+0x5c]
    5467a4 call 0x547240
    5467ad sub eax,0x2
    5467b8 or ebx,0x40
    5467bd or ebx,0x80
    5467c5 or ebx,0x8

Then 0x546850, 0x546B50 and 0x546D50 are called in order, with independent return values. 0x5467F4 writes the output WORD. For the mutable output byte the three branches are prioritized: use the first when 0x546850 yields nonzero; else use the second when 0x546B50 yields nonzero; otherwise use third when 0x546D50 yields nonzero. Return bits from the three calls are OR-combined. This means that output-byte selection and returned-mask composition are distinct.

    5467cd call 0x546850
    5467e0 call 0x546b50
    5467ec call 0x546d50
    5467f4 mov WORD PTR [edx],bx
    5467f7 test esi,esi
    546811 test edi,edi
    54682b test eax,eax

Provisional C++: mask=controller.field5C; phase=stateMachine(controller.state40,globalFB9014); addMaskForPhase(phase,mask); a=sourceA(byteA); b=sourceB(byteB); c=sourceC(byteC); outWord=mask; outByte=a?byteA:b?byteB:byteC; return a|b|c.

It has not been proved which input bit, source branch or phase maps to Z, nor which is keydown/keyup/held. Previous 500ms timeGetTime evidence cannot be declared a Z combo window. Next T10-8 examines the actor/action gates consuming these outputs.