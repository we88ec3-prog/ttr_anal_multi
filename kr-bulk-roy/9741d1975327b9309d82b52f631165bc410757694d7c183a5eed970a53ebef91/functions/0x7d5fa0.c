
undefined1 * FUN_007d5fa0(undefined1 *param_1)

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
  
  puStack_c = &LAB_00909e35;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  *(int *)(param_1 + 0x20) = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(*(int *)(param_1 + 0x20) + 4) = *(int *)(param_1 + 0x20);
  *(int *)(*(int *)(param_1 + 0x20) + 8) = *(int *)(param_1 + 0x20);
  *(undefined1 *)(*(int *)(param_1 + 0x20) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x20) + 0x2d) = 1;
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 1;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x38) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 0x38) + 4) = *(int *)(param_1 + 0x38);
    *(int *)(*(int *)(param_1 + 0x38) + 8) = *(int *)(param_1 + 0x38);
    *(undefined1 *)(*(int *)(param_1 + 0x38) + 0x14) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x38) + 0x15) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

