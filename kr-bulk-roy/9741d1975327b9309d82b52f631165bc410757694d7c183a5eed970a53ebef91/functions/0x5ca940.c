
undefined4 * FUN_005ca940(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cdd6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0x3f800000;
  param_1[3] = 0x3f800000;
  param_1[2] = 0x3f800000;
  param_1[4] = 0x3f800000;
  param_1[5] = 0;
  local_8 = 0;
  *param_1 = FUI::CIMEManager::vftable;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 4;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x14] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[0x13] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x13] + 4) = param_1[0x13];
    *(undefined4 *)(param_1[0x13] + 8) = param_1[0x13];
    *(undefined1 *)(param_1[0x13] + 0x14) = 1;
    *(undefined1 *)(param_1[0x13] + 0x15) = 1;
    local_8._0_1_ = 1;
    puVar3 = (undefined4 *)FUN_00891268(0x80,uVar1);
    local_8._0_1_ = 2;
    local_18 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = FoxUI::FXUIManagedRect::vftable;
      _eh_vector_constructor_iterator_
                (puVar3 + 1,0x14,6,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
      puVar3[0x1f] = 0;
    }
    local_8._0_1_ = 1;
    param_1[0x11] = puVar3;
    local_18 = (undefined4 *)FUN_00891268(0x8c,uVar1);
    local_8._0_1_ = 3;
    if (local_18 == (undefined4 *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_007754b0(3);
    }
    local_8._0_1_ = 1;
    param_1[0xf] = uVar4;
    local_18 = (undefined4 *)FUN_00891268(0x8c);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (local_18 == (undefined4 *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_007754b0(0);
    }
    param_1[0x10] = uVar4;
    *(undefined4 *)(param_1[0xf] + 0x88) = 0x3f800000;
    *(undefined4 *)(param_1[0x10] + 0x88) = 0x3f800000;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

