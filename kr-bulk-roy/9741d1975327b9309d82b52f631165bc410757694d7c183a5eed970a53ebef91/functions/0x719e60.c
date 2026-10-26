
void FUN_00719e60(undefined4 param_1)

{
  uint uVar1;
  undefined4 in_EDX;
  undefined4 unaff_EDI;
  undefined1 local_40 [4];
  undefined1 local_3c [8];
  undefined1 *local_34;
  undefined4 local_30;
  int local_28 [4];
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935658;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = 0;
  FUN_00721830(in_EDX,local_40,param_1);
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_8 = 1;
  FUN_0071a120(0,local_34,local_30,param_1);
  local_8 = 0xffffffff;
  if (local_34 != local_3c) {
    (*(code *)PTR_FUN_00d63d4c)(local_34,uVar1);
  }
  local_8 = 2;
  FUN_004fcd00(unaff_EDI,local_28);
  if (local_28[0] != 0) {
    FUN_0089120c(local_28[0]);
  }
  ExceptionList = local_10;
  return;
}

