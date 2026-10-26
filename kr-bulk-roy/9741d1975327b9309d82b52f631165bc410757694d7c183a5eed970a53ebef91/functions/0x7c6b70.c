
int * FUN_007c6b70(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  uVar5 = 0;
  iVar6 = param_1[0x37] - param_1[0x36] >> 2;
  if (0 < iVar6) {
    do {
      if (uVar5 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
        param_1 = *(int **)(piVar1[0x36] + uVar5 * 4);
      }
      else {
        param_1 = (int *)0x0;
      }
      iVar2 = (**(code **)(*param_1 + 4))();
      if (*(int *)(iVar2 + 4) == param_2) {
        return param_1;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < iVar6);
  }
  iVar6 = (**(code **)(*piVar1 + 0x34))();
  iVar2 = 0;
  if (0 < iVar6) {
    do {
      uVar3 = (**(code **)(*piVar1 + 0x30))(iVar2,param_2);
      piVar4 = (int *)FUN_007c6b70(uVar3);
      if (piVar4 != (int *)0x0) {
        return piVar4;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar6);
  }
  return (int *)0x0;
}

