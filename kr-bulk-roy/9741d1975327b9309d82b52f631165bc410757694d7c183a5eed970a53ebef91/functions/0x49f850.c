
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0049f850(void)

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
  puStack_c = &LAB_009065fd;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fb72a8;
  _DAT_00fb72a8 = 0;
  DAT_00fb72ac = 0;
  _DAT_00fb72b0 = 0;
  _DAT_00fb72b4 = 0;
  _DAT_00fb72c0 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fb72bc = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fb72bc + 4) = DAT_00fb72bc;
  *(int *)(DAT_00fb72bc + 8) = DAT_00fb72bc;
  *(undefined1 *)(DAT_00fb72bc + 0x14) = 1;
  *(undefined1 *)(DAT_00fb72bc + 0x15) = 1;
  local_8 = 0;
  _DAT_00fb72cc = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 != 0) {
    DAT_00fb72c8 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fb72c8 + 4) = DAT_00fb72c8;
    _DAT_00fb72d4 = 0;
    _DAT_00fb72d8 = 0;
    _DAT_00fb72dc = 0;
    _DAT_00fb72e0 = 0;
    _DAT_00fb72e4 = 0;
    ExceptionList = local_10;
    return &DAT_00fb72a8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

