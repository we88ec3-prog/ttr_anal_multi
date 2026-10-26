
undefined2 * FUN_0044f520(undefined2 *param_1)

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
  
  puStack_c = &LAB_0090b7a0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  local_8 = 1;
  uStack_7 = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  *(int *)(param_1 + 0x1e) = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(*(int *)(param_1 + 0x1e) + 4) = *(int *)(param_1 + 0x1e);
  *(int *)(*(int *)(param_1 + 0x1e) + 8) = *(int *)(param_1 + 0x1e);
  *(undefined1 *)(*(int *)(param_1 + 0x1e) + 0x2c) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x1e) + 0x2d) = 1;
  _local_8 = CONCAT31(uStack_7,2);
  *(undefined4 *)(param_1 + 0x28) = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x26) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 0x26) + 4) = *(int *)(param_1 + 0x26);
    *(int *)(*(int *)(param_1 + 0x26) + 8) = *(int *)(param_1 + 0x26);
    *(undefined1 *)(*(int *)(param_1 + 0x26) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x26) + 0x2d) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

