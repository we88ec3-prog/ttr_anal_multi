
undefined * FUN_0052a3b0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fc0dd0 = 0;
  iVar1 = FUN_00891268(0x60);
  if (iVar1 != 0) {
    DAT_00fc0dcc = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc0dcc + 4) = DAT_00fc0dcc;
    *(int *)(DAT_00fc0dcc + 8) = DAT_00fc0dcc;
    *(undefined1 *)(DAT_00fc0dcc + 0x5c) = 1;
    *(undefined1 *)(DAT_00fc0dcc + 0x5d) = 1;
    return &DAT_00fc0dc8;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

