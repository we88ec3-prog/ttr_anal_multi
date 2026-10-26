
undefined4 * FUN_00772b20(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090a696;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  *param_1 = FoxUI::FXUIFontType::vftable;
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[0xe] = 7;
  param_1[0xd] = 0;
  *(undefined2 *)(param_1 + 9) = 0;
  param_1[0x15] = 7;
  param_1[0x14] = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  local_8 = 3;
  uStack_7 = 0;
  param_1[0x19] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0x18] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[0x18] + 4) = param_1[0x18];
  *(undefined4 *)(param_1[0x18] + 8) = param_1[0x18];
  *(undefined1 *)(param_1[0x18] + 0x14) = 1;
  *(undefined1 *)(param_1[0x18] + 0x15) = 1;
  _local_8 = CONCAT31(uStack_7,4);
  param_1[0x1d] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0x1c] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x1c] + 4) = param_1[0x1c];
    *(undefined4 *)(param_1[0x1c] + 8) = param_1[0x1c];
    *(undefined1 *)(param_1[0x1c] + 0x14) = 1;
    *(undefined1 *)(param_1[0x1c] + 0x15) = 1;
    param_1[0x20] = 0x3faa3d71;
    *(undefined1 *)(param_1 + 0x1f) = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

