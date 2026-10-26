
void FUN_00830e10(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[5] = 0;
  iVar1 = FUN_00891268(0x14);
  if (iVar1 != 0) {
    unaff_ESI[4] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(unaff_ESI[4] + 4) = unaff_ESI[4];
    *(undefined4 *)(unaff_ESI[4] + 8) = unaff_ESI[4];
    *(undefined1 *)(unaff_ESI[4] + 0x10) = 1;
    *(undefined1 *)(unaff_ESI[4] + 0x11) = 1;
    unaff_ESI[9] = 0;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 0;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

