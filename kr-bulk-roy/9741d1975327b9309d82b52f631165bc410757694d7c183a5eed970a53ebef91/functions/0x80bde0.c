
undefined4 FUN_0080bde0(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  undefined4 uVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915f38;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 0x1d);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if ((int *)*in_ECX == (int *)0x0) {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_10;
    return 0;
  }
  uVar2 = (**(code **)(*(int *)*in_ECX + 0x18))(uVar1);
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_10;
  return uVar2;
}

