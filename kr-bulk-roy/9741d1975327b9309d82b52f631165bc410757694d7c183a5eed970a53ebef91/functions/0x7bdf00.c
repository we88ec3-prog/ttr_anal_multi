
void FUN_007bdf00(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  if (uVar2 != 0) {
    do {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + uVar1 * 4) + 8) + 0x20))(param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return;
}

