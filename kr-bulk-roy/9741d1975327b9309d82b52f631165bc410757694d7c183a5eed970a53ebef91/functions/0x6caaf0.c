
void FUN_006caaf0(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint in_ECX;
  undefined4 extraout_EDX;
  uint in_stack_ffffffd0;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_00421540(L"{0=##}:{1=##}:{2=##}",in_ECX / 60000,uVar1);
  local_8 = 0;
  FUN_00757800(uVar2);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(in_stack_ffffffd0);
  }
  in_stack_ffffffd0 = in_stack_ffffffd0 & 0xffff0000;
  (**(code **)(*param_1 + 200))();
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc,extraout_EDX,in_stack_ffffffd0);
  return;
}

