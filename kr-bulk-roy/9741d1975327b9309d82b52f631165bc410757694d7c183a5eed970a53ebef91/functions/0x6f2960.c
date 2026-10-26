
void FUN_006f2960(void)

{
  uint uVar1;
  char *_Src;
  LSTATUS LVar2;
  int in_ECX;
  DWORD local_11c [2];
  BYTE local_114 [4];
  HKEY local_110;
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((*(int *)(in_ECX + 0x74) != -0x1ff1f7fc) && (*(int *)(in_ECX + 0x74) != -0x1ff6fbfc)) &&
     (uVar1 = *(uint *)(in_ECX + 0x84), uVar1 != 0)) {
    if ((short)uVar1 == 0x404) {
      _strcpy_s(local_10c,0x104,"software\\microsoft\\windows\\currentversion\\");
      _Src = "MSTCIPH";
      if ((uVar1 & 0xffff0000) < 0x5010000) {
        _Src = "TINTLGNT";
      }
      _strcat_s(local_10c,0x104,_Src);
      LVar2 = RegOpenKeyExA((HKEY)0x80000001,local_10c,0,0x20019,&local_110);
      if (LVar2 == 0) {
        local_11c[1] = 4;
        RegQueryValueExA(local_110,"Keyboard Mapping",(LPDWORD)0x0,local_11c,local_114,local_11c + 1
                        );
        RegCloseKey(local_110);
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

