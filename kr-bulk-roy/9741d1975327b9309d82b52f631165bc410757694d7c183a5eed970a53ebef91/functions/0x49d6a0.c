
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0049d6a0(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090db9b;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_18 = &DAT_00fab104;
  _DAT_00fab104 = 0;
  DAT_00fab108 = 0;
  DAT_00fab10c = 0;
  _DAT_00fab110 = 0;
  local_8 = 0;
  _DAT_00fab120 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    DAT_00fab11c = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fab11c + 4) = DAT_00fab11c;
    *(int *)(DAT_00fab11c + 8) = DAT_00fab11c;
    *(undefined1 *)(DAT_00fab11c + 0x14) = 1;
    *(undefined1 *)(DAT_00fab11c + 0x15) = 1;
    DAT_00fab128 = 1;
    *unaff_FS_OFFSET = local_10;
    return &DAT_00fab104;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

