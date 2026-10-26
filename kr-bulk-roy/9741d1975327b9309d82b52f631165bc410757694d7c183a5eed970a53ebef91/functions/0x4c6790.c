
undefined * FUN_004c6790(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fd926c = 0;
  iVar1 = FUN_00891268(0x2c);
  if (iVar1 != 0) {
    DAT_00fd9268 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fd9268 + 4) = DAT_00fd9268;
    *(int *)(DAT_00fd9268 + 8) = DAT_00fd9268;
    *(undefined1 *)(DAT_00fd9268 + 0x28) = 1;
    *(undefined1 *)(DAT_00fd9268 + 0x29) = 1;
    return &DAT_00fd9264;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

