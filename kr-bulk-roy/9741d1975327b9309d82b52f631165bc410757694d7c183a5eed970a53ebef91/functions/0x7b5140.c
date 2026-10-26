
undefined4 * FUN_007b5140(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_004633a0(param_1,1,in_EAX);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3)) {
LAB_007b5184:
      FUN_004633a0(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(byte *)(piVar1[2] + 0xc) < *(byte *)(in_EAX + 0xc)) {
LAB_007b51ab:
      FUN_004633a0(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3)) &&
       (FUN_007b5340(), *(byte *)(param_2 + 3) < *(byte *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x25) == '\0') {
        FUN_004633a0(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_007b51ab;
    }
    if ((*(byte *)(param_2 + 3) < *(byte *)(in_EAX + 0xc)) &&
       ((FUN_004632f0(), param_2 == *(int **)(in_ECX + 4) ||
        (*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3))))) {
      if (*(char *)(param_2[2] + 0x25) != '\0') {
        FUN_004633a0(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_007b5184;
    }
  }
  puVar2 = (undefined4 *)FUN_007b5270(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

