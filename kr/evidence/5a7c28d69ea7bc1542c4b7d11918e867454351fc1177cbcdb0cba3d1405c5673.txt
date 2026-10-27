
void FUN_0064ab00(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar4 = *(int *)(param_1 + 0x118) - *(int *)(param_1 + 0x114) >> 2;
  uVar5 = 0;
  if (uVar4 != 0) {
    puVar6 = *(undefined4 **)(param_1 + 0x114);
    do {
      if (*(int *)*puVar6 == param_2) {
        piVar1 = *(int **)(*(int *)(param_1 + 0x10c) + 0xd0);
        piVar1[0x31] = uVar5 * 0x3c;
        (**(code **)(*piVar1 + 0x128))();
        (**(code **)(*piVar1 + 200))();
        break;
      }
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 < uVar4);
  }
  if (*(int *)(*(int *)(param_1 + 0x10c) + 0xcc) != 0) {
    FUN_0042c8e0(param_2);
  }
  piVar1 = *(int **)(param_1 + 0x10c);
  puVar6 = (undefined4 *)piVar1[0x19];
  for (puVar2 = (undefined4 *)*puVar6; puVar2 != puVar6; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    if ((*(int *)(iVar3 + 0x60) != 0) && ((*(int **)(iVar3 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar3 + 0x1c) + 0x30))(iVar3);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0x10c) + 200))();
  return;
}

