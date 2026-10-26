
undefined4 * FUN_0054f6a0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00597e80(param_1,1,in_EAX);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(uint *)(in_EAX + 0xc) < (uint)param_2[3]) {
LAB_0054f6e4:
      FUN_00597e80(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *(uint *)(in_EAX + 0xc)) {
LAB_0054f70b:
      FUN_00597e80(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(uint *)(in_EAX + 0xc) < (uint)param_2[3]) &&
       (FUN_008377c0(), (uint)param_2[3] < *(uint *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_00597e80(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_0054f70b;
    }
    if (((uint)param_2[3] < *(uint *)(in_EAX + 0xc)) &&
       ((FUN_0085e240(), param_2 == *(int **)(in_ECX + 4) ||
        (*(uint *)(in_EAX + 0xc) < (uint)param_2[3])))) {
      if (*(char *)(param_2[2] + 0x21) != '\0') {
        FUN_00597e80(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_0054f6e4;
    }
  }
  puVar2 = (undefined4 *)FUN_00597db0(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

