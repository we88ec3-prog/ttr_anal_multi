
char * FUN_00732fe0(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int in_ECX;
  undefined *puVar4;
  
  pcVar2 = (char *)FUN_00731170(param_3);
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  if (*pcVar2 == '\0') {
    return (char *)0x0;
  }
  if (param_2 != (undefined4 *)0x0) {
    FUN_00730f80(pcVar2,param_3);
    *(undefined4 *)(in_ECX + 4) = *param_2;
    *(undefined4 *)(in_ECX + 8) = param_2[1];
  }
  pcVar3 = (char *)FUN_007312f0(in_ECX + 0x14);
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    pcVar2 = (char *)FUN_00731170(param_3);
    if ((pcVar2 == (char *)0x0) || ((*pcVar2 == '\0' || (*pcVar2 != '=')))) {
      if (*(int *)(in_ECX + 0x10) == 0) {
        return (char *)0x0;
      }
      FUN_00732010(7,pcVar2,param_2,param_3);
      return (char *)0x0;
    }
    pcVar2 = (char *)FUN_00731170(param_3);
    if ((pcVar2 == (char *)0x0) || (cVar1 = *pcVar2, cVar1 == '\0')) {
      if (*(int *)(in_ECX + 0x10) == 0) {
        return (char *)0x0;
      }
      FUN_00732010(7,pcVar2,param_2,param_3);
      return (char *)0x0;
    }
    if (cVar1 == '\'') {
      puVar4 = &DAT_00bed1cc;
    }
    else {
      if (cVar1 != '\"') {
        FUN_0043ff70(in_ECX + 0x30);
        while( true ) {
          if (*pcVar2 == '\0') {
            return pcVar2;
          }
          cVar1 = FUN_00730dc0(*pcVar2);
          if (cVar1 != '\0') {
            return pcVar2;
          }
          cVar1 = *pcVar2;
          if (cVar1 == '\n') {
            return pcVar2;
          }
          if (cVar1 == '\r') {
            return pcVar2;
          }
          if (cVar1 == '/') {
            return pcVar2;
          }
          if (cVar1 == '>') {
            return pcVar2;
          }
          if ((cVar1 == '\'') || (cVar1 == '\"')) break;
          FUN_00429630(1,cVar1);
          pcVar2 = pcVar2 + 1;
          if (pcVar2 == (char *)0x0) {
            return (char *)0x0;
          }
        }
        goto LAB_00733153;
      }
      puVar4 = &DAT_00c411ac;
    }
    pcVar2 = (char *)FUN_007315f0(in_ECX + 0x30,0,puVar4);
    return pcVar2;
  }
LAB_00733153:
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_00732010(7,pcVar2,param_2,param_3);
  }
  return (char *)0x0;
}

