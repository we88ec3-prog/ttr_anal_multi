
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fd080(int param_1,int param_2)

{
  int iVar1;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_1 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < param_2 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = DAT_00f94300 + 0x16f8 + param_2 * 0x20;
    if (((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_1c = 0x7f;
      local_1a = 1;
      local_19 = (undefined1)param_2;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,4);
      }
    }
  }
  ExceptionList = local_14;
  return;
}

