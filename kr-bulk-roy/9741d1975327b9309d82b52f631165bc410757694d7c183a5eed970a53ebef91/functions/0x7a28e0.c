
undefined4 * FUN_007a28e0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_007a2c90(param_1,1,in_EAX);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(uint *)(in_EAX + 0x10) < (uint)param_2[4]) {
LAB_007a2924:
      FUN_007a2c90(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0x10) < *(uint *)(in_EAX + 0x10)) {
LAB_007a294b:
      FUN_007a2c90(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(uint *)(in_EAX + 0x10) < (uint)param_2[4]) &&
       (FUN_008377c0(), (uint)param_2[4] < *(uint *)(in_EAX + 0x10))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_007a2c90(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_007a294b;
    }
    if (((uint)param_2[4] < *(uint *)(in_EAX + 0x10)) &&
       ((FUN_0085e240(), param_2 == *(int **)(in_ECX + 4) ||
        (*(uint *)(in_EAX + 0x10) < (uint)param_2[4])))) {
      if (*(char *)(param_2[2] + 0x21) != '\0') {
        FUN_007a2c90(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_007a2924;
    }
  }
  puVar2 = (undefined4 *)FUN_007a2810(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

