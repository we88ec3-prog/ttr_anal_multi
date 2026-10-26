
void FUN_006477c0(void)

{
  undefined4 uVar1;
  int unaff_EDI;
  undefined4 local_4c [5];
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092d0b0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  uVar1 = FUN_00647ea0(local_4c,(float)*(int *)(*(int *)(unaff_EDI + 0xf4) + 0xc4),local_14);
  local_8._0_1_ = 1;
  FUN_004041f0(uVar1,0,0xffffffff);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  FUN_00404300(&DAT_00c02ba8,1);
  FUN_00757800(local_30);
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

