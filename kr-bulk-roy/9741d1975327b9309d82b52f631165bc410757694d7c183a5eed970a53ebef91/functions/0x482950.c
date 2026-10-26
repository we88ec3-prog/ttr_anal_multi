
void FUN_00482950(undefined4 param_1)

{
  uint in_ECX;
  int unaff_EDI;
  uint in_stack_00000018;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0093126b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8._0_1_ = 2;
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_14 = in_ECX & 0xffff;
  FUN_008438c0(&local_14);
  if ((local_18 != DAT_00f8d9b0) && (*(int *)(local_18 + 0x10) != 0)) {
    (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x19c))(in_ECX & 0xffff,0xffffffff,0,0);
    (**(code **)(**(int **)(unaff_EDI + 0x248) + 200))();
    FUN_00757800(&param_1);
    (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
    FUN_007597b0(0);
    FUN_007597b0(1);
    (**(code **)(**(int **)(unaff_EDI + 0x250) + 200))();
  }
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

