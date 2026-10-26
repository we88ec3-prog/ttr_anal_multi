
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007b5430(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911a24;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_00fd9420;
  FUN_007b6c50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  _DAT_00fd9438 = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    DAT_00fd9434 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fd9434 + 4) = DAT_00fd9434;
    *(int *)(DAT_00fd9434 + 8) = DAT_00fd9434;
    *(undefined1 *)(DAT_00fd9434 + 0x14) = 1;
    *(undefined1 *)(DAT_00fd9434 + 0x15) = 1;
    local_8._0_1_ = 1;
    _DAT_00fd9448 = 0;
    iVar1 = FUN_00891268(0x18);
    if (iVar1 != 0) {
      DAT_00fd9444 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00fd9444 + 4) = DAT_00fd9444;
      *(int *)(DAT_00fd9444 + 8) = DAT_00fd9444;
      *(undefined1 *)(DAT_00fd9444 + 0x14) = 1;
      *(undefined1 *)(DAT_00fd9444 + 0x15) = 1;
      local_14 = &DAT_00fd9450;
      InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fd9450,4000);
      local_8._0_1_ = 3;
      DAT_00fd9468 = (undefined4 *)0x0;
      puVar2 = (undefined4 *)FUN_00891268(8);
      if (puVar2 == (undefined4 *)0x0) {
        local_18 = (char *)0x0;
        std::exception::exception((exception *)local_34,&local_18);
        local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_34,&DAT_00c857a8);
      }
      DAT_00fd9468 = puVar2;
      *puVar2 = 0;
      puVar2[1] = 0;
      *DAT_00fd9468 = &DAT_00fd9468;
      _DAT_00fd946c = 0;
      _DAT_00fd9470 = 0;
      _DAT_00fd9474 = 0;
      _DAT_00fd9478 = 0;
      local_18 = &DAT_00fd9480;
      InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fd9480,4000);
      local_8._0_1_ = 5;
      DAT_00fd9498 = (undefined4 *)0x0;
      puVar2 = (undefined4 *)FUN_00891268(8);
      if (puVar2 == (undefined4 *)0x0) goto LAB_007b56a0;
      DAT_00fd9498 = puVar2;
      puVar2[1] = 0;
      *puVar2 = 0;
      *DAT_00fd9498 = &DAT_00fd9498;
      _DAT_00fd949c = 0;
      _DAT_00fd94a0 = 0;
      _DAT_00fd94a4 = 0;
      _DAT_00fd94a8 = 0;
      local_8._0_1_ = 6;
      _DAT_00fd94b0 = 0;
      _DAT_00fd94b4 = 1;
      DAT_00fd94b8 = 0;
      _DAT_00fd94c4 = 0;
      iVar1 = FUN_00891268(0x30);
      if (iVar1 != 0) {
        DAT_00fd94c0 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00fd94c0 + 4) = DAT_00fd94c0;
        *(int *)(DAT_00fd94c0 + 8) = DAT_00fd94c0;
        *(undefined1 *)(DAT_00fd94c0 + 0x2c) = 1;
        *(undefined1 *)(DAT_00fd94c0 + 0x2d) = 1;
        local_8 = CONCAT31(local_8._1_3_,7);
        _DAT_00fd94d0 = 0;
        iVar1 = FUN_00891268(0x24);
        if (iVar1 != 0) {
          DAT_00fd94cc = iVar1;
          *(int *)iVar1 = iVar1;
          *(int *)(DAT_00fd94cc + 4) = DAT_00fd94cc;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fba6d0);
          ExceptionList = local_10;
          return &DAT_00fd9420;
        }
        local_14 = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_14);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
    }
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
LAB_007b56a0:
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

