
void FUN_00404100(undefined4 *param_1)

{
  WCHAR WVar1;
  uint cchWideChar;
  LPWSTR lpWideCharStr;
  LPWSTR pWVar2;
  
  if (((LPCSTR)*param_1 != (LPCSTR)0x0) &&
     (cchWideChar = MultiByteToWideChar(DAT_00fba808,0,(LPCSTR)*param_1,-1,(LPWSTR)0x0,0),
     cchWideChar != 0)) {
    lpWideCharStr =
         (LPWSTR)FUN_0087dc3d(-(uint)((int)((ulonglong)cchWideChar * 2 >> 0x20) != 0) |
                              (uint)((ulonglong)cchWideChar * 2));
    *lpWideCharStr = L'\0';
    MultiByteToWideChar(DAT_00fba808,0,(LPCSTR)*param_1,-1,lpWideCharStr,cchWideChar);
    pWVar2 = lpWideCharStr;
    do {
      WVar1 = *pWVar2;
      pWVar2 = pWVar2 + 1;
    } while (WVar1 != L'\0');
    FUN_00404300(lpWideCharStr,(int)pWVar2 - (int)(lpWideCharStr + 1) >> 1);
    FUN_00891d3d(lpWideCharStr);
  }
  return;
}

