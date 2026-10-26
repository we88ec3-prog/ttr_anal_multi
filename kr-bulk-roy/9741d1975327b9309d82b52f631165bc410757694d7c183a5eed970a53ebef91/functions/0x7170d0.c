
char * FUN_007170d0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar4 = 0;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar2 = param_1;
  if (pcVar3 != param_1 + 1) {
    do {
      if (*pcVar2 == '/') {
        return pcVar2;
      }
      if (*pcVar2 == '\\') {
        return pcVar2;
      }
      uVar4 = uVar4 + 1;
      pcVar3 = param_1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar2 = pcVar2 + 1;
    } while (uVar4 < (uint)((int)pcVar3 - (int)(param_1 + 1)));
  }
  return (char *)0x0;
}

