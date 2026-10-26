
void FUN_00762790(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_00744a40(param_1);
  iVar1 = *param_1;
  uVar2 = 0;
  if (param_1[1] - iVar1 >> 2 != 0) {
    do {
      iVar1 = (**(code **)(**(int **)(iVar1 + uVar2 * 4) + 4))();
      if (iVar1 == 0xf233) {
        FUN_00776150();
      }
      iVar1 = *param_1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(param_1[1] - iVar1 >> 2));
  }
  return;
}

