
void FUN_0046e3c0(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e578;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  puVar1 = param_1;
  if (in_stack_00000018 < 0x10) {
    puVar1 = &param_1;
  }
  FUN_0046e270(puVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

