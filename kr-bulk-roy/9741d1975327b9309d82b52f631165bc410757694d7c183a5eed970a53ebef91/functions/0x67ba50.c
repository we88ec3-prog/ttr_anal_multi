
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0067ba50(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(in_ECX[0x45] + 0x20)) {
      FUN_0067bea0();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x3f] + 0x20)) {
      FUN_0067cd90(0);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x40] + 0x20)) {
      FUN_0067cd90(1);
    }
  }
  else if (iVar1 == 0xf43a9) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_e = (undefined1)in_ECX[0x48];
    local_d = (undefined1)in_ECX[0x49];
    local_b = (undefined1)in_ECX[0x57];
    local_10 = 0x51;
    local_c = (undefined1)in_ECX[0x56];
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_10,6);
      return;
    }
  }
  else if (iVar1 == 0xf43aa) {
    FUN_0067ca70(in_ECX);
    (**(code **)(*in_ECX + 0x16c))(1);
    return;
  }
  return;
}

