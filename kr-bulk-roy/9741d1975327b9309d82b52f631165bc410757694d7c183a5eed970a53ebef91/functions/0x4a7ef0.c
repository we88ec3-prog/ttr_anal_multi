
undefined4 FUN_004a7ef0(void)

{
  undefined4 *puVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)*in_EAX;
  uVar2 = in_EAX[1] - (int)puVar1 >> 2;
  uVar3 = 0;
  puVar4 = puVar1;
  if (uVar2 != 0) {
    do {
      if (*(int *)*puVar4 == unaff_EDI) {
        return puVar1[uVar3];
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < uVar2);
  }
  return 0;
}

