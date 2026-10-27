
void FUN_00540a40(uint param_1)

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
  FUN_00541c00(param_1);
  FUN_00541f90(unaff_EDI + 0x1c);
  iVar1 = *(int *)(unaff_EDI + 0x2c);
  while (iVar1 != 0) {
    param_1 = FUN_00541f10(uVar2);
    param_1 = param_1 & 0xffff;
    uVar3 = FUN_00541a50(&param_1);
    FUN_0044bbd0(local_2c,uVar3);
    iVar1 = *(int *)(unaff_EDI + 0x2c);
  }
  FUN_005417e0(local_2c,1);
  local_8 = 1;
  FUN_004ca160(*local_28,local_28);
  FUN_0089120c(local_28);
  ExceptionList = local_10;
  return;
}

