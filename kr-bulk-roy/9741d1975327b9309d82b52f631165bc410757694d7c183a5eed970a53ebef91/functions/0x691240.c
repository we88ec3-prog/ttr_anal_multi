
void FUN_00691240(undefined4 param_1)

{
  uint uVar1;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009161c0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_40 = 7;
  local_44 = 0;
  local_54[0] = local_54[0] & 0xffff0000;
  local_14 = uVar1;
  FUN_004026e0(&param_1,0,0xffffffff);
  local_24 = 7;
  local_28 = 0;
  local_38 = (uint)local_38._2_2_ << 0x10;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004026e0(local_54,0,0xffffffff);
  local_1c = in_stack_00000020;
  local_18 = in_stack_00000024;
  if (7 < local_40) {
    FUN_0089120c(local_54[0],uVar1);
  }
  local_40 = 7;
  local_44 = 0;
  local_54[0] = local_54[0] & 0xffff0000;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_00691d10();
  if (7 < local_24) {
    FUN_0089120c(local_38,uVar1);
  }
  local_24 = 7;
  local_28 = 0;
  local_38 = local_38 & 0xffff0000;
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

