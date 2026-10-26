
undefined * FUN_004fad80(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe1908 = 0;
  iVar1 = FUN_00891268(0xd0);
  if (iVar1 != 0) {
    DAT_00fe1904 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1904 + 4) = DAT_00fe1904;
    *(int *)(DAT_00fe1904 + 8) = DAT_00fe1904;
    *(undefined1 *)(DAT_00fe1904 + 0xcc) = 1;
    *(undefined1 *)(DAT_00fe1904 + 0xcd) = 1;
    return &DAT_00fe1900;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

