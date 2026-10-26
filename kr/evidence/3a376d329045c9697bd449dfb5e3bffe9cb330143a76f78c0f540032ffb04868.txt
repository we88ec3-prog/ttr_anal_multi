
undefined4 FUN_00544bc0(float param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = (int)param_1;
  piVar4 = *(int **)((int)param_1 + 4);
  if (piVar4 != *(int **)((int)param_1 + 8)) {
    do {
      piVar1 = (int *)*piVar4;
      param_1 = (float)piVar1[0x3f] * 0.5;
      (**(code **)(*piVar1 + 0x4c))(&param_1);
      iVar3 = FUN_007cc520(param_2);
      if (iVar3 != 0) {
        *param_4 = (int)piVar1;
        return 1;
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(iVar2 + 8));
  }
  return 0;
}

