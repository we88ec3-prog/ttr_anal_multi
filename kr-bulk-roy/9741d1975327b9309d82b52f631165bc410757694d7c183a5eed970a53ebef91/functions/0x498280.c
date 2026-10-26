
undefined * FUN_00498280(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fd8f04 = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    DAT_00fd8f00 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fd8f00 + 4) = DAT_00fd8f00;
    *(int *)(DAT_00fd8f00 + 8) = DAT_00fd8f00;
    *(undefined1 *)(DAT_00fd8f00 + 0x14) = 1;
    *(undefined1 *)(DAT_00fd8f00 + 0x15) = 1;
    return &DAT_00fd8efc;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

