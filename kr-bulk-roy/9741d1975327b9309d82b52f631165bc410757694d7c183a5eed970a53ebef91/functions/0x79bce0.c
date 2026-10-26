
void FUN_0079bce0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *unaff_ESI;
  char local_158 [4];
  char local_154 [260];
  char local_50 [64];
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pcVar3 = unaff_ESI;
  if (*(int *)(param_1 + 0x300) == 0) {
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  else {
    iVar2 = FUN_00714550();
    if (iVar2 == 0) {
      __splitpath(unaff_ESI,local_158,local_154,local_50,local_10);
      pcVar3 = local_158;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(local_158,(int)pcVar3 - (int)(local_158 + 1));
      pcVar3 = local_154;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00401fc0(local_154,(int)pcVar3 - (int)(local_154 + 1));
      pcVar3 = local_50;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      FUN_00401fc0(local_50,(int)pcVar3 - (int)(local_50 + 1));
      FUN_00401fc0(&DAT_00c40f68,4);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

