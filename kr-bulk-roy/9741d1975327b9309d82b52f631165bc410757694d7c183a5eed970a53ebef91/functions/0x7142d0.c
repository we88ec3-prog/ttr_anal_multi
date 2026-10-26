
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_007142d0(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a818;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe4c7c;
  _DAT_00fe4c80 = 0;
  iVar2 = FUN_00891268(0x24,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe4c7c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fe4c7c + 4) = DAT_00fe4c7c;
  local_8 = 0;
  _DAT_00fe4c8c = 0;
  iVar2 = FUN_00891268(0x24,uVar1);
  if (iVar2 != 0) {
    DAT_00fe4c88 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fe4c88 + 4) = DAT_00fe4c88;
    DAT_00fe4c94 = 0;
    ExceptionList = local_10;
    return &DAT_00fe4c7c;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

