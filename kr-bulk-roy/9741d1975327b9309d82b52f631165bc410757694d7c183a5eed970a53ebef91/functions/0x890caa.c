
/* Library Function - Single Match
    __Getdateorder
   
   Library: Visual Studio 2010 Release */

int __cdecl __Getdateorder(void)

{
  int iVar1;
  LCTYPE LCType;
  WCHAR *lpLCData;
  int cchData;
  WCHAR local_8 [2];
  
  local_8[0] = L'\0';
  local_8[1] = L'\0';
  cchData = 2;
  lpLCData = local_8;
  LCType = 0x22;
  iVar1 = ____lc_handle_func();
  GetLocaleInfoW(*(LCID *)(iVar1 + 0x14),LCType,lpLCData,cchData);
  if (local_8[0] == L'0') {
    return 2;
  }
  if (local_8[0] == L'1') {
    return 1;
  }
  return (local_8[0] != L'2') - 1 & 3;
}

