
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f98f0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f94300 + 0x23a0 != 0) {
    iVar2 = param_2 + -0x50 + param_1 * 0x50;
    if (0x1df < iVar2 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = DAT_00f94300 + 0x23a0 + iVar2 * 0x18;
    if (((*(int *)(DAT_00f94300 + 0x23ac + iVar2 * 0x18) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
       (iVar1 != 0)) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      FUN_004a4560(param_1,param_2,param_1,param_3);
    }
  }
  ExceptionList = local_14;
  return;
}

