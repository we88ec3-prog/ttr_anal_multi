
int * FUN_00875440(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_10 [12];
  
  iVar1 = *(int *)(in_ECX + 0x30);
  *param_1 = 0;
  param_1[1] = 0;
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x30) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  if (*(int *)(in_ECX + 0x34) != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x34) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  if (*(int *)(in_ECX + 0x38) != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  if (*(int *)(in_ECX + 0x3c) != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x3c) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  if (*(int *)(in_ECX + 0x40) != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x40) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  if (*(int *)(in_ECX + 0x44) != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  if (*(int *)(in_ECX + 0x48) != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x48) + 4))(local_10);
    if (*piVar2 < *param_1) {
      *param_1 = *piVar2;
    }
    if (param_1[1] < piVar2[1]) {
      param_1[1] = piVar2[1];
    }
  }
  return param_1;
}

