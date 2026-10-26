
undefined4 * FUN_008598b0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00908ed8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = gbDxEffect::vftable;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  local_8 = 1;
  uStack_7 = 0;
  param_1[0xe] = 0;
  iVar2 = FUN_00891268(0x48,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0xd] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[0xd] + 4) = param_1[0xd];
  *(undefined4 *)(param_1[0xd] + 8) = param_1[0xd];
  *(undefined1 *)(param_1[0xd] + 0x44) = 1;
  *(undefined1 *)(param_1[0xd] + 0x45) = 1;
  local_8 = 2;
  param_1[0x12] = 0;
  uVar3 = FUN_00570a10();
  param_1[0x11] = uVar3;
  *(undefined4 *)uVar3 = uVar3;
  *(undefined4 *)(param_1[0x11] + 4) = param_1[0x11];
  *(undefined4 *)(param_1[0x11] + 8) = param_1[0x11];
  *(undefined1 *)(param_1[0x11] + 0x40) = 1;
  *(undefined1 *)(param_1[0x11] + 0x41) = 1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  local_8 = 4;
  param_1[0x1a] = 0;
  iVar2 = FUN_00891268(0x24,uVar1);
  if (iVar2 != 0) {
    param_1[0x19] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x19] + 4) = param_1[0x19];
    *(undefined4 *)(param_1[0x19] + 8) = param_1[0x19];
    *(undefined1 *)(param_1[0x19] + 0x20) = 1;
    *(undefined1 *)(param_1[0x19] + 0x21) = 1;
    _local_8 = CONCAT31(uStack_7,5);
    param_1[0x1e] = 0;
    iVar2 = FUN_00891268(0x24,uVar1);
    if (iVar2 != 0) {
      param_1[0x1d] = iVar2;
      *(int *)iVar2 = iVar2;
      *(undefined4 *)(param_1[0x1d] + 4) = param_1[0x1d];
      *(undefined4 *)(param_1[0x1d] + 8) = param_1[0x1d];
      *(undefined1 *)(param_1[0x1d] + 0x20) = 1;
      *(undefined1 *)(param_1[0x1d] + 0x21) = 1;
      param_1[0x23] = 0;
      param_1[0x24] = 0;
      param_1[0x25] = 0;
      param_1[1] = 0;
      param_1[3] = 3;
      param_1[0x21] = 0;
      param_1[2] = 1;
      param_1[0x22] = 0;
      ExceptionList = local_10;
      return param_1;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_24,&local_14);
    local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_24,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_30,&local_18);
  local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_30,&DAT_00c857a8);
}

