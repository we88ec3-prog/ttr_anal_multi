
void FUN_005e1c60(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((((0 < *(int *)(param_2 + 4)) && (*(int *)(param_2 + 4) < 10)) &&
      (*(int *)(param_2 + 8) != 0x1f)) && (*(int *)(param_2 + 8) != 0x1d)) {
    uVar2 = 0x1c6;
    FUN_00585620(0x1c6,uVar1);
    FUN_00585330(uVar2);
    uVar2 = FUN_004ed610();
    local_8 = 0;
    FUN_004041f0(uVar2,0,0xffffffff);
    FUN_004fa440();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

