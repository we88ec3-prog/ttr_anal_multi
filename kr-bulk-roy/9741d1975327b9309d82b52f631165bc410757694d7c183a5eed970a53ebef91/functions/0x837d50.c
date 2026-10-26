
void FUN_00837d50(ULONG_PTR param_1)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  BOOL BVar1;
  undefined4 in_ECX;
  undefined4 *unaff_ESI;
  ULONG_PTR local_8;
  
  *unaff_ESI = in_EAX;
  unaff_ESI[1] = in_ECX;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = param_1;
  hProcess = GetCurrentProcess();
  param_1 = 0;
  local_8 = 0;
  BVar1 = GetProcessAffinityMask(hProcess,&param_1,&local_8);
  if ((BVar1 != 0) && (param_1 != 0)) {
    DAT_00d639f8 = ~param_1 + 1 & param_1;
  }
  CloseHandle(hProcess);
  return;
}

