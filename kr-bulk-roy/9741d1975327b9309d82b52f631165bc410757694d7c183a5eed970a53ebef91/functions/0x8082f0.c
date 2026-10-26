
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_008082f0(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090988d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fc19f8;
  _DAT_00fc19f8 = ObsessionsAI::CManager::vftable;
  _DAT_00fc1a04 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fc1a00 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc1a00 + 4) = DAT_00fc1a00;
  *(int *)(DAT_00fc1a00 + 8) = DAT_00fc1a00;
  *(undefined1 *)(DAT_00fc1a00 + 0x14) = 1;
  *(undefined1 *)(DAT_00fc1a00 + 0x15) = 1;
  local_8 = 0;
  _DAT_00fc1a0c = 0;
  _DAT_00fc1a10 = 0;
  _DAT_00fc1a1c = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    DAT_00fc1a18 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc1a18 + 4) = DAT_00fc1a18;
    *(int *)(DAT_00fc1a18 + 8) = DAT_00fc1a18;
    *(undefined1 *)(DAT_00fc1a18 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fc1a18 + 0x2d) = 1;
    ExceptionList = local_10;
    return &DAT_00fc19f8;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

