
void FUN_007e20b0(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[4] = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    unaff_ESI[3] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(unaff_ESI[3] + 4) = unaff_ESI[3];
    *(undefined4 *)(unaff_ESI[3] + 8) = unaff_ESI[3];
    *(undefined1 *)(unaff_ESI[3] + 0x2c) = 1;
    *(undefined1 *)(unaff_ESI[3] + 0x2d) = 1;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

