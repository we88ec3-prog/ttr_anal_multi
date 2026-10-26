
undefined * FUN_0047ffb0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe1b3c = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    DAT_00fe1b38 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1b38 + 4) = DAT_00fe1b38;
    *(int *)(DAT_00fe1b38 + 8) = DAT_00fe1b38;
    *(undefined1 *)(DAT_00fe1b38 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe1b38 + 0x2d) = 1;
    return &DAT_00fe1b34;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

