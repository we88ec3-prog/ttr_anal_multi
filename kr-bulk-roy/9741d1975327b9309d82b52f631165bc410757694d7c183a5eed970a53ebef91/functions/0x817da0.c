
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00817da0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c1c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fab27c;
  DAT_00fab284 = 0;
  iVar1 = FUN_00891268(0x24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fab280 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fab280 + 4) = DAT_00fab280;
    *(int *)(DAT_00fab280 + 8) = DAT_00fab280;
    *(undefined1 *)(DAT_00fab280 + 0x20) = 1;
    *(undefined1 *)(DAT_00fab280 + 0x21) = 1;
    DAT_00fab28c = 0;
    _DAT_00fab290 = 0;
    _DAT_00fab294 = 0;
    local_8 = 1;
    _DAT_00fba914 = FUN_0040f7f0();
    ExceptionList = local_10;
    return &DAT_00fab27c;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

