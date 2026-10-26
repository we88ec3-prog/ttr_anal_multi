
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007c30c0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  _DAT_00fe1e14 = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    DAT_00fe1e10 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe1e10 + 4) = DAT_00fe1e10;
    *(int *)(DAT_00fe1e10 + 8) = DAT_00fe1e10;
    *(undefined1 *)(DAT_00fe1e10 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe1e10 + 0x2d) = 1;
    return &DAT_00fe1e0c;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

