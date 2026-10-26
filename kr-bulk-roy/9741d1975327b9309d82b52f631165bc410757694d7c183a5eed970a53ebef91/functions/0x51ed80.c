
undefined * FUN_0051ed80(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe1dd8 = 0;
  iVar1 = FUN_00891268(0x54);
  if (iVar1 != 0) {
    DAT_00fe1dd4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1dd4 + 4) = DAT_00fe1dd4;
    *(int *)(DAT_00fe1dd4 + 8) = DAT_00fe1dd4;
    *(undefined1 *)(DAT_00fe1dd4 + 0x50) = 1;
    *(undefined1 *)(DAT_00fe1dd4 + 0x51) = 1;
    return &DAT_00fe1dd0;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

