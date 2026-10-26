
void FUN_00540980(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int unaff_EDI;
  undefined1 local_2c [4];
  undefined4 *local_28;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939552;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_008543e0(local_2c,unaff_EDI + 0x34);
  local_8 = 0;
  FUN_00541ae0(unaff_EDI + 0x1c,param_1);
  iVar1 = *(int *)(unaff_EDI + 0x2c);
  while (iVar1 != 0) {
    param_1 = FUN_00541f10(uVar2);
    uVar3 = FUN_006bde40(&param_1);
    FUN_0044bbd0(local_2c,uVar3);
    iVar1 = *(int *)(unaff_EDI + 0x2c);
  }
  FUN_005417e0(local_2c,2);
  local_8 = 1;
  FUN_004ca160(*local_28,local_28);
  FUN_0089120c(local_28);
  ExceptionList = local_10;
  return;
}

