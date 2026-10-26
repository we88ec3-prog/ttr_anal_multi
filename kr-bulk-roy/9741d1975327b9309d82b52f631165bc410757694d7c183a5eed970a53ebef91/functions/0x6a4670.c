
undefined4 * FUN_006a4670(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cf47;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x20] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0x10101;
  local_8 = 0;
  *param_1 = FUI::CGuildWnd::vftable;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x45] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0x44] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x44] + 4) = param_1[0x44];
    *(undefined4 *)(param_1[0x44] + 8) = param_1[0x44];
    *(undefined1 *)(param_1[0x44] + 0x14) = 1;
    *(undefined1 *)(param_1[0x44] + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
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

