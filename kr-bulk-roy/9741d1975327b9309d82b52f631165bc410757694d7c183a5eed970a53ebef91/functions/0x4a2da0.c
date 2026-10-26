
void FUN_004a2da0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_12c [65];
  undefined4 *local_28;
  undefined4 local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009277d6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007134a0(local_14);
  local_8 = 0;
  DAT_00fba814 = local_12c;
  iVar1 = FUN_00714d50("Table");
  iVar2 = FUN_00891268(0x178);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00715270(iVar2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00715620(1);
  *(undefined4 *)(iVar1 + 0x100) = uVar3;
  if (DAT_00fba797 == '\0') {
    FUN_00585390();
  }
  DAT_00fba814 = (undefined ***)0x0;
  local_12c[0] = Package::CPackageMgr::vftable;
  local_8 = 2;
  if (local_28 != (undefined4 *)0x0) {
    (**(code **)*local_28)(1);
    local_28 = (undefined4 *)0x0;
  }
  local_8 = 3;
  FUN_00714eb0();
  FUN_0089120c(local_24);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

