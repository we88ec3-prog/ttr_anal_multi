
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0080f520(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  _DAT_00fe3418 = 0;
  _DAT_00fe3424 = 0;
  iVar1 = FUN_00891268(0x2c);
  if (iVar1 != 0) {
    DAT_00fe3420 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3420 + 4) = DAT_00fe3420;
    *(int *)(DAT_00fe3420 + 8) = DAT_00fe3420;
    *(undefined1 *)(DAT_00fe3420 + 0x28) = 1;
    *(undefined1 *)(DAT_00fe3420 + 0x29) = 1;
    DAT_00fe342c = 0;
    return &DAT_00fe3418;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

