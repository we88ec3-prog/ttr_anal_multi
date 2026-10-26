
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048be50(int param_1)

{
  code *pcVar1;
  uint uVar2;
  LPCWSTR pWVar3;
  int iVar4;
  int *piVar5;
  LPCWSTR lpText;
  undefined4 uVar6;
  UINT uType;
  undefined1 auStack_174 [4];
  int local_170;
  int local_16c;
  _SYSTEMTIME local_168;
  _OSVERSIONINFOW local_158;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094a0ca;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_174;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffe80;
  ExceptionList = &local_14;
  GetLocalTime(&local_168);
  FUN_006edd00("*Client Launch Time: %d-%d-%d %d:%d:%d\n",local_168.wYear,local_168.wMonth,
               local_168.wDay,local_168.wHour,local_168.wMinute,local_168.wSecond,uVar2);
  FUN_00495460();
  local_158.dwOSVersionInfoSize = 0x114;
  GetVersionExW(&local_158);
  if (local_158.dwMajorVersion < 5) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_170 = 399;
    FUN_005740f0(&local_170);
    if (local_16c == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pWVar3 = (LPCWSTR)(local_16c + 0x10);
    if (7 < *(uint *)(local_16c + 0x24)) {
      pWVar3 = *(LPCWSTR *)pWVar3;
    }
    MessageBoxW((HWND)0x0,pWVar3,*(LPCWSTR *)(param_1 + 0x28),0);
    FUN_006ded00("The system doesn\'t meet the requirement.");
  }
  else {
    iVar4 = FUN_00489990(param_1 + 0xbf70,param_1 + 0xbf74);
    if (iVar4 == 0) {
      local_16c = 0x180;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_16c);
      if (local_170 == *(int *)(iVar4 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      pWVar3 = (LPCWSTR)(local_170 + 0x10);
      if (7 < *(uint *)(local_170 + 0x24)) {
        pWVar3 = *(LPCWSTR *)pWVar3;
      }
      MessageBoxW((HWND)0x0,pWVar3,*(LPCWSTR *)(param_1 + 0x28),0);
      FUN_006ded00("Couldn\'t get the client version info");
    }
    else {
      FUN_006edd00("*Client info: Rev. %d / Built on %s, %s",*(undefined4 *)(param_1 + 0xbf78),
                   "20:32:57","Sep 21 2017");
      FUN_00493170();
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      if ((DAT_00fe726c & 1) == 0) {
        DAT_00fe726c = DAT_00fe726c | 1;
        local_c = 1;
        FUN_004a0950();
        _atexit((_func_4879 *)&DAT_00bce6c0);
        local_c = 0xffffffff;
        if ((DAT_00fe726c & 1) == 0) {
          DAT_00fe726c = DAT_00fe726c | 1;
          local_c = 2;
          FUN_004a0950();
          _atexit((_func_4879 *)&DAT_00bce6c0);
          local_c = 0xffffffff;
        }
      }
      DAT_00d63d78 = 0;
      if ((_DAT_00fe37d8 & 1) == 0) {
        _DAT_00fe37d8 = _DAT_00fe37d8 | 1;
        FUN_008053f0();
        _atexit((_func_4879 *)&LAB_00bd0ba0);
      }
      FUN_00804650();
      FUN_00498eb0("%d.%d.%d",1,1,0x34);
      piVar5 = (int *)FUN_0044d680();
      if (((int *)*piVar5 == (int *)0x0) ||
         (iVar4 = (**(code **)(*(int *)*piVar5 + 0x20))(), iVar4 == 0)) {
        pWVar3 = *(LPCWSTR *)(param_1 + 0x28);
        uType = 0;
        uVar6 = 0x17b;
        FUN_005854b0(0x17b);
        lpText = (LPCWSTR)FUN_00585330(uVar6);
        MessageBoxW((HWND)0x0,lpText,pWVar3,uType);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_174);
  return;
}

