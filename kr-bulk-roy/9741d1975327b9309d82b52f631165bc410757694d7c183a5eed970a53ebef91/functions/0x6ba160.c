
void FUN_006ba160(void)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  undefined4 extraout_EDX;
  undefined1 *unaff_ESI;
  undefined4 uVar3;
  char local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar3 = 0;
  __itoa_s(in_ECX,local_14,0xc,10);
  pcVar2 = local_14;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(local_14,(int)pcVar2 - (int)(local_14 + 1));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar3);
  return;
}

