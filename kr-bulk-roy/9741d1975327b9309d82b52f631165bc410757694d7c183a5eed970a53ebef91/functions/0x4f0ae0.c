
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004f0ae0(void)

{
  undefined4 *puVar1;
  undefined **local_14 [3];
  char *local_8;
  
  DAT_00fe18a4 = (undefined4 *)0x0;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fe18a4 = puVar1;
    *puVar1 = 0;
    puVar1[1] = 0;
    *DAT_00fe18a4 = &DAT_00fe18a4;
    _DAT_00fe18a8 = 0;
    _DAT_00fe18ac = 0;
    _DAT_00fe18b0 = 0;
    _DAT_00fe18b4 = 0;
    return &DAT_00fe18a4;
  }
  local_8 = (char *)0x0;
  std::exception::exception((exception *)local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00c857a8);
}

