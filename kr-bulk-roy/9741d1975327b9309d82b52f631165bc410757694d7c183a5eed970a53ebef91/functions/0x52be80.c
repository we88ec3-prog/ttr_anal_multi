
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0052be80(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923741;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fc0d00;
  _DAT_00fc0d08 = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fc0d04 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc0d04 + 4) = DAT_00fc0d04;
  *(int *)(DAT_00fc0d04 + 8) = DAT_00fc0d04;
  *(undefined1 *)(DAT_00fc0d04 + 0x24) = 1;
  *(undefined1 *)(DAT_00fc0d04 + 0x25) = 1;
  local_8 = 0;
  _DAT_00fc0d18 = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fc0d14 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc0d14 + 4) = DAT_00fc0d14;
  *(int *)(DAT_00fc0d14 + 8) = DAT_00fc0d14;
  *(undefined1 *)(DAT_00fc0d14 + 0x24) = 1;
  *(undefined1 *)(DAT_00fc0d14 + 0x25) = 1;
  local_8._0_1_ = 1;
  _DAT_00fc0d28 = 0;
  iVar2 = FUN_00891268(0x40,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fc0d24 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc0d24 + 4) = DAT_00fc0d24;
  *(int *)(DAT_00fc0d24 + 8) = DAT_00fc0d24;
  *(undefined1 *)(DAT_00fc0d24 + 0x38) = 1;
  *(undefined1 *)(DAT_00fc0d24 + 0x39) = 1;
  local_8._0_1_ = 2;
  _DAT_00fc0d38 = 0;
  iVar2 = FUN_00891268(0x24,uVar1);
  if (iVar2 != 0) {
    DAT_00fc0d34 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc0d34 + 4) = DAT_00fc0d34;
    *(int *)(DAT_00fc0d34 + 8) = DAT_00fc0d34;
    *(undefined1 *)(DAT_00fc0d34 + 0x20) = 1;
    *(undefined1 *)(DAT_00fc0d34 + 0x21) = 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0052c390();
    ExceptionList = local_10;
    return &DAT_00fc0d00;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

