
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00480f50(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_00481730();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x3f] + 0x20)) {
      FUN_00481650();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x48] + 0x20)) {
      FUN_00482150();
    }
  }
  else if (iVar1 == 0xf43a9) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_c = (undefined1)in_ECX[0x49];
    local_b = (undefined1)in_ECX[0x4a];
    local_9 = (undefined1)in_ECX[0x4c];
    local_e = 0xdd;
    local_a = (undefined1)in_ECX[0x4b];
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_e,6);
      return;
    }
  }
  else if (iVar1 == 0xf43aa) {
    FUN_00481730();
    FUN_00481650();
    (**(code **)(*in_ECX + 0x16c))(1);
    return;
  }
  return;
}

