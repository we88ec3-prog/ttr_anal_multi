
void FUN_0084b990(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  if (in_ECX != unaff_ESI) {
    puVar3 = in_EAX + 4;
    puVar2 = in_ECX + 4;
    do {
      if (in_EAX != puVar2 + -4) {
        *in_EAX = puVar2[-4];
        in_EAX[1] = puVar2[-3];
        in_EAX[2] = puVar2[-2];
        if (puVar3 + -1 != puVar2 + -1) {
          puVar3[2] = puVar2[2];
          puVar3[-1] = puVar2[-1];
          *puVar3 = *puVar2;
          puVar3[1] = puVar2[1];
        }
        puVar3[3] = puVar2[3];
        puVar3[4] = puVar2[4];
        puVar3[5] = puVar2[5];
        puVar3[6] = puVar2[6];
      }
      puVar3[7] = puVar2[7];
      puVar3[8] = puVar2[8];
      puVar3[9] = puVar2[9];
      puVar3[10] = puVar2[10];
      puVar3[0xb] = puVar2[0xb];
      puVar3[0xc] = puVar2[0xc];
      puVar3[0xd] = puVar2[0xd];
      puVar3[0xe] = puVar2[0xe];
      puVar3[0xf] = puVar2[0xf];
      puVar1 = puVar2 + 0x10;
      in_EAX = in_EAX + 0x14;
      puVar3 = puVar3 + 0x14;
      puVar2 = puVar2 + 0x14;
    } while (puVar1 != unaff_ESI);
  }
  return;
}

