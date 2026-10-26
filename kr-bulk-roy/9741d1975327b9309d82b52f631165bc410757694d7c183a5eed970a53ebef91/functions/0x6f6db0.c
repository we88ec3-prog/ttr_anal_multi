
undefined4 FUN_006f6db0(void)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  piVar1 = __errno();
  FUN_00898466(*piVar1);
  iVar2 = FUN_006f50f0();
  if ((*(int *)(iVar2 + 8) != 4) && (iVar2 = FUN_006fb5d0(), iVar2 != 0)) {
    if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    FUN_006f50f0();
  }
  FUN_006f5580();
  puVar3 = (undefined4 *)FUN_006f50f0();
  puVar4 = puVar3 + 4;
  if (puVar4 < *(undefined4 **)(in_EAX + 8)) {
    do {
      *puVar3 = *puVar4;
      puVar3[1] = puVar4[1];
      puVar3[2] = puVar3[6];
      puVar4 = puVar4 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar4 < *(undefined4 **)(in_EAX + 8));
  }
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x10;
  return 6;
}

