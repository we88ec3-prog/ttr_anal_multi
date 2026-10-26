
undefined * FUN_0043f500(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fd9294 = 0;
  iVar1 = FUN_00891268(0x24);
  if (iVar1 != 0) {
    DAT_00fd9290 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fd9290 + 4) = DAT_00fd9290;
    *(int *)(DAT_00fd9290 + 8) = DAT_00fd9290;
    *(undefined1 *)(DAT_00fd9290 + 0x20) = 1;
    *(undefined1 *)(DAT_00fd9290 + 0x21) = 1;
    return &DAT_00fd928c;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

