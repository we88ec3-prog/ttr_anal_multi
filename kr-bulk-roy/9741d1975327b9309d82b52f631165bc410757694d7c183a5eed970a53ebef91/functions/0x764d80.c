
/* WARNING: Removing unreachable block (ram,0x00764e75) */

void FUN_00764d80(void)

{
  char cVar1;
  int *in_ECX;
  uint local_70;
  char ***local_4c [5];
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091edd0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004297b0();
  local_8 = 0;
  FUN_004297b0();
  local_8._0_1_ = 1;
  if (local_38 < 0x10) {
    local_4c[0] = (char ***)local_4c;
  }
  do {
    cVar1 = *(char *)local_4c[0];
    local_4c[0] = (char ***)((int)local_4c[0] + 1);
  } while (cVar1 != '\0');
  FUN_00402a70();
  local_8._0_1_ = 2;
  (**(code **)(*in_ECX + 0x14))();
  FUN_0072ecf0();
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_00402bb0();
  if (0xf < local_70) {
    FUN_0089120c();
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00403040(local_4c,0,0xffffffff);
  FUN_007651e0();
  if (0xf < local_1c) {
    FUN_0089120c();
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30 = local_30 & 0xffffff00;
  if (0xf < local_38) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

