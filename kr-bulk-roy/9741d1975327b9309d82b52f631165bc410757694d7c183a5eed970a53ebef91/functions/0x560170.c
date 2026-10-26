
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00560170(void)

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
  puStack_c = &LAB_0093adc8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = &DAT_00fb73c0;
  _DAT_00fb73c0 = 0;
  _DAT_00fb73c4 = 0;
  _DAT_00fb73d0 = 0;
  iVar2 = FUN_00891268(0x34,uVar1);
  if (iVar2 == 0) {
    local_1c = (char *)0x0;
    std::exception::exception((exception *)local_44,&local_1c);
    local_44[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_44,&DAT_00c857a8);
  }
  DAT_00fb73cc = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fb73cc + 4) = DAT_00fb73cc;
  *(int *)(DAT_00fb73cc + 8) = DAT_00fb73cc;
  *(undefined1 *)(DAT_00fb73cc + 0x30) = 1;
  *(undefined1 *)(DAT_00fb73cc + 0x31) = 1;
  local_8 = 0;
  _DAT_00fb73e0 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    DAT_00fb73dc = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fb73dc + 4) = DAT_00fb73dc;
    *(int *)(DAT_00fb73dc + 8) = DAT_00fb73dc;
    *(undefined1 *)(DAT_00fb73dc + 0x14) = 1;
    *(undefined1 *)(DAT_00fb73dc + 0x15) = 1;
    local_8._0_1_ = 1;
    DAT_00fb73e8 = 0;
    _DAT_00fb73ec = 0;
    local_1c = (char *)FUN_00891268(0x48,uVar1);
    local_8._0_1_ = 2;
    if (local_1c == (char *)0x0) {
      DAT_00fb73f0 = 0;
    }
    else {
      DAT_00fb73f0 = FUN_007cd2b0();
    }
    _DAT_00fb73f8 = 0;
    _DAT_00fb73fc = 0;
    _DAT_00fb7400 = 0xffffffff;
    DAT_00fb7418 = 0xf;
    _DAT_00fb7414 = 0;
    DAT_00fb7404._0_1_ = 0;
    local_8._0_1_ = 3;
    _DAT_00fb7428 = 0;
    iVar2 = FUN_00891268(0x14,uVar1);
    if (iVar2 != 0) {
      DAT_00fb7424 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00fb7424 + 4) = DAT_00fb7424;
      *(int *)(DAT_00fb7424 + 8) = DAT_00fb7424;
      *(undefined1 *)(DAT_00fb7424 + 0x10) = 1;
      *(undefined1 *)(DAT_00fb7424 + 0x11) = 1;
      local_8._0_1_ = 4;
      _DAT_00fb7430 = 0;
      _DAT_00fb743c = 0;
      iVar2 = FUN_00891268(0x14);
      if (iVar2 != 0) {
        DAT_00fb7438 = iVar2;
        *(int *)iVar2 = iVar2;
        *(int *)(DAT_00fb7438 + 4) = DAT_00fb7438;
        *(int *)(DAT_00fb7438 + 8) = DAT_00fb7438;
        *(undefined1 *)(DAT_00fb7438 + 0x10) = 1;
        *(undefined1 *)(DAT_00fb7438 + 0x11) = 1;
        local_8._0_1_ = 5;
        _DAT_00fb7444 = 0x3f800000;
        _DAT_00fb7448 = 1;
        FUN_005607d0();
        FUN_00562440();
        if ((DAT_00fe2740 & 1) == 0) {
          DAT_00fe2740 = DAT_00fe2740 | 1;
          local_8 = CONCAT31(local_8._1_3_,6);
          FUN_0055e680();
          _atexit((_func_4879 *)&DAT_00bcf2a0);
        }
        ExceptionList = local_10;
        return &DAT_00fb73c0;
      }
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_38,&local_18);
    local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_38,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_38,&local_18);
  local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_38,&DAT_00c857a8);
}

