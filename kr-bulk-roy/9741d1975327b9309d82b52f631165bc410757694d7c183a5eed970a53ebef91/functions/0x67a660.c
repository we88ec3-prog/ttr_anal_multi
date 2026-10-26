
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0067a660(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x43] + 0x20)) {
      FUN_0067a920();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3d] + 0x20)) {
      FUN_0067b2e0();
    }
  }
  else if (iVar1 == 0xf43a9) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    param_1 = CONCAT13((char)in_ECX[0x45],CONCAT12((char)in_ECX[0x44],0x6f));
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
      return;
    }
  }
  else if (iVar1 == 0xf43aa) {
    FUN_0067b2e0();
    (**(code **)(*in_ECX + 0x16c))(1);
    return;
  }
  return;
}

