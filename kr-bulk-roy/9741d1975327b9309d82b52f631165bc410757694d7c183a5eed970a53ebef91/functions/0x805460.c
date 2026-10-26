
undefined4 * FUN_00805460(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090525e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 0;
  puVar1 = param_1 + 4;
  *puVar1 = 0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_24,&local_14);
    local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_24,&DAT_00c857a8);
  }
  *puVar1 = puVar3;
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined4 **)*puVar1 = puVar1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  local_8._0_1_ = 1;
  param_1[0xb] = 0;
  iVar4 = FUN_00891268(0xc,uVar2);
  if (iVar4 != 0) {
    param_1[10] = iVar4;
    *(int *)iVar4 = iVar4;
    *(undefined4 *)(param_1[10] + 4) = param_1[10];
    local_8 = CONCAT31(local_8._1_3_,2);
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar2);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    else {
      InitializeCriticalSectionAndSpinCount(lpCriticalSection,4000);
    }
    param_1[0xd] = lpCriticalSection;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x13] = 0;
    iVar4 = FUN_00891268(0xc,uVar2);
    if (iVar4 != 0) {
      param_1[0x12] = iVar4;
      *(int *)iVar4 = iVar4;
      *(undefined4 *)(param_1[0x12] + 4) = param_1[0x12];
      ExceptionList = local_10;
      return param_1;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_24,&local_14);
    local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_24,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_30,&local_18);
  local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_30,&DAT_00c857a8);
}

