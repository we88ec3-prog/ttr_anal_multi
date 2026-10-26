
undefined * FUN_0051d800(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00f8d920 = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    DAT_00f8d91c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00f8d91c + 4) = DAT_00f8d91c;
    *(int *)(DAT_00f8d91c + 8) = DAT_00f8d91c;
    *(undefined1 *)(DAT_00f8d91c + 0x14) = 1;
    *(undefined1 *)(DAT_00f8d91c + 0x15) = 1;
    return &DAT_00f8d918;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

