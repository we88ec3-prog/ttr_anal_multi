
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aae80(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x10) == 0xf431d) {
    FUN_005a59e0();
  }
  else if (*(int *)(param_1 + 0x10) == 0xf4328) {
    FUN_005a57d0();
  }
  if (*(int *)(iVar1 + 0x10) == 0xf431f) {
    if (*(int *)(iVar1 + 0x14) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x164) + 0xd4))();
      FUN_006bf310(*(undefined4 *)(in_ECX + 0x168));
      FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x168));
      return;
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    param_1 = CONCAT22(0x33,(undefined2)param_1);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2);
    }
  }
  return;
}

