
void FUN_00431440(wchar_t *param_1,wchar_t *param_2,char param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  mbstate_t local_14;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_1 != param_2) {
    do {
      local_14 = 0;
      iVar2 = __Wcrtomb(local_10,*param_1,&local_14,(_Cvtvec *)(in_ECX + 0x18));
      cVar1 = param_3;
      if (iVar2 == 1) {
        cVar1 = local_10[0];
      }
      *param_4 = cVar1;
      param_1 = param_1 + 1;
      param_4 = param_4 + 1;
    } while (param_1 != param_2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

