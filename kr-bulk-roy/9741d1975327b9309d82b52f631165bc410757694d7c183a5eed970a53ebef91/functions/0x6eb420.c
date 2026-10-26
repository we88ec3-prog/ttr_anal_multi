
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_006eb420(void)

{
  HANDLE hProcess;
  BOOL BVar1;
  undefined4 local_14;
  undefined4 local_10;
  ULONG_PTR local_c;
  ULONG_PTR local_8;
  
  DAT_00fe4b19 = 1;
  _DAT_00fe4b20 = 0;
  _DAT_00fe4b24 = 0;
  DAT_00fe4b28 = 0;
  DAT_00fe4b2c = 0;
  _DAT_00fe4b30 = 0;
  _DAT_00fe4b34 = 0;
  _DAT_00fe4b38 = 0;
  _DAT_00fe4b3c = 0;
  hProcess = GetCurrentProcess();
  local_8 = 0;
  local_c = 0;
  BVar1 = GetProcessAffinityMask(hProcess,&local_8,&local_c);
  if ((BVar1 != 0) && (local_8 != 0)) {
    DAT_00d63d80 = ~local_8 + 1 & local_8;
  }
  CloseHandle(hProcess);
  FUN_006eb360(&local_14);
  _DAT_00fe4b20 = local_14;
  _DAT_00fe4b24 = local_10;
  return &DAT_00fe4b18;
}

