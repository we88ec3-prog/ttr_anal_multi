
void FUN_0059a230(void)

{
  uint uVar1;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00947578;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  if (DAT_00fb73e8 != 0) {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_8 = 1;
      FUN_00560170(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    local_8 = 0xffffffff;
    FUN_00562320();
    ExceptionList = local_10;
    return;
  }
  if ((*(uint *)(*(int *)(unaff_EDI + 0x204) + 0x28) & 0x100) == 0) {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_8 = 0xffffffff;
    if (DAT_00f95c00 == 0) {
      (**(code **)(**(int **)(unaff_EDI + 0x204) + 0xd0))();
      FUN_0044c260();
      ExceptionList = local_10;
      return;
    }
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 3;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  if (DAT_00f95c00 != 0) {
    FUN_00404aa0();
    FUN_0074f940();
  }
  (**(code **)(**(int **)(unaff_EDI + 0x204) + 0xd4))();
  ExceptionList = local_10;
  return;
}

