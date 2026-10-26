
/* Library Function - Single Match
    ___crtMessageBoxW
   
   Library: Visual Studio 2010 Release */

int __cdecl ___crtMessageBoxW(LPCWSTR _LpText,LPCWSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  FARPROC pFVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  undefined1 local_28 [4];
  LPCWSTR local_24;
  LPCWSTR local_20;
  PVOID local_1c;
  int local_18;
  undefined1 local_14 [8];
  byte local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_24 = _LpText;
  local_20 = _LpCaption;
  local_1c = (PVOID)FUN_008a5543();
  local_18 = 0;
  if (DAT_00f8d88c == (PVOID)0x0) {
    hModule = LoadLibraryW(L"USER32.DLL");
    if ((hModule == (HMODULE)0x0) ||
       (pFVar1 = GetProcAddress(hModule,"MessageBoxW"), pFVar1 == (FARPROC)0x0)) goto LAB_008b2336;
    DAT_00f8d88c = EncodePointer(pFVar1);
    pFVar1 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_00f8d890 = EncodePointer(pFVar1);
    pFVar1 = GetProcAddress(hModule,"GetLastActivePopup");
    DAT_00f8d894 = EncodePointer(pFVar1);
    pFVar1 = GetProcAddress(hModule,"GetUserObjectInformationW");
    DAT_00f8d89c = EncodePointer(pFVar1);
    if (DAT_00f8d89c != (PVOID)0x0) {
      pFVar1 = GetProcAddress(hModule,"GetProcessWindowStation");
      DAT_00f8d898 = EncodePointer(pFVar1);
    }
  }
  if ((DAT_00f8d898 == local_1c) || (DAT_00f8d89c == local_1c)) {
LAB_008b22e5:
    if ((((DAT_00f8d890 != local_1c) &&
         (pcVar2 = DecodePointer(DAT_00f8d890), pcVar2 != (code *)0x0)) &&
        (local_18 = (*pcVar2)(), local_18 != 0)) &&
       ((DAT_00f8d894 != local_1c && (pcVar2 = DecodePointer(DAT_00f8d894), pcVar2 != (code *)0x0)))
       ) {
      local_18 = (*pcVar2)(local_18);
    }
  }
  else {
    pcVar2 = DecodePointer(DAT_00f8d898);
    pcVar3 = DecodePointer(DAT_00f8d89c);
    if (((pcVar2 == (code *)0x0) || (pcVar3 == (code *)0x0)) ||
       (((iVar4 = (*pcVar2)(), iVar4 != 0 &&
         (iVar4 = (*pcVar3)(iVar4,1,local_14,0xc,local_28), iVar4 != 0)) && ((local_c & 1) != 0))))
    goto LAB_008b22e5;
    _UType = _UType | 0x200000;
  }
  pcVar2 = DecodePointer(DAT_00f8d88c);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(local_18,local_24,local_20,_UType);
  }
LAB_008b2336:
  iVar4 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar4;
}

