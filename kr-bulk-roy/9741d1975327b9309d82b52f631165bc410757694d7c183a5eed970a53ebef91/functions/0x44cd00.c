
void FUN_0044cd00(void)

{
  DWORD DVar1;
  BOOL BVar2;
  char *pcVar3;
  _union_530 local_32c;
  undefined4 local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  _FILETIME local_308;
  DWORD local_300;
  _OSVERSIONINFOA local_2fc;
  _MEMORYSTATUS local_264;
  CHAR local_244 [264];
  CHAR local_13c [200];
  undefined1 local_74 [108];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  GetSystemTimeAsFileTime(&local_308);
  FUN_0044ca40(local_308.dwLowDateTime,local_308.dwHighDateTime);
  FUN_0044c9e0("Error occurred at %s.\r\n",local_74);
  DVar1 = GetModuleFileNameA((HMODULE)0x0,local_244,0x104);
  if (DVar1 == 0) {
    lstrcpyA(local_244,"Unknown");
  }
  local_300 = 200;
  BVar2 = GetUserNameA(local_13c,&local_300);
  if (BVar2 == 0) {
    lstrcpyA(local_13c,"Unknown");
  }
  FUN_0044c9e0("%s, run by %s.\r\n",local_244,local_13c);
  _memset(&local_2fc.dwMajorVersion,0,0x90);
  local_2fc.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_2fc);
  if (local_2fc.dwPlatformId == 1) {
    FUN_0044c9e0("Windows 95/98 version %d.%d (build %d) %s.\r\n",local_2fc.dwBuildNumber >> 0x18,
                 local_2fc.dwBuildNumber >> 0x10 & 0xff,local_2fc.dwBuildNumber & 0xffff,
                 local_2fc.szCSDVersion);
  }
  else if (local_2fc.dwPlatformId == 2) {
    FUN_0044c9e0("Windows NT version %d.%d (build %d) %s.\r\n",local_2fc.dwMajorVersion,
                 local_2fc.dwMinorVersion,local_2fc.dwBuildNumber,local_2fc.szCSDVersion);
  }
  else {
    FUN_0044c9e0("Unrecognized Windows platform %d.\r\n",local_2fc.dwPlatformId);
  }
  local_32c.dwOemId = 0;
  local_328 = 0;
  local_324 = 0;
  local_320 = 0;
  local_31c = 0;
  local_318 = 0;
  local_314 = 0;
  local_310 = 0;
  local_30c = 0;
  GetSystemInfo((LPSYSTEM_INFO)&local_32c.s);
  FUN_0044c9e0("%d processor(s), type %d.\r\n",local_318,local_314);
  local_264.dwMemoryLoad = 0;
  local_264.dwTotalPhys = 0;
  local_264.dwAvailPhys = 0;
  local_264.dwTotalPageFile = 0;
  local_264.dwAvailPageFile = 0;
  local_264.dwTotalVirtual = 0;
  local_264.dwAvailVirtual = 0;
  local_264.dwLength = 0x20;
  GlobalMemoryStatus(&local_264);
  FUN_0044c9e0("%d MBytes physical memory.\r\n",local_264.dwTotalPhys + 0xfffff >> 0x14);
  FUN_0044c9e0("User ID: ");
  pcVar3 = &DAT_00fba700;
  if (DAT_00fba700 == '\0') {
    pcVar3 = "<unknown>";
  }
  FUN_0044c9e0(&DAT_00bfc340,pcVar3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

