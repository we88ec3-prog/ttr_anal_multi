
undefined4 * FUN_006cf6f0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00518bc0(param_1,1,in_EAX);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(int *)(in_EAX + 0xc) < param_2[3]) {
LAB_006cf734:
      FUN_00518bc0(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *(int *)(in_EAX + 0xc)) {
LAB_006cf75b:
      FUN_00518bc0(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(int *)(in_EAX + 0xc) < param_2[3]) &&
       (FUN_0081a1b0(), param_2[3] < *(int *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x19) == '\0') {
        FUN_00518bc0(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_006cf75b;
    }
    if ((param_2[3] < *(int *)(in_EAX + 0xc)) &&
       ((FUN_00406870(), param_2 == *(int **)(in_ECX + 4) || (*(int *)(in_EAX + 0xc) < param_2[3])))
       ) {
      if (*(char *)(param_2[2] + 0x19) != '\0') {
        FUN_00518bc0(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_006cf734;
    }
  }
  puVar2 = (undefined4 *)FUN_00517bf0(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

