
void FUN_00754b40(int *param_1)

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
      if (iVar1 == 0xf232) {
        iVar1 = FUN_0075ed60();
        if ((iVar1 != 0) && (*(int *)(in_ECX + 0xdc) != 0)) {
          if (*(uint *)(in_ECX + 0xe0) < 8) {
            iVar1 = in_ECX + 0xcc;
          }
          else {
            iVar1 = *(int *)(in_ECX + 0xcc);
          }
          iVar1 = FUN_0077be10(iVar1);
          if (iVar1 != 0) {
            FUN_00405300(in_ECX + 0xe8);
          }
        }
      }
      else {
        iVar1 = (**(code **)(**(int **)(*param_1 + uVar2 * 4) + 4))();
        if (iVar1 == 0xf233) {
          FUN_00776150();
        }
      }
      iVar1 = *param_1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(param_1[1] - iVar1 >> 2));
  }
  return;
}

