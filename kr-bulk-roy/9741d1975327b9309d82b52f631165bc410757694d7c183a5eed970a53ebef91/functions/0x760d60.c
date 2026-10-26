
undefined4 * FUN_00760d60(undefined4 *param_1)

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
  puStack_c = &LAB_00911c77;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007451f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = FoxUI::FXUIPage::vftable;
  param_1[0x22] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0x21] = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1[0x21] + 4) = param_1[0x21];
  *(undefined4 *)(param_1[0x21] + 8) = param_1[0x21];
  *(undefined1 *)(param_1[0x21] + 0x14) = 1;
  *(undefined1 *)(param_1[0x21] + 0x15) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[0x26] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0x25] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0x25] + 4) = param_1[0x25];
    *(undefined4 *)(param_1[0x25] + 8) = param_1[0x25];
    *(undefined1 *)(param_1[0x25] + 0x14) = 1;
    *(undefined1 *)(param_1[0x25] + 0x15) = 1;
    param_1[10] = 0x180;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

