
void FUN_0049b5f0(void)

{
  LPCWSTR lpWideCharStr;
  undefined1 *puVar1;
  int *unaff_ESI;
  
  lpWideCharStr = (LPCWSTR)FUN_006e0070();
  if (lpWideCharStr == (LPCWSTR)0x0) {
    puVar1 = &DAT_00bf2375;
  }
  else {
    WideCharToMultiByte(0,0,lpWideCharStr,-1,&DAT_00fdf710,0x400,(LPCSTR)0x0,(LPBOOL)0x0);
    puVar1 = &DAT_00fdf710;
  }
  FUN_006edd00("Your Graphic Card: %s",puVar1);
  DirectDrawCreateEx(0,&DAT_00fb941c,&DAT_00bd6794,0);
  DAT_00fb9414 = unaff_ESI;
  DAT_00fb9418 = (**(code **)(*unaff_ESI + 0x10))();
  FUN_006defc0();
  return;
}

