
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0048bd30(void)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092539a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe6994 & 1) == 0) {
    DAT_00fe6994 = DAT_00fe6994 | 1;
    local_8 = 0;
    FUN_0048b2e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bce5b0);
  }
  if ((DAT_00fe49f4 & 1) == 0) {
    DAT_00fe49f4 = DAT_00fe49f4 | 1;
    local_8 = 1;
    FUN_007134a0();
    _DAT_00fe48e0 = CPackageWrapper::CClientPackageMgr::vftable;
    _atexit(FUN_00bce070);
  }
  DAT_00fba814 = &DAT_00fe48e0;
  DAT_00fba818 = &DAT_00fe37a0;
  DAT_00fba81c = &DAT_00fe37a0;
  if ((DAT_00fe49f4 & 1) == 0) {
    DAT_00fe49f4 = DAT_00fe49f4 | 1;
    local_8 = 2;
    FUN_007134a0();
    _DAT_00fe48e0 = CPackageWrapper::CClientPackageMgr::vftable;
    _atexit(FUN_00bce070);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_00713740(&DAT_00fe48e0);
  if (iVar1 == 0) {
    ExceptionList = local_10;
    return false;
  }
  iVar1 = FUN_006d7560(iVar1);
  ExceptionList = local_10;
  return iVar1 != 0;
}

