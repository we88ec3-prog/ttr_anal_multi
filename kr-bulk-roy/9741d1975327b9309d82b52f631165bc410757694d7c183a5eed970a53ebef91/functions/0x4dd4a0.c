
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004dd4a0(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  _DAT_00fab0e4 = 0;
  iVar1 = FUN_00891268(0x28);
  if (iVar1 != 0) {
    DAT_00fab0e0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fab0e0 + 4) = DAT_00fab0e0;
    *(int *)(DAT_00fab0e0 + 8) = DAT_00fab0e0;
    *(undefined1 *)(DAT_00fab0e0 + 0x20) = 1;
    *(undefined1 *)(DAT_00fab0e0 + 0x21) = 1;
    return &DAT_00fab0dc;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

