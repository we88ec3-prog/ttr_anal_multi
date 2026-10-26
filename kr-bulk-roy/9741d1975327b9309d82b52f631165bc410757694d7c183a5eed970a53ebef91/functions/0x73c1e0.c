
void FUN_0073c1e0(undefined4 param_1,int param_2,uint param_3,LPRECT param_4)

{
  short sVar1;
  LPCWSTR ***ppppWVar2;
  int in_ECX;
  LPCWSTR ***lpchText;
  HDC local_30;
  HGDIOBJ local_2c;
  LPCWSTR **local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((param_4 != (LPRECT)0x0) && (param_2 != 0)) {
    FUN_0073ce20();
    lpchText = (LPCWSTR ***)local_24[0];
    if (local_10 < 8) {
      lpchText = local_24;
    }
    FUN_0073bd60(param_1);
    ppppWVar2 = lpchText;
    do {
      sVar1 = *(short *)ppppWVar2;
      ppppWVar2 = (LPCWSTR ***)((int)ppppWVar2 + 2);
    } while (sVar1 != 0);
    DrawTextW(local_30,(LPCWSTR)lpchText,(int)ppppWVar2 - ((int)lpchText + 2) >> 1,param_4,
              param_3 | 0xc00);
    SelectObject(*(HDC *)(in_ECX + 0xc),local_2c);
    if (7 < local_10) {
      FUN_0089120c(local_24[0]);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

