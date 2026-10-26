
void FUN_008fe320(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int unaff_ESI;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921c3f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x38,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_008fd800();
  }
  local_8 = 0xffffffff;
  FUN_008fe030(param_1,param_2,param_3,*(undefined4 *)(unaff_ESI + 0x70));
  FUN_00572150(&local_14);
  ExceptionList = local_10;
  return;
}

