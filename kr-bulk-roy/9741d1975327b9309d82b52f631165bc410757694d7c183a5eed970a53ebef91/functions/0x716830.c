
void FUN_00716830(void)

{
  uint uVar1;
  int iVar2;
  int unaff_ESI;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_14 = uVar1;
  FUN_00402a70("COMMON_DDS",10);
  local_8 = 0;
  iVar2 = FUN_007b6f30(local_30);
  if (iVar2 != *(int *)(unaff_ESI + 4)) {
    FUN_0049ae30(uVar1);
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

