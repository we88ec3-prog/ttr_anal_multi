
void FUN_00430270(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + (1 - (int)(param_1 + 1));
  iVar3 = FUN_0087dc3d(pcVar2);
  if (pcVar2 != (char *)0x0) {
    iVar3 = iVar3 - (int)param_1;
    do {
      param_1[iVar3] = *param_1;
      param_1 = param_1 + 1;
      pcVar2 = pcVar2 + -1;
    } while (pcVar2 != (char *)0x0);
  }
  return;
}

