
void FUN_006c9150(undefined4 param_1)

{
  uint uVar1;
  int unaff_EDI;
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e518;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00757800(&param_1);
  (**(code **)(**(int **)(unaff_EDI + 0xf4) + 200))(uVar1);
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

