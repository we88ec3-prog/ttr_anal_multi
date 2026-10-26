
void FUN_004e7db0(void)

{
  WCHAR WVar1;
  int *piVar2;
  HRESULT HVar3;
  WCHAR *pWVar4;
  undefined2 *unaff_ESI;
  int unaff_EDI;
  WCHAR local_418;
  undefined1 local_416 [518];
  WCHAR local_210;
  undefined1 local_20e [518];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_418 = L'\0';
  _memset(local_416,0,0x206);
  local_210 = L'\0';
  _memset(local_20e,0,0x206);
  piVar2 = (int *)(unaff_EDI + 0x20);
  if (7 < *(uint *)(unaff_EDI + 0x34)) {
    piVar2 = (int *)*piVar2;
  }
  FUN_00498ed0(L"%s/%d_%d_%d_S.bmp",piVar2,*unaff_ESI,*(undefined4 *)(unaff_ESI + 2),unaff_ESI[1]);
  FUN_00498ed0(L"./Emblem/%d_%d_%d_S.bmp",*unaff_ESI,*(undefined4 *)(unaff_ESI + 2),unaff_ESI[1]);
  HVar3 = URLDownloadToFileW((LPUNKNOWN)0x0,&local_418,&local_210,0,(LPBINDSTATUSCALLBACK)0x0);
  if (-1 < HVar3) {
    pWVar4 = &local_210;
    do {
      WVar1 = *pWVar4;
      pWVar4 = pWVar4 + 1;
    } while (WVar1 != L'\0');
    FUN_00402160(&local_210,(int)pWVar4 - (int)local_20e >> 1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

