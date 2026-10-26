
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00807120(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  LPCRITICAL_SECTION p_Var4;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907499;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = &DAT_00fe3358;
  _DAT_00fe335c = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fe3358 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fe3358 + 4) = DAT_00fe3358;
  local_8 = 0;
  DAT_00fe3364 = (undefined4 *)0x0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar3 != (undefined4 *)0x0) {
    DAT_00fe3364 = puVar3;
    *puVar3 = 0;
    puVar3[1] = 0;
    *DAT_00fe3364 = &DAT_00fe3364;
    DAT_00fe3368 = 0;
    DAT_00fe336c = 0;
    DAT_00fe3370 = 0;
    DAT_00fe3374 = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fe337c = 0;
    p_Var4 = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar1);
    if (p_Var4 == (LPCRITICAL_SECTION)0x0) {
      p_Var4 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      InitializeCriticalSectionAndSpinCount(p_Var4,4000);
    }
    _DAT_00fe3384 = 0;
    _DAT_00fe338c = 0;
    DAT_00fe3380 = p_Var4;
    iVar2 = FUN_00891268(0xc,uVar1);
    if (iVar2 != 0) {
      DAT_00fe3388 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00fe3388 + 4) = DAT_00fe3388;
      local_8._0_1_ = 2;
      DAT_00fe3394 = (undefined4 *)0x0;
      puVar3 = (undefined4 *)FUN_00891268(8);
      if (puVar3 != (undefined4 *)0x0) {
        DAT_00fe3394 = puVar3;
        *puVar3 = 0;
        puVar3[1] = 0;
        *DAT_00fe3394 = &DAT_00fe3394;
        DAT_00fe3398 = 0;
        DAT_00fe339c = 0;
        DAT_00fe33a0 = 0;
        DAT_00fe33a4 = 0;
        local_8 = CONCAT31(local_8._1_3_,3);
        _DAT_00fe33ac = 0;
        lpCriticalSection = (LPCRITICAL_SECTION)FUN_00891268(0x18);
        p_Var4 = (LPCRITICAL_SECTION)0x0;
        if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
          InitializeCriticalSectionAndSpinCount(lpCriticalSection,4000);
          p_Var4 = lpCriticalSection;
        }
        DAT_00fe33b0 = p_Var4;
        ExceptionList = local_10;
        return &DAT_00fe3358;
      }
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_28,&local_14);
      local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_28,&DAT_00c857a8);
    }
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_14);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

