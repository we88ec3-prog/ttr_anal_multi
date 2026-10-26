
undefined4 FUN_0080ee50(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar1 = FUN_00714550();
  if (iVar1 != 0) {
    iVar1 = FUN_00714770();
    if (iVar1 != 0) {
      uVar2 = FUN_00891268(0x2d0);
      *(undefined4 *)(unaff_ESI + 8) = uVar2;
      iVar3 = ov_open_callbacks(iVar1,uVar2,0,0,FUN_0080edc0,FUN_0080edf0,FUN_0080ee10,FUN_0080ee30)
      ;
      iVar1 = *(int *)(unaff_ESI + 8);
      if (-1 < iVar3) {
        uVar2 = ov_info(iVar1,0xffffffff);
        *(undefined4 *)(unaff_ESI + 0xc) = uVar2;
        uVar2 = ov_comment(*(undefined4 *)(unaff_ESI + 8),0xffffffff);
        *(undefined4 *)(unaff_ESI + 0x10) = uVar2;
        *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(*(int *)(unaff_ESI + 0xc) + 8);
        *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(*(int *)(unaff_ESI + 0xc) + 4);
        return 1;
      }
      if (iVar1 != 0) {
        FUN_0089120c(iVar1);
        *(undefined4 *)(unaff_ESI + 8) = 0;
      }
    }
  }
  return 0;
}

