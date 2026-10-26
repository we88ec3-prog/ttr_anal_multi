
undefined4 * FUN_006f0720(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined **local_30 [3];
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915de7;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = CLogBackend_Type2::vftable;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 1),4000);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 7),4000);
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 0xd),4000);
  local_8._0_1_ = 3;
  param_1[0x14] = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_30,&local_18);
    local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_30,&DAT_00c857a8);
  }
  param_1[0x13] = iVar2;
  *(int *)iVar2 = iVar2;
  *(undefined4 *)(param_1[0x13] + 4) = param_1[0x13];
  local_8._0_1_ = 4;
  param_1[0x17] = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 != 0) {
    param_1[0x16] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x16] + 4) = param_1[0x16];
    param_1[0x19] = 0;
    *(undefined1 *)(param_1 + 0x1a) = 0;
    param_1[0x1b] = 0xffffffff;
    param_1[0x22] = 0xf;
    param_1[0x21] = 0;
    *(undefined1 *)(param_1 + 0x1d) = 0;
    local_8._0_1_ = 6;
    _memset(param_1 + 0x24,0,0x104);
    param_1[0x65] = 0;
    param_1[0x66] = 0;
    param_1[0x67] = 0;
    param_1[0x68] = 0;
    param_1[0x69] = 0;
    *(undefined1 *)(param_1 + 0x6a) = 0;
    FUN_006f04f0(param_1 + 0x6b);
    local_8 = CONCAT31(local_8._1_3_,7);
    *(undefined1 *)(param_1 + 0x74) = 0;
    FUN_00402a70("ClientPacketLog",0xf);
    param_1[0x67] = 100;
    param_1[0x69] = 2000;
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

