
undefined4 * FUN_00445f50(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00480760(param_1,1,in_EAX);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3)) {
LAB_00445f94:
      FUN_00480760(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(byte *)(piVar1[2] + 0xc) < *(byte *)(in_EAX + 0xc)) {
LAB_00445fbb:
      FUN_00480760(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3)) &&
       (FUN_00574e80(), *(byte *)(param_2 + 3) < *(byte *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x2d) == '\0') {
        FUN_00480760(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_00445fbb;
    }
    if ((*(byte *)(param_2 + 3) < *(byte *)(in_EAX + 0xc)) &&
       ((FUN_00717a50(), param_2 == *(int **)(in_ECX + 4) ||
        (*(byte *)(in_EAX + 0xc) < *(byte *)(param_2 + 3))))) {
      if (*(char *)(param_2[2] + 0x2d) != '\0') {
        FUN_00480760(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_00445f94;
    }
  }
  puVar2 = (undefined4 *)FUN_00446080(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

