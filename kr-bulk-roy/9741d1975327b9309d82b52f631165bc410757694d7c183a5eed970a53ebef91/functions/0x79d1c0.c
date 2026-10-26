
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079d1c0(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ebac;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 8;
  DAT_00fc0f50 = 1;
  WaitForSingleObject(DAT_00fc0f54,0xffffffff);
  CloseHandle(DAT_00fc0f5c);
  CloseHandle(DAT_00fc0f54);
  if (DAT_00fc0f40 != 0) {
    FUN_007a37a0(DAT_00fc0f44,&DAT_00fc0e90,uVar3);
    FUN_0089120c(DAT_00fc0f40);
  }
  DAT_00fc0f40 = 0;
  DAT_00fc0f44 = 0;
  _DAT_00fc0f48 = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fc0f28);
  local_8._0_1_ = 6;
  if (DAT_00fc0f18 != 0) {
    FUN_007a37a0(DAT_00fc0f1c,&DAT_00fc0e90);
    FUN_0089120c(DAT_00fc0f18);
  }
  DAT_00fc0f18 = 0;
  DAT_00fc0f1c = 0;
  _DAT_00fc0f20 = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fc0f00);
  piVar2 = DAT_00fc0efc;
  local_8._0_1_ = 4;
  if (DAT_00fc0efc != (int *)0x0) {
    LOCK();
    iVar1 = DAT_00fc0efc[1] + -1;
    DAT_00fc0efc[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      (**(code **)*piVar2)();
      LOCK();
      iVar1 = piVar2[2] + -1;
      piVar2[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)(*piVar2 + 4))();
      }
    }
  }
  local_8._0_1_ = 3;
  _eh_vector_destructor_iterator_(&DAT_00fc0ed8,8,4,FUN_0047bb80);
  local_8._0_1_ = 2;
  if (DAT_00fc0ec8 != 0) {
    FUN_007a37a0(DAT_00fc0ecc,&DAT_00fc0e90);
    FUN_0089120c(DAT_00fc0ec8);
  }
  local_8._0_1_ = 1;
  DAT_00fc0ec8 = 0;
  DAT_00fc0ecc = 0;
  _DAT_00fc0ed0 = 0;
  if (DAT_00fc0eb8 != 0) {
    FUN_007a37a0(DAT_00fc0ebc,&DAT_00fc0e90);
    FUN_0089120c(DAT_00fc0eb8);
  }
  DAT_00fc0eb8 = 0;
  DAT_00fc0ebc = 0;
  _DAT_00fc0ec0 = 0;
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_007a1790(*DAT_00fc0ea4,DAT_00fc0ea4);
  FUN_0089120c(DAT_00fc0ea4);
  local_8 = 10;
  FUN_007a16f0(*DAT_00fc0e94,DAT_00fc0e94);
  FUN_0089120c(DAT_00fc0e94);
  ExceptionList = local_10;
  return;
}

