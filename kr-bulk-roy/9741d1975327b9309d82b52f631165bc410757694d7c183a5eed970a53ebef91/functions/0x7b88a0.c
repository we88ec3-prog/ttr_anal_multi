
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007b88a0(void)

{
  int iVar1;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909fae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe32fc & 1) == 0) {
    DAT_00fe32fc = DAT_00fe32fc | 1;
    local_8 = 0;
    _DAT_00fe3300 = 0;
    _DAT_00fe330c = 0;
    iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_20,&local_14);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    DAT_00fe3308 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3308 + 4) = DAT_00fe3308;
    *(int *)(DAT_00fe3308 + 8) = DAT_00fe3308;
    *(undefined1 *)(DAT_00fe3308 + 0x14) = 1;
    *(undefined1 *)(DAT_00fe3308 + 0x15) = 1;
    _atexit(FUN_00bd0a50);
  }
  ExceptionList = local_10;
  return &DAT_00fe3300;
}

