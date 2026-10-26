
BOOL FUN_008381b0(LARGE_INTEGER *param_1)

{
  HANDLE pvVar1;
  BOOL BVar2;
  DWORD_PTR dwThreadAffinityMask;
  
  dwThreadAffinityMask = 0;
  pvVar1 = GetCurrentThread();
  if (pvVar1 != (HANDLE)0xffffffff) {
    dwThreadAffinityMask = SetThreadAffinityMask(pvVar1,DAT_00d639f8);
    CloseHandle(pvVar1);
  }
  BVar2 = QueryPerformanceCounter(param_1);
  pvVar1 = GetCurrentThread();
  if (pvVar1 != (HANDLE)0xffffffff) {
    SetThreadAffinityMask(pvVar1,dwThreadAffinityMask);
    CloseHandle(pvVar1);
  }
  return BVar2;
}

