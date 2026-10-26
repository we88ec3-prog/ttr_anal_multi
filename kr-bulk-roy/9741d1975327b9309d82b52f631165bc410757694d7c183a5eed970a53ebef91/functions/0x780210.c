
undefined4 FUN_00780210(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  piVar1 = *(int **)(in_ECX + 0x48);
  piVar3 = *(int **)(in_ECX + 0x44);
  if (piVar3 != piVar1) {
    do {
      if (*piVar3 == *(int *)(iVar2 + 4)) break;
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar1);
    if (piVar3 != piVar1) {
      return 0;
    }
  }
  uVar4 = (**(code **)(*param_1 + 0x18))();
  return uVar4;
}

