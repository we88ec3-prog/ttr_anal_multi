
char * FUN_00703c30(int *param_1,char *param_2,char *param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char cVar7;
  
  do {
    switch(*param_3) {
    case '\0':
      return param_2;
    case '$':
      if (param_3[1] == '\0') {
        return (char *)((param_2 != (char *)param_1[1]) - 1 & (uint)param_2);
      }
    default:
switchD_00703c53_caseD_1:
      pcVar4 = (char *)FUN_00703620();
      if (param_2 < (char *)param_1[1]) {
        cVar7 = *param_3;
        if (cVar7 == '%') {
          uVar5 = FUN_00703690();
LAB_00703d92:
          if (uVar5 == 0) goto LAB_00703da0;
        }
        else if (cVar7 != '.') {
          if (cVar7 == '[') {
            uVar5 = FUN_007037a0(*param_2,pcVar4 + -1);
          }
          else {
            uVar5 = (uint)(cVar7 == *param_2);
          }
          goto LAB_00703d92;
        }
        bVar2 = true;
      }
      else {
LAB_00703da0:
        bVar2 = false;
      }
      switch(*pcVar4) {
      case '*':
        pcVar4 = (char *)FUN_007039d0(param_1,param_2,param_3,pcVar4);
        return pcVar4;
      case '+':
        if (!bVar2) {
          return (char *)0x0;
        }
        pcVar4 = (char *)FUN_007039d0(param_1,param_2 + 1,param_3,pcVar4);
        return pcVar4;
      default:
        if (!bVar2) {
          return (char *)0x0;
        }
        param_2 = param_2 + 1;
        param_3 = pcVar4;
        break;
      case '-':
        pcVar4 = (char *)FUN_00703a60(param_1,param_3,pcVar4);
        return pcVar4;
      case '?':
        if ((bVar2) &&
           (pcVar6 = (char *)FUN_00703c30(param_1,param_2 + 1,pcVar4 + 1), pcVar6 != (char *)0x0)) {
          return pcVar6;
        }
        param_3 = pcVar4 + 1;
      }
      break;
    case '%':
      bVar1 = param_3[1];
      if (bVar1 == 0x62) {
        param_2 = (char *)FUN_00703950(param_1);
        if (param_2 == (char *)0x0) {
          return (char *)0x0;
        }
        param_3 = param_3 + 4;
      }
      else if (bVar1 == 0x66) {
        if (param_3[2] != '[') {
          FUN_006f5f30(param_1[2],"missing \'[\' after \'%%f\' in pattern");
        }
        param_3 = (char *)FUN_00703620();
        if (param_2 == (char *)*param_1) {
          cVar7 = '\0';
        }
        else {
          cVar7 = param_2[-1];
        }
        iVar3 = FUN_007037a0(cVar7,param_3 + -1);
        if (iVar3 != 0) {
          return (char *)0x0;
        }
        iVar3 = FUN_007037a0(*param_2,param_3 + -1);
        if (iVar3 == 0) {
          return (char *)0x0;
        }
      }
      else {
        iVar3 = _isdigit((uint)bVar1);
        if (iVar3 == 0) goto switchD_00703c53_caseD_1;
        param_2 = (char *)FUN_00703ba0(param_2);
        if (param_2 == (char *)0x0) {
          return (char *)0x0;
        }
        param_3 = param_3 + 2;
      }
      break;
    case '(':
      if (param_3[1] == ')') {
        pcVar4 = (char *)FUN_00703af0(param_2,param_3 + 2,0xfffffffe);
        return pcVar4;
      }
      pcVar4 = (char *)FUN_00703af0(param_2,param_3 + 1,0xffffffff);
      return pcVar4;
    case ')':
      pcVar4 = (char *)FUN_00703b40(param_2,param_3 + 1);
      return pcVar4;
    }
  } while( true );
}

