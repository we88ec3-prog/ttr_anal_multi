
undefined4 FUN_008beb90(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  undefined4 *in_EAX;
  int iVar4;
  char *pcVar5;
  char *unaff_EBX;
  char *pcVar6;
  
  *in_EAX = unaff_EBX;
  cVar2 = *unaff_EBX;
  pcVar6 = unaff_EBX;
  while (((cVar2 != '\0' && (*pcVar6 != ' ')) && (*pcVar6 != '\t'))) {
    pcVar6 = pcVar6 + 1;
    cVar2 = *pcVar6;
  }
  cVar2 = *pcVar6;
  cVar3 = -1;
  if (cVar2 != '\0') {
    *pcVar6 = '\0';
    cVar3 = cVar2;
  }
  iVar4 = FUN_008be940();
  if (cVar3 != -1) {
    *pcVar6 = cVar3;
  }
  if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 1)) {
    return 0;
  }
  pcVar5 = unaff_EBX + param_1;
  if (*pcVar6 != '\0') {
    *pcVar6 = '\0';
    pcVar6 = pcVar6 + 1;
  }
  cVar2 = *pcVar6;
  while ((cVar2 != '\0' && ((cVar2 == ' ' || (cVar2 == '\t'))))) {
    pcVar1 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
    cVar2 = *pcVar1;
  }
  if (*pcVar6 == '\"') {
    pcVar6 = pcVar6 + 1;
  }
  *param_2 = pcVar6;
  if (pcVar6 < pcVar5) {
    while ((pcVar5[-1] == ' ' || (pcVar5[-1] == '\t'))) {
      pcVar5 = pcVar5 + -1;
      *pcVar5 = '\0';
      if (pcVar5 <= pcVar6) {
        return 1;
      }
    }
    if ((pcVar6 < pcVar5) && (pcVar5[-1] == '\"')) {
      pcVar5[-1] = '\0';
    }
  }
  return 1;
}

