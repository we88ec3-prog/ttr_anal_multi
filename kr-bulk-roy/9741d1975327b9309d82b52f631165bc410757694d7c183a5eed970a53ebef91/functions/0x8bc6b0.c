
char * FUN_008bc6b0(undefined4 param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int local_8;
  
  local_8 = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar3 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_008baee0(param_1,pcVar2 + (int)(pcVar3 + ((1 - (int)(param_3 + 1)) -
                                                                (int)(param_2 + 1))),&local_8);
  if (local_8 == 0) {
    pcVar4 = _strrchr(param_2,0x2f);
    pcVar3 = param_3;
    if (pcVar4 == (char *)0x0) {
      *pcVar2 = '\0';
    }
    else {
      _strncpy(pcVar2,param_2,(size_t)(pcVar4 + (1 - (int)param_2)));
      pcVar2[(int)(pcVar4 + (1 - (int)param_2))] = '\0';
      param_2 = pcVar4 + 1;
    }
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar5 = (int)pcVar3 - (int)param_3;
    pcVar3 = pcVar2 + -1;
    do {
      pcVar4 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar4 != '\0');
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)param_3;
      param_3 = param_3 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; pcVar4 = param_2, uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar3 = *param_3;
      param_3 = param_3 + 1;
      pcVar3 = pcVar3 + 1;
    }
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar5 = (int)pcVar4 - (int)param_2;
    pcVar3 = pcVar2 + -1;
    do {
      pcVar4 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar4 != '\0');
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar3 = *param_2;
      param_2 = param_2 + 1;
      pcVar3 = pcVar3 + 1;
    }
    return pcVar2;
  }
  return (char *)0x0;
}

