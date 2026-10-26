
undefined * FUN_00536730(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe36f8 = 0;
  iVar1 = FUN_00891268(0x34);
  if (iVar1 != 0) {
    DAT_00fe36f4 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe36f4 + 4) = DAT_00fe36f4;
    *(int *)(DAT_00fe36f4 + 8) = DAT_00fe36f4;
    *(undefined1 *)(DAT_00fe36f4 + 0x30) = 1;
    *(undefined1 *)(DAT_00fe36f4 + 0x31) = 1;
    return &DAT_00fe36f0;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

