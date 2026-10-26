
int FUN_006f1fa0(UINT param_1,LPWSTR param_2)

{
  int iVar1;
  LPCSTR unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI == (LPCSTR)0x0) {
    iVar1 = MultiByteToWideChar(param_1,0,(LPCSTR)0x0,unaff_EDI,(LPWSTR)0x0,0);
    return iVar1;
  }
  iVar1 = MultiByteToWideChar(param_1,0,unaff_ESI,unaff_EDI,(LPWSTR)0x0,0);
  if (0x200 < iVar1) {
    return 0;
  }
  iVar1 = MultiByteToWideChar(param_1,0,unaff_ESI,unaff_EDI,param_2,iVar1);
  return iVar1;
}

