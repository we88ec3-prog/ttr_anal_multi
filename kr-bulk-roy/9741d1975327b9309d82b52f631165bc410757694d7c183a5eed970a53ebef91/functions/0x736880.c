
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00736880(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fcde28 = 0;
  DAT_00fcde2c = 0;
  _DAT_00fcde38 = 0;
  iVar1 = FUN_00891268(0x30);
  if (iVar1 != 0) {
    DAT_00fcde34 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fcde34 + 4) = DAT_00fcde34;
    *(int *)(DAT_00fcde34 + 8) = DAT_00fcde34;
    *(undefined1 *)(DAT_00fcde34 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fcde34 + 0x2d) = 1;
    return &DAT_00fcde28;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

