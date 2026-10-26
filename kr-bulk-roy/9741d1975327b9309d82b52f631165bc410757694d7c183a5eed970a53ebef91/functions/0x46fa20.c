
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0046fa20(void)

{
  undefined4 *puVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fc0d98 = (undefined4 *)0x0;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fc0d98 = puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    *DAT_00fc0d98 = &DAT_00fc0d98;
    _DAT_00fc0d9c = 0;
    _DAT_00fc0da0 = 0;
    _DAT_00fc0da4 = 0;
    _DAT_00fc0da8 = 0;
    return &DAT_00fc0d98;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

