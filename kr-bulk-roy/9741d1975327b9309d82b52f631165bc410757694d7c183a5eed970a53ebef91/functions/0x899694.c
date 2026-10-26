
void FUN_00899694(uint param_1,uint param_2)

{
  uchar *puVar1;
  ulong uVar2;
  errno_t eVar3;
  uchar *in_ECX;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar1 = __mbsrchr(in_ECX,0x2e);
  puVar1 = puVar1 + 1;
  if ((puVar1 < in_ECX) || (param_1 <= (uint)((int)puVar1 - (int)in_ECX))) {
    FUN_00893343();
  }
  else {
    uVar2 = _strtoul((char *)puVar1,(char **)0x0,0x20);
    if ((uVar2 + 1 < param_2) &&
       ((eVar3 = __ultoa_s(uVar2 + 1,local_10,8,0x20), eVar3 != 0 ||
        (eVar3 = _strcpy_s((char *)puVar1,(rsize_t)(in_ECX + (param_1 - (int)puVar1)),local_10),
        eVar3 != 0)))) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

