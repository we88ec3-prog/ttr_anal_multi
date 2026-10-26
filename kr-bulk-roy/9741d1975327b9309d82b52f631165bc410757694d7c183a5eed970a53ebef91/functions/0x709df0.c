
void FUN_00709df0(void)

{
  DWORD DVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  CHAR local_114 [268];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  DVar1 = GetModuleFileNameA((HMODULE)0x0,local_114,0x105);
  if (((DVar1 != 0) && (DVar1 != 0x105)) &&
     (pcVar2 = _strrchr(local_114,0x5c), pcVar2 != (char *)0x0)) {
    *pcVar2 = '\0';
    if (((*(int *)(*(int *)(in_ECX + 8) + -8) != 4) && (iVar3 = FUN_006fb5d0(), iVar3 != 0)) &&
       (*(uint *)(*(int *)(in_ECX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_ECX + 0x10) + 0x44))) {
      FUN_006fb3a0();
    }
    FUN_006f6740(&DAT_00c439f0,local_114);
    FUN_006f5270();
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006f5f30();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

