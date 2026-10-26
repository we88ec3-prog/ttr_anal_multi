
int FUN_008e9ac0(char *param_1,uint param_2,int param_3)

{
  char cVar1;
  char *_Str1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  if (0xffff < param_2) {
    return 0;
  }
  iVar4 = 0;
  if (0 < *(int *)(param_3 + 0x11c)) {
    do {
      _Str1 = *(char **)(*(int *)(param_3 + 0x120) + iVar4 * 4);
      if ((_Str1 != (char *)0x0) && (*_Str1 == *param_1)) {
        pcVar2 = _Str1;
        do {
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        if ((int)pcVar2 - (int)(_Str1 + 1) == param_2) {
          iVar3 = _strncmp(_Str1,param_1,param_2);
          if (iVar3 == 0) {
            return iVar4;
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_3 + 0x11c));
  }
  return 0;
}

