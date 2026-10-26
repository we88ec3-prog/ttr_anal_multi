
undefined * FUN_00828c00(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fd9400 = 0;
  iVar1 = FUN_00891268(0x98);
  if (iVar1 != 0) {
    DAT_00fd93fc = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fd93fc + 4) = DAT_00fd93fc;
    *(int *)(DAT_00fd93fc + 8) = DAT_00fd93fc;
    *(undefined1 *)(DAT_00fd93fc + 0x94) = 1;
    *(undefined1 *)(DAT_00fd93fc + 0x95) = 1;
    return &DAT_00fd93f8;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

