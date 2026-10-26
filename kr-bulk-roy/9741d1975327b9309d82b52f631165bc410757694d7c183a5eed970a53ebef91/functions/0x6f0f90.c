
void FUN_006f0f90(void)

{
  uint uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  FILE *pFVar2;
  undefined4 *unaff_ESI;
  undefined4 *puVar3;
  _SYSTEMTIME local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915d63;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  puVar3 = unaff_ESI + 1;
  *unaff_ESI = CLogBackend_Type1::vftable;
  unaff_ESI[6] = 0xf;
  unaff_ESI[5] = 0;
  *(undefined1 *)puVar3 = 0;
  local_14 = uVar1;
  FUN_00402a70("ClientPacketLog",0xf);
  local_8 = CONCAT31(local_8._1_3_,1);
  unaff_ESI[0x49] = 0;
  *(undefined2 *)(unaff_ESI + 0x4a) = 0;
  unaff_ESI[0x4b] = 0;
  unaff_ESI[0x4c] = 2000;
  unaff_ESI[0x4d] = 100;
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar1);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSectionAndSpinCount(lpCriticalSection,4000);
  }
  unaff_ESI[0x4e] = lpCriticalSection;
  GetLocalTime(&local_24);
  if (0xf < (uint)unaff_ESI[6]) {
    puVar3 = (undefined4 *)*puVar3;
  }
  _sprintf_s((char *)(unaff_ESI + 8),0x104,"%s_%04d_%02d_%02d_%02d_%02d_%02d.txt",puVar3,
             (uint)local_24.wYear,(uint)local_24.wMonth,(uint)local_24.wDay,(uint)local_24.wHour,
             (uint)local_24.wMinute,(uint)local_24.wSecond);
  pFVar2 = _fopen((char *)(unaff_ESI + 8),"a");
  unaff_ESI[0x49] = pFVar2;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

