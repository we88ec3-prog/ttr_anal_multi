
void FUN_008d06f0(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  bool bVar7;
  
  puVar3 = (undefined4 *)param_2;
  *(undefined4 *)((int)param_2 + 8) = 0;
  *(undefined4 *)param_2 = 0;
  *(undefined4 *)((int)param_2 + 4) = 0;
  FUN_008d06d0(param_1);
  param_2 = (char *)*param_1;
  pcVar2 = (char *)param_1[2];
  if (pcVar2 <= param_2) {
    return;
  }
  cVar1 = *param_2;
  *puVar3 = param_2;
  if (cVar1 == '(') {
    puVar3[2] = 2;
    iVar5 = FUN_008d0340(&param_2);
    bVar7 = iVar5 == 0;
  }
  else {
    if (cVar1 == '[') {
      pcVar6 = param_2 + 1;
      puVar3[2] = 3;
      param_2 = (char *)0x1;
      *param_1 = pcVar6;
      FUN_008d06d0(param_1);
      pcVar6 = (char *)*param_1;
      iVar5 = (int)param_2;
      while ((param_2 = pcVar6, param_2 < pcVar2 && (param_1[3] == 0))) {
        if (*param_2 == '[') {
          iVar4 = iVar5 + 1;
        }
        else {
          iVar4 = iVar5;
          if ((*param_2 == ']') && (iVar4 = iVar5 + -1, iVar5 + -1 < 1)) {
            param_2 = param_2 + 1;
            goto LAB_008d0753;
          }
        }
        param_2 = (char *)iVar4;
        FUN_008d0590(param_1);
        FUN_008d06d0(param_1);
        pcVar6 = (char *)*param_1;
        iVar5 = (int)param_2;
      }
      goto LAB_008d0756;
    }
    if (cVar1 == '{') {
      puVar3[2] = 3;
      iVar5 = FUN_008d0480(&param_2);
      bVar7 = iVar5 == 0;
    }
    else {
      puVar3[2] = ((*param_2 != '/') - 1 & 3) + 1;
      FUN_008d0590(param_1);
      param_2 = (char *)*param_1;
      bVar7 = param_1[3] == 0;
    }
  }
  if (bVar7) {
LAB_008d0753:
    puVar3[1] = param_2;
  }
LAB_008d0756:
  if (puVar3[1] == 0) {
    *puVar3 = 0;
    puVar3[2] = 0;
  }
  *param_1 = param_2;
  return;
}

