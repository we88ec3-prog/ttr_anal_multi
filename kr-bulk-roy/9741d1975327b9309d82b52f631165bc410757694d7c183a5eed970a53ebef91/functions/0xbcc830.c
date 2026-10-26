
void FUN_00bcc830(void)

{
  HANDLE hProcess;
  BOOL BVar1;
  ULONG_PTR local_c;
  ULONG_PTR local_8;
  
  hProcess = GetCurrentProcess();
  local_8 = 0;
  local_c = 0;
  BVar1 = GetProcessAffinityMask(hProcess,&local_8,&local_c);
  if ((BVar1 != 0) && (local_8 != 0)) {
    DAT_00d639f8 = ~local_8 + 1 & local_8;
  }
  CloseHandle(hProcess);
  _atexit((_func_4879 *)&LAB_00bd0cc0);
  return;
}

