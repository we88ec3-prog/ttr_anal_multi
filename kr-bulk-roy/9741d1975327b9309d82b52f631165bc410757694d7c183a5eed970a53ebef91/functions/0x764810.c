
void FUN_00764810(int *param_1)

{
  undefined4 ****ppppuVar1;
  undefined4 uVar2;
  undefined4 ***local_4c [5];
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091eec0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004297b0(local_14);
  local_8 = 0;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,1);
  ppppuVar1 = (undefined4 ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppuVar1 = local_4c;
  }
  uVar2 = (**(code **)(*param_1 + 0x14))(ppppuVar1);
  FUN_0072e770(uVar2,ppppuVar1);
  if (0xf < local_1c) {
    FUN_0089120c(local_30);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30 = local_30 & 0xffffff00;
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

