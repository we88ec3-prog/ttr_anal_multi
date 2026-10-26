
void FUN_00789dc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (in_ECX != param_1) {
    puVar3 = (undefined4 *)(in_EAX + 8);
    puVar2 = in_ECX + 2;
    do {
      if (puVar3 + -1 != puVar2 + -1) {
        puVar3[2] = puVar2[2];
        puVar3[-1] = puVar2[-1];
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
      }
      puVar3[3] = puVar2[3];
      puVar3[4] = puVar2[4];
      if (puVar3 + 5 != puVar2 + 5) {
        puVar3[8] = puVar2[8];
        puVar3[5] = puVar2[5];
        puVar3[6] = puVar2[6];
        puVar3[7] = puVar2[7];
      }
      if (puVar3 + 9 != puVar2 + 9) {
        puVar3[0xc] = puVar2[0xc];
        puVar3[9] = puVar2[9];
        puVar3[10] = puVar2[10];
        puVar3[0xb] = puVar2[0xb];
      }
      puVar1 = puVar2 + 0xd;
      puVar3 = puVar3 + 0xf;
      puVar2 = puVar2 + 0xf;
    } while (puVar1 != param_1);
  }
  return;
}

