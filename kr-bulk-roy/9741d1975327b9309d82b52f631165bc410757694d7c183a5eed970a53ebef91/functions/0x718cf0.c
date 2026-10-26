
void FUN_00718cf0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  int *unaff_FS_OFFSET;
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  undefined1 local_11;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a7c6;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_1c = unaff_ESI + 1;
  *unaff_ESI = Package::CFileScanner::vftable;
  *(undefined1 *)local_1c = local_11;
  unaff_ESI[3] = 0;
  iVar2 = FUN_00891268(0x28,uVar1);
  if (iVar2 != 0) {
    unaff_ESI[2] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(unaff_ESI[2] + 4) = unaff_ESI[2];
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    local_8 = 1;
    unaff_ESI[0xb] = 0x3f800000;
    FUN_007dcc30(8);
    *unaff_FS_OFFSET = local_10;
    return;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_18);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

