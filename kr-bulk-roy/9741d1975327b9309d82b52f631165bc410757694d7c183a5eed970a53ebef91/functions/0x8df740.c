
void FUN_008df740(char *param_1)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = (int)pcVar2 - (int)(param_1 + 1);
  pcVar2 = in_EAX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = (int)pcVar2 - (int)(in_EAX + 1);
  if (iVar4 < iVar3) {
    iVar5 = 1;
    if (0 < iVar4) {
      pcVar2 = in_EAX + iVar4 + -1;
      pcVar6 = param_1 + iVar3 + -1;
      do {
        if (*pcVar6 != *pcVar2) {
          if (iVar5 <= iVar4) {
            return;
          }
          break;
        }
        iVar5 = iVar5 + 1;
        pcVar6 = pcVar6 + -1;
        pcVar2 = pcVar2 + -1;
      } while (iVar5 <= iVar4);
    }
    iVar3 = (iVar3 - iVar4) + -1;
    if (0 < iVar3) {
      while ((((cVar1 = param_1[iVar3], cVar1 == '-' || (cVar1 == ' ')) || (cVar1 == '_')) ||
             (cVar1 == '+'))) {
        iVar3 = iVar3 + -1;
        if (iVar3 < 1) {
          return;
        }
      }
      if (0 < iVar3) {
        param_1[iVar3 + 1] = '\0';
      }
    }
  }
  return;
}

