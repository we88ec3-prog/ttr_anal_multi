
void FUN_004275b0(byte *param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t local_14;
  undefined1 local_12 [10];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  __ultow_s((uint)*param_1,&local_14,5,10);
  pwVar2 = &local_14;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_00404300(&local_14,(int)pwVar2 - (int)local_12 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

