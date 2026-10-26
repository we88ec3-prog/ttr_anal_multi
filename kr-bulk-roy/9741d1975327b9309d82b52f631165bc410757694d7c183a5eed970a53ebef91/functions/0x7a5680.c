
int FUN_007a5680(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a17d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007a5020(param_1 + 8);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x2c) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(*(int *)(param_1 + 0x2c) + 4) = *(int *)(param_1 + 0x2c);
    *(int *)(*(int *)(param_1 + 0x2c) + 8) = *(int *)(param_1 + 0x2c);
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x20) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x21) = 1;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

