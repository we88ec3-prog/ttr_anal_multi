
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007cffe0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  _DAT_00fe3258 = 0;
  iVar1 = FUN_00891268(0x34);
  if (iVar1 != 0) {
    DAT_00fe3254 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3254 + 4) = DAT_00fe3254;
    *(int *)(DAT_00fe3254 + 8) = DAT_00fe3254;
    *(undefined1 *)(DAT_00fe3254 + 0x30) = 1;
    *(undefined1 *)(DAT_00fe3254 + 0x31) = 1;
    return &DAT_00fe3250;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

