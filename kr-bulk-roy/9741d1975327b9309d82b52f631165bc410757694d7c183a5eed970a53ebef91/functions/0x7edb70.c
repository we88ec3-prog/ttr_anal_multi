
void FUN_007edb70(undefined4 param_1)

{
  uint uVar1;
  int *in_EDX;
  undefined1 local_50 [56];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918768;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  if (*in_EDX != 0) {
    FUN_007ed8d0(local_50,param_1);
    local_8 = 0;
    FUN_007edcd0(uVar1);
    FUN_007ee080();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

