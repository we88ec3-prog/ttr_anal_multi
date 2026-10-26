
void FUN_00733dd0(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char local_20 [4];
  byte local_1c [16];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_00402a70(&DAT_00bf2375,0);
  iVar2 = FUN_00733c30();
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      _sprintf(local_20,"%02x",(uint)local_1c[iVar2]);
      pcVar3 = local_20;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00401fc0(local_20,(int)pcVar3 - (int)(local_20 + 1));
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x10);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

