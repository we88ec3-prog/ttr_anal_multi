
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0080e030(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905188;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = &DAT_00fe33c8;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fe33c8,4000);
  local_8 = 0;
  DAT_00fe33e0 = (undefined4 *)0x0;
  puVar2 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_00fe33e0 = puVar2;
    *puVar2 = 0;
    puVar2[1] = 0;
    *DAT_00fe33e0 = &DAT_00fe33e0;
    _DAT_00fe33e4 = 0;
    _DAT_00fe33e8 = 0;
    _DAT_00fe33ec = 0;
    _DAT_00fe33f0 = 0;
    ExceptionList = local_10;
    return &DAT_00fe33c8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

