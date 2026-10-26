
undefined4 * FUN_0047c370(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927ab3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  local_8 = 0;
  *param_1 = FUI::CScenarioReviewWnd::vftable;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x45] = 0;
  iVar2 = FUN_00891268(0x18);
  if (iVar2 != 0) {
    param_1[0x44] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x44] + 4) = param_1[0x44];
    *(undefined4 *)(param_1[0x44] + 8) = param_1[0x44];
    *(undefined1 *)(param_1[0x44] + 0x14) = 1;
    *(undefined1 *)(param_1[0x44] + 0x15) = 1;
    uVar1 = local_8 >> 8;
    param_1[0x47] = 0;
    param_1[0x48] = 0;
    param_1[0x49] = 0;
    if ((DAT_00fc0f64 & 1) == 0) {
      DAT_00fc0f64 = DAT_00fc0f64 | 1;
      local_8._0_1_ = 2;
      FUN_0047dce0();
      _atexit(FUN_00bcdaf0);
      uVar1 = (uint)local_8._1_3_;
    }
    param_1[0x47] = DAT_00fc0f78;
    if ((DAT_00fc0f64 & 1) == 0) {
      DAT_00fc0f64 = DAT_00fc0f64 | 1;
      local_8._1_3_ = (uint3)uVar1;
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_0047dce0();
      _atexit(FUN_00bcdaf0);
    }
    param_1[0x48] = DAT_00fc0f7c;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

