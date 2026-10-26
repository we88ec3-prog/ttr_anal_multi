
void FUN_0073c290(LONG *param_1,undefined4 param_2,int param_3,int param_4)

{
  short sVar1;
  HDC pHVar2;
  LPCWSTR ***ppppWVar3;
  LPCWSTR **local_3c;
  HDC local_38;
  HGDIOBJ local_34;
  tagSIZE local_30;
  LPCWSTR **local_28 [5];
  uint local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_3c;
  local_30.cx = 0;
  local_30.cy = 0;
  if (param_3 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    FUN_0073ce20();
    pHVar2 = local_38;
    if (local_14 < 8) {
      local_3c = (LPCWSTR **)local_28;
    }
    else {
      local_3c = local_28[0];
    }
    if (param_4 == -1) {
      ppppWVar3 = (LPCWSTR ***)local_3c;
      do {
        sVar1 = *(short *)ppppWVar3;
        ppppWVar3 = (LPCWSTR ***)((int)ppppWVar3 + 2);
      } while (sVar1 != 0);
      param_4 = (int)ppppWVar3 - (int)((int)local_3c + 2) >> 1;
    }
    FUN_0073bd60(param_2);
    GetTextExtentPoint32W(local_38,(LPCWSTR)local_3c,param_4,&local_30);
    SelectObject((HDC)pHVar2[3].unused,local_34);
    *param_1 = local_30.cx;
    param_1[1] = local_30.cy;
    if (7 < local_14) {
      FUN_0089120c(local_28[0]);
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_3c);
  return;
}

