
void FUN_0073c040(undefined4 param_1,int param_2,int param_3,LONG *param_4)

{
  int in_ECX;
  LPCWSTR **lpString;
  tagSIZE local_38;
  HDC local_30;
  HGDIOBJ local_2c;
  LONG *local_28;
  LPCWSTR *local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_28 = param_4;
  if (param_2 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0073ce20();
  lpString = (LPCWSTR **)local_24[0];
  if (local_10 < 8) {
    lpString = local_24;
  }
  FUN_0073bd60(param_1);
  GetTextExtentPointW(local_30,(LPCWSTR)lpString,param_3,&local_38);
  *local_28 = local_38.cx;
  SelectObject(*(HDC *)(in_ECX + 0xc),local_2c);
  if (7 < local_10) {
    FUN_0089120c(local_24[0]);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

