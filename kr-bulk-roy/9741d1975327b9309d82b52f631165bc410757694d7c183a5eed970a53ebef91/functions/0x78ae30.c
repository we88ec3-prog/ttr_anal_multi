
void FUN_0078ae30(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *in_EDX;
  undefined4 *puVar3;
  undefined4 *unaff_EDI;
  
  if (in_EDX != unaff_EDI) {
    puVar2 = in_EAX + 1;
    puVar3 = in_EDX + 4;
    do {
      if (in_EAX != (undefined4 *)0x0) {
        *in_EAX = gbKey<gbVec3<float>_>::vftable;
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        *puVar2 = puVar3[-3];
        puVar2[1] = puVar3[-2];
        puVar2[2] = puVar3[-1];
        puVar2[3] = *puVar3;
        puVar2[4] = puVar3[1];
        *in_EAX = gbBezKey<gbVec3<float>_>::vftable;
        puVar2[5] = puVar3[2];
        puVar2[6] = puVar3[3];
        puVar2[7] = puVar3[4];
        puVar2[8] = puVar3[5];
        puVar2[9] = puVar3[6];
        puVar2[10] = puVar3[7];
        puVar2[4] = 0;
      }
      puVar1 = puVar3 + 8;
      in_EAX = in_EAX + 0xc;
      puVar2 = puVar2 + 0xc;
      puVar3 = puVar3 + 0xc;
    } while (puVar1 != unaff_EDI);
  }
  return;
}

