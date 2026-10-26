
void FUN_0081ecf0(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined **local_14 [3];
  char *local_8;
  
  *unaff_ESI = CLocalizedWordFilterBase::vftable;
  unaff_ESI[3] = 0;
  iVar1 = FUN_00891268(0x10);
  if (iVar1 != 0) {
    unaff_ESI[2] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(unaff_ESI[2] + 4) = unaff_ESI[2];
    *(undefined4 *)(unaff_ESI[2] + 8) = unaff_ESI[2];
    *(undefined1 *)(unaff_ESI[2] + 0xe) = 1;
    *(undefined1 *)(unaff_ESI[2] + 0xf) = 1;
    *unaff_ESI = CLocalizedWordFilter_USA::vftable;
    return;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

