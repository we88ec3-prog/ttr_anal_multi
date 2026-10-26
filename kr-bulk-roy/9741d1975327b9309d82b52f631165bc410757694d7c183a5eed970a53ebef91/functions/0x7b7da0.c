
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_007b7da0(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  undefined1 local_11;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909ff1;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_18 = (char *)FUN_00891268(0x2c,uVar1);
  local_8 = 0;
  if (local_18 == (char *)0x0) {
    DAT_00fe173c = 0;
  }
  else {
    DAT_00fe173c = FUN_007dc3d0(local_18);
  }
  local_8 = 0xffffffff;
  local_1c = &DAT_00fe1740;
  DAT_00fe1740 = local_11;
  _DAT_00fe1748 = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    DAT_00fe1744 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fe1744 + 4) = DAT_00fe1744;
    DAT_00fe1750 = 0;
    _DAT_00fe1754 = 0;
    _DAT_00fe1758 = 0;
    local_8 = 2;
    _DAT_00fe1768 = 0x3f800000;
    FUN_007dcc30(8);
    *unaff_FS_OFFSET = local_10;
    return &DAT_00fe173c;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_18);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

