
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_008132e0(void)

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
  puStack_c = &LAB_009097da;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fab000;
  _DAT_00fab008 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fab004 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab004 + 4) = DAT_00fab004;
  *(int *)(DAT_00fab004 + 8) = DAT_00fab004;
  *(undefined1 *)(DAT_00fab004 + 0x14) = 1;
  *(undefined1 *)(DAT_00fab004 + 0x15) = 1;
  local_8 = 0;
  _DAT_00fab018 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    DAT_00fab014 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fab014 + 4) = DAT_00fab014;
    *(int *)(DAT_00fab014 + 8) = DAT_00fab014;
    *(undefined1 *)(DAT_00fab014 + 0x14) = 1;
    *(undefined1 *)(DAT_00fab014 + 0x15) = 1;
    DAT_00fab020 = 0;
    ExceptionList = local_10;
    return &DAT_00fab000;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

