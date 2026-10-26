
void FUN_0069a600(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = *(int *)(*(int *)(in_ECX + 0x98) + 0xcc);
  if (iVar6 != 0) {
    FUN_00408920(iVar6,8);
  }
  iVar6 = 0;
  piVar5 = (int *)(in_ECX + 0x9c);
  do {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x98) + 0xcc);
    if (((iVar1 == 0) || (iVar6 < 0)) ||
       (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= iVar6)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)((int)piVar5 + *(int *)(iVar1 + 0xa8) + (-0x9c - in_ECX));
    }
    *piVar5 = (int)piVar4;
    (**(code **)(*piVar4 + 0x198))(0x5d3b30);
    iVar1 = *piVar5;
    iVar6 = iVar6 + 1;
    piVar5 = piVar5 + 1;
    *(undefined1 *)(iVar1 + 0x269) = 1;
    *(undefined4 *)(iVar1 + 0x26c) = 0;
    *(undefined4 *)(iVar1 + 0x270) = 0;
    *(undefined4 *)(iVar1 + 0x274) = 0;
  } while (iVar6 < 8);
  iVar6 = *(int *)(*(int *)(in_ECX + 0x98) + 0xcc);
  if (iVar6 != 0) {
    *(undefined1 *)(iVar6 + 0xe0) = 0;
  }
  piVar5 = *(int **)(in_ECX + 0x98);
  puVar2 = (undefined4 *)piVar5[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar6 = puVar3[2];
    if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
    }
  }
  (**(code **)(*piVar5 + 0x128))();
  (**(code **)(**(int **)(in_ECX + 0x98) + 200))();
  return;
}

