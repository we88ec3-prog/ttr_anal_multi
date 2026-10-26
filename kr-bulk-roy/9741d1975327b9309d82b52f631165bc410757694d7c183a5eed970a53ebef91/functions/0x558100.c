
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00558100(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905d65;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_00fc1ac8 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  DAT_00fc1ac4 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc1ac4 + 4) = DAT_00fc1ac4;
  local_8 = 0;
  DAT_00fc1ad0 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar3 != (undefined4 *)0x0) {
    DAT_00fc1ad0 = puVar3;
    *puVar3 = 0;
    puVar3[1] = 0;
    *DAT_00fc1ad0 = &DAT_00fc1ad0;
    _DAT_00fc1ad4 = 0;
    _DAT_00fc1ad8 = 0;
    _DAT_00fc1adc = 0;
    _DAT_00fc1ae0 = 0;
    ExceptionList = local_10;
    return &DAT_00fc1ac4;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

