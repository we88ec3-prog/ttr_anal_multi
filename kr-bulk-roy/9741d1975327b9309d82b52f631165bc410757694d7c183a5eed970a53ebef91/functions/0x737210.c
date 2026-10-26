
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00737210(void)

{
  int iVar1;
  undefined **local_14 [3];
  char *local_8;
  
  _DAT_00fc1a38 = 0;
  _DAT_00fc1a4c = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    DAT_00fc1a48 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc1a48 + 4) = DAT_00fc1a48;
    *(int *)(DAT_00fc1a48 + 8) = DAT_00fc1a48;
    *(undefined1 *)(DAT_00fc1a48 + 0x14) = 1;
    *(undefined1 *)(DAT_00fc1a48 + 0x15) = 1;
    _DAT_00fc1a68 = 0;
    _DAT_00fc1a58 = 0;
    _DAT_00fc1a5c = 0;
    _DAT_00fc1a60 = 0;
    _DAT_00fc1a64 = 0;
    DAT_00fc1a54 = 0xffffffff;
    return &DAT_00fc1a38;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

