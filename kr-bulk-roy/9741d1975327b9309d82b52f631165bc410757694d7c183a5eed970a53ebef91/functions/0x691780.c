
void FUN_00691780(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
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
  
  puStack_c = &LAB_0092c6e0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x134) + 0x24c);
  if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0xdc);
  }
  local_14 = uVar1;
  FUN_004026e0(iVar2 + 0xe8,0,0xffffffff);
  if ((*(uint *)(*(int *)(unaff_EDI + 0x138) + 0x28) >> 7 & 1) != 0) {
    iVar2 = *(int *)(*(int *)(unaff_EDI + 0x138) + 0x24c);
    if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0xdc);
    }
    uVar3 = FUN_005e92c0(local_4c,&DAT_00c0311c,iVar2 + 0xe8,uVar1);
    local_8._0_1_ = 1;
    FUN_004041f0(uVar3,0,0xffffffff);
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  FUN_00757800(local_30);
  (**(code **)(**(int **)(unaff_EDI + 0x1f0) + 200))();
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

