
undefined4 * FUN_006db7d0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_006db9e0(param_1,1,in_EAX);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(short *)(in_EAX + 0x10) < (short)param_2[4]) {
LAB_006db816:
      FUN_006db9e0(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(short *)(piVar1[2] + 0x10) < *(short *)(in_EAX + 0x10)) {
LAB_006db83f:
      FUN_006db9e0(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(short *)(in_EAX + 0x10) < (short)param_2[4]) &&
       (FUN_00536ea0(), (short)param_2[4] < *(short *)(in_EAX + 0x10))) {
      if (*(char *)(param_2[2] + 0x31) == '\0') {
        FUN_006db9e0(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_006db83f;
    }
    if (((short)param_2[4] < *(short *)(in_EAX + 0x10)) &&
       ((FUN_0050ef70(), param_2 == *(int **)(in_ECX + 4) ||
        (*(short *)(in_EAX + 0x10) < (short)param_2[4])))) {
      if (*(char *)(param_2[2] + 0x31) != '\0') {
        FUN_006db9e0(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_006db816;
    }
  }
  puVar2 = (undefined4 *)FUN_006db910(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

