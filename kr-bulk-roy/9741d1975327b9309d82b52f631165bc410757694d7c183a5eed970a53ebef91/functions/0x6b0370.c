
void FUN_006b0370(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if (iVar5 != 0) {
    FUN_00408920(iVar5,9);
  }
  iVar5 = 0;
  piVar6 = (int *)(in_ECX + 0x144);
  do {
    iVar4 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
    if (((iVar4 == 0) || (iVar5 < 0)) ||
       (*(int *)(iVar4 + 0xac) - *(int *)(iVar4 + 0xa8) >> 2 <= iVar5)) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)((int)piVar6 + *(int *)(iVar4 + 0xa8) + (-0x144 - in_ECX));
    }
    piVar6[-0x12] = iVar4;
    FUN_0046b6f0(31000);
    FUN_0043c570(32000);
    iVar4 = *piVar6;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar4 + 0xa4) = 1;
    iVar4 = *piVar6;
    if (((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) &&
       (iVar3 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))(), iVar3 == 0xbf6b)) {
      *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 1;
  } while (iVar5 < 9);
  piVar6 = *(int **)(in_ECX + 0xf8);
  puVar1 = (undefined4 *)piVar6[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar5 = puVar2[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar6 + 0x128))();
  return;
}

