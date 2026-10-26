
void FUN_0078aee0(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *in_EDX;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  if (in_EDX != unaff_ESI) {
    puVar2 = in_EAX + 2;
    puVar3 = in_EDX + 2;
    do {
      if (in_EAX != (undefined4 *)0x0) {
        *in_EAX = gbKey<gbQuat>::vftable;
        puVar2[-1] = 0;
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0x3f800000;
        if (puVar2 + -1 != puVar3 + -1) {
          puVar2[2] = puVar3[2];
          puVar2[-1] = puVar3[-1];
          *puVar2 = *puVar3;
          puVar2[1] = puVar3[1];
        }
        puVar2[3] = puVar3[3];
        puVar2[4] = puVar3[4];
      }
      puVar1 = puVar3 + 5;
      in_EAX = in_EAX + 7;
      puVar2 = puVar2 + 7;
      puVar3 = puVar3 + 7;
    } while (puVar1 != unaff_ESI);
  }
  return;
}

