
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007fca90(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009263dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00fe3340 = 0x43000000;
  local_18 = &DAT_00fe3340;
  _DAT_00fe334c = 0;
  iVar1 = FUN_00891268(0x30,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fe3348 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3348 + 4) = DAT_00fe3348;
    *(int *)(DAT_00fe3348 + 8) = DAT_00fe3348;
    *(undefined1 *)(DAT_00fe3348 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe3348 + 0x2d) = 1;
    local_8 = 0;
    FUN_007fcbe0();
    ExceptionList = local_10;
    return &DAT_00fe3340;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

