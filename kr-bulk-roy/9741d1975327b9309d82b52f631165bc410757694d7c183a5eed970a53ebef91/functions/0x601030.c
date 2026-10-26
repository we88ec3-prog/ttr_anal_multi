
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00601030(int param_1)

{
  int iVar1;
  int unaff_EDI;
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
    if (99 < unaff_EDI - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    iVar1 = unaff_EDI * 0x20 + DAT_00f94300 + 0x16f8;
    if (((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      FUN_004a39f0(1,unaff_EDI,*(undefined4 *)(iVar1 + 0xc),0);
    }
  }
  ExceptionList = local_14;
  return;
}

