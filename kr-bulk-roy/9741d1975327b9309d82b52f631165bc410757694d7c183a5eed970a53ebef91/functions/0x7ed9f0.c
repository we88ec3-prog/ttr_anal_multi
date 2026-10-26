
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_007ed9f0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909c2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe3318;
  DAT_00fe3318 = 0;
  DAT_00fe331c = 0;
  DAT_00fe3320 = 0;
  _DAT_00fe3324 = 0;
  local_8 = 0;
  _DAT_00fe3334 = 0;
  iVar1 = FUN_00891268(0x30,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fe3330 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3330 + 4) = DAT_00fe3330;
    *(int *)(DAT_00fe3330 + 8) = DAT_00fe3330;
    *(undefined1 *)(DAT_00fe3330 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe3330 + 0x2d) = 1;
    ExceptionList = local_10;
    return &DAT_00fe3318;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

