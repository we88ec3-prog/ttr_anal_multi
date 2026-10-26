
char * FUN_00713b10(char *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  int *in_ECX;
  
  iVar1 = in_ECX[2];
  (**(code **)(*in_ECX + 0x10))(param_1,param_2,1);
  iVar2 = in_ECX[2];
  if (iVar2 - iVar1 != 0) {
    bVar3 = false;
    in_ECX[4] = 0;
    pcVar4 = _strchr(param_1,0xd);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = _strchr(param_1,10);
    }
    else if (pcVar4[1] == '\n') {
      bVar3 = true;
    }
    if (pcVar4 != (char *)0x0) {
      iVar5 = (int)pcVar4 - (int)param_1;
      if (bVar3) {
        param_1[iVar5] = '\n';
        iVar5 = iVar5 + 1;
      }
      param_1[iVar5] = '\0';
      (**(code **)(*in_ECX + 0x34))((iVar5 - (iVar2 - iVar1)) + 1,1);
    }
    return param_1;
  }
  return (char *)0x0;
}

