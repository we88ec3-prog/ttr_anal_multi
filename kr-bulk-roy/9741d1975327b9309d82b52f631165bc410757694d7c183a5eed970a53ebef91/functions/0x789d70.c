
void FUN_00789d70(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  if (in_ECX != unaff_ESI) {
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
      puVar1 = puVar2 + 5;
      puVar3 = puVar3 + 7;
      puVar2 = puVar2 + 7;
    } while (puVar1 != unaff_ESI);
  }
  return;
}

