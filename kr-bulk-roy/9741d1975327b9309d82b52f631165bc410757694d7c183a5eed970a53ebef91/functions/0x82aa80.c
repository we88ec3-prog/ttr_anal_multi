
undefined * FUN_0082aa80(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fc16f4 = 0;
  iVar1 = FUN_00891268(0x20);
  if (iVar1 != 0) {
    DAT_00fc16f0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc16f0 + 4) = DAT_00fc16f0;
    *(int *)(DAT_00fc16f0 + 8) = DAT_00fc16f0;
    *(undefined1 *)(DAT_00fc16f0 + 0x1c) = 1;
    *(undefined1 *)(DAT_00fc16f0 + 0x1d) = 1;
    return &DAT_00fc16ec;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

