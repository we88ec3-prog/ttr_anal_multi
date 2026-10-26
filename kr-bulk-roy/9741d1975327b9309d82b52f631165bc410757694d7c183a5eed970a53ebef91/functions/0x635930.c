
undefined4 * FUN_00635930(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00949270;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007451f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = FUI::CTalkBoxDialog::vftable;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  *(undefined1 *)(param_1 + 0x23) = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  puVar1 = param_1 + 0x27;
  *puVar1 = 0;
  puVar2 = (undefined4 *)FUN_00891268(8);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar1 = puVar2;
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined4 **)*puVar1 = puVar1;
    param_1[0x28] = 0;
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
    local_8._0_1_ = 1;
    *(undefined2 *)(param_1 + 0x2d) = 0;
    param_1[0x2e] = 0;
    local_14 = (char *)FUN_00891268(0x180);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_14 == (char *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_006370c0(local_14);
    }
    param_1[0x2f] = iVar3;
    param_1[0x30] = 0;
    param_1[0x31] = 0;
    param_1[0x32] = 0;
    param_1[0x33] = 0;
    param_1[0x34] = 0;
    param_1[0x35] = 0;
    param_1[0x36] = 0;
    *(undefined4 **)(iVar3 + 4) = param_1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

