
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007bef00(void)

{
  int iVar1;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090eb09;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe1b60;
  FUN_007c02f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  _DAT_00fe1b78 = 0;
  iVar1 = FUN_00891268(0x40);
  if (iVar1 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fe1b74 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(DAT_00fe1b74 + 4) = DAT_00fe1b74;
  *(int *)(DAT_00fe1b74 + 8) = DAT_00fe1b74;
  *(undefined1 *)(DAT_00fe1b74 + 0x38) = 1;
  *(undefined1 *)(DAT_00fe1b74 + 0x39) = 1;
  local_8._0_1_ = 1;
  _DAT_00fe1b88 = 0;
  iVar1 = FUN_00891268(0x40);
  if (iVar1 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe1b84 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(DAT_00fe1b84 + 4) = DAT_00fe1b84;
  *(int *)(DAT_00fe1b84 + 8) = DAT_00fe1b84;
  *(undefined1 *)(DAT_00fe1b84 + 0x38) = 1;
  *(undefined1 *)(DAT_00fe1b84 + 0x39) = 1;
  local_8._0_1_ = 2;
  _DAT_00fe1b98 = 0;
  iVar1 = FUN_00891268(0x28);
  if (iVar1 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fe1b94 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(DAT_00fe1b94 + 4) = DAT_00fe1b94;
  *(int *)(DAT_00fe1b94 + 8) = DAT_00fe1b94;
  *(undefined1 *)(DAT_00fe1b94 + 0x20) = 1;
  *(undefined1 *)(DAT_00fe1b94 + 0x21) = 1;
  local_8._0_1_ = 3;
  _DAT_00fe1ba8 = 0;
  iVar1 = FUN_00891268(0x28);
  if (iVar1 != 0) {
    DAT_00fe1ba4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1ba4 + 4) = DAT_00fe1ba4;
    *(int *)(DAT_00fe1ba4 + 8) = DAT_00fe1ba4;
    *(undefined1 *)(DAT_00fe1ba4 + 0x20) = 1;
    *(undefined1 *)(DAT_00fe1ba4 + 0x21) = 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    _DAT_00fe1bb8 = 0;
    iVar1 = FUN_00891268(0x30);
    if (iVar1 != 0) {
      DAT_00fe1bb4 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fe1bb4 + 4) = DAT_00fe1bb4;
      *(int *)(DAT_00fe1bb4 + 8) = DAT_00fe1bb4;
      *(undefined1 *)(DAT_00fe1bb4 + 0x28) = 1;
      *(undefined1 *)(DAT_00fe1bb4 + 0x29) = 1;
      ExceptionList = local_10;
      return &DAT_00fe1b60;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_18);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

