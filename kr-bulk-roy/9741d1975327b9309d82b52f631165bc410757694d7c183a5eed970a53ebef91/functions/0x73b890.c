
void FUN_0073b890(undefined4 param_1,LPCWSTR param_2,uint param_3,RECT *param_4)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  int cchText;
  HBRUSH hbr;
  int in_ECX;
  HDC local_14;
  HGDIOBJ local_10;
  
  if (param_2 != (LPCWSTR)0x0) {
    pWVar2 = param_2;
    do {
      WVar1 = *pWVar2;
      pWVar2 = pWVar2 + 1;
    } while (WVar1 != L'\0');
    cchText = (int)pWVar2 - (int)(param_2 + 1) >> 1;
    if (cchText != 0) {
      FUN_0073bd60(param_1);
      SetBkMode(local_14,1);
      SetBkColor(local_14,0);
      SetTextColor(local_14,0xffffff);
      DrawTextW(local_14,param_2,cchText,param_4,param_3 | 0xc00);
      hbr = GetStockObject(4);
      FillRect(local_14,param_4,hbr);
      DrawTextW(local_14,param_2,cchText,param_4,param_3 | 0x800);
      SelectObject(*(HDC *)(in_ECX + 0xc),local_10);
    }
  }
  return;
}

