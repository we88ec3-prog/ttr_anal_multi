
void FUN_004206a0(ulong *param_1)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t local_20;
  undefined1 local_1e [22];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  __ultow_s(*param_1,&local_20,0xc,10);
  pwVar2 = &local_20;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_00404300(&local_20,(int)pwVar2 - (int)local_1e >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

