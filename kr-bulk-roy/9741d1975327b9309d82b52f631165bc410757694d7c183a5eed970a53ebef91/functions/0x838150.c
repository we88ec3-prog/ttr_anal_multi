
BOOL FUN_00838150(void)

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
  BVar2 = QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00fe3478);
  pvVar1 = GetCurrentThread();
  if (pvVar1 != (HANDLE)0xffffffff) {
    SetThreadAffinityMask(pvVar1,dwThreadAffinityMask);
    CloseHandle(pvVar1);
  }
  return BVar2;
}

