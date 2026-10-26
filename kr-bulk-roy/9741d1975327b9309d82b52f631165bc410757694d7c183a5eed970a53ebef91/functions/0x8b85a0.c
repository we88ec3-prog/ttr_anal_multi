
undefined4 FUN_008b85a0(int param_1,int *param_2,char param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if ((*(byte *)(param_1 + 8) & 2) == 0) {
    return 0x23;
  }
  if (*param_2 == 0) {
    iVar6 = param_2[1];
    iVar5 = iVar6;
    if (param_2[3] != 0) {
      iVar5 = (iVar6 * param_2[3] + 0x24) / 0x48;
    }
    iVar1 = param_2[2];
    iVar2 = iVar1;
    if (param_2[4] != 0) {
      iVar2 = (iVar1 * param_2[4] + 0x24) / 0x48;
    }
    if (((iVar6 == 0) || ((iVar3 = iVar5, iVar1 != 0 && (iVar3 = iVar2, iVar6 == 0)))) &&
       (iVar3 = iVar2, iVar1 != 0)) {
      iVar5 = iVar2;
    }
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      piVar4 = (int *)(*(int *)(param_1 + 0x20) + 8);
      do {
        if (((iVar3 + 0x20U & 0xffffffc0) == (piVar4[1] + 0x20U & 0xffffffc0)) &&
           (((iVar5 + 0x20U & 0xffffffc0) == (*piVar4 + 0x20U & 0xffffffc0) || (param_3 != '\0'))))
        {
          if (param_4 != (int *)0x0) {
            *param_4 = iVar6;
          }
          return 0;
        }
        iVar6 = iVar6 + 1;
        piVar4 = piVar4 + 4;
      } while (iVar6 < *(int *)(param_1 + 0x1c));
    }
    return 0x17;
  }
  return 7;
}

