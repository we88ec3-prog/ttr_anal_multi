
void FUN_004a5110(int param_1)

{
  uint uVar1;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00930d5e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int *)(unaff_EDI + 0x254) = param_1;
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcce20);
  }
  local_8 = 0xffffffff;
  FUN_00757800(param_1 + 4);
  *(undefined4 *)(*(int *)(unaff_EDI + 0x24c) + 0x154) = *(undefined4 *)(param_1 + 0x6c);
  (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

