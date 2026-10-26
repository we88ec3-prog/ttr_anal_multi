
undefined * FUN_0050de90(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe17c8 = 0;
  iVar1 = FUN_00891268(0x4c);
  if (iVar1 != 0) {
    DAT_00fe17c4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe17c4 + 4) = DAT_00fe17c4;
    *(int *)(DAT_00fe17c4 + 8) = DAT_00fe17c4;
    *(undefined1 *)(DAT_00fe17c4 + 0x48) = 1;
    *(undefined1 *)(DAT_00fe17c4 + 0x49) = 1;
    return &DAT_00fe17c0;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

