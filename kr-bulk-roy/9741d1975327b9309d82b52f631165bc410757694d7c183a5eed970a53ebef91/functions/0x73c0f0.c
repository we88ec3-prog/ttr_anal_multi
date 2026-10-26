
void FUN_0073c0f0(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  LPCWSTR ***ppppWVar2;
  int in_ECX;
  LPCWSTR ***lpszString;
  int local_3c;
  tagSIZE local_38;
  HDC local_30;
  HGDIOBJ local_2c;
  LPCWSTR **local_28 [5];
  uint local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_3c;
  if (param_2 == 0) {
    __security_check_cookie(local_c ^ (uint)&local_3c);
    return;
  }
  FUN_0073ce20();
  lpszString = (LPCWSTR ***)local_28[0];
  if (local_14 < 8) {
    lpszString = local_28;
  }
  FUN_0073bd60(param_1);
  local_38.cx = 0;
  local_38.cy = 0;
  local_3c = 0;
  ppppWVar2 = lpszString;
  do {
    sVar1 = *(short *)ppppWVar2;
    ppppWVar2 = (LPCWSTR ***)((int)ppppWVar2 + 2);
  } while (sVar1 != 0);
  GetTextExtentExPointW
            (local_30,(LPCWSTR)lpszString,(int)ppppWVar2 - ((int)lpszString + 2) >> 1,param_3,
             &local_3c,(LPINT)0x0,&local_38);
  GetLastError();
  SelectObject(*(HDC *)(in_ECX + 0xc),local_2c);
  if (7 < local_14) {
    FUN_0089120c(local_28[0]);
  }
  __security_check_cookie(local_c ^ (uint)&local_3c);
  return;
}

