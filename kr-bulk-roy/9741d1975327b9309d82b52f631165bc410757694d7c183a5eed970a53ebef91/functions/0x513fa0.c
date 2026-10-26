
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00513fa0(void)

{
  int iVar1;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00923dde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe3010;
  DAT_00fe3018 = 0;
  DAT_00fe3014 = FUN_00820120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00fe3014 = DAT_00fe3014;
  *(int *)(DAT_00fe3014 + 4) = DAT_00fe3014;
  *(int *)(DAT_00fe3014 + 8) = DAT_00fe3014;
  *(undefined1 *)(DAT_00fe3014 + 0x18) = 1;
  *(undefined1 *)(DAT_00fe3014 + 0x19) = 1;
  DAT_00fe3020 = 0;
  DAT_00fe3024 = 0;
  DAT_00fe3028 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  _DAT_00fe3038 = 0;
  iVar1 = FUN_00891268(0x24);
  if (iVar1 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe3034 = iVar1;
  *(int *)iVar1 = iVar1;
  *(int *)(DAT_00fe3034 + 4) = DAT_00fe3034;
  *(int *)(DAT_00fe3034 + 8) = DAT_00fe3034;
  *(undefined1 *)(DAT_00fe3034 + 0x20) = 1;
  *(undefined1 *)(DAT_00fe3034 + 0x21) = 1;
  local_8._0_1_ = 2;
  _DAT_00fe3048 = 0;
  iVar1 = FUN_00891268(0x24);
  if (iVar1 != 0) {
    DAT_00fe3044 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3044 + 4) = DAT_00fe3044;
    *(int *)(DAT_00fe3044 + 8) = DAT_00fe3044;
    *(undefined1 *)(DAT_00fe3044 + 0x20) = 1;
    *(undefined1 *)(DAT_00fe3044 + 0x21) = 1;
    local_8._0_1_ = 3;
    _DAT_00fe3064 = 0;
    iVar1 = FUN_00891268(0x24);
    if (iVar1 == 0) {
      local_18 = (char *)0x0;
      std::exception::exception((exception *)local_34,&local_18);
      local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_34,&DAT_00c857a8);
    }
    DAT_00fe3060 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3060 + 4) = DAT_00fe3060;
    *(int *)(DAT_00fe3060 + 8) = DAT_00fe3060;
    *(undefined1 *)(DAT_00fe3060 + 0x20) = 1;
    *(undefined1 *)(DAT_00fe3060 + 0x21) = 1;
    local_8._0_1_ = 4;
    _DAT_00fe3074 = 0;
    iVar1 = FUN_00891268(0x14);
    if (iVar1 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_28,&local_14);
      local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_28,&DAT_00c857a8);
    }
    DAT_00fe3070 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fe3070 + 4) = DAT_00fe3070;
    *(int *)(DAT_00fe3070 + 8) = DAT_00fe3070;
    *(undefined1 *)(DAT_00fe3070 + 0x12) = 1;
    *(undefined1 *)(DAT_00fe3070 + 0x13) = 1;
    local_8._0_1_ = 5;
    _DAT_00fe3084 = 0;
    DAT_00fe3080 = FUN_00820120();
    *(int *)DAT_00fe3080 = DAT_00fe3080;
    *(int *)(DAT_00fe3080 + 4) = DAT_00fe3080;
    *(int *)(DAT_00fe3080 + 8) = DAT_00fe3080;
    *(undefined1 *)(DAT_00fe3080 + 0x18) = 1;
    *(undefined1 *)(DAT_00fe3080 + 0x19) = 1;
    local_8._0_1_ = 6;
    _DAT_00fe3094 = 0;
    iVar1 = FUN_00891268(0x24);
    if (iVar1 != 0) {
      DAT_00fe3090 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fe3090 + 4) = DAT_00fe3090;
      *(int *)(DAT_00fe3090 + 8) = DAT_00fe3090;
      *(undefined1 *)(DAT_00fe3090 + 0x20) = 1;
      *(undefined1 *)(DAT_00fe3090 + 0x21) = 1;
      local_8 = CONCAT31(local_8._1_3_,7);
      _DAT_00fe3050 = 0x1599;
      _DAT_00fe3054 = 0x1577;
      _DAT_00fe3058 = 1;
      FUN_00514600();
      FUN_00514740();
      FUN_005148f0();
      ExceptionList = local_10;
      return &DAT_00fe3010;
    }
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

