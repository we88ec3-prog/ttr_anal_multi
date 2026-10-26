
undefined * FUN_0051a650(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe3708 = 0;
  iVar1 = FUN_00891268(0x58);
  if (iVar1 != 0) {
    DAT_00fe3704 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3704 + 4) = DAT_00fe3704;
    *(int *)(DAT_00fe3704 + 8) = DAT_00fe3704;
    *(undefined1 *)(DAT_00fe3704 + 0x54) = 1;
    *(undefined1 *)(DAT_00fe3704 + 0x55) = 1;
    return &DAT_00fe3700;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

