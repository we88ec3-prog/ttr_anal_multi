
void FUN_006f7c50(char *param_1)

{
  char cVar1;
  size_t in_EAX;
  char *pcVar2;
  size_t _Count;
  char *in_ECX;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (*in_ECX == '=') {
    _strncpy(param_1,in_ECX + 1,in_EAX);
    param_1[in_EAX - 1] = '\0';
    return;
  }
  if (*in_ECX != '@') {
    _Count = _strcspn(in_ECX,"\n\r");
    if (in_EAX - 0x11 < _Count) {
      _Count = in_EAX - 0x11;
    }
    builtin_strncpy(param_1,"[string \"",10);
    pcVar2 = in_ECX;
    if (in_ECX[_Count] == '\0') {
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar3 = (int)pcVar2 - (int)in_ECX;
      pcVar2 = param_1 + -1;
      do {
        pcVar5 = pcVar2 + 1;
        pcVar2 = pcVar2 + 1;
      } while (*pcVar5 != '\0');
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)in_ECX;
        in_ECX = in_ECX + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *in_ECX;
        in_ECX = in_ECX + 1;
        pcVar2 = pcVar2 + 1;
      }
    }
    else {
      _strncat(param_1,in_ECX,_Count);
      pcVar2 = param_1 + -1;
      do {
        pcVar5 = pcVar2;
        pcVar2 = pcVar5 + 1;
      } while (pcVar5[1] != '\0');
      builtin_strncpy(pcVar5 + 1,"...",4);
    }
    pcVar2 = param_1 + -1;
    do {
      pcVar5 = pcVar2;
      pcVar2 = pcVar5 + 1;
    } while (pcVar5[1] != '\0');
    pcVar2[0] = '\"';
    pcVar2[1] = ']';
    pcVar5[3] = '\0';
    return;
  }
  pcVar5 = in_ECX + 1;
  pcVar2 = pcVar5;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *param_1 = '\0';
  pcVar6 = pcVar5;
  if (in_EAX - 8 < (uint)((int)pcVar2 - (int)(in_ECX + 2))) {
    pcVar5 = pcVar5 + (((int)pcVar2 - (int)(in_ECX + 2)) - (in_EAX - 8));
    pcVar2 = param_1 + -1;
    do {
      pcVar6 = pcVar2;
      pcVar2 = pcVar6 + 1;
    } while (pcVar6[1] != '\0');
    builtin_strncpy(pcVar6 + 1,"...",4);
    pcVar6 = pcVar5;
  }
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  param_1 = param_1 + -1;
  do {
    pcVar2 = param_1 + 1;
    param_1 = param_1 + 1;
  } while (*pcVar2 != '\0');
  pcVar2 = pcVar6;
  for (uVar3 = (uint)((int)pcVar5 - (int)pcVar6) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar3 = (int)pcVar5 - (int)pcVar6 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *param_1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

