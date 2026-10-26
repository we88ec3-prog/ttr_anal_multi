
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00823e10(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_44 [3];
  undefined **local_38 [3];
  undefined **local_2c [3];
  undefined *local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c0ac;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = &DAT_00fc0c80;
  _DAT_00fc0c80 = CCubeSystem::vftable;
  _DAT_00fc0c8c = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_44,&local_1c);
    local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_44,&DAT_00c857a8);
  }
  DAT_00fc0c88 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc0c88 + 4) = DAT_00fc0c88;
  *(int *)(DAT_00fc0c88 + 8) = DAT_00fc0c88;
  *(undefined1 *)(DAT_00fc0c88 + 0x14) = 1;
  *(undefined1 *)(DAT_00fc0c88 + 0x15) = 1;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  _DAT_00fc0c9c = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    DAT_00fc0c98 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc0c98 + 4) = DAT_00fc0c98;
    *(int *)(DAT_00fc0c98 + 8) = DAT_00fc0c98;
    *(undefined1 *)(DAT_00fc0c98 + 0x14) = 1;
    *(undefined1 *)(DAT_00fc0c98 + 0x15) = 1;
    DAT_00fc0ca4 = 0;
    DAT_00fc0ca8 = 0;
    DAT_00fc0cac = 0;
    local_8._0_1_ = 2;
    _DAT_00fc0cbc = 0;
    iVar2 = FUN_00891268(0x28,uVar1);
    if (iVar2 == 0) {
      local_18 = (char *)0x0;
      std::exception::exception((exception *)local_38,&local_18);
      local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_38,&DAT_00c857a8);
    }
    DAT_00fc0cb8 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc0cb8 + 4) = DAT_00fc0cb8;
    *(int *)(DAT_00fc0cb8 + 8) = DAT_00fc0cb8;
    *(undefined1 *)(DAT_00fc0cb8 + 0x24) = 1;
    *(undefined1 *)(DAT_00fc0cb8 + 0x25) = 1;
    local_8._0_1_ = 3;
    _DAT_00fc0ccc = 0;
    iVar2 = FUN_00891268(0x28,uVar1);
    if (iVar2 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    DAT_00fc0cc8 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc0cc8 + 4) = DAT_00fc0cc8;
    *(int *)(DAT_00fc0cc8 + 8) = DAT_00fc0cc8;
    *(undefined1 *)(DAT_00fc0cc8 + 0x24) = 1;
    *(undefined1 *)(DAT_00fc0cc8 + 0x25) = 1;
    local_8._0_1_ = 4;
    _DAT_00fc0cdc = 0;
    iVar2 = FUN_00891268(0x28,uVar1);
    if (iVar2 != 0) {
      DAT_00fc0cd8 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00fc0cd8 + 4) = DAT_00fc0cd8;
      *(int *)(DAT_00fc0cd8 + 8) = DAT_00fc0cd8;
      *(undefined1 *)(DAT_00fc0cd8 + 0x24) = 1;
      *(undefined1 *)(DAT_00fc0cd8 + 0x25) = 1;
      local_8 = CONCAT31(local_8._1_3_,5);
      _DAT_00fc0cec = 0;
      iVar2 = FUN_00891268(0x28);
      if (iVar2 != 0) {
        DAT_00fc0ce8 = iVar2;
        *(int *)iVar2 = iVar2;
        *(int *)(DAT_00fc0ce8 + 4) = DAT_00fc0ce8;
        *(int *)(DAT_00fc0ce8 + 8) = DAT_00fc0ce8;
        *(undefined1 *)(DAT_00fc0ce8 + 0x24) = 1;
        *(undefined1 *)(DAT_00fc0ce8 + 0x25) = 1;
        DAT_00fc0cf4 = 1;
        ExceptionList = local_10;
        return &DAT_00fc0c80;
      }
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_38,&local_18);
  local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_38,&DAT_00c857a8);
}

