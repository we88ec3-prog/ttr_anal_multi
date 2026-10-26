
undefined4 FUN_008c6560(void)

{
  undefined1 *in_EAX;
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  uint *puVar4;
  
  FUN_008c6520();
  iVar3 = CONCAT31(CONCAT21(CONCAT11(*in_EAX,in_EAX[1]),in_EAX[2]),in_EAX[3]);
  iVar1 = FUN_008c5c80();
  if (iVar1 != 0) {
    return 0;
  }
  puVar4 = *(uint **)(in_ECX + 0x20);
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    uVar2 = (uint)CONCAT21(CONCAT11(in_EAX[4],in_EAX[5]),in_EAX[6]);
    iVar1 = (byte)in_EAX[7] + 1;
    do {
      *puVar4 = uVar2;
      uVar2 = uVar2 + 1;
      puVar4 = puVar4 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    in_EAX = in_EAX + 4;
  }
  *puVar4 = 0;
  return *(undefined4 *)(in_ECX + 0x20);
}

