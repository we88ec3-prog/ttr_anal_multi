
void FUN_0082a0f0(int param_1,int *param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  
  if (*(int *)(param_1 + 8) == 0) {
    param_2 = *(int **)(param_1 + 4);
LAB_0082a107:
    FUN_005189e0(unaff_ESI,1,param_2,in_EAX);
    return;
  }
  piVar1 = *(int **)(param_1 + 4);
  if (param_2 == (int *)*piVar1) {
    if (*(int *)(in_EAX + 0xc) < param_2[3]) {
      FUN_005189e0(unaff_ESI,1,param_2,in_EAX);
      return;
    }
  }
  else if (param_2 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *(int *)(in_EAX + 0xc)) {
      FUN_005189e0(unaff_ESI,0,piVar1[2],in_EAX);
      return;
    }
  }
  else {
    if ((*(int *)(in_EAX + 0xc) < param_2[3]) &&
       (FUN_008377c0(), param_2[3] < *(int *)(in_EAX + 0xc))) {
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_005189e0(unaff_ESI,1,param_2,in_EAX);
        return;
      }
      FUN_005189e0(unaff_ESI,0,param_2,in_EAX);
      return;
    }
    if ((param_2[3] < *(int *)(in_EAX + 0xc)) &&
       ((FUN_0085e240(), param_2 == *(int **)(param_1 + 4) || (*(int *)(in_EAX + 0xc) < param_2[3]))
       )) {
      if (*(char *)(param_2[2] + 0x21) != '\0') {
        FUN_005189e0(unaff_ESI,0,param_2,in_EAX);
        return;
      }
      goto LAB_0082a107;
    }
  }
  puVar2 = (undefined4 *)FUN_005188e0(param_1,in_EAX);
  *unaff_ESI = *puVar2;
  return;
}

