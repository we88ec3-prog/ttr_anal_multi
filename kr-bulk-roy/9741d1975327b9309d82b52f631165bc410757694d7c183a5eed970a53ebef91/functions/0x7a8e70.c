
/* WARNING: Removing unreachable block (ram,0x007a901a) */
/* WARNING: Removing unreachable block (ram,0x007a9025) */
/* WARNING: Removing unreachable block (ram,0x007a90a9) */
/* WARNING: Removing unreachable block (ram,0x007a90b5) */
/* WARNING: Removing unreachable block (ram,0x007a90c9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a8e70(int param_1)

{
  uint uVar1;
  int iVar2;
  int *local_24;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009390fb;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar2 = FUN_00891268();
  local_c = 0;
  if (iVar2 != 0) {
    FUN_007a5020();
    local_c._0_1_ = 1;
    FUN_007a5020();
    local_c = CONCAT31(local_c._1_3_,2);
    FUN_007a5020();
    *(undefined4 *)(iVar2 + 0x68) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
  }
  local_c = 0xffffffff;
  FUN_007aa810();
  local_c = 3;
  _DAT_00000000 = *(undefined4 *)(param_1 + 0x18);
  if (param_1 != -0x24) {
    FUN_004ca160();
    FUN_007a1540();
    FUN_006d7120();
    FUN_007a1660();
  }
  FUN_007a9d90();
  local_c._0_1_ = 4;
  FUN_004e0f60();
  local_c = CONCAT31(local_c._1_3_,3);
  if (local_24 != (int *)0x0) {
    LOCK();
    iVar2 = local_24[1] + -1;
    local_24[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*local_24)();
      LOCK();
      iVar2 = local_24[2] + -1;
      local_24[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*local_24 + 4))();
      }
    }
  }
  FUN_007a5730();
  uRam00000004 = *(int *)(param_1 + 0x24) == 0;
  if (*(char *)(param_1 + 0x20) == '\0') {
    pvRam00000070 = (HANDLE)0xffffffff;
  }
  else {
    pvRam00000070 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x24) = 2;
  uVar1 = local_c >> 8;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_c._0_1_ = 6;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    uVar1 = (uint)local_c._1_3_;
  }
  local_c._1_3_ = (uint3)uVar1;
  local_c = CONCAT31(local_c._1_3_,3);
  FUN_0079da70();
  if (*(char *)(param_1 + 0x20) != '\0') {
    WaitForSingleObject(pvRam00000070,0xffffffff);
    CloseHandle(pvRam00000070);
    FID_conflict__wprintf("Load Immediate Complete\n");
  }
  ExceptionList = local_14;
  return;
}

