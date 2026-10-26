
void FUN_007083f0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  FILE *in_ECX;
  int iVar6;
  char *local_21c;
  int local_218;
  int local_214;
  char local_210 [520];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_214 = param_1;
  local_21c = local_210;
  local_218 = 0;
  while( true ) {
    iVar5 = local_214;
    iVar6 = (int)local_21c - (int)local_210;
    if (iVar6 != 0) {
      if (*(uint *)(*(int *)(local_214 + 0x10) + 0x40) <=
          *(uint *)(*(int *)(local_214 + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      puVar2 = *(undefined4 **)(iVar5 + 8);
      uVar3 = FUN_006fec70(iVar5,local_210,iVar6);
      *puVar2 = uVar3;
      puVar2[2] = 4;
      *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 0x10;
      local_218 = local_218 + 1;
      local_21c = local_210;
      FUN_006f6b60(&local_21c);
    }
    pcVar4 = _fgets(local_210,0x200,in_ECX);
    if (pcVar4 == (char *)0x0) break;
    pcVar4 = local_210;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar5 = (int)pcVar4 - (int)(local_210 + 1);
    if ((iVar5 != 0) && (local_210[iVar5 + -1] == '\n')) {
      local_21c = local_21c + iVar5 + -1;
      FUN_006f6af0();
      FUN_006f5bb0();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_21c = local_21c + iVar5;
  }
  FUN_006f6af0();
  FUN_006f5bb0();
  local_218 = 1;
  FUN_006f5460();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,0);
  return;
}

