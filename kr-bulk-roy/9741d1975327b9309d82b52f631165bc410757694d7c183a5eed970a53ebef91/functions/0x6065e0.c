
undefined4 * FUN_006065e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a834;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  param_1[0x3d] = IInventoryUpdateObserver::vftable;
  *param_1 = FUI::CPackageProvideProductsDlg::vftable;
  param_1[0x3d] = FUI::CPackageProvideProductsDlg::vftable;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  local_8 = 2;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = param_1;
    *puVar1 = FUI::ItemPackageProvider::CCashShopPackageDlg::vftable;
  }
  param_1[0x46] = puVar1;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = param_1;
    *puVar1 = FUI::ItemPackageProvider::CItemPackageDlg::vftable;
  }
  param_1[0x45] = puVar1;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 == (undefined4 *)0x0) {
    param_1[0x47] = 0;
  }
  else {
    puVar1[1] = param_1;
    *puVar1 = FUI::ItemPackageProvider::CCompoundPackageDlg::vftable;
    param_1[0x47] = puVar1;
  }
  ExceptionList = local_10;
  return param_1;
}

