
void FUN_0066f330(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  int unaff_EDI;
  uint in_stack_ffffffd0;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_004068f0(uVar1);
  local_8 = 0;
  FUN_00757800(uVar2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(in_stack_ffffffd0);
  }
  in_stack_ffffffd0 = in_stack_ffffffd0 & 0xffff0000;
  (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc,extraout_EDX,in_stack_ffffffd0);
  return;
}

