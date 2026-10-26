
void FUN_00495460(void)

{
  HANDLE hFindFile;
  int iVar1;
  int iVar2;
  undefined1 auStack_194 [4];
  _WIN32_FIND_DATAA local_190;
  char local_4c;
  undefined4 local_4b;
  undefined4 local_47;
  undefined4 local_43;
  undefined4 local_3f;
  undefined4 local_3b;
  undefined4 local_37;
  undefined4 local_33;
  undefined2 local_2f;
  undefined1 local_2d;
  char local_2c;
  undefined4 local_2b;
  undefined4 local_27;
  undefined4 local_23;
  undefined4 local_1f;
  undefined4 local_1b;
  undefined4 local_17;
  undefined4 local_13;
  undefined2 local_f;
  undefined1 local_d;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_194;
  local_2b = 0;
  local_27 = 0;
  local_23 = 0;
  local_1f = 0;
  local_1b = 0;
  local_17 = 0;
  local_13 = 0;
  local_f = 0;
  local_d = 0;
  local_4c = '\0';
  local_4b = 0;
  local_47 = 0;
  local_43 = 0;
  local_3f = 0;
  local_3b = 0;
  local_37 = 0;
  local_33 = 0;
  local_2f = 0;
  local_2d = 0;
  local_2c = '\0';
  _strcpy_s(&local_2c,0x20,"Tartaros.exe");
  _strcpy_s(&local_4c,0x20,"_Tartaros.exe");
  hFindFile = FindFirstFileA(&local_4c,&local_190);
  if (hFindFile != (HANDLE)0xffffffff) {
    FindClose(hFindFile);
    iVar2 = 10;
    iVar1 = DeleteFileA(&local_2c);
    while (iVar1 == 0) {
      iVar2 = iVar2 + -1;
      if (iVar2 < 0) {
        __security_check_cookie(local_c ^ (uint)auStack_194);
        return;
      }
      Sleep(1000);
      iVar1 = DeleteFileA(&local_2c);
    }
    iVar2 = CopyFileA(&local_4c,&local_2c,0);
    while (iVar2 == 0) {
      Sleep(1000);
      iVar2 = CopyFileA(&local_4c,&local_2c,0);
    }
    DeleteFileA(&local_4c);
  }
  __security_check_cookie(local_c ^ (uint)auStack_194);
  return;
}

