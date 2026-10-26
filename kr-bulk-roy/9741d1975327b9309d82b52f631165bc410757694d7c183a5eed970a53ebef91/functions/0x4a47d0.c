
undefined4 * FUN_004a47d0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904b6b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Graphics::CImage::vftable;
  local_8 = 0;
  FUN_00739120(param_1);
  if (param_1[4] != 0) {
    FUN_0089120c(param_1[4],uVar1);
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_0089120c(param_1,uVar1);
  ExceptionList = local_10;
  return param_1;
}

