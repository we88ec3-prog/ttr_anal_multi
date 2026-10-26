
int * FUN_00869710(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined1 local_c [8];
  
  piVar1 = param_1;
  iVar3 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1 = (int *)0x0;
  if (0 < *(int *)(in_ECX + 0x30)) {
    do {
      piVar2 = (int *)(**(code **)(*(int *)(iVar3 + 0x34 + *(int *)(in_ECX + 0x34)) + 4))(local_c);
      if (*piVar2 < *piVar1) {
        *piVar1 = *piVar2;
      }
      if (piVar1[1] < piVar2[1]) {
        piVar1[1] = piVar2[1];
      }
      param_1 = (int *)((int)param_1 + 1);
      iVar3 = iVar3 + 0x58;
    } while ((int)param_1 < *(int *)(in_ECX + 0x30));
  }
  return piVar1;
}

