
undefined4 * FUN_00673f70(undefined4 *param_1)

{
  int iVar1;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920ccf;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  local_8 = 0;
  *param_1 = FUI::CShopConsumptionDlg::vftable;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[99] = 0;
  iVar1 = FUN_00891268(0xc);
  if (iVar1 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0x62] = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1[0x62] + 4) = param_1[0x62];
  local_8._0_1_ = 1;
  param_1[0x67] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0x66] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x66] + 4) = param_1[0x66];
    *(undefined4 *)(param_1[0x66] + 8) = param_1[0x66];
    *(undefined1 *)(param_1[0x66] + 0x14) = 1;
    *(undefined1 *)(param_1[0x66] + 0x15) = 1;
    param_1[0x69] = 0;
    param_1[0x6a] = 0;
    param_1[0x6b] = 0;
    local_8._0_1_ = 3;
    param_1[0x6d] = 0;
    param_1[0x72] = 0;
    param_1[0x73] = 0;
    *(undefined1 *)((int)param_1 + 0x1d5) = 0;
    param_1[0x7b] = 7;
    param_1[0x7a] = 0;
    *(undefined2 *)(param_1 + 0x76) = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    *(undefined1 *)(param_1 + 0x7d) = 0;
    param_1[0x7e] = 0;
    param_1[0x7f] = 0;
    param_1[0x80] = 0;
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_004d7fe0(param_1 + 0x7e,&local_18,0,0);
    param_1[0x50] = 0;
    param_1[0x55] = 0;
    param_1[0x51] = 0;
    param_1[0x56] = 0;
    param_1[0x52] = 0;
    param_1[0x57] = 0;
    param_1[0x53] = 0;
    param_1[0x58] = 0;
    param_1[0x54] = 0;
    param_1[0x59] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

