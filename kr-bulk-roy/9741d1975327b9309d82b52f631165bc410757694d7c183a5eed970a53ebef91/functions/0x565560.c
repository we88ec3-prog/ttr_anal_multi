
void FUN_00565560(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 != (char *)0x0) {
    iVar2 = _isspace((int)*param_1);
    if (iVar2 != 0) {
      FUN_00402a70(&DAT_00bf2375,0);
      return;
    }
    pcVar3 = param_1;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(param_1,(int)pcVar3 - (int)(param_1 + 1));
  }
  return;
}

