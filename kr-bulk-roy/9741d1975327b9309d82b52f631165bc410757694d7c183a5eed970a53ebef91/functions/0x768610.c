
void FUN_00768610(int *param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  FUN_00744a40(param_1);
  iVar1 = *param_1;
  uVar2 = 0;
  if (param_1[1] - iVar1 >> 2 != 0) {
    do {
      iVar1 = (**(code **)(**(int **)(iVar1 + uVar2 * 4) + 4))();
      if (iVar1 == 0xf233) {
        FUN_00776150();
        iVar1 = FUN_00768150();
        if (iVar1 == 0) {
          *(undefined4 *)(in_ECX + 0x138) = 0;
        }
        else {
          *(int *)(in_ECX + 0x138) = (*(int *)(in_ECX + 0xb0) - *(int *)(in_ECX + 0xa8)) / iVar1;
        }
      }
      iVar1 = *param_1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(param_1[1] - iVar1 >> 2));
  }
  return;
}

