
int FUN_0047e580(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b646;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x1c) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  local_8 = 1;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x38) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 0x38) + 4) = *(int *)(param_1 + 0x38);
    *(int *)(*(int *)(param_1 + 0x38) + 8) = *(int *)(param_1 + 0x38);
    *(undefined1 *)(*(int *)(param_1 + 0x38) + 0x24) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x38) + 0x25) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

