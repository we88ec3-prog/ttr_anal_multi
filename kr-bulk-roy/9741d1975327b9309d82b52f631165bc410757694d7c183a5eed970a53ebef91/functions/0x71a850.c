
char * FUN_0071a850(undefined1 *param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar1 = param_1 + 1;
  pcVar4 = pcVar1;
  switch(*pcVar1) {
  case '#':
    if (param_1[2] == 'x') {
      cVar3 = param_1[3];
      pcVar4 = param_1 + 3;
      if (cVar3 == ';') {
        return pcVar4;
      }
      while( true ) {
        while ((int)cVar3 - 0x30U < 10) {
          pcVar1 = pcVar4 + 1;
          pcVar4 = pcVar4 + 1;
          cVar3 = *pcVar1;
        }
        if (5 < ((int)cVar3 | 0x20U) - 0x61) break;
        cVar3 = pcVar4[1];
        pcVar4 = pcVar4 + 1;
      }
    }
    else {
      cVar3 = param_1[2];
      pcVar4 = param_1 + 2;
      if (cVar3 == ';') {
        return pcVar4;
      }
      while ((int)cVar3 - 0x30U < 10) {
        pcVar1 = pcVar4 + 1;
        pcVar4 = pcVar4 + 1;
        cVar3 = *pcVar1;
      }
    }
    if (cVar3 == ';') {
      iVar2 = FUN_0071a640();
      FUN_0071a810((int)(pcVar4 + 1) - iVar2);
      return pcVar4 + 1;
    }
    break;
  case 'a':
    pcVar4 = param_1 + 2;
    if (param_1[2] == 'm') {
      pcVar4 = param_1 + 3;
      if ((*pcVar4 == 'p') && (pcVar4 = param_1 + 4, *pcVar4 == ';')) {
        *param_1 = 0x26;
        FUN_0071a810(param_1 + (5 - (int)pcVar1));
        return param_1 + 5;
      }
    }
    else if ((((param_1[2] == 'p') && (pcVar4 = param_1 + 3, *pcVar4 == 'o')) &&
             (pcVar4 = param_1 + 4, *pcVar4 == 's')) && (pcVar4 = param_1 + 5, *pcVar4 == ';')) {
      *param_1 = 0x27;
      FUN_0071a810(param_1 + (6 - (int)pcVar1));
      return param_1 + 6;
    }
    break;
  case 'g':
    pcVar4 = param_1 + 2;
    if ((*pcVar4 == 't') && (pcVar4 = param_1 + 3, *pcVar4 == ';')) {
      *param_1 = 0x3e;
      FUN_0071a810(param_1 + (4 - (int)pcVar1));
      return param_1 + 4;
    }
    break;
  case 'l':
    pcVar4 = param_1 + 2;
    if ((*pcVar4 == 't') && (pcVar4 = param_1 + 3, *pcVar4 == ';')) {
      *param_1 = 0x3c;
      FUN_0071a810(param_1 + (4 - (int)pcVar1));
      return param_1 + 4;
    }
    break;
  case 'q':
    pcVar4 = param_1 + 2;
    if ((((*pcVar4 == 'u') && (pcVar4 = param_1 + 3, *pcVar4 == 'o')) &&
        (pcVar4 = param_1 + 4, *pcVar4 == 't')) && (pcVar4 = param_1 + 5, *pcVar4 == ';')) {
      *param_1 = 0x22;
      FUN_0071a810(param_1 + (6 - (int)pcVar1));
      return param_1 + 6;
    }
  }
  return pcVar4;
}

