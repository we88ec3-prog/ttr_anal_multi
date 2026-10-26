
void FUN_007599b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  undefined4 local_68 [5];
  uint local_54;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009192b8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0075a900(param_1,param_2,local_14);
  local_8 = 0;
  FUN_00759d70(local_68);
  local_38 = 7;
  local_3c = 0;
  local_4c = (uint)local_4c._2_2_ << 0x10;
  FUN_00402160(&DAT_00bfb894,1);
  local_8._0_1_ = 1;
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_1c = 7;
  local_20 = 0;
  FUN_00402160(&DAT_00c059b8,2);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00759330(in_ECX,&local_30,&local_4c);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = local_30 & 0xffff0000;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  if (7 < local_54) {
    FUN_0089120c(local_68[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

