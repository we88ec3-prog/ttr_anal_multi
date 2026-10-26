
void FUN_004d6ba0(int param_1,va_list param_2)

{
  wchar_t wVar1;
  undefined4 *puVar2;
  wchar_t *pwVar3;
  wchar_t *in_ECX;
  wchar_t local_20c;
  undefined1 local_20a [514];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = (undefined4 *)FUN_00891268(0x24);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[7] = 7;
    puVar2[6] = 0;
    *(undefined2 *)(puVar2 + 2) = 0;
  }
  *puVar2 = 0;
  *(undefined1 *)(puVar2 + 1) = 1;
  __vswprintf_s_l(&local_20c,0x100,in_ECX,(_locale_t)0x0,param_2);
  pwVar3 = &local_20c;
  do {
    wVar1 = *pwVar3;
    pwVar3 = pwVar3 + 1;
  } while (wVar1 != L'\0');
  FUN_00402160(&local_20c,(int)pwVar3 - (int)local_20a >> 1);
  FUN_004d7b00(param_1);
  if (*(int *)(param_1 + 0x120) == 0) {
    FUN_004d6c90();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

