
/* Library Function - Single Match
    __dospawn
   
   Library: Visual Studio 2010 Release */

intptr_t __cdecl __dospawn(int _Mode,char *_Name,char *_Cmd,char *_Env)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  ulong *puVar6;
  BOOL BVar7;
  DWORD DVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  HANDLE pvVar12;
  uint uVar13;
  _STARTUPINFOA local_6c;
  _PROCESS_INFORMATION local_28;
  HANDLE local_18;
  char *local_14;
  DWORD local_10;
  uint local_c;
  char local_5;
  
  pvVar12 = (HANDLE)0x0;
  local_10 = 0;
  local_5 = '\0';
  if ((_Mode != 0) && (_Mode != 1)) {
    if (_Mode < 2) {
LAB_008b40f1:
      puVar6 = ___doserrno();
      *puVar6 = 0;
      piVar9 = __errno();
      *piVar9 = 0x16;
      FUN_00893343();
      return -1;
    }
    if (3 < _Mode) {
      if (_Mode != 4) goto LAB_008b40f1;
      local_5 = '\x01';
    }
  }
  local_14 = _Cmd;
  while (*_Cmd != '\0') {
    do {
      pcVar2 = _Cmd;
      _Cmd = pcVar2 + 1;
    } while (*_Cmd != '\0');
    if (pcVar2[2] != '\0') {
      *_Cmd = ' ';
      _Cmd = pcVar2 + 2;
    }
  }
  _memset(&local_6c,0,0x44);
  local_6c.cb = 0x44;
  uVar13 = DAT_00fe7294;
  uVar3 = DAT_00fe7294;
  if (DAT_00fe7294 != 0) {
    do {
      uVar3 = uVar3 - 1;
      if (*(char *)((&DAT_00fe72a0)[(int)uVar3 >> 5] + 4 + (uVar3 & 0x1f) * 0x40) != '\0') break;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
    if ((int)uVar13 < 0) goto LAB_008b42ac;
  }
  if (0x3331 < uVar13) {
LAB_008b42ac:
    piVar9 = __errno();
    *piVar9 = 0xc;
    return -1;
  }
  local_6c.cbReserved2 = (short)uVar13 * 5 + 4;
  local_6c.lpReserved2 = __calloc_crt((uint)local_6c.cbReserved2,1);
  if ((uint *)local_6c.lpReserved2 == (uint *)0x0) goto LAB_008b42ac;
  *(uint *)local_6c.lpReserved2 = uVar13;
  puVar10 = (uint *)((int)local_6c.lpReserved2 + 4);
  puVar5 = (undefined4 *)((int)local_6c.lpReserved2 + uVar13 + 4);
  local_c = 0;
  if (0 < (int)uVar13) {
    do {
      puVar4 = (undefined4 *)((local_c & 0x1f) * 0x40 + (&DAT_00fe72a0)[(int)local_c >> 5]);
      bVar1 = *(byte *)(puVar4 + 1);
      if ((bVar1 & 0x10) == 0) {
        *(byte *)puVar10 = bVar1;
        *puVar5 = *puVar4;
      }
      else {
        *(byte *)puVar10 = 0;
        *puVar5 = 0xffffffff;
      }
      local_c = local_c + 1;
      puVar10 = (uint *)((int)puVar10 + 1);
      puVar5 = puVar5 + 1;
    } while ((int)local_c < (int)uVar13);
  }
  if (local_5 != '\0') {
    puVar10 = (uint *)((int)local_6c.lpReserved2 + 4);
    iVar11 = 0;
    puVar5 = (undefined4 *)((int)local_6c.lpReserved2 + uVar13 + 4);
    while( true ) {
      uVar3 = uVar13;
      if (2 < (int)uVar13) {
        uVar3 = 3;
      }
      if ((int)uVar3 <= iVar11) break;
      *(undefined1 *)puVar10 = 0;
      *puVar5 = 0xffffffff;
      iVar11 = iVar11 + 1;
      puVar10 = (uint *)((int)puVar10 + 1);
      puVar5 = puVar5 + 1;
    }
    local_10 = 8;
  }
  puVar6 = ___doserrno();
  *puVar6 = 0;
  BVar7 = CreateProcessA(_Name,local_14,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,1,
                         local_10,_Env,(LPCSTR)0x0,&local_6c,&local_28);
  DVar8 = GetLastError();
  _free(local_6c.lpReserved2);
  if (BVar7 == 0) {
    __dosmaperr(DVar8);
    return -1;
  }
  if (_Mode == 2) {
    __exit(0);
  }
  if (_Mode == 0) {
    WaitForSingleObject(local_28.hProcess,0xffffffff);
    GetExitCodeProcess(local_28.hProcess,(LPDWORD)&local_18);
    pvVar12 = local_18;
  }
  else if (_Mode != 4) goto LAB_008b42a3;
  CloseHandle(local_28.hProcess);
  local_28.hProcess = pvVar12;
LAB_008b42a3:
  CloseHandle(local_28.hThread);
  return (intptr_t)local_28.hProcess;
}

