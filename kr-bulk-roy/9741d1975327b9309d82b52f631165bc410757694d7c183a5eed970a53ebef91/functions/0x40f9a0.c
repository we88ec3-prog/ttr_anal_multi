
undefined4 * FUN_0040f9a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091bf94;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  local_8 = 0;
  *param_1 = FUI::CBuyPracticeTalentWnd::vftable;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x47] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_14);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  param_1[0x46] = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1[0x46] + 4) = param_1[0x46];
  *(undefined4 *)(param_1[0x46] + 8) = param_1[0x46];
  *(undefined1 *)(param_1[0x46] + 0x14) = 1;
  *(undefined1 *)(param_1[0x46] + 0x15) = 1;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  local_8._0_1_ = 2;
  param_1[0x4f] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0x4e] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x4e] + 4) = param_1[0x4e];
    *(undefined4 *)(param_1[0x4e] + 8) = param_1[0x4e];
    *(undefined1 *)(param_1[0x4e] + 0x14) = 1;
    *(undefined1 *)(param_1[0x4e] + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    *(undefined2 *)(param_1 + 0x51) = 0xffff;
    param_1[0x52] = 0;
    param_1[0x53] = 0xffffffff;
    param_1[0x54] = 0xffffffff;
    param_1[0x55] = 0xffffffff;
    param_1[0x56] = 0;
    if (param_1[0x49] != param_1[0x4a]) {
      uVar2 = FUN_00858240(param_1[0x4a],param_1);
      FUN_00516210(param_1[0x4a]);
      param_1[0x4a] = uVar2;
    }
    FUN_00823850();
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

