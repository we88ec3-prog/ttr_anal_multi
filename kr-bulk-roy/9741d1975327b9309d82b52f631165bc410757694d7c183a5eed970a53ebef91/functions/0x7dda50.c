
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007dda50(void)

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
  puStack_c = &LAB_00909d6d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_00fe32d4 = 0x4b7fffff;
  _DAT_00fe32d8 = 0x4b7fffff;
  local_1c = &DAT_00fe32c0;
  _DAT_00fe32c0 = 1;
  _DAT_00fe32c4 = 0;
  _DAT_00fe32c8 = 0;
  _DAT_00fe32cc = 1;
  _DAT_00fe32d0 = 0;
  _DAT_00fe32e4 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe32e0 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fe32e0 + 4) = DAT_00fe32e0;
  *(int *)(DAT_00fe32e0 + 8) = DAT_00fe32e0;
  *(undefined1 *)(DAT_00fe32e0 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fe32e0 + 0x2d) = 1;
  local_8 = 0;
  _DAT_00fe32f4 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    DAT_00fe32f0 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fe32f0 + 4) = DAT_00fe32f0;
    *(int *)(DAT_00fe32f0 + 8) = DAT_00fe32f0;
    *(undefined1 *)(DAT_00fe32f0 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe32f0 + 0x2d) = 1;
    ExceptionList = local_10;
    return &DAT_00fe32c0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

