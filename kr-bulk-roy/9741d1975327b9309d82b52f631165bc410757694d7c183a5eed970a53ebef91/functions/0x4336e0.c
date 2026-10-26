
void FUN_004336e0(short *param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t local_18;
  undefined1 local_16 [14];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  __itow_s((int)*param_1,&local_18,7,10);
  pwVar2 = &local_18;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_00404300(&local_18,(int)pwVar2 - (int)local_16 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

