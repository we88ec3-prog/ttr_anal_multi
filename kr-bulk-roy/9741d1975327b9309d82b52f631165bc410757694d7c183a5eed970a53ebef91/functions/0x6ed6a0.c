
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ed6a0(void)

{
  UINT UVar1;
  WCHAR *pWVar2;
  int iVar3;
  WCHAR local_214 [262];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7e0 != (HMODULE)0x0) {
LAB_006ed7d5:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  UVar1 = GetSystemDirectoryW(local_214,0x105);
  if (UVar1 != 0) {
    iVar3 = 0x104;
    pWVar2 = local_214;
    do {
      if (*pWVar2 == L'\0') {
        if (iVar3 != 0) {
          FUN_006eadb0(L"\\d3d9.dll",0x7fffffff);
        }
        break;
      }
      pWVar2 = pWVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    DAT_00fba7e0 = LoadLibraryW(local_214);
    if (DAT_00fba7e0 != (HMODULE)0x0) {
      DAT_00fba7e4 = GetProcAddress(DAT_00fba7e0,"Direct3DCreate9");
      _DAT_00fba7e8 = GetProcAddress(DAT_00fba7e0,"D3DPERF_BeginEvent");
      _DAT_00fba7ec = GetProcAddress(DAT_00fba7e0,"D3DPERF_EndEvent");
      _DAT_00fba7f0 = GetProcAddress(DAT_00fba7e0,"D3DPERF_SetMarker");
      _DAT_00fba7f4 = GetProcAddress(DAT_00fba7e0,"D3DPERF_SetRegion");
      _DAT_00fba7f8 = GetProcAddress(DAT_00fba7e0,"D3DPERF_QueryRepeatFrame");
      _DAT_00fba7fc = GetProcAddress(DAT_00fba7e0,"D3DPERF_SetOptions");
      _DAT_00fba800 = GetProcAddress(DAT_00fba7e0,"D3DPERF_GetStatus");
      goto LAB_006ed7d5;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

