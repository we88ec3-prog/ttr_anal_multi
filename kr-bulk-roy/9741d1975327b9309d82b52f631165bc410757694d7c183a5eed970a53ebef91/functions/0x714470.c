
void FUN_00714470(int param_1)

{
  char *pcVar1;
  char cVar2;
  int *_Str2;
  int iVar3;
  char *in_ECX;
  uint uVar4;
  int *piVar5;
  char local_108 [256];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_108[0] = '\0';
  _memset(local_108 + 1,0,0xff);
  _strcpy_s(local_108,0x100,in_ECX);
  pcVar1 = in_ECX + 1;
  do {
    cVar2 = *in_ECX;
    in_ECX = in_ECX + 1;
  } while (cVar2 != '\0');
  uVar4 = 0;
  if (in_ECX != pcVar1) {
    do {
      if (local_108[uVar4] == '\\') {
        local_108[uVar4] = '/';
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)((int)in_ECX - (int)pcVar1));
  }
  piVar5 = (int *)**(int **)(param_1 + 0xc);
  if (piVar5 != *(int **)(param_1 + 0xc)) {
    do {
      _Str2 = piVar5 + 2;
      if (0xf < (uint)piVar5[7]) {
        _Str2 = (int *)*_Str2;
      }
      iVar3 = __strnicmp(local_108,(char *)_Str2,piVar5[6]);
      if (iVar3 == 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*(int *)(param_1 + 0xc));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

