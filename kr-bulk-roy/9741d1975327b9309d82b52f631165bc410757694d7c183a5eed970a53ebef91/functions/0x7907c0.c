
void FUN_007907c0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != in_ECX) {
    puVar2 = in_ECX + 2;
    puVar3 = (undefined4 *)(in_EAX + 8);
    do {
      if (puVar3 + -8 != puVar2 + -8) {
        puVar3[-5] = puVar2[-5];
        puVar3[-8] = puVar2[-8];
        puVar3[-7] = puVar2[-7];
        puVar3[-6] = puVar2[-6];
      }
      puVar3[-4] = puVar2[-4];
      puVar3[-3] = puVar2[-3];
      puVar1 = puVar2 + -9;
      puVar2 = puVar2 + -7;
      puVar3 = puVar3 + -7;
    } while (puVar1 != unaff_ESI);
  }
  return;
}

