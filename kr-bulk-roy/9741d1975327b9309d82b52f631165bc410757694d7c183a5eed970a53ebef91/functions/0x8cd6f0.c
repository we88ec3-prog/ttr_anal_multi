
void FUN_008cd6f0(char param_1,short *param_2,int *param_3,int *param_4)

{
  bool bVar1;
  bool bVar2;
  uint in_EAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int local_1c;
  int local_18;
  int local_10;
  
  iVar7 = *param_4;
  local_10 = *param_3;
  bVar1 = true;
  if (in_EAX < 2) {
    *param_3 = local_10;
    *param_4 = iVar7;
    return;
  }
  local_1c = (in_EAX - 2 >> 1) + 1;
  local_18 = iVar7;
  do {
    bVar2 = false;
    if ((bVar1) || (param_1 != '\0')) {
      iVar8 = (int)param_2[1];
      iVar5 = *param_2 - iVar8;
      bVar1 = false;
      iVar3 = iVar7;
      piVar4 = param_4;
    }
    else {
      iVar8 = (int)*param_2;
      iVar5 = param_2[1] - iVar8;
      bVar2 = true;
      iVar3 = local_10;
      piVar4 = param_3;
    }
    piVar4 = piVar4 + 1;
    if (iVar3 != 0) {
      while (*piVar4 <= iVar8) {
        if (iVar8 == *piVar4) {
          if (iVar5 < 0) {
            if (iVar5 < piVar4[1]) {
              piVar4[1] = iVar5;
            }
          }
          else if (piVar4[1] < iVar5) {
            piVar4[1] = iVar5;
          }
          goto LAB_008cd7df;
        }
        piVar4 = piVar4 + 8;
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) goto LAB_008cd7cb;
      }
      if (iVar3 != 0) {
        piVar6 = piVar4 + iVar3 * 8;
        do {
          iVar3 = iVar3 + -1;
          piVar9 = piVar6 + -8;
          piVar10 = piVar6;
          for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar10 = *piVar9;
            piVar9 = piVar9 + 1;
            piVar10 = piVar10 + 1;
          }
          iVar7 = local_18;
          piVar6 = piVar6 + -8;
        } while (iVar3 != 0);
      }
    }
LAB_008cd7cb:
    *piVar4 = iVar8;
    piVar4[1] = iVar5;
    if (bVar2) {
      local_10 = local_10 + 1;
    }
    else {
      iVar7 = iVar7 + 1;
      local_18 = iVar7;
    }
LAB_008cd7df:
    param_2 = param_2 + 2;
    local_1c = local_1c + -1;
    if (local_1c == 0) {
      *param_3 = local_10;
      *param_4 = iVar7;
      return;
    }
  } while( true );
}

