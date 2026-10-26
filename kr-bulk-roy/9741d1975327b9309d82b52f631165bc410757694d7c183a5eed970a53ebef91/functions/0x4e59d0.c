
void FUN_004e59d0(int param_1)

{
  short *psVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  HRESULT HVar5;
  char *pcVar6;
  DWORD DVar7;
  int iVar8;
  int iVar9;
  wchar_t ****_Src;
  short *in_ECX;
  bool bVar10;
  undefined1 auStack_4ec [3];
  undefined1 local_4e9;
  int local_4e8;
  wchar_t ***local_4e0 [5];
  uint local_4cc;
  undefined1 local_4c4 [28];
  undefined1 local_4a8 [120];
  WCHAR local_430;
  undefined1 local_42e [518];
  WCHAR local_228;
  undefined1 local_226 [522];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924a77;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4ec;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffb08;
  ExceptionList = &local_14;
  local_4e8 = param_1;
  local_4e9 = 1;
  *(undefined4 *)(param_1 + 0x5f74) = 0;
  if (in_ECX == (short *)0x0) {
LAB_004e5b8b:
    FUN_006edd00("Invalid Login Notice URL",uVar4);
  }
  else {
    psVar1 = in_ECX + 1;
    do {
      sVar2 = *in_ECX;
      in_ECX = in_ECX + 1;
    } while (sVar2 != 0);
    if ((int)in_ECX - (int)psVar1 >> 1 == 0) goto LAB_004e5b8b;
    local_228 = L'\0';
    _memset(local_226,0,0x206);
    local_430 = L'\0';
    _memset(local_42e,0,0x206);
    FUN_00498ed0(L"%s/Notice.xml");
    FUN_00498ed0(L"./Notice.xml.tmp");
    DeleteFileW(&local_430);
    DeleteUrlCacheEntryW(&local_228);
    HVar5 = URLDownloadToFileW((LPUNKNOWN)0x0,&local_228,&local_430,0,(LPBINDSTATUSCALLBACK)0x0);
    bVar10 = -1 < HVar5;
    pcVar6 = "Success";
    if (!bVar10) {
      pcVar6 = "Failed";
    }
    local_4e9 = bVar10;
    FUN_006edd00("Login Notice Download %s",pcVar6);
    if (!bVar10) goto LAB_004e5d97;
  }
  DVar7 = GetFileAttributesA("./Notice.xml.tmp");
  if (DVar7 != 0xffffffff) {
    FUN_0072ee30(local_4a8);
    local_c = 0;
    cVar3 = FUN_0072f110(0);
    if (cVar3 == '\0') {
      pcVar6 = "Invalid Login Notice XML Format";
    }
    else {
      DeleteFileW(L"./Notice.xml.tmp");
      iVar8 = FUN_0072e360();
      if (iVar8 != 0) {
        iVar8 = FUN_0072e360();
        iVar9 = FUN_0072e360();
        if ((iVar8 != 0) && (iVar8 = FUN_0072ecc0(), iVar8 != 0)) {
          FUN_004ada90(local_4c4);
          local_c._0_1_ = 1;
          FUN_00402a50();
          local_c = CONCAT31(local_c._1_3_,2);
          iVar8 = FUN_00466df0(local_4e0,&DAT_00c059b8,2);
          while (iVar8 != -1) {
            FUN_00498090(iVar8,2,&DAT_00c059c0,2);
            iVar8 = FUN_00466df0(local_4e0,&DAT_00c059b8,2);
          }
          _Src = (wchar_t ****)local_4e0[0];
          if (local_4cc < 8) {
            _Src = local_4e0;
          }
          _wcsncpy_s((wchar_t *)(local_4e8 + 0x5f78),0x32,(wchar_t *)_Src,0x32);
          FUN_004fa440();
          local_c = local_c & 0xffffff00;
          FUN_007cf450();
        }
        if ((iVar9 != 0) && (iVar8 = FUN_0072ecc0(), iVar8 != 0)) {
          FUN_004ada90(local_4c4);
          local_c._0_1_ = 3;
          FUN_00402a50();
          local_c = CONCAT31(local_c._1_3_,4);
          iVar8 = FUN_00466df0(local_4e0,&DAT_00c059b8,2);
          while (iVar8 != -1) {
            FUN_00498090(iVar8,2,&DAT_00c059c0,2);
            iVar8 = FUN_00466df0(local_4e0,&DAT_00c059b8,2);
          }
          if (local_4cc < 8) {
            local_4e0[0] = (wchar_t ***)local_4e0;
          }
          _wcsncpy_s((wchar_t *)(local_4e8 + 0x5fdc),0x400,(wchar_t *)local_4e0[0],0x400);
          FUN_004fa440();
          FUN_007cf450();
        }
        uVar4 = FUN_0072e6d0(1);
        *(uint *)(local_4e8 + 0x5f74) = uVar4 & 0xff;
        local_c = 0xffffffff;
        FUN_00407fb0();
        goto LAB_004e5d97;
      }
      pcVar6 = "Invalid Login Notice XML Format : RootNode not exist";
    }
    FUN_006edd00(pcVar6);
    local_c = 0xffffffff;
    FUN_00407fb0();
  }
LAB_004e5d97:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4ec);
  return;
}

