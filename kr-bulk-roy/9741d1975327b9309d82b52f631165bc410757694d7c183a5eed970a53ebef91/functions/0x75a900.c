
void FUN_0075a900(undefined4 param_1,undefined4 param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined2 *unaff_ESI;
  wchar_t local_34;
  undefined1 local_32 [42];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  __i64tow_s(CONCAT44(param_2,param_1),&local_34,0x16,10);
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  pwVar2 = &local_34;
  do {
    wVar1 = *pwVar2;
    pwVar2 = pwVar2 + 1;
  } while (wVar1 != L'\0');
  FUN_00402160(&local_34,(int)pwVar2 - (int)local_32 >> 1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

