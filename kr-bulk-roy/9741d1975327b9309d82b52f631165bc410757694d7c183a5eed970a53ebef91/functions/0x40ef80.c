
void FUN_0040ef80(void)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  int in_ECX;
  undefined4 extraout_EDX;
  undefined2 *unaff_ESI;
  undefined4 uVar3;
  wchar_t local_20;
  undefined1 local_1e [22];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar3 = 0;
  __itow_s(in_ECX,&local_20,0xc,10);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  pwVar2 = &local_20;
  *unaff_ESI = 0;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_00402160(&local_20,(int)pwVar2 - (int)local_1e >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar3);
  return;
}

