
int FUN_004d8c40(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924cdf;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = FUN_00891268(0x58,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_24,&local_14);
    local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_24,&DAT_00c857a8);
  }
  *(int *)(param_1 + 4) = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x54) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x55) = 1;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x14) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
    *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);
    *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x14) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x15) = 1;
    local_8._0_1_ = 1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    iVar2 = FUN_00891268(0x24,uVar1);
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x24) = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(*(int *)(param_1 + 0x24) + 4) = *(int *)(param_1 + 0x24);
      *(int *)(*(int *)(param_1 + 0x24) + 8) = *(int *)(param_1 + 0x24);
      *(undefined1 *)(*(int *)(param_1 + 0x24) + 0x20) = 1;
      *(undefined1 *)(*(int *)(param_1 + 0x24) + 0x21) = 1;
      *(undefined4 *)(param_1 + 0x44) = 7;
      *(undefined4 *)(param_1 + 0x40) = 0;
      *(undefined2 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x60) = 7;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined2 *)(param_1 + 0x4c) = 0;
      *(undefined2 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined4 *)(param_1 + 0x70) = 0;
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_004d8f50(param_1);
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

