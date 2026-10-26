
void FUN_005ff8c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_2 != param_3) {
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
        iVar1 = param_1;
        FUN_00414680(1,param_2,1,param_3);
        FUN_004a3900(param_1,param_2,iVar1,param_3);
      }
    }
  }
  ExceptionList = local_14;
  return;
}

