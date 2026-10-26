
undefined * FUN_007c02f0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe1b68 = 0;
  iVar1 = FUN_00891268(0x28);
  if (iVar1 != 0) {
    DAT_00fe1b64 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1b64 + 4) = DAT_00fe1b64;
    *(int *)(DAT_00fe1b64 + 8) = DAT_00fe1b64;
    *(undefined1 *)(DAT_00fe1b64 + 0x20) = 1;
    *(undefined1 *)(DAT_00fe1b64 + 0x21) = 1;
    return &DAT_00fe1b60;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

