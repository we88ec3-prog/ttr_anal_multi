
void FUN_00685810(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar1 = param_1;
  puStack_c = &LAB_0092c8d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_8 = 0xffffffff;
  param_1 = uVar1;
  FUN_008438c0(&param_1);
  if ((in_ECX != DAT_00f8d9b0) && (*(int *)(in_ECX + 0x10) != 0)) {
    FUN_00757800(*(int *)(in_ECX + 0x10) + 0x98);
    (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
    (**(code **)(**(int **)(unaff_EDI + 0x248) + 0x19c))(uVar1,0xffffffff,0,0);
    (**(code **)(**(int **)(unaff_EDI + 0x248) + 200))();
  }
  ExceptionList = local_10;
  return;
}

