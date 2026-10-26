
byte * FUN_00704d30(byte *param_1,undefined1 *param_2)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  byte *pbVar5;
  
  bVar1 = *param_1;
  pbVar5 = param_1;
  while ((bVar1 != 0 && (pcVar3 = _strchr("-+ #0",(int)(char)*pbVar5), pcVar3 != (char *)0x0))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  if (5 < (uint)((int)pbVar5 - (int)param_1)) {
    FUN_006f5f30();
  }
  iVar4 = _isdigit((uint)*pbVar5);
  if (iVar4 != 0) {
    pbVar5 = pbVar5 + 1;
  }
  iVar4 = _isdigit((uint)*pbVar5);
  if (iVar4 != 0) {
    pbVar5 = pbVar5 + 1;
  }
  if (*pbVar5 == 0x2e) {
    iVar4 = _isdigit((uint)pbVar5[1]);
    pbVar2 = pbVar5 + 1;
    if (iVar4 != 0) {
      pbVar2 = pbVar5 + 2;
    }
    pbVar5 = pbVar2;
    iVar4 = _isdigit((uint)*pbVar5);
    if (iVar4 != 0) {
      pbVar5 = pbVar5 + 1;
    }
  }
  iVar4 = _isdigit((uint)*pbVar5);
  if (iVar4 != 0) {
    FUN_006f5f30();
  }
  *param_2 = 0x25;
  _strncpy(param_2 + 1,(char *)param_1,(size_t)(pbVar5 + (1 - (int)param_1)));
  (param_2 + 1)[(int)(pbVar5 + (1 - (int)param_1))] = '\0';
  return pbVar5;
}

