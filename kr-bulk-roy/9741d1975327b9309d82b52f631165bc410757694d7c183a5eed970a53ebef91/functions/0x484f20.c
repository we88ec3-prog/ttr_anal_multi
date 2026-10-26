
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00484f20(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090dcb2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fc0ddc;
  FUN_00485780(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  _DAT_00fc0df4 = 0;
  iVar1 = FUN_00891268(0x24);
  if (iVar1 != 0) {
    DAT_00fc0df0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc0df0 + 4) = DAT_00fc0df0;
    *(int *)(DAT_00fc0df0 + 8) = DAT_00fc0df0;
    *(undefined1 *)(DAT_00fc0df0 + 0x20) = 1;
    *(undefined1 *)(DAT_00fc0df0 + 0x21) = 1;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00485810(*(undefined4 *)(DAT_00fc0de0 + 4));
    *(int *)(DAT_00fc0de0 + 4) = DAT_00fc0de0;
    *(int *)DAT_00fc0de0 = DAT_00fc0de0;
    *(int *)(DAT_00fc0de0 + 8) = DAT_00fc0de0;
    DAT_00fc0de4 = 0;
    FUN_00485810(*(undefined4 *)(DAT_00fc0df0 + 4));
    *(int *)(DAT_00fc0df0 + 4) = DAT_00fc0df0;
    *(int *)DAT_00fc0df0 = DAT_00fc0df0;
    *(int *)(DAT_00fc0df0 + 8) = DAT_00fc0df0;
    _DAT_00fc0df4 = 0;
    ExceptionList = local_10;
    return &DAT_00fc0ddc;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

