
undefined2 * FUN_00757200(undefined2 *param_1)

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
  
  puStack_c = &LAB_00911cf3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar2 = FUN_00891268(0x10,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  *(int *)(param_1 + 0xe) = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(*(int *)(param_1 + 0xe) + 4) = *(int *)(param_1 + 0xe);
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar2 = FUN_00891268(0x24,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x16) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 0x16) + 4) = *(int *)(param_1 + 0x16);
    *(int *)(*(int *)(param_1 + 0x16) + 8) = *(int *)(param_1 + 0x16);
    *(undefined1 *)(*(int *)(param_1 + 0x16) + 0x20) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x16) + 0x21) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

