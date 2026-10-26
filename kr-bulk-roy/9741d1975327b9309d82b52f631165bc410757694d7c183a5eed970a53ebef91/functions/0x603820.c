
void FUN_00603820(int param_1)

{
  int iVar1;
  int unaff_EDI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009434cc;
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
    if (unaff_EDI - 1U < 100) {
      iVar1 = unaff_EDI * 0x20 + DAT_00f94300 + 0x16f8;
      if (((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
        if ((DAT_00fb131c & 1) == 0) {
          DAT_00fb131c = DAT_00fb131c | 1;
          local_c = 1;
          FUN_00570ec0();
          _atexit((_func_4879 *)&LAB_00bccf50);
        }
        local_c = 0xffffffff;
        FUN_00571030(&DAT_00fb1320,1,unaff_EDI);
        ExceptionList = local_14;
        return;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    FUN_006edb60(&DAT_00c292ec,1);
    ExceptionList = local_14;
    return;
  }
  FUN_006edb60(&DAT_00c292c8,param_1);
  ExceptionList = local_14;
  return;
}

