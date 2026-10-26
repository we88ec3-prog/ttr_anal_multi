
void FUN_00596e00(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0xf0) == 0) {
    iVar2 = 0;
    local_c = -1;
    piVar1 = (int *)(param_1 + 0xc4);
    do {
      FUN_00848020(&param_2);
      iVar3 = iVar2;
      if (local_8 != *piVar1) break;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 4;
      iVar3 = local_c;
    } while (iVar2 < 3);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        FUN_00596ec0(param_1,param_2);
        return;
      }
      if (iVar3 == 2) {
        FUN_00596ec0(param_1,param_2);
        return;
      }
      (**(code **)(*param_2 + 0xd0))();
      return;
    }
    FUN_00597250(param_1);
    FUN_00596ec0(param_1,param_2);
  }
  return;
}

