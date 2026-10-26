
void FUN_005e48e0(undefined4 param_1,int param_2,int param_3)

{
  int in_EDX;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d838;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00483f00();
  local_8 = 0;
  FUN_004041f0();
  if (7 < local_38) {
    FUN_0089120c();
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_8 = 1;
  if ((in_EDX - param_3 < 1) || (param_3 < 1)) {
    if (in_EDX - param_3 < 0) {
      FUN_004068f0();
      local_8._0_1_ = 3;
      FUN_004041f0();
    }
    else {
      FUN_0040aff0();
      local_8._0_1_ = 4;
      FUN_004041f0();
    }
  }
  else {
    FUN_004068f0();
    local_8._0_1_ = 2;
    FUN_004041f0();
  }
  local_8._0_1_ = 1;
  if (7 < local_1c) {
    local_8._0_1_ = 1;
    FUN_0089120c();
  }
  if (in_EDX == param_2) {
    FUN_004026e0(local_4c,0,0xffffffff);
    FUN_00424c80(L"<#5AFF78> {0}");
    local_8._0_1_ = 6;
    FUN_004041f0();
  }
  else {
    FUN_004026e0(local_4c,0,0xffffffff);
    FUN_004183b0(L"<#5AFF78> + {0} {1}",in_EDX - param_2);
    local_8._0_1_ = 5;
    FUN_004041f0();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < local_1c) {
    FUN_0089120c();
  }
  FUN_00404300();
  if (7 < local_38) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

