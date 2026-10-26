
undefined4 * FUN_00454a10(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927b8d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  *param_1 = FUI::CInfiniteDungeonEntryDlg::vftable;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  param_1[0x5b] = 0;
  iVar1 = FUN_00891268(0x14);
  if (iVar1 != 0) {
    param_1[0x5a] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x5a] + 4) = param_1[0x5a];
    *(undefined4 *)(param_1[0x5a] + 8) = param_1[0x5a];
    *(undefined1 *)(param_1[0x5a] + 0x10) = 1;
    *(undefined1 *)(param_1[0x5a] + 0x11) = 1;
    local_14 = (char *)(param_1 + 0x60);
    param_1[0x5d] = 0xffffffff;
    param_1[0x5e] = 0;
    *(undefined1 *)(param_1 + 0x5f) = 0;
    local_14[0] = '\0';
    local_14[1] = '\0';
    local_14[2] = '\0';
    local_14[3] = '\0';
    param_1[0x61] = 0;
    param_1[0x62] = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00452300(local_14);
    *(undefined1 *)(param_1 + 100) = 0;
    param_1[0x3f] = 0;
    param_1[0x40] = 0;
    param_1[0x41] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

