
void FUN_00432b90(undefined4 param_1)

{
  uint uVar1;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004026e0(param_1,0,0xffffffff);
  FUN_00432ac0();
  local_8 = 0;
  FUN_00432940();
  if (0xf < local_1c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

