
void FUN_0073bdd0(undefined4 param_1,int param_2,int param_3,LPINT param_4,int *param_5)

{
  short sVar1;
  LPCWSTR ***ppppWVar2;
  int cchString;
  LPCWSTR ***lpszString;
  tagSIZE local_40;
  HDC local_38;
  HGDIOBJ local_34;
  int *local_30;
  int local_2c;
  int local_28;
  LPCWSTR **local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_30 = param_5;
  if (param_2 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0073ce20();
  lpszString = (LPCWSTR ***)local_24[0];
  if (local_10 < 8) {
    lpszString = local_24;
  }
  FUN_0073bd60(param_1);
  local_2c = 0;
  ppppWVar2 = lpszString;
  do {
    sVar1 = *(short *)ppppWVar2;
    ppppWVar2 = (LPCWSTR ***)((int)ppppWVar2 + 2);
  } while (sVar1 != 0);
  cchString = (int)ppppWVar2 - ((int)lpszString + 2) >> 1;
  _memset(param_4,0,cchString * 4);
  GetTextExtentExPointW(local_38,(LPCWSTR)lpszString,cchString,param_3,&local_2c,param_4,&local_40);
  if (local_30 != (int *)0x0) {
    *local_30 = local_2c;
  }
  SelectObject(*(HDC *)(local_28 + 0xc),local_34);
  if (7 < local_10) {
    FUN_0089120c(local_24[0]);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

