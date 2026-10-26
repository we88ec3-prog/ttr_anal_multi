
undefined4 * FUN_00480550(undefined4 *param_1,int *param_2)

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
    if (*(ushort *)(in_EAX + 0xc) < *(ushort *)(param_2 + 3)) {
LAB_00480596:
      FUN_00480760(param_1,1,in_EAX);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(ushort *)(piVar1[2] + 0xc) < *(ushort *)(in_EAX + 0xc)) {
LAB_004805bf:
      FUN_00480760(param_1,0,in_EAX);
      return param_1;
    }
  }
  else {
    if ((*(ushort *)(in_EAX + 0xc) < *(ushort *)(param_2 + 3)) &&
       (FUN_00574e80(), *(ushort *)(param_2 + 3) < *(ushort *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x2d) == '\0') {
        FUN_00480760(param_1,1,in_EAX);
        return param_1;
      }
      goto LAB_004805bf;
    }
    if ((*(ushort *)(param_2 + 3) < *(ushort *)(in_EAX + 0xc)) &&
       ((FUN_00717a50(), param_2 == *(int **)(in_ECX + 4) ||
        (*(ushort *)(in_EAX + 0xc) < *(ushort *)(param_2 + 3))))) {
      if (*(char *)(param_2[2] + 0x2d) != '\0') {
        FUN_00480760(param_1,0,in_EAX);
        return param_1;
      }
      goto LAB_00480596;
    }
  }
  puVar2 = (undefined4 *)FUN_004808f0(in_ECX,in_EAX);
  *param_1 = *puVar2;
  return param_1;
}

