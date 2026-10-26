
void FUN_007cff00(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EDI;
  undefined1 local_40 [4];
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009117f8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_40;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  iVar3 = FUN_007b6f30(param_1);
  if (iVar3 != *(int *)(unaff_EDI + 4)) {
    cVar1 = FUN_0049ae30(uVar2);
    if (cVar1 == '\0') goto LAB_007cffb4;
  }
  local_28 = 0xf;
  local_2c = 0;
  local_3c[0] = local_3c[0] & 0xffffff00;
  FUN_00403040(param_1,0,0xffffffff);
  local_20 = 0;
  local_c = 0;
  uVar4 = FUN_00552de0(local_3c);
  FUN_007d0420(iVar3,uVar4);
  if (0xf < local_28) {
    FUN_0089120c(local_3c[0]);
  }
LAB_007cffb4:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_40);
  return;
}

