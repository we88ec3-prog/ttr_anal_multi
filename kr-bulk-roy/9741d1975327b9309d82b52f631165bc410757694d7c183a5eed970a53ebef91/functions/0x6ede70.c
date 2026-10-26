
void FUN_006ede70(LPCSTR param_1)

{
  char cVar1;
  char *pcVar2;
  LPCSTR in_ECX;
  undefined4 extraout_EDX;
  undefined1 *unaff_ESI;
  undefined4 uVar3;
  CHAR local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar3 = 0;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    param_1 = *(LPCSTR *)param_1;
  }
  GetPrivateProfileStringA("Login","IP",in_ECX,local_10c,0x104,param_1);
  pcVar2 = local_10c;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_10c,(int)pcVar2 - (int)(local_10c + 1));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar3);
  return;
}

