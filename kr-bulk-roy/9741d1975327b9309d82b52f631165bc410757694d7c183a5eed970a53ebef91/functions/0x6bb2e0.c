
undefined4 * FUN_006bb2e0(undefined4 *param_1)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916178;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007451f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = FUI::CScenarioEntryDummy::vftable;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x36] = 5;
  param_1[0x37] = 0;
  param_1[0x3b] = 0;
  iVar1 = FUN_00891268(0x14);
  if (iVar1 != 0) {
    param_1[0x3a] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x3a] + 4) = param_1[0x3a];
    *(undefined4 *)(param_1[0x3a] + 8) = param_1[0x3a];
    *(undefined1 *)(param_1[0x3a] + 0x10) = 1;
    *(undefined1 *)(param_1[0x3a] + 0x11) = 1;
    param_1[0x3d] = 0;
    param_1[0x3e] = 0;
    param_1[0x3f] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

