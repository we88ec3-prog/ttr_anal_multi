
int FUN_007039d0(int param_1,char *param_2,char *param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar4 = 0;
  pcVar5 = param_2;
  if (param_2 < *(char **)(param_1 + 4)) {
    do {
      cVar1 = *param_3;
      if (cVar1 == '%') {
        uVar2 = FUN_00703690();
LAB_00703a26:
        if (uVar2 == 0) break;
      }
      else if (cVar1 != '.') {
        if (cVar1 == '[') {
          uVar2 = FUN_007037a0(*pcVar5,param_4 + -1);
        }
        else {
          uVar2 = (uint)(cVar1 == *pcVar5);
        }
        goto LAB_00703a26;
      }
      pcVar5 = pcVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (pcVar5 < *(char **)(param_1 + 4));
    if (iVar4 < 0) {
      return 0;
    }
  }
  do {
    iVar3 = FUN_00703c30(param_1,param_2 + iVar4,param_4 + 1);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  return 0;
}

