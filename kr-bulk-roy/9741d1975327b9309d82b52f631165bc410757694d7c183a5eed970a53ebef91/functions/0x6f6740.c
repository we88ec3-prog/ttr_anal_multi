
void FUN_006f6740(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *in_ECX;
  int in_EDX;
  
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar4 = _strstr(in_ECX,param_1);
  while (pcVar4 != (char *)0x0) {
    FUN_006f6c40(in_ECX,(int)pcVar4 - (int)in_ECX);
    pcVar5 = param_2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_006f6c40(param_2,(int)pcVar5 - (int)(param_2 + 1));
    in_ECX = pcVar4 + ((int)pcVar3 - (int)(param_1 + 1));
    pcVar4 = _strstr(in_ECX,param_1);
  }
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_006f6c40(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  FUN_006f6af0();
  FUN_006f5bb0();
  if (*(int *)(*(int *)(in_EDX + 8) + -8) != 4) {
    iVar6 = FUN_006fb5d0();
    if (iVar6 == 0) {
      __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (*(uint *)(*(int *)(in_EDX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EDX + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
  }
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

