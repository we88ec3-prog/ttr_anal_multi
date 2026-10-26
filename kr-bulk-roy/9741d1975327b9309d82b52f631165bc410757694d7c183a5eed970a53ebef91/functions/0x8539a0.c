
void FUN_008539a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  if (in_ECX != unaff_ESI) {
    puVar3 = in_EAX + 5;
    puVar2 = in_ECX + 5;
    do {
      *in_EAX = puVar2[-5];
      puVar3[-4] = puVar2[-4];
      puVar3[-3] = puVar2[-3];
      puVar3[-2] = puVar2[-2];
      puVar3[-1] = puVar2[-1];
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      puVar3[3] = puVar2[3];
      puVar1 = puVar2 + 4;
      in_EAX = in_EAX + 9;
      puVar3 = puVar3 + 9;
      puVar2 = puVar2 + 9;
    } while (puVar1 != unaff_ESI);
  }
  return;
}

