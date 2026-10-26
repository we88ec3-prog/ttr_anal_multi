
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00426060(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *in_ECX;
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0x10) == 0x70a) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    if (*(int *)(in_ECX[0x41] + 0xcc) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*(int *)(in_ECX[0x41] + 0xcc) + 0xdc);
    }
    if (*(int *)(DAT_00fab130 + 0x5eac) != *(int *)(iVar2 + 0x25c)) {
      local_1c = (uint)*(byte *)(iVar2 + 600);
      uVar1 = *(undefined1 *)(iVar2 + 0x260);
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_20 = 0x101;
      local_1e = (undefined1)local_1c;
      local_1d = uVar1;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_20,4);
      }
    }
    (**(code **)(*in_ECX + 0xd4))();
  }
  else if ((*(int *)(param_1 + 0x10) == 0x70b) &&
          (*(int *)(in_ECX[0x41] + 0x20) == *(int *)(param_1 + 8))) {
    FUN_004266e0(in_ECX);
    ExceptionList = local_14;
    return;
  }
  ExceptionList = local_14;
  return;
}

