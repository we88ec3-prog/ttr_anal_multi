
undefined * FUN_00485780(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fc0de4 = 0;
  iVar1 = FUN_00891268(0x24);
  if (iVar1 != 0) {
    DAT_00fc0de0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc0de0 + 4) = DAT_00fc0de0;
    *(int *)(DAT_00fc0de0 + 8) = DAT_00fc0de0;
    *(undefined1 *)(DAT_00fc0de0 + 0x20) = 1;
    *(undefined1 *)(DAT_00fc0de0 + 0x21) = 1;
    return &DAT_00fc0ddc;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

