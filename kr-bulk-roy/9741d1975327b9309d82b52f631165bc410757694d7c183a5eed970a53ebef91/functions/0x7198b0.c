
void FUN_007198b0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0;
  if (pcVar2 != param_1 + 1) {
    do {
      iVar3 = _toupper((int)param_1[uVar4]);
      param_1[uVar4] = (char)iVar3;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)((int)pcVar2 - (int)(param_1 + 1)));
  }
  return;
}

