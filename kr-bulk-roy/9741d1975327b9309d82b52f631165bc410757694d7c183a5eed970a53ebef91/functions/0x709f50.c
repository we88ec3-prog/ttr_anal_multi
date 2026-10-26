
undefined4 * FUN_00709f50(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *puVar4;
  
  FUN_006f5580();
  FUN_006fb850();
  iVar1 = *(int *)(in_EAX + 8);
  piVar3 = (int *)(iVar1 + -0x10);
  if ((piVar3 != &DAT_00c0bfc8) && (*(int *)(iVar1 + -8) == 0)) {
    *(int **)(in_EAX + 8) = piVar3;
    puVar4 = (undefined4 *)FUN_006f5c20(4);
    *puVar4 = 0;
    FUN_006fec70();
    FUN_006fb850();
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
    FUN_006f5910();
    FUN_006f5580();
    puVar2 = *(undefined4 **)(in_EAX + 8);
    *puVar2 = puVar2[-8];
    puVar2[1] = puVar2[-7];
    puVar2[2] = puVar2[-6];
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
    FUN_006fb9a0();
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + -0x20;
    return puVar4;
  }
  if (*(int *)(iVar1 + -8) == 2) {
    return (undefined4 *)*piVar3;
  }
  if (*(int *)(iVar1 + -8) != 7) {
    return (undefined4 *)0x0;
  }
  return (undefined4 *)(*piVar3 + 0x18);
}

