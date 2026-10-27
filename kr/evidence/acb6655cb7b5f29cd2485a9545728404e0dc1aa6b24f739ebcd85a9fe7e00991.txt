
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00540770(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_FS_OFFSET;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090af83;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_1c = &DAT_00fc0e48;
  DAT_00fc0e5c = 0xf;
  _DAT_00fc0e58 = 0;
  DAT_00fc0e48._0_1_ = 0;
  local_8 = 0;
  DAT_00fc0e64 = (undefined4 *)0x0;
  puVar2 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fc0e64 = puVar2;
  *puVar2 = 0;
  puVar2[1] = 0;
  *DAT_00fc0e64 = &DAT_00fc0e64;
  _DAT_00fc0e68 = 0;
  _DAT_00fc0e6c = 0;
  _DAT_00fc0e70 = 0;
  _DAT_00fc0e74 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  _DAT_00fc0e84 = 0;
  iVar3 = FUN_00891268(0x14,uVar1);
  if (iVar3 != 0) {
    DAT_00fc0e80 = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(DAT_00fc0e80 + 4) = DAT_00fc0e80;
    *(int *)(DAT_00fc0e80 + 8) = DAT_00fc0e80;
    *(undefined1 *)(DAT_00fc0e80 + 0x10) = 1;
    *(undefined1 *)(DAT_00fc0e80 + 0x11) = 1;
    *unaff_FS_OFFSET = local_10;
    return &DAT_00fc0e48;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

